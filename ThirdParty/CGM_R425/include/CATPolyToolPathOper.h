// COPYRIGHT Dassault Systemes 2021, all rights reserved
//===================================================================
// CATPolyToolPathOper:
// Interfaces for tool path computation
//===================================================================
// Aug 2021 : VKH1: Creation in CATPolyToolPathOper
// Feb 2023 : RFL2: Add undercut option
//===================================================================

#ifndef CATPolyToolPathOper_H
#define CATPolyToolPathOper_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "CATListOfDouble.h"
#include "CATListOfInt.h"
#include "ExportedByCATPolyToolPathOper.h"
#include "CATCGMSharedPtr.h"
#include "CATPolyRefCounted.h"
#include "CATCGMOutput.h"

#include "CATUnicodeString.h"
class CATIPolyMesh;
class CATPolyMeshImpl;
class CATPolyPolygon2D;
class CATTolerance;
class CATPolyPolygonOverlayOptions2D;
class CATPolyBar2D;
class CATMathPoint;
class CATPolyVertex2D;
class CATMathVector;
class CATMath3x3Matrix;
class CATPolyExactArithmetic;
class CATSoftwareConfiguration;
class CATPolyMeshVertexFacetNeighborhood;
class CATPolyMinkowskiSumObserverForToolPath;


/** @brief operation type - only Zlevel supported for now
* 
*/
enum ToolPathMillingOperationMode { ZLevel = 1, ContourDriven, Sweeping };

/** @brief enum for Mapping type informations with conventions:
*		VT = > Vertex index in ToolPart and Triangle index in Workpiece
*		TV = > Triangle index in ToolPart and Vertex index in Workpiece
*		EE = > edge index in ToolPart and edge index in Workpiece 
*/
enum TPmappingType { TV = 1, EE, VT };

/** @brief struct containing mapping information for a given couple of vertex corresponding to the extremities of an edge
*/
struct TPmapping {
	TPmappingType TypeOfCouple;
	std::pair<int, int> TV;
	std::pair<std::pair<int, int>, std::pair<int, int>> EE;
	std::pair<int, int> VT;
};

//for internal use
struct BarOrigins {
	std::vector<std::pair<int, int>> TVCouples;
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> EECouples;
	std::vector<std::pair<int, int>> VTCouples;
};

class ExportedByCATPolyToolPathOper CATPolyToolPathOper
{

public:
	CATPolyToolPathOper();
  ~CATPolyToolPathOper();

	/** @brief Set the Milling operation
	* @param iMode the operations type : ZLevel, ContourDriven, Sweeping
	* Limitation: Only ZLevel is supported
	*/
	void SetMillingMode(ToolPathMillingOperationMode iMode);


	/** @brief Set the workpiece
	* @param ipMeshWorkpiece the CATIPolyMesh representing the part
	* @param iInvertTrianglesNormal to Invert triangles normal (false by default)
	* Limitation: Only one mesh, closed or open, connex or non connex
	*/
	void SetWorkpiece(CATCGMSharedPtr<CATIPolyMesh> ipMeshWorkpiece, bool iInvertTrianglesNormal = false);

	/** @brief Add a cutting tool part 
	* @param ipMeshCuttingToolPart: the CATIPolyMesh representing the cutting part of the tool
	* return the index of the tool part (considering a list of tool part for an assembly tool)
  * Limitation: Only one tool part / Mesh must be closed / index == 1 
	*/
	int AddCuttingToolPart(CATCGMSharedPtr<CATIPolyMesh> ipMeshCuttingToolPart);

	/** @brief Add a non cutting tool part - optional
	* @param ipMeshNonCuttingToolPart: the CATIPolyMesh representing the non cutting part of the tool
	* return the index of the tool part
	*/
	int AddNonCuttingToolPart(CATCGMSharedPtr<CATIPolyMesh> ipMeshNonCuttingToolPart); // int AddNonCuttingToolPart(CATIPolyMesh* ipMeshNonCuttingToolPart);

	/** @brief Get number of parts in the tool assembly
	*/
	int GetNumberOfToolParts() const;

