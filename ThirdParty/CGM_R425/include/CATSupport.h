#ifndef CATSupport_H
#define CATSupport_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   basic class which contains a list of viewpoint to be drawn
// ----------   in a specific way. viewpoint contains representations
//              which are materialized differently in fonction of the kind
//              of CATSupport instance.
//
//
//------------------------------------------------------------------------------
// Usage :      is used for graphic visualization and for plotting.
// -------      ( CATGraphicWindow or CATPaper are of kind CATSupport )
//
//------------------------------------------------------------------------------
// Main methods :         
// --------------
//                viewpoint management
//                  AddViewpoint
//                  RemoveViewpoint
//
//                definition of the render tool
//                  CreateDrawingRender
//
//
//
//------------------------------------------------------------------------------
// Class :      CATSupport
// -------        CATCallbackManager (System FW)
//
//------------------------------------------------------------------------------

#include "CATBoolean.h"
#include "CATViz.h" // JQT : Kept due to applicative build impact : CATViz --> SGInfra
#include "SGInfra.h"
#include "CATDataType.h"
#include "CATViewerUtility.h"
#include "CATCallbackManager.h"
#include "list.h"
#include "CATMathPointf.h"
#include "CATMathDirectionf.h"
#include "CATShadowEnum.h"
#include "CATVis2DModeType.h"
#include "VisClipPlaneDesc.h"

class CATPassContainerGeneral;
class CATSupportAlgoFactory;
class CAT4x4Matrix;
class CATGraphicMaterial;
class CATTexturePixelImage;
class CATRepPath;

#if defined(_IRIX_SOURCE) || defined (_AIX)
#  include <signal.h>
#else
class CATFPSThread;
class CATWaitingPoint;
#endif

class CATRender;
class CATDisplayList;
class CATViewpoint;
class CATCharacterFont;
class CATColorMap;
class CATUpdateEvent;
class CATSwapEvent;
class CATVizDisplayContext;
class CATPixelImage;
class CAT3DViewpoint;
class CAT3DLightSourceRep;
class CATPooledThread;

class CATVisuContext;
class CATFrameData;

class CAT3DBagRepWithBox;
class CAT3DGridPlane;
class CAT3DMirroring;
class CATVisInfiniteEnvironment;
class CATVisInfiniteEnvironmentOverload;
class CATVisInfiniteEnvironmentStack;
class CATVisAdvancedHighlight;
class CATVisAdvancedHighlightData;
class CATVisHighlightRenderingData;
class CATVisColorf;
class CATVisFilter;
class CATVisContextFilter;
class CATRepRender;

class CATMPKGWData;

class CATDataShadowMapping;
class CATVisuTexture;
class l_CATSupport;
class CATVisDynamicRenderingQualityData;
class CATVisRenderingStyleSet;

class VisFBO;
class CATVisuTexture;
class IVisTexture;
class IVisTexturePtr;
class CATCullingRenderGLCluster;
struct VisAntialiasingInfo; // NHD : Fix for TSK2859740 (0), VS2015 migration.
struct vGPUMemoryStat;
class vDirectStats;


/** @nodoc */
#define MAXNTEXTZ 2
/** @nodoc */
#define MAXNTEXTLAYER 12

/** @nodoc */
#define MAX_VIEWPOINT_BUFFER 100

/** @nodoc */
#define CAT_CURRENT_BIT                    0x00000001
/** @nodoc */
#define CAT_POINT_BIT                      0x00000002
/** @nodoc */
#define CAT_LINE_BIT                       0x00000004
/** @nodoc */
#define CAT_POLYGON_BIT                    0x00000008
/** @nodoc */
#define CAT_POLYGON_STIPPLE_BIT            0x00000010
/** @nodoc */
#define CAT_PIXEL_MODE_BIT                 0x00000020
/** @nodoc */
#define CAT_LIGHTING_BIT                   0x00000040
/** @nodoc */
#define CAT_FOG_BIT                        0x00000080
/** @nodoc */
#define CAT_DEPTH_BUFFER_BIT               0x00000100
/** @nodoc */
#define CAT_ACCUM_BUFFER_BIT               0x00000200
/** @nodoc */
#define CAT_STENCIL_BUFFER_BIT             0x00000400
/** @nodoc */
#define CAT_VIEWPORT_BIT                   0x00000800
/** @nodoc */
#define CAT_TRANSFORM_BIT                  0x00001000
/** @nodoc */
#define CAT_ENABLE_BIT                     0x00002000
/** @nodoc */
#define CAT_COLOR_BUFFER_BIT               0x00004000
/** @nodoc */
#define CAT_HINT_BIT                       0x00008000
/** @nodoc */
#define CAT_EVAL_BIT                       0x00010000
/** @nodoc */
#define CAT_LIST_BIT                       0x00020000
/** @nodoc */
#define CAT_TEXTURE_BIT                    0x00040000
/** @nodoc */
#define CAT_SCISSOR_BIT                    0x00080000
/** @nodoc */
#define CAT_ALL_ATTRIB_BITS                0x000fffff

/** @nodoc */
#define CAT_3D_WITH_ZDEPTH                 0x00000001
/** @nodoc */
#define CAT_3D_WITHOUT_ZDEPTH              0x00000002 
/** @nodoc */
#define CAT_3D_HIGHLIGHT                   0x00000004
/** @nodoc */
#define CAT_2D                             0x00000008
/** @nodoc */
#define CAT_2D_HIGHLIGHT                   0x00000010
/** @nodoc */
#define CAT_ALL                            0xffffffff

/** @nodoc */
typedef struct _CATOGLDrawMode
{
   unsigned int _activateDebug   : 1;
   unsigned int _triangles       : 1;
   unsigned int _strips          : 1;
   unsigned int _fans            : 1;
   unsigned int _edges           : 1;
   unsigned int _points          : 1;
   unsigned int _lods            : 1;
   unsigned int _voxels          : 1;
   unsigned int _voxelPoints     : 1;
   unsigned int _vboOnly         : 1;
   unsigned int _vboMesh         : 1;
   unsigned int _vboNoVbo        : 1;
   unsigned int _lodLevel        : 9;
   unsigned int _voxelLevel      : 9;

   _CATOGLDrawMode()
   {
      _activateDebug   = 0;
      _triangles       = 1;
      _strips          = 1;
      _fans            = 1;
      _edges           = 1;
      _points          = 1;
      _lods            = 0;
      _voxels          = 0;
      _voxelPoints     = 0;
      _lodLevel        = 0;
      _voxelLevel      = 0;
      _vboOnly         = 0;
      _vboMesh         = 1;
      _vboNoVbo        = 0;
   }

} CATOGLDrawMode;

class CATMathPlane;

/**
* Base class .
*/
class ExportedBySGInfra CATSupport : public CATCallbackManager
{
  friend class CATVisForceViewMode;
  friend class l_CATSupport;
  friend class VisSupportData;
  friend class SGInfraToVisuFConnectToolImpl;
  
public:
  
  CATDeclareClass;

  /**
   * Constructs the class from a width and an height.
   * @param width
   *  pixel width.
   * @param height
   *  pixelheight.
   * @param display
   *  diplay X. Must be NULL on WINDOWS.
   */
  CATSupport (const int width, const int height, const void *display = NULL);
  
  /** Copy Constructor. */
  CATSupport (const CATSupport &);
  
  virtual ~CATSupport();

 
  /**
   * Adds a given viewpoint.
   * 
   *@param iVpt
   * the viewpoint.
   * @param iPlace
   * integer value 
   *<ol>
   *<li> 1 = Foreground </li>
   *<li> 0 = Background </li>
   *</ol>
   */
  virtual void AddViewpoint ( CATViewpoint *iVpt, int iPlace = 1 );
   
  /**
   * Removess a given viewpoint.
   * 
   *@param iVpt
   * the viewpoint.
   */
   virtual void RemoveViewpoint (CATViewpoint *iVpt );


  /**
   * Gives the minimum pixel size for objects to be drawn. 
   *<br><b>Role</b>:
   * Objects which size is less than the <tt> iCullingPrecision</tt> are not drawn.
   *
   * @param iCullingPrecision
   * the minimum pixel size for objects to be drawn.
   */
  inline void SetCullingPrecision ( const int iCullingPrecision );

