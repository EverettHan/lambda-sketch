// COPYRIGHT Dassault Systemes 2012
//=============================================================================
//
// CATVidAction.h
// Header definition of CATVidAction
//
//=============================================================================
//  Feb 2012  Creation: LD5
//=============================================================================
#ifndef CATVidAbstractAction_H
#define CATVidAbstractAction_H

#include <VisuDialog.h>
#include <CATVidActionBase.h>
#include <CATUnicodeString.h>
#include <CATString.h>
#include <CATVidURL.h>
#include <CATMathPoint2Df.h>
#include <CATBaseUnknown_WR.h>
#include <CATBoolean.h>
#include <CATPixelImage.h>
class CATVidAbstractActionGroup;
class CATVidMdlMenu;
class CATVidMdlSubMenu;

//-----------------------------------------------------------------------------

/** @ingroup groupVidMenu
 * An action is the abstraction of a command to execute. 
 *
 * @par Disabled actions
 * Disabling an action means that it cannot be interacted with in a menu view
 * anymore. 
 *
 * @par Data template for action menu item
 * Actions in menus have a default data template. 
 * By default, an action is represented by a 22x22 icon corresponding to the 
 * @c Icon introspectable property, and a text field corresponding to the 
 * @c Text property. 
 * A disabled action is greyed and cannot be interacted with. 
 * The default tooltip of the action menu item is filled-in with @c Title, @c ShortHelp, @c ShortHelpImage,
 * @c ShortHelpImageDimension, @c LongHelp,  @c LongHelpImage, @c LongHelpImageDimension, @c HyperlinkURL, 
 * @c HyperlinkLabel.  
 *
 * @see CATVidAction
 * @see CATVidSubMenuAction
 * @see CATVidActionGroup
 * @see CATVidMdlMenu
 */
