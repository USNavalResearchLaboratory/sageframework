.. container:: header-banner-color

	.. container:: header-banner-text
	
		Managing Behavior Files
		

Managing Behavior Files
===============================

The Server hosts and manages a Behavior repository located in the following directory:

+-------------+----------------------------------+
|             | Behavior Path                    |
+=============+==================================+
| **Windows** | C:\\ProgramData\\Sage\\behaviors |
+-------------+----------------------------------+	
| **Linux**   | /etc/Sage/behaviors              |
+-------------+----------------------------------+

Behavior files must be placed on the Server machine in order for the Server to distribute them across the network. This is because the SAGE runtime looks inside these directory paths before deploying an executable module to a target Node.

**Updating files using SAGE App**

It is recommended to use the :mod:`Behavior Manager` found within the SAGE App to manage your Behaviors.
It provides a syntax check to ensure that the file you are attempting to upload is a properly written and supported SAGE Behavior.

	1) In the SAGE App, click the :mod:`Behavior Manager` button.
	2) Select the :mod:`Manage` drop-down menu and click :mod:`Add Modules`.
	3) Select the targeted file and click :mod:`Ok`.
 
 Upon successful upload, your file will be copied to the proper sub-directory.

**Manually updating files**

The behaviors directory contains sub-directories for SAGE supported languages :mod:`C++`, :mod:`Java`, and :mod:`Python`. 

| :mod:`Windows64`, :mod:`Windows32`, :mod:`Linux64`, :mod:`Linux32`  C++ behavior files directory - Behavior.cpp
| :mod:`Python`  Python behavior files directory - Behavior.egg
| :mod:`Java`  Java behavior files directory - Behavior.jar

You can manually move your Behaviors to their corresponding sub-directory. 

Only SAGE Behaviors should reside in the Behavior directory. Supplemental libraries or files should not be stored within the Behavior repository.