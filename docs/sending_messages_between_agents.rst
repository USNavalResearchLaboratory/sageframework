Sending Messages Between Agents
====================================================

SAGE Agents have the built-in ability to communicate across the network.

This can be useful for:
	- Controlling other agents dynamically.
	- Sending pertinent information, such as files, across your agent network.
	- Gathering information regarding your agent network.

The Message class provides the necessary mechanism to specify a message recipient and the message content. 

- **m_targetNodeName** [string]
	This is the name of the SAGE Node that is the recipient of this message. If left empty, the message is sent to all the Nodes in the SAGE network. 

- **m_targetAgentName** [string]
	This is the name of the SAGE Agent that is the recipient of this message. If left empty, the message is sent to all the Agents in the specified SAGE Node.

- **m_topic** [string]
	If specified, a topic name acts to direct a message to only those Behaviors that have that topic included in their topics list. This provides a filtering mechanism so that messages are only sent to those Behaviors interested in them.

- **m_message** [string]
	This is an arbitrary, application defined string that specifies what the message is.

- **m_data** [string vector]
	This string vector allows the message sender to include an arbitrary number of data items with the message. The content of that data is application defined.

.. container:: padding
	
	.. container:: toggle

		.. container:: header

			C++

		.. code-block:: cpp

			class Message
			{
			public:
				std::string m_targetNodeName;
				std::string m_targetAgentName;
				std::string m_topic;
				std::string m_message;
				std::vector<std::string> m_data;
			}

	.. container:: toggle

		.. container:: header

			Java

		.. code-block:: java

			public class Message 
			{
				public String m_targetNodeName;
				public String m_targetAgentName;
				public String m_topic;
				public String m_message;
				public ArrayList<String> m_data = new ArrayList<String>();
			}

	.. container:: toggle

		.. container:: header

			Python
		
		.. code-block:: python

			class Message(object):
			def __init__(self):
				self.m_targetNodeName = str()
				self.m_targetAgentName = str()
				self.m_topic = str()
				self.m_message = str()
				self.m_data = []
	

Invoke the :mod:`sendMessage` method using your Message as the argument to communicate with other Agents in the SAGE Agent network.


.. code-block:: Java

	Message myMessage = new Message();
		
	myMessage.m_message = "Hello";
	myMessage.m_targetNodeName = "nodeName1";
	myMessage.m_targetAgentName = "newAgentName1";
	sendMessage(myMessage);

As a result, the recipient agent (newAgentName1) will receive a message containing the message content "Hello".

 
