// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMBaseObject.h
// Header definition of CATPLMBaseObject
//
//===================================================================
//
// Usage notes:
//	Described the identifiable object base.
//
//===================================================================
//  May 2003  Creation: jvm
//===================================================================
/**
* @level Private
* @usage U1
*/
#ifndef CATPLMBaseObject_H
#define CATPLMBaseObject_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATBooleanDef.h"

#include "CATOmxKeyString.h"

class CATUnicodeString;
class CATString;
class CATIPLMProviderDesc;

//-----------------------------------------------------------------------

/**
 * Described the identifiable object base.
 */
class ExportedByCATPLMServicesItf CATPLMBaseObject: public CATBaseUnknown
{

public:
  
  // Standard constructors and destructors
  // -------------------------------------
  CATPLMBaseObject (CATString *iId, CATUnicodeString *iAlias, CATIPLMProviderDesc * iProvider);
  virtual ~CATPLMBaseObject ();
  
  /**
  *	@DEPRECATED
  */
  HRESULT GetId ( CATString **oId) ;
  
  /**
  * Return the Id of the object (CATPLMType / CATPLMAttribute / CATPLMDomain / etc...)
  */
  HRESULT GetId ( CATString &oId) ;

#ifdef _DEFINEOLDGETID
  const CATOmxKeyString GetId (int i=0) const {return _Id;}
#endif

  /**
  * Return the Id of the object (CATPLMType / CATPLMAttribute / CATPLMDomain / etc...)
  * Prefered use : No copy or transformation of internal data
  */
  const CATOmxKeyString &GetId () const {return _Id;}

  /**
  *	@DEPRECATED
  */
  virtual HRESULT GetAlias  ( CATUnicodeString **oAlias) ;

  /**
  *	Returns the Type and the instance Id of the provider  
  * @param oProviderDesc [out, CATBaseUnknown#Release]
  *		provider descriptor.
  */
  virtual HRESULT GetProviderDesc ( CATIPLMProviderDesc ** oProviderDesc);
  
  /**
  *	Indicates if the input string is the same as the ID of the object. 
  * @param iInputID
  *		The ID to compare.
  */
  CATBoolean IsIDEqualTo ( const CATString &iInputID);

  /**
  *	Indicates if the input object has the same ID (key) as the current one. 
  * @param iCompareKey
  *		The ID to compare.
  */
  CATBoolean CompareId ( const CATOmxKeyString &iCompareKey ) const;

protected:
  /**
  * Returns the element's NLSTag.
  * @param oNLSTag : NLSTag
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetNLSTag ( CATUnicodeString & oNLSTag);

  /** The Id of the Object */
  //	CATString *_pId;
  CATOmxKeyString _Id;
  /** The Alias of the Object */
  CATUnicodeString *_pAlias;
  /** The ProviderDesc from which the Object is gotten */
  CATIPLMProviderDesc *_pProviderDesc;

protected:
  // Copy constructor
  // -----------------------------------
  CATPLMBaseObject (CATPLMBaseObject &);
private:
  // Equal operator
  // -----------------------------------
  CATPLMBaseObject& operator=(CATPLMBaseObject&);

};

//-----------------------------------------------------------------------

#endif
