#ifndef CATOmbSerializationStrategyAdapter_H
#define CATOmbSerializationStrategyAdapter_H

/**
* COPYRIGHT DASSAULT SYSTEMES 2020
* @level Protected
* @usage U2
*/

#include "CATBaseUnknown.h"
#include "CATIOmbSerializationStrategy.h"
#include "CATOmbLoadableDataUniqueKey.h"
#include "CATUnicodeString.h"
class CATOmbImportExportParameters;

/**
* Base class for adaptable implementation of CATIOmbSerializationStrategy interface.
* @see CATIOmbSerializationStrategy
*/

class ExportedByCATOmbSelectiveLoading CATOmbSerializationStrategyAdapter : public CATIOmbSerializationStrategy
{
  CATDeclareKindOf;

public:

  /**
  * CTOR/DTOR
  */
  CATOmbSerializationStrategyAdapter();
  virtual ~CATOmbSerializationStrategyAdapter();

  virtual HRESULT GetSerializationStrategy(CATBaseUnknown& iComponent, const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iLateType, const CATUnicodeString& iPersisType, CATOmbImportExportParameters* iParameters, SerializeStream::Strategy& oStrategy);

private:

  CATOmbSerializationStrategyAdapter(const CATOmbSerializationStrategyAdapter& iData);
  CATOmbSerializationStrategyAdapter& operator = (const CATOmbSerializationStrategyAdapter& iData);

};
#endif
