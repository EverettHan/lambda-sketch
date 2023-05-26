#ifndef CATVid_H
#define CATVid_H

#include <VisuDialog.h>
#include <CATListOfCATUnicodeString.h>
#include <CATSYPDeclareEnumFactory.h>
#include <CATSYPArray.h>
#include <CATGraphicMaterial.h>

class CATBaseUnknown_var;
class CATVidWidget;
class CATISYPIntrospectable_var;
class CATUnicodeString;
class CATSYPTemplateData;
class CATVidFraWindow;
class CATMathVector2Df;
class CATMathPoint2Df;
class CATSYPDataBlockFactory;
class CATSYPDataBlock;

/**
* @ingroup VIDCore
*/
class ExportedByVisuDialog CATVid
{
public:
  /**
  * Generates the view for the given data item using the given data template.
  *
  * @param i_spLeftObject introspectable object for which a view must be built.
  * Can't be NULL_var, can't be a standard vid control.
  *
  * @param i_styleSheet the stylesheet name that contains the data template to use.
  * Can't be an empty string.
  *
  * @param i_dataTemplate the data template to use to build the view of the item.
  * Can't be an empty string.
  *
  * @return the generated widget in case of success, or NULL otherwise.
  * The widget returned has a reference counter of 1.
  */
  static CATVidWidget* GenerateUsingDataTemplate(const CATISYPIntrospectable_var& i_spLeftObject, const CATUnicodeString & i_styleSheet, const CATUnicodeString & i_dataTemplate, CATSYPTemplateData * o_pTemplateData);

  /**
  * Generate a template from a string and builds a view of it. This string defines one template where the target matches the i_spLeftObject's type.
  * Note that this generation is not performant because template are not saved in the current style processor and re-generated at each time you call this method
  * @param i_spLeftObject introspectable object for which a view must be built.
  * @param i_templateAsString the string that represents one template where the target matches the i_spLeftObject's type
  * @return the generated view is succedded else return NULL.
  * The widget returned has a reference counter of 1.
  */
  static CATVidWidget* GenerateUsingTemplateAsString(const CATISYPIntrospectable_var& i_spLeftObject, const CATUnicodeString & i_dataTemplateAsString);

