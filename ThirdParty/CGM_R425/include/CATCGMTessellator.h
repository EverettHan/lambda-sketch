// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMTessellator.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// April 2017 TPG simplification for static tessellation
//    20-02-2023  LVL ZATPROJECT
//
//===================================================================

#ifndef CATCGMTessellator_H
#define CATCGMTessellator_H

/**
 * Class defining an operator that builds a static Mesh from an initial NCGM form
 */

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATListPV.h"
#include "CATCGMDeltaCacheAccess.h"
#include "CATTessFaceCacheAccess.h"
#include "CATTessEdgeCacheAccess.h"
#include "CATTessellateParam.h"
#include "CATListOfCATIPolySurfaceVertexLine.h"
#include "CATListOfCATIPolySurfaceVertex.h"
#include "CATListOfCATIPolyCurveVertex.h"
#include "CATTopDefine.h"
#include "CATMapOfPtrToPtr.h"

class CATTessellateParamCacheContainer;
class CATTessellateParamCache;
class CATCGMMemoryManager;

class CATCGMV5Settings;
class CATBody;
class CATDomain;
class CATVolume;
class CATFace;
class CATEdge;
class CATVertex;
class CATCell;

class CATTessellateParam;
class CATGeoFactory;
class CATTessellate;
class CATWTData;
class CATFaceWTData;
class CATListPtrCATCell;

class CATTessBuilder;
class CATIPolySurface;
class CATIPolyCurve;
class CATIPolyPoint;
class CATMapOfEdgeToPolySurfaceVertexLine;
class CATMapOfVertexToPolySurfaceVertex;
class CATMapOfVertexToPolyCurveVertex;

class CATTessFaceInsideDeltaCache;
class CATTessStore;
class CATTessStoreV5;

class CATMathPolyBuffers;
class CATEdgeWTData;

#ifndef CATTessFrameworkCaller
#define CATTessFrameworkCallerExpansed(x) #x
#define CATTessFrameworkCaller(x)  CATTessFrameworkCallerExpansed(x)
#endif

class ExportedByTessellateCommon CATCGMTessellator
{
public : 
  CATCGMTessellator(CATTessellateParam& iTessParam, CATGeoFactory* iGeoFactory);
  virtual ~CATCGMTessellator();

public:  
 
  /**
   * Tessellation in context of a CATBody
   *
   * PreProcessBody: compute internal model
   * 0: cell by cell (good when the Body is activated, upward links available).
   * 1: globally (good when the Body is not activated, upward links not available).
  */
  virtual void SetBody(CATBody* iBody, int iPreProcessBody=1);

  /**
   * Storage
  */
  virtual void SetStorage(CATTessStore * iStorage);

  /**
   * Given a CATFace returns its tessellation as a CATIPolySurface.
   * 
   * The orientation of the returned instance is set according to the orientation of the CATFace with respect
   * to the CATBody.  A set of CATIPolySurface instances returned by this method should therefore all have 
   * the same orientation.
   *
   * @param iFace
   *   The input CATFace whose tessellation is requested.
   * @param oPolySurface
   *   The output instance providing access to the tessellation of the CATFace.
   *   The returned instance must be released by the caller.
   * @param ioEdgeMapToPolyCurve
   *   An instance mapping the edges adjacent to the CATFace to their tessellation in the form of 
   *   a CATIPolySurfaceVertexLine.
   *   This argument may be null.
   * @param ioVertexMapToPolyPoint
   *   An instance mapping the vertices adjacent to the CATFace to their tessellation in the form of 
   *   a CATIPolySurfaceVertex.
   *   This argument may be null.
   * @return
   *   <ul>
   *     <li> S_OK if a CATIPolySurface is returned successfully for this CATFace.
   *     <li> E_FAIL or any other error when a failure occurs.
   *   </ul>
   */
  virtual HRESULT GetPolySurface(CATFace &iFace, CATIPolySurface *&oPolySurface, CATOrientation * oOriPolySurfaceVsFace=0, int iLocalTessellation=0);

