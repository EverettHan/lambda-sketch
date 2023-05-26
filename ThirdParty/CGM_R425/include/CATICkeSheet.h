// COPYRIGHT DASSAULT SYSTEMES  1998
//=============================================================================
//
// CATICkeSheet.h:
//
//=============================================================================
// Usage Notes:
//
// Header of interface of sheet object.
//
// 
//
//
//=============================================================================
// 08/06/98   Creation                                   T. Videcoq
//=============================================================================

/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */

/*  CAA2Reviewed by FRH */

/**
 * This interface is an encapsulation of an array of arrays (a sheet) of strings contained in a file.
 *
 * This file can be an excel sheet, or a tabulated text file.The format of the text file
 * has to be :
 * <table>
 * <tr><td>string<sub>1,1</sub></td><td>TAB</td><td>string<sub>1,2</sub></td><td>...</td></tr>
 * <tr><td colspan="3">(n-2 lines)</td></tr>
 * <tr><td>string<sub>n,1</sub></td><td>TAB</td><td>string<sub>n,2</sub></td><td>...</td></tr>
 * </table><br>
 * Empty strings are allowed, but not in the first row because the number of columns is computed using the first row.
 * For design table use, the file is parsed until its end or until the first empty row is found.
 * If you use sheets of format Excel , be careful not to leave Excel process resident in memory (take care of SetCell arguments).
 * <br>
 * A sheet feature has a link to a file. This link has a direction, and this direction is impacting the way links between files (CATIA model and external file)
 * are shown in Impact Graph in LCA.
 * @see CATIDesignTable, CATICkeRelationFactory
*/

#ifndef CATICkeSheet_H
#define CATICkeSheet_H

#include "KnowledgeItf.h"
#include "CATICkeRelationForwards.h"
#include "CATEventSubscriberTypedefs.h"

class CATCommand;


#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeSheet;
#else
extern "C" const IID IID_CATICkeSheet;
#endif
class CATIPsiRepresentationReference_var;


class ExportedByKnowledgeItf CATICkeSheet : public CATBaseUnknown
{
	CATDeclareInterface;

public:
    /**
	* Gets the number of columns in the sheet.
	* @return the number of columns
	*/
	virtual int Columns() const = 0;


	/**
	* Gets the number of rows in the sheet. It includes the columns titles row.
	* @return the number of rows 
	*/
	virtual int Rows() const = 0;

	/**
	* Gets the row r of the sheet.
	* @return  const CATListOfCATUnicodeString* : this list mustn't be destroyed and doesn't change until this method is called again.
	* If r > Rows() returns NULL
	* @param r
	* the wanted row. 1-based Index 
	*/
	virtual const CATListOfCATUnicodeString* Row(const int r) = 0;

	/**
	* Gets the column c of the sheet.
	* @return  const CATListOfCATUnicodeString* : this list must not be destroyed and doesn't change until this method is called again.
	* If c > Columns() returns NULL
	* @param c
	* the wanted column. 1-based Index 
	*/
	virtual const CATListOfCATUnicodeString* Column(const int c) = 0;

	/**
	* Gets the cell r,c.
	* @return the content of the cell r,c. An empty cell if coordinates are wrong
	* @param r
	* the row of the wanted cell (1-based)
	* @param c
	* the column of the wanted cell (1-based)
	*/
	virtual const CATUnicodeString& Cell(const int r, const int c) const = 0;

	/**
	* Sets the content of the cell (r,c) in the sheet and saves the sheet if lastCell = True.
	* WARNING : for text files, this method has strong performance problems. Use CATICkeSheet::AddRow instead of SetCell to fix them
	* @param r (1-based index)
	* row parameter
	* @param c (1-based index)
	* column parameter
	* @param s
	* cell content 
	* @param firstCell
	* this flag has to be set to True if the SetCell function is called for the first time since UpdateLocalCopy method was called
	* @param lastCell
	* this flag  has to be set to True if the SetCell function is called for the last time until UpdateLocalCopy method is called
	* @return  CATCke::True if the function succeded, CATCke::False else<br>
	*/
	virtual CATCke::Boolean SetCell(const int r, const int c, const CATUnicodeString& s, CATCke::Boolean firstCell=1, CATCke::Boolean lastCell=1) = 0;

	/**
	* Gets the index of the column where the sheet takes the value of columnContent in the row r.
	* @return the 1-based index of the searched column, 0 if not found
	* @param r
	* the row where the search is done 
	* @param columnContent
	* the string searched
	*/
	virtual int WhichColumn(const int r, const CATUnicodeString& columnContent) = 0;

