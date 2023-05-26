#ifndef CATCullingRender_H
#define CATCullingRender_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : Cull the objects that are outside the screen
//            and Manage a CATDisplayList to preprare the drawing
//
//------------------------------------------------------------------------------
// Usage :
//
//------------------------------------------------------------------------------
// Main methods :
//               Add a graphic primitive in a CATDisplayList
//                      DrawXXGP ( CATXXGP & )
//
//------------------------------------------------------------------------------
// Inheritance : CATCullingRender
//                  CATRepRender
//                     CATRender
//
//------------------------------------------------------------------------------
#include "CATDataType.h"
#include "SGInfra.h"
#include "CATRepRender.h"
#include "CAT4x4Matrix.h"
#include "CAT3x3Matrix.h"
#include "CATGraphicAttributeSet.h"
#include "CATMathPointf.h"
#include "CATMathPoint2Df.h"
#include "CATDisplayList.h"
#include "CATDataType.h"
#include "CATGraphicMaterial.h"
#include "CATRepPath.h"
#include "CATVizDisplayContext.h"
//#include "CATSupport.h"

#include "VisClipCurveDesc.h"


// Attention l include suivant provoque des erreurs de compil sur AIX
//#include <stack>

class CATVis2DModeFilter;
class CATVizUV3DRep;
class l_CATVisClippingSectionsFilter;
class l_CATVisClippingVolumesFilter;
class l_CATVisCurveClippingFilter;
class CATSupport;
class VisGPGPUPrimitive;
class CATDelegateRender;
class CATVDrawInformationRender;
class CATMaterialIBLParameters;
class VisMaterialApplication;
class IVisTexturePtr;
class CAT3DBlockCloudRep;

//#define ENABLE_OPTIM_CLEAN_RENDER

#define MATRIX_LEVEL 50

extern CATINTPTR DrawMenb (int);

static CATGraphicAttributeSet default_att;
class CATVizVoxelGP;
class CATMutex;
struct vVertexAssembly;
struct vDrawDescription;

class CAT3DMirrorGP;
class CAT3DViewport;

class ExportedBySGInfra CATCullingRender : public CATRepRender
{
  CATDeclareClass_Deprec;
  public :

    // Construction and destruction methods:
    // -------------------------------------

    CATCullingRender (const CATSupport &support);
    virtual ~CATCullingRender();
    void Clean(const CATSupport &iSupport);
    void Draw (list<CATViewpoint> &viewpointL, const int, const float);
    void DrawFurtive (list<CATViewpoint> &viewpointL, const int, const float);
    void DrawDialog(list<CATViewpoint> &viewpointL, const int stereo, const float gap);

    int DrawRepresentation (CATRep &iRep, int iInside, void* &iData);
    int EndDrawRepresentation (CATRep &iRep, void* &iData);

    virtual int IsDrawable (const CATGraphicAttributeSet &, const CAT3DBoundingSphere &, const CATRep &, CATGraphicMaterial *iMat = 0);
    virtual int IsDrawable (const CATGraphicAttributeSet &attribut, const CATRep &rep,  CATGraphicMaterial *iMat);

    //  inheritance management
    //  ----------------------

    virtual void InheritAttributes ( CATGraphicAttributeSet const*, int );
    virtual void InheritElementType ( int type, int choice );

    virtual void SetCurrentAttribute (const CATGraphicAttributeSet &);
    virtual void SetCurrentVisAttribute (VisAttribute& iVisAttr);

    virtual void BeginDrawSurfacicRep();
    virtual void EndDrawSurfacicRep();

