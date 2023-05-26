#ifndef CATIPGMPolyhedralRoughOffset_h_
#define CATIPGMPolyhedralRoughOffset_h_

// COPYRIGHT DASSAULT SYSTEMES 2019

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMPolyTopOperator.h"

class CATBody;
class CATGeoFactory;
class CATTopData;

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMPolyhedralRoughOffset;

/**
* Class defining an operator that creates an approximate rolling-ball offset of a polyhedral body
* <ul>
*     <li> A <tt>CATICGMPolyhedralRoughOffset</tt> operator is created with the <tt>CATCGMCreatePolyhedralRoughOffset</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
* </ul>
*/

class ExportedByCATGMOperatorsInterfaces CATIPGMPolyhedralRoughOffset: public CATIPGMPolyTopOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMPolyhedralRoughOffset();

  //=============================================================================
  // Settings
  //=============================================================================
  /**
  * Defines the signed offset value for all the faces of the input body.
  * This setting is mandatory and the operator will automatically fail if this method is not called before the computation
  * @param iOffsetValue
  * The signed offset value.
  * a positive value will offset volumes outwards (adding matter), and offset skins in a direction equal to their global orientation
  * a negative value will offset volumes inwards (removing matter), and offset skins in a direction opposite to their global orientation
  * a null offset value is totally forbidden, and a too small value regarding the body size may lead to a failure
  */
  virtual void SetOffsetValue(double iOffsetValue) = 0;

  /**
  * Defines a minimum level of accuracy among 3 modes : coarse, medium and fine
  * This option (not mandatory) allows the caller to speed up the computation of an approximate result (coarse mode)
  * or to improve the accuracy of the result in spite of poorer performances (fine mode)
  * The medium level is the default value of accuracy (recommended)
  * The operator can decide internally to increase the accuracy level in order to assure the maximum deviation is always smaller than the offset value
  */
  virtual void SetMinimumAccuracyLevel(int iCoarseMediumOrFine123) = 0;

  /**
  * Activate the EnvelopMode:
  *   The output will be a volume created by generating an envelope of each shell of the
  *     Input.
  *   The envelope of a shell is a double offset (positive and negative) joined with the
  *     offset of the border-edges if any.
  *   The sign of the offset value does not matter in this case and will be ignored
  *
  * For this mode, the non-manifold inputs are allowed.
  */
  virtual void EnableEnvelopMode() = 0;


  // ------------------------------------------------------------------------
  // Get additional information BEFORE Run
  // ------------------------------------------------------------------------

  /**
  * Computes an approximation of the minimum offset value for this input.
  *   The operator may fail for offset-value below this one, due to the size
  *   of the internal voxelization used to compute the offset.
  * CAUTION : in case of a multi-domains input, some offset-value above this minimum can
  *   lead to a fail. But the minimum value should always work.
  *   In fact, by increasing the offsetValue some domains may be too close to be processed
  *     separately. By processing two domains simultaneously, we increase the size of the
  *     bounding box and thus the minimum offset tolerated.
  *
  * @param oMinOffsetValue
  *   an approximation of the minimum offset-value for this input-body.
  *
  * @return[HRESULT]
  *   S_OK    if the minimum offsetValue has been correctly computed.
  *   E_FAIL  in case of an internal error.
  */
  virtual HRESULT GetApproximationOfMinOffsetValue(double &oMinOffsetValue) = 0;

  /**
  * From a MaxDeviation computes the minimum accuracy to use for this operation.
  *
  * @param[in] iMaxDeviation
  *   The max deviation allowed for this operation.
  *
  * @param[out] oAccuracyToUse
  *   This accuracy to use. 1 for coarse, 2 for medium and 3 for a fine accuracy.
  *   0 in case of an error.
  *
  * @param[out] oErrorType
  *   If the method failed (return E_FAIL), errorType != 0 and :
  *        = 1 : the offsetValue is not valid. Use GetApproximationOfMinOffsetValue.
  *              CAUTION : the max deviation has not been checked and may still be invalid.
  *        = 2 : the offsetValue is valid but the maxDeviation is too small. Use GetApproximationOfMinMaxDeviation.
  *        = 3 : unknowed error (offsetValue not set...)
  *
  * Return E_FAIL if the operation is impossible with this deviation and offsetValue.
  *
  * WARNING : the offsetValue must be set before a call to this method.
  */
  virtual HRESULT GetAccuracyFromDeviation(double iMaxDeviation, int &oAccuracyToUse, int &oErrorType) = 0;


  /**
  * From the offsetValue already set, approximates the minimal max-deviation that the operator can ensure.
  *    If the caller ask for a max-deviation below that, it may fails.
  *
  * @param[out] oMinMaxDeviation
  *   The minimal max deviation allowed for this operation.
  *
  * Return E_FAIL if the operation is impossible with this offsetValue.
  */
  virtual HRESULT GetApproximationOfMinMaxDeviation(double &oMinMaxDeviation) = 0;


  //=============================================================================
  // Get additional information after Run
  //=============================================================================
  /**
  * Retrieves the information of maximum deviation from the expected offset value
  * This deviation is supposed to be smaller than the expected offset value, in order to guarantee there is no clash between input and offset bodies
  * This deviation depends on both the offset value and the level of accuracy
  * @param oMaxDeviation
  *   the maximum deviation between the expected offset value and the generated rough offset
  * @param ioComputedAccuracyLevel123
  *   optional argument to know the level of accuracy actually used for the operation.
  *   It allows the caller to know if a better accuracy has been forced internally to optimize the maximum deviation
  * @return [HRESULT]
  *   S_OK    if the maximum deviation has been correctly computed
  *   E_FAIL  if the requested offset value is too low and cannot be applied :
  *         it happens since there is a risk of intersection between input and offset bodies even if the best accuracy has been forced
  */
  virtual HRESULT GetMaxDeviation(
    double &oMaxDeviation,
    int *ioComputedAccuracyLevel123 = 0) = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMPolyhedralRoughOffset(); // -> delete can't be called
};

/**
 * Creates a CATIPGMPolyhedralRoughOffset operator
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToOffset
 * The pointer to the surface body to offset or the volumic body to thick
 *    Surface input : if multiple surfaces, each one is processed independantly BUT if two offsetted surfaces are intersecting
 *        the operation failed.
 *    Volumic input : the volumes too close to each other are processed together.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByCATGMOperatorsInterfaces CATIPGMPolyhedralRoughOffset *CATPGMCreatePolyhedralRoughOffset(
  CATGeoFactory *iFactory,
  CATTopData *iTopData,
  CATBody *iBodyToOffset);

#endif /* CATIPGMPolyhedralRoughOffset_h_ */
