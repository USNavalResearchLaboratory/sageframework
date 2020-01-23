Help and FAQ

Help and FAQ
============

-   Do I need to install both the Server and the Node on every machine?\_
-   How can I verify the server is running?\_
-   Is there a default port number that is commonly used?\_
-   When I deploy SAGE agents to other VMs, how can I verify that they are fully operational?\_
-   Why am I getting a python27.dll is missing error when attempting to connect a SAGE Node?\_
-   Why am I getting a jvm.dll is missing error when attempting to connect a SAGE Node?\_
-   Why am I receiving a 'sageframework.SageLocalInterfaceWrapperPINVOKE' exception upon starting the SAGE App?\_
-   How do I resolve "error while loading shared libraries: libjvm.so" when starting a Node on Linux?\_
-   Why am I getting "ImportError: No module named robot"?\_
-   Why do I receive "WARNING: An illegal reflective access operation has occurred" upon running a Robot file?\_
-   Why does the SAGE App not open?\_

**Do I need to install both the Server and the Node on every machine?**

No. Only one Server instance is required. All tests are to be launched
from the machine that has the SAGE Server instance. The Server will
distribute behavior files to the target Nodes via message. This gives
SAGE users the ability to control complex test scenarios, involving
multiple nodes and agents across various machines, from a single
controller entity.

**How can I verify the server is running?**

To verify a running SAGE Server instance, check the prompt window and
confirm that the following text is displayed, "SAGE server started
listening on port: {portNumber}". This indicates that the SAGE Server is
active and listening over the selected port.

**Is there a default port number that is commonly used?**

There is no default port number for SAGE. It is recommended to avoid
using dedicated port numbers, such as 21 (FTP), 22 (SSH), and 80 (HTTP).
For a list of unassigned port numbers visit [Internet Assigned Numbers
Authority
(IANA)](http://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml).

**When I deploy SAGE agents to other VMs, how can I verify that they are
fully operational?**

It is important to not confuse the terms SAGE agents and SAGE nodes.
SAGE agents are created on-the-fly using a SAGE controller interface
(Robot Framework by default). Currently, there is only support for agent
creation using Robot Keyword, `Create Agent`. When you create an agent,
it is deployed to a SAGE Node. SAGE nodes are containers that are
deployed to a VM/machine. These containers store agents upon their
creation.

When you initialize a node, you will assign it a IP Address and a port
number value. The IP Address value should be the IP Address of the
server VM/machine. The port number must match that of the recipient
server's port number. A matching port number and valid IP is essential
for connecting a node to the intended SAGE Server. Once connected, check
the prompt window for the following text, "Connected to SAGE runtime
using ip address {server\_IP\_address} : {portNumber}", to verify the
node is operational. It is recommended to download the example files to
get a better understanding of the SAGE Node deployment and agent
creation process.

**Why am I getting a python27.dll is missing error when attempting to
connect a SAGE Node?**

This error either means there are multiple Python instances installed on
your machine, a non-supported Python version installed on your machine,
or your installed Python bit version differs from that of the installed
SAGE. SAGE currently supports [Python 2.6 or
2.7](https://www.python.org/downloads/). Be sure you have one of the two
installed. Next, be sure the bit version is consistent with the
installed SAGE bit version. To check the Python bit version, start
Python in the command prompt and it will display the bit number. Check
your Python directory e.g C:\\\\Python27 and verify that the
python27.dll file is there. If not, it is recommended to uninstall the
current Python instance and to do a fresh install. Be sure your
envvar-label `PYTHONHOME` and `PATH` are set and updated, respectively.
Visit [here](http://www.computerhope.com/issues/ch000549.htm) to learn
how to add and edit environment variables.

**Why am I getting a jvm.dll is missing error when attempting to connect
a SAGE Node?**

This error either means there are multiple Java instances installed on
your machine, a non-supported Java version installed on your machine, or
your installed Java bit version differs from that of the installed SAGE.
SAGE currently supports [Java
8](http://www.oracle.com/technetwork/java/javase/downloads/index.html) .
Be sure you have a supported version installed. Next, be sure the bit
version is consistent with the installed SAGE bit version. To check the
Java bit version, type java -version in the command prompt. Check your
Java JDK server directory
e.g C:\\\\Program Files\\\\Java\\\\jdk1.8.0\_91\\\\jre\\\\bin\\\\server
and verify that the jvm.dll file is there. If not, it is recommended to
uninstall the current Java instance and to do a fresh install. Be sure
your envvar-label `JAVAHOME` and `PATH` are set and updated,
respectively. Visit
[here](http://www.computerhope.com/issues/ch000549.htm) to learn how to
add and edit environment variables.

**Why am I receiving a 'sageframework.SageLocalInterfaceWrapperPINVOKE'
exception upon starting the SAGE App?**

The SAGE App goes through a behavior discovery process to locate local
"Native", "Java", and "Python" behavior files. This exception is thrown
if both Java and Python are not found on your machine. Be sure your
envvar-label `PYTHONHOME`, `JAVAHOME`, and `PATH`, are set and updated.
Visit [here](http://www.computerhope.com/issues/ch000549.htm) to learn
how to add and edit environment variables.

**How do I resolve "error while loading shared libraries: libjvm.so"
when starting a Node on Linux?**

SAGE needs JVM dynamic library to be in the runtime library search path.
This is accomplished by including the location in the LD\_LIBRARY\_PATH
environmentvariable. This is typically done by including the definintion
in .bashrc file or .profile file. It can also be temporarily set using
the same command, typically:
export LD\_LIBRARY\_PATH=\$LD\_LIBRARY\_PATH:{JRE\_HOME}/lib/amd64/server

**Why am I getting "ImportError: No module named robot"?**

This error is returned when the robot framework module cannot be found.
By default, robot-framework is distributed with SAGE and appended to the
envvar-label `SAGE_CLASSPATH` system Environment variable upon install.
Be sure to verify that the robotframework-2.9.2.jar is located in the
*"C:\\Program Files\\NRL\\SageServer"* directory. In addition, check the
envvar-label `SAGE_CLASSPATH` environment variable to ensure the
absolute path to the jar *"C:\\Program Files\\NRL
\\SageServer\\robotframework-2.9.2.jar"* has been added and appears as
the first item in the list.

**Why do I receive "WARNING: An illegal reflective access operation has
occurred" upon running a Robot file?**

This warning is a known issue in the current Robot Framework build and
is caused by Java 9+ reflection and package access changes. You can
continue with testing until Robot Framework pushes a new update to
address the changes.

**Why does the SAGE App not open?**

If you said yes to Python, make sure you have `PYTHONHOME` set correctly
and that it is in your `PATH`.
