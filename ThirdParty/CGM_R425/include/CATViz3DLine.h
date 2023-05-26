#ifndef CATViz3DLine_H
#define CATViz3DLine_H

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "SGInfra.h"
#include "CATVizPrimitive.h"
#include "CATVizMacForMetaClass.h"
#include "CATBoolean.h"
#include "IUnknown.h" // -> for  HRESULT
#include "CATVisMacroForInterfaces.h"

class CATStreamer;
class CATRender;
class CAT3DLineGP;

class IVisSG3DPolyline;
class CATViz3DLineIVisSG3DPolylineBOAImpl;

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
* Example a CATViz3DLine defined with 4 points :
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
class ExportedBySGInfra CATViz3DLine : public CATVizPrimitive
{   
   friend class SGCGRStreamerForCATViz3DLine;
   friend class SGCGRNodesFactoryA;
   CATVizDeclareClass;

public :

  CATVisDeclarePublicInterfaceAdhesion(CATViz3DLine, IVisSG3DPolyline, CATViz3DLineIVisSG3DPolylineBOAImpl);
   
   /**
   * Default constructor.
   */
   CATViz3DLine ();
   CATViz3DLine (const CATViz3DLine & toCopy);
   
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
   CATViz3DLine (const float iPoints[], const unsigned int iNbPoints=2, const unsigned int iLineType = LINES, const CATVizAllocMode iAllocMode = CATVizAllocModeAllocate, CATBoolean poolAllocated = FALSE);
   
   /** @nodoc */
   virtual CATVizPrimitive * Duplicate();

   /** @nodoc */
   void Empty();
   
   /** @nodoc */
   virtual void Draw(CATRender &iRender);

   /**
   * @nodoc
   * Streaming
   */
   virtual void Stream(CATStreamer& oStr,int iSavetype=0);
   
   /**
   * @nodoc
   * Streaming
   */
   static void Stream(CATStreamer& oStr, CAT3DLineGP *iGP);
   INLINE virtual unsigned char GetStreamId() const;

   /**
   * @nodoc
   * Streaming
   */  
   virtual void UnStream(CATStreamer& iStr);
   
   /**
   * Retrieves line parameters, such as points coordinates, number of points and line type.
   * <b>Role</b>:This method must be called in the following way :<br>
   * <tt><pre>
   *                float * points;
   *                int nbPoints, lineType;
   *
   *                Get(&points, &nbPoints, &lineType);
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
   inline void GetReadOnly (float const**oPoints, unsigned int *oNbPoints, unsigned int *oLineType) const;

   unsigned int GetLineType() const;
   
   /** @nodoc */
   virtual void SetAllocMode(CATVizAllocMode iAllocMode);

   /** @nodoc */
   virtual CATVizAllocMode GetAllocMode();
   /** @nodoc */
   virtual HRESULT ComputeTangents(float *& oTangents, unsigned int & oNbTangents, unsigned int & oArrayToDelete, int allocate = 1);

   
   void Allocate(float **points, unsigned int nbPoints, CATBoolean allocateOnPool = FALSE, unsigned int iLineType = LINES);
   virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

   CATVizDeclareTinyRefCount(5); // 5 bits refCount

   //--------------------------------------------------------------------------------
   
protected :

  void Swap(CATViz3DLine* iOther);
  /** @nodoc */
  virtual ~CATViz3DLine ();

   //--------------------------------------------------------------------------------
   
protected :
   
  unsigned int    _nb_points : 20; // 28 bits were used when TinyRefCount did not exist
  //----- 5 bits reserved for RefCount
  unsigned int    _poolAllocated : 1;
  unsigned int    _linetype  :  2;
  CATVizAllocMode _allocMode :  1;
  // for derived class CATVizUV3DLine, unfortunately C++ doesn't allow padding between derived classes
  unsigned int _refinementLevel : 3;

  float *         _points;
};

//--------------------------------------------------------------------------------

inline void CATViz3DLine::GetReadOnly(float const**points,
                                      unsigned int *nb_points,
                                      unsigned int *line_type) const
{
   *points    = _points;
   *nb_points = _nb_points;
   *line_type = _linetype;
}

INLINE unsigned char CATViz3DLine::GetStreamId() const
{
	return VIZLINE;
}

#endif
