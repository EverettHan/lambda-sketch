//===================================================================
// COPYRIGHT Dassault Systemes 2015/03/24
//===================================================================
// CATPLMOfflineContentImpl.cpp
// Header definition of class CATPLMOfflineContentImpl
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/03/24 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATPLMOfflineContentImpl_H
#define CATPLMOfflineContentImpl_H

#include "CATPLMOfflineContentBase.h"
#include "CATPLMOfflineContentIdentifier.h"
#include "CATPLMID.h"
#include "CATLISTV_CATPLMID.h"
#include "CATOmxSR.h"
#include "CATPLMIDCollections.h"
class CATPLMIDSet;
class CATIPLMOfflineContentMetadata;
class CATPLMOfflineRepositoryManager;
class CATWOmxBinaryStream ;
class CATIAdpErrorMonitor;

//-----------------------------------------------------------------------

class ExportedByCATPLMOfflineContentBase CATPLMOfflineContentImpl
{
  const CATOmxSR<CATPLMOfflineRepositoryManager> _spRepoManager;
  CATPLMOfflineContentIdentifier _id;
public:
// Standard constructors and destructors
// -------------------------------------
CATPLMOfflineContentImpl (const CATPLMOfflineContentIdentifier           &iId, 
                          const CATOmxSR<CATPLMOfflineRepositoryManager> &_spRepoManager);
//CATPLMOfflineContentImpl (const CATPLMIDSet &iInfos,const CATPLMIDSet &iContent, CATIPLMOfflineContentMetadata &iMetadata);
virtual ~CATPLMOfflineContentImpl ();

HRESULT GetMetadata(CATWOmxBinaryStream &ioMetaData);
HRESULT SetMetadata(CATWOmxBinaryStream &ioMetaData);
HRESULT GetInfoId(CATPLMID &oInfoId) const;
HRESULT GetContent(CATPLMIDs &oInfoId) const;
HRESULT GetContent(CATPLMIDOSet &oInfoId) const;
HRESULT UpdateContent(const CATPLMIDOSet &iNewContent,CATPLMIDOSet &oAdded);
HRESULT HasBeenModified();
HRESULT Synchronise();

HRESULT SaveStructure(const CATPLMOfflineContentIdentifier &iIdentifier);

CATHashKey hash() const { return _id.hash(); }
int Compare(const CATPLMOfflineContentImpl &iOther) const { return _id.Compare(iOther._id);}


// Copy constructor and equal operator
// -----------------------------------
//CATPLMOfflineContentImpl (CATPLMOfflineContentImpl &);
//CATPLMOfflineContentImpl& operator=(CATPLMOfflineContentImpl&);

};

//-----------------------------------------------------------------------

#endif