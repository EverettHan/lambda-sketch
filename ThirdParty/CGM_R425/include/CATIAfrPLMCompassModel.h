//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/08/17
//===================================================================
// CATIAfrPLMCompassModel.cpp
// Header definition of class CATIAfrPLMCompassModel
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/08/17 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIAfrPLMCompassModel_H
#define CATIAfrPLMCompassModel_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"


extern ExportedByCATAfrItf  IID IID_CATIAfrPLMCompassModel ;

class CATCommand;

class ExportedByCATAfrItf CATIAfrPLMCompassModel: public CATBaseUnknown
{
CATDeclareInterface;

public:

	/**
	 * Set filter
	 **/
	/*virtual SetFilter(const CATBaseUnknown_var &)  = 0;*/
	/**
	 * Get filter
	 **/
	virtual const CATBaseUnknown_var &GetFilter(void) const  = 0;

  	/**
	 * Notify of selection change
	 **/
	virtual void OnSelectionChanged(void) = 0;


};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIAfrPLMCompassModel, CATBaseUnknown );

#endif
