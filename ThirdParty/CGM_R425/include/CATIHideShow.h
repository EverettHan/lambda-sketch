#ifndef CATIHIDESHOW_H
#define CATIHIDESHOW_H

// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
// Class  :  	CATIHideShow
// Author :  	CDT
// Date   :  	99
//------------------------------------------------------------------------------
// Abstract:    Interface for Shown or Hidden objects
//
//------------------------------------------------------------------------------

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "list.h"
#include "CATViewpoint.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrFoundation IID IID_CATIHideShow;
#else
extern "C" const IID IID_CATIHideShow;
#endif

class CATFilter;

class ExportedByCATAfrFoundation CATIHideShow : public CATBaseUnknown
{
    CATDeclareInterface;
public:
    virtual HRESULT SeeShown(  ) = 0;
    virtual HRESULT SeeHidden(  ) = 0;
    virtual int  IsShowWorld(  ) = 0;
    virtual HRESULT AddViewpoint ( CATViewpoint *iVpt) = 0;
    virtual HRESULT RemoveViewpoint ( CATViewpoint *iVpt) = 0;
    virtual list<CATViewpoint> * GetViewpoint( ) = 0;
    // for managing the filter on the VisuController
    virtual void SetPermanentFilter(CATFilter *filter) = 0;
    virtual CATFilter * GetPermanentFilter() = 0;
    
};

CATDeclareHandler(CATIHideShow, CATBaseUnknown);

#endif
