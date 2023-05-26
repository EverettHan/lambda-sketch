/* -*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES	1998
//=============================================================================
// CATTessStore
/**
  * This object stores the results of the tessellation.
  * It has to be overloaded by each application,
  * providing a convenient way to reformat the data for any need.
  * The default implementation does nothing: you only have to overload the methods
  * you use really.
  */
//=============================================================================
//
// Feb. 98   Creation                                   A. Collet
// Mar. 99   Ajout d'un StoreFace pour HLR V4           H. Kabla
// Jan. 2003 TPD On cree un "CATTessellateV4" pour mailler les elements V4
// Mai  2003 TPD On garde les coordonnees des points des faces dans "CATTessSToreDisplay " pour les edges
//               en fonction des faces 
// Mars 2004 TPD On chaine les Points Bords de faces entre eux par les CATTessPoints correspondants
// Oct. 2004 TPD Nouvelle sortie : "Polyedre"
// Avr. 2006 TPD Nouvelle methode "SetFaceKo". On rajoute NbFaceKo dans le Dump
// Aug. 2007 HCN Paramètre CATTessEdgeIter* pour StoreEdge(CATEdge*, CATBoolean, CATLONG32, float*);
// Nov. 2007 MNA Je rajoute une nouvelle methode StoreEdge et je reviens a la signature precedente:;
// Mai  2012 WMN WhichCellsDoYouNeed pour bypasser DoYouNeed (optim pour CATIALiveShape) (phase 2 uniquement)
//=============================================================================

#ifndef CATTessStore_H
#define CATTessStore_H

#include "CATIAV5Level.h"

#include <stdlib.h>

#include <stddef.h>
#include "CATCGMNewArray.h"
#include "CATDataType.h"
/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

#include "TessAPI.h"
#include "CATTessConstant.h"
#include "CATMathDef.h"
#include "CATTopDef.h"

#ifdef CATIAR214
#include "CATListOfCATCells.h"
#endif

class CATTessMemoryManager;

class CATMathPoint;
class CATMathSetOfPointsND;
class CATTessIsoLine;
class CATVertex;
class CATEdge;
class CATFace;
class CATCell;
class CATSurface;
class CATCurve;

class CATTessEdgeIter;
class CATTessEdgeIterV4;
class CATTessFanIter;
class CATTessFanIterV4;
class CATTessIsoIter;
class CATTessOutHlr;
class CATTessPointIter;
class CATTessPointIterV4;
class CATTessPointPolyIter;
class CATTessPolyIter;
class CATTessPolyIterV4;
class CATTessStripeIter;
class CATTessStripeIterV4;
class CATTessTrianIter;
class CATTessTrianIterV4;
class CATTessVertexIter;
class CATTessFaceIncrInfo;
class CATTessEdgeIncrInfo;
class CATTessPointOnEdgeCache;

//-----------------------------------------------------------------------------
class ExportedByTessAPI CATTessStore
{
public:
//=============================================================================
//- Constructor
//=============================================================================

  CATTessStore();

//=============================================================================
//- Destructor
//=============================================================================
  virtual ~CATTessStore();

//=============================================================================
//- Methods
//=============================================================================
  /** For partial Tessellation of a Body: return TRUE for the Cells you want to
   * be tessellated. The default implementation returns always TRUE.
   */
  virtual CATBoolean DoYouNeed(CATCell * iCell);

#ifdef CATIAR214
  /** For partial Tessellation of a Body: fill the list with the highest-level
   * cells you want to be tessellated.
   *
   * Lower-level cells will automatically be tessellated for each provided cell,
   * such as edges and vertices for each face from the list.
   *
   * !!! This is an ALTERNATIVE to the DoYouNeed protocol !!!
   *
   * Default implementation does nothing. DoYouNeed is used instead.
   * If the list is filled with cells, DoYouNeed will not be used.
   *
   * Only the cells in the list and their lower-level cells will be tessellated.
   */
  virtual void WhichCellsDoYouNeed(ListPOfCATCell & oListOfCATCells);


  /** Cost prediction for the tessellation of each face in the list iListOfCATCells.
   *  The returned value is the maximum value of the list oListOfCosts
   *  The output list oListOfCosts contains integer values chosen as follows :
   *  !!! TO BE DEFINED PRECISELY !!!
   *
   */
  virtual int CombienCaCoute(ListPOfCATCell* iListOfCATCells,double iSAG,CATListOfInt & oListOfCosts);

#endif

