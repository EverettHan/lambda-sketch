#ifndef CATGMLiveStepFilletManager_H
#define CATGMLiveStepFilletManager_H

#include "AdvOpeInfra.h"
#include "ListPOfCATDeclarativeManifold.h"
#include "ListPOfCATContextualManifold.h"
#include "ListPOfCATStepFilletZones.h"
#include "ListPOfListPOfCATEdge.h"
#include "ListPOfCATBoneFillet.h"
#include "ListPOfCATJointFillet.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATEdgeCurve.h"

#include "CATGMLiveStepFilletAttributeManager.h"
#include "CATGMLiveStepFilletEdgeAttr.h"
#include "CATZoneLimitingsPositionType.h"
#include "IUnknown.h"

class CATGeoFactory;
class CATLiveBody;
class CATSoftwareConfiguration;

class CATBoneFillet;
class CATJointFillet;
class CATBody;
class CATEdge;
class CATVertex;
class CATPlane;
class CATCellManifold;
class CATSurParam;


class ExportedByAdvOpeInfra CATGMLiveStepFilletManager
{
public:
  CATGMLiveStepFilletManager(CATGeoFactory            &iFactory,
                             CATSoftwareConfiguration &iConfig,
                             CATLiveBody              &iLiveBody);

  virtual ~CATGMLiveStepFilletManager();

  HRESULT ComputeZones(ListPOfCATDeclarativeManifold &iFilletsToRemove,
                       ListPOfCATFace                &iFacesToRemove,
                       ListPOfCATStepFilletZones     &oStepFilletZones,
                       ListPOfCATFace                 &oFacesToKeep);

  CATBoolean CanRelimitingEdgeBeAKeepEdge(CATDeclarativeManifold &iFilletManifold, 
                                          CATBody                &iFilletedBody, 
                                          CATEdge                &iG0Edge);

  void SetNetworkedTritangentDetection(CATBoolean iDefeatureMode, CATBoolean iTritangentPresent, CATBoolean iBossRemoval);

private:

  int GetTrackWiresRelativeOrientation(ListPOfCATDeclarativeManifold &iRibbonDeclarativeManifolds, 
                                       CATBody                       &iFilletedBody,
                                       ListPOfCATEdge                 iTrackEdges[2],
                                       CATListOfInt                   iOrientations[2]);

  CATBoolean IsFilletPointed(CATDeclarativeManifold   &iFilletManifold, 
                             ListPOfCATEdge           &iOrderedExtremityTrackEdges,
                             CATBody                  &iFilletedBody,
                             CATVertex                *&oPointVertex1, 
                             CATVertex                *&oPointVertex2,
                             ListPOfCATBoneFillet     *iDMsToRemove=NULL); 

  HRESULT GetG0Edges(CATDeclarativeManifold        &iFilletManifold,
                     ListPOfCATDeclarativeManifold &iRibbonDeclarativeManifolds,
                     ListPOfCATEdge                &iOrderedExtremityTrackEdges,
                     CATBoolean                     iBothDir,
                     CATBody                       &iFilletedBody,
                     int                            iNumberOfPointedExtremities,
                     ListPOfCATEdge                 oG0Edges[2],
                     ListPOfCATFace                *iFacesToRemove=NULL);

  HRESULT GetRibbonOrderedEdges(ListPOfCATDeclarativeManifold &iRibbonDeclativeManifolds,
                                ListPOfCATFace                &iFacesToRemove,
                                ListPOfCATEdge                &iBordersOfAllFacesToRemove,
                                ListPOfCATBoneFillet          &iAllBoneFilletsToTreat,
                                ListPOfCATJointFillet         &iAllJointFilletsToTreat,
                                ListPOfCATEdge                 oTrackEdges[2],
                                CATListOfInt                   oOrientations[2],
                                CATListOfInt                   oContinuityTypes[2]);

  HRESULT GetOppositeZoneEdges(CATEdge         *iPrevZoneEdge,
                               int             &iIntersectedSupport,
                               int             &iIntersectedEdgeIndex,
                               ListPOfCATEdge   iTrackEdges[2],
                               ListPOfCATEdge  &oOppositeZoneEdges);

  void SetStepEdgeType(CATEdge &iEdge, CATGMLiveStepFilletEdgeAttr::Type iType);

  CATBoolean GetStepEdgeType(CATEdge &iEdge, CATGMLiveStepFilletEdgeAttr::Type *oType=NULL);

  HRESULT ComputeAndSetBorderEdgesType(ListPOfCATDeclarativeManifold &iRibbonDeclarativeManifolds,
                                       ListPOfCATFace                &iFacesToRemove,
                                       ListPOfCATEdge                &iBorderEdges);

