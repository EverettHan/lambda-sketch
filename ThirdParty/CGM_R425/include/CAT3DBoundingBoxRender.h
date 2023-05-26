#pragma warning(disable: 5054)
#ifndef CAT3DBoundingBoxRender_H_
#define CAT3DBoundingBoxRender_H_

//*****************************************************************************
//  CATIA Version 5 Release 1 Framework PlantArrangementUI
//  Copyright Dassault Systemes 1998
//*****************************************************************************
//  Abstract:
//  ---------
//  Simple render to compute the bounding box of a representation.
//  The min (x,y,z) and max (x,y,z) of the bounding box is returned.
//
//  This render computes the bounding box for the original representation
//  tree as well as for levels of detail.
//
//*****************************************************************************
//  Usage:
//  ------
//  The render is created with a given CATSupport and CATMathTransformation.
//  The render is called each time a Draw() is executed.
//  Draw is called over entire viewpoint or perticular set of Bag Reps- Reps
//  Query for extremities of bondinb box can be retuned for
//  only 3D representation GetBoundingBox3D
//  or for both 3D+2D  using GetBoundingBox
//
//  Example 1 :
//    Draw called over set of 3DBagRep
//  --------
//
//  CATSupport support (100, 100);
//  CATMathTransformation transform;
//
//  CAT3DBoundingBoxRender* render
//    = new CAT3DBoundingBoxRender (support, transform);
// by default LOD consideration are off: render._UseCoarseLOD =false render._iflag = edefault

//  CATI3DGeoVisu_var hVisu(this);
//  CAT3DRep* rep = (CAT3DRep *) hVisu -> GiveRep();
//  rep -> Draw (*render, 0);
//
// IMP: the second argument should be 0 for performance benifits
// HOW? see OkToDraw in CAT2DRep, CAT3dRep, CATVidOneGPRep and CATVid3DBagRep
// if the second paramter- inside is 0 rep rejection happens giving us performance benifits
// we dont get the benifit if it is
//
//  CATMathPoint minPoint, maxPoint;
//  render -> GetBoundingBox (minPoint, maxPoint);
//  This will provid Extremities of boundingbox with 3D+2D
//  render -> GetBoundingBox3D (minPoint, maxPoint);
//  This will provid Extremities of boundinbbox for 3D only even no 3dlines,markergps,vizlines
//
//  Example 2 : To create bounding box render which works with 2D-Reps also use SetEnable2DReps
//              Draw called over viewpoint. Viewpoint contains user Reps
//  --------
//  CATViewer * pCurrentViewer = GetMyViewer();// GetMyViewer() application developer function
//  CATVizViewer * pVizViewer = NULL;
//  CATViewPoint * pViewpoint = NULL;
//  float x_support = 0,y_support  = 0;
//  if (pCurrentViewer)
//  {
//    pVizViewer = pCurrentViewer->GetVizViewer();
//    pCurrentViewer->GetGraphicSize(&x_support,&y_support);
//  }
//  if ( NULL != pVizViewer )
//    pViewpoint =  &(pVizViewer->GetMainViewpoint());
//
//  list<CATViewpoint>  viewpointL;
//  viewpointL.fastadd(pViewpoint);  //_Viewpoint You want to compute bouding-box
//  CATSupport Support(x_support,y_support);
//  CATMathTransformation Transfo;
//  CAT3DBoundingBoxRender render(Support,Transfo);
//  render.SetEnable2DReps(1);
//  render.Draw(viewpointL,0,0);
//
//  CATMathPoint minPoint, maxPoint;
//  render -> GetBoundingBox (minPoint, maxPoint);
//  dont query GetBoundingBox3D as it will not provide 2D-Reps compuatation
//--------------------------------------
//some Immediate2DDraw are considered for compuatation as 3D-Reps
//To change Render compuatation flag use SetConstraint()
//To allow Render compuatation with LOD use SetUseCoarseLod(true)
//Both flag can be set at time of instance creation
//*****************************************************************************
//  Inheritance:
//  ------------
//                    CAT3DBoundingBoxRender
//                      CATRender
//
//*****************************************************************************
//  Main Methods:
//  -------------
//  Overload draw methods for all 3D graphical primitives.
//
//  Overload matrix methods to ensure proper transformation of graphical
//  primitive vertices.
//
//  Some other control methods have been overloaded too to ensure a complete
//  tree transversal.
//
//*****************************************************************************

/*
Function : 3D Bounding Box Render
Inputs : points,CATPixelImagex,Offset,yOffset and alpha values
Output : Bounding box values
Failure : IF failed to to calculate vlaues then default bounding box will return
*/
//  Mathematics
#include "SGInfra.h"
#include "CATMathPointf.h"
#include "CATMathLimits.h"

