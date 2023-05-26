//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodySplitRefiner
//
//===================================================================
// 18/10/17 F1Z : Creation
// DD/MM/YY
//===================================================================
#ifndef CATPolyBodySplitRefiner_H
#define CATPolyBodySplitRefiner_H

// Polyhedral Interfaces
#include "CATPolyRefCounted.h"

// Polyhedral Mathematics
#include "CATEventQueue.h"
#include "CATPolyObserver.h"

// Polyhedral Objets
#include "CATPolyBody.h"

// Polyhedral Body Operators
#include "PolyBodyRegularize.h"
#include "CATIPolyBodyBarCache.h"

template<typename>
class CATPolyBuckets;

class CATIPolySurfaceVertexPositionConstLayer;
class CATIPolySurfaceVertexNormalConstLayer;
class CATIPolySurfaceVertexUVConstLayer;
class CATIPolySurfaceVertexTextureCoordConstLayer;
class CATMathPoint;
class CATMathVector;
class CATMathPoint2D;
class CATProgressCallback;
class CATPolyBodySplitRefinerAbstract;
class CATSetOfPtr;
class CATPolyBodyBarVertexDataComputer;

/**
* Global split refiner operator.
* It implements an algorithm to refine the bars of a CATPolyBody
* by splitting them until the bars properties is validated (ex: max length criterion).
*
* The convergence is not naturally ensured since it depends of the filters provided.
* Thus, the caller should check the filters provided can coexist to ensure a convergence
* of the operator.
*/
class ExportedByPolyBodyRegularize CATPolyBodySplitRefiner
{
public:
   // -----------------------------------------------------------------
   // Filter
   // -----------------------------------------------------------------
   class Filter;
   class BarDataManager;
   class CATPolyIsBarLocked;
   class Observer;

   // -----------------------------------------------------------------
   // Object Management
   // -----------------------------------------------------------------
   /**
   * General creation of the operator
   * @param iBarManager
   * The bar data manager class to handle and manipulate bar data
   * @param iFilter
   * The bar filter used by the operator to handle the eligibilty of a bar.
   * @param iSplitCalculator
   * The split calculator to update the vertex layers after a split.
   */
   CATPolyBodySplitRefiner(CATPolyBodySplitRefiner::BarDataManager    * iBarManager         ,
                           CATPolyBodySplitRefiner::Filter            * iFilter             ,
                           CATPolyBodyBarVertexDataComputer           * iSplitCalculator = 0);

   /**
   * Create a split refiner operator based on the bar length.
   * The operator will split the longest bars in priority until all the bars
   * have a length under the provided max length.
   * @param iMaxLength
   *   The maximum length an edge of the poly body result can have.
   * @param iMiddleSplit
   *   If set at TRUE, each split is performed at the bar middle point.
   *   Else, the split is performed such as the whole bar is split the less time possible. This break the mesh regularity but provides less triangles in non regular mesh.
   * @param iSplitCalculator
   *   An optional argument for the computation of the new properties of the layers of the vertex splitting a bar.
   */
   CATPolyBodySplitRefiner(double                              iMaxBarLength          ,
                           bool                                iMiddleSplit     = true,
                           CATPolyBodyBarVertexDataComputer  * iSplitCalculator = 0   );

   ~CATPolyBodySplitRefiner();

   // -----------------------------------------------------------------
   // Progress information
   // -----------------------------------------------------------------
   void SetProgressCallback(CATProgressCallback * iProgress);

   // -----------------------------------------------------------------
   // Filter
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

   // -----------------------------------------------------------------
   // Observer
   // -----------------------------------------------------------------
   /**
    * Register a new observer to the operator
    * @param iObserver
    *  The observer to be registered
    */
   void RegisterObserver(Observer * iObserver);

   /**
    * Unregister the observer from the operator
    * @param iObserver
    *  The observer to unregister
    */
   void UnregisterObserver(Observer * iObserver);

   // -----------------------------------------------------------------
   // Run
   // -----------------------------------------------------------------
   /**
   * Refines the bars of the provided CATPolyBody
   * The operator start with iInitBars content and not all the eligible bars
   * The filters set on the operator will manage if the new impacted bar will be treated or not
   * @param iPolyBody
   *  The CATPolyBody
   * @return
   *  <tt>S_OK</tt> if the impacted bars were refined.
   */
   HRESULT Run(CATPolyBody          & iPolyBody    ,
               CATIPolyBodyBarCache * iInitBars = 0);

private:

   CATPolyBodySplitRefinerAbstract * _Operator;
};

// ===================================================================== //
/**
* Class to have access to all the operator filter IsBarLocked method.
*/
class ExportedByPolyBodyRegularize CATPolyBodySplitRefiner::CATPolyIsBarLocked
{
public:
  CATPolyIsBarLocked(){};
  virtual ~CATPolyIsBarLocked(){};
  virtual bool operator()(const CATIPolyBodyBarCache::Bar_Data & iBar) { return false; };
};

// ===================================================================== //
/**
* Class to determine if a bar is eligible for splitting.
*/
class ExportedByPolyBodyRegularize CATPolyBodySplitRefiner::Filter : public CATIPolyBodyBarCache::BarFilter
{
public:
  Filter() : CATIPolyBodyBarCache::BarFilter() {};
  virtual ~Filter(){};

