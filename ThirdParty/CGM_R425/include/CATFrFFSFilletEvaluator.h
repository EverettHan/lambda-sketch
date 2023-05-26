//
//=============================================================================
// Copyright Dassault Systemes Provence 2009-2016, all rights reserved
//=============================================================================
//
// CATCltFilletEvaluator :
// Implementation class for Class A fillet approximator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// 29/02/16 : HLN ; Coverage: suppr. SetConnectionContinuity & SetArcType
// 25/04/12 : NLD ; Reception de la configuration; ajout _SoftwareConfig
// 02/07/09 : MWE ; Creation d'apres CATClassATopoOperators\ProtectedInterfaces\CATCltFilletEvaluator.h
//=============================================================================
#ifndef CATFrFFSFilletEvaluator_H
#define CATFrFFSFilletEvaluator_H

//#include "CATFrFFilletStyle.h"

#include "CATFrFFilletStyle.h"
#include "CATFrFFSError.h"
#include "CATFreeFormDef.h"
#include "CATSurLimits.h"

class CATSurface;
class CATFilletSurface;
class CATGeoFactory;
class CATFrFNurbsMultiForm;
class CATDistanceMinPtSur;
class CATMathPoint;
class CATMathVector;
class CATKnotVector;
class CATFrFFSG3EvalOp;
class CATFrFFSG2OrG3FilletProfile;
class CATSoftwareConfiguration;

class ExportedByCATFrFFilletStyle CATFrFFSFilletEvaluator
//class CATFrFFSFilletEvaluator
{
  public:

    //===============
    //  Constructor 
    //===============
    CATFrFFSFilletEvaluator( CATGeoFactory *ifactory, 
                           CATSoftwareConfiguration* iSoftwareConfig,
                           CATSurface *Fillet,
                           CATSurLimits &FilLimits,
                           CATSurface *Base1,
                           CATSurface *Base2,
                           int iUseProjection = 1,
                           int iContinuity1 = 2,
                           int iContinuity2 = 2,
                           int iMinRadFlag = 0,
                           double iMinRadius = 0.0,
                           int iMinRelative = 0, 
                           double iMinRelation = 1.0,
                           int iTube = 0,
                           int iArcType = 1,
                           CATIsoParameter iFilletOrientation = CATIsoParamU,
                           int iArcOrientation = 1); 

    //==============
    //  Destructor 
    //==============
    virtual ~ CATFrFFSFilletEvaluator();

    //=======
    //  Run 
    //=======

    // Eval
    void Eval(double iPar, CATSurParam &oSurPar1, CATSurParam &oSurPar2, CATFrFNurbsMultiForm *&oIsoCurve );
    // compute the derivatives of the traces
    void EvalDer1(double iPar, CATMathVector *StartDer1, CATMathVector *EndDer1);
    void EvalCenterDer1(double iPar, CATMathVector *Der1);

/*hln29022016    void SetConnectionContinuity(const CATFrFContinuity iCont1, const CATFrFContinuity icont2);
    void SetArcType(int iArcType);*/

   protected:
     void SetKnotVector();

   // 1st settings of evaluation
   protected:
      int _Cont1;     // desired continuity on 1st cluster
      int _Cont2;     // desired continuity on 2nd cluster

      int _ArcType;   // only valid for _Cont1 == _Cont2 == G1
                      // 0 : blend with minimal order 4
                      // 1 : bezier approximation of the arc order 6
                      // 2 : rational ( exact shape of circle will be kept )
   public:  
      int _UseProjection; // ==  1 : for computing the surface the projected points will be used;
                          // ==  0 : for computing the surface the points on the fillet surface will be used

      int _Tube;     // == 1 : compute a tube from the fillet; == 0 : no tube

      int _Order;
      int _MaxSegments;    // tolerance depending segmentation will be computed up to _MaxSegments
      double _Tolerance;   // tolerance used for segmentation

      int _MinRadiusFlag;
      int _MinRadRelative;
      double _MinRadiusValue;
      double _MinRelation;

      CATIsoParameter _FilletOrientation;
      int _ArcOrientation;  // 1 Arc is running from _Base1 to _Base2;
                            // -1 Arc is running from _Base2 to _Base1;

   protected:
      CATGeoFactory *_GeoFactory;
      CATSoftwareConfiguration* _SoftwareConfig;
      CATSurface *_FilletSurf;
      CATSurLimits _FilLimits;

      CATSurface *_Base1;   
      CATSurLimits _Lim1; 
      CATSurLimits _MaxLim1;

      CATSurface *_Base2;
      CATSurLimits _Lim2;
      CATSurLimits _MaxLim2;

   private:
      CATDistanceMinPtSur *_DistMinPtSur1;
      CATDistanceMinPtSur *_DistMinPtSur2;

      CATFrFFSG3EvalOp *_G3Eval1;
      CATFrFFSG3EvalOp *_G3Eval2;

      CATFrFFSG2OrG3FilletProfile *_G3CurveCreator;

      CATKnotVector *_DefaultKnotVec;
      CATSurParam _InitPar1;
      CATSurParam _InitPar2;
      double _Resolution;
      CATBoolean _FirstRunDone;

};
#endif
