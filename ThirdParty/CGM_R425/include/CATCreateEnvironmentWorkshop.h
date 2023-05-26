// COPYRIGHT DASSAULT SYSTEMES 2008
#ifndef CATCreateEnvironmentWorkshop_H
#define CATCreateEnvironmentWorkshop_H

#include <CATCreateWorkshop.h>
#include <CATString.h>

#include "CATAfrFoundation.h"

/**
 * Get current CATCmdAccess environment.
 * <b>Role</b>: Allows you to read the current environment (workshop, workbench or addin)
 * in which further NewEnvironmentAccess, ... will be done.
 * @param classname 
**/
ExportedByCATAfrFoundation CATString GetCommandEnvironment();

/**
 * Set current CATCmdAccess environment.
 * <b>Role</b>: Allows to change the current environment name
 * that will be returned by GetCommandEnvironment.
 * <br> This service is not exported, it can not be used outside of its framework.
 * @param classname 
**/
void SetCommandEnvironment(CATString env);

/**
 * Create an access.
 * <b>Role</b>: Same as NewAccess. 
 * But takes into account the current environment setting to produce a name dependant from  
 * the environment. The name of any command created will be post_fixed with the provided name 
 * @param classname 
 *   The name of the class created 
 *   <b><Legal values></b>: 
 *   <dl>
 *   <dt><tt>same as NewAccess</tt> 
 *   </dl>
 * @param variableName
 *   The pointer to the instance created 
 * @param objectName
 *   The name of the access. This name is used to reference resources
 *   and will be post fixed by the name of the current environment 
 */
#define NewEnvironmentAccess(className, variableName, objectName) \
CATString st##variableName=GetCommandEnvironment(); st##variableName+=#objectName; \
className* variableName = new className (st##variableName, CATCmdAccess::Default)


/**
 * Get workbench and workshop names selected by the user.
 * <b>Role</b>: Returns workbench and workshop names chosen by the user in Start menu.
 * <br>.This services returns empty strings if it is not called between the Start interaction
 * and the workbench change. It may be used for example in CATFrmEditor initialization or in ui-activation code.
**/
ExportedByCATAfrFoundation void GetSelectedWorkshopAndWorkbench(CATString & oWs, CATString & oWb);

#endif
