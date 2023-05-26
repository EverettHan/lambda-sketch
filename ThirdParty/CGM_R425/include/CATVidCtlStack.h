#ifndef CATVidCtlStack_h
#define CATVidCtlStack_h

// COPYRIGHT Dassault Systemes 2012

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidCtlCollection.h>
#include <CATVid.h>
#include <CATVidInformation.h>
#include <CATVidLayConstraintsAndWidget.h>

// IntrospectionInfrastructure framework
#include <CATISYPCollection.h>

// Mathematics framework
#include <CATMathPoint2Df.h>

// System framework
#include <CATBaseUnknown_WR.h>
#include <CATEventSubscriberTypedefs.h>
#include <CATUnicodeString.h>
#include <CATBoolean.h>

class CATVidCtlScrollableArea;
class CATVidCtlButton;
class CATVidLayStack;
class CATVidLayStackConstraints;
class CATVidCtl;
class CATVidCtlCombo;
class CATVidWidget;
class CATSYPEventArgs;
class CATVidLayConstraintsAndWidget;

/**
 * Class used to display a stack of widgets that adapts itself to its current dimension so 
 * the stacked widgets are always easily accessible.
 *
 * If there is not enough space to display all the stacked widgets, the CATVidCtlStack component can 
 * have two behaviours according to the UseScrollableAreaFlag property value :
 *   - if the UseScrollableAreaFlag property is set to TRUE : a scrollable area is used then 
 *     all the stacked widgets are accessible either directly if visible or by scrolling with the 
 *     displayed arrows. They are also accessible through an additional combo box that lists
 *     all the stacked widgets.
 *   - if the UseScrollableAreaFlag property is set to FALSE : no scrollable area is used and only 
 *     the stacked widgets that can fit the available place are directly accessible, the other ones
 *     are accessible only through the combo box.
 * 
 * @see CATVidLayStack
 *
 * @par Styling your CATVidCtlStack
 * Here are the mandatory "syp:named" objects that must be found in the 
 * template of your ".sypstyle" file : 
 *
 * @li 'PreviousButton' [CATVidCtlButton]
 * @li 'ScrollableArea' [CATVidCtlScrollableArea]
 * @li 'Stack' [CATVidLayStack]
 * @li 'NextButton' [CATVidCtlButton]
 * @li 'AdditionalWidgetCtl' [CATVidCtl]
 * @li 'Combo' [CATVidCtlCombo]
 */
class ExportedByVisuDialog CATVidCtlStack : public CATVidCtlCollection
{
  CATDeclareClass;

public:

  /**
   * Default constructor.
   * No associsated style, use the static factory CreateStack.
   */
  CATVidCtlStack();

  /**
   * Creates a styled CATVidCtlStack. 
   * @param i_pParent the parent command
   * @param i_identifier name of the widget
   * @return the new scrollable area.
   */
  static CATVidCtlStack * CreateStack(CATCommand *i_pParent, const CATString & i_identifier, const CATUnicodeString& i_templateName = "Default");

  /**
   * Sets the stack orientation.
   * By default, the orientation is CATVid::Horizontal.
   */
  void SetOrientation(CATVid::Orientation i_orientation);

  /**
   * Returns the stack orientation.
   */
  CATVid::Orientation GetOrientation() const;

  /**
   * Sets the cell spacing (space inter-cells).
   * By default, the cell spacing is null.
   * @deprecated
   */
  void SetCellBorder(int i_cellBorder);

  /**
   * Returns the cell spacing (space inter-cells).
   * @deprecated
   */
  int GetCellBorder() const;

  /**
   * Sets the preferred size of the cells.
   * By default, the preferred size is null, so each cell dimension will be equal to its minimum dimension.
   */
  void SetPreferredCellSize(float i_preferredSize);

  /**
   * Returns the preferred size of the cells.
   */
  float GetPreferredCellSize() const;

  /**
   * Specifies whether the preferred size of the cells is computed directly from the layouted widgets or not.
   * In such case, the cells can have different preferred sizes. If the PreferredCellSize property is also set, the minimum value of
   * the two preferred sizes is used (i.e the minimum between the common preferred size specified with the PreferredCellSize property and 
   * the one computed from the widget).
   * @see SetPreferredCellSize
   */
  void SetUsePreferredSizeFromWidgetFlag(CATBoolean i_usePreferredSizeFromWidgetFlag);

  /**
   * Returns TRUE if the preferred size of the cells is computed directly from the layouted widgets, FALSE otherwise.
   * By default, the UsePreferredSizeFromWidgetFlag property is set to FALSE.
   */
  CATBoolean GetUsePreferredSizeFromWidgetFlag() const;

