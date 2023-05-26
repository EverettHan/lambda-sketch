#ifndef CATViewerUtility_H
#define CATViewerUtility_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */



/** 
* Type of viewer's behaviours.
* <br><b>Role</b>: This type is used in @href CATViewer, @href CAT3DViewer, @href CAT2DViewer ...
*  @param CATViewerBasicIcons
*   Displays a frame over the graphic zone to display the basic viewpoint
*   operations icons. (Refrane, etc...)
*  @param CATViewerScrollbars 
*   Displays vertical and horizontal scrollbars
*  @param CATUpAnchor
*   Sets vertically the anchor at the top of the window (Default=center)
*  @param CATDownAnchor 	
*   Sets vertically the anchor at the bottom of the window (Default=center)
*  @param CATLeftAnchor 	
*   Sets horizontally the anchor at the left of the window (Default=center)
*  @param CATRightAnchor 	
*   Sets horizontally the anchor at the right of the window (Default=center)
*/
typedef unsigned long CATViewerStyle;

// Viewer (2D and 3D)
//-------------------
/** @nodoc */
#define CATViewerBasicIcons          (1 << 1)
/** @nodoc */
#define CATViewerNoIndicator         (1 << 2)
/** @nodoc */
#define CATViewerAlwaysDrawn         (1 << 4)

// 2DViewer
//---------
/** @nodoc */
#define CATViewerScrollbars          (1 << 3)

/** @nodoc */
#define CATViewerHScrollbar          (1 << 9)
/** @nodoc */
#define CATViewerVScrollbar          (1 << 10)

/** @nodoc */
#define CATUpAnchor                  (1 << 5)	
/** @nodoc */
#define CATDownAnchor                (1 << 6)
/** @nodoc */
#define CATLeftAnchor                (1 << 7)
/** @nodoc */
#define CATRightAnchor               (1 << 8)


//******************************************************************************
//  Viewer interactive state:
//  -------------------------
//******************************************************************************

/** @nodoc */
enum ViewerInteractiveState { ObjectNotChoosen,
			      ObjectChoosen,
			      ObjectTaken,
			      ObjectManipulate,
			      ObjectContext,
			      ObjectEdit };


//******************************************************************************
//  Picking style management:
//  ------------------------
//******************************************************************************

/**
* Style to define the way to generate a pick path list.
* <b>Role</b>:This style is used in the @href CATViewer#Pick method.
* @param CATPicking
* It's the simple picking to make the pre-highlight.
* @param CATPickingInside
* An object is selected if it is completly inside the rectangle. The picking is associated to this
* rectangle. 
* @param CATPickingNoOutside
* An object is selected if it is not completly out the polygon. The picking is associated to this
* rectangle. 
* @param CATDrillDecoding
* Internal use. Do not use this value.
* @param CATPickingInsidePolygon 
* An object is selected if it is completly inside the polygon. The picking is associated to this
* polygon. 
* @param CATNormalPicking
* Internal use. Do not use this value.
* @param CATPickingOutside
* An object is selected if it is completly outside the rectangle. The picking is associated to this
* rectangle. 
* @param CATPickingNoInside
* An object is selected if it is not completly in the polygon. The picking is associated to this
* rectangle. 
* @param CATPickingSubEltsNoOutside
* An object is selected if it is not completly out the polygon. The picking is associated to this
* rectangle. Returned picked pathes can include sub-elements
* @param CATPickingSubEltsNoOutsideAndVisible
* An object is selected if it is not completly out the polygon. The picking is associated to this
* rectangle. Returned picked pathes can include sub-elements. Only visible elements and elements 
* joining visible elements are picked.
*/
enum CATPickingStyle {  CATPicking,
                        CATPickingInside,
                        CATPickingNoOutside,
                        CATDrillDecoding, 
                        CATPickingInsidePolygon,
                        CATNormalPicking,
                        CATPickingOutside,
                        CATPickingNoInside,
                        CATNeighbourhoodPicking = 9,
                        CATPickingSubEltsInside = 10,
                        CATPickingSubEltsInsideAndVisible = 11,
                        CATPickingVolume = 12,                        
                        CATPickingSubEltsNoOutside = 13,                        
                        CATPickingSubEltsNoOutsideAndVisible = 14,
                        CATPickingClosed = 15};

/** @nodoc */
typedef CATPickingStyle PickingStyle ;

