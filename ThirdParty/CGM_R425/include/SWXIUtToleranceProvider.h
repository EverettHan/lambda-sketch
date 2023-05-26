//===================================================================
// COPYRIGHT DS SolidWorks 2011/02/10
//===================================================================
// SWXIUtToleranceProvider.cpp
// Header definition of class SWXIUtToleranceProvider
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/02/10 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef SWXIUtToleranceProvider_H
#define SWXIUtToleranceProvider_H

#include "SWXUtGeneral.h"
#include "CATBaseUnknown.h"


extern ExportedBySWXUtGeneral  IID IID_SWXIUtToleranceProvider ;

class CATTolerance;

class ExportedBySWXUtGeneral SWXIUtToleranceProvider: public CATBaseUnknown
{
	CATDeclareInterface;

public:
	// Get an appropriate tolerance object
	virtual const CATTolerance *GetTolerance() = 0;

	// Get a tolerance object appropriate for some other thing.
	// Possibly there should be two different classes.
	virtual const CATTolerance *GetTolerance(const CATBaseUnknown_var &ipObject) = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler( SWXIUtToleranceProvider, CATBaseUnknown );

#endif