  /**
   * Gives the minimum pixel size for objects to be drawn. 
   *<br><b>Role</b>:
   * Objects which size is less than the <tt> iCullingPrecision</tt> are not drawn.
   *
   * @param iCullingPrecision
   * the minimum pixel size for objects to be drawn.
   */
  inline void SetCullingPrecisionf ( const float iCullingPrecision );


  /** Returns the minimum pixel size. */
  inline int GetCullingPrecision() const;

  /** Returns the minimum pixel size. */
  inline float GetCullingPrecisionf() const;

  /**
   * Sets the culling vanishing ratio
   * <br><b>Role</b>:
   * Objects which size is greater that ratio * total scene size are never culled by pixel culling
   */
  inline void SetCullVanishingRatio(float iRatio);

  /**
   * Returns the culling vanishing ratio
   */
  inline float GetCullVanishingRatio() const;


  /**
   * Sets the sag in pixel size.
   *<br><b>Role</b>:
   * sag is used for determining which level of details to use.
   * @param iSagPrecision
   * the sagprecision.
   *  
   */
  inline void SetSagPrecision ( const float iSagPrecision );

  /** Returns the sag precision. */
  inline float GetSagPrecision() const;

  /**
   * Returns the indexed color map. 
   * @see CATColorMap
   */
  inline CATColorMap * GetColorMap() const;
  
  /** @nodoc */
  virtual CATCharacterFont * GetCharacterFont() const;
	
  
  /**
   * Returns whether the point to pixel scale can be changed on current CATSupport
   * @param iScale
   * the new point to pixel scale factor.
   */
  virtual CATBoolean SetPointToPixelScale(const float iScale);
  
  /**
   * Returns the point to pixel scale (used for text and UI size regarding screen quality).
   */
  inline float GetPointToPixelScale() const;

  
  /**
   * Sets one millimeter size in pixel size.
   * @param iSize
   * the pixel size .
   */
  inline void SetMMInSupportUnit(const float iSize);

  /**
   * Returns the millimeter size in pixel size.
   */
  inline float GetMMInSupportUnit() const;
 
  /**
  * In case of a large screen (height > 1m), returns the ratio between said height and a "regular" screen height of 30 cm.
  */
  float GetLargeScreenRatio() ;

  /**
   * Retreives the heigth and width of the current  CATSupport.
   * @param oWidth
   * the width.
   * @param oHeight
   * the height.
   */
  inline void GetWidthAndHeight( float &oWidth, float &oHeight ) const;

  /**
   * Sets the heigth and width of the current  CATSupport.
   * @param iWidth
   * the width.
   * @param iHeight
   * the height.
   */
  inline void SetWidthAndHeight( const float iWidth, const float iHeight);

  /**
   * Sets the ratio heigth/width of one pixel.
   *<br><b>Role</b>:
   * it is useful when pixel is not a squarre. It is screen-dependant.
   */
  inline void SetRatioWH(const float iRatio);
  
  /**
   * Returns the ration heigth/width of one pixel.
   */
  inline float GetRatioWH() const;

	/** @nodoc */
  inline void  SetScale(const float iScaleW, const float iScaleH);
	/** @nodoc */
  inline void  GetScale(float & oScaleW, float & oScaleH) const;

  /** @nodoc */
  void SetWorldOrientation(CATVisWorldOrientation iWorldOrientation);
  /** @nodoc */
  inline CATVisWorldOrientation GetWorldOrientation() const;
  
  //  graphic material managment
  //  --------------------------
	/** @nodoc */
  void SetGraphicMaterial(CATGraphicMaterial * iMat);
	/** @nodoc */
  void ResetGraphicMaterial();
	/** @nodoc */
  inline CATGraphicMaterial * GetGraphicMaterial() const;
  
	/** @nodoc */
  void InitAlgoData(CATFrameData* i_prFrameData);

	/** @nodoc */
  void DoDrawJob();

  /**
   * Draws the scene.
   */
  virtual void Draw    (void);
  
  

  /**
   * Returns whether or not fog is active.
   *@return integer
   *<ol>
   *<li> 1 = fog is active </li>
   *<li> 0 = fog is not active </li>
   *</ol>
   */
  inline int IsFogOn() const;

  /**
   * Sets the fog mode.
   *@param iFogMode
   *<ol>
   * <li> 0 = fog is off</li>
   * <li> 1= fog is on </li>
   *</ol>
   */
  inline void SetFogMode (const int iFogMode);

  /** @nodoc */
  inline int  GetTransparencyMode() const;

  /** @nodoc */
  inline void SetTransparencyMode (const int);
  
  /**
   * Returns whether or not the antialiasing mode for lines is active.
   *@return integer
   *<ol>
   * <li> 0 = antialiasing is off</li>
   * <li> 1 = antialiasing is on </li>
   *</ol>
   */
  inline int  GetAntiAliasingMode() const;

  /**
   * Sets the antialiasing mode for lines.
   *@param iAntialiasingMode
   *<ol>
   * <li> 0 = antialiasing is off</li>
   * <li> 1 = antialiasing is on </li>
   *</ol>
   */
  inline void SetAntiAliasingMode (const int iAntialiasingMode);
  
  

  /** 
   * Sets the background color.
   *@param iR
   * the red composant color.
   *@param iG
   * the green composant color.
   *@param iB
   * the blue composant color.
   */
  virtual void SetBackgroundColor (const float iR, const float iG , const float iB);

  /** 
   * Retreives the background color.
   *@param oR
   * the red composant color.
   *@param oG
   * the green composant color.
   *@param oB
   * the blue composant color.
   */
  void GetBackgroundColor (float *oR, float *oG, float *oB);
  
  /** 
   * Sets the global ambient light color.
   *@param iR
   * the red composant color.
   *@param iG
   * the green composant color.
   *@param iB
   * the blue composant color.
   */
  virtual void SetGlobalAmbientLight (const float iR , const float iG, const float iB);
  
  /** 
   * Retreives the global ambient light color.
   *@param oR
   * the red composant color.
   *@param oG
   * the green composant color.
   *@param oB
   * the blue composant color.
   */
  inline void GetGlobalAmbientLight (float *oR, float *oG, float *oB);

  /** 
   * Sets default material properties.
   *@param iDiffAmbCoef
   * the diffuse and ambient coefficient.
   *@param iSpecCoef
   * the specular coefficient.
   *@param iShininess
   * the shininess.
   */
  inline void SetDefaultMaterialProperties(float iDiffAmbCoef, float iSpecCoef, float iShininess);

  /** 
   * Retreives default material properties.
   *@param oDiffAmbCoef
   * the diffuse and ambient coefficient.
   *@param oSpecCoef
   * the specular coefficient.
   *@param oShininess
   * the shininess.
   */
  inline void GetDefaultMaterialProperties(float& oDiffAmbCoef, float& oSpecCoef, float& oShininess);
 
  /** 
   * Activates or Deactivates the global ambient light.
   *@param iOnOff
   * 0 = off.
   * 1 = on.
   */
  void SetAmbientActivation(unsigned int iOnOff);

   /**
   * Returns whether or not ambient light is active.
   *@return integer
   *<ol>
   *<li> 1 = ambient ligh is active </li>
   *<li> 0 = ambient ligh is not active </li>
   *</ol>
   */
  inline unsigned int IsAmbientActivated();
 
  /** @nodoc  */
  inline int GetLightViewerMode(void);
  /** @nodoc  */
  inline void SetLightViewerMode(int);
  
  // Initialize the viewpoint for them to be seen
  /** @nodoc */
  void InitViewpoints();

  // Viewpoint information 
  /** @nodoc */
  inline ::list<CATViewpoint> & GetListOfViewpoint() ;
  
  
  // Visualization mode control:
  // ---------------------------
  //   Refer to the CATViewer class for method explanation.
  //   - GetViewMode: Returns the internal <_view_mode> parameter holding all
  //     the visualization modes.

  /**
   * Sets the viewmode for viewer enclosed in the current CATSupport.
   * @param iMode:
   *  The viewer mode.
   *  <b>Legal values</b>: @href CATViewModeType 
   * @param iActive
   * 0 = off.
   * 1 = on.
   *
   */
  virtual void SetViewMode (const int iMode,const int iActive);

  /**
   * Returns whether or not the given mode is active.
   * @param iMode
   * the viewer mode.
   * <br><b>Legal values</b>: @href CATViewModeType 
   */
  int ViewMode (const int iMode) const;
  
  /**
   * Returns the current viewer mode of the current  CATSupport.
   * @see CATViewModeType 
   */
  int GetViewMode (void) const;

