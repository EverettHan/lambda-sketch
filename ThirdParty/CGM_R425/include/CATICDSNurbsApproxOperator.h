// COPYRIGHT Dassault Systemes 2012
//===================================================================

// CATICDSNurbsApproxOperator.h

//===================================================================

// Usage notes: Interface of operator dedicated to approximate a curve in a NURBS

//===================================================================

//  Sept 2013  Creation:             BF8 CHU
//===================================================================
#ifndef CATICDSNurbsApproxOperator_H
#define CATICDSNurbsApproxOperator_H

#include "CATCDS.h"
#include "CATCDSBoolean.h"
#define CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces

class CATICDSMonoParametric2D;
#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
class CATCSMonoParametric;
#endif
class CATSoftwareConfiguration;
class CATGeoFactory;

/*
 * @SKIP
 */
class ExportedBySolverInterface CATICDSNurbsApproxOperator
{

public:

  /**
   * Life Cycle (this class must be derived)
   */
  virtual ~CATICDSNurbsApproxOperator();

  /**
   * Initialize attributes. 
   * @param iMonoParam
   *   Monoparametric that we want to approximate
   * @param iLinearTolerance
   *   Minimum distance between solutions
   * @return
   *   TRUE if initialisation completed successfully, otherwise FALSE
   */
  virtual CATCDSBoolean SetCurveToApprox(CATICDSMonoParametric2D & iMonoParam,
    double iLinearTolerance) = 0;

  /**
   * Compute the approximation
   * @return
   *   TRUE if computation completed successfully, otherwise FALSE
   */
  virtual CATCDSBoolean Run() = 0;
   
  /**
   * Read the parameters of the approximate NURBS
   * @param oNbOfControlPoints
   *   Number of control points
   * @param oControlPoints
   *   array of control points coordinates
   * @param oWeights
   *   array of the weights
   * @return
   *   TRUE if the requested solution exists
   */
  virtual CATCDSBoolean GetResultNurbs (int& oNbOfControlPoints, int& oDegree, double*& oControlPoints, double*& oKnots, double*& oWeights) = 0;

#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
   /**
    * @nodoc
    * Do not use. For compatibility only.
    * Initialize operands (same as above), this method is temporary and should not be called when public interfaces are integrated to all applications
    * Temporarily, work wirth protected interface CATCSMonoParametric, to enable trimming profiles created by the player, while the player does not yet handle public interfaces (waiting for bf8)
    */
  virtual CATCDSBoolean SetOperandsBypassPublicInterfaces(CATCSMonoParametric * ipMonoParam, double iLinearTolerance) = 0;
#endif

  virtual void SetConfig(CATSoftwareConfiguration* pConfig) = 0;
  virtual void SetGeoFactory(CATGeoFactory* pGeoFactory) = 0;

  virtual CATSoftwareConfiguration* GetConfig() = 0;
  virtual CATGeoFactory* GetGeoFactory() = 0;

protected :
  /**
  * Life Cycle (this class must be derived)
  */
  CATICDSNurbsApproxOperator();
};

#endif
