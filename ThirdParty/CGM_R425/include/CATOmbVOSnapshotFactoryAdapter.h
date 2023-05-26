// COPYRIGHT Dassault Systemes 2013
//===================================================================
//  June 2013  Creation:   VVG
//===================================================================

#ifndef CATOmbVOSnapshotFactoryAdapter_h
#define CATOmbVOSnapshotFactoryAdapter_h

#include "CATObjectModelerBase.h"

#include "CATIOmbVOSnapshotFactory.h"

#include "CATOmxSet.h"

class CATILinkableObject;
class CATOmxCollecManager;

/**
* Adapter for CATIOmbVOSnapshotFactory. Implements useful methods.
**/
class ExportedByCATObjectModelerBase CATOmbVOSnapshotFactoryAdapter : public CATIOmbVOSnapshotFactory
{
public:

   CATOmbVOSnapshotFactoryAdapter();
   virtual ~CATOmbVOSnapshotFactoryAdapter();

   virtual HRESULT GetVOSnapshot2(PLMIOmbVirtualObjectDescriptor* iTargetOcc, CATILinkableObject **oLinkableVOSnapshot);
   virtual HRESULT GetVOSnapshot(PLMIOmbVirtualObjectDescriptor* iTargetOcc, CATILinkableObject **oLinkableVOSnapshot)=0;

};

#endif

