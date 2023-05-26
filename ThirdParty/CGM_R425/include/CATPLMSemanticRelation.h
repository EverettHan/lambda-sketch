// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATPLMSemanticRelation.h
// Header definition of CATPLMSemanticRelation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Dec 2008  Creation: LEC
//===================================================================
#ifndef CATPLMSemanticRelation_H
#define CATPLMSemanticRelation_H

#include "CATPLMIdentificationAccess.h"

#include "CATBoolean.h"
#include "CATPLMID.h"
#include "CATPLMSemanticRelationData.h"
#include "CATPLMTypeH.h"
#include "CATIAV5Level.h"

/**
 * @level Protected
 * @usage U1
 *
 */

 /*
  * CATPLMSemanticRelation implements SemanticRelation type which is composed of
  *    a target object (or path) implemented through a CATPLMID
  *    a set of attributes (IDRel, Role, PrivateData...) implemented by a CATPLMSemanticRelationData object

  *  This classe is dedicated to import/export of semantic relations between client & server
  */
class ExportedByCATPLMIdentificationAccess CATPLMSemanticRelation final
{
public:
  // constructor
  CATPLMSemanticRelation(const CATPLMID &iTargetID, const CATPLMSemanticRelationData &iSRData) :_Main_PLMID(iTargetID), _Main_SRData(iSRData) {}

  CATPLMSemanticRelation() = default;
  CATPLMSemanticRelation(const CATPLMSemanticRelation&) = default;
  CATPLMSemanticRelation& operator=(CATPLMSemanticRelation &) = default;
  CATPLMSemanticRelation(CATPLMSemanticRelation&&) = default;
  CATPLMSemanticRelation& operator=(CATPLMSemanticRelation&&) = default;


  // get target
  CATPLMID GetTarget() const { return _Main_PLMID; }

  // get "data" (SemanticRelation attributes)
  CATPLMSemanticRelationData GetData() const { return _Main_SRData; }

  // destructor
  virtual ~CATPLMSemanticRelation();

  // obsolete legacy API
  HRESULT GetTargetID(CATPLMID& oTargetID) const { oTargetID = _Main_PLMID; return S_OK; }
  HRESULT GetSRData(CATPLMSemanticRelationData ** oSRData) const;
  HRESULT SetMainRelation(const CATPLMID& iTargetID, const CATPLMSemanticRelationData& iSRData)
  {
    _Main_PLMID = iTargetID;
    _Main_SRData = iSRData;
    return S_OK;
  }

  // removed API
  OMX_DEPRECATED("not implemented") HRESULT SetContextRelation(const CATPLMID &iCtxTargetID, const CATPLMSemanticRelationData &iCtxSRData) { return E_NOTIMPL; }
  OMX_DEPRECATED("not implemented") HRESULT GetCtxTargetID(CATPLMID& oCtxTargetID) const { oCtxTargetID = CATPLMID(); return S_OK; }
  OMX_DEPRECATED("not implemented") CATPLMID GetContextTarget() const { return CATPLMID(); }
  OMX_DEPRECATED("not implemented") HRESULT GetCtxSRData(CATPLMSemanticRelationData** oCtxSRData) const { *oCtxSRData = new CATPLMSemanticRelationData(); return S_OK; }
  OMX_DEPRECATED("not implemented") CATPLMSemanticRelationData GetContextData() const { return CATPLMSemanticRelationData(); }
  OMX_DEPRECATED("not implemented") HRESULT IsContextual(CATBoolean & oIsContextual) const { oIsContextual = FALSE; return S_OK; }

private:
  CATPLMID _Main_PLMID;
  CATPLMSemanticRelationData _Main_SRData;
};

//-----------------------------------------------------------------------

#endif