	/** @brief Define the plans for ZLevel with constant step
	* @param iFirstPlan : Z coordinate of the first cutting plan
	* @param iDistanceBetweenPath : The Distance between each path during the milling operation
	* @param iNbPlan : The number of plan to compute from the FirstCuttingPlan
	*/
	HRESULT SetConstantPlansParam(double iFirstPlan, double iDistanceBetweenPath, int iNbPlan);

	/** @brief Define the list of plans for ZLevel 
	* @param iListOfPlans: the list of Z coord of plans
	*/
	void SetVariablePlans(CATListOfDouble iListOfPlans);

	/** @brief Get list of Zplans
	*/
	CATListOfDouble GetListOfPlans();

	/** @brief Activate the undercut mode
	* undercut mode allows to compute path in the recessed surface of the part
	*/
	void SetHandleUndercut(bool handleUndercut);
	bool IsUndercutHandled() const;

	/** @brief Run the computation
	*/
	HRESULT Run();

	/** @brief Get resulting path polygon in a given plane
	* @param	iNumPlan: Num (index) of the plan asked  
	* WARNING: Index of plans starts to 1 !!  (and finishs to the last num plan)
	*/
	CATPolyPolygon2D* GetPolygon(int iNumPlan);

	/** @brief Get path polygon of a given tool part in a given plane - (necessary?)
	* @param	iToolPartIdx: index of the tool part
	* @param	iNumPlan: index of the plane
	* WARNING: Index of plans starts to 1 !!  (and finishs to the last num plan)
	*/
	CATPolyPolygon2D* GetToolPartPolygon(int iToolPartIdx ,int iNumPlan);

	/** @brief Get Contact Points between cutting tool and part in a given plane
	* @param	iNumPlan: index of the plane 
	* @param	iVx: Index of vertex in the polygon
	* @param	oPCs coordinate 3D of the contact points
	*/
	HRESULT GetContactPoints(int iNumPlan, CATPolyVertex2D& iVx, std::vector<CATMathPoint>& oPCs);

	/** @brief Get mapping information: origons of the segments of the path
	* @param	iNumPlan: index of the plane 
	* @param	iV0V1: index of start and end vertex of the edge of the path
	* @param	oMapInfo: the mapping information from ToolPart and Workpiece 
	* Limitation: Not implemented
	*/
	HRESULT GetMapInfo(int iNumPlan, std::pair<int, int> iV0V1, TPmapping oMapInfo);

	/** @brief internal use only
	* Get Minkowski Sum mesh between part and a given tool part 
	* return the MinkowskiSum mesh result of the Head ToolPart
  */
	CATIPolyMesh* GetMinkowskiSum() const;

	/** @brief internal use only 
	* Get Minkowski Sum mesh between part and a given tool part
	* @param	idxToolPart index opf the tool part in assembly tool
	* index 0 gives the MS of the head (equivalent to call GetMinkowskiSum)
	* index 1 to n-1 gives the MS of the ith non cutting part (with n the number of Tool parts : cutting + non cuttings)
	*/
	CATIPolyMesh* GetToolPartMinkowskiSum(int idxToolPart) const;

	/**
	 * @brief  ??
	 * Get the Name Of the Tool Part
	 * @param idxToolPart the index of the wanted Tool Part, 0 for Head, and 1 to n-1 for non cutting parts (with n the number of Tool parts : cutting + non cuttings)
	 * @return CATUnicodeString the name of the wanted Tool Part
	 */
	CATUnicodeString GetNameOfToolPart(int idxToolPart) const;

	/**
	 * @brief  ??
	 * */
	std::shared_ptr<CATPolyPolygon2D> GetSilhouetteOfPlan(int idxPlan) const;

private:

	/** Set the Distance between each path during the milling operation
	* @param iDistanceBetweenPath: Z distance between a path to the next one
	* Limitation: Only ZLevel compliant
  */
  void SetDistanceBetweenPath(double iDistanceBetweenPath);
  
	/**  Set Z coordinate of the first cutting plan
	* @param iFirstPlan: First Z plan
  * Limitation: Only ZLevel compliant
  */
  void SetFirstCuttingPlan(double iFirstPlan);
  
