#if !defined(__CATOxKey_h__)
#define __CATOxKey_h__
/**
* @level Private
* @usage U1
*/

#include "ExportedByCATPLMIdentification.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATOmxKeyString.h"

//
// this class publish usefull CATUnicodeString defined in TOS
// and which can be used by other guys
//

// use this tag in order to declare new key
#define DECLARE_SKEY(a) const CATString s##a
#define DECLARE_USKEY(a) const CATUnicodeString us##a
#define DECLARE_OMXKEY(a) const CATOmxKeyString omx##a

#define SKEY(a) CATOxKey::Get().s##a
#define USKEY(a) CATOxKey::Get().us##a
#define OMXKEY(a) CATOxKey::Get().omx##a

class CATOxKey
{
  CATOxKey();
  ~CATOxKey() = delete;
  CATOxKey(const CATOxKey&) = delete;
  CATOxKey& operator=(const CATOxKey&) = delete;
public:
  ExportedByCATPLMIdentification static const CATOxKey& Get();

  DECLARE_USKEY(PMRToScopingObject);

  DECLARE_OMXKEY(V_discipline);
  DECLARE_OMXKEY(V_usage);
  DECLARE_OMXKEY(V_version);
  DECLARE_OMXKEY(V_sec_level);
  DECLARE_OMXKEY(V_order);
  DECLARE_OMXKEY(V_isVPLMControlled);
  DECLARE_OMXKEY(V_isTerminal);
  DECLARE_OMXKEY(V_isOnceInstantiable);
  DECLARE_OMXKEY(V_isLastVersion);
  DECLARE_OMXKEY(V_isLastMinorVersion);
  DECLARE_OMXKEY(V_hasConfigStaticMapping);
  DECLARE_OMXKEY(V_hasConfigEffectivity);
  DECLARE_OMXKEY(V_hasConfigContext);
  DECLARE_OMXKEY(V_ChangeHistory);
  DECLARE_OMXKEY(V_AuthorityControl);
  DECLARE_OMXKEY(V_ApplicabilityDate);
  DECLARE_OMXKEY(PLM_ExternalID);
  DECLARE_OMXKEY(minorrevision);
  DECLARE_OMXKEY(majorrevision);
  DECLARE_OMXKEY(revision);
  DECLARE_OMXKEY(minororder);
  DECLARE_OMXKEY(majororder);
  DECLARE_OMXKEY(versionid);
  DECLARE_OMXKEY(minorid);
  DECLARE_OMXKEY(updatestamp); //updatestamp attribute (uuid in a string)
  DECLARE_OMXKEY(C_updatestamp); //legacy updatestamp attribute (int)
  DECLARE_OMXKEY(V_CustoDiscipline);
  DECLARE_OMXKEY(isbestsofar);
  DECLARE_OMXKEY(iscomposee);

  DECLARE_SKEY(V_Owner);
  DECLARE_SKEY(from);
  DECLARE_SKEY(fromrel);

  DECLARE_SKEY(V_InstanceOf);
  DECLARE_SKEY(to);
  DECLARE_SKEY(torel);
};

#endif

