#ifndef CATIAfrLabelLayout_H
#define CATIAfrLabelLayout_H

// COPYRIGHT DASSAULT SYSTEMES 2011/03/22

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"

//-----------------------------------------------------------------------------
/**
* Interface to manage layout of labels.
*/
extern ExportedByCATAfrItf  IID IID_CATIAfrLabelLayout ;
class ExportedByCATAfrItf CATIAfrLabelLayout: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Layout the items.
    */
    virtual HRESULT Layout( CATLISTV(CATBaseUnknown_var)& iospList ) = 0;
};
#endif
