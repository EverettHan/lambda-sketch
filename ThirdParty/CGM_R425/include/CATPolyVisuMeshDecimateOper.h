// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuMeshDecimateOper.h
//
//===================================================================
// May 2010 Creation:  zfi
// March 11, 2016 - Added option to merge faces, -NDO
//===================================================================

#ifndef CATPolyVisuMeshDecimateOper_H
#define CATPolyVisuMeshDecimateOper_H

#include "CATPolyVisuDistiller.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATBoolean.h"
#include "CATVizPtrList.h"
#include "CATIPolyVisuMeshDecimateOper.h"
#include "CATListOfDouble.h"
#include "CATMapOfPtrToInt.h"
#include "CATMathConstant.h" // CATPIBY4
#include "CATListPV.h"
#include "CATListOfCATUnicodeString.h"
#include "CATPolyBodyVisLayer.h"
#include "Poly/UniquePtrDeleter.h"
#include <functional>
#include <memory>

class CATRep;
class CAT3DRep;
class CAT3DBagRep;
class CAT3DLineGP;
class CAT3DEdgeGP;
class CAT3DFaceGP;
class CATPolyBody;
class CATPolyBodyRepDiagnosis;
class CATPolyCustomDecimationOper;
class CATPolyBodyImportVizLayer;
class CATSoftwareConfiguration;
class CATPolyBodyVisLayer;
class CAT4x4Matrix;
class CAT3DRepHierarchyIterator;

class CATPolyBodyJoinDecimateBuilder;
class CATPolyVisuMeshDecimateOperVizLayer;
class CATMapOfIntToGraphicAttributeSet;

class CATechExt;

class CATGraphicMaterial;
class CATGraphicAttributeSet;


class ExportedByPolyVisuDistiller CATPolyVisuMeshDecimateOper
{

public:

  CATPolyVisuMeshDecimateOper ();
  ~CATPolyVisuMeshDecimateOper ();

public:
  //////////////////////
  //Init
  //Provide a 3D rep to join and decimate
  //////////////////////
  HRESULT Init(CAT3DRep& iRep);

  //////////////////////
  //Run Simple
  //////////////////////
  HRESULT Run(CAT3DRep*& oResultRep, double* oPourcentage=0);

  /////////////////////
  //Run Iterative
  ////////////////////
  // if returned result=S_FALSE, the end has been reached without further decimation of the model.
  // Percentage gives the percentage of decimation
  HRESULT Step(double* oPercentage=0);
  HRESULT BuildRep(CAT3DRep*& oResultRep);
  HRESULT Finalize(CAT3DRep*& oResultRep);

  //////////////////////
  //options
  //////////////////////
  // Configure the way operator will be used :
  //     - iDev : Deviation in mm (computed by the application according to model size
  //     - iJoinTolerance : Tolerance used during join phase
  inline HRESULT SetDeviation(double iFaceDeviation, double iEdgeDeviation);
  inline HRESULT SetJoinTolerance(double iJoinTolerance);

  //Freeze boundary bars exclude edge bars
  inline HRESULT DoFreezeFreeBoundarBars(CATBoolean iFreezeFreeBoundarBars, double iAngleTol = -1.0);

  /**
   * Sets a flag to merge all faces into a unique face before running the operator.
   * Adjacent faces (joined by edges) will be merged into a contiguous face.
   * By default, this option is turned off.
   * @param iAngleForSmoothEdges
   *   If set to a positive or null value, will be used as the minimum value (Radian) for the normals around an edge vertex to be considered sharp.
   *   Any smaller value and the edge vertex will be considered smooth, and the adjacent faces merged.
   *   The default value (-1.) ensure all faces are merged.
   *   If called with iFlag == FALSE, but iAngleForSmoothEdges set to a positive or null value, then edges will be created anywhere a bar is considered sharp.
   */
  inline void DoMergeFaces (CATBoolean iFlag, double iAngleForSmoothEdges = -1. /*CATPIBY4*/);

  inline void DoDecimateTargetPercentage(CATBoolean iFlag, double iTarget);
  inline void DoDecimateTargetPercentage(CATBoolean iFlag, const CATListOfDouble &iTargetList, const CATMapOfPtrToInt &iMapOfFaceToTarget);

  //////////////////////
  //version
  //////////////////////
  HRESULT SetSoftwareConfiguration(CATSoftwareConfiguration* iSoftwareConfiguration);

  /**
  * This option is disabled by default.
  * By default, the decimation operator creates one output face for each manifold surfacic patch in the input polybody.
  * Therefore, if the polybody contains faces whose meshes are made up of multiple manifold patches, the output polybody will feature many more faces than the input one.
  * If enabled, this option allows for the creation of exactly one output polybody face per input polybody face.
  */
  void DoCreateOneOutputFacePerInputFace(CATBoolean iDoCreateOneOutputFacePerInputFace);

