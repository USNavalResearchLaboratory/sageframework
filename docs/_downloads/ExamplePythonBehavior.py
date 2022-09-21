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