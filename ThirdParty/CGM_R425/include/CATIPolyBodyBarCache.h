//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyBodyBarCache
//
//===================================================================
// 19/10/17 F1Z : Creation
// DD/MM/YY
//===================================================================
#ifndef CATIPolyBodyBarCache_H
#define CATIPolyBodyBarCache_H

// Special API
#include "CATSysErrorDef.h"

// Polyhedral Mathematics
#include "CATPolyRefCounted.h"
#include "CATPolyActiveCacheObserver.h"

// Polyhedral Body Operators
#include "PolyBodyRegularize.h"

class CATIPolyCurve;
class CATPolyFace;
class CATPolyEdge;
class CATPolyCell;

/**
* A bar definition from the CATPolyBody, defined by:
 * <ul>
 *   <li> The bars extremities vertex id
 *   <li> The associate cell (on which the id are associated)
 * </ul>
*/
struct ExportedByPolyBodyRegularize CATPolyBodyBarLight
{
  CATPolyBodyBarLight();
  CATPolyBodyBarLight(int id0, int id1, CATPolyCell * cell);

   int _id0;
   int _id1;
   CATPolyCell * _Cell;

   /**
   * Method to directly get edge information if any
   * @param oEdge
   * The edge linked to this bar
   * @param oEV0
   * The curve vertex id of _id0 on oEdge
   * @param
   * The curve vertex id of _id1 on oEdge
   * @return
   * S_OK if edge information was found, S_FALSE otherwise, E_FAIL if there was an error.
   */
   HRESULT GetEdgeInformation     (const CATPolyEdge * & oEdge,
                                         int           & oEV0 ,
                                         int           & oEV1 ) const;

   /**
   * Method to directly get face information (or the first one linked to an edge)
   * @param oFace
   * The first face founded linked to this edge
   * @param oSV0
   * The surface vertex id of _id0 on oFace
   * @param oSV1
   * The surface vertex id of _id1 on oFace
   * @return
   * S_OK if the information was found, E_FAIL otherwise.
   */
   HRESULT GetFirstFaceInformation(const CATPolyFace * & oFace,
                                         int           & oSV0 ,
                                         int           & oSV1 ) const;

   /**
   * Method to directly get the first curve linked to this edge bar
   * @param oCurve
   * The first curve
   * @return
   * S_OK if the information was found, S_FALSE if the bar is not an edge bar, E_FAIL otherwise
   */
   HRESULT GetFirstCurveInformation(const CATIPolyCurve * & oCurve) const;

   /**
   * Method to easily get the identifier on the provided face
   * @param iFace
   *  The face where the output identifiers relied on
   * @param oSV0
   *  The surface vertex id of _id0 on iFace
   * param oSV1
   *  The surface vertex id of _id1 on iFace
   * @return
   * S_OK if the face is linked to this bar, S_FALSE otherwise, E_FAIL if there was an error.
   */
   HRESULT GetFaceVertexIdentifier(const CATPolyFace * iFace,
                                         int         & oSV0 ,
                                         int         & oSV1 ) const;
};

/**
 * Cache of bars interface.
 * This container stores bars defined by CATPolyBodyBarLight
 * with additionnal Data attribut.
 */
class ExportedByPolyBodyRegularize CATIPolyBodyBarCache : public CATPolyRefCounted
{
public:
   // -----------------------------------------------------------------
   // Bar definition
   // -----------------------------------------------------------------
   /**
   * A bar definition from the CATPolyBody
   * with additional T data
   */
   struct Bar_Data : public CATPolyBodyBarLight
   {
      Bar_Data()
      {
         _Data._Data = 0;
      }

      union
      {
         void   * _Data  ;
         double   _Double;
      } _Data;
   };

   // -----------------------------------------------------------------
   // Useful bar class
   // -----------------------------------------------------------------
   class BarFilter;
   class BarDataManager;

   // -----------------------------------------------------------------
   // Iterator
   // -----------------------------------------------------------------
   class Iterator : public CATPolyRefCounted
   {
   public:
     Iterator(){};
     virtual ~Iterator(){};
     virtual Bar_Data * operator* () = 0;
     virtual Iterator & operator++() = 0;
     virtual Iterator & Begin() = 0;
     virtual bool       End() = 0;
   };
   virtual Iterator * GetIterator() = 0;

   // -----------------------------------------------------------------
   // Observer definition
   // -----------------------------------------------------------------
   typedef CATPolyActiveCacheObserver<Bar_Data> BarCacheObserver;

