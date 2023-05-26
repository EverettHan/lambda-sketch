// --------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011 
//==========================================================================
//
//    CATSurfacicTopoTools       
//
//==========================================================================
// Aug 2011 KTU : Creation 
//==========================================================================

#ifndef CATSurfacicTopoTools_h
#define CATSurfacicTopoTools_h
#include "CATSurfacicTopoOperators.h"

#include "CATTopDefine.h"
#include "ListPOfCATCell.h"
#include "CATBoolean.h"
#include "CATListOfCATGeometries.h"
#include "CATCGMJournal.h"
#include "CATListOfCATCGMJournals.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATFace.h"
#include "CATLISTV_CATMathPoint.h"
#include "ListPOfCATEdge.h"
#include "CATTessSettings.h"
#include "CATCrvParam.h"
#include "ListPOfCATVertex.h"
#include "CATDynTransformation.h"
#include "CATCloneManager.h"
#include "CATBodyFreezeMode.h"

class CATBody;
class CATICGMObject;
class CATCGMJournalList;
class CATEdge;
class CATSoftwareConfiguration;
class CATTopData;
class CATGeoFactory;
class CATFace;
class CATDomain;
class CATMathPoint;
class CATMath3x3Matrix;
class CATCurve;
class CATCrvLimits;
class CATPolyMeshDistance;
class CATSurface;
class CATSurLimits;
class CATEdgeCurve;
class CATPointOnEdgeCurve;
class CATPCurve;

class CATTessPolyMeshVertexAttributeLayer;
class CATTessPolyMeshVertexUV;
class CATIPolyMesh;
class CATIPolyFactory;
class CATWire;
class CATVertex;

class ExportedByCATSurfacicTopoOperators CATSurfacicTopoTools
{
public:
	// r
	//------------------------------------------------------------------------------------------------------------------------
	// CreateLocalTopDataWithJournal
	// Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	static int CreateLocalTopDataWithJournal(CATSoftwareConfiguration *ipConfig, CATTopData*& opLocalTopData, CATCGMJournalList*& opLocalJournal);
	//------------------------------------------------------------------------------------------------------------------------
	// DeleteLocalTopDataAndJournal
	// Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	static void DeleteLocalTopDataAndJournal(CATTopData*& opLocalTopData, CATCGMJournalList*& opLocalJournal);
	// r
	//------------------------------------------------------------------------------------------------------------------------
	// IsBoundEdge
	// Purpose : True if ipEdgeToCheck is a bound cell of ipAccordingToThisBody
	//------------------------------------------------------------------------------------------------------------------------
	static CATBoolean IsBoundEdge( CATEdge* ipEdgeToCheck, CATBody *ipAccordingToThisBody);

	//------------------------------------------------------------------------------------------------------------------------
	// GetAllCellsAsGeometry
	//------------------------------------------------------------------------------------------------------------------------
	static void ConvertlCellsTolGeometry( ListPOfCATCell &ilCells, CATLISTP(CATGeometry) &olGemetries );

	//------------------------------------------------------------------------------------------------------------------------
	// GetAllCellsAsGeometry
	//------------------------------------------------------------------------------------------------------------------------
	static void GetAllCellsAsGeometry( CATBody *ipBodyCells, const int iCellsDimension, CATLISTP(CATGeometry) &olGemetries );

	//------------------------------------------------------------------------------------------------------------------------
	// ForgetReportOfCells
	//------------------------------------------------------------------------------------------------------------------------
	static void ForgetReportOfCells( CATCGMJournalList *ipInThisReport, CATBody *ipBodyCellsToRepport, const int iCellsToReportDimension  );

	//------------------------------------------------------------------------------------------------------------------------
	// ReportDeletionOfCells
	//------------------------------------------------------------------------------------------------------------------------
	//void ReportDeletionOfCells( CATCGMJournalList *ipInThisReport, CATBody *ipBodyCellsToRepport, const int iCellsToReportDimension );

	//------------------------------------------------------------------------------------------------------------------------
	// RetrieveFirstObjets
	//------------------------------------------------------------------------------------------------------------------------
	static void RetrieveFirstObjets( CATLISTP(CATCGMJournal) & ilReports, CATCell *ipLastCell,  CATCGMJournal::Type iJournalTypeToUse, CATLISTP(CATGeometry) &olLastObj);

