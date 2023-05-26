//==========================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010
//==========================================================================================
//
//==========================================================================================
// Dec 2010 Creation                                    MPX
//==========================================================================================

#ifndef CATDistancePointsBody_H
#define CATDistancePointsBody_H

#ifdef MPXCATDistancePointsBodyAPI

#include "DistanceLight.h"
#include "CATTopOperator.h"
#include "CATTopData.h"
#include "CATDistanceSignMode.h"
#include "CATBoolean.h"


class CATBody;
class CATMathPoint;
class CATSoftwareConfiguration;
class CATTopData;
class CATCGMParamInfo;


/**
 * Class defining the operator for finding the minimum distance between a <code>CATBody</code>
 * and each point in the input list of points.
 * The performance of this operator is optimized for large number of points. If the number of points
 * is small, then using CATICGMDistancePointBody may give better performance.
 * To use the operator:
 * <ul>
 * <li>Create it with the <code>CATCGMCreateDistancePointsBody</code> global function, giving the <code>CATBody</code> as input,
 * <li>Call SetPoints method with an array of <code>CATMathPoint</code>,
 * <li>Call RegisterOutputArrays method with the pre-allocated arrays for storing output,
 * <li>Run the operator,
 * <li>Retrieve the results from the output arrays
 * <li>Release the operator
 * </ul>
*/
class ExportedByDistanceLight CATDistancePointsBody: public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATDistancePointsBody);

public:

  /** @nodoc */
  virtual ~CATDistancePointsBody();

public:

  /**
   * Registers the array of input points
   * @description
   *   This method accepts an array input points which the Run method will use.
   *   Note that the operator does not make a copy of this array. It directly accesses this array.
   *   So the caller should make sure not to delete this array until this operator is alive.
   * @param iNbPoints
   *   Number of points in the input array
   * @param iPoints
   *   The list of input points in the form of an array of <code>CATMathPoint</code> with length same as iNbPoints
   */
  virtual void RegisterInputPointsArray(
                    unsigned int iNbPoints, 
                    const CATMathPoint iPoints[]
                    ) = 0;

  /**
   * Get the array of input points registered with the operator
   * @param oNbPoints
   *   Number of points in the input array registered with the operator
   * @param oPoints
   *   The list of input points in the form of an array of <code>CATMathPoint</code> registered with the operator
   * @param oParamInfos
   *   Pre-allocated array of <code>CATCGMParamInfo</code> registered with the operator
   *   for returning result parameter information.
   */
  virtual void GetInputPointsArray(
                    unsigned int& oNbPoints, 
                    const CATMathPoint*& oPoints
                    ) = 0;
  /**
   * Register the arrays for output results
   * @description
   *   This method accepts pre-allocated arrays which the Run method will populate with results.
   *   If these pre-allocated arrays are not registered, then the Run method will fail.
   *   <br>
   *   <ul>
   *   <li>ioDistances will be populated with result distances. The result distance for each input point 
   *   is the minimum distance between that point and body.
   *     <ul>
   *     <li>If the sign mode is <code>CATDistanceSignModeSigned</code>, then result distance 
   *     may be negative. If it is negative, then it means that the point is inside the body and 
   *     the absolute value gives the minimum distance of the point from the shell of the body.
   *     <li>If the sign mode is <code>CATDistanceSignModeZero</code>, and if the point is inside 
   *     the body, then result distance value is returned is zero.
   *     <li>If the sign mode is <code>CATDistanceSignModeUnsigned</code>, and if the point is inside 
   *     the body, then result distance value is always non-negative and is equal to the distance of
   *     the point from the shell of the body.
   *     </ul>
   *   <li>ioResultPoints will be populated with result points. The result point for each input point 
   *   is the closest point on body.
   *   <li>ioParamInfos will be populated with result parameter information. This is optional, i.e. if this
   *   is passed as NULL (default), then no parameter information is returned. The result parameter information
   *   for each input point contains the cell on which the point lies and the parameters (if applicable).
   *   </ul>
   * @param ioDistances
   *   Pre-allocated array of <code>double</code> with length same as iNbPoints.
   *   The Run method will populate this array with the result distances.
   * @param ioResultPoints
   *   Pre-allocated array of <code>CATMathPoint</code> with length same as iNbPoints.
   *   The Run method will populate this array with the result points.
   * @param ioParamInfos
   *   Pre-allocated array of <code>CATCGMParamInfo</code> with length same as iNbPoints.
   *   The Run method will populate this array with the result parameter information.
   */
  virtual void RegisterOutputArrays(
                    double ioDistances[],
                    CATMathPoint ioResultPoints[],
                    CATCGMParamInfo ioParamInfos[] = NULL
                    ) = 0;

  /**
   * Get the output arrays registered with the operator
   * @param oDistances
   *   Pre-allocated array of <code>double</code> registered with the operator
   *   for returning result distances.
   * @param oResultPoints
   *   Pre-allocated array of <code>CATMathPoint</code> registered with the operator
   *   for returning result points.
   * @param oParamInfos
   *   Pre-allocated array of <code>CATCGMParamInfo</code> registered with the operator
   *   for returning result parameter information.
   */
  virtual void GetOutputArrays(
                    double*& oDistances,
                    CATMathPoint*& oResultPoints,
                    CATCGMParamInfo*& oParamInfos
                    ) = 0;
  /**
   * Define the sign mode. The default is "Signed" mode. 
   * <code>CATDistanceSignModeDefault</code> is interpreted as <code>CATDistanceSignModeSigned</code>.
   * See the documentation of @href CATDistanceSignMode to know more about the different sign modes
   * available and their meanings.
   * @param iSignMode
   *   Sign mode to be defined
   * @see CATDistanceSignMode
   */
  virtual void SetSignMode(CATDistanceSignMode iSignMode) = 0;

  /**
   * Get the sign mode.
   * <code>CATDistanceSignModeDefault</code> is interpreted as <code>CATDistanceSignModeSigned</code>.
   * See the documentation of @href CATDistanceSignMode to know more about the different sign modes
   * @return
   *   Sign mode defined in the operator
   * @see CATDistanceSignMode
   */
  virtual CATDistanceSignMode GetSignMode() = 0;

  /**
   * Runs this operator.
   * <br>Note: You must call SetPoints and RegisterOutputArrays before Run.
   * After calling Run, the results will be available to the caller in the output arrays 
   * previously registered with the operator.
   * @return 
   *   0 if the operator runs successfully and 1 otherwise.
   */
  virtual int Run();


protected:

  /** @nodoc */
  CATDistancePointsBody(CATGeoFactory* iFactory, CATTopData* iData);

};

/**
 * Creates CATDistancePointsBody operator.
 * @param iBody
 * The body whose distance from a list of points is to be found.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. Notice that here, the journal is
 * not filled, because there is no body creation.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByDistanceLight CATDistancePointsBody *CATCGMCreateDistancePointsBody(
                                                    CATBody *iBody,
                                                    CATTopData *iData);

#endif //MPXCATDistancePointsBodyAPI

#endif // CATDistancePointsBody_H