  /** Sets the way curve points should be output
   */
  void AskForCurveDataAsPoints();
  void AskForCurveDataAsDoubles();
  void AskForCurveDataAsFloats();
  void AskForCurveDataAsFloatsUV();
  void AskForCurveDataAsPointsFace();
  // Si il n'y a pas de face, on rend les resultats en fonction :
  //       : AsPoints
  //     P : AsPoints
  //     D : AsDoubles
  //     F : AsFloats
  void AskForCurveDataAsPointsFaceP();
  void AskForCurveDataAsPointsFaceD();
  void AskForCurveDataAsPointsFaceF();
  CATTessConstant::CurveOutputFormat HowShouldIOutputCurveData();

  /** Sets the way vertex should be output
   */
  void AskForVertexDataAsPoints();
  void AskForVertexDataAsPointsFaceP();
  void AskForVertexDataAsPointsFaceM();
  // Si il n'y a pas de face, on rend les resultats en fonction :
  //      P : AsPoec
  //      M : AsPoints
  void AskForVertexDataAsPoec();
  CATTessConstant::VertexOutputFormat HowShouldIOutputVertexData();

  /** Allocates and return storage for data transfer in StoreEdge, StoreCurve
   */
  void * GiveBuffer(size_t iSizeInBytes);

  /**
   * Stores Vertex Geometry
   * iNew tells if this vertex was already discretized or not
   * if not no geometry is provided: you have already stored it somewhere
   */
  virtual void StoreVertex(CATVertex    * iVertex,
			   CATMathPoint * iMathPoint,
			   CATBoolean     iNew, 
		           CATFace      * iBoundedFace,
		           CATLONG32      iPointNumberInFace);
			    
  virtual void StoreVertex(CATVertex         * iVertex,
			   CATBoolean          iNew, 
			   CATTessVertexIter * iVertexIter);
			    
  /**
   * Stores Edge Geometry
   * iNew tells if this edge was already discretized or not
   * if not no geometry is provided: you have already stored it somewhere
   */
  virtual void StoreEdge(CATEdge               * iEdge,
		         CATBoolean              iNew,
		         CATLONG32               iNumberOfPoints,
		         CATMathSetOfPointsND  * iMathPoints,
		         CATMathSetOfPointsND  * iCrvParams, 
		         CATFace               * iBoundedFace,
		         CATLONG32             * iPointNumberInFace);
                                
  virtual void StoreEdge(CATEdge               * iEdge,
		         CATBoolean              iNew,
		         CATLONG32               iNumberOfPoints,
		         CATMathSetOfPointsND  * iMathPoints,
		         CATMathSetOfPointsND  * iCrvParams, 
		         CATFace               * iBoundedFace,
		         CATLONG32             * iPointNumberInFace,
             CATTessEdgeIncrInfo   * iIncrInfo);
  
  virtual void StoreEdge(CATEdge               * iEdge,
                         CATBoolean              iNew,
                         CATLONG32               iNumberOfPoints,
                         double                * iPointData);

  virtual void StoreEdge(CATEdge               * iEdge,
                         CATBoolean              iNew,
                         CATLONG32               iNumberOfPoints,
                         double                * iPointData,
                         CATTessEdgeIncrInfo   * iIncrInfo);

  virtual void StoreEdge(CATEdge               * iEdge,
                         CATBoolean              iNew,
                         CATLONG32               iNumberOfPoints,
                         float                 * iPointData);

  virtual void StoreEdge(CATEdge               * iEdge,
                         CATBoolean              iNew,
                         CATLONG32               iNumberOfPoints,
                         float                 * iPointData,
                         CATTessEdgeIncrInfo   * iIncrInfo);


  virtual void StoreEdge(CATEdge               * iEdge,
                         CATBoolean              iNew,
                         CATLONG32               iNumberOfPoints,
                         float                 * iPointData,
                         CATTessEdgeIter       * iEdgeIter);

  virtual void StoreEdge(CATEdge               * iEdge,
                         CATBoolean              iNew,
                         CATLONG32               iNumberOfPoints,
                         float                 * iPointData,
                         CATTessEdgeIter       * iEdgeIter,
                         CATTessEdgeIncrInfo   * iIncrInfo);

  virtual void StoreEdge(CATEdge               * iEdge,
			 CATBoolean              iNew,
			 CATTessEdgeIter       * iEdgeIter);

  virtual void StoreEdge(CATEdge               * iEdge,
			 CATBoolean              iNew,
			 CATTessEdgeIter       * iEdgeIter,
       CATTessEdgeIncrInfo   * iIncrInfo);

  virtual void StoreEdge(int                    iJeleEdge,
			 CATBoolean             iNew,
			 CATTessEdgeIterV4    * iEdgeIter);

  virtual void StoreEdge(int                     iJeleEdge,
			 CATBoolean              iNew,
			 CATLONG32               iNumberOfPoints,
			 CATMathSetOfPointsND  * iMathPoints,
			 CATMathSetOfPointsND  * iCrvParams, 
			 CATFace               * iBoundedFace,
			 CATLONG32             * iPointNumberInFace);

// Stores curve geometry
  virtual void StoreCurve(CATCurve              * iCurve,
                          CATLONG32               iNumberOfPoints,
                          CATMathSetOfPointsND  * iMathPoints,
                          CATMathSetOfPointsND  * iCrvParams);
  
