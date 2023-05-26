#ifndef CATRepRender_H
#define CATRepRender_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   abstract class for render tool which work on the representation
// ----------   list of a viewpoint
//
//------------------------------------------------------------------------------
// Usage :      is specified for implementing picking and culling
// ------
//
//------------------------------------------------------------------------------
// Class :      CATRepRender
// -------        CATRender
//
//------------------------------------------------------------------------------
// HISTORY :
//    17 June 99 -- CDT -- add '_IsShowSpace' and '_OneNodeIsNoshow' for the show/noshow
//               management.
//
#include "SGInfra.h"
#include "IVisTexturePtr.h"

#include "CATRender.h"
#include "CATElementType.h"
#include "CATVizBaseTools.h"

#include "CATMultiThreadCullingAlgorithm.h"
#include "CATVis2DModeType.h"
#include "VisClipPlaneDesc.h"
#include "VisClipSphereDesc.h"
#include "CATSGUtil.h"
#include "VisFilteringEnums.h"

#include "CATCompVizPrimitiveCacheBehavior.h"

#include <map>
#include <set>
#include <vector>

#define MATRIX_LEVEL 50

#ifdef SG_COMPOSITES_MULTIOS
class CATSGContext;
#endif // SG_COMPOSITES_MULTIOS

class CATGraphicMaterial;

class CATVisFiltersStack;
class CATVisFilter;
class CATVis2DModeFilter;
class l_CATVisClippingSectionsFilter;
class l_CATVisClippingVolumesFilter;
class l_CATVisCurveClippingFilter;
class l_CATVisClippingSphereFilter;
class CATVisRenderingStyleSet;
class CAT3DBoundingSphere;
class CAT2DBoundingBox;
class CATMaterialStack;
class CATDecalStack;
class CATDecalProjector;
class CATMaterialIBLParameters;
class IVisTexture;
struct UVKeyPair;
class VisMaterialApplication;
class VisSGOccurrenceObserver;

class ExportedBySGInfra CATRepRender : public CATRender
{
  CATDeclareClass_Deprec;

public:

  CATRepRender(const CATSupport &support);
  CATRepRender(const CATRepRender &render);

  virtual ~CATRepRender();
  void Clean(const CATSupport &iSupport);
  virtual void Draw(::list<CATViewpoint> &viewpoint, const int, const float);
  virtual void DrawFurtive(::list<CATViewpoint> &viewpoint, const int, const float);
  virtual  void DrawDialog(::list<CATViewpoint> &viewpointL, const int stereo, const float gap);

  virtual int DrawRepresentation(CATRep &iRep, int iInside, void* &iData);
  virtual int EndDrawRepresentation(CATRep &iRep, void* &iData);

  virtual void BeginDraw(CATViewpoint &viewpoint, unsigned int drawtype);
  virtual void BeginDraw(CATViewpoint &viewpoint);
  virtual void EndDraw(CATViewpoint &viewpoint);

  virtual int FilterRepresentation(CATRep& iRep);
  virtual void EndFilterRepresentation(CATRep& iRep);

  // Observer registration for "CompilableRep" check
  bool RegisterObserverForCompiledRep(const VisSGOccurrenceObserver* iObs);
  bool UnregisterObserverForCompiledRep(const VisSGOccurrenceObserver* iObs);

  int DrawCompiledRep(CATRep& iRep);
  void EndDrawCompiledRep(CATRep& iRep);

  virtual void PushFilter(CATVisFilter* filter);
  virtual void PopFilter(CATVisFilter* filter);
  inline unsigned int GetNumAF() { return _numAF; }
  inline VisFilteringEnums GetVisFilteringEnum() { return _eVisFilteringEnum; }

  /**
   * @nodoc
   */
  virtual void SetPolygonOffset(const int);

  /**
   * @nodoc
   */
  virtual void GetPolygonOffset(int&);

  void SetLayersFilter(unsigned char iLayersFilter[1024]);

  void AddFilterForMainViewpoints(CATVisFilter* iFilter);

