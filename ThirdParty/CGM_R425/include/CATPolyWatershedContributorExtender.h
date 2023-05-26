#ifndef CATPolyWatershedContributorExtender_h__
#define CATPolyWatershedContributorExtender_h__

//===================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyWatershedContributorExtender.h
// Header definition of CATPolyWatershedContributorExtender
//
//===================================================================
//
// Usage notes: Extend the contributor area according to the merge tolerance
//
//===================================================================
// 20/03/2019 : NUA : Creation
//===================================================================

#include "ExportedByCATPolyWatershedOperators.h"

#include "CATPolyWatershedSegmentationData.h"

#include "CATSysErrorDef.h"

class CATPolyWatershedContributionsOperator;

class CATIPolyMesh;
class CATMathSetOfPoints;
class CATPolyWatershedPathExtender;

class ExportedByCATPolyWatershedOperators CATPolyWatershedContributorExtender
{
public:

  static CATPolyWatershedContributorExtender * CreateInstance ( CATPolyWatershedContributionsOperator * ContributorOpe , const CATMathSetOfPoints & iPolylinePoints, CATPolyWatershedPathExtender * iPathExtender);

  virtual ~CATPolyWatershedContributorExtender() {}

  virtual HRESULT ExtendContributor(const CATIPolyMesh & iOriginalContrib, double iTolForMerge, CATIPolyMesh *& oMesh, bool iForceManifold) const = 0;
};

#endif // CATPolyWatershedContributorExtender_h__
