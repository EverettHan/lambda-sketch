// COPYRIGHT Dassault Systemes 2009
//===================================================================
// CATIObjectTyping.h
//===================================================================
//  Sep 2009  Creation: Code generated by the CAA wizard  JPI
//===================================================================

#ifndef CATIObjectTyping_H
#define CATIObjectTyping_H

#include "KnowledgeItfCPP.h"
#include "CATBaseUnknown.h"
#include "CATListValCATIType.h"
#include "CATICkeObject.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItfCPP IID IID_CATIObjectTyping;
#else
extern "C" const IID IID_CATIObjectTyping ;
#endif
class CATIType;
//------------------------------------------------------------------

/**
* Interface mainly used to add "types" (or "extensions") on objects. <br/>
* Those objects can be:
* <ul>
*   <li> features in a representation </li>
*   <li> PLM objects declared as "Extensible" </li>
* </ul>
*
* <br><b>Role</b>: The component that implements CATIObjectTyping is the Knowledge Dictionary. 
* To get a pointer on this interface you must do something like
* CATIObjectTyping_var hObjTyping(CATGlobalFunctions::GetTypeDictionary());
* <p>
* @href ClassReference, CATGlobalFunctions#GetTypeDictionary
*/
class ExportedByKnowledgeItfCPP CATIObjectTyping: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

   /** 
    *   Adds an extension on a feature in a Representation or on a PLM object.
    *
    *   @param iObjectToType [in]
    *      The object to type. It must be a feature in a 3DShape or a PLM object. <br/>
    *      In case of a PLM object, this object must be declared extensible and must not already have 
    *      iType as added extension, otherwise E_FAIL is returned.
    *   @param iType [in]
    *      The extension to be added. <br/>
    *      To extend a feature in a 3DShape, iType must be declared as usable in a Representation. <br/>
    *      In case of the extension of a PLM object, iType must be a Customer extension and its scope
    *      must be compatible with the CATIType of iObjectToType, otherwise E_FAIL is returned.
    *   @param oExtObject [out]
    *      if iObjectToType is in a Reprensentation, oExtObject is the added extension. <br/>
    *      if iObjectToType is a PLM object, oExtObject is the extended iObjectToType.
    *   @return
    *      <code>S_OK</code> extension addition was successful </br>
    *  <br><code>E_FAIL<br><code> extension addition failed.
    *  <pre>To get information on the reasons of the failure, call :
    *    CATError::CATGetLastError on the returned HRESULT
    *  then call :
    *    GetNLSMessage on the returned error.
    *  </pre>
    */
	  virtual HRESULT AddType( CATBaseUnknown* iObjectToType,
                             CATIType* iType,
                             CATICkeObject_var& oExtObject)=0;

	 /**
	  *   Removes an extension from a feature in a Representation or from a PLM object.
    *
	  *   @param iTypedObject [in]
    *      Object owning the extension to be removed.	  
	  *   @param iTypeToRemove [in]
    *      Extension to be removed. <br/>
    *      In the case when iTypedObject is a PLM object, we check that iTypeToRemove is already added,
    *      otherwise we return E_FAIL.
    *
	  *   @return
    *      <code>S_OK</code> extension removal was successful </br>
    *  <br><code>E_FAIL</code> extension removal failed.
    *  <pre>To get information on the reasons of the failure, call :
    *    CATError::CATGetLastError on the returned HRESULT
    *  then call :
    *    GetNLSMessage on the returned error.
    *  </pre>
	  */
	  virtual HRESULT RemoveType (CATBaseUnknown*  iTypedObject,
                                CATIType*  iTypeToRemove)=0;

	  /**
	  * Gets the derived types of a type. By default, the abstract types are not returned.
    *
	  *   @param iType [in]
    *      Type to be analysed.	  
	  *   @param iLeavesOnly [in]
    *      if set to TRUE the method returns only the leaves.
	  *   @param iWithAbstractTypes [in]
    *      if set to TRUE the method returns also abstract types.
	  *   @return
	  *      The list of the non abstract types derived from iType. 
	  */
	  virtual CATLISTV(CATIType_var) ListSubTypes(CATIType* iType, 
                                                CATBoolean iLeavesOnly = TRUE, 
                                                CATBoolean iWithAbstractTypes = FALSE)=0;

  // --------------------------------------------------------------
};
CATDeclareHandler(CATIObjectTyping,CATBaseUnknown);
//------------------------------------------------------------------

#endif