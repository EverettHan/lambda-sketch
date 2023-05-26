//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicRelationshipParameter_h
#define _VPMIDicRelationshipParameter_h

#include "VPMIDicInterfaces.h"

#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"
#include "CATString.h"

class VPMIDicClass;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicRelationshipParameter;
#else
extern "C" const IID IID_VPMIDicRelationshipParameter;
#endif

/**
 * Interface to manage the RelationshipParameter.
 */

class  ExportedByVPMIDicInterfaces VPMIDicRelationshipParameter: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
         * Sets the Class referred by the RelationshipParameter.
         * @param iClass : the Class referred by the RelationshipParameter
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT SetTarget ( const VPMIDicClass *iClass ) = 0;


        /**
         * Retrieves the Class referred by the RelationshipParameter.
         * @param oClass : the Class referred by the RelationshipParameter [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
        virtual HRESULT GetTarget ( VPMIDicClass **oOClass ) = 0;
};
#endif
