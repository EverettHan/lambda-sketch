#ifndef CATRender_H
#define CATRender_H


// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"
#include "CATGraphicAttributeSet.h"
#include "CATAnchorPoint.h"
#include "CATViewerUtility.h"
#include "CATSymbolType.h"
#include "CATGraphicPrimitive.h"
#include "CAT4x4Matrix.h"
#include "CATVizGlobals.h"
#include "CATVis2DModeType.h"

#ifdef _IRIX_SOURCE
#include "CAT3DViewport.h"
#endif

class CATGraphicMaterial;
class CATPixelImage;
class CATMathPointf;
class CAT2DBoundingBox;
class CAT3DBoundingSphere;
class CAT3DPolylineGP;
class CATViewpoint;
class CAT2DViewpoint;
class CAT3DViewpoint;
class CATColorMap;
class CATCharacterFont;
class CAT2DMarkerGP;
class CAT2DLineGP;
class CAT3DIndexedLineGP;
class CAT2DPolygonGP;
class CAT2DQuadStripGP;
class CAT2DRectangleGP;
class CAT2DGeometricTextGP;
class CAT2DArcCircleGP;
class CAT2DArcEllipseGP;
class CAT3DLightSourceGP;
class CAT3DLineGP;
class CAT3DEdgeGP;
class CAT3DMarkerGP;
class CAT3DFaceGP;
class CAT3DPlanarFaceGP;
class CAT3DCylinderGP;
class CAT3DCurvedPipeGP;
class CAT3DMirrorGP;
class CAT3DOOCPointCloudGP;
class CATDynamicGP;
class CATVizVoxelGP;
class CAT3x3Matrix;
class CATSupport;
class CATViewport;
class CAT2DViewport;
class CAT3DViewport;
class CATRep;
class CAT3DRep;
class CATRepPath;
class CATFont;
class CATVizVertexBuffer;
class CATViz3DFace;
class CATViz3DEdge;
class CATViz3DLine;
class CATViz3DMarker;
class CATVizDynamicPrimitive;
class CATVizUV3DEdge;
class CATVizUV3DFace;
class CATVizUV3DLine;
class CATVizPrimitiveSet;
class CATVizIndexed3DMarker;
class CAT3DIndexedLineGPVBO;
class VisPrimitive;
class VisGPGPUPrimitive;
class VisAttribute;
class CATVisFilter;
class CATVisGPUStorageManager;
class CATVisTexturesStorageManager;
class CATUnicodeString;
class VisSubSupportData;
struct CAT2DGeomTextAttributeSet;
class CATFreeTypeTextGP;
class vIVertexAssembly;
struct vIndexBufferRange;
class CATDelegateRender;
class VisRawBuffer;
#if defined(_IRIX_SOURCE) || defined(_WINDOWS_SOURCE)
class CATDisplayList;
#endif
class VisMaterial;
class CAT3DCanonicalRep;
class CAT3DCanonicalCuboidRep;
class CAT3DCanonicalSphereRep;
class CAT3DCanonicalPartialSphereRep;
class CAT3DCanonicalCylinderRep;
class CAT3DCanonicalConeRep;
class CAT3DCanonicalTorusRep;
class CAT3DCanonicalPartialTorusRep;
class CAT3DCanonicalCurvedPipeRep;

#include "list.h"
#include "CATMacForRtti.h"
/** Class to create a render.
 * <b>Role</b>:  The CATRender and inherited objects are the classes defining
 * actions on graphical representations and graphical primitives.
 * The renders are the only objects directly connected to the representations
 * and to the primitives through their Draw methods.
 * Mainly, the CATRender inherited objects are used to descend a representation
 * tree from the top to the bottom. Render methods are overloaded in order to
 * pick up information from the representation tree defining the graphical
 * database.
 * The CATRender is called each time a Draw is performed. With the following
 * list of methods, it's made possible to extract any information from the
 * graphical database:
 * <ol>
 * <li> Push/Pop Matrix: Gives the tree architecture.</li>
 * <li> DrawRepresentation: Gives the starting point for the draw of a rep.</li>
 * <li> Draw xxx: Gives information on the type of the graphical primitive
 * that is being drawn.</li>
 * </ol>
 * Note that all these functions are sequentially called, so it's always
 * possible to build back the list of what is being drawn and the order of
 * the draw sequence. It'll never be possible to know exactly which type of
 * representation is being drawn, because representations are an open class,
 * and no application may have the knowledge of all of them.
 */
class ExportedBySGInfra CATRender
{
 CATDeclareClass_Deprec;

 public :

  /** Constructs a render.
   * @param iSupport
   * The @href CATSupport.
   */
  CATRender (const CATSupport &iSupport);

  /** Destructor */
  virtual ~CATRender();

  /**
   * @nodoc
   */
  virtual void Draw (::list<CATViewpoint> &iVP, const int, const float);

  /**
   * @nodoc
   */
  void Clean(const CATSupport &iSupport);
  /**
   * @nodoc
   */
  virtual void DrawFurtive (::list<CATViewpoint> &, const int, const float);

  /**
   * @nodoc
   */
  virtual void DrawDialog (::list<CATViewpoint> &, const int, const float);

  /**
   * @nodoc
   */
  virtual void DrawPath (CATRepPath &path, CATViewpoint &viewpoint, const int = 0);

  /**
   * @nodoc
   */
  virtual void DrawPathes (::list<CATRepPath> &path, CATViewpoint &viewpoint, const int = 0);

  /**
   * @nodoc
   */
  virtual void InheritAttributes (CATGraphicAttributeSet const*,int);

  /**
   * @nodoc
   */
  virtual void InheritElementType (int,int);

  /**
   * @nodoc
   */
  virtual void SetInside (const int);

  /**
   * @nodoc
   */
  virtual void SetPolygonOffset (const int);

  /** Indicates if the representation is drawable with this attribut and this bounding box.
   * @param iAttribut
   * The representation's attributes.
   * @param iBoundingBox
   * The representation's 2D bounding box.
   * @param iRep
   * The representation.
   * @return
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the representation is not drawable.</li>
   * <li> 1: the representation is drawable.</li>
   * </ol>
   */
  virtual int IsDrawable (const CATGraphicAttributeSet &iAttribut, const CAT2DBoundingBox &iBoundinBox, const CATRep &iRep);

  /** Indicates if the representation is drawable with this attribut and this bounding box.
   * @param iAttribut
   * The representation's attributes.
   * @param iBoundingBox
   * The representation's 2D bounding box.
   * @param iSubElementId.
   * The representation's sub-element identificator.
   * @return
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the representation is not drawable.</li>
   * <li> 1: the representation is drawable.</li>
   * </ol>
   */
  virtual int IsDrawable (const CATGraphicAttributeSet &iAttribut, const CAT2DBoundingBox &iBoundingBox, const int iSubElementId);

