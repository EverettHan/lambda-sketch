// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATICkeInitializeEnvironment.h
// Define the CATICkeInitializeEnvironment interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jul 2006  Creation: Code generated by the CAA wizard  sgq
//===================================================================
#ifndef CATICkeInitializeEnvironment_H
#define CATICkeInitializeEnvironment_H

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATICkeInitializeEnvironment;
#else
extern "C" const IID IID_CATICkeInitializeEnvironment ;
#endif

//------------------------------------------------------------------

/**
* Internal interface.
*/
class ExportedByCATLifSpecs CATICkeInitializeEnvironment: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* Remember that interfaces define only virtual pure methods.
	*/
	virtual HRESULT Init() = 0;

	// No constructors or destructors on this pure virtual base class
	// --------------------------------------------------------------
};

//------------------------------------------------------------------
CATDeclareHandler(CATICkeInitializeEnvironment, CATBaseUnknown);

#endif