//===================================================================
// COPYRIGHT Dassault Systemes 2017, all rights reserved
//===================================================================
//
// CATPolyTriangleFlip
//
//===================================================================
//
// Usage notes:
//   Flip bars of a mesh until the targeted triangle criterium
//   are respected (geo validity + shape factor & valence validity).
//
//   No need to call the run several times with the same validator,
//   it shouldn't change the result.
//
//===================================================================
// 05/12/17 F1Z : Creation
// 12/01/18 F1Z : Add ShapeFactor coef and valence
// DD/MM/YY
//===================================================================
#ifndef CATPolyBarFlip_H
#define CATPolyBarFlip_H

// System
#include "CATListOfInt.h"

// Mathematics
#include "CATTolerance.h"

// Polyhedral Mathematics
#include "CATPolyBucketsQueueCache.h"
#include "CATPolyRefCounted.h"
#include "CATSetOfPtr.h"

// Polyhedral Interfaces
#include "CATIPolyMesh.h"

// Polyhedral Operators
#include "CATPolyModOperators.h"
#include "CATPolyModOper.h"
#include "CATIPolyTriangleCache.h"

class CATPolyBarFlipImpl;

class ExportedByCATPolyModOperators CATPolyBarFlip : public CATPolyModOper
{
public :
  // ---------------------------------------------------------------------
  // Typedef
  // ---------------------------------------------------------------------
  typedef CATIPolyTriangleCache<TriangleIdentifier::TriangleId>::Triangle_Data       TriangleFlip;
  typedef CATIPolyTriangleCache<TriangleIdentifier::TriangleId>::TriangleDataManager TriangleDataManager;

  // ---------------------------------------------------------------------
  // Class
  // ---------------------------------------------------------------------
  class Filter;

  // ---------------------------------------------------------------------
  // Object Management
  // ---------------------------------------------------------------------
  CATPolyBarFlip (TriangleDataManager * iTriangleDataManager = 0);
  CATPolyBarFlip (CATIPolyMesh        * ioMesh                 ,
                  TriangleDataManager * iTriangleDataManager   );
  ~CATPolyBarFlip();

  // ---------------------------------------------------------------------
  // Options
  // ---------------------------------------------------------------------
  /**
  * Set the triangle data manager (and replace the existing one if any)
  * @param iTriangleDataManager
  *  The triangle data manager
  */
  void SetTriangleDataManager(TriangleDataManager * iTriangleDataManager);

  /**
  * Add a new filter to the operator
  * @param iFilter
  *  The filter to add.
  */
  void AddFilter   (Filter * iToAdd   );

  /**
  * Remove the filter from the operator
  * @param iFilter
  *  The ptr of the filter to remove.
  */
  void RemoveFilter(Filter * iToRemove);

  // ---------------------------------------------------------------------
  // Basic filters
  // ---------------------------------------------------------------------
  /**
  * Add the filter which check the normal angle to allow a flip. It also check the
  * triangle aren't flipped after the operation.
  * @param iMaxAngle
  *  The maximum angle between the triangle normal to allow the flip
  */
  void AddNormalAngleFilter(const double iMaxAngle);

  /**
  * Add the filter which check the distance between the triangles before and after a flip
  * @param iMaxDistance
  *  The max distance acceptable to allow a flip
  */
  void AddDistanceFilter   (const double iMaxDistance);

  /**
  * Add the shape factor valence filter based on shape factor coef and valence improvement (converge to 6)
  * @param iRatioCoefValence
  * The shape factor coef ratio [0..1] from which they are considered similar, thus
  * force the use of the valence criterium instead.
  * @param iValencePriority
  * Set to true, allow reduction of similar shape factor coef to improve the valence.
  */
  void AddShapeFactorValenceFilter(const double iRatioCoefValence = 0.5  ,
                                   const bool   iValencePriority  = false);

  // ---------------------------------------------------------------------
  // Run
  // ---------------------------------------------------------------------
  HRESULT Run();

private:
   // ---------------------------------------------------------------------
   // Methods
   // ---------------------------------------------------------------------
   HRESULT FillWithTriangle(CATIPolyMesh                                          & iMesh         ,
                            CATIPolyTriangleCache<TriangleIdentifier::TriangleId> & ioTriangleFlip);

   HRESULT BestFlipBarTriangle(int            iIdT          ,
                               CATIPolyMesh & iMesh         ,
                               CATBoolean   & oFlipPerformed);

   bool IsFlipValid(const int          iIdVertices[4],
                    const CATMathPoint iPt        [4],
                    const int          iPtValence [4]);


   // ---------------------------------------------------------------------
   // Attributs
   // ---------------------------------------------------------------------
   // impl
   CATPolyBarFlipImpl * m_op;
};

// ===================================================================== //
class ExportedByCATPolyModOperators CATPolyBarFlip::Filter : virtual public CATPolyRefCounted
{
public:
  Filter(){};
  virtual ~Filter(){};

  // ---------------------------------------------------------------------
  // Basic filters
  // ---------------------------------------------------------------------
  /**
  * Create the filter which check the normal angle to allow a flip. It also check the
  * triangle aren't flipped after the operation.
  * @param iMaxAngle
  *  The maximum angle between the triangle normal to allow the flip
  * @return
  *  The filter
  */
  static Filter * CreateNormalAngleFilter(const double iMaxAngle);

  /**
  * Create the filter which check the distance between the triangles before and after a flip
  * @param iMaxDistance
  *  The max distance acceptable to allow a flip
  * @return
  *  The filter
  */
  static Filter * CreateDistanceFilter   (const double iMaxDistance);

  /**
  * Create the shape factor valence filter based on shape factor coef and valence improvement (converge to 6)
  * @param iRatioCoefValence
  * The shape factor coef ratio [0..1] from which they are considered similar, thus
  * force the use of the valence criterium instead.
  * @param iValencePriority
  * Set to true, allow reduction of similar shape factor coef to improve the valence.
  * @return
  *  The filter
  */
  static Filter*  CreateShapeFactorValenceFilter(const double iRatioCoefValence = 0.5  ,
                                                 const bool   iValencePriority  = false);

  // ---------------------------------------------------------------------
  // Methods
  // ---------------------------------------------------------------------
  /**
   * Check if a triangle is a futur candidate
   * @param iTriangle
   *  The triangle to check
   * @return
   *  true if the triangle is a futur candidate, false otherwise
   */
  virtual bool IsAFuturCandidate(const CATPolyBarFlip::TriangleFlip & iTriangle) {return true; };

  /**
  * Check if a triangle is eligible to have one of its bar to be flipped
  * @param iTriangle
  *  The triangle to check the eligibility
  * @return
  *  true if the triangle is eligible, false otherwise
  */
  virtual bool IsTriangleEligible(const CATPolyBarFlip::TriangleFlip & iTriangle) {return true; };

  /**
  * Check if the flip is valid
  * The current triangles are (iIdVertices[0] - iIdVertices[2] - iIdVertices[1]) and
  * (iIdVertices[0] - iIdVertices[3] - iIdVertices[2]).
  * @param iIdVertices
  *  The id of the triangles vertices on both side of the bar iIdVertices[0] - iIdVertices[2]
  * @param iPt
  *  The position of the vertices
  * @param iPtValence
  *  The valence value at each vertex
  */
  virtual bool IsFlipValid(const int          iIdVertices[4],
                           const CATMathPoint iPt        [4],
                           const int          iPtValence [4]) = 0;
};

#endif
