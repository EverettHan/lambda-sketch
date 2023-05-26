#ifndef CATPLMID_STREAM_STRING_RESTRICTED_H 
#define CATPLMID_STREAM_STRING_RESTRICTED_H
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
* @level Private
* @usage U1
*/
#include "CATPLMIdentificationAccess.h"
#include "CATPLMIDMAXFormatVersion.h"
#include "IUnknown.h"

class CATString;
class CATPLMID;

class CATPLMDebugDumpRecordSet;
class CATPLMFilterCriteria;
class CATPLMFilterConfig;
class CATPLMFilterObjectToTreat;
class CATPLMFilterVolume;
class CATPLMFilterVolumeProximity;
class CATPLMFilterVolumeZone;
class CATPLMPrivateXMLWriter;
class CATMSGObjectAttrImpl;
class CATMSGRel;
class CATOxiPLMIDBuildersAndMarshallers;
class CATPLMQueryFilter;
class CATPLMFilterMinorObjReplacingBSF;
class CATPLMTstXMLWriter;

/**
* This mashalling format is restricted to a very specific infrastructure usage.
* It is STRICTLY FORBIDDEN to store this stream inside PLM persistency.
*/
class ExportedByCATPLMIdentificationAccess CATPLMID_STREAM_STRING_RESTRICTED
{
private:

  friend class CATPLMDebugDumpRecordSet;
  friend class CATPLMFilterCriteria;
  friend class CATPLMFilterConfig;
  friend class CATPLMFilterObjectToTreat;
  friend class CATPLMFilterVolume;
  friend class CATPLMFilterVolumeProximity;
  friend class CATPLMFilterVolumeZone;
  friend class CATPLMPrivateXMLWriter;
  friend class CATMSGObjectAttrImpl;
  friend class CATMSGRel;
  friend class CATOxiPLMIDBuildersAndMarshallers;
  friend class CATPLMQueryFilter;
  friend class CATPLMFilterMinorObjReplacingBSF;
  friend class CATPLMTstXMLWriter;
  friend class CATPLMQueryFilterMessageXML;

  /**
  * Stream the contents of PLMID without checking consistenc
  * The usage of this methode is restricted to query infrastructure
  *
  * @param iPLMID
  *        The PLMID to be streamed
  * @param oString
  *        The string result
  * @param iMessageVersion
  *        The version to be generated
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : otherwise
  */
  static  HRESULT  StreamForXMLTransfer(const CATPLMID             & iPLMID,
                                        CATString                  & oString,
                                        const BYTE                   iMessageVersion=CATPLMIDMAXFormatVersion_MinorMajorCompatibility);

  /**
  * Unstream the contents of PLMID without checking consistency
  *
  * @param iString
  *        The string
  * @param oPLMID
  *        The PLMID
  * @param oMessageVersion
  *        The version
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : otherwise
  */
  static  HRESULT  UnstreamForXMLTransfer(const CATString            & iString,
                                          CATPLMID                   & oPLMID,
                                          BYTE                       * oMessageVersion=NULL);
};

#endif