class ExportedByVisuDialog CATVidAbstractAction : public CATVidActionBase
{
  CATDeclareClass;
  friend class CATVidAbstractActionGroup;
  friend class CATVidMdlMenu;

public:
  /**
   * @return @c TRUE if the action is inside a group, @c FALSE else.
   */
  CATBoolean HasAGroup() const;
  /**
   * @return the icon representing the action.
   */
  CATUnicodeString GetIcon() const;
  /**
   * Set the icon representing the action. Default is empty string.
   *
   * @param i_sIconFile the name of the file where the icon representation of 
   * the action can be found (eg. <tt>"extrude_icon.png"</tt>).
   */
  void SetIcon(const CATUnicodeString& i_sIconFile);
  /**
   * @return the text representing the action.
   */
  CATUnicodeString GetText() const;
  /**
   * Sets the text representing the action (eg. <tt>"Extrude"</tt>).
   * Default is empty string.
   *
   * @param i_sText string representation of the action.
   */
  void SetText(const CATUnicodeString& i_sText);
  /**
   * @return the name identifying a widget that should represent this action in 
   * a CID record debug path (@c Name of the widget).
   */
  CATString GetRecordName() const;
  /**
   * Sets the name identifying an widget that should represent this action in a 
   * CID record debug path (@c Name of the widget). 
   *
   * @param i_sName string representation of the action. 
   */
  void SetRecordName(const CATString& i_sName);
  /**
   * @return short help explaining the command of the action.
   */
  CATUnicodeString GetShortHelp() const;
  /**
   * Associates a short help to the command of the action. Default is empty 
   * string.
   *
   * @param i_sShortHelp short help explaining what the action does (eg. 
   * <tt>"Extrudes a 2D mesh."</tt>).
   *
   * @see CATVidCtl#SetTooltipShortHelp
   */
  void SetShortHelp(const CATUnicodeString& i_sShortHelp);
  /**
   * @return long help explaining the command of the action.
   */
  CATUnicodeString GetLongHelp() const;
  /**
   * Associates a long help to the command of the action. Default is empty 
   * string.
   *
   * @param i_sLongHelp long help explaining what the action does (eg. 
   * <tt>"Extruding a 2D mesh transforms the surface into a closed shape with a 
   * flat bottom."</tt>).
   *
   * @see CATVidCtl#SetTooltipLongHelp
   */
  void SetLongHelp(const CATUnicodeString& i_sLongHelp);
  /**
   * @return an image associated to the action.
   */
  CATUnicodeString GetImage() const;
  /**
   * File name of an image that may be used to illustrate the help of the 
   * command. Default is empty string.
   *
   * @param i_sImageFile the name of the file where the illustrative image can
   * be found (eg. <tt>"extrude_example.png"</tt>).
   *
   * @see CATVidCtl#SetTooltipImage
   */
  void SetImage(const CATUnicodeString& i_sImageFile);
  /**
   * Pixel image that may be used to illustrate the help of the 
   * command. Default is NULL.
   *
   * @return a CATPixelImage that will be displayed in the tooltip.
   *
   */
	CATPixelImage * GetPixelImage() const;
  /**
   * Pixel image of an image that may be used to illustrate the help of the 
   * command. Default is NULL.
   *
   * @param i_pPixelImage a CATPixelImage that will be displayed in the tooltip.
   *
   */
	void SetPixelImage(CATPixelImage* i_pPixelImage);  
  /**
   * @return an image for the short help associated to the action.
   */
  CATUnicodeString GetShortHelpImage() const;
  /**
   * File name of an image that may be used to illustrate the short help of the 
   * command. Default is empty string.
   *
   * @param i_sImageFile the name of the file where the illustrative image can
   * be found (eg. <tt>"extrude_example.png"</tt>).
   *
   * @see CATVidCtl#SetTooltipShortHelpImage
   */
  void SetShortHelpImage(const CATUnicodeString& i_sImageFile);
  /**
   * @return a pixel image for the short help associated to the action.
   */
	CATPixelImage* GetShortHelpPixelImage() const;
  /**  
   * Pixel image that may be used to illustrate the short help of the 
   * command. Default is NULL.
   *
   * @return a CATPixelImage that will be displayed in the tooltip.
   *   
   * @see CATVidCtl#GetTooltipShortHelpImage
   * @see CATVidCtl#SetTooltipTemplateName
   */
	void SetShortHelpPixelImage(CATPixelImage* i_pPixelImage);
  /**
   * @return an image for the long help associated to the action.
   */
  CATUnicodeString GetLongHelpImage() const;
  /**
   * File name of an image that may be used to illustrate the long help of the 
   * command. Default is empty string.
   *
   * @param i_sImageFile the name of the file where the illustrative image can
   * be found (eg. <tt>"extrude_example.png"</tt>).
   *
   * @see CATVidCtl#SetLongHelpTooltipImage
   */
  void SetLongHelpImage(const CATUnicodeString& i_sImageFile);
  /**
   * @return an image for the long help associated to the action.
   */
	CATPixelImage* GetLongHelpPixelImage() const;
  /**
   * Pixel image that may be used to illustrate the long help of the 
   * command. Default is NULL.
   *
   * @return a CATPixelImage that will be displayed in the tooltip long help.
   *
   * @see CATVidCtl#SetTooltipLongHelpPixelImage
   * @see CATVidCtl#SetTooltipTemplateName
   */  
	void SetLongHelpPixelImage(CATPixelImage* i_pPixelImage);
  /**
   * @return the dimension of the image which illustrates the command.
   */
  CATMathPoint2Df GetImageDimension() const;
  /**
   * Attributes a dimension to the image which illustrates the command.
   * Default is (64, 64).
   *
   * @param i_imageDimension dimension of the illustrative image.
   *
   * @see #SetImage
   * @see CATVidCtl#SetTooltipImageDimension
   */
  void SetImageDimension(const CATMathPoint2Df& i_imageDimension);
  /**
   * @return the dimension of the short help image which illustrates the command.
   */
  CATMathPoint2Df GetShortHelpImageDimension() const;
  /**
   * Attributes a dimension to the short help image which illustrates the command.
   * Default is (64, 64).
   *
   * @param i_imageDimension dimension of the illustrative image.
   *
   * @see #SetShortHelpImage
   * @see CATVidCtl#SetTooltipShortHelpImageDimension
   */
  void SetShortHelpImageDimension(const CATMathPoint2Df& i_imageDimension);
  /**
   * @return the dimension of the long help image which illustrates the command.
   */
  CATMathPoint2Df GetLongHelpImageDimension() const;
  /**
   * Attributes a dimension to the long help image which illustrates the command.
   * Default is (64, 64).
   *
   * @param i_imageDimension dimension of the illustrative image.
   *
   * @see #SetLongHelpImage
   * @see CATVidCtl#SetTooltipLongHelpImageDimension
   */
  void SetLongHelpImageDimension(const CATMathPoint2Df& i_imageDimension);
  /**
   * @return an explicative title about what the command of the action does.
   */
  CATUnicodeString GetTitle() const;
  /**
   * Associates a title for the help of the command of this action.
   *
   * @param i_sTitle title to associate to the command of the action 
   * (eg. <tt>"Extrude (2D to 3D)"</tt>).
   *
   * @see CATVidCtl#SetTooltipTitle
   */
  void SetTitle(const CATUnicodeString& i_sTitle);
  /**
   * @return the URL of the hyperlink associated to the help of the action.
   */
  CATVidURL GetHyperlinkURL() const;
  /**
   * Associates an hyperlink URL to the help of the action.
   *
   * @param i_URL a well-formed URL (eg. the URL pointing to the official 
   * documentation).
   *
   * @see #SetHyperlinkLabel
   * @see CATVidCtl#SetTooltipHyperlinkLabel
   */
  void SetHyperlinkURL(const CATVidURL& i_URL);
  /**
   * @return a label for the hyperlink associated to the help of the action.
   */
  CATUnicodeString GetHyperlinkLabel() const;
  /**
   * Associates a label to the hyperlink (@ref #SetHyperlinkURL).
   *
   * @param i_sHyperlinkLabel label for the hyperlink (eg. 
   * <tt>"www.3ds.com"</tt>).
   *
   * @see #SetHyperlinkURL
   * @see CATVidCtl#SetTooltipHyperlinkURL
   */
  void SetHyperlinkLabel(const CATUnicodeString& i_sHyperlinkLabel);
  /** 
   * Actions whose enable state is @c FALSE are disabled. An action is disabled 
   * either because its @c EnableFlag is @c FALSE , or because the 
   * @c EnableFlag of its group is @c FALSE. Disabled actions cannot be 
   * interacted with in the menu view.
   *
   * @return the enable state of the action. 
   *
   * @see #SetEnableFlag
   */ 
  CATBoolean GetEnableState() const;
  /**
   * @return the enable flag of the action.
   *
   * @see #GetEnableFlag
   */
  CATBoolean GetEnableFlag() const;
  /**
   * Default value is 
   *
   * @param i_bEnableFlag the new @c EnableFlag of the action.
   *
   * @see #GetEnableFlag
   */
  void SetEnableFlag(CATBoolean i_bEnableFlag);

protected:
  /** Default constructor. */
  CATVidAbstractAction();
  /** Destructor. */
  virtual ~CATVidAbstractAction();
  /**
   * Puts the action in a group.
   *
   * @param i_pGroup the group to which the action will be added.
   */
  virtual void SetGroup(CATVidAbstractActionGroup * i_pGroup) = 0;
  /**
   * @return the group in which the action has been added, if any.
   */
  CATVidAbstractActionGroup * GetGroup() const;

protected:
  /**
   * Weak reference on the action group of this action, if any.
   */
  CATBaseUnknown_WR _wrGroup;

private:
  /** Copy constructor. */
  CATVidAbstractAction(CATVidAbstractAction &);
  /** Copy operator. */
  CATVidAbstractAction& operator=(CATVidAbstractAction& original);

private:
  /**
   * See @ref #SetIcon .
   */
  CATUnicodeString _sIcon;
  /**
   * See @ref #SetText .
   */
  CATUnicodeString _sText;
  /**
   * See @ref #SetName .
   */
  CATString _sName;
  /**
   * See @ref #SetImage .
   */
  CATUnicodeString _sImage;
  /**
   * See @ref #SetShortHelpImage .
   */
  CATUnicodeString _sShortHelpImage;
  /**
   * See @ref #SetLongHelpImage .
   */
  CATUnicodeString _sLongHelpImage;
  /**
   * See @ref #SetPixelImage .
   */
	CATPixelImage * _pPixelImage;
	/**
	* See @ref #SetShortHelpPixelImage .
	*/
	CATPixelImage * _pShortHelpPixelImage;
	/**
	* See @ref #SetLongHelpPixelImage .
	*/
	CATPixelImage * _pLongHelpPixelImage;
  /**
   * See @ref #SetImageDimension .
   */
  CATMathPoint2Df _fdimImage;
  /**
   * See @ref #SetShortHelpImageDimension .
   */
  CATMathPoint2Df _fdimShortHelpImage;
  /**
   * See @ref #SetLongHelpImageDimension .
   */
  CATMathPoint2Df _fdimLongHelpImage;
  /**
   * See @ref #SetTitle .
   */
  CATUnicodeString _sTitle;
  /**
   * See @ref #SetShortHelp .
   */
  CATUnicodeString _sShortHelp;
  /**
   * See @ref #SetLongHelp .
   */
  CATUnicodeString _sLongHelp;
  /**
   * See @ref #SetHyperlinkURL .
   */
  CATVidURL * _pHyperlinkURL;
  /**
   * See @ref #SetHyperlinkLabel .
   */
  CATUnicodeString _sHyperlinkLabel;
  /**
   * See @ref #SetEnableFlag .
   */
  CATBoolean _bEnableFlag;
  /** 
   * See @ref #SetCheckableFlag .
   */
  CATBoolean _bCheckableFlag;
  /**
   * Check box or radio button is selected.
   */
  CATBoolean _bCheckState;
  /**
   * See @ref #SetActionMenu .
   */
  CATVidMdlSubMenu * _pMenu;
};

//-----------------------------------------------------------------------------
#endif
