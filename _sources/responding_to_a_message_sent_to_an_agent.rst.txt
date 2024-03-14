Responding to a Message Sent to an Agent
=======================================================================

Depending on the Behavior construction, an agent will perform either **reactively** in response to an incoming message or **proactively** upon the receipt of a specific trigger message (m_triggerMessage) or at activation. Your can support both types of execution within a single Behavior file.

**Reactive Response**

Reactive responses are handled within your Behavior :mod:`message` method. Any code found within the :mod:`message` method will be called once your targeted Agent receives any message. 

To avoid invoking the wrong Behavior file, you can specify a specific topic (m_topic) within the senders Message object which matches the list of topics that the Behavior is interested in. Topics are associated with Behaviors when you add them to an agent.


Here's an example of a Message being sent by senderAgent:

.. code-block:: java

	Message myMessage = new Message();
		
	myMessage.m_message = "Hello";
	myMessage.m_targetNodeName = "recipientNode";
	myMessage.m_targetAgentName = "recipientAgent";
	myMessage.m_topic = "Topic1";
	sendMessage(myMessage);
	
Assuming recipientAgent has a Behavior that is associated with the topic "Topic1":

.. code-block:: java

	addBehavior("recipientNode", "recipientAgent", "ExampleBehavior", "ExampleBheavior.jar", "Topic1");


And by setting my execution type (m_executionType) to :mod:`NoExecution` within my Behavior's constructor, I ensure the action() method won't be called:

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
		
			
If all goes well, you should see the following response from the recipient (recipientAgent).

.. code-block:: bat

	begin
	Got message Hello on topic Topic1
	

Here's the same example of a Message being sent by the Server instead:

	1) In the SAGE App select :mod:`Send Message` to recipientAgent on recipientNode.
	2) Type message "Hello".
	3) Type topic "Topic1".
	4) Click the :mod:`Ok` button.
	
	
If all goes well, you should see the same response as above from the recipient (recipientAgent).

.. code-block:: bat

	begin
	Got message Hello on topic Topic1
	
**Proactive Response**

Proactive responses are handled within your Behavior :mod:`action` method. Any code found within the :mod:`action` method will be called once your targeted Agent receives the trigger message. 


Here's an example of a Message being sent by senderAgent:

.. code-block:: java

	Message myMessage = new Message();
		
	myMessage.m_message = "Bye";
	myMessage.m_targetNodeName = "recipientNode";
	myMessage.m_targetAgentName = "recipientAgent";
	sendMessage(myMessage);


By setting my execution type (m_executionType) to :mod:`OnMessage` and specifying a trigger message within my Behavior's constructor, I can invoke the action() method:

.. code-block:: bat

	public ExampleBehavior()
	{
		m_executionType = ExecutionType.OnMessage;
		m_description = "Example Behavior";
		m_name = "ExampleBehavior";
		m_triggerMessage = "Bye";

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

	
If all goes well, you should see the following response from the recipient (recipientAgent).

.. code-block:: bat

	begin
	Hello World from Action

Here's the same example of a Message being sent by the Server instead:

	1) In the SAGE App select :mod:`Send Message` to recipientAgent on recipientNode.
	2) Type message "Bye".
	3) Click the :mod:`Ok` button.
	
	
If all goes well, you should see the same response as above from the recipient (recipientAgent).

.. code-block:: bat

	begin
	Hello World from Action
	
You can also make use of :mod:`OneShot, Cyclical, or TimedCyclical` proactive execution types (m_executionType), which respond as soon as the Agent has been activated, to get the best of both worlds:


.. code-block:: bat

	public ExampleBehavior()
	{
		m_executionType = ExecutionType.OneShot;
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
		System.out.println("Got message "+ message.m_message);
		setAgentActive("recipientNode","recipientAgent", false);
		result.m_executionResult = ExecutionResultType.CompletionSuccess;
		return true;	
	}
	
	public boolean tearDown(Result result)
	{
		System.out.println("end");
		result.m_executionResult = ExecutionResultType.CompletionSuccess;
		return true;
	}

	
Assuming the recipientAgent got a message AFTER the agent was activated, you should see the following response from the recipient (recipientAgent).

.. code-block:: bat

	begin
	Hello World from Action
	Got message Bye
	end
	
In this example, teardown() method was invoked last as the agent was deactivated using the setAgentActive(false) method.