  virtual HRESULT GetPolySurface (CATFace &iFace, CATIPolySurface *&oPolySurface,
                                  CATMapOfEdgeToPolySurfaceVertexLine* ioEdgeMapToPolyCurve,
                                  CATMapOfVertexToPolySurfaceVertex* ioVertexMapToPolyPoint, 
																	CATOrientation * oOriPolySurfaceVsFace=0, //give NULL if no need
																	int iLocalTessellation=0); // 1: local tessellation independent of CATBody context

  virtual HRESULT GetPolySurface(CATFace &iFace, CATIPolySurface *&oPolySurface, 
                         CATListOfCATIPolySurfaceVertexLine* ioTessEdgeCurveList,
                         CATListOfCATIPolySurfaceVertex* ioTessFacePointList, 
												 CATOrientation * oOriPolySurfaceVsFace=0, //give NULL if no need
												 int iLocalTessellation=0); // 1: local tessellation independent of CATBody context

  virtual CATULONG32 GetPolySurfaceIsoVertexLines(CATFace &iFace, CATIPolySurface &iPolySurface, CATIPolySurfaceVertexLine** &ioIsoVertexLinesList); // ioIsoVertexLinesList to be deleted by the caller. 

  virtual HRESULT GetDeltaStatus(CATFace &iFace, int& oNbDelta, CATListPtrCATCell * oListOfDeltaCells = 0, CATListOfDouble * oListOfDeltaParams = 0); // oNbDelta: -1: unknown; 0: no delta; >0: nb delta
  virtual HRESULT GetDeltaStatusFromNeighborDeltaCache(CATFace &iFace, int& oNbDelta, CATListPtrCATCell * oListOfDeltaCells = 0, CATListOfDouble * oListOfDeltaParams = 0); // oNbDelta: -1: unknown; 0: no delta; >0: nb delta
  
  virtual HRESULT GetFaceVsMeshOrientation(CATFace &iFace, int& oOrientation);
  virtual HRESULT GetMeshVsTessCacheOrientation(CATFace &iFace, int& oOrientation);
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
   * @return
   *   <ul>
   *     <li> S_OK if a CATIPolyCurve is returned successfully for this CATEdge.
   *     <li> E_FAIL or any other error when a failure occurs.
   *   </ul>
   */
  virtual HRESULT GetPolyCurve(CATEdge &iEdge, CATIPolyCurve *&oPolyCurve, CATOrientation * oOriPolyCurveVsEdge=0,
											 int iLocalTessellation=0); // 1: local tessellation independent of CATBody context

  virtual HRESULT GetPolyCurve (CATEdge &iEdge, CATIPolyCurve *&oPolyCurve,
                                CATMapOfVertexToPolyCurveVertex* ioVertexMapToPolyPoint, CATOrientation * oOriPolyCurveVsEdge=0,
																int iLocalTessellation=0); // 1: local tessellation independent of CATBody context

	//
  virtual HRESULT GetPolyCurve(CATEdge &iEdge, CATIPolyCurve *&oPolyCurve,
                       CATListOfCATIPolyCurveVertex* ioTessEdgeVertexPointList, CATOrientation * oOriPolyCurveVsEdge=0, //give NULL if no need
											 int iLocalTessellation=0); // 1: local tessellation independent of CATBody context

  virtual HRESULT GetDeltaStatus(CATEdge &iEdge, int& oNbDelta, CATListPtrCATCell * oListOfDeltaCells = 0, CATListOfDouble * oListOfDeltaParams = 0); // oNbDelta: -1: unknown; 0: no delta; >0: nb delta
  virtual HRESULT GetDeltaStatusFromNeighborDeltaCache(CATEdge &iEdge, int& oNbDelta, CATListPtrCATCell * oListOfDeltaCells = 0, CATListOfDouble * oListOfDeltaParams = 0); // oNbDelta: -1: unknown; 0: no delta; >0: nb delta

  /**
   * Given a CATVertex returns its tessellation as a CATIPolyPoint.
   */
  virtual HRESULT GetPolyPoint(CATVertex &iVertex, CATIPolyPoint *&oPolyPoint);

