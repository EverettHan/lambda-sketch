#ifndef CATPickingRender_H
#define CATPickingRender_H

//******************************************************************************
//  CATIA Version 5 Release 1 Framework VFW2
//  Copyright Dassault Systemes 1996
//******************************************************************************
//  Abstract:
//  ---------
//    Render needed to draw the scene to determine what's lying 'under' the
//    mouse.
//
//******************************************************************************
//  Usage:
//  ------
//    Picking disable any kind of backface culling, due to the needs of deep
//    selection. The result of the picking is the filled CATPickPathList given
//    at the object creation. This list contains informations about the element
//    and the way it has been picked (depth of picking, intersection point,
//    normal at intersection, etc...).
//
//    During creation the CATPickingRender takes the viewing configuration of
//    it's support, and then applies some settings on what is to be drawn:
//      - OUTLINES are disabled,
//      - In HLR, MESH and EDGE are both activated.
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CATPickingRender
//                  CATRepRender
//                    CATRender
//
//******************************************************************************
//  Main Methods:
//  -------------
//
//******************************************************************************
#include "SGInfra.h"

#include "CATRepRender.h"
#include "CATMathPoint.h"
#include "CATMathPointf.h"
#include "CATMathVectorf.h"
#include "CATSymbolType.h"
#include "CATGraphicPrimitive.h"
#include "CATAnchorPoint.h"
//#include "CATVizPtrList.h"
#include "CATRefinementEngine.h"
#include "VisConnectivityType.h"
#include "VisDataType.h"
#include <stack>
#include "CATPickPath.h"

class CATRep;
class CATSupport;
class CATGraphicAttributeSet;
class CAT2DBoundingBox;
class CAT3DBoundingSphere;
class CAT2DBoundingSphere;
class CATGraphicMaterial;
class CATMathDirectionf;
class CATPickPathList;
class CATPickPath;
class CAT2DGeometricTextGP;
class CAT3DEdgeGP;
class CAT3DFaceGP;
class CAT3DPlanarFaceGP;
class CAT3DIndexedLineGP;
class CAT3DCylinderGP;
class CAT3DCurvedPipeGP;
class CATDynamicGP;
class CAT4x4Matrix;
class CAT3x3Matrix;
class CATViewpoint;
class CAT3DViewport;
class CATVis2DModeFilter;
class CATMathPlane;
class CATMathPoint2Df;
class CATMathBox;

class CATViz3DFace;
class CATViz3DEdge;
class CATViz3DLine;
class CATViz3DMarker;
class CATVizDynamicPrimitive;
class CATVizUV3DLine;
class l_CATVisClippingSectionsFilter;
class CATVisTetrahedron;
class VisPrimitive;
class VisRawBuffer;

class CAT3DPointCloudRep;
class CAT3DBlockCloudRep;
class l_CATVisClippingVolumesFilter;
class CATVisClippingFilter;

class ExportedBySGInfra CATPickingRender : public CATRepRender
{
  CATDeclareClass_Deprec;
  friend class SGInfraToVisuFConnectToolImpl;

public:

  CATPickingRender(const CATSupport &support, const float x, const float y, const float dx, const float dy, CATPickPathList &pickPathList);
  CATPickingRender(const CATPickingRender &);
  virtual ~CATPickingRender();

  virtual int DrawRepresentation(CATRep &iRep, int iInside, void* &iData);
  virtual int EndDrawRepresentation(CATRep &iRep, void* &iData);

  virtual void InheritAttributes(CATGraphicAttributeSet const*, int);

