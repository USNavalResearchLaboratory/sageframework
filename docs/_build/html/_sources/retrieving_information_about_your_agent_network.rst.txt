Retrieving Information About Your Agent Network
================================================================================
 
SAGE Agents will often need to find the names of SAGE Nodes that are part of the network as well as the names of SAGE Agents residing at a specific node. SAGE uses a query message send and reply protocol to provide this introspection capability. 

SAGE Agents can send query messages to the SAGE Server by specifying :mod:`sage` as the target Node in the Message object (m_targetNodeName). The type of query requested is specified in the message itself (m_message). 

Replies are sent by the SAGE Server to the originating SAGE Agent and contain the original query in the m_message, while the results of the query are returned data element, m_data, of the Message object. Simple queries that request an enumeration of Node and Agent names receive a reply with the Node or Agent names as a string vector in m_data. Deeper queries that request all the relevant information about Nodes or Agents recieve a reply with a JSON object in the first element of the m_data vector (m_data[0]). 

The following introspection queries are supported by SAGE:

**Querying the names of all the SAGE Nodes in the network**

To get the names of all the SAGE Nodes in the network, the message (m_message) should equal ``getNodeNames``. 

Here's an example of a ``getNodeNames`` query generated in a Java behavior:

.. code-block:: Java

	Message myMessage = new Message();
		
	myMessage.m_message = "getNodeNames";
	myMessage.m_targetNodeName = "sage";
	sendMessage(myMessage);
	
In response to this query, the SAGE Server would reply to the sender with a Message containing the following:

.. code-block:: bat

	m_message = "getNodeNames"
	m_topic = "sage"
	m_data[0] = "nodeName1"
		.
		.
	m_data[n - 1] = "nodeNameN"

**Querying the names of all the SAGE Agents in the network**

To get the names of SAGE Agents at a specific SAGE Node, message (m_message) should equal ``getAgentNames`` with the name of the SAGE Node included as the first string data element in the Message object (m_data[0]).
 

Here's an example of a ``getAgentNames`` query generated in a Java behavior:

.. code-block:: Java

	Message myMessage = new Message();
		
	myMessage.m_message = "getAgentNames";
	myMessage.m_targetNodeName = "sage";
	myMessage.m_data.add("nodeName1");
	sendMessage(myMessage);
	
In response to this query, the SAGE Server would reply to the sender with a ``Message`` containing the following:

.. code-block:: bat

	m_message = "getAgentNames"
	m_topic = "sage"
	m_data[0] = "newAgentName1"
		.
		.
	m_data[n - 1] = "newAgentNameN"

**Querying all of the SAGE Nodes in the network**

To get detailed information on all of the SAGE Nodes in a nework, message (m_message) should equal ``getNodes``.
 
Here's an example of a ``getNodes`` query generated in a Java behavior:

.. code-block:: Java

	Message myMessage = new Message();
		
	myMessage.m_message = "getNodes";
	myMessage.m_targetNodeName = "sage";
	sendMessage(myMessage);
	
In response to this query, the SAGE Server would reply to the sender with a ``Message`` containing the following:

.. code-block:: bat

	m_message = "getNodes"
	m_topic = "sage"
	m_data[0]= 
	{
	  "nodes": {
		  "Node1": {
			  "agents": {
				  "Agent1": {
					  "behaviors": {
						  "ExampleJavaBehavior": {
							  "module": "ExampleJavaBehavior.jar",
							  "targetEnvironment": "Any"
						  }
					  }
				  },
				  "Agent2": {
					  "behaviors": {
						  "Hello": {
							  "module": "hello.jar",
							  "targetEnvironment": "Any"
						  }
					  }
				  }
			  },
			  "runtimeEnvironment": "Windows64",
			  "ipAddress": "127.0.0.1"
		  },
		  "Node2": {
			  "agents": {
				  "Agent3": {
					  "behaviors": {
						  "TestGetNode": {
							  "module": "TestGetNode.jar",
							  "targetEnvironment": "Any"
						  }
					  }
				  },
				  "Agent4": {
					  "behaviors": {
						  "ExampleJavaBehavior": {
							  "module": "ExampleJavaBehavior.jar",
							  "targetEnvironment": "Any"
						  }
					  }
				  }
			  },
			  "runtimeEnvironment": "Windows64",
			  "ipAddress": "127.0.0.1"
		  }
	  }
  }

**Querying a specific SAGE Node in the network**