  /**
   * Adds a clipping plane(you cannot define more than six clipping planes).
   *
   * @param iNbPlanes
   *  number of planes.
   * @param iPoint
   * array of 3x<tt>iNbPlanes</tt> of coordinates. Each (x,y,z) represents a point belonging
   * to a clipping plane. And there is only one point per plane.
   * @param iNnormal
   * array of 3x<tt>iNbPlanes</tt> of coordinates. Each (x,y,z) represents a normal to one plane.
   *  And there is only one normal per plane.
  * @param iCappingPlaneFlags
   * Combination of VisClipPlaneDesc flags
   */
  void AddClippingPlane (const int iNbPlanes, const float *iPoint, const float *iNnormal, const int iCappingPlaneFlags = VisClipPlaneDesc::fCapping);
  
  /**
   * Resets all the clipping planes.
   */
  void RemoveClippingPlane ();

  /**
   * Returns the number of clipping planes.
   * @param oPoint
   * pointer to an array of 3x<tt>iNbPlanes</tt> of coordinates. Each (x,y,z) represents a point belonging
   * to a clipping plane. And there is only one point per plane.
   * @param oNnormal
   *  pointer to an array of 3x<tt>iNbPlanes</tt> of coordinates. Each (x,y,z) represents a normal to one plane.
   *  And there is only one normal per plane.
   * @param oCappingPlaneSeen
   *  <ol>
   *  <li> 0 = intersection between clipping planes and volumic graphical representations is not filled in </li>
   *  <li> 1 = intersection between clipping planes and volumic graphical representations is filled in </li>
   * </ol> 
   * @deprecated R420 GetClippingPlaneInfo
   */
  inline int IsClipped (float **oPoint, float **oNormal, int *oCappingPlaneSeen);
  /**
   * Returns the number of clipping planes.
   * @param oPoint
   * pointer to an array of 3x<tt>iNbPlanes</tt> of coordinates. Each (x,y,z) represents a point belonging
   * to a clipping plane. And there is only one point per plane.
   * @param oNnormal
   *  pointer to an array of 3x<tt>iNbPlanes</tt> of coordinates. Each (x,y,z) represents a normal to one plane.
   *  And there is only one normal per plane.
   * @param oCappingPlaneFlags
   *  combination of VisClipPlaneDesc::Flags active on the current plane
   */
  inline int GetClippingPlaneInfo (float **oPoint, float **oNormal, int *oCappingPlaneFlags);

  // Thickness table management to set and get the size in pixel for visualization
  // and in mm for plotting for one entry of the table
  /** @nodoc */
  void SetThicknessTable(int indice,float thicknessMM,float thicknessPixel=0.0);

  // Thickness table management to set and get the size in pixel for visualization
   /** @nodoc */
  void GetPixelThicknessTable(float thickness[6]) const;
  /** @nodoc */
  void SetPixelThicknessTable(float thickness[6]);

  // Thickness and linetype table management to set and get the real size in mm for plotting
   /** @nodoc */
  void GetMMThicknessTable(float thickness[6]) const;
   /** @nodoc */
  void SetMMThicknessTable(float thickness[6]);
   /** @nodoc */
  void GetLinetypeTable(int nbseg[7], float des[7][16]) const;
   /** @nodoc */
  void SetLinetypeTable(int nbseg[7], float des[7][16]);

  /** 
   * Clears the screen.
   */
  virtual void Clear();
 /** @nodoc */
  virtual void Clear(int i_mask);
 /** @nodoc */
  virtual void Clear(int iMask, const CATVisColorf& iColor);
 /** @nodoc */
  virtual void ClearStencil(int i_clearValue);
 /** @nodoc */
  virtual void EnableStencil();
 /** @nodoc */
  virtual void DisableStencil();

 /** @nodoc */
  virtual void FilterDrawToWindow(short i_redFlag, short i_greenFlag, short i_blueFlag, short i_alphaFlag);
  
  /** 
   * Swaps back buffer to front buffer.
   */
  virtual void Swap();

  /** @nodoc */
  virtual void SwapBackBuffer();
  /** @nodoc */
  virtual void SaveRenderBuffer();
  /** @nodoc */
  virtual void RestoreRenderBuffer();

  /** 
   * Sets the stereo mode.
   * @param iMode
   *<ol>
   *<li>0 = off </li>
   *<li>1 = manual </li>
   *<li>2 = automatic </li>
   *</ol>
   * @param iEyeGap 
   * gap between the eyes (model unit). Avaible only in manual mode.
   */
  virtual void SetStereoMode (const int iMode, const float iEyeGap);
 
  /**
   * Retreives the stereo mode.
   * @param oMode
   *<ol>
   *<li>0 = off </li>
   *<li>1 = manual </li>
   *<li>2 = automatic </li>
   *</ol>
   * @param oEyeGap 
   * gap between the eyes (model unit). Avaible only in manual mode.
   */
  inline void GetStereoMode (int *oMode, float *oEyeGap) const;
#ifdef _IRIX_SOURCE
  /** @nodoc */
 inline int GetStereoMode(void);
#endif
  /**
   * Sets the back buffer as active : we are drawing into it.
   */
  virtual void SwitchBack();

  /**
   * Sets  the front buffer as active : we are drawing into it.
   *<br><b>Role</b>: when you are in furtive mode you draw graphical representations
   * into the front buffer.
   */
  virtual void SwitchFront();
  

  /**
   * Sets the left back buffer as active when working in stereo mode: we are drawing into it.
   */
  virtual void SwitchBackLeft();
  /**
   * Sets the right back buffer as active when working in stereo mode: we are drawing into it.
   */
  virtual void SwitchBackRight();
  /**
   * Sets the left front buffer as active when working in stereo mode: we are drawing into it.
   */
  virtual void SwitchFrontLeft();
  /**
   * Sets the right front buffer as active when working in stereo mode: we are drawing into it.
   */
  virtual void SwitchFrontRight();


  /** @nodoc */
  inline int GetDrawBuffer() const;
  /** @nodoc */
  inline int GetFrameBufferObjectId () const;

  /** @nodoc */
  inline int GetMirror(void) const;
  /** @nodoc */
  inline void SetMirror(int);

  /** @nodoc */
  virtual void SetOcclusionMode (const short);
  /** @nodoc */
  virtual short GetOcclusionMode () const;
  /** @nodoc */
  virtual void SetWireframeMode (const short);
  /** @nodoc */
  virtual short GetWireframeMode () const;

  /** @nodoc */
  virtual void SetLogicalOperation (const int);
  /** @nodoc */
  inline int GetLogicalOperation () const ;
  /** @nodoc */
  inline void UseTimer(const int); 
  /** @nodoc */
  inline int  GetUseTimer(); 
  /** @nodoc */
  inline int  GetInterruptDraw();
  /** @nodoc */
  inline void SetInterruptDraw(const int);
  /** @nodoc */
  inline int GetDithering() const;
  /** @nodoc  Shared*/
  virtual int *GetContextId();
  /** @nodoc  Local*/
  virtual int *GetLocalContextId();
  /** @nodoc */
  CATPooledThread* GetContextThread();
  /** @nodoc */
  virtual int *GetSupportId();

  //------------------------------------------------------------------
  /** @nodoc */ 
  inline int GetFullScreenParameter (int *, int *, int *, int *);
  /** @nodoc */ 
  inline void SetFullScreenParameter (int , int , int , int );

  
  /** @nodoc */
  virtual CATRender *CreateCullingRender();
  void CleanCullingRender(CATRender*);
  /** @nodoc */
  virtual CATRender *CreateDrawingRender();

  /** @nodoc */
  virtual ::list<CATViewpoint>          Culling (::list<CATViewpoint> &viewpoint);

  /** @nodoc */
  virtual void          Drawing (::list<CATViewpoint> &viewpoint);

  /** @nodoc */
  virtual void DrawWithRender (CATRender &, ::list<CATViewpoint> &viewpoint);

  /** @nodoc */
  void ResetDL(::list<CATViewpoint> &);

  /** @nodoc */
  inline int GetPolygonMode() const;

  /** @nodoc */
  inline int IsLowlightActivated();
  /** @nodoc */
  inline void ActivateLowlight(const int iOnOff=0);

  /** @nodoc */
  inline void SetBackground3DViewMode(const Background3DViewMode iMode);
  /** @nodoc */
  inline const Background3DViewMode GetBackground3DViewMode();

