/**
 * @level Protected
 * @usage U3
 */
#ifndef  CATPLMAccessBasicQueryResult_h
#define  CATPLMAccessBasicQueryResult_h
#include "CATPLMIntegrationAccess.h"

#include "CATBaseUnknown.h"
#include "CATPLMIdentifier.h"
#include "CATListOfCATUnicodeString.h"

// --- Class definition

/**
 * Generic class to manage query results .
 *
 * <b>Role</b>:
 * This class will contain the results of a query in VPDM : CATPLMIdentifier of the object 
 * result of the query and list of attribute values of this object. 
 */
class ExportedByCATPLMIntegrationAccess CATPLMAccessBasicQueryResult : public CATBaseUnknown
{
public:
   /** @nodoc
    * Constructs a query result object.
    */
   CATPLMAccessBasicQueryResult(const CATPLMIdentifier& PLMIdentifier,const CATListValCATUnicodeString* AttNames,const CATListValCATUnicodeString* AttValues);
   
   /** @nodoc
    * Destructor.
    * <br><b>Role</b>: Destructor.
    */
   virtual ~CATPLMAccessBasicQueryResult() ;
   
   
   /**
    * Gets the PLMIdentifier.
    * <br><b>Role</b>: Gets the object type information.
    * @param oPLMIdentifier
    *    Gets the PLMIdentifier 
    */
   HRESULT GetPLMIdentifier(CATPLMIdentifier & oPLMIdentifier) ;
   
   /**
    * Gets the list of attribute name.
    * <br><b>Role</b>: Gets the list of attributes available on this object.
    * @param oAttNames
    * Gets the list of attribute values. 
    */
   HRESULT GetAttributeNames(CATListValCATUnicodeString & oAttNames ) ;
   
   /**
    * Gets the list of attribute values.
    * <br><b>Role</b>: Gets the list of attributes values on this object.
    * @param oAttValues
    * Gets the list of attribute values. 
    */
   HRESULT GetAttributeValues(CATListValCATUnicodeString & oAttValues ) ;
   
   
private:
   
   /** @nodoc */
   CATPLMIdentifier               _PLMIdentifier ;
   /** @nodoc */
   CATListValCATUnicodeString     _AttNames ;
   /** @nodoc */
   CATListValCATUnicodeString     _AttValues ;
} ;

#endif

