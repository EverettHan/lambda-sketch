#ifndef CATVizPrimitiveCacheRender_h_
#define CATVizPrimitiveCacheRender_h_

#include "SGInfra.h"

// SGInfra (ProtectedInterfaces)
#include "CATRepRender.h"
#include "CATCompVizPrimitiveCacheBehavior.h"

class ExportedBySGInfra CATVizPrimitiveCacheRender : public CATRepRender
{
    CATDeclareClass_Deprec;

public:
    CATVizPrimitiveCacheRender(const CATSupport& iSupport, VizPrimitiveCacheBehavior iVizPrimitiveCacheBehavior);
    virtual ~CATVizPrimitiveCacheRender();

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

    // Graphical elements draw methods:
    // --------------------------------
    //If you override these methods, make sure to call the same of this class
    virtual int DrawRepresentation(CATRep& iRep, int iInside, void*& iData);
    virtual int EndDrawRepresentation(CATRep& iRep, void*& iData);
    // --------------------------------

#if 0
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
#endif // 0

protected:
    virtual void Draw3DCanonicalRep(CAT3DCanonicalRep& iRep);
};

#endif // !CATVizPrimitiveCacheRender_h_
