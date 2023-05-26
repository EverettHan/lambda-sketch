#ifndef CATICAfrDumpUtility_H
#define CATICAfrDumpUtility_H

// COPYRIGHT Dassault Systemes 2013/08/13

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATICAfrComponent;

extern ExportedByCATAfrItf  IID IID_CATICAfrDumpUtility ;

//-----------------------------------------------------------------------------
/**
* Interface managed dump for odt context.
**/
class ExportedByCATAfrItf CATICAfrDumpUtility: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Dumps and compares the component betwen recorded file and referenced file.
    */
    virtual HRESULT DumpAndCompareComponent( CATICAfrComponent* ipiComponent ) = 0;
};
#endif
