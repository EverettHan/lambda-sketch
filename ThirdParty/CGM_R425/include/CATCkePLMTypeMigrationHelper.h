// COPYRIGHT DASSAULT SYSTEMES  2012
//=============================================================================
//

#ifndef CATCkePLMTypeMigrationHelper_H
#define CATCkePLMTypeMigrationHelper_H

#include "PLMDictionaryNavServices.h"
#include "CATIType.h"
#include "CATBoolean.h" 
#include "CATUnicodeString.h"
#include "CATListValCATIType.h"
#include "CATCkeTypeQualification.h"
#include "CATListOfCATUnicodeString.h"
#include "CATCkeTypeProtectedServices.h"

 
class CATCkeMigrationCase;

// Cas Fastener
#define CATCKE_INPUTDATA_CORRUPTED 104

// This class is to be used when you want to migrate an object of a given type
// From V1 to V2 (ex: briefcase)
// From V2 to V1 (ex: briefcase)
// From V2 to pseudo V1 (ex: DBDI)
//
// Usually, if the type is in V1 and the target is V1, nothing needs to be done
// Usually, if the type is in V2 and the target is V2, nothing needs to be done
//
// The objective of the helper is to answer to the following questions
// 1) Do I need to migrate the data? If not, briefcase or DBDI can generate the same data
// 2) If a migration needs to be done there are several cases
//     2.1) The only change may be to choose a different type (to create an object of this type instead of an object of the same type)
//         2.1.1) But in some cases, we cannot deduce the target type only with the information provided in input (the discipline and the origin type)
//         2.1.2) Sometimes, we need to read an attribute value on an extension to deduce the type
//         2.1.3) Sometimes, we need to list the extensions existing on the origin objet
//     2.2) There may be a need to add a set of extensions, or the need to remove a set of extensions: when extensions are removed, the attributes will be positioned on the type
//     2.3) There may be a need to change the content of the V_discipline attribute
//	   2.4)	There finally may need to valuate an attribute of an extension with a value depending on the type
//
// The pseudo code used to migrate the data should be something like this
// 
// Imagine that what you want to migrate is an object of type "Type1"
//      - Type1 could be a custo type in V1, a modeler type, a discipline or a specialisation type
// with a value of V_discipline attribute "Discipline1" (that can be equal to "")
// with one extension of type "ExtensionType2"
//      - ExtensionType1 could be an applicative extension (modeler level in V1, or discipline in V2 or specialised in V2)
//      or a Deployment extension in V2 or a customer Extension in V2
//
// You want to migrate it and you want to migrate it to a V1 repository, a V2 repository or a V2 repository but in DBDI mode
//      - Constraints linked to DBDI are that we must still create applicative subtypes as extensions (so like in V1) and we cannot have specialization types
//
//
// First, you create a CATCkePLMTypeMigrationHelper myHelperForType with the "Type1" and the "Discipline1" and the target repository. You may access it from a CATCkePLMTypeMigrationManager
//
// if (myHelperForType.MigrationNeeded()==FALSE)
//    // Then there is no migration at all for this type
// else
// {
//    // The type of the object must change: but do we need to read an attribute value to compute it ? and do we need the list of extensions
//	  //
//    if (myHelperForType.TypeMigrationRequiresExtensionList()
//    {
//       // We read the list of extensions. If not, the list passed to the following method will be empty
//       if (myHelperForType.TypeMigrationRequiresAttributeValue(oExtensionName,oAttributeName,oAttributeType,piExtensionList) == FALSE)
//       {
//          // We're in a simple case, where we have all the information to compute the targeted type. We compute it
//          myHelperForType.TargetedType (oTargetedType);
//       }
//       else 
//       { 
//          // To determine the type, we need to read an attribute on an extension of the object. 
//          // The previous call has retrieved the name of the attribute, the name of the extension and the type of the attribute (string, int, enum)
//          // We can read the attribute value: note that an enum is read as an integer
//
//          // On lit la liste des extensions que l'on passe au call suivant
//          myHelperForType.DeduceTargetedType(value,oTargetedType,piExtensionList); // value is the integer or the string read
//	     }
//    }
//
//    // At this stage, we know the type of the object we need to create
//    // But there are potential other migration to operate
//    
//    // We may need to suppress some merged extensions
//    if (myHelperForType.ExtensionsToSuppress(listOfExtensions))
//    {
//      // We must loop on those extensions
//      // all the attribute values of the extensions must be mapped on the equivalent attributes on the object type
//      // then we can forget those extensions in the migration process
//    }
//    // We may need to add merged extensions
//    else if (myHelperForType.ExtensionsToAdd(listOfExtensions))
//    {
//      // We must loop on those extensions
//      // all the attribute values of the extensions must be valuated with the equivalent attributes existing on the object type
//    }
//
//    // We may also need to change the discipline attribute
//    if (myHelperForType.DisciplineAttributeIsChanged(newAttributeValue)
//    {
//       // We change the discipline
//    }
//      
//    // Finally, we may need to valuate the sub type attribute
//    if (myHelperForType.MigrationRequiresSubTypeAttributeValuation(oExtensionName,oAttributeName,oAttributeType))
//    {
//       // Depending on the attribute type, we retrieve the value
//       myHelperForType.GetAttributeValueAsString(value);
//         
//       // We use this value to valuate the attribute on the extension
//    }
// 
//
// Second, you create a CATCkePLMTypeMigrationHelper myHelperForExtension with the "ExtensionType1" and the "Discipline1" and the target repository
// if (myHelperForExtension.MigrationNeeded()==FALSE)
//    // Then there is no migration at all for this extension
// else if (myHelperForExtension.ExtensionIsSuppressed())
//    // In the migration process, this extension must be ignored
// else
// {
//    // The type of the extension must change
//    if (myHelperForExtension.TypeMigrationRequiresAttributeValue(oExtensionName,oAttributeName,oAttributeType) == FALSE)
//    {
//       // We're in a simple case, where we have all the information to compute the targeted type of the extension
//       myHelperForExtension.TargetedType (oTargetedType);
//    }
//    else 
//    { 
//       // To determine the type, we need to read an attribute on an extension of the object. 
//       // The previous call has retrieved the name of the attribute, the name of the extension and the type of the attribute (string, int, enum)
//       
//       // We read it: note that an enum is read as an integer
//       myHelperForExtension.DeduceTargetedType(value,oTargetedType); // value is the integer or the string read
//	  }
//
//    // At the stage, we know the type of the extension we need to create
//    // But there are potential other migration to operate
//    
//    // We may need to suppress some merged extensions
//    if (myHelperForExtension.ExtensionsToSuppress(listOfExtensions))
//    {
//      // We must loop on those extensions
//      // all the attribute values of the extensions must be mapped on the equivalent attributes on the object type
//      // then we can forget those extensions in the migration process
//    }
//    // We may need to add merged extensions
//    else if (myHelperForExtension.ExtensionsToAdd(listOfExtensions))
//    {
//      // We must loop on those extensions
//      // all the attribute values of the extensions must be valuated with the equivalent attributes existing on the object type
//      
//      // Finally, we may need to valuate the sub type attribute
//      if (myHelperForExtension.MigrationRequiresSubTypeAttributeValuation(oExtensionName,oAttributeName,oAttributeType))
//      {
//         // Depending on the attribute type, we retrieve the value
//         myHelperForExtension.GetAttributeValueAsString(value);
//         
//         // We use this value to valuate the attribute on the extension
//      }
//    }
// 
//


