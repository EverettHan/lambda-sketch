#ifndef CATOmbPCSUTils_H
#define CATOmbPCSUTils_H

// System
#include "CATUuid.h"
// ObjectModelerCollection
#include "CATOmxOHMap.h"
#include "CATOmxSR.h"
#include "CATOmxSet.h"
#include "CATOmxSharable.h"
// CATVirtualVaultSystem
#include "CATVVSURLConnection.h"
// ObjectModelerBase
// CATPLMStreamDescriptor
#include "CATOmyCioGenerator.h"
#include "CATOmbIPCS.h"
#include "CATOmbImportExportParameters.h"
#include "CATDocument.h"
#include "CATIOmyIncidentCollector.h"
#include "CATAsyncTrace.h"
#include "CATOmbLoadableDataUniqueKey.h"


class ExportedByCATOmbIPCS CATOmbIPCSUtils
{
public:
  CATOmbIPCSUtils();
  virtual ~CATOmbIPCSUtils();

    /**
  * Stream associated sd in temporary cache (XMM)
  * param
  *   - iCID : the component whose SDs has to be streamed in XMM
  *   - ioListOfTargetStreamDefinition : the SDs to stream in cache. definition's watermarkstamp will be updated with the MD5
  * return
  *   - S_OK : everything ran well
  *   - S_FALSE : nothing to stream
  *   - E_XXX : something went wrong
  */

  static CATOmxSR<CATBaseUnknown> GetNoTOSRepRef(const CATUnicodeString& iVStreamDesc
    , const CATOmxOHMap<CATOmbLoadableDataUniqueKey, CATVVSUrl>& iUrlList);

  static HRESULT FlushNoTOSRepRef(CATOmxSR<CATBaseUnknown>& iNoTOSRepRef);

  /**
* As the name suggests this function checks if it is a NonCATIADocument
* @param
*   The LateType of the document.
* @return
* TRUE : it is a CATNonCATIADocument
* FALSE : it is a native document
*/
  static CATBoolean IsNonCATIADocument(const CATUnicodeString& iType);

  static CATUnicodeString GetExtenstionForStream(const CATUnicodeString& iPersistencyType, const CATUnicodeString& iLateType);

  static HRESULT GetVersionFromCATBackLevel(const CATUnicodeString& iCATBackLevel, int& oVersion, int& oRelease);

private:
  CATOmbIPCSUtils(CATOmbIPCSUtils&);
  CATOmbIPCSUtils& operator=(CATOmbIPCSUtils&);
  
};

#endif