	/**
	 *	Set the _inheritColorMode variable without pushing a state in the display list
	 *	use by DisplayAnnotations feature [CATVisAnnotation]
	 */
	inline void	 SetInheritColorMode(const int iMode);
  /*
  * Set the _inheritAFColorMode variable
  * use this variable to turn off ASM inheritance when AF is on
  */
  inline void	 SetInheritAFColorMode(const int iMode);
	/**
	 *	Set the _inheritAlphaMode variable without pushing a state in the display list
	 *	use by DisplayAnnotations feature [CATVisAnnotation]
	 */
	inline void	 SetInheritAlphaMode(const int iMode);
	/**
	 *	Set _inherited_view_mode_owner to lock view mode inheritance
	 *	use by DisplayAnnotations feature [CATVisAnnotation]
	 *	set a rep address to lock
	 *	set NULL to unlock
	 */
	inline void SetInheritedViewModeOwner(CATRep* iRep);

	/**
	 *  Set _inherited_material_owner to lock material inheritance (including forced materials)
	 *  The Material stack will otherwise function normally; materials just will not be applied.
	 *	use by DisplayAnnotations feature [CATVisAnnotation]
	 *	set a rep address to lock
	 *	set NULL to unlock
	 */

	inline void SetInheritedMaterialOwner(CATRep *iRep);

	inline int GetInheritedAlpha();

    virtual void SetCurrentMaterial(CATGraphicMaterial &);
    virtual void SetCurrentUV(unsigned int iNumUV, UVKeyPair const* iChannelsAssoc);
    virtual void SetCurrentMaterialAndUV(CATGraphicMaterial& iMat, unsigned int iNumUV, UVKeyPair const* iChannelsAssoc);
    virtual void SetCurrentVisMaterialAndUV(VisMaterial &iMat, unsigned int iNumUV, UVKeyPair const* iUVAssoc);
    virtual void SetCurrentVisMaterialApplication(const VisMaterialApplication* iMatApp);

    virtual void Draw2DMarker              (CAT2DMarkerGP &);
    virtual void Draw2DLine                (CAT2DLineGP &);
    virtual void Draw2DRectangle           (CAT2DRectangleGP &);
    virtual void Draw2DPolygon             (CAT2DPolygonGP &);
    virtual void Draw2DQuadStrip           (CAT2DQuadStripGP &);
    virtual void Draw2DGeometricText       (CAT2DGeometricTextGP &);
    virtual void Draw2DArcCircle           (CAT2DArcCircleGP &);
    virtual void Draw2DArcEllipse          (CAT2DArcEllipseGP &);

    virtual void Draw3DMarker              (CAT3DMarkerGP &);
    virtual void Draw3DLine                (CAT3DLineGP &);
    virtual void Draw3DIndexedLine         (CAT3DIndexedLineGP &);

    virtual void Draw3DEdge                (CAT3DEdgeGP &);
    virtual void Draw3DBufferedEdge        (CAT3DEdgeGP&);
    virtual void Draw3DEdges               (CAT3DEdgeGP** edge3L, int nedge, int m);
    virtual void DrawLightSource           (CAT3DLightSourceGP &);
    virtual void Draw3DFace                (CAT3DFaceGP &);
    virtual void Draw3DBufferedFace        (CAT3DFaceGP&, int);
    virtual void Draw3DPlanarFace          (CAT3DPlanarFaceGP &);
    virtual void Draw3DCylinder            (CAT3DCylinderGP &, const int = 0);
    virtual void Draw3DCurvedPipe          (CAT3DCurvedPipeGP &);

    // NRE Optimized Call
    virtual void SetVertexAssembly (vIVertexAssembly const* iVertexAssembly);
    virtual void SetDrawInfoShaderOption (unsigned int iShaderOption);
    virtual void PushSimpleDraw (vIndexBufferRange const& iIBRange);
    virtual void PushDrawWithGP (vIndexBufferRange const& iIBRange, CATGraphicPrimitive& , CATVizMetaClass const&);
    virtual void SetCurrentVisAttributeNumInstance(unsigned int iNumInstance);
    virtual void SetCurrentVisAttributeInstanceBuffer(VisRawBuffer* iBufferPtr);
    virtual void SetCurrentDrawIndirectDrawCount(unsigned int iDrawCount);
    virtual void SetCurrentDrawIndirectBuffer(VisRawBuffer * iIndirectBuffer);

