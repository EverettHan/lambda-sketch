//==============================================================================
// COPYRIGHT Dassault Systemes 2017
//==============================================================================
//
//  CATPolyBodySurfaceSubdivision.h
// Header definition of CATPolyBodySurfaceSubdivision
//
//==============================================================================
//
// Usage notes:
//   Subdivision applied on the surface of CATPolyBody
//
//==============================================================================
// 14/12/17 F1Z : Creation
// 26/02/18 F1Z : Add enum to make clear difference between the mode and creator signature
// DD/MM/YY
//==============================================================================

#ifndef CATPolyBodySurfaceSubdivision_H
#define CATPolyBodySurfaceSubdivision_H

// Polyhedral Body Operators
#include "PolyBodyRegularize.h"
#include "CATPolyBodySplitRefiner.h"
#include "CATPolyBodyMeshLoopSubdivision.h"

class CATPolyBody;
class CATIPolyBodySurfaceSubdivisionImpl;
class CATPolyBodyBarVertexDataComputer;

// ===========================================================
// Enum declaration
// ===========================================================
struct SubdivMode
{
   enum Mode {Loop             ,
              BisectorMaxLength,
              BisectorGeneric  };
};

// ===========================================================
// Option declaration
// ===========================================================
template<SubdivMode::Mode M>
struct SubdivInput {};

/**
* Simple loop subdivision. Each triangle is divided in 4 triangles. <br/>
* Thanks to the natural conformity of the poly body edges results, this subdivision is very efficient,
* even though it exponentially increases the number of triangles.
* @param iSubdivisionDepth
* The number of time the subdivision is applied. The final number of triangle from a poly body with N triangle is N^(iSubdivisionDepth)
*/
template<>
struct SubdivInput<SubdivMode::Loop>
{
   template<typename T>
   SubdivInput(T                                                         iSubdivisionDepth    ,
               CATPolyBodyMeshLoopSubdivision::SubdivMeshLayerComputer * iSubdivComputer   = 0)
              : m_subdivisionDepth(iSubdivisionDepth),
                m_subdivComputer  (iSubdivComputer  ) {};

   int                                                       m_subdivisionDepth;
   CATPolyBodyMeshLoopSubdivision::SubdivMeshLayerComputer * m_subdivComputer  ;
};

/**
* Bisector subdivision. For more information, refer to the CATPolyBodySplitRefiner.
* @param iMaxLength
* The maximum bar length after the bisection in the CATPolyBody provided.
*/
template<>
struct SubdivInput<SubdivMode::BisectorMaxLength>
{
   SubdivInput(const double                             iMaxLength             ,
               const bool                               iMiddleSplit     = true,
                     CATPolyBodyBarVertexDataComputer * iSplitCalculator = 0   ) : m_maxLength      (iMaxLength      ),
                                                                                   m_middleSplit    (iMiddleSplit    ),
                                                                                   m_splitCalculator(iSplitCalculator) {};

   double                             m_maxLength      ;
   bool                               m_middleSplit    ;
   CATPolyBodyBarVertexDataComputer * m_splitCalculator;
};

/**
* General creation of the bisector subdivision.
* @param iBarManager
* The bar data manager class to handle and manipulate bar data
* @param iFilter
* The bar filter used by the operator to handle the eligibilty of a bar.
* @param iSplitCalculator
* The split calculator to update the vertex layers after a split.
*/
template<>
struct SubdivInput<SubdivMode::BisectorGeneric>
{
   SubdivInput(CATPolyBodySplitRefiner::BarDataManager * iBarDataManager ,
               CATPolyBodySplitRefiner::Filter         * iBarFilter      ,
               CATPolyBodyBarVertexDataComputer        * iSplitCalculator) : m_barDataManager (iBarDataManager),
                                                                             m_barFilter      (iBarFilter),
                                                                             m_splitCalculator(iSplitCalculator) {};

   CATPolyBodySplitRefiner::BarDataManager * m_barDataManager;
   CATPolyBodySplitRefiner::Filter         * m_barFilter;
   CATPolyBodyBarVertexDataComputer        * m_splitCalculator;
};

// ===========================================================
// CATPolyBodySurfaceSubdivision
// ===========================================================
/**
* Operator that do the subdivision of the surface of a CATPolyBody.
*/
class ExportedByPolyBodyRegularize CATPolyBodySurfaceSubdivision
{
public:
   // -----------------------------------------------------------
   // Object management
   // -----------------------------------------------------------
   template<SubdivMode::Mode M>
   CATPolyBodySurfaceSubdivision(const SubdivInput<M> & iInput);


   virtual ~CATPolyBodySurfaceSubdivision();

public :
   /**
   * Run the Operator on the provided ioPolyBody.
   * @param ioPolyBody
   * The poly body to subdivide.
   */
   HRESULT Run(CATPolyBody & ioPolyBody);

private:

   // -----------------------------------------------------------
   // Attributs (private)
   // -----------------------------------------------------------
   CATIPolyBodySurfaceSubdivisionImpl * _SubdivisionOperatorImpl;
};


#endif