To get detailed information of a single SAGE Node, message (m_message) should equal ``getNode`` and the first element of m_data (m_data[0]) should contain the target Node's name.
 
Here's an example of a ``getNode`` query generated in a Java behavior:

.. code-block:: Java

	Message myMessage = new Message();
		
	myMessage.m_message = "getNode";
	myMessage.m_targetNodeName = "sage";
	message.m_data.add("Node1");
	sendMessage(myMessage);
	
In response to this query, the SAGE Server would reply to the sender with a ``Message`` containing the following:

.. code-block:: bat

	m_message = "getNode"
	m_topic = "sage"
	m_data[0] = 
	{
      "Node1": {
          "agents": {
              "Agent1": {
                  "behaviors": {
                      "ExampleJavaBehavior": {
                          "module": "ExampleJavaBehavior.jar",
                          "targetEnvironment": "Any"
                      }
                  }
              },
              "Agent2": {
                  "behaviors": {
                      "Hello": {
                          "module": "hello.jar",
                          "targetEnvironment": "Any"
                      }
                  }
              }
          },
          "runtimeEnvironment": "Windows64",
          "ipAddress": "127.0.0.1"
      }
  }

**Querying all of the SAGE Agents in the network**

To get detailed information on all of the SAGE Agents in a network, message (m_message) should equal ``getAgents`` and the first element of m_data (m_data[0]) should contain the target Node's name.
 
Here's an example of a ``getAgents`` query generated in a Java behavior:

.. code-block:: Java

	Message myMessage = new Message();
		
	myMessage.m_message = "getAgents";
	myMessage.m_targetNodeName = "sage";
	message.m_data.add("Node1");
	sendMessage(myMessage);
	
In response to this query, the SAGE Server would reply to the sender with a ``Message`` containing the following:

.. code-block:: bat

	m_message = "getAgents"
	m_topic = "sage"
	data[0] =
	{
	  "agents": {
		  "Agent1": {
			  "behaviors": {
				  "ExampleJavaBehavior": {
					  "module": "ExampleJavaBehavior.jar",
					  "targetEnvironment": "Any"
				  }
			  }
		  },
		  "Agent2": {
			  "behaviors": {
				  "Hello": {
					  "module": "hello.jar",
					  "targetEnvironment": "Any"
				  }
			  }
		  }
	  }
	}

**Querying a specific SAGE Agent in the network**

To get detailed information on a specific SAGE Agent in a network, message (m_message) should equal ``getAgent`` and the first element of m_data (m_data[0]) should contain the target Node's name. The second element of m_data (m_data[1]) should contain the Agent's name.
 
Here's an example of a ``getAgent`` query generated in a Java behavior:

.. code-block:: Java

	Message myMessage = new Message();
		
	myMessage.m_message = "getAgent";
	myMessage.m_targetNodeName = "sage";
	message.m_data.add("Node1");
	message.m_data.add("Agent1");
	sendMessage(myMessage);
	
In response to this query, the SAGE Server would reply to the sender with a ``Message`` containing the following:

.. code-block:: bat

	m_message = "getAgent"
	m_topic = "sage"
	data[0] =
	{
	  "Agent1": {
		  "behaviors": {
			  "ExampleJavaBehavior": {
				  "module": "ExampleJavaBehavior.jar",
				  "targetEnvironment": "Any"
			  }
		  }
		}
	}

**Getting the name of the originating Agent and its Node**

There may be instances where you need to know information about the Agent who is currently using your Behavior, such as what Node it resides on. For instance, you may want to ensure that you create a new agent on the same node as the originating Agent.

To achieve this, agents contain a state space that is shared by all the agents' behaviors. State space consists of name-value pairs where name is a unique string identifying a state variable and value is one of the following value types: double-precision floating-point number, a long integer, or a string. 

Behaviors can create, remove, or modify the value of state variables. SAGE guarantees that state space is always synchronized across behavior executions.

SAGE provides two standard state values of type string that are available to behaviors: 

- :mod:`node` is the name of the SAGE Node where the behavior's agent resides
- :mod:`agent` is the name of that agent. 


Use either the :mod:`getState` or :mod:`getStateNames` methods to return the Agent's state space information

.. code-block:: Java

	System.out.println(getState("node"));
	System.out.println(getState("agent"));
	System.out.println(getStateNames());
	
If all goes well, you should see the following response

.. code-block:: Java

	nodeName1
	newAgentName1
	[nodeName1, newAgentName1]

