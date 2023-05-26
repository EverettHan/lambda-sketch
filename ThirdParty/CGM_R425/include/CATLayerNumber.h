#ifndef CATLayerNumber_h
#define CATLayerNumber_h

#include "CATVisItf.h"

//********************************************************************
// CATIA Version 5 Release 2 Framework Visualization
// Copyright Dassault Systemes 2001
//********************************************************************


class ExportedByCATVisItf CATLayerNumber
{	
public:
	CATLayerNumber ();
	~CATLayerNumber ();
	
	static unsigned int  GetNoneLayerNumber();
	static unsigned int  GetMaxLayerNumber();
};



#endif

