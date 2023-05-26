/* -*-C++-*- */

#ifndef CATCVMGeoUtilities_H
#define CATCVMGeoUtilities_H

// COPYRIGHT DASSAULT SYSTEMES 2005

//===================================================================
//===================================================================
//
// CATCVMGeoUtilties
//
// Internal geometric utilities for Collaborative Variational
// Modelling (CVM)
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Mar. 2006    Creation                         Alex State
// Feb. 2008    GetNonCanonical2DBoundingBox     PKC
// May  2008    new methods with instance path   FCX
//===================================================================

#include "CATCVMGeoObjects.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"
#include "ListPOfCATCVMSystem.h"
#include "ListPOfCATBody.h"
#include "CATCVMDef.h"
#include "CATErrorDef.h"

class CATCVMSystem;
class CATCVMGeometry;
class CATMathPoint;
class CATMathLine;
class CATMathAxis;
class CATSurface;
class CATSurParam;
class CATCVMBody;
class CATCVMGeoContainer;
class CATBody;
class CATCVMLog;
class CATCVMComponent;
class CATCGMJournalList;
class CATCGMHashTable;
class CATCVMSession;
class CATCVMPSContainer;
class CATCVMReference;
class CATGeoFactory;
class CATCVMInstancePath;
class CATMathDirection;

class CATSoftwareConfiguration;

class ExportedByCATCVMGeoObjects CATCVMGeoUtilities
{

  //------------------------------------------------------------------------------
  // Is isolated face (i.e. no adjacent faces, but adjacent wires are permitted)
  //------------------------------------------------------------------------------
  public:
	static CATBoolean IsIsolatedFace(CATCVMGeometry *iCVMGeometry);

//------------------------------------------------------------------------------
// Get all isolated vertices in the geocontainer
// if a list ist given as input, returns the list of isolated vertices (as CVMGeometries)
// else ERASE all isolated vertices found
// NB : the list must be empty as input
//------------------------------------------------------------------------------
  public:
  static HRESULT ScanIsolatedVertices(CATCVMGeoContainer * iCVMGeoContainer, 
                                      ListPOfCATCVMGeometry * ioListOfVertives = NULL);
	
  //-----------------------------------------------------------------------------------------
  // Project the input point to a CVM geometry
  // (return TRUE if the projection has been performed, FALSE otherwise)
  //-----------------------------------------------------------------------------------------
	static CATBoolean ProjectPoint(CATMathPoint & ioMathPoint, CATCVMGeometry *iSupport, CATCVMInstancePath * iInstancePath = 0);

  //-----------------------------------------------------------------------------------------
  // Project the input point to a CVM geometry in a given direction
  // (return TRUE if the projection has been performed, FALSE otherwise)
  //-----------------------------------------------------------------------------------------
	static CATBoolean ProjectPointInDirection(CATMathPoint       &ioMathPoint,
                                            CATCVMGeometry     *iSupport,
                                            CATMathDirection   &iDirection,
                                            CATCVMInstancePath *iInstancePath = 0);

  //-----------------------------------------------------------------------------------------
  // Get the center point of the input CVM edge
  // (return TRUE if the edge is a circle, FALSE otherwise)
  //-----------------------------------------------------------------------------------------
  static CATBoolean GetCircleCenter(CATCVMGeometry * iCVMEdge, CATMathPoint & oCenterPoint);

  //-----------------------------------------------------------------------------------------
  // Get the center point of the input CVM edge with instance path
  // (return TRUE if the edge is a circle, FALSE otherwise)
  //-----------------------------------------------------------------------------------------
  static CATBoolean GetCircleCenter(CATCVMGeometry * iCVMEdge, CATCVMInstancePath * iInstancePath, CATMathPoint & oCenterPoint);

  //-----------------------------------------------------------------------------------------
  // Get the list of edges representing a complete circle or arc
  // (return TRUE if the edge is a circle, FALSE otherwise)
  //-----------------------------------------------------------------------------------------
  static CATBoolean GetCompleteArcEdges(CATCVMGeometry * iCVMEdge, ListPOfCATCVMGeometry &oListEdge);

  //-----------------------------------------------------------------------------------------
  // Compute a CATMathPoint defined by :
  // - is on iSupport (if it exists)
  // - is at a minimal distance from iViewLine
  // - is near iApproxPoint (if several solution points exist)
  //-----------------------------------------------------------------------------------------
  // DEPRECATED : use method with instance path
  static void ComputePickingPoint(CATCVMGeometry * iSupport, CATMathLine & iViewLine, CATMathPoint & iApproxPoint, CATMathPoint & oPoint);