// 
//
class ExportedByPLMDictionaryNavServices CATCkePLMTypeMigrationHelper
{
public:

	// objective is to create an object in V1 typing system, in V2 typing system, in V2 but in DBDI context
	enum Target { V1, V2, DBDI };

	// Type of the attribute that contains the sub type
	enum SubType_Attribute_Type { String, Integer, Enumere, None };

	// Constructor / Destructor
	// A noter que ce migration helper peut etre construit pour des types primaires ou des types secondaires (extension)
	// Comme on part d'un objet, cet objet a un type et une valeur de V_Discipline. Quand on souhaite migrer le type, on passe ces deux infos
	// Lorsqu'on souhaite traduire une extension, on dispose de son type en entree. Il faut aussi passer la discipline auquel cette extension peut etre correllee
	CATCkePLMTypeMigrationHelper (const CATIType_var &iInputType,const CATUnicodeString &iDisciplineAttributeValue,Target iTargetRepository);
	~CATCkePLMTypeMigrationHelper ();

	// Enfin, dernier cas de figure. Si la discipline representait un type secondaire, on peut solliciter ce service sans type
	CATCkePLMTypeMigrationHelper (const CATUnicodeString &iDisciplineAttributeValue,Target iTargetRepository);

	// Dans le cas de briefcase, on peut savoir qu'on a un type V1 (dont on a potentiellement perdu le custo type) et on connait en fait le type qu'on veut en V2
	// On est donc surtout interesse de savoir si on doit faire des transformations
	CATCkePLMTypeMigrationHelper (const CATIType_var  &iTargetType);


	// Indicates if the migration helper has been built with an invalid input. In this case, you must ignore this migration
	CATBoolean IsInvalid() const; 

	// Indicates if this migration helper is for a type or an extension
	CATBoolean IsAnExtension () const;

