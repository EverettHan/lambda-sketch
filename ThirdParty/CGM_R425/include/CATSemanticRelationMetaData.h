/* -*-c++-*- */
#ifndef CATSemanticRelationMetaData_H
#define CATSemanticRelationMetaData_H
/**
 * @level Private
 * @usage U3
 */

// SpecialAPI
#include "CATSysErrorDef.h"
// System
#include "CATUnicodeString.h"
// CATPLMIdentificationAccess
#include "CATPLMIdentificationAccess.h"
#include "CATPLMTypeH.h"

class ExportedByCATPLMIdentificationAccess CATSemanticRelationMetaData
{
public:
  inline CATSemanticRelationMetaData() {};
  // On appelle la methode de migration
  CATSemanticRelationMetaData(const CATUnicodeString & iType);
  // On appelle la methode de verification
  CATSemanticRelationMetaData(const CATUnicodeString & iType, const CATUnicodeString & iRole, const CATUnicodeString & iCategory);
  // On appelle la methode de migration
  CATSemanticRelationMetaData(const CATPLMTypeH & iTypeAggr, const CATUnicodeString & iType, const CATUnicodeString & iRole, const CATUnicodeString & iCategory);
  inline CATSemanticRelationMetaData(const CATSemanticRelationMetaData & iCopy) : _Type(iCopy._Type), _Role(iCopy._Role), _Category(iCopy._Category) {}
  inline ~CATSemanticRelationMetaData() {}

  CATSemanticRelationMetaData & operator=(const CATSemanticRelationMetaData &iCopy);

  int operator == (const CATSemanticRelationMetaData& other) const;
  inline int operator != (const CATSemanticRelationMetaData& other) const { return !this->operator==(other); }

  inline const CATUnicodeString & GetType() const { return _Type; }
  inline const CATUnicodeString& GetRole() const { return _Role; }
  inline const CATUnicodeString& GetCategory() const { return _Category; }

  inline HRESULT GetRoleAndCategory(CATUnicodeString & oRole, CATUnicodeString & oCategory) const
  {
    oRole = _Role;
    oCategory = _Category;
    return S_OK;
  }
private:
  CATUnicodeString _Type;
  CATUnicodeString _Role;
  CATUnicodeString _Category;
};

#endif
