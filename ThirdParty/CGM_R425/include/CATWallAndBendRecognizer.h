#ifndef CATWallAndBendRecognizer_H
#define CATWallAndBendRecognizer_H

#include "CATGroupRecognizerBase.h"
#include "AdvOpeInfra.h"

#include "CATWbrData.h"
#include "ListPOfCATWbrData.h"
#include "ListPOfCATCell.h"
#include "ListPOfListPOfCATCell.h"
//RL1
#include "CATCellManifoldBendNavigator.h"

class ExportedByAdvOpeInfra CATWallAndBendRecognizer : public CATGroupRecognizerBase
{
public:
  CATCGMDeclareManifoldAgent(CATWallAndBendRecognizer, CATDeclarativeManifoldAgent);

	// Constructor
  CATWallAndBendRecognizer();

  // Destructor
	virtual ~CATWallAndBendRecognizer();

  virtual int GetPriority();
  virtual CATDeclarativeManifoldAgent* Clone();
  virtual HRESULT CreateManifoldGroup();

	void SetReferenceFace(ListPOfCATFace RefFace);

	// -------------------------------------------------------------------------------------------------------------------------------------
	// CGMReplay
	// -------------------------------------------------------------------------------------------------------------------------------------
	virtual void Stream(CATCGMStream& Str) const;
	virtual void UnStream(CATCGMStream& Str, CATGeoFactory* iFactory, CATSoftwareConfiguration* ipConfig);

	virtual void Dump(CATCGMOutput &os);

protected:

private:
  HRESULT ComputePlanesAndCylinders();
	HRESULT ComputePlanesAndCylindersAndCones();
  HRESULT MergeSElements(ListPOfCATWbrSimpleElement &ioSElts, CATBoolean PlanarElt = FALSE);

  HRESULT ComputeWalls();

  // first element of ioAvailableElts is considered as init element
  // used elements of ioAvailableElts are set to NULL
  HRESULT PropagSElementIntoFElement(ListPOfCATWbrSimpleElement &ioAvailableSElts, ListPOfCATWbrSimpleElement oPropagatedSElt[2], double &oThickness, CATBoolean iWallAnalyzerCheck = FALSE);

  HRESULT ComputeOppositeFaces(ListPOfCATFace &iRep, ListPOfCATFace &iAllowedFaces, ListPOfCATFace &oOppositeFaces);
  CATBoolean AreFacing(ListPOfCATFace &iRep1, ListPOfCATFace &iRep2);
  CATBoolean AreFacing(CATFace &iFace1, CATFace &iFace2);
	void ComputeOppositeCandidates(CATWbrSimpleElement &iSElt, ListPOfCATWbrSimpleElement &iAvailableSElts, ListPOfCATWbrSimpleElement &oCandidatesElts);

  HRESULT ComputeBends();
  HRESULT CreateBendFromRep(ListPOfCATWbrCylinderData iPseudoBend[2], int &iFaceToWallIndexAttribute, CATWbrBendData *&oNewBend);
  HRESULT CreateBendFromConeRep(ListPOfCATWbrConeData iPseudoBend[2], int &iFaceToWallIndexAttribute, CATWbrBendData *&oNewBend);

	HRESULT CreateDRepForRecognizedBends(CATSoftwareConfiguration* ipConfig, CATLiveBody &iLiveBody, CATTopData *iTopData, ListPOfCATWbrBendData & iRecognizedBends, CATCellManifoldBendNavigator::CATBendType iBendType);
	HRESULT MergeBendsBasedOnLateralFaces(ListPOfCATWbrBendData & ioBendsToMerge, int &iFaceToWallIndexAttribute);
	HRESULT MergeBendsSharingWallFaces(ListPOfCATWbrBendData & ioBendsToMerge, int &iFaceToWallIndexAttribute);
	HRESULT FilterBendsBasedOnLateralFaces(ListPOfCATWbrBendData & ioBendsToMerge);
	HRESULT PropagateFromInvalidBend(CATWbrBendData &iBend, ListPOfCATWbrBendData & iAvailableBends, ListPOfCATWbrBendData &oBendsToDelete);
	HRESULT IsConnectedToBend(CATBody &iBody, CATWbrBendData &iBend, ListPOfCATWbrBendData & iCandidateBends, ListPOfCATWbrBendData &oConnectedBends);
  
  HRESULT MergeBendsBasedOnLateralFaces(int &iFaceToWallIndexAttribute);
  HRESULT MergeBendsSharingWallFaces(int &iFaceToWallIndexAttribute);
  HRESULT FilterBendsBasedOnLateralFaces();
	HRESULT PropagateFromInvalidBend(CATWbrBendData &iBend, ListPOfCATWbrBendData &oBendsToDelete);//RL1
	HRESULT IsConnectedToBend(CATBody &iBody, CATWbrBendData &iBend, ListPOfCATWbrBendData &oConnectedBends);//RL1
	HRESULT IsConnectedToRevol(CATWbrBendData &iBend);//RL1

