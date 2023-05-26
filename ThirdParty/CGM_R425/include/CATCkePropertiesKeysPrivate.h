#ifndef CATCkePropertiesKeysPrivate_h
#define CATCkePropertiesKeysPrivate_h

// COPYRIGHT Dassault Systemes 2010
#include <stddef.h>
#include "CATBoolean.h"
#include "PLMDictionaryInterfaces.h"

class CATUnicodeString;


//----------------------------------------------------------------
// This class regroups definition of keywords and properties names in metadata that can be used in dictionary software to provide higher level services
//
// This class is to be used by dictionary software only
//----------------------------------------------------------------

class ExportedByPLMDictionaryInterfaces CATCkePropertiesKeysPrivate
{
	public:

		//-----------------------------------------------------------------------------------------------
		// Contains the names of the keywords (dynamic properties) defined in metadata
		// and that has a meaning for us (Knowledge private team)
		//-----------------------------------------------------------------------------------------------

		// Used by "new" keyword in Knowledge language to determine the type of element created (when it is an instance of a reference)
		// Not inherited
		// No dedicated method to access this information (used internally, read as a property)
		static const CATUnicodeString KweNew_ReturnedType;

		// String containing the life cycle operations: valid values are true and false
		// Access to life cycle operations availability in  CATCkePLMObjectOperationsServices::SupportsOperation
		// Inherited
		static const CATUnicodeString LCO_NewVersion				;
		static const CATUnicodeString LCO_ChangeMaturity			;
		static const CATUnicodeString LCO_Delete				;
		static const CATUnicodeString LCO_LockUnlock				;
		static const CATUnicodeString LCO_TransferOwnership		;
		static const CATUnicodeString LCO_Duplicate				;
		static const CATUnicodeString LCO_EditProperties			;
		static const CATUnicodeString LCO_SaveAsNew			;
		static const CATUnicodeString LCO_NewMinorRevision		;
		static const CATUnicodeString LCO_Evolution			;
		static const CATUnicodeString LCO_Iteration				;
		static const CATUnicodeString LCO_ManageAccess		;
		static const CATUnicodeString LCO_ShareBetweenProjects	;
		static const CATUnicodeString LCO_ChangeCollaborativeSpace	;

		// String containing the property indicating when Life cycle operations are made available on a type based on packaging
		// Available with CATCkePLMObjectOperationsServices::LifeCycleOperationsAvailable
		// Inherited
    //		static const CATUnicodeString LCO_Packaging;
			//static const CATUnicodeString LCO_Packaging_Innovation;

		// String containing the properties indicating the data features supported by a type
		// No service yet
		// Inherited
    // Yes and No are possible values
		static const CATUnicodeString DataSupport_CarryPointers    ;
    static const CATUnicodeString DataSupport_CarryStreams       ;
  		static const CATUnicodeString DataSupport_CarryStreams_One       ;
  		static const CATUnicodeString DataSupport_CarryStreams_One_At_Least       ;
  		static const CATUnicodeString DataSupport_CarryStreams_One_Or_Zero       ;
		static const CATUnicodeString DataSupport_AggregatesComponents;
		static const CATUnicodeString DataSupport_IsSynchronizable  ;
		static const CATUnicodeString DataSupport_UniqueNamingRule  ;

		// String containing the icon name.
		// Retrieved by CATCkeTypeProtectedServices::GetIconName
		// Inherited
		static const CATUnicodeString IconName			 ;
		static const CATUnicodeString TroisDIconName			;

		// String containing the information that a type is Searchable: valid values are true and false
		// Retrieved via CATCkeTypeServices::GetSearchableStatus
		// Not inherited
		static const CATUnicodeString Searchable			  ;

		// String containing the information that a type is DMC Derivable (meaningful in V1 only)
		// Retrieved via CATCkeTypeServices::GetSearchableStatus
		// Not inherited
		static const CATUnicodeString DMCDerivable		 ;

		// String containing the information that a type is Newable: valid values are No, New, Insert, All with a suffix _CAA
		// Retrieved via CATCkePLMObjectOperationsServices::CanBeCreatedByPLMNew
		// Not inherited
		static const CATUnicodeString Newable			;
		static const CATUnicodeString Newable_No		;
		static const CATUnicodeString Newable_New		;
		static const CATUnicodeString Newable_Insert    ;
		static const CATUnicodeString Newable_All	;
		static const CATUnicodeString Newable_CAA		;
		static const CATUnicodeString Newable_Offline	 ;

