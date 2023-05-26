// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMSemanticRelationId.h
// Header definition of CATPLMSemanticRelationId
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  May 2009  Creation: LEC
//===================================================================
#ifndef CATPLMSemanticRelationId_H
#define CATPLMSemanticRelationId_H

/**
* @level Protected
* @usage U1
*/

#include "CATPLMIdentificationAccess.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"  // HRESULT on UNIX ...
#include "CATUnicodeString.h"

class CATPLMSRIds;

/** @nodoc */
class ExportedByCATPLMIdentificationAccess CATPLMSemanticRelationId
{
public:
  // The SemanticRelation creation (no check done on iSRData value)
  CATPLMSemanticRelationId(const unsigned int &iSRID);
  CATPLMSemanticRelationId(const CATUnicodeString& iPathId);
  CATPLMSemanticRelationId(const CATPLMSRIds& iIds);

  // Destructor
  virtual ~CATPLMSemanticRelationId();

  // Get & Set methods
  HRESULT GetSRID(unsigned int &oSRID) const;

  // To set or modify an existing SemanticRelation ID. Returns E_FAIL is the context is already set.
  HRESULT SetSRID(const unsigned int &iSRID);

  CATUnicodeString GetPathId() const;

  void SetPathId(const CATUnicodeString& iPathId);

  // Get & Set methods for Context
  HRESULT GetCtxSRID(unsigned int &oCtxSRID) const;

  // Contextual SR Id creation. 
  HRESULT SetCtxSRID(const unsigned int &iSRID);

  CATUnicodeString GetCtxPathId() const;

  void SetCtxPathId(const CATUnicodeString& iCtxPathId);

  // Is the Semantic Relation ID a contextual one ?
  HRESULT IsContextual(CATBoolean & oIsContextual) const;

  /**
  * Check equality between two CATPLMSemanticRelationId
  * It compares the IdRel values (context too, if applicable)
  *
  * @param iToCompare
  *      Type of CATPLMSemanticRelation to Compare<br>
  *
  * @return
  *      TRUE    if have the two CATPLMSemanticRelationId are identical <br>
  *      FALSE   if have the two CATPLMSemanticRelationId are different <br>
  */
  int operator == (const CATPLMSemanticRelationId & iToCompare) const;

private:
  // Standard constructor
  // --------------------
  CATPLMSemanticRelationId();

  // Copy constructor and equal operator
  // -----------------------------------
  CATPLMSemanticRelationId(CATPLMSemanticRelationId &);
  CATPLMSemanticRelationId& operator=(CATPLMSemanticRelationId&);

  // Members :
  // ---------
  unsigned int _Main_SRID;//<=>IDRel
  CATUnicodeString _Main_PATHID;
  unsigned int _Ctx_SRID;//<=>IDRel for CtxSR
  CATUnicodeString _Ctx_PATHID;
  CATBoolean _Is_Contextual;
};

//-----------------------------------------------------------------------

#endif