/** 
* Position of the viewer.
* @param Background
*  The viewer is set in back of  
* @param Last
*  not used
* @param Foreground
*  The viewer is set in front of  
* @param First
*  not used
* @see CATViewer
*/
enum CATViewerPlacement { Background=0, Last=0, Foreground=1, First=1};

/**
* <b>Visual mode management.</b>
*   <br>
*    These values are used in these methods :
*    <ul>
*    <li>@href CATSupport#SetViewMode </li>
*    <li>@href CATSupport#ViewMode, </li>
*    <li>@href CATSupport#GetViewMode , </li>
*    <li>@href CATViewer#SetViewMode and </li>
*    <li>@href CATViewer#ViewMode. </li>
*    </ul>
*   <br>
* The rules to get the OutputMode for a RequestedMode to be added or removed from the CurrentMode are listed below:
*    <ul>
*     <li> Note.1 : Activation Rules A## are opposite of DeActivation Rules D##. </li>
*     <li> Note.2 : Exclusion rules E## are symmetric but order dependent. </li> 
*     <li> Note.3 : Each of the view modes VIEW_WITHOUT_WIRES, VIEW_WITHOUT_AXIS, VIEW_WITHOUT_POINTS is independent of all other view modes; except when VIEW_EDGE is removed these three are also removed. </li>
*    </ul>
* <b>Deactivation</b>: When the RequestedMode is to be removed from the CurrentMode 
*    <ul>
*     <li> <b> STEP.D0</b> : Initialize OutputMode to CurrentMode. </li> 
*     <li> <b>STEP.D1</b> : Consider the modes on (-) side as ModesToRemove, if the RequestedMode is on (=) side of (=>-) DeActivate operator in D## DeActivation Rules. </li>
*     <ul>
* <li> <b>D01</b>. VIEW_EDGE    =>-  VIEW_WITHOUT_SMOOTH_EDGE, VIEW_WITH_HALF_SMOOTH_EDGE, VIEW_WITHOUT_VERTEX, VIEW_COLORED_EDGES_FROM_FACES, VIEW_LINEONLINE, VIEW_HRD, VIEW_HIDDEN_EDGE, VIEW_WITHOUT_WIRES, VIEW_WITHOUT_AXIS, VIEW_WITHOUT_POINTS </li>
* <br>
* <li> <b>D02</b>. VIEW_MESH    =>-  VIEW_MATERIAL, VIEW_POLYGON, VIEW_TRANSPARENT, VIEW_TOON, VIEW_HRD, VIEW_HIDDEN_EDGE,VIEW_RAYTRACING </li>
*   <br>
* <li> <b>D03</b>. VIEW_OUTLINE =>-  VIEW_HRD </li>
* Exception : If the RequestedMode contains VIEW_HLR and CurrentMode contains VIEW_HIDDEN_EDGE then add VIEW_MESH and VIEW_EDGE to OutputMode
* <li> <b>A04</b>. VIEW_HIDDEN_EDGE            =>+ VIEW_MESH, VIEW_EDGE </li>
*   <br>
* </ul>
*     <li> <b>STEP.D2</b> : Remove the RequestedMode and the ModesToRemove from the OutputMode </li>
*    </ul>
* 
* <b>Activation</b>: When the RequestedMode is to be added to the CurrentMode
*    <ul>
*     <li> <b>STEP.A0</b> : Initialize OutputMode to CurrentMode  </li>
*     <li> <b>STEP.A1</b> : Consider the modes on (+) side, as ModesToAdd, if the RequestedMode is on (=) side of (+<=) Activate operator in A## Activation Rules.  </li>
*     <ul>
* <li> <b>A01</b>. VIEW_EDGE    +<=  VIEW_WITHOUT_SMOOTH_EDGE, VIEW_WITH_HALF_SMOOTH_EDGE, VIEW_WITHOUT_VERTEX, VIEW_COLORED_EDGES_FROM_FACES, VIEW_LINEONLINE, VIEW_HRD, VIEW_HIDDEN_EDGE  </li>
* <br>
* <li> <b>A02</b>. VIEW_MESH    +<=  VIEW_MATERIAL, VIEW_POLYGON, VIEW_TRANSPARENT, VIEW_TOON, VIEW_HRD, VIEW_HIDDEN_EDGE, VIEW_RAYTRACING</li>
* <br>
* <li> <b>A03</b>. VIEW_OUTLINE +<=  VIEW_HRD  </li>
* Exception : Rules A01 and A02 are applicable for VIEW_HIDDEN_EDGE only if the CurrentMode does not contain VIEW_HLR
* <br>
*    </ul>
*     <li> <b>STEP.A2</b> : Add the RequestedMode and the ModesToAdd to the OutputMode   </li>
*     <li> <b>STEP.A3</b> : Update the RequestedMode and OutputMode by excluding the modes on (x) side if RequestedMode is on (=) side of (x<=) Exclude operator in E## Exclusion Rules.   </li>
* Note  : The Exclusion Rules are executed in the following order and consider the RequestedMode updated by previous rule.
* <br>
*    <ul>
* <br>
* <li> <b>E00</b>. VIEW_HLR x<= VIEW_MESH, VIEW_MATERIAL, VIEW_EDGE, VIEW_WITHOUT_SMOOTH_EDGE, VIEW_WITH_HALF_SMOOTH_EDGE, VIEW_OUTLINE, VIEW_HRD  </li>
* Exception : If OutputMode contains VIEW_HIDDEN_EDGE then add VIEW_MESH and VIEW_EDGE
* <br>
* <li> <b>A04</b>. VIEW_HIDDEN_EDGE            =>+ VIEW_MESH, VIEW_EDGE  </li>
* <br>
* <li> <b>E00</b>. VIEW_HLR x<= VIEW_POLYGON, VIEW_TRANSPARENT,  VIEW_TOON, VIEW_LINEONLINE, VIEW_COLORED_EDGES_FROM_FACES, VIEW_REP_OVERLOAD, VIEW_ISOPARS   </li>
* <br>
* <li> <b>E01</b>. VIEW_WITHOUT_SMOOTH_EDGE    =>x  VIEW_WITH_HALF_SMOOTH_EDGE, VIEW_TOON  </li>
* <br>
* <li> <b>E02</b>. VIEW_WITH_HALF_SMOOTH_EDGE  =>x  VIEW_WITHOUT_SMOOTH_EDGE, VIEW_TOON  </li>
* <br>
* <li> <b>E03</b>. VIEW_TOON                   x<= VIEW_EDGE, VIEW_OUTLINE  </li>
* <br>
* <li> <b>E04</b>. VIEW_POLYGON                =>x VIEW_MATERIAL, VIEW_HIDDEN_EDGE, VIEW_HRD, VIEW_TOON, VIEW_TRANSPARENT, VIEW_LINEONLINE, VIEW_COLORED_EDGES_FROM_FACES, VIEW_REP_OVERLOAD, VIEW_RAYTRACING</li>
* <br>
* <li> <b>E05</b>. VIEW_ISOPARS                =>x VIEW_TOON, VIEW_TRANSPARENT, VIEW_LINEONLINE, VIEW_REP_OVERLOAD  </li>
* <br>
* <li> <b>E06</b>. VIEW_HIDDEN_EDGE            =>x VIEW_POLYGON, VIEW_TOON, VIEW_TRANSPARENT, VIEW_COLORED_EDGES_FROM_FACES, VIEW_LINEONLINE  </li>
* <br>
* <li> <b>E07</b>. VIEW_MATERIAL               =>x VIEW_HRD, VIEW_POLYGON, VIEW_TOON, VIEW_TRANSPARENT, VIEW_LINEONLINE, VIEW_COLORED_EDGES_FROM_FACES  </li>
* <br>
* <li> <b>E08</b>. VIEW_HRD                    =>x VIEW_MATERIAL, VIEW_POLYGON, VIEW_TOON, VIEW_TRANSPARENT, VIEW_LINEONLINE, VIEW_COLORED_EDGES_FROM_FACES, VIEW_RAYTRACING  </li>
* <br>
* <li> <b>E09</b>. VIEW_HLR                    =>x VIEW_MESH, VIEW_EDGE, VIEW_WITH_HALF_SMOOTH_EDGE, VIEW_WITHOUT_SMOOTH_EDGE, VIEW_OUTLINE, VIEW_MATERIAL, VIEW_HRD, VIEW_POLYGON, VIEW_ISOPARS, VIEW_TOON, VIEW_TRANSPARENT, VIEW_LINEONLINE, VIEW_COLORED_EDGES_FROM_FACES, VIEW_REP_OVERLOAD  </li>
* <br>
* <li> <b>E10</b>. VIEW_TOON                   =>x VIEW_EDGE, VIEW_WITH_HALF_SMOOTH_EDGE, VIEW_WITHOUT_SMOOTH_EDGE, VIEW_HIDDEN_EDGE, VIEW_MATERIAL, VIEW_OUTLINE, VIEW_HRD, VIEW_POLYGON, VIEW_ISOPARS, VIEW_TRANSPARENT, VIEW_LINEONLINE, VIEW_REP_OVERLOAD  </li>
* <br>
* <li> <b>E11</b>. VIEW_TRANSPARENT            =>x VIEW_HIDDEN_EDGE, VIEW_MATERIAL, VIEW_HRD, VIEW_POLYGON, VIEW_ISOPARS, VIEW_TOON, VIEW_LINEONLINE, VIEW_COLORED_EDGES_FROM_FACES, VIEW_REP_OVERLOAD  </li>
* <br>
* <li> <b>E12</b>. VIEW_LINEONLINE             =>x VIEW_MESH, VIEW_HIDDEN_EDGE, VIEW_MATERIAL, VIEW_OUTLINE, VIEW_HRD, VIEW_POLYGON, VIEW_ISOPARS, VIEW_TRANSPARENT, VIEW_TOON, VIEW_REP_OVERLOAD  </li>
* <br>
* <li> <b>E13</b>. VIEW_MESH                   =>x VIEW_LINEONLINE, VIEW_COLORED_EDGES_FROM_FACES  </li>
* <br>
* <li> <b>E14</b>. VIEW_OUTLINE                =>x VIEW_COLORED_EDGES_FROM_FACES, VIEW_LINEONLINE  </li>
* <br>
* <li> <b>E15</b>. VIEW_COLORED_EDGES_FROM_FACES =>x VIEW_MESH, VIEW_HIDDEN_EDGE, VIEW_MATERIAL, VIEW_OUTLINE, VIEW_HRD, VIEW_POLYGON, VIEW_TRANSPARENT, VIEW_REP_OVERLOAD  </li>
* <br>
* Exception : Exclude VIEW_REP_OVERLOAD from the OutputMode if it contains any of the modes below
* <li> <b>E16</b>. VIEW_REP_OVERLOAD  x<= VIEW_COLORED_EDGES_FROM_FACES, VIEW_LINEONLINE, VIEW_TRANSPARENT, VIEW_TOON, VIEW_ISOPARS, VIEW_POLYGON, VIEW_HLR, VIEW_RAYTRACING  </li>
* <br>
* <li> <b>E17</b>. VIEW_RAYTRACING             =>x VIEW_REP_OVERLOAD, VIEW_POLYGON, VIEW_HRD, VIEW_LINEONLINE, VIEW_COLORED_EDGES_FROM_FACES</li>
* <br>
*    </ul>
*    </ul>
*
*  @param VIEW_NO_DISPLAY
*   No objects are seen.
*  @param VIEW_MESH
*   Face of 3D objects are seen in shading.
*  @param VIEW_EDGE
*   Edge of 3D objects are seen.
*  @param VIEW_OUTLINE
*   Lines wich form the shadow of 3D objects are seen.
*  @param VIEW_MATERIAL
*   The rendering takes account of @href CATGraphicMaterial set on 3D object
*  @param VIEW_HLR
*   Hidden Line Removal: compute by software.
*  @param VIEW_HRD
*   Hidden Line Removal: compute by hardware.
*  @param VIEW_HIDDEN_EDGE
*   Hidden Edges of faces are seen in dashed line.
*  @param VIEW_POLYGON
*   See all the polygons that constitute the faces of 3D objects.
*  @param VIEW_ISOPARS
*   Face are drawn with isoparametric lines.
*  @param VIEW_TOON
*   This mode is not implemented. 
*  @param VIEW_TRANSPARENT
*   All the geometry will be drawn half transparent.
*  @param VIEW_REP_OVERLOAD
*   Rendering style defined per object will be considered.
*  @param VIEW_WITH_HALF_SMOOTH_EDGE
*   Faces are drawn with edges but with half lighted smooth edges.
*  @param VIEW_WITHOUT_SMOOTH_EDGE
*   Faces are drawn with edges but without smooth edges.
*  @param VIEW_LINEONLINE
*   Enables to visualize superimposed lines by displaying them in a different color.
*  @param VIEW_WITHOUT_VERTEX
*   Points are drawn but vertices are not.
*  @param VIEW_COLORED_EDGES_FROM_FACES 
*   The Edges are colored according to the shading faces color. 
*   Each edge has the same color as its adjacent faces. For internal edges, if the two adjacent faces 
*   have two different colors, the edge is painted with the color of the face whose bounding sphere radius is the smallest.
*  @param VIEW_WITHOUT_WIRES
*   Deactivates the display of wires.
*  @param VIEW_WITHOUT_AXIS
*   Deactivates the display of axes and axis systems.
*  @param VIEW_WITHOUT_POINTS
*   Deactivates the display of points.
*  @param VIEW_RAYTRACING
*   Face of 3D objects are displayed using ray tracing.
*/

