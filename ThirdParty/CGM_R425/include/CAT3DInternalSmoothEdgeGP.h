#ifndef CAT3DInternalSmoothEdgeGP_H
#define CAT3DInternalSmoothEdgeGP_H

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "SGInfra.h"
#include "CAT3DLineGP.h"

class CAT3DLineGPEditHelper;

/**
 *    Ne sert que pour le trace des edges morte dans CATHardHLRCullingRender
 */

class ExportedBySGInfra CAT3DInternalSmoothEdgeGP : public CAT3DLineGP
{
 CATDeclareClass;
 
 friend class CAT3DLineGPEditHelper;
 friend class CAT3DLineGP;

  public:

  /**
   * @nodoc
   */
    CAT3DInternalSmoothEdgeGP (void);

  /**
   * @nodoc
   *
   * Constructs a 3D line graphic primitive from points coordinates.
   * @param iPoints
   *    The array of points coordinates: XYZXYZXYZ...
   *    Its size is equal to three times the number of points.
   * @param iNbPoints
   *    The number of points.
   * @param iAlloc
   *    Flag used to specify whether points must be duplicated or not.
   *    <br><b>Legal values</b>:
   *    <dl>
   *      <dt>ALLOCATE</dt>
   *        <dd>All data are duplicated into the graphic primitive</dd>
   *      <dt>DONT_ALLOCATE</dt>
   *        <dd>The graphic primitive has a pointer to the data given as parameter</dd>
   *    </dl>
   *    The default value is <tt>ALLOCATE</tt>.
   * @param iLineType
   *    Flag to specify the line type to use.
   *    <br><b>Legal values</b>:
   *    <dl>
   *      <dt>LINES</dt>
   *        <dd>The number of points must be even. A line will be drawn
   *            between points 1 and 2, another line will be drawn between
   *            points 3 and 4, ...</dd>
   *      <dt>LINE_STRIP</dt>
   *        <dd>The number of points can be either even or odd. A line will
   *            be drawn between points 1 and 2, then, another line will be drawn
   *            between points 2 and 3, ...</dd>
   *      <dt>LINE_LOOP</dt>
   *        <dd>Same as <tt>LINE_LOOP</tt>, excepted that one more line will be
   *            drawn between the last and the first points.</dd>
   *    </dl>
   *    The default value is <tt>LINES</tt>.
   */
   CAT3DInternalSmoothEdgeGP (const float iPoints[], const int iNbPoints=2, 
                              const int iAlloc=ALLOCATE, const int iLineType = LINES);

  /**
   * @nodoc
   */
    void Stream(CATStreamer &str, int savetype=0);

  /**
   * @nodoc
   */
    void UnStream(CATStreamer &str);


  protected:
    
  /**
   * @nodoc
   */
    virtual ~CAT3DInternalSmoothEdgeGP (void);

  /**
   * @nodoc
   */
    CAT3DInternalSmoothEdgeGP (CAT3DInternalSmoothEdgeGP &);

private:
  bool InternalIsDrawable(CATRender& iRender);

};
#endif
