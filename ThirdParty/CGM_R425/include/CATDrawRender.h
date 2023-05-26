#ifndef CATDrawRender_H
#define CATDrawRender_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract: is working on the display list to materialize it somewhere.  
//
//------------------------------------------------------------------------------
// Usage:     
//------------------------------------------------------------------------------
// Main methods:
//
//          Dispatch the display list element 
//             DrawDL
//
//------------------------------------------------------------------------------
// Inheritance : CATDrawRender
//                  CATRender
//
//------------------------------------------------------------------------------

#include "SGInfra.h"
#include "CATListOfInt.h"
#include "list.h"
#include "CATRender.h"
#include "CATMutex.h"  
#include "CATIAV5Level.h"
#include "CATDataType.h"
#include "CATVizBaseTools.h"
#include "CATVisColorf.h"
#include "CATSGSYPArray.h"
#include "CATVisEffectPositionEnum.h"
#include "VisClipPlaneDesc.h"

class CATDisplayList;
class CATPooledDisplayList;
class CATDataShadowMapping;
#if defined(_WINDOWS_SOURCE) || defined _LINUX_SOURCE
class CAT3DLightSourceGP;
class CATBoundingElement;
#endif

#include "CATVizDynamicPrimitive.h"
#include "CATElementType.h"
#include "CATVisEyeType.h"
#include "CAT3DViewpoint.h"
#include "CATVisInfiniteEnvironmentData.h"
#include "CATVisuTextureType.h"
#include "VisConnectivityType.h"
#include "CATSysErrorDef.h"
#include "CATVisDynamicRenderingQualityData.h"
#include "CATVisuTextureInfo.h"
#include "CATGraphicMaterial.h"

class CATRepPath;

class CATVisInfiniteBackground;
class CATVisInfinitePlane;
class l_CATVisInfiniteEnvironment;
class CATVisAO;
class l_CAT3DMirroring;
class CATFrameDataShadowMapping;	
class l_CATVisClippingSectionsFilter;
class l_CATVisClippingVolumesFilter;
class l_CATVisCurveClippingFilter;
class l_CATVisClippingSphereFilter;
class VisPrimitive;
class VisGPGPUPrimitive;
class VisAttribute;
class VisIndicesDescription;
class VisVerticesDescription;
class VisRawBuffer;
class CATVisEffect;
class VisFBO;
class VisResourceManager;
class CATVisuContext;
class CATVisuTextureInfo;
class VisRenderBuffer;
class l_CATVisuVIDDirectRenderer;
class l_CATVisuVIDDirectRendererShader;
class CATTexturePixelImage;
class CATMaterialAsBackground;
class VisIndirectPrimitive;
class CATDecalProjector;
class CATMaterialIBLParameters;
class VisMaterialApplication;

class ExportedBySGInfra CATDrawRender : public CATRender
{
 CATDeclareClass_Deprec;

 friend class CATIsInPlaneSupportRender;

public :
  
  enum EDrawFlags
  {
    /* Filter for connectivity types */
    fFilterVisPoints = VIS_POINTS,
    fFilterVisLines = VIS_LINES,
    fFilterVisLineStrip = VIS_LINE_STRIP,
    fFilterVisLineLoop = VIS_LINE_LOOP,
    fFilterVisTriangles = VIS_TRIANGLES,
    fFilterVisTriangleStrip = VIS_TRIANGLE_STRIP,
    fFilterVisTriangleFan = VIS_TRIANGLE_FAN,
    fFilterVisLineStripRestart = VIS_LINE_STRIP_RESTART,
    fFilterVisLineLoopRestart = VIS_LINE_LOOP_RESTART,
    fFilterVisTriangleStripRestart = VIS_TRIANGLE_STRIP_RESTART,
    fFilterVisTriangleFanRestart = VIS_TRIANGLE_FAN_RESTART,
    fLastFilterFlag = fFilterVisTriangleFanRestart,
    