typedef int CATViewModeType ;

/** @nodoc */
#define VIEW_NO_DISPLAY             (0x0)
/** @nodoc */
#define VIEW_MESH                   (0x1)
/** @nodoc */
#define VIEW_EDGE                   (0x2)
/** @nodoc */
#define VIEW_OUTLINE                (0x4)
/** @nodoc */
#define VIEW_MATERIAL               (0x8)
/** @nodoc */
#define VIEW_HLR                    (0x10)
/** @nodoc */
#define VIEW_HRD                    (0x20)
/** @nodoc */
#define VIEW_HIDDEN_EDGE            (0x40)
/** @nodoc */
#define VIEW_POLYGON                (0x80)
/** @nodoc */
#define VIEW_ISOPARS                (0x100)
/** @nodoc */
#define VIEW_TOON                   (0x200)
/** @nodoc */
#define VIEW_TRANSPARENT            (0x400)
/** @nodoc */
#define VIEW_REP_OVERLOAD           (0x800)
/** @nodoc */
#define  VIEW_WITH_HALF_SMOOTH_EDGE (0x1000)
/** @nodoc */
#define  VIEW_WITHOUT_SMOOTH_EDGE   (0x2000)
/** @nodoc */
#define  VIEW_LINEONLINE            (0x4000)
/** @nodoc */
#define  VIEW_WITHOUT_VERTEX        (0x8000)
/** @nodoc */
#define  VIEW_COLORED_EDGES_FROM_FACES (0x10000)
/** @nodoc */
#define  VIEW_WITHOUT_WIRES         (0x20000)
/** @nodoc */
#define  VIEW_WITHOUT_AXIS          (0x40000)
/** @nodoc */
#define  VIEW_WITHOUT_POINTS        (0x80000)
/** @nodoc */
#define  VIEW_WITHOUT_CONSTRAINTS   (0x100000)
/** @nodoc */
#define  VIEW_RAYTRACING            (0x200000)
/** @nodoc */
#define  VIEW_WITHOUT_SMALL_CURVATURE_STEP_EDGE (0x20000000)