  // MPCulling
#ifndef CULLING_REPARTITION
  inline void SetDrawId(int id) { _drawId = id; };
  inline int  GetDrawId() const { return _drawId; };
  inline int  GetCurrentRepFatherIndex() const { return _currentRepFatherIndex; };
  inline void SetCurrentRepFatherIndex(int i) { _currentRepFatherIndex = i; };
  inline CATLONG32 GetParity() { return _parity; };
  inline void SetParity(CATLONG32 parity) { _parity = parity; };

#endif
  inline void SetRepRenderId(int id) { _repRenderId = id; };
  inline int  GetRepRenderId() { return _repRenderId; };

  inline int GetOldViewMode() { return _old_view_mode; }

  virtual void PushReference();
  virtual void PopReference();
  virtual int IsDrawable(const CATGraphicAttributeSet &,
    const float *,
    const float,
    const int);
  virtual int IsDrawable(const float, const float, const float);
  virtual int IsOutside(const float, const float, const float);

  virtual int CheckTriangleVersusBox(const float  *iTriangle,
    CAT4x4Matrix *iNonRectangularBox = NULL,
    const float   iTol = 0.f);

  virtual int CheckTriangleStripVersusBox(const float  *iStrip,
    const int     iNbPts,
    const void   *iIndices = NULL,
    const int     iIndexType = 1,
    CAT4x4Matrix *iNonRectangularBox = NULL,
    const float iTol = 0.f);

  virtual int CheckTriangleFanVersusBox(const float  *iFan,
    const int     iNbPts,
    const void   *iIndices = NULL,
    const int     iIndexType = 1,
    CAT4x4Matrix *iNonRectangularBox = NULL,
    const float   iTol = 0.f);

  virtual int CheckPolylineVersusBox(const float  *iPolyline,
    const int     iNbPts,
    const int     iClosedPolyline = 0,
    const void   *iIndices = NULL,
    const int     iIndexType = 0,
    const int     iIndexFactor = 1,
    CAT4x4Matrix *INonRectangularBox = NULL,
    const float   iTol = 0.f);

  virtual void CheckParallelepipedBox(float *, float *, int);

  static const unsigned int kMaxClippingPlanes = VisClipPlaneDesc::kMaxClippingPlanes;
  static const unsigned int kMaxClippingSpheres = VisClipSphereDesc::kMaxClippingSpheres;
  typedef VisClipPlaneDesc ClippingPlanes;

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

  virtual void AddCurveClipping(float* filter); // <AKA4> TO DELETE
  virtual void RemoveCurveClipping(float* filter); // <AKA4> TO DELETE

  virtual void SetFilterRepViewMode(const int mode);
  virtual void UnSetFilterRepViewMode();

  virtual void SetScissor(const int i_x, const int i_y, const int i_dx, const int i_dy);
  virtual void GetScissor(CATBoolean& o_scissorEnbledFlag, int& x, int& y, int& dx, int& dy);
  virtual void UnsetScissor();

  virtual void SetAlphaFilterRatio(const float i_alphaFilterRatio);
  float GetAlphaFilterRatio() const;

  virtual CATGraphicMaterial*   PushMaterial(CATGraphicMaterial* ipMat, unsigned int iMatInheritance, void*& oData);
  virtual CATGraphicMaterial*   PushMaterial(CATGraphicMaterial* ipMat, CATULONG32 iMatInheritance, CATULONG32 iLayer, void *& oData);  // E8C : New Materials Inheritance Rules
  const VisMaterialApplication* PushMaterial(VisMaterialApplication* ipMatApp, void *& oData); // AZX : New materials
  virtual CATGraphicMaterial*   PopMaterial(void* &iData);

  inline void DisableLook() { m_DefaultMaterialActivation = false; }
  //++ NC5 Hybrid
  void SetIgnoreCompiledRep(unsigned int);
  inline int IgnoreCompiledRep();
  //-- NC5 Hybrid

  virtual int IsToSmall(const CAT3DBoundingSphere &);
  virtual int IsToSmall(const CAT2DBoundingBox &);

  void PushIBLParameters(CATMaterialIBLParameters const* iParams);
  void PopIBLParameters();

