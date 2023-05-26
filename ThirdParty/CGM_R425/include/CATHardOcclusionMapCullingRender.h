#ifndef CATHardOcclusionMapCullingRender_H
#define CATHardOcclusionMapCullingRender_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 2002

#include "CATVisFoundation.h"
#include "CATCullingRender.h"

class ExportedByCATVisFoundation CATHardOcclusionMapCullingRender : public CATCullingRender
{
 public :
  
  // Construction and destruction methods:
  // -------------------------------------
  
  CATHardOcclusionMapCullingRender (const CATSupport &support);
  virtual ~CATHardOcclusionMapCullingRender();
  
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
  virtual void Draw3DEdge                (CAT3DEdgeGP &);
  virtual void Draw3DEdges               (CAT3DEdgeGP** edge3L, int nedge, int m);
  virtual void DrawLightSource           (CAT3DLightSourceGP &);
  virtual void Draw3DFace                (CAT3DFaceGP &);  
  virtual void Draw3DPlanarFace          (CAT3DPlanarFaceGP &);
  virtual void Draw3DCylinder            (CAT3DCylinderGP &, const int = 0);
  virtual void Draw3DCurvedPipe          (CAT3DCurvedPipeGP &);
  
  virtual void DrawDynamicGP             (CATDynamicGP &);
};

#endif
