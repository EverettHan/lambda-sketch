#ifndef CATRefinementEngine_H
#define CATRefinementEngine_H

#include "SGInfra.h"
#include "CATVizIndexType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
class CAT3DViewpoint;
class CAT3DViewport;
class CATVizUV3DFace;
class CATVizUV3DEdge;
class CATVizUV3DLine;
class CATVizVertexBuffer;

class ExportedBySGInfra CATRefinementEngine
{
public:

   friend class CATEnginesLifeCycle;
   friend class CATComputeHRV;

   void AddRef();
   void Release();

   enum CATEngineType
   {
      CATDSEngine,         /* Standard DS refinement engine */
   };

   enum CATEngineSafety
   {
      CATEngineShared,     /* Non-thread safe */
      CATEngineThreadSafe, /* Thread-safe */
   };

   typedef struct _MeshCBData_
   {
      _MeshCBData_()
      {
        nbTriangles = 0;
        triangleIndices = 0;
        trianglesIndexType = CATVizUIntType;
        nbVertices = 0;
        vertices = 0;
        normals =0;
        textureCoordinates = 0;
        tangents = 0;
        binormals = 0;
        planarNormal = 0;
        textureDimension = 0;
        refined = 0;
        indexFactor = 3;
        indexMapping[0]    = 0;
        indexMapping[1]    = 0;
        indexMapping[2]    = 0;
      }
      unsigned int      nbTriangles;
      void *            triangleIndices;
      CATVizIndexType   trianglesIndexType;
		  unsigned int nbVertices;
      const float *     vertices;
      const float *     normals;
      const float *     textureCoordinates;
      const float *     tangents;
      const float *     binormals;
      const float *     planarNormal;
      unsigned int      textureDimension : 2;
      unsigned int      refined          : 1;
      unsigned int      indexFactor      :29;
      unsigned int      indexMapping[3];
   } MeshCBData;

   typedef struct
   {
      unsigned int      nbPoints; // size of the polyline
      void *            pointsIndices;
      CATVizIndexType   pointsIndexType;
      unsigned int      nbVertices; // size of the vertex array
      const float *     vertices;
      unsigned int      indexFactor;
      unsigned int      lineType;
   } BarsCBData;

   typedef void (*MeshCB)(void * user_data, MeshCBData & mesh_data);
   typedef void (*BarsCB)(void * user_data, BarsCBData & bars_data);

   static CATRefinementEngine * GetEngine(CATEngineType engineType = CATDSEngine, CATEngineSafety engineSafety = CATEngineShared);

   void SetQuality  (const float iQuality);
   void SetViewpoint(CAT3DViewpoint * iViewpoint);
   void SetViewport (CAT3DViewport  * iViewport);
   void ActivateFrustumCulling(CATBoolean iOnOff);
   void SetScale    (const float iScale);
   void SetMeshCallback(CATRefinementEngine::MeshCB iCB, void * user_data);
   void SetBarsCallback(CATRefinementEngine::BarsCB iCB, void * user_data);
   void SetTextureDimension(unsigned int textureDimension);

   virtual HRESULT Refine(CATVizUV3DFace & iFace, CATVizVertexBuffer & iVertexBuffer) = 0;
   virtual HRESULT Refine(CATVizUV3DEdge & iEdge, CATVizVertexBuffer & iVertexBuffer) = 0;
   virtual HRESULT Refine(CATVizUV3DLine & iLine) = 0;

private:

   static void SetHRVEngine(CATRefinementEngine *iEngine);
   static void ResetHRVEngine();

   static CATRefinementEngine *_HRVEngine;

protected:

   CATRefinementEngine();
   virtual ~CATRefinementEngine();

   float             _quality;
   float             _scale;
   CAT3DViewpoint *  _viewpoint;
   CAT3DViewport  *  _viewport;
   CATBoolean _frustumCulling;

   MeshCB            _meshCB;
   void *            _meshCB_user_data;

   BarsCB            _barsCB;
   void *            _barsCB_user_data;
   unsigned int      _textureDimension;

private:

   unsigned int      _refCount;
};

#endif
