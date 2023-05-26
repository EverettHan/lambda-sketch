//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyTriangleCache
//
// If you want an additionnal type of triangle identifier,
// you should add it to the enum and expose the struct content.
//
//===================================================================
// 20/03/18 F1Z : Creation
// DD/MM/YY
//===================================================================
#ifndef CATIPolyTriangleCache_H
#define CATIPolyTriangleCache_H

// Special API
#include "CATSysErrorDef.h"

// Polyhedral Mathematics
#include "CATPolyRefCounted.h"
#include "CATPolyActiveCacheObserver.h"

// Polyhedral Operators
#include "CATPolyModOperators.h"

// Others
template<typename>
class CATPolyBuckets;
class CATIPolyMesh;

// ===========================================================
// Enum declaration
// ===========================================================
struct TriangleIdentifier
{
   enum Type {TriangleId,
              VerticesId};
};

// ===========================================================
// CATPolyTriangleIdentifier
// ===========================================================
template<TriangleIdentifier::Type T>
struct CATPolyTriangleIdentifier {};

/**
* Triangle identified by its CATIPolyMesh id.
*/
template<>
struct CATPolyTriangleIdentifier<TriangleIdentifier::TriangleId>
{
  int _id;
};

/**
* Triangle identified by its three CATIPolySurface vertices id.
* Two triangle are identical if they have the same vertices id
* circular permutation.
*/
template<>
struct CATPolyTriangleIdentifier<TriangleIdentifier::VerticesId>
{
  int _idSV0;
  int _idSV1;
  int _idSV2;
};

// ===========================================================
// CATIPolyTriangleCache
// ===========================================================
/**
 * Cache of triangle.
 * This container stores triangle defined by CATPolyTriangleIdentifier
 * with additionnal Data attribut.
 */
template<TriangleIdentifier::Type Type>
class ExportedByCATPolyModOperators CATIPolyTriangleCache : public CATPolyRefCounted
{
public:
   // -----------------------------------------------------------------
   // Triangle definition
   // -----------------------------------------------------------------
   /**
   * A triangle definition from CATPolyTriangleIdentifier
   * with additional T data
   */
   struct Triangle_Data : public CATPolyTriangleIdentifier<Type>
   {
      Triangle_Data()
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
   // Some useful interfaces
   // -----------------------------------------------------------------
   class ExportedByCATPolyModOperators TriangleDataManager;

   // -----------------------------------------------------------------
   // Observer definition
   // -----------------------------------------------------------------
   typedef CATPolyActiveCacheObserver<Triangle_Data> Observer;

   // -----------------------------------------------------------------
   // Object management
   // -----------------------------------------------------------------
   virtual ~CATIPolyTriangleCache() { };

   // -----------------------------------------------------------------
   // Methods
   // -----------------------------------------------------------------
   virtual Triangle_Data  * New   ()                                                     = 0;
   virtual void             Free  (const Triangle_Data   * & iToFree             )       = 0;

   virtual Triangle_Data  * Add   (      Triangle_Data   *   iToAdd              )       = 0;
   virtual Triangle_Data  * Find  (const Triangle_Data   *   iToFind             ) const = 0;
   virtual HRESULT          Remove(const Triangle_Data   *   iToRemove           ,
                                         bool                iToFree       = true,
                                         bool                iCheckSamePtr = true)       = 0;

   virtual int              Size  ()                                               const = 0;
   virtual void             Clear ()                                                     = 0;

   // -----------------------------------------------------------------
   // Observers
   // -----------------------------------------------------------------
   virtual HRESULT RegisterObserver  (Observer * iObserver) = 0;
   virtual HRESULT UnregisterObserver(Observer * iObserver) = 0;

protected:
   // -----------------------------------------------------------------
   // Object management (protected)
   // -----------------------------------------------------------------
   CATIPolyTriangleCache() { };
};

// ===========================================================
// Create methods
// ===========================================================
/**
* Method for a bar cache handle by a poly bucket
* O(log(N)) in add/remove/find
* O(1) in new
*/
template<TriangleIdentifier::Type Type>
CATIPolyTriangleCache<Type> * CreateTriangleBucketsQueueCache(){return 0;};

template<>
ExportedByCATPolyModOperators CATIPolyTriangleCache<TriangleIdentifier::TriangleId> * CreateTriangleBucketsQueueCache<TriangleIdentifier::TriangleId>();

template<>
ExportedByCATPolyModOperators CATIPolyTriangleCache<TriangleIdentifier::VerticesId> * CreateTriangleBucketsQueueCache<TriangleIdentifier::VerticesId>();

// ===========================================================
// TriangleDataManager
// ===========================================================
template<TriangleIdentifier::Type Type>
class CATIPolyTriangleCache<Type>::TriangleDataManager : virtual public CATPolyRefCounted
{
public:
  TriangleDataManager(){};
  virtual ~TriangleDataManager(){};

  /**
  * Computes and fills the ioTriangle._Data attributs
  * @param ioTriangle
  *  The triangle which data has to be computed and filled
  * @param iMesh
  *  The mesh containing the triangle information
  * @return
  *  HRESULT
  */
  virtual HRESULT     ComputeData  (      typename CATIPolyTriangleCache<Type>::Triangle_Data & ioTriangle,
                                    const          CATIPolyMesh                               & iMesh     ) = 0;

  /**
  * Free the iTriangle._Data attributs
  * @param iTriangle
  *  The triangle which _Data has to be free
  */
  virtual void        FreeData     (const typename CATIPolyTriangleCache<Type>::Triangle_Data & iTriangle ) = 0;

   /**
   * Strict comparison of triangle data (then triangle id if the data are equal)
   * @param iTriangle1
   *  The first triangle for the comparison
   * @param iTriangle2
   *  The second triangle for comparison
   * @return
   *  -1 if iTriangle1 is detected as lower than iTriangle2, 0 if they are equals, +1 if iTriangle1 is detected as higher than iTriangle2.
   */
   virtual int        StrictCompare(const typename CATIPolyTriangleCache<Type>::Triangle_Data * iTriangle1,
                                    const typename CATIPolyTriangleCache<Type>::Triangle_Data * iTriangle2) const = 0;

   /**
   * Tolerant comparison of bars datas (then triangle id if the data are equal)
   * @param iTriangle1
   *  The first triangle for comparison
   * @param iTriangle2
   *  The second triangle for comparison
   * @return
   *   -1 if iBar1 is detected as lower than iBar2, 0 if they are equals, +1 if iBar1 is detected as higher than iBar2.
   */
   virtual int        TolCompare   (const typename CATIPolyTriangleCache<Type>::Triangle_Data * iTriangle1,
                                    const typename CATIPolyTriangleCache<Type>::Triangle_Data * iTriangle2) const { return StrictCompare(iTriangle1, iTriangle2); };
};

// ===========================================================
// Create methods
// ===========================================================
/**
* Create a triangle shape factor data manager
*/
template<TriangleIdentifier::Type Type>
typename CATIPolyTriangleCache<Type>::TriangleDataManager * CreateTriangleShapeFactorManager(){ return 0; };

template<>
ExportedByCATPolyModOperators CATIPolyTriangleCache<TriangleIdentifier::TriangleId>::TriangleDataManager * CreateTriangleShapeFactorManager<TriangleIdentifier::TriangleId>();
template<>
ExportedByCATPolyModOperators CATIPolyTriangleCache<TriangleIdentifier::VerticesId>::TriangleDataManager * CreateTriangleShapeFactorManager<TriangleIdentifier::VerticesId>();

#endif

