/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

/**
 * @defgroup VIDCore VID core (basic classes and utils provided by VID.)
 * This module contains some basic components and root widgets used massively in the whole components.
 */
/**
 * @defgroup VIDFrame VID frame (the objects used to represent and organize dialog boxes.)
 * This module contains all the components and widgets defining the dialog box infrastructure of VID.
 * All dialog box inherit CATVidFraWindow.
 * @image html class_c_a_t_vid_fra_window__inherit__graph.png "Inherit graph of CATVidFraWindow"
 */
/**
 * @defgroup VIDGP VID graphic primitives (all the graphic representations provided by VID infrastructure.)
 * This module contains all the components and widgets that are part of the display of VID. 
 * Mainly it contains the GP used as final nodes in a VID widget tree.
 * All GP inherits the @c CATVidGP class.
 * @image html class_c_a_t_vid_g_p__inherit__graph.png "Inherit graph of CATVidGP"
 */
/**
 * @defgroup VIDLayout VID layout (all the layout provided by the VID infrastructure.)
 * This module contains all the components and widgets that allow to organize widgets together.
 * @par Layout classes
 * A widget is dedicated to organize widgets together (layout) : @ref CATVidLayCollection.
 * Here are the available layout inheriting CATvidLayCollection :
 *    - @href CATVidLayGrid
 *    - @href CATVidLayDock
 *    - @href CATVidLayFlow
 *    - @href CATVidLaySideAttach
 *    - @href CATVidLayStack
 *    - @href CATVidLaySideAttach
 * @par Constraints classes
 * A widgets added to a layout has t obe assiociated to a constraints, wich will define informations specific to the layout. 
 * Thus there is one constraints class per available layout.
 * @image html class_c_a_t_vid_lay_constraints__inherit__graph.png "Inherit graph of CATVidLayConstraints"
 */
/**
 * @defgroup VIDControls VID controls (all the controls provided by the VID infrastructure.)
 * This module contains all the components and widgets defining the basic controls provided by VID.
 */

