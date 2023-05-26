//===================================================================
// COPYRIGHT Dassault Systemes 2015/03/02
//===================================================================
// CATPLMOfflineAccess.cpp
// Header definition of class CATPLMOfflineAccess
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/03/02 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATPLMOfflineContent_H
#define CATPLMOfflineContent_H

#include "CATPLMIntegrationAccess.h"
#include "CATIPLMOfflineContentMetadata.h"
#include "CATPLMIDSet.h"
#include "CATOmxOSet.h"
#include "CATOmxCollecManager.h"
#include "CATOmxOHMap.h"
#include "CATOmxSR.h"
#include "CATLISTV_CATPLMID.h"
#include "CATIAV5Level.h"
#include "CATPLMIDCollections.h"

class CATPLMOfflineContentImpl;
class CATIAdpErrorMonitor;

class ExportedByCATPLMIntegrationAccess CATPLMOfflineContent
{
protected:
  CATPLMOfflineContentImpl *_pImpl;
public:

// Standard constructors and destructors
// -------------------------------------
CATPLMOfflineContent ();

virtual ~CATPLMOfflineContent ();

HRESULT GetMetadata(CATIPLMOfflineContentMetadata &ioMetaData);
HRESULT SetMetadata(CATIPLMOfflineContentMetadata &ioMetaData);

/**
* Gets info id 
* <br><b>Role</b>: As defined at creation or modified
* @param &oInfoId
* May be complex PLMID
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
HRESULT GetInfoId(CATPLMID &oInfoId) const;

/**
* Gets content ids
* <br><b>Role</b>: As defined at creation or modified
* @param &oContent
* May be complex PLMID
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
HRESULT GetContent(CATPLMIDs &oContent) const;
HRESULT GetContent(CATPLMIDOSet &oContent) const;

/**
* Tells if the favorites has modifications to save
* <br><b>Role</b>: 
* @param 
* 
* @return
* <dl>
* <dt><code>S_OK</code> Modification are present <dd>
* <dt><code>S_FALSE</code> No modification present <dd>
* <dt><code>E_*</code> Error while processing <dd>
* </dl>
*/
HRESULT HasBeenModified();

/**
* Synchronise offline content from database
* <br><b>Role</b>: PLMIDs will be updated with last informations from database. To be used online
* 
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
HRESULT Synchronise();

//cf. Save Favorite Content (content modification)

/**
* Updates the base plmids of this local content
* <br><b>Role</b>: This method should be used to replace current PLMIDs of the structure. It must only be called
* to modify the structure, not for logging session modifications
* @param &iNewIds
* 
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
HRESULT UpdateContent(const CATPLMIDOSet &iNewIds);

/**
* Updates the base plmids of this local content
* <br><b>Role</b>: This method should be used to replace current PLMIDs of the structure
* @param &iNewIds
* 
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
//HRESULT UpdateInfos(const CATPLMIDSet &iNewIds);

HRESULT GetErrorMonitor(CATOmxSR<CATIAdpErrorMonitor> &ioErrorMonitor);

CATPLMOfflineContent (const CATPLMOfflineContent &);
CATPLMOfflineContent& operator=(const CATPLMOfflineContent&);

CATPLMOfflineContent (CATPLMOfflineContent &&);
CATPLMOfflineContent& operator=(CATPLMOfflineContent&&);

CATHashKey hash() const;
int Compare(const CATPLMOfflineContent& iOther) const;
CATOmxSR<CATIAdpErrorMonitor> _spErrorMonitor;
};

//-----------------------------------------------------------------------

template<> ExportedByCATPLMIntegrationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMOfflineContent>::manager(); 
typedef ExportedByCATPLMIntegrationAccess CATOmxOSet<CATPLMOfflineContent> CATPLMOfflineContentsSet;
typedef ExportedByCATPLMIntegrationAccess CATOmxOHMap<CATPLMID, CATPLMOfflineContent> CATPLMOfflineContentsMap;


#endif