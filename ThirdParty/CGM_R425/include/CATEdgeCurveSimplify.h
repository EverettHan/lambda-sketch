/* -*-C++-*-*/
#ifndef CATEdgeCurveSimplify_h
#define CATEdgeCurveSimplify_h

#include "Thick.h"
#include "CATDataType.h"
#include "CATMathInline.h"

//==========================================================================
//	COPYRIGHT DASSAULT SYSTEMES 1999
//--------------------------------------------------------------------------
      
//	Operator designed to replace edge-curves by one of their agregated curves
//  within the topology of a body, in order to optimize the quality of these
//  curves (prefered type, gap, etc..) and (optionnally) to share edge-curves
//  between several edges whenever possible to enable new simplifications 

//  Processes either CATBody type or client topological models. In all cases,
//  a CATClientBody has to be constructed before the operator itself can be
//  constructed. In order to work with a native CATBody, use the derived 
//  class CATClientBodyNCGM to plug the CATBody into a CATClientBody object

//  Processes either single edges (regardless of any possibility to share
//  edge-curves between neighbor edges), or a whole body, or a subset of its
//  edges defined by an external iterator method. This iterator can be omitted
//  if all edges are to be processed and if a CATBody was used at construction
//  of CATClientBody input data.
//  If a single edge is processed, one mandatory pcurve per face can be
//  specified if necessary.

//  Orientation of edges is never modified, but relative orientation of edges
//  with respect to their edge-curve can be modified

//  A user-defined external comparator can be provided to select the best
//  of two edge-curves. If not, a default comparator is taken. Its properties
//  are listed below.
  
//  Run() is always required, a "basic mode" with implicit run upon
//  construction is not available
         
//==========================================================================
#include "CATTopDef.h"
class CATEdge;
class CATBody;
class CATPCurve;
class CATEdgeCurve;
class CATPointOnEdgeCurve;
class CATEdgeCurveIterator;
class CATSurface;
class CATClientBody;
class CATCGMOutput;
class CATMacroPoint;
class CAThkContext;


