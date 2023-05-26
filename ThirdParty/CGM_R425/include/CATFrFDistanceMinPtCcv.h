// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATFrFDistanceMinPtCcv :
// Declaration of global functions used to compute intersection
// between CompositeCurve and Plane
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//   /02/98 CPL Creation
//   /12/98 CPL Modification
// 22/03/10 NLD Ajout GetAllCCvParamsEqualToPoint(), _AllParamsEqualToPoint, _NbAllParamsEqualToPoint
//              pour traiter les solutions multiples en cas de point sur la CCV
//              (on ne generalise pas le traitement aux points hors de la CCV)
//=============================================================================
#ifndef CATFrFDistanceMinPtCcv_H
#define CATFrFDistanceMinPtCcv_H
//
#include "FrFAdvancedOpeCrv.h"
#include "CATMathDef.h"
#include "CATGeoFactory.h"
#include "CATFrFCompositeCurve.h"
#include "CATMathPoint.h"
#include "CATFrFCCvParam.h"
#include "CATDistanceMinPtCrv.h"
#include "CATPGMFrFDistanceMinPtCcv.h"

//
//-------------------------------------------------------------------
class ExportedByFrFAdvancedOpeCrv CATFrFDistanceMinPtCcv : public CATPGMFrFDistanceMinPtCcv
{
  public :
    CATFrFDistanceMinPtCcv(CATGeoFactory* iFactory,
                           CATFrFCompositeCurve* iCcv,
                           const CATMathPoint& iPoint );
    virtual ~CATFrFDistanceMinPtCcv();

    void Run();

/**
 * Returns the minimum distance between a CATCurve and a CATPoint.
 */
  double GetDistance() const;

/**
 * Returns the global parameter of a point on curve realizing the minimum
 * distance.
 *<br>Note that only one point is proposed, even multiple solutions exist.
 */
  CATFrFCCvParam GetCCvParam() const;

/**
 * Returns all the global parameters of points on curve equivalent to input point,
 * if any.
 *<br>Note that only one point is proposed on each curve, even if multiple solutions exist.
 */
  void GetAllCCvParamsEqualToPoint(CATLONG32& oNbPoints, CATFrFCCvParam*& oPoints ) const;


/**
 * Set the point from which the min distance with the curve will be done.
 */
  void SetPoint(const CATMathPoint & iPoint);

  private:

    CATGeoFactory*          _Factory;
    CATFrFCompositeCurve*   _Ccv;
    CATLONG32               _n;
    CATMathPoint            _Point;
    double                  _Distance;
    CATFrFCCvParam          _CcvParam;

    CATLONG32               _NbAllParamsEqualToPoint;
    CATFrFCCvParam*         _AllParamsEqualToPoint;
    CATDistanceMinPtCrv**   _OpCrv;

};

  // We compute just ONE result: the first result (No Next() result)
  // Result can be out of the Block Limitation of the CompositeCurve...
  ExportedByFrFAdvancedOpeCrv
  void ComputeDistanceMinPtCcv(CATGeoFactory* iFactory,
                               CATFrFCompositeCurve * iCcv,
                               const CATMathPoint& iPoint,
                               CATLONG32 &oCrvIndex, CATCrvParam& oCrvParam);

  ExportedByFrFAdvancedOpeCrv
  CATFrFDistanceMinPtCcv* CreateDistanceMin(CATGeoFactory * iWhere,
                                         const CATMathPoint & iPt,
                                         CATFrFCompositeCurve * iCcv,
                                         CATSkillValue iMode=BASIC);

  ExportedByFrFAdvancedOpeCrv void Remove(CATFrFDistanceMinPtCcv*& iOp);

#endif


