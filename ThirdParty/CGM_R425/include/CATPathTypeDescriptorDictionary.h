// COPYRIGHT Dassault Systemes 2007


#ifndef CATPathTypeDescriptorDictionary_H
#define CATPathTypeDescriptorDictionary_H


#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATIPathTypeDescriptor.h"
class CATUnicodeString;

#include "CATOmxOMap.h" 

// To retrieve the iterator on path descriptors
typedef void* CATPathDescriptorH;

/** 
 * This class of services is used to retrieve information to put on a path from a specs modeler declaration
 * It is also intended for briefcase and 3DXML software components
 */

class ExportedByCATLifSpecs CATPathTypeDescriptorDictionary
{
public:


	/**
	 * Service made for specs modeler for new declarations (that include the path type)
	 * Objective is to produce the persistent information to be stored on a path created from a new tk_external
	 * @param iPathTypeName: name of the pathtype declared in OSM.feat
	 * @param oPathTypeName : name of the path type to be stored 
	 * @param oRoleName : value to be put in the role attribute. It is blank
	 * @param oCategoryName : value to be put in the category attribute. It is blank
   * Basically, this service is now completely useless
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded
   *    <li>E_INVALIDARG   iPathTypeName empty or not recognized by dictionary or SemanticRelationName empty or not recognized by dictionary.</li>
   *    </ul>
   */
    static HRESULT ProducePathCharacteristics ( const CATUnicodeString &iPathTypeName,
												CATUnicodeString &oPathTypeName,
												CATUnicodeString &oRoleName,
												CATUnicodeString &oCategoryName);

	/**
	 * Service made for specs modeler for legacy definitions that still relied on role and category
	 * Objective is to produce the persistent information to be stored on a path created from a tk_external
	 * @param iRoleName : correspond to the role defined in OSM.feat
	 * @param iCategoryName : correspond to the category defined in OSM.feat	
	 * @param oPathTypeName : name of the path type (that will be RoleName_CategoryName)
	 * @param oRoleName : value to be put in the role attribute (that will depend on UNICORN_ROLE_REPLACED variable)
	 * @param oCategoryName : value to be put in the category attribute (that will depend on UNICORN_ROLE_REPLACED variable)
     * @return
     *    <ul>
     *    <li>S_OK     Operation succeeded
     *    <li>E_INVALIDARG   iRoleName empty or not recognized by dictionary or iCategoryName empty or not recognized by dictionary.</li>
     *    </ul>
     */
    static HRESULT ProducePathCharacteristics_Legacy (	const CATUnicodeString &iRoleName,
														const CATUnicodeString &iCategoryName,
														CATUnicodeString &oPathTypeName,
														CATUnicodeString &oRoleName,
														CATUnicodeString &oCategoryName);
	/**
	 * Service made for specs modeler for all models. Will combine the two previous methods
	 * Objective is to produce the persistent information to be put in session created from a tk_external
	 * @param oPathTypeName : name of the path type. Can be empty
	 * @param iRoleName : correspond to the role defined in OSM.feat. Can be empty
	 * @param iCategoryName : correspond to the category defined in OSM.feat. Can be empty
	 * @param oPathTypeName : name of the path type to have in session (never empty! it will be RoleName_CategoryName))
	 * @param oRoleName : value to be put in the role attribute to have in session. Can be empty if UNICORN_ROLE_REPLACED variable is set)
	 * @param oCategoryName : value to be put in the category attribute. Can be empty if UNICORN_ROLE_REPLACED variable is set)
     * @return
     *    <ul>
     *    <li>S_OK     Operation succeeded
     *    <li>E_INVALIDARG   Bad combination of inputs
     *    </ul>
     */
    static HRESULT ProducePathCharacteristics_AllCases ( const CATUnicodeString &iPathTypeName,
                            const CATUnicodeString &iRoleName,
														const CATUnicodeString &iCategoryName,
														CATUnicodeString &oPathTypeName,
														CATUnicodeString &oRoleName,
														CATUnicodeString &oCategoryName);


	/**
	 * Service made for briefcase import for legacy paths (without path type)
	 * Objective is to produce the persistent information to be stored on the path to import coming from briefcase
	 * @param iAggregatorTypeName : correspond to the type of the aggregator of the path
	 * @param iRoleName : correspond to the role defined in the briefcase
	 * @param iCategoryName : correspond to the category defined in the briefcase
	 * @param oPathTypeName : name of the path type
	 * @param oRoleName : value to be put in the role attribute
	 * @param oCategoryName : value to be put in the category attribute
     * @return
     *    <ul>
     *    <li>S_OK     Operation succeeded (effective migration)
     *    <li>S_FALSE  Operation succeeded (no migration: role & category unchanged, returned in output)
     *    <li>E_INVALIDARG   iRoleName empty or not recognized by dictionary or iCategoryName empty or not recognized by dictionary. Or aggregator Type name does not exist </li>
     *    </ul>
     */
    static HRESULT MigratePathCharacteristics        (	const CATUnicodeString &iAggregatorTypeName,
														                            const CATUnicodeString &iRoleName,
														                            const CATUnicodeString &iCategoryName,
														                            CATUnicodeString &oPathTypeName,
														                            CATUnicodeString &oRoleName,
														                            CATUnicodeString &oCategoryName);

  /** 
   * Method to retrieve a path type per its name. For example, ClassA.Rel1 for local paths or Role_Categorie or PathTypeName2 for global paths 
   */
  static CATIPathTypeDescriptor_var FindPathType (const CATUnicodeString &iPathTypeName);

														
  static CATUnicodeString SeparatorUsed ();

private:
	
	CATPathTypeDescriptorDictionary();	
	CATPathTypeDescriptorDictionary(const CATPathTypeDescriptorDictionary &);	
	CATPathTypeDescriptorDictionary & operator=(const CATPathTypeDescriptorDictionary &);
	~CATPathTypeDescriptorDictionary();	


};

//-------------------------------------------------------------------------

#endif
