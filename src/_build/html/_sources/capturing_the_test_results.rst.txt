.. container:: header-banner-color

	.. container:: header-banner-text
	
		Capturing the Test Results
		

Capturing the Test Results
===============================

A Result object provides a reporting mechanism back to the server to indicate the results of the execution of a Behavior’s methods.

The :mod:`m_logMessages` member is a vector of strings and is intended to provide a log of events that occurred during the execution of a Behavior.

You can capture messages back to your Robot report by appending to this :mod:`m_logMessages` list:

.. code-block:: java
	
		public boolean action(Result result)
		{
			System.out.println("Hello World from Action");
			result.m_logMessages.add("This is log message string3.");
			result.m_executionResult = ExecutionResultType.CompletionSuccess;
			return true;
		}
		
		public boolean message(Message message, Result result)
		{
			System.out.println("Got message");
			result.m_logMessages.add("This is log message from message string1.");
			result.m_executionResult = ExecutionResultType.CompletionSuccess;
			return true;	
		}

As a result, your Robot log should read:

.. code-block:: bat
	
	This is log message string3.
	
	This is log message from message string1.
	
	
While your console reads:
		
.. code-block:: bat
	
	Hello World from Action
	
	Got message

All execution logs and results are pushed back to the Server. Logs and results can be found on the **Server machine** in the following directories:

.. code-block:: bat
	
	Logs directory: "C:\ProgramData\SAGE\logs"
	
	Results directory: "C:\ProgramData\SAGE\results"