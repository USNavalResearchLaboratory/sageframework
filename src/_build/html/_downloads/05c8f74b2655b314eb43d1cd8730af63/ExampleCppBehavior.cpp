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
        ExampleCppBehavior::create,     // <-- this function is exported with...
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