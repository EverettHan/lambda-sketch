#ifndef CATCAfrEnum_H
#define CATCAfrEnum_H

// COPYRIGHT Dassault Systemes 2012
#include "CATAfrItf.h"
#include "CATDataType.h"

#include "CATSYPDeclareBitField.h"
#include "CATSYPDeclareBitFieldBoxing.h"
#include "CATSYPDeclareBitFieldFactory.h"


typedef CATULONG64 AfrDnDStyle;
/**
* Specifies where a drop can happen in a components.
*/
/**
* Drop is not possible anywhere.
*/
#define AfrDnDNoDropLocation ( 0 )
/**
* Dragged item can be dropped on other items.
*/
#define AfrDnDDropOn ( 1<<0 )
/**
* Dragged item can be dropped before other items. 
*/
#define AfrDnDDropBefore ( 1<<1 )
/**
* Dragged item can be dropped after other items. 
*/
#define AfrDnDDropAfter ( 1<<2 )
/**
* Dragged items can be dropped on the viewport. On that case, their drop
* position is determined by the default drop position of the model.
*/
#define AfrDnDDropViewport ( 1<<3 )

class ExportedByCATAfrItf CATCAfrEnum
{
  public:

    /**
    * Possible orientation of children.
    */
    enum Orientation 
    {
      Undef      = 0,
      Vertical   = 1, 
      Horizontal = 2
    };

    /**
    * Possible mode of selection for C-Afr List.
    */
    enum SelectionMode
    {
      /** No selection is allowed */
      NoSelection = 0,
      /** Only one element can be selected at a time */
      SingleElement = 1,
      /** Several contiguous element can be selected at a time */
      ContiguousElements = 2,
      /** Several range of contiguous element can be selected at a time */
      MultiRange = 3,
      /** Only one element can be selected at a time and the selection is cleared after*/
      SingleElementJustClick = 4,
      /** The selection state of an element is toggle when clicked, holding shift let you select a range */
      MultiToggle = 5
    };

    /**
    * Possible mode of thumbnails for C-Afr List.
    */
    enum ThumbnailsMode
    {
      /** Thumbnails with picture or text */
      Classic = 0, 
      /** ThuViewer mode */
      ThumbnailViewer = 1, 
      /** Tile mode */
      Tile = 2, 
      /** Viewer mode */
      Drafting3DMaster = 3, 
      /** Navigation Tag */
      NavigationTag = 4, 
      /** CAfrComponent */
      CAfrComponentView = 5, 
      /** QuickPick */
      QuickPick = 6, 
      /** Thumbnails with picture or text with the new specification*/
      NewClassic = 7, 
      /** Thumbnails with picture or text*/
      Basic = 8, 
      /** Tile with picture or text with the new specification*/
      NewTile = 9,
      /** Thumbnails with picture or text with the new specification 1/3*/
      Classic_Tiers = 10, 
      /** Details view*/
      Details = 11 
    };

    /**
    * Possible decorator of C-Afr Form.
    */
    enum Decorator
    {
      NoDecorator    = 0, 
      Separator      = 1, 
      Expander       = 2, 
      GroupBox       = 3, 
      Frame          = 4, 
      TabPage        = 5, 
      Left_TabPage   = 6, 
      ScrollableArea = 7
    };

    /**
    * Possible crp policy of C-Afr Form label.
    */
    enum CropPolicy
    {
      NoCrop       = 0, 
      CropCut      = 1, 
      CropWithDots = 2
    };

    /**
    * Possible icon type for message box.
    */
    enum MsgBoxIcon
    {
      NoIcon      = 0,
      Question    = 1, 
      Information = 2, 
      Warning     = 3,
      Critical    = 4
    };

    /**
    * Possible tree type expander
    */
    enum ExpanderLook{
      /**
      * Default = Right Arrow / Down Arrow
      */
      Arrow = 0,
      /**
      * Plus / Minus.
      */
      Plus,
      /**
      * Do not display the expander.
      */
      NoExpander
    };

    /**
    * Possible areas to use to dock a window to the main parent window.
    */
    enum DockArea {
      /** The window is not docked */
      NoneDockArea    = 1, 
      /** Top area of the window docking level */
      TopDockArea     = 1<<1, 
      /** Bottom area of the window docking level */
      BottomDockArea  = 1<<2, 
      /** Left area of the window docking level */
      LeftDockArea    = 1<<3, 
      /** Right area of the window docking level */
      RightDockArea   = 1<<4
    };

    /**
    * Possible areas to use to attach a window to another one.
    */
    enum SnapArea {
      NoneArea = 0, 
      OutsideArea,
      TopArea, 
      BottomArea, 
      LeftArea, 
      RightArea, 
      InsideArea
    };

	/**
	*Possible dropmode types and eventually drag modes
	*/
	enum DNDMode {
		/**
		* @li Drop: no drop received.
		*/
		Inactive = 0,
		/**
		* NOT ACTIVE. FOR FUTURE DEVELOPMENTS.
		*
		* * @li Drop: Receive drops of data stored in @ref CATVidDnD if the
        * OS DnD has not been launched (for example, CID @ref Clipboard drags).
		*/
		Clipboard,
		/**
		* @li Drop: Control only accept drops from itself. Use for controls
		* composed of smaller components, for example model/view controls.
		*/
		Itself,
		/**
		*@li Drop: Receive all drops, provided that the OS DnD has been launched.
		*/
		Internal,
		/**
		* @li Drop: Receive all drops, provided that the OS DnD has been launched.
		*/
		External
	};

    /**
     * Bitfield class for the state of a CATCmdContainer.
     * Use by CATCmdContainer class and X-Afr.
     */
    CATSYP_DECLARE_ULONG64_BITFIELD(ExportedByCATAfrItf, ContainerState)
};

// Bitfield for CATCmdContainer State property
/**
 * The CATCmdContainer object is in normal state
 */
#define CATAfrContainerNormal ( 0 )
/**
 * The CATCmdContainer object is in active state
 */
#define CATAfrContainerActive ( 1 << 0 )
/**
 * The CATCmdContainer object is in pinned state
 */
#define CATAfrContainerPinned ( 1 << 1 )

CATSYP_DECLARE_ULONG64_BITFIELDBOXING(ExportedByCATAfrItf, CATCAfrEnum, ContainerState)
CATSYP_DECLARE_ULONG64_BITFIELDFACTORY(ExportedByCATAfrItf, CATCAfrEnum, ContainerState)

#endif