    /* Drawing hints */
    fMaskDrawHints = 0xffff0000,
    fOrderIndependentDraw = 1 << 16,
  };

	virtual ~CATDrawRender();

	virtual void GetModelViewMatrix(CAT4x4Matrix &);

	CATDrawRender (const CATSupport &support);
  void Clean(const CATSupport &iSupport);


	virtual void BeginDraw      (CATViewpoint &viewpoint);

	virtual void DrawDLL     (const list<CATPooledDisplayList>&, CATVizElementType type);

	virtual void BeginDrawDL (CATVizElementType type);
	// MPCullingTMP : to shift to protected section
	virtual void DrawDL      (CATDisplayList &, CATVizElementType type);
	virtual void EndDrawDL   (CATVizElementType type);     

  
	virtual CATRender* PushMatrix ( CAT3x3Matrix &matrix );
	virtual CATRender* PushMatrix ( CAT4x4Matrix &matrix );
	virtual void PopMatrix ( CATRender *render );

  virtual void SetWorldScale(CATMathVector const& iScale);

	virtual void PushTextureMatrix ( CAT4x4Matrix &matrix );
	virtual void PopTextureMatrix ();

	virtual void SetForeground      (const int &);
	virtual void SetForegroundRGBA  (const int);
	virtual void SetColor(float red, float green, float blue, float alpha);

  virtual void  SetRepViewMode(CATVizElementType dltype, const int mode); //UO4+ IR-360692 New Rep View Modes with outlines

	virtual void SetNormal(float nx, float ny, float nz);
	virtual void ImmediateDrawVoxelTree(CATVizVoxelGP *gp, const CATMathPointf *eye, const CATMathDirectionf *sight, const float scaleFactor);
  
	virtual void SetCurrentVisAttribute (VisAttribute* iVisAttr);
  virtual void SetCurrentDepth(float iDepth);
  
  /** 
   * Method used to draw a material on the background so that 1 texel = 1 pixel
   * The method is public, but note that the parameter class is private, to restrict usage to VisualizationFoundation and friends.
   */
  virtual void InternalDrawMaterialAsBackground(const CATMaterialAsBackground& i_material){}

	//
	// This virtual method is implemented in CATOGLRender
	//
#if defined _WINDOWS_SOURCE || defined _IOS_SOURCE   || defined _LINUX_SOURCE
    virtual int  FxUpdatePass(bool isgeom, int &type_idx, int* &type, void**  &elem) {return 1;}
#endif

#if defined(_WINDOWS_SOURCE) || defined (_IOS_SOURCE) || defined _LINUX_SOURCE
  typedef struct struct_StackDrawRender
  {
   CATINTPTR _d4;
   CATINTPTR _d5;
   int* _types;
   void** _elem;
   int _length;
   int _finter;
   CATDrawRender *_render[50];
   int _current_value[50];
   int _push;
   CATViewpoint *_viewpoint;
   CATViewport  *_viewport; 
   CATGraphicAttributeSet _attribut;
   int _toSave;
   int _type;
   float *_eye_in_mc_;
   int *_typei;
  } StackDrawRender;

  list<CAT3DLightSourceGP> _shaderLights;
  unsigned int _textureUnit;
  float *_texCoordFlag;

#endif

	virtual void DrawDynamicGP (CATDynamicGP &);
	void DrawDynamicGP (CATDynamicGP &, CATViewpoint *, CATViewport *);
	virtual void DrawCATVizDynamicPrimitive (CATVizDynamicPrimitive &);

	virtual void DrawClippingPlanes(float *);
	virtual void DrawClippingPlanesPass2(float *);
	virtual void EndDrawClippingPlanes(float *);

	virtual void DrawClippingSections(l_CATVisClippingSectionsFilter *);
	virtual void DrawClippingSectionsPass2(l_CATVisClippingSectionsFilter *);
	virtual void EndDrawClippingSections(l_CATVisClippingSectionsFilter *);

