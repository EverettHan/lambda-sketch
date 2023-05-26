 /**
  * @level Protected 
  * @usage U3
  */

// COPYRIGHT DASSAULT SYSTEMES 2005
#ifndef CATIReporter_H
#define CATIReporter_H

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
#include "CATLISTP_CATIReporterInfo.h"
#include "CATErrorDefs.h"
#include "CATIReporterInfo.h"
#include "CATUnicodeString.h"

class CATError;


extern ExportedByAD0XXBAS IID IID_CATIReporter ;

//------------------------------------------------------------------

/**
  * Interface offering mechanims to store errors informations.<BR>
  * Each information is a couple:
  * <UL>
  *  <LI><B>a Name</B>: this name is usually the name of the object which has raised the error.</LI>
  *  <LI><B>an Error</B>: This error is created from a CATError given in parameters or information to construct this CATError.</LI>
  * </UL><BR>
  * This information is manipulated by the interface CATIReporterInfo.
  * Before stacking information in the reporter (with CreateInfo methods), user must call ResetReporterData to empty the reporter list.<BR>
  * At any time, it is possible to get the list of information stacked by calling GetListReporterInfo.
  * The CATIReporter pointer  is retrievable thanks to the @href CATPLMReporterServices#GetSessionReporter method.
*/
class ExportedByAD0XXBAS CATIReporter: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:
  /**
  * @nodoc
  * Do not use. Will be deleted in CATIAV5 release 16.
  * @return CATBaseUnknown#Release
  */
	virtual CATIReporterInfo* CreateInfo( CATBaseUnknown* iObj, 
										  CATErrorId iId,
										  const char * iMsgId,
										  const char * iMsgCatalog = NULL) = 0;
  /**
  * @nodoc
  * Do not use. Will be deleted in CATIAV5 release 16.
  * @return CATBaseUnknown#Release
  */
  virtual CATIReporterInfo* CreateInfo( CATBaseUnknown* iObj, 
										  CATError* iError) = 0;
 /** 
	* Adds an information from an error identifier.
  * <BR><B>Role</B>: This method creates an information and stores it in an internal list. The error associated to the
  * information, is created by using the 3 last parameters.
  * <P>
  * @param opiReporterInfo [out, CATBaseUnknown#Release]
  *   An interface pointer on the error information. It must be released.<BR>
  * If an error occurs, this returned value is NULL.  
  * @param iObjStr [in]
	*   The string associated with the created error information.
	* @param iId [in]
	*   The Identifier of the error.
	* @param iMsgId [in]
	*   The index name used to retrieve th error message in the NLS file.
	* @param iMsgCatalog [in]
	*   The name of the NLS file containing error messages. This file contains errors identified by messages identifier.<BR>
  *   If this parameter is not given, the error message is the parameter iMsgId.
  * @return 
  *   <code>S_OK</code>, if everything ran well, otherwise <code>E_FAIL</code>.
	*/
  virtual HRESULT CreateInfo(CATIReporterInfo*& opiReporterInfo,
                      CATUnicodeString& iObjStr, 
										  CATErrorId iId,
										  const char * iMsgId,
										  const char * iMsgCatalog = NULL) = 0;
 /**
	* Adds an information from an existing error.
  * <BR><B>Role</B>: This method creates an information and stores it in an internal list. The error associated to the
  * information is given in parameter.
  * <P>
  * @param opiReporterInfo [out, CATBaseUnknown#Release]
  *   An interface pointer on the error information. It must be released.<BR>
  * @param iObjStr [in]
	*   The string associated with the created error information.
	* @param iError [in]
	*   The error to report.
	* @return 
  *   <code>S_OK</code>, if everything ran well, otherwise <code>E_FAIL</code>.
	*/
  virtual HRESULT CreateInfo(CATIReporterInfo*& opiReporterInfo,
                             CATUnicodeString& iObjStr, 
										         CATError* iError) = 0;

  /**
   * Gets the list of stored error information.
   * <BR><B>Role</B>: The returned list contained all informations stacked from the last call of ResetReporterData.<BR>
   * Warning, if you use this method, do not forget to call ResetReporterData before creating your informations.
   * @return
   *   The list of errors information stacked in this reporter.
   */
  virtual const CATLISTP(CATIReporterInfo)& GetListReporterInfo() const = 0;
  
 /** 
  * Resets all error informations.
  * <BR><B>Role</B>: This method empties all information stacked from the last call of this method.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
  */
  virtual HRESULT ResetReporterData() = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIReporter, CATBaseUnknown ) ;


#endif
