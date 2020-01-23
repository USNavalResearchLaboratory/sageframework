Adding a Behavior to an Agent

Adding a Behavior to an Agent
=============================

The Server will distribute behavior files to the target Nodes by way of
a file transfer. From there, a targeted Agent will be given access to
the Behavior.

A Behavior contains some action expected to be fulfilled by an Agent
residing on a Node instance.

Behaviors can be sent to connected Agents in a number of ways.

**Using the Behavior Manager in SAGE App** - You can populate your
existing Agents with Behaviors using the SAGE App. This is the manual
way to configure your agent network with the proper Behaviors prior to
executing your automation.

> 1)  In the SAGE App, select the targeted Agent name and
>     click Add Behavior.
> 2)  Select the Behavior name from the list of available Behaviors and
>     click Ok.
> 3)  Enter the desired Behavior topic strings and click Ok.

Assuming the Behavior file is in the proper sub-directory on the Server:

**By a Controller Application** - You can add available behaviors to
agents using a Controller Application, such as Robot Framework. This
gives SAGE users the ability to control complex test scenarios,
involving multiple nodes and agents, from a single controller entity.

> 1)  In your robot file, use the Add Behavior keyword to populate a
>     targeted Node and Agent name with the specified behavior.
>
>     > ``` {.sourceCode .bat}
>     > Add Behavior   nodeName1    newAgentName1   ExampleBehavior   ExampleBheavior.jar   Topic1   Topic2
>     > ```
>
**Through the execution of a Behavior** - Agents have the ability
configure other agent entities. This is a dynamic way to build your
agent network to be more robust. This unique SAGE capability enables
agents to send behaviors to other agents.

> 1)  In your Behavior file, use the addBehavior method to populate a
>     targeted Node and Agent with the specified behavior.
>
>     > ``` {.sourceCode .bat}
>     > addBehavior("nodeName1", "newAgentName1", "ExampleBehavior", "ExampleBheavior.jar", "Topic1", "Topic2");
>     > ```
>