    // XK7 GPU_SKINNING ++
    virtual void SetCurrentVisAttributeBoneTransformationBuffer(VisRawBuffer* iBufferPtr);
    virtual void SetCurrentVisAttributeBonePositionsBuffer(VisRawBuffer* iBufferPtr);
    virtual void SetCurrentVisAttributeNumBoneInstance(unsigned int iNumInstance);
    void SetCurrentVisAttributeNumBone(unsigned int iNumBone);
    // XK7 GPU_SKINNING --


    virtual void BeginMultipleDraw ();
    virtual void EndMultipleDraw ();

    virtual void DrawDynamicGP             (CATDynamicGP &);
    virtual void DrawCATVizDynamicPrimitive(CATVizDynamicPrimitive &);

    virtual CATVizVertexBuffer* SetCurrentVertexBuffer(CATVizVertexBuffer *vb);

    virtual void DrawOOCPointCloudGP       (CAT3DOOCPointCloudGP &);

    virtual void DrawBlockCloud( CAT3DBlockCloudRep& iRep );

	  virtual void DrawCATViz3DFace          (CATViz3DFace *face);
    virtual void DrawCATViz3DEdge          (CATViz3DEdge *edge);
    virtual void DrawCATViz3DLine          (CATViz3DLine *line);
    virtual void DrawCATViz3DMarker        (CATViz3DMarker *marker);
    virtual void DrawCATVizVoxel        (CATVizVoxelGP *marker);


    virtual void DrawScissor               (float *, CATGraphicAttributeSet const&);
    virtual void EndDrawScissor            ();

    //++ OU4: New RenderEngine
    virtual void DrawHighLight();
    virtual void EndDrawHighLight();
    //-- OU4: New RenderEngine

    virtual void Draw3DMirror              (CAT3DMirrorGP &iMirrorGP);
    virtual void DrawVisPrimitive          (VisPrimitive &);
	virtual void DrawVisGPGPUPrimitive     (VisGPGPUPrimitive &iVP);


    virtual CATRender * PushMatrix (CAT4x4Matrix &);
    virtual CATRender * PushMatrix (CAT3x3Matrix &);
    virtual void        PopMatrix  (CATRender *);

    virtual void SetWorldScale(CATMathVector const& iScale);

    virtual void PushTextureMatrix (CAT4x4Matrix &);
    virtual void PopTextureMatrix  ();
    virtual void SetUVTransform (float const*);

    void SetIBLParameters(CATMaterialIBLParameters const* iParams);
    void SetLightingProperties(const LightingProperties& iProp);
    void SetChannelTexture(unsigned int iChannel, IVisTexturePtr &iTexture) override;

    virtual void PushDecal(CATDecalProjector const* iProj, CATGraphicMaterial* iMat, CAT4x4Matrix const& iMatrix, float const* iUVTrans);
    virtual void PopDecal(CATDecalProjector const* iProj);

    virtual void operator *= (const CAT4x4Matrix&);
    virtual void operator *= (const CAT3x3Matrix&);

    virtual void PushReference();
    virtual void PopReference();

    virtual int IsMaterialInDLTranspart(CATGraphicMaterial *iMaterial);
    virtual int IsMaterialInDLTranspart(VisMaterial *iMaterial);

    virtual void SetFurtive (const int OnOff);

    virtual void SetScissor(const int x, const int y, const int dx, const int dy);
    virtual void UnsetScissor();

    virtual void SetAlphaFilterRatio(const float i_alphaFilterRatio);

    virtual void SetInside  (const int OnOff);

    virtual void SetPolygonOffset  (const int OnOff);

    virtual int IsInside  (const CAT3DBoundingSphere &);
    virtual int IsOutside (const CAT3DBoundingSphere &);
    virtual int IsToSmall (const CAT3DBoundingSphere &);
    int ComputeOcclusion (const CAT3DBoundingSphere &);

    virtual void SetColorMask (const int mode);
    virtual void SetPolygonMode (const int mode);
    virtual void SetClippingMode (const int mode);
    virtual void SetUncutMode(const int mode);    //UO4 Uncut++

