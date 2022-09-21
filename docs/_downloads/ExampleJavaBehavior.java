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