Installation

5 easy-to-follow steps.

Installation
============

Requirements
------------

Note that SAGE may be compatible with other versions of Windows and
Linux distributions not listed.

-   Windows 7, 8, 8.1, 10, Server 2013
-   Red Hat Enterprise Linux 7
-   Ubuntu 14

### Optional

-   [Python](https://www.python.org/downloads/) 2.6 or 2.7
-   [Java SE Runtime
    Environment](http://www.oracle.com/technetwork/java/javase/downloads/index.html)
    8 and up.

Windows
-------

### 1. Start the SAGE Server or Node Installer executable

SAGE Server and Node softwares are packaged independently and include
separate installers.

After the SAGE distribution has finished downloading it should be
available in your download directory. Start the SAGE Server or SAGE Node
Installer executable. You may be asked to install Visuall C++ Runtime.
If so, select ‘OK’ and proceeed. Select repair if needed.

![](_images/sage_installer_imgs/visual_c_install.png)

Select the ‘Next’ button to continue with installing SAGE.

![](_images/sage_installer_imgs/setup_begin.png)

### 2. Review the SAGE license agreement

Review the terms of agreement. To proceed, agree to the terms of the
license agreement.

Select the ‘Next’ button to continue.

![](_images/sage_installer_imgs/setup_license.PNG)

### 3. Select your installation folder

Specify the folder where you want SAGE to be installed. The default
folder will be in your Program Files directory.

Select the ‘Next’ button to continue.

![](_images/sage_installer_imgs/setup_filePath.png)

### 4. Confirm SAGE installation

Select the ‘Next’ button to begin the installation. You may get a
security warning to run this file. Select ‘Yes’ to allow SAGE to proceed
with installation.

![](_images/sage_installer_imgs/setup_ready.png)

### 5. Installation complete

Once the installation is complete you can now launch SAGE.

![](_images/sage_installer_imgs/setup_complete.png)

Environment variables
---------------------

The following System variables will be automatically added:

**Additional User variables**

Add the following User variables if you would like to include support
for `Java` or `Python` Behaviors.

Your actual path may be set with a different name or version number.
Ensure each variable points to the directory of your distribution.

**Update your PATH System variable**

Edit your PATH System variable to append your Users variables.

Java installation requires access to *jvm.dll* and *java.exe*.

Python requires access to *python.exe*.

Installation on Linux
---------------------

On a terminal enter the following command, assuming the current sage
distribution rpms are in the local folder:

``` {.sourceCode .bat}
sudo rpm -Uvh nrl-sage-node-*.rpm
```

Note that the SDK package is optional and needed only for C++ behavior
development. Java and Python Behaviors can be developed without it. Note
that the Linux Server is still considered to be an experimental version.
To install the SDK and Server:

``` {.sourceCode .bat}
sudo rpm -Uvh nrl-sage-sdk-*.rpm
sudo rpm -Uvh nrl-sage-server-*.rpm
```

If you're on a Debian based Linux that does not have rpm, such as
Ubuntu, you can install the alien package. Then the above rpm commands
will work.

``` {.sourceCode .bat}
sudo apt-get install alien
```

**Environment variables**

SAGE Node needs the Java JVM dynamic library to be in the runtime
library search path. This is accomplished by including its location in
the `LD_LIBRARY_PATH` environment variable. This is typically done by
including the definition in .bashrc file or .profile file.

It can also be temporarily set using the same command, typically:

If you intend to use the Robot Framework on Linux with the SAGE Server
you will need to define the `SAGE_ROBOT_LIBRARY` environment variable.
