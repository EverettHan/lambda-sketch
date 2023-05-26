//===================================================================
// COPYRIGHT Dassault Systemes 2015/03/02
//===================================================================
// CATPLMOfflineManagerAccess.cpp
// Header definition of class CATPLMOfflineManagerAccess
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/03/02 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATPLMOfflineManager_H
#define CATPLMOfflineManager_H

#include "CATPLMIntegrationAccess.h"
#include "CATPLMOfflineContent.h"
#include "CATPLMIDCollections.h"
#include "CATOmxSR.h"
#include "CATOmxAutoPtr.h"
#include "CATOmxOSet.h"

class CATPLMOfflineContentManagerImpl;
class CATIAdpErrorMonitor;
//-----------------------------------------------------------------------
class ExportedByCATPLMIntegrationAccess CATPLMOfflineContentManager
{
  CATOmxAutoPtr<CATPLMOfflineContentManagerImpl> _pImpl;
public:
// Standard constructors and destructors
// -------------------------------------
CATPLMOfflineContentManager ();
CATPLMOfflineContentManager (CATOmxSR<CATIAdpErrorMonitor> &ioErrorMonitor);
virtual ~CATPLMOfflineContentManager ();


/**
* Gets the list of available offline contents
* <br><b>Role</b>: 
* @param &oOfflineContents
* 
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
HRESULT GetList(CATPLMOfflineContentsSet &oOfflineContents) const;


/**
* Gets offline content corresponding to the info id
* <br><b>Role</b>: The info id is one set at creation (or updated). It must be unique.
* @param &iInfoId
* 
* @param &oContent
* 
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
HRESULT Search(const CATPLMID &iInfoId, CATPLMOfflineContent &oContent) const;

/**
* Gets offline content corresponding to the info id
* <br><b>Role</b>: The info id is one set at creation (or updated). It must be unique.
* Order is not preserved !
* @param &iInfoId
* 
* @param &oContent
* 
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
HRESULT Search(const CATPLMIDOSet &iInfoId, CATPLMOfflineContentsMap &oContentMap) const;

/**
* Creates an offline content
* <br><b>Role</b>: Create the content, not saved until an update method is called on it.
* @param &iInfoIds
* Identifier for offline content. May be a complex plmid, in this case
* the root is the identifier to locate the offline content. 
* @param &iContentIds
* The new offline content. It must be saved.
* @param &oContent
* The created offline content
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>S_FALSE</code> There is a warning in the error monitor <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
HRESULT CreateNew(const CATPLMID &iInfoId, const CATPLMIDOSet &iContentIds, CATIPLMOfflineContentMetadata &iMetadata);
HRESULT CreateNew(const CATPLMID &iInfoId, const CATPLMIDOSet &iContentIds, CATIPLMOfflineContentMetadata &iMetadata, CATPLMOfflineContent &oOfflinecontent);

/**
* Removes the content from the offline content database
* <br><b>Role</b>: If called, it won't be possible anymore to use this offline content.
* Other contents are unnaffected.
* @param &iOfflineContent
* 
* @return
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_INVALIDARG</code> Not a valid offline content <dd>
* <dt><code>E_*</code> <dd>
* </dl>
*/
HRESULT Remove(const CATPLMOfflineContent &iOfflineContent);
HRESULT Remove(const CATPLMOfflineContentsSet &iOfflineContent);

HRESULT GetErrorMonitor(CATOmxSR<CATIAdpErrorMonitor> &ioErrorMonitor);
private:
// Copy constructor and equal operator
// -----------------------------------
CATPLMOfflineContentManager (CATPLMOfflineContentManager &);
CATPLMOfflineContentManager& operator=(CATPLMOfflineContentManager&);

};

//-----------------------------------------------------------------------

#endif