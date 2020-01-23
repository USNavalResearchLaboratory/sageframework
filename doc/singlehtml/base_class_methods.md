Base Class - SAGE Behavior Methods

Base Class - SAGE Behavior Methods
==================================

The SAGE Behavior base class provides a number of powerful methods that
allow Agents to communicate with other Agents, create and remove Agents,
add and remove Behaviors from Agents, activate and deactivate Agents,
and manage their Agent's state space.

This capability in SAGE supports the idea of meta-agents that can reason
about their current environment and create other Agents based on that
reasoning.

addBehavior
-----------

This method enables SAGE Agents to populate other SAGE Agents with new
Behaviors.

-   

    **nodeName** \[string\]

    :   This is the name of a SAGE Node where the target Agent exists.

-   

    **agentName** \[string\]

    :   This is the name of the SAGE Agent that will receive the
        new Behavior.

-   

    **behaviorName** \[string\]

    :   This is the name that was assigned to the SAGE Behavior by
        its developer.

-   

    **module** \[string\]

    :   This is the file name of the module containing the Behavior to
        be added. Depending on the language the Behavior was written in,
        this could be a Java .jar file, a Python .egg file, or a native
        dynamic load library (.dll or .so).

-   

    **topics** \[string vector\]

    :   The topic vector specifies the set of topic names that the new
        Behavior will be interested in. Messages sent to the Behavior's
        Agent will only be routed to this new Behavior if the topic
        specified in the message matches one of the topic names in
        this vector. Note that messages that do not specify a topic are
        sent to all Behaviors and conversely Behaviors that don't
        specify a topic list receive all message irrespective of the
        topic the message specifies.

C++

``` {.sourceCode .cpp}
void addBehavior(std::string nodeName, std::string agentName, std::string behaviorName, std::string module, std::vector<std::string> topics);
```

Java

``` {.sourceCode .java}
public void addBehavior(String nodeName, String agentName, String behaviorName, String module, ArrayList<String> topics)
```

Python

``` {.sourceCode .python}
def addBehavior(self, nodeName, agentName, behaviorName, module_, topics)
```

createAgent
-----------

This method enables SAGE Agents to create other SAGE Agents through
their Behaviors. New Agents can be created on an Agent's local Node or a
remote Node.

-   

    **nodeName** \[string\]

    :   This is the name of a SAGE Node where the new Agent will
        be created.

-   

    **agentName** \[string\]

    :   This is will be the name assigned to the new SAGE Agent. Agent
        names must be unique within the Node that contains them.

C++

``` {.sourceCode .cpp}
void createAgent(std::string nodeName, std::string agentName);
```

Java

``` {.sourceCode .java}
public void createAgent(String nodeName, String agentName)
```

Python

``` {.sourceCode .python}
def createAgent(self, nodeName, agentName)
```

createState
-----------

This method enables Behaviors to create a new, named state in its
Agent's state space. State names must be unique so this method returns
false if a state with the specified name already exists.

-   

    **name** \[string\]

    :   This is the name of the new state to be added to state space.

C++

``` {.sourceCode .cpp}
bool createState(std::string name);
```

Java

``` {.sourceCode .java}
public Boolean createState(String name)
```

Python

``` {.sourceCode .python}
def createState(self, name)
```

getState
--------

This method returns the value of a named state in an Agent's state
space. The method throws an exception if the specified state name is not
found. The state value is returned as a generic value.

-   

    **name** \[string\]

    :   This is the name of the state whose value will be returned.

In C++, the value is returned as a boost::variant that can contain long,
double, or std::string types. The boost::variant which() method can be
used to determine the type held. The which() method returns the 0-based
index of the type currently held by the boost::variant. In SAGE, a value
of 0 is a long, a value of 1 is a double, and a value of 2 is a
std::string.

To retreive the actual value of the boost::variant, use the
boost::get&lt;T&gt;(value) function template. For a long value use
boost::get&lt;long&gt;(value), for a double value use
boost::get&lt;double&gt;(value), and for a std::string value use
boost::get&lt;std::string&gt;(value).

C++

``` {.sourceCode .cpp}
sageframework::StateValueType getState(std::string name);
```

In Java the value is returned as a generic Object. Java's getClass()
method can be called on the Object to discover its type. The object can
then be cast to the appropriate type to retreive its value.

Java

``` {.sourceCode .java}
public Object getState(String name) throws Exception
```

In Python, the type(value) function returns the type of a variable.
Python variables are dynamically typed so the value returned from the
getState can be assigned to Python variable.

Python

``` {.sourceCode .python}
def getState(self, name)
```

getStateNames
-------------

This method returns a vector of all the state names that currently exist
in an Agent's state space.

C++

``` {.sourceCode .cpp}
std::vector<std::string> getStateNames();
```

Java

