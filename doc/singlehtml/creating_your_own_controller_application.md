Creating Your Own Controller Application

Creating Your Own Controller Application
========================================

A Controller in the SAGE framework is an application that interacts with
the SAGE Server to create and manage a network of Agents. SAGE
Controller applications are external applications that remotely connect
to an instance of a SAGE Server running in either a console application
(ex. SageServerConsole\_x64.exe) or in the SageServerApplication.

The SAGE SDK provides both C++ and Java bindings for creating Controller
applications. The SageRemoteInterface class provides an interface for
creating a remote connection to an instance of the SAGE Server and for
creating and managing agents.

Using the SageRemoteInterface to create and manage an Agent network, a
Control application performs the following steps:

1)  Create an instance of the SageRemoteInterface class.
2)  Connect to the SAGE Server by providing an IP address and
    port number.
3)  Create and manage the Agent network.
4)  Synchronize events.
5)  Retrieve results.
6)  Disconnect from the SAGE server.
7)  Destroy the SageRemoteInterface object.

The SageRemoteInterface class provides a number of methods to interface
with Controller applications.

addBehavior
-----------

This method adds a new Behavior to a SAGE Agent. Behaviors are units of
execution that define how an Agent acts either due to a deterministic
execution pattern, or in response to an incoming message. This method
allows the caller to specify an optional set of topics that act as a
message filter for the Agent. If a topic set is specified for a
Behavior, then only incoming messages that specify one of those topics
will be passed through to that Behavior. If no topic set is specified,
then all messages are passed to the Behavior. This method returns a
boolean value indicating whether or not the Behavior was successfully
added.

-   

    **nodeName** \[string\]

    :   This is the name of the SAGE Node in which the Agent resides.

-   

    **agentName** \[string\]

    :   This is the name of the Agent.

-   

    **behaviorName** \[string\]

    :   This is the name that was assigned to the SAGE Behavior by
        its developer.

-   

    **module** \[string\]

    :   This is the file name of the module containing the Behavior to
        be added. Depending on the language the Behavior was written in,
        this could be a Java .class file, a Python .py file, or a native
        dynamic load library (.dll or .so).

-   

    **topics** \[string vector\]

    :   The topic vector specifies the set of topic names that the new
        Behavior will be interested in. Messages sent to the Behavior's
        Agent will only be routed to this new Behavior if the topic
        specified in the message matches one of the topic names in
        this vector. Note that messages that do not specify a topic are
        sent to all Behaviors and conversely Behaviors that don't
        specify a topic list receive all messages irrespective of the
        topic the message specifies.

C++

``` {.sourceCode .cpp}
bool addBehavior(std::string nodeName, std::string agentName, std::string behaviorName, std::string module, std::vector<std::string> topics);
```

Java

``` {.sourceCode .java}
public boolean addBehavior(String nodeName, String agentName, String behaviorName, String module, StringVector topics);
```

connect
-------

This method establishes a connection to a running SAGE Server either on
the local machine or an a remote machine. It returns a boolean value
indicating if the connection was successfully established.

-   

    **serverIPAddress** \[string\]

    :   This is the IP address of the machine where the SAGE Server
        is running.

-   

    **portNumber** \[integer\]

    :   This is the port number that the SAGE Server is using to accept
        new connection. The port number is specified when the server
        is started.

C++

``` {.sourceCode .cpp}
bool connect(std::string serverIPAddress, int portNumber);
```

Java

``` {.sourceCode .java}
public boolean connect(String serverIPAddress, int portNumber);
```

clearExecutionResults
---------------------

This method clears the set of Result objects reported to the SAGE
Server. Control Applications can use this method after retrieving Result
objects using getExecutionResults to avoid duplicates.

C++

``` {.sourceCode .cpp}
void clearExecutionResults();
```

Java

``` {.sourceCode .java}
public void clearExecutionResults();
```

createAgent
-----------

This method creates a SAGE Agent in the specified SAGE Node. The Node is
identified by the name that was given when is was created. Node names
must be unique across Agent networks. The Agent is created in an
inactive state and must be activated before it will initiate any of its
Behaviors. This method returns a boolean value indicating whether or not
the Agent was created.

-   

    **nodeName** \[string\]

    :   This is the name of the SAGE Node in which the Agent will
        be created.