	/**
	* Gets the index of the row where the sheet takes the value of rowContent in the column c.
	* @return the 1-based index of the searched row, 0 if not found
	* @param c
	* the column where the search is done 
	* @param rowContent
	* the string searched
	*/
	virtual int WhichRow(const int c, const CATUnicodeString& rowContent) = 0;
	
	/**
	* Performs analysis of the sheet. 
	* (parses the content of the sheet, updates the number of columns and rows)
	* @param forceWidth
	* this parameter mustn't be used in most cases : it forces the width (nb of columns)
	* looked for (used in CATCkeImportServices to ensure that the columns of formulas and comments will be read).
	* If forceWidth != 0, the nb of column will be >= forceWidth
	* @param forceHeight
	* the counterpart of forceWidth for the height of the sheet
	* @return  CATCke::False if the parsing fails (empty sheet, no sheet, ...) 
	*/
	virtual CATCke::Boolean UpdateLocalCopy(const int forceWidth = 0, const int forceHeight = 0) = 0;

	/**
	* Indicates if source file data has to be copied into the CATIA model.
	* @param mode
	* : if True, performs a persistent copy of the content of the sheet
	*/ 
	virtual void SetCopyMode(CATCke::Boolean mode) = 0;

	/**
	* Returns the value of the CopyMode_ attribute.
	*/
	virtual CATCke::Boolean CopyMode() const = 0;

	/**
	* Creates a file for future sheet. If the path contains the .xls extension,
	* an excel file is created. Else, a text file is created
	* @return  CATCke::False if the creation of the file fails
	* @param path
	* The path of the file to create
	* @param iCreateLink
	* A link to the file is created on the feature
	*/	
	virtual CATCke::Boolean CreateSourceFile(const CATUnicodeString &path, const int iCreateLink = 1) = 0;

	/**
	* Does the same work as UpdateLocalCopy.
	* But with data taken from the model (if CopyMode_ is equal to True). 
	* @return False if no data was put in the model (CopyMode_ = False)
	*/
	virtual CATCke::Boolean UpdateLocalCopyFromSpec() = 0;

	/**
	* Sets the path of the file containing the data. The format of the file is tabulated.
	* @param path 
	* The path to be set
	*/
	virtual void SetSourceFilePath(const CATUnicodeString &path) = 0;

	/**
	* Returns the path and name of the file from which data are imported.
	*/
	virtual CATUnicodeString GetSourceFilePath() = 0;

	/**
	* Synchronizes if needed the link between the sheet and the PLM Representation encapsulating the source file.
	* @return
	* TRUE is the the link had to be synchronized, FALSE otherwise
	*/
	virtual CATBoolean SynchronizeLinkToRep() = 0;

	enum SourceStatus
	{
		ReadOnly,
		NotFound,
		ReadWriteOk,
		Empty,
		NotReadable
	};

	/**
	* This method is used to know the status of the source file.
	* @return CATICkeSheet::NotFound if the file isn't found, CATICkeSheet::ReadOnly 
	* if the file is read-only, CATICkeSheet::ReadWriteOk if the file can be written to, 
	* CATICkeSheet::Empty if the file path is empty
	*/
	virtual CATICkeSheet::SourceStatus GetSourceStatus() = 0;

	/**
	* This method is used to change the source file. The type of
	* the file must be the same as the old one...(excel <-> excel, text file <-> text file).
	* This method only changes the source file : it doesn't update the content of the sheet (no call to UpdateLocalCopy)
	* @return False if the method fails
	* @param path
	* the path of the new source file
	*/
	virtual CATCke::Boolean ChangeSourceFile(const CATUnicodeString &path) = 0;

	enum SourceFormat
	{
		Text,
		Excel,
		NoSource
	};

	/**
	* This method allows to know the format of the linked file.
	* @return CATICkeSheet::Text if text file, CATICkeSheet::Excel if Excel file 
	* If no file is associated, or if the link is lost,
	* returns CATICkeSheet::NoSource
	*/
	virtual CATICkeSheet::SourceFormat GetSourceFormat() = 0;

	
	/**
	* Gets the associated command that sends the Ole doc. Close and modify notification
	* If a client wants to receive this notification, he has to write : <br>
	* AddCallback(sheet->GetCallbackCommand(), sheet->GetOleModifyAndCloseNotification(), (CATSubscriberMethod) &CATClientClass::OnSheetModification))
	* @return the command
	*/
	virtual CATCommand * GetCallbackCommand() = 0;

    /**
    * Do not use.
	* @return the event
    */
	virtual CATCallbackEvent GetFileDateChangedNotification() = 0;

	/**
	* Returns the orientation of the sheet.
	* @return 1 for vertical columns and 0 for horizontal ones.
	*/
	virtual int GetOrientation() const = 0;

