/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
//  CATIUnload :
//		interface used to unload a document
//  
//=============================================================================          
//
//==================================================================
//  Usage notes
//
//	slg, mzc Dec.98
//==================================================================
#ifndef CATIUnload_H
#define CATIUnload_H

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "AC0XXLNK.h"

extern ExportedByAC0XXLNK IID IID_CATIUnload ;



class ExportedByAC0XXLNK CATIUnload : public CATBaseUnknown
{
  CATDeclareInterface;

  public:
  
	virtual
	  HRESULT Unload ( ) = 0;
	
	virtual
	  HRESULT BreakLinks ( ) = 0;	  

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIUnload , CATBaseUnknown ) ;


#endif
