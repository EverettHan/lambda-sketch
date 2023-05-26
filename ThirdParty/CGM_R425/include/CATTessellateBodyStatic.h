// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessellateBodyStatic
//*
//* Instance of CATCGMTessBody that:
//* • provides a watertight tessellation of a CATBody (set of topologically connected cells) for a particular set of tessellation parameters.
//* • supports incremental tessellation (cell by cell in the context of the CATBody: when assembling all cell meshes, the resulted mesh of the CATBody is watertight).
//* • provides a TessID to identify the tessellation of a cell in the context of the CATBody, to be compared with the one created with another CATBody for possible reuse. 
//* • stores in each cell the local description of its tessellation (cache), allowing it to be reused in a context of another CATBody for the same set of tessellation parameters. 
//*   The number of cache is limited due to memory consumption: 3 sets of tessellation parameters are recommended: coarse, medium and fine (for example MaxDeviation = 0.2, 0.05, 0.02).
//*
// Use CATCGMCreateTessBody with CATCGMTessellateParam to create this instance:
// CATCGMTessBody *CATCGMCreateTessBody(CATBody &iBody, CATSoftwareConfiguration* iSoftwareConfig, const CATCGMTessellateParam &iTessellateParam, int iMode=0, int iPrecision=1);
//
//===================================================================
//
// April 2012  TPG
//    20-02-2023  LVL ZATPROJECT
//
//===================================================================

#ifndef CATTessellateBodyStatic_H
#define CATTessellateBodyStatic_H

#include "ExportedByTessellateCommon.h"
#include "CATPGMTessBody.h"
#include "CATListPV.h"
#include "CATErrors.h"
#include "CATListOfCATIPolySurfaceVertexLine.h"
#include "CATListOfCATIPolySurfaceVertex.h"
#include "CATListOfCATIPolyCurveVertex.h"
#include "CATMapOfPtrToPtr.h"
#include "CATMapOfEdgeToPolySurfaceVertexLine.h"
#include "CATMapOfVertexToPolySurfaceVertex.h"

class CATGeoFactory;
class CATBody;
class CATFace;
class CATEdge;
class CATVertex;
class CATCell;
class CATTessDataCache;

class CATIPolySurface;
class CATIPolyCurve;
class CATIPolyPoint;
class CATPolySurfaceVertexLineList;

class CATTessellateParam;
class CATTessellateParamCache;
class CATTessellateParamCacheContainer;

class CATCGMUVTessBuilder;
class CATCGMUVWTData;
class CATCGMUVFaceWTData;
class CATCGMUVEdgeWTData;
class CATICGMUVTessellator;
class CATCGMTessellator;
class CATMapOfPtrToPtr;
class CATTessellateBodyStaticObserver;
class CATListPtrCATCell;

class CATMathPolyBuffers;
class CATTessParameters;

/** 
 * @see CATCGMTessBody
*/
class ExportedByTessellateCommon CATTessellateBodyStatic : public CATPGMTessBody
{
public:
	/**
	* Constructor and Destructor
	*
	* working mode (refer to CATCGMTessellator)
	* iWorkingMode: 
	* 0: cpu +++ memory + (default).
	* 1: cpu ++  memory ++.
	* 2: cpu +   memory +++.
	*
	* precision
	* 0: float vertex position.
	* 1: double vertex position.
	*
	* PreProcessBody: compute internal model
	* 0: cell by cell (good when the Body is activated, upward links available).
	* 1: globally (good when the Body is not activated, upward links not available).
	*/
	CATTessellateBodyStatic(CATBody& iBody, CATTessellateParam& iTessParam, int iWorkingMode=0, int iPrecision=1, int iPreProcessBody=1, int iConstructorWithoutAddRef=0);
	~CATTessellateBodyStatic();

public:
	/** 
	* @see CATCGMTessBody
	*/
	const CATBody &GetBody() const;

	/** 
	* @see CATCGMTessBody
	*/
	CATBody& GetBody ();
 
