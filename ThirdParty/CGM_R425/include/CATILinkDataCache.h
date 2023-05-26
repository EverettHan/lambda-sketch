// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATILinkDataCache_H
#define CATILinkDataCache_H

/**
 * @level Private
 * @usage U3
 */

#include <CATBaseUnknown.h>
#include <CATIContainer.h>
#include <CATFormat.h>

#include <CP0CLIP.h>

extern ExportedByCP0CLIP IID IID_CATILinkDataCache ;

class ExportedByCP0CLIP CATILinkDataCache: public CATBaseUnknown
{
  CATDeclareInterface;
 public:

    // Object Definition & Update;
    virtual CATBaseUnknown_ptr SetCache(CATBaseUnknown_ptr from_localizable_object_or_container, int is_auto=0, const CATFormat* format=NULL, CATIContainer* into_container=NULL)=0;
    virtual int SetUpdateMode(int is_auto=1)=0;

    // Object Query
    virtual CATBaseUnknown_ptr FromObject() const =0;
    virtual int UpdateMode() const =0;
    virtual const CATFormat* FromFormat() const =0;
    virtual CATBaseUnknown_ptr Cache() const =0;

    // Synchronization
    virtual int NeedUpdate() const =0; // in case of manual mode
    virtual int CanUpdate() const =0; // binding to initial object can be done
    virtual int Update()=0;           // can failed due to partial update, or conciliation requirement
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATILinkDataCache, CATBaseUnknown ) ;

#endif 

