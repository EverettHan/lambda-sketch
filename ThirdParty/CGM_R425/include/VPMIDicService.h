//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicService_h
#define _VPMIDicService_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMDicSECURITYPATTERN.h"
#include "VPMIDicElement.h"

class VPMIDicInputParameters;
class VPMIDicOutputParameters;
class VPMIDicReturnParameter;


#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicService;
#else
extern "C" const IID IID_VPMIDicService;
#endif

/**
 * Interface to manage the Service.
 */

class  ExportedByVPMIDicInterfaces VPMIDicService: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
         * Creates an InputParameters
         * @param oDicInputParameters : InputParameters [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT CreateInputParameters     ( VPMIDicInputParameters ** oDicInputParameters ) = 0;


        /**
         * Creates an OutputParameters
         * @param oDicInputParameters : OutputParameters [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT CreateOutputParameters    ( VPMIDicOutputParameters ** oDicOutputParameters ) = 0;


        /**
         * Creates a ReturnParameters
         * @param oDicReturnParameter : ReturnParameter [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
        */
        virtual HRESULT CreateReturnParameter     ( VPMIDicReturnParameter ** oDicReturnParameter ) = 0;


        /**
         * Retrieves the InputParameters
         * @param oDicInputParameters : InputParameters [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
        */
        virtual HRESULT GetInputParameters        ( VPMIDicInputParameters ** oDicInputParameters ) = 0;


        /**
         * Retrieves the OutputParameters
         * @param oDicOutputParameters : OutputParameters [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
        */
        virtual HRESULT GetOutputParameters       ( VPMIDicOutputParameters ** oDicOutputParameters ) = 0;


        /**
         * Retrieves the ReturnParameter
         * @param oDicReturnParameter : ReturnParameters [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
        */
        virtual HRESULT GetReturnParameter        ( VPMIDicReturnParameter ** oDicReturnParameter ) = 0;


        /**
         * Retrieves the SecurityPattern
         * @param oSecurityPattern : the SecurityPattern
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
        */
        virtual HRESULT GetSecurityPattern        ( VPMDicSECURITYPATTERN *oSecurityPattern ) = 0;


        /**
         * Sets the SecurityPattern
         * @param iSecurityPattern : the Security Pattern
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
        */
        virtual HRESULT SetSecurityPattern        ( const VPMDicSECURITYPATTERN iSecurityPattern ) = 0;


        /**
         * Retrieves the LicenceOption mode
         * @param oLicenceOption : the Licence Option mode
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
        */
        virtual HRESULT GetLicenceOption          ( boolean * oLicenceOption ) = 0;


        /**
         * Sets the LicenceOption mode
         * @param iLicenceOption : the Licence Option mode
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
        */
        virtual HRESULT SetLicenceOption          ( boolean iLicenceOption ) = 0;


        /**
         * Retrieves the WriteAccess mode
         * @param oWriteAccess : the Write Access mode
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
        */
        virtual HRESULT GetWriteAccess          ( boolean * oWriteAccess ) = 0;


        /**
         * Sets the WriteAccess mode
         * @param iWriteAccess : the Write Access mode
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
        */
        virtual HRESULT SetWriteAccess          ( boolean iWriteAccess ) = 0;

};
#endif
