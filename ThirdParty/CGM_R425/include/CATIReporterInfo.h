/**
 * @level Protected 
 * @usage U3
 */
// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATIReporterInfo_H
#define CATIReporterInfo_H

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
#include "CATError.h"

class CATUnicodeString;

extern ExportedByAD0XXBAS IID IID_CATIReporterInfo ;

//------------------------------------------------------------------

/**
* Interface to retrieve the data of an error information.<BR>
* An error information is an object created via the interface CATIReporter. It is stacked in
* an internal list. Its data are a name and an error instance.<BR>
* See @href CATIReporter.
*/
class ExportedByAD0XXBAS CATIReporterInfo: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:		

	/** 
   * Gets the error associated with the error information.
   * <BR><B>Role</B>: This method sets the given oError to the error instance stored in the error information.
	 * @param oError [out]
	 *   The pointer on the error associated with the error information. Must be released.
	 * @return
	 *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
	 */
	virtual HRESULT GetError(CATError*& oError) = 0;
  /** 
   * Sets the given string to the string contained in the error information.
   * <BR><B>Role</B>: This method gets the string stored in the error information. It usually represents
   * the name of the object that has raised this error.
   * @param oStr [out]
   *   The given string.
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
   */
  virtual HRESULT GetAssociatedString(CATUnicodeString& oStr) = 0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler( CATIReporterInfo, CATBaseUnknown ) ;


#endif
