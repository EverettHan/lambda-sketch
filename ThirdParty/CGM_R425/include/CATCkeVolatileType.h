/**
 * @level Protected
 * @usage U1
 */

#ifndef CATCkeVolatileType_H
#define CATCkeVolatileType_H

#include "CATLifDictionary.h"
#include "CATEventSubscriber.h"
#include "CATICkeExpressionForwards.h"
#include "CATICkeType.h"
#include "CATICkeMKSUnit.h"
#include "CATUnicodeString.h"
#include "CATIAV5Level.h"
class CATIAttributesDescription_var;
class CATIDelegateInstanciation_var;
class CATAttributeInfos;

struct ExportedByCATLifDictionary CATCkeVolatileType 
{
  
  static CATICkeType_var Create (const CATUnicodeString &name,
								 const CATICkeType_var &type = NULL_var,
								 const CATUnicodeString &username = "",
								 const CATCke::Boolean &fakeone = 0);
  
  /**
   * Indicates if a type can be used in an expression to fulfill a given argument type  
   * @param iType: argument type
   * @param iArgType: argument type
   * @return : CATCke::True if fulfills 
   */
  static CATCke::Boolean FulfillArgumentType (const CATICkeType_var &iType,const CATICkeType_var &iArgType);
  
  /*
     * @nodoc
     */
  static HRESULT FindByNameAndExactType(const CATIAttributesDescription_var& iType,const CATUnicodeString& iName, 
                                        CATAttributeInfos*& oAttributeInfos,CATIAttributesDescription_var &oExactType );
#ifdef CATIAR211
  // Ajout FRH pour acceder a la factory applicative pour le PLM New UI
  /**
	* Retrieve the applicative class used to instanciate the Object.<br>
	* Do not use. Strictly restricted to PLM New UI.<br>
	* @param iType
	* Type that we want to create
	* @param oApplicativeFactory
	* Factory (can be NULL)
	* @return
	*  <ol>
	*    <li> E_INVALIDARG if type is empty or if the type has no associated factory mechanism
	*    <li> S_OK if the factory has been retrieved.
	*    <li> S_FALSE if the factory has not been retrieved because it didn't exist on this type.
	*  </ol>
	*/ 
  static HRESULT RetrieveApplicativeFactory (const CATBaseUnknown_var& iType,CATIDelegateInstanciation_var& oApplicativeFactory);
#endif
};

#endif

