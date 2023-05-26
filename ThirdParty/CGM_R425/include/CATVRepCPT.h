//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//==============================================================================================================

// CATVRepCPT : Closest Point Transform : generates a valuated VRep from a mesh

//==============================================================================================================
// Creation : CHU , March 2006
// Modif    : CHU , Nov 2006 - architecture update
//==============================================================================================================

#ifndef CATVRepCPT_H
#define CATVRepCPT_H

// Release comment in the following line to enable DegenKiller algorithm on a 3rd pass, when the input mesh has degenerate triangles
// To do in CATVRepCPTContext.h, CATVRepCPT.h and and CATVRepMeshDegenKiller.h
// #define CPT_ENABLE_DEGEN_MESH_RECOVERY

#include "CATErrorDef.h"          // HRESULT definition
#include "CATListOfInt.h"         // agregated
#include "VRepGen.h"              // ExportedBy definition
#include "CATTolerance.h"         // ExportedBy definition

#include "CATIAV5Level.h"

#ifdef CATIAR420
#ifndef _MOBILE_SOURCE
#include <vector>
#undef nested
#include "LatticeNBModel.h"
#endif
#endif

class CATVRepCPTScenario;
class CATVRepCPTContext;
class CATVRepWorkLists;
class CATIPolyMesh;
class CATVRepTree;
class CATVRepFeed;
class CATVRepType;
class CATVRepWatch;
class CATVRepVoronoi;
class CATVRepVisitMesh;
class CATVRepMultiVisitMesh;
class CATVRepCPTDebugOutput;
class CATPolyEvaluatedCell;
class CATPolyError;
class CATMathBox;
class CATMathVector;
class CATMathPoint;
class CATCGMOutput;
class CATSoftwareConfiguration;
class CATCGMProgressBar;
class CATIPolySurfaceVertexIterator;
class CATIPolyMeshTriangleIterator;

#ifdef CATIAR420
class LatticeNBModel;
class CATVRepVisitBarGraph;
class CATVRepMultiVisitBarGraph;
#endif

class ExportedByVRepGen CATVRepCPT
{

public :

  // -----------------------------------------------------------------
  // Life cycle

  // An input mesh is assumed to have compliant triangle orientation (two triangles sharing an edge
  // that is not shared by any other triangle have compliant orientations)
  // The voxel size in input is the size of the smallest voxels that will be handled
  // The resulting VRep (if the operation is successful) has to be deleted by the caller

  // If an existing vrep has to be fed, its voxel size is kept and its definition box must
  // already contain all points where the distance field will be valuated by next run
  // (e.g, for an offset, the set of triangles that will be processed -entire iMesh, or a box of it-,
  // augmented by the maximum offset specified for computing fields)

  // Note that the mesh spatial extent (in X,Y or Z) may not be larger than 2**15 (32768) times
  // the requested voxel size

  // If iSoftwareConfiguration==NULL -> behavior is like open config (last CGMLevel)

  static CATVRepCPT * CreateCPT(CATVRepType & iVRepType, CATVRepTree * iExistingVRep = 0,
    CATSoftwareConfiguration * iSoftwareConfiguration = 0,
    const CATTolerance & iTol=CATGetDefaultTolerance());

  virtual ~CATVRepCPT();

  // -----------------------------------------------------------------
  // Inputs

  void SetInputMesh(const CATIPolyMesh & iMesh);
  void SetMeshTrianglesToVisit(CATIPolyMeshTriangleIterator * iTrianglesToVisit);
  void SetMeshVerticesToVisit(CATIPolySurfaceVertexIterator * iVerticesToVisit);
#ifdef CATIAR420
  void SetInputBarGraph(const LatticeNBModel & iBarGraph);
#ifndef _MOBILE_SOURCE
  void SetBarGraphNodesToVisit(const std::vector<LatticeNBModel::NodeDescriptor> * iNodesToVisit);
  void SetBarGraphBeamsToVisit(const std::vector<LatticeNBModel::BeamDescriptor> * iBeamsToVisit);
#endif //#ifndef _MOBILE_SOURCE
#endif

