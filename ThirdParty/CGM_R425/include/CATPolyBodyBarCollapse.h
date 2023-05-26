//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyBarCollapse
//
//===================================================================
// 05/03/18 F1Z : Creation
// DD/MM/YY
//===================================================================
#pragma once

// SpecialAPI
#include "CATBoolean.h"

// Polyhedral Mathematics
#include "CATPolyRefCounted.h"

// Polyhedral Objets
#include "CATPolyBody.h"

// Polyhedral Body Operators
#include "PolyBodyRegularize.h"
#include "CATIPolyBodyBarCache.h"

// std
#include <functional>

class CATPolyBodyBarCollapseImp;
class CATPolyCell;
class CATPolyBodyNewVerticesObserver;
class CATProgressCallback;
class CATPolyBodyBarVertexDataComputer;
class CATMathPoint;

// ===========================================================
// Enum declaration
// ===========================================================
struct CollapseMode
{
   enum Mode {Generic   ,
              MinLength ,
              QM_Chordal};
};

// ===========================================================
// Option declaration
// ===========================================================
template<CollapseMode::Mode M>
struct CollapseInput {};

/**
 * General creation of the operator
 * @param iBarDataManager
 *  The bar data manager to handle the content of the bar._Data attributs and define the priority.
 * @param iFilter
 *  A filter to constraint the bar to collapse.
 * @param iBarVertexComputer
 *  Compute the new position after a collapse.
*/
template<>
struct CollapseInput<CollapseMode::Generic>
{
  CollapseInput(CATIPolyBodyBarCache::BarDataManager * iBarDataManager       ,
                CATPolyBodyBarVertexDataComputer     * iBarVertexComputer = 0)
               : m_barDataManager   (iBarDataManager   ),
                 m_barVertexComputer(iBarVertexComputer) {};

  CATIPolyBodyBarCache::BarDataManager * m_barDataManager;
  CATPolyBodyBarVertexDataComputer     * m_barVertexComputer;
};

/**
 * Remove all the bar under the provided length if possible.
 * @param iMinLength
 *  The min length
 * @param iBarVertexComputer
 *  Compute the new position after a collapse.
*/
template<>
struct CollapseInput<CollapseMode::MinLength>
{
  CollapseInput(const double                             iMinLength            ,
                      CATPolyBodyBarVertexDataComputer * iBarVertexComputer = 0)
              : m_minLength        (iMinLength        ),
                m_barVertexComputer(iBarVertexComputer){};

  const double                             m_minLength;
        CATPolyBodyBarVertexDataComputer * m_barVertexComputer;
};

/**
 * Remove all the bar with a chordal deviation lower than the one provided
 * @param iMaxChordalDeviation
 *  The maximum error distance
 * @param iPolyBody
 *  The poly body on which the run will be make
 */
template<>
struct CollapseInput<CollapseMode::QM_Chordal>
{
  CollapseInput(const double        iMaxChordalDeviation,
                      CATPolyBody * iPolyBody          )
              : m_chordalDist(iMaxChordalDeviation),
                m_polyBody   (iPolyBody           ){};

  const double        m_chordalDist;
        CATPolyBody * m_polyBody   ;
};

// ===========================================================
// CATPolyBodyBarCollapse
// ===========================================================

/**
* Operator to perform a global edge collapse
* based on the provided filters criterium.
*
* Default constraint only allow to keep the poly body topo structure.
* Additionnal filter are required to constraint the decimation (deformation, minLength etc...)
*/
class ExportedByPolyBodyRegularize CATPolyBodyBarCollapse
{
public:
   // -----------------------------------------------------------------
   // Classes
   // -----------------------------------------------------------------
   class  Filter;
   struct QMData;

   // -----------------------------------------------------------------
   // Object Management
   // -----------------------------------------------------------------
   template<CollapseMode::Mode M>
   CATPolyBodyBarCollapse(const CollapseInput<M> & iInput);
   ~CATPolyBodyBarCollapse();

   // -----------------------------------------------------------------
   // Options
   // -----------------------------------------------------------------
   /**
   * Add a new filter to the operator
   * @param iFilter
   *  The filter to add.
   */
   void AddFilter   (Filter * iFilter);

   /**
   * Remove the filter from the operator
   * @param iFilter
   *  The ptr of the filter to remove.
   */
   void RemoveFilter(Filter * iFilter);

   /**
   * Add a filter to ensure valid geometry with low deformation
   * @param iMaxRelativeNormalAngle
   *   The maximum relative normal angle fluctuation before and after a collapse
   * @param iMaxRelativeBarAngle
   *   The maximum relative normal angle between the two triangles of a mesh bar
   *   to allow the collapsing of the bar.
   * @param iMinTriangleAngle (optional)
   *   The min angle a triangle can have after a collapse. It help to prevent degenerate triangle.
   */
   void AddGeoFilter(const double iMaxRelativeNormalAngle   ,
                     const double iMaxRelativeBarAngle      ,
                     const double iMinTriangleAngle      = 0);

   // -----------------------------------------------------------------
   // Progress information
   // -----------------------------------------------------------------
   void SetProgressCallback(CATProgressCallback * iProgress);