  /**
   * Determines how the future items that will be added to the stack will be attached (stretched, top, left, ...)
   * Setting this will not modify attachment of already added items.
   * @see CATVidLayStackConstraints::Attachment
   */
  void SetStackAttachmentAppendPolicy(CATVid::StackAttachmentAppendPolicy i_stackAttachmentAppendPolicy);

  /**
   * @see SetStackAttachmentAppendPolicy
   */
  CATVid::StackAttachmentAppendPolicy GetStackAttachmentAppendPolicy() const;

  /**
   * Specifies the horizontal alignment of the stack.
   */
  void SetHAlignment(CATVid::Alignment i_HAlignment);

  /**
   * Returns the horizontal alignment of the stack.
   * By default, the HAlignment property is set to CATVid::AlignLeft.
   */
  CATVid::Alignment GetHAlignment() const;

  /**
   * Specifies the vertical alignment of the stack.
   */
  void SetVAlignment(CATVid::VAlignment i_VAlignment);

  /**
   * Returns the vertical alignment of the stack.
   * By default, the VAlignment property is set to CATVid::VAlignTop.
   */
  CATVid::VAlignment GetVAlignment() const;

  /**
   * Specifies whether a scrollable area must be used or not to display the stacked widgets.
   *
   * If there is not enough space to display all the stacked widgets, the CATVidCtlStack component can 
   * have two behaviours according to the UseScrollableAreaFlag property value :
   *   - if the UseScrollableAreaFlag property is set to TRUE : a scrollable area is used then 
   *     all the stacked widgets are accessible either directly if visible or by scrolling with the 
   *     displayed arrows. They are also accessible through an additional combo box that lists
   *     all the stacked widgets.
   *   - if the UseScrollableAreaFlag property is set to FALSE : no scrollable area is used and only 
   *     the stacked widgets that can fit the available place are directly accessible, the other ones
   *     are accessible only through the combo box.
   *
   * By default, the UseScrollableAreaFlag property is set to TRUE.
   */
  void SetUseScrollableAreaFlag(CATBoolean i_useScrollableAreaFlag);

  /**
   * Returns TRUE if a scrollable area is used to display the stacked widgets, FALSE otherwise.
   * @see SetUseScrollableAreaFlag
   */
  CATBoolean GetUseScrollableAreaFlag() const;

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
   * Returns TRUE if the 'PreviousButton' and 'NextButton' buttons used to scroll through the stacked widgets 
   * are currently displayed, FALSE otherwise.
   */
  CATBoolean GetUseScrollingButtonsState() const;

  /**
   * Sets the additional widget that will be placed between the scrollable area used to 
   * display the stacked widgets and the combo box.
   * This additional widget is optional.
   */
  void SetAdditionalWidget(CATVidWidget * i_pWidget);

  /**
   * Returns the additional widget.
   */
  CATVidWidget * GetAdditionalWidget() const;

  /**
   * Sets the widget that will be placed in the scrollable area to fill the remaining space after the stack.
   * This filling widget is optional.
   */
  void SetFillingWidget(CATVidWidget * i_pWidget);

  /**
   * Returns the widget that will be placed in the scrollable area to fill the remaining space after the stack.
   */
  CATVidWidget * GetFillingWidget() const;

  /**
   * Specifies whether the combo box must always be used (even if there is enough space 
   * to display all the stacked widgets) or not.
   * By default, the AlwaysShowComboBoxFlag property is set to FALSE.
   * @see GetUseComboBoxState
   * @see SetAlwaysHideComboBoxFlag
   */
  void SetAlwaysShowComboBoxFlag(CATBoolean i_alwaysShowComboBoxFlag);

  /**
   * Returns TRUE if the combo box must always be used (even if there is enough space 
   * to display all the stacked widgets), FALSE otherwise.
   * @see GetUseComboBoxState
   */
  CATBoolean GetAlwaysShowComboBoxFlag() const;

  /**
   * Specifies whether the combo box must never be used (even if there is not enough space 
   * to display all the stacked widgets) or not.
   * By default, the AlwaysHideComboBoxFlag property is set to FALSE.
   * @see GetUseComboBoxState
   * @see SetAlwaysShowComboBoxFlag
   */
  void SetAlwaysHideComboBoxFlag(CATBoolean i_alwaysHideComboBoxFlag);

  /**
   * Returns TRUE if the combo box must never be used (even if there is not enough space 
   * to display all the stacked widgets), FALSE otherwise.
   * @see GetUseComboBoxState
   */
  CATBoolean GetAlwaysHideComboBoxFlag() const;

