
.. container:: header-banner-color

	.. container:: header-banner-text
	
		Writing a SAGE Behavior
		

Writing a SAGE Behavior
============================================

SAGE Behaviors are classes that are be developed, outside of the main SAGE codebase, and ran by SAGE Agents. An example Behavior might be a Python module that when invoked uses a Java package to test an external application and make the test results available to the SAGE Server. 

Behaviors can be written so that agents can perform either **reactively in response to an incoming message**, or **proactively on a continuous or one time basis.**

Behavior objects must contain four methods that constitute their execution repertoire:

- ``setUp`` This method is called when a Behavior is instantiated and is expected to perform initialization activities. Behaviors are instantiated when an Agent becomes active, or when a new Behavior is added to an active Agent.
- ``action`` This method implements the proactive execution of a Behavior based on the execution mode specified.
	- OneShot execution activates the ``action`` method once when the Agent is activated. 
	- Periodic execution activates the ``action`` method continuously. 
	- TimedPeriodic execution activates the ``action`` method every *n* milliseconds.
	- OnMessage activates the ``action`` method upon the receipt of a specific message. 
- ``message`` This method is called when an Agent receives a message. Behaviors can specify a topic filter consisting of a list of topics that the Behavior is interested in. Incoming messages that do not specify one of those topics in the topic filter are not propagated to the Behavior.
- ``tearDown`` This method is called on each Behavior when an Agent is deactivated. It is expected to perform any de-initialization activities necessary to bring the system to a known state.

Each method can populate a Result object that includes the result of the execution as well as a log of the activities performed during the execution. Result objects that specify an execution result other than ``NotSet`` (see below) are passed back to the Server. 

Behaviors are run by (within) a SAGE Node process. When a Behavior is added to an :ref:`agent-label`, its executable module is sent to the Node containing the Agent so that it can be scheduled for execution by that Node.




Inheritance from the base class
++++++++++++++++++++++++++++++++++++++++++++++++++++


Behaviors can be written in C++, Java, or Python. In each language a SAGE Behavior is a class and is required to conform to a specific interface. This includes inheriting from a base class and using specific objects provided by the SAGE Framework. To develop C++ Behaviors you will need to install the SAGE SDK. Behaviors developed in Java or Python do not require the SAGE SDK. 


Every C++ Behavior class, in this example named "ExampleCppBehavior", is a subclass (child) of NativePluginInterface. The NativePluginInterface header file is available in the SAGE SDK.

.. container:: padding

	.. container:: toggle

		.. container:: header

			C++
		
		.. code-block:: cpp
			
			class ExampleCppBehavior : public NativePluginInterface
			

In Java every Behavior is a subclass of SageBehavior. The Java SageBehavior class code is in the SageJavaBehaviorInterface.jar file distributed with the SAGE Node installer. The Java source files are distributed in the SAGE SDK.

.. container:: padding

	.. container:: toggle

		.. container:: header

			Java
			
		.. code-block:: java

			public class ExampleJavaBehavior extends SageBehavior
	

In Python every Behavior is a subclass of SageBehavior. The Python SageBehavior code is in the file SagePythonBehaviorInterface-1.0-py2.7.egg which is distributed with the SAGE Node and SAGE Server installers. The code itself is distributed in the SAGE SDK. 

.. container:: padding

	.. container:: toggle

		.. container:: header

			Python
			
		.. code-block:: python

			class ExamplePythonBehavior(SageBehavior.SageBehavior):


Result object
++++++++++++++++++++++++++++++++++++++++++++++++++++
			
A Result object provides a reporting mechanism back to the Server to indicate the results of the execution of a Behavior's :mod:`setup()`, :mod:`action()`, :mod:`message()`, or :mod:`teardown()` methods. 

A Result object contains the following three members that should be assigned appropriate values by the Behavior developer:

.. container:: padding

	.. container:: toggle

		.. container:: header

			C++

		.. code-block:: cpp

			std::vector<std::string> m_logMessages;
			std::string m_exception;
			ExecutionResultType m_executionResult;

	.. container:: toggle

		.. container:: header

			Java

		.. code-block:: java

			public ArrayList<String> m_logMessages = new ArrayList<String>();
			public String m_exception = "";
			public ExecutionResultType m_executionResult = ExecutionResultType.CompletionSuccess;

	.. container:: toggle

		.. container:: header

			Python

		.. code-block:: python

			self.m_logMessages = []
			self.m_exception = ""
			self.m_executionResult = ExecutionResultType.CompletionSuccess