	virtual void DrawSubClippingSections(l_CATVisClippingSectionsFilter *, int);
	virtual void DrawSubClippingSectionsPass2(l_CATVisClippingSectionsFilter *, int);
	virtual void EndDrawSubClippingSections(l_CATVisClippingSectionsFilter *);

  virtual void DrawClippingVolumes(l_CATVisClippingVolumesFilter *);
  virtual void EndDrawClippingVolumes(l_CATVisClippingVolumesFilter *);

  virtual void DrawClippingSpheres(l_CATVisClippingSphereFilter *);
  virtual void EndDrawClippingSpheres(l_CATVisClippingSphereFilter *);

  virtual void DrawCurveClipping(l_CATVisCurveClippingFilter *);
  virtual void EndDrawCurveClipping();
  
	void SetWidthAndHeight( const float iWidth, const float iHeight);
  
	void FilterDialog(int iOnOff=1);
  void FilterDisplayList(int iFilterMesh, int iFilterTranparent, int iFilterOther);
  void InitFilterDisplayList(int iFilter = 0);
  void FilterDisplayList(CATVizElementType iType, int iFilter = 1);

  void WriteDialogElementsInStencil (unsigned int iOnOff);

  void ForceMaterial(CATGraphicMaterial* iMat);

	void SetMirroring(l_CAT3DMirroring* iMirroring);
      
	virtual void DrawVisPrimitive (VisPrimitive &iVP);
	virtual void DrawVisGPGPUPrimitive (VisGPGPUPrimitive &iVP);

	virtual void SetPointSpriteRenderingState();
	virtual void UnsetPointSpriteRenderingState();
	virtual void SetVisColor(int coordCount, VisDataType iDataType, void* pColorData);
	virtual void SetVisNormal(int coordCount, VisDataType iDataType, void* pNormalData);
	virtual void SetPrimitiveType (VisConnectivityType primitiveType);
	virtual HRESULT SetVisIndicesDescription (VisIndicesDescription* pIndicesDescription);
	virtual HRESULT SetVisVerticesDescription (VisVerticesDescription* pVerticesDescription);
	virtual void DrawArrays (unsigned int count);
	virtual void DrawElements (unsigned int count);
	virtual void BeginDrawVisPrimitive();
	virtual void EndDrawVisPrimitive();

	void SetEyeType(CATVisEyeType iEye);
	const CATVisEyeType&  GetEyeType() const;

	void SetDimensionAsPixel(int iDefineDimensionAsPixel);
	void GetDimensionAsPixel(int& oDefineDimensionAsPixel) const;

  void SetGlobalAmbientLight(float iRed, float iGreen, float iBlue);
  void GetGlobalAmbientLight(float &iRed, float &iGreen, float &iBlue) const;
    
  /** Dump current channel Color, Stencil, Depth into a file
   *  @param iFileName The path and the file name : ex "e:\\dumpColor.tiff"
   *  @param iMask The mask Must be GL_RGBA (for color) (0x1908), GL_DEPTH_COMPONENT (for depth) (0x1902), GL_STENCIL_INDEX (for stencil)
   *               You CANNOT use more than one component at a time. Ex : you CANNOT do  GL_DEPTH_COMPONENT | GL_STENCIL_INDEX.
   *               So just don't try...
   *  @param iWidth usualy the width of the support.
   *  @param iHeight usualy the height of the support.
   */
  virtual void DumpChannelIntoFile(const char * iFileName, unsigned int iMask, unsigned int iWidth, unsigned int iHeight) const;


  /** Dump the content of iVisuTexture in a file disk. This method support MS textures.
   *  @param iFileName The path and the file name : ex "e:\\dumpTexture.tiff"
   *  @param iVisuTexture The texture to dump.
   */
  virtual void DumpVisuTextureIntoFile(const char * iFileName, CATVisuTexture * iVisuTexture) const;
  
