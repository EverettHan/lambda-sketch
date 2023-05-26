// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCkePLMTypeAppliServices.h
// Header definition of CATCkePLMTypeAppliServices
//
//===================================================================
//
// Usage notes:
// Provides services for finding information on types, useful for applications (and not infrastructure)
//
//===================================================================

 

#ifndef CATCkePLMTypeAppliServices_H 
#define CATCkePLMTypeAppliServices_H 

// Module export
#include "PLMDictionaryNavServices.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
 

class CATIType_var;

/**
 * Services used by applications
 * @see CATIType
 */
class ExportedByPLMDictionaryNavServices CATCkePLMTypeAppliServices 
{

  public:

	  /**
	  * This service indicates if the type supports configuration.
	  * @param iType
	  * The type    
	  * @param iResult
	  * True if it support configuration, False instead.
	  * @param iVS
	  * True is the type supports Variability Space, False if it supports effectivity
	  * @return
	  *  <ol>
      * 	 <li> E_INVALIDARG if the input PLM type is invalid (NULL)
      * 	 <li> S_OK if we found the property
      * 	 <li> S_FALSE if we didn't find the information
	  *  </ol>
	  */
 	  static HRESULT SupportsConfiguration      (const CATIType_var &iType,CATBoolean &iResult,CATBoolean &iVS);

	  /**
	  * This service indicates if the type supports change management.
	  * @param iType
	  * The type    
	  * @param iResult
	  * True if it support configuration, False instead.
	  * @return
	  *  <ol>
      * 	 <li> E_INVALIDARG if the input PLM type is invalid (NULL)
      * 	 <li> S_OK if we found the property
      * 	 <li> S_FALSE if we didn't find the information
	  *  </ol>
	  */
 	  static HRESULT SupportsChangeManagement   (const CATIType_var &iType,CATBoolean &iResult);
	

	  /**
	  * This service enables to implement a sort strategy for children of an object of a given type.
	  * @param iType
	  * The type    
	  * @param oAttributeUsed
	  * Name of the attribute used to operate a sort
	  * @param oListOrderedTypeNames
	  * Returns potentially a list of types name, that can be used to classify the children and to present them in this order
	  * @return
	  *  <ol>
      * 	 <li> E_INVALIDARG if the input PLM type is invalid (NULL) 
      * 	 <li> S_OK if we found the property
      * 	 <li> S_FALSE if we didn't find the information or if the syntax was incorrect
	  *  </ol>
	  */
 	  static HRESULT SortingChildrenInTreeMethodology      (const CATIType_var &iType,CATUnicodeString &oAttributeUsed, CATListOfCATUnicodeString& oListOrderedTypeNames);

    /**
    * This service checks the V_usage value and returns S_OK if it is a possible value for a 3DShape Representation.
    * @param iUsageValue
    *   The value of the V_usage attribute.
    * @return
    *  <ol>
      *    <li> S_OK if the usage value is a possible value for 3DShapes
      *    <li> E_FAIL if not
    *  </ol>
    */
    static HRESULT IsA3DShapeUsage( const CATUnicodeString& iUsageValue );
};
//-----------------------------------------------------------------------

#endif

