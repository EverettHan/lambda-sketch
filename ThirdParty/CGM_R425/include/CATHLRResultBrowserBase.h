/* -*-C++-*-*/
#ifndef CATHLRResultBrowserBase_H
#define CATHLRResultBrowserBase_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2001
//
// CATHLRResultBrowserBase 
//
// DESCRIPTION :
/**
 * Object to browse the results of the HLR.
 * <BR> The result is obtained using the Id of the objects that has been returned
 * by the CATHLRComputer when using the method AddObject().
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Nov. 2001 LAT  Creation
//
//=============================================================================

// For Windows NT
#include "HLRModele.h"

// Other includes
#include "CATHLRConstant.h"
#include "CATHLRDiscretizer.h"
#include "CATHLRBodyId.h"
#include "CATMathPoint.h"
#include "CATListPV.h"
#include "CATMapOfIntToInt.h"

class CATCrvParam;
class CATEdge;
class CATFace;
class CATGeoFactory;
class CATTolerance;

class CATHLRContainerEntity;
class CATHLRCurve;
class CATHLREdge;
class CATHLRFace;
class CATHLRGeometry2DFactory;
class CATHLRPlanarProjection;
class CATHLRResultEdge;
class CATHLRResultEntity;
class CATHLRResultPart;
class CATPCurve; 
class CATPlane;
class CATHLRObjectLinker;
class CATHLRMemoryManager;
class CATSoftwareConfiguration;
class CATHLRTemporaryContainer;

class ExportedByHLRModele CATHLRResultBrowserBase
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor
 */
  CATHLRResultBrowserBase(CATHLRContainerEntity &iContainerEntity, const CATTolerance & iCtxTol, CATSoftwareConfiguration * iConfig = 0);



//=============================================================================
// METHODS
//=============================================================================
/** Sets the SoftwareConfiguration for versionning
 */
  virtual void SetCGMSoftwareConfiguration(CATSoftwareConfiguration * iConfig);

  // Drives the behavior of the output partition of an input edge
  // iPolyhedralPartOK equal to TRUE means that output polyhedral parts are authorized
  // -> Please keep in mind that ProjectPart() on a polyhedral part leads to a C2 interpolation (PSpline etc...)
  // iPolyhedralPartOK equal to FALSE (default value) leads to split the curve into bars and then to get a set of PLines as projection result
  inline void SetPolyhedralResultPartMode(CATBoolean iPolyhedralPartOK);

/** Returns 1 if the result has been computed through an 'exact' algorithm,
 *  Returns 0 if the result has been computed through the V4 algorithm
 */
  virtual int IsExact();

/** Selects the mode when the output is in the projection view.
 */
  virtual void SetProjectionSpaceMode();

/** Selects the mode when the output is in the original space ( default mode).
 */
  virtual void SetOriginalSpaceMode();

/** Selects only the results of a body, defined by its identifier CATHLRId.
 */
  virtual void SelectObject(CATHLRBodyId iObjectId);

/** Selects all the results.
 */
  virtual void SelectAll();

/** Sets the view parameters : the orserver is the position of the eyes of the one
 * that looks at the scene, the target defines the plane of projection, as being
 * orthogonal to the line that passes by the observer and the target. The third
 * parameter sets the Type of projection ( Conical of Cylindrical).
 * These informations are required for conical projection
 */
  virtual void SetViewParameters(const CATMathPoint             & iObserver,
                                 const CATMathPoint             & iTarget, 
                                 CATHLRConstant::TypeProjection   iTypeProjection);


  inline CATHLRBodyId GetSelectedBodyID();

  inline const CATTolerance & GetSceneTolerance();


/** Clashes handlers
 *
 */

  void SetEntityEntityClashPoints(const CATListOfDouble & iClashPoints, const CATListOfInt & iVisibility);

  void GetEntityEntityClashPoints(CATListOfDouble& oClashPoints, CATListOfInt &oVisibility);

  int GetEntityEntityClashCount();

  void SetSilhEntityClashPoints(const CATListOfDouble & iClashPoints, const CATListOfInt & iVisibility);

  void GetSilhEntityClashPoints(CATListOfDouble& oClashPoints, CATListOfInt &oVisibility);

  int GetSilhEntityClashCount();

  void AddUnknownVisibilityClashPoints(const CATListOfDouble & iClashPoints);

  void GetUnknownVisibilityClashPoints(CATListOfDouble& oClashPoints);

  int GetUnknownVisibilityClashCount();