  /** This method set the rendering mode on the draw render. The value can be Static(0) or Dynamic(1).
   *  By default, the mode is set to static and the data is empty.
   *  If you set Dynamic mode, some additionnal information may be useful. This is the iDataQuality purpose.
   *  @param iMode 0 = Static, 1 = dynamic, other value are not allowed
   *  @param iDataQuality The quality used in dynamic mode.
   */
  void SetStaticOrDynamicMode(unsigned int iMode, const CATVisDynamicRenderingQualityData & iDataQuality);
 

  void GetGLViewport(CATViewpoint& iVp, int& oX, int& oY, int& oDx, int& oDy);
  
  inline void SetBackground3DViewMode(const Background3DViewMode iMode);
  inline const Background3DViewMode GetBackground3DViewMode();
  
  void SetAlphaFilterValue(float i_alphaFilterValue);
  float GetAlphaFilterValue() const;

  virtual void SetScissor(CATScissorStruct& i_viewport);
  virtual void UnsetScissor();

  virtual l_CATVisuVIDDirectRenderer* GetVIDDirectRenderer(l_CATVisuVIDDirectRendererShader& i_cidShader);

  virtual void SetIBLParameters(CATMaterialIBLParameters const*) {}
  virtual void SetLightingProperties(CATULONG32 iChannels, CATULONG32 iFlags) {}
  virtual void SetChannelTexture(unsigned int, IVisTexture*) {}

  virtual void SetCurrentVisMaterialApplication(const VisMaterialApplication* iMatApp) {}

  virtual void PushDecal(CATDecalProjector const* iProj, CATGraphicMaterial* iMat, CAT4x4Matrix const& iMatrix, float const* iUVTrans){}
  virtual void PopDecal(CATDecalProjector const* iProj){}

  virtual void SetUVAssoc(unsigned int iChannel, unsigned int iUVKeyHash){}

  void EnableAlphaOnLine();
  void DisableCappingPloygon();
  
  // GF8: Filter added to cull selected primtivies during rendering
  inline void SetPrimitiveFilter(unsigned int);
  inline unsigned int GetPrimitiveFilter() const;

  // return true if order independent batching is true
  inline void SetOrderIndependentDraw(bool iValue);
  inline bool IsOrderIndependentDraw() const;

  // return true if order independent batching is true
  inline void SetDrawHints(unsigned int iValue);
  inline unsigned int GetDrawHints() const;

  virtual void SetDrawLayer(int iLayer);
  virtual void SetDrawGeomIndex(unsigned int iGeomIndex);

  virtual void SetDrawPriority(unsigned short iPriority);
  virtual void SetZTestAnnotation(bool iZTestFlag);
  virtual void SetRepLayerNumber(int layerNumber);
protected :
 CATDrawRender (const CATDrawRender & iRender) ;

#if defined(_WINDOWS_SOURCE) || defined _LINUX_SOURCE
 StackDrawRender _inShaderStack;
 StackDrawRender _outShaderStack;
#endif

 
  virtual void Draw2DGeometricText (CAT2DGeometricTextGP &, CATViewpoint *viewpoint = NULL, CATViewport *viewport = NULL);
  virtual void Draw2DArcCircle     (CAT2DArcCircleGP &, CATViewpoint *viewpoint = NULL, CATViewport *viewport = NULL);
  virtual void Draw2DArcEllipse    (CAT2DArcEllipseGP &, CATViewpoint *viewpoint = NULL, CATViewport *viewport = NULL);

  virtual void ActivateOutlineComputation(unsigned int iActivate);
  virtual void DrawCATVizUV3DFace_Outline(CATVizUV3DFace *face, CAT3DViewpoint *viewpoint, CAT3DViewport *viewport);

// MPCullingTMP : to uncomment (see upward)
//  virtual void DrawDL      (CATDisplayList &, CATVizElementType type);

  void LockMaterialChg(unsigned int iLock=1);
  void UnlockMaterialChg();
  
