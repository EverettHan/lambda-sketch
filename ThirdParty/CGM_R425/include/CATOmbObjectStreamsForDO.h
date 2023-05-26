#ifndef CATOmbObjectStreamsForDO_H
#define CATOmbObjectStreamsForDO_H

// System
#include "CATUuid.h"
// ObjectModelerCollection
#include "CATOmxAny.h"
#include "CATOmxList.h"
#include "CATOmxArray.h"
#include "CATOmxSR.h"
// CATPLMStreamDescriptor
#include "CATOmbObjectStreams.h"
#include "CATPLMStreamDescriptorForInfraOnly.h"

/**
* OMB Parameters dictionary for CATOmbObjectStreams :
* key : "OMBGenerationContext"          / value type : unsigned int                                  / Read  by OMB and Read/Write by Application  / role : context of generation
* key : "OMBVisuPersistencyName"        / value type CATUnicodeString                                / Set by caller, read by OMB for visu SD creation/ role: keep same name as XCAD visu context.
* other parameters could be inside CATOmbObjectStreams parameters table in order tho share them between caller and callee of OMB
*/

class CATPLMStreamDescriptor;
class CATOmbImportExportParameters;
class CATError;
class CATUnicodeString;
class CATDocument;
class CATVVSUrl;
class CATOmbLoadableDataUniqueKey;


class ExportedByCATPLMStreamDescriptor CATOmbObjectStreamsForDO : public CATOmbObjectStreams
{
  friend class CATOmbSdsStreamServices;
  friend class CATOmbStreamDescriptorSessionService;
  friend class CATOmbTstLinkableUtilities;
  friend class CATOmbObjectStreamsCollection;
  friend class __TA__TestLinkableStreamsGenerationAndUpdate;
public:
  /**
  * @brief  build a wrapper of a PLM component to update and check this one about DO generation
  *
  * @param iComponent The component to be managed
  */
  CATOmbObjectStreamsForDO(CATBaseUnknown* iComponent);
  /**
  * @brief build a wrapper of Non PLM Component (Cloud) to update and check this one about DO generation
  *  (use this if you have one SD or if you are always converting using the First SD)
  *
  * @param iComponnentPhysId The component Physical ID
  * @param iVStreamDescStr   The V_StreamDescriptor of the component (Looks like SDv2( Format , Role , LateType , (CATUnicodeString) WatermarkStamp , synchroStamp , PersType , PersName ))
  * @param iMainSDUrl  The Url of the main (first) StreamDescriptor in the Component
  *                    WARNING this should be a VVSUrl pointing to an actual Stream and not an IFC
  */
  CATOmbObjectStreamsForDO(const CATUnicodeString& iComponnentPhysId,
    const CATUnicodeString& iVStreamDescStr,
    const CATUnicodeString& iMainSDUrl);
  /**
   * @brief build a wrapper of Non PLM Component (Cloud) to update and check this one about DO generation
   *
   * @param iComponnentPhysId The component Physical ID
   * @param iVStreamDescStr   The V_StreamDescriptor of the component (Looks like SDv2( Format , Role , LateType , (CATUnicodeString) WatermarkStamp , synchroStamp , PersType , PersName ))
   * @param iListOfUrls       A list of couples (CATOmbLoadableDataUniqueKey which is Format Role persistency name and the associated file path)
   */
  CATOmbObjectStreamsForDO(const CATUnicodeString& iComponnentPhysId,
    const CATUnicodeString& iVStreamDescStr,
    const CATOmxOHMap<CATOmbLoadableDataUniqueKey, CATUnicodeString>& iListOfUrls);
  /**
   * @brief build a wrapper of Non PLM Component (Cloud) without Sds in input
   *        to be used ONLY with IFC file as source
   *
   * @param iComponnentPhysId The component Physical ID
   */
  CATOmbObjectStreamsForDO(const CATUnicodeString& iComponnentPhysId);
  /**
  * @brief append a SD definition to generate from component main stream. The CATPLMStreamDescriptor will be addref'ed by this instance
  *
  * @param iSD the input CATPLMStreamDescriptor
  * @return HRESULT
  */
  HRESULT AppendSDDefinition(CATPLMStreamDescriptor* iSD);
  /**
  * @brief Set the SD key that will be used for generation by default it is the Authoring stream that will be used.
  *
  * @param iSDKey the SD key to look for conversion input (see CATOmbLoadableDataUniqueKey.h)
  * @return
  *   S_OK : SD is present and will be used.
  *   E_INVALIDARG : SD is not present and cannot be used.
  *   E_XXX : unspecified error.
  */
  HRESULT SetSDSourceForGeneration(const CATOmbLoadableDataUniqueKey& iSDKey);
  
  /**
   * @brief Set the Extrenal File For Generation object using CATVVSUrl
   *
   * @param iUrl and IFC file to be used as source 
   * @return S_OK if file was set, E_FAIL if file does not exists
   */
  virtual ~CATOmbObjectStreamsForDO();

private:
  /**
  * @brief Construct a new CATOmbObjectStreamsForDO object from a subsequent DO generation
  *        Warning the pointer is addref'd and must must deleted or used (Stolen) in a CATOmxSR
  *
  * @param iParentObjectStreams CATOmbObjectStreams object that contains the Subsequent operations
  * @param iSubsequentOpsIndx Sebsequent DO operation index
  */
  static CATOmbObjectStreamsForDO* CreateSubsequentDO(CATOmbObjectStreams* iParentObjStreams);
  /*
   * Dump the ObjectStreams to a string
   * the string will look like this : Source file : {Authoring,'',sldprt} Target SD : {AuthoringVisu,'',stp} , ..
   */
  virtual CATUnicodeString DumpObjectstreamsStr();
  CATOmxSR<CATOmbObjectStreams> m_ParentObjectStreams;
  void SetConnexionOnStreamedSDDef(CATPLMStreamDescriptor* iSD, CATVVSURLConnectionSharable* iConnection);

  CATOmbObjectStreamsForDO(CATOmbObjectStreamsForDO&);
  CATOmbObjectStreamsForDO& operator=(CATOmbObjectStreamsForDO&);
};

#endif // CATOmbObjectStreamsForDO_H
