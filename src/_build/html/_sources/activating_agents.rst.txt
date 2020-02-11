.. container:: header-banner-color

	.. container:: header-banner-text
	
		Activating Agents


Activating Agents
=======================================================

Remember that depending on how your Agents' Behaviors are programmed, Agents may execute code in response to being activated. 


Agent entities can be activated in multiple ways.

**Using the SAGE App** -  You can activate your existing Agents using the SAGE App. This method is a fast way to activate a large number of agents simultaneously on a single Node.
	
	1) In the SAGE App, select the targeted Node name or single Agent name and click :mod:`Activate Agent`.
	
**By a Controller Appliction** - You can activate agents using a Controller Application, such as Robot Framework. This method is a fast way to activate a large number of single Agents across multiple Nodes.

	1) Use the :mod:`Activate Agent` keyword to activate a targeted Agent name residing on the targeted Node.
	
		.. code-block:: bat
		
			Activate Agent   nodeName1    newAgentName1
			Activate Agent   nodeName1    newAgentName2
			Activate Agent   nodeName2    newAgentName1

**Through the execution of a Behavior** - Agents have the ability to activate other agent entities. This is a dynamic way to build your agent network to be more robust. This unique SAGE capability is supported by activating agents within your SAGE Behavior code. This enables agents to activate other agents.

	1) In your Behavior file, use the :mod:`setAgentActive` method to activate a targeted Agent name residing on the targeted Node. 
	2) Set the value to *true* to activate or *false* to deactivate.

		.. code-block:: bat
			
				setAgentActive(nodeName1, newAgentName2, true);
				setAgentActive(nodeName1, newAgentName2, false);
				