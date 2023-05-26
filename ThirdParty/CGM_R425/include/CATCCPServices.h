/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1997  
//-----------------------------------------------------------------------------
// CATCCPServices Global Functions
// 
//-----------------------------------------------------------------------------
// Usage Notes:
//
//
// Global functions for CCP
//-----------------------------------------------------------------------------
// Creation by jnm	June 98
// Modified NLL         June 99
//-----------------------------------------------------------------------------
#ifndef CATCCPServices_H
#define CATCCPServices_H

/**
 * @level Private 
 * @usage U1
 */

#include "CP0CLIP.h"
#include "IUnknown.h"

class CATBaseUnknown;
class CATIContainer_var;
class CATICCPFormatSupport;
class CATFormat;

/** Obsolete function : do not use any more ! */
ExportedByCP0CLIP 
int IsClipboard( const CATIContainer_var&  featCont ) ;

/* 
   Look for a CCP-format Support in the dictionary 
   iFormat : paste format
   iTarget : target-object's late type
*/
ExportedByCP0CLIP 
HRESULT CATMatchCCPFormat(  const CATFormat* iFormat
			  , CATBaseUnknown* iTarget);

/* 
   Note : Created Support should always be deleted by CATDeleteCCPFormatSupport
          No previous 'Release' required.
*/
ExportedByCP0CLIP
HRESULT CATCreateCCPFormatSupport(  const CATFormat* iFormat
				  , CATBaseUnknown* iTarget
				  , CATICCPFormatSupport** oSupport);

ExportedByCP0CLIP 
HRESULT CATDeleteCCPFormatSupport(CATICCPFormatSupport* iSupport);

#endif