    virtual void SetRepViewMode (const int mode); //UO4++ IR-360692 New Rep View Modes with outlines

    void SetPointTypeAttribute (const unsigned int &iPtType);
    void SetPointSizeAttribute (const float &iPtSize);

    // MPCulling : set the number of thread used for drawing
    virtual void SetMultiThreadMode(int mode) ;

    virtual int GetCurrentMatrix(CAT4x4Matrix& o_matrix);

    // Structure added to the display list for CATDrawRender
    typedef VisClipPlaneDescWithID ClippingPlanesWithID;

    virtual void AddClippingPlanes(float *);
    virtual void RemoveClippingPlanes(float *);

    virtual void AddClippingSpheres(l_CATVisClippingSphereFilter *);
    virtual void RemoveClippingSpheres(l_CATVisClippingSphereFilter *);

    virtual void AddClippingSections(l_CATVisClippingSectionsFilter *);
    virtual void RemoveClippingSections(l_CATVisClippingSectionsFilter *);

    virtual void AddClippingVolumes(l_CATVisClippingVolumesFilter *);
    virtual void RemoveClippingVolumes(l_CATVisClippingVolumesFilter *);

    virtual void AddCurveClipping(l_CATVisCurveClippingFilter *);
    virtual void RemoveCurveClipping(l_CATVisCurveClippingFilter *);

    void DisableDynamicElements();
    void DisableMarkerElements();
    void DisableLineicElements();
    void DisableMain3DHighlight();
    void DisableMain3DFurtive();

    inline int AreDynamicElementsDisabled();
    inline int AreMArkerElementsDisabled();
    inline int AreLineicElementsDisabled();

    void SetWidthAndHeight( const float iWidth, const float iHeight);
    virtual void SetAllElementInZMode(int mode);
    virtual void SetRepLayerNumber(int layerNumber);

    virtual void PushToleranceScale(float iToleranceScale);

    virtual void PopToleranceScale(float iToleranceScale);

    virtual void SetBackFaceCullingMode(const unsigned int iMode);
    virtual void SetTwoSidedLightingMode(const unsigned int iMode);

    void SaveViewpointViewport();

    void SetDialogFlag(int iFlag);
    virtual void SetRenderingMode(const unsigned int mode);

    enum CATCullingTypeEnum
    {
      Basic = 0,
      Shadow,
      Mirror
    };

    inline  CATCullingTypeEnum GetCullingType() const;
    void SetCullingType(CATCullingTypeEnum iType);

    virtual int Get3DLODNumber (const CAT3DBoundingSphere & iBS3D, const int iNbOfLOD, const float sagArray[] ) const;

    inline CATVDrawInformationRender* GetVDrawInfoRender() {return _vDrawInfoRender;}

    /**
     * Deprecated. Please use 'SetEnableVDrawInfo()'.
     * By default, 'vDrawInformation' usage is disabled.
     */
    void SetDisableVDrawInfo(unsigned int iDisable);

    void SetEnableVDrawInfo(bool enable);

    /** Deprecated. Please use 'IsVDrawInfoEnabled()'. */
    unsigned int DisableVDrawInfo() { return _disableDrawInfo; }

    bool IsVDrawInfoEnabled() const { return (_disableDrawInfo == 0); }

    virtual void ActivateRayTracingFilter(ERaytracingFilterMode iFilterMode);

    void SetDrawLayer(unsigned int iDrawLayer);

    void SetDrawGeomIndex();

    void SetDrawPriority(unsigned int iPriority);

    //d6f: Fixing NRE bug of drawing pre-highlight elements as furtive
    enum class DrawType
    {
      eUndefined,  //d6f: IR-754459 Need to differentiate between furtive and pre-highlight
      ePrehighlight
    };

    void SetDrawType(DrawType drawType) { _drawType = drawType; }
    //d6f: -- End --