//  Visualization
#include "CATRepRender.h"
#include "CAT4x4Matrix.h"
#include "CAT3x3Matrix.h"
#include "list.h"
#include "CATBooleanDef.h"
#include "CATDisableRender.h"
#include "CATCGMSTDSafeIncludeStart.h"
#include <vector>
#include <memory>
#include "CATCGMSTDSafeIncludeEnd.h"

#include <VisFilteringEnums.h>

// Multithreading dev
//#include "CATVisClippingFilter.h"
#include "DSYSysAtomic.h"
#include "DSYSysSemaphore.h"

// 2D and 3D entities
#define DIMTWO 2
#define DIMTHREE 3

// 0D, 1D, and 3D Topological Entities
#define TYPEPOINT 1
#define TYPELINE 2
#define TYPEFACE 0

struct vBoundsData;
struct vBoundingBoxDrawBase;
class  vBoundingBoxFilterStack;
class CATVisClippingFilter;
class vBoundingBoxCmdDispatcher;

namespace VKL
{
  class vTaskNode;
  class vWorkerThread;
}

class CAT3DBagRep;
class CAT3DPolylineGP;
class CATMathTransformation;
class CATMathPoint;
class CATVisFilter;
class l_CATVisClippingFilter;
class l_CATVisClippingSectionsFilter;
class l_CATVisScissorFilter;
class l_CATVisFilter;

class CAT3DPointCloudRep;
class CAT3DBlockCloudRep;

/*
BoundConstraint flag decides which kind of computation BoundingBox render consider
*/
enum BoundConstraint
{
  eDefault = 0,                   //default 0  computes two BoundingBox 1] only 3D 2] 3D and 2D(lines,markergps,wireframe)
  eCalculateOnlyWithWireframe,    //Computes BB for 3D and 2D no sperate only 3D BB
  eXAxisMin,                      //Min point along X axis  includes 3D,2D GPs
  eYAxisMin,                      //Min Point along Y axis
  eZAxisMin,                      //Min Point along Z axis
  eVolumicsOnly,                  //compute bounding box only for Volumic GPs.
  eAllGeometries                  //compute bounding box for all GPs
};

class ExportedBySGInfra CAT3DBoundingBoxRender : public CATRepRender
{
  CATDeclareClass_Deprec;

  //-------------------------------------------------------------------------------------------
public:
  //  Constructors/destructors
  //--------------------------
  CAT3DBoundingBoxRender(const CATSupport& support, const CATMathTransformation& iMatrix, BoundConstraint iFlag = eDefault, bool iUseCoarseLOD = false);

  CAT3DBoundingBoxRender(const CAT3DBoundingBoxRender& brother);

  ~CAT3DBoundingBoxRender();

  virtual int IsOutside(const float, const float, const float);

  //  Drawing testing methods
  //--------------------------
  virtual int IsDrawable(const CATGraphicAttributeSet&, const CAT2DBoundingBox&, const CATRep&);

  virtual int IsDrawable(const CATGraphicAttributeSet&, const CAT2DBoundingBox&, const int SubElementId);

  virtual int IsDrawable(const CATGraphicAttributeSet& attribute, const float* center, const float radius, const int SubElementId);

  virtual int IsDrawable(const CATGraphicAttributeSet& attribute, const CAT3DBoundingSphere&, const CATRep&, CATGraphicMaterial* iMat = 0);

  virtual int IsDrawable(const CATGraphicAttributeSet&, const CAT3DBoundingSphere&, const int SubElementId);

  virtual int IsDrawable(const CATGraphicAttributeSet& attribute, const int SubElementId);

  virtual int IsDrawable(const CATGraphicAttributeSet& attribute, const CATRep&, CATGraphicMaterial* iMat = 0);

  virtual int IsDrawable(const CATGraphicAttributeSet& attribute, CATGraphicMaterial* iMat);

  virtual int IsDrawable(const CATGraphicAttributeSet& attribute);

  virtual int IsDrawable(const int SubElementId);

  virtual int IsSeen(const float*, const float*);
  virtual int IsToSmall(const CAT3DBoundingSphere&);
  virtual int IsToSmall(const CAT2DBoundingBox&);
  virtual int IsInside(const CAT3DBoundingSphere&);
  virtual int IsInside(const CAT2DBoundingBox&);

  // Defining minimal size & level of detail methods:
  //------------------------------------------------
  virtual float Get3DModelCulling(const CAT3DBoundingSphere&) const;

  virtual int   Get3DLODNumber(const CAT3DBoundingSphere& iBS3D, const int iNbOfLOD, const float sagArray[]) const;

