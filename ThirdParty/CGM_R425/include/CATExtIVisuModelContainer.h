#ifndef CATEXTIVISUMODELCOTAINER_H
#define CATEXTIVISUMODELCOTAINER_H

/*
 * Abstract: 	Adapter for CATIVisuModelContainer interface
 */

// Local Framework
#include "SceneGraphManager.h"
// System Framework
#include "CATBaseUnknown.h"

class ExportedBySceneGraphManager CATExtIVisuModelContainer : public CATBaseUnknown
{

	CATDeclareClass;

public:

	CATExtIVisuModelContainer();
  
	~CATExtIVisuModelContainer();

	// CATIVisuModelContainer interface
	virtual HRESULT GetModelContainer(CATBaseUnknown*& opModelContainer);

};

#endif