    //tnn9: some cases benefit from knowing if the input CATCullingRender is for prehighlight or otherwise; the most relevant piece of existing info seems to be _drawtype
    DrawType GetDrawType() const { return _drawType; }
    //tnn9: -- End --

  //------------------------------------------------------------------------------
  protected :

    int InitDrawRepresentation(CATRep& iRep); //UO4+ IR-360692 New Rep View Modes
    int ExitDrawRepresentation(CATRep &iRep, int iInside, void* &iData);
    int InitEndDrawRepresentation(CATRep &iRep, void* &iData);
    void ExitEndDrawRepresentation(CATRep &iRep);  //UO4- IR-360692 New Rep View Modes

    /* Mutex for culing render. Lock it if you reimplement the method Draw and don't call CATCullingRender::Draw*/
    static CATMutex& GetCullingMutex();

    virtual void BeginDraw (CATViewpoint &viewpoint, unsigned int drawtype);
    virtual void BeginDraw (CATViewpoint &viewpoint);
    virtual void EndDraw (CATViewpoint &viewpoint);

    int GetRenderingMainDialogViewpointFlag(){return _renderingMainDialogViewpointFlag;};

    virtual void Draw3DCanonicalRep(CAT3DCanonicalRep& iRep);

    //  Display List Management
    //  -----------------------

    CATDisplayList *_displayList;
    int _current_list;

    //  inheritance management
    //  ----------------------

    int _inheritElementType;
    int _inh_transparency;
  	int _inherited_alpha;
    int _inh_repmode;
    int _inh_2Dmode;
    int _occlusion, _isBag;
    float _val_near, _val_far;
    bool _material_inheritance_lock;

    CATMathPointf wp1, wp2, wp3;
    CATMathPoint2Df w2Dp2, w2Dp3;

    CATVDrawInformationRender* _vDrawInfoRender;
    DrawType _drawType = DrawType::eUndefined; //d6f: Fixing NRE bug of drawing pre-highlight elements as furtive

  private :

    void SetInternalCurrentMaterial  (CATGraphicMaterial *, unsigned int iNumUV, UVKeyPair const* iUVAssoc);

    template <typename T>
    void _SetCurrentMaterial(T ipMat, unsigned int iNumUV, UVKeyPair const* iUVAssoc);

    CATBoolean _IsAlphaTestEnabled(CATGraphicMaterial* ipMaterial);
    CATBoolean _IsMaterialPropertiesActivation(CATGraphicMaterial* ipMaterial);

    CATBoolean _IsAlphaTestEnabled(VisMaterial* ipVisMaterial);
    CATBoolean _IsMaterialPropertiesActivation(VisMaterial* ipVisMaterial);

    CATBoolean _DoesContainSparseTexture(CATGraphicMaterial* ipMaterial) const;
    CATBoolean _DoesContainSparseTexture(VisMaterial* VisMaterial) const;

    void _FastAddMaterialInDL(int iList, VisMaterial* ipVisMaterial, unsigned int iNumUV, UVKeyPair const* iUVAssoc);
    void _FastAddMaterialInDL(int iList, CATGraphicMaterial* ipMaterial, unsigned int iNumUV, UVKeyPair const* iUVAssoc);

    HRESULT GetFiniteLineByClipping(CATMathPoint2Df infPts[2], CATMathPoint2Df clipPts[2]);
    void ReorderEndPoints(CATMathPoint2Df &pt1, CATMathPoint2Df &pt2, int isVertical);

    // Notably returns false in the situation where we are in dynamic mode (camera is moving) and the quality
    // settings deactivate the raytracing in dynamic mode.
    bool _IsRayTracingActivatedInCurrentMode() const;

    void _SetRayTracingViewModeFilterState(const CATRep& iRep);
    void _UnsetRayTracingViewModeFilterState(const CATRep& iRep);

    void _ApplyForcedBackFaceCulling(VisMaterial *ipMat);
    void _ApplyForcedBackFaceCulling(CATGraphicMaterial *iMat);

    int *_geomCullingTextNumber;