  /** @nodoc */
  virtual void SetViewportSize(int width, int height);

  /** @nodoc */
  virtual void *ReadZBuffer (int format);

  /** @nodoc */
  virtual void WriteZBuffer (int format, void *data);

  /** @nodoc */
  virtual float *ComputeDistanceMap(float *zBuffer) {return NULL;};

  /** @nodoc */
  virtual void RendertoPixelBuffer(int flag);
  
  /** @nodoc */
  virtual bool IsNewVisu() {return false;}

#ifdef _WINDOWS_SOURCE
  /** @nodoc */
  inline void* GetState();

  /** @nodoc */ 
  inline unsigned int & GetNVRenderNormal();

  /** @nodoc */ 
  inline float & GetNVRenderNormalWidth();
  
  /** @nodoc */ 
  inline float & GetNVRenderNormalHeight();

#endif

  /** @nodoc */
  inline int GetDrawPathMode(void);


#if defined(_IRIX_SOURCE) || defined(_WINDOWS_SOURCE)
  /** @nodoc */
  inline void* GetShaderDrawAction();
  /** @nodoc */
  inline void SetShaderDrawAction(void *);
  /** @nodoc */
  inline void* GetShaderCompileAction();
  /** @nodoc */
  inline void SetShaderCompileAction(void *);
 /** @nodoc */
  void *_shaderCompileAction;
 /** @nodoc */
  void *_shaderDrawAction;
#endif

#ifdef _IRIX_SOURCE
  /** @nodoc */
 CATMPKGWData* GetMPKGWData();
  /** @nodoc */
 void SetMPKGWData(CATMPKGWData *p);
  /** @nodoc */
  inline void* GetState();
 /** @nodoc */
  CATMPKGWData* _pMPKGwData;
 
 /** @nodoc */
  int   _spiviewpointflag;
#endif

  /** @nodoc */
  inline static int GetMaxLightNumber() {return _MaxNbLight;};
  /** @nodoc */
  inline void ResetLight() {_NbLight=0;};
  /** @nodoc */
  inline int AddLight() {_NbLight++;return _NbLight;};
  /** @nodoc */
  void SetDisplayContext(CATVizDisplayContext *vdc);
  /** @nodoc */
  inline CATVizDisplayContext * GetDisplayContext() {return _DisplayContext;};

  /** @nodoc */
  virtual void SetMultiThreadCullingMode(int nb_thread);
  
  /** @nodoc 
   *  return 0 if mode off and the number of culling threads otherwise */
  int GetMultiThreadCullingMode();

  /** @nodoc */  
  inline void SetMultiTexture(int multi) { _multiTexture = multi; };

  /** @nodoc */
  inline int GetMultiTexture(void) { return _multiTexture; };
  
  /** @nodoc */
  virtual void DrawMapToWindow(CATVisuTexture* i_pImage, float i_point1X, float i_point1Y, float i_point2X, float i_point2Y);
  /** @nodoc */
  virtual void DrawMapToWindow(int i_textureId, float i_point1X, float i_point1Y, float i_point2X, float i_point2Y);
  /** @nodoc */
  virtual void SetShadowMapSize (const int shadowDepthMapPrecision);
  /** @nodoc */
  virtual void SetShadowMode (const CATVisShadowMode);
  /** @nodoc */
  CATVisShadowMode GetShadowMode () const;
  /** @nodoc */
  virtual void SetShadowOnFlag (CATBoolean i_shadowOnFlag);
  /** @nodoc */
  CATBoolean GetShadowOnFlag ();
  /** @nodoc */
  void SetShadowVersion (const CATVisShadowVersion);
  /** @nodoc */
  CATVisShadowVersion GetShadowVersion () const;

  
  /** @nodoc */
  void SetLightViewFitting (const CATVisLightViewFittingMode i_lightViewFitting, CAT3DViewpoint*);
  /** @nodoc */
  void SetLightViewFitting (const CATVisLightViewFittingMode i_lightViewFitting);
  /** @nodoc */
  CATVisLightViewFittingMode GetLightViewFitting () const;
  /** @nodoc */
  int GetShadowMapSize() const;
  /** @nodoc */
  void SetAllShadowMapUpdateFlag();
  /** @nodoc */
  void AddShadowingLight (CAT3DLightSourceRep* i_pLightSourceRep);
  /** @nodoc */
  //deprecated, use AddShadowingLight
  void SetShadowingLight (CAT3DLightSourceRep* i_pLightSourceRep);
  /** @nodoc */
  void RemoveShadowingLight (CAT3DLightSourceRep* i_pLightSourceRep);
  /** @nodoc */
  CAT3DLightSourceRep* GetShadowingLight(int i_nb =0);
  /** @nodoc */
  CATDataShadowMapping* GetShadowMappingData(int i_nb =0);
   /** @nodoc */
  void UpdateLightShadowData(CATDataShadowMapping* i_pShadowMappingData);
  /** @nodoc */
  CAT3DBagRepWithBox* GetShadowingRep ();

  /** @nodoc */
  void SetShadowPolygonOffset(int i_shadowPOFactor, int i_shadowPOUnit);
  /** @nodoc */
  void GetShadowPolygonOffset(int &o_shadowPOFactor, int &o_shadowPOUnit);

  /** @nodoc */
  void SetPBufferActivated (const int i_flag);
  /** @nodoc */
  int GetPBufferActivated () const;
  /** @nodoc */
  static int IsShadowMappingPossible();
  /** @nodoc */
  static int IsShadowMappingPossible(CATVisShadowVersion i_shadowVersion);

  /** @nodoc */
  void SetAllowAdvancedDrawingCapabilities(int i_onOff);
  /** @nodoc */
  int  GetAllowAdvancedDrawingCapabilities();

  /** @nodoc */
  inline void DisableLighting(int);
  /** @nodoc */
  inline int IsLightingDisabled() const;

  /** @nodoc */
  inline void SetSpecific2DMode(const int iOnOff);

  /** @nodoc */
  inline void SetOGLRenderDrawMode(CATOGLDrawMode iDrawMode){ _OGLRenderDrawMode = iDrawMode; };
  /** @nodoc */
  inline CATOGLDrawMode GetOGLRenderDrawMode(){ return _OGLRenderDrawMode; };
  /**
  * Returns the grabbed <tt>CATPixelImage</tt> by reading the pixel rectangle at specified location (lower left corner) and size (rectangular block of pixels) from the framebuffer.
  * @param x
  *   Specify the X window coordinate of the first pixel that is read from the frame buffer.
  * @param y
  *   Specify the Y window coordinate of the first pixel that is read from the frame buffer.
  * @param width
  *  The width of the captured image that specifies the horizontal dimension of the pixel rectangle to read. width <= 0 is invalid.
  * @param height
  *  The height of the captured image that specifies the vertical dimension of the pixel rectangle to read. height <= 0 is invalid.
  * @param img
  *  The input pointer to the <tt>CATPixelImage</tt>.
  *  The default value for this parameter is NULL.
  *  Only <tt>CATPixelImageFormat</tt> RGBA is supported.
  *  If provided the pixels of img will be modified with pixel rectangle and the same is returned.
  * @param buffer
  *  The frame buffer to read from. The default value for this parameter is 0.
  *  0 = Front Buffer
  *  1 = Back Buffer
  * @return
  *  The pointer to the new or modifed input <tt>CATPixelImage</tt>. Values for pixels that lie outside the Buffer are undefined.
  */
  virtual CATPixelImage* GrabPixelImage (int x, int y, int width, int height, CATPixelImage *img = NULL, int buffer = 0) {return NULL;};
  /** @nodoc */
  virtual CATTexturePixelImage *GrabPixelZImage(int x, int y, int width, int height, CATTexturePixelImage *img = NULL, int buffer = 0) {return NULL;};
  /** @nodoc */
  virtual void GrabVisuTexture(int i_x, int i_y, int i_width, int i_height, CATVisuTexture* ioTexture);
  
  /** @nodoc */
  // GrabIVisTexture please use the one using IVisTexturePtr
  virtual void GrabIVisTexture(int i_x, int i_y, int i_width, int i_height, IVisTexture * ioTexture, unsigned int iTextureSlice = 0);