  HRESULT ComputeFilletEdgesType(CATDeclarativeManifold &iFilletDeclMan,
                                 ListPOfCATFace         &iFacesToRemove,
                                 ListPOfCATEdge         &oG1Edges,
                                 ListPOfCATEdge         &oG2Edges,
                                 ListPOfCATEdge         &oRelimitingEdges);

  HRESULT ComputeZonesForOneRibbonToRemove(ListPOfCATDeclarativeManifold &iFilletsToRemove,
                                           ListPOfCATFace                &iFacesToRemove,
                                           ListPOfCATEdge                &iBordersOfAllFacesToRemove,
                                           ListPOfCATBoneFillet          &iAllBoneFilletsToTreat,
                                           ListPOfCATJointFillet         &iAllJointFilletsToTreat,
                                           ListPOfCATStepFilletZones     &oStepFilletZones,
                                           ListPOfCATFace                 &oFacesToKeep);

  void PropagateBoneToRemove(CATBoneFillet                 &iBoneToPropagate,
                             ListPOfCATBoneFillet          &iAllBonesToRemove, 
                             ListPOfCATJointFillet         &iJointsToRemove,
                             ListPOfCATDeclarativeManifold &oPropagatedDeclMan);

  CATBoolean IsWireIntersected(ListPOfCATEdge &iWireEdges,
                               CATListOfInt   &iOrientations, 
                               CATBody        &iLimitingBody, 
                               int            &oIntersectedEdgeIndex, 
                               int            &oNextEdgeIndex);

  HRESULT GetStepFilletZones(ListPOfCATFace            &iBoneFilletFaces,
                             double                    &iRadius,
                             CATBody                   &iFilletedBody,
                             ListPOfCATJointFillet     &iAllJointFilletsToTreat,
                             ListPOfCATEdge             iTrackEdges[2],
                             CATListOfInt               iOrientations[2],
                             CATListOfInt               iContinuityTypes[2],
                             ListPOfCATStepFilletZones &oZones,
                             ListPOfCATFace            &oFacesToKeep);

  HRESULT CreateAlternatedRibZones(ListPOfCATFace            &iBoneFilletFaces,
                                   double                    &iRadius,
                                   CATBody                   &iFilletedBody,
                                   ListPOfCATJointFillet     &iAllJointFilletsToTreat,
                                   ListPOfCATEdge             ioTrackEdges[2],
                                   CATListOfInt               ioOrientations[2],
                                   CATListOfInt               ioContinuityTypes[2],
                                   CATBoolean                 iRibClosure,
                                   ListPOfCATStepFilletZones &oZones);

  CATBody * CreateLimitingBody(CATEdge        &iExtremityEdge, 
                               CATVertex      &iExtremityVertex,
                               CATBody        &iFilletedBody,
                               ListPOfCATFace &iBoneFaces,
                               double          iRadius,
                               CATPlane       *&oLimitingPlane,
                               CATBoolean      iInsideEdge,
                               CATBoolean      iNoFreeze=FALSE,
                               double          iLEPositionRatio=0.);

  // Creates Limiting when propagation is judged sufficient for RemoveFace (G2G2 zone)
  CATBody * CreatePropagationLimitingBody(CATEdge               *iRootEdge,
                                          CATVertex             *iExtremityVertex,
                                          CATBody               &iFilletedBody, 
                                          ListPOfCATFace        &iBoneFilletFaces, 
                                          ListPOfCATJointFillet &iAllJointFilletsToTreat,
                                          double                 iRadius,
                                          CATBoolean             &oProbableLimiting,
                                          CATStepFilletZone     & iZone);

  // Check if we truely need to define G1G2 zones leading to Limitings creation
  void CheckTrueG1G2EdgesContinuityTypes(ListPOfCATDeclarativeManifold &iRibbonDeclarativeManifolds,
                                         ListPOfCATFace                &iBoneFilletFaces,
                                         ListPOfCATEdge                 iTrackEdges[2],
                                         CATListOfInt                   ioContinuityTypes[2]);

  // Retrieve all created propagation limiting bodies (Shift Limitings Project)
  void GetPropagLimitingBodies(ListPOfCATBody &oPropagLimitingBodies);