	/**  Set the number of plan to compute from the FirstCuttingPlan
  * moving to the next doing: Z_Next = FirstCuttingPlan - iDistanceBetweenPath	
	* @param iNbPlan: Nbplan
  * Limitation: Only ZLevel compliant
  */
  void SetNbPlan(int iNbPlan);

	/**
	 * Get list of Zplans - really necessary ?
	 * */
	int GetNumberOfPlans() const;

	/**  BuildOverlayOptions2D
	* @param iOnlyHead: Only the tool head is considered
	* @param iTol: Tolerance
	* @param iExactArithmetic: ExactArithmetic
	* @param iMSResHolderWS: Mesh of the holder tool part (only if iOnlyHead is false)
	* @param iMSResShankWS: Mesh of the shank tool part (only if iOnlyHead is false)
	* @param iMSResHeadWS: Mesh of the head tool part
	* @param oOptions_MS_ToolCompleteXYView_WS: OverlayOptions
	*/
  HRESULT BuildOverlayOptions2D(bool iOnlyHead, const CATTolerance& iTol, CATPolyExactArithmetic& iExactArithmetic,
		CATIPolyMesh& iMSResHolderWS, CATIPolyMesh& iMSResShankWS, CATIPolyMesh& iMSResHeadWS,
		CATPolyPolygonOverlayOptions2D& oOptions_MS_ToolCompleteXYView_WS);

	/*
		MatrixInversibility
			iM: Matrix to inversed
			iTol: Tolerance
  */
	static CATBoolean MatrixInversibility(const CATMath3x3Matrix& iM, double iTol);

	/*
		GetBarExtremities
			iNumPlan: Plan index
			ibar: bar
			oPtS: Start point of the bar
			oPtE: End point of the bar
	*/
	HRESULT GetBarExtremities(int iNumPlan, CATPolyBar2D* ibar, CATMathPoint& oPtS, CATMathPoint& oPtE);

	/*
		ComputeContactPointFromTV
			return the list of contact points computed from an MinkowskiSum mesh created by a Triangle-Vertex (TV) couple of mesh inputs 

			iNumPlan: Plan index
			ibar: bar
			iTV: TV couple
			oPCs: Contact points computed
  */
	HRESULT ComputeContactPointFromTV(int iNumPlan, CATPolyBar2D* ibar, std::pair<int, int>& iTV, std::vector<CATMathPoint>& oPCs);
	
	/*
		ComputeContactPointFromEE
			return the list of contact points computed from an MinkowskiSum mesh created by a Edge-Edge (EE) couple of mesh inputs

			iNumPlan: Plan index
			ibar: bar
			iEE: EE couple
			oPCs: Contact points computed
  */
	HRESULT ComputeContactPointFromEE(int iNumPlan, CATMathPoint iPtS, std::pair<std::pair<int, int>, std::pair<int, int>>& iEE, std::vector<CATMathPoint>& oPCs);
	
	/*
		ComputeContactPointFromVT
			return the list of contact points computed from an MinkowskiSum mesh created by a Vertex-Triangle (VT) couple of mesh inputs

			iNumPlan: Plan index
			ibar: bar
			iVT: VT couple
			oPCs: Contact points computed
	*/
	HRESULT ComputeContactPointFromVT(int iNumPlan, CATMathPoint iPtS, std::pair<int, int>& iVT, std::vector<CATMathPoint>& oPCs);
	
	/*
		RemoveDuplicatesContactPoints
			because sometimes, a same contact point can be computed by several ways (TV, EE, VT)

			oPCs: Contact points computed
	*/
	HRESULT RemoveDuplicatesContactPoints(std::vector<CATMathPoint>& oPCs);
	
	/*
		GetIntersection

			iO1: Origin1
			iV1: Vector1
			iO2: Origin2
			iV2: Vector2
			oIntersectionPt: intersection points computed
	*/
	HRESULT GetIntersection(CATMathPoint& iO1, CATMathVector& iV1, CATMathPoint& iO2, CATMathVector& iV2, CATMathPoint& oIntersectionPt);
	
