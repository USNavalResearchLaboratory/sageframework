Robot Framework Background

Robot Framework Background
==========================

["Robot Framework"](http://robotframework.org) by Robot Framework
Foundation is licensed under the [Apache License
2.0.](http://apache.org/license/LICENSE-2.0)\
All information presented is derived from [Robot Framework User
Guide](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html)
.

Robot Framework is a generic test automation framework that uses the
keyword-driven testing approach.

Keyword-driven testing uses keywords (or action words) to perform a
specific task.

-   Facilitates simple to use tabular syntax to create test cases.
-   Generates easy to read result reports as well as logs in
    HTML format.
-   Independent of application and platform.
-   Supports creation of data driven test cases.
-   Provides tagging for categorizing and selecting test cases that are
    to be executed.
-   Has built in support for variables to enable testing in
    different environments.

**File extension**

Starting from Robot Framework 2.7.6, every robot framework file is saved
as a .ROBOT file extension type.

> e.g., *sageTest.robot*

**Settings**

Robot Framework test data is defined in tabular format, thus all content
outside of the recognized table types is ignored.

The asterisk (*) symbol is used to distinguish each table. When creating
each table you can input "*", "**", or "***" before you add the name of
the table. For consistency purposes it is common to use "*****\*\*"
before you add the table name. Be sure that the table name is spaced
between the asterisks.

``` {.sourceCode .bat}
*** Settings ***
```

Four common settings are *\[Documentation\]*, *\[Library\]*, *\[Test
Setup\]*, and *\[Test Teardown\]*.

**Documentation**

The *\[Documentation\]* setting allows you specify documentation of a
test case. The supporting text is shown in both the command line output,
as well as the test logs and reports.

``` {.sourceCode .bat}
*** Settings ***
Documentation    Written explanation of test case to be documented
```

**Library**

Importing supporting Robot Framework libraries is essential to make use
of its keywords and their functionality. Test libraries may be imported
using the *\[Library\]* setting.

The library name is both case- and space-sensitive. If a library is in a
package, the full name including the package name must be used.

``` {.sourceCode .bat}
*** Settings ***
Documentation    Written explanation of test case to be documented

Library    SageRobotKeywords
```

The Library setting is Robot Framework’s equivalent of Java’s and
Python’s respective import statement. Import SageRobotKeywords to use
SAGE Framework specific keywords.

**Test Setup**

The *\[Test Setup\]* setting allows you to run a Keyword before running
your test case. This is useful for setting up your environment prior to
conducting your test, such as configuring your network or having the
proper windows open.

``` {.sourceCode .bat}
*** Settings ***
Documentation    Written explanation of test case to be documented

Library    SageRobotKeywords
Test Setup    Start SAGE
```

**Test Teardown**

The *\[Test Teardown\]* setting allows you to run a Keyword after your
test case either completes or fails. This is useful for performing any
clean-up and shutdown activities, such as deactivating your agents or
closing any active windows.

``` {.sourceCode .bat}
*** Settings ***
Documentation    Written explanation of test case to be documented

Library    SageRobotKeywords
Test Setup    Start SAGE
Test Teardown    Deactivate Agent   MyNode   MyAgent
```

**Test case**

The first column in the **Test Cases** table contains the test case name

``` {.sourceCode .bat}
*** Test Cases ***
TestName
```

*"TestName"* is the name of the test case, while **"Test Cases"** is the
table name.

A test case concludes once a new test case or table is declared or if
the current test reaches its final keyword.

**Keywords**

Keywords are considered as functions or methods that can be used for
testing. Each keyword correspond to a set of actions.

Keywords are specified in the second column. Keywords are `Start SAGE`
and `Connect to SAGE Runtime`. Columns after the keyword name contain
possible arguments to the specified keyword. Arguments are
**server\_IP\_address** and **port\_number**.

Robot Framework recommends using *four spaces between columns*.

``` {.sourceCode .bat}
*** Test Cases ***
TestName
    Start SAGE
    Connect to SAGE Runtime    {server_IP_address}    {port_number}
```

**Comments**

In order to comment out a line include the pound (\#) symbol.

``` {.sourceCode .bat}
*** Test Cases ***
TestName
    Start SAGE
    Connect to SAGE Runtime    {server_IP_address}    {port_number}
    # This keyword is commented out
```

**Arguments**

Keywords may accept zero or more arguments. The number of arguments a
keyword accepts depends on its implementation, and typically the best
place to search for this information is located in a keyword's
documentation (if supplied by the developer).

If an argument has a default value you may specify that value by
separating the argument name and its value with an equal sign.

``` {.sourceCode .bat}
*** Test Cases ***
TestName
    Start SAGE
    Connect to SAGE Runtime    {server_IP_address}    {port_number}
    # This keyword is commented out
    Create Agent    nodeName=MyNode    agentName=MyAgent
```

**Robot file runtime**

Robot Framework is executed in these following steps:

1.  Collecting test cases, reading and setting variables
2.  Running all the steps in every test case
3.  Providing the execution statistics (which test cases
    have passed/failed)
4.  Writing the detailed log in xml format
5.  Generating the report and log in html format.

All executed test suites and test cases, as well as their statuses, are
shown in real time.