	/**
	* Sets the orientation of the sheet.
	* @param vertical equal to 1 for vertical columns and 0 for horizontal ones.
	*/
	virtual void SetOrientation(const int vertical) = 0;

	/**
	* Exports all the sheet content to a Text or an Excel file.
	* @param iFilePath
	* The path of the file that will be created. If it contains :
	* - ".xls", an excel file will be created
	* else, a text file will be created.
	* The link is not kept with the file (if you go on modifying the model sheet
	* after exporting its content to a file, the file content will not be up to
	* date with the model sheet content). The file is just a visible image of
	* the sheet content at a given instant.
	* Notice that this method will fail if you give the path of an existing file
	* without setting the 2d argument to 1 or if the existing file access is not
	* Read/Write.
	* @param iReplaceFileIfExist
	* If you give a path that corresponds to an existing file, you have to set it to 1
	* to force the file replacement (else this method will failed).By default, this
	* argument is set to 0 in order to keep the existing file.
	* @return
	* E_FAIL if the file creation or the file filling failed, and S_OK else.
	*/
	virtual HRESULT ExportContentToFile(const CATUnicodeString& iFilePath, int iReplaceFileIfExist) = 0;

	/**
	* Exports all the sheet content to a representation reference (containing text or excel file).
	* @param iospRepRef The representation reference won't be created. 
	* The link is not kept with the representation reference (if you go on modifying the model sheet
	* after exporting its content to representation reference, the representation reference content will not be up to
	* date with the model sheet content). The representation reference is just a visible image of
	* the sheet content at a given instant.
	* Notice that this method will fail if you give an existing representation reference
	* without setting the second argument to 1.
	* @param iReplaceRepresentationReferenceIfExist
	* If you give a representation reference that corresponds to an existing representation reference, you have to set it to 1
	* to force the representation reference replacement (else this method will failed).By default, this
	* argument is set to 0 in order to keep the existing representation reference.
	* @return E_FAIL if the representation reference filling failed, and S_OK else.
	*/
	virtual HRESULT ExportContentToRepRef(CATIPsiRepresentationReference_var& iospRepRef, int iReplaceRepresentationReferenceIfExist=0) = 0;
	
	
	/**
	* Launches the sheet editor.
	* Warning, the behaviour of this method is different for text files or Excel  files : <br>
	* its call is blocking for text files and not for other ones.<br>For Excel  files, to be warned after Excel closure in case of a sheet modification,
	* you have to put a callback on CATICkeOleSheet::GetOleModifyAndCloseNotification event.
	* @return
	* S_OK if method succeeds, E_FAIL if method fails : for example, calling it on UNIX for an Excel based design table, or calling it on NT with Excel not installed
	*/
	virtual HRESULT LaunchEditor() = 0;


	/** 
	* Changes the quality of source file link attribute (sp_in or sp_out).
	*
	* @param iIn [in]
	*   1 for sp_In, 0 for sp_Out (CATISpecDeclarations not available here)
	*/
	virtual void SetSourceLinkDirection(int iIn) = 0;

	/** 
	* Returns the quality of source file link attribute (sp_in or sp_out).
	*
	* @return
	*   1 for sp_In, 0 for sp_Out (CATISpecDeclarations not available here)
	*/
	virtual int GetSourceLinkDirection() = 0;

	/** 
	* Sets the representation reference of the sheet. 
	* The format of the file is tabulated.
	* @param iRepresentation The new representation reference
	* @return E_FAIL if the method fails or 
	*		  S_OK if the method succeeds or 
	*         E_INVALIDARG if representation reference isn't correct
	*
	*/
	virtual HRESULT SetSourceRepRef(const CATIPsiRepresentationReference_var& iRepresentation) = 0;

	/**
	* Returns the representation reference.
	* @param oRepresentation The representation reference
	* @return E_FAIL if the method fails or 
	*		  S_OK if the method succeeds
	*
	*/
	virtual HRESULT GetSourceRepRef(CATIPsiRepresentationReference_var& oRepresentation) = 0;
	

	/**
	* Indicates if the representation reference has been modified.
	* @param oRepRefModified 1 if date stored in sheet feature is different from file one, 0 else.
	* @return E_FAIL if the method fails or 
	*		  S_OK if the method succeeds
	*/

	virtual CATBoolean IsSourceModified() = 0;


	/**
	* Erases the content of the sheet
	*/
	virtual void Clean() = 0;

	virtual CATBoolean IsEditorOpened() = 0;

};
CATDeclareHandler(CATICkeSheet,CATBaseUnknown);

#endif