  virtual float Get3DModelSag(const CAT3DBoundingSphere& iBS3D) const;

  // Graphical elements draw methods:
  // --------------------------------
  //If you override these methods, make sure to call the same of this class
  virtual void DrawRepresentation(CATRep& iRep);
  virtual int DrawRepresentation(CATRep& iRep, int iInside, void*& iData);
  virtual int EndDrawRepresentation(CATRep& iRep, void*& iData);
  virtual void Draw(::list<CATViewpoint>& viewpoint, const int, const float);
  // --------------------------------

  virtual void Draw3DMarker(CAT3DMarkerGP&);
  virtual void Draw3DPolyline(CAT3DPolylineGP&);
  virtual void Draw3DLine(CAT3DLineGP&);
  virtual void Draw3DEdge(CAT3DEdgeGP&);
  virtual void Draw3DFace(CAT3DFaceGP&);
  virtual void Draw3DPlanarFace(CAT3DPlanarFaceGP&);
  virtual void Draw3DCylinder(CAT3DCylinderGP&, const int = 0);
  virtual void Draw3DCurvedPipe(CAT3DCurvedPipeGP&);
  virtual void DrawDynamicGP(CATDynamicGP&);

  virtual void DrawCATViz3DFace(CATViz3DFace* face);
  virtual void DrawCATViz3DEdge(CATViz3DEdge* edge);
  virtual void DrawCATViz3DLine(CATViz3DLine* line);
  virtual void DrawCATViz3DMarker(CATViz3DMarker* marker);
  virtual void DrawCATVizDynamicPrimitive(CATVizDynamicPrimitive& dprimitive);

  virtual void Draw2DMarker(CAT3DMarkerGP& marker);

  virtual void Draw2DArcCircle(CAT2DArcCircleGP& circle2);
  virtual void Draw2DArcEllipse(CAT2DArcEllipseGP& ellipse2);
  virtual void Draw2DLine(CAT2DLineGP& line2);
  virtual void Draw2DPolygon(CAT2DPolygonGP& polygon2);
  virtual void Draw2DRectangle(CAT2DRectangleGP& rectangle2);
  virtual void Draw3DEdges(CAT3DEdgeGP** edge3L, int nedge, int m);
  virtual void Draw2DGeometricText(CAT2DGeometricTextGP& text2);

  virtual void DrawVisPrimitive(VisPrimitive& primitive);

  virtual void ImmediateDraw3DMarker(const float* points, const int nb_points, SymbolType symbol);
  virtual void ImmediateDraw3DLine(const float* ipPoints, const int iPointCount, const int iLineType = 0, TessFlag iTessStatus = LINE);
  /*
  Function : 3D Bounding Box Render
  Inputs : points,CATPixelImagex,Offset,yOffset and alpha values
  Output : Bounding box values
  Failure : IF failed to to calculate vlaues then default bounding box will return
  */
  virtual void ImmediateDraw3DImagePixel(const float* point, const CATPixelImage* image, const int xOffset, const int yOffset, const int alpha);

  virtual void Draw3DIndexedLine(CAT3DIndexedLineGP& iGP);
  virtual void ImmediateDrawTriangle(float* v1, float* v2, float* v3);
  virtual void ImmediateDraw2DLine(const float* points, const int nb_points, TessFlag TessStatus);
  virtual void ImmediateDraw2DLine(const float* points, const int nb_points, const int line_type = 0, TessFlag TessStatus = LINE);

  virtual void Draw2DMarker(CAT2DMarkerGP& marker);
  virtual void ImmediateDraw2DAnnotationText(const float* point, const CATUnicodeString& text, CATAnchorPoint position = BASE_LEFT, const float height = 0.f, const int contour = 0, const CATGraphicAttributeSet* contour1 = NULL, const CATGraphicAttributeSet* contour2 = NULL);
  virtual void ImmediateDraw3DAnnotationText(const float* point, const CATUnicodeString& text, AnchorPoint position = BASE_LEFT, const float height = 0.f, const int contour = 0);
  virtual void ImmediateDraw2DGeomText(CATFont* font, const CATUnicodeString& text, CAT2DGeomTextAttributeSet& attset, const float height, const int rendertype);
  virtual void ImmediateDraw2DImagePixel(const float* point, const CATPixelImage* image, const int alpha, const int xOffset = 0, const int yOffset = 0);
  virtual void ImmediateDraw2DQuadStrip(const float* points, const int nb_points, const float* vertexcolors);
  virtual void ImmediateDraw2DQuadStrip(const float* i_pPoints, const int i_nbPoints, const float* i_pVertexcolors, const CATBoolean& i_formatRGBAFlag);
  virtual void ImmediateDraw2DMarker(const float* points, const int nb_points, SymbolType symbol);
  virtual void ImmediateDraw2DPolygon(const float* points, const int nb_points, const int fill, const int nb_triangle = 0, const int* type = 0, const int* triangle = 0, const int* vertex = 0, TessFlag TessStatus = LINE);
  virtual void ImmediateDraw2DPolyline(const float* points, const int nb_points, TessFlag TessStatus = LINE);

