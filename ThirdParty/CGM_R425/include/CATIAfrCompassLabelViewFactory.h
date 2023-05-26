#ifndef CATIAfrCompassLabelViewFactory_H
#define CATIAfrCompassLabelViewFactory_H

// COPYRIGHT DASSAULT SYSTEMES 2011/01/11

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATCommand;
class CATString;
class CATIAfrCompassLabelView;

extern ExportedByCATAfrItf  IID IID_CATIAfrCompassLabelViewFactory ;

//-----------------------------------------------------------------------------
/**
* Interface managing Label View.
*
*/
class ExportedByCATAfrItf CATIAfrCompassLabelViewFactory: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Creates Label view
    **/
    virtual HRESULT CreateLabelView( CATCommand* ipFather, 
                                     const CATString& iName, 
                                     CATIAfrCompassLabelView** opiLabelView ) = 0;

};
#endif