  // -----------------------------------------------------------------
  // Basic filters
  // -----------------------------------------------------------------
  /**
  * Filter which allow all the bar which length is above the iMinLength provided
  * to be refined.
  * @iMinLength
  *  The min length on an eligible bar to be refined.
  * @return
  *  The filter
  */
  static Filter * CreateLengthFilter   (const double        iMinLength );

  /**
  * Filter which allow the bar to be split if the impacted vertices valence
  * is below the iMaxValence provided.
  * @param iMaxValence
  *  The max valence allowed
  * @return
  *  The filter
  */
  static Filter * CreateValenceFilter  (const int           iMaxValence);

  /**
  * Filter which allow a bar to be split if to belong (or not) to the provided faces
  * @param iFaces
  *  The list of faces to allow the bar refinement or not
  * @param iAreLocked
  *  true if the list of faces represents the locked faces, false otherwise
  * @return
  *  The filter.
  */
  static Filter * CreateFacesLockFilter(const CATSetOfPtr & iFaces     ,
                                        const bool          iAreLocked);

  /**
  * Filter which allow a bar to be refined if the new created triangle angle
  * are higher than the iMinAngle provided.
  * @param iMinAngle
  *  The min angle to allow a bar split
  * @retrun
  *  The filter.
  */
  static Filter * CreateAngleLockFilter(const double        iMinAngle  );

  // -----------------------------------------------------------------
  // Interface
  // -----------------------------------------------------------------
  /**
  * Check if a bar is eligible to process
  * @param iBar
  *  The bar to check
  * @param iIsBarLocked
  *  The function to call all the operator filters to check if a bar is locked or not
  * @param iToRemove
  *  If provided, set at true if the not eligible iBar should be removed from the active bar, false otherwise.
  * @return
  *  true if the iBar is eligible, false otherwise.
  */
  virtual bool IsEligibleBarToProcess (const CATIPolyBodyBarCache::Bar_Data                & iBar            ,
                                             CATPolyBodySplitRefiner::CATPolyIsBarLocked   & iIsBarLocked    ,
                                             bool                                        *   iToRemove    = 0) = 0;

  /**
  * Check if the provided bar is locked for any change (split here)
  * @param iBar
  *  The bar to check
  * @return
  *  true if the bar is locked, false otherwise
  */
  virtual bool IsBarLocked(const CATIPolyBodyBarCache::Bar_Data & iBar) { return false; };
};

// ===================================================================== //

/**
* Class to define and manipulate the bar data
*/
class ExportedByPolyBodyRegularize CATPolyBodySplitRefiner::BarDataManager : public CATIPolyBodyBarCache::BarDataManager
{
public:
  BarDataManager(){};
  virtual ~BarDataManager(){};

  /**
  * Compute the best ratio where the bar should be splitted
  * @param iBar
  *  The bar which is going to be splitted
  * @return
  *  The ratio (between [0,1]) where the bar should be splitted.
  */
  virtual double ComputeBestSplitRatio  (const CATIPolyBodyBarCache::Bar_Data & iBar) const { return 0.5; };

  /**
  * Call made to know if a split can affect already active bar data.
  * @return
  *  true if it can affect already active bar data, false otherwise
  */
  virtual bool IsUpdateRequired() { return FALSE; };

  /**
  * Call made to update the data of the active bar after a split
  * @param iBarSplitter
  *  The bar splitted
  * @param iIdNewVertex
  *  The id of the new vertex
  * @param ioBarCache
  *  The cache of active bar
  * @return
  *  HRESULT
  */
  virtual HRESULT UpdateActiveBar(const CATIPolyBodyBarCache::Bar_Data & iBarSplitter,
                                  const int                              iIdNewVertex,
                                        CATIPolyBodyBarCache           & ioBarCache  ) { return S_OK; };

  /**
  * Find the eligible priority bar based on the highest eligible bar
  * @param ioIte
  *  The iterator of the priority bar. It'll be updated to the eligible bar
  * @param
  *  The filter to check if the bar is eligible or not (this filter is encapsulating all the filter provided to the operator).
  * @return
  *  The eligible bar (0 if none was found).
  */
  virtual CATIPolyBodyBarCache::Bar_Data * FindPriorityBar(CATEventQueue::Iterator         & ioIte  ,
                                                           CATPolyBodySplitRefiner::Filter & iFilter)
  {
    return (ioIte.End())? 0 : (CATIPolyBodyBarCache::Bar_Data*) ioIte.GetElement();
  };
};

// ===================================================================== //
/**
* Class to observer the operator
*/
class ExportedByPolyBodyRegularize CATPolyBodySplitRefiner::Observer : public CATPolyObserver<CATPolyBodySplitRefiner::Observer>
{
public:
  Observer(){};
  virtual ~Observer(){};

  /**
   * Call before the split operation
   * iBarToSplit is going to be splitted by the operator and wont exist anymore
   */
  virtual HRESULT PrepareToSplitBar(const CATIPolyBodyBarCache::Bar_Data & iBarToSplit) { return S_OK; };

  /**
   * Call after a split operation
   * iBarSplit is not valid anymore
   * iNewBars are the bars created by the split operations. No filter is applied yet
   */
  virtual HRESULT ReactToSplitBar(const CATIPolyBodyBarCache::Bar_Data                 & iBarSplit,
                                  const std::vector<CATIPolyBodyBarCache::Bar_Data * > & iNewBars ) { return S_OK; };
};

#endif