  // -----------------------------------------------------------------
  // Settings

  // Initialize Voxel size (mandatory, unless a pre-existing VRep was provided)
  void SetIsClientExpectedDepth(CATBoolean iSet);
  HRESULT SetVoxelSize(double iVoxelSize);
  HRESULT SetClientExpectedDepthValue(int iClientExpectedDepthValue);
  double GetVoxelSize();

  // Trim voronois according to iIJKTrimBox
  void SetIJKTrimBox(unsigned int * iIJKTrimBox);

  // Define area where distance / gradient fields should be computed (mandatory)
  // iMeshSides says how min and max offset should be considered:
  // = 0: apply them to both sides, +1 = toward normal only, -1 = opposite normal only
  // (note that if iMinOffset is negative and iMaxOffset positive, iMeshSides must not be =0)
  void SetFieldAreaAsOffsetRange(int iMeshSides, double iMinOffset, double iMaxOffset);
  void SetFieldAreaAsOffsetRange(int iMeshSides, double iTargetOffset); // range is sqrt(3)* VoxelSize by default

  // For Lattice
  void SetFieldAreaAsInflateRange(int iMeshSides, double iTargetOffset); // range is [0, sqrt(3)* VoxelSize] by default
  void SetFieldAreaAsInflateRangeLimit(int iMeshSides, double iTargetOffset); // range is [-sqrt(3)* VoxelSize, sqrt(3)* VoxelSize] by default


  void SetFieldAreaAsBoxLimits(int iMeshSide = -1); // default = inward closed mesh = -1 * mesh normals; only -1 or +1 allowed

  // Define an offset that should be pre-applied to distances and gradients
  // This offset can be positive or negative, the method may not be called if it should remain null
  // If the VRep must be computed with unsigned distance fields, then a negative applied offset is not allowed
  // If the offset can be applied a posteriori, then it is advised not to call this method
  void SetPreAppliedOffset(double iPreAppliedOffset);

  // Define how the VRep should be trimmed in the neighborhood of free edges (skin boundaries)
  // The VRep can either be trimmed by a tangent extrapolation of the skin (default),
  // or by a normal comb on the boundary (iNormalCombTrim should then be set to 1)
  // If the VRep should be "approximately" trimmed by the normal to the skin border, but with fields fed one
  // voxel away from the normal, set iNormalCombTrim = 2, and optionnally adjust the number of added voxels
  // to be fed by SetNbAddedVoxelsAwayFromNormalToSkinBorder(), the default being = 1
  // The VRep reference in the extension is the mesh border by default, but can be optionally switched to a linear
  // extrapolation of the mesh in order to get a linear-extrapolated offset
  // This parameter has no effect if the input mesh is closed (volume)
  void SetVRepTrimOnFreeEdges(int iNormalCombTrim=0);
  void SetNbAddedVoxelsAwayFromNormalToSkinBorder(int iNbAddedVoxels = 1);
  void SetLinearExtendMode(int iLinear = 1);

  // Define an "extended-rounded-border-mode" for an offset operation required on one side only, with no normal trim on the edges :
  // Under this mode, the VRep will also be fed on the other side of the input mesh, close to the skin borders,
  // thus enabling the DualContouring operator to build quads that connect the border Voronois on either sides,
  // and to avoid a trimming effect close to these edges
  void SetExtendedRoundedBorderMode(int iMode=1);


  // Enable multithreading : it is disabled by default, so far.
  // In order to actually start multi-thread, environment variable CCGMMULTITHREAD must also be set =1
  inline void EnableMultiThread(int iEnable=1);

  // Disable multithread but run 8 subtasks in sequence (covers conciliation code)
  inline void SetForceMultiTaskForCoverage(int iForce = 1);


  inline void EnablePartialCPT();