  /** Indicates if the representation is drawable with this attribut and this bounding sphere.
   * @param iAttribut
   * The representation's attributes.
   * @param iBoundingSphere
   * The representation's 3D bounding sphere.
   * @param iSubElementId.
   * The representation's sub-element identificator.
   * @return
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the representation is not drawable.</li>
   * <li> 1: the representation is drawable.</li>
   * </ol>
   */
  int IsDrawable (const CATGraphicAttributeSet &iAttribut, const CAT3DBoundingSphere &iBoundingSphere, const int iSubElementId);

  /**
   * @nodoc
   */
  virtual int IsDrawable (const CATGraphicAttributeSet &, const float *center, const float radius, const int SubElementId);

  /** Indicates if the representation is drawable with this attribut and this bounding sphere.
   * @param iAttribut
   * The representation's attributes.
   * @param iBoundingSphere
   * The representation's 3D bounding sphere.
   * @param iRep.
   * The representation.
   * @param iMaterial
   * The material to be load.
   * @return
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the representation is not drawable.</li>
   * <li> 1: the representation is drawable.</li>
   * </ol>
   */

  virtual int IsDrawable (const CATGraphicAttributeSet &iAttribut, const CAT3DBoundingSphere &iBoundingSphere, const CATRep &iRep, CATGraphicMaterial *iMaterial = 0);

#ifdef _IRIX_SOURCE
  /** @nodoc */
  virtual void AddSurfacicRep(const int);
  /** @nodoc */
  virtual int IsDrawable (const CATGraphicAttributeSet &attribut, float *box_center, float *box_dim, const int);
  /** @nodoc */
  inline int IsDrawable (const CATMathPointf &minP, const CATMathPointf &maxP);
  /** @nodoc */
  inline int IsDrawable (const float , const float , const float);
  /** @nodoc */
  virtual CATDisplayList *GetDisplayList(void);
#endif

  /**
   * @nodoc
   * use IsDrawable (const CATGraphicAttributeSet &iAttribut, const int iSubElementId) instead.
   * Indicates if the representation is drawable with this attribut.
   * @param iAttribut
   * The representation's attributes.
   * @param iSubElementId.
   * The representation's sub-element identificator.
   * @param iType.
   * Flag to update the type of representation.
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the type is not updated.</li>
   * <li> 1: the type is updated.</li>
   * </ol>
   * @return
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the representation is not drawable.</li>
   * <li> 1: the representation is drawable.</li>
   * </ol>
   */
  virtual int IsDrawable (const CATGraphicAttributeSet &iAttribut, const int iSubElementId, const int iType);

  /** @nodoc
   * use IsDrawable (const CATGraphicAttributeSet &iAttribut, const list<int>& ipSubElementIdList) instead.
   * Indicates if the representation is drawable with this attribut.
   * @param iAttribut
   * The representation's attributes.
   * @param iSubElementId.
   * The representation's sub-elements identificators.
   * @param iType.
   * Flag to update the type of representation.
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the type is not updated.</li>
   * <li> 1: the type is updated.</li>
   * </ol>
   * @return
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the representation is not drawable.</li>
   * <li> 1: the representation is drawable.</li>
   * </ol>
   */
  virtual int IsDrawable (const CATGraphicAttributeSet &iAttribut, const ::list<int>& ipSubElementIdList, const int iType);

  /** Indicates if the representation is drawable with this attribut.
   * @param iAttribut
   * The representation's attributes.
   * @param iSubElementId.
   * The representation's sub-element identificator.
   * @return
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the representation is not drawable.</li>
   * <li> 1: the representation is drawable.</li>
   * </ol>
   */
  virtual int IsDrawable (const CATGraphicAttributeSet &iAttribut, const int iSubElementId);

  /** Indicates if the representation is drawable with this attribut.
   * @param iAttribut
   * The representation's attributes.
   * @param ipSubElementIdList.
   * The representation's sub-elements identificators.
   * @return
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the representation is not drawable.</li>
   * <li> 1: the representation is drawable.</li>
   * </ol>
   */
  virtual int IsDrawable (const CATGraphicAttributeSet &iAttribut, const ::list<int>& ipSubElementIdList);

  /** Indicates if the representation is drawable with this attribut.
   * @param iAttribut
   * The representation's attributes.
   * @param iRep.
   * The representation.
   * @param iMaterial
   * The material to be load.
   * @return
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the representation is not drawable.</li>
   * <li> 1: the representation is drawable.</li>
   * </ol>
   */
  virtual int IsDrawable (const CATGraphicAttributeSet &iAttribut, const CATRep &iRep,  CATGraphicMaterial *iMaterial = 0);

  /** Indicates if the representation is drawable with this attribut.
   * @param iAttribut
   * The representation's attributes.
   * @param iMaterial
   * The material to be load.
   * @return
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the representation is not drawable.</li>
   * <li> 1: the representation is drawable.</li>
   * </ol>
   */
  virtual int IsDrawable (const CATGraphicAttributeSet &iAttribut, CATGraphicMaterial *iMaterial );

  /** Indicates if the representation is drawable with this attribut.
   * @param iAttribut
   * The representation's attributes.
   * @return
   * <br><b>Legal values</b>:
   * <ol>
   * <li> 0: the representation is not drawable.</li>
   * <li> 1: the representation is drawable.</li>
   * </ol>
   */
  virtual int IsDrawable (const CATGraphicAttributeSet &);

  /**
   * @nodoc
   */
  virtual int IsDrawable (const int SubElementId);

  /**
   * @nodoc
   */
  virtual int IsDrawable (const ::list<int>& ipSubElementIdList);

  /**
   * @nodoc
   */
  virtual int IsDrawable (VisAttribute& iAttribut, const int i);

  /**
   * @nodoc
   */
  virtual int IsSeen  (const float*, const float*);

  /**
   * @nodoc
   */
  virtual int IsToSmall (const CAT3DBoundingSphere &);

  /**
   * @nodoc
   */
  virtual int IsToSmall (const CAT2DBoundingBox &);

  /**
   * @nodoc
   */
  virtual int IsInside  (const CAT3DBoundingSphere &);

  /**
   * @nodoc
   */
  virtual int IsInside  (const CAT2DBoundingBox &);

  /**
   * @nodoc
   */
  virtual float Get2DModelCulling () const;

  /**
   * @nodoc
   */
  virtual float Get3DModelCulling (const CAT3DBoundingSphere &) const;

  /**
   * @nodoc
   */
  virtual int   Get3DLODNumber (const CAT3DBoundingSphere & iBS3D, const int iNbOfLOD, const float sagArray[] ) const;

