/* -*-c++-*- */
#ifndef __CATOmbRelationRuleManager_H
#define __CATOmbRelationRuleManager_H
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U1
 */

#include "CATObjectModelerBase.h"
#include "CATBoolean.h"
#include "IUnknown.h"
#include "CATComponentId.h"
#include "CATOmxSR.h"
#include "CATOmxKeyString.h"

class CATString;
class CATUnicodeString;
class CATPLMTypeId;
class CATComponentId;
class CATOmbExternalsDictionaryCache;
class CATOmbExternalsDictionaryCacheEntry;
class CATOmbRelationMetaData;

/**
* USAGE IS RESERVED TO CATPLMClientCore
*
* This class manages a rule system for the relations and links of a given component.
* It allows to provide information about the component, as well as to check the consistency
* of its metadata. Among other things, it computes the possibility to save the component
* without saving its private stream.
*
* stream is here either the CATLnk stream or the PLMCoreStreamStorage.Stream attribute
*
* notice that the following is meaningless on representations/structured connections
*/
class ExportedByCATObjectModelerBase CATOmbRelationRuleManager
{
public:
  // CONSTRUCTOR / DESTRUCTOR
  CATOmbRelationRuleManager(const CATComponentId & iComponent);
  ~CATOmbRelationRuleManager();


  /*
  * semantic/usage unclear
  */
  CATBoolean IsLightModeCompliantForSave();

  /*
  * TRUE if it is forbidden for this component to have a stream
  * Legacy components can however hold a stream in which case a migration will occur
  */
  CATBoolean IsLightModeMandatory();

  /*
   * TRUE if links held by this component require a stream for proper persistance (for example the link has a private part leading to an object inside a representation)
   *
   * Notice that while the other methods of this class expose meta-data (type information), this one exposes data (object information)
   */
  CATBoolean IsStreamingMandatory();

  /*
  * return the name of the path matching input (role,category) couple
  * warning, there exist objects that violates (role,category) unicity rule
  */
  HRESULT GetSubRelationshipName(const CATOmbRelationMetaData & iRMD, CATOmxKeyString & oName);
private:
  const CATComponentId _CID;
  CATOmxSR<CATOmbExternalsDictionaryCacheEntry> _Entry;
protected:
  CATOmbExternalsDictionaryCacheEntry& DictionaryEntry();
};

#endif
