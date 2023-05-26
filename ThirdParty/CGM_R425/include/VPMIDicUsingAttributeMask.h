//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicUsingAttributeMask_h
#define _VPMIDicUsingAttributeMask_h

#include "VPMIDicInterfaces.h"

#include "VPMIDicElement.h"
#include "VPMDicCOLLECTION.h"
#include "VPMDicACCESSMODE.h"
#include "VPMDicPRIMITIVEType.h"

class VPMIDicAttributeMask;
class VPMIDicSimple;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicUsingAttributeMask;
#else
extern "C" const IID IID_VPMIDicUsingAttributeMask;
#endif

/**
 * To manage the definition of an UsingAttributeMask object
 */

class  ExportedByVPMIDicInterfaces VPMIDicUsingAttributeMask : public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
         * Retrieves the referred AttributeMask.
         * @param oDicAttributeMask [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetTarget     ( VPMIDicAttributeMask ** oDicAttributeMask ) = 0;


        /**
         * Sets the referred AttributeMask.
         * @param iDicAttributeMask
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT SetTarget     ( const VPMIDicAttributeMask * iDicAttributeMask ) = 0;


        /**
         * Sets the UsingAttributeMask's AccessMode property.
         * @param iAccMode
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT SetAccessMode ( const VPMDicACCESSMODE iAccMode ) = 0;


        /**
         * Sets the UsingAttributeMask's Mandatory property.
         * @param iMandatory
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT SetMandatory  ( boolean iMandatory ) = 0;


        /**
         * Sets the UsingAttributeMask's Order property.
         * @param iOrder
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT SetOrder      ( int Order ) = 0;


        /**
         * Retrieves the AccessMode property.
         * @param oAccMode
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetAccessMode       ( VPMDicACCESSMODE * oAccMode ) = 0;


        /**
         * Retrieves the authorized values list.
         * @param oAuthorizedValues
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetAuthorizedValues ( CATListOfCATUnicodeString & oAuthorizedValues, const boolean iNLS = CATFalse ) = 0;

        /**
         * Retrieves the CollectionType property.
         * @param CollType
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetCollectionType   ( VPMDicCOLLECTION * oCollType ) = 0;


        /**
         * Retrieves the default value.
         * NB: The default value is assigned either from the explicit definition of the metadata, from the explicit definition of the P&O mask, or from the implicit default value for the primitive type of the underlying Simple. In all cases, RC is set to S_OK; therefore RC = E_FAIL means that a severe internal unexpected problem has occured.
         * @param oDefaultValue the default value, if any
         * @param oIndex        if the underlying Simple is an enumeration, oIndex is the index of the Enumerator defined as default
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded, a significant defaut value was returned.</li>
         *    <li>S_FALSE  Operation succeeded, but no default value was found to be returned.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetDefault          ( CATUnicodeString * oDefaultValue, const boolean iNLS = CATFalse ) = 0;


        /**
         * Retrieves the help values list.
         * @param oHelpValues
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetHelpValues       ( CATListOfCATUnicodeString & oHelpValues ) = 0;


        /**
         * Retrieves the Lower property.
         * @param oLow
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetLower            ( int * oLow ) = 0;


        /**
         * Retrieves the Magnitude property.
         * @param oMagnitude
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetMagnitude        ( CATUnicodeString * oMagnitude ) = 0;


       /**
         * @deprecated
         * @nodoc
         */
        virtual HRESULT GetMandatory        ( boolean * oMandatory ) = 0;


        /**
         * Retrieves the MaxLength property.
         * @param oMaxLength
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetMaxLength        ( int * oMaxLength ) = 0;


        /**
         * Retrieves the MultiValuated property.
         * @param oMulti
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetMultiValuated    ( boolean * oMulti ) = 0;


        /**
         * Retrieves the Order property.
         * @param oOrder
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetOrder            ( int * oOrder ) = 0;


        /**
         * Retrieves the referred Simple (via the referred AttributeMask).
         * @param oDicSimple [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetTargetSimple     ( VPMIDicSimple ** oDicSimple ) = 0;


        /**
         * Retrieves the referred Primitive type.
         * @param oPrimitiveType [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetType             ( VPMDicPRIMITIVEType * oPrimitiveType ) = 0;


        /**
         * Retrieves the Upper property.
         * @param oUpp
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetUpper            ( int * oUpp ) = 0;


        /**
         * Retrieves the ExtendedEnterprise property.
         * @param oExtendedEnterprise either True or False, depending on whether the Attribute related to the UsingAttributeMask is ExtendedEnterprise="Yes" or ="No".</li>
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetExtendedEnterprise ( boolean * oExtendedEnterprise ) = 0;


        /**
         * Retrieves the NLSValue of the Simple or the Volatile pointed by the UsingAttributeMask.
         * NB: the Class pointed by the Mask to which the current UsingAttributeMask is taken into account to retrieve the NLS value.
         * @param oNLSValue : NLSValue
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetTargetElementNLSValue  ( CATUnicodeString & oNLSValue ) = 0;


        /**
         * Retrieves the Name of the Simple or the Volatile pointed by the UsingAttributeMask.
         * @param oName : the Name of the Simple or the Volatile
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetTargetElementName  ( CATUnicodeString & oName ) = 0;


        /*
        * @nodoc
        */
        virtual CATUnicodeString getID () = 0; //-- 2011: un truc pour l'Etape 1 dans la gestion des MaskedAttributes

};

CATDeclareHandler(  VPMIDicUsingAttributeMask,  VPMIDicElement  );

#endif