#include "CATIACGMLevel.h"
#ifdef CATIACGMV5R22
class CATEdgeCurveSimplify
#else
class ExportedByThick CATEdgeCurveSimplify
#endif
{
public :

  // Definition of an iterator on edges to be processed in a body
  // The ioIterContext updated at each iteration will typically include the
  // previous edge (or its range) and the iterator data itself
  typedef void* (* EdgIter) (void * ioIterContext);

  // Definition of a void function that resets the above defined iterator
  // context, in order to rescan the edges. If no such function is provided,
  // the operator assumes the context automatically goes back to initial
  // state upon last iteration
  typedef void (* EdgIterReset) (void * ioIterContext);

  // Definition of an edge-curve comparator. Returns -1 if iEC1 < iEC2, 0 if
  // they are equivalent, +1 if iEC1 > iEC2.
  // Contextual data (iCmpContext) can be passed to the comparator if needed
  // (see SetComparator method), otherwise send null pointer.
  // It is not advised to return zero (equivalent edge-curves) because this may
  // force the calling operator to make context-sensitive (unstable) decisions.
  typedef int (* ECrvComparator) (CATEdgeCurve * iEC1, CATEdgeCurve * iEC2,
                                  void * iCmpContext);

  // Definition of a function type that returns a binary "closed surface" information 
  // (1=closed, 0=no), intended for handling non periodic closed surfaces (closed sweeps ...)
  // iUorV=0 <=> "U-closed" <=> iso-V (e.g. U axis) are cycles and there exists 2 identical
  //              iso-U <=> same result as method IsClosedU() if the surface is periodic
  // iUorV=1 <=> "V-closed" <=> iso-U (e.g. V axis) are cycles and there exists 2 identical
  //              iso-V <=> same result as method IsClosedV() if the surface is periodic
  // iContext can be used to provide contextual information to the function itself
  // If oMinClosedParm or oMinClosedParm is not null as input, it will point towards 
  // the minimum (or maximum) value taken by the closed parameter (ex: MinU and MaxU if iUorV=0)
  // (identical definition can be found in 
  // GeometricOperators\ProtectedInterfaces\CATPositionVsSurfaceBorder.h)
  typedef short (*InvestigateClosedSurf)(CATSurface * iSurf, short iUorV, void * iContext,
    double * oMinClosedParm, double * oMaxClosedParm);

  // ------------------------- Data Management ---------------------------

  // Two constructors are available, depending whether one single edge or
  // several (or all) edges are to be processed. Set methods allow to change
  // this mode after construction in any case (use 2nd constructor with no
  // arguments if mode is unset upon construction, none of the constructors 
  // is costly). No "Create.." method is provided, use constructors directly.

  // Constructor for single edge processing
  CATEdgeCurveSimplify(CATClientBody * iCBody, void * iSingleEdge, CAThkContext *iContext);

  // Constructor for multiple edge processing (if all edges have to be
  // processed, the iterator and its associated context can be omitted)
  // The iterator, if any, is a pointer to a global function that returns
  // an edge* and updates a "context" cast to void*. If the context is omitted, 
  // null pointer will be passed to the iterator. Otherwise, the context, in
  // its "initial" status (before first iteration), must be provided here.
  CATEdgeCurveSimplify(CATClientBody * iCBody, 
                       EdgIter iEdgIter=0, void * iIterContext=0,
                       EdgIterReset iReset=0, CAThkContext *iContext=0);

  // Destructor (the iterator context, if any, is not deleted)
  ~CATEdgeCurveSimplify();

  // copy construction and operator = are not allowed, no implementation
  CATEdgeCurveSimplify(const CATEdgeCurveSimplify &);
  CATEdgeCurveSimplify& operator=(const CATEdgeCurveSimplify&);

  // -------------- Methods to ce called before Run(), if needed ------------
  // all these methods are optional

  // Sets or resets a single edge to process (in same body).
  // cancels "multiple edge" mode if it was active
  // prohibits furher use of get methods to investigate the last Run(), if any
  void SetSingle(void * iEdge);

  // Sets "multiple edge" mode and sets or resets the iterator (in same body)
  // cancels "single edge" mode if it was active
  // Prohibits furher use of get methods to investigate the last Run(), if any
  // The third argument is compulsory if the second one (context) is provided,
  // it is used to reset the context before starting a new scan.
  void SetMultiple(EdgIter iEdgIter=0, void * iIterContext=0,
                   EdgIterReset iReset=0);

  // Gives a method used to compare 2 edge-curves qualifying for the same edge
  // If no comparator is provided, int-curves are taken first, then sim-curves,
  // then merged-curves. For a given type, the smallest number of pcurves is
  // preferred, then the smallest gap.
  void SetComparator(ECrvComparator iCmp, void * iCmpContext=0);

  // Says whether shared edge-curves must always be prefered on neighbor edges,
  // in "multiple edges" mode, even if they are not the best edge-curves chosen
  // by the current comparator (or default comparator if none)
  // Input 1 to prefer shared edge-curves (default), 0 to prefer best edge-crv
  // Useless under single edge mode, since "best edge-curve" is the only
  // possibility in this case
  void SetPreferedSharedEdges(short iYes);

  // Sets (or unsets, if null) a function to evaluate surface closure.
  // Enables handling non-periodic closed surfaces that do not respond
  // to IsClosedU and IsClosedV
  void SetClosedSurfFunction(InvestigateClosedSurf iFunction, void * iClosedSurfContext = 0);

  // Setting and unsetting mandatory pcurves 
  // Mandatory PCurves can be imposed on specific faces (co-edge). In this case
  // the operator assumes these pcurves have already been set in the topology
  // by the "SetGeometryOnFace" method
  // Returns 0 if iPCurve had already been forced (with or without same face),
  // and returns 1 otherwise (1=ok, 0=uneffective).
  // In "single edge" mode, the edge under process has to be passed as 1st arg.
  short AppendMandatoryPCurve(void * iEdge, 
                              CATPCurve * iPCurve, void * iRelatedFace=0);

  // Cancels previous call to SetMandatoryPCurve with same PCurve, for all
  // concerned faces (only one edge can be concerned, if body has no self-
  // confusions)
  // Returns 0 if iPCurve had never been forced (with or without any face),
  // and returns 1 otherwise (1=ok, 0=uneffective).
  short RemoveMandatoryPCurve(CATPCurve * iPCurve);

  // Cancels all previous call to SetMandatoryPCurve
  void FreeMandatoryPCurves();

  // ---------------- Main process and CATBody update ----------------------

  // Run the algorithm (results can be investigated by following "Get.." methods)
  void Run();

  // If a native CATBody has been plugged into the input client body, updating
  // this CATBody can be done by the following method, provided the Run() method
  // has been called before. Returns 1 if one modification at least is performed
  short UpdateNCGMModel();

  // ------------ Methods to be called after Run(), if needed --------------

  // Gives the number of edges whose geometry (edge-curve) has changed
  CATLONG32 GetNumberOfChangedEdges();

  // Says how an edge is changed (0 <= iIndex <= GetNumberOfChangedEdges())
  // oNbChangedCoEdges is the number of couples <edge, face> with new pcurves
  // Note that the oorientation of the edge is not supposed to be modified,
  // but a (new) relative orientation versus its edge-curve is returned
  void GetChangedEdge(CATLONG32 iIndex, void *& oEdge, CATEdgeCurve *& oNewECrv,
                      short & oECrvOriVsEdg, CATPointOnEdgeCurve *& oStartEdgPoec,
                      CATPointOnEdgeCurve *& oEndEdgPoec, CATLONG32 & oNbChangedCoEdges);

  // Gives the total number of co-edges (edge on face) whose pcurve has changed
  CATLONG32 GetTotalNumberOfChangedCoEdges();

  // Says how a co-edge <pcurve, face> is changed. Orientations are not given since
  // they can be obtained by methods on edge-curves.
  // 0 <= iIndexInEdge <= oNbChangedCoEdges (from previous call to GetChangedEdge)
  void GetChangedCoEdgeWithinEdge(void * iEdge, CATLONG32 iIndexInEdge, void *& oFace,
                                  CATPCurve *& oOldPCrv, CATPCurve *& oNewPCrv,
                                  CATSide & oFaceSideVsEdg);

  // Gives the number of vertices (in fact, macro-points) that must be changed
  CATLONG32 GetNumberOfChangedVertices();

  // Says how a vertex's macro-point is changed
  void GetChangedVertex(CATLONG32 iIndex, void *& oVertex, CATLONG32 & oNbAddedPoecs,
                        CATLONG32 & oNbRetrievedPoecs);

  // Scans added (if iAdded=1) or retrieved (if iAdded=0) poecs on a given vertex
  // 0<= iIndex <= oNbAddedPoecs or 0<= iIndex <= oNbRetrievedPoecs, according to iAdded
  // Note: if a CATBody is used, retrieved poecs will not be actually retrieved from
  // the model for "smart" model compliancy.
  void GetAddedOrRetrievedPoec(void * iVertex, CATLONG32 iIndex, short iAdded,
                               CATPointOnEdgeCurve *& oPoec);

  // Retrieves the old edge-curve before simplification, and optionnally says
  // whether it has changed (*oChanged = 1 if so, 0 if it was left unchanged)
  // This method enables journaling
  CATEdgeCurve * GetOldEdgeCurve(void * iEdge, short * oChanged=0);

  //==========================================================================
  //  None of the following methods must be directly called by the user application
  //==========================================================================
  INLINE CATClientBody * GetClientBody() const;
  INLINE void * GetClosedSurfContext() const;

  void DumpObj(CATCGMOutput & s) const;
  friend ExportedByThick CATCGMOutput& operator<< (CATCGMOutput& s, const CATEdgeCurveSimplify & iObj);
  void ShortDumpCell(CATCGMOutput& s, void * iCell) const;

  //  Internal classes, private methods & data
  //--------------------------------------------------------------------------
  // sub-structure describing an edge qualifying for a given target edge-curve
  struct QEdge {
    void * _ConcernedEdge;
    short  _OriVsECrv;
    CATLONG32   _ConnectedSet; // number of simplifiable set containing edge on target ecrv
  };

  //--------------------------------------------------------------------------
  // structure attached to edge-curves
  struct ECrvAtt {

    // Chaining objects
    CATEdgeCurveSimplify * _Master;
    ECrvAtt              * _PrevECrvAtt; // objet cree juste avant
    ECrvAtt              * _NextECrvAtt; // objet cree plus tard

    // Edge-curve, and iterator eventually needed to get the new "smaller" poecs
    CATEdgeCurve         * _OwningECrv;
    CATEdgeCurveIterator * _Iter;

    // Number of agregated pcurves
    CATLONG32                   _NbSubPCrv;

    // Qualifying edges, arranged by connected sets
    CATLONG32                   _NbConcernedEdges;
    QEdge                * _ConcernedEdges;
    
    ECrvAtt(CATEdgeCurveSimplify * iMaster,
            CATEdgeCurve * iECrv,
            CATEdgeCurveIterator * iIter);
    ~ECrvAtt();

    CATLONG32 AppendConcernedEdge(void * iEdge, short iOriECrvVsEdge); // return new number, or 0
    short Concerns(void * iEdge);

    void BuildConnectedSets(); // to be called after VAtt are constructed

    // read a QEdge sub-structure associated with a given edge
    QEdge * GetQEdge(void * iEdge, short iThrowIfNotFound = 1);

    void DumpObj(CATCGMOutput & s, const CATEdgeCurveSimplify * iMaster); // for debug only
  };

  //--------------------------------------------------------------------------
  // Attributes attached to vertices, for two purposes:
  // Store list of possible edge-curves for incident edges, in order to
  //       optimize their choice when sharing edge-curves is wanted
  // Store old and new poecs in order to update macro-points
  // All allocations here are handled by malloc / realloc / free
  struct VAtt {
    CATEdgeCurveSimplify * _Master;
    void          * _OwnerVtx;

    CATLONG32            _NbECrv;               // allocated list of incident ecrv
    CATLONG32            _ECrvAllocSize;        // 
    CATEdgeCurve ** _ECrv;                 // incident edge curve and
    CATLONG32          * _NbOcc;                // number of occurences of _ECrv[]

    short                  _MacroPointAlreadyVisited;
    CATLONG32                   _NbPoecs;
    CATLONG32                   _PoecsAllocSize; // 3 following lists are paralle
    CATPointOnEdgeCurve ** _Poecs;          // and have _NbPoecs length
    CATLONG32                 * _NbOwningEdges;  // _IsNew[] = 0 for an initial poec
    short                * _IsNew;          // 1 if created by the operator

    VAtt(CATEdgeCurveSimplify * iOpe, void * iVtx);
    ~VAtt();
    void AppendECrv(CATEdgeCurve * iECrv, short iIgnoreIfNotPresent=0);
    CATLONG32 GetNbOccurences(CATEdgeCurve * iECrv);
    void AddPoec(CATPointOnEdgeCurve * iPoec, short iIsNew);
    void ReplacePoec(CATPointOnEdgeCurve * iOldPoec,
                     CATPointOnEdgeCurve * iNewPoec, short iNewReplacingPoec);
    void IsMacroPointChanged(CATLONG32 & oNbAddedPoecs, CATLONG32 & oNbRetrievedPoecs);
    void UpdateMacroPoint();

    void DumpObj(CATCGMOutput & s); // for debug only
  };

  //--------------------------------------------------------------------------
  // Handling imposed new coedges and old coedges
  struct Coedg {
    CATEdgeCurveSimplify * _Master;
    void                 * _Edg;
    CATPCurve            * _PCrv;
    void                 * _RelFac; // related face, zero if unset for imposed coedges

    void DumpObj(CATCGMOutput & s); // for debug only
  };

  //--------------------------------------------------------------------------
  // Handling Closures
  struct Closure {
    CATSurface * _Surf;
    short        _SurfNum;    // number returned by EdgeCurveIterator
    CATPCurve  * _OldPCrv;    // old pcurve met with following characteristics
    short        _CloNum;     // 1 if closure line is iso-U, 2 if iso-V
    short        _DetSign;    // det<NormSurf, TgNaturalClosure, TgSideOfPCurve>

    void DumpObj(CATCGMOutput & s); // for debug only
  };

  //--------------------------------------------------------------------------
  // Mapping old and new pcurves in topological model
  struct PCrvMap {
    // This object says "if NewECrv is eventually taken, then _NewPCrv must be
    // chosen to trim _Face instead of _OldPCrv under _Edge (by SetGeometryOnFace method)"
    // _Side stores the side of _Face in relation with the topological edge

    // Note: _Edge is not redundant in case a single pcurve bounds twice the
    // same face with two different sides under two distinct edges (non-manifold)
    CATEdgeCurveSimplify * _Master;
    CATPCurve            * _OldPCrv; 
    void                 * _Face;
    void                 * _Edge;
    CATSide                _Side;
    CATEdgeCurve         * _NewECrv;
    CATPCurve            * _NewPCrv;

    void DumpObj(CATCGMOutput & s); // for debug only
  };

  //--------------------------------------------------------------------------
  // Attribute attached to old pcurves: there are as many maps as there are
  // qualifying edge-curves to replace those (presumably one, if the body has
  // no self confused edges) that agregate the current "old" pcurve
  // Exception : if the same pcurve can remain attached to a given face, no 
  // specific map is added. If this is true for all qualifying ecrvs and all
  // concerned faces (lying on current pcurve support), no attribute is created
  struct PCrvAtt {
    CATEdgeCurveSimplify * _Master;
    CATLONG32                   _NbLocalMaps;
    PCrvMap              * _LocalMaps;

    PCrvAtt(CATEdgeCurveSimplify * iOpe);
    ~PCrvAtt();
    void AppendLocalMap(PCrvMap * iMap);

    void DumpObj(CATCGMOutput & s); // for debug only
  };

  //--------------------------------------------------------------------------
  // structure attached to edges
  struct EdgAtt {
    CATEdgeCurveSimplify * _Master;
    InvestigateClosedSurf  _MasterClosedSurfFunction; // copied 

    void                 * _OwnerEdge;
    CATEdgeCurve         * _OldECrv;

    CATEdgeCurve        ** _QualifyingECrv;
    CATLONG32                   _NbQualifying;

    CATEdgeCurve         * _NewECrv;
    short                  _NewOriVsEdg;

    // following poecs are ordered by the edge
    CATPointOnEdgeCurve  * _NewPoecs[2];

    // list of _NbFaces maps giving the correpondance old pcrv -> new pcrv
    CATLONG32                   _NbChangedFaces;
    PCrvMap              * _ChosenMaps;

    // add a new edge-curve qualifying for this edge
    void AddQualifyingECrv(CATEdgeCurve * iEcrv);

    // initialize _ChosenMaps, return numbers of affected faces (coedges)
    CATLONG32 InitializeChosenMaps(void* iEdge,
                              CATEdgeCurveIterator * iECIter,
                              int iPCrvAttKey);
    void AppendChosenMap(PCrvMap * iMap);

    // actually updates topological model for given edge (returns 1 if modified)
    short UpdateTopoEdge(CATEdge * iEdge);

    EdgAtt(CATEdgeCurveSimplify * iOpe, InvestigateClosedSurf iFunction,
           void * iOwnerEdge, CATEdgeCurve * iOld,
           CATEdgeCurve * iNew, short iNewOri);
    ~EdgAtt();

    void DumpObj(CATCGMOutput & s); // for debug only
  };
  //--------------------------------------------------------------------------

  enum {_STATIC_SIZE = 3, _ALLOCATION_STEP = 10};

  // Utility methods to get geometric data (type secured), or tags associated
  // with client cells, and to handle _LastCreatedECrvAtt
  CATEdgeCurve  * GetEdgeCurve(void * iEdge, short * oRelOri = 0) const;
  CATSurface    * GetSurface(void * iFace, short * oRelOri = 0);
  CATPCurve     * GetGeometryOnFace(void * iEdge, void * iFace, CATSide iSide,
                                    short & oOriVsEdg);
  CATPointOnEdgeCurve * GetGeometryOnEdge(void * iVertex, void * iEdge, CATSide iSide);
  CATULONGPTR            GetTag(void * iCell) const;
  ECrvAtt * GetLastCreatedECrvAtt() const;
  void SetLastCreatedECrvAtt(ECrvAtt * iLastCreated);

  // read an ECrvAtt attribute attached to a given edge-curve
  ECrvAtt * GetECrvAtt(CATEdgeCurve * iECrv, short iThrowIfNotFound = 1);

private :

  // cleans allocated memory and attributes attached to edge-curves and vertices
  // in the container
  void FreeMemory();
  void FreeIterator();         // part of FreeMemory()
  void CleanAttributes();
  void FreeChangedVerticesAndEdges();

  // registering closures for one edge, in _Closure[] list
  void AppendClosure(CATSurface * iSurf, CATPCurve * iOldPCrv,
                     short iSurfNum, short iCloNum, short iDetSign);
  void FreeClosures();

  // registering pcurve mapping for one ecrv -> any ecrv substitution
  void AppendMap(CATPCurve * iOldPCrv, void * iFace, CATSide iSide,
                 void * iEdge, CATEdgeCurve * iNewECrv, CATPCurve * iNewPCrv);
  void FreeMaps();
  void ResetMaps(); // keeps allocated memory if any, for optimization needs

  // handling ECrvAtt structures (inserting a new qualifying edge-curve)
  void UpdateECrvAtt(ECrvAtt *& ioEcatt, CATEdgeCurve * iECrv);

  // choosing edge-curves (if no comparator provided)
  // returns -1 if iEC1 < iEC2 (i.e. iEC2 better), 0 if equivalent, +1 otherwise
  int CompareEdgeCurves(CATEdgeCurve * iEC1, CATLONG32 iNbPCrv1,
                        CATEdgeCurve * iEC2, CATLONG32 iNbPCrv2);

  // scanning edges to be processed, returns 0 when finished
  void * NextToProcess(void * iPrev);

  // choosing pcurves with intrinsic criteria
  CATPCurve * ChoosePCrv(CATPCurve * iPCrv1, CATPCurve * iPCrv2);

  // building all VAtt attributes
  void BuildVAtts();

  // Find all possible edge-curves and associated pcurve mapping tables
  // and attach these data as attributes to edge-curves and pcurves
  // Returns the number of qualifying edge-curves for the edge given
  CATLONG32 FindQualifyingECrv(void * iEdge);

  // find best edge-curve for one given edge, and return its orientation
  CATEdgeCurve * FindTargetECrv(void * iEdge, short & oOriTargetVsEdg);

  // builds pcurve mappings for one qualifying edge-curve, returns 0 ik ok,
  // 1 if it must be discarded (mismatching position vs closure, no image for
  // one of the pcurves)
  short TryECrv(void * iEdge, CATEdgeCurveIterator * iOldECrvIter,
                CATEdgeCurve * iNewECrv, CATLONG32 iNbPCrv);

  // Diagnostic sur une pcurve : est-elle instanciee par au moins une face dans _CBody
  short IsPCrvUsedByAnyFace(CATPCurve * iPCrv, void * iEdge);

  // dump methods implemented for debug only
  void DumpAttributes(CATCGMOutput & s) const;
  void DumpClosures(CATCGMOutput & s) const;
  void DumpPCrvMaps(CATCGMOutput & s) const;

  //------------------------------------------------------------------------
  // data
  CATClientBody       * _CBody;

  CAThkContext        *_Context;

  void                * _SingleEdge;    // not null <=> single edge mode
  EdgIter               _UserIter;
  void                * _IterContext;
  EdgIterReset          _UserReset;
  
  void                * _GlobalIter;    // constructed only if _UserIter = 0

  // global diagnostic
  short                 _AtLeastOneModif;

  // edge-curve comparison tuning :
  // _PreferSharedEdges = 0 if comparator output must be taken first
  ECrvComparator   _Comparator;
  void           * _CmpContext;
  short            _PreferSharedEdges;

  // surface closure evaluation (if null, IsClosedU and IsClosedV will be used)
  InvestigateClosedSurf _ClosedSurfFunction;
  void                * _ClosedSurfContext;

  // list of changed vertices (macro-points)
  CATLONG32             _NbChangedVertices;
  VAtt          ** _ChangedVertices;

  // list of changed edges
  CATLONG32             _NbChangedEdges;
  EdgAtt        ** _ChangedEdges;

  // mandatory coedges (for single edge mode)
  CATLONG32             _NbMandatoryCoedges;
  CATLONG32             _ImposedCoedgAllocSize;
  Coedg          * _ImposedCoedg;

  // counters 
  CATLONG32             _NbChangedCoedges;

  // chaining ECrvAtt objects
  ECrvAtt        * _LastCreatedECrvAtt;

  // handling closures (for one edge)
  Closure          _StaticClosure[_STATIC_SIZE];
  Closure        * _Closure;
  CATLONG32             _NbClosures;
  CATLONG32             _ClosureAllocatedSize;

  // mapping pcurves (for one ecrv -> all possible ecrv substitutes on 1 edge)
  PCrvMap          _StaticMaps[_STATIC_SIZE];
  PCrvMap        * _Maps;
  CATLONG32             _NbMaps;
  CATLONG32             _MapsAllocatedSize;

  // attribute keys (0 if unset)
  int              _ECrvAttKey;         // old ecrv -> ECrvAtt* structure 
  int              _PCrvAttKey;         // old pcrv -> PcrvAtt* structure

  short            _EdgAttExist;
  short            _VAttExist;
};

INLINE CATClientBody * CATEdgeCurveSimplify::GetClientBody() const {
  return _CBody; }

INLINE void * CATEdgeCurveSimplify::GetClosedSurfContext() const {
  return _ClosedSurfContext; }

#endif










