//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicInputParameters_h
#define _VPMIDicInputParameters_h

#include "VPMIDicInterfaces.h"

#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"

#include "CATString.h"

class VPMIDicSimpleParameter;
class VPMIDicRelationshipParameter;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicInputParameters;
#else
extern "C" const IID IID_VPMIDicInputParameters;
#endif


/**
 * Interface to manage the InputParameters that can be defined for a Service.
 */

class  ExportedByVPMIDicInterfaces VPMIDicInputParameters: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
         * Creates a SimpleParameter.
         * @param iName : the SimpleParameter name
         * @param iName : the SimpleParameter Uuid
         * @param oDicSimpleParameter : the SimpleParameter [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT CreateSimpleParameter       ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicSimpleParameter ** oDicSimpleParameter ) = 0;


        /**
         * Creates a RelationshipParameter.
         * @param iName : the RelationshipParameter name
         * @param iName : the RelationshipParameter Uuid
         * @param oDicSimpleParameter : the RelationshipParameter [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT CreateRelationshipParameter ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicRelationshipParameter ** oDicRelationshipParameter ) = 0;


        /**
         * Retrieves the list of input parameters.
         * @param ioElements : the list of input parameters.
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetParameters               ( CATLISTP(IUnknown) * ioElements ) = 0;

};
#endif
