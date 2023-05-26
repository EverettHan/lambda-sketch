// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATExtruded:
// Utility for producing extrusion of Geometric entities.
//
//=============================================================================
// Usage notes:
//
// - Combines 2 geometric elements into a single one.
// - Establishes links with previously extruded entities.
// - Retains information on what has been combined into what.
//=============================================================================
//   /06/98 RR  Creation                                     R. Rorato
// 01/10/09 NLD Ajout ComputeEdgeCurveAggregate()
// 16/01/11 NLD Ajout ComputeEdgeCurveC0Intersect()
//=============================================================================
#ifndef CATExtruded_H
#define CATExtruded_H

#include "Extrude.h"
class CATGeometry ;
class CATCrvParam ;
class CATSetOfCrvParams;
class CATCrvLimits ;
class CATSurParam ;
class CATSurLimits ;
class CATExtrudedInstance ;
class CATError;
#include "CATExtruder.h"
#include "CATCrvLimits.h"
#include "CATListOfInt.h"
#include "CATListOfCATPGMExtruded.h"
#include "CATListOfCATExtrudedInstances.h"
#include "CATMathDef.h"
#include "CATPGMExtruded.h"
#include "CATSoftwareConfiguration.h"


//-----------------------------------------------------------------------------
class ExportedByExtrude CATExtruded  : public CATPGMExtruded
{
  public :

  //-------------------------------------------------------------------------
  // Constructors ( please use CATExtruder::CreateExtruded )
  //-------------------------------------------------------------------------
  CATExtruded();

  //-------------------------------------------------------------------------
  // Init
  //-------------------------------------------------------------------------
  void Init ( CATGeometry               *iProfile,          // MacroPoint, EdgeCurve or Surface
              CATCrvLimits              *iProfileLimits,    // If EdgeCurve
              CATGeometry               *iCenter,           // MacroPoint, EdgeCurve or Surface
              CATCrvLimits              *iCenterLimits,     // If EdgeCurve
              CATLISTP(CATPGMExtruded)  &iLinkWith,
              CATLISTP(CATGeometry)     &iLinkWithGeom,
              CATListOfInt              &iSigns,
              CATExtruder               *iExtruder,
              CATSoftwareConfiguration  *iSoftwareConfiguration,
              CATExtruder::Continuity iContinuity = CATExtruder::C1   ) ;

  //-------------------------------------------------------------------------
  // Destructor
  //-------------------------------------------------------------------------
  virtual ~CATExtruded();
  
  //-------------------------------------------------------------------------
  // GetResult() returns resulting composite geometry.
  // GetResult(Profile,Center,LinkWith) Returns sub-geometry generated from 
  // multiplication of a Sub-Geometry and 
  // a sub-geometry in the context of a previous extrusion.
  // Sub-Geometry is the one which is returned by CATCell::GetGeometryOn...
  //-------------------------------------------------------------------------
  CATGeometry* GetResult ( CATGeometry    * iProfile  = NULL,
                           CATGeometry    * iCenter   = NULL,
                           CATPGMExtruded * iLinkWith = NULL, // anciennement CATExtruded*
                           CATGeometry    * iGeom     = NULL
                         ) ; 

  //-------------------------------------------------------------------------
  void GetCuttingParams (const CATSetOfCrvParams *& ioCuttingParams, CATListOfInt ** ioSharpness) const;

  //-------------------------------------------------------------------------
  // Surface: Returns TRUE whenever the normal of the generated surface 
  // could not be set to Profile ^ Center.
  // Curve: returns TRUE whenever the generated curve has a different
  // orientation from the input curve.
  // Must be called after GetResult() call.
  //-------------------------------------------------------------------------
  CATBoolean IsOrientationChanged() const ; 

  //=========================================================================
  // Internal usage
  //=========================================================================
  CATLONG32 GetInstancesCount() const ;
  CATExtrudedInstance* GetInstance( const CATLONG32 iInstanceIndex = 0 ) const ;

  //-------------------------------------------------------------------------
  // Access to Extruder
  //-------------------------------------------------------------------------
  CATPGMExtruder* GetExtruder() const ;

  private:
  //-------------------------------------------------------------------------
  // Edge curve computation by aggregation
  //-------------------------------------------------------------------------
  void ComputeEdgeCurveAggregate(CATError*& oError);

  //-------------------------------------------------------------------------
  // Edge curve computation on guide C0 vertex by intersection
  //-------------------------------------------------------------------------
  void ComputeEdgeCurveC0Intersect(CATError*& oError);

  //-------------------------------------------------------------------------
  // Data
  //-------------------------------------------------------------------------
  private :

  CATExtruder*                   _Extruder           ;
  CATGeoFactory*                 _Factory            ;
  CATGeometry*                   _Profile            ;
  CATGeometry*                   _Center             ;
  CATGeometry*                   _Result             ;
  CATExtruder::Continuity        _Continuity         ;
  short                          _ProfileDimension   ;
  short                          _CenterDimension    ;
  short                          _ResultDimension    ;
  CATCrvLimits                   _ProfileLimits      ;
  CATCrvLimits                   _CenterLimits       ;
  CATLISTP(CATCrvLimits)         _PCurveLimits       ;
  CATCrvLimits                   _OriginalProfileLimits;
  CATCrvLimits                   _OriginalCenterLimits;
  CATCrvLimits                   _OriginalPCurveLimits;
  CATLISTP(CATExtrudedInstance)  _Instances          ;

  // For Meridian Curves only
  CATLISTP(CATPGMExtruded)       _InitExtrudedPoints ;
  CATLISTP(CATPointOnEdgeCurve)  _InitPoecs          ;
  CATLISTP(CATExtrudedInstance)  _InitPoecsInstance  ;
  CATListOfInt                   _InitSigns          ;
  CATLISTP(CATPointOnEdgeCurve)  _CuttingPoecs       ;
  CATSetOfCrvParams             *_CuttingParams      ;
  CATListOfInt                  *_Sharpness;

  //versionning:
  CATSoftwareConfiguration      *_SoftwareConfiguration;
};

#endif