  /** @nodoc */
  virtual void GrabIVisTexture(int i_x, int i_y, int i_width, int i_height, IVisTexturePtr &ioTexture, unsigned int iTextureSlice = 0);

#ifdef _SUNOS_SOURCE //DDG+
  /** @nodoc */
  inline int  getRenderThread() { return(_mirrorxy); }
  /** @nodoc */
  inline void setRenderThread(int thrd) { _mirrorxy = thrd; }
#endif //DDG-

  /** @nodoc */
  void SetStayReadyForSpriteFlag(short i_flag);
  /** @nodoc */
  void ActivateSprites(int iOnOff);  
  /** @nodoc */
  void ForceSpritesActivation(int iOnOff);
  /** @nodoc */
  void ForceSpritesDeactivation(int iOnOff);
  /** @nodoc */
  int AreSpritesActivated(void);
   /** @nodoc */
  void SetUpdateSpritesMapsFlag(short i_flag);



#if  defined (_WINDOWS_SOURCE) || defined (_COCOA_SOURCE) || defined (_ANDROID_SOURCE)
 /** @nodoc */ 
  virtual void ComputeVideoSize();
#else
  /** @nodoc */
  virtual void ComputeVideoSize ( void *display = NULL);
#endif

  /** @nodoc */
  inline void * GetDisplay() { return _display; };

  /** @nodoc */
  void SetBoxPointAndNormal(const int, const float *, const float *);
  /** @nodoc */
  inline int GetBoxNbPlane() { return _NbBoxPlanes;};  
  /** @nodoc */
  inline void GetBoxPointAndNormal(CATMathPointf **point, CATMathDirectionf **normal) { *point = _BoxPoint; *normal = _BoxNormal;};

  /** @nodoc */
  void Set2DMode(CATVis2DModeType i_2DMode);
  /** @nodoc */
  CATVis2DModeType Get2DMode();
  /** @nodoc */
  void Set2DModePlane(CATMathPlane& i_plane);
  /** @nodoc */
  CATMathPlane* Get2DModePlane();

  /** @nodoc 
   * Set a default Fx material that will be used with SKIN, VOLUME and TRANSPAR
   * when the system is shader compliant
   */
  void SetDefaultFxMaterial(CATGraphicMaterial* i_pDefaultFxMaterial);
  /** @nodoc
   * Get the current default Fx material. Return NULL if no default Fx material is set
   */
  CATGraphicMaterial* GetDefaultFxMaterial();

  /** @nodoc */
  virtual VisFBO * GetBackBufferFBO();

  /** @nodoc */
  virtual VisFBO * GetFBOMultisampled();

  /** @nodoc */
  unsigned int GetAAFactor() const;

  /** @nodoc */
  void SetAAFactor(const unsigned int & iFactor);

  /** @nodoc */
  unsigned int IsAAEnabledOnSSAO() const;

  /** @nodoc */
  void SetAAOnSSAO(unsigned int iActivateAA); //1 --> Enable the antialiasing on the SSAO, 0 to disable

  /** @nodoc */
  unsigned int IsAAEnable() const;

  /** @nodoc */
  void SetFullSceneFBO(CATFrameData * iFrameData = NULL);

  /** @nodoc */
  void UnsetFullSceneFBO();

  /**
* For Varjo VR inner view
* Retreives the heigth and width of the current  CATSupport.
* @param oWidth
* the width.
* @param oHeight
* the height.
*/
  inline void GetInnerWidthAndHeight(float &innerWidth, float &innerHeight) const;

  /**
   * For Varjo VR inner view
   * Sets the heigth and width of the current  CATSupport.
   * @param iWidth
   * the width.
   * @param iHeight
   * the height.
   */
  inline void SetInnerWidthAndHeight(const float innerWidth, const float innerHeight);
  
  /**
   * For Varjo VR inner view
   * Returns the ration heigth/width of one pixel.
   */
  inline float GetInnerRatioWH() const;

  /**
   * For Varjo VR inner view
   * Sets the ratio heigth/width of one pixel.
   *<br><b>Role</b>:
   * it is useful when pixel is not a squarre. It is screen-dependant.
   */
  inline void SetInnerRatioWH(const float iRatio);

  /**
   * For Varjo VR inner view
   * Sets one millimeter size in pixel size.
   * @param iSize
   * the pixel size .
   */
  inline void SetInnerMMInSupportUnit(const float iSize);

  /**
   * For Varjo VR inner view
   * Returns the millimeter size in pixel size.
   */
  inline float GetInnerMMInSupportUnit() const;

public:
  /** @nodoc */
  virtual CATVisuContext* GetVisuContext();

  /** @nodoc */
  static void SetAlgoFactory(CATSupportAlgoFactory* i_pAlgoFactory);

  /** @nodoc */
  void DrawSceneDirectly(CATViewpoint *i_prViewpoint = NULL, short i_doNotSwapFlag = 0, short i_forceSpriteActivation = 0);

  /** @nodoc */
  virtual void DrawWithDefaultRender(::list<CATViewpoint>& iViewpoint);

  /** @nodoc */
  CATPassContainerGeneral *GetPassContainer();
  /** @nodoc */
  void SetNewPassContainer(CATPassContainerGeneral *i_pPassContainer);
  /** @nodoc */
  void UncachePassContainer();
  /** @nodoc */
  void UpdateAlgo();

  /** @nodoc */
  void LockUpdatePassAlgoFlag ();
  /** @nodoc */
  void UnlockUpdatePassAlgoFlag ();

  /** @nodoc */
  void SetUpdatePassAlgoFlag (short i_updatePassAlgoFlag);
  /** @nodoc */
  short GetUpdatePassAlgoFlag () const;

  /** @nodoc */
  virtual HRESULT GivePBuffer(int& io_width, int& io_height);

  /** @nodoc */
  virtual void  UnsetContext();
  /** @nodoc */
  virtual short SetContext();

  /** @nodoc */
  virtual void SetShadowOffset();
  /** @nodoc */
  virtual void UnsetShadowOffset();
  /** @nodoc */
  virtual void DrawSpot(float i_spotAngle, float i_nearPlan, const CAT4x4Matrix &i_projectionMatrix);

  /** @nodoc expose... Better in GW. */
  short GetExposeJustDoneFlag();
  /** @nodoc expose... Better in GW. */
  void UnsetExposeJustDoneFlag();

  /** @nodoc */
  inline void Set2DLayoutPrintMode(const int mode);
  /** @nodoc */
  void SetBlankingPolygonMode(const int mode);
  /** @nodoc */
  int GetBlankingPolygonMode();

  /** @nodoc */
  inline void SetDisplayLayerType(const unsigned int mode);
  /** @nodoc */
  inline unsigned int GetDisplayLayerType();
  
  /** @nodoc */										
   void SetSeeThruMode(unsigned int i_flag);
  /** @nodoc */
  unsigned int GetSeeThruMode();

  /** @nodoc */
  void SetSeeThruPlane(CATMathPlane* i_pPlane);
  /** @nodoc */
  CATMathPlane* GetSeeThruPlane();

  /** @nodoc */
  void ActivateMirroring(int iOnOff);

  /** @nodoc */
  inline int IsMirroringActivated() const;
  
  /** @nodoc */
  int IsSSAOActivated() const;
  
  /** @nodoc */
  void ActivateAdvancedHighlight(unsigned int iOnOff, const CATVisAdvancedHighlightData& iData);

  /** @nodoc */
  const CATVisHighlightRenderingData& GetHighlightRenderingData() const;

  /** @nodoc */
  int IsAdvancedHighlightActivated() const;

  /** @nodoc */
  void ActivateGridPlane(int iOnOff, const CATMathDirectionf& iNormal, const CATMathDirectionf& iDir);
  /** @nodoc */
  int IsGridPlaneActivated() const;
  /** @nodoc */
  void UpdateGridPlane();
  /** @nodoc */
  void ModifyGridPlane(int iAutomaticMode, const CATMathPointf& iCenter, float iRadius);
  /** @nodoc */
  void LockGridPlaneAutoPosition(int iLock);