  /**
   * @nodoc
   */
  virtual float Get3DModelSag  (const CAT3DBoundingSphere & iBS3D) const;

  /**
   * @nodoc
   */
  virtual float Get2DModelSag  () const;

  /**
   * @nodoc
   */
  virtual void SetCurrentVisAttribute(VisAttribute& iVisAttr);

  /**
   * @nodoc
   */
  virtual void SetCurrentAttribute (const CATGraphicAttributeSet &);

  /**
   * @nodoc
   */
  void SetCurrentAttribute (const int, const int);

  /**
   * @nodoc
   */
  virtual void BeginDrawSurfacicRep();

  /**
   * @nodoc
   */
  virtual void EndDrawSurfacicRep();

  /**
   * @nodoc
   */
  virtual void SetCurrentMaterial (CATGraphicMaterial &);
  /** @nodoc */
  CATGraphicMaterial* GetCurrentMaterial() const;

  /**
   * @nodoc
   */
  inline CATGraphicAttributeSet & GetCurrentAttribute ();

  /**
   * @nodoc
   */
  virtual void SetMaterialProperties (CATGraphicMaterial &iMat);

  /**
   * @nodoc
   */
  virtual void SetTexture (const int iOnoff,CATGraphicMaterial &iMat);

  /**
   * @nodoc
   */
  virtual void UpdateTextureParameters(CATGraphicMaterial &iMat);


  /** Draws a representation.
   * @param iRep
   * The representation to draw.
   */
  virtual void DrawRepresentation (CATRep &iRep);

  /** This method is called at the begining of a Rep draw.
   * You can overload it to get in your code before the rep is drawn.
   * You must return 1 if you want the DrawShading to be done.
   * @param iRep
   * The Rep which is going to be drawn.
   * @param iInside
   * @param iData
   * A pointer to the data you want to pass from
   * DrawRep to EndDrawRep
   */
  virtual int DrawRepresentation (CATRep &iRep, int iInside, void* &iData);

  /** This method is called at the end of a Rep draw.
   * Return 1 if evrything's ok
   * @param iRep
   * The Rep which has been drawn.
   * @param iData
   * A pointer to the data you want to pass from
   * DrawRep to EndDrawRep
   */
  virtual int EndDrawRepresentation (CATRep &iRep, void* &iData);

  /** @nodoc */
  virtual int FilterRepresentation(CATRep& iRep);

  /** @nodoc */
  virtual void EndFilterRepresentation(CATRep& iRep);

  /** @nodoc */
  virtual void PushFilter(CATVisFilter* filter);

  /** @nodoc */
  virtual void PopFilter(CATVisFilter* filter);

  /** Draws a 2D marker.
   * @param iGP
   * The @href CAT2DMarkerGP to draw.
   */
  virtual void Draw2DMarker (CAT2DMarkerGP &iGP);

  /** Draws a 2D line.
   * @param iGP
   * The @href CAT2DLineGP to draw.
   */
  virtual void Draw2DLine (CAT2DLineGP &iGP);

  /** Draws a 2D rectangle.
   * @param iGP
   * The @href CAT2DRectangleGP to draw.
   */
  virtual void Draw2DRectangle (CAT2DRectangleGP &iGP);

  /** Draws a 2D quad strip.
   * @param iGP
   * The @href CAT2DQuadStripGP to draw.
   */
  virtual void Draw2DQuadStrip (CAT2DQuadStripGP &iGP);

  /** Draws a 2D polygon.
   * @param iGP
   * The @href CAT2DPolygonGP to draw.
   */
  virtual void Draw2DPolygon (CAT2DPolygonGP &iGP);

  /** Draws a 2D geometric text.
   * @param iGP
   * The @href CAT2DGeometricTextGP to draw.
   */
  virtual void Draw2DGeometricText (CAT2DGeometricTextGP &iGP);

  /** Draws a 2D arc's circle.
   * @param iGP
   * The @href CAT2DArcCircleGP to draw.
   */
  virtual void Draw2DArcCircle (CAT2DArcCircleGP &iGP);

  /** Draws a 2D arc's ellipse.
   * @param iGP
   * The @href CAT2DArcEllipseGP to draw.
   */
  virtual void Draw2DArcEllipse (CAT2DArcEllipseGP &iGP);

  /** Draws a 3D marker.
   * @param iGP
   * The @href CAT3DMarkerGP to draw.
   */
  virtual void Draw3DMarker (CAT3DMarkerGP &iGP);

  /** Draws a 3D line.
   * @param iGP
   * The @href CAT3DLineGP to draw.
   */
  virtual void Draw3DLine (CAT3DLineGP &iGP);

  /**
   * @nodoc
   * Draws a 3D indexed line.
   * @param iGP
   * The @href CAT3DIndexedLineGP to draw.
   */
  virtual void Draw3DIndexedLine (CAT3DIndexedLineGP &iGP);

  /** Draws a 3D edge.
   * @param iGP
   * The @href CAT3DEdgeGP to draw.
   */
  virtual void Draw3DEdge (CAT3DEdgeGP &iGP);

  /**
   * @nodoc
   */
  virtual void Draw3DBufferedEdge (CAT3DEdgeGP&);

  /**
   * @nodoc
   */
  virtual void Draw3DEdges (CAT3DEdgeGP **iGP, int iN, int iM);

  /** Draws a 3D light source.
   * @param iGP
   * The @href CAT3DLightSourceGP to draw.
   */
  virtual void DrawLightSource (CAT3DLightSourceGP &iGP);

  /** Draws a 3D face.
   * @param iGP
   * The @href CAT3DFaceGP to draw.
   */
  virtual void Draw3DFace (CAT3DFaceGP &iGP);

  /**
   * @nodoc
   */
  virtual void Draw3DFace1DTexture (CAT3DFaceGP &iGP);

  /**
   * @nodoc
   */
  virtual void Draw3DFace2DTexture (CAT3DFaceGP &iGP);

#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
  /**
   * @nodoc
   */
  virtual void Draw3DFaceMultiTexture (CAT3DFaceGP &iGP);
#endif

  /**
   * @nodoc
   */
  virtual void Draw3DFaces (CAT3DFaceGP **, int n, int *types);

  /**
   * @nodoc
   */
  virtual void Draw3DFaces1DTexture (CAT3DFaceGP **iGP, int n, int *types);

  /**
   * @nodoc
   */
  virtual void Draw3DFaces2DTexture (CAT3DFaceGP **iGP, int n, int *types);
#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
  /**
   * @nodoc
   */
  virtual void Draw3DFacesMultiTexture (CAT3DFaceGP **iGP, int n, int *types);
#endif

  /**
   * @nodoc
   */
  virtual void Draw3DBufferedFace (CAT3DFaceGP&, int n=0);

