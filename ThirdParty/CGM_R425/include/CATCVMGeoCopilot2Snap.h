// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATCVMGeoCopilot2Snap_H
#define CATCVMGeoCopilot2Snap_H

/**
* 14.09.17 KJD : Addition of the WriteSnap + StoreGeo APIs to enable the record  the GMCopilot CGMReplay during CVM Run
*                 => extract of the data from CVMSnap to GMSnap 
*/

#include "CATCVMGeoCopilot2.h"
#include "CATCVMGeoOperators.h"
#include "ListPOfCATCVMGeometry.h"
#include "CATMathDirection.h"
#include "CATMathDirection2D.h"
#include "CATCVMGeoDef.h"
#include "CATMathPlane.h"
#include "CATLISTV_CATMathPoint.h"
#include "ListPOfCATCVMGeoMesh.h"
#include "CATCVMInstancePath.h"
#include "CATCVMGeometry.h"

//#ifdef  ActivateCVMInstancePath  //En attendant migration CATLSDrawMagnet
#include "ListPOfCATCVMInstancePath.h"
//#endif 

class ExportedByCATCVMGeoOperators CATCVMGeoCopilot2Snap
{
public:

  virtual ~CATCVMGeoCopilot2Snap();

  /**
  * return the type of this snap (definition of CATCVMSnapType in CATCVMGeoDef.h)
  */
  virtual CATCVMSnapType GetType() = 0;

  /**
  * get the reference geometry list (if this snap is a CATCVMSnapType_ReferenceDirection,
  * return a null size list)
  */
  virtual void GetReferenceGeometry(ListPOfCATCVMGeometry & oListReferenceGeometry) = 0;

  /**
  * get the reference meshes list (if this snap is a CATCVMSnapType_GeoMeshPoint)
  */
  virtual void GetReferenceGeoMesh(ListPOfCATCVMGeoMesh & oListReferenceGeoMesh) = 0;

  /**
  * return TRUE: get the alignment direction (if this snap is an aligned snap type)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetAlignmentDirection(CATMathDirection & oAlignmentDirection) = 0;

  /**
  * return TRUE: get the 2D alignment direction (if this snap is an aligned snap type)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetAlignmentDirection2D(CATMathDirection2D & oAlignmentDirection2D) = 0;

  /**
  * return TRUE: get the reference direction (if this snap is a CATCVMSnapType_ReferenceDirection)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetReferenceDirection(CATMathDirection & oReferenceDirection) = 0;

  /**
  * return TRUE: get the 2D reference direction (if this snap is a CATCVMSnapType_ReferenceDirection)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetReferenceDirection2D(CATMathDirection2D & oReferenceDirection2D) = 0;

  /**
  * return TRUE: get the alignment reference edge (if this snap is an aligned snap type)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetAlignmentEdge(CATCVMGeometry *& oAlignmentEdge) = 0;

  /**
  * return TRUE: get the reference plane (if this snap is a CATCVMSnapType_ReferencePlanePoint)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetReferencePlane(CATMathPlane & oReferencePlane) = 0;

  /**
  * return TRUE: get the reference circle (if this snap is a CATCVMSnapType_OnRestrictedDistance)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetReferenceDistance(double & oReferenceDistance) = 0;

  /**
  * return TRUE: get the tangency points corresponding to the edge iCVMEdge (if this snap is a CATCVMSnapType_CircleTangentDirection)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetTangencyPoints(CATCVMGeometry * iCVMEdge, CATLISTV(CATMathPoint) & oTangencyPoints) = 0;

  /**
  * return TRUE: get the radial points corresponding to the edge iCVMEdge (if this snap is a CATCVMSnapType_CircleRadialDirection)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetRadialPoints(CATCVMGeometry * iCVMEdge, CATLISTV(CATMathPoint) & oRadialPoints) = 0;

  /**
  * return TRUE: get arc extremities data (if this snap is a CATCVMSnapType_ExtremityForTangentArc or CATCVMSnapType_LineForTangentArc)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetArcExtremities(CATLISTV(CATMathPoint) & oListPoint, ListPOfCATCVMGeometry & oListSupportGeometry) = 0;

  virtual void Dump(CATCGMOutput & os)  = 0;

private:

  CATCVMGeoCopilot2Snap(const CATCVMGeoCopilot2Snap &);
  void operator = (const CATCVMGeoCopilot2Snap &);

protected:

  CATCVMGeoCopilot2Snap();

//En attendant migration CATLSDrawMagnet
  public:
 /**
  * get the reference geometry list (if this snap is a CATCVMSnapType_ReferenceDirection,
  * return a null size list)
  */
  virtual void GetReferenceGeometry(ListPOfCATCVMGeometry & oListReferenceGeometry, ListPOfCATCVMInstancePath & oListInstancePath) = 0;
  virtual void WriteSnap(CATCGMStream  & ioStream) = 0;
  virtual int StoreGeo(CATLISTP(CATGeometry) & ListGeo) = 0;
#ifdef  ActivateCVMInstancePath
public:
   /**
  * get the reference geometry list (if this snap is a CATCVMSnapType_ReferenceDirection,
  * return a null size list)
  */
  //virtual void GetReferenceGeometry(ListPOfCATCVMGeometry & oListReferenceGeometry, ListPOfCATCVMInstancePath & oListInstancePath) = 0;

  /**
  * get the reference meshes list (if this snap is a CATCVMSnapType_GeoMeshPoint)
  */
  virtual void GetReferenceGeoMesh(ListPOfCATCVMGeoMesh & oListReferenceGeoMesh, ListPOfCATCVMInstancePath & oListInstancePath) = 0;

  /**
  * return TRUE: get the alignment reference edge (if this snap is an aligned snap type)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetAlignmentEdge(CATCVMGeometry *& oAlignmentEdge, CATCVMInstancePath *& oInstancePath) = 0;
 
  /**
  * return TRUE: get the tangency points corresponding to the edge iCVMEdge (if this snap is a CATCVMSnapType_CircleTangentDirection)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetTangencyPoints(CATCVMGeometry * iCVMEdge, CATCVMInstancePath * iInstancePath, CATLISTV(CATMathPoint) & oTangencyPoints) = 0;

  /**
  * return TRUE: get the radial points corresponding to the edge iCVMEdge (if this snap is a CATCVMSnapType_CircleRadialDirection)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetRadialPoints(CATCVMGeometry * iCVMEdge, CATCVMInstancePath * iInstancePath, CATLISTV(CATMathPoint) & oRadialPoints) = 0;

  /**
  * return TRUE: get arc extremities data (if this snap is a CATCVMSnapType_ExtremityForTangentArc or CATCVMSnapType_LineForTangentArc)
  * return FALSE: otherwise
  */
  virtual CATBoolean GetArcExtremities(CATLISTV(CATMathPoint) & oListPoint, ListPOfCATCVMGeometry & oListSupportGeometry, ListPOfCATCVMInstancePath & oListInstancePath) = 0;
#endif

};

#endif
