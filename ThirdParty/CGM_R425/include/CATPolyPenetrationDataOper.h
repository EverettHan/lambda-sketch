// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPenetrationDataOper.h
//
//===================================================================
// May 2011 Creation: NDO
//===================================================================
#ifndef CATPolyPenetrationDataOper_h
#define CATPolyPenetrationDataOper_h

#include "CATPolyBoundingVolumeOperators.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATIPolyPrimitiveSupport;
class CATPolyCollisionInterf;


/**
 * Class that computes the interference data between two entities including:
 * <ul>
 *   <li> The penetration direction. This is the direction along which the first entity must be moved
 *        to remove the clash with the second object.
 *   <li> The penetration depth.  This is the pulling distance along the penetration direction
 *        to get rid of the clash between the two entities.
 *   <li> The contact points.  These are the points of contacts between the two entities once the
 *        first entity has been pulled from the second object.
 * </ul>
 *
 * This class is virtual.  Custom implementation of the computation can be provided.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyPenetrationDataOper
{

public:

  CATPolyPenetrationDataOper ();

  virtual ~CATPolyPenetrationDataOper ();

public:

  /**
   * Enumerator that specifies the clash status.
   */
  enum ClashStatus 
  {
    /** The status is undetermined. */                   eUndetermined = 0,  
    /** There is no clash between both operands. */      eNoClash,  
    /** There is a contact between the two operands. */  eContact,
    /** There is a clash between the two operands. */    eClash  
  };

public:

  /**
   * Computes the penetration data between two entities.
   * The implementation of this method must be thread-safe.
   * @param iPrimitive1
   *   The first primitive.  (This is the support of a CATPolyBody.)
   * @param iSupport2
   *   The second primitive.  (This is the support of a CATPolyBody.)
   * @param oClashStatus
   *   The status of the computed clash between the two supports.  This is an output.
   * @param oInterference
   *   The output computed interference (encapsulating penetration direction and depth and the contact points.)
   *   The returned object must be deleted.
   * @return
   * <ul>
   *   <li> <tt>S_FALSE</tt> The penetration could not be computed between the two entities.
   *   <li> <tt>S_OK</tt> The penetration has been successfully computed.
   *   <li> <tt>E_FAIL</tt> An error occured.
   * </ul>
   */
  virtual HRESULT ComputePenetration (const CATIPolyPrimitiveSupport* iPrimitive1,
                                      const CATIPolyPrimitiveSupport* iPrimitive2,
                                      ClashStatus& oClashStatus, 
                                      CATPolyCollisionInterf*& oInterference) const;

};

#endif /* CATPolyPenetrationDataOper_h */
