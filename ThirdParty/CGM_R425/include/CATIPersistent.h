/* -*-c++-*- */
#ifndef CATIPersistent_h
#define CATIPersistent_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @level Private
  * @usage U3
  */

#include "booleanDef.h"
#include "CATBaseUnknown.h"
#include "stringDef.h"
#include "sequence_octet.h"

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIPersistent ;

/**
* Interface to manage persistency of document's data.
* <b> Note: </b> if only these methods are needed, it is
* recommended to use CATDocumentServices services.
*
* @see CATDocumentServices
*/

class ExportedByAD0XXBAS CATIPersistent : public CATBaseUnknown
{
  CATDeclareInterface;

public:
   /** 
	*  Specifies if the document is modified or not.
   * <br>You should not use this method, but use the <tt>NeedToBeSaved</tt> method of the <tt>CATIxPDMItem</tt> interface instead.
	*/	
    virtual CATBoolean Dirty ()=0 ;

    /**
	 * Saves document's data in the same file.
	 */
	virtual void Save ()=0 ;

    /**
  	 * Saves document's data in another file.
 	 * @param iStoragePrintableName
	 *        given storage name to specify the file where to save.
	 * @param iBecameCurrent
	 *        not used.
	 */
    virtual void SaveAs (char* iStoragePrintableName, 
			 CATBoolean iBecameCurrent)=0 ;

	/** 
	* This method is not used.
	*/
    virtual void SaveAs_B (SEQUENCE(octet) storageName, 
			   CATBoolean becameCurrent)=0 ;

	/**
	* Loads a document.
	* <br><b> Note: </b> when a document is loaded, its data is not
	* initialized. Init method of CATInit has to be called after load.
	* @see CATInit
	* @param iStoragePrintableName
	*        storage name of the file to load.
    * @param iReadOnly
    *      FALSE: default value, the document will be read/write.
    *	     <br> TRUE if the document has to lock for writing.
	*/
    
    virtual void Load (char* iStoragePrintableName, 
		       CATBoolean iReadOnly)=0 ;

	/** 
	* This method is not used.
	*/
    virtual void Load_B (SEQUENCE(octet) storageName, 
			 CATBoolean readOnly)=0 ;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIPersistent, CATBaseUnknown ) ;


#endif



