/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
// Creation: BES

#ifndef CATVVSMassiveCopy_Adaptor_h
#define CATVVSMassiveCopy_Adaptor_h

#include "CATVVSNetBase.h"
#include "CATIVVSMassiveCopy2.h"
#include "CATIAV5Level.h"
#include "CATVVSUrl.h"

/**
 * @level Protected
 * @usage U1
 */

/**
* Adapter for CATIVVSMassiveCopy2 interface. Implements useful methods.
*/

class ExportedByVVSNetBase CATVVSMassiveCopy_Adaptor : public CATIVVSMassiveCopy2
{
  
public:

  // interface IUnknown
  ULONG   __stdcall AddRef();
  ULONG   __stdcall Release();
  HRESULT __stdcall QueryInterface(const IID &iid, void ** ppv);
    
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
                                  CATIVVSMassiveCopy::ErrorBehavior copyBehavior=CATIVVSMassiveCopy::EnforceCopy)
    { return E_NOTIMPL; }

  virtual  HRESULT __stdcall Copy(const CATOmxArray<CATVVSUrl> &iFromUrlList,const CATOmxArray<CATVVSUrl> &iToUrlList, 
                                  const CATVVSMassiveCopyStatus * iCopyStatus, CATBoolean iMD5ToBeCheckedByFCS)
    { return E_NOTIMPL; }
    
protected:

  CATVVSMassiveCopy_Adaptor():_RefCount_(1)
    {}
  virtual ~CATVVSMassiveCopy_Adaptor()
    {}
    
private:
  
  ULONG _RefCount_;
};

#endif
