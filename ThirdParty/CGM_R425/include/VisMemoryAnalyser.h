#ifndef VisMemoryAnalyser_H_
#define VisMemoryAnalyser_H_

#include "CATSupport.h"
#include "CATRep.h"
#include "CATUnicodeString.h"
#include <map>
#include <string>
#include "CATVizMetaClass.h"
#include "CATVisFoundation.h"
class CATMetaClass;
class CATRep;
class CATGraphicPrimitive;
class CATMaterialApplication;
class CATGraphicMaterial;
class CATManipulator;
class VisSGOccurrenceHook;
class CATViz3DFace;
class CATViz3DEdge;
class CATViz3DMarker;
class CATSGCompositeRing;
class CAT4x4Matrix;
class CATVizVertexBuffer;
class CAT3DGeomRep;
class CAT3DCylinderRep;
class CAT3DCurvedPipeRep;
class CAT3DCustomRep;
class CATVizPrimitive;
class CATVizVertexBufferRep;
class CATVizPrimitiveSet;

class ExportedByCATVisFoundation VisMemoryAnalyser
{
public:

  enum SceneGraph {
    eSGTotal,
    eSGReps,
    eSGGps,
    eSGNumberOfLodGPs,
    eSGNumberOfVizPrimitiveSets,
    eSGVertexBuffers,
    eSGLightScenegraph,
    eSGComposites,
    eManipulators,
    eSGMatrices,
    eSGMatApps,
    eSGMaterials,
    eSGCount
  };

  enum Direct {
    eDirTotal,
    eDirNodes,
    eDirMaterials,
    eDirCommand,
    eDirCount
  };

  enum Observer
  {
    eObsTotal,
    eObsOccuGraph,
    eObsHook,
    eObsCount
  };

  enum Geometry
  {
    eVertices,
    eNormals,
    eBinormals,
    eTangents,
    eTexCoords,
    eTriangles,
    eStrips,
    eFans,
    eLines,
    eLineStrips,
    eLineLoops,
    ePoints,
    eGeomCount
  };

  struct ElemCounters
  {
    size_t NbReferences;
    size_t NbInstances;
    size_t Memory;
 
    ElemCounters() : NbReferences(0), NbInstances(0), Memory(0) {}
  };

  struct ElemIndiceCounters : ElemCounters
  {
    size_t Indices;
    ElemIndiceCounters() : ElemCounters(), Indices(0) {}
  };


  VisMemoryAnalyser()
  {
    memset(GeometryCounters, 0, sizeof(size_t)*eGeomCount);
  }
  virtual ~VisMemoryAnalyser() {}

  virtual void Analyse(CATSupport& iSupport, CATViewpoint& iViewpoint, CATRep& iRep, CATUnicodeString iPath);

  virtual void WriteReport(CATUnicodeString iPath, CATSupport& iSupport, CATViewpoint& iViewpoint);

  std::map<CATMetaClass*, ElemCounters> m_NbRepTypes;
  std::map<CATMetaClass*, ElemCounters> NbGPTypes;


  std::map<CATRep*, ElemCounters> Reps;
  std::map<CATGraphicPrimitive*, ElemCounters> Gps;
  std::map<CATVizVertexBuffer*, ElemCounters> Buffers;
  std::map<CATMaterialApplication*, ElemCounters> MatApps;
  std::map<CATGraphicMaterial*, ElemCounters> CatMaps;
  std::map<CATSGCompositeRing*, ElemCounters> Rings;
  std::map<CATManipulator*, ElemCounters> Manipulators;
  std::map<VisSGOccurrenceHook*, ElemCounters> Hooks;
  std::map<CATVizPrimitive*, ElemIndiceCounters>  VizPrimitives; 
  std::map<std::string, ElemIndiceCounters>  VizPrimitivesTypes; 

  std::map<const CAT4x4Matrix*, ElemCounters> Matrices;

  ElemIndiceCounters SGCounters[eSGCount];
  ElemCounters DirectCounters[eDirCount];
  ElemCounters ObserverCounter[eObsCount];
  ElemCounters DrawInfo;

  size_t GeometryCounters[eGeomCount];


protected:

  void _Analyse(CAT3DGeomRep* iRep); 
  void _Analyse(CAT3DCylinderRep* iRep);
  void _Analyse(CAT3DCurvedPipeRep* iRep);
  void _Analyse(CAT3DCustomRep* iRep);
  void _Analyse(CATVizVertexBufferRep* iRep);

  void _Analyse(CATGraphicPrimitive* iGp);

  void _Analyse(CATVizVertexBuffer* iVb);
  void _Analyse(CATVizPrimitive* iViz);
  void _Analyse(CATVizPrimitiveSet* iViz);


};
#endif  


