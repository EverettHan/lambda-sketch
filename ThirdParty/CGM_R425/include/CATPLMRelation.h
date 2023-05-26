// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMRelation.h
// Header definition of CATPLMRelation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  May 2003  Creation: Code generated by the CAA wizard  jvm
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMRelation_H
#define CATPLMRelation_H

// CATPLMIdentificationAccess
#include "CATLISTV_CATPLMTypeId.h"
#include "CATPLMStrongRelationshipId.h"
// CATPLMServices
#include "CATPLMBaseObject.h"
#include "CATPLMServicesItf.h"
#include "CATPLMOmxCollections.h"

class CATPLMType;
class CATListPtrCATPLMType;
class CATString;
class CATUnicodeString;
class VPMIDicRelationship;
class VPMIDicSubRelationship;
class CATSemanticRelationMetaData;

/**
* @level Private 
* @usage U1
*/

/** direction of this relation. Either UPPER or LOWER or UNDEF */
/*
* @deprecated
**/
enum direction{
  /** UPPER */
  UPPER = 0,
  /** LOWER */
  LOWER = 1, 
  /** UNDEF */
  UNDEF = 2
};

/**
* This class describes the relation/links between object types. These links can be oriented.
*/
class ExportedByCATPLMServicesItf CATPLMRelation: public CATPLMBaseObject
{
  CATDeclareClass;
public:

  // Standard constructors and destructors
  // -------------------------------------
  CATPLMRelation (CATString *iRelationId,CATUnicodeString *iAlias, CATIPLMProviderDesc * iProvider,
    CATPLMType *iSource, 
    CATListPtrCATPLMType *iTargetList/*, 
                                     direction iDirection=LOWER*/);

  CATPLMRelation (const CATString& iRelationId,CATIPLMProviderDesc * iProvider,CATPLMType *iSource,const CATPLMTypeList& iTargetList);

  CATPLMRelation(VPMIDicRelationship * iRelationship, CATIPLMProviderDesc * iProvider,
    CATPLMType *iSource, 
    CATListPtrCATPLMType *iTargetList/*, 
                                     direction iDirection=LOWER*/);

  CATPLMRelation(VPMIDicRelationship * iRelationship, CATIPLMProviderDesc * iProvider,
    CATPLMType *iSource, 
    const CATPLMTypeList& iTargetList/*, 
                                     direction iDirection=LOWER*/);

  // CATPLMRelation is built on VPMIDicSubRelationship only if IsSemanticRelation on VPMIDicSubRelationship == TRUE
  CATPLMRelation(VPMIDicSubRelationship * iRelationship, CATIPLMProviderDesc * iProvider,
    CATPLMType *iSource);

  virtual ~CATPLMRelation ();

  CATPLMStrongRelationshipId::eStrongRelId GetRelId();

  /**
  * Returns the source Type of this relation
  * @param oSourceId [out]
  *      The source CATPLMType.
  */
  virtual HRESULT From ( CATString **  oSourceId) ;

  /**
  * Returns the source Type of this relation
  * @param oSourceId [out]
  *      The source CATPLMType.
  */
  virtual HRESULT From ( CATString& oSourceId) ;

  /**
  * Returns the list of target Types of this relation. if the Relation target type is ANYObject, returns a non null list with size == 0
  */
  virtual HRESULT To (CATListPtrCATPLMType ** oTargetList) ;

  /**
  * Returns the list of target Types of this relation. if the Relation target type is ANYObject, returns a non null list with size == 0
  */
  virtual HRESULT To (CATPLMTypeList& oTargetList) ;

  /**
  * Returns the number of target Types of this relation. -1 if the Relation target type is ANYObject
  */
  virtual HRESULT TargetCount (int  *oCount) ;

  /**
  * Returns the direction of this relation. Either UPPER or LOWER or UNDEF
  */
  //virtual HRESULT Direction (direction * oDirection) ;

  /**
  * @return
  *    S_OK: the Relation is visible, it will be returned by CATPLMType#ListRelations.<br>
  *    S_FALSE: the Relation is not visible, it will not be returned by CATPLMType#ListRelations.<br>
  *    E_FAIL: the operation failed.
  */
  virtual HRESULT IsVisible() ;

  /**
  * Returns the element's NLSTag.
  * @param oNLSTag : NLSTag
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetNLSTag( CATUnicodeString & oNLSTag);

  /**
  * Returns the Type characteristic of the Relationship.
  * @param oType
  *   the Type characteristic of the Relationship
  */
  virtual HRESULT GetType (CATUnicodeString * oType) const;

  /**
  * Returns the Category characteristic of the Relationship. T
  * @param oCategory
  *   the Category characteristic of the Relationship
  */
  virtual HRESULT GetCategory (CATUnicodeString * oCategory) const;

  /**
  * Returns the Role characteristic of the Relationship. This value matches one of the Enumerators� Name defined in the C_RoleEnum Enum (see RELATION_ENUMS.metadata)
  * @param oRole
  *   the Role characteristic of the Relationship
  */
  virtual HRESULT GetRole (CATUnicodeString * oRole) const;

  /**
  *@deprecated (replaced by method IsMultiValuated)
  * Returns the Cardinality of Relationship.
  * @param oCardinalityMin
  *   The Cardinality Min. 1 if no Multi valuated
  * @param oCardinalityMax
  *   The Cardinality Max.
  *    1 if no Multi valuated
  *   -1 if Multi valuated to n
  */
  virtual HRESULT GetCardinality(int * oCardinalityMin, int * oCardinalityMax);

  /*
   * TRUE means that of course, it is not a strong relationship (from, to, V_Owner...<=> _pRelationship != NULL && _pSubRelationship == NULL)
   * TRUE means that _pRelationship == NULL  && _pSubRelationship != NULL && _pSubRelationship Inherits from SemanticRelation
  */
  virtual CATBoolean IsSemanticRelation();

  virtual CATBoolean IsMultiValuated();
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATPLMRelation (CATPLMRelation &);
  CATPLMRelation& operator=(CATPLMRelation&);
  HRESULT _IsVPMIDicVisible();
  HRESULT _GetVPMIDicSRMD (CATSemanticRelationMetaData & ioSRMD) const;
  HRESULT _GetVPMIDicCardinality(int * oCardinalityMin, int * oCardinalityMax);

  void _DeclareInvalidCATPLMRelation();

  CATString *_pFromId;
  CATPLMTypeIds *_pTargetList;
  //direction _Direction;

  // A Relation can be even a VPMIDicSubRelationship or VPMIDicRelationship --- BEAAAARK
  VPMIDicRelationship * _pRelationship;
  VPMIDicSubRelationship * _pSubRelationship;

protected:
  friend class CATPLMType;
  HRESULT UpdateTargets(CATPLMRelation & iRelationWithNewTargets);
};
#endif