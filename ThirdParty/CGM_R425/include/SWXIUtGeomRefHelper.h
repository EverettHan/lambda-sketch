//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2012/10/19
//===================================================================
// SWXIUtGeomRefHelper.cpp
// Header definition of class SWXIUtGeomRefHelper
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/10/19 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef SWXIUtGeomRefHelper_H
#define SWXIUtGeomRefHelper_H

#include "SWXUtJournal.h"
#include "CATBaseUnknown.h"

extern ExportedBySWXUtJournal IID IID_SWXIUtGeomRefHelper;

class CATMathPoint;

class ExportedBySWXUtJournal SWXIUtGeomRefHelper : public CATBaseUnknown
{
	CATDeclareInterface;

	public:

		virtual bool IsGeometryReference( CATBaseUnknown* iObject ) = 0;
		virtual bool GeometryReferenceContainsPoint( CATBaseUnknown* iObject, CATMathPoint& iPoint ) = 0;
};

//-----------------------------------------------------------------------

CATDeclareHandler( SWXIUtGeomRefHelper, CATBaseUnknown );

#endif
