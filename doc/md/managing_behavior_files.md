Managing Behavior Files

Managing Behavior Files
=======================

The Server hosts and manages a Behavior repository located in the
following directory:

                 Behavior Path
  -------------- -----------------------------------
  **Windows**    C:\\ProgramData\\Sage\\behaviors
  **Linux**      /etc/Sage/behaviors

Behavior files must be placed on the Server machine in order for the
Server to distribute them across the network. This is because the SAGE
runtime looks inside these directory paths before deploying an
executable module to a target Node.

**Manually updating files**

The behaviors directory contains sub-directories for SAGE supported
languages C++, Java, and Python.

Windows64, Windows32, Linux64, Linux32 C++ behavior files directory -
Behavior.cpp\
Python Python behavior files directory - Behavior.egg\
Java Java behavior files directory - Behavior.jar

You can manually move your Behaviors to their corresponding
sub-directory.

**Updating files using SAGE App**

It is recommended to use the Behavior Manager found within the SAGE App
to manage your Behaviors. It provides a syntax check to ensure that the
file you are attempting to upload is a properly written and supported
SAGE Behavior.

> 1)  In the SAGE App, click the Behavior Manager button.
> 2)  Select the Manage drop-down menu and click Add Modules.
> 3)  Select the targeted file and click Ok.

> Upon successful upload, your file will be copied to the proper
> sub-directory.