  /**
   * @nodoc
   */
  virtual void Draw3DBufferedFace1DTexture (CAT3DFaceGP&, int n=0);

  /**
   * @nodoc
   */
  virtual void Draw3DBufferedFace2DTexture (CAT3DFaceGP&, int n=0);

  /**
   * @nodoc
   */
  virtual void Draw3DBufferedUVFace (CATVizUV3DFace*, int n=0);

  /**
   * @nodoc
   */
  virtual void Draw3DBufferedUVFace1DTexture (CATVizUV3DFace*, int n=0);

  /**
   * @nodoc
   */
  virtual void Draw3DBufferedUVFace2DTexture (CATVizUV3DFace*, int n=0);


#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
  /**
   * @nodoc
   */
  virtual void Draw3DBufferedFaceMultiTexture (CAT3DFaceGP&, int n=0);
#endif

  /**
   * @nodoc
   */
  virtual void Draw3DPlanarFace1DTexture (CAT3DPlanarFaceGP &iGP);

  /**
   * @nodoc
   */
  virtual void Draw3DPlanarFace2DTexture (CAT3DPlanarFaceGP &iGP);
#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
  /**
   * @nodoc
   */
  virtual void Draw3DPlanarFaceMultiTexture (CAT3DPlanarFaceGP &iGP);
#endif
  /** Draws a 3D planar face.
   * @param iGP
   * The @href CAT3DPlanarFaceGP to draw.
   */
  virtual void Draw3DPlanarFace (CAT3DPlanarFaceGP &iGP);

  /** Draws a 3D cylinder.
   * @param iGP
   * The @href CAT3DCylinderGP to draw.
   */
  virtual void Draw3DCylinder (CAT3DCylinderGP &iGP, const int = 0);

  /**
   * @nodoc
   */
  virtual void Draw3DCylinder1DTexture (CAT3DCylinderGP &iGP, const int = 0);

  /**
   * @nodoc
   */
  virtual void Draw3DCylinder2DTexture (CAT3DCylinderGP &iGP, const int = 0);
#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
  /**
   * @nodoc
   */
  virtual void Draw3DCylinderMultiTexture (CAT3DCylinderGP &iGP, const int = 0);
#endif
  /** Draws a 3D curved pipe.
   * @param iGP
   * The @href CAT3DCurvedPipeGP to draw.
   */
  virtual void Draw3DCurvedPipe (CAT3DCurvedPipeGP &iGP);

  /**
   * @nodoc
   */
  virtual void Draw3DCurvedPipe1DTexture (CAT3DCurvedPipeGP &iGP);

  /**
   * @nodoc
   */
  virtual void Draw3DCurvedPipe2DTexture (CAT3DCurvedPipeGP &iGP);
#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
  /**
   * @nodoc
   */
  virtual void Draw3DCurvedPipeMultiTexture (CAT3DCurvedPipeGP &iGP);
#endif

  /**
   * @nodoc
   *
   * Draws a CAT3DCanonicalRep representing a 3D Cuboid.
   * You should override this method in all derived renders and process CAT3DCanonicalReps without using the mesh data.
   */
  virtual void Draw3DCanonicalCuboid(CAT3DCanonicalCuboidRep& iRep);
  /**
   * @nodoc
   *
   * Draws a CAT3DCanonicalRep representing a 3D Sphere.
   * You should override this method in all derived renders and process CAT3DCanonicalReps without using the mesh data.
   */
  virtual void Draw3DCanonicalSphere(CAT3DCanonicalSphereRep& iRep);
  /**
   * @nodoc
   *
   * Draws a CAT3DCanonicalRep representing a 3D PartialSphere.
   * You should override this method in all derived renders and process CAT3DCanonicalReps without using the mesh data.
   */
  virtual void Draw3DCanonicalPartialSphere(CAT3DCanonicalPartialSphereRep& iRep);
  /**
   * @nodoc
   *
   * Draws a CAT3DCanonicalRep representing a 3D Cylinder.
   * You should override this method in all derived renders and process CAT3DCanonicalReps without using the mesh data.
   */
  virtual void Draw3DCanonicalCylinder(CAT3DCanonicalCylinderRep& iRep);
  /**
   * @nodoc
   *
   * Draws a CAT3DCanonicalRep representing a 3D Cone.
   * You should override this method in all derived renders and process CAT3DCanonicalReps without using the mesh data.
   */
  virtual void Draw3DCanonicalCone(CAT3DCanonicalConeRep& iRep);
  /**
   * @nodoc
   *
   * Draws a CAT3DCanonicalRep representing a 3D Torus.
   * You should override this method in all derived renders and process CAT3DCanonicalReps without using the mesh data.
   */
  virtual void Draw3DCanonicalTorus(CAT3DCanonicalTorusRep& iRep);
  /**
   * @nodoc
   *
   * Draws a CAT3DCanonicalRep representing a 3D PartialTorus.
   * You should override this method in all derived renders and process CAT3DCanonicalReps without using the mesh data.
   */
  virtual void Draw3DCanonicalPartialTorus(CAT3DCanonicalPartialTorusRep& iRep);
  /**
   * @nodoc
   *
   * Draws a CAT3DCanonicalRep representing a 3D CurvedPipe following a discrete curve.
   * You should override this method in all derived renders and process CAT3DCanonicalReps without using the mesh data.
   */
  virtual void Draw3DCanonicalCurvedPipe(CAT3DCanonicalCurvedPipeRep& iRep);

   /**
   * @nodoc
   */
  virtual void SetVertexAssembly (vIVertexAssembly const* iVertexAssembly);


   /**
   * @nodoc
   */
  virtual void SetDrawInfoShaderOption (unsigned int iShaderOption);

   /**
   * @nodoc
   */
  virtual void PushSimpleDraw (vIndexBufferRange const& iIBRange);

   /**
   * @nodoc
   */
  virtual void PushDrawWithGP (vIndexBufferRange const& iIBRange, CATGraphicPrimitive& iPrim, CATVizMetaClass const& iElemType);

  //Custom instance buffer
  /**
   * @nodoc
   */
  virtual void SetCurrentVisAttributeNumInstance(unsigned int iNumInstance);

  /**
   * @nodoc
   */
  virtual void SetCurrentVisAttributeInstanceBuffer(VisRawBuffer* iBufferPtr);

 // XK7 GPU_SKINNING ++
  /**
   * @nodoc
   */
  virtual void SetCurrentVisAttributeBoneTransformationBuffer(VisRawBuffer* iBufferPtr);

  /**
   * @nodoc
   */
  virtual void SetCurrentVisAttributeBonePositionsBuffer(VisRawBuffer* iBufferPtr);

  /**
   * @nodoc
   */
  virtual void SetCurrentVisAttributeNumBoneInstance(unsigned int iNumInstance);
  // XK7 GPU_SKINNING --