	/** 
	* @see CATCGMTessBody
	*/  
	double GetSag() const;

public:
 
	/**
	* Given a CATFace returns its tessellation as a CATIPolySurface.
	*
	* @param iFace
	*   The input CATFace whose tessellation is requested.
	* @param oPolySurface
	*   The output instance providing access to the tessellation of the CATFace.
	*   The returned instance must be released by the caller.
	* @param oOriPolySurfaceVsFace (optional)
	*   Orientation of the output polysurface with respect to the CATFace.
	* @return
	*   <ul>
	*     <li> S_OK if a CATIPolySurface is returned successfully for this CATFace.
	*     <li> E_FAIL or any other error when a failure occurs.
	*   </ul>
	*/
	HRESULT GetPolySurface (CATFace &iFace, CATIPolySurface *&oPolySurface, CATOrientation * oOriPolySurfaceVsFace=0);

	HRESULT ReMeshFace(CATGeoFactory* iFactory, CATSoftwareConfiguration* iConfig, CATFace* iFaceA, CATIPolySurface* iPolySurfaceA, CATOrientation iOriA, CATFace* iFaceB, CATIPolySurface* iPolySurfaceB, CATOrientation iOriB);
	
	/**
	* Given a CATFace returns its tessellation as a CATIPolySurface.
	*
	* @param iFace
	*   The input CATFace whose tessellation is requested.
	* @param oPolySurface
	*   The output instance providing access to the tessellation of the CATFace.
	*   The returned instance must be released by the caller.
	* @param ioEdgeMapToPolyCurve
	*   An instance mapping the edges adjacent to the CATFace to their tessellation in the form of 
	*   a CATIPolySurfaceVertexLine (same orientation as corresponding PolyCurve returned by GetPolyCurve).
	*   This argument may be null.
	* @param ioVertexMapToPolyPoint
	*   An instance mapping the vertices adjacent to the CATFace to their tessellation in the form of 
	*   a CATIPolySurfaceVertex.
	*   This argument may be null.
	* @param oOriPolySurfaceVsFace (optional)
	*   Orientation of the output polysurface with respect to the CATFace.
	* @return
	*   <ul>
	*     <li> S_OK if a CATIPolySurface is returned successfully for this CATFace.
	*     <li> E_FAIL or any other error when a failure occurs.
	*   </ul>
	*/
	HRESULT GetPolySurface (CATFace &iFace, CATIPolySurface *&oPolySurface,
												CATMapOfEdgeToPolySurfaceVertexLine* ioEdgeMapToPolyCurve,
												CATMapOfVertexToPolySurfaceVertex* ioVertexMapToPolyPoint, 
																	CATOrientation * oOriPolySurfaceVsFace=0);

	/**
	* Given a CATFace returns its local tessellation (CATBody context independent) as a CATIPolySurface.
	*
	* @param iFace
	*   The input CATFace whose tessellation is requested.
	* @param oPolySurface
	*   The output instance providing access to the tessellation of the CATFace.
	*   The returned instance must be released by the caller.
	* @param ioEdgeMapToPolyCurve
	*   An instance mapping the edges adjacent to the CATFace to their tessellation in the form of 
	*   a CATIPolySurfaceVertexLine (same orientation as corresponding PolyCurve returned by GetPolyCurve).
	*   This argument may be null.
	* @param ioVertexMapToPolyPoint
	*   An instance mapping the vertices adjacent to the CATFace to their tessellation in the form of 
	*   a CATIPolySurfaceVertex.
	*   This argument may be null.
	* @param oOriPolySurfaceVsFace (optional)
	*   Orientation of the output polysurface with respect to the CATFace.
	* @return
	*   <ul>
	*     <li> S_OK if a CATIPolySurface is returned successfully for this CATFace.
	*     <li> E_FAIL or any other error when a failure occurs.
	*   </ul>
	*/
	HRESULT GetPolySurfaceLocal (CATFace &iFace, CATIPolySurface *&oPolySurface,
												CATMapOfEdgeToPolySurfaceVertexLine* ioEdgeMapToPolyCurve,
												CATMapOfVertexToPolySurfaceVertex* ioVertexMapToPolyPoint, 
																	CATOrientation * oOriPolySurfaceVsFace=0);