  // Initialize a function that reads a binary data on all mesh/lattice cells and copy that data onto all gradient fields
  // that point to this cell (i.e. onto all gradient fields inside the Voronoi associated with the cell)
  // cf typedef (*GetClientBinaryDataFromCell) in CATVRepCPTScenario.h
  void SetCellDataVisitor(void * iVisitorContext, HRESULT (*iVisitorFunction)(const CATIPolyMesh &, int, int [2], void *, unsigned int &));
#ifdef CATIAR420
  void SetCellDataVisitor(void * iVisitorContext, HRESULT (*iVisitorFunction)(const LatticeNBModel &, int, int, void *, unsigned int &));
#endif

  // -----------------------------------------------------------------
  // Main algorithm : build the vrep
  // Triangles may be filtered by a box, or by a "keep" function that returns 1 to keep a triangle, 0 to discard it
  // At most one of the two arguments iOnlyInBox and iKeepTriangle may be not null; by default they are both null.
  // Note that several runs can be tried in sequence, but the resulting VReps have to be deleted by the caller
  CATPolyError * RunCPT(CATMathBox * iOnlyInBox = 0, int (*iKeepTriangle)(int iTrIdx, void * iContext) = 0, void * iKeepTriangleContext = 0);

  // Used by partial CPT : compute the reference box of the (master) VRep
  CATPolyError * RunComputeRefBox(CATMathBox & oRefBox, int & oDepth, CATMathBox * iOnlyInBox = 0);

  // Get result (note that the vrep is not deleted by the destructor)
  CATVRepTree * GetVRep() const;

  // Read vertices in error (relevant when a CATPolyError* has been returned by RunCPT())
  // oVertexList should be empty in input, and contains vertex indexes related to the initial mesh in output
  // Important: must not be called after RetrieveCPTDebugOutput()
  //            if both methods should be called, this one must be called first (juste after RunCPT())
  void GetVerticesInError(CATListOfInt & oVertexList);

  // Retrieve debug output for interactive debug purposes
  // Important: must not be called before GetVerticesInError()
  CATPolyError * RetrieveCPTDebugOutput(int iShowGrids, int iShowGradients, int iShowDistances,
    int iShowBoxes, int iShowGeneratingCells, int iShowUnboundedVor, int iShowRecoveryMesh, CATVRepCPTDebugOutput *& oDebugOutput);

  // -----------------------------------------------------------------
  // Customization for debug (kept if several runs are tried) :

  // Keep only Voronoi polyhedra generated by one init-mesh-cell,
  // of dimension iCellDim. iCellIdx2 is used only for edges between vertices iCellIdx1 and iCellIdx2
  // Leave iVorNum=0 to keep all voronois associated with the cell, else give the target Voronoi number
  // by order of creation
  // If iCellDim==-1, all data previously kept is cancelled
  void KeepVoronoiForSingleCell(int iInvolveRecoveryMesh, int iCellDim, int iCellIdx1, int iCellIdx2, int iVorNum, int iOnlyPassNumber);
  void KeepAllVoronois();
  inline void SetFeedVRepLevel(int iFeedVRepLevel); // 0=none, 1=division, 2=init.fields (default)
  void SetKeepGridsWithVoronois(int iKeep=1);
  inline void SetIgnoreTrimBoxToSetRefBox(int iIgnore);

  // Activate check or dump on all work-lists (debug or coverage)
  static void SetCheckLevel(int iCheck=1);
  static void SetDumpLevelForCoverage(int iDumpLevel=1);

  // Customization for debug: Keep only Voronoi polyhedra containing at least one corner in
  // given box, and write history of field assignments in this box
  void TrackIJKBox(unsigned int * iIJKBox);

  // -----------------------------------------------------------------
  // Introspection
  int GetExpectedDepth();

  int GetAllowDepthDiffAfterMargin();
  void SetAllowDepthDiffAfterMargin(int iMargin);

  // Dump
  HRESULT Dump( CATCGMOutput & s) const;

  /**
  * Sets the callback instance that is called to track progress during the Run () method.
  **/
  void SetCallback(CATCGMProgressBar* callback, int startProgress = 0, int endProgress = 100);


private:

  // Constructor called by create method
  CATVRepCPT(CATVRepCPTScenario & iScenario, CATVRepCPTContext & iContext);

#ifdef CPT_ENABLE_DEGEN_MESH_RECOVERY
  // Fix degenerate triangles
  CATPolyError * FixDegenerateTriangles();

  // Update the VRep inside new edge-voronois and vertex-voronois based on the given recovery mesh
  // The size of the voronois involved depends on the pass number
  CATPolyError * UpdateVRepInsideDegenInducedVoronois(CATIPolyMesh * iRecoveryMesh);
#endif

  // Take ownership of all work-lists after run, for debug purposes
  CATVRepWorkLists * TakeWList(int iForceXYZCoordinates);

  // Create one or several mesh-visit operators, according to the multi-thread context
  // In case multi-thread is active, context and WList clones are created
  CATPolyError * CreateVisitOperators(CATMathBox * iOnlyInBox, int (*iKeepTriangle)(int iTrIdx, void * iKeepTriangleContext), void * iKeepTriangleContext);

  // Merge sub-results in multi-threaded mode: FieldSets, VReps, Work-lists are merged, clones are deleted
  CATPolyError * MergeThreadResults();

  // Clean all clone data: WLists, VReps, contexts (and owned field sets)
  void DeleteAllClones();

  // -------------------------------------------------------------------
  // Data
  CATVRepCPTScenario     & _CPTScenario; // owned
  int                      _CPTDisableMultiThread;
  int                      _ForceMultiTaskForCoverage; // coverage only

  int                      _NbTasks; // > or = _NbThreads (each thread runs one or more tasks in sequence)
  int                      _NbThreads;
  CATBoolean               _PartialCPT; // TRUE if this CPT operator runs on a child VRep

  CATVRepCPTContext      & _CPTContext;  // owned, contains a pointer to the result vrep
  CATVRepWorkLists       * _WList; // owned

  CATVRepMultiVisitMesh ** _MultiVisitMeshOpe; // array of _NbThreads operators, owned + objects owned
#ifdef CATIAR420
  CATVRepMultiVisitBarGraph ** _MultiVisitBarGraphOpe; // array of _NbThreads operators, owned + objects owned
#endif

  // The size of all (4) following lists is _NbTasks
  CATVRepCPTContext     ** _CloneContextList; // owned + objects owned
  CATVRepWorkLists       * _CloneWList;       // owned (size = _NbTasks)
  CATVRepTree           ** _CloneVReps; // owned + objects owned : actually, duplicated VReps focussed on a partition of the octree
  CATVRepVisitMesh      ** _VisitMeshOpe; // list + all objects owned, sub-operators called for each Voronoi-pass
#ifdef CATIAR420
#ifndef _MOBILE_SOURCE
  CATVRepVisitBarGraph  ** _VisitBarGraphOpe; // list + all objects owned, sub-operators called for each Voronoi-pass
#endif
#endif

  // Customization for debug: only some cells can be actually processed
  CATVRepWatch           * _Watch; // owned, left null if no debug customization active
  int                      _IgnoreTrimBoxToSetRefBox;
  int                      _FeedVRepLevel;

  // Output: cell in error (debug)
  int                      _CellInErrorNumber;

  CATCGMProgressBar        * _Callback;
  int                   _StartProgress, _EndProgress;

  // PRIVATE METHODS
  // ===============

  HRESULT UpdateProgress (const int progress);
};

inline void CATVRepCPT::SetFeedVRepLevel(int iFeedVRepLevel) {
  _FeedVRepLevel = iFeedVRepLevel; }

inline void CATVRepCPT::SetIgnoreTrimBoxToSetRefBox(int iIgnore) {
  _IgnoreTrimBoxToSetRefBox = iIgnore; }

inline void CATVRepCPT::EnableMultiThread(int iEnable) {
  _CPTDisableMultiThread = 1-iEnable; }

inline void CATVRepCPT::SetForceMultiTaskForCoverage(int iForce) {
  _ForceMultiTaskForCoverage = iForce; }

inline void CATVRepCPT::EnablePartialCPT() {
  _PartialCPT = TRUE;}


#endif