  virtual void DrawPointCloud(const CAT3DPointCloudRep& iRep);
  virtual void DrawBlockCloud(const CAT3DBlockCloudRep& iRep);

  // Matrix
  //--------
  //The returned object must be destroyed
  virtual CATRender* PushMatrix(CAT4x4Matrix& matrix);
  virtual void        PopMatrix(CATRender* render);
  virtual CATRender* PushMatrix(CAT3x3Matrix& iMatrix);

  void SetMatrix(const CAT4x4Matrix& matrix);
  void SetMatrix(const CATMathTransformation& matrix);

  // Manage Clipping filters/ Clipping/ Scissor sections
  //---------------------------------------------------------------
  virtual int GetFiltersApply() { return _filtersApply; };
  virtual void SetFiltersApply(int iFiltersApply)
  {
    //if iFiltersApply is nonzero, set to 1 else set to 0
    _filtersApply = (iFiltersApply != 0) ? 1 : 0;
    //if the global clipping filter is added at the time of constructor,
    //there we dont know if filters apply will be 0 or 1 again but we set filterexist to 1.
    // hence if filtersapply is set to 0 here, we have  to reset filterexist and coarse box state
    //We dont need global clipping filter so we remove it 
    if (0 == _filtersApply && _bHasGlobalClipFilter)
    {
      RemoveClippingPlanes((float*)nullptr);
      _filtersExist = 0;
      UpdateCoarseBoxState();
    }
    _ComputeFlagsFromOptions();
  };

  /*
  * Consider 2D Reps Inside rep tree for BoudingBoxRender computation
  * To run BoundingBoxRender for 2D-Reps it is mandatory to provide CATSupport constructed using
  * correct width and height in CAT3DBoundingBoxRender constructor and valid viewpoint and viewport .Please Refer example 2 at start of header
  */
  virtual void SetEnable2DReps(int iEnable2DReps) { _enable2DReps = iEnable2DReps; };
  virtual int GetEnable2DReps() { return _enable2DReps; };

  virtual int GetCurrentMatrix(CAT4x4Matrix& oMatrix) { oMatrix = _matrix; return 1; };

  virtual void PushFilter(CATVisFilter* filter);
  virtual void PopFilter(CATVisFilter* filter);

  /*
    * By default, (global) clipping planes will be considered from the CATSupport used to construct CAT3DBoundingBoxRender
    * If called explicitely, aleready added global clipping planes if any, will be replaced with ipClippingData
    */
  virtual void AddClippingPlanes(float* ipClippingData);
  /*
    * for clipping planes on the viewer
    * remove global clipping planes if any with new global clipping planes
    */
  virtual void RemoveClippingPlanes(float* ipClippingData);

  // clipping planes on the FilterBagRep
  virtual void AddClippingPlanes(l_CATVisClippingFilter* ipClippingFilter);
  virtual void RemoveClippingPlanes(l_CATVisClippingFilter* ipClippingFilter);

  // clipping sections on the FilterBagRep
  virtual void AddClippingSections(l_CATVisClippingSectionsFilter* ipClippingSectionsFilter);
  virtual void RemoveClippingSections(l_CATVisClippingSectionsFilter* ipClippingSectionsFilter);

  // scissor polygon on a FilterBagRep
  virtual void AddScissor(l_CATVisScissorFilter* ipScissorFilter);
  virtual void RemoveScissor(l_CATVisScissorFilter* ipScissorFilter);

  // Processing
  //------------
  virtual void InitializeExtremities(const float* vertex, const int index);
  virtual void EvaluateAsNewExtremityPoint(const float* vertex, const int index);

  // Result query
  //-------------
  HRESULT GetBoundingBox(CATMathPoint& oMinPoint, CATMathPoint& oMaxPoint) const;
  HRESULT GetBoundingBoxd(CATMathPoint& oMinPoint, CATMathPoint& oMaxPoint) const;
  HRESULT GetBoundingBox(CATMathPointf& oMinPoint, CATMathPointf& oMaxPoint) const;

  HRESULT GetBoundingBox3D(CATMathPointf& oMinPoint, CATMathPointf& oMaxPoint) const;
  HRESULT  GetBoundingBoxMinAlongAxis(double& oMinPoint) const;