		// String containing the predefined query attributes
		// No services yet / OBSOLETE / TO BE SUPPRESSED
		static const CATUnicodeString PQ_Attributes		 ;

		// String containing the type of the occurrence for a given type
		// Retrieved via CATKweDicoExtension::RetrieveOccurrenceFromExtension
		// Inherited
		static const CATUnicodeString OccurrenceType		;

		// Example: For 3D Part, we define a type that is created by assembling several PLM Types
		// This property contains the list of those PLM types separated by comma
		// Retrieved via CATCkeTypeProtectedServices::AccessListOfAggregatedTypes
		// Not inherited
		static const CATUnicodeString ComposedSubtypes      ;

		// String containing the type of the extension related to a discipline (that goes with it)
		// A related extension is always created with the discipline
		// A merged extension is created with the discipline in typing V1 but without the extension in typing V2
		// Retrieved via CATCkeTypeProtectedServices::RelatedExtensions
		// Inherited
		static const CATUnicodeString RelatedExtensionType	;
		static const CATUnicodeString MergedExtensionType		;

		// Tag on object types that determines their nature
		// Service at CATPLMType level only
		// Inherited
		static const CATUnicodeString ObjectNature	 ;
		// Can live independantly: can be created, versioned, has a lifecycle, has a owner
		static const CATUnicodeString ObjectNature_Independant	   ;
		// Is considered as a sub part of its aggregator: no independant life. Cannot be created without aggregator
		// Copied with its aggregator, versioned with it, deleted with it
		// No different owner, no different security
		static const CATUnicodeString ObjectNature_SubComponent     ;
		// Aggregated: Cannot be created without aggregator. But has an independant ownership, security, maturity.
		// Copied with its aggregator, versioned with it, deleted with it
		static const CATUnicodeString ObjectNature_Aggregated     ;

    static const CATUnicodeString ObjectNature_MayBeAggregated;

		// Instance: Cannot be created without aggregator. But has an independant ownership, security. Has no maturity.
		// Copied with its aggregator, versioned with it, deleted with it
		static const CATUnicodeString ObjectNature_Instance          ;
		// No: Is not an object
		static const CATUnicodeString ObjectNature_No         ;

		// Tag on relationship types that determines the nature of the relation
		// Note that if a relationship is seen as an object, it will have an object nature also
		// Service at CATPLMType level only
		// Inherited
		static const CATUnicodeString RelationNature	 ;
			// Models an aggregation source-target: propagates versioning, cloning and delete to the target object
			// The target object cannot be shared
			// Is a relationship used for expand (and representing children)
			// Cannot load the source without loading the target
			static const CATUnicodeString RelationNature_Aggregation	;
			// Models an instanciation source-target: supports configuration
			// The target object to can be shared
			// Is a relationship used for expand (and representing children)
			// Cannot load the relationship without loading the target
			static const CATUnicodeString RelationNature_Instanciation  ;
			// Models a structure source-target
			// The target can be shared
			// Is a relationship used for expand (and representing children)
			// Cannot load the relationship without loading the target
			static const CATUnicodeString RelationNature_Structure    ;
			// Models a simple reference/pointer
			// The target object can be shared of course
			// Is not a relationship used for expand (and representing children)
			// Can load the relationship without loading the target. But the source must be loaded
			static const CATUnicodeString RelationNature_Pointer   	; // Default value
			// Models a simple reference
			// The target object can be shared of course
			// Is not a relationship used for expand (and representing children)
			// Can load the relationship without loading the target nor the source
			static const CATUnicodeString RelationNature_Association    ;
			// Models a link to an aggregator (from its aggregated)
			// Cannot load the relationship without loading the target
			static const CATUnicodeString RelationNature_Aggregator   ;

			// No: Is not a relation
			static const CATUnicodeString RelationNature_No         ;

		// String containing the support of configuration (possible values: Yes, No)
		// Retrieved via CATCkePLMTypeAppliServices::SupportsConfiguration
		// Inherited
		static const CATUnicodeString Configurable			;

