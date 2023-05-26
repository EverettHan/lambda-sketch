//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyTriangleVertexDataComputer
//
//===================================================================
// 17/04/18 F1Z : Creation
// DD/MM/YY
//===================================================================
// TODO:
// Expose an interface to perform the data computation.
//===================================================================

#ifndef CATPolyBodyTriangleVertexDataComputer_H
#define CATPolyBodyTriangleVertexDataComputer_H

// Polyhedral Interfaces
#include "CATPolyRefCounted.h"

// Polyhedral Body Operators
#include "PolyBodyRegularize.h"

// Others
class CATMathPoint;
class CATMathVector;
class CATMathPoint2D;

template<typename>
class CATPolyBuckets;

class CATIPolyMesh;
class CATIPolySurfaceVertexPositionConstLayer;
class CATIPolySurfaceVertexNormalConstLayer;
class CATIPolySurfaceVertexUVConstLayer;
class CATIPolySurfaceVertexTextureCoordConstLayer;
class CATIPolyLayerIterator;

class CATPolyFace;

// ======================================================================================= //
//                          CATPolyBodyTriangleVertexDataComputer                          //
// ======================================================================================= //
class ExportedByPolyBodyRegularize CATPolyBodyTriangleVertexDataComputer : virtual public CATPolyRefCounted
{
public:
  // -----------------------------------------------------------------
  // Object Management
  // -----------------------------------------------------------------
  CATPolyBodyTriangleVertexDataComputer() {};
  virtual ~CATPolyBodyTriangleVertexDataComputer() {};

  // -----------------------------------------------------------------
  // Methods
  // -----------------------------------------------------------------
  virtual HRESULT ComputePoint  (const CATPolyFace                                  *   iFace        ,
                                 const CATIPolyMesh                                 *   iMesh        ,
                                 const int                                              iIdTriangle  ,
                                 const double                                           iBaryCoord[3],
                                 const CATIPolySurfaceVertexPositionConstLayer        & iPosLayer    ,
                                       CATMathPoint                                   & oPoint       );

   virtual HRESULT ComputeNormal(const CATPolyFace                                  *   iFace        ,
                                 const CATIPolyMesh                                 *   iMesh        ,
                                 const int                                              iIdTriangle  ,
                                 const double                                           iBaryCoord[3],
                                 const CATIPolySurfaceVertexNormalConstLayer          & iNormalLayer ,
                                       CATMathVector                                  & oNormal      );

   virtual HRESULT ComputeUV    (const CATPolyFace                                  *   iFace        ,
                                 const CATIPolyMesh                                 *   iMesh        ,
                                 const int                                              iIdTriangle  ,
                                 const double                                           iBaryCoord[3],
                                 const CATIPolySurfaceVertexUVConstLayer              & iUVLayer     ,
                                       CATMathPoint2D                                 & oUV          );

   virtual HRESULT ComputeTex   (const CATPolyFace                                  *   iFace        ,
                                 const CATIPolyMesh                                 *   iMesh        ,
                                 const int                                              iIdTriangle  ,
                                 const double                                           iBaryCoord[3],
                                 const CATIPolySurfaceVertexTextureCoordConstLayer    & iTexLayer    ,
                                       CATMathPoint                                   & oTexCoord    ,
                                       CATMathVector                                  & oTexTgt      ,
                                       CATMathVector                                  & oTexBinormal );

   // Special methods for unknown data
   virtual HRESULT ComputeData  (const CATPolyFace                                  *   iFace        ,
                                 const CATIPolyMesh                                 *   iMesh        ,
                                 const int                                              iIdTriangle  ,
                                 const double                                           iBaryCoord[3],
                                       CATIPolyLayerIterator                      & iDataLayerIterator  ,
                                       CATPolyBuckets<void*>                          & ioData      );

   virtual HRESULT SetData      (      CATIPolyLayerIterator                      & iDataLayerIterator  ,
                                 const int                                              iV          ,
                                       CATPolyBuckets<void*>                          & ioData      );

   virtual HRESULT Clean        (      CATPolyBuckets<void*>                          & ioData      );

};

#endif

