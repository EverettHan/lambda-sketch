// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidCtl.h
// Header definition of CATVidCtl
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2007  Creation: jov
//===================================================================
#ifndef CATVidCtl_H
#define CATVidCtl_H

#include <VisuDialog.h>
#include <CATVidContainer.h>
#include <CATVid.h>
#include <CATISYPIntrospectableProvider.h>
#include <CATSYPEvent.h>
#include <CATBoolean.h>
#include <CATVidDnD.h>

class CATISYPPresenter_var;
class CATSYPTemplateData;
class CATMathPoint2Df;
class CATUnicodeString;
class CATSYPDataBlock;
class CATISYPTemplate;
class CATVidFraTooltip;
class CATVidURL;
class CATVidMdlContextMenu;
class CATVizViewer;

//-----------------------------------------------------------------------------
/**
 * @ingroup VIDControls
 *
 * This is the base class for all controls of VID. 
 *
 *
 * @par Adding a tooltip
 *
 * @par
 * Each control widget can be enriched with a tooltip that can be displayed
 * in short and long forms (@ref CATVid#TooltipForm). 
 * Default data and default style are provided for the tooltip, 
 * but they can be customised -- see @ref #SetTooltipProvider for data, 
 * @ref #SetTooltipTemplateName and @ref #SetTooltipStyleSheet for style.
 *
 * If you choose to use the default tooltip template, you can populate it with the 
 * default-tooltip accessors listed in @ref #SetTooltipProvider documentation.
 *
 * If you want to activate the new documentation tooltip templates, you can
 * set @c ShortTooltipTemplateName ,  @c LongTooltipTemplateName or both
 * to the virtual template "StandardTooltip" and use auto detect (activated by default).
 *
 * @par Default tooltip
 *
 * @par
 * The default tooltip has six main attributes: a title, an short help image, a short
 * help, a long help image, a long help and a clickable hyperlink. Filling them is optional.
 *
 * With the default template:
 * @li Short form displays only the short help.
 * @li Long form displays the title, the image, the long help and the hyperlink.
 *
 * With the virtual "standard template", depending on which data have been set, a fitting
 * template will be chosen for both short and long tooltip.
 *
 * @par Tooltip temporal behaviour
 *
 * @par
 * By default, the tooltip behaves as follow ("wait" means that the mouse 
 * cursor do not move):
 *
 * @par
 * <pre>
 * Inactive 
 *    |
 *    | Enter control, then wait TooltipInitialDelay sec
 *    |
 * Display short tooltip -----------------------------------------> HideTooltip
 *    |                                    Move outside Ctl
 *    |
 *    | Wait TooltipShortToLongDelay sec
 *    |
 * Display long tooltip 
 *    |
 *    | Wait AutoPopDelay sec or move outside Ctl
 *    |
 * Hide tooltip --------------------------------> Display another short tooltip
 *    |              Move over new control, 
 *    |              then wait DeactivateDelay sec 
 *    | 
 *    | Wait DeactivateDelay sec
 *    |
 * Inactive
 * </pre>
 *
 * @par
 * This tooltip display automata can be customized with the tooltip type
 * (@ref #SetTooltipType) and the tooltip persistence 
 * (@ref #SetTooltipPersistence). In particular, if the tooltip persistence is
 * @ref CATVid#Reachable, when the long tooltip is on display and the mouse 
 * pointer is going towards it, the long tooltip does not disappear.
 *
 *
 * @par Tooltip hierarchy
 *
 * @par
 * Tooltips cannot have a tooltip. 
 * When the mouse pointer is over several controls, the tooltip on display is 
 * that of the outermost children bearing a tooltip (ie. which has a not 
 * @c NULL_var tooltip provider) in the widget tree.
 *
 *
 * @par Adding a context menu
 *
 * @par
 * You can add a default empty context menu to this control by calling 
 * @ref #GetContextMenu (builds empty default context menu if not already 
 * defined) or @ref #BuildDefaultContextMenu (builds empty default context 
 * menu, overriding the current context menu, if any) 
 * and fill it with @ref CATVidAction (see @ref CATVidMdlContextMenu).
 * You can add an already filled-in or custom context menu with 
 * @ref #SetContextMenu. 
 *
 *
 * @par Context menu hierarchy
 *
 * @par 
 * When the mouse pointer is over several controls, the context menu displayed 
 * that of the outermost children bearing a context menu (ie. which has a not 
 * @c NULL_var context menu provider) in the widget tree.
 *
 *
 * @par Drag and drop
 *
 * @par 
 * To allow a control to be dragged:
 * @li define its @c DragMode (@ref #SetDragMode)
 * @li authorize copy, move and/or link with 
 * @ref #SetPossibleDnDEffects
 * @li listen to @ref #Dragged and @ref #Dropped events
 *
 * @par 
 * To allow a control to accept drops:
 * @li defines its @c DropMode (@ref #SetDropMode)
 * @li listen to @ref #CanImportData and #ImportData events
 *
 * @par 
 * To implement a visual feedback when the mouse moves over the control during 
 * drag-and-drop, listen to @ref CATVidGP#BeginPreDrop (mouse enters the 
 * GP), @ref CATVidGP#PreDrop (mouse moves over the GP) and CATVidGP#EndPreDrop 
 * (mouse leaves the GP) @ref events. There are no container events yet (mouse
 * enters control, mouse move over control, mouse leaves the control). You can
 * also listen to the @ref #CATDlgQueryContinueDragNotification of the 
 * @c CATInteractiveApplication, called continuously during drag-and-drop.
 *
 * @par
 * For a scenario, see: http://codewiki/codewiki/index.php/CID_:_Drag_and_drop
 */
