.. _examples-label:

Example
==================
	
Test case
----------------------------------------------------------------

**SenderReceiverTest.robot** 

Robot file that uses the SageRobotKeywords [Library] and contains one [Test Case] titled "Test Message Communications".

.. code-block:: bat

		# "%JAVAHOME_X64%\bin\java.exe" -cp "%SAGE_CLASSPATH%" org.robotframework.RobotFramework SenderReceiverTest.robot

		*** Settings ***
		Documentation   Used to test communications across the Agent network.
		...             Sets up SAGE Agents with their corresponding Behavior and activates them.
		...             Waits until the Agents are done communicating to generate report.

		Library         SageRobotKeywords
		Test Setup      Connect to SAGE Server
		Test Teardown   Log Results

		*** Test Cases ***
		Test Message Communications
			# Create Agents on existing Nodes
			Create Agent   	NodeOne   Agent1
			Create Agent   	NodeTwo   Agent2

			# Add Behaviors to Agents so that they can learn skill
			Add Behavior   	NodeOne   Agent1	SenderReceiverBehavior   SenderReceiverBehavior.jar   talking
			Add Behavior   	NodeTwo   Agent2	SenderReceiverBehavior   SenderReceiverBehavior.jar   talking

			# Activate Agents
			Activate Agent  NodeOne   Agent1
			Activate Agent  NodeTwo   Agent2

			# Wait until each Agent reports back to the Server upon completion	
			Wait For Result   NodeOne   Agent1   SenderReceiverBehavior   teardown   100000
			Wait For Result   NodeTwo   Agent2   SenderReceiverBehavior   teardown   100000
			
			
		*** Keywords ***
		Connect to SAGE Server
			Start Sage
			Connect to Sage Runtime   127.0.0.1   50001

		Log Results
			# Gather results that have been logged
			@{RESULTS}      Get Results

			:FOR    ${ELEMENT}    IN    @{RESULTS}
			\       Report Result   ${ELEMENT}
			
			# Clear results so that no results are cached
			Clear Results
		
		
[Test Setup] includes running the Keyword named "Connect to SAGE Server", identified in the *Keywords* table which includes:
	
	- ``Start Sage``
	- ``Connect to Sage Runtime``
	
The [Test Case] involves dynamically constructing two Agent entities on separate connected Nodes. Both Agents are to learn the same Behavior.
	
In order to add the Behavior to an Agent you must give the ``Add Behavior`` keyword the following arguments:

	- *nodeName* - refers to target Node.
	- *agentName* - refers to target Agent.
	- *behaviorName* - refers to the Behavior’s name (m_name) variable found within the Behavior's constructor.
	- *behaviorModule* - refers to the Behavior filename.
	- *topics* - allows you to add tags to Behaviors so that you can properly associate a message with a particular Behavior.


Incorporating the ``Wait For Result`` keyword ensures that Robot will not conclude prematurely. In this example, you wait until the teardown() method of each Agent returns the results of its execution before concluding the test. This enables the Server to wait until the Agents have finished communicating before generating a report. Otherwise, Robot will conclude the test after activating Agent2.


After the test has concluded, the [Test Teardown] execution will gather the logged events from the preceding steps, as well as clear those logs once captured.
		
	
**SenderReceiverBehavior.java**

Behavior file that demonstrates the use of having both a reactive and proactive execution response.  