  //-----------------------------------------------------------------------------------------
  // Compute a CATMathPoint defined by :
  // - is on iSupport (if it exists)
  // - is at a minimal distance from iViewLine
  // - is near iApproxPoint (if several solution points exist)
  //-----------------------------------------------------------------------------------------
  static void ComputePickingPoint(CATCVMGeometry * iSupport, CATCVMInstancePath * iInstancePath, CATMathLine & iViewLine, CATMathPoint & iApproxPoint, CATMathPoint & oPoint);

  //------------------------------------------------------------------------------
  // Create a CVM body with a given CGM body
  //------------------------------------------------------------------------------  
  static CATCVMBody *CreateCVMBody(CATCVMGeoContainer *iCVMGeoContainer,
                                   CATBody            *iCGMBody,
                                   CATCVMLog          *iCVMLog,
                                   CATCVMComponent    *iRootComponent = NULL,
                                   CATCGMJournalList  *iJournalList   = NULL);
  //------------------------------------------------------------------------------
  // Get all CVM System under another system (and all underlying systems)
  // For example all CVMBodies  under a CVMReference 
  // For example all CVMGeoMesh under the ReuseComponent
  // Warning: if iCVMSystem is a iCVMType Object, it will be added first in the oCVMSystemList 
  // it must be added to avoid recursive treatment onto iCVMSystem itself
  //------------------------------------------------------------------------------
  public:
  static void GetAllCVMSystems(CATCVMSystem        *iCVMSystem,
                               ListPOfCATCVMSystem &ioCVMSystemList,
                               CATCVMObjectType     iCVMType,
                               CATCGMHashTable     *iWorkingHashTable=NULL);
  //------------------------------------------------------------------------------
  // Get all CGM Bodies under the CVMGeoContainer or under a specific CVMsystem of it
  // For example all CVMBodies  under a CVMReference 
  // For example all CVMGeoMesh under the ReuseComponent
  // Warning: if iCVMSystem is a iCVMType Object, it will be added first in the oCVMSystemList 
  // it must be added to avoid recursive treatment onto iCVMSystem itself
  //------------------------------------------------------------------------------
  static void GetCATBodies(CATCVMGeoContainer * iCVMGeoContainer,
                           ListPOfCATBody     & oCGMBodies,
                           CATCVMSystem       * iCVMRootSystem=NULL );

  
  //--------------------------------------------------------------------------
  // Compute Exact 2DBox of planar Face under iCVMGeometry
  // (iCVMGeometry MUST be a planar Face)
  // 2DBox is computed in Axis defined by iAxis
  // iAxis must have third direction parallel to support plane normal direction
  // resulting 2D Box is not parallel to canonical axis of plane but parallel to 
  // iAxis First and second direction.
  // oLow is Low Point of 2D Box
  // oHigh is High Point of 2D Box
  // 
  // return TRUE is computation is OK
  // return FALSE if computation is KO 
  // 
  //--------------------------------------------------------------------------
  static CATBoolean GetNonCanonical2DBoundingBox(CATCVMGeometry* iCVMGeometry,
                                                 CATMathAxis& iAxis,
                                                 CATSurface*& oSupportSurface,
                                                 CATSurParam& oLow,
                                                 CATSurParam& oHigh);

  //--------------------------------------------------------------------------
  // Create a session with a PSContainer and
  // a RootReference containing an empty GeoContainer
  //--------------------------------------------------------------------------
  static CATCVMSession *CreateSession(CATCVMPSContainer **oPSContainer   = NULL,
                                      CATCVMReference   **oRootReference = NULL,
                                      CATCVMGeoContainer **oGeoContainer = NULL);

  //--------------------------------------------------------------------------
  // Get the GeoContainer of the root reference of the PS container
  //--------------------------------------------------------------------------
  static CATCVMGeoContainer *GetGeoContainer(CATCVMPSContainer  *iPSContainer,
                                             CATCVMReference   **oRootReference = NULL);


  //-----------------------------------------------------
  // KUB: Trouve le "centre" d'une interface (pour le scaling)
  //-----------------------------------------------------
  static int ComputeScalingCenter(CATMathPoint & iBoundingBoxCenter, ListPOfCATCVMGeometry & iListOfSelectedGeom, CATMathPoint &oInterfaceCenter);



  private:
  CATCVMGeoUtilities();
};
#endif
