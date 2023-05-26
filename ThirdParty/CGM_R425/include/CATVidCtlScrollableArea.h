// COPYRIGHT Dassault Systemes 2011
//=============================================================================
//
// CATVidCtlScrollableArea.h
// Header definition of CATVidCtlScrollableArea
//
//=============================================================================
//  Oct 2011  Creation: Code generated by the CAA wizard LD5
//=============================================================================
#ifndef CATVidCtlScrollableArea_H
#define CATVidCtlScrollableArea_H
#include <CATVidCtlAbstractScrollableArea.h>
#include <CATBoolean.h>
class CATVidMouseWheelEventArgs;
/**
 * @ingroup VIDControls
 *
 * @c CATVidCtlScrollableArea provides a basic scrollable area that can scroll 
 * vertically and horizontally on any widget. 
 *
 * As a @ref CATVidCtlAbstractScrollableArea, the position and visibility of 
 * its eventual scrollbars can be customized, as well as the stretching 
 * behaviour of the scrolled widget. In addition, motionless 
 * widgets can be added around the viewport on the scrolled widget. Please see
 * the documentation of @ref CATVidCtlAbstractScrollableArea for knowing all
 * the features of a scrollable area.
 *
 * There are several ways to scroll on the central widget:
 * @li The scrolled widget can be moved from visible scrollbars, which are 
 * pickable and can be moved by the mouse cursor on the screen. 
 * @li When the focus is on a scrollbar, keyboard and mouse events command to 
 * the corresponding scrollbar, scrolling either horizontally or vertically. 
 * @li The scrolled widget of the @c CATVidCtlScrollableArea is pickable by 
 * default. On that case, the scrolled widget can be scrolled horizontally and 
 * vertically with keyboard and mouse when the focus is on it. 
 * @li The scrolled widget can be scrolled by C++ code, from outside the class 
 * (@ref #ScrollContentBy), horizontally and vertically at once. 
 *
 * The scrolled widget can also be made not pickable by deactivating the 
 * @c PickAndScroll (@ref CATVidCtlAbstractScrollableArea#SetPickAndScroll). On
 * that case, it is not possible to move it with mouse or keyboard events, 
 * unless a scrollbar is picked.
 *
 * Each time that a scroll action is performed, be it from mouse, keyboard, 
 * scrollbars or code, a @ref CATVidCtlAbstractScrollableArea#Scroll event is 
 * sent.
 *
 * @see CATVidCtlAbstractScrollableArea
 */
