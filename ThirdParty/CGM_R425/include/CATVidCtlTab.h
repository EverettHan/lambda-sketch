#ifndef CATVidCtlTab_h
#define CATVidCtlTab_h

// COPYRIGHT Dassault Systemes 2005

// Local framework
#include <VisuDialog.h>
#include <CATVidCtl.h>
#include <CATVid.h>
#include <CATVidColor.h>
#include <CATSYPArray.h>
#include <CATVidMdlContextMenu.h>
#include <CATVidTabButtonEditedEventArgs.h>
#include <CATVidTabReorderEventArgs.h>

// IntrospectionInfrastructure framework
#include <CATSYPDeclareEnumFactory.h>

// System framework
#include <CATListOfInt.h>
#include <CATBoolean.h>
#include <CATEventSubscriberTypedefs.h>
#include <CATBaseUnknown_WR.h>
#include <CATVidTabPopOverEventArgs.h>

class CATVidCtlTabBar;
class CATUnicodeString;
class CATVidCtlMenuItem;
class CATISYPCollection_var;
class CATVidTabHeaderData;
class CATVidMouseAndKeyboardEventArgs;
class CATVidTabContextMenuEventArgs;
class CATSYPDataBlock;
class CATSYPValidator;
class CATVidCtlTabButton;
class CATSYPEventArgs;

/**
 * @ingroup VIDControls
 * Provides a stack of tabbed widgets.
 * A CATVidCtlTab provides a tab bar (see CATVidCtlTabBar) and an area used to display
 * a selected page. By default the tab bar is located on the top of the widget, but it 
 * can be changed by modifying the TabPosition property.
 * Depending of the property #HideTabBarWhenOnlyOnePageFlag, the tab bar can be hidden when
 * the control holds only one page.
 * 
 * The standard way to to use a CATVidCtlTab in C++ is to do the following :
 * 
 * <UL>
 * <LI>Create a tab by using one of the static factory (CreateCompactTab).</LI>
 * <LI>Create the widgets to visualize in the tab control.</LI>
 * <LI>Call AddPage with the created widgets and a title and/or an icon name if a resource file.</LI>
 * </UL>
 */
class ExportedByVisuDialog CATVidCtlTab : public CATVidCtl
{
  CATDeclareClass;

public:
  
  /** 
   * Legacy constructor, that builds the component with an old style. Prefer the static factory.
   */
  CATVidCtlTab(CATCommand *i_pParent, const CATString & i_pIdentifier, unsigned int i_tabPageSide);
  
  /** 
   * Creates a tab control with the default tab page look. 
   * With this look, the icon and title of each page are displayed in the corresponding tab bar button.
   * @see GetTextVisibleState
   */
  static CATVidCtlTab * CreateTab(CATCommand *i_pParent, const CATString & i_pIdentifier);
  
  /** 
   * Creates a tab control with a compact tab page look. 
   * With this look, only the icon of each page is displayed in the corresponding tab bar button.
   * The title is available only in the tooltip of the tab bar button.
   * @see GetTextVisibleState
   */
  static CATVidCtlTab * CreateCompactTab(CATCommand *i_pParent, const CATString & i_pIdentifier);
  
