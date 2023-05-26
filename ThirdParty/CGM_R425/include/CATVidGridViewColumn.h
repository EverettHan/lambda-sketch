//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2012/07/02
//===================================================================
// CATVidGridViewColumn.h
// Header definition of class CATVidGridViewColumn
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/07/02 Creation: Code generated by the 3DS wizard  VV6
//===================================================================

#ifndef CATVidGridViewColumn_H
#define CATVidGridViewColumn_H

#include <CATBaseUnknown.h>
#include <CATVidCtlAbstractItemsView.h>
#include <VisuDialog.h>
#include <CATVid.h>
#include <CATBoolean.h>

class CATUnicodeString;
class l_CATVidGridViewColumn;
class CATVidWidget;
class CATISYPPresenter_var;
class CATVidMdlIndex;

/**
 * Define a column for a multi-columns control.
 *
 * A column is made of two parts: a header and its content. The header is
 * always displayed at the top of the control and is always visible regardless
 * what are the items visible. The content corresponds to what must be
 * displayed inside the column.
 *
 * @par Defining the header
 * In the most simple case, you can only set a string that will be displayed in
 * the header. To do that, you need to use the #SetHeaderTitle member function.
 * However, if you need more customization capabilities, you can provide a
 * data template describing the view of your header section using the
 * SetCellDataTemplate member function.
 *
 * @par Defining the content
 * Basically, there is two approaches to set the content that must be displayed
 * inside a column. When you only needs to display basic data inside a column
 * you can use the #SetData member function. This member function allows you to
 * indicate the name of the property of your data object that must be displayed
 * inside this column. As this is the most easy way to display information
 * inside a column, only basic type can be represented like this
 * (CATUnicodeString, int, float, ...).
 * The other approach lets you deal with more complicated data. In fact, you
 * specify a data template that describes the view of each cell of this column.
 * The view generated by this data template will be binded to your data object,
 * so that, you will be able to build advanced view for your cell.
 *
 */
class ExportedByVisuDialog CATVidGridViewColumn : public CATBaseUnknown
{
  CATDeclareClass;
public:
  /** Default constructor */
  CATVidGridViewColumn();
  /** Destructor */
  ~CATVidGridViewColumn();
  /**
   * Set an identifier to the ViewColumn. Caller must ensure the unicity of this identifier inside the View control.
   * If this method is not called, a fallback is implemented. 
   * This id will be used when constructing the view, when sorting or filter a list.
   * @see #SetData and #CellDataTemplate
   */
  void SetId(const CATString& i_id);
  /** @return the identifier of the column.*/
  const CATString& GetId() const{return _id;}
  /**
   * Shortcut member function to set the title displayed inside the header of
   * the column.
   *
   * @note
   * This member function must only be used with the default introspectable
   * model for the header. If another introspectable model is used, then this
   * member function will do nothing.
   *
   * @param i_headerTitle the string to display inside the header of the
   * column.
   */
  void SetHeaderTitle(const CATUnicodeString & i_headerTitle);
  /**
   * Shortcut member function to get the title displayed inside the header of
   * the column.
   *
   * @note
   * This member function must only be used with the default introspectable
   * model for the header. If another introspectable model is used, then this
   * member function will do nothing.
   *
   * @return the title displayed inside the header column if any.
   */
  CATUnicodeString GetHeaderTitle() const;
  /**
   * Set the name of the property to display inside the column.
   * This property will be extracted from the data objects stored
   * inside the model associated to the multi-column control.
   * If the Id property is not set, it will be set automatically with the Data property.
   *
   * @param i_data the name of the property to set to this column.
   */
  void SetData(const CATUnicodeString & i_data);
  /**
   * Get the name of the property displayed by this column.
   *
   * @return the name of the property displayed by this column if any.
   */
  CATUnicodeString GetData() const;

  /**
   * Set the visibility flag to the column.
   * Set the column VisibleFlag to FALSE will hide the column and its header.
   * Set the index of the column of the model, where is the referenced data (GetData).
   * This property is usefull if GridViewColumn referenced model owns several column.
   * A default value of 0 is provided, for the case of model owning 1 introspectable per line (old only posible model case.).
   *
   * By default, a column is visible.
   */
  void SetVisibleFlag(CATBoolean i_visibleFlag);
  
