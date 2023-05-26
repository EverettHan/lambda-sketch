// COPYRIGHT Dassault Systemes 2005
#ifndef CATIListColorModel_H
#define CATIListColorModel_H

#include <CATViewItf.h>
#include <CATIListViewModel.h>
#include <CATUnicodeString.h>
#include <CATLISTV_CATBaseUnknown.h>
typedef  CATLISTV(CATBaseUnknown_var)  CATListOfCATBaseUnknown_var;

typedef CATULONG64 CATDlgTableStyle;

extern ExportedByCATViewItf IID IID_CATIListColorModel;

/**
 * CATIListColorModel. Interface to modify the model in a list view.
 **/
class ExportedByCATViewItf CATIListColorModel: public CATIListViewModel
{
    CATDeclareInterface;

public:

  /** @nodoc
  * Retrieves the cell border color for all cells of given style.
  *
  * <br><b>Role</b>: Retrieves the cell border color for all cells of given style.
  *
  * input : Default color value
  * ouput : New color value. Leave value unchanged to keep default colors
  *
  * @param iStyle [in]
  *   The searched cell style. The possible values are:
  *   <ul>
  *       <li>CATDlgTableLeftJustify   | </li>
  *       <li>CATDlgTableRightJustify  |- Horizontal cell alignement</li>
  *       <li>CATDlgTableCenterJustify | </li>
  *
  *       <li>CATDlgTableTopJustify    | </li>
  *       <li>CATDlgTableBottomJustify |- Vertical cell alignement</li>
  *       <li>CATDlgTableMiddleJustify | </li>
  *
  *       <li>CATDlgTableCellOK      | OK cell style</li>
  *       <li>CATDlgTableCellNormal  | Normal cell style</li>
  *       <li>CATDlgTableCellWarning | Warning cell style</li>
  *       <li>CATDlgTableCellError   | Error cell style</li>
  *       <li>CATDlgTableCellCustom  | Custom cell style</li>
  *   </ul>
  * @param ioRed [inout]
  *   It defines the red component of the border color.The value ranges from 0 to 255. 
  * @param ioGreen [inout]
  *   It defines the green component of the border color.The value ranges from 0 to 255. 
  * @param ioBlue [inout]
  *   It defines the blue component of the border color.The value ranges from 0 to 255. 
  * @param ioAlpha [inout]
  *   Not supported.
  */
	virtual HRESULT GetBorderColor(CATDlgTableStyle iStyle, unsigned int & ioRed, 
                                 unsigned int & ioGreen, unsigned int & ioBlue, 
                                 unsigned int & ioAlpha) = 0;

  /**
  * Retrieves the cell background color for all cells of given style.
  * 
  * <br><b>Role</b>: Retrieves the cell background color for all cells of given style.
  *
  * input : Default color value
  * ouput : new color value. Leave value unchanged to keep default colors
  *
  * @param iStyle [in]
  *   The searched cell style. The possible values are:
  *   <ul>
  *       <li>CATDlgTableLeftJustify   | </li>
  *       <li>CATDlgTableRightJustify  |- Horizontal cell alignement</li>
  *       <li>CATDlgTableCenterJustify | </li>
  *
  *       <li>CATDlgTableTopJustify    | </li>
  *       <li>CATDlgTableBottomJustify |- Vertical cell alignement</li>
  *       <li>CATDlgTableMiddleJustify | </li>
  *
  *       <li>CATDlgTableCellOK      | OK cell style</li>
  *       <li>CATDlgTableCellNormal  | Normal cell style</li>
  *       <li>CATDlgTableCellWarning | Warning cell style</li>
  *       <li>CATDlgTableCellError   | Error cell style</li>
  *       <li>CATDlgTableCellCustom  | Custom cell style</li>
  *   </ul>
  * @param ioRed [inout]
  *   It defines the red component of the text color.The value ranges from 0 to 255.
  * @param ioGreen [inout]
  *   It defines the green component of the text color.The value ranges from 0 to 255.
  * @param ioBlue [inout]
  *   It defines the blue component of the text color.The value ranges from 0 to 255.
  * @param ioAlpha [inout]
  *   Not supported.
  */
	virtual HRESULT GetTextColor(CATDlgTableStyle iStyle, unsigned int & ioRed, 
                               unsigned int & ioGreen, unsigned int & ioBlue, 
                               unsigned int & ioAlpha) = 0;

