//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyMeshLoopSubdivision
//
//===================================================================
// 26/02/18 F1Z : Creation
// DD/MM/YY
//===================================================================
#ifndef CATPolyBodyMeshLoopSubdivision_H
#define CATPolyBodyMeshLoopSubdivision_H

// Polyhedral Interfaces
#include "CATPolyRefCounted.h"

// Polyhedral Body Operators
#include "PolyBodyRemeshing.h"

class CATPolyBody;
class CATPolyFace;
class CATIPolyMesh;

class CATPolyBodyMeshLoopSubdivisionImpl;
class CATIPolySurfaceVertexPositionLayer;
class CATIPolySurfaceVertexTextureCoordLayer;
class CATIPolySurfaceVertexNormalLayer;
class CATIPolySurfaceVertexUVLayer;

/**
* Simple loop subdivision. Each triangle is divided in 4 triangles. <br/>
* Thanks to the natural conformity of the poly body edges results, this subdivision is very efficient,
* even though it exponentially increases the number of triangles.
*/
class ExportedByPolyBodyRemeshing  CATPolyBodyMeshLoopSubdivision
{
public:
   // -----------------------------------------------------
   // SubdivMeshLayerComputer
   // -----------------------------------------------------
   class ExportedByPolyBodyRemeshing SubdivMeshLayerComputer : public CATPolyRefCounted
   {
   public:
      SubdivMeshLayerComputer() : CATPolyRefCounted(){};
      virtual ~SubdivMeshLayerComputer() {};

      // Information about the computation status
      virtual void BeginFaceSubdivision(const CATPolyFace * iFace){};
      virtual void EndFaceSubdivision  (const CATPolyFace * iFace){};

      // Methods for the computation
      virtual HRESULT ComputePosition(const int                                      iEVertexPrev   ,
                                      const int                                      iEVertex       ,
                                      const int                                      iEVertexNext   ,
                                      const int                                      iSVertexPrev   ,
                                      const int                                      iSVertex       ,
                                      const int                                      iSVertexNext   ,
                                      const double                                   iRatio         ,
                                      const CATPolyEdge                            * iEdge          ,
                                      const CATPolyFace                            * iFace          ,
                                            CATIPolySurfaceVertexPositionLayer     & ioPositionLayer);

      virtual HRESULT ComputeTexture (const int                                      iEVertexPrev   ,
                                      const int                                      iEVertex       ,
                                      const int                                      iEVertexNext   ,
                                      const int                                      iSVertexPrev   ,
                                      const int                                      iSVertex       ,
                                      const int                                      iSVertexNext   ,
                                      const double                                   iRatio         ,
                                      const CATPolyEdge                            * iEdge          ,
                                      const CATPolyFace                            * iFace          ,
                                            CATIPolySurfaceVertexTextureCoordLayer & ioTextureLayer );

      virtual HRESULT ComputeNormal  (const int                                      iEVertexPrev   ,
                                      const int                                      iEVertex       ,
                                      const int                                      iEVertexNext   ,
                                      const int                                      iSVertexPrev   ,
                                      const int                                      iSVertex       ,
                                      const int                                      iSVertexNext   ,
                                      const double                                   iRatio         ,
                                      const CATPolyEdge                            * iEdge          ,
                                      const CATPolyFace                            * iFace          ,
                                            CATIPolySurfaceVertexNormalLayer       & ioNormalLayer  );

      virtual HRESULT ComputeUV      (const int                                      iEVertexPrev   ,
                                      const int                                      iEVertex       ,
                                      const int                                      iEVertexNext   ,
                                      const int                                      iSVertexPrev   ,
                                      const int                                      iSVertex       ,
                                      const int                                      iSVertexNext   ,
                                      const double                                   iRatio         ,
                                      const CATPolyEdge                            * iEdge          ,
                                      const CATPolyFace                            * iFace          ,
                                            CATIPolySurfaceVertexUVLayer           & ioUVLayer      );

      virtual HRESULT ComputePosition(const int                                      iSVertexPrev   ,
                                      const int                                      iSVertex       ,
                                      const int                                      iSVertexNext   ,
                                      const double                                   iRatio         ,
                                      const CATPolyFace                            * iFace          ,
                                            CATIPolySurfaceVertexPositionLayer     & ioPositionLayer);

      virtual HRESULT ComputeTexture (const int                                      iSVertexPrev   ,
                                      const int                                      iSVertex       ,
                                      const int                                      iSVertexNext   ,
                                      const double                                   iRatio         ,
                                      const CATPolyFace                            * iFace          ,
                                            CATIPolySurfaceVertexTextureCoordLayer & ioTextureLayer );

      virtual HRESULT ComputeNormal  (const int                                      iSVertexPrev   ,
                                      const int                                      iSVertex       ,
                                      const int                                      iSVertexNext   ,
                                      const double                                   iRatio         ,
                                      const CATPolyFace                            * iFace          ,
                                            CATIPolySurfaceVertexNormalLayer       & ioNormalLayer  );

      virtual HRESULT ComputeUV      (const int                                      iSVertexPrev   ,
                                      const int                                      iSVertex       ,
                                      const int                                      iSVertexNext   ,
                                      const double                                   iRatio         ,
                                      const CATPolyFace                            * iFace          ,
                                            CATIPolySurfaceVertexUVLayer           & ioUVLayer      );
   };

   // -----------------------------------------------------
   // Class management
   // -----------------------------------------------------
   CATPolyBodyMeshLoopSubdivision(const int iSubdivisionDepth);
   virtual ~CATPolyBodyMeshLoopSubdivision();

public:

   /**
   * Run the Operator
   */
   HRESULT Run(CATPolyBody & ioPolyBody);

private:
   // -----------------------------------------------------
   // attributs (private)
   // -----------------------------------------------------
   CATPolyBodyMeshLoopSubdivisionImpl * m_loopSubdivisor;
};

#endif
