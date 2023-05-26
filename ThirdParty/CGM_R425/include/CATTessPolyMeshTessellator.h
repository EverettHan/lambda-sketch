//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// Layer of tessellation's vertex attributes.
//
//=============================================================================
//  2006-11-02  BPG: New.
//=============================================================================
#ifndef CATTessPolyMeshTessellator_H
#define CATTessPolyMeshTessellator_H

#include "TessPolygon.h"

#include "CATDataType.h"
#include "CATTessDiagnostic.h"

//
class CATTessSettings;

class CATBody;
class CATFace;
class CATCell;

class CATIPolyMesh;
class CATTessPolyMeshTriangleAttributeLayer;
class CATTessPolyMeshVertexAttributeLayer;

class CATSoftwareConfiguration;

 
#ifndef CATTessFrameworkCaller
#define CATTessFrameworkCallerExpansed(x) #x
#define CATTessFrameworkCaller(x)  CATTessFrameworkCallerExpansed(x)
#endif


//
class ExportedByTessPolygon CATTessPolyMeshTessellator
{
public:
  inline CATTessPolyMeshTessellator();
  inline ~CATTessPolyMeshTessellator();

public:
  /** Tesselate a CATBody into a CATIPolyMesh without outputting any attributes.
   */
  CATTessDiagnostic Compute(CATBody *iBody,
                            const CATTessSettings &iSettings,
                            CATIPolyMesh &ioMesh,
                            CATSoftwareConfiguration *iConfig = 0,
                            const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_) ) const;

  CATTessDiagnostic ComputeLocal(CATBody *iBody,
                                  const CATTessSettings &iSettings,
                                  CATIPolyMesh &ioMesh,
                                  CATSoftwareConfiguration *iConfig = 0) const;
  /** Tesselate a CATBody into a CATIPolyMesh, outputting vertices attributes.
   *
   * You may choose which data you want it to export into the attribute layer
   * by selecting the good iVertexInfo combination:
   * - (iVertexInfo & 1): export UV attributes (ie U,V parameters and CATFace)
   * - (iVertexInfo & 4): export W attributes (ie W parameter and CATEdge)
   */
  CATTessDiagnostic Compute(CATBody *iBody,
                            const CATTessSettings &iSettings,
                            CATLONG32 iVertexInfo,
                            CATIPolyMesh &ioMesh,
                            CATTessPolyMeshVertexAttributeLayer &oVertexAttr,
                            CATSoftwareConfiguration *iConfig = 0,
                            const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_) ) const;


  /** Tesselate a CATBody into a CATIPolyMesh, outputting vertices and triangle
   * attributes.
   *
   * You may choose which data you want it to export into the vertex attribute
   * layer by selecting the good iVertexInfo combination, as described above.
   */
  CATTessDiagnostic Compute(CATBody *iBody,
                            const CATTessSettings &iSettings,
                            CATLONG32 iVertexInfo,
                            CATIPolyMesh &ioMesh,
                            CATTessPolyMeshVertexAttributeLayer &oVertexAttr,
                            CATTessPolyMeshTriangleAttributeLayer &oTriangleAttr,
                            CATSoftwareConfiguration *iConfig = 0,
                            const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_) ) const;


  /** Tesselate a CATFace into a CATIPolyMesh, outputting vertices attributes.
   *
   * You may choose which data you want it to export into the attribute layer
   * by selecting the good iVertexInfo combination:
   * - (iVertexInfo & 1): export UV attributes (ie U,V parameters and CATFace)
   * - (iVertexInfo & 4): export W attributes (ie W parameter and CATEdge)
   */
  CATTessDiagnostic Compute(CATFace *iFace,
                            CATBody *iBody, //body containing the face
                            const CATTessSettings &iSettings,
                            CATLONG32 iVertexInfo,
                            CATIPolyMesh &ioMesh,
                            CATTessPolyMeshVertexAttributeLayer &oVertexAttr,
                            CATSoftwareConfiguration *iConfig = 0,
                            const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_) ) const;

  // Internal use only
protected:
  CATTessDiagnostic Compute(CATBody *iBody,
                            CATCell* iCell,
                            const CATTessSettings &iSettings,
                            CATLONG32 iVertexInfo,
                            CATIPolyMesh &ioMesh,
                            CATTessPolyMeshVertexAttributeLayer *oVertexAttr,
                            CATTessPolyMeshTriangleAttributeLayer *oTriangleAttr,
                            CATSoftwareConfiguration *iConfig,
                            const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_) ) const;
};

// ----------------------------------------------------------------------------

inline
CATTessPolyMeshTessellator::CATTessPolyMeshTessellator()
{}

inline
CATTessPolyMeshTessellator::~CATTessPolyMeshTessellator()
{}

#endif // !CATTessPolyMeshTessellator_H
