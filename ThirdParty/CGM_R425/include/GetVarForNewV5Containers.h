/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES  2005                                         
//===========================================================================
//
// GetVarForNewV5Containers 
//
//==============================================================================
// Creation : V. ZAFRANY le 15/06/2005
//==============================================================================
#ifndef GetVarForNewV5Containers_H
#define GetVarForNewV5Containers_H

/**
*@level Protected
*@usage U1
*/

/** @required */
#include "ExportedByCATIAEntity.h"

#include "IUnknown.h"

/**
 * The state of the environment variable "NEW_V5_CONTAINERS_PROJECT".
 * @param NoValue
 *   The static variable is not valuated.
 * @param VariableOFF
 *   The environment variable is switched OFF.
 * @param VariableON
 *   The environment variable is switched ON.
 */
enum NewV5ContEnum{NoValue         =0,
                   OldV5Containers =1,
                   NewV5Containers =2};

/**
 * The state of the environment variable "V4_MODEL_REMOVE_PROJECT".
 * @param NoVal
 *   The static variable is not valuated.
 * @param ModelNotDeleted
 *   The environment variable is switched OFF.
 * @param ModelDeleted
 *   The environment variable is switched ON.
 */
enum RemoveV4ModelEnum{NoVal           =0,
                       ModelNotDeleted =1,
                       ModelDeleted    =2};

/**
 * return the state of the variable "omc3DLive"
 */
ExportedByCATIAEntity int UseOmc3DLive();

/**
 * return the state of the variable "NEW_V5_CONTAINERS_PROJECT"
 */
ExportedByCATIAEntity int UseNewV5OmcContainer_CDB();

/**
 * Retrieves the state of the "NEW_V5_CONTAINERS_PROJECT" environment variable.
 * <br><b>Role</b>: This service enables to read the environment variable linked 
 * with the new V5 Containers tree corresponding to the old V4 Data Structure. 
 * According to this variable state, the V5 Containers tree corresponding to the 
 * containers registered in the V4 model is built.
 * A static enum "NewV5ContainersVariable" is valuated according to the environment variable state.
 * @param oVarForV5Containers
 *	The state of the environment variable "NEW_V5_CONTAINERS_PROJECT".
 *  <br><b>Legal values</b>:
 *  <dl>
 *	<dt><tt>NoValue</tt>     <dd>the static variable is not valuated
 * 	<dt><tt>VariableOFF</tt> <dd>the environment variable is switched OFF
 * 	<dt><tt>VariableON</tt>  <dd>the environment variable is switched ON 
 *  </dl>
 * @return
 *  <dl>
 *	<dt><tt>S_OK</tt>   <dd>on Success
 * 	<dt><tt>E_FAIL</tt> <dd>on Failure
 *  </dl>
 */
ExportedByCATIAEntity HRESULT GetNewV5Containers(NewV5ContEnum &oVarForV5Containers);

/**
 * Retrieves the state of the "V4_MODEL_REMOVE_PROJECT" environment variable.
 * <br><b>Role</b>: This service enables to read the environment variable linked 
 * with the new V5 Containers tree corresponding to the old V4 Data Structure. 
 * According to this variable state, the V4 Data Structure is deleted, once the 
 * document has been loaded, if no V4 element has been created.
 * A static enum "RemoveV4ModelVariable" is valuated according to the environment variable state.
 * @param oVarRemoveV4Model
 *	The state of the environment variable "V4_MODEL_REMOVE_PROJECT".
 *  <br><b>Legal values</b>:
 *  <dl>
 *	<dt><tt>NoVal</tt>           <dd>the static variable is not valuated
 * 	<dt><tt>ModelNotDeleted</tt> <dd>the environment variable is switched OFF
 * 	<dt><tt>ModelDeleted</tt>    <dd>the environment variable is switched ON 
 *  </dl>
 * @return
 *  <dl>
 *	<dt><tt>S_OK</tt>   <dd>on Success
 * 	<dt><tt>E_FAIL</tt> <dd>on Failure
 *  </dl>
 */
ExportedByCATIAEntity HRESULT GetRemoveV4Model(RemoveV4ModelEnum &oVarRemoveV4Model);

#endif
