// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATIAttributeComputed.h
// Define the CATIAttributeComputed interface
//
//===================================================================
//
// Usage notes:
//   When defining an attribute, it is possible to declare that this attribute will be computed by a C++ fonction (volatile attribute)
//===================================================================
#ifndef CATIAttributeComputed_H
#define CATIAttributeComputed_H

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATIType.h"

/** 
* @CAA2Level L1
* @CAA2Usage U4 CATAttributeComputedAdapter
*/


class CATICkeObject;

class CATUnicodeString;
class CATIValue_var;
class CATIValue;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIAttributeComputed;
#else
extern "C" const IID IID_CATIAttributeComputed ;
#endif


/**
 * This interface is to be implemented on a late type that also implements CATICreateInstance.<br>
 * When defining an attribute with CATAttributeInfos, the last argument (iAttributeAccess) is the name of the late type that implements CATIAttributeComputed.<br>
 * Reading and/or writing the attributes through EKL (or through CATCkeObjectAttrReadServices/CATCkeObjectAttrWriteServices), will delegate to the methods of CATIAttributeComputed on the late type.
 * <p><b>BOA information</b>: this interface can be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the "Object Modeler" chapter in the CAA Encyclopedia.</p>
 * @see CATAttributeInfos, CATIType, CATIValue, CATICkeObject, CATCkeObjectAttrReadServices, CATCkeObjectAttrWriteServices, CATCkeGlobalFunctions, CATICkeParmFactory
 */
class ExportedByCATLifSpecs CATIAttributeComputed: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
    /**
	 * Indicates if the computed attribute can be computed on this object.<br>
	 * @param iObject
 	 * Knowledge object on which we want to "valuate" an attribute.
	 * @return
	 *  <ol>
	 * 	 <li> TRUE if the object is valid.
	 * 	 <li> FALSE if the object is not valid.
	 *  </ol>
     */
   virtual CATBoolean IsMeaningful (CATICkeObject*			  iObject) = 0;

    /**
	 * Provides the value of a computed attribute on a given object.<br>
	 * @param iObject
 	 * Knowledge object on which we want to compute an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param oValue
	 * Value that we will read on the attribute.
	 * @param iType
	 * Useless
	 * @return the value if succeeded, NULL instead. An AddRef must be done
	 * To create the value, please use CATCkeGlobalFunctions::GetVolatileFactory() to retrieve volatile value factory (CATICkeParmFactory) and use ad-hoc method to create your value.
	 *  </ol>
     */
    virtual CATIValue* GetValue(  CATICkeObject*			  iObject,
								  const CATUnicodeString &iAttributeName,
								  const CATIType_var     &iType = NULL_var ) = 0;
    
    /**
	 * "Valuates" the value of a computed attribute on a given object by translating it and propagating to real object.<br>
	 * @param iObject
 	 * Knowledge object on which we want to "valuate" an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param iType
	 * Useless
	 * @param oValue
	 * Value that we will "put" on the object
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the attribute not supported, or object NULL.
	 * 	 <li> S_OK	if the attribute has been put correctly
	 * 	 <li> E_FAIL if the valuation has failed.
	 *  </ol>
    */
    virtual HRESULT SetValue(	CATICkeObject*           iObject,
								const CATUnicodeString  &iAttributeName,
								const CATIType_var      &iType,
								const CATIValue_var     &iValue) = 0;
};

CATDeclareHandler(CATIAttributeComputed, CATBaseUnknown);

#endif
