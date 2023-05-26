#ifndef CATOxBaseDumpServices_H 
#define CATOxBaseDumpServices_H
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/

#include "CATPLMIdentificationAccess.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

class CATPLMCEStamp;
class CATUnicodeString;
class CATPLMTypeId;
class CATPLMID_Any;
class CATOmxAny;
class CATUuid;
class CATPLMID_RepositoryLocation;
class CATPLMRepositoryName;
class CATPLMID_Simple;

/**
* Usage is restricted to debug UI Framework
*/
class ExportedByCATPLMIdentificationAccess CATOxBaseDumpServices
{
private:
  CATOxBaseDumpServices();
public:

  /**
  * Convert CEStamp for dump
  */
  static CATUnicodeString ConvertCEStampForDump(const CATPLMCEStamp & iCEStamp);

  /**
  * Convert TypeId for dump
  */
  static CATUnicodeString ConvertTypeIdForDump(const CATPLMTypeId & iTypeId);

  /**
  * Convert Identifier for dump
  */
  static CATUnicodeString ConvertIdentifierForDump(const CATPLMID_Any & iIdentifier, CATBoolean iDecorateWithDebugInfos = TRUE);

  /**
  * Convert Repository name for dump
  */
  static CATUnicodeString ConvertRepositoryNameFromDump(const CATPLMRepositoryName & iRepositoryName);

  /**
  * Convert Repository location for dump
  */
  static CATUnicodeString ConvertRepositoryLocationFromDump(const CATPLMID_RepositoryLocation & iRepositorLocation);

  /**
  * Convert Master stamp for dump
  */
  static CATUnicodeString ConvertMasterStampForDump(const CATOmxAny & iMasterStamp);

  /**
  * Convert CATUuid for dump
  */
  static CATUnicodeString ConvertCATUuidForDump(const CATUuid & iUuid, CATBoolean iDecorateWithDebugInfos = TRUE);
  static void ConvertUuidForDump(const CATUuid & iUuid, char *CUuid);

  /**
  * Convert any for dump
  */
  static CATUnicodeString ConvertAnyForDump(const CATOmxAny & iAny);

};

#endif
