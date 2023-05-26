#ifndef CATVidCtlTabExpander_h
#define CATVidCtlTabExpander_h

// COPYRIGHT Dassault Systemes 2012

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidCtlExpander.h>
#include <CATVid.h>
#include <CATVidRectangle.h>

// Mathematics framework
#include <CATMathPoint2Df.h>

// System framework
#include <CATBoolean.h>
#include <CATUnicodeString.h>
#include <CATBaseUnknown_WR.h>

class CATVidCtlTabBar;
class CATVidCtlButton;
class CATSYPEventArgs;
class CATSYPEvent;

/**
 * Expander class used to collapse / expand contents placed in tab pages.
 * 
 *
 * @par Styling your tab expander
 * If you want to create a new style for a CATVidCtlTabExpander, you must have
 * a CATVidCtlButton "syp:named" 'ExpandCollapseButton' in your ".sypstyle" file
 * if you want the AutoHide capability to work correctly.
 *
 * @ingroup VIDControls
 */
class ExportedByVisuDialog CATVidCtlTabExpander : public CATVidCtlExpander
{
  CATDeclareClass;

public:
  
  /**
   * Constructs a CATVidCtlTabExpander.
   * No associsated style, use static factory instead
   */
  CATVidCtlTabExpander();
 
  /**
   * Constructs a CATVidCtlTabExpander with the 'AutoHide' style.
   * @param i_pParent
   *   The parent of the widget.
   * @param i_identifier
   *   The name of the widget.
   */
  static CATVidCtlTabExpander * CreateAutoHideExpander(CATCommand *i_pParent, const CATString & i_identifier);

  /**
   * Sets the content used by the AutoHide capability to check whether the mouse position 
   * is over the expander content bounding rectangle, in which case the expander remains expanded.
   */
  void SetAutoHideContent(CATVidWidget * i_pWidget);
  CATVidWidget * GetAutoHideContent() const;

  // Overriden methods
  virtual void SetExpandedFlag(CATBoolean i_expandedFlag);

  /**
   * Sets the expander side.
   * By default, the ExpanderSide property is set to CATVid::Top.
   */
  void SetExpanderSide(CATVid::Side i_expanderSide);

  /**
   * Returns the expander side.
   */
  CATVid::Side GetExpanderSide() const;

  /**
   * Sets the tooltip short help text of the button used to collapse / expand the expander content.
   */
  void SetExpandCollapseTooltip(const CATUnicodeString& i_tooltip);

  /**
   * Returns the tooltip short help text of the button used to collapse / expand the expander content.
   */
  CATUnicodeString GetExpandCollapseTooltip() const;

  /**
   * Sets the tooltip text long help of the button used to collapse / expand the expander content.
   */
  void SetExpandCollapseTooltipLongHelp(const CATUnicodeString& i_tooltipLongHelp);

  /**
   * Returns the tooltip long help text of the button used to collapse / expand the expander content.
   */
  CATUnicodeString GetExpandCollapseTooltipLongHelp() const;

  /**
   * Specifies whether the expander is pinned or not.
   * When the expander is pinned, its content is always visible (expanded).
   * When not pinned, the content is made visible only when the end user moves the mouse cursor
   * over the 'AutoHide' expander bar and stays expanded while the cursor is over the 
   * AutoHide content bounding rectangle.
   * By default, the PinnedFlag property is set to TRUE.
   * @see SetExpandedFlag
   * @see GetAutoHideEnabledState
   */
  void SetPinnedFlag(CATBoolean i_pinnedFlag);
  CATBoolean GetPinnedFlag() const;

  /**
   * Specifies whether the expander enables the AutoHide capability or not.
   * By default, the AutoHideEnabledFlag property is set to TRUE.
   * @see GetAutoHideEnabledState
   */
  void SetAutoHideEnabledFlag(CATBoolean i_autoHideEnabledFlag);
  CATBoolean GetAutoHideEnabledFlag() const;

  /**
   * Returns TRUE if the expander enables the Auto Hide capability, FALSE otherwise.
   * This method returns TRUE if the AutoHideEnabledFlag property is set to TRUE and if the 
   * CreateAutoHideExpander factory has been used to create the expander.
   * @see CreateAutoHideExpander
   * @see SetAutoHideEnabledFlag
   */
  CATBoolean GetAutoHideEnabledState() const;

  /**
   * Returns the associated tab bar.
   */
  CATVidCtlTabBar * GetTabBar();

  /**
   * Specifies whether the expander tab bar is visible or not.
   * By default, the ShowTabBarFlag property is set to TRUE.
   */
  void SetShowTabBarFlag(CATBoolean i_showTabBarFlag);
  CATBoolean GetShowTabBarFlag() const;