	/**
	* Given a CATFace and its CATIPolySurface previously computed returns the list of IsoVertexLines.
	*
	* @param iFace
	*   The input CATFace whose tessellation is requested.
	* @param iPolySurface
	*   The input instance providing access to the tessellation of the CATFace.
	* @param ioIsoVertexLinesList
	*   The list of CATIPolySurfaceVertexLine, to be deleted by the caller.
	* @return
		*   Number of CATIPolySurfaceVertexLine
	*/
	CATULONG32 GetPolySurfaceIsoVertexLines(CATFace &iFace, CATIPolySurface &iPolySurface, CATIPolySurfaceVertexLine** &ioIsoVertexLinesList);

	// @nodoc
	HRESULT GetPolySurface(CATFace &iFace, CATIPolySurface *&oPolySurface, 
									CATListOfCATIPolySurfaceVertexLine* ioTessEdgeCurveList, //give NULL if no need
									CATListOfCATIPolySurfaceVertex* ioTessFacePointList,
													CATOrientation * oOriPolySurfaceVsFace=0); //give NULL if no need

	/**
	* Given a CATEdge returns its tessellation as a CATIPolyCurve.
	*
	* The CATIPolyCurve instance returned is just a discrete curve in space with no reference to the underlying surface
	* even when the CATEdge is adjacent to a CATFace.  This CATIPolyCurve is *not* a CATIPolySurfaceVertexLine. 
	* See GetPolySurface to obtain the tessellation of an edge with references to the underlying geometry.
	*
	* @param iEdge
	*   The input CATEdge whose tessellation is requested.
	* @param oPolyCurve
	*   The output instance providing access to the tessellation of this CATEdge.
	*   The returned instance must be released by the caller.
	* @param oOriPolyCurveVsEdge (optional)
	*   Orientation of the output polycurve with respect to the CATEdge.
	* @return
	*   <ul>
	*     <li> S_OK if a CATIPolyCurve is returned successfully for this CATEdge.
	*     <li> E_FAIL or any other error when a failure occurs.
	*   </ul>
	*/
	HRESULT GetPolyCurve (CATEdge &iEdge, CATIPolyCurve *&oPolyCurve, CATOrientation * oOriPolyCurveVsEdge=0);

	/**
	* Given a CATEdge returns its tessellation as a CATIPolyCurve.
	*
	* The CATIPolyCurve instance returned is just a discrete curve in space with no reference to the underlying surface
	* even when the CATEdge is adjacent to a CATFace.  This CATIPolyCurve is *not* a CATIPolySurfaceVertexLine. 
	* See GetPolySurface to obtain the tessellation of an edge with references to the underlying geometry.
	*
	* @param iEdge
	*   The input CATEdge whose tessellation is requested.
	* @param oPolyCurve
	*   The output instance providing access to the tessellation of this CATEdge.
	*   The returned instance must be released by the caller.
	* @param ioVertexMapToPolyPoint
	*   An instance mapping the vertices adjacent to the CATEdge to their tessellation in the form of 
	*   a CATIPolyCurveVertex.  Note that there are two and only two CATVertex adjacent to a CATEdge.
	*   This argument may be null.
	* @param oOriPolyCurveVsEdge (optional)
	*   Orientation of the output polycurve with respect to the CATEdge.
	* @return
	*   <ul>
	*     <li> S_OK if a CATIPolyCurve is returned successfully for this CATEdge.
	*     <li> E_FAIL or any other error when a failure occurs.
	*   </ul>
	*/
	HRESULT GetPolyCurve (CATEdge &iEdge, CATIPolyCurve *&oPolyCurve,
												CATMapOfVertexToPolyCurveVertex* ioVertexMapToPolyPoint, 
												CATOrientation * oOriPolyCurveVsEdge=0);

