//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicElementH_h
#define _VPMIDicElementH_h

#include "VPMIDicInterfaces.h"

#include "VPMDicTYPE.h"

#include "CATBaseUnknown.h"
class CATDbBinary;
class CATString;

/**
 * VPMIDicElementH is the base interface of all Package's Elements
 * Mandatory Interface
 *
 *<p>
 * <br>
*/

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicElementH;
#else
extern "C" const IID IID_VPMIDicElementH;
#endif

class  ExportedByVPMIDicInterfaces VPMIDicElementH : public CATBaseUnknown
{
    CATDeclareInterface;

    public:
        /**
        * Retrieves the object type.
        * @param oType : Dictionary object type
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetType ( VPMDicTYPE * oType ) = 0;


        /**
        * Retrieves the object UUID.
        * @param oUuid : Dictionary object UUID
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetUuid ( CATDbBinary * oUuid ) = 0;


        /**
        * Retrieves the object name.
        * @param oName : Dictionary object name
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetName ( CATString * oName ) = 0;        //-- chd, rajoute le 01/02/2005

};
#endif
