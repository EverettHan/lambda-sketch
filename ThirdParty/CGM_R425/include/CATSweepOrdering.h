// COPYRIGHT DASSAULT SYSTEMES 2000 
//=============================================================================
//
// CATSweepOrdering:
// Orders two sets of composite curves (guides and profiles) for the sweep
// 
//=============================================================================
// Usage notes:
//
//=============================================================================

//=============================================================================
// HISTORIC
// 23 02 00 ALM Creation
// 12 01 05 NLD Ajout arguments optionnels oMaxDistanceGuideIndex et oMaxDistanceProfileIndex à GetMaxDistance()
// 13 01 05 NLD Ajout SetNoDefaultOrientation()
//=============================================================================

#ifndef CATSweepOrdering_H  
#define CATSweepOrdering_H

#include "FrFAdvancedOpeCrv.h"
#include "CATDataType.h"
#include "CATCGMVirtual.h"

class CATFrFCompositeCurve;
class CATFrFCCvParam;
//-----------------------------------------------------------------------------
class  ExportedByFrFAdvancedOpeCrv CATSweepOrdering : public CATCGMVirtual
{
  public :

    virtual ~CATSweepOrdering();
    virtual void SetNoDefaultOrientation(CATLONG32 iNoDefaultOrientation)=0;
    virtual void Run()=0; 

    // GetGuideOrder returns a CATLONG32 in [0 ; _NbGuides-1] that indicates the
    // order of the guide iGuideIndex.
    virtual CATLONG32 GetGuideOrder(CATLONG32 iGuideIndex)=0;

    // GetOrderProfile returns a CATLONG32 in [0 ; _NbProfiles-1] that indicates
    // the order of the profile iProfileIndex.
    virtual CATLONG32 GetProfileOrder(CATLONG32 iProfileIndex)=0;

    // GetGuideOrientation returns the relative orientation of the guide iGuideIndex 
    // with the first guide.
    // The master orientation is given by the first element of the input set.
    virtual CATLONG32 GetGuideOrientation(CATLONG32 iGuideIndex)=0;

    // GetProfileOrientation returns the relative orientation of the profile 
    // iProfileIndex with the first profile.
    // The master orientation is given by the first element of the input set.
    virtual CATLONG32 GetProfileOrientation(CATLONG32 iProfileIndex)=0;

    // GetDistMinCCvParamsOnProfiles fills an already allocated CATFrFCCvParam
    // array with the params resulting from the distance-min computing between
    // the bases and the guides. The oCCvParams array has only the params on
    // the profiles, and is filled like :
    // oCCvParams[(j*_NbGuides)+i] = param of the intersection between the 
    // guide i (0<=i<_NbGuides) and the profile j (0<=j<_NbProfiles).
    virtual void GetDistMinCCvParamsOnProfiles(CATFrFCCvParam * oCCvParams)=0;

    // GetDistMinCCvParamsOnGuides fills an already allocated CATFrFCCvParam
    // array with the params resulting from the distance-min computing between
    // the bases and the guides. The oCCvParams array has only the params on
    // the guides, and is filled like :
    // oCCvParams[(i*_NbProfiles)+j] = param of the intersection between the 
    // guide i (0<=i<_NbGuides) and the profile j (0<=j<_NbProfiles).
    virtual void GetDistMinCCvParamsOnGuides(CATFrFCCvParam * oCCvParams)=0;

    // GetMaxDistance returns the maximum value of all the distance-min 
    // computed between the profiles and the guides, and, if specified,
    // the guide index and profile index for which it is reached
    virtual double GetMaxDistance(CATLONG32* oMaxDistanceGuideIndex=0,
                                  CATLONG32* oMaxDistanceProfileIndex=0)=0;

};
#endif
