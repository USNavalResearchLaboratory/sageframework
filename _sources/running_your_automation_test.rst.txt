Running Your Automation Test
===============================

You are ready to execute your test once you have constructed your Robot file with the proper SAGE Keywords.

All test cases are ran at the **Server level**.

The Server will communicate with each connected Node, whether local or remote. This allows you to store all your test cases in a single location while testing across multiple network connected machines.


**Execute a robot file using the command-line**

	.. code-block:: bat
	
		java -cp "%SAGE_CLASSPATH%" org.robotframework.RobotFramework path/to/my_tests/Hello.robot
	

**Execute a robot file using the SAGE App**

	1) In the SAGE App click the :mod:`Robot Interface` button.
	2) Click the :mod:`Add` button.
	3) Using the finder, select your Robot file.
	4) Once your Robot file has been added to the list, click the :mod:`Start` button.
	