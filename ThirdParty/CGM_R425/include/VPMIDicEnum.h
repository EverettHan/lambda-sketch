//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicEnum_h
#define _VPMIDicEnum_h

#include "VPMIDicInterfaces.h"

#include "CATLISTPIUnknown.h"
#include "VPMIDicElement.h"
#include "VPMDicCUSTOMEREXPOSITION.h"
#include "VPMDicCUSTOMEREXPOSITIONPURPOSE.h"

class VPMIDicEnumerator;
class VPMIDicPrimitive;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByVPMIDicInterfaces const IID IID_VPMIDicEnum;
#else
extern "C" const IID IID_VPMIDicEnum;
#endif

class ExportedByVPMIDicInterfaces VPMIDicEnum: public VPMIDicElement
{

    CATDeclareInterface;

    public:

        /* begin old */
        /**
        * Creates an Enumerator element for the current Enum.
        * Because the Enumerator's Name and Value are given here, the Enumerator does not need to be completed, and therefore the pointer on the newly created Enumerator is not returned (unlike with the CreateEnumerator method).
        * @param iName Name of the Enumerator
        * @param iValue Value of the Enumerator
        * @return S_OK, E_FAIL
        */
        virtual HRESULT CreateEnumValue ( const CATString *iName , int Value ) = 0;

        /**
        * Gets the Value of a given Enumerator of the current Enum.
        * @param iName Name of the Enumerator
        * @param iValue Value of the Enumerator
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetEnumValue ( const CATString *iEnumValue ,  int *oValue ) = 0;

        /**
        * Removes a given Enumerator element of the current Enum.
        * @param iName Name of the Enumerator
        * @return S_OK, E_FAIL
        */
        virtual HRESULT RemoveEnumValue ( const CATString *iName ) = 0;

        /**
        * Gets all the Names of the Enumerator elements of the current Enum.
        * NB: this method is not well named, because it does not get the Values (i.e. integers values) of the Enumerators defined in the Enum, but their Names!
        * @param ioListOfEnumValue Name of the Enumerator
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetEnumValues ( CATListOfCATString *ioListOfEnumValue ) = 0;
        /* end odl */

        /**
        * Creates an Enumerator element for the current Enum.
        * @param iName
        * @param iUuid
        * @param oEnumerator [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT CreateEnumerator ( const CATString *iName, const CATDbBinary * iUuid, VPMIDicEnumerator **oEnumerator ) = 0;

        /**
        * Gets an Enumerator element by its name.
        * @param iName
        * @param oEnumerator [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetEnumerator    ( const CATString *iName, VPMIDicEnumerator **oEnumerator ) = 0;

        /**
        * Removes an Enumerator element of the current Enum.
        * @param iName
        * @return S_OK, E_FAIL
        */
        virtual HRESULT RemoveEnumerator ( const CATString *iName ) = 0;

        /**
        * Gets the list of all the Enumerators of the current Enum
        * @param oEnumeratorList
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetEnumerators   ( CATLISTP(IUnknown) * oEnumeratorList ) = 0;

        /**
         * Sets the Primitive of the Enum.
         * @param iPrimitive : the Enum's Primitive
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT SetPrimitive ( const VPMIDicPrimitive *iPrimitive ) = 0;

        /**
         * Retrieves the Primitive of the Enum.
         * @param oPrimitive : the Enum's Primitive [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetPrimitive ( VPMIDicPrimitive **oPrimitive ) = 0;

        /**
        * @nodoc
        */
        virtual HRESULT SetCustomerExposition ( const VPMDicCUSTOMEREXPOSITION iCustomerExposition ) = 0;


        /**
        * @nodoc
        */
        virtual HRESULT IsExposedForPurpose ( const VPMDicCUSTOMEREXPOSITIONPURPOSE iPurpose, boolean & oIsExposed  ) const =0;
};


#endif