class ExportedByVisuDialog CATVidCtl: public CATVidContainer
{
  friend class VIDScrollableSamplesApplication; 
  CATDeclareClass;
public:
  /**
   * Constructor.
   */
  CATVidCtl ();
  /**
   * Constructor.
   * @see CATVidWidget#CATVidWidget
   */
  CATVidCtl (CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Sets the physical child of the control.
   * Reset the current embedded widget's parent and set itself as widget parent 
   * of i_pWidget.
	 * @param i_widget the embedded widget.
   */
  void SetEmbeddedWidget(CATVidWidget* i_pWidget);
  /**
   * @return the physical child of the control.
   */
  CATVidWidget* GetEmbeddedWidget() const;
  /**
   * Sets which animation the Ctl should use when its visibility 
   * property is changed.
   * @param i_VisibilityPolicy the visibility policy. 
   * Default value is NoAnimation.
   * @see CATVidWidget#SetVisibleFlag
   * @see CATVid#VisibilityPolicy
   */
  void SetVisibilityPolicy(CATVid::VisibilityPolicy i_VisibilityPolicy);
  /**
   * @return which animation the Ctl should use when its visibility 
   * property is changed.
   * @see CATVidWidget#SetVisibleFlag
   * @see CATVid#VisibilityPolicy
   */
  CATVid::VisibilityPolicy GetVisibilityPolicy() const;

  virtual void SetPresenterContent(CATVidWidget* i_pWidget);
  virtual CATVidWidget* GetPresenterContent() const;

  void SetAlphaFilterValue(unsigned int i_alphaFilterValue);
  unsigned int  GetAlphaFilterValue() const;

	void SetUseViewportFilter(int i_alphaFilterValue);
  int GetUseViewportFilter() const;

  /**
   * @copydoc CATVidWidget#TunnelInformation
   */
  virtual void TunnelInformation(const CATVidInformation& i_information);
  /**
   * @copydoc CATVidContainer#UpdateContainer
   */
  virtual void UpdateContainer();
  /**
   * Sets the style informations of a custom control, that will allow to build the XML styled view of the control.
   * Asserts if the template is not found inside the given style sheet, or if the style sheet is not found.
   */
  void SetCustomStyle(const CATUnicodeString& i_styleSheet, const CATUnicodeString& i_templateName, const CATUnicodeString& i_variationName="");
  /**
   * Sets the style informations of a standard control, that will allow to build the XML styled view of the control.
   * Asserts if the template is not found inside the theme.
   */
  void SetStyle(const CATUnicodeString& i_templateName, const CATUnicodeString& i_variationName="");
  /**
   * Forces the style generation, from the style informations.
   */
  void ForceStyleGeneration();
  /**
   * @copydoc CATISYPTemplate#GetTemplateData
   */
  CATSYPTemplateData* GetTemplateData() const;
  /**
   * When this flag is up, the viewport is taken into account. Else the 
   * viewport is the dimension of the widget and the minimum viewport is
   * the minimum dimension of the widget. By default, the flag is @c FALSE.
   *
   * @param i_ignoreMinimumDimensionFlag 
   *    The flag must be set to @c TRUE to activate the viewport.
   */
  void SetIgnoreMinimumDimensionFlag(CATBoolean i_ignoreMinimumDimensionFlag);
  /**
   * @return @ TRUE if the viewport is active on the control, @c FALSE else.
   *
   * @see #SetIgnoreMinimumDimensionFlag
   */
  CATBoolean GetIgnoreMinimumDimensionFlag() const;
  /**
   * Sets the minimum value accepted for the viewport of the control.
   *
   * @param i_dimension 
   *    The minimum viewport.
   */
  void SetMinimumViewport(const CATMathPoint2Df& i_dimension);
  /**
   * @return The minimum viewport of the control.
   *
   * @see #SetMinimumViewport
   */
  const CATMathPoint2Df& GetMinimumViewport() const;
  /**
   * Sets the minimum value accepted for the height of the viewport of the 
   * control. By default, the minimum height is 0.
   *
   * @param i_length 
   *    The minimum height of the viewport.
   */
  void SetMinimumViewportHeight(int i_length);
  /**
   * @return The minimum height for the viewport of the control.
   *
   * @see #SetMinimumViewportHeight
   */
  int GetMinimumViewportHeight() const;
  /**
   * Sets the minimum value accepted for the width of the viewport of the 
   * control. By default, the minimum width is 0.
   *
   * @param i_length 
   *    The minimum width of the viewport.
   */
  void SetMinimumViewportWidth(int i_length);
  /**
   * @return The minimum width for the viewport of the control.
   *
   * @see #SetMinimumViewportWidth
   */
  int GetMinimumViewportWidth() const;
  /**
   * Deprecated method. Use #SetEmbeddedWidget instead.
   * @deprecated
   */
  void SetEmbededWidget(CATVidWidget* i_pWidget);
  /**
   * Deprecated method. Use #GetEmbededWidget instead.
   * @deprecated
   */
  CATVidWidget* GetEmbededWidget() const;
  /**
   * @copydoc CATISYPTemplate#GetTemplateName
   */
  const CATUnicodeString& GetTemplateName() const;
  /**
   * @copydoc CATISYPTemplate#SetTemplateName
   */
  void SetTemplateName(const CATUnicodeString& i_templateName);
  /**
   * @copydoc CATISYPTemplate#GetVariationName
   */
  const CATUnicodeString& GetVariationName() const;

  void SetTemplateStylesToInit(const CATUnicodeString& i_templateStyleToInit);
  const CATUnicodeString& GetTemplateStylesToInit() const;

  virtual void SetChild(CATBaseUnknown_var i_spToConnect);
  virtual CATBaseUnknown_var GetChild();
  virtual CATISYPPresenter_var GetItem();

  /**
   * Specifies whether the control is focusable or not.
   * By default, the FocusableFlag property is set to FALSE.
   */ 
  void SetFocusableFlag(CATBoolean i_focusableFlag);

  /**
   * Returns TRUE if the control is focusable, FALSE otherwise.
   */
  CATBoolean GetFocusableFlag() const;

  /**
   * Returns TRUE if the control has the focus, FALSE otherwise.
   */
  CATBoolean GetFocusedFlag() const;

	/**
	* The property VisualState is used for styling purpose only.
	*/
	virtual int GetHoveringVisualState();

  /**
   * Retrieves a widget of the current widget hierarchy, set by #SetTemplatedView.
   * You can cast it to have a pointer on a widget, for example to change properties not available to introspection.
   * The best practice is to do it in the reimplemented function #TemplateDataUpdated,
   * which is called at the end of #SetTemplatedView.
   *
   * No assertion will be thrown if no object with this name has been found, the caller needs to test the pointer and
   * eventually assert himself. You can use #RetrieveSypNamedObject to assert in case of @c FAILURE.
   * 
   * @return @c NULL if the component was not found; else it returns a pointer to the component.
   * @c AddRef has not been called on the returned component so it must not be @c Released by the caller.
   *
   * @code
   * #include "CATBaseUnknown.h"
   * #include "CATSysMacros.h"
   *
   * CATBaseUnknown* pCBU = pMyWidget->RetrieveSypNamedObject("MyObjectName");
   * // return if pCBU is NULL
   *
   * _pMyObject = CAT_DYNAMIC_CAST(MyWidgetClass, pCBU);
   * // _pMyObject is a class member of type MyWidgetClass
   * @endcode
   * 
   * It is advised and considered as best practice to do it in #TemplateDataUpdated,
   * so it will be done each time the view is constructed.
   */
  CATBaseUnknown* TryRetrieveSypNamedObject(const CATUnicodeString& i_sypName);
  /**
   * Retrieves a widget of the current widget hierarchy, set by #SetTemplatedView.
   * You can cast it to have a pointer on a widget, for example to change properties not available to introspection.
   * The best practice is to do it in the reimplemented function #TemplateDataUpdated,
   * which is called at the end of #SetTemplatedView.
   * 
   * This function asserts with a @ref FAILURE if returns @c NULL if an object with this name can not be found.
   * The @ref FAILURE will have a explicit message specifying which name was expected to be found in the template,
   * and also the name of the template and its variation.
   * You can use #TryRetrieveSypNamedObject if you don't want a @c FAILURE to be raised.
   * 
   * @return @c NULL if the component was not found (in that case a FAILURE has been raised);
   * else it returns a pointer to the component.
   * @c AddRef has not been called on the returned component so it must not be @c Released by the caller.
   *
   * @code
   * #include "CATBaseUnknown.h"
   * #include "CATSysMacros.h"
   *
   * CATBaseUnknown* pCBU = pMyWidget->RetrieveSypNamedObject("MyObjectName");
   * // return if pCBU is NULL
   *
   * _pMyObject = CAT_DYNAMIC_CAST(MyWidgetClass, pCBU);
   * // _pMyObject is a class member of type MyWidgetClass
   * @endcode
   *
   * It is advised and considered as best practice to do it in #TemplateDataUpdated,
   * so it will be done each time the view is constructed.
   */
  CATBaseUnknown* RetrieveSypNamedObject(const CATUnicodeString& i_sypName);

  //---------------------------------------------------------------------------
  //                                Tooltip
  //---------------------------------------------------------------------------
  /**
   * @return The introspectable provider in charge of returning the tooltip 
   * content's data block. 
   *
   * @see #SetTooltipProvider
   */
  CATISYPIntrospectableProvider_var GetTooltipProvider() const;
  /**
   * Sets the introspectable provider in charge of returning the tooltip. The
   * tooltip can any introspectable object; in particular, it can be a 
   * datablock.
   *
   * If the tooltip provider is @c NULL_var, no tooltip is displayed. Else, a 
   * tooltip will be displayed. If the minimum dimension of this tooltip is
   * (0, 0) (empty default tooltip for eg.), an assertion will be raised at the 
   * time of the display.
   *
   * If no provider is set, a default provider is created when setting any 
   * default-tooltip-related data throught one of the default-tooltip 
   * accessors, to be used with the default and/or standard templates: 
   *
   * @li @ref #SetTooltipTitle (default and standard)
   * @li @ref #SetTooltipShortHelp (default and standard)
   * @li @ref #SetTooltipLongHelp (default and standard)
   * @li @ref #SetTooltipImage (default)
   * @li @ref #SetTooltipShortHelpImage (standard)
   * @li @ref #SetTooltipLongHelpImage (standard)
   * @li @ref #SetTooltipImageDimension (default)
   * @li @ref #SetTooltipShortHelpImageDimension (standard)
   * @li @ref #SetTooltipLongHelpImageDimension (standard)
   * @li @ref #SetTooltipHyperlinkLabel (default)
   * @li @ref #SetTooltipWrapThreshold (default and standard)
   * @li @ref #SetTooltipToleranceMargin (default and standard)
   * 
   * This default provider is a @ref CATSYPStaticIntrospectableProvider that 
   * always returns the same default data block.
   *
   * For example, if you chose the default template, this default data block 
   * is filled with a title, a short help image, a short help, a long help image,
   * a long help, an hyperlink label, a wrap threshold and a wrap tolerance margin.
   *
   * If you want to change the look of the tooltip, you can provide your own
   * tooltip data template (@ref #SetTooltipTemplateName,
   * @ref #SetLongTooltipStyleSheet). To set the parameters that have the
   * same name and type than the default/standard ones, you can use the tooltip
   * accessors.
   *
   * If you want to add new parameters to the tooltip, you can change the 
   * static tooltip provider for your own static introspectable provider (it 
   * will be the tooltip provider) and make it return an 
   * introspectable (it will be interpreted as a tooltip) containing 
   * your own parameters. You must then create your own data template to
   * support the new parameters.
   *
   * If you want to create tooltips dynamically, you can change the static
   * tooltip provider for a dynamic one. You must once again provide your own 
   * data templates unless the introspectable parameters of your tooltip are
   * the same than the default tooltip parameters, as listed in 
   * @ref #SetTooltipTemplateName.
   *
   * Setting the tooltip provider will deactivate auto-detect for the tooltip
   * type (@ref SetAutoDetectTooltipTypeFlag). It will also delete all
   * previously set tooltip-related values: for this reason, you must always
   * set your tooltip provider before using the tooltip accessors. Also
   * you cannot provide both tooltip introspectable parameters and tooltip
   * provider by @c CATSYPStyle for a same control, as the order of
   * initialization is not guaranteed.
   * 
   * @param i_spiIntrospectableProvider the introspectable provider to use or 
   * @c NULL_var if no tooltip must be displayed (for eg. when all tooltip 
   * parameters are empty). By default, it is set to @c NULL_var until any
   * default-tooltip accessor is used.
   *
   * @see CATSYPIntrospectableProvider
   * @see CATSYPStaticIntrospectableProvider
   */
  void SetTooltipProvider(CATISYPIntrospectableProvider_var i_spiIntrospectableProvider);
  /**
   * Sets the current tooltip to "no tooltip", ie the tooltip provider to
   * @c NULL_var. 
   *
   * @see #SetTooltipProvider
   */
  void ResetTooltip();
  /**
   * As soon as the tooltip provider is not @c NULL, the control has a tooltip.
   * 
   * @return @c TRUE if the control has a tooltip, @c FALSE else.
   */
  CATBoolean HasATooltip();
  /**
   * Shortcut function for the default tooltip. Will only work if there is an 
   * "Image" CATUnicodeString introspectable property in the tooltip.
   *
   * @return a path to the image that will be displayed in the tooltip.
   *
   * @see #SetTooltipImage
   * @see #SetTooltipTemplateName
   */
  CATUnicodeString GetTooltipImage() const;
  /**
   * Shortcut function for the default tooltip. Will only work if there is an 
   * "Image" CATUnicodeString introspectable property in the tooltip. Default
   * value is empty string, which corresponds to no image.
   *
   * @param i_sImage a path to the image that will be displayed in the tooltip.
   *
   * @see #GetTooltipImage
   * @see #SetTooltipTemplateName
   */
  void SetTooltipImage(const CATUnicodeString& i_sImage);
  /**
   * Shortcut function for the default tooltip. Will only work if there is a 
   * "PixelImage" CATPixelImage introspectable property in the tooltip.
   *
   * @return a CATPixelImage that will be displayed in the tooltip.
   *
   * @see #SetTooltipPixelImage
   * @see #SetTooltipTemplateName
   */
	CATPixelImage * GetTooltipPixelImage() const;
  /**
   * Shortcut function for the default tooltip. Will only work if there is a
   * "PixelImage" CATPixelImage introspectable property in the tooltip. Default
   * value is NULL, which corresponds to no image.
   *
   * @param i_pPixelImage a CATPixelImage that will be displayed in the tooltip.
   *
   * @see #GetTooltipImage
   * @see #SetTooltipTemplateName
   */
	void SetTooltipPixelImage(CATPixelImage* i_pPixelImage);
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a 
   * "ShortHelpImage" CATUnicodeString introspectable property in the tooltip.
   *
   * @return a path to the short help image that will be displayed in the tooltip.
   *
   * @see #SetTooltipShortHelpImage
   * @see #SetTooltipTemplateName
   */
  CATUnicodeString GetTooltipShortHelpImage() const;
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a 
   * "ShortHelpImage" CATUnicodeString introspectable property in the tooltip.
   * Default value is empty string, which corresponds to no image.
   *
   * @param i_sImage a path to the short help image that will be displayed in the tooltip.
   *
   * @see #GetTooltipShortHelpImage
   * @see #SetTooltipTemplateName
   */
  void SetTooltipShortHelpImage(const CATUnicodeString& i_sImage);
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a 
   * "ShortHelpPixelImage" CATPixelImage introspectable property in the tooltip short help.
   *
   * @return a CATPixelImage that will be displayed in the tooltip.
   *
   * @see #SetTooltipShortHelpPixelImage
   * @see #SetTooltipTemplateName
   */
	CATPixelImage* GetTooltipShortHelpPixelImage() const;
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a 
   * "ShortHelpPixelImage" CATPixelImage introspectable property in the tooltip.
   * Default value is NULL, which corresponds to no image.
   *
   * @param i_pPixelImage a CATPixelImage that will be displayed in the tooltip short help.
   *
   * @see #GetTooltipShortHelpImage
   * @see #SetTooltipTemplateName
   */
	void SetTooltipShortHelpPixelImage(CATPixelImage* i_pPixelImage);
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a 
   * "LongHelpImage" CATUnicodeString introspectable property in the tooltip.
   *
   * @return a path to the long help image that will be displayed in the tooltip.
   *
   * @see #SetTooltipLongHelpImage
   * @see #SetTooltipTemplateName
   */
  CATUnicodeString GetTooltipLongHelpImage() const;
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a
   * "LongHelpImage" CATUnicodeString introspectable property in the tooltip. Default
   * value is empty string, which corresponds to no image.
   *
   * @param i_sImage a path to the long help image that will be displayed in the tooltip.
   *
   * @see #GetTooltipLongHelpImage
   * @see #SetTooltipTemplateName
   */
  void SetTooltipLongHelpImage(const CATUnicodeString& i_sImage);
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a 
   * "LongHelpPixelImage" CATPixelImage introspectable property in the tooltip.
   *
   * @return a CATPixelImage that will be displayed in the tooltip long help.
   *
   * @see #SetTooltipLongHelpPixelImage
   * @see #SetTooltipTemplateName
   */  
	CATPixelImage* GetTooltipLongHelpPixelImage() const;
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a
   * "LongHelpImage" CATPixelImage introspectable property in the tooltip. Default
   * value is NULL, which corresponds to no image.
   *
   * @param i_pPixelImage a CATPixelImage that will be displayed in the tooltip long help.
   *
   * @see #GetTooltipLongHelpImage
   * @see #SetTooltipTemplateName
   */
	void SetTooltipLongHelpPixelImage(CATPixelImage* i_pPixelImage);
  /**
   * Shortcut function for the default tooltip. Will only work if there is an 
   * "ImageDimension" CATMathPoint2Df introspectable property in the tooltip.
   *
   * @return the dimension of the tooltip image on the screen.
   *
   * @see #SetTooltipImage
   * @see #SetTooltipImageDimension
   * @see #SetTooltipTemplateName
   */
  CATMathPoint2Df GetTooltipImageDimension() const;
  /**
   * Shortcut function for the default tooltip. Will only work if there is an 
   * "ImageDimension" CATMathPoint2Df introspectable property in the tooltip.
   * Default value is (64, 64).
   *
   * @param i_imageDim the dimension of the tooltip image on the screen.
   *
   * @see #GetTooltipImage
   * @see #GetTooltipImageDimension
   * @see #SetTooltipTemplateName
   */
  void SetTooltipImageDimension(const CATMathPoint2Df& i_imageDim);
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a
   * "ShortHelpImageDimension" CATMathPoint2Df introspectable property in the tooltip.
   *
   * @return the dimension of the short help tooltip image on the screen.
   *
   * @see #SetTooltipShortHelpImage
   * @see #SetTooltipShortHelpImageDimension
   * @see #SetTooltipTemplateName
   */
  CATMathPoint2Df GetTooltipShortHelpImageDimension() const;
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a
   * "ShortHelpImageDimension" CATMathPoint2Df introspectable property in the tooltip.
   * Default value is (150, 75).
   *
   * @param i_imageDim the dimension of the short help tooltip image on the screen.
   *
   * @see #GetTooltipShortHelpImage
   * @see #GetTooltipShortHelpImageDimension
   * @see #SetTooltipTemplateName
   */
  void SetTooltipShortHelpImageDimension(const CATMathPoint2Df& i_imageDim);
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a
   * "LongHelpImageDimension" CATMathPoint2Df introspectable property in the tooltip.
   *
   * @return the dimension of the long help tooltip image on the screen.
   *
   * @see #SetTooltipLongHelpImage
   * @see #SetTooltipLongHelpImageDimension
   * @see #SetTooltipTemplateName
   */
  CATMathPoint2Df GetTooltipLongHelpImageDimension() const;
  /**
   * Shortcut function for the standard tooltip. Will only work if there is a
   * "LongHelpImageDimension" CATMathPoint2Df introspectable property in the tooltip.
   * Default value is (150, 75).
   *
   * @param i_imageDim the dimension of the long help tooltip image on the screen.
   *
   * @see #GetTooltipLongHelpImage
   * @see #GetTooltipLongHelpImageDimension
   * @see #SetTooltipTemplateName
   */
  void SetTooltipLongHelpImageDimension(const CATMathPoint2Df& i_imageDim);
  /**
   * Shortcut function for the default and standard tooltips. Will only work if there is a 
   * "Title" CATUnicodeString introspectable property in the tooltip.
   *
   * @return the title of the tooltip.
   *
   * @see #SetTooltipTitle
   * @see #SetTooltipTemplateName
   */ 
  CATUnicodeString GetTooltipTitle() const;
  /**
   * Shortcut function for the default and standard tooltips. Will only work if there is a 
   * "Title" CATUnicodeString introspectable property in the tooltip. Default
   * value is empty string, which corresponds to no title.
   *
   * @param i_sTitle the title of the tooltip.
   *
   * @see #GetTooltipTitle
   * @see #SetTooltipTemplateName
   */
  void SetTooltipTitle(const CATUnicodeString& i_sTitle);
  /**
   * Shortcut function for the default and standard tooltips. Will only work if there is a 
   * "ShortHelp" CATUnicodeString introspectable property in the tooltip.
   *
   * @return the short-help of the tooltip.
   *
   * @see #SetTooltipShortHelp
   * @see #SetTooltipTemplateName
   */
  CATUnicodeString GetTooltipShortHelp() const;
  /**
   * Shortcut function for the default and standard tooltips. Will only work if there is a 
   * "ShortHelp" CATUnicodeString introspectable property in the tooltip.
   * Default value is empty string, which corresponds to no short help.
   *
   * @param i_sShortHelp the short-help of the tooltip.
   *
   * @see #GetTooltipShortHelp
   * @see #SetTooltipTemplateName
   */
  void SetTooltipShortHelp(const CATUnicodeString& i_sShortHelp);
  /**
   * Shortcut function for the default and standard tooltips. Will only work if there is a 
   * "LongHelp" CATUnicodeString introspectable property in the tooltip.
   *
   * @return the long-help of the tooltip.
   *
   * @see #SetTooltipLongHelp
   * @see #SetTooltipTemplateName
   */
  CATUnicodeString GetTooltipLongHelp() const;
  /**
   * Shortcut function for the default and standard tooltips. Will only work if there is a 
   * "LongHelp" CATUnicodeString introspectable property in the tooltip.
   * Default value is empty string, which corresponds to no long help.
   *
   * @param i_sLongHelp the long-help of the tooltip.
   *
   * @see #GetTooltipLongHelp
   * @see #SetTooltipTemplateName
   */
  void SetTooltipLongHelp(const CATUnicodeString& i_sLongHelp);
  /**
   * Shortcut function for the default tooltip. Will only work if there is an 
   * "HyperlinkLabel" CATUnicodeString introspectable property in the tooltip.
   *
   * @return the label of the hyperlink of the tooltip.
   *
   * @see #GetTooltipHyperlinkLabel
   * @see #SetTooltipTemplateName
   */ 
  CATUnicodeString GetTooltipHyperlinkLabel() const;
  /**
   * Shortcut function for the default tooltip. Will only work if there is an 
   * "HyperlinkLabel" CATUnicodeString introspectable property in the tooltip.
   * Default value is empty string, which corresponds to no hyperlink. If you
   * wan a clickable hyperlink, the hyperlink label must not be empty and the
   * tooltip persistence must be set to @ref CATVid#Reachable so that you can 
   * reach your long tooltip before it disappears.
   *
   * @param i_sHyperlinkLabel a label for the hyperlink of the tooltip.
   *
   * @see #GetTooltipHyperlinkLabel
   * @see #SetTooltipTemplateName
   * @see CATVid#TooltipPersistece
   */
  void SetTooltipHyperlinkLabel(const CATUnicodeString& i_sHyperlinkLabel);
  /**
   * Default hyperlink URL is an empty URL.
   *
   * @return the tooltip hyperlink URL.
   *
   * @see #SetTooltipHyperlinkURL
   */ 
  CATVidURL GetTooltipHyperlinkURL() const;
  /**
   * Shortcut function for the default tooltip. This URL will be opened when
   * clicking on the @c TooltipHyperlinkLabel in the default tooltip, unless
   * the @ref #TooltipHyperlinkClicked event sent from the tooltip to the
   * control is consumed. For example, you can consume this event to run a 
   * command when the hyperlink label is clicked on in the tooltip.
   *
   * @param i_sHyperlink the hyperlink URL of the tooltip.
   *
   * @see #TooltipHyperlinkClicked
   */
  void SetTooltipHyperlinkURL(const CATVidURL& i_sHyperlink);
  /**
   * @return the name of the data template to use for short or long tooltip 
   * display.
   *
   * @param i_eTooltipForm the concerned tooltip form.
   *
   * @see #SetTooltipTemplateName
   * @see CATVid#TooltipForm
   */
  CATUnicodeString GetTooltipTemplateName(CATVid::TooltipForm i_eTooltipForm) const;
  /**
   * Sets the name of the data template to use for short or long tooltip 
   * display. 
   *
   * @param
   * If you want to define a new data template to display the default-tooltip
   * data block, you may use data-binding with the following parameters:
   *
   * @li <BoxProperty type="CATUnicodeString" name="Title"/>
   * @li <BoxProperty type="CATUnicodeString" name="ShortHelp"/>
   * @li <BoxProperty type="CATUnicodeString" name="LongHelp"/>
   * @li <BoxProperty type="CATUnicodeString" name="Image"/>
   * @li <BoxProperty type="CATUnicodeString" name="ShortHelpImage"/>
   * @li <BoxProperty type="CATUnicodeString" name="LongHelpImage"/>
   * @li <BoxProperty type="CATMathPoint2Df" name="ImageDimension"/>
   * @li <BoxProperty type="CATMathPoint2Df" name="ShortHelpImageDimension"/>
   * @li <BoxProperty type="CATMathPoint2Df" name="LongHelpImageDimension"/>
   * @li <BoxProperty type="CATUnicodeString" name="HyperlinkLabel"/>
   * @li <BoxProperty type="int" name="WrapThreshold"/>
   * @li <BoxProperty type="int" name="WrapToleranceMargin"/>
   *
   * @param
   * Parameter "XXX" in the tooltip corresponds to parameter "TooltipXXX" 
   * in the @c CATVidCtl. The frame that will hold your tooltip is compact,
   * meaning that each component of your tooltip will appear at minimum
   * dimension.
   *
   * @param
   * Conversely, the default data templates for short and long tooltips handles
   * any data block or introspectable object that opens above parameters to 
   * introspection. Please pay attention that some parameters are related to
   * the default tooltip template only, some to the standard tooltip virtual
   * template only (new template used for documentation). See #SetTooltipProvider
   * to know which.
   *
   * @param
   * Finally, in the default tooltip, if you want the tooltip hyperlink clic to be active on your
   * tooltip, you must use a "Hyperlink"-sypnamed @ref CATVidCtlButton, 
   * that may display the @c TooltipHyperlinkLabel, for example:
   *
   * @code
   * <CATVidCtlButton Label="@HyperlinkLabel" UnderlineFlag="1" 
   *		CropPolicy="NoCrop" ForegroundColor="80 80 80 255"
   *		syp:Template="Hyperlink" syp:name="Hyperlink"/>
   * @endcode
   * 
   * The URL provided as the @c TooltipHyperlinkURL will be opened when this
   * "Hyperlink"-sypnamed @c CATVidCtlButton is clicked on.
   *
   * @param
   * Similarly, if you want ".mng" animation support on your @c TooltipImage,
   * you must put this image as the texture of a "ImageSquare"-sypnamed
   * @ref CATVidGPSquare, such as:
   *
   * @code
   *  <CATVidGPSquare Texture="@Image" 
   *		RequestedMinimumDimension="@ImageDimension" 
   *		syp:name="ImageSquare"/>
   * @endcode
   *
   * @param i_eTooltipForm short or long.
   * @param i_sTemplateName the name of the template to use.
   *
   * @see #GetTooltipTemplateName
   */
  void SetTooltipTemplateName(CATVid::TooltipForm i_eTooltipForm, const CATUnicodeString& i_sTemplateName);
  /**
   * Default value points to the default short tooltip data template. Set to the virtual template
   * "StandardTemplate" to activate the new templates used for documentation: the right template will
   * be selected at runtime, provided that you let the auto-detect functionality activated.
   * 
   * @param i_sTemplateName the name of the template for the short tooltip form.
   *
   * @see #SetTooltipTemplateName
   */
  void SetShortTooltipTemplateName(const CATUnicodeString& i_sTemplateName);
  /**
   * @return the name of the template for the short tooltip form.
   *
   * @see #GetTooltipTemplateName
   */
  CATUnicodeString GetShortTooltipTemplateName() const;
  /**
   * Default value points to the default long tooltip data template. Set to the virtual template
   * "StandardTemplate" to activate the new templates used for documentation: the right template will
   * be selected at runtime, provided that you let the auto-detect functionality activated.
   *
   * @param i_sTemplateName the name of the template for the long tooltip form.
   *
   * @see #SetTooltipTemplateName
   */
  void SetLongTooltipTemplateName(const CATUnicodeString& i_sTemplateName);
  /**
   * @return the name of the template for the long tooltip form.
   *
   * @see #GetTooltipTemplateName
   */
  CATUnicodeString GetLongTooltipTemplateName() const;
  /**
   * @param i_eTooltipForm short or long. 
   *
   * @return the name of the style sheet where the data template for short or 
   * long tooltip for is defined.
   *
   * @see #SetTooltipStyleSheet
   */
  CATUnicodeString GetTooltipStyleSheet(CATVid::TooltipForm i_eTooltipForm) const;
  /**
   * Sets the name of the style sheet where the data template for the short or 
   * long tooltip is defined. Default value is the style sheet of default data 
   * template (see @ref #SetTooltipTemplateName).
   * 
   * @param i_eTooltipForm short or long.
   * @param i_sStyleSheet the name of the style sheet.
   *
   * @see #GetShortTooltipStyleSheet
   */
  void SetTooltipStyleSheet(CATVid::TooltipForm i_eTooltipForm, CATUnicodeString& i_sStyleSheet);
  /**
   * @return the name of the style sheet where the data template for the short
   * tooltip for is defined.
   *
   * @see #SetShortTooltipStyleSheet
   */
  CATUnicodeString GetShortTooltipStyleSheet() const;
  /**
   * Sets the name of the style sheet where the data template for the short 
   * tooltip is defined. Default value is the style sheet of default data 
   * template (see @ref #SetShortTooltipTemplateName).
   * 
   * @param i_sStyleSheet the name of the style sheet.
   *
   * @see #GetShortTooltipStyleSheet
   */
  void SetShortTooltipStyleSheet(const CATUnicodeString& i_sStyleSheet);
  /**
   * @return the name of the style sheet where the data template for the short
   * tooltip for is defined.
   *
   * @see #SetLongTooltipStyleSheet
   */
  CATUnicodeString GetLongTooltipStyleSheet() const;
  /**
   * Sets the name of the style sheet where the data template for the short 
   * tooltip is defined. Default value is the style sheet of default data 
   * template (see @ref #SetLongTooltipTemplateName).
   * 
   * @param i_sStyleSheet the name of the style sheet.
   *
   * @see #GetLongTooltipStyleSheet
   */
  void SetLongTooltipStyleSheet(const CATUnicodeString& i_sStyleSheet);
  /**
   * @return the offset between mouse position and the upper-left corner of the
   * tooltip when displayed.
   *
   * @see #SetTooltipOffset
   */
  CATMathPoint2Df GetTooltipOffset() const;
  /**
   * The tooltip will be displayed at the position of the mouse augmented by 
   * the an offset, the base point being the upper-left corner of the tooltip 
   * frame. If the tooltip does not fall inside the viewer, it will be pushed 
   * inside. 
   *
   * By default, the offset is <tt>(15, 15)</tt>.
   *   
   * @param i_offset the offset between mouse position and the upper-left 
   * corner of the tooltip when displayed.
   *
   * @see #GetTooltipOffset
   */
  void SetTooltipOffset(CATMathPoint2Df i_offset);
  /**
   * @return the tooltip initial delay, in seconds.
   *
   * @see #SetTooltipInitialDelay
   */
  float GetTooltipInitialDelay() const;
  /**
   * Default tooltip initial delay is 0.5 second.
   * 
   * @param i_fDelay the delay after which the tooltip must appear when 
   * the cursor is immobile over a control (in short form if the tooltip type 
   * is @ref CATVid#ShortOnly or @ref CATVid#ShortThenLong tooltip, in long 
   * form if the tooltip type is @ref CATVid#LongOnly).
   *
   * @ref #GetTooltipInitialDelay
   */
  void SetTooltipInitialDelay(float i_fDelay);
  /**
   * @return the tooltip short-to-long delay, in seconds.
   *
   * @see #SetTooltipShortToLongDelay
   */
  float GetTooltipShortToLongDelay() const;
  /**
   * Default tooltip short-to-long delay is 2 seconds.
   * 
   * @param i_fDelay the delay after which the long tooltip must appear when 
   * the cursor is immobile over a control and the short tooltip is already on 
   * display.
   *
   * @see #GetTooltipShortToLongDelay
   */
  void SetTooltipShortToLongDelay(float i_fDelay);
  /**
   * @return the tooltip autopop delay, in seconds.
   *
   * @see #SetTooltipAutoPopDelay
   */
  float GetTooltipAutoPopDelay() const;
  /**
   * Default tooltip autopop delay is 8 seconds.
   *
   * @param i_fDelay the delay after which the tooltip must disappear when the 
   * cursor is immobile over a control and the long tooltip is on display (if 
   * the tooltip type is @ref CATVid#LongOnly or CATVid#ShortThenLong) or the 
   * short tooltip is on display (if the tooltip type is case 
   * CATVid#ShortOnly).
   *
   * @see #GetTooltipAutoPopDelay
   */
  void SetTooltipAutoPopDelay(float i_fDelay);
  /**
   * @return the tooltip deactivate delay, in seconds.
   *
   * @see #SetTooltipDeactivateDelay
   */
  float GetTooltipDeactivateDelay() const;
  /**
   * Default tooltip deactivate delay is 0.5 second. 
   *
   * @param i_fDelay the delay after which the tooltip goes inactive when the 
   * cursor is immobile over a control. If it the mouse cursor moves over 
   * another control and this other control has a tooltip before this delay 
   * times out, the other tooltip is displayed after @c TooltipReshowDelay 
   * seconds, which is supposed to be a smaller than the 
   * @c TooltipInitialDelay .
   *
   * @see #GetTooltipDeactivateDelay
   * @see #SetTooltipInitialDelay
   * @see #SetTooltipReshowDelay
   */
  void SetTooltipDeactivateDelay(float i_fDelay);
  /**
   * @return the tooltip reshow delay, in seconds.
   *
   * @see #SetTooltipReshowDelay
   */
  float GetTooltipReshowDelay() const;
  /**
   * Default tooltip reshow delay is 0.1 second. 
   *
   * @param i_fDelay the delay after which the tooltip can be displayed 
   * if the @c DeactivateDelay of the last tooltip has not ran out. It is
   * supposed to be smaller than @c TooltipInitialDelay .
   *
   * @see #GetTooltipReshowDelay
   * @see #SetTooltipInitialDelay
   * @see #SetTooltipReshowDelay
   */
  void SetTooltipReshowDelay(float i_fDelay);
  /**
   * Tunes all tooltip delays with the current initial tooltip delay as a 
   * reference:
   *
   * @li @c TooltipAutoPopDelay = 16 * @c TooltipInitialDelay
   * @li @c TooltipShortToLongDelay = 4 * @c TooltipInitialDelay
   * @li @c TooltipDeactivateDelay = @c TooltipInitialDelay
   * @li @c TooltipReshowDelay = @c TooltipInitialDelay / 5
   *
   * @see #SetTooltipInitialDelay
   * @see #SetTooltipShortToLongDelay
   * @see #SetTooltipAutoPopDelay
   * @see #SetTooltipDeactivateDelay
   */
  void AdjustAllTooltipDelays();
  /**
   * @see SetAutoDetectTooltipTypeFlag
   */
  CATBoolean GetAutoDetectTooltipTypeFlag() const;
  /** 
   * The tooltip infrastructure can detect which tooltip form must be displayed
   * (short, long, or short then long) depending on how the tooltip has been
   * filled in, dynamically, just before the tooltip is displayed.
   * 
   * @par
   * By default, auto-detect is activated.
   *
   * @par
   * If the tooltip has a not-empty @c CATUnicodeString "ShortHelp" parameter, 
   * then the short tooltip will be displayed.
   *
   * @par
   * In addition, the long tooltip will be displayed if the tooltip has any of 
   * the following parameters:
   * @li a not-empty @c CATUnicodeString "Title"
   * @li a not-empty @c CATUnicodeString "LongHelp"
   * @li a not-empty @c CATUnicodeString "HyperlinkLabel"
   *
   * @par
   * This mode works exclusively with the default tooltip provider. If your
   * tooltip data template is different from the default one, assertions may
   * be risen. Thus, it is automatically deactivated when a custom tooltip 
   * provider is given.
   *
   * @param i_bAutoDetect @c TRUE to activate auto-detect, @ FALSE else.
   */
  void SetAutoDetectTooltipTypeFlag(CATBoolean i_bAutoDetect);
  /**
   * Sets the type of the tooltip. This will define what will be displayed
   * of the tooltip when staying immobile over a control:
   *
   * @li @ref CATVid#ShortThenLong : short form, then long form.
   * @li @ref CATVid#ShortOnly : short form only.
   * @li @ref CATVid#LongOnly : long form only.
   * @li @ref CATVid#NotDisplayed : tooltip not displayed (default when the
   * @c AutoDetectTooltipTypeFlag is not activated).
   *
   * @param i_eTooltipType the type of the tooltip.
   *
   * Deactivate @c AutoDetectTooltipTypeFlag if you want to set a static 
   * tooltip type.
   *
   * @see CATVid#TooltipType
   */
  void SetTooltipType(CATVid::TooltipType i_eTooltipType);
  /**
   * @return the type of the tooltip.
   *
   * @see #SetTooltipType
   */
  CATVid::TooltipType GetTooltipType() const;
  /**
   * @deprecated
   * Deprecated method. Currently, this method does nothing.
   *
   * @see #GetTooltipPersistence
   */
  void SetTooltipPersistence(CATVid::TooltipPersistence i_eTooltipPersistence);
  /**
   * This methods gives the persistence state of the tooltip.
   * The persistence state of the tooltip is @ref CATVid#Reachable
   * if the tooltip has an HyperLink URL set.
   * It will be @ref CATVid#HideWhenMoving otherwise.
   *
   * @return the persistence state of the tooltip.
   *
   * @see CATVid#TooltipPersistence
   */
  CATVid::TooltipPersistence GetTooltipPersistence() const;
  /** 
   * The tooltip wrap policy defines the overall look of the tooltip.
   *
   * @li @ref CATVid#SingleLine : single-line look.
   * When this policy is used with the default tooltip template, short and long 
   * help will wrap at the @c TooltipWrapThreshold with a 
   * @c TooltipWrapToleranceMargin, abiding to a @ref CATVid#ToleranceMargin 
   * wrap policy.
   * @li @ref CATVid#MultiLine (default): multi-line look.
   * When this policy is used with the default tooltip template, the widths of 
   * the short and long help of the tooltip are limited to 90 percents of the 
   * viewer size. 
   *
   * @param i_eTooltipWrapPolicy the wrapping policy of the tooltip.
   *
   * @see CATVid#TooltipWrapPolicy
   * @see #SetTooltipWrapThreshold
   * @see #SetTooltipWrapToleranceMargin
   */
  void SetTooltipWrapPolicy(CATVid::TooltipWrapPolicy i_eTooltipWrapPolicy);
  /**
   * @return the wrapping policy of the tooltip (multi-line or single-line).
   *
   * @see #SetTooltipWrapPolicy
   */
  CATVid::TooltipWrapPolicy GetTooltipWrapPolicy() const;
  /**
   * Set the animation policy of the tooltip, used if the tooltip image is a
   * ".mng".
   * 
   * @param i_eTooltipAnimationPolicy the tooltip animation policy
   *
   * @see CATVid#TooltipAnimationPolicy
   */
  void SetTooltipAnimationPolicy(CATVid::TooltipAnimationPolicy i_eTooltipAnimationPolicy);
  /**
   * @return the animation policy of the tooltip, used if the tooltip image is
   * a ".mng".
   *
   * @see #SetTooltipAnimationPolicy
   * @see CATVid#TooltipAnimationPolicy
   */
  CATVid::TooltipAnimationPolicy GetTooltipAnimationPolicy() const;
  /**
   * Sets the position policy of the tooltip. The default position policy is
   * @ref CATVid#MouseRelative.
   *
   * @param i_eTooltipPositionPolicy the position policy of the tooltip.
   *
   * @see CATVid#PositionPolicy
   */
  void SetTooltipPositionPolicy(CATVid::PositionPolicy i_eTooltipPositionPolicy);
  /**
   * @return the position policy fo the tooltip.
   *
   * @see #SetTooltipPositionPolicy
   */
  CATVid::PositionPolicy GetTooltipPositionPolicy() const;
  /**
   * Shortcut function for the default tooltip. Will only work if there is a 
   * "WrapThreshold" int introspectable property in the tooltip. 
   *
   * Sets the wrapping threshold of short and long help in a multi-line 
   * tooltip. Default value is 270 pixels.
   *
   * @param i_iTooltipWrapThreshold the wrapping threshold of short help and 
   * long help in the tooltip, in pixels.
   *
   * @see #SetTooltipWrapPolicy
   * @see CATVid#WrapPolicy
   * @see #GetTooltipWrapThreshold
   * @see #SetTooltipTemplateName
   */
  void SetTooltipWrapThreshold(int i_iTooltipWrapThreshold);
  /**
   * Shortcut function for the default tooltip. Will only work if there is a 
   * "WrapThreshold" int introspectable property in the tooltip.
   *
   * @return the wrapping threshold of short help and long help in the tooltip,
   * in pixels. 
   *
   * @see #SetTooltipWrapThreshold
   * @see #SetTooltipTemplateName
   */
  int GetTooltipWrapThreshold() const;
  /**
   * Shortcut function for the default tooltip. Will only work if there is a 
   * "WrapToleranceMargin" int introspectable property in the tooltip. 
   *
   * Sets the wrapping tolerance margin of short and long help in a multi-line 
   * tooltip. Default value is 100 pixels.
   *
   * @param i_iTooltipWrapThreshold the wrapping tolerance margin of short help 
   * and long help in the tooltip, in pixels.
   *
   * @see #SetTooltipWrapPolicy
   * @see CATVid#WrapPolicy
   * @see #GetTooltipWrapToleranceMargin
   * @see #SetTooltipTemplateName
   */
  void SetTooltipWrapToleranceMargin(int i_iTooltipWrapToleranceMargin);
  /**
   * Shortcut function for the default tooltip. Will only work if there is a 
   * "WrapToleranceMargin" int introspectable property in the tooltip.
   *
   * @return the wrapping tolerance margin of short help and long help in the 
   * tooltip, in pixels. 
   *
   * @see #SetTooltipWrapToleranceMargin 
   * @see #SetTooltipTemplateName
   */
  int GetTooltipWrapToleranceMargin() const; 
  /**
   * @return @c TRUE if the tooltip must not disappear as long as we are over
   * the control that launched it, @c FALSE else. Default value is @c FALSE.
   * Must be @c FALSE for all big controls (for example a control that has
   * the size of the screen: the tooltip would never disappear), may be @c TRUE
   * in any other case.
   */
  CATBoolean GetTooltipPersistOverCtlFlag() const;
  /**
   * Set to @c TRUE if the tooltip must not disappear as long as we are over
   * the control that launched it, @c FALSE else.
   */
  void SetTooltipPersistOverCtlFlag(CATBoolean i_bFlag); 
  /**
   * @return @c TRUE if the position of the long tooltip must be recalculated
   * after display of the short tooltip, @c FALSE else. Default is @c FALSE.
   */
  CATBoolean GetUpdateLongTooltipPositionFlag() const;
  /**
   * Set to @c TRUE to allow the long tooltip to be positionned somewhere else
   * than the short tooltip (change in tooltip offset, change in mouse 
   * position), @c FALSE else. 
   */
  void SetUpdateLongTooltipPositionFlag(CATBoolean i_bFlag);
  /**
   * Allows the tooltip to be displayed once again on this control, even
   * if it has already been displayed and the mouse did not already hover 
   * another control.
   */
  void ResetTooltipAlreadyDisplayedState();
  /**
   * Default value of the long help ID is empty string. It corresponds to a
   * control for which no long help has been defined. Here, "long help" is an 
   * online help, longer than the long tooltip, that may be accessed when the 
   * tooltip (short or long) of the control is on display.
   *
   * @par
   * The long help ID is saved as the current long help ID in the 
   * @ref CATInteractiveApplication as soon as the tooltip is displayed (in 
   * short form for @ref CATVid#ShortOnly or @ref CATVid#ShortThenLong 
   * tooltips, in long form for @ref CATVid#LongOnly). It is removed from the 
   * @ref CATInteractiveApplication when the tooltip disappear (in short form
   * for @ref CATVid#ShortOnly tooltip, in long form for 
   * @ref CATVid#ShortThenLong and @ref CATVid#LongOnly tooltips).
   * 
   * @param i_longHelpId ID for the long help of the control.
   * 
   * @see CATDialog#SetLongHelpId
   */
  void SetLongHelpId(const CATUnicodeString& i_longHelpId);
  /**
   * @return the ID for the long help of the control.
   *
   * @see #SetLongHelpId
   * @see CATDialog#GetLongHelpId
   */
  const CATUnicodeString& GetLongHelpId() const;

  //---------------------------------------------------------------------------
  //                             Context menu
  //---------------------------------------------------------------------------
  /**
   * Each control can be enriched with a context menu, available on right
   * click on said control. At first call, if no context menu has been defined,
   * this getter calls @ref #BuildDefaultContextMenu and returns it.
   *
   * @return the not @c NULL current context menu associated to this 
   * control. @ AddRef has not been called on returned pointer.
   *
   * @see GiveContextMenu
   */
  CATVidMdlContextMenu * GetContextMenu();
  /**
   * @return the current context menu associated to this control, @c NULL if
   * it has not been instanciated yet. @c AddRef has not been called on 
   * returned pointer.
   *
   * @see #GetContextMenu
   */
  CATVidMdlContextMenu * GiveContextMenu() const;
  /**
   * Creates a default empty context menu and associates it to the control. You
   * can then enrich this context menu by adding @ref CATVidActions and 
   * separators to it.
   *
   * @see CATVidMdlContextMenu
   */
  void BuildDefaultContextMenu();
  /**
   * @return TRUE if the control has been defined a context menu, 
   * @c FALSE else.
   */
  CATBoolean HasAContextMenu() const;
  /**
   * A default context menu is already associated to this control, available by 
   * calling @ref #GetContextMenu. Nonetheless, if you need to associate an
   * already instanciated context menu to the control, you can do so by
   * calling this setter. @c AddRef will be called on input pointer; you
   * are responsible for releasing your own pointer.
   *
   * @param i_pMdlContextMenu a context menu to associate to the control.
   *
   * @see #GetContextMenu
   */
  void SetContextMenu(CATVidMdlContextMenu * i_pMdlContextMenu);
  /**
   * Display the context menu under the mouse pointer, in the viewer of the
   * control. By default, this function is called on right click on the 
   * control.
   *
   * @see #ContextMenuRequired
   */
  void DisplayContextMenuAtDefaultPosition();
  /**
   * Display the context menu in a given viewer, at a given position, one time.
   *
   * @param i_pViewer the viewer in which to display the context menu. Must not
   * be @c NULL.
   * @param i_position the position of the context menu inside the viewer.
   *
   * @see #ContextMenuRequired
   */
  void DisplayContextMenu(CATVizViewer * i_pViewer, const CATMathPoint2Df& i_position); 
  /**
   * Hide the context menu of the control. 
   */
  void HideContextMenu();
  /**
   * Returns the context menu owner.
   * The default implementation returns this.
   */
  CATVidCtl * GetContextMenuOwner() const;

  /**
  * Specify if this control will be used in responsive design context.
  * Set this flag only if your template use several version according to control dimension.
  * See complete doc at : http://wikitechno/wiki/index.php/CID_:_Responsive_Design.
  */
  void SetResponsiveFlag(CATBoolean i_ResponsiveFlag);

  /**
  * Get the responsive design flag of this control.   
  */
  CATBoolean GetResponsiveFlag()const;

   /** 
   * Get the @c TooltipHyperlinkClicked event.
   *
   * The @c TooltipHyperlinkClicked event is emitted when the hyperlink of the
   * default tooltip is clicked on. If you consume this event, the tooltip URL
   * will not be opened by the tooltip infrastructure.
   * 
   * @par EventProperties
   *   @li Name: @c "TooltipHyperlinkClicked"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   */
  static CATSYPEvent * TooltipHyperlinkClicked();
  /** 
   * Get the @c TooltipBeforeDisplay event.
   *
   * The @c TooltipBeforeDisplay event is emitted just before a tooltip is
   * displayed. At this time, the position of the tooltip has not been
   * calculated, so the tooltip offset can still be changed.
   * 
   * @par EventProperties
   *   @li Name: @c "TooltipBeforeDisplay"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidTooltipFormEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   */
  static CATSYPEvent * TooltipBeforeDisplay();
  /** 
   * Get the @c PreContextMenuRequired event. 
   *
   * @par
   * The @c PreContextMenuRequired event is emitted just before the
   * @c ContextMenuRequiredEvent, after a right click on the control.
   * It is transmitted from the root widget to the origin @c CATVidGP 
   * of the @c CATVidGP#RightClick event.
   *
   * @par EventProperties
   *   @li Name: @c "PreContextMenuRequired"
   *   @li Type of propagation: @c RootToOrigin
   *   @li Type of argument: @ref CATVidMouseAndKeyboardEventArgs
   *
   * It allows a father widget of the control to take responsibility over
   * the context menu.
   * 
   * If this event is consumed on a control, the @c ContextMenuRequired
   * events of its children are never sent. You can fill-in and/or display
   * your own context menu instead (see @ref #DisplayContextMenuAtDefaultPosition).
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer. 
   *
   * @see ContextMenuRequired
   */
  static CATSYPEvent * PreContextMenuRequired();
  /** 
   * Get the @c ContextMenuRequired event. 
   *
   * @par
   * The @c ContextMenuRequired event is emitted on right click on the control
   * if the control has a not @c NULL context menu (see @ref #GetContextMenu). 
   * If you plan to fill-in the context menu dynamically, it must be created
   * empty beforehand.
   * 
   * @par EventProperties
   *   @li Name: @c "ContextMenuRequired"
   *   @li Type of propagation: @c OriginToRoot
   *   @li Type of argument: @ref CATVidMouseAndKeyboardEventArgs
   *
   * @par 
   * If the event is emitted because of a right click on the control, the 
   * arguments of the right click can be recovered by calling 
   * @ref CATVidMouseAndKeyboardEventArgs#GetMouseEventArgs. On that case,
   * @ref CATVidMouseAndKeyboardEventArgs#GetKeyboardEvent returns @c NULL.
   *
   * @par 
   * Else, the event is emitted because of a click on the context menu key on
   * windows. This keyboard event can be recovered by calling
   * @ref CATVidMouseAndKeyboardEventArgs#GetKeyboardEvent.
   * On that case, @ref CATVidMouseAndKeyboardEventArgs#GetMouseEventArg
   * returns @c NULL.
   *
   * @par Dynamic context menu 
   * If you listen to this event, you can fill-in the context menu just before
   * display. Still, you must have set an empty context menu or called
   * @ref #BuildDefaultContextMenu once to receive the event. If you do not
   * consume the event, the context menu will be displayed by the 
   * infrastructure just after you filled it.
   *
   * @par 
   * If you consume this event, the context menu will not be displayed by the 
   * infrastructure. This allows you to:
   * @li deactivate context menu on right click: do nothing when receiving the
   * event and display the context menu by yourself when you need it
   * (call #DisplayContextMenuAtDefaultPosition)
   * @li display the context menu at another position than the default one 
   * (call @ref #DisplayContextMenu).
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer. 
   *
   * @see PreContextMenuRequired
   */
  static CATSYPEvent * ContextMenuRequired();
  /** 
   * Get the @c ContextMenuHidden event. 
   *
   * @par
   * The @c ContextMenuHidden event is emitted just after a displayed context
   * menu is hidden.
   * 
   * @par EventProperties
   *   @li Name: @c "ContextMenuHidden"
   *   @li Type of propagation: @c OriginToRoot
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer. 
   */
  static CATSYPEvent * ContextMenuHidden();

  //---------------------------------------------------------------------------
  //                             Drag and drop
  //---------------------------------------------------------------------------
  /**
   * The drag mode specifies what happens in case it is dragged. By default 
   * (@ref CATVidDnD#Inactive), nothing happens.
   *
   * If any other drag mode is chosen, the control becomes a drag source: it 
   * will emit @ref #Dragged and @ref #Dropped events.
   * 
   * @return the current drag mode.
   *
   * @see CATVidDnD#Mode
   * @see #Dragged
   * @see #Dropped
   */
  CATVidDnD::Mode GetDragMode() const;
  /**
   * @param i_mode the drag mode for this control.
   *
   * @see #GetDragMode
   */
  void SetDragMode(CATVidDnD::Mode i_mode);
  /**
   * @return all drag-and-drop effects available for the drag source.
   *
   * @see CATVidDnD#Effect
   */
  CATVidDnD::Effects GetPossibleDnDEffects();
  /**
   * @param i_effects available drag-and-drop effects on the drag source.
   * 
   * @see GetPossibleDnDEffects
   */
  void SetPossibleDnDEffects(CATVidDnD::Effects i_effects);
  /**
   * The drop mode specifies what will happen when data to drop is moved over 
   * the control. By default (@ref CATVidDnD#Inactive), the control does not
   * accept drops, so nothing happens. 
   *
   * Else, the control becomes a drop source: it will emit @ref #CanImportData
   * and #ImportData events.
   *
   * @return the current drag mode.
   *
   * @see CATVidDnD#Mode
   * @see #CanImportData
   * @see #ImportData
   */
  CATVidDnD::Mode GetDropMode() const;
  /**
   * @param i_mode the drop mode for this control.
   * 
   * @see #GetDropMode
   */
  void SetDropMode(CATVidDnD::Mode i_mode);
  /** 
   * Get the @c Dragged event.
   *
   * @par Emission
   * The @c Dragged event is emitted by a drag source (@ref #GetDragMode), when 
   * a prolongated drag happens. A prolongated drag is defined by the reception 
   * of a @ref CATVidGP#Drag while the mouse cursor is far enough (internal 
   * threshold) from the position of the last @ref CATVidGP#Press. One and only 
   * one #Dragged event is emitted per drag-and-drop action.
   *
   * @par Message passing
   * The purpose of this event is to collect the data to export for 
   * drag-and-drop. To export said data, the event handler must create a
   * @ref CATVidDnDData, enrich the event arguments with it 
   * (CATVidDraggedEventArgs#SetSourceData) and consume the event
   * (@ref CATSYPEventArgs#Consume). If the data is @c NULL or the event is
   * not consumed, no drag-and-drop will be initiated.
   *
   * @par EventProperties
   *   @li Name: @c "Dragged"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidDraggedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   */
  static CATSYPEvent * Dragged();
  /** 
   * Get the @c DnDMove event.
   *
   * @par Emission
   * The @c DnDMove event is emitted by a drag source (@ref #GetDragMode) during the drag-and-drop
   * each time the mouse moves.
   *
   * @par EventProperties
   *   @li Name: @c "DnDMove"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   */
  static CATSYPEvent * DnDMove();
  /** 
   * Get the @c Dropped event.
   *
   * @par Emission
   * The @c Dropped event is emitted by a drag source (@ref #GetDragMode),  
   * just after the drag and drop finished. The success of the operation is 
   * described by @ref CATVidDroppedEventArgs#GetSuccess. Depending on the 
   * whether the drag-and-drop succeded or not, and on the effect on drop
   * (CATVidDnD#Effect), actions may be taken by the event handler (eg.
   * destroying the source data representation -- which may be the drag source 
   * itself, or an item in case the drag source is a list -- for a move effect, 
   * etc...). One and only one #Dropped event is emitted per drag-and-drop 
   * action. The receiver should not consume this event.
   *
   * @par EventProperties
   *   @li Name: @c "Dropped"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidDroppedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   */
  static CATSYPEvent * Dropped();
  /** 
   * Get the @c CanImportData event.
   *
   * @par Emission
   *
   * @par
   * @ref #CanImportData events are emitted at each @ref CATVidGP#PreDrop 
   * event received on a drop target (move over), provided that:
   *
   * @li @c DragMode of the drag source and @ref DropMode of the drop target 
   * are compatible
   * @li Current @c RequestedEffect (CATVidDnDEventArgs#GetRequestedEffect) 
   * defined by the current keyboard modifiers 
   * (CATVidMouseEventArgs#GetModifiers, CATVidDnD#Effect) belongs the the 
   * @c DnDEffects allowed on the drag source.
   *
   * Several #ImportData may be emitted per drag-and-drop action.
   *
   * @par
   * At the time of the drop, a final @ref #CanImportData will be emitted, to
   * determine the success of the drop (unless above conditions are not met and
   * the drop can only fail). If the drop is allowed, @ref ImportData will be 
   * emitted.
   *
   * @par
   * Please note that they @ref #CanImportData events are not continuously 
   * received at each move over the drop target in case the @c DragMode of the 
   * drag source is @ref CATVidDnD#Clipboard, but only one time before drop, to 
   * determine the drop success. 
   *
   * @par Message passing
   * The purpose of this event is to determine whether a drop can happen on the
   * drop source, depending on the type of the data currently being dragged and
   * the current position in the drop target. If the receiver wants to update
   * the current feedback, it must fill-in the arguments
   * (@ref CATVidDnDDataEventArgs#SetFeedback). In case it can import the
   * data, it must consume the event.
   *
   * @par Purpose
   * Do not use this event to implement visual feedback during drag-and-drop
   * (see drag-and-drop section of @ref CATVidCtl documentation).
   *
   * @par EventProperties
   *   @li Name: @c "CanImportData"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidDnDDataEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   */
  static CATSYPEvent * CanImportData();
  /** 
   * Get the @c ImportData event.
   *
   * @par Emission
   * The @c ImportData event is emitted on drop, by a drop target source, if 
   * and only if the drop is allowed, ie. the following conditions are
   * met: 
   *
   * @li @c DragMode of the drag source and @ref DropMode of the drop target 
   * are compatible
   * @li Current @c RequestedEffect (CATVidDnDEventArgs#GetRequestedEffect) 
   * defined by the current keyboard modifiers 
   * (CATVidMouseEventArgs#GetModifiers, CATVidDnD#Effect) belongs the the 
   * @c DnDEffects allowed on the drag source.
   * @li the feedback of the @ref #CanImportData emitted just before drop, at
   * the current mouse position, is @c TRUE.
   *
   * Thus, upon reception of the event, the event handler can safely import the 
   * data. Zero or one @ref #ImportData is emitted per drag-and-drop action.
   * The receiver should not consume the event.
   *
   * @par EventProperties
   *   @li Name: @c "ImportData"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidDnDDataEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned 
   * pointer.
   */
  static CATSYPEvent * ImportData();

protected:
  CATVidCtl (CreateLetterFunc i_pCreateLetterFunc);
  CATVidCtl (CATCommand *i_pParent, const CATString & i_pIdentifier, CreateLetterFunc i_pCreateLetterFunc);
  /** Destructor. */
	virtual ~CATVidCtl();
  /** @copydoc CATVidWidget#ChildWidgetDeleted */
  virtual void ChildWidgetDeleted(CATVidWidget* i_pDeletedChild);
  /** @copydoc CATVidWidget#UpdateComputedMinimumDimension */
  virtual void UpdateComputedMinimumDimension();
  /**
   * This function is called once the template data have been collected from the style processor.
   * You can derive it, and use it to access objects in our xml style template by their @c syp:name
   * @see RetrieveSypNamedObject, TryRetrieveSypNamedObject
   */
  virtual void TemplateDataUpdated();
  /**
   * @copydoc CATISYPTemplate#SetTemplatedView
   */
  void SetTemplatedView(CATBaseUnknown_var& i_spView, CATSYPTemplateData* i_pTemplateData);
  /**
   * @copydoc CATISYPTemplate#SetVariationName
   */
  void SetVariationName(const CATUnicodeString& i_variationName);
private:

  CATVidCtl(const CATVidCtl &iToCopy);
  CATVidCtl& operator=(const CATVidCtl&);
private:
  CATUnicodeString _templateName;
  CATUnicodeString _variationName;
  CATUnicodeString _templateStyleToInit;
  friend class TIECATISYPTemplateCATVidCtl;
  friend class CATVidCtlResponsiveUpdater;
public:
    /**
  * Returns TRUE if the control must be seen as a black box, i.e its children must not be watched by the CATVidWatcher, FALSE otherwise.
  */
  CATBoolean GetBlackBoxFlag() const;

  /**
  * Specifies whether the control must be seen as a black box, i.e its children must not be watched by the CATVidWatcher, or not.
  */
  void SetBlackBoxFlag(CATBoolean i__blackBoxFlag);

};

//-----------------------------------------------------------------------------

#endif
