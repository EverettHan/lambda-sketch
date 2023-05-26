// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATIModifiedBySynchro.h
// Define the CATIModifiedBySynchro interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Mar 2002  Creation:  YGN
//===================================================================
#ifndef CATIModifiedBySynchro_H
#define CATIModifiedBySynchro_H

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "AC0XXLNK.h"

extern ExportedByAC0XXLNK IID IID_CATIModifiedBySynchro ;

//------------------------------------------------------------------

/**
* Interface use to manage objects modified by synchronization process
*/
class ExportedByAC0XXLNK CATIModifiedBySynchro: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:
		
	// No constructors or destructors on this pure virtual base class
	// --------------------------------------------------------------
	virtual HRESULT SetModified() = 0;
	virtual HRESULT UnsetModified() = 0;
	virtual HRESULT IsModified() = 0;
};


// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIModifiedBySynchro, CATBaseUnknown ) ;


#endif
