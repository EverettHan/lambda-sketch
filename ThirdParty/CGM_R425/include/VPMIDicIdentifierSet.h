//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicIdentifierSet_h
#define _VPMIDicIdentifierSet_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATLISTPIUnknown.h"
#include "VPMDicTYPE.h"
#include "VPMIDicElement.h"

class VPMIDicAttribute;
class VPMIDicClass;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicIdentifierSet;
#else
extern "C" const IID IID_VPMIDicIdentifierSet;
#endif

class  ExportedByVPMIDicInterfaces VPMIDicIdentifierSet: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
        * Add an Attribute element in the current IdentifierSet definition.
        * @param iElement Attribute to be added in the IdentifierSet definition
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT AddElement    ( const VPMIDicAttribute * iElement ) = 0;


        /**
        * Remove an Attribute element from the current IdentifierSet definition.
        * @param iElement Attribute to be removed from the IdentifierSet definition
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT RemoveElement ( const VPMIDicAttribute * iElement ) = 0;


        /**
        * Get the list of all Attribute elements taking part in the IdentifierSet definition.
        * @param ioElements List of Attribute elements taking part in the IdentifierSet definition
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetElements   ( CATLISTP(IUnknown) * ioElements ) = 0;


        /**
        * Get the Class to which the current IdentifierSet belongs.
        * @param oClass the Class to which the current IdentifierSet belongs [out, CATBaseUnknown#Release]
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetOrigin     ( VPMIDicClass ** oClass ) = 0;
}
;
#endif

