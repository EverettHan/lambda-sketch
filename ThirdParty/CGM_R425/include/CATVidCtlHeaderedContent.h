// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATVidCtlHeaderedContent.h
// Header definition of CATVidCtlHeaderedContent
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  March 2008  Creation: jov
//===================================================================
#ifndef CATVidCtlHeaderedContent_H
#define CATVidCtlHeaderedContent_H

#include <VisuDialog.h>
#include <CATSYPTemplateData.h>
#include <CATVid.h>
#include <CATVidCtl.h>
#include <CATBoolean.h>
#include <CAT4x4Matrix.h>
#include <CATMathPointf.h>
#include <CATVidCursor.h>
#include <CATVidColor.h>
#include <CATISYPPresenter.h>
#include <CATBaseUnknown_WR.h>

class CATVidMinMax;
class CATVidCtlMenuItem;
class CATVidCtlContextMenu;
class CATVidGP;
class CATVidTooltip;
class CATSYPDataBlock;

//-----------------------------------------------------------------------
/**
* @ingroup VIDControls
*/
class ExportedByVisuDialog CATVidCtlHeaderedContent: public CATVidCtl
{
  CATDeclareClass;

  friend class l_CATVidCtlHeaderedContent;

public:
  // Standard constructor
  // --------------------
  CATVidCtlHeaderedContent();
  CATVidCtlHeaderedContent(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
  * Sets the data template to use to build the header view.
  * This method can be called before after creating the headred widget view.
  *
  * @param i_dataTemplate the data template name to use to build the headred view.
  * Can't be an empty unicode string.
  *
  * @param i_styleSheet the sypstyle file in which the data template is defined.
  * Can't be an empty unicode string.
  *
  * Before calling this method check that your i_styleSheet contains the input i_dataTemplate
  * otherwise an error message is displayed
  *
  * It is possible to associate left object using #SetHeaderDataBlock. 
  * Can't be NULL and must be a data block. The #SetHeaderDataBlock must be called 
  * before this method.
  *
  * Widget built with SetHeaderDataTemplate can be retrieved using CATVidCtl::GetPresenterContent.
  *
  * @see #SetHeaderDataBlock
  */
  void SetHeaderDataTemplate(const CATUnicodeString& i_dataTemplateName, const CATUnicodeString& i_styleSheet);


  /**
  * Sets the stylesheet that contains the data template to compute the header view.
  *
  * @note
  * Calling only this member function without calling SetHeaderDataTemplateName
  * is not enough for this control to be able to build the view of data items.
  * So, when you call SetHeaderDataTemplateStyleSheet, you need also to call SetHeaderDataTemplateStyleName.
  *
  * @param i_dataTemplateStyleSheet name of the stylesheet that contains the
  * data template to use to build the view of displayed items.
  *
  * @see SetHeaderDataTemplateName
  */
  void SetHeaderDataTemplateStyleSheet(const CATUnicodeString& i_dataTemplateStyleSheet);

  /**
  * Sets the name of the data template to use to compute the header view.
  *
  * @note
  * Calling only this member function without calling SetDataTemplateStyleSheet
  * is not enough for this control to be able to build the header view.
  * So, when you call SetHeaderDataTemplateName, you need also to call SetHeaderDataTemplateStyleSheet.
  *
  * @param i_dataTemplateName name of the data template to use.
  *
  * @see SetHeaderDataTemplateStyleSheet
  */
  void SetHeaderDataTemplateName(const CATUnicodeString& i_dataTemplateName);

  /**
  * Returns the stylesheet in which the data template to use to compute the header view.
  */
  CATUnicodeString GetHeaderDataTemplateStyleSheet() const;


  /**
  * Returns the name of the data template to use to compute the header view.
  */
  CATUnicodeString GetHeaderDataTemplateName() const;

  /**
  * Releases the previous header data block and associate the new one to the
  * current header data template; the header view will be re-generated
  *
  *@param i_pDataBlock : data block(left object) associated to the current header data template
  * Can't be NULL.
  *
  * By default, the header data block exposes icon and label properties like:
  * for icon : the name,dimension, background color, ColorizeIconBlackPixelTo 
  * and for label : text, font height, font weight, foreground color and crop policy
  * 
  * the UseIconFlag and UseLabelFlag determins if display icon and label in the header view
  * @see #SetHeaderDataTemplate
  */
  void SetHeaderDataBlock(CATSYPDataBlock* i_pDataBlock);

  /**Get header data block*/
  CATSYPDataBlock* GetHeaderDataBlock()const;

  /**
  * Gives the content view i.e physical child to the headeredcontent widget;
  * the view is refreshed and leads resize as content dimension
  * the content should be a kind of CATVidWidget.
  * Warning: if the content inherit from CATVidCtlAbstractItemsView such as CATVidCtlTreeView; 
  * you should give requested minimum dimensions to the content in order to be visible(displayed)
  * @see CATVidWidget#SetRequestedMinimumDimensions
  * @param i_pContent: content widget
  */
  virtual void SetContent(CATVidWidget* i_pContent);
 
  /**Gets content view */
  virtual CATVidWidget* GetContent() const;

  /**Sets header label text color*/
  void SetForegroundColor( const CATVidColor &i_foregroundColor );
  /**Gets current header label text color*/
  const CATVidColor &GetForegroundColor( void ) const;

  /**Sets header label background color*/
  void SetBackgroundColor( const CATVidColor &i_backgroundColor );
  /**Gets current header label background color*/
  const CATVidColor &GetBackgroundColor( void ) const;

  /**Sets header icon name.
  * The icon appears only if you gives a non-NULL dimension; use SetIconDimension 
  * @see #SetIconDimension
  */
  void SetIcon( const CATUnicodeString &i_icon );
  /**Gets header icon name*/
  const CATUnicodeString &GetIcon( void ) const;

  /**
  * SetColorizeBlackPixelTo on header icon
  * @see CATVidGPTexturedWidget#SetColorizeBlackPixelTo
  */
  void SetColorizeIconBlackPixelTo( const CATVidColor & i_colorizeIconBlackPixelTo);
  /**
  * GetColorizeBlackPixelTo on header icon
  * @see CATVidGPTexturedWidget#GetColorizeBlackPixelTo
  */
  const CATVidColor &GetColorizeIconBlackPixelTo() const;

  /**Returns whether if icon header's ColorizeIconBlackPixelTo property is setted*/
  CATBoolean GetColorizeIconBlackPixelFlag() const;
  
  /**Gives dimension to header's icon*/
  void SetIconDimension( const CATMathPoint2Df &i_iconDimension );
  /**Gets icon dimension*/
  const CATMathPoint2Df& GetIconDimension() const;

  /**Sets header label text*/
  void SetLabel( const CATUnicodeString &iLabel );
  /**Gets header label text*/
  const CATUnicodeString &GetLabel( void ) const;

  /**Sets header label text font height*/
  void SetFontHeight(unsigned int i_fontHeight);
  /**Gets header label font height*/
  unsigned int GetFontHeight();

  /**Sets header label text bold flag; 0:Std; 1:Bold*/
  void SetFontWeight(unsigned int i_fontWeight);
  /**Gets header label bold flag*/
  unsigned int GetFontWeight() const;

  /**
  * Sets the crop policy of the label
  * @param i_crop
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
  * Returns the crop policy of the label
  *   <br>
  * The crop property can be:
  *   <dl>
  *   <dt><tt>CATVid::NoCrop</tt><dd> : the minimum dimension of the button is function of the label dimension
  *   <dt><tt>CATVid::CropCut</tt><dd> : the dimension of the button is not function of the label dimension, the label is cutted
  *   <dt><tt>CATVid::CropWithDots</tt><dd> : the dimension of the button is not function of the label dimension, the label is cutted with dots
  *   </dl>
  */  
  CATVid::CropPolicy GetCropPolicy() const;


  virtual CATISYPPresenter_var GetItem();
  void SetHeaderedContentItem(const CATISYPPresenter_var& i_spHeaderedContentItem);
  CATISYPPresenter_var GetHeaderedContentItem();

  /**Returns whether if icon header is setted*/
  CATBoolean GetUseIconFlag() const;

  /**Returns wheter if label header is setted*/
  CATBoolean  GetUseLabelFlag() const;

  virtual void SetChild(CATBaseUnknown_var i_spToConnect);

  /**
   * Specifies whether the window uses margins or not.
   * By default, the UseMarginsFlag property is set to TRUE.
   */
  void SetUseMarginsFlag(CATBoolean i_useMarginsFlag);

  /**
   * Returns TRUE if the window uses margins, FALSE otherwise.
   */
  CATBoolean GetUseMarginsFlag() const;

  protected:
  virtual ~CATVidCtlHeaderedContent ();
  /**
  * Update header view with the _dataTemplateName found in the _dataTemplateStyleSheet
  * @see SetHeaderDataTemplate
  */
  void UpdateHeaderView();
  virtual void ComputeDefaultDataTemplateName(CATUnicodeString& o_dataTemplateName, CATUnicodeString& o_styleSheet) const{}

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlHeaderedContent (CATVidCtlHeaderedContent &);
  CATVidCtlHeaderedContent& operator=(CATVidCtlHeaderedContent& original);
  void CleanHeader();

  /**
  * Create default header data block(left object of header view)
  *
  * @see #ConnectDBProperties
  */
  CATSYPDataBlock* CreateDefaultHeaderDB();

  /**
  * Connect HeadredContent view properties with the data block(left object of header view) properties
  * 
  * By default, the header data block exposes icon and label properties like:
  * for icon : the name,dimension, background color, ColorizeIconBlackPixelTo 
  * and for label : text, font height, font weight, foreground color and crop policy.
  */
  void ConnectDBProperties();

private:
  CATUnicodeString                _icon;
  CATVidColor                     _foregroundColor;
  CATVidColor                     _backgroundColor;
  CATVidColor                     _colorizeIconBlackPixelTo;
  CATUnicodeString                _label;
  int                             _fontHeight;
  unsigned int                    _fontWeight;
  CATVid::CropPolicy              _cropPolicy;
  CATMathPoint2Df                 _iconDimension;

  CATBaseUnknown_WR _wrContent;
  CATBaseUnknown_WR _wrHeader;
  CATISYPPresenter_var _spHeaderedContentItem;
  unsigned char _colorizeIconBlackPixelFlag;

  CATSYPDataBlock* _pHeaderDataBlock;

  CATUnicodeString _dataTemplateName;
  CATUnicodeString _dataTemplateStyleSheet;
  CATBoolean _useMarginsFlag;
  CATSYPTemplateData * _pHeaderContentTemplateData;
  bool _destroyHeaderFlag;

#ifndef VID_DEPRECATED
public:
  void SetCropProperty(CATVidLabelCropProperty i_crop);
  CATVidLabelCropProperty GetCropProperty() const;
#endif
};

//-----------------------------------------------------------------------
#endif