  /**
   * @param iDataModelColumnIndex : the index in the model of the referenced introspectable column.
   */
  void SetDataModelColumn(int i_dataModelColumnIndex);
  /**
   * Get the visibility flag of the column.
   * Get the index of the column of the model, where is the referenced data (GetData).
   *
   * @return the visibility flag of the column.
   */
  CATBoolean GetVisibleFlag() const;

  /**
   * @return the index of the model column in which introspectable referenced by the CATVidGridViewColumn is located. 
   */
  int GetDataModelColumn() const;
  /**
   * Set the data template name used to build the view of the cells belonging
   * to this column.
   * If the Id property is not set, it will be set automatically with the Data property.
   *
   * @param i_cellDataTemplate the data template name used to build the view
   * of the cells belonging to this column.
   */
  void SetCellDataTemplate(const CATUnicodeString & i_cellDataTemplate);
  /**
   * Get the data template name used to build the view of the cells belonging
   * to this column.
   *
   * @return the data template name used to build the view of the cells
   * belonging to this column if any.
   */
  CATUnicodeString GetCellDataTemplate() const;
  /**
   * Set the stylesheet name in which the data template used to build the view
   * of the cells belonging to this column is defined.
   *
   * @param i_cellStyleSheet the stylesheet name to use
   */
  void SetCellStyleSheet(const CATUnicodeString & i_cellStyleSheet);
  /**
   * Get the stylesheet name in which the data template used to build the view
   * of the cells belonging to this column is defined.
   *
   * @return the stylesheet name that contains the data template to use to
   * build the view of items displayed by this column
   */
  CATUnicodeString GetCellStyleSheet() const;
  /**
   * Set the given object as the introspectable model to use as the
   * header for this column.
   *
   * @note
   * For compliance with StyleProcessor.
   *
   * @param i_spChild the introspectable object to set as the header
   * model for this column.
   */
  virtual void SetChild(CATBaseUnknown_var i_spChild);
  /**
   * Get the introspectable model used as the header for this column.
   *
   * @return the introspectable model used as the header for this column.
   */
  virtual CATBaseUnknown_var GetChild();
  /**
   * Get the presenter associated to this object.
   *
   * @note this member function is only used by StyleProcessor when parsing
   * a sypstyle.
   *
   * @return the CATVidGridViewColumn object as a presenter.
   */
  CATISYPPresenter_var GetItem();
  /**
   * Get the name of the data template used to build the view of the header of
   * this column.
   *
   * @note
   * Not implemented for the moment
   *
   * @return the name of the data template used to build the view of the
   * header of this column.
   */
  CATUnicodeString GetHeaderDataTemplateName() const;
  /**
   * Set the name of the data template used to build the view of this header.
   *
   * @note
   * Not implemented for the moment
   *
   * @param i_headerDataTemplate the name of the data template used to build
   * the view of this header.
   */
  void SetHeaderDataTemplateName(const CATUnicodeString & i_headerDataTemplate);
  /**
   * Get the name of the stylesheet that contains the data template for the
   * header content.
   *
   * @note
   * Not implemented for the moment
   *
   * @return the name of the stylesheet that contains the data template for the
   * header content.
   */
  CATUnicodeString GetHeaderStyleSheet() const;
  /**
   * Set the name of the stylesheet that contains the data template for the
   * header content.
   *
   * @param i_headerStyleSheet the name of the stylesheet that contains the
   * data template to use for the header content.
   */
  void SetHeaderStyleSheet(const CATUnicodeString & i_headerStyleSheet);
  /**
   * Get the name of the property on which sort mechanism will be applied in the model.
   * (Column need to be sortable using SetSortEnabledFlag(TRUE)).
   * This is mandatory to activate the search for column whose cells view is generated by data template.
   * For a column linked to model by CATVidGridViewColumn::SetData, this option is optional.
   * (CATVidGridViewColumn::GetData will be choosen if no SortingProperty is declared).
   * Note that in this last case, GetSortingProperty will overwrite GetData value for sorting property.
   *
   *
   * @return the name of the property on which sort mechanism will be applied in the model.
   */
  CATUnicodeString GetSortingProperty() const;
  /**
   * Set the name of the property on which sort mechanism will be applied in the model.
   *
   * @param i_sortingProperty the name of the property on which sort mechanism will be applied in the model.
   */
  void SetSortingProperty(const CATUnicodeString & i_sortingProperty);

