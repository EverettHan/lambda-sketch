// COPYRIGHT DASSAULT SYSTEMES 1998 
//==========================================================================
//
// CATLoftReordering:
// Reorders two sets of composite curves (guides and bases) for the loft
//
// Given two sets of curves the profiles or the bases and the guides,
// we try to find the most probably order of thes curves to create
// a surface that will fill this net of curves.
// The orientation in the direction of the profiles is given by
// the first profile.
// The orientation in the direction of the guides is given by the
// first guide.
// 
//==========================================================================
// Usage notes:
//
//========================================================================== 
// August 98     Design                       PRG
//========================================================================== 
//#define LoftReorderingInactif
#ifdef LoftReorderingInactif

#ifndef CATLoftReordering_H  
#define CATLoftReordering_H

#include "FrFAdvancedOpeCrv.h"
#include "CATCGMVirtual.h"

class CATFrFCompositeCurve;

//-----------------------------------------------------------------------------
class  ExportedByFrFAdvancedOpeCrv CATLoftReordering : public CATCGMVirtual
{
  public :

    virtual ~CATLoftReordering();
    virtual void Run()=0; 
    virtual CATLONG32 IsOrientable()=0;

    // GetOrderGuide(iG) gives a number in [0; _nbOfGuides-1]
    // it indicates the order of the input guide CCV[iG-1]
    // for instance, if guide iG is the 3rd one,
    // then GetOrderGuide(CATLONG32 iG)=2 (3-1 for the table index). 
    virtual CATLONG32 GetOrderGuide(CATLONG32 iG)=0;

    // We use the same rule for the bases
    virtual CATLONG32 GetOrderBase(CATLONG32 iB)=0;

    // in the same way : 
    // GetSensGuide gives the direction of the guide iG (ie the input guide
    // number iG), according to the first given guide.
    // The master orientations, according the bases, as well as according the
    // guides are given by the first base and by the first given guide.
    virtual CATLONG32 GetSensGuide(CATLONG32 iG)=0;

    // We use the same rule for the bases
    virtual CATLONG32 GetSensBase(CATLONG32 iB)=0;

    // returns the maximum of the minimum distance between both sets of contours
    virtual double GetMaxDistance()=0;
};
#endif
#endif
