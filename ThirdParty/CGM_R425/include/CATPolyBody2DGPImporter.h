// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBody2DGPImporter.h
//
//===================================================================
//
// October 2015  Creation: JXO
//===================================================================
#ifndef CATPolyBody2DGPImporter_H
#define CATPolyBody2DGPImporter_H

#include "PolyVizAdapters.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATGraphicPrimitive;
class CAT2DLineGP;
class CAT2DMarkerGP;
class CAT2DPolygonGP;
class CAT2DArcCircleGP;
class CAT2DArcEllipseGP;
class CAT2DQuadStripGP;
class CAT2DRectangleGP;

class CATPolyBody;
class CATPolyFace;
class CATPolyEdge;
class CATPolyPoint;
class CATPolyVertex;
class CATPolyCell;
class CATPolyBodyGPDiagnosis;

/*
This is an importer that constructs a CATPolyBody view of lists of GP markers, lines, edges and faces
The importer makes new CATPolyCell's that encapsulate the GP primitives and adds them to the CATPolyBody. 

This importer embeds a complete or partial list of GP primitives into a CATPolyBody.  For instance, if the list of 
CAT3DEdgeGP is empty, it provides a view of the CAT3DFaceGP without the edges.  It can process a single face 
or edge too.

*/
class ExportedByPolyVizAdapters CATPolyBody2DGPImporter
{

public:

  /*
   * Constructor.
   * The parameter is used to record the primitives whose data cannot be added to the CATPolyBody due
   * to some error.  It's basically used as a log of the primitives with error during call to Run ().
   */
  inline CATPolyBody2DGPImporter (CATPolyBodyGPDiagnosis* iDiagnosis = 0);
  inline ~CATPolyBody2DGPImporter ();

public:

  // Construct a CATPolyBody view of a CATGraphicPrimitive, of type:
  // CAT2DLineGP
  // CAT2DMarkerGP
  // CAT2DPolygonGP
  // CAT2DArcCircleGP
  // CAT2DArcEllipseGP
  // CAT2DQuadStripGP
  // CAT2DRectangleGP
  // Return the CATPolyCell associated to the CATGraphicPrimitive.
  HRESULT Run (CATGraphicPrimitive& iGP, 
               CATPolyBody& ioPolyBody,
               CATPolyCell*& oPolyCell,
               double iToleranceScale = 1.) const;
  // Construct a CATPolyBody view of a CAT2DLineGP.
  // Return the CATPolyCell associated to the CAT3DLineGP.
  HRESULT RunLine (CAT2DLineGP& iLineGP, 
               CATPolyBody& ioPolyBody,
               CATPolyEdge*& oPolyEdge) const;
  // Construct a CATPolyBody view of a CAT2DMarkerGP.
  // Return the last CATPolyVertex associated to the CAT2DMarkerGP.
  HRESULT RunMarker (CAT2DMarkerGP& iMarkerGP, 
               CATPolyBody& ioPolyBody,
               CATPolyVertex*& oPolyVertex) const;
  // Construct a CATPolyBody view of a CAT2DPolygonGP.
  // Returns a CATPolyFace if the CAT2DPolygonGP is filled.
  // Returns a CATPolyEdge if not.
  HRESULT RunPolygon (CAT2DPolygonGP& iPolygonGP, 
               CATPolyBody& ioPolyBody,
               CATPolyCell*& oPolyCell) const;
  // Construct a CATPolyBody view of a CAT2DArcCircleGP.
  // Returns a CATPolyFace if the CAT2DArcCircleGP is filled.
  // Returns a CATPolyEdge if not.
  HRESULT RunCircle (CAT2DArcCircleGP& iArcGP, 
               CATPolyBody& ioPolyBody,
               CATPolyCell*& oPolyCell,
               double iToleranceScale = 1.) const;
  // Construct a CATPolyBody view of a CAT2DArcEllipseGP.
  // Returns a CATPolyFace if the CAT2DArcEllipseGP is filled.
  // Returns a CATPolyEdge if not.
  HRESULT RunEllipse (CAT2DArcEllipseGP& iArcGP, 
               CATPolyBody& ioPolyBody,
               CATPolyCell*& oPolyCell,
               double iToleranceScale = 1.) const;
  // Construct a CATPolyBody view of a CAT2DQuadStripGP.
  // Returns a CATPolyFace
  HRESULT RunQuadStrip(CAT2DQuadStripGP& iQuadGP, 
               CATPolyBody& ioPolyBody,
               CATPolyCell*& oPolyCell) const;
  // Construct a CATPolyBody view of a CAT2DRectangleGP.
  // Returns a CATPolyFace if the rectangle is filled
  // Returns a CATPolyEdge if not.
  HRESULT RunRectangle(CAT2DRectangleGP& iQuadGP, 
               CATPolyBody& ioPolyBody,
               CATPolyCell*& oPolyCell) const;



  // Construct a CATPolyBody view of any 2D buffers of points.
  // Returns a CATPolyEdge
  HRESULT Run (const float * points,
               const int nbPoints,
               const int lineType,
               CATPolyBody& ioPolyBody,
               CATPolyCell*& oPolyEdge) const;
  // Construct a CATPolyBody view of any 2D buffers of points.
  // Returns a CATPolyFace, or CATPolyEdge if !fill
  HRESULT Run(const float *points,
              const int nb_points,
              const int fill,
              const int nb_triangle,
              const int *type,
              const int *triangle,
              const int *vertex,
              CATPolyBody& ioPolyBody,
              CATPolyCell*& oPolyCell) const;

private:

  CATPolyBodyGPDiagnosis* _Diagnosis;

};

inline CATPolyBody2DGPImporter::CATPolyBody2DGPImporter (CATPolyBodyGPDiagnosis* iDiagnosis) :
  _Diagnosis (iDiagnosis)
{
}

inline CATPolyBody2DGPImporter::~CATPolyBody2DGPImporter ()
{
  _Diagnosis = 0;
}


#endif // !CATPolyBody2DGPImporter_H