	//------------------------------------------------------------------------------------------------------------------------
	// RetrieveModifiedAncestor
	//------------------------------------------------------------------------------------------------------------------------
	static CATGeometry* RetrieveModifiedAncestor(CATCGMJournalList *plReports, CATGeometry *ipChild);

	//------------------------------------------------------------------------------------------------------------------------
	// RetrieveBoundingEdgesOnly
	// Retrieve from input lists the geometries that are bounding cells in  ipAccordingToThisBody
	//------------------------------------------------------------------------------------------------------------------------
	static void RetrieveBoundingEdgesOnly(CATLISTP(CATGeometry) &ilObjects, CATBody *ipAccordingToThisBody, CATLISTP(CATGeometry) &olBoundingObjects);

	//------------------------------------------------------------------------------------------------------------------------
	// GetBoundaries
	// Purpose : Retrieve the boundary of mono-domain shell. 
	//------------------------------------------------------------------------------------------------------------------------
	static int GetBoundary( CATGeoFactory *ipFactory, CATTopData* ipTopData, CATBody * ipMonoDomainBody, CATBody* &opBoundaryBody );
	//------------------------------------------------------------------------------------------------------------------------
	// IsClosed
	// Purpose : Return TRUE if the imput is a closed mono-shell. 
	//------------------------------------------------------------------------------------------------------------------------
	static CATBoolean IsClosed(CATBody * ipMonoShellBody );
	//------------------------------------------------------------------------------------------------------------------------
	// Function : RemoveBodies
	// Purpose : if ipTopData!= NULL and its Journal if exists, will be used for all. keep it on NULL if you have doubt
	//------------------------------------------------------------------------------------------------------------------------
	static void RemoveBodies( ListPOfCATBody &ilBodies, CATTopData *ipTopData=NULL  );
	//------------------------------------------------------------------------------------------------------------------------
	// Function : RemoveBody
	// Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	static void RemoveBody( CATBody*& iopBodyToRemove, CATTopData *ipTopData=NULL);
	//------------------------------------------------------------------------------------------------------------------------
	// Function : Extract one face 
	// Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	//static void ExtractFace(CATGeoFactory *pFactory, CATTopData *ipTopData, CATFace* ipFaceToExtract, CATBody*& opResultBody);
	//------------------------------------------------------------------------------------------------------------------------
	// Function : DoFacesBelongToThisDomain
	// Purpose : Returns TRUE if all faces belong to the domain
	//------------------------------------------------------------------------------------------------------------------------
	static CATBoolean DoFacesBelongToThisDomain(ListPOfCATFace &ilFaces, CATDomain *ipDomain);

	//------------------------------------------------------------------------------------------------------------------------
	// Function : AssembleBoi
	// Purpose : Returns 0 for success and non-zero on failure
	//------------------------------------------------------------------------------------------------------------------------
	static int AssembleBodies(CATGeoFactory *ipFactory, CATTopData* ipTopData, ListPOfCATBody & ilBodiesToAssemble, const double iAssembleTol, CATBody* &opResultBody 
		,const CATBoolean iKeepSmallEdges=FALSE, ListPOfCATCell *ipCellsToMerge=NULL ,CATBodyFreezeMode iFreezeMode=CATBodyFreezeOn);

	//------------------------------------------------------------------------------------------------------------------------
	// Function : AssembleWireBodies
	// Purpose : Returns 0 for success and non-zero on failure
	//------------------------------------------------------------------------------------------------------------------------
	static int AssembleWireBodies(CATGeoFactory *ipFactory, CATTopData* ipTopData, ListPOfCATBody & ilBodiesToAssemble, const double iAssembleTol, CATBody* &opResultBody);

  static CATBoolean HasPlanarSymetry(CATGeoFactory *ipFactory, CATSoftwareConfiguration *ipConfig, CATBody* iBody, CATMathPlane& iSymPlane);

  static CATBoolean IsBothSidePlane(CATGeoFactory *ipFactory, const CATBody *ipBody, CATMathPlane& iSymPlane);
  

	//---------------------------------------------------------------------------------------------
	// Function : 	ComputeMassProperties3D
	// Purpose :  only the non null out arguments will be filled.
	//---------------------------------------------------------------------------------------------
	static int ComputeMassProperties3D(CATBody *ipBody,  CATTopData * ipTopData
		,double * opLengthValue, double * opAreaValue, double * opVolumeValue
		,CATMathPoint* opGravityCenter, CATMath3x3Matrix*opInertiaMatrix);

