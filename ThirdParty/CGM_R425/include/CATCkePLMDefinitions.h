#ifndef CATCkePLMDefinitions_h
#define CATCkePLMDefinitions_h

// COPYRIGHT Dassault Systemes 2010 
#include <stddef.h>
#include "CATBoolean.h"
#include "CATBaseUnknown.h" // HRESULT
#include "PLMDictionaryInterfaces.h"

class CATUnicodeString;

 


//----------------------------------------------------------------
// This class regroups definition of types & attributes that may be useful for applications and infrastructure layers
// They correspond to core types and core attributes that we will find on all PLM objects (or almost)
//
// It can be used by applications and infrastructure to avoid duplicating these definitions everywhere in the software as hard coded strings
//
// See also
// CATCkeSharedServices::GetAttributeUsedForLogicalName: for accessing attribute name used for naming objects
// CATCkePLMNavPublicServices: for accessing basic attribute names
//----------------------------------------------------------------

class ExportedByPLMDictionaryInterfaces CATCkePLMDefinitions 
{
	public:

	//----------------------------------------------------------------
	// Attribute names as declared in the core part of the dictionary (PLM Core, ER Core, ...)
	//----------------------------------------------------------------

		// ----------------
		// Naming of objects: which attributes to use
		// We recommend to use CATCkeSharedServices::GetAttributeUsedForLogicalName to be independent from core type considerations
		// ----------------

		// Attributes PLM_ExternalID: default attribute for identifying PLM IRPC Objects 
		// Available on IRPC types: (Reference, Representations, Instance, RepresentationInstance, Port, Connection)
		static const CATUnicodeString Attribute_PLM_ExternalID;
		
		// Attributes V_name: default attribute for naming PLM Objects (Reference and Representation) in OCDX context
		// Available on IRPC types: Reference type and Representations type
		static const CATUnicodeString Attribute_V_Name;

		// Attributes name: default attribute for naming ER based objects
		static const CATUnicodeString Attribute_name;

		// Attributes Title: default attribute for naming PLM Objects (ER ones)
		static const CATUnicodeString Attribute_Title;

		// ----------------
		// objects "types"
		// ----------------

		// Attributes V_discipline: well known, stores an applicative type. Useful mainly in former typing. But maintained in Unified typing for compatibility reasons
		// Available on IRPC types
		static const CATUnicodeString Attribute_Discipline;

		// policy attribute (available on all Business objects (ref, rep, port, connections, and all business types)
		static const CATUnicodeString Attribute_Policy;


		// ----------------
		// Basics attributes supporting PLM operations
		// For reading basic attributes, we recommend the usage of CATCkePLMNavPublicServices services to be independent of mapping
		// ----------------

		// Attribute for sorting objects (V_TreeOrder)
		// Available on IRPC types
		static const CATUnicodeString Attribute_TreeOrder;

		// attribute minorrevision (minorrevision)
		// available on any business types 
		static const CATUnicodeString Attribute_minorrevision;

		// attribute revision (revision (concatenates major and minor)): can be seen as a computed attributes
		// available on any business types 
		static const CATUnicodeString Attribute_revision;
		
		// attribute V_fromExternalID for OCDX behavior: contains the name of origin object of a copy/duplicate operation
		// available for IRPC objects. 
		static const CATUnicodeString Attribute_V_fromExternalID;
		
		// attribute V_versionComment for OCDX behavior: comment put by end-user when revisioning the object
		static const CATUnicodeString Attribute_V_versionComment;

	
		//----------------------------------------------------------------
		// Attribute names: basics owned by IRPC types, that are mapped
		// Please use CATCkePLMNavPublicServices when you want to access the name of a basics independantly from the fact that the mapping is effective or not
		// The following values are defined here for the places of code that ARE dependant on the mapping
		//----------------------------------------------------------------

		// List of basic attributes that are mapped (their meanings)
		enum MappedAttribute { owner=0, organization=1, project=2, maturity=3, originated=4, modified=5, reserved=6, reservedby=7, majorrevision=8, physicalid=9, logicalid=10, cestamp=11 };
		
		// Returns the name of the mapped attribute from its meaning
		// If last argument is false, we return the unmapped: ex: owner
		// If last argument is true, we return the mapped: ex: V_user
		static CATUnicodeString ComputeAttributeName (const MappedAttribute &iAttributeRank,CATBoolean &iUsingMapping);

		// Finds the meaning of a mapped attribute from its name: works with an attribute name that is mapped or unmapped
		// indicates in output if it is a mapped or unmapped one
		// Returns E_INVALIDARG if the name in input was not the name of a basic attribute (mapped or unmapped)
		static HRESULT FindMappedAttribute (const CATUnicodeString &iName,MappedAttribute &oAttributeRank,CATBoolean &oMapped);

			// majorrevision attribute on IRPC side
			// available on Reference and Representation
			static const CATUnicodeString Attribute_V_version;
			// majorrevision attribute on ER side (and IRPC nor mapped)
			// available on all business type 
			static const CATUnicodeString Attribute_majorrevision;

			// maturity attribute on IRPC side when mapped
			// available on Reference and Representation
			static const CATUnicodeString Attribute_V_maturity;
			// maturity attribute on ER (and IRPC nor mapped)
			// available on all Business types
			static const CATUnicodeString Attribute_maturity;
		
			// organization attribute on IRPC side
			// available on IRPC
			static const CATUnicodeString Attribute_V_organization;
			// organization attribute on ER side (and IRPC nor mapped)
			// available on all business type and relation type
			static const CATUnicodeString Attribute_organization;