  void DumpMap(CATMapOfPtrToPtr* iFastPassFaceAccess);
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
   *     <li> S_OK if a CATMathPolyBuffers is returned successfully for this CATFace.
   *     <li> E_FAIL or any other error when a failure occurs.
   *   </ul>
   */
  virtual HRESULT GetPolyBuffers(CATFace& iFace, const CATMathPolyBuffers* &oFacePolyBuffers, CATOrientation& oOriPolyBuffersVsFace,
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
   *     <li> S_OK if a CATMathPolyBuffers is returned successfully for this CATEdge.
   *     <li> E_FAIL or any other error when a failure occurs.
   *   </ul>
   */
  virtual HRESULT GetEdgePolyBuffers(CATEdge &iEdge, const CATMathPolyBuffers* &oEdgePolyBuffers, CATOrientation& oOriBuffersVsEdge,
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
  virtual HRESULT GetVertexCoordinates(CATVertex &iVertex, double* &oCoordinates);
  virtual HRESULT GetVertexCoordinates(CATVertex &iVertex, float* &oCoordinates);

  /**
  * working mode
  * iMode: 
  * 0: cpu +++ memory + (default).
  * 1: cpu ++  memory ++.
  * 2: cpu +   memory +++.
  * 3: cpu +++ memory + ().
  */
  virtual void SetWorkingMode(int iMode);

  /**
  * Cache format
  * 0: float vertex position.
  * 1: double vertex position.
  */
  virtual void SetCacheFormat(int iCacheFormat);

  /**
  * GeomVisu
  * 0: 
  * 1: 
  */
  virtual void SetGeomVisu(int iGeomVisu);
  
  /**
  * Global mode : no delta <-> local = global
  * 0: 
  * 1: 
  */
  void SetGlobalMode(int iGlobalMode);

  /**
* Micron Tessellation
* 0:
* 1:
*/
  void SetMicronTessellation(int iUnableMicronTessellation);


  /*
* Renvoie la liste des CATCell bordant l'Edge
*/
  HRESULT GetAllCells(CATEdge& iEdge, CATListPtrCATCell& iofaces);

  void SetGMPolyBodyContext(int iGMPolyBodyContext);

public:  
 
  /**
  * Updates the Cache, Body, should be called on the same body
  * iListPtrCATCell: input list of CATCell, if NULL process the entire Body
  * iTypeCache: 0 process on empty DataCache; 1 process on empty DeltaCache
  */
  virtual HRESULT UpdateCache(CATBody& iBody, CATListPtrCATCell * iListPtrCATCell = 0, int iTypeCache = 0, int iSynchronizeFaces = 0);

  /**
  * Updates the DeltaCache, Body, should be called on the same body
  * iListPtrCATCell: input list of CATCell, if NULL process the entire Body
  */
  virtual HRESULT UpdateDeltaCache(CATBody& iBody, CATListPtrCATCell * oListPtrCATCell=0);
  virtual HRESULT CheckAndCreateDeltaCache(CATBody& iBody, CATListPtrCATCell * oListPtrCATCell=0);
  
  /**
  * Updates the face cache (face local tessellation), Face(+Countour Edges), should be called on the same body
  */
  virtual HRESULT UpdateFaceCache(CATFace& iFace);
  /**
  * Updates the face inside delta cache (delta mesh provided by the face itself to the neighbor)
	* inside delta cache is used to compute the TessID of the neighbor face
	* iOption:
	* 0 : check cache, if no cache compute delta, then create cache only if delta exist
	* 1 : check cache, if no cache create a cache with no delta (usefull while unstreaming cache from disk)
	* 2 : check cache, if no cache compute delta, then create cache whatever delta exist or not (usefull in part update context)
  */
  virtual HRESULT UpdateFaceInsideDeltaCache(CATFace& iFace, int iOption=0);
    
  /**
  * Updates the Cache, Edge(Wire), should be called on the same body
  */
  virtual HRESULT UpdateWireEdgeCache(CATEdge& iWireEdge);

	/**
  * Get the CellDataCache
  */
  virtual HRESULT GetCellDataCache(CATCell& iCell, const CATTessDataCache*& oCellDataCache);

public:
  /**
  * Clear Cache
  */
  //Body
  virtual HRESULT ClearBodyCache(CATBody& iBody);

  //Face
  virtual HRESULT ClearFaceCache(CATFace& iFace);
  virtual HRESULT ClearFaceDeltaCache(CATFace& iFace);
  
  //Edge
  virtual HRESULT ClearEdgeCache(CATEdge& iEdge);

public:
  /**
  * AddRef CacheItem
  */
  virtual HRESULT AddRefCacheItem(CATCell& iCell);
  virtual HRESULT AddRefCacheItem(CATBody& iBody);

  /**
  * Release CacheItem
  */
  virtual HRESULT ReleaseCacheItem(CATCell& iCell, CATBoolean iRemoveNonPersistantDeltaCache=FALSE);
  virtual HRESULT ReleaseCacheItem(CATBody& iBody, CATBoolean iRemoveNonPersistantDeltaCache=FALSE);

public:
  /**
  * Set the Cache persistent, Body
  */
  virtual HRESULT SetCachePersistent(CATBody& iBody);
  virtual HRESULT SetDeltaCachePersistent(CATBody& iBody, CATListPtrCATCell * oListPtrCATCell=0);

  /**
  * Set the Cache persistent, Face(+Countour Edges)
  */
  virtual HRESULT SetFaceCachePersistent(CATFace& iFace);
  virtual HRESULT SetFaceDeltaCachePersistent(CATFace& iFace);
    
  /**
  * Set the Cache persistent, Edge(Wire)
  */
  virtual HRESULT SetWireEdgeCachePersistent(CATEdge& iWireEdge);

public:
  //check
  /**
  * Checks the Cache, Body
  */
  virtual HRESULT CheckCache(CATBody& iBody);
  virtual HRESULT CheckDeltaCache(CATBody& iBody, CATListPtrCATCell * oListPtrCATCell=0);

  /**
  * Checks the Cache, Face
  */
  virtual HRESULT CheckFaceCache(CATFace& iFace);
  virtual HRESULT CheckFaceDeltaCache(CATFace& iFace);
    
  /**
  * Checks the Cache, Edge(Wire)
  */
  virtual HRESULT CheckWireEdgeCache(CATEdge& iWireEdge);

public:
  virtual void EmptyLocalDataTessellation(CATFace &iFace);
  virtual void EmptyLocalDataTessellation(CATEdge &iEdge);

  // NHD
  virtual HRESULT FillVertexToPolyPointMap(CATFace* iFace, CATIPolySurface* iPolySurface, CATMapOfVertexToPolySurfaceVertex* ioVertexToPolyPoint);
  virtual HRESULT FillEdgeToPolyLineMap(CATFace* iFace, CATIPolySurface* iPolySurface, CATMapOfEdgeToPolySurfaceVertexLine* ioVertexToPolyPoint);
  HRESULT GetOneRingFace(CATFace& iFace, CATListPtrCATCell& ioListPtrCATCell) const;

private :


//#ifdef CATTESSDEBUG
  void DisplayDeltaCache(CATFace& iFace, CATTessFaceInsideDeltaCache* iFaceDeltaCache) const;
//#endif

  CATCGMTessellator(const CATCGMTessellator &);
  void operator = (const CATCGMTessellator &);

   /**
  * Updates the Cache, Domain
  */
  HRESULT UpdateCache(CATDomain& iDomain);
  
  /**
  * Updates the Cache, Volume
  */
  HRESULT UpdateCache(CATVolume& iVolume);

  /**
  * Runs operator Local Mode
  */
  HRESULT Run(CATFace& iFace, const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_));

  HRESULT Run(CATEdge& iWireEdge, const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_));

