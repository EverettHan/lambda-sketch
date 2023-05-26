/**
 * @fullreview ERS-CVE 02:02:12
 * @error MISC Y manque includes CATUnicodeString et CATBaseUnknown
 */
#ifndef CATCmdWorkbenchServices_H
#define CATCmdWorkbenchServices_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATString.h"
#include "CATListOfCATString.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"

class CATCmdWorkbench; 

#include "CATAfrFoundation.h"

/**
 * Create a new workbench
 * <b>Role</b>: Create a new workbench related to a workshop
 * .br
 * if workshop name is not defined, workbench is created under current workshop
 * if factory name is not defined, workbench is created as a CATCmdWorkbench (User workbench)
 * .br
 * Created workbench is stored into session data so it has not to be created again in a new session
 * .br
 * Normal execution return 0; otherwise fail with 1: workshop does not exist, 2: workbench already exists
 * @see CATIWorkbench 
 */

ExportedByCATAfrFoundation CATCmdWorkbench* CreateUserWorkbench(const CATString& name, const CATUnicodeString& title, const CATString* wshopName=NULL, CATClassId itfId=NULL);


// PHB (Feb2005) : Migration on Deployed workbenches
 /**
 * Create a new workbench
 * <b>Role</b>: Create a new workbench related to a workshop
 * .br
 * if workshop name is not defined, workbench is created under current workshop
 * .br
 * Created workbench is stored into session data so it has not to be created again in a new session
 * .br
 * Normal execution return 0; otherwise fail with 1: workshop does not exist, 2: workbench already exists
 * @see CATIWorkbench 
 */
ExportedByCATAfrFoundation CATCmdWorkbench* CreateDeployedWorkbench(const CATString& iName, const CATUnicodeString& title, const CATString* wshopName, CATClassId itfId);
//
// PHB (Mar2008) : Remove the CATWorkbench
ExportedByCATAfrFoundation HRESULT CATDwbRemoveDeployedWorkbench(const CATString& iName);
//
// PHB (Mar2008) : Refresh on Deployed workbenches
ExportedByCATAfrFoundation void CATDwbUpdateDeployedWorkbenches();


 /**
 * Give the list of toolbars of current workbench
 * <b>Role</b>: Builds the list of current toolbar pointers.
 * .br
 * The list first contains the global toolbars, then the workshop toolbars and then the workbench toolbars.
 * .br
 * The list contains CATBaseUnknown pointers, because toolbars might be represented in many ways.
 * For example, if you want to retrieve all Dialog framework toolbars, keep the pointers which IsAKindOf(CATDlgToolbar) is True.
 */
ExportedByCATAfrFoundation CATLISTP(CATBaseUnknown) CurrentToolbarList();


 /**
 * Loads a workbench
 * <b>Role</b>: Loads a workbench of the current workshop.
 * @param iWbName
 * Name of the workbench to load.
 * @return
 * Returns S_OK on success. On failure, it returns one of the following
 * error codes :
 * <ul>
 * <li>E_INVALIDARG if the name does not correspond to a workbench of the current workshop </li>
 * <li>E_FAIL if the load operation failed </li>
 * </ul>
 */
ExportedByCATAfrFoundation HRESULT CATAfrLoadWorkbench (CATString iWbName);

#endif