-   

    **agentName** \[string\]

    :   This is the name that will be assigned to the new SAGE Agent.
        Agent names must be unique within a SAGE Node.

C++

``` {.sourceCode .cpp}
bool createAgent(std::string nodeName, std::string agentName);
```

Java

``` {.sourceCode .java}
public boolean createAgent(String nodeName, String agentName);
```

disconnect
----------

This method ends a connection to a running SAGE Server.

C++

``` {.sourceCode .cpp}
void disconnect();
```

Java

``` {.sourceCode .java}
public void disconnect();
```

getAgentNames
-------------

This method returns the names of all the SAGE Agents residing in the
specified Node.

-   

    **nodeName** \[string\]

    :   This is the name of the SAGE Node whose Agent names are to
        be returned.

-   

    **agentNames** \[vector of strings\]

    :   This is a vector of strings containing SAGE Agent names.

C++

``` {.sourceCode .cpp}
bool getAgentNames(std::string nodeName, std::vector<std::string>& agentNames);
```

Java

``` {.sourceCode .java}
public boolean getAgentNames(String nodeName, StringVector agentNames);

StringVector is a Java class that provides a get(int i) method for retrieving the Agent name at index i.
```

getExecutionResults
-------------------

This method returns all the Result objects that have been reported to
the SAGE Server at the time of the call. This method does not clear the
set of Result objects. Subsequent calls to this method will return the
cumulative Result objects until the clearExecutionResults method is
called.

-   **results** \[vector of Result objects\]

C++

``` {.sourceCode .cpp}
void getExecutionResults(std::vector<Result>& results);
```

Java

``` {.sourceCode .java}
public void getExecutionResults(ResultVector results);

ResultVector is a Java class that provides a get(int i) method for retrieving the Result at index i. 
```

The Result class enables Behaviors to report the results of the
execution of either a action() method or a message() method. It consists
of the following members:

-   **m\_logMessages** while the container type varies across languages,
    the m\_logMessages member is a vector of strings and should is
    intended to provide a log of events that occurred during the
    execution of a Behavior.
-   **m\_exception** if the execution of code in the action() method or
    a message() methods generates an exception, the m\_exception string
    should contain text describing the cause of the exception.
-   

    **m\_executionResult** this member consists of an enumeration of type ExecutionResultType. It can have one of three values:

    :   -   `CompletionSuccess` - the method completed execution
            successfully
        -   `CompletionFailure` - the method completed execution but
            failed
        -   `ExceptionThrown` - code in the method caused an exception
            to be thrown. It is highly recommended that Behavior
            developers execute any code that can potentially generate
            exceptions withing a try - catch statement.

C++

``` {.sourceCode .cpp}
std::vector<std::string> m_logMessages;
std::string m_exception;
ExecutionResultType m_executionResult;
```

Java

``` {.sourceCode .java}
public ArrayList<String> m_logMessages = new ArrayList<String>();
public String m_exception = "";
public ExecutionResultType m_executionResult = ExecutionResultType.CompletionSuccess;
```

getNodeNames
------------

This method returns the names of all SAGE Nodes connected to this SAGE
Server.

-   

    **nodeNames** \[vector of strings\]

    :   This is a vector of strings containing SAGE Node names.

C++

``` {.sourceCode .cpp}
void getNodeNames(std::vector<std::string>& nodeNames);
```

Java

``` {.sourceCode .java}
public void getNodeNames(StringVector nodeNames);

StringVector is a Java class that provides a get(int i) method for retrieving the Node name at index i.
```

sendFile
--------

This method transmits a file to a SAGE Node. This capability is useful
for sending auxiliary data or executable library files needed by
Behaviors. Files transmitted to a SAGE Node running on the Windows
operating system are placed in the sage\\data subfolder of the
ProgramData folder (usually `C:\ProgramData\SAGE\data`). On the Linux
operating system, files are placed in the `/etc/sage/data` folder.

-   

    **nodeName** \[string\]

    :   This is the name of a SAGE Node where the file will be sent.

-   

    **filePath** \[string\]

    :   This is a fully qualified path to the file.

C++

``` {.sourceCode .cpp}
bool sendFile(std::string nodeName, std::string filePath);
```

Java

``` {.sourceCode .java}
public boolean sendFile(String nodeName, String filePath);
```

sendMessage
-----------

