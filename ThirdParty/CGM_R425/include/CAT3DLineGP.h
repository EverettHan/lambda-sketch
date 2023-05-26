#ifndef CAT3DLineGP_H
#define CAT3DLineGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Inheritance: CAT3DLineGP
//                 CATGraphicPrimitive
//                    CATBaseUnknown (SYSTEM framework)
//------------------------------------------------------------------------------

#include "SGInfra.h"
#include "CATGraphicPrimitive.h"
#include "CATVizMacForMetaClass.h"

class CATStreamer;
class CAT3DLineGPEditHelper;
class CATMathPolyBuffers;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG3DPolyline;
class CAT3DLineGPIVisSG3DPolylineBOAImpl;
//-- SGCAAPlan


//used only by CATVis3DLineGPBuilder for WYSIWYG mode
#define IS_JUNCTION 4

/** @nodoc */
#define LINES      0
/** @nodoc */
#define LINE_STRIP 1
/** @nodoc */
#define LINE_LOOP  2

/**
 * Class to create the graphic primitive of one or several 3D lines.
 * <b>Role</b>:
 * The first line is drawn between the first two points. Then, the next lines are
 * drawn with the next points according to the line style.
 * Example a CAT3DLineGP defined with 4 points :
 * <pre>
 *
 *         LINES style:               point 1 X--------------------X point 2
 *                                                   point 3 X-----------------------X point 4
 *
 *
 *         LINE_STRIP style:          point 1 X--------------------X point 2
 *                                                                /
 *                                                               /
 *                                                              /
 *                                                     point 3 X----------------------X point 4
 *
 *         LINE_LOOP style:           point 1 X--------X point 2
 *                                             \      /
 *                                              \    /      
 *                                               \  /
 *                                                \/
 *                                                /\
 *                                               /  \
 *                                      point 3 X----X point 4
 * </pre>
 */
class ExportedBySGInfra CAT3DLineGP : public CATGraphicPrimitive
{

 friend class CAT3DLineGPEditHelper;
 friend class CATMarshallable3DLineGP;
 friend class CATMarshallable3DPolylineGP;
 friend class SGCGRStreamerFor3DLineGP;
 friend class SGCGRNodesFactoryA;
 CATDeclareClass;
 CATVizDeclareClass;
 CATVisDeclarePublicInterfaceAdhesion(CAT3DLineGP, IVisSG3DPolyline, CAT3DLineGPIVisSG3DPolylineBOAImpl);

public :

  /**
   * Default constructor.
   */
  CAT3DLineGP ();

  /**
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
  CAT3DLineGP (const float iPoints[], const int iNbPoints=2, 
               const int iAlloc=ALLOCATE, const int iLineType = LINES);

  /**
   *@nodoc
   * Constructs a 3D line graphic primitive from CATMathPolyBuffers.
   * @param iEdgePolyBuffers
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
  CAT3DLineGP (const CATMathPolyBuffers* iEdgePolyBuffers, const int iLineType = LINES);
   
  /**
   * @nodoc
   * Streaming
   */
  virtual void Stream(CATStreamer& oStr,int iSavetype=0);

  /**
   * @nodoc
   * Streaming
   */  
  virtual void UnStream(CATStreamer& iStr);

 /**
   * @nodoc
   * Skips the unstreaming of a 3D Line.
   * <br><b>Role:</b>: This method can be used when you do not want
   * to unstream a line. It is used like this :<br>
   * CAT3DLineGP::Skip(str);
   * @param iStr
   *   The streamer used to unstream the 3D lines.
   */
  static void Skip(CATStreamer & iStr);


  /**
   * Retrieves line parameters, such as points coordinates, number of points and line type.
   * <b>Role</b>:This method must be called in the following way :<br>
   * <tt><pre>
   *                float const* points;
   *                int nbPoints, lineType;
   *
   *                GetReadOnly(&points, &nbPoints, &lineType);
   * </pre></tt>
   * @param oPoints
   *    Retrieves the points coordinates array.
   *    Array of points coordinates: XYZXYZXYZ...
   *    Its size is equal to three times the number of points.
   * @param oNbPoints
   *    Retrieves the number of points.
   * @param oLineType
   *    Retrieves the line type.
   *    <br><b>Legal values</b>:
   *    <dl>
   *      <dt>LINES</dt>
   *        <dd>The number of points must be even. A line will be drawn
   *            between points 1 and 2, an other line will be drawn between
   *            points 3 and 4, ...</dd>
   *      <dt>LINE_STRIP</dt>
   *        <dd>The number of points can be either even or odd. A line will
   *            be drawn between points 1 and 2, then, an other line will be drawn
   *            between points 2 and 3, ...</dd>
   *      <dt>LINE_LOOP</dt>
   *        <dd>Same as <tt>LINE_LOOP</tt>, excepted that one more line will be
   *            drawn between the last and the first points.</dd>
   *    </dl>
   */
  inline void GetReadOnly (float const**oPoints, int *oNbPoints,int *oLineType) const;

  /**
   * @nodoc
   */
  inline const int GetAllocMode(void);

  /**
   * @nodoc
   */
  inline TessFlag GetTessStatus (void);

  /**
   * @nodoc
   */
  TessFlag GetTessStatus (float iToleranceScale);

  /**
   * @nodoc
   */
  inline void     SetTessStatus (TessFlag iTessStatus);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif
  /**
   * Draws the 3D lines.
   * @param iRender
   *    The render through wich the 3D line is drawn.
   */
  virtual void Draw (CATRender &iRender) GP_FUNC_OVERRIDE_FINAL;
    
  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);
   
  /**
   * @nodoc
   */
  virtual CATVizPrimitive * GetVizPrimitive(int &oAllocateMode);

  /**
   * @nodoc
   */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

  /**
   * @nodoc
   */
  virtual void Visit(CATIGPVisitor& iVisitor) const final;

//--------------------------------------------------------------------------------

protected :
  /**
   * @nodoc
   */
  virtual void SetVizPrimitive(CATVizPrimitive* iPrimitive, int iAllocateMode);

  virtual ~CAT3DLineGP();

//--------------------------------------------------------------------------------

//private :

  float *_points;
  unsigned int _nb_points  : 26;
  unsigned int _isJunction :  1;
  unsigned int _linetype   :  2;
  unsigned int _alloc      :  1;
  unsigned int _TessStatus :  2;

  //const CATMathPolyBuffers* _EdgePolyBuffers;
};

//--------------------------------------------------------------------------------
inline void CAT3DLineGP::GetReadOnly(float const **points,
                                     int *nb_points,
                                     int *line_type) const
{
  *points    = _points;
  *nb_points = (int)_nb_points;
  *line_type = (int)_linetype;
}

inline const int CAT3DLineGP::GetAllocMode(void)
{
  return (const int)_alloc;
}

inline TessFlag CAT3DLineGP::GetTessStatus (void)
{
  return (TessFlag)_TessStatus;
}

inline void CAT3DLineGP::SetTessStatus (TessFlag tessStatus)
{
  _TessStatus = tessStatus;
}

#endif