  void Reset(void);

  void DisableDynamicElements();
  void DisableMarkerElements();
  void DisableLineicElements();

  inline void SetConstraint(BoundConstraint iFlag);
  inline void SetUseCoarseLod(bool iFlag);
  inline  int GetfiltersComputing() { return _filtersExist; };
  inline  int GetMarkerElements() { return _disableMarkerElements; };
  inline  int GetLineicElements() { return _disableLineicElements; };
  inline  int Get2DRepElements() { return _enable2DReps; };

  //Multithreading
  void EnableMultithreading(int numThreads);
  void DisableMultithreading();

  virtual bool IsA3DBoundingBoxRender() const { return true; }

  // A2X API to retrieve box for Annotation
  HRESULT GetAnnotationSizes(const float* point, const CATUnicodeString& text, CATAnchorPoint position, const float hauteur, const int contour, int& ioHeight , int& ioWidth, int& ioDescent);
protected:
  //If you override this methods, make sure to call the same of this class
  void DrawViewpoint(CATViewpoint* iVpt);

  virtual void Draw3DCanonicalRep(CAT3DCanonicalRep& iRep);

  //-------------------------------------------------------------------------------------------
private:
  void Init(const CATSupport& support, const CATMathTransformation& iMatrix, BoundConstraint iFlag, bool IsLODModeOn);
  // Processing
  // ----------
  void EvaluateAsNewExtremityPoint(const float* vertex, const int index, short i_type);
  void EvaluateAsExtremityLine(const float* ipVertex1, const float* ipVertex2, short iType);
  void EvaluateAsExtremityTriangle(const float* ipVertex1, const float* ipVertex2, const float* ipVertex3, short iType);

  //Multithreading dev

  /* Check whether local GP bbox (if available) is filtered
   away from any CATVisClippingFilter planes (as part of early-rejection mechanism) */
   //bool IsFaceGPBoxClippedAway(CAT3DFaceGP&);
  VisFilterResult IsBoxFiltered(const float iCenter[], const float iDimension[]);

  int IsPointFiltered(const float iXLoc, const float iYLoc, const float iZLoc);
  int IsLineFiltered(const float iX1Loc, const float iY1Loc, const float iZ1Loc,
    const float iX2Loc, const float iY2Loc, const float iZ2Loc,
    float*& opFilteredLineGlobTab, int& oFilteredLineCount);
  int IsTriangleFiltered(const float iX1Loc, const float iY1Loc, const float iZ1Loc,
    const float iX2Loc, const float iY2Loc, const float iZ2Loc,
    const float iX3Loc, const float iY3Loc, const float iZ3Loc,
    float*& opFilteredTriangleGlobTab, int& oFilteredTriangleCount);
  bool EvaluateAsPolygon(const float* iTriangle, short iType);

  inline static void MatrixMultiply(const float* Vertex, const float* matrix, float oP[3]);
  inline static void MatrixMultiplyd(const double* Vertex, const double* matrix, double oP[3]);

  void OP_EvaluateVertices(const float* vertex, const int nb_point, short i_type, int offset = DIMTHREE);
  void OP_FaceTriIndex(const int* triIndex, const float* vertex, const int trinum, short iType);
  void OP_FaceStripIndex(const int* triIndex, const float* vertex, const int trinum, int const* numVertsInStrip, short itype);

  enum class BBoxStates
  {
    eFiniteValidBox = 0,  // return S_OK, min[i]<max[i] and min[i]!=INF, max[i]!=-INF
    eMinInfiniteMaxFinite, //return S_OK, min[i] = max[i] when min[i]=INF
    eMaxInfiniteMinFinite,//return S_OK, max[i] = min[i] when max[i]=-INF
    eFiniteInvalidBox,// return E_FAIL, min[i]>max[i] and min[i]!=INF, max[i]!=-INF
    eInfiniteBox     // return E_FAIL, min[i]=INF and max[i]=-INF
  };
  /**
   @brief Checks if the Global bounding(d or 3D) is valid or not and make it valid.
   @param oMinPoint- out variable to stores validated box min point
   @param oMaxPoint- out variable to stores validated box max point
   @param is3DBoxQueried- if true it validates 3d box else if false validated d version of box.
   @return BBoxStates of the original box before making it valid
  */
  BBoxStates MakeBBoxValid(CATMathPoint& oMinPoint, CATMathPoint& oMaxPoint, bool is3DBoxQueried = false) const;
  //-------------------------------------------------------------------------------------------

protected:
  // Global
  // ------
  CATMathPoint	   _maxPointd;
  CATMathPoint    _minPointd;

