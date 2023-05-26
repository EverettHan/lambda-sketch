// COPYRIGHT Dassault Systemes 2001
//===================================================================
//
// CATKweCustomNamingAdapter.h
// Define the CATKweCustomNamingAdapter interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  
//===================================================================
#ifndef CATKweCustomNamingAdapter_H
#define CATKweCustomNamingAdapter_H

/** 
* @CAA2Level L1
* @CAA2Usage U2 
*/

/*  CAA2Reviewed by FRH */

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"

#include "CATBoolean.h"
#include "CATUnicodeString.h"

//------------------------------------------------------------------

/**
* Class to be used as an adapter for objects that implement CATIKweCustomNaming
*/

class ExportedByKnowledgeItf CATKweCustomNamingAdapter: public CATBaseUnknown
{
public:
	/**
	* Constructor.
	*/
	CATKweCustomNamingAdapter();

	/**
	* Destructor.
	*/
	virtual ~CATKweCustomNamingAdapter() ;

	/**
	* Returns CATFalse
	*/
	virtual CATBoolean IgnoreInNaming();

	/**
	* Returns CATFalse
	*/
	virtual CATBoolean UseCustomFather();

	/**
	* Returns CATFalse
	*/
	virtual CATBoolean UseCustomName();

	/**
	* Returns an empty string
	*/
	virtual CATUnicodeString GetCustomName();

	/**
	* Returns NULL_var
	*/
	virtual CATBaseUnknown_var GetCustomFather();

private:
	CATKweCustomNamingAdapter(const CATKweCustomNamingAdapter&);
};

//------------------------------------------------------------------

#endif
