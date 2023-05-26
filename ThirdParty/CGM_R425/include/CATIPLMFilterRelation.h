// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMFilterRelation.h
// Define the CATIPLMFilterRelation interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//  Feb 2005  Creation:  jvm
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMFilterRelation_H
#define CATIPLMFilterRelation_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATPLMStrongRelationshipId.h"
#include "CATPLMPathTypeH.h"
#include "CATPLMOmxCollections.h"
#include "CATBoolean.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMFilterRelation;
#else
extern "C" const IID IID_CATIPLMFilterRelation ;
#endif

class CATPLMType;
class CATString;
class CATListPtrCATIPLMFilterRelationQuality;

/** Direction of the filter relation */
/*
REL_IMPACTEDBY <=> From pointING object to pointED object
REL_IMPACTSON  <=> From pointED object to pointing object
*/
enum RelDirection{
  /** Impacted By Direction */
  REL_IMPACTEDBY = 0,
  /** Impacts on Direction */
  REL_IMPACTSON = 1,
  /** Both (Impacted By and ImpactsOn) Direction */
  REL_IMPACTBOTH = 2,
  /** IsInstanceOf Direction */
  REL_ISINSTANCEOF = 3,
  /** IsOwnedBy Direction */
  REL_ISOWNEDBY = 4,
  /** IsTo Direction */
  REL_ISTO = 5,
  /** IsFrom Direction */
  REL_ISFROM = 6,
  /** pointING relation1--------->pointED relation*/
  REL_ISTOREL = 7,
  /** pointING relation1--------->pointED relation*/
  REL_ISFROMREL = 8,
  /** pointED relation1--------->pointING relation*/
  REL_ISTOMID = 9,
  /** pointED relation1--------->pointING relation*/
  REL_ISFROMMID = 10
};

class ExportedByCATPLMServicesItf CATPLMRelDirectionHelpers
{
public:
  static HRESULT Convert(RelDirection ieRelDir,CATString& oStrongRel);

  static const CATString IsOwnedBy;
  static const CATString IsInstanceOf;

  static const CATString ISOWNEDBY;
  static const CATString ISINSTANCEOF;

  // For CATString from, please use CATPLMStrongRelationshipId::sfrom
  // For CATString to, please use CATPLMStrongRelationshipId::sto

  static CATBoolean IsValid(CATPLMType* ipSourceType,CATPLMType* ipTargetType,RelDirection ieRelDir);
};

/**
* The Relation filter allows you to narrow the list of objects returned.
* With CATIPLMFilterRelation allowed in CATIPLMFilterCriteria or CATIPLMFilterCondition
* you may specify Relationships or SemanticRelation on which you want to navigate during expand operation.
*/
class ExportedByCATPLMServicesItf CATIPLMFilterRelation: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  *	Returns the source Type of this relation
  * @param oSourceType [out, CATBaseUnknown#Release]
  *      The source CATPLMType.
  */
  virtual HRESULT GetSourceType ( CATPLMType **  oSourceType) = 0;

  /**
  *	Returns the target Type of this relation. 
  * @param oTargetType [out, CATBaseUnknown#Release]
  *      The target CATPLMType.
  */
  virtual HRESULT GetTargetType (CATPLMType ** oTargetType) = 0;

  /**
  *	Returns the direction of this relation. 
  * Either REL_IMPACTEDBY or REL_IMPACTSON or REL_IMPACTBOTH
  * or either REL_ISINSTANCEOF or REL_ISOWNEDBY.
  * @param oDirection
  *      The relation RelDirection.
  */
  virtual HRESULT GetDirection (RelDirection * oDirection) = 0;

  /**
  * Returns the Category applied on this semantic relation.
  * @param oCategory
  *   the category. NULL is no category applied
  */
  //virtual HRESULT GetCategory( CATString ** oCategory ) = 0; 

  /**
  * Returns the Role applied on this semantic relation.
  * @param oRole
  *   the role. NULL is no role applied
  */
  //virtual HRESULT GetRole( CATString ** oRole ) = 0; 

  /** 
  * Adds a Filter on relation Quality : Category or/and role. 
  * CATIPLMFilterRelation is used for specifying on which relation qualities you want to navigate
  * Relation depends on the orientation (IN-OUT-NEUTRAL-IN/OUT) held by the category of the SR. 
  * it depends also on others Categories qualifiers (Propagation Orientation, Visibility, Synchrosensitivity..) and Role of SR.
  * @param iCategory
  *   the category. NULL is no category applied
  *   Don't use strong relationship with this service, use AddFilterStrongRelationQuality(...).
  * @param iRole
  *   the role. NULL is no role applied
  */
  virtual HRESULT AddFilterRelationQuality(const CATString& iCategory, const CATString& iRole) = 0;
  // @deprecated
  virtual HRESULT AddFilterRelationQuality(CATString * iCategory, CATString * iRole) = 0;

  /**
  * Specify the strong relationship on which you navigate
  * WARNING: useable when no instance mapping project is activate >2016x
  * @param iStrongRel:
  * Between complex type<=>port/cnx and entity, use eV_Owner.
  * Between relation and entity, use efrom or eto.
  * Between relation and relation, use efromrel or etorel.
  * eV_InstanceOf is deprecated with no instance attribute mapping.
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT AddFilterStrongRelationQuality(CATPLMStrongRelationshipId::eStrongRelId iStrongRel) =0;

  /** 
  * Returns the list of CATIPLMFilterRelationQuality in the FilterCondition. NULL if no CATIPLMFilterRelationQuality has been added.
  * @param oFilterRelationQualities
  *   the FilterRelationQualities used for filtering query result from relations. NULL if no CATIPLMFilterRelationQuality 
  */
  virtual HRESULT ListFilterRelationQuality( CATListPtrCATIPLMFilterRelationQuality ** oFilterRelationQualities ) = 0;

  virtual HRESULT ListFilterRelationQuality(CATIPLMFilterRelationQualityList& oFilterRelationQualities) = 0;

  /** 
  * Adds a flag for specifying the 1rst path for the navigate.
  * waiting for a better solution...
  */
  virtual void AddSpecialTagForFastener () = 0;

  /** 
  * Gets the flag for specifying the 1rst path for the navigate.
  * waiting for a better solution...
  */
  virtual void GetSpecialTagForFastener (CATBoolean & oTagForFastener) = 0;

  /** 
  * Adds a Filter on relation Quality. 
  * CATIPLMFilterRelation is used for specifying on which relation qualities you want to navigate
  * Relation depends on the orientation (REL_IMPACTSON/REL_IMPACTEDBY) held by current relation. 
  * @param iPathType
  *   the iPathType.
  */
  virtual HRESULT AddFilterRelationQuality (const CATPLMPathTypeH& iPathType) = 0;

  /**
  * CATIPLMFilterRelation Implementation.
  */
  virtual HRESULT ListFilterRelationQuality( CATPLMPathTypeHArray& olPathType ) = 0;

  virtual CATBoolean IsNavFromBoToRelUsingFrom() = 0;

  virtual CATBoolean IsNavFromRelToBoUsingTo() = 0;

  virtual CATBoolean IsNavFromBoToComplexTypeUsingVOwner() = 0;
};

#endif
