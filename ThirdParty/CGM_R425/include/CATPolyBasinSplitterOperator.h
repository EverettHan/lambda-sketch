//===================================================================
// COPYRIGHT Dassault Systemes Provence 2020
//===================================================================
// CATPolyBasinSplitterOperator.h
//===================================================================
//
// Usage notes: Split basin mesh by horizontal plane
//===================================================================
// HISTORIQUE :
// 26/04/2020 : NUA : Creation
//===================================================================

#ifndef CATPolyBasinSplitterOperator_h__
#define CATPolyBasinSplitterOperator_h__



#include "ExportedByCATPolyWatershedOperators.h"
#include "CATErrorDef.h"

#include <vector>

class CATIPolyMesh;
struct CATPolyWatershedCallback;

/*
1 - Instanciate operator
2 - Call run method
3 - Call others methods
*/

class ExportedByCATPolyWatershedOperators CATPolyBasinSplitterOperator
{
public:


	// Creates ope instance
	static CATPolyBasinSplitterOperator * CreateInstance(CATIPolyMesh & ioMesh, double zplane);

  virtual ~CATPolyBasinSplitterOperator() {}

  virtual void SetTriangleSet(const std::vector<int> & iTrSet) = 0;

  enum KindOfPartToKeep
  {
    K_Below,
    K_Above,
    K_All
  };

  virtual HRESULT Run(KindOfPartToKeep PartToKeep = K_All) = 0;

  virtual void DisableManifoldCheck() = 0;

	// Enable to know the current computation state 
  virtual void SetProgressCallback(CATPolyWatershedCallback * iCB) = 0;

  
};



#endif // CATPolyBasinSplitterOperator_h__