    unsigned char _renderingMainDialogViewpointFlag;

    unsigned int _disableDynamicElements    : 1;
    unsigned int _disableMarkerElements     : 1;
    unsigned int _disableLineicElements     : 1;
    //NC5 : for Print
    unsigned int _disableDrawInfo           : 1;

		l_CATVisClippingSectionsFilter* _pClippingSectionsFilter;
		int _drawSubClippingSections;
    //int _savedTransparForFBMaterial;

    static unsigned int _allowTranspar2D; //1=enable traspar2D, 0 disable, by default 1
    static unsigned int _initDone;        //1=init has been done. Avoid mutliple init

    static void InitParameter();

    //Uncut+
    // _uc : uncut | b : bool | i : int | a : array | _nb : number of | AF : Annotation Filter
    bool	_ucb_Afmode;
    bool	_ucb_CallFromSetUCM;
    int	_uci_nbAFs;
    int	_uci_nbUnCutters;
    int	_uci_nbCutters;
    int	_uci_nbiClips;
    int _uci_nbSkippedUncutters;
    int _ucia_SkippedUncutters[CATRepRender::kMaxClippingPlanes];
    ClippingPlanesWithID*	_ucpa_iClips[CATRepRender::kMaxClippingPlanes];

    //Uncut Sections
    int	_uci_nbUnCutSectsOuter;
    int	_uci_nbUnCutSectsInner;
    l_CATVisClippingSectionsFilter*	_ucpa_UnCutSectsOuter[CATRepRender::kMaxClippingPlanes];
    l_CATVisClippingSectionsFilter*	_ucpa_UnCutSectsInner[CATRepRender::kMaxClippingPlanes];

    //Uncut Volume
    int	_uci_nbUnCutVolsOuter;
    int	_uci_nbUnCutVolsInner;
    l_CATVisClippingVolumesFilter* _ucpa_UnCutVolsOuter[CATRepRender::kMaxClippingPlanes];
    l_CATVisClippingVolumesFilter* _ucpa_UnCutVolsInner[CATRepRender::kMaxClippingPlanes];

    //Uncut Sphere
    int	_uci_nbUnCutSphsOuter;
    int	_uci_nbUnCutSphsInner;
    l_CATVisClippingSphereFilter* _ucpa_UnCutSphsOuter[VisClipSphereDesc::kMaxClippingSpheres];
    l_CATVisClippingSphereFilter* _ucpa_UnCutSphsInner[VisClipSphereDesc::kMaxClippingSpheres];

    //Uncut Curve
    int	_uci_nbUnCutCurvesOuter;
    int	_uci_nbUnCutCurvesInner;
    l_CATVisCurveClippingFilter* _ucpa_UnCutCurvesOuter[VisClipCurveDesc::kMaxCurveClippingFilters];
    l_CATVisCurveClippingFilter* _ucpa_UnCutCurvesInner[VisClipCurveDesc::kMaxCurveClippingFilters];
    //UO4 Uncut-

    int _inheritAFColorMode; //IR-730755++

    ClippingPlanesWithID* _saveClip[CATRepRender::kMaxClippingPlanes];
    ClippingPlanesWithID* _globalClip;
    int _clipPlaneIDIndex;
    int _nClipping;
    bool _capping;

    int _clippingCount; // Global clipping counter for transparency behavior with back faces culling (includes every kind of clipping)

    bool _backFaceCullingIsForced;
    CATCullingTypeEnum _cullingType;

    // mGPU
    float _maxAngularObjectSagForLOD; // for slave render
    float _maxAngularObjectSizeForPixelCulling; // for slave render
    int _isSlave;
    int _multipipeActivated;

    //std::stack<CATRep*> _RepStack;
    CATRep* _currentRep;
    bool _isDepthPushed;
    void PushDepth(CAT3DBoundingGP* iGp);

    bool _rayTracingFilteringActivation;
    int _oldViewMode_GhostLook;
    CATBoolean _applyBckgrd3dMode;

