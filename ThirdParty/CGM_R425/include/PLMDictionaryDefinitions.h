#ifndef PLMDictionaryDefinitions_h
#define PLMDictionaryDefinitions_h

// COPYRIGHT DASSAULT SYSTEMES 2011


#include "PLMDictionaryInterfaces.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h" // HRESULT
#include "CATBoolean.h"

/**   
* Name space: contains PLM Dictionary definitions useful for the different PLM Dictionary implementations and services
*/
class ExportedByPLMDictionaryInterfaces PLMDictionaryDefinitions 
{
public:

  //--------------------------------------------------------------------------------------
  // New typing management: prefer methods that answer to question, instead of using the enum
  //--------------------------------------------------------------------------------------

  /** We have 4 levels of PLM types: customer specialization, applicative discipline, top modeler, and abstracts
  * @param AbstractType
  * abstract types 
  * @param TopModelerType
  * Top modeler type: owns the C++ interfaces implementation of the object
  * @param ApplicationType
  * Types defined by applications
  * @param SpecializationType
  * Types defined by customer as specialization in new typing
  * @param CustoType
  * Types defined by customer in old typing system
  */
  enum PLMTypeLevel { AbstractType=0, TopModelerType=1, ApplicationType=2, SpecializationType=3, CustoType=4 };

  /** We have different kind of extensions
  * @param TopExtension
  * Extension root
  * @param ApplicationExtension
  * Sub extension types defined by applications
  * @param CustomerExtension
  * Extensions defined by customer as specialization in new typing
  * @param SpecializationExtension
  * Extensions defined by customer, independant from any DS Type
  * @param DeploymentExtension
  * Deployment extensions defined by customer
  */
  enum PLMExtensionLevel { TopExtension=1, ApplicationExtension=2, SpecializationExtension=3, DeploymentExtension=4, CustomerExtension=5};


  // Behavior1: Indicates if we must generate a late type for this type
  static CATBoolean HasALateType (const PLMTypeLevel iTypeLevel);

  // Behavior2: Indicates if we must generate a late type for this extension
  static CATBoolean HasALateType (const PLMExtensionLevel iTypeLevel);

  // Behavior3: Indicates if this extension must generate a Knowledge (CATIInstance) view natively (without delegating to CATIInstanceExtension
  static CATBoolean HasAGenericKnowledgeView (const PLMExtensionLevel iTypeLevel);



  //--------------------------------------------------------------------------------------
  // Object management
  //--------------------------------------------------------------------------------------

  /** Nature of an object corresponding to a class (not an instance) or a Relation Class
  * @param Independent
  *    Can live independantly: can be created, versioned, has a lifecycle, has a owner
  * 
  * @param SubComponent
  *    Is considered as a sub part of its aggregator: no independant life. Cannot be created without aggregator
  *    Copied with its aggregator, versioned with it, deleted with it
  *    No different owner, no different security   
  * 
  * @param Aggregated
  *    Aggregated: Cannot be created without aggregator. But has an independant ownership, security, maturity. 
  *    Copied with its aggregator, versioned with it, deleted with it
  *
  * @param Instance
  *    Aggregated: Cannot be created without aggregator. But has an independant ownership, security. Has no maturity. 
  *    Copied with its aggregator, versioned with it, deleted with it
  */
  enum PLMObjectTypeNature { Independent=0, SubComponent=1, Aggregated=2, Instance=3, MayBeAggregated=4  };

  // From property value to PLMObjectTypeNature
  // Returns S_FALSE if not translatable
  static HRESULT TranslatePLMObjectTypeNature (const CATUnicodeString &iPropertyValue,PLMObjectTypeNature &oNature);


  // Behavior 1: This kind of object must be aggregated
  static CATBoolean MustBeAggregated (const PLMObjectTypeNature iObjectTypeNature);

  // Behavior 2: This kind of object has an independant ownership (influencing lock)
  static CATBoolean HasIndependentOwnership (const PLMObjectTypeNature iObjectTypeNature);

  // Behavior 3: This kind of object can be versioned independantly 
  static CATBoolean CanBeVersioned (const PLMObjectTypeNature iObjectTypeNature);