  /**
  * Runs operator Global Mode
  * iTypeCache: 0 process on empty DataCache; 1 process on empty DeltaCache
  */
  HRESULT Run(CATBody& iBody, CATListPtrCATCell * iListPtrCATCell = 0, int iTypeCache = 0, const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_), int iSynchronizeFaces = 0);

  /**
  * Clear cache
  */
  HRESULT ClearCache(CATCell& iCell);

  CATEdge* GetEdgeFromPolyCurve(const CATIPolyCurve& iPolyCurve);
  CATVertex* GetVertexFromPolyPoint(const CATIPolyPoint& iPolyPoint);

  HRESULT GetEdgeWTData(CATEdge &iEdge, CATEdgeWTData* &oEdgeWTData, CATOrientation * oOriPolyCurveVsEdge=0, //give NULL if no need
						int iLocalTessellation=0); // 1: local tessellation independent of CATBody context, oEdgeWTData should be deleted
  
private:
  enum Command_T
  {
    Update=0,
    SetPersistent,
    Check,
	Clear_Cache,
	AddRef_Cache,
	Release_Cache,
    CheckAndCreateDelta, // check cache, if no cache create a cache with no delta (usefull while unstreaming cache from disk)
    UpdateDelta, // check cache, if no cache compute delta, then create cache only if delta exist
    UpdateAndCreateDelta, // check cache, if no cache compute delta, then create cache whatever delta exist or not (usefull in part update context)
    SetPersistentDelta,
    CheckDelta,
	Clear_DeltaCache,
	AddRef_DeltaCache,
	Release_DeltaCache
  };
  HRESULT ProcessBody(CATBody& iBody,Command_T iCommand,CATListPtrCATCell * oListPtrCATCell = 0);
  HRESULT ProcessDomain(CATDomain& iDomain,Command_T iCommand,CATListPtrCATCell * oListPtrCATCell = 0);
  HRESULT ProcessVolume(CATVolume& iVolume,Command_T iCommand,CATListPtrCATCell * oListPtrCATCell = 0);
  HRESULT ProcessFace(CATFace& iFace,Command_T iCommand);
  HRESULT ProcessWireEdge(CATEdge& iWireEdge,Command_T iCommand);

  /*
  * Renvoie la liste des CATCell bordant la Face
  */
  void GetAllCells(CATFace & iFace, CATListPtrCATCell & iofaceEdges);

  HRESULT ComputeFaceWTData(CATFace &iFace, CATFaceWTData* &ofaceWTData, int iLocalTessellation = 0);

  /**
  * Updates the face cache (face local tessellation), Face(+Countour Edges), should be called on the same body
	*
	* also updates the InsideDeltaCache
	* iOptionForInsideDeltaCache:
	* 0 : check cache, if no cache compute delta, then create cache only if delta exist
	* 1 : check cache, if no cache create a cache with no delta (usefull while unstreaming cache from disk)
	* 2 : check cache, if no cache compute delta, then create cache whatever delta exist or not (usefull in part update context)
  */
  HRESULT UpdateFaceCache(CATFace& iFace, int iOptionForInsideDeltaCache);
  /**
  * AddFaceInsideDeltaCache (delta mesh provided by the face itself to the neighbor)
	* inside delta cache is used to compute the TessID of the neighbor face
	* iOption:
	* 0 : compute delta, then create cache only if delta exist
	* 2 : compute delta, then create cache whatever delta exist or not (usefull in part update context)
  */
  HRESULT AddFaceInsideDeltaCache(CATFace& iFace, int iOption=0);

private:
  // Manager for the memory
  CATTessellateParamCacheContainer* _TessParamCacheContainer;
  CATCGMMemoryManager* _MemoryManager;

  CATTessellateParam _TessParam;
  CATTessellateParamCache* _TessParamCache;
  CATCGMV5Settings* _TessSettings;
  CATTessellate* _Tessellator;
  CATWTData* _WTData;
  CATCGMDeltaCacheAccess _DeltaCacheAccess;
  CATTessFaceCacheAccess _FaceCacheAccess;
  CATTessEdgeCacheAccess _EdgeCacheAccess;
  int _WorkingModeFromCGMTessellator;
  int _CacheFormat;
  int _GeomVisu;
  int _GlobalMode; // no delta: local = global
  int _UnableMicronTessellation;
  CATTessBuilder* _TessBuilder;
  CATBody* _Body;
  CATBoolean _PreProcessBody;
  int _GMPolyBodyContext;

  CATTessStore * _Storage;
  CATMapOfPtrToPtr _AddFaceInsideDeltaCache;
  CATMapOfPtrToPtr _UpdateFaceInsideDeltaCache;
  CATMapOfPtrToPtr _ComputeFaceWTData;
};

#endif