  CAT4x4Matrix    _matrix;      // Aggregate transform for node of Rep
  CAT3DBagRep* _rep;         // Rep corresponding to the processed render

  //-------------------------------------------------------------------------------------------
private:
  //Surcharge de l'opérateur =
  CAT3DBoundingBoxRender& operator = (const CAT3DBoundingBoxRender&);

  BoundConstraint _iFlag;
  int _matrixActivation = 0;

  MatrixState _matrixState;
  MatrixScaling _matrixScaleState;

  int BBRENDER_NUM_WORKER_THREADS = 0;

  /* @param axis_
  For boundingbox computation along single axis, axis_ is  0,1,2 index for x,y,z axis
  */
  int _axis;
  mutable bool _IsLOD;
  bool _UseCoarseLOD;
  // 3DBox
  // -----
  CATMathPoint   _minPoint3D;    // Min (x,y,z) of bounding box
  CATMathPoint   _maxPoint3D;    // Max (x,y,z) of bounding box


  unsigned int _disableDynamicElements : 1;
  unsigned int _disableMarkerElements : 1;
  unsigned int _disableLineicElements : 1;
  unsigned int _filtersApply : 1;
  unsigned int _filtersExist : 1;
  unsigned int _enable2DReps : 1;

  HRESULT _errorCode;
  ::list<l_CATVisFilter>	_stackFilters;
  CATDisableRender* _disableRender;

  struct MatrixData {
    float matrix[16];

    MatrixData(
      const CAT4x4Matrix& v
    )
    {
      v.GetMatrixInFloat(matrix);
      //memcpy(matrix, v.GetMatrix(), sizeof(float)*16);
    }


    MatrixData(const MatrixData& iMatrixPointData)
    {
      memcpy(matrix, iMatrixPointData.matrix, sizeof(float) * 16);

    }

    void GetData(
      CAT4x4Matrix& vr)
    {
      vr.SetElements(matrix);
    }
  };

  typedef std::vector<MatrixData> MatrixStack;
  MatrixStack _matrixStack;

  //NPE3++

  bool _matHasRotation;
  //we are not having new variable for filter as 
  enum class eCoarseBoxState
  {
    eCB_INITIATED,    //initial state
    eCB_UNDER_ROT, //set when GP is under rotation 
    eCB_UNDER_FILTER,  // set when GP is under filter
    eCB_UNDER_ROTFILTER,   //set when GP is under rotation as well as filter
    eCB_UNDER_NONE,    // set when rotated or filtered GP encountered earlier but not this GP 
  };
  eCoarseBoxState _eGCBState; //global coarse bounding box state

  //to denote which pass we are in, 
  //legal values: 0,1,2
  short _coarsePassID;
  //first rep hit when draw called with this render
  CATRep* _pBeginRep;
  //If true we are required do second draw pass
  bool _bSecondPassRequired;
  // if true, means  First draw is called on viewpoint
  bool _bDrawOnViewPoints;
  //true if global clipping plane filter is added else false
  bool _bHasGlobalClipFilter;
  //currant matrix scales
  double _currentMatrixScales[3];
public:
  //Get current state of Matrix
  inline MatrixState GetCurrentMatrixState();
  //Get current state of scaling in Matrix
  inline MatrixScaling GetCurrentMatrixScalingState();
  /*
  * Computes the matrix state enum depending on matrix data
  * state of Matrix is enum- MatrixState
  * state of Scaling is enum- MatrixScaling
  */
  void ComputeMatrixAndScaleState(CAT4x4Matrix& iMatrix);
private:

  /**
  * Compare and update the bounding box dependeing on the state of matrix and state of scale of matrix
  * @param iGPlocalMinPoint - local min point of GP
  * @param iGPlocalMaxPoint - local max point of GP
  * @return
  * true if the box is updated and can ignore further processing.
  * false if the box is not updated and needs further processing.
  */
  bool CompareUpdateBoxOnMatrixState(const CATMathPoint& iGPlocalMinPoint, const CATMathPoint& iGPlocalMaxPoint);

  /**
  * Compute Bounding Box which covers the Bounding Sphere defined by center and radius
  * @param iCenter-
  * center of Bounding Sphere as array of 3 float variable
  * @param iRadius-
  * radius of Bounding sphere
  * @param opMinPoint, opMaxPoint-
  * out paramters containing minpoint and maxpoint of Bounding box
  */
  HRESULT GetBBoxOfBSphere(const float iCenter[], double iRadius, CATMathPoint* opMinPoint, CATMathPoint* opMaxPoint);