	// Indicates if there is a need for a migration
	// If answer is no, then the type to create at the end is the same as the type in input
	CATBoolean MigrationNeeded () const;

	//-----------------------------------------------------------
	// If a migration is needed: we need to ask some questions
	//-----------------------------------------------------------

	// Indicates if the extension must be suppressed in the process (if we built the migration helper on an extension)
	CATBoolean ExtensionIsSuppressed () const;

	// Indicates if the discipline is altered during the migration process. If it is the case, oDisciplineAttribute contains the target value
	CATBoolean DisciplineAttributeIsChanged (CATUnicodeString &oDisciplineAttribute) const;

	// If a migration is needed, do I need more information to compute the target type ?

	// I may need the list of extensions
	CATBoolean TypeMigrationRequiresExtensionList () const;
	// Makes sense only when target is V1
	HRESULT ComputeExtensionRequestedFromType (CATIType_var &oTypeExtension) const;

	// I may need the value of an attribute (and if previous method answered yes, I need to pass the list of extensions to find it)
	CATBoolean TypeMigrationRequiresAttributeValue (CATUnicodeString &oExtensionName,CATUnicodeString &oAttributeName,SubType_Attribute_Type &oAttributeType,const CATListOfCATUnicodeString *piExtensionList=NULL) const;

	// Returns the targeted type: fails if we need the computation of an attribute to determine the targeted type
	HRESULT TargetedType (CATIType_var &oTargetedType) const;

	// Returns the targeted type deduced from an attribute value defined as a string and the list of extensions if necessary
	// May return E_FAIL due to the fact that the migration is impossible (fastener case)
	HRESULT DeduceTargetedType (const CATUnicodeString &iAttributeValue,CATIType_var &oTargetedType,const CATListOfCATUnicodeString *piExtensionList=NULL) const;

	// Returns the targeted type deduced from an attribute value defined as an integer (works for enumere case) and the list of extensions if necessary
	HRESULT DeduceTargetedType (int iAttributeValue,CATIType_var &oTargetedType,const CATListOfCATUnicodeString *piExtensionList=NULL) const;

	// I may need the value of an attribute (and if previous method answered yes, I need to pass the list of extensions to find it)
	CATBoolean ExtensionTypeMigrationRequiresAttributeValue (CATUnicodeString &oExtensionName,CATUnicodeString &oAttributeName,SubType_Attribute_Type &oAttributeType,const CATListOfCATUnicodeString *piExtensionList=NULL) const;

		// In case the extension is not found, briefcase will provide the existing extensions on the object, and we will verify if the extensions available
	    // Are potentially correct
	    // This method has been introduced to support V1 objects (like Product) that would have been extended with a V2 extension (ex: ToolDevice)
	    // This can happen in hybrid mode
	    CATBoolean IsTargetExtensionAlreadyThere (const CATListValCATIType_var &iExtensions);

	// Returns the targeted type deduced from an attribute value defined as a string and the list of extensions if necessary
	HRESULT DeduceTargetedExtensionType (const CATUnicodeString &iAttributeValue,CATIType_var &oTargetedType,const CATListOfCATUnicodeString *piExtensionList=NULL) const;

	// Returns the targeted type deduced from an attribute value defined as an integer (works for enumere case) and the list of extensions if necessary
	HRESULT DeduceTargetedExtensionType (int iAttributeValue,CATIType_var &oTargetedType,const CATListOfCATUnicodeString *piExtensionList=NULL) const;

	// Do we need to suppress extensions: in this case, we will have to report the attributes of the extensions on the type
	// Sometimes to know the list of extensions to suppress, the discipline is not sufficient. This is the case where TypeMigrationRequiresExtensionList
	// In this case, you need to deduce the targeted type and pass it to this method
	CATBoolean ExtensionsToSuppress (CATLISTV(CATIType_var) &oListOfExtensionsToSuppress,const CATIType_var &targetedType = NULL_var) const;

	// Do we need to add extensions
	CATBoolean ExtensionsToAdd (CATLISTV(CATIType_var) &oListOfExtensionsToAdd) const;
	
	// Do we need to valuate a sub type attribute 
	CATBoolean MigrationRequiresSubTypeAttributeValuation (CATUnicodeString &oExtensionName,CATUnicodeString &oAttributeName,SubType_Attribute_Type &oAttributeType) const;
	
	// If yes, we can retrieve the value to set
	HRESULT GetAttributeValueAsString (CATUnicodeString &oAttributeValue) const;
	HRESULT GetAttributeValueAsInteger(int &oAttributeValue) const;