  /** @nodoc */
  virtual void SetInfiniteEnvironment(CATVisInfiniteEnvironment* iEnv);
  /** @nodoc */
  virtual void SetInfiniteEnvironment(const CATString& iName);
    /** @nodoc */
  virtual void PushInfiniteEnvironment(CATVisInfiniteEnvironment* iEnv);
  /** @nodoc */
  virtual void PushInfiniteEnvironment(const CATString& iName);
  /** @nodoc */
  virtual void PopInfiniteEnvironment();
  /** @nodoc */
  virtual void PushOverloadInfiniteEnvironment(CATVisInfiniteEnvironmentOverload* iOverloadEnv);
  /** @nodoc */
  virtual void PopOverloadInfiniteEnvironment(CATVisInfiniteEnvironmentOverload* iOverloadEnv=NULL);
  /** @nodoc */
  void LockInfiniteEnvGroundUpdate(int iOnOff);
  /** @nodoc */
  void UpdateInfiniteEnvGround();
  /** @nodoc */
  void InvalidInfiniteEnv(int iForceUpdate=0);
  /** @nodoc */
  int IsEnvironmentActivated(const char* iEnvProperty=NULL) const;
  /** @nodoc */
  const CATString& GetInfiniteEnvironmentRootName();
  /** @nodoc */
  CATVisInfiniteEnvironment* GetCloneOfInfiniteEnvironment();
  /** @nodoc */
  void CloneInfiniteEnvironment(const CATSupport& iSupportToClone);
  /** @nodoc */
  virtual void OnAmbianceModified();
  
 /** @nodoc */
  inline CATBoolean IsSmartLoadingActivated() { return _smartLoadingActivated; };
  /** @nodoc */
  inline void       ActivateSmartLoading() { _smartLoadingActivated = TRUE; };

  /** @nodoc */
  virtual unsigned int PolyhedralHLR();


  /** @nodoc */
  int GetNbJitteringSamples() const;

  /** @nodoc */
  void SetNbJitteringSamples(int iNbSamples);

  /** @nodoc */
  int	Is_Super_Sampling_FSAA(int &oNbSamples);

  /** @nodoc */
  int	Is_Super_Sampling_FSAA(void);

  /** @nodoc */
  void SetHighlightMode (int iHighlightMode, int iFromSettings=1);

  /** @nodoc */
  int GetHighlightMode () const;

  /** @nodoc */
  void FillRenderWithFilter(CATRepRender& ioRender);

  /** @nodoc */  
  void SetDynamicRenderingQuality(const CATVisDynamicRenderingQualityData& iData);

  /** @nodoc */
  l_CATSupport& GetLetter() const;

  /** @nodoc */
  void SetCustomRenderingStyle(CATVisRenderingStyleSet* iRenderingStyle);

  /** Synchronize slave windows together in Multi GPU case. This method is only available in the new render engine.
   *  @return E_FAIL it all windows fail to synchronize. S_OK if all succeed, S_FALSE if there are failure but at least one is OK.
   */
  virtual HRESULT SynchronizeSlaveWindows() const;

  void UpdateHighlightColors();//r7v IR-308607

  struct ShadowBe
  {
    enum Type { eSphere, eBox };
  };

  /** @nodoc 
   *  This is a NRE method only.
   *  This will tell which kind of Bounding Element the shadow will use.
   *  For now, using box can have performance impacts on edition but a better quality
   *  Sphere will produce faster results but with a lower quality.
   *  @param iType The new type to set.
   */
  void SetShadowBe(const ShadowBe::Type iType);

  /** 
   * @nodoc
   * Set the full AA info struct. 
   * Best usage is to use the GetAntiAliasingInfo method, modify your parameter and set the whole structure.
   * @param iAAInfo The info to set.
   */
  void SetAntiAliasingInfo (const VisAntialiasingInfo & iAAInfo);

  /** 
   * @nodoc
   * Fill the oAAInfo struct with current parameters.
   * @param oAAInfo the result.
   */
  void GetAntiAliasingInfo (VisAntialiasingInfo & oAAInfo) const;

protected:
  CATVisuContext* _pVisuContext;
  CATGraphicMaterial* _pDefaultFxMaterial;

  //  cull and sag information
  //  ------------------------

  float sagPrecision_, /** @nodoc */_FPSSag;
  float cullingPrecision_, /** @nodoc */_FPSCulling;
  float _cullVanishingRatio;
  /** @nodoc */
  int _logicalOp;

  /** @nodoc */CATUpdateEvent *_UpdateEvent;
  /** @nodoc */CATSwapEvent *_SwapEvent;
  CATGraphicMaterial *_Material ;
  CATColorMap *_catcolormap;

  /** @nodoc */
  static CATCharacterFont *_catfont;
  CATViewpoint *_viewpoint_array[MAX_VIEWPOINT_BUFFER];
  //  video display management
  //  ------------------------


  float width_;
  float	height_;
  float ratioWH_;
  float _scaleW;
  float _scaleH;
  float scalePt2Px_;
  float scalePt2PxConversion_;
  float	mmInSupportUnit_;
  void *_display;
  float innerWidth_;
  float innerHeight_;
  float innerRatioWH_;
  float innerMMInSupportUnit_;
  CATVisWorldOrientation _worldOrientation;

 /** @nodoc */
  ::list<CATViewpoint> viewpoint_;

  int _fogActive;
  int _TransparencyMode;
  int _AntiAliasingMode;
  int _lightLocalViewer;
  /** @nodoc */
  int _full[4];
  
  int _polygonMode;
  int _view_mode;
  
  int   _Clipping, _ClippingFlags;
  float _Clip_point[18];
  float _Clip_normal[18]; 

  float _r_ambient, _g_ambient, _b_ambient;

  /** @nodoc */
  Background3DViewMode _Bckgrd3DViewMode;

  /** @nodoc */
  float _ThicknessPixel[6];
  /** @nodoc */
  float _ThicknessMM[6];
  /** @nodoc */
  float _LineType[7][16];
  /** @nodoc */
  int   _NbSegment[7];

  //  Stereo
  int _stereoMode;
  float _stereoEyeGap;
  /** @nodoc */
  int _DrawBuffer;
  /** @nodoc */
  int _doDithering;
 
  // FPS Constant
  /** @nodoc */
  void StartTimer();
  /** @nodoc */
  void ResetTimer();
 /** @nodoc */
  void SuspendTimer();
  /** @nodoc */
  void StopTimer();
  /** @nodoc */
  int _StartTimer;
  /** @nodoc */
  int _UseTimer;
 /** @nodoc */ 
  float _Step;
#if defined(_IRIX_SOURCE) || defined (_AIX)
 /** @nodoc */
  static void AlarmCB(int, siginfo_t *, void *);
 /** @nodoc */
  struct sigaction _sigalarm, _osigalarm;
 /** @nodoc */ 
  static int _InterruptDraw;
#else
  /** @nodoc */ 
  int _InterruptDraw;
  /** @nodoc */ 
  CATFPSThread *_FPSThread; 
  /** @nodoc */ 
  CATWaitingPoint *_pFPSWaitForModeOn,*_pFPSWaitForDrawEnded;
#endif

#ifdef _WINDOWS_SOURCE
  /** @nodoc */ 
  void* _state;

  /** @nodoc */ 
  unsigned int        _nv_render_normal_tex;
  /** @nodoc */ 
  float               _nv_render_normal_tex_width;
  /** @nodoc */ 
  float               _nv_render_normal_tex_height;
#endif

  /** @nodoc */ 
  int _drawPathFlag;
  /** @nodoc */ 
  int _mirrorxy;
  
#ifdef _IRIX_SOURCE
  /** @nodoc */ 
  void* _state;
#endif

  /* Gestion des light source par rapport au nombre supporte par OpenGL */
  /** @nodoc */
  static int _MaxNbLight;
  /** @nodoc */
  int _NbLight;
  /** @nodoc */
  CATVizDisplayContext *_DisplayContext;

protected:  
    int _LightingDisabled;

    static int _onCulling;

    int _PBufferActivated;
    int _allowAdvancedDrawingCapabilities;

    unsigned int _renderBufferSave;
      
#ifdef _IRIX_SOURCE

#define MAX_TEXTURES 40


public:
  /** @nodoc */
  void AddTextureToDelete ( int, void* );
  /** @nodoc */
  void RemoveOldTextures  ();

  /** @nodoc */  
  inline void SetMultiSample(int multi) { _multiSample = multi; };

  /** @nodoc */
  inline int GetMultiSample(void) { return _multiSample; };

private:
  int         _NbTextureToDelete;
  int         _IdTextureToDelete[MAX_TEXTURES];
  void       *_CCTextureToDelete[MAX_TEXTURES];
protected:  
  int	     _multiSample;
#endif
  int	     _multiTexture;    

