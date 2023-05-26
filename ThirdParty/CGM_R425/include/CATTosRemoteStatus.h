#ifndef CATTosRemoteStatus_H
#define CATTosRemoteStatus_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @level Private
 * @usage U3
 */

 /**
 * Definition of the TOS level for retrieving one handle.
 * The component todo status can be evaluated globally or from the last local save operation.
 *
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CATTosRemoteStatus_Error</tt>            <dd>The remote status is not initialized.
 * @param <tt>CATTosRemoteStatus_Alive</tt>            <dd>Existing component.
 * @param <tt>CATTosRemoteStatus_Destroy</tt>          <dd>Destroyed component.
 * </dl>
 */
enum CATTosRemoteStatus
{
  CATTosRemoteStatus_Error,
  CATTosRemoteStatus_Alive,
  CATTosRemoteStatus_Destroy
};

enum CATTosConcurrencyType 
{ 
		CATTosConcurrencyType_Unknown, 
		CATTosConcurrencyType_CEStamp, 
		CATTosConcurrencyType_LockStatus, 
		CATTosConcurrencyType_LockUser
};

#endif