  /**
  * Get the name of the property on which edition mechanism (tweaker edition) will be applied in the model.
  * (Column need to be editable using SetEditableFlag(TRUE)).
  * This is mandatory to activate the edition for column whose cells view is generated by data template.
  * For a column linked to model by CATVidGridViewColumn::SetData, this option is not taken in account!!!   
  * @return the name of the property on which edition mechanism will be applied in the model.
  *
  *
  * @return the name of the property on which sort mechanism will be applied in the model.
  */
  CATUnicodeString GetEditingProperty();

  /**
  * Set the name of the property on which edition mechanism (tweaker edition) will be applied in the model.
  *
  * @param i_editingProperty the name of the property on which edition mechanism will be applied in the model.
  */
  void SetEditingProperty(const CATUnicodeString & i_editingProperty);

  /**
   * Build the view of the header content.
   *
   * @return the created widget.
   */
  CATVidWidget * BuildHeaderContentView();
  /**
   * Set the minimum width of the column.
   *
   * @note By default, a column has a minimum width of 25px.
   *
   * @param i_minimumWidth the new minimum width of the column.
   */
  void SetMinimumWidth(float i_minimumWidth);
  /**
   * Get the minimum width of the column.
   *
   * @return the minimum width of the column.
   */
  float GetMinimumWidth() const;
  /**
   * Set the minimum width of the column.
   *
   * @note By default, a column has a maximum width of -1.f, which is not taken in account.
   *
   * @param i_maximumWidth the new maximum width of the column.
   */
  void SetMaximumWidth(float i_maximumWidth);
  /**
   * Get the maximum width of the column.
   *
   * @return the maximum width of the column.
   */
  float GetMaximumWidth() const;
  /**
   * Set the current width of the column.
   *
   * @note the new width will only be taken into account if it is greater than
   * the minimum width of the column, lower than the maximum width (if defined) and greater than the
   * RequestedMinimumDimension property of all controls contained inside the
   * column header.
   *
   * @param i_width the new width of the column.
   */
  void SetWidth(float i_width);
  /**
   * Get the width of the column.
   *
   * @return the width of the column.
   */
  float GetWidth() const;
  /**
   * Set the WidthToMaxLabelItemWith flag. This flag controls the width of a column.
   * if set to TRUE, on all views of the column take the width of the bigger CATVidGPLabel in its UNCROPPED dimensions.
   * This method will have no effect if cell does not contains a CATVidGPLabel.
   * Note the computed value of column width by "SetWidthToMaxLabelItemWithFlag" will override other previous values set by SetWidth or SetMinimumWidth.
   *
   *
   * @Note
   * By default, this flag value is set to FALSE.
   *
   * @param
   */
  void SetWidthToMaxLabelItemWidthFlag(CATBoolean i_WidthToMaxLabelItemWithFlag);
    /**
   * Set the Editable flag. This flag controls the editability of a column.
   *
   * @Note
   * By default, a column is not editable.
   *
   * @param
   */
  CATBoolean GetWidthToMaxLabelItemWidthFlag() const;

  /**
   * Set the Editable flag. This flag controls the editability of a column.
   *
   * @Note
   * By default, a column is not editable.
   *
   * @param
   */
  void SetEditableFlag(int i_editableFlag);
  /**
   * Get the editable flag value.
   *
   * @return the editable flag value.
   */
  int GetEditableFlag() const;

  void SetEditionMode(CATVidCtlAbstractItemsView::EditionMode i_editionMode)
  {
    _editionMode = i_editionMode;
  }
  CATVidCtlAbstractItemsView::EditionMode GetEditionMode() const
  {
    return _editionMode;
  }

  void SetEditionTweakerDirectBindingFlag(int i_editionTweakerDirectBindingFlag);
  int GetEditionTweakerDirectBindingFlag() const;

  /**
   * Specifies whether the sorting of the column is enabled or not.
   * By default, the SortEnabledFlag property is set to FALSE.
   */
  void SetSortEnabledFlag(CATBoolean i_sortEnabledFlag);