	/**
	* Given a CATEdge returns its local tessellation (CATBody context independent) as a CATIPolyCurve.
	*
	* The CATIPolyCurve instance returned is just a discrete curve in space with no reference to the underlying surface
	* even when the CATEdge is adjacent to a CATFace.  This CATIPolyCurve is *not* a CATIPolySurfaceVertexLine. 
	* See GetPolySurface to obtain the tessellation of an edge with references to the underlying geometry.
	*
	* @param iEdge
	*   The input CATEdge whose tessellation is requested.
	* @param oPolyCurve
	*   The output instance providing access to the tessellation of this CATEdge.
	*   The returned instance must be released by the caller.
	* @param ioVertexMapToPolyPoint
	*   An instance mapping the vertices adjacent to the CATEdge to their tessellation in the form of 
	*   a CATIPolyCurveVertex.  Note that there are two and only two CATVertex adjacent to a CATEdge.
	*   This argument may be null.
	* @param oOriPolyCurveVsEdge (optional)
	*   Orientation of the output polycurve with respect to the CATEdge.
	* @return
	*   <ul>
	*     <li> S_OK if a CATIPolyCurve is returned successfully for this CATEdge.
	*     <li> E_FAIL or any other error when a failure occurs.
	*   </ul>
	*/
	HRESULT GetPolyCurveLocal (CATEdge &iEdge, CATIPolyCurve *&oPolyCurve,
											CATMapOfVertexToPolyCurveVertex* ioVertexMapToPolyPoint, 
																CATOrientation * oOriPolyCurveVsEdge=0);

	// @nodoc
	HRESULT GetPolyCurve(CATEdge &iEdge, CATIPolyCurve *&oPolyCurve,
								CATListOfCATIPolyCurveVertex* ioTessEdgeVertexPointList,
												CATOrientation * oOriPolyCurveVsEdge=0);//give NULL if no need

	/**
	* Given a CATFace returns its tessellation as a CATMathPolyBuffers.
	* 
	* @param iFace
	*   The input CATFace whose tessellation is requested.
	* @param oFacePolyBuffers [out, IUnknown#Release] 
	*   The output instance providing access to the tessellation of the CATFace.
	*   The returned instance must be released by the caller.
	* @param oOriPolyBuffersVsFace
	*   The orientation of triangles buffer regarding to the CATFace.
	* @return
	*   <ul>
	*     <li> S_OK if a CATIPolySurface is returned successfully for this CATFace.
	*     <li> E_FAIL or any other error when a failure occurs.
	*   </ul>
	*/
	HRESULT GetPolyBuffers(CATFace& iFace, const CATMathPolyBuffers* &oFacePolyBuffers, 
													CATOrientation& oOriPolyBuffersVsFace,
													int iLocalTessellation=0); // 1: local tessellation independent of CATBody context

	/**
	* Given a CATEdge returns its tessellation as a CATMathPolyBuffers.
	* 
	* @param iEdge
	*   The input CATEdge whose tessellation is requested.
	* @param oEdgePolyBuffers [out, IUnknown#Release] 
	*   The output instance providing access to the tessellation of the CATEdge.
	*   The returned instance must be released by the caller.
	* @param oOriBuffersVsEdge
	*   The orientation of position buffer regarding to the CATEdge.
	* @return
	*   <ul>
	*     <li> S_OK if a CATMathPolyBuffers is returned successfully for this CATFace.
	*     <li> E_FAIL or any other error when a failure occurs.
	*   </ul>
	*/
	HRESULT GetEdgePolyBuffers(CATEdge &iEdge, const CATMathPolyBuffers* &oEdgePolyBuffers,
			  											CATOrientation& oOriBuffersVsEdge,
															int iLocalTessellation=0); // 1: local tessellation independent of CATBody context