	/** 
	* Retrieves the cell text color for the cell defined by iLine, iColumn.
	*
	* <br><b>Role</b>: Retrieves the cell text color for the cell defined by iLine, iColumn.
  * This method is not called if the cells does not have the style CustomColor
	*
  * input : Default color value
  * ouput : new color value. Leave value unchanged to keep default colors
  *
	* @param iLine [in]
	*   The line containing the cell. This data must be serializable.
	* @param iColumn [in]
	*   ID of the column containing the cell.
	* @param ioRed [inout]
	*   It defines the red component of the text color.The value ranges from 0 to 255. 
	* @param ioGreen [inout]
	*   It defines the green component of the text color.The value ranges from 0 to 255.
	* @param ioBlue [inout]
	*   It defines the blue component of the text color.The value ranges from 0 to 255.
	* @param ioAlpha [inout]
	*   Not supported
	*
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise...
	*
	*/
	virtual HRESULT GetTextColor(CATBaseUnknown_var iLine, const CATString &iColumn, 
                               unsigned int & ioRed, unsigned int & ioGreen, 
                               unsigned int & ioBlue, unsigned int & ioAlpha) = 0;

  /**
  * Retrieves the cell background color for all cells of given style
  *
  * <br><b>Role</b>: 
  * Style possible value are : OK, Normal, Warning, Error, Highlight, SubHighlight
  * input : Default color value
  * ouput : new color value. Leave value unchanged to keep default colors
  *
  * @param iStyle [in]
  *   The searched cell style. The possible values are:
  *   <ul>
  *       <li>CATDlgTableLeftJustify   | </li>
  *       <li>CATDlgTableRightJustify  |- Horizontal cell alignement</li>
  *       <li>CATDlgTableCenterJustify | </li>
  *
  *       <li>CATDlgTableTopJustify    | </li>
  *       <li>CATDlgTableBottomJustify |- Vertical cell alignement</li>
  *       <li>CATDlgTableMiddleJustify | </li>
  *
  *       <li>CATDlgTableCellOK      | OK cell style</li>
  *       <li>CATDlgTableCellNormal  | Normal cell style</li>
  *       <li>CATDlgTableCellWarning | Warning cell style</li>
  *       <li>CATDlgTableCellError   | Error cell style</li>
  *       <li>CATDlgTableCellCustom  | Custom cell style</li>
  *   </ul>
  * @param ioRed [inout]
  *   It defines the red component of the background color.The value ranges from 0 to 255.
  * @param ioGreen [inout]
  *   It defines the green component of the background color.The value ranges from 0 to 255.
  * @param ioBlue [inout]
  *   It defines the blue component of the background color.The value ranges from 0 to 255.
  * @param ioAlpha [inout]
  *   Not supported.
  */
	virtual HRESULT GetBackgroundColor(CATDlgTableStyle iStyle, unsigned int & ioRed, 
                                     unsigned int & ioGreen, unsigned int & ioBlue, 
                                     unsigned int & ioAlpha) = 0;

  /** 
  * Retrieves the cell background color for the cell defined by iLine, iColumn.
  *
  * <br><b>Role</b>: This method is not called if the cells does not have the style CustomColor.
  *
  * input : Default color value
  * ouput : New color value. Leave value unchanged to keep default colors
  *
  * @param iLine [in]
  *   The line containing the cell.
  * @param iColumnID [in]
  *   ID of the column containing the cell.
  * @param ioRed [inout]
  *   It defines the red component of the background color.The value ranges from 0 to 255.
  * @param ioGreen [inout]
  *   It defines the green component of the background color.The value ranges from 0 to 255.
  * @param ioBlue [inout]
  *   It defines the blue component of the background color.The value ranges from 0 to 255.
  * @param ioAlpha [inout]
  *   Not supported.
  */
	virtual HRESULT GetBackgroundColor(CATBaseUnknown_var iLine , const CATString &iColumnID, 
                                     unsigned int & ioRed, unsigned int & ioGreen, 
                                     unsigned int & ioBlue, unsigned int & ioAlpha) = 0;
};

CATDeclareHandler( CATIListColorModel, CATIListViewModel );

#endif
