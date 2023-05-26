#ifndef _CATSYPTypeFactory_H
#define _CATSYPTypeFactory_H

#include <IntroInfra.h>
#include <CATSYPFactoryResult.h>
#include <nlohmann/json_fwd.hpp>
class CATUnicodeString;

/**
 * CATSYPDuration
 */
extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATSYPDurationFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra
HRESULT CATSYPCATSYPDurationSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);
extern "C" ExportedByIntroInfra
HRESULT CATSYPCATSYPDurationJsonBuilder(const CATBaseUnknown_var& i_spCBU, nlohmann::json& o_json);

/**
 * CATSYPRepeatBehavior
 */
extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATSYPRepeatBehaviorFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra
HRESULT CATSYPCATSYPRepeatBehaviorSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);
extern "C" ExportedByIntroInfra
HRESULT CATSYPCATSYPRepeatBehaviorJsonBuilder(const CATBaseUnknown_var& i_spCBU, nlohmann::json& o_json);

#endif
