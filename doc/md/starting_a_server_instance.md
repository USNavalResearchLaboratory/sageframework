Starting a Server Instance

Starting a Server Instance
==========================

**Initialize Server**

On a Windows command prompt enter the following command:

> ``` {.sourceCode .bat}
> SageServerConsole_x64.exe {port_number}
> ```

On a Linux terminal enter the following command:

> ``` {.sourceCode .bat}
> SageServerConsole {port_number}
> ```

To verify a running SAGE Server instance, check the prompt window and
confirm that the following text is displayed,
`SAGE server started listening on port: {port_number}`.

This can also be accomplished using the SAGE App:

> 1)  In the SAGE App, configure your serverAppSettings-label by
>     clicking the gear icon Settings button.
> 2)  Enter a port number in the Server Port dialog box and click the
>     Ok button.
> 3)  Click the green Start button to initialize the Server.

Note that there is no default port number for SAGE. It is recommended to
avoid using dedicated port numbers, such as 21 (FTP), 22 (SSH), and 80
(HTTP). For a list of unassigned port numbers visit [Internet Assigned
Numbers Authority
(IANA)](http://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml).