	//---------------------------------------------------------------------------------------------
	// Function : 	ComputeEdgeLenght
	// Purpose : 
	//---------------------------------------------------------------------------------------------
	static int ComputeEdgeLenght(CATEdge *ipEdge,  CATTopData * ipTopData ,double &oLengthValue);

	//---------------------------------------------------------------------------------------------
	// Function : 	ComputeWireLenght
	// Purpose : 
	//---------------------------------------------------------------------------------------------
	static int ComputeWireLenght(CATGeoFactory *ipFactory, CATSoftwareConfiguration *ipConfig, CATWire *ipWire ,double &oLengthValue);

	//---------------------------------------------------------------------------------------------
	// Function : 	CreateTopWire
	// Purpose :  overload of 
	//---------------------------------------------------------------------------------------------
	static CATBody * CreateTopWire( CATGeoFactory *iFactory,  CATTopData *iData,  int iNbCurves,  CATCurve **iCurves,  CATCrvLimits *iLimits,  short *iOrientations);

	//---------------------------------------------------------------------------------------------
	// Function : 	GetG1ErrorsInEdge
	// Purpose :  from CATTopologicalFillBoundary 
	//---------------------------------------------------------------------------------------------
	static int GetDefaultsBetweenFaces (CATGeoFactory *iFactory, CATSoftwareConfiguration *ipConfig, CATEdge *ipEdge,CATFace * ipFace0,CATFace * ipFace1, double &oG0Error, double &oG1Error);
	//---------------------------------------------------------------------------------------------
	// Function : 	GetEdgeCurveDefaults
	// Purpose : 
	//---------------------------------------------------------------------------------------------
	static int GetEdgeCurveDefaults
		(
		CATGeoFactory *ipFactory,  CATSoftwareConfiguration *ipConfig
		, CATEdgeCurve *ipEdgeCurve, CATPointOnEdgeCurve * ipStartPOEC, CATPointOnEdgeCurve * ipEndPOEC										
		, CATFace * ipFace0, CATPCurve* ipPCurve0
		, CATFace * ipFace1, CATPCurve* ipPCurve1
		, double &oG0Error, double &oG1Error
		);

	//---------------------------------------------------------------------------------------------
	// Function : 	GetEdgeDefaults
	// Purpose : 
	//---------------------------------------------------------------------------------------------
	static int GetEdgeDefaults
		(
		CATGeoFactory *ipFactory,  CATSoftwareConfiguration *ipConfig
		, CATEdge* ipEdge, CATBody * ipInBody						
		, CATFace * ipRefFace, CATCrvParam otParamOnRefPcrv[2]
	, double &oG0Error, double &oG1Error
		);
	//---------------------------------------------------------------------------------------------
	// Function : 	CreateTopWireFromPCrv
	// Purpose : 
	//---------------------------------------------------------------------------------------------
	static CATBody * CreateTopWireFromPCrv (CATGeoFactory *iFactory,CATTopData *iData,CATEdge *ipEdge,CATFace * ipFace, const CATBoolean iInvertOrien=FALSE);

	//------------------------------------------------------------------------------------------------------------------------
	//Function: ComputeGlobalInnerDeviation()
	//Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	static int ComputeGlobalInnerDeviation(CATSoftwareConfiguration* ipSoftwareConfiguration, CATBody* ipInBody, CATBody* ipResBody, const double iSag, const int ilevel, CATListOfDouble &olDeviations , CATLISTV(CATMathPoint) &olDeviationPoints, double &oMaxDev );

	//------------------------------------------------------------------------------------------------------------------------
	//Function: GetOffsetValues()
	//Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	static int GetOffsetValues( CATGeoFactory *ipFactory, CATSoftwareConfiguration *ipConfig, CATSurface * ipSurface, const CATSurLimits * pSurLimits,  double &oPosValue, double &oNegValue  );

	//------------------------------------------------------------------------------------------------------------------------
	//Function: CreateMergeCurve()
	//Purpose : creates mergecurve by confusion
	//------------------------------------------------------------------------------------------------------------------------
	static int CreateMergeCurve( CATGeoFactory *ipFactory, CATSoftwareConfiguration *ipConfig
		,CATCurve * ipCrv1,const CATCrvLimits * ipCrvLim1
		,CATCurve * ipCrv2,const CATCrvLimits * ipCrvLim2
		,const double iMergingTol
		,CATEdgeCurve *& opMergeCurve
		,CATPointOnEdgeCurve* &opStartPOEC, CATPointOnEdgeCurve* &oEndPOEC  );