  /**
  * This option enables keeping the smallest representation for canonical representations, i.e. the canonical representation.
  * When dealing with CAT3DCanonicalRep, CAT3DCylinderRep and CAT3DCurvedPipeRep, we keep it as is.
  * This option is disabled by default.
  */
  void DoCopyCanonicalRepresentations(CATBoolean iDoCopyCanonicalRepresentations);

  /**
  * This option enables keeping the wires
  * Wires are not decimated.
  * This option is disabled by default.
  */
  void DoCopyWires(CATBoolean iDoCopyWires);

  /**
   * This option enables decimating VisPrimitiveGroupRep's
   * Default is to IGNORE VisPrimitiveGroupRep's. They are not part of the result.
   */
  void DoTreatVisPrimitiveGroupRep(CATBoolean iTreatVisPrimitiveGroupRep);

  /**
   * Turns on or off an option for the construction of all edges in the result.
   * By default, this option is turned ON. Edges will be constructed.
   * If turned off, the result won't contain edges.
   */
  void DoCreateEdges(CATBoolean iDoCreateEdges);

  /**
   * Sets the flag to interpolate the normal when collapsing a bar
   * By default, this option is turned on.
   * It may lead to shading problems when heavily decimating areas where normals vary a lot.
   * In this case, you may want to set it to off.
   * If turned off, then normals are fully computed again at the end of decimation.
   * On is good for CAD models where edges between faces are kept.
   * Off is good for impostors.
   */
  void DoInterpolateNormals(CATBoolean iDoInterpolateNormals);

  /**
  * Sets the flag to compute new edges as a post process. Works well for a massive decimation with the option to merge all the faces.
  * By default, this option is turned off.
  * @param iDoPostProcessSharpEdges
  *        If set to TRUE, activates this post process
  * @param iAngleForSharpEdges
  *   Will be used as the minimum value (Radian) for the normals around a bar to be considered sharp.
  *   Any smaller value and the bar will be considered smooth.
  *   Edges will be created along sharp bars, and normals computed again for a better shading.
  */
  void DoPostProcessSharpEdges(CATBoolean iDoPostProcessSharpEdges, double iAngleForSharpEdges = CATPIBY4);

  /**
  * Includes the nD texture coordinates for the simplification of the bars and placement of the nodes.
  * @param iDim
  *   Number of constraints.
  * @param iWeight
  *   The weights given to the texture coordinates.
  */
  void DoProcessTextureCoordinatesConstraints(const int iDim, const double iWeight[]);

  /**
   * Sets a flag to use and process the data in the layer specified by its identifier.
   */
  void DoProcessDataLayer(const CATUnicodeString& iIdentifier);

  /*
   * Allow for (macro) vertex merge when it does not introduce any face collapse.
   * Note that this option will de-activate the texture restrictions (texture charts may be bigger and overlap)
   */
  void DoAllowVertexMerge(CATBoolean iAllow = TRUE);

  /**
   * When using angles for the merge of the faces and the post process of sharp edges,
   * do not create full edges. It creates less edges but should guarantee a valid output,
   * provided the input is valid.
   * Default is off (all edges are created.)
   **/
  void DoNotCreateFullEdges(CATBoolean iFlag);

  /**
  * Sets the flag to add an additional restriction to conserve texture coordinates inside original charts.
  * By default, this option is turned off.
  * @param iTextureCoordinatesInsideCharts
  *        If set to TRUE, activates this restriction.
  */
  void DoKeepTextureCoordinatesInsideCharts(CATBoolean iTextureCoordinatesInsideCharts);

  /** Default is Off */
  void DoStitchDifferentNormals(CATBoolean iDoStitchDifferentNormals);


  /**
   * Activate the decimation by blocks (FUN132413)
   * This mode is not compatible with the run iterative mode (Step, BuildRep, Finalize)
   * @param iNbTrianglePerBlock: Expected max number of triangles in a part. Reps or faces are not split so max might be higher (Min = 100)
   * @param iDecimationByBlockAndJoinBlock: If TRUE, decimate all the decimated parts together with the same deviation at the end
   * Default is off
   */
  void DoDecimationByBlocks(unsigned int const iNbTrianglePerBlock = 10000000, CATBoolean const iDecimationByBlockAndJoinBlock = FALSE) {
    m_DecimationByBlock = TRUE;
    m_NbTrianglePerBlock = iNbTrianglePerBlock;
    m_DecimationByBlockAndJoinBlock = iDecimationByBlockAndJoinBlock;
  }

public:
	// Phoenix extension
	void SetPhoenixExtension (CATechExt* iExtension, CATBoolean iDeleteBuilder = FALSE);
	CATechExt* HasPhoenixExtension (CATBoolean iForceCreation = FALSE);
  double GetFaceDeviation() const { return _ChordalDev;}
  double GetEdgeDeviation() const { return _ChordalDev;}
  double GetJoinTolerance() const { return _JoinTol;}
  CATBoolean GetFreezeBoundaryBars() const { return _FreezeBoundaryBars;}
  CATBoolean GetMergeFaces () const {return _MergeFaces;}
  const CATSoftwareConfiguration* GetVersion() const {return _SoftwareConfiguration;}
  const CAT3DRep* GetInputRep() const {return _InputRep;}
  const CAT3DRep* GetOutputRep() const {return _OutputRep;}
  const int GetNumStep() const {return _NumStep;}

private:
  class InitBarGraphFunctor {
  public:
    InitBarGraphFunctor(CATPolyVisuMeshDecimateOper& decimateOper_);
    virtual ~InitBarGraphFunctor() = default;

