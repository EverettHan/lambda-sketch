//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicEnumerator_h
#define _VPMIDicEnumerator_h

#include "VPMIDicInterfaces.h"
#include "VPMIDicElement.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByVPMIDicInterfaces const IID IID_VPMIDicEnumerator;
#else
extern "C" const IID IID_VPMIDicEnumerator;
#endif

class ExportedByVPMIDicInterfaces VPMIDicEnumerator: public VPMIDicElement
{
    CATDeclareInterface;

public:
    /**
    * Sets the integer value of the current Enumerator.
    * @param iValue Value of the Enumerator
    * @return S_OK, E_FAIL
    */
    virtual HRESULT SetValue ( int Value ) = 0;


    /**
    * Gets the integer value of the current Enumerator.
    * @param oValue Value of the Enumerator
    * @return S_OK, E_FAIL
    */
    virtual HRESULT GetValue ( int * oValue ) = 0;
};

#endif