  virtual void StoreCurve(CATCurve              * iCurve,
                          CATLONG32               iNumberOfPoints,
                          double                * iPointData);

  virtual void StoreCurve(CATCurve              * iCurve,
                          CATLONG32               iNumberOfPoints,
                          float                 * iPointData);
                                
  // Stores Surface Geometry (for debug purpose only)                                
  virtual void StoreSurface(CATTessIsoLine * iTessIsopar, CATSurface* iSurface);

  /**
   * Stores Face Geometry
   * iNew tells if this face was already discretized or not
   * if not no geometry is provided: you have already stored it somewhere.
   * iVolume tells if the face belongs to a closed shell or not
   * iPlane  tells if the face is plane or not
   * iSide is the orientation of the underlying geometry of the Face in the shell
   * The point iterator allows you to scan the points and retrieve x,y,z,u,v and normal
   */
  // Sorties VISU
  virtual void StoreFace(CATFace            * iFace,
			 CATBoolean           iNew,
			 CATBoolean           iVolume,
			 CATSide              iSide,
			 CATBoolean           iPlane,
			 CATLONG32            iNumberOfPoints,
		         CATTessPointIter   * iPoints,
			 CATLONG32            iNumberOfStrips,
			 CATTessStripeIter  * iStrips,
			 CATLONG32            iNumberOfFans,
			 CATTessFanIter     * iFans,
			 CATLONG32            iNumberOfPolygons,
			 CATTessPolyIter    * iPolygons,
			 CATLONG32            iNumberOfTriangles,
			 CATTessTrianIter   * iTriangles);

  virtual void StoreFace(CATFace            * iFace,
			 CATBoolean           iNew,
			 CATBoolean           iVolume,
			 CATSide              iSide,
			 CATBoolean           iPlane,
			 CATLONG32            iNumberOfPoints,
		         CATTessPointIter   * iPoints,
			 CATLONG32            iNumberOfStrips,
			 CATTessStripeIter  * iStrips,
			 CATLONG32            iNumberOfFans,
			 CATTessFanIter     * iFans,
			 CATLONG32            iNumberOfPolygons,
			 CATTessPolyIter    * iPolygons,
			 CATLONG32            iNumberOfTriangles,
			 CATTessTrianIter   * iTriangles,
       CATTessFaceIncrInfo* iIncrInfo);

  virtual void StoreFace(CATFace            * iFace,
			 CATBoolean           iNew,
			 CATBoolean           iVolume,
			 CATSide              iSide,
			 CATBoolean           iPlane,
			 CATLONG32            iNumberOfPoints,
		         CATTessPointIter   * iPoints,
			 CATLONG32            iNumberOfStrips,
			 CATTessStripeIter  * iStrips,
			 CATLONG32            iNumberOfFans,
			 CATTessFanIter     * iFans,
			 CATLONG32            iNumberOfPolygons,
			 CATTessPolyIter    * iPolygons,
			 CATLONG32            iNumberOfTriangles,
			 CATTessTrianIter   * iTriangles,
			 CATLONG32            iNumberOfIsopares,
			 CATTessIsoIter     * iIsopares );

  virtual void StoreFace(CATFace            * iFace,
			 CATBoolean           iNew,
			 CATBoolean           iVolume,
			 CATSide              iSide,
			 CATBoolean           iPlane,
			 CATLONG32            iNumberOfPoints,
		         CATTessPointIter   * iPoints,
			 CATLONG32            iNumberOfStrips,
			 CATTessStripeIter  * iStrips,
			 CATLONG32            iNumberOfFans,
			 CATTessFanIter     * iFans,
			 CATLONG32            iNumberOfPolygons,
			 CATTessPolyIter    * iPolygons,
			 CATLONG32            iNumberOfTriangles,
			 CATTessTrianIter   * iTriangles,
			 CATLONG32            iNumberOfIsopares,
			 CATTessIsoIter     * iIsopares,
       CATTessFaceIncrInfo* iIncrInfo);

  virtual void StoreFace(CATFace            * iFace,
			 CATBoolean           iNew,
			 CATBoolean           iVolume,
			 CATSide              iSide,
			 CATBoolean           iPlane,
			 CATLONG32            iNumberOfPoints,
		   CATTessPointIter   * iPoints,
			 CATLONG32            iNumberOfIsopares,
			 CATTessIsoIter     * iIsopares );