		// String containing the support of filters by configuration (possible values: Yes, No)
		// Retrieved via CATCkePLMTypeAppliServices::SupportsConfiguration
		// Inherited
		static const CATUnicodeString Filtrable				;

		// String containing the support of change management (possible values : Yes No)
		// Retrieved by CATCkePLMTypeAppliServices::SupportsChangeManagement
		static const CATUnicodeString ChangeManagementSupport  ;

		// String containing information about how to present children in the tree: it contains a list of strings separated by ;
		// A;B;C;D
		// A is the name of the attribute that is found on the children that enables to operate a sort.
		// B, C, D are the type of children that must be shown in the following order (first the B, then the C)
		// Retrieved by CATCkePLMTypeAppliServices::SortingChildrenInTreeMethodology
		// Inherited
		static const CATUnicodeString SortingChildrenInTree  ;

		// V6 Exportable: indicates if an attribute will by default be exportable in briefcase and X-PDM (possible values: Yes / No)
    // Is meaningful also on extensions
		// No service yet
		static const CATUnicodeString V6Exportable  ;

		// Properties/keywords defined on SemanticRelation
		//------------------------------------------------------
		// Sensitivity to synchronization of the pointed
		// Retrieved via CATIPathTypeDescriptor
		// Inherited
		static const CATUnicodeString SynchroSensitivity  ;
			// Different values: can be None
			// Last: sensitive only to the last element of the path
			static const CATUnicodeString SynchroSensitivity_Last  ;
			// Last: sensitive to all elements of the path plus the last element
			static const CATUnicodeString SynchroSensitivity_PathAndLast  ;

		// Adaptative to Minor: value Yes: the pointer will reconnect to last minor in session / No, the pointer will stay on its minor
		// Retrieved via CATIPathTypeDescriptor
		// Inherited
		static const CATUnicodeString AdaptativeToMinor  ;

		// Reroute On effective change: value Yes: the pointing must be duplicated when the pointer is split due to effectivity change. No pointer will stay the same
		// Retrieved via CATIPathTypeDescriptor
		// Inherited
		static const CATUnicodeString RerouteOnEffectivityChange  ;

		// Protection: indicates which software layer is in charge of modifying the path
		static const CATUnicodeString Protection  ;
			static const CATUnicodeString Protection_Internal  ;

		// Orientation: value Neutral / In / Out / InOut
		// Retrieved via CATIPathTypeDescriptor
		// Inherited
		static const CATUnicodeString Orientation  ;
			// Different values: can be Neutral, In, InOut, Out
			static const CATUnicodeString Orientation_Neutral  ;
			static const CATUnicodeString Orientation_In  ;
			static const CATUnicodeString Orientation_Out  ;
			static const CATUnicodeString Orientation_InOut  ;

		//-----------------------------------------------------------------------------------------------
		// Contains the names of the dynamic properties that are only available at Knowledge level (no view as a property in metadata)
		//-----------------------------------------------------------------------------------------------

		// Name to be filled in the V_Discipline attribute
		// Correspondance between type name and attribute name is provided in CATCkeTypeServices::GetDisciplineAttribute
		// Used to use another name to valuate the V_Discipline attribute instead of the type name (ex: Drafting instead of Drawing).
		// Retrieved by CATCkeTypeProtectedServices::GetDisciplineAttribute
		// Inherited
		static const CATUnicodeString DisciplineAttributeValue ;

		// Redirection for a type to the type that will be used as a discipline
		// Retrieved by CATCkeTypeProtectedServices::GetDisciplineAttribute
		// Inherited
		static const CATUnicodeString TypeForDisciplineValuation ;

		// Redirection for a type to the type that will group types logically
		// Retrieved by CATCkeTypeServices::FindTypeToOperateLicensingTest
		static const CATUnicodeString GroupingType;

		// Integer containing the core type
		// Retrieved by CATITypeExtension::GetCoreType
		// Not inherited but Knowledge projection should ensure that it is project with inheritance
		static const CATUnicodeString CoreType				;

		// List of types that can be aggregated under a type (separated by ;)
		// Retrieved by CATCkePLMNavServices::ListAggregatableTypesUnderAnObject
		// Inherited
		static const CATUnicodeString AggregatableTypes		;

		// List of types that can be used as a owner/aggregator of a given type (separated by ;)
		// Retrieved by CATCkePLMNavServices::TypeCanBeAggregated
		// Inherited
		static const CATUnicodeString OwnerTypes		;