    const VisMaterialApplication* _pVisMatApp;
    mutable CAT3DViewport* _pSupport3DViewport; // temporary viewport for calculation to avoid data race on creation.

    // FUN085229 prehighlight of hidden objects ++
    bool _highlightOnHiddenObj;
    bool _preHighlightOnHiddenObj;
    unsigned int _lineTypeSettings[NB_VISU_LINETYPE];
    unsigned int _linePatternSettings[NB_VISU_LINETYPE];
    unsigned int _lineRatioSettings[NB_VISU_LINETYPE];
    bool _highLightHiddenObjectSetting = false;
    int _opaqueFacesSettings = 0;
    int _allInZodeSettings = 0;

    // FUN085229 prehighlight of hidden objects --

    class RTVMData
    {
    public:
      bool CurrentlyBrowsingNotRaytracedSubDAG() const;
      void EnterNotRaytracedSubDAG(const CATRep* ipRootOfNotRaytracedSubDAG);
      void ExitNotRaytracedSubDAG();
      bool IsRootOfCurrentNotRaytracedSubDAG(const CATRep* ipRootOfNotRaytracedSubDAG);

    private:
      // DAG Directed Acyclic Graph; the set of all descendants of a rep is a sub-DAG, not a sub-tree
      const CATRep* m_pRootOfCurrentNotRaytracedSubDAG = nullptr;
    } _rtvmData;


public:

  /**
   * @nodoc
   */

  virtual void ActivateRefinement(unsigned int OnOff);


  /**
   * @nodoc
   */

  virtual void SetQuality(float ldni);

  /**
   * @nodoc
   */

  virtual void DrawCATVizUV3DFace(CATVizUV3DFace *rep);

  /**
   * @nodoc
   */

  virtual void DrawCATVizUV3DEdge(CATVizUV3DEdge *edge);

  /**
   * @nodoc
   */

  virtual void DrawCATVizUV3DLine(CATVizUV3DLine *line);

  /**
   * @nodoc
   */
  virtual void DrawPrimitiveSet(CATVizPrimitiveSet *set);

  virtual void DrawCATVizIndexed3DMarker(CATVizIndexed3DMarker *marker);
  virtual void Draw3DBufferedIndexedLine (CAT3DIndexedLineGPVBO &iGP);

  virtual void SetCurrentVisMaterial(VisMaterial &iMaterial);

  // FUN085229 prehighlight of hidden objects ++
  virtual bool IsHighlightOnHiddenObj() const;
  virtual bool IsPreHighlightOnHiddenObj() const;

  virtual void SetHighlightOnHiddenObj(bool iVal);
  virtual void SetPreHighlightOnHiddenObj(bool iVal);
  // FUN085229 prehighlight of hidden objects --

};

inline int CATCullingRender::AreDynamicElementsDisabled()
{
    return _disableDynamicElements;
}

inline int CATCullingRender::AreMArkerElementsDisabled()
{
    return _disableMarkerElements;
}

inline int CATCullingRender::AreLineicElementsDisabled()
{
    return _disableLineicElements;
}

inline void	 CATCullingRender::SetInheritColorMode(const int iMode)
{
	_inheritColorMode = iMode;
}

inline void	 CATCullingRender::SetInheritAFColorMode(const int iMode) //IR++
{
  _inheritAFColorMode = iMode;
}

inline void	 CATCullingRender::SetInheritAlphaMode(const int iMode)
{
	_inheritAlphaMode = iMode;
}

inline void	 CATCullingRender::SetInheritedViewModeOwner(CATRep* iRep)
{
	_inherited_view_mode_owner = iRep;
}

inline void  CATCullingRender::SetInheritedMaterialOwner(CATRep* iRep)
{
    _inherited_material_owner = iRep;
}

inline int CATCullingRender::GetInheritedAlpha()
{
	return _inherited_alpha;
}

inline CATCullingRender::CATCullingTypeEnum CATCullingRender::GetCullingType() const
{
  return _cullingType;
}

#endif
