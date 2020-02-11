.. container:: header-banner-color

	.. container:: header-banner-text
	
		Creating A Test Case Using Robot Framework - Controller Application

Creating A Test Case Using Robot Framework - Controller Application
====================================================================

A Controller in the SAGE Framework is an external application that interacts with the SAGE Server. 

This component is optional. However, it is highly recommended for users using SAGE for test automation to use a Controller to interact with your tests. It provides greater visibility by enabling report generation and step-by-step test case building.

By default, SAGE Framework supports native Robot Framework integration as a SAGE controller mechanism.

By remotely connecting Robot Framework to an running SAGE Server instance, you can manage a network of Agents in a single Robot file using Keyword-based testing.

For users in test automation, controlling your agent network via Robot Framework provides the following benefits:

	- You can construct an entire test case in a single file.
	- Robot Framework prints a test report with each step producing a result.
	- You can quickly create several independent agent networks for multiple test cases.
	- All tests are stored and ran from a single server machine.
	- You can run multiple Robot files sequentially.

If either of these benefits are not fitting for your automation needs, then you may not require the use of a controller mechanism. Instead, continue using the Server and Node only.

Keywords, such as ``Start SAGE``, ``Connect To SAGE Runtime``, ``Create Agent``, ``Add Behavior``, and ``Activate Agent`` are used to construct an agent network. 

.. code-block:: bat
		
		**Test Cases**
		This is an Example Test
			Start SAGE
			Connect To SAGE Runtime   {server_IP_address}   {port_number}
			Create Agent   nodeName1   agentName1
			Add Behavior   nodeName1   agentName1   {behaviorName}   {behaviorModule}   topic
			Activate Agent   nodeName1   agentName1

While keywords, such as ``Remove Agent`` and ``Deactivate Agent``, can be used to de-construct your network.

.. code-block:: bat
		
		**Test Cases**
		This is an Example Test
			Start SAGE
			Connect To SAGE Runtime   {server_IP_address}   {port_number}
			Create Agent   nodeName1   agentName1
			Add Behavior   nodeName1   agentName1   {behaviorName}   {behaviorModule}   topic
			Activate Agent   nodeName1   agentName1
			Deactivate Agent   nodeName1   agentName1
			Remove Agent   nodeName1   agentName1

			
Using keywords, such as ``Send Message`` and ``Run Step`` allows the Server to send a message to a targeted Agent.

.. code-block:: bat
		
		**Test Cases**
		This is an Example Test
			Start SAGE
			Connect To SAGE Runtime   {server_IP_address}   {port_number}
			Create Agent   nodeName1   agentName1
			Add Behavior   nodeName1   agentName1   {behaviorName}   {behaviorModule}   topic
			Activate Agent   nodeName1   agentName1
			Send Message   nodeName1   agentName1   Topic1   Hello
			Deactivate Agent   nodeName1   agentName1
			Remove Agent   nodeName1   agentName1

Depending on the Behavior construction, an agent will perform either **reactively** in response to an incoming message or **proactively** upon the receipt of a specific trigger message or at activation.


Here's an example constructed test case:

.. code-block:: bat

	This is an Example Test
		Start SAGE
		Connect To SAGE Runtime   121.0.0.1   50001
		Create Agent   recipientNode   recipientAgent
		Add Behavior   recipientNode   recipientAgent   ExampleBehavior   ExampleBehavior.jar   Topic1
		Activate Agent   recipientNode   recipientAgent
		Send Message   recipientNode   recipientAgent   Topic1   Hello
		Deactivate Agent   recipientNode   recipientAgent
		Remove Agent   recipientNode   recipientAgent


Looking at the Java code for ExampleBehavior file:

.. code-block:: java

	public ExampleBehavior()
	{
		m_executionType = ExecutionType.NoExecution;
		m_description = "Example Behavior";
		m_name = "ExampleBehavior";
	}
	public boolean setUp(Result result)
	{
		System.out.println("begin");
		result.m_executionResult = ExecutionResultType.CompletionSuccess;
		return true;
	}

	public boolean action(Result result)
	{
		System.out.println("Hello World from Action");
		result.m_executionResult = ExecutionResultType.CompletionSuccess;
		return true;
	}

	public boolean message(Message message, Result result)
	{
		System.out.println("Got message "+ message.m_message + " on topic " + message.m_topic);
		result.m_executionResult = ExecutionResultType.CompletionSuccess;
		return true;	
	}
	public boolean tearDown(Result result)
	{
		System.out.println("end");
		result.m_executionResult = ExecutionResultType.CompletionSuccess;
		return true;
	}
		
			
If all goes well, you should see the following results from your executed test case:

.. code-block:: bat

	begin
	Got message Hello on topic Topic1
	end
	
This is because, the :mod:`Send Message` Keyword points to the Behavior associated with Topic1 (ExampleBehavior). Knowing this, the Server sends message "Hello" to the recipient Agent (recipientAgent) using that Behavior.

If you were to make the following change to :mod:`Send Message`:

.. code-block:: bat

	This is an Example Test
		Start SAGE
		Connect To SAGE Runtime   121.0.0.1   50001
		Create Agent   recipientNode   recipientAgent
		Add Behavior   recipientNode   recipientAgent   ExampleBehavior   ExampleBehavior.jar   Topic1
		Activate Agent   recipientNode   recipientAgent
		Send Message   recipientNode   recipientAgent   Topic10000   Hello
		Deactivate Agent   recipientNode   recipientAgent
		Remove Agent   recipientNode   recipientAgent

You would expect the following results from your executed test case:

.. code-block:: bat

	begin
	end

This is due to the message not being propagated to any Behavior, as no Behavior was added that is associated with Topic10000. 

