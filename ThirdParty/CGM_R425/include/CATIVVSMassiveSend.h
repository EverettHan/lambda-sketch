//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2007                                          *
//*===========================================================================*
//*                                                                           *
//*  CATIVVSMassiveSend                                                          *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation september 2007                                                  *
//*===========================================================================*
#ifndef CATIVVSMassiveSend_H
#define CATIVVSMassiveSend_H
/**
* @level Private
* @usage U3
*/
#include "CATVVSNetBase.h"
#include "IUnknown.h"
#include "CATListOfCATVVSUrl.h"
class CATVVSMassiveCopyStatus;

extern ExportedByVVSNetBase IID IID_CATIVVSMassiveSend;
/**  
*  Class providing general services for massive url copies.
*/
class ExportedByVVSNetBase CATIVVSMassiveSend : public IUnknown
{
public:
  /**
  * Type of the copy behavior.
  * @param StopAtFirstError
  * Stop at first error.
  * @param EnforceSend
  * Continue if errors occur.
  */
  enum ErrorBehavior { StopAtFirstError=0,
    EnforceSend };
  /**
  * Receive a list of distant vault URls to a list of generally local, cached URLs.
  * <b>Role</b>:Send a list of URls to a list of URLs. 
  * @param iFromUrlList [in]
  *   the list of pointers to URLs to be copied. These are generally local, cached URLs, whose stream
  *   is accessible through a CATILockBytes2 interface.
  * @param iToUrlList [in]
  *   the list of pointers to URLs to copy to. These HAVE to be URLs belonging to the target vault site.
  * @param iSendStatus [in]
  *   the copy diagnostic for each urls. 
  * @param copyBehavior
  *   copy behavior when an error occurs. 
  * @return
  *   <b>Legal values</b>:
  *   <br><tt> S_OK :</tt>on Success for all lockbytes.
  *   <br><tt> STG_E_READFAULT :</tt> problem while reading.
  *   <br><tt> STG_E_INVALIDPARAMETER :</tt> invalid arguments.
  *   <br><tt> STG_E_ACCESSDENIED:</tt> No sufficient permission to read.
  *   <br><tt> STG_E_UNKNOWN :</tt> unexpected error.
  *   <br><tt> E_NOTIMPL :</tt> if not implemented.
  */     
  virtual  HRESULT __stdcall Send(const CATListOfCATVVSUrl &iFromUrlList, const CATListOfCATVVSUrl &iToUrlList,
    const CATVVSMassiveCopyStatus * iSendStatus,
    CATIVVSMassiveSend::ErrorBehavior sendBehavior=CATIVVSMassiveSend::EnforceSend) = 0;

};
#endif