		// List of types that can be used as a owner/aggregator of an instance of a given type (separated by ;)
		// Retrieved by CATCkePLMNavServices::TypeCanBeInstantiatedUnder
		// Inherited
		static const CATUnicodeString InstantiationOwnerTypes		;

		// Instance type to be used when instantiating a reference
		// Retrieved by CATCkeTypeServices::RetrieveInstantiationType
		// Inherited
		static const CATUnicodeString InstantiationType		;

		//-----------------------------------------------------------------------------------------------
		// Contains the names of the dynamic properties defined in metadata that are not available as a property at Knowledge level
		//-----------------------------------------------------------------------------------------------

		// Instanciation method
		// Consequence is that the type implements CATIInstanciation and delegates to CATIDelegateInstanciation interface
		// implemented on a class which name is the value of this property
		static const CATUnicodeString KweNew_InstanciationMethod ;


		// Value of properties shared by several elements
		static const CATUnicodeString Value_true;
		static const CATUnicodeString Value_false;

		// Used when a type or a list of type is provided to express that none is accepted
		static const CATUnicodeString Value_None;

		// Unit to use for manipulating a given attribute
		static const CATUnicodeString ManipulationUnit ;

		// 6W
		static const CATUnicodeString Quadrant ;

		// Abbreviation
		static const CATUnicodeString Abbreviation ;

		// C++ class that controls the list of authorized values of an attribute
		static const CATUnicodeString AttributeController ;

		// Property on RelationshipType to invert the direction (from-to)
		static const CATUnicodeString RelationDirection;
			static const CATUnicodeString RelationDirection_Normal;		// Default value
			static const CATUnicodeString RelationDirection_Inverted;	// Inverted relation

		// Automatic association for a deployment extension
		static const CATUnicodeString AutomaticAssociation ;

		// Indicates if the type is proposed in data set up application
		static const CATUnicodeString ProposedInDataSetup  ;


		// Indicates that an attribute is multiline (or not). It is a boolean
		static const CATUnicodeString Multiline  ;
    
		// Indicates that an attribute can be written only once. It is a boolean
		static const CATUnicodeString CanBeWrittenOnlyOnce  ;
			static const CATUnicodeString CanBeWrittenOnlyOnce_AtCreation;		// set at creation only
			static const CATUnicodeString CanBeWrittenOnlyOnce_Later;		// can be set after creation
			static const CATUnicodeString CanBeWrittenOnlyOnce_No;		// not written only once

		// Indicates that a type or an extension type is representing a standard object
		static const CATUnicodeString Standard  ;

    // Indicates that a type or an extension type or an attribute is deprecated
		static const CATUnicodeString Deprecated  ;

    // Indicates that 2 objets differentiate depending on attribute value. When computing policy, we must rely on attribute values
    // No dedicated service
		static const CATUnicodeString PolicyChoiceDependsOnAttributeValue  ;

		//-----------------------------------------------------------------------------------------------
		// Services used by the metadata checker
		//-----------------------------------------------------------------------------------------------

		// kind of property: this enum is used for the checker that validates metadata to know what can be found beneath a property
		enum Nature {	ControlledListOfValue =0 , // this property can contain a fixed list values A, B, C
						SingleType =1,             // this property contains a type name
						SingleOccurrenceType =2,   // this property contains an occurrence type name
						ListOfType =3,			   // this property contains a list of type names
						ListOfExtensionType = 4,   // this property contains a list of extension type names
						SingleInternalType = 5};   // this property contains a type that is not public

		// method pointer
		typedef CATBoolean  (*CATCkePropertyChecker) (Nature iNature,const CATUnicodeString &PropertyValue,CATUnicodeString &oMessage);

		// Method to check a property value on a type that exists in a metadata: invoked by checker
		static void    CheckPropertyOnType	  (const CATUnicodeString &PropertyName,const CATUnicodeString &PropertyValue,CATBoolean &oExistence,CATBoolean &oValueValid,CATUnicodeString &oMessage,CATCkePropertyChecker iPropertyChecker = NULL);

