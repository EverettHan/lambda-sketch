#ifndef CATPickingInsideRender_H
#define CATPickingInsideRender_H

//COPYRIGHT DASSAULT SYSTEMES 2003

#include "SGInfra.h"
#include "CATPickingRender.h"

class CATViz3DFace;
class CATViz3DEdge;

class ExportedBySGInfra CATPickingInsideRender : public CATPickingRender
{
  CATDeclareClass_Deprec;

public:

  CATPickingInsideRender(const CATSupport &support, const float x, const float y, const float dx, const float dy, CATPickPathList &pickPathList);
  CATPickingInsideRender(const CATPickingInsideRender &);

  virtual ~CATPickingInsideRender();

  //  Begin / End Draw
  //  ----------
  virtual int DrawRepresentation(CATRep &iRep, int iInside, void* &iData);
  virtual int EndDrawRepresentation(CATRep &iRep, void* &iData);

  //  IsDrawable
  //  ----------
  virtual int IsDrawable(const CATGraphicAttributeSet &, const CAT2DBoundingBox &, const CATRep &);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const CAT2DBoundingBox &, const int SubElementId);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const float *center, const float radius, const int SubElementId);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const CAT3DBoundingSphere &, const CATRep &, CATGraphicMaterial *iMat = 0);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const CATRep &, CATGraphicMaterial *iMat = 0);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const int SubElementId);
  virtual int IsDrawable(const CATGraphicAttributeSet &, const int SubElementId, const int type);
  virtual int IsDrawable(const CATGraphicAttributeSet &);
  virtual int IsDrawable(const int SubElementId);
  virtual int IsDrawable(VisAttribute& iAttribut, const int SubElementId);

  //  IsInside
  //  ----------
  virtual int IsInside(const CAT3DBoundingSphere &);
  virtual int IsInside(const CAT2DBoundingBox &);

  //  IsToSmall
  //  ----------
  virtual int IsToSmall(const CAT3DBoundingSphere &);
  virtual int IsToSmall(const CAT2DBoundingBox &);

  //  Draw GPs
  //  ----------
  virtual void ImmediateDraw2DImagePixel(const float *, const CATPixelImage *, const int, const int xOffset = 0, const int yOffset = 0);
  virtual void ImmediateDraw3DImagePixel(const float *, const CATPixelImage *, const int, const int, const int);

  virtual void ImmediateDraw2DAnnotationText(const float *, const CATUnicodeString &, AnchorPoint position = BASE_LEFT, const float height = 0.f, const int contour = 0, const CATGraphicAttributeSet *contour1 = NULL, const CATGraphicAttributeSet *contour2 = NULL);
  virtual void ImmediateDraw3DAnnotationText(const float *, const CATUnicodeString &, AnchorPoint position = BASE_LEFT, const float height = 0.f, const int contour = 0);

  virtual void ImmediateDraw2DLine(const float *, const int, const int linetype = 0, TessFlag flag = LINE);
  virtual void ImmediateDraw3DLine(const float *, const int, const int linetype = 0, TessFlag flag = LINE);

  virtual void ImmediateDraw2DMarker(const float *, const int, SymbolType);
  virtual void ImmediateDraw3DMarker(const float *, const int, SymbolType);

  virtual void ImmediateDraw2DPolygon(const float *, const int, const int, const int, const int *, const int *, const int *, TessFlag);

  virtual void ImmediateDraw2DQuadStrip(const float* ipPoints, const int iPointCount, const float* ipVertexcolors, const CATBoolean& iFormatRGBAFlag);

  virtual void ImmediateDrawFreeTypeText(const CATFreeTypeTextGP* iTextGP);

  virtual void DrawPointCloud(CAT3DPointCloudRep& iRep, const CATMathBox& iBox);
  virtual void DrawBlockCloud(CAT3DBlockCloudRep& iRep, const CATMathBox& iBox);

  virtual void Draw2DGeometricText(CAT2DGeometricTextGP &);
  virtual void Draw3DCylinder(CAT3DCylinderGP &, const int);
  virtual void Draw3DCurvedPipe(CAT3DCurvedPipeGP &);

  virtual void DrawCATViz3DFace(CATViz3DFace *face);
  virtual void DrawCATViz3DEdge(CATViz3DEdge *edge);

  virtual void DrawVisPrimitive(VisPrimitive &);

  //  Clipping
  //  ----------
  virtual void AddClippingSections(l_CATVisClippingSectionsFilter *) { ; }
  virtual void RemoveClippingSections(l_CATVisClippingSectionsFilter *) { ; }

protected:

  // picking methods
  virtual int PickPoint2D(const float *p1, const float dimension = 0.f);
  virtual int PickLine2D(const float *p1, const float *p2, const float dimension = 1.f);
  virtual int PickTriangle2D(const float *p1, const float *p2, const float *p3, int iUsePickingSize = 1);

  // try to pick a segment (with an open end at p1) by sampling points along it
  bool PickSegment3D(const CATMathPointf & iPt1, const CATMathPointf & iPt2);

  // Virtual because CATPickingInsidePolygonRender inherits from this.
  virtual bool IsOutside3D(const float *);

  CATBoolean _IgnoreNextSubElt;
  CATBoolean _IsRepOKToAdd; // Is the CATRep whose GPs are currently processed a valid selection target ?
  CATBoolean _IsRepDrawn; // Was at least one GP of the current CATRep actually traversed ?

private:

  CATPickingInsideRender();
  CATPickingInsideRender & operator= (const CATPickingInsideRender &);

  friend class VisPrimitiveGroupRep;
};

#endif
