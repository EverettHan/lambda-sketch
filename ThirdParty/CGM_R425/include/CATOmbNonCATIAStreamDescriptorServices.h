#ifndef CATOmbNonCATIAStreamDescriptorServices_H_V1
#define CATOmbNonCATIAStreamDescriptorServices_H_V1

/**
* @level Protected
* @usage U1
*/

#include "CATOmbSessionService.h"
#include "CATOmbNonCATIADocument.h"
#include "CATOmbNonCATIASDExtensionDefinition.h"
#include "CATListOfCATOmbNonCATIASDExtensionDefinition.h"

#include "CATVVSFileDescriptionServices.h"
#include "CATComponentId.h"
#include "CATPLMID.h"

/**
* This static class provides methods to determine which extensions can be used as NonCATIAStreamDescriptor
*
* <br><b>Role</b>: 
* <p>
*   This class allows determining the status of NonCATIAStreamDescriptor definitions :
*   <li>
*     <ul> specifies which extensions can be used </ul>
*     <ul> retrieves detected errors in the files specifying extension definitions</ul>    
*   </li>
*/

class ExportedByCATOmbNonCATIADocument CATOmbNonCATIAStreamDescriptorServices 
{

public :

  /** 
  * Retrieves all extensions available and valid to create NonCATIAStreamDescriptor. 
  *
  *
  * @param oDefinitions [out]
  *   List of definitions parameters for each valid extension. 
  *
  * @return
  *   <code>S_OK</code>     All definitions are valid
  *   <code>S_FALSE</code>  Some Definitions are not valid. @see RetrieveDeclarationErrors to retrieve the erroneous definitions
  *   <code>E_FAIL</code>   unexpected error
  *
  */

  static HRESULT RetrieveAllNonCatiaSDExtensionDefinitions(CATListOfCATOmbNonCATIASDExtensionDefinition& oDefinitions);    


  /** 
  * Retrieves the definition parameter of a given extension. 
  *
  * @param iExtension [in]
  *   The given extension. 
  * @param oDefinition [out]
  *   Parameters associated to this extension. 
  *
  * @return
  *   <code>S_OK</code> Extension has been declared and is valid for NonCATIAStreamDescriptor
  *   <code>CATOmb_E_ExtensionNotDefined</code> Extension has not been defined. oDefinition.GetStatus returns CATOmbNotDefined
  *   <code>CATOmb_E_ExtensionDefintionError</code> An error has been detected in the extension definition. @see CATOmbNonCATIASDExtensionDefinition::GetStatus to retrieve more information  
  *   <code>E_FAIL</code> unexpected error. 
  *
  */

  static HRESULT CheckExtensionIsAvailableForNonCATIAStreamDescriptor(const CATUnicodeString& iExtension, CATOmbNonCATIASDExtensionDefinition& oDefinition);


  /** 
  * List all detected errors in NonCATIAStreamDescriptors Extension Definitions. 
  *
  * <br><b>Role</b>: List all detected errors in NonCATIAStreamDescriptors Extension Definitions. 
  * All Extensions in error cannot be used for NonCATIAStreamDescriptor.
  *
  * @param oErrors [out]
  *   List of detected errors. 
  *
  * @return
  *   <code>S_OK</code> code is successfull. 
  *   <code>E_FAIL</code> unexpected error. 
  *
  */

  static HRESULT RetrieveDeclarationErrors(CATListOfCATOmbNonCATIASDExtensionDefinition&  oErrors);   


  /** 
  *        Retrieve LateType From NonCATIA Extension.
  *
  * @param iExtension [in]
  *   Extension to look for.
  * @param oLateType [out]
  *   LateType associated with iExtension.
  *
  * @return
  *   <code>S_OK</code>     A LateType has been found for a NonCATIA Extension and Extension is 
  *                         different from LateType (ex: ext. : JPG LateType jpeg)
  *   <code>S_FALSE</code>  A LateType has been found for a NonCATIA Extension and Extension and
  *                         LateType are similar.
  *   <code>E_FAIL</code>   Extension is not a registered NonCATIA Extension
  *
  */
  static HRESULT RetrieveNonCATIALateTypeFromExtension(const CATUnicodeString& iExtension, CATUnicodeString& oLateType) ;

  /** 
  * Is the input LateType/NonCATIA GenericExtension declared as a NonCATIA type
  *
  * @param iLateType [in]
  *   the LateType or NonCATIA GenericExtension to be analysed.
  * @return
  *   <code>TRUE</code>   This LateType is declared as a NonCATIA generic Extension or a CATNonCATIADocument (sub)LateType
  *   <code>FALSE</code>  This LateType doesn't represent a Non CATIA SD
  */
  static CATBoolean IsANonCATIASDType(const CATUnicodeString& iLateType);

  /** 
  * Is the input PersistencyType currently marked with LocalStorage mode
  *
  * @param iCompoPersisType [in]
  *   the PersistencyType to be checked.
  * @param oLSMode [out]
  *   the LocalStorage mode declared by the mark.
  * @param oPersisType [out]
  *   the true PersistencyType.
  * @return
  *   <code>TRUE</code>   Input PersistencyType is marked with LocalStorage tag. True PersistencyType is oPersisType.
  *   <code>FALSE</code>  Input PersistencyType is the true one. iCompoPersisType = oPersisType.
  */
  static CATBoolean IsALocalStorageType(const CATUnicodeString& iCompoPersisType, FD::FileDescriptionBehavior& oLSBehavior, CATUnicodeString& oPersisType);

  /** 
  * Mark the input PersistencyType with LocalStorage mode.
  *
  * @param iCompoPersisType [in]
  *   the true PersistencyType to be marked.
  * @param iLSMode [in]
  *   the LocalStorage mode to declare.
  * @param oCompoPersisType [out]
  *   the composite marked PersistencyType.
  * @return
  *   <code>TRUE</code>   Input PersistencyType has  marked with LocalStorage tag. True PersistencyType is oPersisType.
  *   <code>FALSE</code>  Input PersistencyType is the true one. iCompoPersisType = oPersisType.
  */
  static CATBoolean SetAsLocalStorageType(const CATUnicodeString& iPersisType, FD::FileDescriptionBehavior iLSBehavior, CATUnicodeString& oCompoPersisType);

  /**
  * Local storage lock management
  * Gets a serialized physical id of the component owning a (non CATIA) SD to be referenced in Local storage lock table
  *
  * @param iCId or iPLMId [in]
  *   a global identifier of the component.
  * @param oPhysicalId [out]
  *   a serialized format of the component physical id. 
  * @return
  *   <code>S_OK</code>          everything went well.
  *   <code>E_UNEXPECTED</code>  a problem occured, invalid output.
  */
  static HRESULT GetSerializedPhysicalId(const CATComponentId& iCId, CATUuid& oPhysicalId);
  static HRESULT GetSerializedPhysicalId(const CATPLMID& iPLMId, CATUuid& oPhysicalId);

private :

  CATOmbNonCATIAStreamDescriptorServices();
  ~CATOmbNonCATIAStreamDescriptorServices();
};
#endif