class ExportedByVisuDialog CATVidCtlScrollableArea: public CATVidCtlAbstractScrollableArea
{
  friend class l_CATVidCtlScrollableArea;
  CATDeclareClass;

//public:
//  /** Possible tunings of a scrollable. May be used as a starting point before 
//  an eventual fine-tuning. */
//  enum Tuning 
//  { 
//    /** Scrollbars / scroll indicators appear and disappear when needed. */
//    DynamicScrollable=0, 
//    /** Scrollbars / scroll indicators are always there. */
//    StaticScrollable, 
//    /** Horizontal ribbon with no vertical scrollbar / scroll indicator. */
//    HRibbon, 
//    /** Vertical ribbon with no horizontal scrollbar / scroll indicator. */
//    VRibbon 
//  };

public:
  /** Constructor. */
  CATVidCtlScrollableArea();
  /**
   * Creates a styled scrollable area. 
   *
   * Opaque scrollbars appear around the content of the scrollable area, 
   * causing the viewport to shrink.
   *
   * Corresponds to <tt>syp:Template="Default"</tt> in the <tt>sypstyle</tt> 
   * file.
   *
   * @return the new scrollable area.
   *
   * @see CATVidCtlAbstractScrollableArea
   */
  static CATVidCtlScrollableArea * CreateScrollable();
  /**
   * Creates a lighthweight scrollable with no scrollbars. 
   *
   * Scrollbars are not even instantiated. Scrollbar policy has no effect.
   *
   * Corresponds to <tt>syp:Template="NoScrollbars"</tt> in the 
   * <tt>sypstyle</tt> file.
   *
   * @return the new scrollable area.
   *
   * @see CATVidCtlAbstractScrollableArea
   */
  static CATVidCtlScrollableArea * CreateScrollableWithoutScrollbars();
  /**
   * Creates a styled scrollable area with scroll indicators instead of 
   * scrollbars. 
   *
   * Semi-transparent scroll indicators appear above the content of the 
   * scrollable area when scrolling and when the scrollbar policy requires it.
   *
   * Corresponds to <tt>syp:Template="ScrollIndicators"</tt> in the 
   * <tt>sypstyle</tt> file. Sets the @c ScrollbarsOnlyOnScrollFlag to @c TRUE
   * in the scrollable area.
   *
   * @return the new scrollable area.
   *
   * @see CATVidCtlAbstractScrollableArea
   * @see CATVidCtlAbstractScrollableArea#SetScrollbarsOnlyOnScrollFlag
   */
  static CATVidCtlScrollableArea * CreateScrollableWithScrollIndicators();
  /**
   * Creates a lighthweight scrollable with no scrollbars. 
   *
   * Scrollbars are not even instantiated. Scrollbar policy has no effect.
   *
   * Corresponds to <tt>syp:Template="NoScrollbars"</tt> in the 
   * <tt>sypstyle</tt> file.
   *
   * @param i_pParent the parent command
   * @param i_pIdentifier name of the widget
   *
   * @return the new scrollable area.
   *
   * @see CATVidCtlAbstractScrollableArea
   */
  static CATVidCtlScrollableArea* CreateScrollable(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Creates a lighthweight scrollable with no scrollbars. 
   *
   * Scrollbars are not even instantiated. Scrollbar policy has no effect.
   *
   * Corresponds to <tt>syp:Template="NoScrollbars"</tt> in the 
   * <tt>sypstyle</tt> file.
   *
   * @param i_pParent the parent command
   * @param i_pIdentifier name of the widget
   *
   * @return the new scrollable area.
   *
   * @see CATVidCtlAbstractScrollableArea
   */
  static CATVidCtlScrollableArea* CreateScrollableWithoutScrollbars(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Creates a styled scrollable area with scroll indicators instead of 
   * scrollbars. 
   *
   * Semi-transparent scroll indicators appear above the content of the 
   * scrollable area when scrolling and when the scrollbar policy requires it.
   *
   * Corresponds to <tt>syp:Template="ScrollIndicators"</tt> in the 
   * <tt>sypstyle</tt> file. Sets the @c ScrollbarsOnlyOnScrollFlag to @c TRUE
   * in the scrollable area.
   *
   * @param i_pParent the parent command
   * @param i_pIdentifier name of the widget
   *
   * @return the new scrollable area.
   *
   * @see CATVidCtlAbstractScrollableArea
   * @see CATVidCtlAbstractScrollableArea#SetScrollbarsOnlyOnScrollFlag
   */
  static CATVidCtlScrollableArea * CreateScrollableWithScrollIndicators(CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Sets the scrolled widget.
   *
   * @param i_pHandledWidget the scrolled widget.
   */
  void SetScrolledWidget(CATVidWidget* i_pWidget);
  /**
   * @return the scrolled widget.
   */
  CATVidWidget* GetScrolledWidget() const;
  /**
   * Removes the scrolled widget from the scrollable area.
   *
   * @return the scrolled widget.
   */
  CATVidWidget* TakeScrolledWidget();
  /**
   * Scrolls the scrolled widget and updates the scrollbars, if any. 
   *
   * The horizontal scroll offset will be added @c -i_iDeltaX; 
   * the vertical scroll offset will be added @c -i_iDeltaY.
   *
   * The horizontal scrollbar, if instanciated, will move from @c i_iDeltaX 
   * (even if the scrollbar is not visible);
   * the vertical scrollbar, if instanciated, will move from @c i_iDeltaY 
   * (even if the scrollbar is not visible).
   *
   * The scrolling will not go beyond the limits defined by the edges of the 
   * scrolled widget inside the viewport square, which also corresponds to the 
   * limit of the eventual scrollbars. If the absolute value of @c i_iDeltaX or 
   * @c i_iDeltaY is too big, it will be cut.
   *
   * At the end of the function, 
   * @ref CATVidCtlAbstractScrollableArea#ScrollContentBy is called.
   *
   * @param i_iDeltaX the horizontal scrolling
   * @param i_iDeltaY the vertical scrolling
   */
  virtual void ScrollContentBy(int i_iDeltaX, int i_iDeltaY);
  /**
   * @copydoc l_CATVidCtl#TemplateDataUpdated
   * Here are the mandatory "syp:named" objects : 
   * @li Presenter [CATVidCtl]
   * @li StretchGrid [CATVidLayGrid]
   * @li ScrolledWidgetArea [CATVidCtl]
   * And the optional ones :
   * @li VScrollbar [CATVidCtlScrollbar]
   * @li HScrollbar [CATVidCtlScrollbar]
   */
  virtual void TemplateDataUpdated();
protected:
  /** Destructor. */
  virtual ~CATVidCtlScrollableArea();
  /**
   * Add event notifications on scrollbars, if any. 
   */
  virtual void AddEventNotifications();
private:
  /** Copy constructor. */
  CATVidCtlScrollableArea (CATVidCtlScrollableArea &);
  /** Copy operator. */
  CATVidCtlScrollableArea& operator=(CATVidCtlScrollableArea&original);
  /**
   * Scrolls the scrolled widget when a scrollbar is modified by the user.
   */
  void OnScrollbarSlide(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  /** 
   * Handler for @ref CATVidGP#MouseWheel event
   * called when a mouse wheel is done over a widet, consumes the event.
   *
   * This handler must only be registered on a CATVidLayScrollable.
   */ 
  void HandleMouseWheel(CATBaseUnknown *i_pSender, CATVidMouseWheelEventArgs *i_pArgs);

private:
};

//-----------------------------------------------------------------------

#endif