		// Method to check a property value on an attribute that exists in a metadata: invoked by checker
		static void    CheckPropertyOnAttribute (const CATUnicodeString &PropertyName,const CATUnicodeString &PropertyValue,CATBoolean &oExistence,CATBoolean &oValueValid);


};
//-----------------------------------------------------------------------------------------------
// Contains the names of the dynamic properties defined in metadata
// and that has a meaning for us (Knowledge private team)
//-----------------------------------------------------------------------------------------------

// Used by "new" keyword in Knowledge language to determine the type of element created (when it is an instance of a reference)
// No dedicated method to access this information (used internally, read as a property)
#define CATCkePropertiesKey_KweNew_ReturnedType   CATCkePropertiesKeysPrivate::KweNew_ReturnedType

// String containing the life cycle operations: valid values are true and false
// Access to life cycle operations availability in  CATCkePLMObjectOperationsServices::SupportsOperation
#define CATCkePropertiesKey_LCO_NewVersion				CATCkePropertiesKeysPrivate::LCO_NewVersion
#define CATCkePropertiesKey_LCO_ChangeMaturity			CATCkePropertiesKeysPrivate::LCO_ChangeMaturity
#define CATCkePropertiesKey_LCO_Delete					CATCkePropertiesKeysPrivate::LCO_Delete
#define CATCkePropertiesKey_LCO_LockUnlock				CATCkePropertiesKeysPrivate::LCO_LockUnlock
#define CATCkePropertiesKey_LCO_TransferOwnership		CATCkePropertiesKeysPrivate::LCO_TransferOwnership
#define CATCkePropertiesKey_LCO_Duplicate				CATCkePropertiesKeysPrivate::LCO_Duplicate
#define CATCkePropertiesKey_LCO_EditProperties			CATCkePropertiesKeysPrivate::LCO_EditProperties
#define CATCkePropertiesKey_LCO_SaveAsNew				CATCkePropertiesKeysPrivate::LCO_SaveAsNew
#define CATCkePropertiesKey_LCO_NewMinorRevision		CATCkePropertiesKeysPrivate::LCO_NewMinorRevision
#define CATCkePropertiesKey_LCO_Evolution				CATCkePropertiesKeysPrivate::LCO_Evolution
#define CATCkePropertiesKey_LCO_Iteration				CATCkePropertiesKeysPrivate::LCO_Iteration
#define CATCkePropertiesKey_LCO_ManageAccess			CATCkePropertiesKeysPrivate::LCO_ManageAccess
#define CATCkePropertiesKey_LCO_ShareBetweenProjects	CATCkePropertiesKeysPrivate::LCO_ShareBetweenProjects

// String containing the properties indicating the data features supported by a type
#define CATCkePropertiesKey_DataSupport_CarryPointers        CATCkePropertiesKeysPrivate::DataSupport_CarryPointers
#define CATCkePropertiesKey_DataSupport_CarryStreams         CATCkePropertiesKeysPrivate::DataSupport_CarryStreams
#define CATCkePropertiesKey_DataSupport_AggregatesComponents CATCkePropertiesKeysPrivate::DataSupport_AggregatesComponents
#define CATCkePropertiesKey_DataSupport_IsSynchronizable     CATCkePropertiesKeysPrivate::DataSupport_IsSynchronizable
#define CATCkePropertiesKey_DataSupport_UniqueNamingRule     CATCkePropertiesKeysPrivate::DataSupport_UniqueNamingRule

// String containing the icon name.
// Retrieved by CATCkeTypeProtectedServices::GetIconName
#define CATCkePropertiesKey_IconName              CATCkePropertiesKeysPrivate::IconName
#define CATCkePropertiesKey_3DIconName            CATCkePropertiesKeysPrivate::TroisDIconName

// String containing the information that a type is Searchable: valid values are true and false
// Retrieved via CATCkeTypeServices::GetSearchableStatus
#define CATCkePropertiesKey_Searchable            CATCkePropertiesKeysPrivate::Searchable

// String containing the information that a type is DMC Derivable (meaningful in V1 only)
// Retrieved via CATCkeTypeServices::GetSearchableStatus
#define CATCkePropertiesKey_DMCDerivable          CATCkePropertiesKeysPrivate::DMCDerivable