  /**
  * Same behaviour than the previous function, but when a stylesheet is not needed.
  */
  static CATVidWidget* GenerateUsingDataTemplate(const CATISYPIntrospectable_var& i_spLeftObject, const CATUnicodeString & i_dataTemplate, CATSYPTemplateData * o_pTemplateData);
  /**
  * Add this stylesheet to the user style processor.
  * It won't be processed if it has already been.
  * @param i_styleSheet the stylesheet to add.
  * @param i_fullPathFlag if FALSE, the file will be searched in standard resources paths.
  */
  static void AddResources(const CATUnicodeString& i_styleSheet, CATBoolean i_fullPathFlag);
 /**
  * Generates the data block factory using the given data block factory template.
  *
  * @param i_styleSheet the stylesheet name that contains the data block factory template to use.
  * Can't be an empty string.
  *
  * @param i_dataBlockFactoryTemplate the data block factory template to use to build the data block factory.
  * Can't be an empty string.
  *
  * @return the generated data block factory in case of success, or NULL otherwise.
  */
  static CATSYPDataBlockFactory* GenerateDataBlockFactoryFromTemplate(const CATUnicodeString & i_styleSheet, const CATUnicodeString & i_dataBlockFactoryTemplate);
 /**
  * Generates the data block factory using the given data block factory template (already loaded previously).
  *
  * @param i_dataBlockFactoryTemplate the data block factory template to use to build the data block factory.
  * Can't be an empty string.
  *
  * @return the generated data block factory in case of success, or NULL otherwise.
  */
  static CATSYPDataBlockFactory* GenerateDataBlockFactoryFromTemplate(const CATUnicodeString & i_dataBlockFactoryTemplate);
 /**
  * Generates a data block based on the data block factory built using the given data block factory template.
  * Internally the data block factory built is stored to avoid to recreate it each time this function is called.
  *
  * @param i_styleSheet the stylesheet name that contains the data block factory template to use.
  * Can't be an empty string.
  *
  * @param i_dataBlockFactoryTemplate the data block factory template to use to build the data block.
  * Can't be an empty string.
  *
  * @return the generated data block in case of success, or NULL otherwise.
  */
  static CATSYPDataBlock* GenerateDataBlockFromTemplate(const CATUnicodeString & i_styleSheet, const CATUnicodeString & i_dataBlockFactoryTemplate);
 /**
  * Generates a data block based on the data block factory built using the given data block factory template (already loaded previously).
  * Internally the data block factory built is stored to avoid to recreate it each time this function is called.
  *
  * @param i_dataBlockFactoryTemplate the data block factory template to use to build the data block.
  * Can't be an empty string.
  *
  * @return the generated data block in case of success, or NULL otherwise.
  */
  static CATSYPDataBlock* GenerateDataBlockFromTemplate(const CATUnicodeString & i_dataBlockFactoryTemplate);

public:
  enum Orientation {Vertical = 0, Horizontal};
  enum Side {Top = 0, Bottom, Right, Left};
  enum Corner {
    NoCorner    =0,
    TopLeft     = 1 << 0,
    TopRight    = 1 << 1,
    BottomRight = 1 << 2,
    BottomLeft  = 1 << 3
  };
  /**
  * Cursors used by vid
  * @see CATVidCursor
  */
  enum MouseCursorShape {
    /** A simple arrow, the default cursor */
    ArrowCursor=0,
    /** A resizing vertical arrow */
    SizeVerCursor,
    /** A resizing horizontal arrow */
    SizeHorCursor,
    /** A resizing arrow, oblique, oriented NorthEast-SouthWest */
    SizeBDiagCursor,
    /** A resizing arrow, oblique, oriented NorthWest-SouthEst */
    SizeFDiagCursor,
    /** A panning cursor, i.e. a cross with four arrows */
    PanCursor,
    /** A classic edit cursor. Typically the shape of an I-beam. */
    EditCursor,
    /** A hand cursor, with the index finger and the thumb unfolded */
    NorthHandCursor,
    /** A rotate cursor, two arrows forming a circle */
    RotateCursor,
    /** A cursor representing the action of unpinning */
    PinnedCursor,
    /** A cursor representing the action of pinning */
    UnpinnedCursor,
    /** A cursor representing the action of column resizing */
    ColResizeCursor,
    /** A cursor representing the action of row resizing */
    RowResizeCursor,
    /** A cursor representing a crosshair */
    CrosshairCursor,
    /** A cursor representing an opened hand */
    OpenedHandCursor,
    /** A cursor representing a closed hand */
    ClosedHandCursor,
    /** A cursor representing the impossibility to drop */
    NoDropCursor,
    /** A cursor representing the forbidding of an action */
    NotAllowedCursor,
    /** A cursor representing a shortcut that can be created. */
    AliasCursor,
    /** A cursor representing a table or a set of cell */
    CellCursor,
    /** A cursor representing the possibility to copy draggable content */
    DragCopyCursor,
    /** A cursor representing the possibility to drag a link */
    DragLinkCursor,
    /** A cursor representing the possibility to move a draggable content */
    DragMoveCursor,
    /** A cursor representing the impossibility to drag */
    DragNoneCursor,
    /** A cursor representing a help */
    HelpCursor,
    /** An hidden cursor */
    NoneCursor,
    /** A cursor representing that the program is performing some processing */
    ProgressCursor,
    /** A vertical edit cursor. Typically the shape of a sideways I-beam. */
    VerticalEditCursor,
    /** A cursor representing that the program is busy and user shoud wait */
    WaitCursor
    /** A cursor representing something that can be zoomed (magnified) in */
    // ZoomInCursor,
    // /** A cursor representing something that can be zoomed (magnified) out */
    // ZoomOutCursor
  };

  enum CropPolicy {NoCrop=0, CropCut, CropWithDots, CropBeginWithDots, CropMiddleWithDots};
  enum VisibilityPolicy {NoAnimation=0, BlindAnimation, ClipAnimation, SlideAnimation, SlideRToLAnimation, SlideLToRAnimation, SlideTToBAnimation, SlideBToTAnimation, ScaleAnimation, AlphaAnimation};
  enum WidgetTransition {NoTransition=0, FlipFromLeft, FlipFromRight, SlideRightToLeft, SlideLeftToRight, SlideTopToBottom, SlideBottomToTop};
  enum EchoMode {EchoNormal=0,NoEcho,EchoPassword};
  /** Horizontal alignment. */
  enum Alignment {AlignLeft=0, AlignCenter, AlignRight};
  /** Vertical alignment. */
  enum VAlignment {VAlignTop=0, VAlignCenter, VAlignBottom};
  /** Orientation Agnostic alignment */
  enum AlignmentPolicy {Near=0, Center, Far};
  /** Alignment for snapping. */
  enum SnapAlignment {SnapAlignTop=0, SnapAlignBottom, SnapAlignCenter, SnapAlignLeft, SnapAlignRight};
  /** Constraint for docking. */
  enum DockConstraint {DockTop=0, DockBottom, DockCenter, DockLeft, DockRight};

