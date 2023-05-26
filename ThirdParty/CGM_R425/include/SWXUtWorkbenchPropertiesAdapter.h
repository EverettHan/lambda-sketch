//===================================================================
// COPYRIGHT Dassault Systemes 2017/04/28
//===================================================================
// SWXUtWorkbenchPropertiesAdapter.cpp
// Header definition of class SWXUtWorkbenchPropertiesAdapter
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2017/04/28 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtWorkbenchPropertiesAdapter_H
#define SWXUtWorkbenchPropertiesAdapter_H

#include "SWXUtGeneral.h"
#include "SWXIUtWorkbenchProperties.h"
#include "CATString.h"

//-----------------------------------------------------------------------

class ExportedBySWXUtGeneral SWXUtWorkbenchPropertiesAdapter : public SWXIUtWorkbenchProperties
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	SWXUtWorkbenchPropertiesAdapter();
	virtual ~SWXUtWorkbenchPropertiesAdapter();

	virtual CATString GetDefaultCommand() const override;

private:
	// Copy constructor and equal operator
	// -----------------------------------
	SWXUtWorkbenchPropertiesAdapter(SWXUtWorkbenchPropertiesAdapter &);
	SWXUtWorkbenchPropertiesAdapter& operator=(SWXUtWorkbenchPropertiesAdapter&);
};

//-----------------------------------------------------------------------

#endif