/** @nodoc */
typedef int Background3DViewMode;
/** @nodoc */
#define BCKGRD3D_NOT_ACTIVATED  (0x0)
/** @nodoc */
#define BCKGRD3D_LOWLIGHT       (0x1)
/** @nodoc */
#define BCKGRD3D_NO_DISPLAY     (0x2)
/** @nodoc */
#define BCKGRD3D_NO_PICK        (0x4)
/** @nodoc */
#define BCKGRD3D_FOG            (0x8)
/** @nodoc */
#define BCKGRD3D_GHOST_LOOK     (0x10)
/** @nodoc */
#define BCKGRD3D_INVERSE        (0x20)

/**
* Camera type.
* @param CAT3DConicCamera
*   for a 3D perspective projection
* @param CAT3DCylindricCamera
*   for a 3D Cylindric projection
* @param CAT3DUnknownCamera
*   for any 3D type projection
* @param CAT2DCamera
*   for a 2D view
*/
enum  CATCameraType {CAT3DConicCamera, CAT3DCylindricCamera, CAT3DUnknownCamera, CAT2DCamera};

/**
* Orientation of the world axis system.
* @param CATVis_World_Orientation_ZUp_YRight
*   for a world orientation with the z axis up and the y axis right for front orientation.
* @param CATVis_World_Orientation_YUp_XRight
*   for a world orientation with the y axis up and the x axis right for front orientation.
*/
enum  CATVisWorldOrientation { CATVis_World_Orientation_ZUp_YRight, CATVis_World_Orientation_YUp_XRight};


#endif
