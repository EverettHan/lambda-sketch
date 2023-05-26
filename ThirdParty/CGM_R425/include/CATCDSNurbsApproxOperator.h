// COPYRIGHT Dassault Systemes 2013
//===================================================================

// CATCDSNurbsApproxOperator.h

//===================================================================

// Usage notes: Math function associated with the X or Y coordinate of a 2D monoparametric

//===================================================================

//  Oct 2012  Creation:             BF8 CHU
//===================================================================
#ifndef CATCDSNurbsApproxOperator_H
#define CATCDSNurbsApproxOperator_H

#include "CATICDSNurbsApproxOperator.h"
#include "CDSProfile.h"

class CATCSMonoParametric;
class CATSoftwareConfiguration;
class CATGeoFactory;
class CATSurface;
//-----------------------------------------------------------------------

class ExportedByCDSProfile CATCDSNurbsApproxOperator : public CATICDSNurbsApproxOperator
{
public:
   // Life Cycle
  CATCDSNurbsApproxOperator(CATSoftwareConfiguration* pConfig);
  virtual ~CATCDSNurbsApproxOperator();

  //Initialize attributes. 
  virtual CATCDSBoolean SetCurveToApprox(CATICDSMonoParametric2D & iMonoParam, double iLinearTolerance);

  //Compute the approximation
  virtual CATCDSBoolean Run();
 
   
  //Read the parameters of the approximate NURBS
  virtual CATCDSBoolean GetResultNurbs (int& oNbOfControlPoints, int& oDegree, double*& oControlPoints, double*& oKnots, double*& oWeights);

#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
   /**
    * @nodoc
    * Do not use. For compatibility only.
    * Initialize operands (same as above), this method is temporary and should not be called when public interfaces are integrated to all applications
    * Temporarily, work wirth protected interface CATCSMonoParametric, to enable trimming profiles created by the player, while the player does not yet handle public interfaces (waiting for bf8)
    */
  virtual CATCDSBoolean SetOperandsBypassPublicInterfaces(CATCSMonoParametric * ipMonoParam, double iLinearTolerance);
#endif

  
  virtual void SetConfig(CATSoftwareConfiguration* pConfig);
  virtual void SetGeoFactory(CATGeoFactory* pGeoFactory);

  virtual CATSoftwareConfiguration* GetConfig();
  virtual CATGeoFactory* GetGeoFactory();

private:
  // Input Data
  CATSoftwareConfiguration * _pConfig;     //Not owned
  CATGeoFactory            * _pCGMFactory; //owned
  CATSurface               * _pPlane;      //owned
  CATICDSMonoParametric2D  * _pMonoParam;  //Not owned
  int                        _NbOfControlPoints;
  int                        _Degree;
  double                   * _aControlPoints; 
  double                   * _aKnots; 
  double                   * _aWeights;
  double                     _LinearTolerance;

#ifdef CDSPROFILE_FIX_2013_01_10_TemporaryBypassPublicInterfaces    
  CATCSMonoParametric     * _pMonoParamBypassPublicInterfaces; 
#endif
};

//-----------------------------------------------------------------------

#endif
