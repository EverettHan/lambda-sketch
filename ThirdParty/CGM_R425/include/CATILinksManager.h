/* -*-c++-*- */
#ifndef CATILinksManager_h
#define CATILinksManager_h
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002  
//-----------------------------------------------------------------------------
// class CATILinksManager:
//
//-----------------------------------------------------------------------------
// Usage Notes:
//
// 
// cf comments
//
//-----------------------------------------------------------------------------
// Creation by ygn  - October 02
//-----------------------------------------------------------------------------
//
/**
 * @level Private
 * @usage U3
 */

#include "CATListOfInt.h"
#include "booleanDef.h"
#include "CATBaseUnknown.h"

#include "AC0XXLNK.h"

extern ExportedByAC0XXLNK IID IID_CATILinksManager ;

class ExportedByAC0XXLNK CATILinksManager : public CATBaseUnknown
{
  CATDeclareInterface;

public:
    virtual HRESULT ComputeLinksCounters(CATListOfInt* oDiffCounters=NULL) =0 ;
		virtual HRESULT CopyLinksCounters(boolean DownToMemory=FALSE) =0 ;
		virtual HRESULT GetCurrentCounters(CATListOfInt& oCounters,boolean SessionOnly=FALSE) =0 ;
    
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATILinksManager, CATBaseUnknown ) ;


#endif










