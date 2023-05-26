//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicSimpleParameter_h
#define _VPMIDicSimpleParameter_h

#include "VPMIDicInterfaces.h"

#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"

class VPMIDicPrimitive;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicSimpleParameter;
#else
extern "C" const IID IID_VPMIDicSimpleParameter;
#endif

/**
 * Interface to manage the SimpleParameter.
 */

class  ExportedByVPMIDicInterfaces VPMIDicSimpleParameter: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
         * Retrieves the maximum length of the SimpleParameter.
         * @param oMax : the SimpleParameter's length
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetMaxLength ( int * oMax ) = 0;


        /**
         * Sets the maximum length of the SimpleParameter.
         * @param iMax : the SimpleParameter's length
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT SetMaxLength ( int Max ) = 0;


        /**
         * Sets the Primitive type of the SimpleParameter.
         * @param iPrimitive : the SimpleParameter's Primitive
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT SetPrimitive ( const VPMIDicPrimitive *iPrimitive ) = 0;


        /**
         * Retrieves the Primitive type of the SimpleParameter.
         * @param oPrimitive : the SimpleParameter's Primitive [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetPrimitive ( VPMIDicPrimitive **oPrimitive ) = 0;

};
#endif