    virtual HRESULT BuildPolyBody(CATRep& rep, CATGraphicMaterial const* const pGM, CATGraphicAttributeSet const* const pGA);
    virtual void BuildResultVisLayer(std::unique_ptr<CATPolyBodyVisLayer>& visLayer, CATGraphicMaterial const* const pGM, CATGraphicAttributeSet const* const pGA);
    virtual HRESULT UsePolyBody(CAT4x4Matrix const* const pMat);
    virtual bool NextBlock() const {return false;}
    virtual HRESULT Finalize() {return S_OK;}

    CATPolyBody const& GetPolyBody() const {
      return *uPolyBody;
    }

  protected:
    virtual HRESULT BuildPolyBodyVisPrimitiveGroupRep(CATRep& rep, CATPolyBody*& pCurrentPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis, int const polyBodyCellTypes);
    virtual HRESULT BuildPolyBodyRepAdapter(CATRep& rep, CATPolyBody*& pCurrentPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis, int const polyBodyCellTypes);

    CATPolyVisuMeshDecimateOper& decimateOper;
    std::unique_ptr<CATPolyBody, Poly::CATPolyBodyDeleter> uPolyBody;
    CATPolyBodyVisLayer localVisLayer;
    CATBoolean Visprim;
  public:
    CATBoolean ForceVisprim;
  };

  class InitBarGraphByBlockFunctor : public InitBarGraphFunctor {
  public:
    InitBarGraphByBlockFunctor(CATPolyVisuMeshDecimateOper& decimateOper_):
      InitBarGraphFunctor(decimateOper_),
      nextFace(0) {}

    virtual void BuildResultVisLayer(std::unique_ptr<CATPolyBodyVisLayer>& visLayer, CATGraphicMaterial const* const pGM, CATGraphicAttributeSet const* const pGA) override;
    virtual HRESULT UsePolyBody(CAT4x4Matrix const* const pMat) override ;
    virtual bool NextBlock() const override;
    virtual HRESULT Finalize() override;

  protected:
    virtual HRESULT BuildPolyBodyRepAdapter(CATRep& rep, CATPolyBody*& pCurrentPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis, int const polyBodyCellTypes) override;
    HRESULT Decimate();
    CATGraphicMaterial const* pGM = nullptr;
    CATGraphicAttributeSet const* pGA = nullptr;

    CATVizPtrList<CAT3DLineGP> lines;
    CATVizPtrList<CAT3DEdgeGP> edges;
    CATVizPtrList<CAT3DFaceGP> faces;
    int nextFace;
  };

  HRESULT InitBarGraph(CAT3DRep& iRep);
  HRESULT InitBarGraphWithHierarchyIterator(CAT3DRep& iRep, InitBarGraphFunctor& initBarGraph);
  HRESULT InitDecimation();
  CATPolyBodyJoinDecimateBuilder * InstantiateJoinDecimateBuilder(CATListPV & polybodies, CATPolyBodyImportVizLayer & importVizLayer);
  HRESULT CopyRep(CATRep& iRep, CAT4x4Matrix const* const pMat);
  HRESULT RunOnBarGraph(CAT3DRep*& oResultRep);
  HRESULT RunOnBarGraphNext(double& oPercentage);
  HRESULT BuildBarGraphRep(CAT3DRep*& oResultRep);
  HRESULT FinalizeBarGraph(CAT3DRep*& oResultRep);

  HRESULT RunDecimationByBlock(CAT3DRep*& oResultRep);

private:
  double _ChordalDev, _EdgeChordalDev, _JoinTol, _minDev;
  CATBoolean _FreezeBoundaryBars;
  CATBoolean _MergeFaces;
  CATSoftwareConfiguration * _SoftwareConfiguration;

