#ifndef CAT2DLineGP_H
#define CAT2DLineGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"

#include "CATGraphicPrimitive.h"
#include "list.h"
#include "CATVizMacForMetaClass.h"
#include "CAT2DGeomTextStructures.h"

class CATMathPoint2Df;
class CAT2DGeometricTextGP;
class CATStreamer;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG2DPolyline;
class CAT2DLineGPIVisSG2DPolylineBOAImpl;
//-- SGCAAPlan

/** @nodoc */
#define LINES      0
/** @nodoc */
#define LINE_STRIP 1
/** @nodoc */
#define LINE_LOOP  2

/**
 * Class to create the graphic primitive of a 2D line.
 */
class ExportedBySGInfra CAT2DLineGP : public CATGraphicPrimitive
{
 CATDeclareClass;
 CATVizDeclareClass;
 CATVisDeclarePublicInterfaceAdhesion(CAT2DLineGP, IVisSG2DPolyline, CAT2DLineGPIVisSG2DPolylineBOAImpl);

public :

/**
 * Default constructor.
 */
   CAT2DLineGP ();

/**
* Constructs a 2D line graphic primitives from point coordinates.
* @param iPoints
*    Array of point coordinates: XYXYXY...
*    Its size is equal to two times the number of points.
* @param iNbPoints
*    The number of points.
* @param iAlloc
*    Flag used to specify whether points must be duplicated or not.
*    <br><b>Legal values</b>:
*    <ul>
*      <li>ALLOCATE :
*        All data are duplicate into the graphic primitive</li>
*      <li>DONT_ALLOCATE
*        The graphic primitive has a pointer to the data given as parameter</li>
*    </ul>
*    The default value is ALLOCATE.
* @param iLineType
*    Flag to specify the line type to use.
*    <br><b>Legal values</b>:
*    <ul>
*      <li>LINES :
*        The number of points must be even. A line will be drawn
*            between points 1 and 2, another line will be drawn between
*            points 3 and 4, ...
*			<pre>
*                       point 1 X--------------------X point 2
*                                                   point 3 X-----------------------X point 4
*			</pre>
*		</li>
*      <li>LINE_STRIP :
*        The number of points can be either even or odd. A line will
*            be drawn between points 1 and 2, then, another line will be drawn
*            between points 2 and 3, ...
*			<pre>
*                       point 1 X--------------------X point 2
*                                                   /
*                                                 /
*                                               /
*                                      point 3 X----------------------X point 4
*			</pre>
*		</li>
*      <li>LINE_LOOP :
*        Same as LINE_LOOP, excepted that one more line will be
*            drawn between the last and the first points.
*			<pre>
*                                    point 1 X--------X point 2
*                                             \      /
*                                              \    /      
*                                               \  /
*                                                \/
*                                                /\
*                                               /  \
*                                      point 3 X----X point 4
*			</pre>
*		</li>
*    </ul>
*    The default value is LINES.
*/
   CAT2DLineGP (const float iPoints[], const int iNbPoints=2,
                const int iAlloc=ALLOCATE, const int iLinetype = LINES);

/**
* Constructs a 2D line graphic primitives from points.
* @param iPoints
*    Array of 2D points.
*    Its size is equal to the number of points.
* @param iNbPoints
*    The number of points.
* @param iAlloc
*    Flag used to specify whether points must be duplicated or not.
*    <br><b>Legal values</b>:
*    <ul>
*      <li>ALLOCATE :
*        All data are duplicate into the graphic primitive</li>
*      <li>DONT_ALLOCATE
*        The graphic primitive has a pointer to the data given as parameter</li>
*    </ul>
*    The default value is ALLOCATE.
* @param iLineType
*    Flag to specify the line type to use.
*    <br><b>Legal values</b>:
*    <ul>
*      <li>LINES :
*        The number of points must be even. A line will be drawn
*            between points 1 and 2, another line will be drawn between
*            points 3 and 4, ...
*			<pre>
*                       point 1 X--------------------X point 2
*                                                   point 3 X-----------------------X point 4
*			</pre>
*		</li>
*      <li>LINE_STRIP :
*        The number of points can be either even or odd. A line will
*            be drawn between points 1 and 2, then, another line will be drawn
*            between points 2 and 3, ...
*			<pre>
*                       point 1 X--------------------X point 2
*                                                   /
*                                                 /
*                                               /
*                                      point 3 X----------------------X point 4
*			</pre>
*		</li>
*      <li>LINE_LOOP :
*        Same as LINE_LOOP, excepted that one more line will be
*            drawn between the last and the first points.
*			<pre>
*                                    point 1 X--------X point 2
*                                             \      /
*                                              \    /      
*                                               \  /
*                                                \/
*                                                /\
*                                               /  \
*                                      point 3 X----X point 4
*			</pre>
*		</li>
*    </ul>
*    The default value is LINES.
*/
   CAT2DLineGP (const CATMathPoint2Df iPoints[], const int nbPoints=2,
                const int alloc=ALLOCATE, const int iLinetype = LINES);  
 
/**
* Retrieves line parameters, such as points coordinates, number of points and line type.
* <b>Role</b>: To retrieve line parameters. This method must be called like this :
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
*    <ul>
*      <li>LINES :
*        The number of points must be even. A line will be drawn
*            between points 1 and 2, another line will be drawn between
*            points 3 and 4, ...
*			<pre>
*                       point 1 X--------------------X point 2
*                                                   point 3 X-----------------------X point 4
*			</pre>
*		</li>
*      <li>LINE_STRIP :
*        The number of points can be either even or odd. A line will
*            be drawn between points 1 and 2, then, another line will be drawn
*            between points 2 and 3, ...
*			<pre>
*                       point 1 X--------------------X point 2
*                                                   /
*                                                 /
*                                               /
*                                      point 3 X----------------------X point 4
*			</pre>
*		</li>
*      <li>LINE_LOOP :
*        Same as LINE_LOOP, excepted that one more line will be
*            drawn between the last and the first points.
*			<pre>
*                                    point 1 X--------X point 2
*                                             \      /
*                                              \    /      
*                                               \  /
*                                                \/
*                                                /\
*                                               /  \
*                                      point 3 X----X point 4
*			</pre>
*		</li>
*    </ul>
*/
   inline void Get (float **oPoints, int *oNbPoint, int *oLineType) const;

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
   inline void     SetTessStatus (TessFlag tessStatus);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif
   /**
* Draws the 2D line.
* @param iRender
*    The render through which the 2D line is drawn.
*/
   virtual void Draw (CATRender & iRender) GP_FUNC_OVERRIDE_FINAL;

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
 */
   virtual int DetailCulling(CATRender *render);

/**
 * @nodoc
 */
   virtual void ReverseLineRoute();

/**
 * @nodoc
 */
   virtual void Visit(CATIGPVisitor& iVisitor) const final;

//--------------------------------------------------------------------------------
 
 protected :

   virtual ~CAT2DLineGP();
     
//--------------------------------------------------------------------------------

 private :

   float *_points;
   int   _nb_points;
   int   _linetype;
   int   _alloc;
   TessFlag _TessStatus;
   CAT2DGeomTextPolylineList * _polylineList;
};
    
//--------------------------------------------------------------------------------

inline void CAT2DLineGP::Get(float **points, 
                             int *nb_points, 
                             int *line_type) const
{
 *points    = _points;
 *nb_points = _nb_points;
 *line_type  = _linetype;
}

inline TessFlag CAT2DLineGP::GetTessStatus (void)
{
  return _TessStatus;
}

inline void CAT2DLineGP::SetTessStatus (TessFlag tessStatus)
{
  _TessStatus = tessStatus;
}

#endif
