
.. container:: header-banner-color

	.. container:: header-banner-text
	
		SAGE Node
		

SAGE Node
==========================


.. figure::  _images/Sage_Node.png
   :align:   center


SAGE Nodes are containers for your SAGE Agents. A single Node can manage hundreds of Agents.


Nodes connect directly to the SAGE Server and must be uniquely identifiable by name. Nodes are usually deployed on systems based on the locality of the automation. For example, in a SOA test automation scenario, SAGE Nodes would be deployed on the system under test (SUT).
	
A SAGE Node fulfills a number of functions including: 

- Handling incoming requests from other Agents for message delivery, including file download and upload.
- Agent creation and deletion
- Agent Behavior management
- Agent activation and deactivation, .
- Scheduling the execution of Agent Behaviors.
- Communicating with the SAGE Sever to deliver requests to remote Agents.
- Reporting the results of Behavior execution back to the Server.
- Implementing synchronization between Agents.
	

.. _agent-label:

SAGE Agent
++++++++++++++++++++++++++
SAGE Agents are autonomous, active objects that execute your automation code (Behaviors). Agents exist within a SAGE Node instances.

They contain a state space that consists of name-value tuples, providing Agents with the information they need to carry out their behaviors. 

Agent names only have to be unique within the Node that contains them. 

Agents in SAGE are constructed dynamically, at runtime, through requests from the SAGE Server or from other Agents.
This capability enables Agents to create and configure other Agents at runtime. 

SAGE Agent services include:

- Create and destroy Agents
- Configure Agents
- Activate and Deactivate Agents
- Send messages to Agents
- Execute Behaviors
	
Addressing an Agent in a SAGE runtime requires both the Node name as well as the Agent name.

.. code-block:: python
	
	Create Agent  TestNode  TestAgent
	Add Behavior  TestNode  TestAgent  ExampleBehavior  ExampleBehavior.jar
	Activate Agent   TestNode    TestAgent