  /**
   * @nodoc
   */
  virtual void SetCurrentDrawIndirectDrawCount(unsigned int iDrawCount);

  /**
  /* @nodoc
   */
  virtual void SetCurrentDrawIndirectBuffer(VisRawBuffer * iIndirectBuffer);


   /**
   * @nodoc
   */
  virtual void BeginMultipleDraw ();

   /**
   * @nodoc
   */
  virtual void EndMultipleDraw ();


  /** Draws a dynamic graphic primitive.
   * @param iGP
   * The @href CATDynamicGP to draw.
   */
  virtual void DrawDynamicGP (CATDynamicGP &iGP);

  /** @nodoc */
  virtual void DrawOOCPointCloudGP(CAT3DOOCPointCloudGP &iGP);

  /** @nodoc */
  virtual void DrawScissor(float *, CATGraphicAttributeSet const &);

  /** @nodoc */
  virtual void EndDrawScissor();

  /** @nodoc */
  virtual void AddCurveClipping(float *);

  /** @nodoc */
  virtual void RemoveCurveClipping();

  /** @nodoc */
  virtual void DrawHighLight();

  /** @nodoc */
  virtual void EndDrawHighLight();

  /** @nodoc */
  virtual void Draw3DMirror (CAT3DMirrorGP &iMirrorGP);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw3DMarker         (const float *points, const int nb_points, SymbolType symbol);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw3DPolyline       (const float *points, const int nb_points, TessFlag TessStatus = LINE);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw3DLine           (const float *points, const int nb_points, const int line_type = 0, TessFlag TessStatus = LINE);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw3DAnnotationText (const float *point, const CATUnicodeString &text, CATAnchorPoint position = BASE_LEFT, const float height = 0.f, const int contour = 0);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw3DImagePixel     (const float *point, const CATPixelImage *image, const int xOffset, const int yOffset, const int alpha);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw2DMarker         (const float *points, const int nb_points, SymbolType symbol);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw2DPolyline       (const float *points, const int nb_points, TessFlag TessStatus = LINE);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw2DLine           (const float *points, const int nb_points, const int line_type = 0, TessFlag TessStatus = LINE);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw2DAnnotationText (const float *point, const CATUnicodeString &text, CATAnchorPoint position = BASE_LEFT, const float height = 0.f, const int contour = 0, const CATGraphicAttributeSet *contour1 = NULL, const CATGraphicAttributeSet *contour2 = NULL);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw2DImagePixel     (const float *point, const CATPixelImage *image, const int alpha,  const int xOffset = 0, const int yOffset = 0);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw2DNurbsOrPolyBezier(const int order, const float *controls, const int nb_controls, const float *nodes, const int nb_nodes, const float start_param, const float end_param, const float *weights, const float *bezier_controls, const int nb_bezier_controls);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw2DPolygon        (const float *points, const int nb_points, const int fill, const int nb_triangle = 0, const int *type = 0, const int *triangle = 0, const int *vertex = 0, TessFlag TessStatus = LINE);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw2DQuadStrip      (const float *points, const int nb_points, const float *vertexcolors);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw2DQuadStrip      (const float *i_pPoints, const int i_nbPoints, const float *i_pVertexcolors, const CATBoolean& i_formatRGBAFlag);

  /**
   * @nodoc
   */
  virtual void ImmediateDraw2DGeomText      (CATFont * font, const CATUnicodeString & text, CAT2DGeomTextAttributeSet & attset, const float height, const int rendertype);



  /**
   * @nodoc
   */
  virtual CATVizVertexBuffer* SetCurrentVertexBuffer(CATVizVertexBuffer *vb);

  /**
   * @nodoc
   */
  inline CATVizVertexBuffer* GetCurrentVertexBuffer();

  /**
   * @nodoc
   */
  virtual void DrawCATViz3DFace(CATViz3DFace *face);

  /**
   * @nodoc
   */
  virtual void DrawCATViz3DFace1DTexture(CATViz3DFace *face);

  /**
   * @nodoc
   */
  virtual void DrawCATViz3DFace2DTexture(CATViz3DFace *face);

#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
  /**
   * @nodoc
   */
  virtual void DrawCATViz3DFaceMultiTexture(CATViz3DFace *face);
#endif

  /**
   * @nodoc
   */
  virtual void DrawCATViz3DEdge(CATViz3DEdge *edge);

  /**
   * @nodoc
   */
  virtual void DrawCATViz3DLine(CATViz3DLine *line);

  /**
   * @nodoc
   */
  virtual void DrawCATViz3DMarker(CATViz3DMarker *marker);

  /**
   * @nodoc
   */
  virtual void DrawCATVizDynamicPrimitive(CATVizDynamicPrimitive &dprimitive);

  /**
   * @nodoc
   */
  virtual void DrawVisPrimitive (VisPrimitive &iVP);

  /**
   * @nodoc
   */
  virtual void DrawVisGPGPUPrimitive (VisGPGPUPrimitive &iVP);

  /**
   * @nodoc
   */

  virtual void DrawCATVizVoxel        (CATVizVoxelGP *voxel);

  /**
   * @nodoc
   */
  virtual void ImmediateDrawOcclusionBox    (float xMin, float yMin, float zMin, float xMax, float yMax, float zMax);

  /**
   * @nodoc
   */
  virtual void ImmediateDrawTriangle        (float * v1, float * v2, float * v3);

  /**
   * @nodoc
   */
  virtual void ReadFrontBuffer(const int *points, CATPixelImage *background);

  /** Get the support's width and height.
   * @param oWidth
   * The returned width.
   * @param oHeight
   * The returned height.
   */
  inline void GetWidthAndHeight( float &oWidth, float &oHeight ) const;

  /** Get the mm size in model unit for 2D.
   * @return
   * The mm size in model unit.
   */
  float GetMMFromModelRatio () const ;

  /** Get the mm size in model unit for a 3D point.
   * @param iPoint
   * The 3D point where the size is calculated.
   * @return
   * The mm size in model unit.
   */
  float GetMMFromModelRatio (const CATMathPointf & iPoint) const ;

  /** Get the pixel size in model unit for 2D.
   * @return
   * The pixel size in model unit.
   */
  float GetPixelFromModelRatio () const;

  /** Get the pixel size in model unit for a 3D point.
   * @param iPoint
   * The 3D point where the size is calculated.
   * @return
   * The pixel size in model unit.
   */
  float GetPixelFromModelRatio (const CATMathPointf & iPoint) const;

  /** Get the pixel's ratio height/weight.
   * @return
   * The pixel's ratio.
   */
  inline float GetPixelRatioWH() const;

  /**
   * @nodoc
   */
  int IsDrawingLeft() const;