  struct LightingProperties
  {
    LightingProperties() : channels(kAllChannels), flags(kDefaultFlags) {}
    LightingProperties(const LightingProperties& iPrev, const LightingProperties& iAdded) : channels(iPrev.channels), flags(iPrev.flags)
    {
      if (0 != (iAdded.flags & fDefineLightChannels))
      {
        flags |= fDefineLightChannels;
        channels = iAdded.channels;
      }

      if (0 != (iAdded.flags & fDefineCasterReceiver))
      {
        flags &= ~kDefaultFlags;
        flags |= fDefineCasterReceiver | (iAdded.flags & kDefaultFlags);
      }

      if (0 != (iAdded.flags & fDefineLightMapMode))
      {
        flags |= fDefineLightMapMode;

        if (0 != (iAdded.flags & fLightMapIlluminanceMode))
          flags |= fLightMapIlluminanceMode;
        else
          flags &= ~fLightMapIlluminanceMode;
      }
    }

    enum FFlags
    {
      fDefineLightChannels = (1 << 0),
      fDefineCasterReceiver = (1 << 1),
      fCastShadows = (1 << 2),
      fReceiveShadows = (1 << 3),
      fCastReflections = (1 << 4),
      fReceiveReflections = (1 << 5),
      fDefineLightMapMode = (1 << 6),
      fLightMapIlluminanceMode = (1 << 7)
    };

    CATULONG32 channels;
    CATULONG32 flags;

    void SetLightChannels(CATULONG32 iChannels)
    {
      flags |= fDefineLightChannels;
      channels = iChannels;
    }

    void SetCasterReceiverFlags(bool iCastShadows, bool iReceiveShadows, bool iCastReflections, bool iReceiveReflections)
    {
      flags &= ~kDefaultFlags;
      flags |= fDefineCasterReceiver | (iCastShadows ? fCastShadows : 0) | (iReceiveShadows ? fReceiveShadows : 0)
            | (iCastReflections ? fCastReflections : 0) | (iReceiveReflections ? fReceiveReflections : 0);
    }

    void SetLightMapFlags(bool iMode)
    {
      flags |= fDefineLightMapMode | (iMode ? fLightMapIlluminanceMode : 0);
    }

    static const CATULONG32 kAllChannels = 0xFFFFFFFF;
    static const CATULONG32 kDefaultFlags = fCastShadows | fReceiveShadows | fCastReflections | fReceiveReflections;
  };

  void PushLightingProperties(const LightingProperties& iProp);
  void PopLightingProperties();

  void PushChannelTexture(unsigned int iChannel, const IVisTexturePtr &iTexture);
  void PopChannelTexture(unsigned int iChannel);

  virtual void PushDecal(CATDecalProjector const* iProj, CATGraphicMaterial* iMat, CAT4x4Matrix const& iMatrix, float const* iUVTrans) {}
  virtual void PopDecal(CATDecalProjector const* iProj) {}

  virtual void SetCurrentUV(unsigned int iNumUV, UVKeyPair const* iChannelsAssoc);
  virtual void SetCurrentMaterialAndUV(CATGraphicMaterial& iMat, unsigned int iNumUV, UVKeyPair const* iChannelsAssoc);
  virtual void SetCurrentVisMaterialAndUV(VisMaterial& iMat, unsigned int iNumUV, UVKeyPair const* iChannelsAssoc);
  virtual void SetCurrentVisMaterialApplication(const VisMaterialApplication* iMatApp) {};

  virtual CATRender * PushMatrix(CAT4x4Matrix &);
  virtual CATRender * PushMatrix(CAT3x3Matrix &);
  virtual void        PopMatrix(CATRender *);

  virtual int IsCurrentWorldScaled();
  virtual void GetWorldScaleCancelMatrix(CAT4x4Matrix& oMatrix);

  //(1.0,1.0,1.0) acts as a pop. Other acts as a Push. Not alterning Unit vector with non unit vector will result in an assert.
  virtual void SetWorldScale(CATMathVector const& iScale);

#ifdef SG_COMPOSITES_MULTIOS
  void             SetSGContext(CATSGContext* iCtx) { _currentSGContext = iCtx; }
  CATSGContext*    GetSGContext() { return _currentSGContext; }
#endif // SG_COMPOSITES_MULTIOS

