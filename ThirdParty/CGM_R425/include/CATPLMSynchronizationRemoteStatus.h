// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMSynchronizationRemoteStatus.h
// Define the CATPLMSynchronizationRemoteStatus interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Sep 2004  Creation: Code generated by the CAA wizard  son 
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMSynchronizationRemoteStatus_H
#define CATPLMSynchronizationRemoteStatus_H

/**
* Definition of the possible component's status on remote side.
* <tt> Possible values:</tt>
* <dl>
* @param <tt>CATPLMSynchronizationRemoteStatus_Alive</tt>     <dd>Component is alived.
* @param <tt>CATPLMSynchronizationRemoteStatus_Destroy</tt>   <dd>Component is destroyed.
* </dl>
*/
enum CATPLMSynchronizationRemoteStatus
{
  CATPLMSynchronizationRemoteStatus_Destroy = 0,
  CATPLMSynchronizationRemoteStatus_Alive = 1
};

enum CATPLMSynchronizationConcurrencyType
{
	CATPLMSynchronizationConcurrencyType_CEStamp = 0,
	CATPLMSynchronizationConcurrencyType_LockStatus = 1,
	CATPLMSynchronizationConcurrencyType_LockUser = 2
};

#endif
