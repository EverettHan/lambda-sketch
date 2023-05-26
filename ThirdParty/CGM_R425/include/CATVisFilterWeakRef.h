#ifndef CATVisFilterWeakRef_H
#define CATVisFilterWeakRef_H
//
// CATIA Version 5 Release 15 Framework Visualization
// Copyright Dassault Systemes 2004

#include "SGInfra.h"

class CATVisFilter;
class ExportedBySGInfra CATVisFilterWeakRef  
{
	friend class CATVisFilter;

public :
	void AddRef(); 
	void Release();

	CATVisFilter* GiveFilter();

protected:
	static CATVisFilterWeakRef* Create(CATVisFilter* filter);
	void KillRef();
	
private :
	CATVisFilterWeakRef(CATVisFilter* filter);
	~CATVisFilterWeakRef();


	CATVisFilter* _filter;
	unsigned int _nRef;
};
#endif 