  /** 
   * Creates a tab control with the immersive tab page look. 
   * This look is reserved for specifics use only when the tab page needs to be immersive. Please use the CreateTab factory method instead.
   * With this look, the icon and title of each page are displayed in the corresponding tab bar button.
   * @see GetTextVisibleState
   */
  static CATVidCtlTab * CreateImmersiveTab(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
   * Creates a tab control with the window page look.
   * Check the ux specifications to learn about its use cases.
   * With this look, the icon and title of each page are displayed in the corresponding tab bar button.
   * @see GetTextVisibleState
   */
  static CATVidCtlTab * CreateTabWindow(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
   * Default constructor. Build a tab control with no view.
   */
  CATVidCtlTab();

  /**
   * Adds a page to the tab control. This involves the creation of a selector button in the tab bar.
   * Asserts if the given widget is NULL, or if it is already a page of the tab.
   * @param i_title the title of the page, displayed in the corresponding tab bar button.
   * @param i_iconName the icon resource file that will be displayed in the corresponding tab bar button.
   * @param i_pWidget the widget to visualize when the tab is selected.
   * @param i_makeCurrentFlag a flag to make current the page of the given widget.
   * @param i_allowCloseButtonFlag a flag to allow (TRUE) or prevent (FALSE) the presence of the 'Close' button 
	 * @param i_horizontallyCompactFlag a flag to compact inserted widget horizontally according to the tab orientation
	 * @param i_verticallyCompactFlag a flag to compact inserted widget vertically according to the tab orientation
   * of the added page when the PagesClosableFlag property is set to TRUE (see SetPagesClosableFlag)
   */
  void AddPage(
      const CATUnicodeString& i_title, 
      const CATUnicodeString& i_iconName, 
      CATVidWidget * i_pWidget, 
      CATBoolean i_makeCurrentFlag = TRUE,
      CATBoolean i_allowCloseButtonFlag = TRUE,
			CATBoolean i_horizontallyCompactFlag = FALSE,
			CATBoolean i_verticallyCompactFlag = FALSE);

  /**
   * Inserts a page to the tab control. This involves the creation of a selector button in the tab bar.
   * Asserts if the given widget is NULL, or if it is already a page of the tab, or if the index is not valid.
   * @param i_index the position at which the new tab must be inserted (between 0 and #GetCount)
   * @param i_title the title of the page, displayed in the corresponding tab bar button.
   * @param i_iconName the icon resource file that will be displayed in the corresponding tab bar button.
   * @param i_pWidget the widget to visualize when the tab is selected.
   * @param i_makeCurrentFlag a flag to make current the page of the given widget.
   * @param i_allowCloseButtonFlag a flag to allow (TRUE) or prevent (FALSE) the presence of the 'Close' button 
	 * @param i_horizontallyCompactFlag a flag to compact inserted widget horizontally according to the tab orientation
	 * @param i_verticallyCompactFlag a flag to compact inserted widget vertically according to the tab orientation
   * of the added page when the PagesClosableFlag property is set to TRUE (see SetPagesClosableFlag)
   */
  void InsertPage(int i_index,
      const CATUnicodeString& i_title, 
      const CATUnicodeString& i_iconName, 
      CATVidWidget * i_pWidget, 
      CATBoolean i_makeCurrentFlag = TRUE,
      CATBoolean i_allowCloseButtonFlag = TRUE,
			CATBoolean i_horizontallyCompactFlag = FALSE,
			CATBoolean i_verticallyCompactFlag = FALSE);


  /**
  * Inserts some pages to the tab control. This involves the creation of a selector button in the tab bar.
  * Asserts if one of the given widget is NULL, or if it is already a page of the tab, or if the index is not valid.
  * Also asserts if the number of the given widgets is not the same as the number of the given headerdatas.
  * @param i_pWidgetList the list of widgets to visualize to add @CATVidWidget.
  * @param i_pTabHeaderList the list of headerdata. There should be one headerdata per given widget. @CATVidTabHeaderData
  * @param i_indexToSetActivateFlag a flag to make current the page of the given widget.
  * @param i_horizontallyCompactFlag a flag to compact inserted widget horizontally according to the tab orientation
  * @param i_verticallyCompactFlag a flag to compact inserted widget vertically according to the tab orientation
  * of the added page when the PagesClosableFlag property is set to TRUE (see SetPagesClosableFlag)
  */
  void AddPages(const CATSYPConstArray<CATBaseUnknown_var> &i_pWidgetList,
                const CATSYPConstArray<CATBaseUnknown_var> &i_pTabHeaderList,
                int i_indexToSetActivateFlag,
                CATBoolean i_horizontallyCompactFlag = FALSE,
                CATBoolean i_verticallyCompactFlag = FALSE);
  
  /**
   * Removes the page corresponding to the given widget. Asserts if the widget is NULL, 
   * or if the widgets doesn't belongs to the tab. 
   * The notification given by #GetTabPageRemovedNotification and an introspection event TabPageRemoved will be sent, 
   * The title and icon informations that are assigned to the corresponding bar button will be lost.
   * Note that this method does not destroy the given widget. It is up to the caller to handle the life cycle of the removed widget.
   * @param the widget which tab page must be removed.
   */
  void RemovePage(CATVidWidget* i_pWidget);

  /**
   * Moves a tab page.
   *
   * @param i_fromIndex the index of the tab that must be moved (between <tt>0</tt> and <tt>GetNbPage() - 1</tt>)
   * @param i_toIndex the position where it must go (between <tt>0</tt> and <tt>GetNbPage()</tt>)
   */
  //void ReorderPage(int i_fromIndex, int i_toIndex);

  /**
   * Specifies the properties (i.e the title and icon name) of the tab corresponding to the given widget.
   * The given widget must belong to the tab.
   * @param i_pWidget the widget of the tab page whose properties must be changed
   * @param i_title the tab page title.
   * @param i_iconName the tab icon name.
   */
  void SetTabProperties(
    CATVidWidget * i_pWidget, 
    const CATUnicodeString& i_title,
    const CATUnicodeString& i_iconName);

  /**
   * Returns the context menu of a tab from the corresponding widget. Asserts
   * that input widget is not @c NULL.
   * @param i_pWidget the widget of the tab page which menu must be accessed.
   * @return the context menu of the tab associated to the given widget.
   */
  CATVidMdlContextMenu * GetContextMenu(CATVidWidget * i_pWidget);
  
  /**
   * @return the number of pages of the tab.
   */
  int GetNbPage() const;
  
  /**
   * Returns a widget from a given tab index. Asserts if the index is out of bounds.
   * The index of the first widget is equal to 0.
   * @return the widget corresponding to the given index.
   */
  CATVidWidget * GetWidget(int i_index);

  /**
   * Finds the contained widget from its identifier.
   */
  CATVidWidget * FindWidget(const CATString& i_id) const;

  /**
   * Sets as current the page related to the given index. Asserts if the index is out of bounds.
   * The index of the first widget is equal to 0.
   * Note that if a page is already current, the new current page will fit its dimensions, to
   * avoid resize artifacts.
   * @param i_index the index from the page to make current.
   */
  void SetCurrentIndex(int i_index);

  /**
   * Sets as current the pages related to the given indexes (Multi Selection Tab case). Asserts if the index is out of bounds.
   * The index of the first widget is equal to 0.
   * Note that if a page is already current, the new current page will fit its dimensions, to
   * avoid resize artifacts.
   * @param iListIndexes
   */
  void SetCurrentIndexes(const CATListOfInt & iListIndexes);
  const CATListOfInt& GetCurrentIndexes() const;
  
  CATVidContainer * GetWidgetCollection() const;
  
  /**
   * @return the index of the current page. Can be -1 if the tab is empty.
   */
  int GetCurrentIndex() const;
  
  /**
   * @return TRUE if the page at the i_index is active, FALSE otherwise.
   */
  CATBoolean IsCurrentIndex(int i_index) const;

  /**
   * @return the content item of the current tab page.
   */
  CATVidWidget * GetCurrentWidget() const;
  
  /**
   * Sets the dimension of all the icons of the tab bar. Asserts if the dimensions are negative.
   * Default value is (18, 14).
   * @param i_dimension the dimension to set.
   */
  void SetIconDimension(const CATMathPoint2Df& i_dimension);
  
  /**
   * @return the dimension of the icons of the tab bar.
   */
  const CATMathPoint2Df& GetIconDimension() const;

  /**
   * Specifies whether a default icon must be used for the tab buttons whose icon name has not been specified, or not.
   * By default, the ForceIconFlag property is set to TRUE.
   */
  void SetForceIconFlag(CATBoolean i_forceIconFlag);
  CATBoolean GetForceIconFlag() const;

  /**
   * Returns the index of the given widget. Asserts if the widget is NULL.
   * The index of the first widget is equal to 0.
   * @return the index of the input widget, or -1 if the widget doesn't belong to the tab.
   */
  int GetIndexOf(CATVidWidget* i_pWidget) const;
  
  /**
   * Sets the position of the tab bar.
   * By default, the TabPosition property is set to CATVid::Top.
   * See @ref #CATVid::Side enum documentation for details.
   * @param i_tabPosition the position of the tab bar
   */
  void SetTabPosition(CATVid::Side i_tabPosition);
  
  /**
   * See @ref #CATVid::Side enum documentation for details.
   * @return the tab position.
   */
  CATVid::Side GetTabPosition() const;

  /**
   * Sets the tab stacking orientation.
   * By default, the stackingOrientation property is set to CATVid::Vertical.
   */
  void SetStackingOrientation(CATVid::Orientation i_stackingOrientation);
  CATVid::Orientation GetStackingOrientation() const;
  /**
   * Specifies whether a 'Close' button must be present on each tab selector of the tab bar or not.
   * Note that, if the PagesClosableFlag property is set to TRUE, you can disable the presence of 
   * the 'Close' button for specified tab pages by calling the method AddPage with the parameter 
   * i_allowCloseButtonFlag equal to FALSE.
   * By default the PagesClosableFlag property is set to FALSE.
   * @param i_pagesClosableFlag TRUE to enable this mode, or FALSE to disable it.
   */
  void SetPagesClosableFlag(CATBoolean i_pagesClosableFlag);
  
  /**
   * @return TRUE when PagesClosableFlag is enabled, FALSE oherwise.
   */
  CATBoolean GetPagesClosableFlag() const;
  
  /**
   * Sets a mode that hides the tab bar when 1 or 0 page only is available.
   * @param i_hideTabBarWhenOnlyOnePageFlag TRUE to enable this mode, or FALSE to disable it.
   */
  void SetHideTabBarWhenOnlyOnePageFlag(CATBoolean i_hideTabBarWhenOnlyOnePageFlag);
  
  /**
   * @return TRUE when HideTabBarWhenOnlyOnePageFlag is enabled, FALSE oherwise.
   */
  CATBoolean GetHideTabBarWhenOnlyOnePageFlag() const;
  
  /**
   * @return TRUE if the tab bar is actually shown, FALSE otherwise.
   */
  CATBoolean GetShowTabBarState() const;
  
  /**
   * Possible display modes used for the text in the tab bar buttons.
   * @see GetTextVisibleState
   */
  enum TextDisplayMode {
    /** No text is displayed in the tab bar buttons */
    NoText = 0, 
    /** An horizontal text is displayed in the tab bar buttons */
    HorizontalText 
  };

  /**
   * Sets the display mode used for the text in the tab bar buttons.
   * By default, the TextDisplayMode property is set to CATVidCtlTab::NoText.
   * When the factory CreateTab is used, this property is set to CATVidCtlTab::HorizontalText;
   * @see GetTextVisibleState
   */
  void SetTextDisplayMode(CATVidCtlTab::TextDisplayMode i_textDisplayMode);
  CATVidCtlTab::TextDisplayMode GetTextDisplayMode() const;

  /**
   * @return TRUE if the title of each page is displayed in the corresponding tab bar button, FALSE otherwise.
   * If the TextDisplayMode property is set to CATVidCtlTab::NoText (e.g when the factory CreateCompactTab is used),
   * this method returns FALSE.
   * @see SetTextDisplayMode
   * @see CreateCompactTab
   */
  CATBoolean GetTextVisibleState() const;

  /**
   * Sets the crop policy of the text displayed in the tab bar buttons.
   * By default, the CropPolicy property is set to CATVid::CropWithDots.
   * @param i_cropPolicy
   *   <br>
   *   <b>Legal values</b> : It can be set to either :
   *   <dl>
   *   <dt><tt>CATVid::NoCrop</tt><dd> : the minimum dimension of the button is function of the label dimension
   *   <dt><tt>CATVid::CropCut</tt><dd> : the dimension of the button is not function of the label dimension, the label is cutted
   *   <dt><tt>CATVid::CropWithDots</tt><dd> : the dimension of the button is not function of the label dimension, the label is cutted with dots
   *   </dl>
   */  
  void SetCropPolicy(CATVid::CropPolicy i_cropPolicy);

  /**
   * @return the crop policy of the text displayed in the tab bar buttons.
   */  
  CATVid::CropPolicy GetCropPolicy() const;

  /**
   * Sets the requested preferred size common to all the tab bar buttons.
   * This requested size is taken into account only for the horizontal tab bar buttons (i.e when the TabPosition 
   * property is equal to CATVid::Top or CATVid::Bottom) when their title is displayed.
   * @see GetTextVisibleState
   * @see SetTabPosition
   */
  void SetPreferredTabSize(float i_preferredSize);

  /**
   * Returns the requested preferred size common to all the tab bar buttons.
   */
  float GetPreferredTabSize() const;

  /**
   * Specifies whether the preferred size of the tab bar buttons is computed directly from the text of the button or not.
   * In such case, the tab buttons can have different preferred sizes. If the PreferredTabSize property is also set, the minimum value of
   * the two preferred sizes is used (i.e the minimum between the common preferred size specified with the PreferredTabSize property and 
   * the one computed from the text of the button).
   * @see SetPreferredCellSize
   */
  void SetUsePreferredSizeFromTextFlag(CATBoolean i_usePreferredSizeFromTextFlag);

  /**
   * Returns TRUE if the preferred size of the tab bar buttons is computed directly from the text of the button, FALSE otherwise.
   * By default, the UsePreferredSizeFromTextFlag property is set to FALSE.
   */
  CATBoolean GetUsePreferredSizeFromTextFlag() const;

  /**
   * Sets the requested minimum size of the tab bar buttons.
   * This minimum size is used to compute the minimum width of the tab bar buttons.
   * By default, the MinimumTabSize property is set to 0.
   */
  void SetMinimumTabSize(int i_minimumTabSize);

  /**
   * Returns the requested minimum size of the tab bar buttons.
   */
  int GetMinimumTabSize() const;

  /**
   * Specifies whether the tab bar uses an additional button or not.
   * This button is always displayed at the end of the tab bar buttons.
   * By default, the AdditionalButtonFlag property is set to FALSE.
   * @see SetAdditionalButtonIcon
   */
  void SetAdditionalButtonFlag(CATBoolean i_additionalButtonFlag);
  CATBoolean GetAdditionalButtonFlag() const;

  /**
   * Specifies the icon to use for the additional button of the tab bar.
   * The tab bar uses an additional button if the property AdditionalButtonFlag is set to TRUE.
   * The icon dimension of this button is the one returned by the method GetIconDimension.
   * @see SetAdditionalButtonFlag
   */
  void SetAdditionalButtonIcon(const CATUnicodeString& i_iconName);
  CATUnicodeString GetAdditionalButtonIcon() const;

  /**
   * Specifies the tooltip to use for the additional button of the tab bar.
   * The tab bar uses an additional button if the property AdditionalButtonFlag is set to TRUE.
   * @see SetAdditionalButtonFlag
   */
  void SetAdditionalButtonTooltip(const CATUnicodeString& i_tooltip);
  CATUnicodeString GetAdditionalButtonTooltip() const;

  /**
   * Returns the context menu of the additional button of the tab bar.
   * The method SetAdditionalButtonFlag must have previously been called with a TRUE value as parameter.
   * @see SetAdditionalButtonFlag
   */
  CATVidMdlContextMenu * GetAdditionalButtonContextMenu();
  
  /**
   * Specifies whether the combo box used to list the tab buttons must always be displayed 
   * (even if there is enough space to display all the tab buttons in the tab bar) or not.
   * By default, the AlwaysShowComboBoxFlag property is set to FALSE.
   */
  void SetAlwaysShowComboBoxFlag(CATBoolean i_alwaysShowComboBoxFlag);

  /**
   * Returns TRUE if the combo box used to list the tab buttons must always be displayed 
   * (even if there is enough space to display all the tab buttons in the tab bar), FALSE otherwise.
   */
  CATBoolean GetAlwaysShowComboBoxFlag() const;

  /**
  * Specifies whether the 'PreviousButton' and 'NextButton' buttons used to scroll through the stacked widgets
  * must be displayed if needed.
  * By default, the UseScrollingButtonsFlag property is set to TRUE.
  */
  void SetUseScrollingButtonsFlag(CATBoolean i_useScrollingButtonsFlag);

  /**
  * Returns TRUE if the 'PreviousButton' and 'NextButton' buttons used to scroll through the stacked widgets
  * must be displayed if needed, FALSE otherwise.
  */
  CATBoolean GetUseScrollingButtonsFlag() const;

  /**
   * @return the color used as background color
   */
  const CATVidColor& GetBackgroundColor() const;

  /**
   * @return the color used as border color
   */
  const CATVidColor& GetColorizeBorderBlackPixelTo() const;

  /**
   * Return the margins surrounding the tab widget.
   * @return a point whose abscissa @c x is the horizontal margin and 
   * whose ordinate @c y is the vertical margin.
   * @see SetUseMarginsFlag
   */
  const CATMathPoint2Df& GetMargins() const;

  /**
   * Specifies whether the tab bar uses margins or not.
   * By default, the UseMarginsFlag property is set to TRUE.
   * @see GetMargins
   */
  void SetUseMarginsFlag(CATBoolean i_useMarginsFlag);
  CATBoolean GetUseMarginsFlag() const;

  /**
   * Specifies whether the tab located under the mouse pointer must be activated 
   * when the end user right clicks on it, or not.
   * By default, the ActivateTabOnRightClickFlag property is set to TRUE.
   */
  void SetActivateTabOnRightClickFlag(CATBoolean i_activateTabOnRightClickFlag);
  CATBoolean GetActivateTabOnRightClickFlag() const;

  /**
   * @return the flag that indicates if the background can be picked
   */
  CATBoolean GetPickFlag() const;

  /**
   * Specifies the associated tab bar.
   * This method asserts if an associated tab bar already exists.
   */
  void SetTabBar(CATVidCtlTabBar * i_pTabBar);

  /**
   * Returns the associated tab bar.
   */
  CATVidCtlTabBar * GetTabBar() const;

  /** 
   * Adds a header to the tab page that contains the widget @c i_spChild. 
   * @param i_spChild the content widget of a tab page.
   * @param i_pHeaderData the header data to set.
   */
  void SetHeaderData(const CATBaseUnknown_var& i_spChild, CATVidTabHeaderData * i_pHeaderData);

  /**
   * @param i_spChild the content widget of a tab page.
   * @return the header of the tab page that contains the widget @c i_spChild. 
   */
  CATVidTabHeaderData * GetHeaderData(const CATBaseUnknown_var& i_spChild) const;

  /** 
   * Adds a header to the tab page of index @c i_index. 
   * @param i_index a valid tab page index.
   * @param i_pHeaderData the header data to set.
   */
  void SetHeaderData(int i_index, CATVidTabHeaderData * i_pHeaderData);

  /**
   * @param i_index a valid tab page index.
   * @return the header of the tab page of index @c i_index. 
   */
  CATVidTabHeaderData * GetHeaderData(int i_index) const;

 /**
  * Sets the data template to use to build the content of the tab buttons.
  *
  * @param i_dataTemplate the name of the data template to use. Cannot be an
  * empty string.
  *
  * @param i_styleSheet the sypstyle file in which the data template is
  * defined. Cannot be an empty string.
  *
  * Before calling this method, please check that your style sheet contains
  * @c i_dataTemplate.
  */
  void SetButtonContentDataTemplate(const CATUnicodeString& i_dataTemplateName, const CATUnicodeString& i_styleSheet);

 /**
  * Sets the stylesheet that contains the data template used to compute the
  * view of the tab buttons content. Always use in coordination with
  * @ref #SetContentDataTemplateName. Does not update the current view.
  *
  * @param i_dataTemplateStyleSheet name of the stylesheet that contains the
  * data template to use to build the view of displayed items.
  *
  * @see SetButtonContentDataTemplateName
  */
  void SetButtonContentDataTemplateStyleSheet(const CATUnicodeString& i_dataTemplateStyleSheet);

  /**
  * Sets the name of the data template to use to compute the view of the tab buttons
  * content. Always use in coordination with
  * @ref #SetContentDataTemplateStyleSheet. Does not update the current view.
  *
  * @param i_dataTemplateName name of the data template to use.
  *
  * @see #SetContentDataTemplateStyleSheet
  */
  void SetButtonContentDataTemplateName(const CATUnicodeString& i_dataTemplateName);

 /**
  * @return the stylesheet in which the data template of the button content can
  * be found.
  */
  CATUnicodeString GetButtonContentDataTemplateStyleSheet() const;

 /** @return the name of the data template used to build the header view. */
  CATUnicodeString GetButtonContentDataTemplateName() const;

  /**
   * Get the validator object in charge of the validation process in edition
   * mode.
   *
   * @return the validator object in charge of the validation process in
   * edition mode or NULL if there is no validator associated.
   */
  CATSYPValidator * GetValidator() const;
  /**
   * Set the validator object in charge of the validation process in
   * edition mode.
   *
   * @param the validator object in charge of the validation process in
   * edition mode.
   */
  void SetValidator(CATSYPValidator * i_pValidator);
  
  /**
   * Specifies whether the tab buttons are editable on double-click or not. Edits
   * the "Label" property of the tab button.
   *
   * Default value is @c FALSE.
   *
   * @param i_flag @c TRUE to allow the edition of tab buttons on double-click.
   */
  void SetButtonsEditableFlag(CATBoolean i_flag);
  /**
   * @return @c FALSE (default) if tab buttons are not editable, @c TRUE else.
   */
  CATBoolean GetButtonsEditableFlag() const;

  /**
   * Specifies whether a view of the content widget of a tab page pops in the tooltip,
   * along with the title of the tab, when hovering the tab. The @c TooltipFlag must
   * be @c TRUE (default) for a tooltip to pop over at all.
   *
   * Default value is @c TRUE.
   *
   * @param i_flag @c TRUE to allow pop over on mouse over, @c FALSE else.
   *
   * @see #SetTooltipFlag
   */
  void SetPopOverFlag(CATBoolean i_flag);
  /**
   * @return @c TRUE (default) if a view of the content widget pops when the mouse stops over
   * the tab, @c FALSE else.
   *
   * @see #SetTooltipFlag
   */
  CATBoolean GetPopOverFlag() const;

  /**
   * Specifies whether a tooltip pops when hovering the tab.
   *
   * Default value is @c TRUE.
   *
   * @param i_flag @c TRUE to allow a tooltip on mouse over, @c FALSE else.
   */
  void SetTooltipFlag(CATBoolean i_flag);
  /**
   * @return @c TRUE (default) if a tooltip pops when the mouse stops over
   * the tab, @c FALSE else.
   */
  CATBoolean GetTooltipFlag() const;

  /**
   * Specifies tab pages can be reordered.
   *
   * Default value is @c FALSE.
   *
   * @param i_flag @c TRUE to allow the reorder of tab pages.
   */
  void SetReorderFlag(CATBoolean i_flag);
  /**
   * @return @c FALSE (default) if tab pages can be reordered,
   * @c FALSE else.
   */
  CATBoolean GetReorderFlag() const;


  /**
   * Specifies tab pages can be dragged.
   *
   * Default value is @c FALSE.
   *
   * @param i_flag @c TRUE to allow the drag and drop of tab pages.
   */
  void SetAllowDragAndDropFlag(CATBoolean i_flag);
  /**
   * @return @c FALSE (default) if tab pages can be dragged,
   * @c FALSE else.
   */
  CATBoolean GetAllowDragAndDropFlag() const;


  /**
   * Specifies tab pages can be reordered.
   *
   * Default value is @c FALSE.
   *
   * @param i_flag @c TRUE to allow the reorder of tab pages.
   */
  void SetAllowReorderFlag(CATBoolean i_flag);
  /**
   * @return @c FALSE (default) if tab pages can be reordered,
   * @c FALSE else.
   */
  CATBoolean GetAllowReorderFlag() const;

  /**
   * Specifies the users can select several tab pages
   *
   * Default value is @c FALSE
   *
   * @param i_flag @c TRUE to allow the multiselection of tab pages
   */
  void SetMultiTabSelFlag(CATBoolean i_flag);

  /**
   *@return @c FALSE (default) if several tab pages can be selected
   @c TRUE else
   */
  CATBoolean GetMultiTabSelFlag() const;

  /**
   * During an external drag and drop operation, specifies if hovering a tab button activates it or not.
   *
   * Default value is @c FALSE
   *
   * @param i_flag @C TRUE to allow tab activation during an external drag and drop operation.
   */
  void SetActivateTabOnExternalDnD(const CATBoolean& i_flag);
  
  /**
   *@return @c FALSE (default) if tab activation is not allowed during an external drag and drop operation
   @c TRUE else
   */
  CATBoolean GetActivateTabOnExternalDnD() const;

  /**
  * Specifies if separators have to be displayed in the widgets collection when selecting several tabs (MultiTabSelFlag needs to be set to TRUE.)
  *
  * Default value is @c TRUE
  *
  * @param i_flag @C TRUE to display separators between widgets of the collection when selecting several tabs.
  */
  void SetDisplayMultiTabSelSeparatorsFlag(const CATBoolean& i_flag);

  /**
  *@return @c TRUE (default) if tab activation is not allowed during an external drag and drop operation
  @c TRUE else
  */
  CATBoolean GetDisplayMultiTabSelSeparatorsFlag() const;

  /**
   * @param i_index an integer
   *
   * @return @c 1 if the input is a valid tab index, @c 0 else.
   */
  int IsValid(int i_index);

  /**
   * Possible transition animation types used when the current tab index is modified.
   */
  enum WidgetTransitionType
  {
    /** No transition animation */
    NoTransition,
    /* Slide type transition animation */
    SlideTransition,
    /* Flip type transition animation */
    FlipTransition
  };

  /**
   * Specifies the transition animation type used when the current tab index is modified.
   * By default, the WidgetTransitionType property is set to SlideTransition
   * @see SetCurrentIndex
   */
  void SetWidgetTransitionType(CATVidCtlTab::WidgetTransitionType i_widgetTransitionType);

  /**
   * Returns the transition animation type used when the current tab index is modified.
   * @see SetCurrentIndex
   */
  CATVidCtlTab::WidgetTransitionType GetWidgetTransitionType() const;

  /** @copydoc CATVidWidget#TunnelInformation */
  virtual void TunnelInformation(const CATVidInformation& i_information);
  /** @copydoc CATVidWidget#ChildWidgetDeleted */
  virtual void ChildWidgetDeleted(CATVidWidget* i_pDeletedChild);

 /**
  * @name CATIVidEnsureVisible implementation
  */

 /**
  * Ensure the visibility of children widget. @copydoc CATIVidEnsureVisible#EnsureWidgetVisibility.
  */
  HRESULT EnsureWidgetVisibility(CATVidWidget* i_pWidget);
  
  /**
   * @name CATISYPCollection implementation
   */
  /*@{*/ 
  /** @copydoc CATISYPCollection#GetAt */
  virtual CATBaseUnknown_var GetAt(int i_index);
  /** @copydoc CATISYPCollection#GetCount */
  virtual int GetCount();
  /** @copydoc CATISYPCollection#Append */
  virtual void Append(const CATBaseUnknown_var &i_spObject);
  /** @copydoc CATISYPCollection#AppendList */
  virtual void AppendList(const CATSYPConstArray<CATBaseUnknown_var> &i_list);
  /** @copydoc CATISYPCollection#Remove */
  virtual void Remove(const CATBaseUnknown_var &i_spObject);
  /** @copydoc CATISYPCollection#RemoveList */
  virtual void RemoveList(const CATSYPConstArray<CATBaseUnknown_var> &i_list);
  /** @copydoc CATISYPCollection#Clear */
  virtual void Clear();
  /** @copydoc CATISYPCollection#Contains */
  virtual int Contains(const CATBaseUnknown_var &i_spObject);
  /** @copydoc CATISYPCollection#Append */
  virtual void Append(const CATLISTV(CATBaseUnknown_var) &i_list);
  /*@}*/
  
   /** 
   * Returns the @c TabPageSelected event.
   *
   * @par
   * A @c TabPageSelected event is emitted when a tab page is selected.
   * 
   * @par EventProperties
   *   @li Name: @c "TabPageSelected"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   *
   */
  static CATSYPEvent * TabPageSelected();

   /** 
   * Returns the @c TabPageRemoved event.
   *
   * @par
   * A @c TabPageRemoved event is emitted when a widget is removed from the tab control.
   * 
   * @par EventProperties
   *   @li Name: @c "TabPageRemoved"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   *
   */
  static CATSYPEvent * TabPageRemoved();

   /** 
   * Returns the @c CloseCurrentTabPage event.
   *
   * @par
   * A @c CloseCurrentTabPage event is emitted on left click on the 
   * Close tab button.
   * 
   * @par EventProperties
   *   @li Name: @c "CloseCurrentTabPage"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   *
   */
  static CATSYPEvent * CloseCurrentTabPage();

  /** 
   * Returns the @c TabContextMenuRequired event.
   *
   * @par
   * A @c TabContextMenuRequired event is emitted on right click on a tab 
   * button or on press on the contextual menu key on Windows while the tab
   * button is active, ie. upon reception of a 
   * @ref CATVidCtl#ContextMenuRequired event on any button of the tab bar.
   * 
   * @par EventProperties
   *   @li Name: @c "TabContextMenuRequired"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidTabContextMenuEventArgs
   *
   * @par 
   * If you consume the event, the @ref CATVidCtl#ContextMenuRequired event 
   * received on the button will be consumed.
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer. 
   *
   * @see CATVidCtl#ContextMenuRequired
   */
  static CATSYPEvent * TabContextMenuRequired();

  /** 
   * Returns the @c AdditionalButtonContextMenuRequired event.
   *
   * @par
   * A @c AdditionalButtonContextMenuRequired event is emitted on right click 
   * on the additional button or, on Windows, on press on the contextual menu 
   * key while the additional button is active, ie. upon reception of a 
   * @ref CATVidCtl#AdditionalButtonContextMenuRequired event on the additional
   * button.
   * 
   * @par EventProperties
   *   @li Name: @c "AdditionalButtonContextMenuRequired"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMouseAndKeyboardEventArgs
   *
   * @par 
   * If you consume the event, the 
   * @ref CATVidCtl#ContextMenuRequired event received on the additional
   * button will be consumed.
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer. 
   *
   * @see CATVidCtl#AdditionalButtonContextMenuRequired
   */
  static CATSYPEvent * AdditionalButtonContextMenuRequired();

   /** 
   * Returns the @c AdditionalButtonClicked event.
   *
   * @par
   * A @c AdditionalButtonClicked event is emitted on left click on the 
   * additional tab button.
   * 
   * @par EventProperties
   *   @li Name: @c "AdditionalButtonClicked"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   *
   */
  static CATSYPEvent * AdditionalButtonClicked();

  /** 
   * Returns the @c TabEdited event.
   *
   * @par
   * A @c TabEdited event is emitted on successful edition of a tab button.
   * 
   * @par EventProperties
   *   @li Name: @c "TabEdited"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidTabEditedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   */
  static CATSYPEvent * TabEdited();
   /** 
   * Returns the @c TabAdded event.
   *
   * @par
   * A @c TabAdded event is emitted on successful addition of a new tab button.
   * 
   * @par EventProperties
   *   @li Name: @c "TabAdded"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidTabAddedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   */
  static CATSYPEvent * TabAdded();

  /**
   * @name Notifications
   */
  /*@{*/ 
  /** @return the notification sent whenever a tab page is made current*/
  CATNotification * GetTabPageSelectedNotification() const;
  /** @return the notification sent whenever a widget is removed from the tab*/
  CATNotification * GetTabPageRemovedNotification() const;
  /** @return the notification sent whenever the close button of the current page is clicked*/
  CATNotification * GetCloseTabPageNotification() const;
  /** @return the notification sent whenever the additional button of the tab bar is clicked*/
  CATNotification * GetAdditionalButtonClickedNotification() const;
  /*@}*/ 

  void OnTabPageNotif(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  void OnCloseCurrentTabPageCB(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  void OnAdditionalButtonClicked(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

  // DEPRECATED:
  
  /** @nodoc */
  CATISYPCollection_var GetItems();
  /**
   * @deprecated Use @ref #GetContextMenu(CATVidWidget* i_pWidget) and fill-in
   * the CID context menu.
   */
  void AddItemToContextualMenu(CATVidWidget* i_pWidget, CATVidCtlMenuItem* i_pPushItem);
  /**
   * @deprecated Use @ref #GetContextMenu(CATVidWidget* i_pWidget) and remove
   * your item from the CID context menu.
   */
  void RemoveItemFromContextualMenu(CATVidWidget* i_pWidget, CATVidCtlMenuItem* i_pPushItem);
  /**
   * @deprecated Use @ref #GetContextMenu(CATVidWidget* i_pWidget) and fill-in
   * the CID context menu.
   */
  void AddItemToContextualMenu(const CATString& i_name, CATVidCtlMenuItem* i_pPushItem);
  /**
   * @deprecated Use @ref #GetContextMenu(CATVidWidget* i_pWidget) and remove
   * your item from the CID context menu.
   */
  void RemoveItemFromContextualMenu(const CATString& i_name, CATVidCtlMenuItem* i_pPushItem);
  /** 
   * @deprecated use @ref #SetTextDisplayMode instead
   */
  void SetTextVisibleFlag(CATBoolean i_textVisibleFlag);
  /** 
   * @deprecated use @ref #GetTextDisplayMode instead
   */
  CATBoolean GetTextVisibleFlag() const;

	/**
	* set vertically compact state of a widget inside tab
	*/
	void SetTabVerticallyCompactFlag(CATVidWidget* i_pWidget, CATBoolean i_verticallyCompactFlag);

	/**
	* set horizontally compact state of a widget inside tab
	*/
	void SetTabHorizontallyCompactFlag(CATVidWidget* i_pWidget, CATBoolean i_horizontallyCompactFlag);

  /**
   * Sets the tab horizontal alignment.
   * By default, the horizontal alignment is set to CATVid::AlignLeft.
   */
  void SetHAlignment(CATVid::Alignment i_tabHAlignment);
  CATVid::Alignment GetHAlignment() const;

protected:
  
  /** destructor. */
  virtual ~CATVidCtlTab();

  /**
   * Returns and creates if needed the associated tab bar.
   */
  CATVidCtlTabBar * GetOrCreateTabBar();

  /**
   * Updates the view of the tab button content.
   */
  void UpdateButtonContentView();

  /**
   * Returns the syp-named 'Content' CATVidCtl.
   */
  CATVidCtl * GetContentCtl() const;

  /**
   * This member function is called as soon as the style processor has
   * created the view of the control. Mandatory "syp:name"-d objects:
   * @li FeedbackLayer [CATVidLaySideAttach]
   */
  virtual void TemplateDataUpdated();

private:
  
  CATVidCtlTab (CATVidCtlTab &);
  CATVidCtlTab& operator=(CATVidCtlTab&);

  void TabPageDeletedCB(CATCallbackEvent, void *i_pInput, CATNotification *, CATSubscriberData i_pSubscriberData, CATCallback);

  /**
   * Dispatches a @ref CATVidCtlTab#TabContextMenuRequired event on the tab. 
   * Consumes the original @ref CATVidCtlTabBar#TabContextMenuRequired event 
   * of the button iif the dispatched event is consumed.
   *
   * @param i_pSender the button that dispatched the original 
   * @ref CATVidCtlTabBar#TabContextMenuRequired.
   * @param i_pArgs arguments of the original event.
   */
  void OnTabButtonContextMenuRequired(CATBaseUnknown * i_pSender, CATVidTabContextMenuEventArgs * i_pArgs);

  /** 
   * Dispatches a @ref CATVidCtlTab#AdditionalButtonContextMenuRequired 
   * event on the tab. Consumes the original 
   * @ref CATVidCtlTabBar#AdditionalButtonContextMenuRequired event of the 
   * button iif the dispatched event is consumed.
   *
   * @param i_pSender the button that dispatched the original 
   * @ref CATVidCtlTabBar#AdditionalButtonContextMenuRequired.
   * @param i_pArgs arguments of the original event.
   */
  void OnAdditionalButtonContextMenuRequired(CATBaseUnknown * i_pSender, CATVidMouseAndKeyboardEventArgs * i_pArgs);

  /** 
   * Dispatches a @ref CATVidCtlTab#TabEdited 
   * event on the tab. Consumes the original 
   * @ref CATVidCtlTabBar#TabButtonEdited event of the 
   * button iif the dispatched event is consumed.
   *
   * @param i_pSender the tab bar.
   * @param i_pArgs arguments of the event.
   */
  void OnTabButtonEdited(CATBaseUnknown * i_pSender, CATVidTabButtonEditedEventArgs * i_pArgs);

  /** 
   * Fill-in the pop over image from the widget of the tab currently hovered.
   *
   * @param i_pSender the tab bar.
   * @param i_pArgs arguments of the event.
   */
  void OnPopOver(CATBaseUnknown * i_pSender, CATVidTabPopOverEventArgs * i_pArgs);

  /** 
   * Ends a reorder.
   *
   * @param i_pSender the tab bar.
   * @param i_pArgs arguments of the event.
   */
  void OnReorder(CATBaseUnknown * i_pSender, CATVidTabReorderEventArgs * i_pArgs);

  CATVidWidget * FindWidget(CATVidCtlTabButton * i_pButton, CATString& io_id) const;

  void BuildTab();
  CATString GiveTabName(const CATString& i_name) const;
  void RemoveWidget(CATVidWidget* i_pWidget, CATBoolean i_widgetDeleted);

  /** Stores the content of a tab page. */
  class CATVidCtlTabPageStruct
  {
  public:

    CATVidCtlTabPageStruct(CATVidWidget* i_pContent, CATVidTabHeaderData* i_pHeaderData, const CATString& i_identifier, CATCallback i_callback, CATBoolean i_horizontallyCompactFlag = FALSE, CATBoolean i_verticallyCompactFlag = FALSE);
    ~CATVidCtlTabPageStruct();

    const CATString& GetIdentifier() const{return _identifier;};
    CATVidTabHeaderData * GetHeaderData() const {return _pHeaderData;};
    CATVidWidget* GetContent() const {return _pContent;};
    CATPixelImage* GetContentImage() const {return _pContentImage;}
    CATCallback GetCallback()const {return _callback;}
		CATBoolean GetHorizontallyCompactFlag()const { return _horizontallyCompactFlag; };
		CATBoolean GetVerticallyCompactFlag()const { return _verticallyCompactFlag; };

		void SetVerticallyCompactFlag(CATBoolean i_verticallyCompactFlag){_verticallyCompactFlag = i_verticallyCompactFlag;}
		void SetHorizontallyCompactFlag(CATBoolean i_horizontallyCompactFlag){_horizontallyCompactFlag = i_horizontallyCompactFlag;}

    void SetContentImage(CATPixelImage * i_pImage);
  
  private:
  
    CATVidWidget* _pContent;
    CATPixelImage* _pContentImage;
    CATVidTabHeaderData * _pHeaderData;
    CATString _identifier;
    CATCallback _callback;
		CATBoolean _horizontallyCompactFlag;
		CATBoolean _verticallyCompactFlag;
  };

private:
  /**
   * Find the CATString identifier that corresponds to a tab button.
   *
   * @param i_pButton a tab button
   * @param o_id the identifier of the tab button, if found
   *
   * @return @c 1 if the identifier has been found, 0 else.
   */
  int FindIdentifier(CATVidCtlTabButton * i_pButton, CATString& o_id) const;
  /**
   * @param i_pButton a tab button
   *
   * @return the object that stores the information related to the tab page associated
   * with the input tab button
   */
  CATVidCtlTabPageStruct * FindPage(CATVidCtlTabButton * i_pButton) const;
  /**
   * @param i_id a tab page identifier
   *
   * @return the object that stores the information related to the tab page associated
   * with the input identifier
   */
  CATVidCtlTabPageStruct * FindPage(const CATString& i_id) const;
  /**
   * Refreshes the pop over image of the tab widget of index @c i_index.
   *
   * @param i_page a tab page structure
   */
  void UpdateImage(CATVidCtlTabPageStruct * i_page);
  /**
   * Refreshes the pop over image of the tab widget of index @c i_index.
   *
   * @param i_index a tab index
   */
  void UpdateImage(int i_index);
  /**
   * @return the dimension to use to create a pop-over image of the widgets of the tab
   */
  CATMathPoint2Df GetPopOverDimension();
  /**
   * @param i_fromIndex index of the page to reorder
   * @param i_toIndex position where it must be inserted
   */
  void _ReorderPage(int i_fromIndex, int i_toIndex);

   /**
   * Update the tab layouting
   *
   */
  void UpdateTab(const CATListOfInt & iListIndexes);

	/**
	* Update tab widget collection column and row weights
	*/
	void UpdateTabWidgetCollectionWeights(CATVidContainer* i_pWidgetCollection, const CATListOfInt & iListIndexes);

  /** Tab pages, by order of apparition from left to right: */
  CATSYPDynArray<CATVidCtlTabPageStruct*> _tabPageList;
  /** @see #GetCurrentIndex */
  //int _currentIndex;

  /** CATListOfInt for current Tabs open (MultiSel Tabs case) */
  CATListOfInt _listCurrentIndexes;
  /** Can be temporarily different from the current index if the tab is built
  from a stylesheet: */
  int _wishedCurrentIndex;
  /** History of selected indices: */
  CATListOfInt _indexOrder;
  CATListOfInt _previousIndexes;
  CATBaseUnknown_WR _contentCtlWR;
  CATVidCtlTab::WidgetTransitionType _widgetTransitionType;

  CATSYPDynArray<CATVidWidget *> _separatorArrays;

  /** List containing the current widgets (Multi selection tabs case) */
  CATVidContainer * _pTabWidgetCollection;
  CATUnicodeString _buttonContentDataTemplateName;
  CATUnicodeString _buttonContentDataTemplateStyleSheet;
  CATVid::Orientation _stackingOrientation;
  CATVid::Alignment _tabHAlignment;
  friend class l_CATVidCtlTab;
};

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidCtlTab__TextDisplayMode);
CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidCtlTab__WidgetTransitionType);

#endif // CATVidCtlTab_h