	//------------------------------------------------------------------------------------------------------------------------
	//Function: LocalCCK()
	//Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	static int LocalCCK(CATGeoFactory *ipFactory, CATSoftwareConfiguration *ipConfig
		,CATEdge * ipEdge1, CATFace* ipFace1
		,CATEdge * ipEdge2, CATFace* ipFace2
		,int &oNbPoints
		,CATCrvParam otParamOnPcrv1[2]
	,CATCrvParam otParamOnPcrv2[2]
	,double *& opGaps, CATMathPoint *&opGapPoints
		,double &oMaxGap, CATMathPoint& oMaxGapPoint
		,double *& opAngles, CATMathPoint *&opAnglePoints
		,double &oMaxangle, CATMathPoint& oMaxAnglePoint		
		);// option crv plutard


	//-----------------------------------------------------------------------------------------------------------------------
	// Function DeviationShellShell
	// Purpose:  computes CC like deviations  between boundaries of shells and DA (out-> In) 
	//           The out lists contain the points ans its values that are out of given tolerances 
	//           If all points are in the tolerance,  only the max points are pushed in the lists.
	//------------------------------------------------------------------------------------------------------------------------
	static int DeviationShellShell(CATGeoFactory *ipFactory, CATSoftwareConfiguration *ipConfig
		, CATBody *ipRefShellBody, CATBody *ipRefBody
		, CATBody *ipResShellBody, CATBody *ipResBody
		, const double iBoundTolG0, const double iBoundTolG1, const double iInnerTol
		, double  &oMaxBoundG0, double  &oMaxBoundG1,  double  &oMaxInner
		, CATListOfDouble &olBoundGaps , CATLISTV(CATMathPoint) &olBoundGapPoints
		, CATListOfDouble &olBoundAngles, CATLISTV(CATMathPoint) &olBoundAnglePoints
		, CATListOfDouble &olInnerDeviations , CATLISTV(CATMathPoint) &olInnerDeviationPoints
		, CATBoolean*  opContinuitiesAreBroken = NULL ,CATBoolean iStopIfBroken = FALSE
		);

	static int CCKShellShell(CATGeoFactory *ipFactory, CATSoftwareConfiguration *ipConfig
		, CATBody *ipShellBody0, CATBody *ipShellBody1
		, double &oMaxDefectG0, double &oMaxDefectG1
		, CATListOfDouble &olBoundGaps , CATLISTV(CATMathPoint) &olBoundGapPoints
		, CATListOfDouble &olBoundAngles, CATLISTV(CATMathPoint) &olBoundAnglePoints
		, const double iBoundTolG0=-1., const double iBoundTolG1=-1.
		);
	//-----------------------------------------------------------------------------------------------------------------------
	// Function:CreateEmpyPolyMesh..
	// Purpose : creates an empty cat polymesh 
	//          if the input is not null,  it will be deleted. So be carrefull.
	// can be transferred to tools file. very independant.
	//-----------------------------------------------------------------------------------------------------------------------
	static int CreateEmptyPolyMesh(CATIPolyFactory* ipPolyContainer, CATIPolyMesh *&oPolyMesh);

	//-----------------------------------------------------------------------------------------------------------------------
	// TesselateBody..
	//-----------------------------------------------------------------------------------------------------------------------
	static int TesselateBody(CATIPolyFactory* ipPolyContainer,  CATSoftwareConfiguration *ipConfig
		,CATBody *ipBodyToTesselate, const CATTessSettings & iTessSetting
		,CATIPolyMesh *&oPolyMesh , const CATLONG32 iVertexInfo=0, CATTessPolyMeshVertexAttributeLayer* opVertexAttributeLayer=NULL
		);

  //-----------------------------------------------------------------------------------------------------------------------
	// GetVertexNormal
	//-----------------------------------------------------------------------------------------------------------------------
  //static int GetVertexNormal( CATTessPolyMeshVertexUV * pVtxContext, CATOrientation iOrientationFaceBody , CATMathVector &oNormal, CATBoolean &oIsDegenerated );


	//-----------------------------------------------------------------------------------------------------------------------
	// FlagBoundVtx..
	//-----------------------------------------------------------------------------------------------------------------------
	static int FlagBoundVtx(CATIPolyMesh *ipPolyMesh , CATBoolean *&opIsBound, int & oNbBound);

	//-----------------------------------------------------------------------------------------------------------------------
	// Function : 	GetModelSize
	// Purpose : PLow.DistanceTo(PHigh) of BoundingBox
	//-----------------------------------------------------------------------------------------------------------------------
	static int GetModelSize(CATGeometry *ipGeometry, double &oSize );


	//-----------------------------------------------------------------------------------------------------------------------
	// Function : CompuInternalContinuitiesOf
	// Purpose : compute internal continuities of input sub shell according to the global body.
	////-----------------------------------------------------------------------------------------------------------------------
	//static int CompuInternalContinuityDefaultsOf(CATGeoFactory *ipFactory, CATSoftwareConfiguration *ipConfig
	//	,CATBody *ipSubShell, CATBody* ipGlobalBody, double &oG0MaxError, double &oG1MaxError );

	//-----------------------------------------------------------------------------------------------------------------------
	// Function : CompuInternalContinuitiesOf
	// Purpose : ipInputSubShell is a subpart of ipInputBody whose the result is ipResultBody 
	//           ipResultSubShell is the result of ipInputSubShell ans subpart of ipResultBody
	//           This method check if the continuities of ipResultSubShell according to ipResultBody is better than those 
	//           of ipInputSubShell according to ipInputBody
	//-----------------------------------------------------------------------------------------------------------------------
	static CATBoolean IsEdgeContBroken(CATGeoFactory *ipFactory, CATSoftwareConfiguration *ipConfig
		,CATEdge * ipRefEdge, CATFace * ipRefFace, CATCrvParam itParamOnRefPCrv[2], CATBody * ipRefBody
		,CATEdge * ipResEdge, CATFace * ipResFace, CATCrvParam itParamOnResPCrv[2], CATBody * ipResBody
		,const double iBoundTolG0, const double iBoundTolG1);

	static int GetAbsolutOffsetInfos(CATGeoFactory *ipFactory, CATSoftwareConfiguration *ipConfig,CATBody * ipBody
		,double &oMinOffsetValue,  int &oNumberOfFacesUnderV, double iTol);


	//-----------------------------------------------------------------------------------------------------------------------
	// Function : IsElementaryBody
	// Purpose : Return TRUE if the body is a shell and all faces in it have as support an elementary surface
	//-----------------------------------------------------------------------------------------------------------------------
	static CATBoolean IsElementaryBody(CATBody *ipBody);
	//-----------------------------------------------------------------------------------------------------------------------
	// Function : IsElementaryBody
	// Purpose : Return TRUE if the face has as support an elementary surface
	//-----------------------------------------------------------------------------------------------------------------------
	static CATBoolean IsElementaryFace(CATFace *ipFace);
	///---------------------------------------------------------------------------------------------
	// Function : 	IsSingularFace
	// Purpose :  returns FALSE  if the  input has at least a singular ISO  or if error occurs
	//            passerelle vers   CATSurfacicTopoSingularityTools
	//---------------------------------------------------------------------------------------------
	static CATBoolean IsSingularFace(CATFace *ipFace);


	///---------------------------------------------------------------------------------------------
	// Function : GetExternalBondaries	
	// Purpose : 
	//          
	//---------------------------------------------------------------------------------------------
	static int GetExternalBondaries(CATGeoFactory * ipFactory, CATTopData *ipData, CATBody *ipBody, CATBody *&oResBody ) ;

	///---------------------------------------------------------------------------------------------
	// Function : GetNumberOfExternalBondaries	
	// Purpose : 
	//          
	//---------------------------------------------------------------------------------------------
	static int GetNumberOfExternalBondaries(CATGeoFactory * ipFactory, CATTopData *ipData, CATBody *ipBody ) ;

	///---------------------------------------------------------------------------------------------
	// Function : GetExternalBondaries	
	// Purpose : 
	//          
	//---------------------------------------------------------------------------------------------
	//static CATBody * CommputeVtxOnWireAtDistanceTo(CATGeoFactory * ipFactory, CATTopData *ipData, CATWire *ipWire, CATVertex *ipRefVtx, const double iRelativeDistance ) ;

	//---------------------------------------------------------------------------------------------
	// Function : GetTearWireBodyFrom	
	// Purpose :         
	//---------------------------------------------------------------------------------------------
	//static CATBody * GetTearWireBodyFrom(CATGeoFactory * ipFactory, CATTopData *ipData, CATBody *ipBodyToTear,  CATVertex *ipStartVtx );
  //---------------------------------------------------------------------------------------------
	// Function : DistanceVertexVertex	
	// Purpose :         
	//---------------------------------------------------------------------------------------------
	static int DistanceVertexVertex(CATSoftwareConfiguration *ipConfig, CATVertex *ipVertex1, CATVertex *ipVertex2, double& oDist );

	//---------------------------------------------------------------------------------------------
	// Function : SplitClosedInOneDirShellInTwoShells	
	// Purpose :         
	//---------------------------------------------------------------------------------------------
	static int SplitClosedInOneDirShellInTwoShells(CATGeoFactory * ipFactory, CATSoftwareConfiguration *ipConfig, CATBody *ipShellBodyToSplit, ListPOfCATFace& olFacesPack1, ListPOfCATFace& olFacesPack2, const CATBoolean iDgbMode=FALSE );

	//---------------------------------------------------------------------------------------------
	// Function : GetEdgesBoundedByVtx:
	// Purpose :
	//---------------------------------------------------------------------------------------------
	static int GetEdgesBoundedByVtx(CATVertex *ipVertex,  const ListPOfCATEdge &ilEdgesToCheck, ListPOfCATEdge &olEdgesBounded);
	//---------------------------------------------------------------------------------------------
	// Function : AdjacentFacesAtVtxInBody
	// Purpose :
	//---------------------------------------------------------------------------------------------
	static int AdjacentFacesAtVtxInBody(CATTopData *ipTopData, CATBody*ipInBody, CATVertex *ipVertex, ListPOfCATFace &olAdjacentFaces);

	//---------------------------------------------------------------------------------------------
	// Function : PropagateEdge
	// Purpose :
	//---------------------------------------------------------------------------------------------
	static CATBody* PropagateEdge(CATGeoFactory *ipFactory, CATTopData *ipTopData, CATBody*ipBodyToPropagate, CATEdge *ipEdgeToPropagate, CATFace *ipReferenceFace);

	//---------------------------------------------------------------------------------------------
	// Function : CreateShellFromListOfFacesNoDupli
	// Purpose :
	//---------------------------------------------------------------------------------------------
	static CATBody* CreateShellFromListOfFacesNoDupli(CATGeoFactory *ipFactory, ListPOfCATFace & ilFaces);

	//-----------------------------------------------------------------------------------------------------------------------
	// Function SubdivideInTwoGroups
	// Purpose: Separate the shell in  two packs of faces.
	//------------------------------------------------------------------------------------------------------------------------
	static int SubdivideInTwoGroups( CATGeoFactory * ipFactory, CATSoftwareConfiguration *ipConfig 
		,CATBody * ipShellBodyToSubdivide, CATBody *ipTearingBody
		,ListPOfCATFace& olFacesPack1, ListPOfCATFace& olFacesPack2, const CATBoolean iDgbMode);

	////---------------------------------------------------------------------------------------------
	//// Function : 	SafeCloneBody
	//// Purpose : 
	////---------------------------------------------------------------------------------------------
	//static CATBody* SafeCloneBody (CATGeoFactory *iFactory, CATSoftwareConfiguration *ipConfig, CATBody *ipBodyToClone,CATCloneManagerType iCloneType 
	//	,CATCGMJournalList* ipReport=NULL, CATCGMJournal::Type iReportType=CATCGMJournal::Modification, CATBoolean iAddInfo=FALSE);
	
	//------------------------------------------------------------------------------------------------------------------------
	// TransformInputBody
	//------------------------------------------------------------------------------------------------------------------------
	static CATBody * TransformBody(CATGeoFactory *ipFactory, CATTopData  *ipTopData, CATBody *ipBodyToTransform,const CATMathTransformation &iTrsf, const CATDynTransformation::CATDynReportMode &iReportType);

	//------------------------------------------------------------------------------------------------------------------------
	// CreateMonoFaceBodyByTopSkin
	// creation d'une face a partir de son support de ses pcrv bords et eventualement de ses loops internes.
	//------------------------------------------------------------------------------------------------------------------------
	static int CreateMonoFaceBodyByTopSkin( CATGeoFactory *ipFactory, CATTopData *ipTopData, CATSurface * ipResSurface, 
		int iNbExtPcurves,  CATPCurve **iptpExtPCurves, CATCrvLimits *iptExtCrvLimits, short *pExteOrien
		, const CATBoolean iReverseResultOrientation
		,CATBody* &opBody 
		,int iNbInternalLoops=0, int* ipNbElemInEachInternalLoops=NULL, CATPCurve **iptpInternalLoopsPCurves=NULL, CATCrvLimits *iptInternalCrvLimits=NULL, short *ipInternalteOrien=NULL);

	//------------------------------------------------------------------------------------------------------------------------
	// CreateMonoFaceBodyByTopSkin
	// creation d'une face a partir de son support de CATSurLimits.
	//------------------------------------------------------------------------------------------------------------------------
	static int CreateMonoFaceBodyByTopSkin(  CATGeoFactory *ipFactory, CATTopData *ipTopData, CATSurface * ipResSurface, const CATSurLimits* ipSurLim, CATBody* &opBody, CATFace ** opFace);
	
	//---------------------------------------------------------------------------------------------
	// Function : Retreve2DElemStatsOn
	// Purpose :         
	//---------------------------------------------------------------------------------------------
	static int Retreve2DElemStatsOn(CATBody *ipBody, int &oNbCells, int &oNbSurfaces);
   static int FindFaces(CATEdge* currentEdge, CATBody* iBody, CATLONG32 & nbFaces, CATFace** oFace);

  static CATBody* BodyVertex(CATGeoFactory* ifactory, CATVertex* iVertex);

   static CATBody* BodyWire(CATGeoFactory* ifactory, CATEdge* iEdge);

  // Pose un vertex sur un body en sortie on a un vertex du body si possible (NULL sinon)
		static CATVertex* LayDown(CATGeoFactory* ifactory, CATTopData& iData, 
			                        CATVertex* iVertex, CATBody *iSupport);
    //Debug CGM
    static int AddBodies(CATLISTP(CATGeometry)& iListe,const CATBody* iB1,const char* iName);

     // Debug CGM : Sauvegarde des operande dans un fichier 
    static int SaveOperand(CATLISTP(CATGeometry)& iListe, const char* iNameOperator);

    static CATICGMObject* Duplicate(CATGeoFactory* iFactory, CATICGMObject* iObj);
	//---------------------------------------------------------------------------------------------
	// Function : 	CreateIso
	// Purpose : 
	//          
	//---------------------------------------------------------------------------------------------
	static CATPLine * CreateIso(CATGeoFactory * ipContainer, CATSoftwareConfiguration *ipConfig
		, CATSurface* ipSurface, const CATSurParam &iLowParam, const CATSurParam &iHighParam
		, double  *opIsoLength);

	//---------------------------------------------------------------------------------------------
	// Function : 	CreateIsoOnFace(
	// Purpose :  Calcul l'iso sur la Face
	//          
	//---------------------------------------------------------------------------------------------
	static CATBody * CreateIsoOnFace( CATSoftwareConfiguration *ipConfig, CATFace *ipFace, const CATSurParam &iLowIsoParam, const CATSurParam &iHighIsoParam);
	//---------------------------------------------------------------------------------------------
	// Function : 	GetWireExtremitiesAndMiddlePoint
	// Purpose :  Evaute  the  point correspondint to CrvParam (StartCrvParam+ iLambda *(EndCrvParam-StartCrvParam)
	//            iLambda in [0., 1.] 
	//---------------------------------------------------------------------------------------------
	static int EvaluatePointOnWire (CATBody *ipMonoWireBodyToCheck, const double  iLambda, CATMathPoint &oPoint );

  //---------------------------------------------------------------------------------------------
  // Function : 	Removes an object from one CATICGMContainer.
  // Purpose :  catch potential throw with error / trace management
  // return positive value in case of error.
  // else the ptr iObjectToRemov is automatically set to 0.
  //---------------------------------------------------------------------------------------------
  static int SafeRemove(CATGeoFactory * ipContainer, CATICGMObject* iObjectToRemove, CATICGMContainer::CATRemovingDependancies iHow= CATICGMContainer::KeepDependancies);

