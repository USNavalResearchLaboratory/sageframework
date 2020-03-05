
.. container:: header-banner-color

	.. container:: header-banner-text
	
		Using Supplemental Files in Your Automation


Using Supplemental Files in Your Automation
================================================================================================

There are many cases in which your automation test may require files other than Behaviors, such as images, text files, executables, or other libraries.

These files can be used to support your automation scripts at the **Node** level.

Supplemental files should be manually placed in the following directory on the targeted **Node machine**:

+-------------+-----------------------------+
|             | Data Path                   |
+=============+=============================+
| **Windows** | C:\\ProgramData\\Sage\\data |
+-------------+-----------------------------+
| **Linux**   | /etc/Sage/data              |
+-------------+-----------------------------+


**Update SAGE_CLASSPATH environment variable if needed**

SAGE runtime uses the :mod:`SAGE_CLASSPATH` environment variable. 

If your Behavior needs to load other classes found within a separate library, such as a JAR file, be sure to append that file to the :mod:`SAGE_CLASSPATH` environment variable.

	1) On the targeted Node machine, copy the library into the SAGE data directory.
	2) Add your library to the :mod:`SAGE_CLASSPATH` environment variable, e.g., *C:\\ProgramData\\Sage\\data\\<xxxxx.jar>*.


