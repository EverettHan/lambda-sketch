
#ifndef __CATIReplace_h__
#define __CATIReplace_h__

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATMmrReplaceAdapter
 */


#include "CATProviderItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

extern ExportedByCATProviderItf IID IID_CATIReplace;

/**
 * Interface to replace the valuation of an attribute by another one.
 * <br><b>Role</b>:
 * This interface is dedicated to an internal use and is called during replace operations. 
 * It needs to be implemented on any new applicative feature. 
 * The implementation should include the additional method GetRequestedBehavior.
 * @see CATMmrReplaceAdapter.
 * <p><b>BOA information</b>: this interface can be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 */
class ExportedByCATProviderItf CATIReplace : public CATBaseUnknown
{
  CATDeclareInterface;

public:
	
  /**
   * Determines whether the candidate element is allowed to replace the existing one.
	 * <br> This method should only be called internally.
   * @param iName
   *        name of the attribute whose value is to be replaced.
   * @param iElement
   *        candidate element for replace.
   * @param oMessage
   *        explains returned HRESULT
   * @param oElementValidity
   * <b>Legal values </b>: 
   *     <tt> 0 if element is not valid </tt>,
   *     <br><tt> 1 if element is valid </tt>
   * @param iOldValue
   *        position of the feature to replace if the attribute is a list.
   * @return HRESULT
   * <br><b>Legal values </b>: 
   *     <tt>  S_OK   </tt>
   *     <tt>  E_FAIL  </tt>
   *     <tt>  E_NOTIMPL </tt>
   */
  virtual HRESULT IsElementValidForReplace(const CATUnicodeString & iName, const CATBaseUnknown_var & iElement, CATUnicodeString & oMessage, int & oElementValidity, const CATBaseUnknown_var & iOldValue = NULL_var) = 0;

  /**
   * Valuates a given attribute with another object.
	 * <br> This method should only be called internally.
   * @param iName
   *        name of the attribute whose value is to be replaced
   * @param iElement
   *        candidate element for replace.
   * @param iOldValue
   *        position of the feature to replace if the attribute is a list.
   * @return HRESULT
   * <br><b>Legal values </b>: 
   *     <tt>  S_OK   </tt>
   *     <tt>  E_FAIL  </tt>
   *     <tt>  E_NOTIMPL </tt>
   */
  virtual HRESULT Replace(const CATUnicodeString & iName, CATBaseUnknown_var & iElement, const CATBaseUnknown_var & iOldValue = NULL_var) = 0;

};

CATDeclareHandler(CATIReplace, CATBaseUnknown);


#endif // __CATIReplace_h__