   // -----------------------------------------------------------------
   // Methods - Independant of the run
   // -----------------------------------------------------------------
   class CATIPolyComputeBarCollapseProperties;
   /**
    * Return the method to compute the bar collapse properties
    * It depends only on the topology, filters and the bar vertex computer
    * @return
    *  The method. It should be released after use.
    */
   CATIPolyComputeBarCollapseProperties * GetBarCollapsePropertiesComputer();

   // -----------------------------------------------------------------
   // Run
   // -----------------------------------------------------------------
   /**
   * Collapse the bar of the provided poly body.
   * @param iPolyBody
   *   The CATPolyBody.
   * @param iBarCache
   *  The operators is initialized with the bar in iBarCache if eligible
   * @return
   *   <tt>S_OK</tt> if no issue were encountered.
   */
   HRESULT Run (CATPolyBody          & ioPolyBody   ,
                CATIPolyBodyBarCache * iInitBars = 0);

private:
   CATPolyBodyBarCollapseImp * m_op;
};

// ===================================================================== //

class ExportedByPolyBodyRegularize CATPolyBodyBarCollapse::Filter : virtual public CATPolyRefCounted
{
public:
   Filter(){};
   virtual ~Filter(){};

   // -----------------------------------------------------------------
   // Basic Filters
   // -----------------------------------------------------------------
   /**
   * Create a filter to ensure valid geometry with low deformation
   * @param iMaxRelativeNormalAngle
   *   The maximum relative normal angle fluctuation before and after a collapse
   * @param iMaxRelativeBarAngle
   *   The maximum relative normal angle between the two triangles of a mesh bar
   *   to allow the collapsing of the bar.
   * @param iMinTriangleAngle (optional)
   *   The min angle a triangle can have after a collapse. It help to prevent degenerate triangle.
   * @return
   *  The filter ptr.
   */
   static Filter * CreateGeoFilter(const double iMaxRelativeNormalAngle   ,
                                   const double iMaxRelativeBarAngle      ,
                                   const double iMinTriangleAngle      = 0);

   /**
   * Create a filter to lock the new vertices set in iNewVerticesObserver
   * @param iPolyBody
   *  The poly body to decimate
   * @param iNewVerticesObserver
   *  The new vertices observer
   * @return
   *  The filter ptr.
   */
   static Filter * CreateLockVerticesFilter(const CATPolyBody                    * iPolyBody           ,
                                                  CATPolyBodyNewVerticesObserver * iNewVerticesObserver);

   // -----------------------------------------------------------------
   // Filter interfaces
   // -----------------------------------------------------------------
   /**
   * Check if a bar can be a futur candidate for collapsing
   * @param iBar
   *  The poly body bar information
   * @return
   *  true is the bar is a futur potential candidate, false otherwise.
   */
   virtual bool IsAFuturCandidate(const CATIPolyBodyBarCache::Bar_Data & iBar) { return true; };

   /**
   * Check if a bar can be collapsed at this given moment
   * @param iBar
   *  The poly body bar information
   * @param iIsFirstToKeep
   *  Set at true, it means the poly body will keep the iBar._id0 vertex for the merge.
   * @param iRatio
   *  Return the ratio between [0,1] where the remaining point will stay after the merge.
   * @param iNewPosition
   *  The position in 3D of the remaining point after the collapse phase.
   * @return
   *  true if the bar can be collapsed, false otherwise.
   */
   virtual bool IsEligibleBarToCollapse(const CATIPolyBodyBarCache::Bar_Data & iBar          ,
                                        const bool                             iIsFirstToKeep,
                                        const double                           iRatio        ,
                                        const CATMathPoint                   & iNewPosition  ) { return true; };

   /**
   * Check if a bar is locked and should remained untouched.
   * @param iBar
   *  The poly body bar information
   * @return
   *  true if the bar is locked, false otherwise.
   */
   virtual bool IsBarLock              (const CATIPolyBodyBarCache::Bar_Data & iBar          ) { return false; };

   /**
   * Check if a vertex is locked and should remained untouched
   * @param iIdVertex
   *  The id of the vertex on iCellSupport
   * @param iCellSupport
   *  The lowest topology on which the point relies.
   * @return
   *   true if the vertex is locked, false otherwise.
   */
   virtual bool IsVertexLock           (const int                              iIdVertex     ,
                                        const CATPolyCell                    & iCellSupport  ) { return false; };
};

// ===================================================================== //

class CATPolyBodyBarCollapse::CATIPolyComputeBarCollapseProperties : public CATPolyRefCounted
{
public:
  CATIPolyComputeBarCollapseProperties(){};
  virtual ~CATIPolyComputeBarCollapseProperties(){};
  
  virtual bool operator()(const CATIPolyBodyBarCache::Bar_Data & iBar          ,
                                bool                           & oIsFirstToKeep,
                                double                         & oRatio        ,
                                bool                           & oIsEligible   ,
                                CATMathPoint                   & oNewPosition  ) = 0;
};

// ===================================================================== //
/**
 * Struct used by the bar data manager for QM case
 */
struct ExportedByPolyBodyRegularize CATPolyBodyBarCollapse::QMData
{
  double _sqLength;
  double _coef;
};
