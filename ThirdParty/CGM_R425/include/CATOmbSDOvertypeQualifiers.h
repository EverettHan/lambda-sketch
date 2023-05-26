#ifndef CATOmbSDOvertypeQualifiers_H
#define CATOmbSDOvertypeQualifiers_H

#include "CATOmbSelectiveLoading.h"
#include "CATOmbLoadableDataUniqueKey.h"

class ExportedByCATOmbSelectiveLoading CATOmbSDOvertypeQualifiers : public CATOmbLoadableDataUniqueKey
{
public:

  CATOmbSDOvertypeQualifiers();
  CATOmbSDOvertypeQualifiers(const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iFromPersisType, const CATUnicodeString& iToPersisType);
  virtual ~CATOmbSDOvertypeQualifiers();

  inline const CATUnicodeString& GetOriginType() const { return _FromPersisType; }
  inline const CATUnicodeString& GetTargetType() const { return _ToPersisType; }

  // Operators
  CATOmbSDOvertypeQualifiers(const CATOmbSDOvertypeQualifiers&);
  CATOmbSDOvertypeQualifiers&	operator= (const CATOmbSDOvertypeQualifiers&);

  int operator==(const CATOmbSDOvertypeQualifiers&	iOpD) const;
  int operator!=(const CATOmbSDOvertypeQualifiers&	iOpD) const;

private:
  CATUnicodeString _FromPersisType;
  CATUnicodeString _ToPersisType;
};

template<> ExportedByCATOmbSelectiveLoading CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmbSDOvertypeQualifiers>::manager();
#endif
