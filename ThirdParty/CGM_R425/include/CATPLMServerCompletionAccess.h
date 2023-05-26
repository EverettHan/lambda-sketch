/**
 * @level Private
 * @usage U1
 */

#ifndef CATPLMServerCompletionAccess_H
#define CATPLMServerCompletionAccess_H

#include "CATPLMIntegrationAccess.h"

#include "CATPLMIDCEStampPairCollections.h"

#include "CATPLMComplexTypeObjInfos.h"

#include "CATPLMOmxCollections.h"

#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATBinary.h"
#include "CATSysErrorDef.h"// for HRESULT
#include "CATCollec.h"

class CATPLMProcedureParams;
class CATUnicodeString;
class CATPLMID;
class CATLISTV(CATPLMID);
class CATIPLMError;
class CATPLMTypeH;

class ExportedByCATPLMIntegrationAccess CATPLMServerCompletionAccess
{
public:
  struct InputPaths {
    // each complex plmid is an occurrence. Each complex plmid contains a list of simple plmid.
    CATLISTV(CATPLMID) paths;
    // each complex plmid is an occurrence. Each complex plmid contains a list of simple plmid.
    CATLISTV(CATPLMID) selectedPaths;
    // each simple plmid is a root. roots.Size()==configBinaries.Size(). roots[i] is associated with configBinaries[i]. map can be built map.Insert(roots[i],configBinaries[i]).
    CATLISTV(CATPLMID) roots;
    //configBinaries[i] contains a compiled form.
    CATListOfCATBinary configBinaries;
  };

  struct OutputPaths {
    CATPLMIDCEStampPairArrayArray plmidAndCEStampList;
    CATPLMComplexTypeObjInfosArray complexObjectList;
  };

  CATPLMServerCompletionAccess();
  virtual ~CATPLMServerCompletionAccess();

  /*
  * Executes completion with 4 DAGS: procedure / product / systeme / resource
  */
  HRESULT Execute(const CATUnicodeString& iScriptName,
    const InputPaths& procInput, const InputPaths& prodInput, const InputPaths& sysOpInput, const InputPaths& resInput,
    OutputPaths& procOutput, OutputPaths& prodOutput, OutputPaths& sysOpOutput, OutputPaths& resOutput, 
    CATIPLMError*& opError);

  /*
  * Executes completion with 5 DAGS: procedure / product / systeme / resource / workplan
  */
  HRESULT Execute(const CATUnicodeString& iScriptName,
    const InputPaths& procInput, const InputPaths& prodInput, const InputPaths& sysOpInput, const InputPaths& resInput, const InputPaths& workplanInput,
    OutputPaths& procOutput, OutputPaths& prodOutput, OutputPaths& sysOpOutput, OutputPaths& resOutput, OutputPaths& workplanOutput,
    CATIPLMError*& opError);

private:
  HRESULT _BuildAllAndSelectedParam(const InputPaths& iParam,
                                    const CATString& iParamNameForSelectedOcc,const CATString& iParamNameForAllOcc,
                                    const CATString& iParamNameForRootOcc,const CATString& iParamNameForConf,
                                    CATPLMProcedureParams& ioParams);

  HRESULT _BuildParam(const CATLISTV(CATPLMID)& iOccs, CATListOfCATUnicodeString& oStrListOfOccs);

  HRESULT _BuildParam(  const CATLISTV(CATPLMID)& iListSelectedOcc,const CATListOfCATBinary& iListConfOfSelectedRootOcc,
                        CATOmxOMap<CATUnicodeString,CATBinary>& ioMapRootOccWithConfig,CATListOfCATUnicodeString& oStrListOfRoot);

  HRESULT _BuildPhysicalId(const CATPLMID& iPlmid,CATUnicodeString& oPhysicalId);

  HRESULT _BuildOutput(const CATPLMProcedureParams& iProcedureOutParams, const CATString& iOccurrenceOutParam, const CATString& iComplexObjectsOutParam, OutputPaths& output, CATIPLMError*& opError);

  HRESULT _BuildAnswer(const CATListOfCATUnicodeString& iListOccWithCes,CATPLMPairUuidCesArrayArray& oListOfOccWithCes);

  HRESULT _BuildPlmidAndCestamp(const CATPLMPairUuidCesArrayArray& listOfOccPhysCesAsUuid,CATPLMIDCEStampPairArrayArray& oListOfOccPlmidCes,CATIPLMError*& opError);

  HRESULT _BuildComplexObjects(const CATPLMPairUuidCesArrayArray& iListOfUUIDCes, CATPLMComplexTypeObjInfosArray& oComplexObjects, CATIPLMError*& opError);

  HRESULT _ConvertFromUuidToString(const CATUuid& iPhysAsUuid,CATUnicodeString& oPhysAsString);

  HRESULT _ConvertFromStringToCes(const CATUnicodeString& iCesAsString,CATPLMCEStamp& oCes);
};

#endif