  CATPolyBody * _ToKeepPolyBody;
  CATPolyCustomDecimationOper* _CurrentDecimator;
  CATPolyBodyImportVizLayer* _CurrentVizLayer;
  int _CurrentLevel, _MaxLevel;
  int _NbTriangles, _CurrentNbTriangles;
  int _NbBars;

  CATPolyBodyJoinDecimateBuilder* _CurrentJoinDecimateBuilder;
  CATPolyBodyJoinDecimateBuilder* _JoinDecimateBuilderForVisPrimitives;
  CATPolyVisuMeshDecimateOperVizLayer* _VizLayer;
  std::unique_ptr<CATPolyBodyVisLayer> _ResultVisLayer;
  CATMapOfIntToGraphicAttributeSet* _MapTagToGA;

  CATBoolean _DoDecimateTargetPercentage;
  double _TargetPercentage;
  CATListOfDouble *_TargetList;
  CATMapOfPtrToInt *_MapOfFaceToTarget;

  //Phoenix Handle
	CATechExt* _PhoenixExtension ;
  CAT3DRep* _InputRep;
  CAT3DRep* _OutputRep;
  CAT3DBagRep* _CopiedOutputRep;
  int _NumStep;

  CATBoolean _DoCreateOneOutputFacePerInputFace;
  CATBoolean _DoCopyCanonicalRepresentations;
  CATBoolean _DoCopyWires;
  CATBoolean _TreatVisPrimitiveGroupRep;
  double _FreezeBoundaryBarsAngle;
  CATBoolean _DoCreateEdges;
  CATBoolean _DoInterpolateNormals;
  double _AngleForSmoothEdges;
  CATBoolean _DoPostProcessSharpEdges;
  double _AngleForSharpEdges;
  int _DoProcessTextureCoordinatesConstraints;
  double * _DoProcessTextureCoordinatesConstraintsWeights;
  CAT4x4Matrix* _pTextureMat;
  CATListOfCATUnicodeString _ListOfDataLayers;
  CATBoolean _DoAllowVertexMerge;
  CATBoolean _DoKeepTextureCoordinatesInsideCharts;

  CATBoolean m_DoNotCreateFullEdges;
  CATBoolean m_DoStitchDifferentNormals;

  // Decimation by parts
  std::unique_ptr<CAT3DRep, Poly::CATBaseUnknownDeleter> uInputRep;
  CATBoolean m_DecimationByBlock;
  unsigned int m_NbTrianglePerBlock;
  unsigned int m_NbTriangleInTheCurrentBlock;
  CATBoolean m_DecimationByBlockAndJoinBlock;
  CAT3DRep* m_DecimationByBlockOutputRep;
};

inline HRESULT CATPolyVisuMeshDecimateOper::SetDeviation(double iFaceDeviation, double iEdgeDeviation)
{
  _ChordalDev = iFaceDeviation;
  _EdgeChordalDev=iEdgeDeviation;
  return S_OK;
}

inline HRESULT CATPolyVisuMeshDecimateOper::SetJoinTolerance(double iJoinTolerance)
{
  _JoinTol = iJoinTolerance;
  return S_OK;
}

inline HRESULT CATPolyVisuMeshDecimateOper::DoFreezeFreeBoundarBars(CATBoolean iFreezeFreeBoundarBars, double iAngleTol)
{
  _FreezeBoundaryBars = iFreezeFreeBoundarBars;
  _FreezeBoundaryBarsAngle = iAngleTol;
  return S_OK;
}

inline void CATPolyVisuMeshDecimateOper::DoMergeFaces (CATBoolean iFlag, double iAngleForSmoothEdges)
{
  _MergeFaces = iFlag;
  _AngleForSmoothEdges = iAngleForSmoothEdges;
}

inline void CATPolyVisuMeshDecimateOper::DoDecimateTargetPercentage(CATBoolean iFlag, double iTarget)
{
  _DoDecimateTargetPercentage = iFlag;

  if (_TargetList)
    delete _TargetList;
  _TargetList = 0;

  if (_MapOfFaceToTarget)
    delete _MapOfFaceToTarget;
  _MapOfFaceToTarget = 0;

  _TargetPercentage = iTarget;
}

inline void CATPolyVisuMeshDecimateOper::DoDecimateTargetPercentage(CATBoolean iFlag, const CATListOfDouble &iTargetList, const CATMapOfPtrToInt &iMapOfFaceToTarget)
{
  _DoDecimateTargetPercentage = iFlag;

  if (_TargetList)
    delete _TargetList;
  _TargetList = 0;

  if (_MapOfFaceToTarget)
    delete _MapOfFaceToTarget;
  _MapOfFaceToTarget = 0;

  if (iFlag) {
    _TargetList = new CATListOfDouble(iTargetList);
    _MapOfFaceToTarget = new CATMapOfPtrToInt(iMapOfFaceToTarget);
  }
}

#endif
