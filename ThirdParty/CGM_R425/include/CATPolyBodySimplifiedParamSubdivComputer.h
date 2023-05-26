//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodySimplifiedParamSubdivComputer
//
//===================================================================
// 26/02/18 F1Z : Creation
// DD/MM/YY
//===================================================================
#ifndef CATPolyBodySimplifiedParamSubdivComputer_H
#define CATPolyBodySimplifiedParamSubdivComputer_H

// Polyhedral Mathematics
#include "CATMapOfPtrToPtr.h"
#include "CATMapOfPtrToInt.h"
#include "CATMapOfIntToPtr.h"
#include "CATPolyBucketsCache.h"

// Polyhedral Body Operators
#include "PolyBodyRemeshing.h"
#include "CATPolyBodyMeshLoopSubdivision.h"
#include "CATIPolyBodiesPositionMapping.h"

// Std
#include <vector>

class CATIPolyMesh;
class CATPolyBodyCopierIndicesObserver;

/**
* Subdiv computer implementation for subdiv loop operator
* on the decimated poly body obtained from the CATPolyBodySimplifiedParametrisationOperator.
*/
class ExportedByPolyBodyRemeshing CATPolyBodySimplifiedParamSubdivComputer : public CATPolyBodyMeshLoopSubdivision::SubdivMeshLayerComputer
{
public:
   // --------------------------------------------------------
   // Object management
   // --------------------------------------------------------
   static CATPolyBodySimplifiedParamSubdivComputer * Create(const CATIPolyBodiesPositionMapping *   iPositionMapping   ,
                                                            const CATPolyBody                   *   iTargetPolyBody    ,
                                                                  CATPolyBody                   * & oSubdivPolyBody    ,
                                                                  CATMapOfPtrToPtr                & oSubdivSimplCellMap);

   CATPolyBodySimplifiedParamSubdivComputer(const CATPolyBody                      * iSubdivPolyBody      ,
                                            const CATPolyBody                      * iTargetPolyBody      ,
                                            const CATPolyBodyCopierIndicesObserver * iSubdivSimplMap      ,
                                            const CATIPolyBodiesPositionMapping    * iPositionMapping     );
   ~CATPolyBodySimplifiedParamSubdivComputer();

   // --------------------------------------------------------
   // Information methods
   // --------------------------------------------------------
   void BeginFaceSubdivision(const CATPolyFace * iFace);
   void EndFaceSubdivision  (const CATPolyFace * iFace);

   // --------------------------------------------------------
   // Compute methods
   // --------------------------------------------------------
   HRESULT ComputePosition(const int                            iEVertexPrev   ,
                           const int                            iEVertex       ,
                           const int                            iEVertexNext   ,
                           const int                            iSVertexPrev   ,
                           const int                            iSVertex       ,
                           const int                            iSVertexNext   ,
                           const double                         iRatio         ,
                           const CATPolyEdge                  * iEdge          ,
                           const CATPolyFace                  * iFace          ,
                           CATIPolySurfaceVertexPositionLayer & ioPositionLayer);

   HRESULT ComputePosition(const int                            iSVertexPrev   ,
                           const int                            iSVertex       ,
                           const int                            iSVertexNext   ,
                           const double                         iRatio         ,
                           const CATPolyFace                  * iFace          ,
                           CATIPolySurfaceVertexPositionLayer & ioPositionLayer);

private:
   // --------------------------------------------------------
   // class (private)
   // --------------------------------------------------------
   class SubdivVertex;
   class SubdivVertexVertex;
   class SubdivVertexBar;
   class SubdivVertexTriangle;
   class SubdivEdgeVertex;

   // --------------------------------------------------------
   // Methods (private)
   // --------------------------------------------------------
   HRESULT InitPolyBodyCellMapping();
   HRESULT InitFaceVertexVertex(const CATPolyFace * iFace  ,
                                const int           iIdFace);

   HRESULT AddSubdivVertex    (const int             iVertexPrev,
                               const int             iVertex    ,
                               const int             iVertexNext,
                               const double          iRatio     ,
                               const int             iIdFace    ,
                                     SubdivVertex * & oSV       );

   HRESULT AddSubdivVertex    (const int                  iEVertexPrev,
                               const int                  iEVertex    ,
                               const int                  iEVertexNext,
                               const double               iRatio      ,
                               const int                  iIdEdge     ,
                                     SubdivEdgeVertex * & oSEV        );

   HRESULT CreateSubdivVertex (const SubdivVertexVertex   & iSVVPrev,
                               const SubdivVertexVertex   & iSVVNext,
                               const double                 iRatio  ,
                               const int                    iIdFace ,
                                     SubdivVertex       * & oSV     ) const;

   HRESULT CreateSubdivVertex (const SubdivVertexBar      & iSVVPrev,
                               const SubdivVertexBar      & iSVVNext,
                               const double                 iRatio  ,
                               const int                    iIdFace ,
                                     SubdivVertex       * & oSV     ) const;

   void    ComputeBaryCoord   (const SubdivVertexBar      & iSVB         ,
                               const int                    iIdT         ,
                               const CATIPolyMesh         & iSimplMesh   ,
                                     double                 oBaryCoord[3]) const;

   HRESULT ComputePosition    (const int                                  iSVertex       ,
                               const int                                  iIdEdge        ,
                               const int                                  iIdEVertexPrev ,
                               const double                               iRatio         ,
                               const int                                  iIdFace        ,
                                     CATIPolySurfaceVertexPositionLayer & ioPositionLayer) const;

   HRESULT ComputePosition    (const int                                  iSVertex       ,
                               const int                                  iIdFace        ,
                               const int                                  iIdTriangle    ,
                               const double                               iBaryCoord  [3],
                                     CATIPolySurfaceVertexPositionLayer & oPositionLayer ) const;

   HRESULT GetSimplPointInfo  (const SubdivVertex & iSV           ,
                               const int            iIdFace       ,
                                     int          & oIdTriangle   ,
                                     double         oBarCoord  [3]) const;

   // --------------------------------------------------------
   // Attributs (private)
   // --------------------------------------------------------
   // Input
   const CATPolyBody                                                       * m_subdivPolyBody ;
   const CATPolyBody                                                       * m_simplifPolyBody;
   const CATPolyBody                                                       * m_projPolyBody;
   const CATPolyBody                                                       * m_targetPolyBody;
   const CATIPolyBodiesPositionMapping                                     * m_positionMapping;

   // Map between subdiv poly body and the simplif one
         CATMapOfPtrToInt                                                    m_faceSubdivToIdSimpl;
         CATMapOfPtrToInt                                                    m_edgeSubdivToIdSimpl;
   const CATPolyBodyCopierIndicesObserver                                  * m_subdivSimplMap;

   // Current mesh modification
         std::vector<CATMapOfIntToPtr*>                                      m_faceToPoints;
         std::vector<CATMapOfIntToPtr >                                      m_edgeToPoints;
 mutable CATPolyBucketsCache<SubdivVertexVertex>                             m_meshVV;
 mutable CATPolyBucketsCache<SubdivVertexBar>                                m_meshVB;
 mutable CATPolyBucketsCache<SubdivVertexTriangle>                           m_meshVT;
 mutable CATPolyBucketsCache<SubdivEdgeVertex>                               m_edgeVB;

   // class status
         HRESULT                                                             m_status;
};


#endif

