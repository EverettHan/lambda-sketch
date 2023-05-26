// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATFrFCombMF :
// Inherit from CATFrFNurbsBipar
// this class is used to describe the transition continuity on a bipar
//
//=============================================================================
// Usage notes:
//
// convention of the TransitionSide and its positive Orientation
//
//                               2       
//                     +--------->---------+
//                     !                   !
//                     !                   !
//                     !    A V            !
//                   1 A    !              A 3
//                     !    !              !
//                     !    +-----> U      !
//                     !                   !
//                     +--------->---------+
//                               0       
//
//
//=============================================================================
// Aug 99  Creation                          tpg
//=============================================================================
#ifndef CATFrFCombMF_H
#define CATFrFCombMF_H

#include "FrFObjects.h"

#include "CATFrFNurbsBipar.h"
#include "CATFrFNurbsMultiForm.h"

//-----------------------------------------------------------------------------
class ExportedByFrFObjects CATFrFCombMF : public CATFrFNurbsBipar
{
 public:

    //----------------
    //  Constructors !
    //----------------
    // constructor with CATFrFNurbsBipar
    CATFrFCombMF(CATFrFNurbsBipar * iBipar,
                 CATLONG32 iTransitionSide);
    //  copy constructor
    CATFrFCombMF(const CATFrFCombMF &iFrFCombMF);
   
    //--------------
    //  Destructor !
    //--------------
    virtual ~CATFrFCombMF       ();

    //-----------
    //  Methods !
    //-----------
    // Set and Get
    void      SetTransitionSide(CATLONG32 iTransitionSide);
    CATLONG32 GetTransitionSide() const;
    void      SetTransitionSideOrientation(CATLONG32 iTransitionSideOrientation);
    CATLONG32 GetTransitionSideOrientation() const;
    // Get MultiForm
    // extraction order
    // iOrder = 0 : one form
    //          1 : two forms
    //          2 : three forms
    CATFrFNurbsMultiForm * GetMultiForm(CATLONG32 iOrder = 2) const;
    // Get Knot Vector
    CATKnotVector        * GetTransverseKnotVector() const;
    CATKnotVector        * GetLongitudinalKnotVector() const;
    // Reverse the lengthwise orientation
    void                   ReverseTransitionSideOrientation();
    // Read one MF control point 
    CATMathPoint         * GetOneControlPointMF
      (CATLONG32 iRankLongitudinal,CATLONG32 iRankTransverse) const;

/*NDNCoverage041005
    // Set one MF control points 
    void SetOneControlPointMF(CATLONG32 iRankLongitudinal,CATLONG32 iRankTransverse, 
                              const CATMathPoint *iControlPoint);
    // Read one MF weight (if the bipar is rational)
    double GetOneWeightMF(CATLONG32 iRankLongitudinal,CATLONG32 iRankTransverse) const;
    // Set one MF weight (if the bipar is rational)
    void SetOneWeightMF(CATLONG32 iRankLongitudinal,CATLONG32 iRankTransverse, 
                        double iWeight);
*/

    // Compute opposite CATFrFCombMF by extending the parametric domain 
    CATFrFCombMF * ComputeOppositeCombMF() const;
 protected:
    // Operator '=' (overloaded) //NDNCoverage051005 - deplace de Public a Protected
     virtual CATFrFCombMF & operator = (const CATFrFCombMF &iCombMF) { return *this; };//NDNCoverage041005

    //-----------
    //  Data    !
    //-----------

    // input
    CATLONG32 _TransitionSide;
    CATLONG32 _TransitionSideOrientation;
};

#endif