.. code-block:: java

		/*  Use the following command line to build:
				javac -cp "%SAGE_SERVER_HOME%"\SageJavaBehaviorInterface.jar SenderReceiverBehavior.java

			 Create JAR file:
				jar cf SenderReceiverBehavior.jar SenderReceiverBehavior.class
		*/

		import nrl.sage.BehaviorInterface.*;

		public class SenderReceiverBehavior extends SageBehavior
		{
			int count;
			String senderAgent;
			String senderNode;
			String receiptAgent;
			String receiptNode;

			public SenderReceiverBehavior()
			{
				m_name = "SenderReceiverBehavior";
				m_description = "Periodically sends messages to other agents all while receiving messages";
				m_executionType = ExecutionType.TimedCyclical;
				m_delay = 50;
				m_period = 200;
			}
			
			public boolean setUp(Result result)
			{
				count = 1;
				result.m_executionResult = ExecutionResultType.NotSet;
				return true;
			}
			
			public boolean action(Result result)
			{
				try{
					// Using Agent state, retrieve the information of the Agent using this Behavior
					senderAgent = (String)getState("agent");
					senderNode = (String)getState("node");

					// Knowing who the sender agent is, store the intended agent recipient information
					if (senderAgent.equals("Agent1")){
						receiptAgent = "Agent2";
						receiptNode = "NodeTwo";
					}
					else {
						receiptAgent = "Agent1";
						receiptNode = "NodeOne";
					}

					// Construct the message content to send.
					Message messageToAgent = new Message();
					messageToAgent.m_message = "send" + " messageNo:" +Integer.toString(count);
					messageToAgent.m_data.add(senderAgent);
					messageToAgent.m_data.add(receiptAgent);
					messageToAgent.m_targetNodeName = receiptNode;
					messageToAgent.m_targetAgentName = receiptAgent;
					messageToAgent.m_topic = "talking";
					sendMessage(messageToAgent);
					
					// Increase count to know how many messages have been sent
					count++;

					System.out.println(senderAgent + " sent " + messageToAgent.m_message + " to " +receiptAgent);
				}
				catch (Exception e){
					result.m_exception = e.toString();
					result.m_executionResult = ExecutionResultType.ExceptionThrown;
				}
				
				result.m_executionResult = ExecutionResultType.NotSet;
				return true;
			}
			
			public boolean message(Message message, Result result)
			{
				// Print the message content in the console
				System.out.println(message.m_data.get(1) + " received " + message.m_message + " from " + message.m_data.get(0));
				
				// Deactivate agents after 20 messages have been sent
				if (count>20){
					setAgentActive(receiptNode, receiptAgent, false);
					setAgentActive(senderNode, senderAgent, false);
				}

				result.m_executionResult = ExecutionResultType.NotSet;
				return true;	
			}
			public boolean tearDown(Result result)
			{

				System.out.println("Tearing down behavior " + m_name);

				// Log event
				result.m_logMessages.add(senderAgent + " signing off. Goodbye!");

				// Report back to the Server indicating a successful teardown
				result.m_executionResult = ExecutionResultType.CompletionSuccess;
				return true;
			}

		}

	
	
The following indicates that the Agent will proactively respond at activation:

	- *m_executionType* has been set to TimedCyclical;
	
Proactive responses invoke the action() method. In this example, the response is to construct and send a message to a fellow Agent after identifying the originating Agent. 

TimedCyclical execution type continuously invokes the action() method. This continuous calling of the action() method enables the Agent to send more than one message.


The message() method handles the Agents reactive response and is invoked by way of message. In this example, the Agent is assumed to receive messages that contain the following content:
	
	- *message.m_message* - contains a string.
	- *message.m_data.get(0)* - contains the sender's name.
	- *message.m_data.get(1)* - contains the receiver's name.

Once the Agent has received 20 messages it will proceed to deactivate its fellow Agent, as well as itself.

The tearDown() method will be invoked upon deactivation, signaling the Agent to report the result of the tearDown back to the Server.



Running test
-------------------------------------

On your ``Server`` machine, create a java file using the above Behavior code to create ``SenderReceiverBehavior.java``. Compile the code and place it into the Java Behavior sub-directory:

	.. code-block:: bat
		
		For Windows: C:\ProgramData\SAGE\behaviors\Java\SenderReceiverBehavior.jar 

		For Linux: /etc/Sage/behaviors/Java/SenderReceiverBehavior.jar 


Ensure that both the SAGE Server and SAGE Node were installed with Java support. In addition, ensure that the Behavior file has been placed in the correct directory *(C:\\ProgramData\\SAGE\\behaviors\\Java)* on the Server machine. If not yet done, add the Behavior file to the specified directory.

Start the SAGE Server by opening the terminal and typing the command:

	.. code-block:: bat
		
		SageServerConsole_x64.exe 50001
	

Create and connect a Node named ``NodeOne`` by typing: 

	.. code-block:: bat
		
		SageNodeConsole_x64.exe NodeOne 127.0.0.1 50001
		
Create and connect a Node named ``NodeTwo`` by typing: 

	.. code-block:: bat
		
		SageNodeConsole_x64.exe NodeTwo 127.0.0.1 50001
	
	
Upon successful connection, you will be ready to run the test. 

Create your Robot test case using the above Robot Framework code to create ``SenderReceiverTest.robot``.

Start the example by by typing:

	.. code-block:: bat
		
		java -cp "%SAGE_CLASSPATH%" org.robotframework.RobotFramework SenderReceiverTest.robot
	

.. _resultsdemo-label:

Generated results
----------------------------------------------

A report and log HTML file are generated after running test. Report gives you an overview of the test execution by detailing viewable statistics including Pass/Fail ratios and elapsed times. Log details statistics from each step of the test execution, from keyword to keyword. It enables you to drill down on the specifics of the test in case of failure or otherwise `[*] <http://robotframework.org/#examples>`_. 

Expand the elements to find returned results for each step execution. For more information regarding report and log files, see `Robot Framework output documentation <http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#log-file>`_.

This log is based on successfully running SenderReceiverTest.robot. 

.. figure::  _images/log_example.png