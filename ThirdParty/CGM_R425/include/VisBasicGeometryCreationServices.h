#ifndef VisBasicPrimitiveCreationServices_H
#define VisBasicPrimitiveCreationServices_H

//  copyright dassault systemes 2011

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

//Visu fw
#include "SGInfra.h"

//Math fw
#include "CATMathConstant.h"

class CAT3DRep;

class CATMathPoint;
class CATMathAxis;
class CATMathDirection;
class CATMathVector;

/**
 *  Base services for creating canonical reps.
 *  <b>Role:</b> 
 *  Collection of services aiming at facilitating the creation of some canonicals representations.
 *  Resulting representation LifeCycle is under caller's responsability.
 *
 */


/**  
*  Constructs  a  3D  cylinder  from  its  bottom  face  center  coordinates,  its  top face center coordinates,    
*  its  radius  and  the  sag  used  for  tesselation.  
*  @param  iBottomCenterPoint  
*      Mathematical description  of  the  cylinder  bottom  extremal  face  center.  
*  @param  iTopCenterPoint  
*      Mathematical description  of  the  cylinder  top  extremal  face  center. 
*  @param  iRadius  
*      The  radius  of  the  cylinder  (iRadius > 0.0).
*  @param  iSag  
*      This  parameter  defines  the  number  of  vertices  along  the  cylinder,  
*      and  means  the  chordal  deviation  along  the  base  circle.  
*/  

extern ExportedBySGInfra CAT3DRep* CreateVis3DCylinder(const CATMathPoint &iBottomCenterPoint , const CATMathPoint &iTopCenterPoint, double iRadius, double iSag=0.0);

/**  
*  Constructs  a  3D  cone  from  its  bottom  face  center  coordinates,  its  top face center coordinates,    
*  its  bottom and top radii  and  the  sag  used  for  tesselation.  
*  @param  iBottomCenterPoint  
*      Mathematical description  of  the  cone  bottom  extremal  face  center.  
*  @param  iTopCenterPoint  
*      Mathematical description  of  the  cylinder  top  extremal  face  center. 
*  @param  iBottomRadius  
*      The  radius  of  the  bottom face (iBottomRadius >= 0.0 && max(iBottomRadius, iTopRadius) > 0.0).  
*  @param  iTopRadius  
*      The  radius  of  the  top face (iTopRadius >= 0.0 && max(iBottomRadius, iTopRadius) > 0.0).  
*  @param  iSag  
*      This  parameter  defines  the  number  of  vertices  along  the  cone,  
*      and  means  the  chordal  deviation  along  the  largest  circle.  
*/  
extern ExportedBySGInfra CAT3DRep* CreateVis3DCone    (const CATMathPoint &iBottomCenterPoint , const CATMathPoint &iTopCenterPoint, double iBottomRadius, double iTopRadius=0.0, double iSag=0.0);

/**  
*  Constructs  a  solid which permits to connect in a straight way 2 cylinders  with  different  orientations and radii from  its  bottom  face  center  coordinates and orientation,  its  top face center coordinates and orientation,    
*  its  bottom and top radii  and  the  sag  used  for  tesselation.  (not necessarily a cone from a mathematical point of view)
*  @param  iBottomCenterPoint  
*      Mathematical description  of  the  cylinder  connector  bottom  extremal  face  center.  
*  @param  iBottomNormal  
*      Mathematical description  of  the  cylinder  connector  bottom  extremal  face  normal (OUTWARD pointing. (iTopCenterPoint-iBottomCenterPoint)*iBottomNormal<0.0).  
*  @param  iTopCenterPoint  
*      Mathematical description  of  the  cylinder  connector  top  extremal  face  center.
*  @param  iTopNormal  
*      Mathematical description  of  the  cylinder  connector  top  extremal  face  normal (OUTWARD pointing. (iTopCenterPoint-iBottomCenterPoint)*iTopNormal>0.0).
*  @param  iBottomRadius  
*      The  radius  of  the  bottom face (iBottomRadius >= 0.0 && max(iBottomRadius, iTopRadius) > 0.0).  
*  @param  iTopRadius  
*      The  radius  of  the  top face (iTopRadius >= 0.0 && max(iBottomRadius, iTopRadius) > 0.0).  
*  @param  iSag  
*      This  parameter  defines  the  number  of  vertices  along  the  cone,  
*      and  means  the  chordal  deviation  along  the  largest  circle.  
*/  
extern ExportedBySGInfra CAT3DRep* CreateVis3DCone   (const CATMathPoint &iBottomCenterPoint, const CATMathDirection &iBottomNormal, const CATMathPoint &iTopCenterPoint, const CATMathDirection &iTopNormal, double iBottomRadius, double iTopRadius, double iSag=0.0);