  /**
   * Returns TRUE if the combo box is used, FALSE otherwise.
   * This method returns TRUE in the two following cases : 
   *   - the AlwaysShowComboBoxFlag property is set to TRUE
   *   - if there is not enough space to display all the stacked widgets : the remaining widgets
   *     will automatically be put in a combo box, so they are still accessible.
   * In all cases, if the AlwaysHideComboBoxFlag property is set to TRUE the combo box is never used.
   *
   * @see SetAlwaysShowComboBoxFlag
   * @see SetAlwaysHideComboBoxFlag
   */
  CATBoolean GetUseComboBoxState() const;

  /**
   * Sets the data template to use to build the view of each item displayed in the combo box.
   *
   * @param i_dataTemplateName the data template name to use to build the view of
   * each item displayed in the combo box. Can't be an empty unicode string.
   *
   * @param i_styleSheet the sypstyle file in which the data template is defined.
   * Can't be an empty unicode string.
   *
   * @see GetUseComboBoxState
   */
  void SetDataTemplate(const CATUnicodeString& i_dataTemplateName, const CATUnicodeString& i_styleSheet);

  /**
   * Sets the name of the data template to use to compute the view of each item 
   * displayed in the combo box.
   *
   * @note
   * Calling only this member function without calling SetDataTemplateStyleSheet
   * is not enough for this control to be able to build the view of the items.
   * So, when you call SetDataTemplateName, you need also to call SetDataTemplateStyleSheet.
   *
   * @param i_dataTemplateName name of the data template to use.
   *
   * @see SetDataTemplateStyleSheet
   * @see GetUseComboBoxState
   */
  void SetDataTemplateName(const CATUnicodeString& i_dataTemplateName);

  /**
   * Returns the name of the data template to use to compute the view of each item 
   * displayed in the combo box.
   */
  CATUnicodeString GetDataTemplateName() const;

  /**
   * Sets the stylesheet that contains the data template to use to compute the
   * view of each item displayed in the combo box.
   *
   * @note
   * Calling only this member function without calling SetDataTemplateName
   * is not enough for this control to be able to build the view of data items.
   * So, when you call SetDataTemplateStyleSheet, you need also to call SetDataTemplateStyleName.
   *
   * @param i_dataTemplateStyleSheet name of the stylesheet that contains the
   * data template to use to build the view of displayed items.
   *
   * @see SetDataTemplateName
   * @see GetUseComboBoxState
   */
  void SetDataTemplateStyleSheet(const CATUnicodeString& i_dataTemplateStyleSheet);

  /**
   * Returns the stylesheet that contains the data template to use to compute the view of
   * each item displayed in the combo box.
   */
  CATUnicodeString GetDataTemplateStyleSheet() const;

  /**
   * Specifies the index of the item to select in the combo box.
   * The first element of a combo box has an index equal to 0.
   * @see GetUseComboBoxState
   */
  void SetSelectedIndex(int i_index);

  /**
   * Returns the index of the current selected item in the combo box.
   * The first element of a combo box has an index equal to 0.
   * @see GetUseComboBoxState
   */
  int GetSelectedIndex() const;

  /**
   * @param i_flag @c TRUE (default) to allow the stack to be scrolled via mouse 
   * grab-and-scroll, @c FALSE else.
   */ 
  void SetMouseScrollFlag(CATBoolean i_flag);

  /**
   * @name CATISYPCollection implementation
   */
  /*@{*/ 
  /** @copydoc CATISYPCollection#Clear */
  virtual void Clear();
  /*@}*/

	/**
	* Calculate dimension from children preferred size and add previousButton,nextButton,combo and additional widget dimensions if they are visible.
	* @return preferredDimension
	* @see #GetPreferredCellSize()
	*/
	CATMathPoint2Df GetPreferredDimension();
	/**
	* Get position of first widget.
	*/
	void GetFirstWidgetPosition(float& o_x, float& o_y);

protected:
  
  virtual ~CATVidCtlStack();

  void _Build();

  /**
   * Returns the scrollable area.
   */
  CATVidCtlScrollableArea * _GetScrollableArea() const;

  /**
   * Returns the embedded CATVidLayStack.
   */
  CATVidLayStack * _GetLayStack() const;

  /**
   * Returns the 'PreviousButton' button.
   */
  CATVidCtlButton * _GetPreviousButton() const;

  /**
   * Returns the 'NextButton' button.
   */
  CATVidCtlButton * _GetNextButton() const;

  /**
   * Returns the embedded additional widget container.
   */
  CATVidCtl * _GetAdditionalWidgetCtl() const;

  /**
   * Returns the combo box.
   */
  CATVidCtlCombo * _GetCombo() const;

