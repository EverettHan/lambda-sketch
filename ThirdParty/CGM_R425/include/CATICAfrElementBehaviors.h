#ifndef CATICAfrElementBehaviors_H
#define CATICAfrElementBehaviors_H

// COPYRIGHT DASSAULT SYSTEMES 2011/09/27

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATListValCATString;

extern ExportedByCATAfrItf  IID IID_CATICAfrElementBehaviors ;

//-----------------------------------------------------------------------------
/**
* Interface managed C-Afr component behaviors.
**/
class ExportedByCATAfrItf CATICAfrElementBehaviors: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
    /**
    * Sort the properties list.
    */
    virtual HRESULT SortProperties( CATListValCATString& ioListOfPropId ) = 0;

};
#endif