  // Behavior 4: This kind of object can be duplicated independantly
  static CATBoolean CanBeDuplicated (const PLMObjectTypeNature iObjectTypeNature);

  // Behavior 5: This kind of object has a maturity state (and can be promoted)
  static CATBoolean HasAMaturityState (const PLMObjectTypeNature iObjectTypeNature);

  // Behavior 6: This kind of object delegates access (security) to its father
  static CATBoolean DelegatesAccessToItsAggregator (const PLMObjectTypeNature iObjectTypeNature);

  // Behavior 7: This object can be deleted in the authoring session
  static CATBoolean SupportsDeletionFromAuthoringSession (const PLMObjectTypeNature iObjectTypeNature);

  // Behavior 8: This object can be deleted in short transaction
  static CATBoolean SupportsShortTransactionDeletion (const PLMObjectTypeNature iObjectTypeNature);

  // Behavior 9: This kind of object can be changed of collaborative space 
  static CATBoolean CanBeChangedOfCollaborativeSpace (const PLMObjectTypeNature iObjectTypeNature);

  //--------------------------------------------------------------------------------------
  // Relations management: prefer methods that answer to question, instead of using the enum
  // Note that relations are usually oriented from the "FROM" Subclause to the "TO" Subclause
  // - we call Source the object referenced by the FROM of the relationship
  // - we call Target the object referenced by the TO of the relationship
  // Normally, an aggregation for example is oriented from the aggregating object (FROM) to the aggregated object (TO)
  // But as we cannot be sure of this situation, we will answer to questions on relations, by precising what happens to the source or the target object
  //--------------------------------------------------------------------------------------

  /** Nature of a Relation corresponding to a relation class (or an instance) or a semantic relation
  * @param Pointer
  *    The relation models a link/Pointer between 2 objects (between a source and a target
  *    The target and the source object can be shared of course
  *    Do not participate to expand (target is not seen as a child)
  *    Can load the relationship without loading the target. But the source must be loaded
  *    Can load the source without loading the target or the relationship
  *
  * @param Association
  *    The relation models an association between 2 objects (no difference between source and target)
  *    The target and the source object can be shared of course
  *    Do not participate to expand (target is not seen as a child)
  *    Can load the relationship without loading the target nor the source
  *    Can load the source without loading the target or the relationship
  *
  * @param Structure
  *    The relation models a structural link between 2 objects (a source and a target)
  *    The target can be shared
  *    Participates to the expand of the source (target is seen as a child from navigation standpoint)
  *    Cannot load the relationship without loading the target and the source 
  *    The source can be loaded without loading the relationship
  * 
  * @param Instanciation
  *    The relation models an instanciation between 2 objects (a source and a target)
  *    This relation supports configuration
  *    The target can be shared
  *    Participates to the expand of the source (target is seen as a child from navigation standpoint)
  *    Cannot load the relationship without loading the target and the source
  *    Source can be loaded without loading the target
  *
  * @param Aggregation
  *    The relation models an aggregation between 2 objects (a source and a target)
  *    It drives the propagation of versioning, cloning and delete of the source to the target
  *    The target cannot be shared
  *    Participates to the expand of the source (target is seen as a child from navigation standpoint)
  *    Cannot load the source without loading the target 
  *    Cannot load the relationship without loading the target & the source 
  *
  * @param Aggregator
  *    The relation models a link between an object and its aggregator
  *    It drives the propagation of versioning, cloning and delete of the source to the target
  *    The source cannot be shared
  *    Cannot load the source without loading the target 
  *    Cannot load the relationship without loading the target & the source 
  */
  enum PLMRelationshipTypeNature { Pointer=0, Association=1, Structure=2, Instanciation=3, Aggregation=4, Aggregator=5 };


  // Computed from property value: RelationNature defined on relationship types
  // Returns S_FALSE if not translatable
  static HRESULT TranslatePLMRelationshipTypeNature (const CATUnicodeString &iPropertyValue,PLMRelationshipTypeNature &oNature);


  // Behavior 1: Indicates if this relation participates to the expand (and the target seen as child of source)
  static CATBoolean IsSeenAsAChild (const PLMRelationshipTypeNature iRelationTypeNature);