``` {.sourceCode .java}
public Set getStateNames()
```

Python

``` {.sourceCode .python}
def getStateNames(self)
```

removeAgent
-----------

This method enables SAGE Agents to remove other SAGE Agents through
their Behaviors. Agents can be removed from an Agent's local Node or a
remote Node.

-   

    **nodeName** \[string\]

    :   This is the name of a SAGE Node where the target Agent exists.

-   

    **agentName** \[string\]

    :   This is the name of the SAGE Agent that is removed.

C++

``` {.sourceCode .cpp}
void removeAgent(std::string nodeName, std::string agentName);
```

Java

``` {.sourceCode .java}
public void removeAgent(String nodeName, String agentName)
```

Python

``` {.sourceCode .python}
def removeAgent(self, nodeName, agentName)
```

removeBehavior
--------------

This method enables SAGE Agents to remove existing Behaviors from other
Agents.

-   

    **nodeName** \[string\]

    :   This is the name of a SAGE Node where the target Agent exists.

-   

    **agentName** \[string\]

    :   This is the name of the SAGE Agent that will have its
        Behavior removed.

-   

    **behaviorName** \[string\]

    :   This is the name of the Behavior that will be removed.

C++

``` {.sourceCode .cpp}
void removeBehavior(std::string nodeName, std::string agentName, std::string behaviorName);
```

Java

``` {.sourceCode .java}
public void removeBehavior(String nodeName, String agentName, String behaviorName)
```

Python

``` {.sourceCode .python}
def removeBehavior(self, nodeName, agentName, behaviorName)
```

removeState
-----------

This method enables Behaviors to remove a named state from its Agent's
state space. If the specified state name is not found, this method
returns false.

-   

    **name** \[string\]

    :   This is the name of the state to be removed from state space.

C++

``` {.sourceCode .cpp}
bool removeState(std::string name);
```

Java

``` {.sourceCode .java}
public Boolean removeState(String name)
```

Python

``` {.sourceCode .python}
def removeState(self, name)
```

setAgentActive
--------------

This method enables SAGE Agents to activate and deactivate other SAGE
Agents. Agents are created in an inactive state. Activating an inactive
agents causes the setUp() methods of its Behaviors to be called and its
action() and message() methods to be invoked based on the properties of
the Agent and in response to incoming messages. Deactivating an active
Agent causes the tearDown() method of its Behaviors to be called and the
Agent then becomes dormant.

-   

    **nodeName** \[string\]

    :   This is the name of a SAGE Node where the target Agent exists.

-   

    **agentName** \[string\]

    :   This is the name of the SAGE Agent that will be activated
        or deactivated.

-   

    **isActive** \[boolean\]

    :   This is a flag indicating if an Agent is to be activated (true)
        or deactivated (false).

C++

``` {.sourceCode .cpp}
void setAgentActive(std::string nodeName, std::string agentName, bool isActive);
```

Java

``` {.sourceCode .java}
public void setAgentActive(String nodeName, String agentName, boolean isActive)
```

Python

``` {.sourceCode .python}
def setAgentActive(self, nodeName, agentName, isActive)
```

sendFile
--------

This method transmits a file to the SAGE Server. This capability is
useful for sending auxiliary data or arbitrary files to a centralized
location. Files transmitted to a SAGE Server running on the Windows
operating system are placed in the sage\\downloads subfolder of the
ProgramData folder (usually `C:\ProgramData\SAGE\downloads`).

-   

    **filePath** \[string\]

    :   This is a fully qualified path to the file.

C++

``` {.sourceCode .cpp}
void sendFile(std::string filePath);
```

Java

``` {.sourceCode .java}
public void sendFile(String filePath);
```

Python

``` {.sourceCode .python}
def sendFile(self, filePath)
```

sendMessage
-----------

The sendMessage method can be called by Behaviors to communicate with
other Agents in the SAGE Agent network.

C++

``` {.sourceCode .cpp}
void sendMessage(const sageframework::Message& message)
```

Java

``` {.sourceCode .java}
public void sendMessage(Message message)
```

Python

``` {.sourceCode .python}
def sendMessage(self, message)
```

setState
--------

This method sets the value of named state in an Agent's state space. The
method returns false if the state name is not found. In C++ setState is
a templated function that is instantiated for values of type long,
double, and std::string. It can be called with values that are one of
those three types.

-   

    **name** \[string\]

    :   This is the name of the state whose value will be modified.

-   

    **value** \[long, double, or std::string\]

    :   This is the new value that the state will take on. Valid values
        must of type long, double, or std::string.

C++

``` {.sourceCode .cpp}
template<typename T> bool setState(std::string, T value);
```

Java

``` {.sourceCode .java}
public Boolean setState(String name, Object value)
```

Python

``` {.sourceCode .python}
def setState(self, name, value)
```
