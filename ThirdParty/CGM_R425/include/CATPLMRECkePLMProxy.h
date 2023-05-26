// Copyright Dassault Systemes 2011
#ifndef CATPLMRECkePLMProxy_h
#define CATPLMRECkePLMProxy_h

//----------------------------------------------------------------------------------------------------------------
// The CATPLMRECkePLMProxy is a volatile object that represents a PLM Proxy (mimics a PLM object)
//----------------------------------------------------------------------------------------------------------------

#include "CATCkeInstance.h" // Inherited class

#include "CATListValCATIType.h" 

//----------------------------------------------------------------------------------------------------------------------------------------------------------
// A CATCkeVolatileInstance is a volatile object that contains a list of CATICkeParm for parameters and a list of CATIInstance as children
// It implements CATIInstance / CATIAttributesDescription / CATIDynamicAttributes
//----------------------------------------------------------------------------------------------------------------------------------------------------------
class ExportedByCATLifInstance CATPLMRECkePLMProxy : public CATCkeInstance
{

CATDeclareClass;

public :

	
	
	// if iType is NULL, it will be replaced by feature type
	// The 2 lists in input are used as is and deallocated by this object. As a consequence they must be allocated by the caller and not deleted by it
	CATPLMRECkePLMProxy (const CATUnicodeString &iName,
					const CATIType_var &iType,   // ATTENTION CE TYPE EST LE MAINTYPE (celui rendu par CATIInstance::Type)
					CATLISTV(CATBaseUnknown_var) *pListAttributes = NULL,
					CATLISTV(CATBaseUnknown_var) *pListChildren = NULL,
					CATBoolean iManageModifiedAttributes = TRUE
					);   
	virtual ~CATPLMRECkePLMProxy() ; 

	static HRESULT CreateCKEInstance(const CATUnicodeString &iName,
										const CATIType_var &iType,
										CATLISTV(CATBaseUnknown_var) *pListAttributes,
										CATLISTV(CATBaseUnknown_var) *pListChildren,
										CATBoolean iComputeModifiedAttributes,
										CATIInstance_var& spoInstance	);



	// CATIDynamicAttributes
	virtual HRESULT AddTypeSupport ( const CATIType_var &iTypeAdded) ;

	virtual HRESULT GetAttributes(CATLISTV(CATBaseUnknown_var) *& listAttributes);
	virtual HRESULT SetAttributes(CATLISTV(CATBaseUnknown_var) * listAttributes);
	virtual HRESULT GetChildrens(CATLISTV(CATBaseUnknown_var) *& listChildrens);
	virtual HRESULT RemoveAttribute(const CATUnicodeString& iAttribute);


		  //  CATLISTV(CATBaseUnknown_var)	*_plistAttributes;		// list of attributes (simple one: can be boolean, int, string, or a reference to an object)
  //  CATLISTV(CATBaseUnknown_var)	*_plistChildrens;	

protected: 
	// Sets a value from the list of attributes (recognized by name): adds a test
	virtual HRESULT SetValueInternal( const CATUnicodeString& iKey, const CATIValue_var& iValue ) ;

	// Do we want to propagate Unset status when valuating an attribute of a volatile instance
	virtual CATCke::Boolean WantPropagateUnset (const CATICkeParm_var &oValue);

	// Adds the extensions if any to the list
	virtual HRESULT ListSupportedTypesInternal( CATListValCATIType_var& oListOfCATIType ) const ;





}; 

#endif