  /** Push the 3D matrix.
   * @param iMatrix
   * The 3D matrix to apply.
   * @return
   * The pointer to the new render.
   */
  virtual CATRender * PushMatrix (CAT4x4Matrix &iMatrix);

  /** Push the 2D matrix.
   * @param iMatrix
   * The 2D matrix to apply.
   * @return
   * The pointer to the new render.
   */
  virtual CATRender * PushMatrix (CAT3x3Matrix &iMatrix);

  /** Pop a matrix.
   * @param ioRender
   * The render created by PushMatrix to delete.
   */
  virtual void PopMatrix (CATRender *ioRender);

  /**
   * @nodoc
   */
  virtual void PushTextureMatrix (CAT4x4Matrix &iMatrix);

  /**
   * @nodoc
   */
  virtual void PopTextureMatrix ();

  /**
   * @nodoc
   */
  virtual int IsCurrentWorldScaled ();

  /**
   * @nodoc
   */
  virtual void GetWorldScaleCancelMatrix(CAT4x4Matrix& oMatrix);

  /**
   * @nodoc
   */
  virtual void SetUVTransform (float const*);

  /**
   * @nodoc
   */
  virtual void operator *= (const CAT4x4Matrix &iMatrix);

  /**
   * @nodoc
   */
  virtual void operator *= (const CAT3x3Matrix &iMatrix);

  /**
   * @nodoc
   */
  virtual void PushReference ();

  /**
   * @nodoc
   */
  virtual void PopReference ();

  /**
   * @nodoc
   */
  virtual void SetForeground      (const int &);

  /**
   * @nodoc
   */
  virtual void SetForegroundRGBA  (const int);

  /**
   * @nodoc
   */
  virtual void SetLineAttributes  (const int &, const int &);

  /**
   * @nodoc
   */
  virtual void SetPointTypeAttribute (const unsigned int &iPtType);

   /**
   * @nodoc
   */
  virtual void SetPointSizeAttribute (const float &iPtSize);

  /**
   * @nodoc
   */
  virtual void SetFurtive       (const int OnOff);

  /**
   * @nodoc
   */
  inline virtual int  GetFurtive	();

  /**
   * @nodoc
   */
  inline int HighlightInheritance();

  /**
   * @nodoc
   */
  inline int ColorInheritance();

  /**
   * @nodoc
   */
  virtual CATGraphicAttributeSet& GetInheritedColor();

  /**
   * @nodoc
   */
  inline int Get2DModeInheritanceCounter();
  /**
   * @nodoc
   */
  virtual const CATGraphicAttributeSet& GetInherited2DModeColor() const;

  /**
   * @nodoc
   */
  inline int ASMColorInheritance();

  /**
   * @nodoc
   */
  virtual CATGraphicAttributeSet& GetInheritedASMColor();

  /**
   * @nodoc
   */
  inline int AlphaInheritance();

  /**
   * @nodoc
   */
  inline int LineWidthInheritance();

  /**
   * @nodoc
   */
  inline int LineTypeInheritance();

  /**
   * @nodoc
   */
  inline int FilterInheritance();

  /**
   * @nodoc
   */
  int AreSpritesActivated();
  /**
   * @nodoc
   */
  void ActivateSprites(const int iOnOff=0);

  /**
   * @nodoc
   */
  inline int IsAllElementInZMode();

  /**
   * @nodoc
   */
  virtual void SetAllElementInZMode(int mode);


  /** Get the mm size in pixel.
   * @return
   * The mm size in pixel.
   */
  inline float GetMMInSupportUnit() const;

  /** Gets the render's CATColorMap.
   * @return
   * The pointer to the color map.
   */
  inline CATColorMap * GetCATColorMap();

  /** Sets the render's view mode.
   * @param iViewMode
   * The view mode.  @see CATViewerUtility.
   * @param iActive
   * <br><b> Legal values</b>:
   * <ol>
   * <li> 0 : the view is inactivated </li>
   * <li> 1 : the view is activated </li>
   * </ol>
   */
  inline void SetViewMode (const int iViewMode, const int iActive);

  /** Gets the render's current view mode.
   * @param oViewMode
   * The returned view mode.
   */
  virtual int ViewMode (const int oViewMode) const;

  /**
   * @nodoc
   */
  virtual void SetColorMask (const int mode);

  /**
   * @nodoc
   */
  virtual void SetPolygonMode (const int mode);

  /**
   * @nodoc
   */
  virtual void SetClippingMode (const int mode);

  /**
   * @nodoc
   */
  virtual void SetClippingPlanes(int iNbPlanes, float *iPoint, float *iNormal, int iCappingPlaneFlags = 1);

  /**
   * @nodoc
   */
  virtual void AddInstance(CATRep *iRep);

  /** Gets the render's 3D Viewpoint.
   * @return
   * The pointer to the 3D viewpoint.
   */
  virtual CAT3DViewpoint * Get3DViewpoint() const;

  /**
   * @nodoc
   */
  inline int GetGeomTextNumber() const;

  /**
   * @nodoc
   */
  virtual void BeginDraw (CATViewpoint &viewpoint);

  /**
   * @nodoc
   */
  virtual void EndDraw   (CATViewpoint &viewpoint);

  /** Gets the render's Support.
   * @return
   * The pointer to the support.
   */
  inline CATSupport* GetSupport();

  /** @nodoc */
  inline void SetAdvancedPriority(const int iOnOff);
  /** @nodoc */
  inline int  GetAdvancedPriority();

  /** @nodoc */
  virtual int GetCurrentMatrix(CAT4x4Matrix& o_matrix);

  /** @nodoc */
  int _IsShowSpace;
  /** @nodoc */
  int _OneNodeIsNoshow;

  /** @nodoc */
  inline int IsAPickingRender();

  /** @nodoc */
  inline int IsADrawingRender();

  /** @nodoc */
  inline int IsACullingRender();

  /** @nodoc */
  void DisableLighting(int);

 /** @nodoc
  *  MPCulling : return the number of thread used for drawing */
 virtual int  IsMultiThreadMode() const ;

 /** @nodoc
  *  MPCulling : set the number of thread used for drawing */
 virtual void SetMultiThreadMode(int mode);

 /** @nodoc */
 inline void SetSemanticLevel(CATVizSemanticLevel level);

 /** @nodoc */
 inline CATVizSemanticLevel GetSemanticLevel();

 /** @nodoc */
 void Lock2DMode();
 /** @nodoc */
 void Unlock2DMode();
 /** @nodoc */
 void Set2DMode(CATVis2DModeType i_2DMode);
 /** @nodoc */
 CATVis2DModeType Get2DMode();
 /** @nodoc */
 int Get2DModeState();
 /** @nodoc */
 void Set2DModeState(int i_state);

