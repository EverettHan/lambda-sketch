#ifndef CAT2DPolylineGP_H
#define CAT2DPolylineGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"
#include "CAT2DLineGP.h"

/**
 * Class to create the graphic primitive of a 2D polyline.
 * <b>Role</b>: <pre>
 *              Example of a CAT2DPolyline made of four points :
 *
 *              point 1 X--------------------X point 2
 *                                           |
 *                                           |
 *                                   point 3 X-----------------------X point 4
 *              </pre>
 */
class ExportedBySGInfra CAT2DPolylineGP : public CAT2DLineGP
{
 CATDeclareClass;

 public :

/**
   * Constructs a 2D polyline graphic primitive from a list of points.
   * @param iPoints
   *   Array containing the x, y  coordinates for
   *   each point of the polyline. Its size is equal
   *   to two times the number of points. So, the coordinates
   *   x, y of the first point are respectively stored in iPoints[0], and  iPoints[1],
   *   the coordinates x, y of the second point, in iPoints[2], iPoints[3], and so on...
   * @param iNbPoints
   *   The number of points used to define the polyline.
   *   <br><b>Legal values</b>: the default value is 2.
   * @param iAlloc
   *   Parameter used to specify whether to allocate or not the data.
   *    <br><b>Legal values</b>:
   *   <ul>
   *      <li>ALLOCATE :
   *        All data are duplicated into the graphic primitive</li>
   *      <li>DONT_ALLOCATEb :
   *        The graphic primitive has a pointer to the data given as parameter</li>
   *   </ul>
   *   
   */
   CAT2DPolylineGP (const float iPoints[], const int iNbPoints=2, const int iAlloc=ALLOCATE);

/**
   * Constructs a 2D polyline graphic primitive from a list of points.
   * @param iPoints
   *   Array containing 2D points which define the polyline. Its size is equal
   *   to one time the number of points.
   * @param iNbPoints
   *   The number of points used to define the polyline.
   *   <br><b>Legal values</b>: the default value is 2.
   * @param iAlloc
   *   Parameter used to specify whether to allocate the data or not.
   *    <br><b>Legal values</b>:
   *   <ul>
   *      <li>ALLOCATE :
   *        All data are duplicated into the graphic primitive</li>
   *      <li>DONT_ALLOCATEb :
   *        The graphic primitive has a pointer to the data given as parameter</li>
   *   </ul>
   *   
   */
   CAT2DPolylineGP (const CATMathPoint2Df iPoints[], const int iNbPoints=2, const int iAlloc=ALLOCATE);  
  	
//--------------------------------------------------------------------------------
                  
 protected :

  virtual ~CAT2DPolylineGP();
                   
};

#endif
