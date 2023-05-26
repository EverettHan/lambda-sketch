//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// Operator to define a no linear Transformation of the space
//
//==========================================================================
// Usage Notes
//==========================================================================
// June. 2000     Creation                       APD

// March 2001     Move To FreeFormOperators       DR
//========================================================================== 
#ifndef CATSpatialTransfoImp_H
#define CATSpatialTransfoImp_H


#include "CATMathDef.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMapFunctionXYZ.h"
#include "CATSpatialTransfo.h"

#include "CATMath3x3Matrix.h"

class CATMathVector;


class CATSpatialTransfoImp : public CATSpatialTransfo
{
  public:

    CATSpatialTransfoImp(const CATMapFunctionXYZ * iMap);

    ~CATSpatialTransfoImp();

  //===========
    //Information
    //===========
    CATBoolean IsAKindOf(const char*) const; 


  //===========
    //Initialization
    //===========  
      void Set(const CATMathPoint& iPoint) ;
      CATBoolean OK() const ;
      void Run() ;

  //===========
    // Shorter Initialization (One methode to do Set/Ok/Run)
    //===========  
      CATLONG32 Init(const CATMathPoint& iPoint);



  //===========
    //Evaluators
    //===========    
    // Get the Transformed Point
    void GetPoint(CATMathPoint & oPModified) const;

    // Transform a vector ( a tangential vector ?)
    void TransformVector(CATMathVector& iV, CATMathVector& oV) const;

    // Transform a normal
    void TransformNormal(CATMathVector& iV, CATMathVector& oV) const;

    // Transform a second derivative
    void TransformSecondDeriv(CATMathVector& inFirstDeriv, 
                              CATMathVector& inSecDeriv, 
                              CATMathVector& outSecDeriv ) const;

    // Transform a crossed second derivative
    void TransformCrossDeriv(CATMathVector &inDerivU,
                             CATMathVector &inDerivV,
                             CATMathVector &inCrossUV,
                             CATMathVector &outCrossUV ) const;

  private:
 
     CATMathPoint              _Point;
     const CATMapFunctionXYZ * _Map;
     CATMath3x3Matrix          _MatrixJacob; 
     CATBoolean                _CalculMat;
     CATMathVector             _Cxx, _Cyy, _Czz, _Cxy, _Cxz, _Cyz ; 



};

#endif
