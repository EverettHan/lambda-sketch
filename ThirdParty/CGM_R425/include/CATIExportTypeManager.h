#ifndef CATIExportTypeManager_H
#define CATIExportTypeManager_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @level Private
* @usage U3
*/


#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"

#include "CosDataObject.h"
#include "CATStreamArea.h"

class CATDocument;

extern ExportedByAD0XXBAS IID IID_CATIExportTypeManager ;
/**
* @nodoc
* Interface to export a given format to an another one.
* <br><b>Usage</b> : to be able to save an existing document
* in a specific format, you have to :
* <br>1. add a new declaration in your dictionary: 
* <b>DocumentType_MyFormat  CATIExportTypeManager  libXXX</b>
* For example, if you want to save a CATProduct document to a "MyFormat"
* format, you would declare <b>CATProduct_MyFormat</b> in the dictionary.
* The new dictionary declaration will cause "MyFormat" to appear in the list of
* document types in the File/SaveAs panel.
* <br>2. implement the ExportData method of CATIExportTypeManager in order to
* specify the way the "MyFormat"-type document is to be saved.
*/
class ExportedByAD0XXBAS CATIExportTypeManager: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

	/**
        *@nodoc
	* Defines how to export data of a given document.
	* <br><b> Role: </b> Will be called at SaveAs .
	* @param iDoc
	*        The given document to be saved.
	* @param iPath
	*        The path describing the storage area where data is to be exported.
	* <br><b>Note:</b> this path is the one selected in 
	* File / SaveAs box dialog.
	*/
	virtual HRESULT ExportData ( CATDocument *iDoc, CATUnicodeString iPath ) = 0;

	/**
        *@nodoc
	* Defines how to export data from a given area.
	* @param iToExportPath
	*        Tje path of the document from which data is to be exported.
	* @param iExportedPath
	*        The path describing the storage area where data is to be exported.
	*/
	virtual HRESULT ExportData (CATUnicodeString iToExportPath , CATUnicodeString iExportedPath ) = 0;



};


CATDeclareHandler( CATIExportTypeManager, CATBaseUnknown );

#endif
