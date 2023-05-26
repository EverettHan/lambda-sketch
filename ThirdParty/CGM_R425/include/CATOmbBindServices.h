#ifndef __CATOmbBindServices_h__
#define __CATOmbBindServices_h__
/**
 * @level Protected
 * @usage U1
 */
#include "AC0XXLNK.h"
#include "IUnknown.h"
class CATBaseUnknown;
class _SEQUENCE_octet;

class CATDocument ;
class CATILinkableObject_var ;



namespace CATOmbBindServices {
  /**
   * Bind a symbolic link according to the provided namingcontext.
   * @param iNamingContext the naming context ie.
   * @param iRelativeName the relative name
   * @param oRes [out, CATBaseUnknown#Release] the output result.
   * @return if an exception is caught it returns E_UNEXPECTED, on V5 if oRes is NULL returns E_FAIL, 
   *   on V6 may returns other errors @href CATOmbLinKStatusServices#GetLinkStatusFromRC
   */
  HRESULT ExportedByAC0XXLNK BindFromContext(CATBaseUnknown *iNamingContext,const _SEQUENCE_octet& iRelativeName, CATBaseUnknown*& oRes) ;

  /**
   * Bind a full name sequence in the context of a document in session. DO NOT modify document symbols table.
   * @param iDoc the document in session.
   * @param iFullName the full name
   * @param oRes the output result.
   * @return returns E_FAIL if failed, returns other errors @href CATOMBLinkResolutionError in V5, @href CATOmbLinKStatusServices#GetLinkStatusFromRC in V6
   */
  HRESULT ExportedByAC0XXLNK BindFullSequenceInContext 
      (const CATDocument & iDoc, const _SEQUENCE_octet & iFullName, CATILinkableObject_var & oPointedObject) ;
};
#endif