	/*
		GetPCForBarExtremity
			specific case of ComputeContactPointFromEE method (see code)

			iT0: Start Point of Tool Edge
			iT1: End Point of Tool Edge
			iPtBarExtremity: Point of the bar for which we compute the contact points
			iP0: Start Point of Workpiece Edge
			iP1: End Point of Workpiece Edge
			oPCs: Contact points computed
	*/
	HRESULT GetPCForBarExtremity(CATMathPoint& iT0, CATMathPoint& iT1, CATMathPoint& iPtBarExtremity, CATMathPoint& iP0, CATMathPoint& iP1, std::vector<CATMathPoint>& oPCs);
	
	/*
		CheckPCregardingZ
			check regarding the Plan index if the contact points computed are coherent (ZPlan +/- Tool Head Height)

			iNumPlan: Plan index
			iPC: End Point of Tool Edge
			izmin: zmin possible of the contact point controlled
			zmax: zmax possible of the contact point controlled
			iRes: End Point of Workpiece Edge
	*/
	HRESULT CheckPCregardingZ(int iNumPlan, CATMathPoint& iPC, double& izmin, double& zmax, bool& iRes);

	/*
		RunPart
			run all tool path oper computation method for a given part of the tool

			iToolPart: Tool part
			oToolPartForMS: End Point of Tool Edge
			iFileName: Name of the path computed file
			oPolygonList: Resulting polygons
			iListPlan: List of plans
			iomapBarToTri: map [ bar in resulting polygon <-> triangle of the minkowskiSum mesh result ] 
			iomapPolygonBarsToCouplesOrigins: map [ bar in resulting polygon <-> couple origin ]
	*/
	HRESULT RunPart(CATCGMSharedPtr<CATIPolyMesh>& iToolPart, 
		CATCGMSharedPtr<CATIPolyMesh>& oToolPartForMS, 
		std::vector<CATPolyPolygon2D*>& oPolygonList, 
		CATListOfDouble& iListPlan, 
		std::vector<std::multimap<const CATPolyBar2D*, int>*>& iomapBarToTri, 
		std::vector<std::map<CATPolyBar2D*, BarOrigins>>& iomapPolygonBarsToCouplesOrigins);

	
	//??
	HRESULT PrintInputsAt(CATUnicodeString const& path) const;

	//??
	HRESULT PrintOutputAt(CATUnicodeString const& path) const;

	//??
	HRESULT ComputeWPSilhouettes();

	//??
	void CleanPolygonFromTooSmallFaces(CATPolyPolygon2D& ioPolygon, double tol);

	//??
	class ToolPart : public CATPolyRefCounted 
	{
	public :

		ToolPart(CATCGMSharedPtr<CATIPolyMesh> const& toolPart, bool isCutting);
		~ToolPart();

		bool isCuttingPart() const;
		void SetName(std::string const& name);
		const char* GetName() const;
		void SetToolPartForMS(CATCGMSharedPtr<CATIPolyMesh> meshToolPartForMS);

		CATIPolyMesh& GetMeshToolPart();
		CATIPolyMesh& GetMeshToolPartForMS();
		
		double GetZOfPlan(int idxPlan) const;
		CATPolyPolygon2D* GetPolygon(int k) const;

		void ComputeVertexFacetNeighborhoodOfToolPartForMS();
		CATPolyMeshVertexFacetNeighborhood& GetVertexFacetNeighborhoodOfToolPartForMS();
		CATPolyMinkowskiSumObserverForToolPath& GetObserverMS();
		
		void SetListOfPlans(CATListOfDouble& iListOfPlans, double shift = 0);

		//Check if the tool part is not null and is closed
		HRESULT CheckMeshToolPart() const;

		double ComputeOverlayingTolerance(CATIPolyMesh const& workpiece) const;
		HRESULT RunAndCheckMinkowskiSum(CATCGMSharedPtr<CATIPolyMesh> const& workpiece);
		
		HRESULT ComputeContourPathForPlanK(int k, CATIPolyMesh& workpiece, double overlayingTolerance, 
										   CATPolyMeshVertexFacetNeighborhood& iVertexFacetNeighborhoord_WP,
										   CATSoftwareConfiguration& iSoftwareConfig);
		
		void ComputeContactPointsForPlanK(int k);

	public:

		CATCGMSharedPtr<CATIPolyMesh> _meshToolPart; 
		CATCGMSharedPtr<CATIPolyMesh> _meshToolPartForMS; //usually : the toolPart Rotated of 180 around y

		CATCGMSharedPtr<CATIPolyMesh> _meshResMS;
		CATPolyMinkowskiSumObserverForToolPath* _observerMS = nullptr;

		bool _isCutting;
		std::string _name;
		
		//[WARNING] : to fit the CATListOfDouble indexation convention, all vectors starts from index 1 (index 0 is not initialized)
		CATListOfDouble* _heightOfZPlans = nullptr;
		double _shift;
		std::vector<CATPolyPolygon2D*> _polygons;

		//the ith elmt of the vector is the map for the ith polygon of _polygons
		std::vector<std::multimap<const CATPolyBar2D*,int>*> _mapBarToMSTriangle;

		std::vector<std::map<CATPolyBar2D*, BarOrigins>> _mapBarsToCouplesOrigins;

		CATPolyMeshVertexFacetNeighborhood* _vertexFacetNeighborhoord_ToolPartForMS = nullptr;

	};

	//??
	HRESULT RunPart(ToolPart& ioToolPart);


	double _DistanceBetweenPath = 0.;
	double _FirstPlan = 0.;
	int _NbPlan = 0;
	double _TolPercentageForPlanComputation = 0.;

	ToolPathMillingOperationMode _Mode = ToolPathMillingOperationMode::ZLevel;

	CATListOfDouble _ListPlan; //contains the list of plan's height for the cutting tool part
	
	// ------------- Cutting part, put it into a struct/class : ToolPart --------------
	//CATCGMSharedPtr<ToolPart> _cuttingToolPart;
	CATCGMSharedPtr<CATIPolyMesh> _MeshCuttingToolPart; //used into : CheckPCregardingZ
	CATCGMSharedPtr<CATIPolyMesh> _MeshCuttingToolPartForMSObs; //used into : ComputeContactPointFromEE, ComputeContactPointFromVT
	CATCGMSharedPtr<CATIPolyMesh> _MeshResMinkowskiSum; //used into : GetMinkowskiSum
	std::vector<CATPolyPolygon2D*> _PolygonHeadList;
	std::vector<std::multimap<const CATPolyBar2D*, int>*> _mapBarToTri; // // Contact Points [OK]
	std::vector<std::map<CATPolyBar2D*, BarOrigins>> _mapPolygonBarsToCouplesOrigins;  //used into : GetContactPoints	
	// ------------- Cutting part, put it into a struct/class : ToolPart --------------

	
	//Non Cutting Parts ordered from nearest to farest from the cutting part
	std::vector<CATCGMSharedPtr<ToolPart>> _nonCuttingToolParts;

	CATSoftwareConfiguration* _Config_MS_ToolCompleteXYView_WS = nullptr;
	CATPolyMeshVertexFacetNeighborhood* _PolyMeshVertexFacetNeighborhood_WP = nullptr;

	std::vector<CATPolyPolygon2D*> _PolygonList;
	CATCGMSharedPtr<CATIPolyMesh> _MeshWorkpiece;

	//the poly _slihouettes[i] is the silhouette of the part of the workpiece which is between _ListPlan[i] and above
	std::vector<std::shared_ptr<CATPolyPolygon2D>> _silhouettes; 

	//set the handle of the undercut. If it is true, then the toolpath will assume that the toolend point can't be under a part of the workpiece
	//It avoid collisions between the workpiece and the machine when the machine has 3 axis. (for more axis, the toolend can be under the workpiece without any collision)
	bool _isUnderCutHandled = false;

	int _NbNonCuttingPartDeclared = 0;

	bool _b_EnvVar_TP_Perfo = false;
	bool _b_EnvVar_TP_NoToolRotation = false;
	bool _b_EnvVar_TP_DebugTraces = false;
	bool _b_EnvVar_TP_GetInputMesh = false;
	bool _b_EnvVar_TP_GetMeshResMinkowskiSum = false;
	CATUnicodeString _cus_EnvVar_TP_GetPolygonsInFolder;
	bool _b_EnvVar_TP_DeactivateParallelCode = false;
};


#endif