 /** @nodoc */
 virtual void SetGPUStorageManager(CATVisGPUStorageManager* ipGPUStorageManager);

 /** @nodoc */
 void UpdateFrameCounterOnGPUStorage(unsigned int iStorageID, unsigned int iMemorySpace=0);

 /** @nodoc */
 inline CATVisGPUStorageManager* GetGPUStorageManager();

 /** @nodoc */
 virtual void SetTexturesStorageManager(CATVisTexturesStorageManager* ipTextureStorageManager);

 /** @nodoc */
 virtual void PushToleranceScale(float iToleranceScale);

  /** @nodoc */
 virtual void PopToleranceScale(float iToleranceScale);

  /** @nodoc */
 virtual void GetToleranceScale(float& oToleranceScale) const;

  /** @nodoc */
  inline int GetHighlightMode () const;


  //HRD_OcclusionMap
  /** @nodoc */
  virtual void SetHRDOcclusionMapMode(unsigned int iOnOff);
  /** @nodoc */
  virtual unsigned int GetHRDOcclusionMapMode() const;

  /** @nodoc */
  virtual void SetDialogFlag(int iFlag);

  /** @nodoc */
  virtual void SetRenderingMode(const unsigned int mode);

  /** @nodoc */
  void SetSubSupportData(const VisSubSupportData& iSubSupportData);

  /**
   * @nodoc
   * Do not call if already call FilterRepresentation
   */
  virtual int DrawCompiledRep(CATRep& iRep);

  /**
   * @nodoc
   */
  virtual void EndDrawCompiledRep(CATRep& iRep);

  /** @nodoc */
  virtual bool IsAOutlineCullingRender() const { return false; }

  /** @nodoc */
  virtual bool IsA3DBoundingBoxRender() const { return false; }


  /**
   * @nodoc
   */
  inline CATDelegateRender* GetDelegateRender() {return _delegateRender;}

  /** @nodoc */
  inline void SetCloneViewpointAtBeginDraw(bool iCloneViewpoint);

  /** @nodoc */
  inline bool IsCloneViewpointAtBeginDraw() const;


 protected :

  /** @nodoc */
  int IntersectionFrustum(CATMathPointf Intersection, CATMathPointf Origine, CATMathPointf Sommet1, CATMathPointf Sommet2);

  /** @nodoc */
  virtual int DoesMaterialsTextureRequireUpdating(CATGraphicMaterial &iMat);

  /** @nodoc */
  virtual int DoMaterialTextureParametersEqual(CATGraphicMaterial &iMat1, CATGraphicMaterial &iMat2);

  /**
   * @nodoc
   *
   * By default, methods like Draw3DCanonicalCylinder() will call this method, and it will process the canonical reps as CATViz3DFace/CATViz3DEdge.
   * You should override Draw3DCanonicalRep() or make sure that DrawCATViz3DFace() and DrawCATViz3DEdge() are implemented in your render.
   */
  virtual void Draw3DCanonicalRep(CAT3DCanonicalRep& iRep);

  /**
   * @nodoc
   */
  CATRender (const CATRender &brother);

  CATSupport       *_support;
  CATColorMap      *_catcolormap;
  CATCharacterFont *_catfont;

  CATViewpoint	 *viewpoint_;
  CAT2DViewpoint *viewpoint2D_;
  CAT3DViewpoint *viewpoint3D_;
  CATViewport    *viewport_;
  CAT2DViewport  *viewport2D_;
  CAT3DViewport  *viewport3D_;
  CAT3DViewport  *_ClippedViewport;

  CATGraphicAttributeSet _current_attribut;
  CATGraphicAttributeSet _inherited_color_attribut;
  CATGraphicAttributeSet _inherited_asmcolor_attribut;
  CATGraphicAttributeSet _inherited_2DModeColor_attribut;

  VisAttribute* m_currentVisAttr;
  unsigned int m_currentPointType;
  float        m_currentPointSize;

  float supportCull_;
  float supportSag_;
  float cull_;
  float sag_;
  float width_;
  float height_;
  float ratio_;
  float mmInSupportUnit_;
  float scale_;

  CAT3DRep* _pCurrentRoot;
  float _cullVanishingRatio;

  CATGraphicMaterial 	*  _CurrentMaterial ;
  CATGraphicMaterial 	*  _DefaultMaterial ;

  int _view_mode;
  int _stereoActivate;

  int _currentType;

  //  attribut inheritance management
  //  -------------------------------

  int _inheritColorMode;
  int _inheritASMColorMode;
  int _inheritAlphaMode;
  int _inheritLinewidth;
  int _inheritLinetype;
  int _inheritLook;
  int _isInside;
  int _colorRGBAsave;
  int _colorsave;
  int _highlight_on;
  int _sprites_activated;
  int _line_width_save;
  int _line_type_save;
  int _furtive;
  int _DrawingLeft;
  int _geomTextNumber;
  int _color;
  int _alpha;
  int _asmcolor;
  int _linetype;
  int _linewidth;
  int _polygonMode;
  int nb_light_;
  int _look;
  int _iBackFaceCullingMode;
  int _inherit2DModeCounter;

  // Clipping plane;
  int _Clipping, _ClippingFlags;
  float *_Clip_point;
  float *_Clip_normal;

  CAT4x4Matrix _working_matrix4x4;
  CATMathPointf FrustumVertices[8];

  int _isAPickingRender;
  int _isADrawingRender;
  int _isACullingRender;
  int _disableLighting;

  // MPCulling
  short _multiThreadMode;

  int _AllZBuffer;
  int _advancedPriority;

  Background3DViewMode _bckgrd3d_activated;

  CATVizVertexBuffer* _CurrentVertexBuffer;
  CATVizSemanticLevel _semanticLevel;

  int _2DModeState;
  int _2DModeLock;

  CATVis2DModeType _using2DMode;

  CATVisGPUStorageManager*      _pGPUStorageManager;
  CATVisTexturesStorageManager* _pTexturesStorageManager;
  CATDelegateRender*            _delegateRender;

  float _ToleranceScale;
  unsigned int _refinementActivated;
  float _quality;

  // sub support data
  int   _subSupportMode;
  float _subSupportXPos, _subSupportYPos;
  float _subSupportWidth, _subSupportHeight;
  float _zoomForDefaultSize;

  bool _IsHighLightPass; //++ OU4 : New Engine
  // authorize viewpoint cloning only for the main thread.
  // In other threads it could create races on CATBaseUnknown (see CATOutlineCullingRender)
  bool _cloneViewpointAtBeginDraw = true;

private :
   /** @nodoc */
   // Highlight Mode Management
   // "0" : for faces, highlights its edges
   // "1" : for faces, highlights given faces in shading mode
   unsigned int  _uiHighlightMode;

