#ifndef CATOmbRepRefInitServicesForVALDRIV_H
#define CATOmbRepRefInitServicesForVALDRIV_H

#include "CATOmbSelectiveLoading.h"
#include "IUnknown.h"
#include "CATSysBoolean.h"

class CATComponentId;
class CATOmxKeyValueBlock;
class CATBaseUnknown;
class CATDocument;
class CATUnicodeString;

class ExportedByCATOmbSelectiveLoading CATOmbRepRefInitServicesForVALDRIV
{
public:
  /**
  * Init an empty RepRep with an sd authoring pointing to a CATDocument of an other version than the software version.
  * For instance init a rep with a 13x document on a 17x software
  * @param ioRepRefComponentId
  *   the component id of the repRef to initialize
  * @param iParams
  *   A key value block (map) containing data about the initialisation to do. Keys to use :
  *   - "PivotSoftLevel" : string valuated to the targetted software level. Minimum downward level is V6R2013x, and it has to be a lower version than current one
  *   - "Latetype" : string valuated to the latetype of document to create. CATPart for most cases.
  * @return
  *   S_OK : Init well done
  *   E_INVALIDARG : argument not valid or software level error
  *   E_FAIL : Something went wrong
  */
  static HRESULT InitPivotRepRef(const CATComponentId& ioRepRefComponentId, const CATOmxKeyValueBlock& iParams);
  
  /** Same method but taking pointer on RepRef instead of ComponentId*/
  static HRESULT InitPivotRepRef(const CATBaseUnknown* ioRepRef, const CATOmxKeyValueBlock& iParams);

  /**
  * Method to get status about downgrad status of a CATDocument
  * @param iDoc
  *   the document to check
  * @param oDowngradeLevel
  *   the level in which the document has been downgraded (for instance CATIAV6R214). Null string if returns FALSE
  * @param oOriginLevel
  *   the level of the original document that has been downgraded. Null string if returns FALSE
  * @return
  *   TRUE : the document has been downgraded
  *   FALSE : the document has not been downgraded (common case)
  */
  static CATBoolean isDocumentDowngraded(const CATDocument& iDoc, CATUnicodeString& oDowngradeLevel, CATUnicodeString& oOriginLevel);
  static CATBoolean isDocumentDowngraded(const CATDocument& iDoc);
};


#endif // CATOmbRepRefInitServicesForVALDRIV_H 
