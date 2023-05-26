//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2005                                          *
//*===========================================================================*
//*                                                                           *
//*  CATIVVSMassiveCopy                                                          *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation september 2005                                                  *
//*===========================================================================*
#ifndef CATIVVSMassiveCopy_H
#define CATIVVSMassiveCopy_H
/**
* @level Private
* @usage U3
*/
#include "CATVVSNetBase.h"
#include "IUnknown.h"
#include "CATListOfCATVVSUrl.h"
#include "CATOmxGetIID.h"

class CATVVSMassiveCopyStatus;
 
extern ExportedByVVSNetBase IID IID_CATIVVSMassiveCopy;
/**  
*  Class providing general services for massive url copies.
*/
class ExportedByVVSNetBase CATIVVSMassiveCopy : public IUnknown
{
public:
/**
 * Type of the copy behavior.
 * @param StopAtFirstError
 * Stop at first error.
 * @param EnforceCopy
 * Continue if errors occur.
 */
 enum ErrorBehavior { StopAtFirstError=0,
                      EnforceCopy };
/**
 * Copy a list of URls to a list of URLs.
 * <b>Role</b>:Copy a list of URls to a list of URLs. 
 * @param iFromUrlList [in]
 *   the list of pointers to URLs to be copied.
 * @param iToUrlList [in]
 *   the list of pointers to URLs to copy to.
 * @param iCopyStatus [in]
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
  virtual  HRESULT __stdcall Copy(const CATListOfCATVVSUrl &iFromUrlList,const CATListOfCATVVSUrl &iToUrlList,
				                          const CATVVSMassiveCopyStatus * iCopyStatus,
                                  CATIVVSMassiveCopy::ErrorBehavior copyBehavior=CATIVVSMassiveCopy::EnforceCopy) = 0;
};

template<> inline const IID& CATOmxGetIID<CATIVVSMassiveCopy>(const CATIVVSMassiveCopy* )
{
  return IID_CATIVVSMassiveCopy;
}

#endif