  friend class CATDelegateRender;
  /**
  * @nodoc
  * ctor for CATDelegateRender only.
  */
  CATRender();

public:

  /**
   * @nodoc
   */

  virtual void ActivateRefinement(unsigned int OnOff);

  /**
   * @nodoc
   */

  virtual unsigned int GetRefinement();


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

  virtual void DrawCATVizUV3DFace(CATVizUV3DFace *rep, CAT3DViewpoint *viewpoint, CAT3DViewport *viewport);

  /**
   * @nodoc
   */

  virtual void DrawCATVizUV3DEdge(CATVizUV3DEdge *edge);

  /**
   * @nodoc
   */

  virtual void DrawCATVizUV3DEdge(CATVizUV3DEdge *edge, CAT3DViewpoint *viewpoint, CAT3DViewport *viewport);


  /**
   * @nodoc
   */

  virtual void DrawCATVizUV3DLine(CATVizUV3DLine *line);

  /**
   * @nodoc
   */

  virtual void DrawCATVizUV3DLine(CATVizUV3DLine *line, CAT3DViewpoint *viewpoint, CAT3DViewport *viewport);

  /**
   * @nodoc
   */
  virtual void DrawPrimitiveSet(CATVizPrimitiveSet *set);

  /**
   * @nodoc
   */

  virtual void DrawPrimitiveSet(CATVizPrimitiveSet *set, CAT3DViewpoint *viewpoint, CAT3DViewport *viewport);

  /**
   * @nodoc
   */
  virtual void DrawCATVizIndexed3DMarker(CATVizIndexed3DMarker *marker);

  /**
   * @nodoc
   */
  virtual void Draw3DBufferedIndexedLine (CAT3DIndexedLineGPVBO &iGP);

  /**
   * @nodoc
   */
  virtual void SetBackFaceCullingMode (const unsigned int);

  /**
   * @nodoc
   */
  virtual void SetTwoSidedLightingMode (const unsigned int);

  /**
   * @nodoc
   */
  virtual void ImmediateDrawFreeTypeText     (const CATFreeTypeTextGP* iTextGP);

  /**
   * @nodoc
   */
  virtual void SetIgnoreCompiledRep(unsigned int);

  /**
   * @nodoc
  */
  typedef enum
  {
      eAllZNone = 0, //_AllZBuffer option is disabled.
      eAllZMode1,    //_AllZBuffer option is enabled with default mode.
      eAllZMode2     //_AllZBuffer option is enabled but texts and blanking polygons must be differentiated to avoid z-fight.
  } EAllZModes;

  /** @nodoc */
  virtual void SetCurrentVisMaterial(VisMaterial &iMaterial);
  /** @nodoc */
  virtual VisMaterial* GetCurrentVisMaterial() const;

protected:
  VisMaterial *_pCurrVisMaterial ;
};

inline int CATRender::IsAPickingRender()
{
	return _isAPickingRender;
}

inline int CATRender::IsADrawingRender()
{
	return _isADrawingRender;
}

inline int CATRender::IsACullingRender()
{
	return _isACullingRender;
}

inline CATGraphicAttributeSet & CATRender::GetCurrentAttribute ()
{
 return (_current_attribut);
}

inline int CATRender::GetFurtive()
{
 return (_furtive);
}

inline int CATRender::HighlightInheritance()
{
  return _highlight_on;
}

inline int CATRender::ColorInheritance()
{
  return _inheritColorMode;
}

inline CATGraphicAttributeSet& CATRender::GetInheritedColor()
{
  return _inherited_color_attribut;
}

inline int CATRender::ASMColorInheritance()
{
  return _inheritASMColorMode;
}

inline int CATRender::Get2DModeInheritanceCounter()
{
  return _inherit2DModeCounter;
}
inline const CATGraphicAttributeSet& CATRender::GetInherited2DModeColor() const
{
  return _inherited_2DModeColor_attribut;
}

inline CATGraphicAttributeSet& CATRender::GetInheritedASMColor()
{
  return _inherited_asmcolor_attribut;
}

inline int CATRender::AlphaInheritance()
{
  return _inheritAlphaMode;
}

inline int CATRender::LineWidthInheritance()
{
  return _inheritLinewidth;
}

inline int CATRender::LineTypeInheritance()
{
  return _inheritLinetype;
}

inline int CATRender::FilterInheritance()
{
  return /*_inheritFilter*/0;
}


inline CATColorMap * CATRender::GetCATColorMap()
{
 return _catcolormap;
}

inline int CATRender::GetGeomTextNumber() const
{
 return _geomTextNumber;
}

inline CATSupport* CATRender::GetSupport()
{
 return (_support);
}

inline void CATRender::SetViewMode (const int view_mode, const int active)
{
  if(active)
    _view_mode|=view_mode;
  else
    _view_mode&=~view_mode;
}

inline float CATRender::GetMMInSupportUnit () const
{
 return (mmInSupportUnit_);
}


inline float CATRender::GetPixelRatioWH() const
{
 return (ratio_);
}

inline void CATRender::GetWidthAndHeight( float &width, float &height ) const
{
 width =  width_;
 height = height_;
}

inline int CATRender::IsAllElementInZMode()
{
  return _AllZBuffer;
}


#ifdef _IRIX_SOURCE
inline int CATRender::IsDrawable (const float x, const float y, const float z)
{
    return !viewport3D_->IsOutside(x,y,z);
}

inline int CATRender::IsDrawable (const CATMathPointf &minPoint, const CATMathPointf &maxPoint)
{
    return !viewport3D_->IsOutside(minPoint, maxPoint);
}
#endif

inline void CATRender::SetSemanticLevel(CATVizSemanticLevel level)
{
   _semanticLevel = level;
}

inline CATVizSemanticLevel CATRender::GetSemanticLevel()
{
   return _semanticLevel;
}

inline CATVizVertexBuffer* CATRender::GetCurrentVertexBuffer()
{
  return _CurrentVertexBuffer;
}

inline void CATRender::SetAdvancedPriority(const int iOnOff)
{
 _advancedPriority = iOnOff;
}

inline int  CATRender::GetAdvancedPriority()
{
 return _advancedPriority;
}

inline CATVisGPUStorageManager* CATRender::GetGPUStorageManager()
{
  return _pGPUStorageManager;
}

inline int CATRender::GetHighlightMode () const
{
   return _uiHighlightMode;
}

inline void CATRender::SetCloneViewpointAtBeginDraw(bool iCloneViewpoint)
{
  _cloneViewpointAtBeginDraw = iCloneViewpoint;
}

inline bool CATRender::IsCloneViewpointAtBeginDraw() const
{
  return _cloneViewpointAtBeginDraw;
}

#endif
