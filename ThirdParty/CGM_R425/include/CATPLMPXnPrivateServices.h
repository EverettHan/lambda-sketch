
#ifndef CATPLMPXnPrivateServices_H
#define CATPLMPXnPrivateServices_H

#include "CATPLMPXn.h"
#include "CATSysErrorDef.h"
class CATIPLMRecordReadSet;
class CATPLMPXnPrivateServicesImpl;
class CATUnicodeString;
class CATIPLMRecordReadSet;

class ExportedByCATPLMPXn CATPLMPXnPrivateServices
{
  CATPLMPXnPrivateServices();
  ~CATPLMPXnPrivateServices();

  friend class CATOmyLocalStorageCollector; //This is used by streams management
  friend class CATPLMPXnServicesTest;

private:
  /*
  * Get all the records associated to every local save image.
  * This will return a record for each plmid in local save image.
  * Please note this important piece of information : local save is incremental
  * and this method will return every record, meaning you can find multiple different records
  * for the same PLMID, with different attributes.
  * Said differently, records are not an image of the current local save, but images of multiple past
  * local saves since last merge. Merge should be done at each open of a local save image
  * (ie. at each restore of a previous session).
  * A call to this after session restored and not touched should give the latest record reads.
  */
  HRESULT GetAllRecordsFromImages(CATIPLMRecordReadSet *&oRecords);

  /*
  * Same as the other version, but specifying a particuliar image.
  */
  HRESULT GetAllRecordsFromImage(const CATUnicodeString &iImagePath, CATIPLMRecordReadSet *&oRecords);

  CATPLMPXnPrivateServicesImpl* m_pImpl;
};

#endif
