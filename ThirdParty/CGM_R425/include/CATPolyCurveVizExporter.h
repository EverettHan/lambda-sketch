//=============================================================================
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// CATPolyCurveVizExporter.cpp
//
//=============================================================================
// 2008-03-07   BPG: New.
//=============================================================================
#ifndef CATPolyCurveVizExporter_H
#define CATPolyCurveVizExporter_H

#include "PolyImportExport.h"

#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATIPolyCurve;
class CATIPolySurfaceVertexLine;

class CAT3DLineGP;
class CAT3DEdgeGP;
class CAT3DBoundingGP;

class CATViz3DLine;
class CATViz3DEdge;
class IVisSGCustomPrimitive;

class CATPolySurfaceCompactVertexIndexMapper;
class CATGraphicAttributeSet;
//
class ExportedByPolyImportExport CATPolyCurveVizExporter
{
public:
  CATPolyCurveVizExporter();
  virtual ~CATPolyCurveVizExporter();

public:
  HRESULT Export(CATIPolyCurve &iCurve, 
                  CAT3DLineGP *&o3DLineGP) const;

  HRESULT Export(CATIPolySurfaceVertexLine &iSurfaceLine, int iVertexBufferEntry, 
                    const CATPolySurfaceCompactVertexIndexMapper* iCompactIndexMap, CAT3DBoundingGP *iFaces[2],
                    CAT3DEdgeGP *&o3DEdgeGP);

public:
  HRESULT Export(CATIPolyCurve &iCurve, 
                  CATViz3DLine *&oViz3DLine) const;

  HRESULT Export(CATIPolySurfaceVertexLine &iSurfaceLine, 
                int VertexBufferEntry, 
                const CATPolySurfaceCompactVertexIndexMapper* iCompactIndexMap, 
                CAT3DBoundingGP *iBoundingGPs[2],
                CATViz3DEdge *&oVizEdge);
  
};

#endif // !CATPolyCurveVizExporter_H
