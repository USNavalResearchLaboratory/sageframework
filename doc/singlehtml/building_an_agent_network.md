Building an Agent Network

Building an Agent Network
=========================

You can start to build out an agent network once you have established a
connection between your SAGE Server and Node components.

Agent entities can be created within any active Node using the SAGE App,
a Controller Application, or within a Behavior.

**SAGE App** - You can populate your existing Nodes with agents using
the SAGE App. This is the manual way to configure your agent network
with the proper Behaviors prior to executing your automation.

> 1)  In the SAGE App, select the targeted Node name and
>     click Create Agent.
> 2)  Type in a name for your agent and click the OK button.

**Controller Application** - You can create agents using a Controller
Application, such as Robot Framework. This method is a fast way to
generate a large number of agents across any active Nodes.

> 1)  In your robot file, connect the controller to the Server by using
>     the keywords Start Sage and Connect to Sage Runtime.
> 2)  Use the Create Agent keyword to populate a targeted Node name with
>     an expected Agent name.
>
>     > ``` {.sourceCode .bat}
>     > Create Agent   nodeName1    newAgentName1
>     > Create Agent   nodeName1    newAgentName2
>     > Create Agent   nodeName2    newAgentName1
>     > ```
>
**Behavior** - Agents have the ability to spawn and configure other
agent entities. This is a dynamic way to build your agent network to be
more robust. This unique SAGE capability is supported by initializing
agents within your SAGE Behavior code. This enables agents to create
other agents.

> 1)  In your Behavior file, use the CreateAgent method to populate a
>     targeted Node name with an expected Agent name.
>
>     > ``` {.sourceCode .bat}
>     > createAgent("nodeName1", "newAgentName1");
>     > ```
>