	// Services for applications (not for briefcase) to verify that current implementation of migration services are OK
	// Computes from a V2 type, the extension name, attribute name, attribute type, and the value corresponding to the sub type
	// Returns false, if no attribute
	static HRESULT RetrieveSubTypeAttributeFromType (const CATIType_var &iType,CATUnicodeString &oExtensionName,CATUnicodeString &oAttributeName,SubType_Attribute_Type &oAttributeType,CATUnicodeString &oAttributeValueAsString,int &oAttributeValue);
	
	// Computes from a V1 type, a discipline, the extension name, the attribute name, the attribute type, and the value corresponding to the sub type, the final type in V2
	// Returns false, if no attribute
	static HRESULT ComputeSubTypeFromAttributeValue (const CATIType_var &iType,const CATUnicodeString &iDiscipline,
													 const CATUnicodeString &oExtensionName,
													 const CATUnicodeString &oAttributeName,
													 const CATListOfCATUnicodeString *piExtensionList,
													 const CATUnicodeString &oAttributeValueAsString,
													 int oAttributeValue,
													 CATIType_var &oTargetType);

	// Indicates if there is a conflict between two methods that need to be solved by managing priorities
	// Returns 0 if no priority/no conflict
	// Returns 1 for higher priority, 2 for lower priority
	int GetPriority () const;

private:
	
	//---------------------------------------------------
	// Les entrées 
	//---------------------------------------------------
	Target					_target;						// targeted typing system

	// Information computed concerning the input type
	CATIType_var			_inputType;						// type in input (coming from briefcase or DBDI): may be NULL, in case of an extension
	CATBoolean              _pureSecondaryDiscipline;       // Called with second constructor: we are trying to migrate an extension
	CATBoolean              _isInvalid;                     // Indicates that we are trying to solve an invalid migration pattern

		// Information deduite directement du type
		CATCkeTypeQualification::Nature _Nature;                // Nature of the input type
		CATCkeTypeQualification::Origin _Origin;                // Origin of the input type

	// valeur de l'attribut discipline normalement en entree mais peut etre modifiee sur le process de migration le necessite
	CATUnicodeString        _disciplineAttributeValue;      // value of the attribute V_Discipline
	
		// Informations en provenance de la discipline
		CATIType_var			_disciplineType;				// type computed from the discipline
		//CATIType_var			_PrimaryType;					// type in input (coming from briefcase or DBDI): custo type is skipped.
		CATBoolean				_disciplinePrimary;				// The discipline is a primary discipline (as opposed to an extension)



	// Information deduite de la discipline ou du type d'entree
	CATIType_var            _applicativeTypeTarget;         // Type cible applicatif: si le type en entree etait V2, c'est le meme. Sinon, il est plutot issu de la discipline, ou du calcul a partir de l'attribut "SubType"
	CATIType_var            _TypeTarget;					// Type cible effectif: qui pourra etre un type custo si on vise du V1 ou ce type applicatif

	// liste d'extensions de l'applicative target type
	CATLISTV(CATIType_var)  _ListOfMergedExtensions;		// list of merged extensions for the type in input

	// Nature of the migration
	CATBoolean				_RequiresMigration;							// Indicates if there is a need for a migration (changing type)
	CATBoolean              _RequiresDisciplineAttributeToChange;       // we must change the V_discipline attribute value
	CATBoolean				_RequiresDeletion;							// Indicates if there is a need for a suppression of the extension in input
	CATBoolean				_RequiresSuppressionOfMergedExtension;		// Indicates if there is a need for suppressing the list of merged extension
	CATBoolean				_RequiresAdditionOfMergedExtension;			// Indicates if there is a need for adding the list of merged extension
	CATBoolean              _RequiresSubTypeManagement;					// Do we need to take care of subtype or not
	CATBoolean              _SubTypeComputed;							// Is sub type computed from attribute. If it is not the case and if _RequiresSubTypeManagement, then we will need to valuate the SubType attribute
	CATCkeMigrationCase*    _migrationCase;								// Case of migration used to manage the sub types

	void Compute(const CATUnicodeString &iDiscipline); // Internal method that computes all the deduced data members of the class
	void ComputeV1ToV2WithPrecomputedV2();			   // Internal method that computes all the deduced data members of the class
		void InvestigateSubTypeManagement ();          // Method used to verify if we need to manage sub type attributes
		void InvestigateDisciplineChange ();           // Method used to verify if we need to change the V_Discipline attribute

    // Method used to find the sub type from attribute Sub type value
	HRESULT FindSubType (const CATUnicodeString &iAttributeAsString,int iAttributeAsInteger,CATIType_var &oTargetedType,const CATListOfCATUnicodeString *piExtensionList=NULL) const;

	// Computes the V1 type from the modeler type
	HRESULT ProduceV1Type (CATIType_var &oTargetedType);

};
#endif