  enum ERaytracingFilterMode
  {
    eNone = 0,
    eBoundingGP,
    eFull,
    eRayTracedByRTVMBegin, // this filter (added much later) is meant to prevent volatile from drawing objects that are raytraced in RTVM (Ray Tracing View Mode)
    eRayTracedByRTVMEnd // everything between eRayTracedByRTVMBegin and eRayTracedByRTVMEnd will be skipped for some specific passes.
  };
  virtual void ActivateRayTracingFilter(ERaytracingFilterMode iFilterMode) {};

  inline int GetPLMViewMode() const {
      return _plmViewMode;
  }

  virtual void SetRepLayerNumber(int layerNumber);

  // Disable some properties
  // Useful for dedicated render (dialog, highlight, prehighlight main in vVolFrameData)

  enum class EProperty
  {
    eHighlight,
    eMain3DHighlight,
    ePreHighlight,
    eFurtive,
    eMain3DFurtive,
    eBackgroundViewMode,
    ePLMViewMode,
    eDialog,
    eCount
  };

  void DisableHighlight     (bool iOnOff = true);
  void DisablePrehighlight  (bool iOnOff = true);
  void DisableFurtive       (bool iOnOff = true);
  void Disable              (EProperty iProperty, bool iOnOff = true);
  bool IsDisabled(EProperty iProperty) const;

protected:

  void PushUVTransform(float const* iTrans);
  void PopUVTransform();

  virtual void SetIBLParameters(CATMaterialIBLParameters const*) {}

  virtual void SetLightingProperties(const LightingProperties&) {}

  struct ChannelTexture
  {
    IVisTexture* texture;
    unsigned int channel;
  };
  virtual void SetChannelTexture(unsigned int, IVisTexturePtr&) {}

  void DrawViewpoint(CATViewpoint* iVpt);
  void DrawFurtiveViewpoint(CATViewpoint* iVpt);

  virtual void Draw3DCanonicalRep(CAT3DCanonicalRep& iRep);

  inline void SetApplyWorldScale(bool iApply);
  inline bool ApplyWorldScale() const;

  void _BeginDraw(CATViewpoint &viewpoint);
  void _EndDraw(CATViewpoint &viewpoint);

#ifdef SG_COMPOSITES_MULTIOS
  CATSGContext* _currentSGContext;
  VizPrimitiveCacheBehavior _vizPrimitiveCacheBehavior;
#endif // SG_COMPOSITES_MULTIOS

  //  Push/Pop Matrix Management
  //  --------------------------

  int _nb_push;
  float _push_sag[MATRIX_LEVEL];
  float _push_cull[MATRIX_LEVEL];

  CATViewpoint *_push_viewpoint[MATRIX_LEVEL];
  CATViewport  *_push_viewport[MATRIX_LEVEL];

  CATViewpoint *_viewpoint_array[MATRIX_LEVEL];
  CATViewport  *_viewport_array[MATRIX_LEVEL];

  //  to manage calculation of real eyepoint for culling
  //  and face determination
  CAT4x4Matrix _push_modelMatrix[MATRIX_LEVEL];
  CATGraphicAttributeSet _push_att[MATRIX_LEVEL];

  int _ViewpointViewportSaved;
  CAT4x4Matrix _projectionMatrix;

  float _eyepoint[4];
  int _eyepointValid;

  int _current_priority, _current_delta, _priority_array_size;
  int* _delta_priority;
  int _old_view_mode;
  int      _Box;
  float    _BoxCenter[3];
  float    _BoxAxes[9];
  float    _BoxHalfSides[3];
  CATRep* _inherited_view_mode_owner;
  CATRep* _inherited_material_owner;
  //++ NC5 World Scale
  unsigned int _applyWorldScale : 1;
  unsigned int _curApplyWorldScale : 1;
  //- NC5 World Scale
  //++ NC5 Hybrid
  unsigned int _ignoreCompiledRep : 1;
  unsigned int _disableIgnoreCounter : 27;
  //-- NC5 Hybrid