  virtual int IsDrawable(const CATGraphicAttributeSet &, const CAT2DBoundingBox &, const CATRep &);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const CAT2DBoundingBox &, const int SubElementId);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const float *center, const float radius, const int SubElementId);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const CAT3DBoundingSphere &, const CATRep &, CATGraphicMaterial *iMat = 0);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const int SubElementId, const int type);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const list<int>& ipSubElementIdList, const int iType);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const int SubElementId);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const list<int>& ipSubElementIdList);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const CATRep &, CATGraphicMaterial *iMat = 0);
  virtual int IsDrawable(const CATGraphicAttributeSet &, CATGraphicMaterial *iMat);
  virtual int IsDrawable(const CATGraphicAttributeSet &);
  virtual int IsDrawable(const int);
  virtual int IsDrawable(const list<int>&);
  virtual int IsDrawable(VisAttribute& iAttribut, const int SubElementId);

  virtual int IsToSmall(const CAT3DBoundingSphere &);

  virtual void SetCurrentAttribute(const CATGraphicAttributeSet &);

  virtual int Get3DLODNumber(const CAT3DBoundingSphere & iBS3D, const int iNbOfLOD, const float sagArray[]) const;

  //  hidden faces must be picked
  //  ---------------------------

  virtual int IsSeen(const float *, const float *);

  virtual void Draw2DGeometricText(CAT2DGeometricTextGP &);
  virtual void Draw3DEdge(CAT3DEdgeGP &);
  virtual void Draw3DFace(CAT3DFaceGP &);
  virtual void Draw3DPlanarFace(CAT3DPlanarFaceGP &);
  virtual void Draw3DIndexedLine(CAT3DIndexedLineGP &iGP);
  virtual void Draw3DCylinder(CAT3DCylinderGP &, const int = 0);
  virtual void Draw3DCurvedPipe(CAT3DCurvedPipeGP &);
  virtual void DrawDynamicGP(CATDynamicGP &);
  virtual void DrawCATVizDynamicPrimitive(CATVizDynamicPrimitive &);
  virtual void DrawVisPrimitive(VisPrimitive &);
  virtual void DrawCATVizUV3DFace(CATVizUV3DFace *face);
  virtual void DrawCATVizUV3DEdge(CATVizUV3DEdge *edge);
  virtual void DrawCATVizUV3DLine(CATVizUV3DLine *line);

  virtual void ImmediateDraw3DMarker(const float *points, const int nb_points, SymbolType symbol);
  virtual void ImmediateDraw3DLine(const float *points, const int nb_points, const int line_type = 0, TessFlag TessStatus = LINE);
  virtual void ImmediateDraw3DAnnotationText(const float *point, const CATUnicodeString &text, AnchorPoint position = BASE_LEFT, const float height = 0.f, const int contour = 0);
  virtual void ImmediateDraw3DImagePixel(const float *point, const CATPixelImage *image, const int xOffset, const int yOffset, const int alpha);

  virtual void ImmediateDraw2DMarker(const float *points, const int nb_points, SymbolType symbol);
  virtual void ImmediateDraw2DLine(const float *points, const int nb_points, const int line_type = 0, TessFlag TessStatus = LINE);
  virtual void ImmediateDraw2DAnnotationText(const float *point, const CATUnicodeString &text, AnchorPoint position = BASE_LEFT, const float height = 0.f, const int contour = 0, const CATGraphicAttributeSet *contour1 = NULL, const CATGraphicAttributeSet *contour2 = NULL);
  virtual void ImmediateDraw2DImagePixel(const float *point, const CATPixelImage *image, const int alpha, const int xOffset = 0, const int yOffset = 0);
  virtual void ImmediateDraw2DPolygon(const float *points, const int nb_points, const int fill, const int nb_triangle = 0, const int *type = 0, const int *triangle = 0, const int *vertex = 0, TessFlag TessStatus = LINE);
  virtual void ImmediateDraw2DQuadStrip(const float *i_pPoints, const int i_nbPoints, const float *i_pVertexcolors, const CATBoolean& i_formatRGBAFlag);
  //  virtual void ImmediateDrawVoxelTree        (CATVizVoxelGP *gp, int levelToDraw, int drawWithPoints = 0, float pointSize = 1.0f);

  virtual void ImmediateDrawFreeTypeText(const CATFreeTypeTextGP* iTextGP);

  virtual void DrawCATViz3DFace(CATViz3DFace *face);
  virtual void DrawCATViz3DEdge(CATViz3DEdge *edge);
  virtual void DrawCATViz3DLine(CATViz3DLine *line);
  virtual void DrawCATViz3DMarker(CATViz3DMarker *marker);
  virtual void DrawPointCloud(CAT3DPointCloudRep& iRep, CATMathBox& iBox);
  virtual void DrawBlockCloud(CAT3DBlockCloudRep& iRep, CATMathBox& iBox);

  virtual CATRender * PushMatrix(CAT4x4Matrix &);
  virtual CATRender * PushMatrix(CAT3x3Matrix &);
  virtual void PopMatrix(CATRender *ioRender);

  virtual void PushReference();
  virtual void PopReference();

  virtual void operator *= (const CAT4x4Matrix &);
  virtual void operator *= (const CAT3x3Matrix &);

  virtual void SetFurtive(const int OnOff);

  // Update PickPath
  virtual int SetPickPath(const CATMathPoint & iPos, const float dimension);
  virtual int SetPickPath(const CATMathPoint & iPos, const CATMathDirectionf & iNormal, const float iDeep, const float iDimension, const int iId = 0);
  virtual int SetPickPath(const CATMathPoint & iPos, const CATMathDirectionf & iNormal, const CATMathDirectionf & iTangent, const float iDeep, const float iDimension, const int iId = 0);

  // @deprecated R424FD01
  virtual int SetPickPath(const CATMathPointf & iPos, const float dimension);
  // @deprecated R424FD01
  virtual int SetPickPath(const CATMathPointf & iPos, const CATMathDirectionf & iNormal, const float iDeep, const float iDimension, const int iId = 0);
  // @deprecated R424FD01
  virtual int SetPickPath(const CATMathPointf & iPos, const CATMathDirectionf & iNormal, const CATMathDirectionf & iTangent, const float iDeep, const float iDimension, const int iId = 0);
  virtual void AddPickPath();
  virtual void AddPickPath(int iOther3D);

  virtual void BeginDraw(CATViewpoint &viewpoint);
  virtual void EndDraw(CATViewpoint &viewpoint);

  void StopAfterFirstPick(const int);
  void UsePickingWindowSizeForFaces(const int);
  void SetSubSubElementsMode(const int iSubSubElementsMode);
  void SetPickOOCPointCloud(bool iDoPick);

  inline void GetPickCoordinates(float* oX, float* oY, float* oDX, float* oDY);
  virtual int IsOutside(const float, const float, const float);
  virtual int IsInside(const CAT3DBoundingSphere &);
  virtual void InheritElementType(int, int);

  virtual void AddClippingPlanes(float *);
  virtual void RemoveClippingPlanes(float *);

  virtual void AddBasicClippingPlanes(float *);
  virtual void RemoveBasicClippingPlanes(float *);

  //D6F FUN095444 pickable capping for CATVisClippingFilter ++
  virtual void AddClippingPlanes(CATRepRender::ClippingPlanes* ipPlane, CATVisClippingFilter* ipFilter);
  virtual void RemoveClippingPlanes(CATRepRender::ClippingPlanes* ipPlane, CATVisClippingFilter* ipFilter);
  //D6F FUN095444 pickable capping for CATVisClippingFilter --

  virtual void AddClippingSections(l_CATVisClippingSectionsFilter *);
  virtual void RemoveClippingSections(l_CATVisClippingSectionsFilter *);

  //D6F ER052520 Volume clipping picking ++
  void AddClippingVolumes(l_CATVisClippingVolumesFilter* ipClippingVolumeFilter);
  void RemoveClippingVolumes(l_CATVisClippingVolumesFilter* ipClippingVolumeFilter);
  //D6F ER052520 Volume clipping picking --

  virtual void DrawScissor(float *, CATGraphicAttributeSet const&);

  virtual void EndDrawScissor();

  void SetCurrentPathMatrix(const CAT4x4Matrix& i_matrix);

  int GetIgnoreNoPickFlag() const;
  void SetIgnoreNoPickFlag(int flag);
  inline void SetTraverseDrawPath(bool i_traverseDrawPath) { _traverseDrawPath = i_traverseDrawPath; }
  inline bool IsTraverseDrawPath() const { return _traverseDrawPath; }

  virtual CATMathPoint GetPickingOrigin();
  virtual float GetPickingRadius();
  virtual CATMathDirectionf GetPickingDirection();

