#ifndef UAProtectedServices_H
#define UAProtectedServices_H
#include "ExportedByUAServices.h"
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2014
//------------------------------------------------------------------------------
// fw UserAssistance
// UAServices.m
// protected
//------------------------------------------------------------------------------

#include "IUnknown.h" // HRESULT definition under UNIX
#include "CATBoolean.h"

class CATString;
class CATUnicodeString;
class CATVidCtl;

//---------------------------------------------------------------------------
/**
 * Set tooltip.
 * <br><b>Role</b>: This function gets information from resource file and sets tooltip properties on a CID control.
 * @param iResourceFileName
 *  (CATNls) Resource file name
 * @param iVidCtlId
 *  CID Control resource Id
 * @param iVidCtl
 *  CID Control
 * @return
 * @return 
 *   <dl>
 *   <dt> <tt>S_OK</tt>    <dd> The Tooltip has been created
 *   <dt> <tt>S_FALSE</tt> <dd> The Tooltip has not been created
 *   <dt> <tt>E_FAIL</tt>  <dd> Resources have not been found
 *   </dl>   
 */
ExportedByUAServices
HRESULT UASetCIDTooltip (const CATString & iResourceFileName,
                         const CATUnicodeString & iVidCtlId,
                         CATVidCtl * iVidCtl);
#endif