/** Gets the counts of edges in the selected result.
 */
  virtual CATLONG32 GetCountEdges() const;

/** Go to the next edge of the selected ones. It returns 0 if there is no more edge,
 * 1 else.
 */
  virtual CATLONG32 GoToNextEdge();

/** Go to the edge designated.
 */
  virtual void GoToEdge(CATLONG32 iIdxEdge);

//-----------------------------------------------------------------------------
// About the edge
//-----------------------------------------------------------------------------
/** Gets the count of parts in the current edge.
 */
  virtual CATLONG32 GetCountParts() const;

/** Gets the curve associated to the edge.
 */
  virtual CATHLRCurve * GetCurve() const;

/** Returns 1 if the edge is smooth.
 */
  virtual CATLONG32 IsSmooth() const;

/** Gets the CATEdge associated to the edge. This returns NULL if there is no
 * (in case of created reflect line, for example).
 */
  virtual CATEdge * GetEdge() const ;

/** Gets the CATHLREdge associated to the edge.
 */
  virtual CATHLREdge * GetHLREdge() const;

/** Gets the number of faces linked to the edge. If the edge is imbedded in a 
 * face, there should be only one ( this is the case for a created reflect line). 
 */
  virtual CATLONG32 GetCountFaces() const;

/** Gets a face linked to the edge from its number (this should start at 0 and
 * be strictly lower than GetCountFaces() ).
 */
  virtual CATHLRFace * GetFace(CATLONG32 iIdxFace) const;

/** Gets the number of visible vectors of the current edge.
 */
  virtual CATLONG32 GetCountVisibleVectors() const;

/** Gets the number of hidden vectors of the current edge.
 */
  virtual CATLONG32 GetCountHiddenVectors() const;

/** Gets the number of visible reflect vectors of the current edge.
 */
  virtual CATLONG32 GetCountVisibleSilhouetteVectors() const;

/** Gets the number of hidden reflect vectors of the current edge.
 */
  virtual CATLONG32 GetCountHiddenSilhouetteVectors() const;

/** Gets the array of visible vectors.
 */
  virtual const double * GetVisibleVectors() const;

/** Gets the array of hidden vectors.
 */
  virtual const double * GetHiddenVectors() const;

//-----------------------------------------------------------------------------
// About the current part
//-----------------------------------------------------------------------------
/** Gets the visibility of the current part.
 */
  virtual CATHLRConstant::TypeVisibility GetVisibility() const;

/** Gets the start/end parameters of the current part on the curve
 */
  virtual void GetStartParam(CATCrvParam & oStart) const;
  virtual void GetEndParam(CATCrvParam & oEnd) const;

/** Returns 1 if the part is a reflect.
 */
  virtual CATLONG32 IsReflect() const;

/** Returns 1 if the part is AutoHidden.
 */
  virtual CATLONG32 IsAutoHidden() const;

/** Gets the OcclusionType.
 */
  virtual CATHLRConstant::TypeOcclusion GetOcclusionType() const;

/** Go to the next part. Returns 0 if there is no more part on the edge, 1 else.
 */
  virtual CATLONG32 GoToNextPart();

//=============================================================================
// OTHER METHODS
//=============================================================================
/** Sets/unsets the halo mode (1 sets; 0 unsets)
 *  The halo mode displayssegments of visible edges in smaller pieces, so 
 *  taht a sympathetic 3D aspect appears on the 2D view
 */
  inline void SetHaloMode(int iModeValue);

/** AddRef / Release mechanism. Pointer should never be used after release.
 */
  int AddRef();
  int Release();

/** Computes the new segments limits when the halo mode is on
 */
  virtual void ComputeHaloRelimitations();
  virtual void ComputeHaloOnStart(CATHLRResultPart * iPart);
  virtual void ComputeHaloOnEnd  (CATHLRResultPart * iPart);

/** Adds an edge in the result (this creates an entity if necessary).
 */
  virtual void AddEdge(CATHLREdge * iLinkedEdge);

/** Adds a part in the current edge.
 * The iIsReflect flag is to test if the part is a reflect line. 
 * The iOcclusionType refers to CATHLRHedge::typeOcclusion. Default value is 4 (undefinedSide).
 * The value will be different if and only if : iVisibility value is Occluded and AdvancedOcclusions are activated (CATHLRView::IsAdvancedOcclusionEnabled)
 */
  virtual void AddPart(      CATHLRConstant::TypeVisibility   iVisibility,
	                     const CATCrvParam                    & iStart,
	                     const CATCrvParam                    & iEnd,
	                     short                                  iIsReflect,
                       short                                  iIsAutoHidden,
                             CATHLRConstant::TypeOcclusion    iOcclusionType);

  // Adds a container in the list of silhouette containers
  // The container has to be released in this class destructor
  void AddSilhContainer(const CATHLRTemporaryContainer *iContainer);


