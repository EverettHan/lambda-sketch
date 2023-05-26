//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2007
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicVolatile_h
#define _VPMIDicVolatile_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"
#include "VPMDicPROTECTION.h"

#include "VPMIDicClass.h" // Important a garder pour compatibilite ascendante du service
#define VPMIDicVolatileNlsAsGenericClass

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicVolatile;
#else
extern "C" const IID IID_VPMIDicVolatile;
#endif

/**
* Interface to manage the Volatile.
*/
class ExportedByVPMIDicInterfaces VPMIDicVolatile : public VPMIDicElement
{
  CATDeclareInterface;

public:

  /**
  * Retrieves the TypeName property of the Volatile.
  * @param oTypeName
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetTypeName ( CATUnicodeString * oTypeName ) = 0;

  /**
  * Retrieves the AccessMode property of the Volatile.
  * @param oAccessMode
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetAccessMode ( CATUnicodeString * oAccessMode ) = 0;

  /**
  * Retrieves the Accessor property of the Volatile.
  * @param oAccessor
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetAccessor ( CATUnicodeString * oAccessor ) = 0;

  /**
  * Retrieves the Simple's CustoUserAccess, depending on its Protection and its Property "CustoUserAccess" if any
  * @return
  */
  virtual VPMDicCUSTOUSERACCESS GetCustoUserAccess() const = 0; 

  /**
  * Retrieves the Volatile's NLSTag, possibly in the context of a given Class.
  * In that case, this given Class must be derived from the Class where the current Volatile is actually defined.
  * @param iDicClass : the Class in which the Volatile is to be considered
  * @param oNLSTag : NLSTag
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetNLSTag ( CATUnicodeString & oNLSTag, const VPMIDicGenericClass * iDicClass = NULL ) = 0;


  /**
  * Retrieves the Volatile's NLSValue, possibly in the context of a given Class.
  * In that case, this given Class must be derived from the Class where the current Volatile is actually defined.
  * @param iDicClass : the Class in which the Volatile is to be considered
  * @param oNLSValue : NLSValue
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetNLSValue ( CATUnicodeString & oNLSValue, const VPMIDicGenericClass * iDicClass = NULL ) = 0;

  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Methods to modify dictionary should never be user, except by providers
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  /**
  * Sets the Accessor property of the Volatile.
  * @param iAccessor
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetAccessor  ( const CATUnicodeString * iAccessor ) = 0;

  /**
  * Sets the AccessMode property of the Volatile.
  * @param iAccessMode
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetAccessMode ( const CATUnicodeString *iAccessMode ) = 0;

  /**
  * Sets the TypeName property of the Volatile.
  * @param iTypeName
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetTypeName ( const CATUnicodeString *iTypeName ) = 0;


};

CATDeclareHandler( VPMIDicVolatile, VPMIDicElement );

#endif /*_VPMIDicVolatile_h*/
