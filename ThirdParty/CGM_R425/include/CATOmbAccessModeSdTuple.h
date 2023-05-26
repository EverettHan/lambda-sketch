#ifndef CATOmbAccessModeSdTuple_H
#define CATOmbAccessModeSdTuple_H

#include "CATOmxSharable.h"
#include "omb_cst.h"
#include "CATUnicodeString.h"
#include "CATOmxArray.h"
#include "CATOmbLoadableDataUniqueKey.h"
#include "CATSysBoolean.h"
#include "CATOmbSelectiveLoading.h"

class ExportedByCATOmbSelectiveLoading CATOmbAccessModeSdTuple : public CATOmxSharable
{
public:
  CATOmbAccessModeSdTuple(RepRefDataAccess access, const CATUnicodeString& loadingMode, const CATOmxArray<CATOmbLoadableDataUniqueKey>& loadedKeys);
  CATOmbAccessModeSdTuple(RepRefDataAccess access, const CATUnicodeString& loadingMode, const CATOmbLoadableDataUniqueKey& loadedKey);
  ~CATOmbAccessModeSdTuple();

  /*
  * Give the Access of the tuple
  */
  RepRefDataAccess GetAccess() const;

  /* 
  * Give the loadingMode of the tuple
  */
  const CATUnicodeString& GetLoadingMode() const;

  /*
  * returns the array of keys loaded for the given tuple
  */
  const CATOmxArray<CATOmbLoadableDataUniqueKey>& GetLoadedSDKeys() const;

  CATBoolean operator== (const CATOmbAccessModeSdTuple& tuple);
  CATBoolean operator!= (const CATOmbAccessModeSdTuple& tuple){return !operator==(tuple);}

private:
  RepRefDataAccess _access;
  CATUnicodeString _loadingMode;
  CATOmxArray<CATOmbLoadableDataUniqueKey> _loadedKeys;
};

#endif // CATOmbAccessModeSdTuple_H