/**  
*  Constructs  a  3D  torus  from  an axis system (defined by an origin and two directions), and two radii.
*  The  torus  is  defined  by  an  axes  system  (Axis)  and  two  radii.  
*  The  major  ring  sweeps  a  full  circle  in  the  (O,X,Y)  plane,  
*  of  radius  MajorRadius  and  centered  at  the  origin  of  the  Axis.  
*  The  minor  ring  sweeps  a  full  circle  of  radius  MinorRadius,  centered  
*  at  some  point  on  the  major  ring  and  lying  in  the  plane  
*  containing  this  center  point,  the  origin  O,  and  the  vector  Z.  
*  A  piece  of  the  full  torus  is  given  by  limiting  the  angles  
*      through  which  the  major  ring  sweeps  
*  @param  iAxisSystem  
*      The  (O,X,Y,Z)  axes  system,  whose  third  direction  Z  is  the  torus  direction.
*  @param  iMajorRadius  
*      The  major  ring  radius  on  the  plane  (O,X,Y) (iMajorRadius > 0.0).
*  @param  iMinorRadius  
*      The  minor  ring  radius  on  the  plane  (O,X,Z) (iMinorRadius > 0.0). 
*  @param  iMajorStartAngle  
*      The  low  limitation  of  the  major  ring,  measured  from  the  axis  first  direction.
*  @param  iMajorEndAngle  
*      The  high  limitation  of  the  major  ring,  measured  from  the  axis  first  direction. 
*  @param  iSag  
*      This  parameter  defines  the  number  of  vertices  along  the  torus,     
*/  
extern ExportedBySGInfra CAT3DRep* CreateVis3DTorus    (const CATMathAxis &iAxisSystem,
                                                                 double iMajorRadius,
                                                                 double iMinorRadius,
                                                                 CATAngle iMajorStartAngle=0.0,
                                                                 CATAngle iMajorEndAngle=CAT2PI,
                                                                 double iSag=0.0);


/**
* @nodoc
* Interface representing a geometric sphere.
* Constructs  a  3D  sphere  from  an axis system and one radius.
* <table>
*  @param  iAxisSystem  
*      The (O,X,Y,Z)  axes  system, whose center is the spere center.
*  @param  iRadius  
*      The Sphere Radius (iRadius > 0.0).  
*  @param  iMeridianStart  
*      The low limitation of the meridians existence.
*  @param  iMeridianStart  
*      The high limitation of the meridians existence.
*  @param  iMeridianStart  
*      The low limitation of the parallels existence.
*  @param  iMeridianStart  
*      The high limitation of the parallels existence.
*  @param  iSag  
*      This  parameter  defines  the  number  of  vertices  along  the  sphere, 
* The meridian planes are passing through the axis third direction.
* The parallel planes are othogonal to the axis third direction.
* -Pi/2 <= ParallelStart < Pi/2, ParallelStart < ParallelEnd <= Pi/2, 
*     0 <= MeridianStart < 2*Pi, MeridianStart < MeridianEnd <= 2*Pi.
*/
extern ExportedBySGInfra CAT3DRep* CreateVis3DSphere   (const CATMathAxis &iAxisSystem,
                                                                 double iRadius,
                                                                 CATAngle iMeridianStart=0.0,
                                                                 CATAngle iMeridianEnd=CAT2PI,
                                                                 CATAngle iParallelStart=-CATPIBY2,
                                                                 CATAngle iParallelEnd=CATPIBY2,
                                                                 double iSag=0.0);

/**
* @nodoc
* Interface representing a 3D box.
* Constructs the representation of a box from a corner and 3 vectors.
* @param iCornerPoint
*     The reference corner of the box.
* @param iFirstAxis
*     The orientation and the length of the box along the first direction.
* @param iSecondAxis
*     The orientation and the length of the box along the second direction.
* @param iThirdAxis
*     The orientation and the length of the box along the third direction.
*/
extern ExportedBySGInfra CAT3DRep* CreateVis3DCuboid   (const CATMathPoint  &iCornerPoint,
                                                                 const CATMathVector &iFirstAxis,
                                                                 const CATMathVector &iSecondAxis,
                                                                 const CATMathVector &iThirdAxis);

/**  
*  Constructs  a  3D  tube  (perforated cylinder) from  its  bottom  face  center  coordinates,  its  top face center coordinates,    
*  its  internal/external radii  and  the  sag  used  for  tesselation.  
*  @param  iBottomCenterPoint  
*      Mathematical description  of  the  tube  bottom  extremal  face  center.  
*  @param  iExtrusionVector  
*      The vector along which the tube is extruded (Norm of iExtrusion vector must be > 0.0). 
*  @param  iInternalRadius  
*      The  internal  radius  of  the  tube (0.0 <= iInternalRadius < iExternalRadius).
*  @param  iExternalRadius  
*      The  external  radius  of  the  tube (0.0 <= iInternalRadius < iExternalRadius).
*  @param  iSag  
*      This  parameter  defines  the  number  of  vertices  along  the  tube,  
*      and  means  the  chordal  deviation  along  the  base  circle.  
*/  
extern ExportedBySGInfra CAT3DRep* CreateVis3DTube   (const CATMathPoint  &iBottomCenterPoint,
                                                               const CATMathVector &iExtrusionVector,
                                                               double iInternalRadius,
                                                               double iExternalRadius,
                                                               double iSag=0.0);

#endif
