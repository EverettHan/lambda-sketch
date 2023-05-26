//===================================================================
// COPYRIGHT Dassault Systemes 2014/06/20
//===================================================================
// SWXIUtWorkbenchProperties.cpp
// Header definition of class SWXIUtWorkbenchProperties
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2014/06/20 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef SWXIUtWorkbenchProperties_H
#define SWXIUtWorkbenchProperties_H

#include "SWXUtGeneral.h"
#include "CATBaseUnknown.h"

#include "CATString.h"

extern ExportedBySWXUtGeneral  IID IID_SWXIUtWorkbenchProperties ;

class ExportedBySWXUtGeneral SWXIUtWorkbenchProperties: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	virtual CATString GetDefaultCommand() const = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler( SWXIUtWorkbenchProperties, CATBaseUnknown );

#endif