	/**
	* Specifies whether the expander header is visible or not.
	* By default, the ShowTabBarFlag property is set to TRUE.
	*/	
	void SetShowExpanderHeaderState(CATBoolean i_showTabBarFlag);
	const int GetShowExpanderHeaderState();

  /**
   * Specifies whether the expander divider is visible or not.
   * By default, the DividerVisibleFlag property is set to FALSE.
   */
  void SetDividerVisibleFlag(CATBoolean i_dividerVisibleFlag);
  CATBoolean GetDividerVisibleFlag() const;

  /**
   * Returns the expander header dimension.
   */
  CATMathPoint2Df GetHeaderDimension() const;

  /**
   * Get the @c Click event.
   * 
   * The @c Click event is emitted when the expander button is clicked
   * 
   * @par EventProperties
   *   - Name: @c "Click"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent * Click();

  /**
   * Constructs a CATVidCtlTabExpander with the 'AutoHideDock' style.
   * This style is reserved for the docking windows, use the CreateAutoHideExpander method instead.
   * @param i_pParent
   *   The parent of the widget.
   * @param i_identifier
   *   The name of the widget.
   */
  static CATVidCtlTabExpander * CreateAutoHideDockExpander(CATCommand *i_pParent, const CATString & i_identifier, CATBoolean i_ABV3);

  /**
   * @deprecated use the CreateAutoHideExpander method instead
   * Constructs a CATVidCtlTabExpander with the 'Legacy' style.
   */
  static CATVidCtlTabExpander * CreateLegacyExpander(CATCommand *i_pParent, const CATString & i_identifier);

protected:
  
  virtual ~CATVidCtlTabExpander();

  void _InitAutoHide();

  /**
   * @copydoc l_CATVidCtl#TemplateDataUpdated
   * Here are the mandatory "syp:named" objects : 
   * @li 'ExpandCollapseButton' [CATVidCtlButton]
   */
  virtual void TemplateDataUpdated();

private:

  /**
   * Returns the Expand Collapse button.
   */
  CATVidCtlButton * _GetExpandCollapseButton();

  /**
   * Returns the bounding rectangle of the given widget
   */
  CATVidRectangle _GetWidgetBoundingRect(CATVidWidget * i_pWidget);

  /**
   * Adds an extra margin to the bounding rectangle according to the expander side.
   * This method adds a margin on the exterior side of the expander
   * (left margin for the left side, right margin for the right one, ...)
   */
  void _EnlargeBoundingRect(CATVidRectangle& io_boundingRect);
  
  /**
   * Returns TRUE if the mouse position is over the given bounding rectangle,
   * FALSE otherwise.
   */
  CATBoolean _IsMouseOverBoundingRect(const CATVidRectangle& i_boundingRect);

  /**
   * Returns TRUE if the mouse position is over the expander button,
   * FALSE otherwise.
   * This method computes the expander button bounding rectangle and adds
   * a margin on its exterior side (left margin for the left side, 
   * right margin for the right one, ...)
   */
  CATBoolean _IsMouseOverExpandCollapseButton();

  /**
   * Returns TRUE if the mouse position is over the expander content bounding rectangle,
   * FALSE otherwise.
   * This method computes the content bounding rectangle and adds a margin on 
   * the exterior side of the expander (left margin for the left side, 
   * right margin for the right one, ...)
   * @see SetAutoHideContent
   */
  CATBoolean _IsMouseOverContent();

  /**
   * Event handler called when the end user cliks on the expander button.
   */
  void OnExpandCollapseButtonClick(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  /**
   * Event handler called when the mouse enters the expander.
   */
  void OnTabExpanderEntry(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  /**
   * Callback method on Timeout to expand the content if the mouse cursor is still 
   * on top of the expander.
   */
  static void OnTabExpanderEntryTimerCB(CATCommand* iCmd, int iTime, void* iClientData);

  /**
   * Callback method on Timeout to handle the mouse leaving from the AutoHide content bounding rectangle.
   * If the mouse cursor is no more on top of this bounding rectangle, this method collapses 
   * the expander if it is not pinned.
   * @see SetAutoHideContent
   */
  static void OnAutoHideTimerCB(CATCommand* iCmd, int iTime, void* iClientData);


  /*
  * To know if a popup is openened in widgets hierarchy of the Docking window.
  */
  CATBoolean IsPopupOpenedInsideDockingWindow()const;

  CATVid::Side _expanderSide;
  CATUnicodeString _tooltip;
  CATUnicodeString _tooltipLongHelp;
  CATBaseUnknown_WR _tabBarWR;
  CATBaseUnknown_WR _autoHideContentWR;
  CATBoolean _pinnedFlag;
  CATBoolean _autoHideEnabledFlag;
  CATBoolean _dividerVisibleFlag;
  CATBoolean _showTabBarFlag;
	CATBoolean _showExpanderHeaderState;  
};

#endif // CATVidCtlTabExpander_h