  /**
  * Updates the state depending on rotation matrix and filter existense
  * @return
  * true if the state has changed
  * false if the state hasnt changed
  */
  bool UpdateCoarseBoxState();

  /**
  * return true : GP Box is inside; Discard GP
  * return false: otherwse; go for the computation
  */
  bool CoarseCompareAndUpdateGlobalBox(const CATMathPoint& iMinPoint, const CATMathPoint& iMaxPoint);
  /**
  * Checks if incoming box is inside the global coarse box
  * @param iMinPoint-
  * minpoint of box to check
  * @param iMaxPoint
  * maxpoint of box to check
  * @return
  * true if inside the coarse
  * false if not inside the box
  */
  bool IsBoxInsideGlobalBox(const CATMathPoint& iMinPoint, const CATMathPoint& iMaxPoint);
  bool IsBoxInsideGlobalBox3D(const CATMathPoint& iMinPoint, const CATMathPoint& iMaxPoint);
  void CoarseUpdateGlobalBoxWithLocalBox(const CATMathPoint& iMinPt, const CATMathPoint& iMaxPt);
  void CoarseUpdateGlobalBox3DWithLocalBox(const CATMathPoint& iMinPt, const CATMathPoint& iMaxPt);

  bool IsLocalGPBoxInsideGlobalBox(const float iCenter[], const float iDimension[]);

  /**
 * Check if Coarse box is filtered or not
 * Updates the min and maxpoint to the filtered box min and max point
 * param: oBoxMinPt : Minpoint of box to be checked if filtered
 * param: oBoxMaxPt : MaxPoint of box to be checked if filtered
 * return : true, filtered out. false, inside or intersecting
 */
  VisFilterResult GetBoxFiltered(const float iCenter[], const float iDimension[], CATMathPoint& oBoxMinpt, CATMathPoint& oBoxMaxpt);

  /*
  * This method returns Axis aligned box of 8 transformed corners computed from iCenter and iDimension
  */
  void CreateBoxFromLocalBox(const float iCenter[], const float iDimension[], CATMathPoint& oBoxMinpt, CATMathPoint& oBoxMaxpt);
  /*
  * Executes Both coarse passes
  * true=> can reject the GP false=> process it
  */
  bool ExecuteCoarsePass(float iCenter[], const float iDimension[], const float iSphereCenter[], const double iSphereRadius, VisFilterResult& oFilterRes);

private:
  enum class eBBoxOptimizeMode
  {
    eSerial = 0, //SERIAL
    eHybrid = 1, //(MT,SERIAL)
    //eSerialCoarse1Pass, 1 pass, not necessary, 
    //updates coarse and processes and updates precise for the same GP, so no rejecton possible hence not necessary.
    eSerialCoarse2Pass = 2, //(Serial,2Pass)
    eHybridCoarse1Pass = 3, //(MT,1Pass) default
    eHybridCoarse2Pass = 4, //(MT,2Pass)
  };
  eBBoxOptimizeMode _optiMode;
private:
  //API to set optimization  mode
  void SetOptimizationMode(eBBoxOptimizeMode iOptiMode);
  //NPE3--

protected:

  // NER2 ++ BoundingBoxOptimization
  CATRep* _entryPointRep;
  CATMutex _boundsMutex;
  CATMutex _updateMutex;
  vBoundsData* _computedBounds;  // cannot be a member, vstype : define it like vBoundsData _computedBounds;

  std::unique_ptr<vBoundingBoxCmdDispatcher>  _taskDispatcher; //task queue for job submission

  void InitMultiThreading();

public:
  typedef unsigned int uint32;

  enum Flags
  {
    fDynamicElementsDisabled = 1 << 0,
    fMarkersElementsDisabled = 1 << 1,
    fLineicElementsDisabled = 1 << 2,
    fUseCoarseLod = 1 << 3,
    f2DRepsEnabled = 1 << 4,
    fFiltersEnabled = 1 << 5,
    fCompute3DBoundsSeparately = 1 << 6,
    fComputeOnlyMinX = 1 << 7,
    fComputeOnlyMinY = 1 << 8,
    fComputeOnlyMinZ = 1 << 9,
    fDefaultFlags = fCompute3DBoundsSeparately,

    fFlags_LastFlag = 1 << 10, // @nodoc
  };

  // @nodoc
  enum State
  {
    fFiltersComputing = fFlags_LastFlag << 0,
    fMatrixComputing = fFlags_LastFlag << 1, // _matrixActivation
    fLodInUse = fFlags_LastFlag << 2, // _IsLOD
    fIs3DElement = fFlags_LastFlag << 3,

    fState_LastFlag = fFlags_LastFlag << 4,
  };

