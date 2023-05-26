// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATICkeSheetInternal.h
// Define the CATICkeSheetInternal interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Oct 2009  Creation: Code generated by the CAA wizard  ufm
//===================================================================
#ifndef CATICkeSheetInternal_H
#define CATICkeSheetInternal_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATICkeSheetInternal;
#else
extern "C" const IID IID_CATICkeSheetInternal;
#endif

//------------------------------------------------------------------

/**
* Interface representing xxx.
*
* <br><b>Role</b>: Components that implement
* CATICkeSheetInternal are ...
* <p>
* Do not use the CATICkeSheetInternal interface for such and such

*
* @example
*  // example is optional
*  CATICkeSheetInternal* currentDisplay = NULL;
*  rc = window-&gt;QueryInterface(IID_CATICkeSheetInternal,
*                                     (void**) &amp;currentDisplay);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByKnowledgeItf CATICkeSheetInternal : public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* Exports all the sheet content to a PLM Document (containing text or excel file).
	* @param iospRepDoc
	* The PLM Document won't be created.
	* The link is not kept with the PLM Document (if you go on modifying the model sheet
	* after exporting its content to PLM Document, the PLM Document content will not be up to
	* date with the model sheet content). The PLM Document is just a visible image of
	* the sheet content at a given instant.
	* Notice that this method will fail if you give an existing PLM Document
	* without setting the second argument to 1.
	* @param iReplaceRepresenationReferenceIfExist
	* If you give a PLM Document that corresponds to an existing PLM Document, you have to set it to 1
	* to force the PLM Document replacement (else this method will failed).By default, this
	* argument is set to 0 in order to keep the existing PLM Document.
	* @return
	* E_FAIL if the PLM Document filling failed, and S_OK else.
	*/
	virtual HRESULT ExportContentToRepRefPLMDoc(CATBaseUnknown_var& iospRepDoc, int iReplaceRepresentationReferenceIfExist = 0) = 0;

	/**
	* Sets the PLM Document of the sheet.
	* The format of the file is tabulated.
	* @param iRepDoc The new PLM Document
	* @return E_FAIL if the method fails or
	*		  S_OK if the method succeeds or
	*       E_INVALIDARG if PLM Document isn't correct
	*
	*/
	virtual HRESULT SetSourceRepRefPLMDoc(const CATBaseUnknown_var& iRepDoc) = 0;

	/**
	* Returns the PLM Document.
	* @param oRepDoc The PLM Document
	* @return E_FAIL if the method fails or
	*		    S_OK if the method succeeds
	*
	*/
	virtual HRESULT GetSourceRepRefPLMDoc(CATBaseUnknown_var& oRepDoc) = 0;


	// only active for Excel.
	// worsen performance when reading file because it implies additional automation calls for every cell.
	virtual void ActivateHighPrecisionForExcelRead() = 0;

	/**
	* <br><b> Retrieves and returns the work sheet name. </b>:
	* This method is only for Excel sheets and it involves a quite performance overhead.
    * Better performance can be achieved by calling it after call to set first cell and before 
    * call to set last cell. Please make sure you call this method wisely.
    *
	* @return
	* <dl>
	* <dt><code>S_OK : Successfully retrieved and returned the Excel sheet name. </code> <dd>
	* <dt><code>E_FAIL : Failed to retrieve the Excel sheet name.</code> <dd>
	* <dt><code>E_NOTIMPL : Sheet is not Excel sheet.</code> <dd>
	* @param osSheetName : Work sheet name.
	* </dl>
	*/
	virtual HRESULT GetSheetName(CATUnicodeString& osSheetName) = 0;

	/**
	* <br><b> Sets the work sheet name. </b>:
    * This method is only for Excel sheets and it involves a quite performance overhead.
    * Better performance can be achieved by calling it after call to set first cell and before
    * call to set last cell. Please make sure you call this method wisely.
	* @param isSheetName : New name for Work sheet.
	*
	* @return
	* <dl>
	* <dt><code>S_OK : Successfully set the Excel sheet name. </code> <dd>
	* <dt><code>E_FAIL : Failed to set the Excel sheet name.</code> <dd>
	* <dt><code>E_NOTIMPL : Sheet is not Excel sheet.</code> <dd>
	* </dl>
	*/
	virtual HRESULT SetSheetName(const CATUnicodeString& isSheetName) = 0;

    /**
    *
    * <br><b> Retrieves and returns the total number of work sheets including empty sheets. </b>:
    * This method is only for Excel sheets and it involves a quite performance overhead.
    * Better performance can be achieved by calling it after call to set first cell and before
    * call to set last cell. Please make sure you call this method wisely.
    * @param &oiSheetCount : [output] The total number of work sheets in the Excel workbook.
    *
    * @return
    * <dl>
    * <dt><code>S_OK : Successfully retrieved and returned the total number of work sheets including empty sheets. </code> <dd>
    * <dt><code>E_FAIL : Failed to retrieve the total number of work sheets.</code> <dd>
    * <dt><code>E_NOTIMPL : Sheet is not Excel sheet.</code> <dd>
    * </dl>
    */
    virtual HRESULT GetSheetCount(int& oiSheetCount) = 0;

    /**
    *
    * <br><b> Retrieves and returns all work sheet names in the order as they are in the Excel workbook including empty sheets. </b>:
    * This method is only for Excel sheets and it involves a quite performance overhead.
    * Better performance can be achieved by calling it after call to set first cell and before
    * call to set last cell. Please make sure you call this method wisely.
    * @param olSheetNames : [output] List of all work sheet names in a Excel workbook.
    *
    * @return
    * <dl>
    * <dt><code>S_OK : Successfully retrieved and returned all work sheet names in a Excel workbook including empty sheets. </code> <dd>
    * <dt><code>E_FAIL : Failed to retrieve all work sheet names in a Excel workbook. </code> <dd>
    * <dt><code>E_NOTIMPL : Sheet is not Excel sheet.</code> <dd>
    * </dl>
    */
    virtual HRESULT GetAllSheetNames(CATListOfCATUnicodeString& olSheetNames) = 0;

	/**
	* Sets excel library preference for this excel sheet.
	* @param iPreference
	* 0 : Preference not set.
	* 1 : Microsoft Excel8 Lib
	* 2 : XLNT Lib.
	* @return
	* <dl>
	* <dt><code>S_OK : Successfully set the preference. </code> <dd>
	* <dt><code>E_FAIL : Failed to set the preference. </code> <dd>
	* <dt><code>E_NOTIMPL : Sheet is not Excel sheet.</code> <dd>
	* </dl>
	*/
	virtual HRESULT SetExcelLibraryPreference(const int &iPreference) = 0;

	/**
	* Get excel library preference for this excel sheet.
	* @param &oiSheetCount : [output] excel library preference
	* 0 : Preference not set.
	* 1 : Microsoft Excel8 Lib
	* 2 : XLNT Lib.
	* @return
	* <dl>
	* <dt><code>S_OK : Successfully retrieved the preference. </code> <dd>
	* <dt><code>E_FAIL : Failed to retrieve the preference. </code> <dd>
	* <dt><code>E_NOTIMPL : Sheet is not Excel sheet.</code> <dd>
	* </dl>
	*/
	virtual HRESULT GetExcelLibraryPreference(int &iPreference) = 0;

};

//------------------------------------------------------------------
CATDeclareHandler(CATICkeSheetInternal, CATBaseUnknown);

#endif
