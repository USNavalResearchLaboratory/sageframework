Connecting a Node to the Server

Connecting a Node to the Server
===============================

**Initialize node**

On a Windows command prompt enter the following command:

> ``` {.sourceCode .bat}
> SageNodeConsole_x64.exe nodeName {server_IP_address} {port_number} *{scheduler_mode}
> ```

On a Linux terminal enter the following command:

> ``` {.sourceCode .bat}
> SageNodeConsole nodeName {server_IP_address} {port_number} *{scheduler_mode}
> ```

*scheduler\_mode* is optional and accepted mode values depend of the
current CPU load:

> -   "high" (Default) - Scheduler runs with sub millisecond accuracy
>     and yields the processor between runs of the scheduler. Running in
>     high mode is not recommended for battery powered devices.
> -   "medium" - Scheduler runs every 1-2 milliseconds.
> -   "low" - Scheduler runs every 15 milliseconds.

To verify if a SAGE Node is operational, check the prompt window and
confirm that the following text is displayed,
`Connected to SAGE runtime using ip address {server_IP_address}:{port_number}`.