  enum WordWrapMode{NoWordWrap=0,WordWrap,WrapAnywhere,WrapAtWordBoundaryOrAnywhere};
  //enum LineWrapMode { NoWrap=0, WidgetWidth,FixedColumnWidth};

	enum AutoCompleteMode{AutocompleteNone=0,Suggest,Append,SuggestAppend};
	enum AutoCompleteSource{History=0,Custom,CustomHistory};

  /* The type of texture filter to use during minification */
  enum TextureFilter {
    Nearest=0,            /*< Nearest neighbor ie no filtering */
    Linear,               /*< Linear filtering */ 
    LinearMipMapNearest,  /*< Bilinear mipmap filtering */
    LinearMipMapLinear,   /*< Trilinear mipmap filtering */
    NearestMipMapNearest, /*< Mipmap filtering (seldom used)*/
    NearestMipMapLinear   /*< Another bilinear mipmap filtering (seldom used) */
  };
  /**
  * Scrollbar policy.
  */
  enum ScrollbarPolicy{
    /** Scrollbar only appear when the size of the viewport is too big. */
    AsNeeded=0, 
    /** Scrollbar never appear. */
    AlwaysHidden, 
    /** Scrollbar always appear. */
    AlwaysVisible};
  /**
  * Stack attachment append policy
  * Determines how future objects added to the stack will be attached (stretched or not)
  * @see CATVidLayStackConstraints::Attachment
  */
  enum StackAttachmentAppendPolicy{
    /** Default : objects are not stretched nor attached */
    NoAttachmentPolicy=0,
    /** Stretch attachment */
    StretchAttachmentPolicy};   
  /**
  * Stretch policy of a container. 
  *
  * @par
  * If the stretch policy is "*Stretch", the 
  * containee is allowed to stretch if the container gets bigger than the
  * minimum dimension of its containee. 
  *
  * @par
  * If the stretch policy is "*Fit", the minimum dimension of the 
  * container will fit exactly the minimum dimension of its containee.
  */
  enum StretchPolicy{
    /** The container can be bigger or smaller than the minimum dimension of 
    its containee. When it is bigger, the containee stretches. */
    Stretch=0, 
    /** The containee stays at minimum dimension. */
    NoStretch, 
    /** The container is at least as big as the minimum dimension of its 
    containee. When it is bigger, the containee stretches. */
    StretchFit,
    /** The container is at least as big as the minimum dimension of its 
    containee. The containee stays at minimum dimension. */
    NoStretchFit};
  /**
  * HandleMode defines the modification handle visibility behavior 
  */
  enum HandleMode{
    /** The handle is always visible */
    Generic=0, 
    /** The handle is only visible on entry and mouse over */
    Ghost, 
    /** The handle is never visible but still sends events */
    FullGhost};
  /**
  * HandleState defines the look of the modification handle
  */
  enum HandleState{
    /** default look */
    Default=0, 
    /** specific look for error */
    Error, 
    /** specific look for origin point */
    Origin,
    /** specific look for reference point */
    Reference,
    /** specific look for deactivated handle */
    Deactivate};
  /**
  * Wrap policy defines different wrapping modes.
  */
  enum WrapPolicy{
    /** Do not wrap content. */
    NoWrap=0,
    /** Wrap content when it goes beyond the length of the containing widget. 
    Use the length of the containing widget as the maximum wrapping length. */
    Auto,
    /** Wrap content when it goes beyond a given threshold. 
    Use said threshold as the maximum wrapping length. */
    Threshold,
    /** Wrap content when it goes beyond a given threshold + tolerance margin. 
    Use said threshold as the maximum wrapping length. */
    ToleranceMargin};
  /**
  * ItemScrollingPolicy defines the way the displayed items of an ItemsView
  * control will scroll.
  */
  enum ItemsScrollMode{
    /** The scrolling will be performed one item at a time. */
    ItemPerItem=0,
    /** The scrolling will be fluid */
    PixelPerPixel
  };
  /**
  * ItemsFlow defines the direction in which the items displayed by a control
  * (such as ListView or TreeView) are laid out.
  */
  enum ItemsFlow{
    /** Items are laid out from top to bottom */
    TopToBottom=0,
    /** Items are laid out from left to right */
    LeftToRight
  };
  /**
  * The @c TooltipForm is used to distinguish different declinations of the 
  * same tooltip.
  *
  * In default templates for short and long tooltips, the short tooltip 
  * displays the @c TooltipShortHelp of the default datablock; the long 
  * tooltip displays the @c TooltipLongHelp of the default datablock.
  * Remaining attributes are displayed by both tooltips.
  *
  * @see CATVidCtl
  */
  enum TooltipForm{
    /** Short tooltip. */
    ShortTooltip=0,
    /** Long tooltip. */
    LongTooltip};
  /** 
  * @c TooltipType defines which forms of the tooltip appear when staying 
  * immobile over a given control. Tooltip forms are @c ShortTooltip and 
  * @c LongTooltip.
  */
  enum TooltipType{
    /** First the short tooltip is displayed, then it is replaced by the long 
    tooltip. */
    ShortThenLong=0,
    /** Only the short tooltip is displayed. */
    ShortOnly,
    /** Only the long tooltip is displayed. */
    LongOnly,
    /** The tooltip of this control is not displayed. If a child of the control 
    has a tooltip, the tooltip of the child can still be displayed. If a parent
    of the control has a tooltip, it will not be displayed, as the control does
    have a tooltip (it is just not displayed). */
    NotDisplayed};
  /**
  * @c TooltipPersistance defines the behaviour of the tooltip when the mouse
  * moves towards it.
  */
  enum TooltipPersistence{
    /** The long tooltip can be reached and clicked on. It will not autopop as 
    long as the mouse cursor is inside the tooltip. */
    Reachable=0,
    /** The tooltip is hidden as soon as the mouse cursor moves. It will also
    autopop after some idle time. */
    HideWhenMoving};
  /**
  * @c TooltipWrapPolicy defines the global appearance of the tooltip. 
  *
  * @see CATVid#WrapPolicy
  * @see CATVidCtl#SetTooltipWrapPolicy
  */
  enum TooltipWrapPolicy{
    /** The tooltip is meant to be single-line. */
    Singleline=0,
    /** The tooltip is multi-line. */
    Multiline};
  /**
  * @c TooltipAnimationPolicy defines the behaviour of the animation if the
  * tooltip image is a ".mng". Duration, number of loops and number of frames 
  * are retrieved from the mng texture settings.
  */
  enum TooltipAnimationPolicy{
    /** Animate the ".mng" when the user goes over the tooltip. */
    AnimateOnMouseOver=0,
    /** Animate the ".mng" when the tooltip is displayed. */
    AnimateOnDisplay
  };
  /**
   * @c PositionPolicy defines the position policy of an element.
   */
  enum PositionPolicy
  {
    /** Position the element relatively to the mouse position */
    MouseRelative = 0,
    /** Position the element at the top of its related control */
    ControlTop,
    /** Position the element at the Bottom of its related control */
    ControlBottom,
    /** Position the element at the Left of its related control */
    ControlLeft,
    /** Position the element at the Right of its related control */
    ControlRight
  };
  /**
  * Identifiers for not-overlapping parts of an URL.
  *
  * @see CATVidURL
  */
  enum URLPart{
    Scheme=0, 
    UserInfo=1,
    Host=2,
    Port=3,
    Path=4,
    Query=5,
    Fragment=6};
  /**
  * Modes that can apply to the selection behavior.
  */
  enum SelectionMode{
    /** No selection is allowed */
    NoSelection = 0,
    /** Only one element can be selected at a time */
    SingleElement,
    /** Several contiguous element can be selected at a time */
    ContiguousElements,
    /** Several range of contiguous element can be selected at a time */
    MultiRange,
    /** Only one element can be selected at a time when the mouse is over it. */
    MouseOver,
    /** The selection state of an element is toggle when clicked, holding shift let you select a range */
    MultiToggle,
    /** MouseOver and persistance when the mouse leave the widget */
    MouseOverWithPersistence};
  /**
  * Flag used by the selection model to know the operation that the
  * select function must achieved.
  */
  enum SelectionFlag{
    /**
    * Select all the given indexes. Does nothing with a model index if it
    * is already selected.
    */
    Select = 0,
    /**
    * Unselect all the given indexes. Does nothing with a model index that is
    * not selected.
    */
    Unselect,
    /**
    * Select all non-selected indexes and unselect all selected indexes.
    */
    Toggle
  };
  /**
  * Defines the look of the expander in a CATVidCtlTreeView
  */
  enum ExpanderLook{
    /**
    * Default = Right Arrow / Down Arrow
    */
    Arrow = 0,
    /**
    * Plus / Minus / Dot. Dot icon only available for node of CATVidMdlCacheTreeAdapter having the partialExpand property.
    */
    Plus,
    /**
    * Do not display the expander.
    */
    NoExpander
  };
  /**
  * Defines the look of the expander in a CATVidCtlTreeView
  */
  enum ArcLook{
    /**
    * Default = Line.
    */
    Line = 0,
    /**
    * Dotted line.
    */
    Dotted,
    /**
    * Do not display the arc.
    */
    NoArc
  };
  /**
  * Defines the type of the model used in ModelView
  */
  enum ModelType{
    /** Default. */
    ModelView = 0,
    /** Common list model. */
    List,
    /** Common tree model. */
    Tree,
    /** Static list model. */
    StandardList,
    /** Static tree model. */
    StandardTree,
    /** Dynamic tree model. */
    DynamicTree,
    /** Dynamic tree model with cache. */
    CacheTree
  };
  /**
  * Defines the look of the selection in an abstract items view control
  */
  enum SelectionFeedback{
    /**
    * No visual feedback appears on a selected items.
    */
    NoFeedback = 0,
    /**
    * The background of the item is modified.
    */
    BackgroundFeedback,
    /**
    * A visual overlay appears on a selected item.
    */
    OverlayFeedback
  };
  /**
  * Defines the type of the virtual keyboard return key
  */
  enum ReturnKeyType{
    /** Default. */
    DefaultReturnKey = 0,
    /** Go. */
    GoReturnKey,
    /** Search. */
    SearchReturnKey,
    /** Send. */
    SendReturnKey,
    /** Done. */
    DoneReturnKey,
    /** Next. */
    NextReturnKey
  };
  /**
   * Defines the order of a sorting.
   */
   enum SortOrder
  {
    /** The items are sorted ascending (e.g. starts with 'AAA' ends with 'ZZZ') */
    AscendingOrder = 0,
    /** The items are sorted descending (e.g. starts with 'ZZZ' ends with 'AAA') */
    DescendingOrder
  };

public:
  /**
  * Calculate window position according to a widget positionning
  * @param i_pWidget : i_pWindow position is calculated from this widget
  * @param i_pWindow : window to position
  * @param i_snapFlag : determin if i_pWindow 
  * @param i_snapSide : snapping side, used when i_snapFlag is TRUE
  * @param i_offsetPosition : offset used i_snapFlag == FALSE
  * @param o_position : output calculated i_pWindow position
  * @return S_OK position compute is successful
  */
  static  HRESULT CalculateWindowPositionFromWidget(CATMathPoint2Df& o_position, CATBaseUnknown* i_pWidget,CATVidFraWindow* i_pWindow, CATMathVector2Df i_offsetPosition,CATBoolean i_snapFlag=TRUE, CATVid::Side i_snapSide = CATVid::Right);

  static const CATSYPDynArray<CATUnicodeString>& GetFontFamilyList();

private:
  static CATSYPDynArray<CATUnicodeString> _fontFamilyList;
};

CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__Orientation);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__WordWrapMode);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__Side);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__SnapAlignment);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__MouseCursorShape);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__CropPolicy);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__VisibilityPolicy);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__WidgetTransition);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__EchoMode);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__Alignment);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__VAlignment);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__TextureFilter);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__ScrollbarPolicy);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__StackAttachmentAppendPolicy);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__StretchPolicy);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__HandleMode);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__HandleState);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__WrapPolicy);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__ItemsScrollMode);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__ItemsFlow);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__URLPart);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__HandleMode);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__HandleState);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__WrapPolicy);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__TooltipForm);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__TooltipType);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__TooltipPersistence);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__TooltipWrapPolicy);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__TooltipAnimationPolicy);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__PositionPolicy);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__SelectionMode);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__SelectionFlag);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__ExpanderLook);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__ArcLook);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__ModelType);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__SelectionFeedback);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__ReturnKeyType);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__SortOrder);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__DockConstraint);
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVid__AlignmentPolicy);

#endif

