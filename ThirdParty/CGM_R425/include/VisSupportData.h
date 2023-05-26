#ifndef VisSupport_H
#define VisSupport_H

// COPYRIGHT DASSAULT SYSTEMES 2010

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 2010
//------------------------------------------------------------------------------
// Abstract :   basic class which contains all initial information defining a support:
// ----------    a list of viewpoint to be drawn.
//               draw options.
//
//------------------------------------------------------------------------------
// Usage :      is used by VisSuuportLayout.
// -------      
//
//------------------------------------------------------------------------------
// Main methods :         
// --------------
//                viewpoint management
//                  AddViewpoint
//                  RemoveViewpoint
//
//                draw options SagPrecision MMInSupportUnit
//
//
//------------------------------------------------------------------------------
// Class :      VisSupportData
// -------        CATVizBaseIUnknown
//
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATVizBaseIUnknown.h"
#include "CATViewerUtility.h"
#include "CATShadowEnum.h"
#include "list.h"
#include "CATVis2DModeType.h"
#include "CATBoolean.h"
#include "CATMathPointf.h"
#include "CATMathDirectionf.h"
#include "CATString.h"
#include "VisAntialiasingInfo.h"
#include "VisQualityData.h"
#include "VisClipPlaneDesc.h"
#include "VisAppearance.h"
#include <memory>

class CATViewpoint;
class CATGraphicMaterial;
class CATColorMap;
class CAT3DLightSourceRep;
class CATMathPlane;
class CATVisInfiniteEnvironment;
class CATVisInfiniteEnvironmentOverload;
class CATVisHighlightRenderingData;
class CATString;
class CATVisDynamicRenderingQualityData;
class CATVisInfiniteEnvironmentStack;
class CATSupport;
class CATVisRenderingStyleSet;
struct VisShadowsInfo;
struct VisRTAOInfo;
class CustomPassManager;

class ExportedByCATVisFoundation VisSupportData : public CATVizBaseIUnknown
{
public:
  
  /**
   * Constructs the class from a width and an height.
   * @param width
   *  pixel width.
   * @param height
   *  pixelheight.
   */
  VisSupportData (const int iWidth, const int iHeight);
  
  /** Copy Constructor. */
  VisSupportData (const VisSupportData&);
  
  /** Copy Constructor. */
  VisSupportData (const CATSupport&);

  /** Destructor. */
  virtual ~VisSupportData ();

  /** Copy Data to CATSupport. */
  virtual void InitSupport (CATSupport&);

  /**
   * Adds a given viewpoint.
   * @param iVpt
   * the viewpoint.
   * @param iPlace
   * integer value 
   *<ol>
   *<li> 1 = Foreground </li>
   *<li> 0 = Background </li>
   *</ol>
   */
  virtual void AddViewpoint (CATViewpoint* ipViewpoint, int iPlace = 1);
   
  /**
   * Removes a given viewpoint.
   * @param iVpt
   * the viewpoint.
   */
  virtual void RemoveViewpoint (CATViewpoint* ipViewpoint );

  /**
   * Get viewpoint list.
   */
  list<CATViewpoint>& GetListOfViewpoint () ;
  
  /**
   * Returns the millimeter size in pixel size.
   */
  float GetMMInSupportUnit () const;
  
  /**
   * Sets the heigth and width of the current  CATSupport.
   * @param iWidth
   * the width.
   * @param iHeight
   * the height.
   */
  void SetWidthAndHeight (const float iWidth, const float iHeight);

  /**
   * Retreives the heigth and width of the current  CATSupport.
   * @param oWidth
   * the width.
   * @param oHeight
   * the height.
   */
  void GetWidthAndHeight (float& oWidth, float& oHeight ) const;

  /**
   * Sets the ratio heigth/width of one pixel.
   *<br><b>Role</b>:
   * it is useful when pixel is not a squarre. It is screen-dependant.
   */
//  void SetRatioWH (const float iRatio);
  
  /**
   * Returns the ration heigth/width of one pixel.
   */
  float GetRatioWH () const;

  /**
   * Sets Default Graphic Material
   */
  void SetGraphicMaterial (CATGraphicMaterial* ipMaterial);

  /**
   * Returns Default Graphic Material
   */
  CATGraphicMaterial* GetGraphicMaterial () const;
  
  /**
   * Returns the indexed color map. 
   * @see CATColorMap
   */
  CATColorMap* GetColorMap () const;
  