  /**
   * Updates the scrollable area according to the UseScrollableAreaFlag and Orientation 
   * properties value.
   */
  void _UpdateScrollableArea();

  /**
   * Updates the scrolling buttons enable state according to the current scroll offset.
   */
  void _UpdateScrollButtons();

  /**
   * Updates the combo box content according to the list of stacked widgets.
   */
  void _UpdateCombo();

  /**
   * Specifies whether the 'PreviousButton' and 'NextButton' buttons used to scroll through the stacked widgets 
   * are displayed or not.
   */
  void SetUseScrollingButtonsState(CATBoolean i_useScrollingButtonsState);

  /**
   * Specifies whether the combo box is used or not.
   * If there is not enough space to display all the stacked widgets, the remaining widgets
   * will automatically be put in a combo box, so they are still accessible.
   */
  void SetUseComboBoxState(CATBoolean i_useComboBoxState);

  /**
   * Returns the position of the given widget relative to the scrolled widget area.
   */
  CATMathPoint2Df _GetRelativePosition(CATVidWidget * i_pWidget) const;

  /**
   * Ensures the widget corresponding to the selected index is visible.
   */
  void _EnsureSelectedWidgetVisible();

  /**
   * Returns the first layouted widget.
   */
  CATVidWidget * _GetFirstLayoutedWidget() const;
  
  /**
   * Returns the last layouted widget.
   */
  CATVidWidget * _GetLastLayoutedWidget() const;

  // Overriden methods
  virtual CATVidLayConstraints * CreateConstraints();
  virtual void InternalSetConstraints(CATVidLayConstraintsAndWidget * i_pConstraintsAndWidget, CATBoolean i_newWidget, CATVidLayConstraints * i_pOldConstraints);
  virtual void InternalRemoveWidget(CATVidLayConstraintsAndWidget * i_pConstraintsAndWidget, CATBoolean i_widgetDeleted);
  void AppendList(const CATSYPConstArray<CATBaseUnknown_var> &i_list);

  /** @copydoc CATVidWidget#UpdateComputedMinimumDimension */
  virtual void UpdateComputedMinimumDimension();
  
  /** Compute dimensions and positions of the children widgets.*/
  virtual void UpdateContainer();

  /**
   * @copydoc CATVidCtl#TemplateDataUpdated
   * Here are the mandatory "syp:named" objects : 
   * @li 'PreviousButton' [CATVidCtlButton]
   * @li 'ScrollableArea' [CATVidCtlScrollableArea]
   * @li 'Stack' [CATVidLayStack]
   * @li 'NextButton' [CATVidCtlButton]
   * @li 'AdditionalWidgetCtl' [CATVidCtl]
   * @li 'Combo' [CATVidCtlCombo]
   */
  virtual void TemplateDataUpdated();

private:
  
  CATVidCtlStack (CATVidCtlStack &);
  CATVidCtlStack& operator=(CATVidCtlStack&);

  /**
   * Callback method registered on the 'PreviousButtons' and 'NextButton' buttons press events.
   */
  void ScrollingButtonPressedCB(CATBaseUnknown * i_pSender, CATSYPEventArgs *i_pArgs);

  /**
   * Callback method registered on the scrollable area event.
   */
  void ScrollCB(CATBaseUnknown * i_pSender, CATSYPEventArgs *i_pArgs);

  CATBaseUnknown_WR _scrollableArea; // CATVidCtlScrollableArea type
  CATBaseUnknown_WR _previousButton; // CATVidCtlButton type
  CATBaseUnknown_WR _nextButton; // CATVidCtlButton type
  CATBaseUnknown_WR _layStack; // CATVidLayStack type
  CATBaseUnknown_WR _additionalWidgetCtl; // CATVidCtl type
  CATBaseUnknown_WR _additionalWidget; // CATVidWidget type
  CATBaseUnknown_WR _combo; // CATVidCtlCombo type
  CATBaseUnknown_WR _fillingWidget; // CATVidWidget type
  CATUnicodeString _dataTemplateName;
  CATUnicodeString _dataTemplateStyleSheet;
  int _selectedIndex;
  CATBoolean _useScrollableAreaFlag;
  CATBoolean _useScrollingButtonsFlag;
  CATBoolean _useScrollingButtonsState;
  CATBoolean _alwaysShowComboBoxFlag;
  CATBoolean _alwaysHideComboBoxFlag;
  CATBoolean _useComboBoxState;
  CATBoolean _usePreferredSizeFromWidgetFlag;

  CATBoolean _preventUpdateFlag;
};

#endif // CATVidCtlStack_h

