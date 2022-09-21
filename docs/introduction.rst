Introduction 
==================================

SAGE Framework is a multi-agent system designed as an enabeling technology for the research, development, and deployment of agent systems that address wide range of problems including: automated testing of distributed systems, emergent agent configurations, novel agent reasoning algorithms, and distributed simulation.
SAGE maintains a small footprint; it's implemented in C++ and uses a highly efficient, and widely used IPC/RPC framework called Remote Call Framework (www.deltavsoft.com). 

SAGE is free software and has no dependencies that require paid licenses or impose restrictions on distribution. SAGE is an open system that can interact with external systems, and can run on a variety of platforms from servers to IOT devices.

SAGE was designed to be pragmatic so that it can easily integrate into new or existing software systems. SAGE provides interface libraries that allow external applications to build, control, and interact with SAGE agent networks. SAGE Agents can also interact with their surrounding sofware environment wherever that may be. SAGE includes an interactive agent development environment called SAGE App where you can interactively build, experiment with, visualize, and store agent networks. 

.. figure::  _images/introduction_1.png
	:width: 650 px
	:align: center

SAGE is simple to use. It consists of four parts:

**SAGE Server** is a console appication available for both 32 and 64 bit version of Windows and Linux. SAGE Server acts as the hub of a SAGE agent nework. It interacts with other SAGE components to provide them with services, manage communications, maintain system state, log system events, and provide introspection services. 

**SAGE Node** is also a console application available for both 32 and 64 bit versions of Windows and Linux. SAGE Node acts as a container for SAGE Agents managing their execution and maintining connectivity to the SAGE Server. SAGE Node is designed to be portable across a wide variety of system architectures. Multiple instances of SAGE Nodes can be distributed across a network of computing devices of various architectures. SAGE Framework manages the data translation between different architectures trasparently. 

**SAGE Agents** are automous agents consisting of a repitoir of Behaviors and a state. SAGE Agents exist within a SAGE Node and can communicate with other agents using message passing. Agents can have any number of Behaviors each consisting of a mix of C++, Java, or Python modules. Behaviors are stored in a centeral repository on the SAGE Server and are sent to agents at runtime on demand. 

**SAGE Behaviors** are objects that are derived from base classes provided with the SAGE Framework. A SAGE behavior endows an Agent with the capability to act either proactivily or reactively.