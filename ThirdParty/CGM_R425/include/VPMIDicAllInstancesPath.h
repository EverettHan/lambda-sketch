//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicAllInstancesPath_h
#define _VPMIDicAllInstancesPath_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicPathOfInstancesConstraint.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicAllInstancesPath;
#else
extern "C" const IID IID_VPMIDicAllInstancesPath;
#endif

/**
 * Interface to manage the VPMIDicAllInstancesPath.
 */

class  ExportedByVPMIDicInterfaces VPMIDicAllInstancesPath: public VPMIDicPathOfInstancesConstraint
{
    CATDeclareInterface;

    public:

        /**
        * Method Short Description.
        * Method Long Description.
        * @param
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
//        virtual HRESULT UneMethode ( const CATString BlahBlahBlah ) = 0;
};
#endif
