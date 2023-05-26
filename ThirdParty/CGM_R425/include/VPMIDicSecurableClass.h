//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicSecurableClass_h
#define _VPMIDicSecurableClass_h

#include "VPMIDicInterfaces.h"

#include "VPMIDicElement.h"

class VPMIDicClass;
class VPMIDicSecurableAttribute;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicSecurableClass;
#else
extern "C" const IID IID_VPMIDicSecurableClass;
#endif

/**
 * To manage the definition of a SecurableClass object
 */

class  ExportedByVPMIDicInterfaces VPMIDicSecurableClass : public VPMIDicElement
{
    CATDeclareInterface;

    public:


        /**
        * @deprecated
        */
        virtual HRESULT CreateSecurableAttribute  ( const CATUnicodeString & iName, const CATDbBinary & iUuid, VPMIDicSecurableAttribute ** oSecurableAttribute ) = 0;


        /**
        * @deprecated
        */
        virtual HRESULT GetListOfSecurableAttribute ( CATLISTP(IUnknown) & oSecurableAttributeList ) = 0;


        /**
        * @deprecated
        */
        virtual HRESULT GetTarget ( VPMIDicClass ** oDicClass ) = 0;


        /**
        * @deprecated
        */
        virtual HRESULT SetTarget ( const VPMIDicClass * iDicClass ) = 0;


};
#endif