			// project attribute on IRPC side
			// available on IRPC
			static const CATUnicodeString Attribute_V_project;
			// project attribute on ER side (and IRPC nor mapped)
			// available on all business type and relation type
			static const CATUnicodeString Attribute_project;

			// owner attribute on IRPC side
			// available on IRPC
			static const CATUnicodeString Attribute_V_user;
			// owner attribute on ER side (and IRPC nor mapped)
			// available on all business type and relation type
			static const CATUnicodeString Attribute_owner;

			// originated attribute on IRPC side
			// available on IRPC
			static const CATUnicodeString Attribute_C_created;
			// originated attribute on ER side (and IRPC nor mapped)
			// available on all business type and relation type
			static const CATUnicodeString Attribute_originated;

			// modified attribute on IRPC side
			// available on IRPC
			static const CATUnicodeString Attribute_C_modified;
			// modified attribute on ER side (and IRPC nor mapped)
			// available on all business type and relation type
			static const CATUnicodeString Attribute_modified;

			// reserved attribute on IRPC side
			// available on IRPC
			static const CATUnicodeString Attribute_LOCKSTATUS;
			// reserved attribute on ER side (and IRPC nor mapped)
			// available on all business type and relation type
			static const CATUnicodeString Attribute_reserved;
			
			// reservedby attribute on IRPC side
			// available on IRPC
			static const CATUnicodeString Attribute_LOCKUSER;
			// reservedby attribute on ER side (and IRPC nor mapped)
			// available on all business type and relation type
			static const CATUnicodeString Attribute_reservedby;

			// physicalid attribute on IRPC side
			// available on Reference and Representation
			static const CATUnicodeString Attribute_PHYSICALID;
			// physicalid attribute on IRPC side
			// available on all business type 
			static const CATUnicodeString Attribute_physicalid;

			// logicalid attribute on IRPC side
			// available on Reference and Representation
			static const CATUnicodeString Attribute_LOGICALID;
			// logicalid attribute on IRPC side
			// available on all business type 
			static const CATUnicodeString Attribute_logicalid;

			// cestamp attribute on IRPC side
			// available on Reference and Representation
			static const CATUnicodeString Attribute_CESTAMP;
			// logicalid attribute on IRPC side
			// available on all business type 
			static const CATUnicodeString Attribute_cestamp;

			// product specific. V_Scale attribute
			static const CATUnicodeString Attribute_V_Scale;

		//----------------------------------------------------------------
		// Computed attributes for an easy navigation in EKL
		//----------------------------------------------------------------

		// Computed attribute defined on Instances to retrieve the reference of the instance
		// exists only from a Knowledge perspective (CATIType)
		// Available on Instance type (and representation instance type)
		static const CATUnicodeString ComputedAttribute_Reference;

		// Computed attribute defined on Representations to retrieve the aggregated reference
		// exists only from a Knowledge perspective (CATIType)
		// Available on Representation types
		static const CATUnicodeString ComputedAttribute_AggregatingReference;

	//----------------------------------------------------------------
	// Type names as declared in the core part of the dictionary (PLM Core, ER Core, ...)
	//----------------------------------------------------------------
		
		// basic type for Reference
		static const CATUnicodeString Type_PLMCoreReference;

		// basic type for Representation
		static const CATUnicodeString Type_PLMCoreRepReference;

		// basic type for Instance
		static const CATUnicodeString Type_PLMCoreInstance;
		 
		// basic type for BusinessType
		static const CATUnicodeString Type_BusinessType;

		// basic type for RelationType
		static const CATUnicodeString Type_RelationType;

		// basic type for DatabaseObjectType (root of all database types, in Knowledge view)
		static const CATUnicodeString Type_DatabaseObjectType;

		// basic type for PLMEntity
		static const CATUnicodeString Type_PLMEntity;

		// Root path type used in IRPC for the moment (SemanticRelation)
		static const CATUnicodeString PathTypeRoot;

			// Concatenates a global path type from Class name (or Relation class name) and local path type name
			static CATUnicodeString ComputeGlobalPathTypeName (const CATUnicodeString &iClassName,const CATUnicodeString &iLocalPathTypeName);

			// Separator used to separate SemanticRelation name in catalog name and key
			static const CATUnicodeString Separator;

		// Name of the ERCoreModelerPackage
		static const CATUnicodeString ERCoreModelerPackage;

		//----------------------------------------------------------------
		// Meta maturity state names: to enable exchange between maturity states between several PLM installation
		// We define a list of meta maturity state: a state will be able to declare its corresponding meta maturity state
		// Several states in a maturity graph can have the same meta maturity state
		// This relationships is currently established by a business rule (INFRAMaturityStateInformation opening)
		//----------------------------------------------------------------

		// List of meta states
    // PRIVATE: object waiting for approval (example, case of an ECA that you can use after approval).
    // IN_WORK: object that can be modified or used.
    // FROZEN: object that cannot be modified anymore.
    // RELEASED: object that cannot be modified and that has been certified by relevant authority.
    // OBSOLETE: object not to be used any longer (neither modified, nor instantiated).
		enum MetaMaturityState { undefined =0, MS_private=2, inwork=1, MS_frozen=5, released=3, obsolete=4 };
		
		// Returns the name of the meta state: undefined returns ""
		static CATUnicodeString ComputeMetaMaturityStateName (const MetaMaturityState &state);

		// Finds the meaning of a state from its name
		// Returns E_INVALIDARG if the name in input was not the name of a state
		static HRESULT DecodeMetaMaturityStateName (const CATUnicodeString &iName,MetaMaturityState &oState);

};

#endif // CATCkePLMDefinitions_h