  /**
   * Returns TRUE if the sorting of the column is enabled, FALSE otherwise.
   */
  CATBoolean GetSortEnabledFlag() const;

  /**
   * Specifies whether the sorting of the column is active or not.
   * The sorting can be active on only one column at a time.
   * By default, the SortActiveFlag property is set to FALSE.
   */
  void SetSortActiveFlag(CATBoolean i_sortActiveFlag);

  /**
   * Returns TRUE if the sorting of the column is active, FALSE otherwise.
   */
  CATBoolean GetSortActiveFlag() const;

  /**
   * Sets the column sort order (ascending or descending).
   * By default, the SortOrder property is set to CATVid::AscendingOrder.
   */
  void SetSortOrder(CATVid::SortOrder i_sortOrder);

  /**
   * Returns the column sort order.
   */
  CATVid::SortOrder GetSortOrder() const;

	/*
	* To have columns interactively resizable, ColumnsResizersFlag property of embedding CATVidCtlAbstractItemsView must be set to TRUE!
	* Then To decide decativating interactive resize on some columns, VisibleColumnResizerFlag has to be set to FALSE.
	* TRUE is the default value.(i.e if you just set ColumnsResizersFlag property of embedding CATVidCtlAbstractItemsView is set to TRUE, all contained CATVidGridViewColumn can be interactively resized.)
	*/
	void SetVisibleColumnResizerFlag(CATBoolean i_visibleColumnResizerFlag);

	/*
	* Get the VisibleColumnsResizersFlag value.
	*/
	CATBoolean GetVisibleColumnResizerFlag();


  INLINE l_CATVidGridViewColumn* GetLetter() const {return _pImpl;}

  //For NLS easier management.
  CATString & GetName();

  void  SetName(CATString & i_Name);

  //For NLS resources.
  char* GetResourceFilename(int i_depth) const;

  CATString& GetResourceID();

	/**
	* Modify the flag that determines whether consumed press event must be
	* taken into account for selection.
	*
	* @param: i_flag: the new value of the flag (should be 0 or 1)
	*/
	virtual void SetHandleConsumedPressEventFlag(int i_flag);

	/**
	* Get the value of the flag that determines whether consumed press event
	* must be taken into account for selection.
	*/
	int GetHandleConsumedPressEventFlag() const;

	/*
	* Get the flag value indicating if editable cell feedback (triangle on cell left top corner) is visible (TRUE) or not (FALSE).
	*/
	CATBoolean GetCellEditableFeedbackFlag(CATVidMdlIndex & i_index);

	/*
	* Set the quick edition flag. If set (TRUE), any editable cell will enter in edition mode as soon as strings are typed on keyboard. Else (FALSE), edition mode needs first to be activated by click or double click(see GetEditionMode).
	*/
	void SetQuickEditionFlag(CATBoolean i_Flag);

		/*
		* Set the quick edition flag.
		*/
	CATBoolean GetQuickEditionFlag();

  //!!!!!!!!!!!!!!!!!!!!!
  // AUTOMATIC TEXT COLOR CHANGE AT ROW/CELL SELECTION
  //!!!!!!!!!!!!!!!!!!!!!
  /*
  * Give the syp name of the label widget whose text color will change at selection.
  */
  void SetLabelWidgetTextColorSypName(const CATString& i_Flag);

  /*
  * get the syp name of the label widget whose text color will change at selection.
  */
  CATString& GetLabelWidgetTextColorSypName();

  /*
  * Give the introspectable property of label widget which will be changed at selection
  */
  void SetTextColorProperty(const CATString& i_Flag);

  /*
  * Set the quick edition flag.
  */
  CATString& GetTextColorProperty();

private:
  // Copy constructor and assignement operator are disabled
  CATVidGridViewColumn(const CATVidGridViewColumn &);
  CATVidGridViewColumn & operator= (const CATVidGridViewColumn &);
  CATVidCtlAbstractItemsView::EditionMode _editionMode;
  /** Implementation data */
  l_CATVidGridViewColumn * _pImpl;
  CATString _id;
  CATString _name;
	CATBoolean _visibleColumnResizerFlag;
	int _handleConsumedPress;
	CATBoolean _quickEditionFlag;
  CATString _labelWidgetTextColorSypName;
  CATString _textColorProperty;
};

#endif