// String containing the information that a type is Newable: valid values are No, New, Insert, All with a suffix _CAA
// No services yet
#define CATCkePropertiesKey_Newable               CATCkePropertiesKeysPrivate::Newable
#define CATCkePropertiesValue_Newable_No          CATCkePropertiesKeysPrivate::Newable_No
#define CATCkePropertiesValue_Newable_New         CATCkePropertiesKeysPrivate::Newable_New
#define CATCkePropertiesValue_Newable_Insert      CATCkePropertiesKeysPrivate::Newable_Insert
#define CATCkePropertiesValue_Newable_All         CATCkePropertiesKeysPrivate::Newable_All
#define CATCkePropertiesValue_Newable_CAA         CATCkePropertiesKeysPrivate::Newable_CAA
#define CATCkePropertiesValue_Newable_Offline     CATCkePropertiesKeysPrivate::Newable_Offline

// String containing the predefined query attributes
// No services yet
#define CATCkePropertiesKey_PQ_Attributes         CATCkePropertiesKeysPrivate::PQ_Attributes

// String containing the type of the occurrence for a given type
// No services yet
#define CATCkePropertiesKey_OccurrenceType        CATCkePropertiesKeysPrivate::OccurrenceType

// Example: For 3D Part, we define a type that is created by assembling several PLM Types
// This property contains the list of those PLM types separated by comma
#define CATCkePropertiesKey_ComposedSubtypes      CATCkePropertiesKeysPrivate::ComposedSubtypes

// String containing the type of the extension related to a discipline (that goes with it)
// A related extension is always created with the discipline
// A merged extension is created with the discipline in typing V1 but without the extension in typing V2
// No services yet
#define CATCkePropertiesKey_RelatedExtensionType  CATCkePropertiesKeysPrivate::RelatedExtensionType
#define CATCkePropertiesKey_MergedExtensionType   CATCkePropertiesKeysPrivate::MergedExtensionType

// Tag on object types that determines their nature
// Service at CATPLMType level only
#define CATCkePropertiesKey_ObjectNature                  CATCkePropertiesKeysPrivate::ObjectNature

// Can live independantly: can be created, versioned, has a lifecycle, has a owner
#define CATCkePropertiesKey_ObjectNature_Independant      CATCkePropertiesKeysPrivate::ObjectNature_Independant

// Is considered as a sub part of its aggregator: no independant life. Cannot be created without aggregator
// Copied with its aggregator, versioned with it, deleted with it
// No different owner, no different security
#define CATCkePropertiesKey_ObjectNature_SubComponent     CATCkePropertiesKeysPrivate::ObjectNature_SubComponent

// Aggregated: Cannot be created without aggregator. But has an independant ownership, security, maturity.
// Copied with its aggregator, versioned with it, deleted with it
#define CATCkePropertiesKey_ObjectNature_Aggregated       CATCkePropertiesKeysPrivate::ObjectNature_Aggregated

// if iscomposee == true, then object is Aggregated
// if iscomposee == false, then object is Independant
#define CATCkePropertiesKey_ObjectNature_MayBeAggregated  CATCkePropertiesKeysPrivate::ObjectNature_MayBeAggregated

// Instance: Cannot be created without aggregator. But has an independant ownership, security. Has no maturity.
// Copied with its aggregator, versioned with it, deleted with it
#define CATCkePropertiesKey_ObjectNature_Instance         CATCkePropertiesKeysPrivate::ObjectNature_Instance
// No: Is not an object
#define CATCkePropertiesKey_ObjectNature_No               CATCkePropertiesKeysPrivate::ObjectNature_No