  // clipping sections
  virtual void GetClippingVolumeDomains(float*& opVerticesPositionTab, float*& opVerticesNormalsTab, int& oVerticesPosAndNormalTabSize, int*& opTrianglesVerticesIndicesTab, int*& opTrianglesCountForEachClippingVolumeDomain, int& oClippingVolumeDomainCount);
  virtual int IsClippingSectionsPass2Activated();
    
  //point type and point size management (SGV6)
  virtual void SetCurrentVisAttributePointType(unsigned int iPtType);
  virtual void SetCurrentVisAttributePointSize(float        iPtSize);

  //Custom instance buffer
  virtual void SetCurrentVisAttributeNumInstance(unsigned int iNumInstance);
  virtual void SetCurrentVisAttributeInstanceBuffer(VisRawBuffer* iBufferPtr);

  // XK7 GPU_SKINNING ++
  virtual void SetCurrentVisAttributeBoneTransformationBuffer(VisRawBuffer* iBufferPtr);
  virtual void SetCurrentVisAttributeBonePositionsBuffer(VisRawBuffer* iBufferPtr);
  virtual void SetCurrentVisAttributeNumBoneInstance(unsigned int iNumInstance);
  virtual void SetCurrentVisAttributeNumBone(unsigned int iNumBone);
  // XK7 GPU_SKINNING --

  //Unbind VBO and IBO
  virtual void UnbindBufferObject();

  virtual void SetClearColor(float iColor[4]);

  //Change the viewport. Put the viewport in iX, iY position with a width of iWidth and an height of iHeight
  virtual void ChangeViewport(int iX, int iY, int iWidth, int iHeight) const;

  //put from CATOGLRender To CATDrawRender by NJ3
  // sub support data combined with multiview
  void GetGLViewportInSubSupportContext(CATViewpoint* ipViewpoint, int& oXGLViewportGlobalPos, int& oYGLViewportGlobalPos, int& oGLViewportWidth, int& oGLViewportHeight, int& oXGLViewportLocalPos, int& oYGLViewportLocalPos);


  /** Say if a the DL in the viewpoint contains element of a specific DL type.
   * @param iViewpoint the viewpoint from which you want to get the viewpoint list.
   * @param iDL the DL.
   * @return 0 if the DLL contains no element else 1.
   */
  unsigned int HasDLGeometry(CATViewpoint * iViewpoint, CATVizElementType iDL) const;

  // returns true if clipping is allowed for display list types beyond OTHER3D_2DMODE
  static bool IsClippingPlanesAllowed(CATVizElementType type, const VisClipPlaneDescWithID* clipPlaneData, bool isPrehighlight);
  static bool IsClippingAllowed(CATVizElementType type, unsigned int flags, bool isPrehighlight);

  // Viewpoint data for possible use in software backface culling
  float *eye_in_mc_;
  float _Thickness[6];

  // Culling data for possible use in software backface culling
  unsigned char * visible_;

  // Depth priority for 2D
  int _priority;
  float _SaveMaterial[4];
  int _EdgeHighlight;
  int _MatTracksColor;
  int _saveMatTracksColor;
  
//------------------------------------------------------------------------------
 protected :
  void ApplyPlmViewMode();
  void RevertPlmViewMode();
  void DrawCATVizDynamicPrimitive (CATVizDynamicPrimitive &, CATViewpoint *, CATViewport *);

  virtual void ResetDefaultFxMaterial();
  virtual void  SetDefaultFxMaterial(CATGraphicMaterial* i_pDefaultFxMaterial);

  CATGraphicMaterial* _forcedMaterial;
  int _lockMaterialChg;

  virtual void SetAlphaTransparency(int i_alphaTransparencyFlag);
  int GetAlphaTransparency();

  static CATMutex _mutexDynamicGP;
    
  CATGraphicMaterial* _pDefaultFxMaterial;
  