  //++ NC5 World Scale
  CATMathVector _curScale;
  //-- NC5 World Scale
  unsigned int _geomIndex = 1;


  CATScissorStruct _currentScissor;
  CATBoolean _scissorEnabledFlag;

  CATVisRenderingStyleSet* _customRenderingStyle;

  unsigned int _drawDialog;

  // PLM Rendering Style
  virtual void SetCurrentPLMRenderingStlye(int iID);

  inline int IsPlmInheritModeOn() const {
    return _plmStyleInheritance != 0;
  }

  int _stateRepViewModeFilter;
  int _repViewModeInFilter;
  int _numRepViewModeFilter;

  int _curPolygonOffsetMode;

  enum eRVMFState {  //CATVisRepViewModeFilter States
    RVMF_ABSENT,
    RVMF_PUSHED,
    RVMF_ACTIVE,
    RVMF_POPPED
  };

  void PushDefaultMaterial(const VisMaterialApplication *ipMatApp);
  void PopDefaultMaterial();

private:
  virtual void MPDraw(::list<CATViewpoint> &viewpoint, const int, const float);

  void ApplyMaterial(bool iForceDefault = false);
  void ApplyDefaultMaterial();
  int                    m_LastViewMode;
  CATMaterialStack*      m_MaterialStack;

  float* m_uvTransformHeap;
  short  m_uvTransSize;
  short  m_uvTransTop;

  CATMaterialIBLParameters** m_iblParamsHeap;
  short  m_iblParamsSize;
  short  m_iblParamsTop;

  LightingProperties* m_lightPropHeap;
  short  m_lightPropSize;
  short  m_lightPropTop;

  std::map<unsigned int, std::vector<IVisTexturePtr>> m_multiTextures;

  std::set<const VisSGOccurrenceObserver*> m_ObserversForCompiledRep;

  bool m_DefaultMaterialActivation;

  unsigned short m_usInvalidTC;
  unsigned int _materialDeactivation;

  int           _plmViewMode;
  int           _plmCurID;
  unsigned int  _plmStyleInheritance;
  int           _plmSavedViewMode;
  int           _plmSavedInhAsmColor;
  int           _plmSavedInhColor;
  int           _plmSavedInhLinetype;
  int           _plmSavedInhLinewidth;

protected:
  CATGraphicAttributeSet _plmSavedCurAtt;

private:
  // MPCulling
#ifndef CULLING_REPARTITION
  int      _drawId;
  int      _currentRepFatherIndex;
  CATLONG32     _parity;
#endif
  int      _repRenderId;

  float _alphaFilterRatio;

  // <FBJ>
  CATVisFiltersStack* _filtersStack;
  unsigned int        _filtersActivation : 1;
  unsigned char       _layersFilter[1024];
  ::list<CATVisFilter>  _filtersOnMainVP;
  // </FBJ>

  CATDecalStack*      _decalStack;

  //RAII drawdata release
  struct DrawDataDeleter
  {
    inline DrawDataDeleter(CATRepRender& iRender) : m_Render(iRender) {}
    inline ~DrawDataDeleter() { m_Render.FreeDrawData(); }
    CATRepRender& m_Render;
  };

  void InitDrawDataStack();
  void* AllocDrawData();
  void FreeDrawData();

  void* m_DrawDataStack;
  int   m_DrawDataStackSize;
  int   m_DrawDataStackPos;
  unsigned int _numAF;
  VisFilteringEnums _eVisFilteringEnum;
  unsigned int _forceAFShow;
  CATRep* _inherited_forceAFShow_owner;

  unsigned int _disableProperty[static_cast<int>(EProperty::eCount)];
  Background3DViewMode _savedBackground3DViewMode;
};

inline int CATRepRender::IgnoreCompiledRep()
{
  return _ignoreCompiledRep ? 1 : 0;
}

inline void CATRepRender::SetApplyWorldScale(bool iApply)
{
  _applyWorldScale = iApply;
}

inline bool CATRepRender::ApplyWorldScale() const
{
  return _applyWorldScale;
}

#endif
