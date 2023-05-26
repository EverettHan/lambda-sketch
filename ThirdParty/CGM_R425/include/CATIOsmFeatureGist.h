/**
 * @level Private
 * @usage U1
 */

#ifndef __CATIOsmFeatureGist_h__
#define __CATIOsmFeatureGist_h__


class CATUuid;
class CATOmxAny;
#include "CATOmxSharable.h"

/**
 * This class represents the gist of a feature.
 * It allows to browse some data of a feature without fully loading the feature container
 * It is composed of:
 *   its instance number (aka #ele aka ordinal, see CATILinkableObject::GetIdentier/CATGetUniqueIdentifier)
 *   its uuid (linkability identifier, see CATILinkableObject::GetIdentier/CATIUuid::GetUuid)
 *   its link synchro stamp (modification id for link synchronization, see CATIOmbLinkSynchroStamp::GetLinkSynchroStamp)
 */
class CATIOsmFeatureGist : public CATOmxSharable
{
public:
  /**Retrieve instance number*/
  virtual HRESULT GetInstanceNumber(int & oInstanceNumber) const = 0;
  /**Retrieve uuid*/
  virtual HRESULT GetUuid(CATUuid & oUuid) const = 0;
  /**Retrieve link synchro stamp*/
  virtual HRESULT GetLinkSynchroStamp(CATOmxAny & iVersion, CATOmxAny & oStamp) const = 0;
};


#endif // __CATIOsmFeatureGist_h__