protected:
  virtual void Draw3DCanonicalRep(CAT3DCanonicalRep& iRep);

  //-------------------------------------------------------------------------------
protected:

  CATPickPath     * _current_path;
  CATPickPathList &_pickpath;
  // FIFO queue of sets of clipping planes, for accumulation during Scene Graph traversal

  //D6F FUN095444 pickable capping for CATVisClippingFilter ++
  // I tried to reorganize stuffs by making planes and filters together but there are some crazy things going on.
  // For instance, ClippingBox_Create ODT is KO with SG dump if I dare to touch _saveClip or even change the position of _saveClip in header!!!
  // For this reason, I would declare array of filters later on this file.
  CATRepRender::ClippingPlanes* _saveClip[6];
  //D6F FUN095444 pickable capping for CATVisClippingFilter --

  int _ignoreNoPickFlag;

  // coordinates in pixel where the pick is done.
  float	x_, _dx;
  float 	y_, _dy;

  float	_SavedX, _SavedDX;
  float	_SavedY, _SavedDY;

  int _force;
  int _AllowAddPickPath;
  unsigned int _renderPointsOnly;

  CATMathPointf _neard, _fard;
  CATMathPointf _push_neard[MATRIX_LEVEL];
  CATMathPointf _push_fard[MATRIX_LEVEL];
  CATMathVectorf _vector;

  // viewpoint where the representation has been picked.
  CATViewpoint	*viewpointWherePicked_;

  // picking methods
  virtual int PickTriangle2D(const float *p1, const float *p2, const float *p3, int iUsePickingSize = 1);
  virtual int PickTriangle3D(const float *p1, const float *p2, const float *p3, const float *normal = 0, const int Id = 0);
  virtual int PickLine3D(const float *p1, const float *p2, const float dimension = 1.f, const float *normal = 0, const int Id = 0);
  virtual int PickLine2D(const float *p1, const float *p2, const float dimension = 1.f);
  virtual int PickPoint3D(const float *p1, const float dimension = 0.f, const float *normal = 0, const int Id = 0);
  virtual int PickPoint3D(const float *p1, const float dimension, const float *normal, const float *tangent, const int Id);
  virtual int PickPoint2D(const float *p1, const float dimension = 0.f);
  virtual int PickTriangle3D(const double *p1, const double *p2, const double *p3, const float *normal = 0, const int Id = 0);
  virtual int PickLine3D(const double *p1, const double *p2, const float dimension = 1.f, const float *normal = 0, const int Id = 0);
  virtual int PickPoint3D(const double *p1, const float dimension = 0.f, const float *normal = 0, const int Id = 0);
  virtual int PickTriangle2D(const double* p1, const double* p2, const double* p3, int iUsePickingSize = 1);
  virtual int PickLine2D(const double* p1, const double* p2, const float dimension = 1.f);
  virtual int PickPoint2D(const double* p1, const float dimension = 0.f);

  virtual int IsOutside3DViewport(const CAT3DBoundingSphere& iBs3D);
  virtual int IsOutside3DViewport(const float* ipCenter, const float& iRadius);
  virtual int IsInside3DViewport(const CAT3DBoundingSphere& iBs3D);
  virtual int IsInside3DViewport(const float* ipCenter, const float& iRadius);

  virtual int IsInside2DViewport(const CAT2DBoundingBox &bs2D, const float iRatio = 1.0f);
  virtual int IsInside2DViewport(const float* ipPoint);
  virtual int IsOutside2DViewport(const CAT2DBoundingBox &bs2D);
  virtual int IsOutside2DViewport(const CATMathPoint2Df &bs2DCenter);
  virtual int IsOutside2DViewport(const float x, const float y);
  virtual int IsCursorOutsideClipped2DViewport();
  virtual int IsOutsideClipped2DViewport(const float* ipPoint);
  virtual int IsInsideClipped2DViewport(const CAT2DBoundingBox& iBs2D);

  virtual int IsInsideScissorPolygon(const CAT2DBoundingBox& iBs2D);
  virtual int IsOutsideScissorPolygon();
  virtual int IsOutsideScissorPolygon(const CATMathPointf & iPoint);
  int IsPixelOutsideScissorPolygon(const CATMathPoint2Df & iPixel);

  bool IsSegment3DNotClipped(const CATMathPointf& iPt1, const CATMathPointf& iPt2, float* (&ippPlanes)[4], int iNbPlanes);

  // void DrawVoxelTree(const CATMathPointf & iCenter, float iHalfSize, const CATVizPtrList<CATVizVoxelLevel> & levels, int currentLevel, int levelToDraw, float *sight, int drawWithPoints = 0, float pointSize = 1.0f);

  virtual int GetCurrentMatrix(CAT4x4Matrix& o_matrix);
  virtual void Get2DPickingSquare(float *oXMinPickSquare, float *oXMaxPickSquare, float *oYMinPickSquare, float *oYMaxPickSquare);

  // Update PickPath
  virtual void SetCurrentAttribute(const CATGraphicAttributeSet &, const int iType);
  void SetCurrentPath(const CATRep *);
  void SetCurrentPath(const int iSubElementId);
  void SetCurrentPath(const list<int>& iSubElementIdList);

  static bool IsDraftingFrameRep(const CATRep& iRep);

  int _stopAfterFirstPick;

  int _inh_repmode;
  int _inheritElementType;
  int _inheritTopPriority;

  float _renderWidth;
  float _renderHeight;

  int _current_list;
  // Number of sets of clipping planes in _saveClip
  int _nClipping;

  // Clipping can be used either in local or global mode :
  // 1/ In local mode, clipping planes are updated during Scene Graph traversal on CAT3DFilterBagRep using AddClippingPlanes/RemoveClippingPlanes;
  // 2/ In global mode, they are generally provided by the CATSupport at the beginning and activated or deactivated during the traversal
  // depending on the current attribute in SetCurrentAttribute.
  int _clipping_global_mode;

  bool _clippingUsed;

  // Rotated Viewport
  CAT3DViewport* _pRotatedViewport;
  CAT3DViewport* _rotatedViewport_array[MATRIX_LEVEL];
  int _IsViewportRotated;

  // Box Viewport
  CAT3DViewport * _pBoxViewport;
  CAT3DViewport * _boxViewport_array[MATRIX_LEVEL];

  //Scissor
  float *_scissorPolygon;

  //Use picking window size for triangle 3D selection
  int _usePickingWindowSizeForFaces;

  //Return all sub sub elements in pickPath whether returns one sub sub element of the picked sub element.
  int _subSubElementsMode;

  //Clipping Sections
  void GetTetrahedraSelectionZone(l_CATVisClippingSectionsFilter* ipClippingSectionsFilter, list<CATVisTetrahedron>& oPickedSpaceDivision) const;

  int _pickPathCountBeforeClippingSection;
  std::stack<int> _pickPathCountBeforeVolumeClipping; //D6F ER052520 Volume clipping picking ++ --
  int _stopAfterFirstPickVolumeClipping; //D6F ER052520 Volume clipping picking ++ --

  //D6F FUN095444 pickable capping for CATVisClippingFilter ++ --
  std::stack<int> _pickPathCountBeforeClippingPlane;
  int _stopAfterFirstPickClippingPlane;

  struct RejectedData
  {
    float m_Deep;
    CATPickPath m_PickPath;

    RejectedData(float deep, const CATPickPath& repPath) : m_Deep(deep) , m_PickPath(repPath) {}
  };

  std::stack<std::vector<RejectedData>> _rejectedByClippingPlane;
  void ProcessCappingForClippingPlanes();
  std::vector<CATVisClippingFilter*> _filters[6];   // Size of filters would be _saveClip[i]->nb_planes
  //D6F FUN095444 pickable capping for CATVisClippingFilter --

  // FUN099945 Picking of Section Profile ++
  struct ColinearTriangleData
  {
    float m_StartDeep, m_EndDeep;
    CATPickPath m_PickPath;
  };

  void ProcessPickingOfSectionProfile();
  std::stack<std::vector<ColinearTriangleData>> _colinerTriangleData;
  bool _isContourPickingActive;
  // FUN099945 Picking of Section Profile --


  int _currentPrimitiveItemNum;
  VisConnectivityType _currentPrimitiveItemConnectivityType;

  bool _pickOOCPointCloud;
  bool _traverseDrawPath;