  int _savePositionForClippingSections;
  int _numDrawForClippingSections;  
  int _savePositionForClippingPlanes;    
  
  
  int _savedPositionForDoubleMaterials;
  CATListOfInt _ltexChannel; 
  CATListOfInt _ltexCoordSet;  
  bool _cullingHasChanged;

  inline int GetStereoMode() const;
    
  bool m_IsDialog;
  unsigned int _isDrawingMain3DVp : 1;

  unsigned int _alphaOnLineDisable;
  unsigned int _cappingPolygonDisable;

  // GF8: Filter added to cull selected primtivies during rendering
  unsigned int _flags;

  // GF8: PLM View mode
  bool _skipDraws; // Used for casting properties
  bool _customRenderingStyle;
  int _plmViewMode;
  int _plmSavedViewMode;

  inline bool AreBoundingGPFiltered() const;
  void ActivateFilterRayTracing(bool iActivation);

private:
  void BeginDraw (CATViewpoint &iVp, const int iStereoMode, const float iEyeGap);
  
   unsigned int                      _staticOrDynamicMode;
  CATVisDynamicRenderingQualityData _dynamicRenderingQualityData;
   
  // filtering
  unsigned int  _filterDialog;
  unsigned char _filterDL[65], _filterDLActivation;
  
  l_CATVisClippingSectionsFilter* _pSectionsFilter;
  
  float _alphaFilterValue;

  CATVisEyeType   _eyeType;
  int             _stereoMode;

  int _defineDimensionAsPixel;

  CATVisColorf _globalAmbientLight;

  bool _filterRayTracingActivation;
  bool _filterRayTracing;
  bool _filterBoundingGP;
  bool _filterRayTracingViewMode;







  //------------------------------------------------------------------------------
  // Folling methods are only used by printerender
  // They should not be used anymore
  public:
  virtual void Draw(list<CATViewpoint> &, const int, const float);
  virtual void DrawFurtive(list<CATViewpoint> &, const int, const float);
  void DrawStandard3DViewpoint(CAT3DViewpoint *i_pViewpoint);


  //------------------------------------------------------------------------------
  // <FBJ> ORE Suppresion
  
public:
  enum CATRenderMode {
    CATRenderModeStd,
    CATRenderModeDrawPath,
    CATRenderModeShadow,
    CATRenderModePlanarShadow,
    CATRenderModeMirrorReflexion,
    CATRenderModeMultiLightShadow,
    CATRenderModeAdvancedEffectOnTexture,
    CATRenderModeNormalMap,
    CATRenderModeEnvMap,
    CATRenderDrawEffects
  };
  
  CATRenderMode GetRenderMode();
  void SetRenderMode(CATRenderMode i_RenderMode);
  
protected:
  CATRenderMode _renderMode;
};

inline int CATDrawRender::GetStereoMode() const
{
  return _stereoMode;
}

inline void CATDrawRender::SetBackground3DViewMode(const Background3DViewMode iMode)
{
  _bckgrd3d_activated = iMode; // _bckgrd3d_activated member of CATRender
}
inline const Background3DViewMode CATDrawRender::GetBackground3DViewMode()
{
  return _bckgrd3d_activated;
}

inline void CATDrawRender::SetPrimitiveFilter(unsigned int flag) {
	_flags = (flag & fMaskDrawHints) | flag;
}

inline unsigned int CATDrawRender::GetPrimitiveFilter() const {
	return _flags;
}

inline bool CATDrawRender::AreBoundingGPFiltered() const
{
  return _filterBoundingGP;
}

inline void CATDrawRender::SetOrderIndependentDraw(bool iValue) {
  _flags = iValue ? _flags | fOrderIndependentDraw : _flags & (~fOrderIndependentDraw);
  
}

inline bool CATDrawRender::IsOrderIndependentDraw() const {
  return (_flags & fOrderIndependentDraw) != 0;
}

inline void CATDrawRender::SetDrawHints(unsigned int iValue) {
  _flags = iValue;
}

inline unsigned int CATDrawRender::GetDrawHints() const {
  return _flags;
}

#endif

