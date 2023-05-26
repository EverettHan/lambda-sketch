#ifndef CAT3DPolylineGP_H
#define CAT3DPolylineGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Inheritance: CAT3DPolylineGP
//                 CAT3DLineGP
//                    CATGraphicPrimitive
//                       CABaseUnknown 
//------------------------------------------------------------------------------
// Main Methods:
//
//         Draw
//           Draw 3D polyline with a associated CATRender
//           
//------------------------------------------------------------------------------

#include "SGInfra.h"
#include "CAT3DLineGP.h"

/**
 * Class to create the graphic primitive of a 3D polyline.
 * <b>Role</b>: <pre>
 *              Example of a CAT3DPolyline made of four points :
 *
 *              point 1 X--------------------X point 2
 *                                           |
 *                                           |
 *                                   point 3 X-----------------------X point 4
 *              </pre>
 */
class ExportedBySGInfra CAT3DPolylineGP : public CAT3DLineGP
{
 friend class CATMarshallable3DPolylineGP;
 CATDeclareClass;

 public :

  /**
   * Default constructor.
   */
   CAT3DPolylineGP ();

  /**
   * Constructs a 3D polyline graphic primitive from a list of points.
   * @param iPoints
   *   Array containing the x, y, z coordinates for
   *   each point of the polyline. Its size is equal
   *   to three times the number of points. So, the coordinates
   *   x, y, z of the first point are respectively stored in iPoints[0], iPoints[1] and iPoints[2],
   *   the coordinates x, y, z of the second point, in iPoints[3], iPoints[4], iPoints[5], and so on...
   * @param iNbPoints
   *   The number of points used to define the polyline.
   *   <br><b>Legal values</b>: the default value is 2.
   * @param iAlloc
   *   Parameter used to specify whether to allocate or not the data.
   *    <br><b>Legal values</b>:
   *   <dl>
   *      <dt>ALLOCATE</dt>
   *        <dd>All data are duplicate into the graphic primitive</dd>
   *      <dt>DONT_ALLOCATE</dt>
   *        <dd>The graphic primitive has a pointer to the data given as parameter</dd>
   *   </dl>
   *   
   */
   CAT3DPolylineGP (const float iPoints[], const int iNbPoints=2, const int iAlloc=ALLOCATE);
   	
//--------------------------------------------------------------------------------
 
   /**
   * @nodoc
   * Streaming
   */
  virtual void Stream(CATStreamer& oStr,int iSavetype=0);                  

 protected :

  virtual ~CAT3DPolylineGP();

};

#endif
