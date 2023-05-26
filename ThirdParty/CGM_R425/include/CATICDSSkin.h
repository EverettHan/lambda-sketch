#ifndef CATICDSSkin_H
#define CATICDSSkin_H

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCDS.h"

#include "CATCDSAdvancedEnums.h"
#include "CATICDSGeometryLeaf.h"

class CATICDSSkinParam;

/**
 * @SKIP
 *
 * 3D rigid surface.
 */ 
class ExportedBySolverInterface CATICDSSkin : public CATICDSGeometryLeaf
{
public:
  
  /** 
   * Create a parameter on the skin.
   * @return
   *   Created skin parameter.
   */
  virtual CATICDSSkinParam* CreateParam() const = 0;
  
  /** 
   * Create a parameter on the skin from a 3D point.
   * @return
   *   Created skin parameter.
   */
  virtual CATICDSSkinParam* CreateParam(double iaPoint[3]) const = 0;

  /** 
   * Create a parameter on the skin from another skin parameter.
   * @return
   *   Created skin parameter.
   */
  virtual CATICDSSkinParam* CreateParam(const CATICDSSkinParam *ipPointOnSkin) const = 0;

  /**
   * Evaluate 3D data on skin at a skin parameter.
   * @param ipPointOnSkin
   *   Input skin parameter.
   * @param oaPoint
   *   Output 3D point.
   * @param oaDU
   *   Output first derivative along U.
   * @param oaDV
   *   Output first derivative along V.
   * @param oaD2U
   *   Output second derivative along U.
   * @param oaDUDV
   *   Output second derivative.
   * @param oaD2V
   *   Output second derivative along V.
   * @return
   *   TRUE if successful.
   */
  virtual CATCDSBoolean Evaluate(
    CATICDSSkinParam *ipPointOnSkin,
    double oaPoint[3],
    double oaDU[3],
    double oaDV[3],
    double oaD2U[3],
    double oaDUDV[3],
    double oaD2V[3]) const = 0;

  /**
   * Evaluate 3D data on skin at skin parameter on wire.
   * @param ipPointOnSkin
   *   Input skin parameter.
   * @param oaPoint
   *   Output 3D point.
   * @param oaDW
   *   Output first derivative.
   * @param oaD2W
   *   Output second derivative.
   * @return
   *   TRUE if successful.
   */
  virtual CATCDSBoolean EvaluateOnWire(
    CATICDSSkinParam *ipPointOnSkin,
    double oaPoint[3],
    double oaDW[3],
    double oaD2W[3]) const = 0;

  /**
   * Compute a new skin parameter from an initial skin parameter and a 2D
   * vector expressed in the initial skin parameter's base.
   * @param ipPointOnSkin
   *   Input skin parameter.
   * @param iDeltaU
   *   Input change of U parameter.
   * @param iDeltaV
   *   Input change of V parameter.
   * @param iStopCommand
   *   Input stop command.
   * @param opPointOnSkin
   *   Result skin parameter.
   * @param oAppliedDeltaU
   *   Acheived change of U parameter.
   * @param oaPoint
   *   Acheived change of V parameter.
   * @return
   *   TRUE if successful.
   */
  virtual CATCDSBoolean GetClosePoint(
    CATICDSSkinParam *ipPointOnSkin,
    double iDeltaU, double iDeltaV,
    CATCSStopCommand iStopCommand,
    CATICDSSkinParam * opPointOnSkin,
    CATCSClosePointDiagnostics &oDiagnostics,
    double &oAppliedDeltaU, double &oAppliedDeltaV) const = 0;

  /**
   * Compute a new skin parameter from an initial skin parameter on wire and a
   * parameter delta in its wire.
   * @param ipPointOnSkin
   *   Input skin parameter.
   * @param iDeltaW
   *   Input change of parameter.
   * @param iDeltaV
   *   Input translation along V axis.
   * @param iStopCommand
   *   Input stop command.
   * @param opPointOnSkin
   *   Result skin parameter.
   * @param oAppliedDeltaU
   *   Acheived change of parameter.
   * @return
   *   TRUE if successful.
   */
  virtual CATCDSBoolean GetClosePointOnWire(
    CATICDSSkinParam * ipPointOnSkin,
    double iDeltaW,
    CATCSStopCommand iStopCommand,
    CATICDSSkinParam *opPointOnSkin,
    CATCSClosePointDiagnostics & oDiagnostics,
    double & oAppliedDeltaW) const = 0;
};

#endif