  /**
   * Sets the antialiasing mode for lines.
   *@param iAntialiasingMode
   *<ol>
   * <li> 0 = antialiasing is off</li>
   * <li> 1 = antialiasing is on </li>
   *</ol>
   */
  void SetAntiAliasingMode (const int iAntialiasingMode);
  
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
   */
  int IsClipped (float **oPoint, float **oNormal, int *oCappingPlaneSeen);
  /**
   * Returns the number of clipping planes.
   * @param oPoint
   * pointer to an array of 3x<tt>iNbPlanes</tt> of coordinates. Each (x,y,z) represents a point belonging
   * to a clipping plane. And there is only one point per plane.
   * @param oNnormal
   *  pointer to an array of 3x<tt>iNbPlanes</tt> of coordinates. Each (x,y,z) represents a normal to one plane.
   *  And there is only one normal per plane.
   * @param oCappingPlaneFlags
   *  combination of VisClipPlaneDesc
   */
  int GetClippingPlaneInfo (float **oPoint, float **oNormal, int *oCappingPlaneFlags);
  
  /** @nodoc */
  virtual void SetShadowOnFlag (CATBoolean i_shadowOnFlag);
  /** @nodoc */
  CATBoolean GetShadowOnFlag ();
  

public:

  /** @nodoc */
  void SetBlankingPolygonMode(const int mode);
  
  /** @nodoc */
  int IsMirroringActivated() const;

  /** @nodoc */
  int IsAmbOcclusionActivated() const;
  
  /** @nodoc */
  void PushOverloadInfiniteEnvironment(CATVisInfiniteEnvironmentOverload* iOverloadEnv);
  /** @nodoc */
  void PopOverloadInfiniteEnvironment(CATVisInfiniteEnvironmentOverload* iOverloadEnv=NULL);
  
  /** @nodoc */
  int GetNbJitteringSamples() const;
  /** @nodoc */
  void SetNbJitteringSamples(int iNbSamples);

  /** @nodoc */
  void SetCustomRenderingStle(CATVisRenderingStyleSet* iCustomRenderingstyle);

  /** @nodoc */
  CATVisRenderingStyleSet* GetCustomRenderingstyle() const;


private:
  // viewpoints to draw
  list<CATViewpoint> viewpoint_;

  // culling information
  int cullingPrecision_;

  // sag information
  float sagPrecision_;

  // color map 
  CATColorMap* _catcolormap;

  // video display information
  float width_;
  float height_;
  float ratioWH_;
  float mmInSupportUnit_;

  // default material
  CATGraphicMaterial* _Material ;

  // fog mode
  int _fogActive;

  // tranparency mode
  int _TransparencyMode;

  // antiAliasing mode
  int _AntiAliasingMode;

  // ambient mode
  float _r_ambient, _g_ambient, _b_ambient;
  unsigned int _ambientActivation;
  float _defaultDiffuseAmbientCoef, _defaultSpecularCoef, _defaultShininess;

  // specular reflection angles information
  int _lightLocalViewer;

  // view mode
  int _view_mode;
  VisAppearance _defaultAppearance;

  // log Z
  int _z_mode;
  
  // clipping plane
  int   _Clipping, _ClippingFlags;
  float _Clip_point[18];
  float _Clip_normal[18]; 

  // stereo
  int _stereoMode;
  float _stereoEyeGap;

  // occlusion mode
  short _occlusionMode;

  //
  Background3DViewMode _Bckgrd3DViewMode;

  // Shadow
  CATVisShadowVersion _shadowVersion;
  CATBoolean _shadowOnFlag;
  int _shadowPOFactor;
  int _shadowPOUnit;
  CATVisLightViewFittingMode _lightViewFitting;
  int _shadowMapSize;
  VisShadowsInfo* _shadowsInfo;
  VisRTAOInfo* _hrtaoInfo;

  // See Thru
  CATMathPlane*    _pSeeThruPlane;
  unsigned int     _seeThruOnFlag:1;

  // 2D Mode
  CATMathPlane*  _p2DModePlane;
  CATVis2DModeType _2DMode;

  // DL type to draw
  int _DisplayLayerType;

  // Blanking Polygon for text
  int _BlankingPolygonMode;

  // CullingBox
  int _NbBoxPlanes;
  CATMathPointf _BoxPoint[6];
  CATMathDirectionf _BoxNormal[6];

  // Antialiasing
  VisAntialiasingInfo _aaInfo;

  // Default FX material
  CATGraphicMaterial* _pDefaultFxMaterial;

  // Mirroring
  unsigned int                    _mirroringActivation;

  // Advanced Highlight/PreHighlight
  CATVisHighlightRenderingData*   _highlightRendering[2];

  // Infinite Env
  CATSupport* _emptySupportForInfiniteEnv;
  CATVisInfiniteEnvironmentStack* _infiniteEnvStack;

  // Visual Quality
  VisQualityData                 _visualQuality;

  // Rendering style
  CATVisRenderingStyleSet*    _customRenderingStyle;

  // Custom Pass Manager
  std::shared_ptr<CustomPassManager> _customPassManager;
};

#endif
   
