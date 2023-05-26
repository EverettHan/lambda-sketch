// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATSweepGeo2:
// Utility for migration.
//
//=============================================================================
// July. 98   Creation                                     C. FOUCART
//=============================================================================
#ifndef CATSweepGeo2_H
#define CATSweepGeo2_H                
               
#include "BO0SWEEPLight.h"
#include "CATMathDef.h" 
#include "CATListOfCATGeometries.h"
#include "CATListOfCATSweepGeo2.h"

class CATSweepGeo2Def ;
class CATGeometry ; 
class CATCrvLimits;   
class CATPGMExtruded;
class CATSetOfCrvParams;   

//-----------------------------------------------------------------------------
class ExportedByBO0SWEEPLight CATSweepGeo2
{
  public :
 
  //-------------------------------------------------------------------------
  // Constructors
  //-------------------------------------------------------------------------
  CATSweepGeo2 ();
  
  //-------------------------------------------------------------------------
  // Constructors
  //-------------------------------------------------------------------------
  void Init (int                     iProfileDim,
             CATGeometry            *iProfile,
             const CATCrvLimits     &iProfileLimits,
             int                     iCenterDim,
             CATGeometry            *iCenter,
             const CATCrvLimits     &iCenterLimits, 
             CATBoolean              isCenterVertexC1,
             CATLISTP(CATSweepGeo2) &iLinkWith,
             CATLISTP(CATGeometry)  &iLinkWithGeom,
             CATListOfInt           &iLinkWithOrient,
             CATSweepGeo2Def        *iGeometricDefinition) ;

  //-------------------------------------------------------------------------
  // Destructor
  //-------------------------------------------------------------------------
  ~CATSweepGeo2();

  //-------------------------------------------------------------------------
  // Read
  //-------------------------------------------------------------------------
  CATPGMExtruded * GetExtruded ();

#if 0
  //-------------------------------------------------------------------------
  // Extrude only one part of the Profile ( resp Center ).
  // Raise an exception whenever Profile is not a Curve.
  //-------------------------------------------------------------------------
  void SetProfileLimits( const CATCrvLimits & iProfileLimits ) ; 
  void SetCenterLimits ( const CATCrvLimits & iCenterLimits  ) ; 
#endif
  
  //-------------------------------------------------------------------------
  // Read resulting geometry
  //-------------------------------------------------------------------------
  CATGeometry* GetResult() ;
  void GetCuttingParams (CATSetOfCrvParams *& ioCuttingParams, CATListOfInt ** ioSharpness=NULL); 

  //-------------------------------------------------------------------------
  // Read sub-geometry generated from multiplication of a Sub-Geometry and 
  // a sub-geometry in the context of a supporting geometry.
  // Sub-Geometry is the one whichis returned by CATCell::GetGeometryOn...
  //-------------------------------------------------------------------------
  CATGeometry* GetResult ( CATGeometry* iProfile, 
			   CATGeometry* iCenter, 
			   CATSweepGeo2* iLinkWith=NULL,
         CATGeometry * iGeom = NULL
         ) ; 

  //-------------------------------------------------------------------------
  // Returns TRUE whenever the normal of the generated surface 
  // could not be set to Profile ^ Center.
  //-------------------------------------------------------------------------
  CATBoolean IsOrientationChanged() const ; 
 
 //-------------------------------------------------------------------------
  // Data
  //-------------------------------------------------------------------------
  protected :
	
  CATPGMExtruded  *              _Extruded;
};

#endif