    /** @nodoc */
    CATOGLDrawMode _OGLRenderDrawMode;

public:
    /** @nodoc */
    CATVisContextFilter* GetViewModeContextualFilter(); //UO4 TSK3716061 
	  
protected:
  // DRAW
    /** @nodoc */
   static CATSupportAlgoFactory* _s_pAlgoFactory;
    /** @nodoc */
   short _exposeJustDoneFlag;
    /** @nodoc */
   CAT3DBagRepWithBox* _pShadowingRep;

    /** @nodoc */
   ::list <CATDataShadowMapping> _shadowMappingDataList;

    /** @nodoc */
   CATPassContainerGeneral *_pPassContainer;
    /** @nodoc */
   CATPassContainerGeneral *_pPassContainerCache;

    /** @nodoc */
  short _updatePassAlgoFlag;
    /** @nodoc */
  short _updatePassAlgoFlagLock;
    /** @nodoc */
  short _occlusionMode;
    /** @nodoc */
  short _wireframeMode;

    /** @nodoc */
  int _nb_culling_thread;

    /** @nodoc */
  CATPooledThread*   _contextThread;
  

  CATMathPlane*    _pSeeThruPlane;
  unsigned int     _seeThruOnFlag:1;

  CATMathPlane*  _p2DModePlane;
  CATVis2DModeType _2DMode;

  unsigned int _renderBufferFBOId;

  void InitSprites(CATFrameData* i_prFrameData);

  /** @nodoc */
  // NRE new method don't use without authorization
  virtual void _PerformDraw(CATViewpoint *i_prViewpoint = NULL, short i_doNotSwapFlag = 0, short i_forceSpriteActivation = 0);

  /** @nodoc */
  virtual void _ForceSynchro();


  /** @nodoc */
  virtual int  GetNbSlaveWindow() const;
  virtual CATSupport* GetSlaveWindow(int i) const; /* return NULL if i<0 or i>=GetNbSlaveWindow()*/

  virtual void  _GetMemoryStats(CATViewpoint*, size_t(&oData)[11], float(&oFrag)[2]);
  virtual void  _GetObserverStats(CATViewpoint*, vDirectStats& oStats);
  virtual void  _GetGPUMemoryStats(vGPUMemoryStat& oStats);

  /** @nodoc */
  /* reliquat de code Depta Peeling
  Je ne peux pas le virer, le nom est trop commun et je ne sais
  pas si quelqu'un tire dessus ou pas  */
  int _Layer;

  VisFBO * _fboBackBuffer;
  VisFBO * _fboMS;

private:
  l_CATSupport* _pLetter;
  /** @nodoc */
  int _DisplayLayerType;
  /** @nodoc */
  int _BlankingPolygonMode;
  /** @nodoc */
  int _NbBoxPlanes;
  /** @nodoc */
  CATMathPointf _BoxPoint[6];
  /** @nodoc */
  CATMathDirectionf _BoxNormal[6];

  unsigned int _ambientActivation;
  float _defaultDiffuseAmbientCoef,  _defaultSpecularCoef, _defaultShininess;

  CATVisShadowVersion _shadowVersion;
  CATBoolean _shadowOnFlag;
  int _shadowPOFactor;
  int _shadowPOUnit;
  CATVisLightViewFittingMode _lightViewFitting;
  int _shadowMapSize;
  CATBoolean        _smartLoadingActivated;

  void UpdateIntrospection();

  void UpdateMirroring();
  CAT3DMirroring*                 _mirroring;
  unsigned int                    _mirroringActivation;

  void UpdateInfiniteEnvironment();
  CATVisInfiniteEnvironmentStack* _infiniteEnvStack;
  unsigned int                    _isInfiniteEnvActivated;

  unsigned int                    _IsTextureVBOalreadyActivated;
  
  /** @nodoc */
  // Highlight Mode Management
  // "0" : for faces, highlights its edges
  // "1" : for faces, highlights given faces in shading mode
  unsigned int  _uiHighlightModeSettingsCtrl    :  1;
  unsigned int  _uiHighlightMode                :  31;
  

  void                 SetViewModeContextualFilter(CATVisContextFilter* iFilter);
  CATVisContextFilter* _viewModeContextualFilter;
  CATVisFilter*        _2DModeFilter;

  void ComputePointToPixelScale(); 

};


//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************

inline int CATSupport::GetDithering (void) const
{
  return _doDithering;
}

inline int CATSupport::GetDrawPathMode(void)
{
  return _drawPathFlag;
}

#if defined (_WINDOWS_SOURCE) || defined (_IRIX_SOURCE)
inline void* CATSupport::GetState (void)
{
  return _state;
}

#ifdef _WINDOWS_SOURCE
inline unsigned int & CATSupport::GetNVRenderNormal()
{
 return _nv_render_normal_tex;
}

inline float & CATSupport::GetNVRenderNormalWidth()
{
 return _nv_render_normal_tex_width;
}
  
inline float & CATSupport::GetNVRenderNormalHeight()
{
 return _nv_render_normal_tex_height;
}

#endif
#endif


#ifdef _IRIX_SOURCE
inline int CATSupport::GetStereoMode(void)
{
 return _stereoMode;
}
#endif

#if defined(_IRIX_SOURCE) || defined(_WINDOWS_SOURCE)
inline void* CATSupport::GetShaderDrawAction()
{
 return _shaderDrawAction;
}
inline void CATSupport::SetShaderDrawAction(void *d)
{
 _shaderDrawAction = d;
}
inline void* CATSupport::GetShaderCompileAction()
{
 return _shaderCompileAction;
}
inline void CATSupport::SetShaderCompileAction(void *c)
{
 _shaderCompileAction = c;
}
#endif

inline void CATSupport::GetStereoMode (int *mode, float *eyeGap) const
{
  if (!mode || !eyeGap) return;
  *mode   = _stereoMode;
  *eyeGap = _stereoEyeGap;
}

inline int CATSupport::GetLightViewerMode(void)
{
    return _lightLocalViewer;
}

inline void CATSupport::SetLightViewerMode(int l)
{
    _lightLocalViewer = l;
}

inline void CATSupport::ActivateLowlight(const int iOnOff)
{
}

inline int CATSupport::IsLowlightActivated()
{
  return 0;
}

inline void CATSupport::SetBackground3DViewMode(const Background3DViewMode iMode)
{
  if (_Bckgrd3DViewMode==iMode) return;
  _Bckgrd3DViewMode = iMode;
  SetUpdateSpritesMapsFlag(TRUE);

  const int nbSlaveWindow = GetNbSlaveWindow();

  //Apply on slave windows
  unsigned int nbSlave = this->GetNbSlaveWindow();

  for(unsigned int i = 0; i < nbSlave; ++i) {
    CATSupport * slaveSupport = this->GetSlaveWindow(i);

    if(slaveSupport)
      slaveSupport->SetBackground3DViewMode(iMode);
  }
}

inline const Background3DViewMode CATSupport::GetBackground3DViewMode()
{
  return _Bckgrd3DViewMode;
}

inline int CATSupport::GetPolygonMode() const
{
 return (_polygonMode);
}

inline int CATSupport::GetFullScreenParameter (int *x, int *y, int *w, int *h)
{
  if(!x ||!y ||!w ||! h) return 0;

 *x = _full[0]; 
 *y = _full[1]; 

 *w = _full[2];
 *h = _full[3];

 if (*w && *h) return (1);

 return (0);
}

inline void CATSupport::SetFullScreenParameter (int x, int y, int w, int h)
{
 _full[0] = x; 
 _full[1] = y; 

 _full[2] = w;
 _full[3] = h;
}

inline int CATSupport::GetInterruptDraw()
{
 return _InterruptDraw;
}

inline void CATSupport::SetInterruptDraw(const int value)
{
 _InterruptDraw=value;
}

inline void CATSupport::UseTimer(const int mode)
{
 _FPSSag=sagPrecision_;
 _FPSCulling=cullingPrecision_;
 _UseTimer=mode;
}

inline int CATSupport::GetUseTimer()
{
 return _UseTimer;
}

inline int CATSupport::GetLogicalOperation () const
{
 return (_logicalOp);
}

inline int CATSupport::GetDrawBuffer () const
{
 return (_DrawBuffer);
}

inline int CATSupport::GetFrameBufferObjectId () const
{
 return (_renderBufferFBOId);
}