protected:

/**
 * Destructor // private use only, please, use Release() method instead
 */
  virtual ~CATHLRResultBrowserBase();


//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Enumeration for the selected bodies
  enum {AllSelected = -1};

// Enumeration of the mode for the results
  enum EnumResultMode {ProjectionSpace, OriginalSpace};

  EnumResultMode                 _ResultMode;

  // Input Data from HLR drivers
  CATHLRContainerEntity        & _ContainerEntity;

  // Tolerance
  const CATTolerance           & _SceneHLRTol;

  // Versionning
  CATSoftwareConfiguration     * _SoftwareConfiguration;
  int                            _InputConfig;

// Selected body. If equal AllSelected, all the bodies are selected ( the default)
  CATHLRBodyId                   _SelectedBody;

// Type de projection (par defaut cylindrique)
  CATHLRConstant::TypeProjection _ProjectionType;
  
  unsigned char                  _HaloMode;

// Points used to put the result in the original space
// when the projection type is conical
  CATMathPoint                   _Observer;
  CATMathPoint                   _Target;

  // Counter for AddRef / Release mechanism
  CATLONG32                       _ReferenceCounter;

// Memory manager
  CATHLRMemoryManager           * _MemoryManager;

// List of entities in the result
  CATHLRResultEntity           ** _ArrayEntity;
  CATLONG32                       _IdxCurrentEntity;

// Number of entities
  CATLONG32                       _CountEntities;

// Allocation of the array of entities
  CATLONG32                       _AllocatedEntities;

  CATMapOfIntToInt                _EntitiesIDToIdx; // to speed up the search in SelectObject

// Clash Data
  typedef struct clashData_
  {
    CATMathPoint clashPoint;
    unsigned char visibility;

    clashData_(const double iX, const double iY, const double iZ, unsigned char _visibility = 0) : visibility(_visibility)
    {
      clashPoint = CATMathPoint(iX, iY, iZ);
    }

  } clashData;

// Lists of clashData pointers
  CATListPV                _EntityEntityClashPoints; // Clash Entity vs. Entity
  CATListPV                _SilhEntityClashPoints; // Clash Silhouette vs. Entity
  CATListPV                _UnknownVisibilityClashPoints; // Ignored clashes 

// Number of selected edges
  CATLONG32                _CountSelectedEdges;

// Total number of edges
  CATLONG32                _TotalCountEdges;

// Current selected edge
  CATHLRResultEdge       * _CurrentResultEdge;

// Current edge number in the selection
  CATLONG32                _CurrentEdgeNumber;

// Current HLR edge
  CATHLREdge             * _CurrentHLREdge;

// Current Part used.
  CATHLRResultPart       * _CurrentPart;

// First edge of the results selected
  CATHLRResultEdge       * _FirstResultEdge;
  CATHLRResultEdge       * _LastResultEdge;

// Current Id of the body
  CATHLRBodyId             _CurrentId;

// Current entity in which the edges and parts are added.
  CATHLRResultEntity     * _UsedEntity;

// Current Result edge on which the parts are added
  CATHLRResultEdge       * _UsedResultEdge;

  CATHLRObjectLinker     * _EdgeToResultEdgeTable;

  // List of pointers on the silhouette containers related to the entities
  // This list length is similar to the number of entities in the scene
  CATListPV                _SilhContainers;

  CATHLRDiscretizer        _HLRDiscretizer;

//------------------------------------------------------------
// Internal methods
//------------------------------------------------------------
// Select the CurrentEdge
  virtual void SelectCurrentEdge();
  virtual void SelectEntity(CATLONG32 iIdxEntity);
  virtual void ReallocateEntity();

};

//=============================================================================
// INLINE FUNCTIONS
//=============================================================================

inline void CATHLRResultBrowserBase::SetHaloMode(int iMode) {
  _HaloMode = (char) iMode;}

inline CATHLRBodyId CATHLRResultBrowserBase::GetSelectedBodyID() {
  return _SelectedBody; }

inline const CATTolerance & CATHLRResultBrowserBase::GetSceneTolerance() {
  return _SceneHLRTol; }

#endif
