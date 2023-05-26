#ifndef CATVisContextFilterStrategy_H
#define CATVisContextFilterStrategy_H
//
// CATIA Version 5 Release 15 Framework Visualization
// Copyright Dassault Systemes 2004

#include "SGInfra.h"

class CATPathElement;
class CATRepPath;

class ExportedBySGInfra CATVisContextFilterStrategy 
{
public :
	void AddRef();
	void Release();

	virtual void BuildRepPath(CATRepPath& reppath, CATPathElement* iPath) = 0;

protected :
	CATVisContextFilterStrategy();
	virtual ~CATVisContextFilterStrategy() ;

private : 
	unsigned int  _nRef;
};

#endif 
  
  