	/**
	* Given a CATVertex returns its tessellation as coordinates.
		*
	* @param iVertex
	*   The input CATVertex whose tessellation is requested.
	* @param oCoordinates [out, IUnknown#Release] 
	*   The output coordinates of the CATVertex, must be deleted by the caller.
	* @return
	*   <ul>
	*     <li> S_OK if coordinates are returned successfully for this CATVertex.
	*     <li> E_FAIL or any other error when a failure occurs.
	*   </ul>
	*/
	HRESULT GetVertexCoordinates(CATVertex &iVertex, double* &oCoordinates);
	HRESULT GetVertexCoordinates(CATVertex &iVertex, float* &oCoordinates);

	/** 
	* @see CATCGMTessBody
	*/
	HRESULT GetPolyPoint(CATVertex &iVertex, CATIPolyPoint *&oPolyPoint);

	/**
	* @see CATCGMTessBody
	*/
	HRESULT GetTessellateID (CATCell &iCell, CATCGMTessellateID* &oTessID);
	HRESULT GetRefCountedTessellateID (CATCell &iCell, CATCGMTessellateID* &oTessID);

	/**
	* GetSettingsTessellateID
	*/
	HRESULT GetSettingsTessellateID (CATCGMTessellateID* &oTessID);

	/**
	* @see CATCGMTessBody
	*/
	void EmptyBodyCache (CATBoolean iRemoveNonPersistantDeltaCache=FALSE);
	void EmptyCellCache (CATCell &iCell, CATBoolean iRemoveNonPersistantDeltaCache=FALSE);

  /**
  * Returns the CATTessellateBodyStatic
  */
  CATTessellateBodyStatic * SafeCastToCATTessellateBodyStatic();

	/**
	* Following not implemented, do not call
	*/
	/**
	* @see CATCGMTessBody
	*/
	HRESULT GetTessID (CATCell &iCell, CATCGMTessID &oTessID);

	/**
	* @see CATCGMTessBody
	*/
	HRESULT GetPolySurfaceVertexLine (CATFace& iFace, CATEdge& iEdge, CATIPolySurface& iPolySurface, 
												CATIPolySurfaceVertexLine*& oPolySurfaceVertexLine);

	/**
	* @see CATCGMTessBody
	*/
	HRESULT GetPolySurfaceVertex (CATFace& iFace, CATVertex& iVertex, CATIPolySurface& iPolySurface, 
											CATIPolySurfaceVertex*& oPolySurfaceVertex);

	/**
	* @see CATCGMTessBody
	*/
	HRESULT GetPolyCurve (CATFace& iFace, CATEdge& iEdge, CATIPolyCurve*& oPolyCurve);

	/**
	* @see CATCGMTessBody
	*/
	HRESULT GetPolyPoint (CATFace& iFace, CATVertex& iVertex, CATIPolyPoint*& oPolyPoint);

	/**
	* @see CATCGMTessBody
	*/
	const CATTessParam& GetTessParam () const;

	/**
	* @see CATCGMTessBody
	*/
	const CATTessParamToken& GetTessToken () const;

	/**
	* Specific methods
	*/
  
	HRESULT SynchronizeFaces(CATFace* iFace1, CATFace* iFace2);
  /**
  * working mode(refer to CATCGMTessellator)
  * iWorkingMode:
  * 0 : cpu++ + memory + (default).
  * 1 : cpu ++  memory++.
  * 2 : cpu + memory++ + .
  */
  void SetWorkingMode(int iMode);

	/**
	* GeomVisu
	* 0: 
	* 1: 
	*/
	void SetGeomVisu(int iGeomVisu);
    int GetGeomVisu();

  /**
* Micron Tessellation
* 0:
* 1:
*/
  void SetMicronTessellation(int iUnableMicronTessellation);

	/**
	* Direct access to the tessellation cache (local mesh) and orientation of the cell regarding data cache 
	* returns oCellDataCache=NULL if there is delta mesh in the body context
	*/
	HRESULT GetCellDataCache(CATCell& iCell, const CATTessDataCache*& oCellDataCache, int & oOrientation);

	/**
* return the Delta Params of an Edge in order to display them for example ( NCGM)
*/
	HRESULT GetDeltaParam(CATEdge& iCell, int& oNbDelta, CATListPtrCATCell* oListOfDeltaCells, CATListOfDouble* oListOfDeltaParams);