// Tag on relationship types that determines the nature of the relation
// Note that if a relationship is seen as an object, it will have an object nature also
// Service at CATPLMType level only
#define CATCkePropertiesKey_RelationNature    CATCkePropertiesKeysPrivate::RelationNature
// Models an aggregation source-target: propagates versioning, cloning and delete to the target object
// The target object cannot be shared
// Is a relationship used for expand (and representing children)
// Cannot load the source without loading the target
#define CATCkePropertiesKey_RelationNature_Aggregation    CATCkePropertiesKeysPrivate::RelationNature_Aggregation
// Models an instanciation source-target: supports configuration
// The target object to can be shared
// Is a relationship used for expand (and representing children)
// Cannot load the relationship without loading the target
#define CATCkePropertiesKey_RelationNature_Instanciation  CATCkePropertiesKeysPrivate::RelationNature_Instanciation
// Models a structure source-target
// The target can be shared
// Is a relationship used for expand (and representing children)
// Cannot load the relationship without loading the target
#define CATCkePropertiesKey_RelationNature_Structure      CATCkePropertiesKeysPrivate::RelationNature_Structure
// Models a simple reference/pointer
// The target object can be shared of course
// Is not a relationship used for expand (and representing children)
// Can load the relationship without loading the target. But the source must be loaded
#define CATCkePropertiesKey_RelationNature_Pointer   	  CATCkePropertiesKeysPrivate::RelationNature_Pointer // Default value
// Models a simple reference
// The target object can be shared of course
// Is not a relationship used for expand (and representing children)
// Can load the relationship without loading the target nor the source
#define CATCkePropertiesKey_RelationNature_Association    CATCkePropertiesKeysPrivate::RelationNature_Association
// Models a link to an aggregator (from its aggregated)
// Cannot load the relationship without loading the target
#define CATCkePropertiesKey_RelationNature_Aggregator    CATCkePropertiesKeysPrivate::RelationNature_Aggregator

// No: Is not a relation
#define CATCkePropertiesKey_RelationNature_No          CATCkePropertiesKeysPrivate::RelationNature_No

// String containing the support of configuration (possible values: Yes, No)
#define CATCkePropertiesKey_Configurable			 CATCkePropertiesKeysPrivate::Configurable
// String containing the support of filters by configuration (possible values: Yes, No)
#define CATCkePropertiesKey_Filtrable				 CATCkePropertiesKeysPrivate::Filtrable

// String containing the support of change management (possible values : Yes No)
#define CATCkePropertiesKey_ChangeManagementSupport  CATCkePropertiesKeysPrivate::ChangeManagementSupport

// String containing information about how to present children in the tree: it contains a list of strings separated by ;
// A;B;C;D
// A is the name of the attribute that is found on the children that enables to operate a sort.
// B, C, D are the type of children that must be shown in the following order (first the B, then the C)
#define CATCkePropertiesKey_SortingChildrenInTree  CATCkePropertiesKeysPrivate::SortingChildrenInTree

//-----------------------------------------------------------------------------------------------
// Contains the names of the dynamic properties that are only available at Knowledge level (no view as a property in metadata)
//-----------------------------------------------------------------------------------------------

// Name to be filled in the V_Discipline attribute
// Correspondance between type name and attribute name is provided in CATCkeTypeServices::GetDisciplineAttribute
// Used to use another name to valuate the V_Discipline attribute instead of the type name (ex: Drafting instead of Drawing).
#define CATCkePropertiesKey_DisciplineAttributeValue CATCkePropertiesKeysPrivate::DisciplineAttributeValue

// Redirection for a type to the type that will be used as a discipline
#define CATCkePropertiesKey_TypeForDisciplineValuation CATCkePropertiesKeysPrivate::TypeForDisciplineValuation

// Integer containing the core type
// Retrieved by CATITypeExtension::GetCoreType
#define CATCkePropertiesKey_CoreType				 CATCkePropertiesKeysPrivate::CoreType

// List of types that can be aggregated under a type (separated by ;)
#define CATCkePropertiesKey_AggregatableTypes		CATCkePropertiesKeysPrivate::AggregatableTypes

// Instance type to be used when instantiating a reference
#define CATCkePropertiesKey_InstantiationType		CATCkePropertiesKeysPrivate::InstantiationType

//-----------------------------------------------------------------------------------------------
// Contains the names of the dynamic properties defined in metadata that are not available as a property at Knowledge level
//-----------------------------------------------------------------------------------------------

// Instanciation method
// Consequence is that the type implements CATIInstanciation and delegates to CATIDelegateInstanciation interface
// implemented on a class which name is the value of this property
#define CATCkePropertiesKey_KweNew_InstanciationMethod CATCkePropertiesKeysPrivate::KweNew_InstanciationMethod


#define CATCkePropertiesValue_true				 CATCkePropertiesKeysPrivate::Value_true
#define CATCkePropertiesValue_false				 CATCkePropertiesKeysPrivate::Value_false

// Unit to use for manipulating a given attribute
#define CATCkePropertiesKey_ManipulationUnit CATCkePropertiesKeysPrivate::ManipulationUnit




#endif // CATCkePropertiesKeysPrivate_h