  // Behavior 1: Indicates if this relation participates to the expand (and the target seen as child of source) (or its source, if relation is defined the other way round)
  static HRESULT IsSeenAsAChild (const PLMRelationshipTypeNature iRelationTypeNature,CATBoolean &iSourceSeenAsAChild,CATBoolean &iTargetSeenAsAChild);

  // Behavior 2: Indicates if this relation propagates versioning, cloning to its target (or its source, if relation is defined the other way round)
  static HRESULT PropagatesDuplication (const PLMRelationshipTypeNature iRelationTypeNature,CATBoolean &iPropagateToSource,CATBoolean &iPropagateToTarget);

  // Behavior 3: Indicates if this relation propagates deletion from source to target (or its source, if relation is defined the other way round)
  static HRESULT PropagatesDeletion (const PLMRelationshipTypeNature iRelationTypeNature,CATBoolean &iPropagateToSource,CATBoolean &iPropagateToTarget);

  // Behavior 4: Indicates if this relation propagates transfer ownership if the target object  has no ownership (or its source, if relation is defined the other way round)
  static HRESULT PropagatesPotentiallyTransferOwnership (const PLMRelationshipTypeNature iRelationTypeNature,CATBoolean &iPropagateToSource,CATBoolean &iPropagateToTarget);

  // Behavior 5: Indicates if this relation propagates lock if the target object has no ownership (or its source, if relation is defined the other way round)
  static HRESULT PropagatesPotentiallyLock (const PLMRelationshipTypeNature iRelationTypeNature,CATBoolean &iPropagateToSource,CATBoolean &iPropagateToTarget);

  // Behavior 4: Indicates if this relation supports effectivities
  static CATBoolean SupportsConfiguration (const PLMRelationshipTypeNature iRelationTypeNature);

  // Behavior 5: Indicates if this relation must load its source and/or its target
  static HRESULT MustBeLoaded (const PLMRelationshipTypeNature iRelationTypeNature,CATBoolean &iLoadSource,CATBoolean &iLoadTarget);

  // Behavior 6: Indicates if this relation is aggregated under the source or under the target 
  static HRESULT IsAggregatedUnder (const PLMRelationshipTypeNature iRelationTypeNature,CATBoolean &iItsSource,CATBoolean &ItsTarget);


  /**
  * Enumerated value that defines the list of operations that are supported on a PLM Object.<br>
  * @param NewVersion
  * Versioning operation. Major version.
  * @param ChangeMaturity
  * Changing maturity of an object.
  * @param LockUnlock
  * Locking or unlocking an object.
  * @param TransferOwnership
  * Transfering ownership of an object.
  * @param NewMinorRevision
  * Revision operation. Minor revision.
  */
  enum PLMOperationSupport { NewVersion=1,
    ChangeMaturity=2,
    Delete=3,
    LockUnlock=4,
    TransferOwnership=5,
    Duplicate=6,
    NewMinorRevision=9,
    ChangeCollaborativeSpace =14
  };

  /**
  * Enumerated value that defines the list of data features supported by a PLM type.<br>
  * @param CarryStream
  * Does an object carries stream?
  * @param CarryPointers
  * Does an object carries pointers?
  * @param AggregatesComponents
  * Does an object aggregates components?
  * @param IsSynchronizable
  * Does an object supports synchronization (carry update stamp)
  * @param UniqueNamingRule
  * Does an object supports unique naming rule (identifier set or unique key)
  */
  enum PLMDataFeaturesSupport { CarryStreams=1,
    CarryPointers=2,
    AggregatesComponents=3,
    IsSynchronizable=4 ,
    UniqueNamingRule=5 };

  /** Returns the name of the boolean property used to model the data feature */	 
  static HRESULT RetrievePLMDataFeatureProperty (PLMDataFeaturesSupport iDataFeature,CATUnicodeString &iPropertyName,CATUnicodeString &iPropertyValue);

  /** Interprets the CarryStream property value 
  * returns E_FAIL if property value is not recognized
  * iPropertyValue: is the value of the property
  * oMinimum: is the minimum number of streams
  * oMaximum: is the maximum number of streams. If there is no maximum, value is equal to -1
  */
  static HRESULT InterpretCarryStreams (const CATUnicodeString &iPropertyValue,int &oMinimum,int &oMaximum);
};

#endif