   // -----------------------------------------------------------------
   // Object management
   // -----------------------------------------------------------------
   virtual ~CATIPolyBodyBarCache() { };

   // -----------------------------------------------------------------
   // Methods
   // -----------------------------------------------------------------
   virtual Bar_Data * New() = 0;
   virtual void Free(const Bar_Data * & iToFree ) = 0;

   // Add,find,remove active bar methods
   virtual Bar_Data * Add(Bar_Data * iToAdd) = 0;
   virtual Bar_Data * Find(const Bar_Data * iToFind) const = 0;
   virtual Bar_Data * Find(const CATPolyBodyBarLight& iToFind) const = 0;
   virtual HRESULT Remove(const Bar_Data* iToRemove,
                          bool iToFree = true,
                          bool iSamePtr = true) = 0;
   virtual HRESULT Remove(const CATPolyBodyBarLight& iToRemove) = 0;

   virtual int Size () const = 0;
   virtual void Clear () = 0;

   // -----------------------------------------------------------------
   // Observers
   // -----------------------------------------------------------------
   virtual HRESULT RegisterObserver(BarCacheObserver * iObserver) = 0;
   virtual HRESULT UnregisterObserver(BarCacheObserver * iObserver) = 0;

protected:
   // -----------------------------------------------------------------
   // Object management (protected)
   // -----------------------------------------------------------------
   CATIPolyBodyBarCache() { };
};

/**
* Method for a bar cache handle by a poly bucket
* O(log(N)) in add/remove/find
* O(1) in new
*/
ExportedByPolyBodyRegularize CATIPolyBodyBarCache * CreateBarBucketsQueueCache();

// -----------------------------------------------------------------
// CATIPolyBodyBarCache::BarFilter
// -----------------------------------------------------------------
class ExportedByPolyBodyRegularize CATIPolyBodyBarCache::BarFilter : virtual public CATPolyRefCounted
{
public:
   BarFilter() : CATPolyRefCounted() {};
   virtual ~BarFilter(){};

  /**
  * Check if a bar can be add to the list of active bar
  * @param iBar
  *  The bar to check
  * @return
  *  TRUE is the bar is eligible to be added, FALSE otherwise;
  */
   virtual bool IsEligibleBarToAdd(const CATIPolyBodyBarCache::Bar_Data & iBar) = 0;
};

// -----------------------------------------------------------------
// CATIPolyBodyBarCache::BarDataManager
// -----------------------------------------------------------------
/**
 * BarDataManager handle the CATIPolyBodyBarCache::Bar_Data _Data attributs content.
 * It provides was to compute the data content, compare it and free it.
 */
class ExportedByPolyBodyRegularize CATIPolyBodyBarCache::BarDataManager : virtual public CATPolyRefCounted
{
public:
   BarDataManager(){};
   virtual ~BarDataManager(){};

   /**
   * Compute and fill the iBar._Data attributs
   * @param iBar
   *  The bar to compute the data
   * @return
   *  HRESULT
   */
   virtual HRESULT    Compute        (      CATIPolyBodyBarCache::Bar_Data & iBar) = 0;

   /**
   * Call made after a bar is free, in order to free the iBar._Data if needed.
   * @param iBar
   *  The bar to free the _Data attributs
   */
   virtual void       FreeData       (const CATIPolyBodyBarCache::Bar_Data & iBar) {};

   /**
   * Strict comparison of bars data (then bar id if the data are equal)
   * @param iBar1
   *  The first bar for the comparison
   * @param iBar2
   *  The second bra for comparison
   * @return
   *  -1 if iBar1 is detected as lower than iBar2, 0 if they are equals, +1 if iBar1 is detected as higher than iBar2.
   */
   virtual int        StrictCompare  (const CATIPolyBodyBarCache::Bar_Data * iBar1,
                                      const CATIPolyBodyBarCache::Bar_Data * iBar2) const = 0;

   /**
   * Tolerant comparison of bars datas (then bar id if the data are equal)
   * @param iBar1
   *  The first bar for comparison
   * @param iBar2
   *  The second bar for comparison
   * @return
   *   -1 if iBar1 is detected as lower than iBar2, 0 if they are equals, +1 if iBar1 is detected as higher than iBar2.
   */
   virtual int        TolCompare     (const CATIPolyBodyBarCache::Bar_Data * iBar1,
                                      const CATIPolyBodyBarCache::Bar_Data * iBar2) const { return StrictCompare(iBar1, iBar2); };
};

#endif