  enum StateFlagsCombinations
  {
    fActive3DMode = fIs3DElement | fCompute3DBoundsSeparately,
  };

private:

  // specialized members (MT specific)
  inline void _QueueTask(vBoundingBoxDrawBase* command);
  void _InitializeCommand(vBoundingBoxDrawBase* command);

  void _PushFilter_MT(l_CATVisFilter* iFilter);
  void _PopFilter_MT();
  void _NewFilterStack();
  void _ComputeOptionsFromFlags();
  void _ComputeFlagsFromOptions();

  bool IsFilterStackInUse() const;

  // #section CAT3DBoundingBoxRender
  // Functions that should rather be in CAT3DBoundingBoxRender
  bool AreDynamicElementsDisabled() const { return CAT3DBoundingBoxRender::_disableDynamicElements != 0; }
  inline bool AreMarkerElementsDisabled() const { return _disableMarkerElements != 0; }
  inline bool AreLineicElementsDisabled() const { return _disableLineicElements != 0; }
  inline bool GetUseCoarseLOD() const { return _UseCoarseLOD; }
  inline BoundConstraint GetConstraint() const { return _iFlag; }

  // #section Recompute
  // we recompute these variables when draw is called
  unsigned int _flags;

  vBoundingBoxFilterStack* _filterStackMT;

  //---------------Refactored methods------------------  
  //This method takes global point
  //Compares with global bounding box both d and 3D version and updates it
  //does not check for IsPointFiltered
  /**
  * @brief Compares with global bounding box both d and 3D version and updates it.
           It does not check for IsPointFiltered.
           To Update 3D Point it checks for _iFlag not Type
    @param iGlobPoint point in Global coordinate (Transformed)
  */
  void CompareUpdateGlobalBox(const CATMathPoint& iGlobPoint);
  /**
  @brief Compare the point with global bounding box and updates it.
         If the matrix is non indentity it transforms the point.
         If there are filters, it checks if the input point is filtered out or not,
         and updates only when point is not filtered out
         This method shall not be called, if _iFlag is eVolumics

  @param iLocalX local x coordinate of point
  @param iLocalY local y coordinate of point
  @param iLocalZ local z coordinate of point
  */
  void EvaluatePointAndUpdateGlobalBoxWithFlags(const double iLocalX, const double iLocalY, const double iLocalZ, short iType);
  void Draw3DFace_MT(CAT3DFaceGP&, const int, const CATMathPoint&, const CATMathPoint&);
  void Draw3DFace_Serial(CAT3DFaceGP&);

  void Draw3DMarker_MT(CAT3DMarkerGP&, const int);
  void Draw3DMarker_Serial(CAT3DMarkerGP&);


  void DrawCATViz3DFace_MT(CATViz3DFace*, const int);
  void DrawCATViz3DFace_Serial(CATViz3DFace*);

};

inline void CAT3DBoundingBoxRender::SetConstraint(BoundConstraint iFlag)
{
  Reset();
  _iFlag = iFlag;
  _axis = iFlag - eXAxisMin;
};

inline void CAT3DBoundingBoxRender::SetUseCoarseLod(bool iFlag)
{
  Reset();
  _UseCoarseLOD = iFlag;
}

inline void CAT3DBoundingBoxRender::MatrixMultiply(const float* Vertex, const float* matrix, float oP[3])
{
  float lx = Vertex[0];
  float ly = Vertex[0 + 1];
  float lz = Vertex[0 + 2];

  oP[0] = matrix[0] * lx + matrix[4] * ly + matrix[8] * lz + matrix[12];
  oP[1] = matrix[1] * lx + matrix[5] * ly + matrix[9] * lz + matrix[13];
  oP[2] = matrix[2] * lx + matrix[6] * ly + matrix[10] * lz + matrix[14];
}

inline void CAT3DBoundingBoxRender::MatrixMultiplyd(const double* Vertex, const double* matrix, double oP[3])
{
  double lx = Vertex[0];
  double ly = Vertex[0 + 1];
  double lz = Vertex[0 + 2];

  oP[0] = matrix[0] * lx + matrix[4] * ly + matrix[8] * lz + matrix[12];
  oP[1] = matrix[1] * lx + matrix[5] * ly + matrix[9] * lz + matrix[13];
  oP[2] = matrix[2] * lx + matrix[6] * ly + matrix[10] * lz + matrix[14];
}
inline MatrixState CAT3DBoundingBoxRender::GetCurrentMatrixState()
{
  return _matrixState;
}
inline MatrixScaling CAT3DBoundingBoxRender::GetCurrentMatrixScalingState()
{
  return _matrixScaleState;
}
#endif
