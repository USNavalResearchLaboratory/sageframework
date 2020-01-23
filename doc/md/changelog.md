Changelog

Changelog
=========

**SAGE 2.0.28**

Release date: 2019-12-09

Core and Builtins

> -   Issue \#52: Fixed bug in periodic actions that occured when the
>     period specified is very small. This could lead to a
>     race condition.

**SAGE 2.0.24**

Release date: 2019-08-05

Core and Builtins

> -   Issue \#51: Fixed bug, Java behaviors within JAR files that
>     include supportiing libraries could throw a duplicate class
>     exception due to how Java loads dependencies.

Server Application

> -   Some UI enhancements.
> -   Bug fixes.

**SAGE 2.0.22**

Release date: 2019-06-11

Core and Builtins

> -   Issue \#50: Fixed bug, under some conditions it was possible to
>     get the Server to hang if you were trying to stop it but it was
>     also waiting for a Result.
> -   Issue \#49: Behavior members are now checked on each run of
>     the scheduler. That way action and message methods can change
>     period, execution type, delay, and trigger message at runtime.
> -   Issue \#48: The environment variable SAGE\_HOME has been replaced
>     with SAGE\_SERVER\_HOME and SAGE\_NODE\_HOME.
> -   Issue \#47: Better error checking to make sure multiple Agents on
>     the same Node can't use different versions of a Behavior (Note:
>     they will use different instances).
> -   Issue \#46: Behaviors will now only be sent from the Server to the
>     Node if the Node does not already have the latest version.
> -   Issue \#45: Better information and error reporting from Nodes back
>     to the Server.
> -   Issue \#44: Fixed bug where under certain conditions a Node that
>     was shut down on purpose would show an error message.
> -   Issue \#43: For Java, Sage no longer uses the system CLASSPATH
>     environment variable and instead uses SAGE\_CLASSPATH.
> -   Issue \#42: All Java behaviors now must be in jars and are
>     internally loaded by a custom class loader.
> -   Issue \#41: Fixed a bug where a TimedCyclical behavior could drift
>     over time.
> -   Issue \#40: Fixed an issue where a new version of a Behavior was
>     not properly replacing the old version in a Node.
> -   Issue \#39: Added Keywords to Sage Robot Keywords to allow access
>     to individual parts of a Result object, for example "Get Result
>     Behavior Name".

Server Application

> -   Light and dark color scheme enhancements.
> -   Behavior Manager now a non-modal dialog window.
> -   Added application settings for specifying which non-modal dialog
>     windows stay on top of the main form window.
> -   Added double-click event handling for agent tree view nodes.
> -   Bug fixes.

**SAGE 1.2.18**

Release date: 2018-10-08

Core and Builtins

> -   Issue \#38: Fixed message broadcasting bug.
> -   Issue \#37: Added JSON based introspection for getting detailed
>     Agent state.
> -   Issue \#36: Fixed introspection bug.
> -   Issue \#35: Added new scheduling mechanism that allows users to
>     control the precision of the Node scheduler to control the CPU
>     usage of SageNodeConsole.

Server Application

> -   Improved UI interactions for selecting Nodes, Agents,
>     and Behaviors.
> -   Improved Network graph view layout.
> -   Added zoom control to Network graph view.
> -   Added application settings for controlling Node
>     scheduler precision.
> -   Added light and dark theme selections.
> -   Fixed core bugs.

**SAGE 1.1.14**

Release date: 2017-09-28

Core and Builtins

> -   Issue \#34: User's CLASSPATH is now appended to the
>     runtime CLASSPATH.
> -   Issue \#33: Added new SAGE Robot keyword Clear Results.
> -   Issue \#32: BehaviorModule class now only returns a single
>     behavior instead of a vector of behaviors. This addresses
>     potential memory corruption due to cross
>     DLL allocation/deallocation.
> -   Issue \#31: Fixed bug that would cause JVM to unexpectedly crash.
> -   Issue \#30: Added server methods to load and save agent networks
>     so that clients don't have to instantiate SAGE internal classes.
> -   Issue \#29: Fixed bug that would cause the loss of Result objects.
> -   Issue \#28: Fixed crash of Robot caused by Result objects
>     being corrupted.
> -   Issue \#27: Fixed GDI resource issue.
> -   Issue \#26: Fixed issue with Behavior files not being overwritten
>     on Node machine if Server contained newer version of file.
> -   Issue \#25: Fixed problem with SAGE Server memory leak caused by
>     the server running for very long periods of time.
> -   Issue \#24: Fixed memory leak in SAGE Node code.
> -   Issue \#23: Fixed issue where Node would not reconnect to SAGE
>     Server after stopping then starting Server.
> -   Issue \#22: Added support for sending files back to the server.
>     Base class functionality now includes sendFile method.
> -   Issue \#21: Added support for persistent networks. Network
>     settings can be stored as SAGE extension files for
>     save/load capability.

