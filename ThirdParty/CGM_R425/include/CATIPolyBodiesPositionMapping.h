//==============================================================================
// COPYRIGHT Dassault Systemes 2018
//==============================================================================
//
//  CATIPolyBodiesPositionMapping.h
// Header definition of CATIPolyBodiesPositionMapping
//
//==============================================================================
//
// Usage notes:
//   Class defining the mapping between two CATPolyBody with the same topology,
//   so any point on a poly body corresponds to a unique point on the other poly body.
//
//   In case the mapping is not a bijection, the evaluation return E_FAIL if
//   the mapping is not possible in this way.
//
//==============================================================================
// 15/02/18 F1Z : Creation
// DD/MM/YY
//==============================================================================

#ifndef CATIPolyBodiesPositionMapping_H
#define CATIPolyBodiesPositionMapping_H

// Polyhedral Interfaces
#include "CATPolyRefCounted.h"

// Polyhedral Objects
#include "CATPolyBody.h"

// Polyhedral Body Operators
#include "PolyBodyRemeshing.h"

// Others

// ======================================================================================== //
//                              CATIPolyBodiesPositionMapping                               //
// ======================================================================================== //
class ExportedByPolyBodyRemeshing CATIPolyBodiesPositionMapping : public CATPolyRefCounted
{
public:
   // -----------------------------------------------------------
   // Class
   // -----------------------------------------------------------
   class PolyEdgePoint;
   class PolyMeshPoint;

   // -----------------------------------------------------------
   // Object management
   // -----------------------------------------------------------
   virtual ~CATIPolyBodiesPositionMapping(){};

   // -----------------------------------------------------------
   // Get
   // -----------------------------------------------------------
   virtual const CATPolyBody * GetFirstPolyBody ()                    const = 0;
   virtual const CATPolyBody * GetSecondPolyBody()                    const = 0;
   virtual const bool          DoesMapFirstPolyBodyToSecondPolyBody() const = 0;
   virtual const bool          DoesMapSecondPolyBodyToFirstPolyBody() const = 0;

   // -----------------------------------------------------------
   // Eval
   // -----------------------------------------------------------
   /**
   * @param iPoint
   * The poly mesh point information on iPolyBody
   * @param iPolyBody
   * The poly body where the point lies
   * @param oPoint
   * The corresponding mesh point on the other mesh
   */
   virtual HRESULT Eval(const PolyMeshPoint   & iPoint   ,
                        const CATPolyBody   *   iPolyBody,
                              PolyMeshPoint   & oPoint   ) const = 0;

   /**
   * @param iPoint
   * The poly edge point information on iPolyBody
   * @param iPolyBody
   * The poly body where the point lies
   * @param oPoint
   * The corresponding edge point on the other edge
   */
   virtual HRESULT Eval(const PolyEdgePoint   & iPoint   ,
                        const CATPolyBody   *   iPolyBody,
                              PolyEdgePoint   & oPoint   ) const = 0;

protected:
   // -----------------------------------------------------------
   // Object management (protected)
   // -----------------------------------------------------------
   CATIPolyBodiesPositionMapping(){};
};

// ======================================================================================== //
//                                          Create                                          //
// ======================================================================================== //
ExportedByPolyBodyRemeshing CATIPolyBodiesPositionMapping * CreatePolyBodiesPositionMappingProjection(      CATPolyBody * iPolyBody         ,
                                                                                                      const CATPolyBody * iSupportPolyBody  ,
                                                                                                      const double        iResLengthTest    ,
                                                                                                      const double        iEpsgForLengthTest);

// ======================================================================================== //
//                                       PolyEdgePoint                                      //
// ======================================================================================== //
class ExportedByPolyBodyRemeshing CATIPolyBodiesPositionMapping::PolyEdgePoint
{
public:
  PolyEdgePoint() : _IdEdge(0), _IdPrevEdgeVertex(0), _Ratio(0) {};
  PolyEdgePoint(int    iIdEdge          ,
                int    iIdPrevEdgeVertex,
                double iRatio           )
  {
    _IdEdge           = iIdEdge;
    _IdPrevEdgeVertex = iIdPrevEdgeVertex;
    _Ratio            = iRatio;
  }
  ~PolyEdgePoint(){};

  int    _IdEdge;
  int    _IdPrevEdgeVertex;
  double _Ratio;
};

// ======================================================================================== //
//                                       PolyMeshPoint                                      //
// ======================================================================================== //
class ExportedByPolyBodyRemeshing CATIPolyBodiesPositionMapping::PolyMeshPoint
{
public:
  PolyMeshPoint() : _IdFace(0), _IdTriangle(0) {};
  PolyMeshPoint(int    iIdFace       ,
                int    iIdTriangle   ,
                double iBaryCoord [3])
  {
    _IdFace       = iIdFace;
    _IdTriangle   = iIdTriangle;
    _BaryCoord[0] = iBaryCoord[0];
    _BaryCoord[1] = iBaryCoord[1];
    _BaryCoord[2] = iBaryCoord[2];
  }
  ~PolyMeshPoint(){};

  int    _IdFace       ;
  int    _IdTriangle   ;
  double _BaryCoord [3];
};

#endif