	/**
	* Tessellation delta cache management 
	*/
	HRESULT CheckAndCreateInsideDeltaCache(CATListPtrCATCell * oListPtrCATCellWithInsideDeltaCache=0); // for the entire body
	HRESULT CheckAndCreateInsideDeltaCache(CATFace& iFace); // for a face

	/**
	* GetTessellator 
	*/
	CATCGMTessellator* GetTessellator();
	
private:

  /**
  * Global mode : no delta <-> local = global
  * 0:
  * 1:
  */
  void SetGlobalMode(int iGlobalMode);

	HRESULT RunGlobal();
	CATEdge* GetEdgeFromPolyCurve(const CATIPolyCurve& iPolyCurve);
	CATMapOfEdgeToPolySurfaceVertexLine* GetMapEdgeToPolyLine (CATFace& iFace, CATIPolySurface* iPolySurface);
	HRESULT NewEdgeToPolyLineMap (CATFace& iFace, CATIPolySurface* iPolySurface, CATMapOfEdgeToPolySurfaceVertexLine*& oVertexToPolyPointMap);
	CATVertex* GetVertexFromPolyPoint(const CATIPolyPoint& iPolyPoint);
	CATMapOfVertexToPolySurfaceVertex* GetMapVertexToPolyPoint (CATFace& iFace, CATIPolySurface* iPolySurface);
	HRESULT NewVertexToPolyPointMap (CATFace& iFace, CATIPolySurface* iPolySurface, CATMapOfVertexToPolySurfaceVertex*& oVertexToPolyPointMap);
	HRESULT GetTessellateID_Private (CATCell &iCell, CATCGMTessellateID* &oTessID, int iOwned=0);
  HRESULT CleanSupport(CATListOfCATIPolySurfaceVertexLine * iTessEdgeCurveList);
  HRESULT CleanSupport(CATMapOfEdgeToPolySurfaceVertexLine* ioEdgeMapToPolyCurve);

private:
	CATBody& _Body;
	CATGeoFactory* _Factory;
	CATTessellateParam* _TessellateParam;
	CATCGMTessellateID* _SettingsTessellateID;
	CATTessellateParamCache * _TessParamCache;
	CATTessellateParamCacheContainer* _TessParamCacheContainer;
	CATCGMTessellator* _Tessellator;


	// Maps
	CATMapOfPtrToPtr _MapCellToRefCountedTessellateID;   // Map of a CATCell to its RefCounted CATCGMTessellateID.
  
	CATMapOfPtrToPtr _MapFaceToVertexMap;   // Map of a CATFace to a map of CATVertex to CATIPolyPoint.
	CATMapOfPtrToPtr _MapFaceToMeshLineMap;   // Map of a CATFace to a map of CATEdge to CATIPolySurfaceMeshLine.
	CATMapOfPtrToPtr _MapFaceToPolySurface;  // Map of a CATFace to a CATIPolySurface.
	// For global tessellation.
	friend class CATTessellateBodyBuilderStatic;

	// For Phoenix recording
	friend class CATTessellateBodyStatic_CATechExt;
	friend class CAT3DNCGM;
	CATTessellateBodyStaticObserver * _Observer;

	// Special feature
	int _WorkingModeFromTessellateBodyStatic;
	int _Precision;
	int _GeomVisu; 
	int _GlobalMode; // no delta: local = global
  int _UnableMicronTessellation;

  int _ConstructorWithoutAddRef; // H7W - Nov 2020 : CATICGMTessBodyLink extension of CATBody

	// memory usage
	CATULONGPTR _start_mem;
	CATULONGPTR _start_virmem;
	CATULONGPTR _end_mem;
	CATULONGPTR _end_virmem;
};

//inline HRESULT CATTessellateBodyStatic::GetTessID(CATCell &iCell, CATCGMTessID &oTessID)
//{
//  return S_OK;
//}


#endif /* CATTessellateBodyStatic_H */