Server Application

> -   View SAGE User Guide from Help window.
> -   Add Network graph view.
> -   Integrate Import and Export network settings.
> -   Add "Activate All Agents", " Deactiviate All Agents", and "Remove
>     All Agents" buttons.
> -   Update layout and icons.

**SAGE 1.0.12**

Release date: 2017-06-27

Core and Builtins

> -   Issue \#20: Fixed problem with SAGE ServerApp not allowing
>     behaviors to be overwritten in the Behavior Manager.
> -   Issue \#19: Fixed issue in SAGE ServerApp where behaviors would
>     not show up in the tree view until the one of the behaviors'
>     methods is called.
> -   Issue \#18: Fixed problem where sending a message back to the
>     sender in the message() method would crash SAGE.
> -   Issue \#17: Added support for packaged behaviors. Behaviors and
>     supporting class files may now be packaged into JAR and EGG files.

Server Application

> -   Items respond immediately to mouse-clicks when not in focus.
> -   Update layout and icons.
> -   Add bi-directional object selection.

Documentation

> -   Add Robot Framework background.
> -   Update SAGE Server Application.

**SAGE 1.0.11**

Release date: 2017-03-07

Core and Builtins

> -   Issue \#16: JVM path automatically appended to the system
>     environment PATH variable.
> -   Issue \#15: Modified Namespaces for SageBehaviorInterface (both
>     Java and Python module) to nrl.sage.BehaviorInterface,
>     SageRemoteInterface to nrl.sage.BehaviorInterface, and
>     SageLocalInterface to nrl.sage.BehaviorInterface.
> -   Issue \#14: Linux SageNode rpm now correctly sets folder
>     permissions in /etc/sage.
> -   Issue \#13: Fixed problem with running robot files in
>     SageServerApp when the user account does not have
>     administrator privileges.
> -   Issue \#12: Added a package name to the
>     SageRemoteInterface.jar library. Java applications using that jar
>     must import sageremoteinterface.\*
> -   Issue \#11: Added support that enables SAGE to be installed and
>     operate properly on machines that don't have Java and/or
>     Python installed. (Windows version only)
> -   Issue \#10: Fixed problem with importing Java behaviors using the
>     behavior manager in SageServerApp.

**SAGE 1.0.10**

Release date: 2016-12-15

Core and Builtins

> -   Issue \#9: Improved Robot error reporting to include more
>     informative messages.
> -   Issue \#8: Fixed issue where the SageServer was not updated when
>     an agent was removed by another agent that resides in the
>     same Node.

**SAGE 1.0.9**

Release date: 2016-10-31

Core and Builtins

> -   Issue \#7: Added source node and source agent fields to messages
>     sent to Behaviors.
> -   Issue \#6: Run Step and Report Result now throw an exception on
>     result = "failure".
> -   Issue \#5: Routines in SageRobotKeywords.java now return a
>     boolean value.

**SAGE 1.0.8**

Release date: 2016-10-07

Documentation

> -   Update API Reference section with C++ Behavior file example.

Library

> -   Update Boost to 1.61.0.
> -   Removed Pluma dependencies.

**SAGE 1.0.7**

Release date: 2016-09-28

Core and Builtins

> -   Issue \#4: Added support for asynchronous/multi-threaded calls.
> -   Issue \#3: Wait For Result SageRobotKeyword now takes an
>     additional argument that indicates which method to wait on to
>     generate a result.
> -   Issue \#2: The Behavior methods setUp() and tearDown() now are
>     called with a Result parameter.
> -   Issue \#1: Fixed bug that continued Behavior process after
>     internal error occurred in Behavior methods setUp(), action(),
>     message(), or tearDown().

Server Application

> -   Add new Options menu.
> -   Add new Options and Server tool strips.
> -   Add context sensitive interaction between the AgentTreeView and
>     the menu/toolstrip tools.

