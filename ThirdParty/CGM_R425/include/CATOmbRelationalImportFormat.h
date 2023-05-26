/**
* @level Private
* @usage U2*/
#ifndef _CATOmbRelationalImportFormat_H
#define _CATOmbRelationalImportFormat_H

/**
 * @level Private
 * @usage U1
 */

#include "CATOmbLinkTraderForRestrictedAccess.h"
#include "CATBoolean.h"
#include "CATOmxOptional.h"
#include "CATOmxArray.h"
#include "IUnknown.h"

class CATOmbRelationImport;
class CATPLMSemanticRelation;
class CATPLMIDCompatibilityActor;

/**
* Abstract class providing import protocol for relations
*/
class ExportedByCATOmbLinkTraderForRestrictedAccess CATOmbRelationalImportFormat
{
public:
  /**
  * Initialized object
  *
  * @return
  *     S_OK    : if succeeded.
  *     S_FALSE : if still initialized.
  *     E_FAIL  : if failed.
  */
  HRESULT Init(const CATUnicodeString & iTypeAggr);
protected:
  /**
  * To be implemented by derived class
  *
  * @return
  *     S_OK    : if succeeded.
  *     E_FAIL  : if failed.
  */
  virtual HRESULT BuildSRList(const CATUnicodeString & iTypeAggr) = 0;
public:
  CATOmxArray<CATPLMSemanticRelation> GetSRList() const;

protected:
  CATOmbRelationalImportFormat() = default;
  virtual ~CATOmbRelationalImportFormat();

private:
  friend class CATOmbRelationalCheckSum;
  friend class CATOmbComponentRecovery;
  void SetCompatibilityActor(CATPLMIDCompatibilityActor * iCompatibilityActor) { _CompatibilityActor = iCompatibilityActor; }

  /* forbidden operations */
  CATOmbRelationalImportFormat(CATOmbRelationalImportFormat &) = delete;
  CATOmbRelationalImportFormat& operator=(CATOmbRelationalImportFormat&) = delete;

protected:
  CATOmx::optional<CATOmxArray<CATPLMSemanticRelation> > _SRList;
  CATPLMIDCompatibilityActor* _CompatibilityActor = nullptr;
};

#endif
