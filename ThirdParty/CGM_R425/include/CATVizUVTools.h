#ifndef _CATVizUVTools_
#define _CATVizUVTools_

#include "SGInfra.h"

// For HRESULT definition
#include "IUnknown.h"
class CATRep;
class CATUVDecoder;

// UV Streaming options
typedef unsigned int CATUVOptions;

#define NO_CANONICAL_COMPRESSION	   0x1
#define OPTIMISED_STREAM 			   0x2
#define WIRES_STREAMING				   0x4
#define NO_NORMAL_COMPRESSION		   0x8
#define TANGENTS_ON_LINEAR_EDGES		0x16
#define NO_SMOOTH_EDGE_COMPRESSION  0x32
#define POLAR_TANGENTS_AND_NORMALS  0x64

// UV Read/Write entry points
ExportedBySGInfra HRESULT CATWriteUV (const char *filename, CATRep *rep, float accuracy = 0.0f, CATUVOptions options = 0);
ExportedBySGInfra HRESULT CATReadUV  (const char ** filenames, unsigned int nbFiles, CATRep ** oReps);
ExportedBySGInfra CATRep *CATReadUV  (const char *filename);
ExportedBySGInfra HRESULT CATReadUV  (const char *filename, CATUVDecoder & decoder);

// UV Utility functions
typedef struct
{
   unsigned int NbFaces;
   unsigned int NbPlanarFaces;
   unsigned int NbEdges;
   unsigned int NbBoundaryEdges;
   unsigned int NbInternalSharpEdges;
   unsigned int NbInternalSmoothEdges;
   unsigned int NbWireEdges;
   unsigned int NbBoundaryPoints;
   unsigned int NbInternalSharpPoints;
   unsigned int NbInternalSmoothPoints;
   unsigned int NbSurfacicPoints;
   unsigned int NbFreePoints;
   unsigned int NbInfiniteFaces;
   unsigned int NbIsopars;
} CATVizRepInfo;

ExportedBySGInfra CATRep * CATVizConvertUVRepToStdRep(CATRep & iRep, float & ioAccuracy);
ExportedBySGInfra HRESULT CATVizReplaceAllUVRep(CATRep * iRep);
ExportedBySGInfra HRESULT  CATVizGetRepInfo(CATRep & iRep, CATVizRepInfo & oRepInfo);
ExportedBySGInfra HRESULT  CATVizIsABody(CATRep & iRep);

// UV Quality
ExportedBySGInfra HRESULT CATVizIncreaseUVQuality();
ExportedBySGInfra HRESULT CATVizDecreaseUVQuality();
ExportedBySGInfra float   CATVizGetUVQuality();
ExportedBySGInfra void    CATVizSetUVQuality(float iQuality);

#endif
