//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicInterface_h
#define _VPMIDicInterface_h

#include "VPMIDicInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATString.h"

#include "VPMIDicElement.h"
#include "CATListOfVPMIDicService.h"
#include "CATListOfVPMIDicAttribute.h"

class VPMIDicService;
class VPMIDicSimple;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicInterface;
#else
extern "C" const IID IID_VPMIDicInterface;
#endif


class  ExportedByVPMIDicInterfaces VPMIDicInterface: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
        * Get the super Interface of the current Interface.
        * @param oSuperInterface [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetSuperInterface ( VPMIDicInterface ** oSuperInterface) = 0;

        /**
        * Set the super Interface of the current Interface.
        * @param iSuperInterface
        * @return S_OK, E_FAIL
        */
        virtual HRESULT SetSuperInterface ( const VPMIDicInterface * iSuperInterface) = 0;

        /**
        * Create a Service element for the current Interface.
        * @param iName Name of the Service
        * @param iUuid Uuid of the Service
        * @param oDicService the Service element [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT CreateService     ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicService ** oService ) = 0;

        /**
        * Get a Service element of the current Interface according to its name.
        * @param iName Name of the Service
        * @param iWithInherited taking into account Services possibly defined in super Interface
        * @param oService the Sevice [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetService        ( const CATString * iName, VPMIDicService ** oDicService, boolean iWithInherited = CATTrue ) = 0;

        /**
        * Get the list of Service elements of the current Interface.
        * @param iWithInherited taking into account Services possibly defined in super Interface
        * @param oDicServiceList (each element of the list should also be released by the caller)
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetServices       ( CATListOfVPMIDicService & oDicServiceList, boolean iWithInherited = CATTrue  ) = 0;

        /**
        * Create a Simple element for the current Interface.
        * @param iName Name of the Service
        * @param iUuid Uuid of the Service
        * @param oSimple the Simple element [out, CATBaseUnknown#Release]
        * @return S_OK, E_FAIL
        */
        virtual HRESULT CreateSimple      ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicSimple  ** oSimple ) = 0;

        /**
        * Get the list of Attribute elements of the current Interface.
        * @param oDicAttributeList (each element of the list should also be released by the caller)
        * @return S_OK, E_FAIL
        */
        virtual HRESULT GetAttributes     ( CATListOfVPMIDicAttribute & oDicAttributeList ) = 0;
};
#endif
