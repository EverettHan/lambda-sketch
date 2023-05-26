// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATPLMFilterRelationAdapter.h
// Define the CATPLMFilterRelationAdapter interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
// November 2016  Creation:  EPB
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATPLMFilterRelationAdapter_H
#define CATPLMFilterRelationAdapter_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATPLMStrongRelationshipId.h"
#include "CATPLMPathTypeH.h"
#include "CATPLMOmxCollections.h"
#include "CATBoolean.h"
#include "CATIPLMFilterRelation.h"

class CATPLMType;
class CATString;
class CATListPtrCATIPLMFilterRelationQuality;

class ExportedByCATPLMServicesItf CATPLMFilterRelationAdapter: public CATIPLMFilterRelation
{
public:
  CATPLMFilterRelationAdapter ();
  virtual ~CATPLMFilterRelationAdapter ();

  virtual HRESULT GetSourceType ( CATPLMType **  oSourceType);

  virtual HRESULT GetTargetType (CATPLMType ** oTargetType);

  virtual HRESULT GetDirection (RelDirection * oDirection);

  virtual HRESULT AddFilterRelationQuality (CATString * iCategory, CATString * iRole);

  virtual HRESULT AddFilterStrongRelationQuality(CATPLMStrongRelationshipId::eStrongRelId iStrongRel);

  virtual HRESULT ListFilterRelationQuality( CATListPtrCATIPLMFilterRelationQuality ** oFilterRelationQualities );

  virtual HRESULT ListFilterRelationQuality(CATIPLMFilterRelationQualityList& oFilterRelationQualities);

  virtual void AddSpecialTagForFastener ();

  virtual void GetSpecialTagForFastener (CATBoolean & oTagForFastener);

  virtual HRESULT AddFilterRelationQuality (const CATPLMPathTypeH& iPathType);

  virtual HRESULT ListFilterRelationQuality( CATPLMPathTypeHArray& olPathType );

  virtual CATBoolean IsNavFromBoToRelUsingFrom();

  virtual CATBoolean IsNavFromRelToBoUsingTo();

  virtual CATBoolean IsNavFromBoToComplexTypeUsingVOwner();

private:
  CATPLMFilterRelationAdapter (CATPLMFilterRelationAdapter &);
  CATPLMFilterRelationAdapter& operator=(CATPLMFilterRelationAdapter&);
};

#endif