  HRESULT FindConnectedWalls(ListPOfCATWbrCylinderData iPseudoBend[2], int &iFaceToWallIndexAttribute, ListPOfCATWbrWallData oConnectedWalls[2], CATListOfInt oIsReversedForEachWall[2]);
	HRESULT FindConnectedWallsFromCone(ListPOfCATWbrConeData iPseudoBend[2], int &iFaceToWallIndexAttribute, ListPOfCATWbrWallData oConnectedWalls[2], CATListOfInt oIsReversedForEachWall[2]);
  HRESULT ComputeBendLateralFaces(CATWbrBendData &iBend, ListPOfCATFace &oMinLateralFaces, ListPOfCATFace &oMaxLateralFaces);
  HRESULT ComputeBendExtremityWires(CATWbrBendData &iBend, ListPOfCATEdge oMinParamWire[2], ListPOfCATEdge oMaxParamWire[2]);

  HRESULT GetFacesMinMaxParam(CATMathLine &iAxis, ListPOfCATFace &iFaces, double &oMinParam, double &oMaxParam);
  HRESULT GetEdgesMinMaxParam(CATMathLine &iAxis, ListPOfCATEdge &iEdges, double &oMinParam, double &oMaxParam);
  HRESULT GetVerticesMinMaxParam(CATMathLine &iAxis, ListPOfCATVertex &iVertices, double &oMinParam, double &oMaxParam);

  HRESULT ComputeGroupsOfConfusedBendsWithConfusedWalls(ListPOfCATWbrBendData &iBends, ListPOfListPOfCATWbrBendData &oGroupedBends);
  HRESULT OrderBendsByParamOnAxis(ListPOfCATWbrBendData &iBends, CATMathLine &iAxis, ListPOfCATWbrBendData &oBends, CATListOfInt &oMinHasLaterals, CATListOfInt &oMaxHasLaterals);

  HRESULT CreateDRepForWalls();
  HRESULT CreateDRepForBends();

	//introducing Ref face
	void PropagateFromRefFace(CATSoftwareConfiguration* ipConfig, CATBody &iBody, ListPOfCATFace &iStartingFace, ListPOfCATFace &oPropagatedFaces);

  // utils
  void GetAsSimpleElements(ListPOfCATWbrVirtualElement &iVElts, ListPOfCATWbrSimpleElement &oSElts);
  void GetAsPlanes(ListPOfCATWbrSimpleElement &iElts, ListPOfCATWbrPlaneData &oPlanes);
  void GetAsCylinders(ListPOfCATWbrSimpleElement &iElts, ListPOfCATWbrCylinderData &oCylinders);
	void GetAsCones(ListPOfCATWbrSimpleElement &iElts, ListPOfCATWbrConeData &oCones);


  // attribute management
  void CleanAttributes(const int iAttKey = 0, ListPOfCATCell *iCellsToClean = NULL); // 0 for all attribute keys
  void CleanAttributes(const int iAttKey, ListPOfCATFace &iFacesToClean);

  void AssignFaceToIntAttribute(const int iAttKey, CATFace* iFace, int iAssociatedInt);
  void AssignFaceToIntAttribute(const int iAttKey, ListPOfCATFace iFaces, int iAssociatedInt);
  int* GetIntFromFace(const int iAttKey, CATFace* iFace);

  // debug
  void CreateExtractBody(ListPOfCATCell &iCells, int iR, int iG, int iB, CATUnicodeString iBodyName, int iNum = -1);
  void CreateExtractBody(ListPOfCATFace &iFaces, int iR, int iG, int iB, CATUnicodeString iBodyName, int iNum = -1);

  //-------------------------------------------------------------------------
  // Data
  //-------------------------------------------------------------------------
  ListPOfCATWbrPlaneData _Planes;
  ListPOfCATWbrCylinderData _Cylinders;
	ListPOfCATWbrConeData _Cones;
  ListPOfCATWbrWallData _Walls;
  ListPOfCATWbrBendData _Bends;
	ListPOfCATWbrBendData _CylindricalBends;
	ListPOfCATWbrBendData _ConicalBends;

  // GTA results
  double _MaxThickness;
  ListPOfCATFace _LateralFaces;

  // attribute management
  CATListOfInt _AttKeys;
  ListPOfListPOfCATCell _FacesWithAtt;

	// candidate bends in stamps
	ListPOfCATWbrBendData _InvalidBends;

	// reference face
	// ListPOfCATFace _RefFace; RefFaceList now in base clash 
	ListPOfCATFace _PropagatedFaces;
};

#endif
