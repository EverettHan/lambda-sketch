#ifndef CATAttributeComputedAdapter_H
#define CATAttributeComputedAdapter_H

// COPYRIGHT DASSAULT SYSTEMES 2002

/** 
* @CAA2Level L1
* @CAA2Usage U2
*/

// Export Module 
#include "CATLifSpecs.h" 

// inherit from
#include "CATBaseUnknown.h"
#include "CATIForwardsDecl.h"
#include "CATIAttributeComputed.h"

/**   
 * CAA2 Adapter to CATIAttributeComputed Interface.
 * <b>Role</b>: This class must be derived to implement CATIAttributeComputed.<br>
 * CATIAttributeComputed is the interface used by Knowledgeware to delegate the read and write of computed attributes.<br>
 * @see CATIAttributeComputed, CATICkeObject, CATIType, CATIValue
 */
class ExportedByCATLifSpecs CATAttributeComputedAdapter : public CATIAttributeComputed
{
public:

   /** 
    * Constructs the adapter.
    */ 
    CATAttributeComputedAdapter();

   /** 
    * Deletes the adapter.
    */ 
    virtual ~CATAttributeComputedAdapter();

	 /**
	 * Indicates if the computed attribute can be computed on this object.<br>
	 * Default implementation returns FALSE.
	 * @param iObject
 	 * Knowledge object on which we want to "valuate" an attribute.
	 * @return
	 *  <ol>
	 * 	 <li> TRUE if the object is valid.
	 * 	 <li> FALSE if the object is not valid.
	 *  </ol>
     */
    virtual CATBoolean IsMeaningful (CATICkeObject*			  iObject) ;

    /**
	 * Provides the value of a computed attribute on a given object.<br>
	 * Default implementation returns NULL.
	 * @param iObject
 	 * Knowledge object on which we want to compute an attribute.
	 * @param iAttributeName
	 * Name of the attribute in the Knowledge dictionary (internal name)
	 * @param oValue
	 * Value that we will read on the attribute.
	 * @param iType
	 * Useless
	 * @return the value if succeeded, NULL instead. An AddRef must be done
	 *  </ol>
     */
    virtual CATIValue* GetValue(  CATICkeObject*			  iObject,
								  const CATUnicodeString &iAttributeName,
								  const CATIType_var     &iType  ) ;
    
    /**
	 * "Valuates" the value of a computed attribute on a given object by translating it and propagating to real object.<br>
	 * Default implementation returns E_FAIL.
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
								const CATIValue_var     &iValue) ;

private:
 
  /**
   */
   CATAttributeComputedAdapter(const CATAttributeComputedAdapter&);
};


#endif
