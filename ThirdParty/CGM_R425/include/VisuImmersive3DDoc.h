/**
 * @defgroup V3DCore V3D core (basic classes and utils provided by V3D.)
 * This module contains some basic components and root widgets used massively in the whole components.
 */
/**
 * @defgroup V3DFrame V3D frame (the objects used to represent VID in 3D.)
 * The 3d window used inherit from CATVidFraWindow.
 */
/**
 * @defgroup V3DGP V3D graphic primitives (all the graphic representations provided by V3D infrastructure.)
 * This module contains all the components and widgets that are part of the display of V3D. 
 * Mainly it contains the GP used as final nodes in a V3D widget tree.
 * All V3DGP inherits the CATV3DGraphicPrimitive class.
 */
/**
 * @defgroup V3DLayout V3D layout (all the layout provided by the V3D infrastructure.)
 * This module contains all the components and widgets that allow to organize widgets together.
 * @par Layout classes
 * A widget is dedicated to organize widgets together (layout) : @ref CATV3DLayCollection.
 * The 3D layout inheriting CATV3DLayCollection is @href CATV3DLay3D
 * @par Constraints classes
 * A widgets added to a layout has to be assiociated to a constraints, wich will define informations specific to the layout. 
 * The constraints associated to a V3D widget placed in a CATV3DLay3D is @href CATV3DLay3DConstraints
 */
/**
 * @defgroup V3DControls V3D controls (all the controls provided by the V3D infrastructure.)
 * This module contains all the components and widgets defining the basic controls provided by V3D.
 */

