// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATCVMGeoCopilot2_H
#define CATCVMGeoCopilot2_H

#include "CATCVMGeoOperator.h"
#include "CATCVMGeoDef.h"
#include "ListPOfCATCVMGeoCopilot2Magnet.h"
#include "ListPOfCATCVMGeometry.h"
#include "ListPOfCATCVMBody.h"
#include "ListPOfCATCVMGeoMesh.h"
#include "CATLISTP_CATMathDirection.h"
#include "CATLISTP_CATMathDirection2D.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATLISTP_CATMathPlane.h"

class CATCVMGeoContainer;
class CATTopData;
class CATMathPoint;
class CATCVMSystem;

//#define ActivateCVMInstancePath
#ifdef  ActivateCVMInstancePath
#include "ListPOfCATCVMInstancePath.h"
#endif

class ExportedByCATCVMGeoOperators CATCVMGeoCopilot2 : public CATCVMGeoOperator
{
  CATCGMVirtualDeclareClass(CATCVMGeoCopilot2);
public:

  //------------------------------------------------------------------------------
  // Create a Copilot operator
  //------------------------------------------------------------------------------

  static CATCVMGeoCopilot2 * Create(CATCVMGeoContainer *iCVMGeoContainer,
                                    CATTopData         *iTopData);



  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
protected:
  CATCVMGeoCopilot2(CATCVMGeoContainer   *iCVMGeoContainer,
                    CATTopData           *iTopData,
                    CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoCopilot2(CATTopData           *iTopData,
                    CATCVMGeoOperatorExt *iExtensible);
  
public:

  virtual ~CATCVMGeoCopilot2();

  /**
  * Remove all internal data except : domain, reference directions & planes, alignment directions 
  */
  virtual void Reset();

  /**
  * Do not optimize magnets according to the length of geometries on the screen 
  */
  virtual void SetNoScreenLengthOptimization();

  /**
  * To launch intersection after a first interruption
  */
  virtual void SetIntersectionPostInterrupt(CATBoolean SetIntersect = TRUE);

  /**
  * Magnets are not deleted by the Copilot operator and can be used after its destruction
  * (the user is in charge of deleting all magnets after use)
  * In this mode, magnets do not contain reference geometry information
  */
  virtual void SetExternalMagnetManagement();

  /**
  * Set magnet computation mode (default value is CATCVMComputationMode_Standard)
  */
  virtual void SetMagnetComputationMode(CATCVMComputationMode iMode);

  /**
  * iPoint: Previous point (needed snapping on direction). If null, cancel previous call to this method
  */
  virtual void SetPreviousPoint(CATMathPoint * iPoint);


  /**
  * iPoint: Previous point (needed snapping on direction). If null, cancel previous call to this method
  */
  virtual void SetRefPoint(CATMathPoint * iPoint);

  /**
  * Define the arc creation mode
  * if the size of the input lists is 1, it means that one extremity is set (step 1)
  * if the size of the input lists is 2, it means that the 2 extremities are set (step 2)
  * if the size of the input lists is 0, cancel the arc creation mode
  * iListPoint : list of 3D points representing the extremities
  * iListSupportGeometry : list of corresponding support geometry (face, edge, vertex or NULL if there is no support)
  */
  virtual void SetArcExtremities(CATLISTV(CATMathPoint) & iListPoint, ListPOfCATCVMGeometry & iListSupportGeometry);


  /**
  * Define the rectangle mode
  * iRectangleMode : TRUE rectangle mode is active
  *                  FALSE rectangle mode is unactive
  */  
  virtual void SetRectangleMode(CATBoolean iRectangleMode = TRUE);

  /**
  * iPlane: plane in which all magnets are restricted. If null, cancel previous call to this method
  */
  virtual void SetRestrictingPlane(CATMathPlane * iPlane);

  /**
  * iDistance: distance from previous point. If below resolution, null or negative, cancel previous call to this method
  */
  virtual void SetRestrictingDistance(double iDistance);
  
  /**
  * iDirection: direction of extrude (to be used only in extrude context). If null, cancel previous call to this method
  */
  virtual void SetExtrudeDirection(CATMathDirection * iDirection);

  /**
  * iDomain: 8 points defining a truncated pyramid
  * - only the cells within this domain are taken into account for snapping
  * - resulting magnets are restricted within this box
  * iViewPoint: view point (top of the vizualisation pyramid)
  * iTargetPoint: center point of the vizualisation sphere
  */
  virtual void SetDomain(CATLISTV(CATMathPoint) * iDomain, CATMathPoint * iViewPoint = 0, CATMathPoint * iTargetPoint = 0);

  /**
  * iListDirection: List of reference directions for snapping
  * (CATCVMSnapType_ReferenceDirection)
  */
  virtual void SetReferenceDirections(CATLISTP(CATMathDirection) & iListDirection);

  /**
  * iListPlane: List of reference planes for snapping
  * (CATCVMSnapType_ReferencePlanePoint)
  */
  virtual void SetReferencePlanes(CATLISTP(CATMathPlane) & iListPlane);

  /**
  * iListDirection: List of reference directions for snapping on aligned geometries :
  *  CATCVMSnapType_AlignedVertexPoint
  *  CATCVMSnapType_AlignedMiddlePoint
  *  CATCVMSnapType_AlignedVertexOnDemandPoint
  *  CATCVMSnapType_AlignedMiddleOnDemandPoint
  *  CATCVMSnapType_AlignedCircleCenterPoint
  *  CATCVMSnapType_AlignedCircleCenterOnDemandPoint
  */
  virtual void SetAlignmentDirections(CATLISTP(CATMathDirection) & iListDirection);

  /**
  * iListDirection2D: List of reference directions for snapping in 2D
  * (CATCVMSnapType_ReferenceDirection)
  * Used only if RestrictingPlane is set.
  */
  virtual void SetReferenceDirections2D(CATLISTP(CATMathDirection2D) & iListDirection2D);

  /**
  * iListDirection: List of reference directions for snapping on aligned geometries in 2D :
  *  CATCVMSnapType_AlignedVertexPoint
  *  CATCVMSnapType_AlignedMiddlePoint
  *  CATCVMSnapType_AlignedVertexOnDemandPoint
  *  CATCVMSnapType_AlignedMiddleOnDemandPoint
  *  CATCVMSnapType_AlignedCircleCenterPoint
  *  CATCVMSnapType_AlignedCircleCenterOnDemandPoint
  * Used only if RestrictingPlane is set.
  */
  virtual void SetAlignmentDirections2D(CATLISTP(CATMathDirection2D) & iListDirection);

  /**
  * iFace: face support to compute UV magnets. If null, cancel the UV magnets computation mode.
  */
  virtual void SetComputeUVMagnetsOnFace(CATCVMGeometry * iFace);

  /**
  * iListDirectionUV: List of reference directions for UV snapping :
  * CATCVMSnapType_ReferenceDirectionUV
  * Used only if SetComputeUVMagnetsOnFace mode is set.
  */
  virtual void SetReferenceDirectionsUV(CATLISTP(CATMathDirection2D) & iListDirectionUV);

  /**
  * iListDirectionUV: List of reference directions for UV snapping on aligned geometries :
  *  CATCVMSnapType_AlignedVertexPointUV
  *  CATCVMSnapType_AlignedMiddlePointUV
  *  CATCVMSnapType_AlignedVertexOnDemandPointUV
  *  CATCVMSnapType_AlignedMiddleOnDemandPointUV
  * Used only if SetComputeUVMagnetsOnFace mode is set.
  */
  virtual void SetAlignmentDirectionsUV(CATLISTP(CATMathDirection2D) & iListDirectionUV);

  /**
  * Add candidates for a type of snapping
  * iSnapType: all types of snapping except CATCVMSnapType_ReferenceDirection and CATCVMSnapType_ReferencePlanePoint
  * iListGeometry: candidate geometries
  */
  virtual void AddMagnetGeometricCandidates(CATCVMSnapType iSnapType, ListPOfCATCVMGeometry & iListGeometry);

  /**
  * Remove candidates for a type of snapping
  * iSnapType: all types of snapping except CATCVMSnapType_ReferenceDirection and CATCVMSnapType_ReferencePlanePoint
  * iListGeometry: candidate geometries
  */
  virtual void RemoveMagnetGeometricCandidates(CATCVMSnapType iSnapType, ListPOfCATCVMGeometry & iListGeometry);

  /**
  * Add candidates for a type of snapping
  * iSnapType: all types of snapping except CATCVMSnapType_ReferenceDirection and CATCVMSnapType_ReferencePlanePoint
  * iListGeoMesh: candidate meshes
  * iListInstancePath: instance path of candidate meshes
  */
  virtual void AddMagnetGeometricCandidates(CATCVMSnapType iSnapType, ListPOfCATCVMGeoMesh & iListGeoMesh);

  /**
  * Remove candidates for a type of snapping
  * iSnapType: all types of snapping except CATCVMSnapType_ReferenceDirection and CATCVMSnapType_ReferencePlanePoint
  * iListGeoMesh: candidate meshes
  * iListInstancePath: instance path of candidate meshes
  */
  virtual void RemoveMagnetGeometricCandidates(CATCVMSnapType iSnapType, ListPOfCATCVMGeoMesh & iListGeoMesh);

  /**
  * Remove all candidates for a type of snapping
  * iSnapType: all types of snapping except CATCVMSnapType_ReferenceDirection and CATCVMSnapType_ReferencePlanePoint
  */
  virtual void RemoveMagnetGeometricCandidates(CATCVMSnapType iSnapType);

  /**
  * iListGeometry: candidate edges to add
  */
  virtual void AddAlignmentEdges(ListPOfCATCVMGeometry & iListEdge);

  /**
  * iListGeometry: candidate edges to remove
  */
  virtual void RemoveAlignmentEdges(ListPOfCATCVMGeometry & iListEdge);

  /**
  * oListMagnet: list of the new magnets to add
  */
  virtual void GetMagnetListToAdd(ListPOfCATCVMGeoCopilot2Magnet & oListMagnet);

  /**
  * oListMagnet: list of the existing magnets to remove
  */
  virtual void GetMagnetListToRemove(ListPOfCATCVMGeoCopilot2Magnet & oListMagnet);

  /**
  * oListMagnet: list of the existing magnets that have been modified
  */
  virtual void GetMagnetListToModify(ListPOfCATCVMGeoCopilot2Magnet & oListMagnet);

  /**
  * compute a list of candidate cells (iMaxNumberOfCandidates items max) :
  * 1. geometry inside domain (only the first iMaxNumberOfCellsToCheck are checked)
  * 2. keep the closest geometries to the viewpoint
  * if iMaxNumberOfCandidates = 0, it means that no limit is used (the same with iMaxNumberOfCellsToCheck)
  * oListEdgeForMiddlePoint (optional) : linear edges whose middle is inside domain
  * oListEdgeForCenterPoint (optional) : circular edges whose center is inside domain
  */
  virtual void ComputeCandidateCells( ListPOfCATCVMBody & iListBody,
                                      int iMaxNumberOfCandidates,
                                      int iMaxNumberOfCellsToCheck,
                                      ListPOfCATCVMGeometry & oListVertex,
                                      ListPOfCATCVMGeometry & oListEdge,
                                      ListPOfCATCVMGeometry & oListFace,
                                      ListPOfCATCVMGeometry * oListEdgeForMiddlePoint = 0,
                                      ListPOfCATCVMGeometry * oListEdgeForCenterPoint = 0,
                                      ListPOfCATCVMGeometry * oListCircle = 0);




  /**
  * retreive the CPU time (in miliseconds) of the previous calls to ComputeCandidateCells + RunOperator
  */
	virtual CATULONG32 GetTiming();



#ifdef  ActivateCVMInstancePath
public :
  static CATCVMGeoCopilot2 * Create(CATCVMInstancePath *iCVMInstancePath,
                                    CATTopData         *iTopData);
                                      
  static CATCVMGeoCopilot2 * Create(CATTopData         *iTopData);
  /**
  * Define the arc creation mode
  * if the size of the input lists is 1, it means that one extremity is set (step 1)
  * if the size of the input lists is 2, it means that the 2 extremities are set (step 2)
  * if the size of the input lists is 0, cancel the arc creation mode
  * iListPoint : list of 3D points representing the extremities
  * iListSupportGeometry : list of corresponding support geometry (face, edge, vertex or NULL if there is no support)
  * iListInstancePath : instance path of support geometries
  */
  virtual void SetArcExtremities(CATLISTV(CATMathPoint) & iListPoint, ListPOfCATCVMGeometry & iListSupportGeometry, ListPOfCATCVMInstancePath & iListInstancePath);

  /**
  * iFace: face support to compute UV magnets. If null, cancel the UV magnets computation mode.
  * iInstancePath : instance path of the face support
  */
  virtual void SetComputeUVMagnetsOnFace(CATCVMGeometry * iFace, CATCVMInstancePath * iInstancePath);

  /**
  * Add candidates for a type of snapping
  * iSnapType: all types of snapping except CATCVMSnapType_ReferenceDirection and CATCVMSnapType_ReferencePlanePoint
  * iListGeometry: candidate geometries
  * iListInstancePath: instance path of candidate geometries
  */
  virtual void AddMagnetGeometricCandidates(CATCVMSnapType iSnapType, ListPOfCATCVMGeometry & iListGeometry, ListPOfCATCVMInstancePath & iListInstancePath);

  /**
  * Add candidates for a type of snapping
  * iSnapType: all types of snapping except CATCVMSnapType_ReferenceDirection and CATCVMSnapType_ReferencePlanePoint
  * iListGeoMesh: candidate meshes
  * iListInstancePath: instance path of candidate meshes
  */
  virtual void AddMagnetGeometricCandidates(CATCVMSnapType iSnapType, ListPOfCATCVMGeoMesh & iListGeoMesh, ListPOfCATCVMInstancePath & iListInstancePath);

  /**
  * Remove candidates for a type of snapping
  * iSnapType: all types of snapping except CATCVMSnapType_ReferenceDirection and CATCVMSnapType_ReferencePlanePoint
  * iListGeometry: candidate geometries
  * iListInstancePath: instance path of candidate geometries
  */
  virtual void RemoveMagnetGeometricCandidates(CATCVMSnapType iSnapType, ListPOfCATCVMGeometry & iListGeometry, ListPOfCATCVMInstancePath & iListInstancePath);

  /**
  * Remove candidates for a type of snapping
  * iSnapType: all types of snapping except CATCVMSnapType_ReferenceDirection and CATCVMSnapType_ReferencePlanePoint
  * iListGeoMesh: candidate meshes
  * iListInstancePath: instance path of candidate meshes
  */
  virtual void RemoveMagnetGeometricCandidates(CATCVMSnapType iSnapType, ListPOfCATCVMGeoMesh & iListGeoMesh, ListPOfCATCVMInstancePath & iListInstancePath);

   /**
  * iListGeometry: candidate edges to add
  * iListInstancePath: instance path of candidate edges to add
  */
  virtual void AddAlignmentEdges(ListPOfCATCVMGeometry & iListEdge, ListPOfCATCVMInstancePath & iListInstancePath);

  /**
  * iListGeometry: candidate edges to remove
  * iListInstancePath: instance path of candidate edges to remove
  */
  virtual void RemoveAlignmentEdges(ListPOfCATCVMGeometry & iListEdge, ListPOfCATCVMInstancePath & iListInstancePath);

    /**
  * This method was implemented for the 3DVIAShape needs (CATCVMInstancePath)
  * compute a list of candidate cells (iMaxNumberOfCandidates items max) :
  * 1. geometry inside domain (only the first iMaxNumberOfCellsToCheck are checked)
  * 2. keep the closest geometries to the viewpoint
  * if iMaxNumberOfCandidates = 0, it means that no limit is used (the same with iMaxNumberOfCellsToCheck)
  * oListEdgeForMiddlePoint, oListEdgeForMiddlePointIP (optional) : linear edges whose middle is inside domain
  * oListEdgeForCenterPoint, oListEdgeForCenterPointIP (optional) : circular edges whose center is inside domain
  */
  virtual void ComputeCandidateCells( CATCVMInstancePath * iInstancePath,
                                      int iMaxNumberOfCandidates,
                                      int iMaxNumberOfCellsToCheck,
                                      ListPOfCATCVMGeometry & oListVertex,
                                      ListPOfCATCVMInstancePath & oListVertexIP,
                                      ListPOfCATCVMGeometry & oListEdge,
                                      ListPOfCATCVMInstancePath & oListEdgeIP,
                                      ListPOfCATCVMGeometry & oListFace,
                                      ListPOfCATCVMInstancePath & oListFaceIP,
                                      ListPOfCATCVMGeometry * oListEdgeForMiddlePoint = 0,
                                      ListPOfCATCVMInstancePath * oListEdgeForMiddlePointIP = 0,
                                      ListPOfCATCVMGeometry * oListEdgeForCenterPoint = 0,
                                      ListPOfCATCVMInstancePath * oListEdgeForCenterPointIP = 0,
                                      ListPOfCATCVMGeoMesh * oListGeoMesh = 0,
                                      ListPOfCATCVMInstancePath * oListGeoMeshIP = 0,
                                      ListPOfCATCVMBody * iListExcludedBody = 0);

#endif
  
};
#endif