  void BuildLimitingBodyData(CATFace                      *iAdjacentBoneFace, 
                             CATEdge                      &iExtremityEdge,
                             CATVertex                    &iExtremityVertex,
                             double                       &ioRadius,
                             CATBoolean                   &iIsInsideEdge,
                             CATEdgeCurve                 *oTrackEdgeCurve,
                             CATCrvParam                  &oParamOnEdgeCurve,
                             CATMathPoint                 &oCenter,
                             CATMathVector                &oSectionNormal,
                             CATZoneLimitingsPositionType  iLimitingPosition=DEFAULT,
                             double                        iLEPositionRation=0.);

  CATBoolean CheckIfTwoUntwistedFacesConnectedByParabolicEdge(CATEdge& iExtremityEdge,
                                                              CATFace* iCurFace,
                                                              CATEdgeCurve* iCurTrackEdgeCurve,
                                                              CATCrvParam& iCurParamOnEdgeCurve,
                                                              CATVertex* iExtremityVertex,
                                                              CATSurface* &oConnectedSurface,
                                                              CATSurParam oSurParam[2]);

  CATBoolean IsWireCrossingBone(CATBoneFillet  &iBone,
                                CATEdge        &iEdge, 
                                ListPOfCATEdge &iGroupOfEdges,
                                ListPOfCATEdge &iAllRelimEdges,
                                CATBody        &iFilletedBody, 
                                ListPOfCATEdge &oWireEdges);

  CATBoolean IsMicroTakeDownEdge(CATEdge &iEdge, ListPOfCATEdge &iRelimitingEdges, CATBody &iFilletedBody);

  CATBoolean CheckIfLastZoneEdgeCanBeAdded(int iSupNb,
                                           ListPOfCATEdge iTrackEdges[2],
                                           CATListOfInt iContinuityTypes[2],
                                           CATListOfInt iOrientations[2],
                                           ListPOfCATFace &iBoneFilletFaces,
                                           ListPOfCATEdge ioCurrentZoneEdges[2]);

  void DeleteLastG1G2ZoneIfInvalidForRemoval(ListPOfCATStepFilletZones & ioZones, CATBoolean iProbableLimiting);

  void FindFacesCompletelyOnOtherSideOfLimiting(CATEdge * iRootEdge, 
                                                ListPOfCATEdge & iStartZoneTrackEdges,
                                                CATBody        & iFilletedBody,
                                                ListPOfCATFace & iBoneFilletFaces,
                                                ListPOfCATJointFillet &iAllJointFilletsToTreat,
                                                CATBoolean     iStartSide,
                                                ListPOfCATFace &ofacesToKeep);

  CATBoolean UselessG1EdgeForRemovalFace(CATBoneFillet * iBoneFillet, CATEdge * iCommonEdge);

  void CheckIfSupFaceIsPairedAndCommonEdgesCrossingSupBone(ListPOfCATEdge &iCommonEdges,
                                                           ListPOfCATFace &iSupportFaces,
                                                           ListPOfCATEdge &iRepBorderEdges,
                                                           CATBoneFillet * iSupportBone,
                                                           CATBoneFillet * iBoneFillet,
                                                           CATCellManifold * iConnectedCellManifold,
                                                           ListPOfCATFace &iFacesToRemove,
                                                           CATListOfInt &oFaceIsPairedAndEdgeCrossingSupBone);

 CATBoolean AreRelimitingEdgesValid(CATBody & iFilletedBody,
                                    ListPOfCATEdge & iRelimitingEdges,
                                    ListPOfCATEdge * iTrackEdges,
                                    ListPOfCATEdge & iOrderedExtremityTrackEdges);

  CATBoolean AreEdgesCrossingChangingConvexityBones(ListPOfCATEdge & iConnexGroup,
                                                    CATBoneFillet * iSupportBone,
                                                    CATBoneFillet * iBoneFillet,
                                                    CATCellManifold * iConnectedCellManifold);

  void RemoveTracksFromZoneForFacesToKeep(CATStepFilletZone * ioZone, ListPOfCATFace & iFacesToKeep);

  CATBoolean PairedBoneOnOneSideAndUnpairedBoneOnOtherSide(CATBoneFillet* iBoneFillet,
                                                           CATCellManifold* iConnectedCellManifold,
                                                           CATFace* iCurFilletFace);

  CATBoolean allSupportsAreBoneFillets(CATBoneFillet* iBoneFillet);

  private:
  CATGeoFactory                      &_Factory;
  CATSoftwareConfiguration           &_Config;
  CATLiveBody                        &_LiveBody;
  ListPOfCATBody                      _PropagationLimitingBodies;
  CATGMLiveStepFilletAttributeManager _AttributeManager;
  CATBoolean _networkedTritangentIsPresent, _DefeatureMode, _BossRemoval;
};


#endif