The sendMessage method enables the Control Application to send messages
to Agents.

C++

``` {.sourceCode .cpp}
bool sendMessage(const sageframework::Message& message)
```

Java

``` {.sourceCode .java}
public boolean sendMessage(Message message);
```

The Message class provides the necessary mechanism to specify a message
recipient and the message content.

-   

    **m\_targetNodeName** \[string\]

    :   This is the name of the SAGE Node that is the recipient of
        this message. If left empty, the message is sent to all the
        Nodes in the SAGE network.

-   

    **m\_targetAgentName** \[string\]

    :   This is the name of the SAGE Agent that is the recipient of
        this message. If left empty, the message is sent to all the
        Agents in the specified SAGE Node.

-   

    **m\_topic** \[string\]

    :   If specified, a topic name acts to direct a message to only
        those Behaviors that have that topic included in their
        topics list. This provides a filtering mechanism so that
        messages are only sent to those Behaviors interested in them.

-   

    **m\_message** \[string\]

    :   This is an arbitrary, application defined string that specifies
        what the message is.

-   

    **m\_data** \[string vector\]

    :   This string vector allows the message sender to include an
        arbitrary number of data items with the message. The content of
        that data is application defined.

C++

``` {.sourceCode .cpp}
class Message
{
public:
    std::string m_targetNodeName;
    std::string m_targetAgentName;
    std::string m_topic;
    std::string m_message;
    std::vector<std::string> m_data;
}
```

Java

``` {.sourceCode .java}
public class Message 
{
    public String m_targetNodeName;
    public String m_targetAgentName;
    public String m_topic;
    public String m_message;
    public ArrayList<String> m_data = new ArrayList<String>();
}
```

setAgentActive
--------------

This method sets the active state of an SAGE Agent. Agents are created
in an inactive state so that Agent Behaviors are not eligible for
execution. This allows the Control Application to populate the Agent
with Behaviors before any Behaviors execute. This method returns a
boolean value indicating whether or not the Agent state was set.

-   

    **nodeName** \[string\]

    :   This is the name of the SAGE Node in which the Agent resides.

-   

    **agentName** \[string\]

    :   This is the name of the Agent.

-   

    **isActive** \[boolean\]

    :   This is a boolean flag specifying whether the Agent state should
        be active (true), or inactive (false).

C++

``` {.sourceCode .cpp}
bool setAgentActive(std::string nodeName, std::string agentName, bool isActive);
```

Java

``` {.sourceCode .java}
public boolean setAgentActive(String nodeName, String agentName, boolean isActive);
```

removeAgent
-----------

This method removes a SAGE Agent from the specified SAGE Node. The Node
is identified by the name that was given when is was created. It is good
practice for Control applications to remove any Agents they created
before exiting. This method returns a boolean value indicating whether
or not the Agent was removed.

-   

    **nodeName** \[string\]

    :   This is the name of the SAGE Node in which the Agent will
        be removed.

-   

    **agentName** \[string\]

    :   This is the name of the Agent to remove.

C++

``` {.sourceCode .cpp}
bool removeAgent(std::string nodeName, std::string agentName);
```

Java

``` {.sourceCode .java}
public boolean removeAgent(String nodeName, String agentName);
```

removeBehavior
--------------

This method removes an existing Behavior from an Agent. This will cause
the Behavior's tearDown() method to be invoked.

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

waitForResult
-------------

This method causes the Control Application to block until a specified
Behavior executes either its action() method or its message() method and
generates a Result object. This capability is useful for synchronizing
the execution of the Control Application with events in the Agent
network.

-   

    **nodeName** \[string\]

    :   This is the name of a SAGE Node where the Agent resides.

-   

    **agentName** \[string\]

    :   This is the name of the SAGE Agent that has the target Behavior.

-   

    **behaviorName** \[string\]

    :   This is the name of the Behavior that generates the
        Result object.

-   

    **timeOut** \[int\]

    :   This the maximum time, in milliseconds, that the Control
        Application will block waiting for the Result object.

C++

``` {.sourceCode .cpp}
bool waitForResult(std::string nodeName, std::string agentName, std::string behaviorName, int timeOut);
```

Java

``` {.sourceCode .java}
public boolean waitForResult(String nodeName, String agentName, String behaviorName, int timeOut);
```