- **m_logMessages** is a vector of strings and is intended to provide a log of events that occurred during the execution of a Behavior. 

- **m_exception** if the execution of code in the method generates an exception, the m_exception string should contain text describing the cause of the exception.

- **m_executionResult** this member consists of an enumeration of type ExecutionResultType. It can have one of three values:
	- ``CompletionSuccess`` - the method completed execution successfully
	- ``CompletionFailure`` - the method completed execution but failed 
	- ``ExceptionThrown`` - code in the method caused an exception to be thrown. It is highly recommended that Behavior developers execute any code that can potentially generate exceptions within a try - catch statement.
	- ``NotSet`` - the method has not yet assigned m_executionResult a value.


Behavior constructor
++++++++++++++++++++++++++++++++++++++++++++

It is a requirement for SAGE Behaviors that their **constructors only set member variables**. There should be no significant code executed in a Behavior constructor. This is because the SAGE Framework may instantiate and destroy Behaviors when doing inquiry functionality.  Any startup related code should be put in the :mod:`setUp()` method.  

Behaviors in all three languages have the same members declared in the base class.    

There are six members:

- **m_name** [a string]
	This is the Behavior's name.
	Other parts of the SAGE system depend on this name (and the Behavior's filename) to find and execute the Behavior.
- **m_description** [a string]
	A description of the Behavior.
- **m_executionType**
	Set to ``OneShot``, ``Cyclical``, ``TimedCyclical``, ``OnMessage``, or ``NoExecution``.
	These values all pertain to when the Behavior's action() method will be invoked.
	
	- ``OneShot`` action() is called once when the Agent is activated.
	- ``Cyclical`` action() is called continuously after the Agent is activated.
	- ``TimedCyclical`` action() is called continuously every m_period milliseconds after the Agent is activated.
	- ``OnMessage`` action() is called upon the receipt of a message that matches m_triggerMessage. Do not confuse this with the Behavior's message() method.
	- ``NoExecution`` action() is not called.  The Behavior is still created, setUp() is invoked, and the Behavior can be used via the message() method.
- **m_triggerMessage** [a string]
	If the Behavior's **m_executionType** is ``OnMessage`` then action() will be invoked when a message is sent from elsewhere in the SAGE system that matches the string **m_triggerMessage**.
- **m_period** [time in in milliseconds]
	If the **m_executionType** is ``TimedCyclical`` then the action() method will be called every **m_period** milliseconds.
- **m_delay** [time in in milliseconds]
	This is the initial amount of time the Behavior's Agent will wait before calling the Behavior's action(). 
	A Behavior is instantiated when its Agent is activated or when a Behavior is added to an active Agent. At that time the Behavior's setUp() method is also called. If the Behavior has defined an **m_executionType** of ``OneShot``, ``Cyclical``, or ``TimedCyclical`` then the action() will first be called after **m_delay** milliseconds have passed.
	
	
In C++, SAGE enforces this requirement by requiring that a Behavior's constructor be created using a macro **SAGE_BEHAVIOR** (defined in NativePluginInterface.h).  Use of this macro also allows a SAGE Server running on Windows to inspect an .so file created under Linux. 

.. container:: toggle

		.. container:: header

			C++

		.. code-block:: cpp

			SAGE_BEHAVIOR(CLASS_NAME, BEHAVIOR_NAME, BEHAVIOR_DESCRIPTION, EXECUTION_TYPE, TRIGGER_MESSAGE, PERIOD, DELAY)
	
The first parameter should be the name of the class.  The remaining map to each of the six members.
  
In Java and Python, the members should be set in the constructor.

.. container:: toggle

		.. container:: header

			Java

		.. code-block:: java

			public ExampleJavaBehavior()
				{
					m_name = "SimpleExample";
					m_description = "Simple description";
					m_executionType = ExecutionType.OneShot;
					m_triggerMessage = "";
					m_period = 0;
					m_delay = 0;
				}
			
.. container:: toggle

		.. container:: header

			Python

		.. code-block:: python

			def __init__(self):
					super(ExamplePythonBehavior, self).__init__()
					self.m_name = "SimpleExample"
					self.m_description = "Simple description"
					self.m_executionType = ExecutionType.ExecutionType.OneShot
					self.m_triggerMessage = ""
					self.m_period = 0
					self.m_delay = 0


Behavior setUp
+++++++++++++++++++++++++

This method is called when a Behavior is instantiated and is expected to perform initialization activities. Behaviors are instantiated when an Agent becomes active, or when a new Behavior is added to an active Agent.

- **result** [Result object]
	Results of this method's execution should be reported using Result object. Result objects contain m_logMessages, m_exception, or m_executionResult.


It returns true or false; false indicates that there is a SAGE Behavior internal error meaning this Behavior should not be run again. 

.. container:: toggle

		.. container:: header

			C++

		.. code-block:: cpp

			bool ExampleCppBehavior::setUp(sageframework::Result& result)
			{
					result.m_logMessages.push_back("This is log message string3.");
					result.m_exception = "Nothing exceptional here.";
					result.m_executionResult = sageframework::ExecutionResultType::NotSet;
					return true;
			}
					
.. container:: toggle

		.. container:: header

			Java

		.. code-block:: java

			public boolean setUp(Result result)
			{
					result.m_logMessages.add("This is log message string3.");
					result.m_exception = "Nothing exceptional here.";
					result.m_executionResult = ExecutionResultType.NotSet;
					return true;
			}
					
.. container:: toggle

		.. container:: header

			Python

		.. code-block:: python

			def setUp(self, result):
			        result.m_logMessages.append("This is log message string3.")
					result.m_exception = "Nothing exceptional here."
					result.m_executionResult = ExecutionResultType.ExecutionResultType.NotSet
					return True

Behavior action
++++++++++++++++++++++++++++++++++++++

This method is called based on the execution type (m_executionType) specified in the Behavior constructor. Execution types include, :mod:`OneShot`, :mod:`Cyclical`, :mod:`TimedCyclical`, :mod:`OnMessage`, or :mod:`NoExecution`. This is method is a proactive response.

- **result** [Result object]
	Results of this method's execution should be reported using Result object. Result objects contain m_logMessages, m_exception, or m_executionResult.
	
It returns true or false; false indicates that there is a SAGE Behavior internal error meaning this Behavior should not be run again.

.. container:: toggle

		.. container:: header

			C++

		.. code-block:: cpp

			bool ExampleCppBehavior::action(sageframework::Result& result)
			{	
				result.m_logMessages.push_back("This is log message string.");
				result.m_exception = "Nothing exceptional here.";
				result.m_executionResult = sageframework::ExecutionResultType::CompletionSuccess;
				return true;
			}
					
.. container:: toggle

		.. container:: header

			Java

		.. code-block:: java

			public boolean action(Result result)
			{
					result.m_logMessages.add("This is log message string.");
					result.m_exception = "Nothing exceptional here.";
					result.m_executionResult = ExecutionResultType.CompletionSuccess;
					return true;
			}
					
.. container:: toggle

		.. container:: header

			Python

		.. code-block:: python

			def action(self, result):
			        result.m_logMessages.append("This is log message string.")
					result.m_exception = "Nothing exceptional here."
					result.m_executionResult = ExecutionResultType.ExecutionResultType.CompletionSuccess
					return True


Behavior message
++++++++++++++++++++++++++++++++++++++

This method is called when an Agent receives a message. This is method is a reactive response. Elsewhere is the SAGE system Behaviors are specified to have a topic filter consisting of a list of topics that the Behavior is interested in. 

Incoming messages that do not specify one of those topics in the topic filter are not propagated to the Behavior.

- **Message** [Message object]
	Provides the necessary mechanism to retrieve the message content sent to the message recipient. Messages may contain m_targetNodeName, m_targetAgentName, m_topic, m_message, and m_data.
- **result** [Result object]
	Results of this method's execution should be reported using Result object. Result objects contain m_logMessages, m_exception, or m_executionResult.


It returns true or false; false indicates that there is a SAGE Behavior internal error meaning this Behavior should not be run again.

.. container:: toggle

		.. container:: header

			C++

		.. code-block:: cpp

			bool ExampleCppBehavior::message(const sageframework::Message& message, sageframework::Result& result)
			{
				std::cout << "Got message  " << message.m_message << " on topic " << message.m_topic << std::endl;
				std::cout << "len of m_data is " << message.m_data.size() << std::endl;
				result.m_logMessages.push_back("This is log message from message string1.");
				result.m_exception = "Nothing exceptional here.";
				result.m_executionResult = sageframework::ExecutionResultType::CompletionSuccess;
				return true;
			}
					
.. container:: toggle

		.. container:: header

			Java

		.. code-block:: java

				public boolean message(Message message, Result result)
				{
					System.out.println("Got message " + message.m_message + " on topic " + message.m_topic);
					System.out.println("length of m_data is", message.m_data.size());
					result.m_logMessages.add("This is log message from message string1.");
					result.m_exception = "Nothing exceptional here.";
					result.m_executionResult = ExecutionResultType.CompletionSuccess;
					return true;	
				}
					
.. container:: toggle

		.. container:: header

			Python

		.. code-block:: python

				def message(self, message, result):
					print("Got message ", message.m_message, " on topic ", message.m_topic)
					print("length of m_data is", len(message.m_data) )
					result.m_logMessages.append("This is log message from message string1.")
					result.m_exception = "Nothing exceptional here."
					result.m_executionResult = ExecutionResultType.ExecutionResultType.CompletionSuccess	
					return True


Behavior tearDown
+++++++++++++++++++++++++++++++++++

This method is called when the Agent is deactivated.  It should perform any clean-up and shutdown activities. 

- **result** [Result object]
	Results of this method's execution should be reported using Result object. Result objects contain m_logMessages, m_exception, or m_executionResult.

It returns true or false; false indicates that there is a SAGE Behavior internal error meaning this Behavior should not be run again.

.. container:: toggle

		.. container:: header

			C++

		.. code-block:: cpp

			bool ExampleCppBehavior::tearDown(sageframework::Result& result)
			{
					result.m_logMessages.push_back("This is log message string3.");
					result.m_exception = "Nothing exceptional here.";
					result.m_executionResult = sageframework::ExecutionResultType::NotSet;
					return true;
			}
					
.. container:: toggle

		.. container:: header

			Java

		.. code-block:: java

			public boolean tearDown(Result result)
			{
					result.m_logMessages.add("This is log message string3.");
					result.m_exception = "Nothing exceptional here.";
					result.m_executionResult = ExecutionResultType.NotSet;
					return true;
			}
					
.. container:: toggle

		.. container:: header

			Python

		.. code-block:: python

			def tearDown(self, result):
			        result.m_logMessages.append("This is log message string3.")
					result.m_exception = "Nothing exceptional here."
					result.m_executionResult = ExecutionResultType.ExecutionResultType.NotSet
					return True


C++ header file
++++++++++++++++++++++++++++++++++++++++

C++ requires a header file. In addition to providing declarations of the required four methods, the header file must include a line required by the Boost Dll library that SAGE uses to manage dynamic load libraries. 

The static create() method is a factory method that creates instances of the behavior class. 

The BOOST_DLL_ALIAS statement exports that symbol so that SAGE can find it in the dynamic load library and invoke it. 

The use of a factory method to load the behavior class means that each C++ dll/so can only contain one behavior class. While this is a restriction, its likely a good practice to follow in general.

Here is a example header file called ExampleCppBehavior.h:

.. code-block:: cpp

	#pragma once

	#include "NativePluginInterface.h"

	// This class will be compiled into ExampleCppBehavior.dll under Windows
	// or ExampleCppBehavior.so under Linux.
	//
	class ExampleCppBehavior : public NativePluginInterface
	{
	public:
		ExampleCppBehavior();
		bool setUp(sageframework::Result& result);
		bool action(sageframework::Result& result);
		bool message(const sageframework::Message& message, sageframework::Result& result);
		bool tearDown(sageframework::Result& result);
		
		// Factory method
		static boost::shared_ptr<ExampleCppBehavior> create() 
		{
			return boost::shared_ptr<ExampleCppBehavior>(new ExampleCppBehavior());
		}
	};

	BOOST_DLL_ALIAS
	(	
		ExampleCppBehavior::create,	// <-- this function is exported with...
		create_plugin               // <-- ...this alias name
	)



Example Behavior file
+++++++++++++++++++++++++++++++++++

This is an example Behavior in its entirety.  Other parts of the SAGE system would refer to this as the Behavior named ExampleBehavior.  This Behavior does not do anything useful, but it defines each of the four required methods, will print out when each is called, and fills in the result parameter.

.. container:: padding

	.. container:: toggle

		.. container:: header

			C++
			
		.. code-block:: c++
		
			// -------------------------------  Header file  -------------------------------
			#pragma once

			#include "NativePluginInterface.h"

			// This class is exported from the ExampleCppBehavior.dll
			class ExampleCppBehavior : public NativePluginInterface
			{
			public:
				ExampleCppBehavior();
				virtual bool setUp(sageframework::Result& result);
				virtual bool action(sageframework::Result& result);
				virtual bool message(const sageframework::Message& message, sageframework::Result& result);
				bool tearDown(sageframework::Result& result);

				// Factory method
				static boost::shared_ptr<ExampleCppBehavior> create() 
				{
					return boost::shared_ptr<ExampleCppBehavior>(new ExampleCppBehavior());
				}
			};
			
			BOOST_DLL_ALIAS
			(	
				ExampleCppBehavior::create,	// <-- this function is exported with...
				create_plugin               // <-- ...this alias name
			)
			
			// ----------------------------  cpp behavior file  ------------------------------
			// ExampleCppBehavior.cpp : Defines the exported functions for the DLL.
			//

			#include "stdafx.h"
			#include "Common.h"
			#include "Message.h"
			#include "Result.h"
			#include "ExampleCppBehavior.h"

			SAGE_BEHAVIOR(ExampleCppBehavior, SimpleExample, does something cool, sageframework::ExecutionType::OneShot, "", 0, 0)

			bool ExampleCppBehavior::setUp(sageframework::Result& result)
			{
				std::cout << "Setting up behavior" << std::endl;
				result.m_executionResult = sageframework::ExecutionResultType::CompletionSuccess;
				return true;
			}

			bool ExampleCppBehavior::action(sageframework::Result& result)
			{	
				std::cout << "Hello World from Action" << std::endl;
				result.m_logMessages.push_back("This is log message string1.");
				result.m_logMessages.push_back("This is log message string2.");
				result.m_logMessages.push_back("This is log message string3.");
				result.m_exception = "Nothing exceptional here.";
				result.m_executionResult = sageframework::ExecutionResultType::CompletionSuccess;
			
				return true;
			}

			bool ExampleCppBehavior::message(const sageframework::Message& message, sageframework::Result& result)
			{
				std::cout << "Got message  " << message.m_message << " on topic " << message.m_topic << std::endl;
				std::cout << "len of m_data is " << message.m_data.size() << std::endl;
				
				for (int i=0; i < message.m_data.size(); i++)
				{
					std::cout << "Data[" << i << "] = " <<  message.m_data[i] << std::endl;
				}
				
				result.m_logMessages.push_back("This is log message from message string1.");
				result.m_exception = "Nothing exceptional here.";
				result.m_executionResult = sageframework::ExecutionResultType::CompletionSuccess;
				
				return true;
			}

			bool ExampleCppBehavior::tearDown(sageframework::Result& result)
			{
				std::cout << "Tearing down behavior " << m_name << std::endl;
				result.m_executionResult = sageframework::ExecutionResultType::CompletionSuccess;
				return true;
			}
		
	.. container:: toggle

		.. container:: header

			Java
			
		.. code-block:: java
		
			/* Example SAGE Behavior in Java.
				Shows the four methods that have to be defined:
				setUp, action, message, tearDown
				
				 Use the following command line to build:
					javac -cp "%SAGE_SERVER_HOME%"\SageJavaBehaviorInterface.jar ExampleJavaBehavior.java
					
				 Create jar file
					jar cf ExampleJavaBehavior.jar ExampleJavaBehavior.class
			*/


			import nrl.sage.BehaviorInterface.*;


			public class ExampleJavaBehavior extends SageBehavior
			{
				public ExampleJavaBehavior()
				{
					m_name = "SimpleExample";
					m_description = "Simple behavior that prints a lot";
					m_executionType = ExecutionType.OneShot;
					m_delay = 15000;
				}
				
				public boolean setUp(Result result)
				{
					/* The class needs a setUp. Return True or False */
					System.console().printf("Setting up behavior %s\n", m_name);
					result.m_executionResult = ExecutionResultType.CompletionSuccess;
				
					return true;
				}
				
				public boolean action(Result result)
				{
					/* The class needs an action fill in result. Return True or False */
					System.out.println("Hello World from Action");
					result.m_logMessages.add("This is log message string1.");
					result.m_logMessages.add("This is log message string2.");
					result.m_logMessages.add("This is log message string3.");
					result.m_exception = "Nothing exceptional here.";
					result.m_executionResult = ExecutionResultType.CompletionSuccess;
				
					return true;
				}
				
				public boolean message(Message message, Result result)
				{
					/* The class needs a message message method. It is passed in a message object. Return True or False */
					System.out.println("Got message " + message.m_message + " on topic " + message.m_topic);
					System.out.println("length of m_data is", message.m_data.size());
					for (int i=0; i<message.m_data.size(); i++)
					{
							System.out.println("Data[" + Integer.toString(i) + "] = " + message.m_data.get(i));
					}
					result.m_logMessages.add("This is log message from message string1.");
					result.m_exception = "Nothing exceptional here.";
					result.m_executionResult = ExecutionResultType.CompletionSuccess;

					return true;	
				}
				public boolean tearDown(Result result)
				{
					/* The class needs a tearDown. Return True or False */
					System.console().printf("Tearing down behavior %s", m_name);
					result.m_executionResult = ExecutionResultType.CompletionSuccess;
				
					return true;
				}

			}



		
	.. container:: toggle

		.. container:: header

			Python
			
		.. code-block:: python

			#!/usr/bin/env python

			# Example SAGE Behavior in Python.
			# Shows the four methods that have to be defined:
			# setUp, action, message, tearDown
			#

			from nrl.sage.BehaviorInterface import *


			class ExamplePythonBehavior(SageBehavior.SageBehavior):
				""" This is a simple SAGE Behavior """
				def __init__(self):
					super(ExamplePythonBehavior, self).__init__()
					self.m_name = "SimpleExample"
					self.m_description = "Simple behavior that prints a lot."
					self.m_executionType = ExecutionType.ExecutionType.OneShot
					self.m_delay = 15000

				def setUp(self, result):
					""" The class needs a  setUp.  Return True or False """
					print("Setting up behavior ", self.m_name)
					result.m_executionResult = ExecutionResultType.ExecutionResultType.CompletionSucces
					
					return True

				def action(self, result):
					""" The class needs an  action  fill in  result.  Return True or False """
					print("Hello World from Action")
					result.m_logMessages.append("This is log message string1.")
					result.m_logMessages.append("This is log message string2.")
					result.m_logMessages.append("This is log message string3.")
					result.m_exception = "Nothing exceptional here."
					result.m_executionResult = ExecutionResultType.ExecutionResultType.CompletionSuccess
					
					return True

				def message(self, message, result):
					""" The class needs a  message method. It is passed in a message object. Return True or False """
					print("Got message ", message.m_message, " on topic ", message.m_topic)
					print("length of m_data is", len(message.m_data) )
					i = 0
					while i < len(message.m_data):
						print("Data[", i, "] = ", message.m_data[i] )
						i += 1
					result.m_logMessages.append("This is log message from message string1.")
					result.m_exception = "Nothing exceptional here."
					result.m_executionResult = ExecutionResultType.ExecutionResultType.CompletionSuccess
					
					return True

				def tearDown(self, result):
					""" The class needs a  tearDown. Return True or False """
					print("Tearing down behavior ", self.m_name)
					result.m_executionResult = ExecutionResultType.ExecutionResultType.CompletionSuccess
					
					return True

					
Packaged Behaviors
+++++++++++++++++++++++++++++++++++++++++++++++++

SAGE Behaviors **MUST** be packaged into .JAR or .EGG files for Java and Python behaviors respectively. C++ behaviors are packaged as .DLL or .SO modules depending on the target platform.   

Note that there can only be one SAGE Behavior per package. 