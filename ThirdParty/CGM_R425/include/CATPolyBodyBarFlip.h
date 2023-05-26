//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyBarFlip
//
//===================================================================
// 07/12/17 F1Z : Creation
// 22/03/18 F1Z : Rename into CATPolyBodyBarFlip and add operator
// DD/MM/YY
//===================================================================
#ifndef CATPolyBodyBarFlip_H
#define CATPolyBodyBarFlip_H

// Polyhedral Operators
#include "CATIPolyTriangleCache.h"

// Polyhedral Body Operators
#include "PolyBodyRegularize.h"

class CATPolyBody;
class CATProgressCallback;
class CATPolyBodyBarFlipImpl;
class CATProgressCallback;
class CATMathPoint;

/**
* Global bar flip performed on each face of the provided CATPolyBody
* to improve the shape factor and valence (to converge to 6).
* The poly body edge are not impacted.
* @param ioPolyBody
*   CATPolyBody to apply the bar flip on
* @param iNormalAngleLimits
*   The normal max angle to apply a flip
* @param iMaxDistanceDeform
*   The maximal distance of the triangle before/after a flip
* @param iRatioCoefValence
*   The shape factor coef ratio [0..1] from which they are considered similar, thus
*   force the use of the valence criterium instead.
* @param iValencePriority
*   Set to true, allows reduction of similar shape factor coef to improve the valence.
*/
HRESULT ExportedByPolyBodyRegularize ApplyBarFlip(CATPolyBody         & ioPolyBody                ,
                                                  CATProgressCallback * ioProgressBar             ,
                                                  double                iNormalAngleLimits = -1   ,
                                                  double                iMaxDistanceDeform = -1   ,
                                                  double                iRatioCoefValence  = 0.5  ,
                                                  bool                  iValencePriority   = false);


/**
* Operator to perform a global bar flip on the whole poly body
* based on the provided filter criterium.
* The triangleDataManager is required to defined an order of treatment.
* see @CATIPolyTriangleCache header to find some definition.
*/
class ExportedByPolyBodyRegularize CATPolyBodyBarFlip
{
public:
  // -----------------------------------------------------------------
  // Typdef
  // -----------------------------------------------------------------
  typedef CATIPolyTriangleCache<TriangleIdentifier::TriangleId>::Triangle_Data       TriangleFlip;
  typedef CATIPolyTriangleCache<TriangleIdentifier::TriangleId>::TriangleDataManager TriangleDataManager;

  // -----------------------------------------------------------------
  // Filter
  // -----------------------------------------------------------------
  class Filter;

  // -----------------------------------------------------------------
  // Object Management
  // -----------------------------------------------------------------
  CATPolyBodyBarFlip(TriangleDataManager * iTriangleDataManager = 0,
                     Filter              * iFilter              = 0);
  ~CATPolyBodyBarFlip();

  // -----------------------------------------------------------------
  // Options
  // -----------------------------------------------------------------
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
  void AddFilter   (Filter * iFilter);

  /**
  * Remove the filter from the operator
  * @param iFilter
  *  The ptr of the filter to remove.
  */
  void RemoveFilter(Filter * iFilter);

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

   // -----------------------------------------------------------------
   // Progress information
   // -----------------------------------------------------------------
   void SetProgressCallback(CATProgressCallback * iProgress);

  // -----------------------------------------------------------------
  // Run
  // -----------------------------------------------------------------
  /**
  * Flip the bar of the provided poly body.
  * @param iPolyBody
  *   The CATPolyBody.
  * @return
  *   <tt>S_OK</tt> if no issue were encountered.
  */
  HRESULT Run (CATPolyBody & ioPolyBody);

private:
  CATPolyBodyBarFlipImpl * m_op;
};

// ===================================================================== //

class ExportedByPolyBodyRegularize CATPolyBodyBarFlip::Filter : virtual public CATPolyRefCounted
{
public:
  // -----------------------------------------------------------------
  // Object Management
  // -----------------------------------------------------------------
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
  * Check if a triangle is eligible to have one of its bar to be flipped
  * @param iIdFace
  *  The iIdFace(th) face of the poly body
  * @param iTriangle
  *  The triangle to check the eligibility
  * @return
  *  true is the triangle is eligible, false otherwise
  */
  virtual bool IsTriangleEligible(const int                                iIdFace  ,
                                  const CATPolyBodyBarFlip::TriangleFlip & iTriangle) {return true; };

  /**
  * Check if the flip is valid on the id(th) face of the poly body.
  * The current triangles are (iIdVertices[0] - iIdVertices[2] - iIdVertices[1]) and
  * (iIdVertices[0] - iIdVertices[3] - iIdVertices[2]).
  * @param iIdFace
  *  The iIdFace(th) face of the poly body
  * (based on the CATPolyBodyFaceIterator, from 1 to NBFaces, cf. CATPolyBodyIteratorIdServices.h)
  * @param iIdVertices
  *  The id of the triangles vertices on both side of the bar iIdVertices[0] - iIdVertices[2]
  * @param iPt
  *  The position of the vertices
  * @param iPtValence
  *  The valence value at each vertex
  */
  virtual bool IsFlipValid(const int          iIdFace       ,
                           const int          iIdVertices[4],
                           const CATMathPoint iPt        [4],
                           const int          iPtValence [4]) = 0;
};

#endif