private:

  static void UVFacePickingCB(void * user_data, CATRefinementEngine::MeshCBData & iData);
  static void UVEdgePickingCB(void * user_data, CATRefinementEngine::BarsCBData & iData);

  HRESULT GetPrimitivePositionComponent(VisPrimitive& iVisPrimitive, VisRawBuffer*& opVerticesBuffer, VisSize& oVerticesCount, VisSize& oNbValuesPerVertex, VisDataType& oVerticesDataFormat, VisSize& oVerticesOffset, float*& opVerticesRawBufferf, double*& opVerticesRawBufferd);
  void GetPrimitiveItemVertexPosition(VisSize iVertexIndex, VisDataType iIndicesDataTypeReduced, const void* ipIndicesRawPointer, VisSize iPositionFactor, unsigned int& oArrayPosition);
  unsigned int GetPrimitiveItemVertexPositionForRestart(VisSize iVertexIndex, VisDataType iIndicesDataTypeReduced, const void* ipIndicesRawPointer, VisSize iPositionFactor, unsigned int& oArrayPosition);
  int PickTriangleVisPrimitiveItem(VisConnectivityType iPrimitiveType, void* ipIndicesDescription, float* ipVerticesRawBufferf, double* ipVerticesRawBufferd, VisSize iVerticesCount, VisSize iPositionFactor);
  int PickLineVisPrimitiveItem(VisConnectivityType iPrimitiveType, void* ipIndicesDescription, float* ipVerticesRawBufferf, double* ipVerticesRawBufferd, VisSize iVerticesCount, VisSize iPositionFactor);
  int PickPointVisPrimitiveItem(VisConnectivityType iPrimitiveType, void* ipIndicesDescription, float* ipVerticesRawBufferf, double* ipVerticesRawBufferd, VisSize iVerticesCount, VisSize iPositionFactor);

  void ApplyClippingPlanesToVectors(CATMathPointf & ioNeard, CATMathPointf & ioFard);

  template<typename T>
  void Get3DLineNormal(const T* ipBgnPnt, const T* ipEndPnt, const T* ipPrvPnt, const T* ipNxtPnt);

  CATPickingRender();
  CATPickingRender & operator= (const CATPickingRender &);

  friend class VisPrimitiveGroupRep;
  friend class VisDrawIndirectGroupRep;
  friend class CATEPickingAlgo;
  friend class CATVidDynamicGP_BufferedDraw;
  friend class CATVidVisitor_Pick;
};

inline void CATPickingRender::GetPickCoordinates(float* oX, float* oY, float* oDX, float* oDY)
{
  *oX = x_;
  *oY = y_;
  *oDX = _dx;
  *oDY = _dy;
}

#endif