private :

	//------------------------------------------------------------------------------------------------------------------------
	//Function: MaxDeviation()
	//Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	static int MaxDeviation(CATPolyMeshDistance* ipDistanceOp, /*double &oMaxDeviation,*/  CATListOfDouble &olDeviations , CATLISTV(CATMathPoint) &olDeviationsPoints);

	//------------------------------------------------------------------------------------------------------------------------
	//Function: Remove()
	//Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	static int Remove(CATGeoFactory *ipFactory, CATEdgeCurve *& iopMergeCurve,CATPointOnEdgeCurve* &iopStartPOEC, CATPointOnEdgeCurve* &ioEndPOEC ) ;
	//-----------------------------------------------------------------------------------------------------------------------
	// Function RetrievalBoundEdgesAndItsFaces
	// Purpose:
	//------------------------------------------------------------------------------------------------------------------------
	static int RetrievalBoundEdgesAndItsFaces(CATGeoFactory *ipFactory, CATSoftwareConfiguration *ipConfig, CATBody *ipShellBody
		, ListPOfCATEdge &olBoundEdges, ListPOfCATFace &olBoundEdgesFaces
		);
	//-----------------------------------------------------------------------------------------------------------------------
	// Function GetFeasibleTearVtx
	// Purpose: wire must be closed 
	//------------------------------------------------------------------------------------------------------------------------
	static int GetFeasibleTearWireVtxForShell( CATTopData *ipData, CATWire *ipWire, CATBody * ipShellBody, ListPOfCATVertex & olVtx, double &oWireLength, int  &oNbButtefleyVtx, CATListOfDouble& olDistanceToNext, ListPOfCATEdge &olEdgeTearPath,  ListPOfCATFace &olFaces);

	//---------------------------------------------------------------------------------------------
	// Function : EstimateNextVtxAtGivenLenght	
	// Purpose :         
	//---------------------------------------------------------------------------------------------
	static int EstimateNextVtxAtGivenLenght(const int iCurrentIdx, const CATListOfDouble& ilDistanceToNext, const double iInterLength , double &oLength, int &oCorrespondingIdx );

	//---------------------------------------------------------------------------------------------
	// Function : ComputeDisconnectBodyFromTearWires	
	// Purpose :         
	//---------------------------------------------------------------------------------------------
	static  CATBody * ComputeDisconnectBodyFromTearWires(CATGeoFactory * ipFactory, CATTopData *ipData, CATBody *ipBodyToTear, const ListPOfCATVertex & ilVtx
		, const CATListOfDouble& ilDistanceToNext/*, const double iWireLength*/, const ListPOfCATEdge &ilEdgeTearPath, const ListPOfCATFace &ilFaces);

	//-----------------------------------------------------------------------------------------------------------------------
	// Function SplitClosedInOneDirShellWireMode
	// Purpose: wire must be closed 
	//------------------------------------------------------------------------------------------------------------------------
	static int SplitClosedInOneDirShellWireMode( CATGeoFactory * ipFactory, CATSoftwareConfiguration *ipConfig 
		,CATBody * ipShellBodyToSplit, const ListPOfCATVertex & ilTearVtx
		,  const CATListOfDouble &ilDistanceToNext, const ListPOfCATEdge &ilEdgeTearPath, const ListPOfCATFace &ilRefFacesOfEdgeTearPath
		,ListPOfCATFace& olFacesPack1, ListPOfCATFace& olFacesPack2, const CATBoolean iDgbMode);
	//-----------------------------------------------------------------------------------------------------------------------
	// Function SplitClosedInOneDirShellButterflyMode
	// Purpose:  au plus  deux vtx  papillon  au moins  1 
	//------------------------------------------------------------------------------------------------------------------------
	static int SplitClosedInOneDirShellButterflyMode( CATGeoFactory * ipFactory, CATSoftwareConfiguration *ipConfig 
		,CATBody * ipShellBodyToSplit, const ListPOfCATVertex & ilTearVtx
		,  const CATListOfDouble &ilDistanceToNext, const ListPOfCATEdge &ilEdgeTearPath, const ListPOfCATFace &ilRefFacesOfEdgeTearPath
		,ListPOfCATFace& olFacesPack1, ListPOfCATFace& olFacesPack2, const CATBoolean iDgbMode);



	//---------------------------------------------------------------------------------------------
	// Function : SumDistances
	// Purpose :         
	//---------------------------------------------------------------------------------------------
	static double SumDistances(const CATListOfDouble& ilDistanceToNext);

	
		


};

#endif
