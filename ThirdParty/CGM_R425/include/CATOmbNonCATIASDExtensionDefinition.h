#ifndef  CATOmbNonCATIASDExtensionDefinition_H_V1
#define  CATOmbNonCATIASDExtensionDefinition_H_V1

/**
* @level Protected
* @usage U1
*/

#include "CATOmbNonCATIADocument.h"
#include "CATError.h"
#include "CATUnicodeString.h" 

class CATOmbNonCATIASDExtensionDefinitionPrivate;

/**
* Extension declaration status. 
*
* @param CATOmbNotDefined
*   Extension has not been defined. 
* @param CATOmbDefined
*   Extension has been correctly defined.
* @param CATOmbMultiplePersistencyType
*   At least two files in the runtime view provides incompatible declaration for the extension. (use of different persistency type)
* @param CATOmbInvalidLateType
*   At least two files in the runtime view provides incompatible declaration for the extension. (use of different inheritance tree)
* @param CATOmbBySessionDefined
*   Extension has been statically defined as a sub-CATNonCATIADocument late type at the beginning of the session.
*
*/


enum CATOmbNonCATIAStreamDesciptorDefinitionStatus
{
    CATOmbNotDefined=0,
    CATOmbDefined=1,
    CATOmbMultiplePersistencyType=2,
    CATOmbInvalidLateType=3,
    CATOmbBySessionDefined=4
};

#define NB_DEF_STATUS 5
static CATUnicodeString DefStatusToDump[NB_DEF_STATUS]  = { "Undefined", "User defined", "ERROR multiple def !", "ERROR forbidden type !", "session defined" }; // ! Keep length in relation with enum above !

/**
* Class representing the definition of an extension for NonCATIAStreamDescriptor. 
*
* <br><b>Role</b>: 
* This class is generated according to the content of file located in CNEXT\NonCATIAStreamDescriptor\ApplicationName.ExtDefinition 
* It contains all information related to the extension definition.
* This class can be built with a given extension for look-up in a HashTable. 
* HashTable Key is generated according to the persistency type.
* <p>
*/


class ExportedByCATOmbNonCATIADocument CATOmbNonCATIASDExtensionDefinition
{       
public :

    CATOmbNonCATIASDExtensionDefinition();
    CATOmbNonCATIASDExtensionDefinition(CATOmbNonCATIASDExtensionDefinitionPrivate& ExtensionDefinitionPrivate);

~CATOmbNonCATIASDExtensionDefinition(); 

    /**
    * Retrieves the persistency type associated to the set of extensions. 
    */

    CATUnicodeString GetPersistencyType();

    /**
    * LateType of the NonCATIAStreamDescriptor 
    */

    CATUnicodeString GetLateType();

    /** 
    * Retrieves the FilePath of the file that has created this entry. 
    */

    CATUnicodeString GetFilePath();

    /**
    * Returns the extension associated to this entry. 
    */

    CATUnicodeString GetExtension();

    /**
    * Returns comments associated to this entry. 
    */

    CATUnicodeString GetComments();

    /**
    * Returns visibility of this entry. 
    */

    CATBoolean GetVisibility();

    /** 
    * Status of the entry. 
    * 
    * @return
    * <code>CATOmbNotDefined</code> Extension is not defined. All Other methods will return empty results. 
    * <code>CATOmbDefined</code> Extension is defined and is valid
    * <code>CATOmbMultiplePersistencyType</code> Extension has been defined but with an error @see GetAssociatedError to understand why
    * <code>CATOmbInvalidLateType</code> Extension has been defined but with an error @see GetAssociatedError to understand why
    */

    CATOmbNonCATIAStreamDesciptorDefinitionStatus GetStatus();  
   
    /**  
    *  Returns  the  error  that  affects  the  definition  if  any.    
    *  <b>Role</b>  
    *  @param  oErrors  
    *        The  detected  error.  Error  is  Adreffed.    
    *  @return  
    *  <ul>  
    *  <li>  S_OK      :  Error  returned  
    *  <li>  E_FAIL    :  No  error  returned    
    *  </ul>  
    */                    
    HRESULT  GetAssociatedError(CATError*&  oError); 

    const CATUnicodeString DumpExtension();

    CATBoolean operator == (const CATOmbNonCATIASDExtensionDefinition&) const;
    CATBoolean operator != (const CATOmbNonCATIASDExtensionDefinition&) const;

    /** 
    * returns the main extension associated to this entry (the generic extension for the set of extensions)
    */
    CATUnicodeString GetGenericExtension();

private : 
    CATOmbNonCATIASDExtensionDefinitionPrivate*  _pCATOmbNonCATIASDExtensionDefinitionPrivate;

    CATOmbNonCATIASDExtensionDefinition(CATUnicodeString AppsName, CATUnicodeString RegisteredAs, 
        CATUnicodeString Inherits, CATUnicodeString Extension, 
        CATOmbNonCATIAStreamDesciptorDefinitionStatus Status);
       
};        
#endif
