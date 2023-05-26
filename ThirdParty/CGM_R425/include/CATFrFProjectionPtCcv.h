// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATFrFProjectionPtCcv :
// Declaration of global functions used to compute projection
// Point on CompositeCurve
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//   /05/08 JBX Creation
// 26/06/06 NLD Ajout SetPoint() pour Run multiple
// 27/06/06 NLD Ajout _CcvCurvesLimits
//              Ajout FindBestPoint()
// 03/07/06 NLD Ajout _RunDone
//              Ajout argument iRunToDo à Create()
// 21/10/11 NLD - Create()       est renommée CreateAndRunOperators()
//                Clear()        est renommée ClearOperators()
//              - SetGuideRank() est renommée SetCurveRank()
//                NumGuide       est renommée NumCurve
//              - Ajout _InvalidState
//=============================================================================
#ifndef CATFrFProjectionPtCcv_H 
#define CATFrFProjectionPtCcv_H 
//
#include "FrFAdvancedOpeUtil.h"
#include "CATMathDef.h"
#include "CATGeoFactory.h"
#include "CATFrFCompositeCurve.h"
#include "CATMathPoint.h"
#include "CATProjectionPtCrv.h"
#include "CATCGMVirtual.h"

//
class CATCrvParam;


class ExportedByFrFAdvancedOpeUtil  CATFrFProjectionPtCcv  : public CATCGMVirtual
{

 public:

  // Basic methods
  CATFrFProjectionPtCcv(       CATGeoFactory        *  iFactory,
                         const CATFrFCompositeCurve *  iCcv,
                         const CATMathPoint          & iPoint,
                         const CATMathDirection     *  iDirection = (const CATMathDirection *) NULL);
  virtual ~CATFrFProjectionPtCcv();

  // Returns the maximum orthogonal distance between the Ccv and the
  // point to project.
  double GetDistance();

  // Returns the number of points resulting of a CATProjectionPtCcv operator.
  CATLONG32 GetNumberOfPoints();

  // Initializes the iterator of the resulting points of a
  // CATProjectionPtCcv operator.
  // By default, the initialization is performed once the operator has been
  // calculated, and is therefore only used to read the solutions again.
  void BeginningPoint();

  // Points to the next solution point of a CATProjectionPrCrv operator.
  // After Beginning, it points to the first point.
  // return 1 if there is a solution point
  //        0 no more solution point.
  CATBoolean NextPoint();

  // Returns the next solution point of a CATProjectionPtCcv operator
  // as a CATCartesianPoint pointer.
  // Creates the object if necessary.
  CATCartesianPoint *GetCartesianPoint(CATLONG32 &oIndexOfCurve);

  // Returns the next solution point of a CATProjectionPtCcv operator
  // as a CATPointOnCurve pointer.
  // Creates the object if necessary.
  CATPointOnCurve  * GetPointOnCurve(CATLONG32 &oIndexOfCurve);

  // Returns the next solution point of a CATProjectionPtCcv operator
  // as a CATCrvParam.
  //Creates the object if necessary.
  CATCrvParam GetParam(CATLONG32 &oIndexOfCurve);
  CATLONG32   GetCrvIndexPoint() const;
  
  // Returns the number of curves resulting of a CATProjectionPtCcv operator.
  CATLONG32 GetNumberOfCurves();

  // Initializes the iterator of the resulting curves of a
  // CATProjectionPtCcv operator.
  // By default, the initialization is performed once the operator has been
  // calculated, and is therefore only used to read the solutions again.
  void BeginningCurve();

  // Points to the next solution curve of a CATProjectionPtCcv operator.
  // After Beginning, it points to the first point.
  // return 1 if there is a solution point
  //        0 no more solution point.
  CATBoolean NextCurve();

  // Returns the limitations of the current resulting curve of a
  // CATProjectionPtCcv operator.
  // Creates the object if necessary.
  CATCrvLimits  GetCurveLimits(CATLONG32 &oIndexOfCurve);
  CATLONG32     GetCrvIndexCurve() const;

  // Runs a CATProjectionPtCcv operator in mode.
  void Run();
  // Set new point to project
  void SetPoint(CATMathPoint& iPointToProject) ;
  // Recherche du meilleur point; attention usage limité ** EN TEST ***
  // ne pas utiliser les Get divers après cette methode
  CATBoolean FindBestPoint(CATLONG32 &oIndexOfCurve, CATCrvParam& oCrvParam) ;

  void SetTolerance( double iTol );

  void SetCurveRank( CATLONG32 iCurveRank );

 protected:
   void CreateAndRunOperators(int iRunToDo=1);
   void ClearOperators();

 private:

  // Input data
  CATGeoFactory              *  _Factory ;
  const CATFrFCompositeCurve *  _Ccv;
  CATMathPoint                  _PointToProject;

  //
  CATProjectionPtCrv         ** _ProjectionTab;
  CATLONG32                     _NbCurves;
  CATCartesianPoint          *  _PointInFactory;
  const CATMathDirection     *  _Direction;
  CATMathPoint               *  _CcvCurvesLimits ;

  // Les 2 paremetres suivants permettent la gestion de la solution courante
  CATLONG32                     _CurrentPoint;
  CATLONG32                     _CurrentCurve;

  double                        _Tol;
  CATLONG32                     _NumCurve;
  int                           _RunDone ;
  int                           _InvalidState;
};
#endif






