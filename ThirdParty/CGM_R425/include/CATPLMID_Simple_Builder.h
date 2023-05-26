#ifndef _CATPLMID_Simple_Builder_H
#define _CATPLMID_Simple_Builder_H

/**
 * @level Private
 * @usage U1
 */

#include "IUnknown.h"
#include "CATPLMIdentificationAccess.h"
#include "CATIAV5Level.h"

class CATPLMID_Simple;
class CATPLMID_Any;
class CATPLMID_RepositoryLocation;
class CATPLMRepositoryName;
class CATPLMTypeId;

/**
 * PLMID factory, see GeneratePLMID comments
 */
class ExportedByCATPLMIdentificationAccess CATPLMID_Simple_Builder
{
public:

  /**
  * Generates a PLMID from given arguments.
  *
  * WARNING: Outside infrastructure framework (Identification, Adapter, Integration), you should not need to build a PLMID
  *          So outside these frameworks, usage is forbidden and behavior is unspecified.
  *          I you can't find any better solution and use this API, it is at your own risks.
  *          If you build an irrelevant PLMID:
  *             saying it comes from database ("valid for remote usage") when it is not
  *             using invalid type
  *             assigning incorrect repository
  *             assigning incorrect logicalid/majorid
  *          API may succeed but consequences on session/server queries are unspecified and you can expect the worst.
  *          typically some code may use physicalid as unique identifier while other may use all properties.
  *
  * Only iLocation is optional. All other attributs are mandatory.
  * @param iRepositoryName : the name of the repository
  * @param iLocation : the location of the repository
  *                    if not empty: PLMID will be seen as "valid for remote usage" (CATPLMID_RepositoryLocation::Dummy() is standard "not empty" value)
  *                    if empty:     PLMID will be seen as not "valid for remote usage"
  * @param iTypeId : the type of the component
  * @param iPhysicalIdentifier : the physical identifier of the component
  * @param iMajorIdentifier : the major identifier of the component
  * @param iLogicalIdentifier : the logical identifier of the component
  * @param oPLMID : the generated PLMID
  *
  * @return
  *       S_OK if the PLMID was generated
  *       E_INVALIDARG if oPLMID_Simple was not an empty PLMID or invalid arg
  *       E_FAIL if generation failed
  */
  static HRESULT GeneratePLMID(const CATPLMRepositoryName& iRepositoryName,
    const CATPLMID_RepositoryLocation& iLocation,
    const CATPLMTypeId& iTypeId,
    const CATPLMID_Any& iPhysicalIdentifier,
    const CATPLMID_Any& iMajorIdentifier,
    const CATPLMID_Any& iLogicalIdentifier,
    CATPLMID_Simple& oPLMID);
};

#endif
