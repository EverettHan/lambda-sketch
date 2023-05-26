//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyBarvertexDataComputer (Position Mapping)
//
//===================================================================
// 19/04/18 F1Z : Creation
// DD/MM/YY
//===================================================================

#ifndef CATPolyBodyBarVertexDataComputer_H
#define CATPolyBodyBarVertexDataComputer_H

// Polyhedral Interfaces
#include "CATPolyRefCounted.h"

// Polyhedral Body Operators
#include "PolyBodyRegularize.h"
#include "CATIPolyBodyBarCache.h"

class CATMathPoint;
class CATMathPoint2D;
class CATMathVector;
class CATMathVector2D;

template<typename>
class CATPolyBuckets;

class CATIPolySurfaceVertexPositionConstLayer;
class CATIPolySurfaceVertexNormalConstLayer;
class CATIPolySurfaceVertexUVConstLayer;
class CATIPolySurfaceVertexTextureCoordConstLayer;
class CATIPolyCurveVertexTangentConstLayer;
class CATIPolyCurveVertexWConstLayer;
class CATIPolyLayerIterator;

class CATPolyEdge;
class CATPolyFace;

class CATIPolyBodiesPositionMapping;
class CATPolyBodyTriangleVertexDataComputer;

// -----------------------------------------------------------------
// CATPolyBodyBarVertexDataComputer
// -----------------------------------------------------------------
class ExportedByPolyBodyRegularize CATPolyBodyBarVertexDataComputer : virtual public CATPolyRefCounted
{
public:
   CATPolyBodyBarVertexDataComputer(){};
   virtual ~CATPolyBodyBarVertexDataComputer(){};

   /**
   * Compute the position of the point on the bar
   * @param iBar
   * The bar support
   * @param iRatio
   * The ratio between the first and second vertex of the bar to defined where the point is
   * @param iFace
   * The face linked to iPosLayer (allowing to five a context for the computation)
   * @param iPosLayer
   * The position layer
   * @param oPoint
   * The position of the point on the bar
   * @return
   * @ S_OK, E_FAIL if there was an issue
   */
   virtual HRESULT CalculatePoint (const CATPolyBodyBarLight                          & iBar        ,
                                   const double                                         iRatio      ,
                                   const CATPolyFace                                  * iFace       ,
                                   const CATIPolySurfaceVertexPositionConstLayer      & iPosLayer   ,
                                         CATMathPoint                                 & oPoint      );

   virtual HRESULT CalculateNormal(const CATPolyBodyBarLight                          & iBar        ,
                                   const double                                         iRatio      ,
                                   const CATPolyFace                                  * iFace       ,
                                   const CATIPolySurfaceVertexNormalConstLayer        & iNormalLayer,
                                         CATMathVector                                & oNormal     );

   virtual HRESULT CalculateUV    (const CATPolyBodyBarLight                          & iBar        ,
                                   const double                                         iRatio      ,
                                   const CATPolyFace                                  * iFace       ,
                                   const CATIPolySurfaceVertexUVConstLayer            & iUVLayer    ,
                                         CATMathPoint2D                               & oUV         );

   virtual HRESULT CalculateTex   (const CATPolyBodyBarLight                          & iBar        ,
                                   const double                                         iRatio      ,
                                   const CATPolyFace                                  * iFace       ,
                                   const CATIPolySurfaceVertexTextureCoordConstLayer  & iTexLayer   ,
                                         CATMathPoint                                 & oTexCoord   ,
                                         CATMathVector                                & oTexTgt     ,
                                         CATMathVector                                & oTexBinormal);

   virtual HRESULT CalculateTgt   (const CATPolyBodyBarLight                          & iBar        ,
                                   const double                                         iRatio      ,
                                   const CATIPolyCurve                                * iCurve      ,
                                   const CATIPolyCurveVertexTangentConstLayer         & iTgtLayer   ,
                                         CATMathVector                                & oTgt        );

   virtual HRESULT CalculateW     (const CATPolyBodyBarLight                          & iBar        ,
                                   const double                                         iRatio      ,
                                   const CATIPolyCurve                                * iCurve      ,
                                   const CATIPolyCurveVertexWConstLayer               & iWLayer     ,
                                         double                                       & oW          );

   // Special methods for unknown data
   virtual HRESULT CalculateData  (const CATPolyBodyBarLight                          & iBar        ,
                                   const double                                         iRatio      ,
                                   const CATPolyFace                                  * iFace       ,
                                         CATIPolyLayerIterator                    & iDataLayer  ,
                                         CATPolyBuckets<void*>                        & ioData      );

   virtual HRESULT SetData        (      CATIPolyLayerIterator                    & iDataLayer  ,
                                   const int                                            iV          ,
                                         CATPolyBuckets<void*>                        & ioData      );

   virtual HRESULT Clean          (      CATPolyBuckets<void*>                        & ioData      );
};

// ========================================================================================== //
//                      CATPolyBodyBarVertexDataComputerPositionMapping                       //
// ========================================================================================== //
struct ExportedByPolyBodyRegularize CATPolyBodyBarVertexDataComputerPositionMapping
{
  enum Option
  {
    /** Bit 0: Position computed on the second poly body*/ ComputePosition_PM = 0x00001,
    /** Bit 1: Normal computed on the second poly body*/   ComputeNormal_PM   = 0x00002,
    /** Bit 2: UV computed on the second poly body*/       ComputeUV_PM       = 0x00004,
    /** Bit 3: Texture computed on the second poly body*/  ComputeTexture_PM  = 0x00008,
    /** Bit 4: Tangent computed on the second poly body*/  ComputeTangent_PM  = 0x00010,
    /** Bit 5: W computed on the second poly body*/        ComputeW_PM        = 0x00020,
    /** Bit 6: Data computed on the second poly body*/     ComputeData_PM     = 0x00040,
  };

  /**
  * @param iPositionMapping
  * The position mapping to map the current point on the second poly body
  * @param iOptions
  * Define which data has to be computed on the first or second poly body. If it is on the first,
  * it will use the provided iFirstPolyBodyCalculator or the mother class default implementation.
  * @param iFirstPolyBodyBarVertexCalculator
  * Calculator used if the computation is done on the first poly body. Default one is used if not set.
  * @param iSecondPolyBodyBarVertexCalculator
  * Calculator used if the vertex bar computation is done on the second poly body. Default one is used if not set.
  * @param iSecondPolyBody
  * Calculator used when the vertex triangle computation is done (always on second poly body). Default one is used if not set.
  * @return
  * The bar vertex computer
  */
  static CATPolyBodyBarVertexDataComputer * Create(CATIPolyBodiesPositionMapping         * iPositionMapping                                          ,
                                                   unsigned int                            iOptions                              = ComputePosition_PM,
                                                   CATPolyBodyBarVertexDataComputer      * iFirstPolyBodyBarVertexCalculator     = 0                 ,
                                                   CATPolyBodyBarVertexDataComputer      * iSecondPolyBodyBarVertexCalculator    = 0                 ,
                                                   CATPolyBodyTriangleVertexDataComputer * iSecondPolyBodyTriangleVertexComputer = 0                 );
};

#endif