  virtual void StoreFace(CATFace            * iFace,
			 CATBoolean           iNew,
			 CATBoolean           iVolume,
			 CATSide              iSide,
			 CATBoolean           iPlane,
			 CATLONG32            iNumberOfPoints,
		   CATTessPointIter   * iPoints,
			 CATLONG32            iNumberOfIsopares,
			 CATTessIsoIter     * iIsopares,
       CATTessFaceIncrInfo* iIncrInfo);

  // Sorties HLR
  virtual void StoreFace(CATFace            * iFace,
			 CATTessOutHlr      * iOutHlr);

  // Sorties Poly
  virtual void StoreFace(CATFace            * iFace,
			 CATBoolean           iNew,
			 CATBoolean           iVolume,
			 CATSide              iSide,
			 CATBoolean           iPlane,
			 CATLONG32            iNumberOfStrips,
			 CATTessStripeIter  * iStrips,
			 CATLONG32            iNumberOfFans,
			 CATTessFanIter     * iFans,
			 CATLONG32            iNumberOfPolygons,
			 CATTessPolyIter    * iPolygons,
			 CATLONG32            iNumberOfTriangles,
			 CATTessTrianIter   * iTriangles);

  virtual void StoreFace(CATFace            * iFace,
			 CATBoolean           iNew,
			 CATBoolean           iVolume,
			 CATSide              iSide,
			 CATBoolean           iPlane,
			 CATLONG32            iNumberOfStrips,
			 CATTessStripeIter  * iStrips,
			 CATLONG32            iNumberOfFans,
			 CATTessFanIter     * iFans,
			 CATLONG32            iNumberOfPolygons,
			 CATTessPolyIter    * iPolygons,
			 CATLONG32            iNumberOfTriangles,
			 CATTessTrianIter   * iTriangles,
       CATTessFaceIncrInfo* iIncrInfo);


  virtual void StoreFace(CATFace * iFace,
                        CATBoolean iNew,
                        CATBoolean isVolume,
                        CATSide     iSide,
                        CATBoolean  isPlane,
                        CATLONG32 iNbPoints,
                        double * iPoints,
                        double *iNormals, 
                        CATLONG32 iNbTriangles,
                        int * iTriangles);

  // Sorties VISU V4 
  virtual void StoreFace(int                    iJeleFace,
			 CATBoolean             iNew,
			 CATBoolean             iVolume,
			 CATSide                iSide,
			 CATBoolean             iPlane,
			 CATLONG32              iNumberOfPoints,
			 CATTessPointIterV4   * iPoints,
			 CATLONG32              iNumberOfStrips,
			 CATTessStripeIterV4  * iStrips,
			 CATLONG32              iNumberOfFans,
			 CATTessFanIterV4     * iFans,
			 CATLONG32              iNumberOfPolygons,
			 CATTessPolyIterV4    * iPolygons,
			 CATLONG32              iNumberOfTriangles,
			 CATTessTrianIterV4   * iTriangles );

  // Sorties Poly
  virtual void StorePoint(CATTessPointPolyIter *  iPointPolyIter,
			  CATLONG32             & oNuPoint       );

    // Sorties Poly
  virtual void StorePoint(CATTessPointPolyIter *  iPointPolyIter,CATFace * iFace,
			  CATLONG32             & oNuPoint       );

  /**
   * Use local tessellation of cells
   */
  virtual int UseLocalTessellation();

  /**
   * GeomVisu
   */
  virtual int GeomVisu();

  /**
   * Provide existing tessellation to avoid computation
   *
   * Set Edge tessellation
   */
  virtual CATBoolean IsCacheAvailable(CATEdge * iEdge);
  virtual void SetEdge(CATEdge * iEdge,
                       CATLONG32 & oNbPoints,
                       double  * & oPoints,
                       double  * & oCrvParams,
                       CATTessPointOnEdgeCache * & oFirstPointOnEdgeCache);

  /**
   * Retrieve tessellation
   *
   * Get Edge tessellation
   */
  virtual void GetEdge(CATEdge * iEdge,
                       CATLONG32 iNbPoints,
                       const double * iPoints,
                       const double * iCrvParams,
                       CATTessPointOnEdgeCache * iFirstPointOnEdgeCache);

  // la face n'est pas maillee
  virtual 
#ifndef __ibmxl__
inline 
#endif 
  void SetFaceKo();

  // GetMemoryManagerName
  virtual const char * GetMemoryManagerName();

  CATTessConstant::CurveOutputFormat  _CurveOutputFormat;
  CATTessConstant::VertexOutputFormat _VertexOutputFormat;

private:
  CATTessMemoryManager * _TessMemoryManager;
  void                 * _OutputBuffer;
  int                    _OutputBufferSize;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
#ifndef __ibmxl__
inline 
#endif 
  void CATTessStore::SetFaceKo()
{
}

#endif
