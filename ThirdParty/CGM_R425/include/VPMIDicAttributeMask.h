//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */

#ifndef _VPMIDicAttributeMask_h
#define _VPMIDicAttributeMask_h

#include "VPMIDicInterfaces.h"
#include "VPMIDicElement.h"

class VPMIDicSimple;
class VPMIDicElement;
class VPMIDicEnum;
class VPMIDicEnumerator;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicAttributeMask;
#else
extern "C" const IID IID_VPMIDicAttributeMask;
#endif

/**
 * To manage the definition of an AttributeMask object
 */

class  ExportedByVPMIDicInterfaces VPMIDicAttributeMask : public VPMIDicElement
{
    CATDeclareInterface;

    public:
        /**
        * @nodoc
        * @deprecated
        * @param oDicSimple [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetTarget             ( VPMIDicSimple ** oDicSimple ) = 0;


        /**
        * @nodoc
        * @deprecated
        * @param iDicSimple
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetTarget             ( const VPMIDicSimple * iDicSimple ) = 0;


        /**
        * @nodoc
        * @param oAuthorizedValues
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetAuthorizedValues   ( CATListOfCATUnicodeString & oAuthorizedValues, const boolean iNLS = CATFalse ) = 0;


        /**
        * @deprecated
        * @param iEnumerator
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetAuthorizedValue    ( const VPMIDicEnumerator * iEnumerator ) = 0;


        /**
        * @nodoc
        * @param iAuthorizedValues
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetAuthorizedValues   ( const CATListOfCATUnicodeString & iAuthorizedValues ) = 0;


        /**
        * @deprecated
        * @param oEnum [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetAuthorizedValueEnum( VPMIDicEnum ** oEnum ) = 0;


        /**
        * @nodoc
        * @param oHelpValues
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetHelpValues         ( CATListOfCATUnicodeString & oHelpValues ) = 0;


        /**
        * @nodoc
        * @param oEnum [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetHelpValueEnum      ( VPMIDicEnum ** oEnum ) = 0;


        /**
        * @nodoc
        * @param iEnumerator
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetHelpValue          ( const VPMIDicEnumerator * iEnumerator ) = 0;


        /**
        * @nodoc
        * @param iEnum
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetHelpValueEnum      ( const VPMIDicEnum * iEnum ) = 0;


        /**
        * @nodoc
        * @param iHelpValues
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetHelpValues         ( const CATListOfCATUnicodeString & iHelpValues ) = 0;


        /**
         * Retrieves the default value.
         * @param oDefaultValue
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded, a significant defaut value was returned.</li>
         *    <li>S_FALSE  Operation succeeded, but no default value was found to be returned.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetDefaultValue       ( CATUnicodeString & oDefaultValue, int * oIndex = NULL ) = 0;


        /**
        * @nodoc
        * @param oEnumerator [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetDefaultValue       ( VPMIDicEnumerator ** oEnumerator ) = 0;


        /**
        * @nodoc
        * @param iDefaultValue
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetDefaultValue       ( const CATUnicodeString & iDefaultValue ) = 0;


        /**
        * @nodoc
        * @param iEnumerator
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetDefaultValue       ( const VPMIDicEnumerator * iEnumerator ) = 0;


        /**
        * @nodoc
        * @param iEnumerator
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetValidValue         ( const VPMIDicEnumerator * iEnumerator ) = 0;


        /**
        * @nodoc
        * @param oEnumerators
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetValidValueTargets  ( CATLISTP(IUnknown) * oEnumerators ) = 0;


        /**
        * @nodoc
        * @param oDicElement [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetTarget             ( VPMIDicElement ** oDicElement ) = 0;


        /**
        * @nodoc
        * @param iDicElement
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetTarget             ( const VPMIDicElement * iDicElement ) = 0;


};
#endif
