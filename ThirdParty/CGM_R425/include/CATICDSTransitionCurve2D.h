#ifndef CATICDSTransitionCurve2D_H
#define CATICDSTransitionCurve2D_H

// COPYRIGHT DASSAULT SYSTEMES  2020

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */
 
#include "CATCDS.h"

#include "CATICDSEnums.h"
#include "CATCDSBoolean.h"
#include "CATICDSCurve2D.h"
#include "StreamGM.h"
#include "CATCivilCurveDef.h"

class CATICDSFactory;
class CATICDSPoint2D;
class CATICDSLine2D;
class CATICDSCircle2D;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCurve;
class CATCivilCurveEvaluator;

/**
 * A Transition curve constructed from geometrical objects and parameters
 */
class ExportedByStreamGM CATICDSTransitionCurve2D : public CATICDSCurve2D
{
public:
  virtual CATCivilCurveType GetTransitionCurveType() const = 0;

  virtual CATICDSPoint2D*   GetInitialPoint() const = 0;

  virtual CATICDSLine2D*    GetInitialLine() const = 0;

  virtual CATICDSCircle2D*  GetInitialCircle() const = 0;

  virtual CATICDSPoint2D*   GetFinalPoint() const = 0;

  virtual CATICDSLine2D*    GetFinalLine() const = 0;

  virtual CATICDSCircle2D*  GetFinalCircle() const = 0;

  virtual int               GetSide() const = 0;

  virtual int               GetInitialOrientation() const = 0;

  virtual int               GetFinalOrientation() const = 0;

  virtual void              GetInitialParameters( double const *& opA2,
                                           double const *& opLength,
                                           double const *& opRadius,
                                           double const *& opAngle,
                                           double const *& opShift)   = 0;

  virtual void              SetGeoFactory( CATGeoFactory *ipGeoFactory) = 0;

  virtual void              SetSoftwareConfiguration (CATSoftwareConfiguration* ipConfig) = 0;

  virtual CATCDSBoolean     CreateCurve(CATPlane &  iPlane,
                                    CATCurve *& opTransitionCurve,
                                    double      oaPoint[2]          )    const = 0;

  virtual CATCDSBoolean CreateCurve(CATPlane                  & iPlane,
                                    CATCurve                 *& opTransitionCurve,
                                    double                      oaPoint[2],
                                    double                   *& opA2,
                                    double                   *& opLength,
                                    double                   *& opRadius,
                                    double                   *& opAngle,
                                    double                   *& opShift) const = 0;


  //old
  static CATICDSTransitionCurve2D* Create(CATICDSFactory            * ipFactory, 
                                          CATCivilCurveType           iType,
                                          CATICDSPoint2D            * ipInitialPoint, 
                                          int                         initialOrientation, 
                                          CATICDSLine2D             * ipInitialLine, 
                                          CATICDSCircle2D           * ipInitialCircle, 
                                          CATICDSPoint2D            * ipFinalPoint, 
                                          int                         iFinalOrientation, 
                                          CATICDSLine2D             * ipFinalLine, 
                                          CATICDSCircle2D           * ipFinalCircle, 
                                          int                         iSide, 
                                          double                    * ipA2,
                                          double                    * ipLength, 
                                          double                    * ipRadius, 
                                          double                    * ipAngle, 
                                          double                    * ipShift);

  static CATICDSTransitionCurve2D* Create(CATICDSFactory            * ipFactory, 
                                          CATCivilCurveType           iType,
                                          CATICDSPoint2D            * ipInitialPoint, 
                                          int                         initialOrientation, 
                                          CATICDSLine2D             * ipInitialLine, 
                                          CATICDSCircle2D           * ipInitialCircle, 
                                          CATICDSTransitionCurve2D    * ipInitialSpiral, 
                                          CATICDSPoint2D            * ipFinalPoint, 
                                          int                         iFinalOrientation, 
                                          CATICDSLine2D             * ipFinalLine, 
                                          CATICDSCircle2D           * ipFinalCircle, 
                                          int                         iSide, 
                                          double                    * ipA2,
                                          double                    * ipLength, 
                                          double                    * ipRadius, 
                                          double                    * ipAngle, 
                                          double                    * ipShift);

  virtual ~CATICDSTransitionCurve2D() {}
};

#endif
