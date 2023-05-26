
#ifndef CATIAfrVidView_H
#define CATIAfrVidView_H

// COPYRIGHT DASSAULT SYSTEMES 2011/09/21

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATAfrModelRoot;

extern ExportedByCATAfrItf  IID IID_CATIAfrVidView ;

//-----------------------------------------------------------------------------
/**
* Interface created the form vid componenet view.
**/
class ExportedByCATAfrItf CATIAfrVidView: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
    /**
    * Creates a Vid view.
    *   @param ipParent
    *     The father of the view componenet
    *   @param ipAfrModel
    *     Object to display.
    *   @param opViewModel
    *     The view Model.
    */
    virtual HRESULT CreateView( CATBaseUnknown* ipParent, CATBaseUnknown* ipAfrModel, 
                                CATBaseUnknown** opViewModel ) = 0;

};
#endif
