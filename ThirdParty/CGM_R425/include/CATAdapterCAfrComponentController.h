// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATAdapterCAfrComponentController
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Fev 2011  Creation                                                   T. Pech
//=============================================================================
#ifndef CATAdapterCAfrComponentController_H
#define CATAdapterCAfrComponentController_H

#include "CATAfrItf.h"
#include "CATICAfrComponentController.h"
#include "CATString.h"

class CATCAfrComponentControllerArg;

//-----------------------------------------------------------------------------
class ExportedByCATAfrItf CATAdapterCAfrComponentController: public CATICAfrComponentController
{
  CATDeclareClass;

  public:
    CATAdapterCAfrComponentController ();
    virtual ~CATAdapterCAfrComponentController ();

    virtual HRESULT ComponentAction( CATCAfrComponentControllerArg* ipControllerArg );

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATAdapterCAfrComponentController (CATAdapterCAfrComponentController &);
    CATAdapterCAfrComponentController& operator=(CATAdapterCAfrComponentController&);

};
#endif
