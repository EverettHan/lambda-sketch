//==============================================================================
// COPYRIGHT Dassault Systemes 2018
//==============================================================================
//
//  CATPolyBodySimplifiedParametrisationOperator.h
// Header definition of CATPolyBodySimplifiedParametrisationOperator
//
//==============================================================================
//
// Usage notes:
//   Creation of a decimated poly body which maps to the provided one at any point,
//   thus creating a parametrisation of this last.
//   This parametrisation is provided by the returned CATIPolyBodiesPositionMapping.
//
//   The polyBodyInitProj is a copy of the original poly body provided projected
//   to the decimated one.
//   The polyBodyInitClone is a copy of the original poly body with the same indices
//   with the polyBodyInitProj.
//   The mapping is thus ensured thanks to these two previous polyBody.
//
//==============================================================================
// 05/01/18 F1Z : Creation (To replace CATPolyBodySimplfyOperator made by DR)
// DD/MM/YY
//==============================================================================

#ifndef CATPolyBodySimplifiedParametrisationOperator_H
#define CATPolyBodySimplifiedParametrisationOperator_H

// Polyhedral Body Operators
#include "PolyBodyRemeshing.h"

class CATMapOfPtrToPtr;
class CATPolyBody;
class CATIPolyBodySimplifiedParametrisationOperatorImpl;
class CATIPolyBodiesPositionMapping;

class ExportedByPolyBodyRemeshing CATPolyBodySimplifiedParametrisationOperator
{
public:
   // -----------------------------------------------------------
   // Object management
   // -----------------------------------------------------------
   CATPolyBodySimplifiedParametrisationOperator (const CATPolyBody * iPolyBody);
   ~CATPolyBodySimplifiedParametrisationOperator();

   // -----------------------------------------------------------
   // Options
   // -----------------------------------------------------------

   // -----------------------------------------------------------
   // Run
   // -----------------------------------------------------------
   /**
   * Run the Operator on the provided poly body.
   * @return
   * The run status.
   */
   HRESULT Run();

   // -----------------------------------------------------------
   // Ouput
   // -----------------------------------------------------------

   /**
   * Retrieve the cell map between the original poly body and the simplified result
   * @param oCellMap
   * The cell map.
   **/
   HRESULT GetCellMap(CATMapOfPtrToPtr * & oCellMap) const;

   /**
   * Retrieve the simplified poly body
   * @param oPolyBodySimplified
   * The decimated poly body
   */
   HRESULT GetSimplifiedPolyBody(CATPolyBody * & oPolyBodySimplified) const;

   /**
   * Retrieve the projection of the copy of the original poly body provided
   * projected on the simplified one.
   * @oPolyBodyInitProj
   * The projected poly body on the simplified one.
   */
   HRESULT GetProjectionPolyBody(CATPolyBody * & oPolyBodyInitProj  ) const;

   /**
   * Retrieve the copy of the original one, sharing common indices
   * with the projection one.
   * @param oPolyBodyInitClone
   * The clone of the init poly body with common indices with the projected one.
   */
   HRESULT GetInitClonePolyBody (CATPolyBody * & oPolyBodyInitClone ) const;

   /**
   * Retrieve the position mapping function between the decim poly body and the proj one.
   * @param oPositionMapping
   * The position mapping function between the decim poly body and the proj one. <br/>
   * The addref is performed during the call, thus the caller has to release it after its use.
   */
   HRESULT GetPositionMapping(CATIPolyBodiesPositionMapping * & oPositionMapping) const;

private:
   // -----------------------------------------------------------
   // Attributs (private)
   // -----------------------------------------------------------
   CATIPolyBodySimplifiedParametrisationOperatorImpl * _SimplifiedOperatorImpl;
};

#endif

