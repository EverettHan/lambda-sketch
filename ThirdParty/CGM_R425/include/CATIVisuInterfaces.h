// COPYRIGHT Dassault Systemes 2004
//===================================================================

#ifndef CATIVisuInterfaces_H
#define CATIVisuInterfaces_H

#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"

#include "list.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATIVisuInterfaces;
#else
extern "C" const IID IID_CATIVisuInterfaces ;
#endif

class ExportedBySceneGraphManager CATIVisuInterfaces: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:
	virtual list<IID> *GetVisuInterface() = 0;
	virtual void SetVisuInterface(IID * iid) = 0;
	virtual void AddVisuInterface(IID * iid) = 0;
	virtual void RemVisuInterface(IID * iid) = 0;
};


#endif
