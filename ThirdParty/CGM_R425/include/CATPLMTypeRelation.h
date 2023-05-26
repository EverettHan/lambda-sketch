/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeRelation_H
#define CATPLMTypeRelation_H

#include "CATPLMIdentificationAccess.h"
#include "CATOmxKeyString.h"
#include "CATPLMTypeH.h"
#include "CATPLMTypeHSet.h"
#include "CATPLMStrongRelationshipId.h"
class CATPLMTypeHIter;
class CATString;

/**
 * Class defining a Relation managed on a PLM type.
 *
 * <br><b>Role</b>: This class enables to represent a PLM Relation defined on a PLM Type in the metadata.
 */
class ExportedByCATPLMIdentificationAccess CATPLMTypeRelation
{
public:
  CATPLMTypeRelation();
  virtual ~CATPLMTypeRelation();
  CATPLMTypeRelation( const CATPLMTypeRelation & iOther );
  CATPLMTypeRelation & operator =( const CATPLMTypeRelation & iOther );

/**
 * Get the identifier of the Relation (For strong relation, please use GetRelationId( CATPLMStrongRelationshipId::eStrongRelId& oStrongRelId )).
 * <br><b>Role:</b>Give access to the relation identifier as defined in the metadata.
 *
 * @param oRelationId [out]
 * The identifier.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if a PLM relation is given back.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_UNEXPECTED</tt> if the Relation is invalid.</li>
 * </ul>
 */
  HRESULT GetRelationId( CATString & oRelationId ) const;

/**
 * Get the identifier of the Strong Relation (eg: from, to...).
 * <br><b>Role:</b>Give access to the relation identifier as defined in the metadata.
 *
 * @param oRelationId [out]
 * The identifier.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if a PLM relation is given back.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * <li><tt>E_UNEXPECTED</tt> if the Relation is invalid.</li>
 * </ul>
 */
  HRESULT GetRelationId( CATPLMStrongRelationshipId::eStrongRelId& oStrongRelId ) const;
  
/**
 * List the PLM Type pointed through the PLM Relation.
 * <br><b>Role:</b>Give access PLM Type (@href CATPLMTypeH) pointed through the Relation.
 *
 * @param oPLMTypes [out]
 * An iterator on the PLM types.
 *
 * @return
 * <ul>
 * <li><tt>S_OK</tt> if a PLM relation is given back.</li> 
 * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
 * </ul>
 */
  HRESULT ListPLMTypes( CATPLMTypeHSet & oPLMTypes ) const;

protected:
  friend class PLMTypeBehaviorsRelationsFilter;
  CATPLMTypeRelation( const CATString & iRelationId );
  void SetRelationId( const CATString & iRelationId );
  HRESULT AddType( const CATPLMTypeH & iType );
  HRESULT AddRelationId( const CATString & iRelationId );

private:
  CATPLMTypeHSet _PLMTypes;
  CATOmxKeyString _RelationId;
};

#endif
