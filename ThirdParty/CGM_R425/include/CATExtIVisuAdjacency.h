#ifndef CATEXTIVISUADJACENCY_H
#define CATEXTIVISUADJACENCY_H

/*
 * Abstract: 	Adapter for CATIVisuAdjacency interface
 */

// Local Framework
#include "SceneGraphManager.h"
// System Framework
#include "CATBaseUnknown.h"
#include "CATListOfCATPathElement.h"
#include "CATListOfInt.h"

class ExportedBySceneGraphManager CATExtIVisuAdjacency : public CATBaseUnknown
{

	CATDeclareClass;

public:

	CATExtIVisuAdjacency();
  
	~CATExtIVisuAdjacency();

	// CATIVisuAdjacency interface
	virtual HRESULT ComputeAdjacency(const CATLISTP(CATPathElement)* ipPathElementList, const CATListOfInt& iVisiblePathEltsIndexList, const CATListOfInt& iHiddenPathEltsIndexList, CATListOfInt& oVisibleAndAdjoiningPathEltsIndexList);

};

#endif


