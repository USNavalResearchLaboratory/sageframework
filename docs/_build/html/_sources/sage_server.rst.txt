SAGE Server
==========================

.. figure::  _images/Sage_Server.png
   :align:   center

   
The SAGE Server establishes and maintains a connection between SAGE Nodes, other SAGE Servers, and external controller systems connected through the SAGE Remote Interface.

SAGE Server acts as a hub connecting local SAGE Nodes forming a cluster. It provides agents within this cluster with the following services:

Communication
	- Exchange messages with agents residing in Nodes in the local cluster or in remote clusters
Introspection
	- Discover Nodes, Agents, and remote Servers 
Agent Management
	- Create and destroy Agents
	- Add and remove Agent behaviors
	- Activate and deactivate Agents
Runtime Control
	- Retrieve Behavior execution results
	- Synchronize execution of SAGE behaviors
Behavior Management
	- Hosts the Behavior repository
	- Synchronize the Behavior repository across clusters
	- Manage Behavior delivery to Agents
Server Clusters
	- SAGE supports a Fog Computing model where multiple SAGE Servers reside in different cloudlets connected over long haul networks. Agents residing within a cluster are tighly coupled so that they can perform collabrative tasks that require agents to synchronize thier actions at or near real-time. Agent interaction between clusters is assumed to be unreliable and, to varying degrees, latent. Agents could interact across clusters to report events, share state (e.g. ML models for distributed learning), or communicate new goals.
	- In the example below, we depict two agent clusters performing a coordinated search operation where a group of unmanned aircraft systems (UAS) are canvassing a region searching for some target. The agents in this instance must coordinate their actions to optimize the search operation based on multiple criteria (e.g. area coverage, terrain features, energy consumption). The UASs then direct two unmanned ground systems (UGS) instrumented with proper sensors to move to areas where a match is found to verify the presence of the target. If a UGS confirms the find, it would direct a UGS specilized for object retrieval to traverse to that location and retrieve the object. The operation described above can be carried out in a completely autnomous fashion with operators in a remote location are simply observing the operation under way. 



  
.. figure::  _images/SageCluster.png
	:width: 650 px
	:align: center