inline int CATSupport::GetClippingPlaneInfo( float **point, float **normal, int *seen)
{
  if (!point || !normal || !seen) return 0;
  *point  = _Clip_point;
  *normal = _Clip_normal;
  *seen   = _ClippingFlags;

  return (_Clipping);
}

inline int CATSupport::IsClipped( float **point, float **normal, int *seen)
{
  if (!point || !normal || !seen) return 0;
  *point  = _Clip_point;
  *normal = _Clip_normal;
  *seen   = (_ClippingFlags & VisClipPlaneDesc::fCapping);

  return (_Clipping);
}

inline ::list<CATViewpoint> & CATSupport::GetListOfViewpoint()
{
	return viewpoint_;
}

inline void CATSupport::GetGlobalAmbientLight(float *r, float *g, float *b)
{
  if (!r || !g ||!b) return;
  *r = _r_ambient * _ambientActivation;
  *g = _g_ambient * _ambientActivation;
  *b = _b_ambient * _ambientActivation;
}

inline void CATSupport::SetDefaultMaterialProperties(float iDiffAmbCoef, float iSpecCoef, float iShininess)
{
  _defaultDiffuseAmbientCoef = iDiffAmbCoef;

  _defaultSpecularCoef = iSpecCoef;
  _defaultShininess = iShininess;
}

inline void CATSupport::GetDefaultMaterialProperties(float& oDiffAmbCoef, float& oSpecCoef, float& oShininess)
{
    oDiffAmbCoef = _defaultDiffuseAmbientCoef;

    oSpecCoef = _defaultSpecularCoef;
    oShininess = _defaultShininess;
}

inline unsigned int CATSupport::IsAmbientActivated()
{
    return _ambientActivation;
}

inline void CATSupport::SetAntiAliasingMode(const int mode)
{
  if (mode==_AntiAliasingMode) return;
 _AntiAliasingMode=mode;
 SetUpdateSpritesMapsFlag(TRUE);
}

inline int CATSupport::GetAntiAliasingMode() const
{
 return _AntiAliasingMode;
}

inline int CATSupport::IsFogOn() const
{
 return (_fogActive);
}

inline void CATSupport::SetFogMode(const int OnOff)
{
  if (_fogActive==OnOff) return;
 _fogActive = OnOff;
 SetUpdateSpritesMapsFlag(TRUE);
}

inline void CATSupport::SetTransparencyMode(const int mode)
{
  if (_TransparencyMode==mode) return;
 _TransparencyMode=mode;
 SetUpdateSpritesMapsFlag(TRUE);
}

inline int CATSupport::GetTransparencyMode() const
{
 return _TransparencyMode;
}

inline CATGraphicMaterial * CATSupport::GetGraphicMaterial() const
{
	return(_Material);
}

inline float CATSupport::GetRatioWH() const
{
 return ratioWH_;
}

inline void CATSupport::SetRatioWH(const float ratioWH)
{
 ratioWH_ = ratioWH;
}

inline void CATSupport::GetScale( float & oScaleW, float & oScaleH) const
{
   oScaleW = _scaleW;
   oScaleH = _scaleH;
}

inline void CATSupport::SetScale(const float iScaleW, const float iScaleH)
{
   _scaleW = iScaleW;
   _scaleH = iScaleH;
}

inline CATVisWorldOrientation CATSupport::GetWorldOrientation() const
{
  return _worldOrientation;
}

inline float CATSupport::GetPointToPixelScale() const
{
  return scalePt2Px_;
}

inline float CATSupport::GetMMInSupportUnit() const
{
	return mmInSupportUnit_;
}

inline void CATSupport::SetMMInSupportUnit (const float mmInSupportUnit)
{
 mmInSupportUnit_ = mmInSupportUnit;
}

inline void CATSupport::GetWidthAndHeight( float &width, float &height ) const
{
  width =  width_;
  height = height_;
}

inline void CATSupport::SetWidthAndHeight( const float width, const float height ) 
{
 width_ =  width;
 height_ = height;
}

inline CATColorMap * CATSupport::GetColorMap() const
{
	return _catcolormap;
}

inline void CATSupport::SetCullingPrecision( const int cullingPrecision )
{
	cullingPrecision_ = static_cast<float>(cullingPrecision);

  //Apply on slave windows
  unsigned int nbSlave = this->GetNbSlaveWindow();

  for(unsigned int i = 0; i < nbSlave; ++i) {
    CATSupport * slaveSupport = this->GetSlaveWindow(i);

    if(slaveSupport)
      slaveSupport->SetCullingPrecision(cullingPrecision);
  }
}

inline int CATSupport::GetCullingPrecision() const
{
	return static_cast<int>(cullingPrecision_);
}

inline void CATSupport::SetCullingPrecisionf( const float cullingPrecision )
{
	cullingPrecision_ = cullingPrecision;

  //Apply on slave windows
  unsigned int nbSlave = this->GetNbSlaveWindow();

  for(unsigned int i = 0; i < nbSlave; ++i) {
    CATSupport * slaveSupport = this->GetSlaveWindow(i);

    if(slaveSupport)
      slaveSupport->SetCullingPrecisionf(cullingPrecision);
  }
}

inline float CATSupport::GetCullingPrecisionf() const
{
	return cullingPrecision_;
}

inline void CATSupport::SetCullVanishingRatio(float iRatio)
{
  _cullVanishingRatio = iRatio;

  //Apply on slave windows
  unsigned int nbSlave = this->GetNbSlaveWindow();

  for(unsigned int i = 0; i < nbSlave; ++i) {
    CATSupport * slaveSupport = this->GetSlaveWindow(i);

    if(slaveSupport)
      slaveSupport->SetCullVanishingRatio(iRatio);
  }
}

inline float CATSupport::GetCullVanishingRatio() const
{
  return _cullVanishingRatio;
}

inline void CATSupport::SetSagPrecision( const float sagPrecision )
{
	sagPrecision_ = sagPrecision;

  //Apply on slave windows
  unsigned int nbSlave = this->GetNbSlaveWindow();

  for(unsigned int i = 0; i < nbSlave; ++i) {
    CATSupport * slaveSupport = this->GetSlaveWindow(i);

    if(slaveSupport)
      slaveSupport->SetSagPrecision(sagPrecision);
  }
}

inline float CATSupport::GetSagPrecision() const
{
	return sagPrecision_;
}

inline int CATSupport::GetMirror(void) const
{
 return _mirrorxy;
}

inline void CATSupport::SetMirror(int xy)
{
 _mirrorxy = xy;
}

inline void CATSupport::DisableLighting(int value)
{
 _LightingDisabled = value;
}

inline int CATSupport::IsLightingDisabled() const
{
 return _LightingDisabled;
}

inline void CATSupport::SetSpecific2DMode(const int iOnOff)
{
}

inline void CATSupport::Set2DLayoutPrintMode(const int mode)
{
 if (mode == 0)
 { 
  _DisplayLayerType = CAT_ALL;
 }
 else if (mode == 1)
 {
  _DisplayLayerType = CAT_3D_WITH_ZDEPTH|CAT_3D_HIGHLIGHT;
 }
 else if (mode == 2)
 {
  _DisplayLayerType = CAT_3D_WITHOUT_ZDEPTH|CAT_3D_HIGHLIGHT;
 }
}

inline void CATSupport::SetDisplayLayerType(const unsigned int type)
{
 _DisplayLayerType = type;
}

inline unsigned int CATSupport::GetDisplayLayerType()
{
 return _DisplayLayerType;
}

inline int CATSupport::IsMirroringActivated() const
{
    return (_mirroring ? 1 : 0);
}

inline void CATSupport::GetInnerWidthAndHeight(float &innerWidth, float &innerHeight) const
{
  innerWidth = innerWidth_;
  innerHeight = innerHeight_;
}

inline void CATSupport::SetInnerWidthAndHeight(const float innerWidth, const float innerHeight)
{
  innerWidth_ = innerWidth;
  innerHeight_ = innerHeight;
}

inline float CATSupport::GetInnerMMInSupportUnit() const
{
  return innerMMInSupportUnit_;
}

inline void CATSupport::SetInnerMMInSupportUnit(const float innerMMInSupportUnit)
{
  innerMMInSupportUnit_ = innerMMInSupportUnit;
}

inline void CATSupport::SetInnerRatioWH(const float innerRatioWH)
{
  innerRatioWH_ = innerRatioWH;
}

inline float CATSupport::GetInnerRatioWH() const
{
  return innerRatioWH_;
}

#endif
		
