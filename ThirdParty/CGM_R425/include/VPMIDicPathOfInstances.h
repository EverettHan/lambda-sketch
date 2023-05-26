//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicPathOfInstances_h
#define _VPMIDicPathOfInstances_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicPathOfInstances;
#else
extern "C" const IID IID_VPMIDicPathOfInstances;
#endif

class VPMIDicAllInstancesPath;
class VPMIDicBeginWithPath;

/**
 * Interface to manage the VPMIDicPathOfInstances.
 */

class  ExportedByVPMIDicInterfaces VPMIDicPathOfInstances: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
        * Get the minimal depth of the current PathOfInstances element.
        * @param oMinDepth the MinDepth value
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetMinDepth ( int & oMinDepth ) const = 0;

        /**
        * Get the maximal depth of the current PathOfInstances element.
        * @param oMaxDepth the MaxDepth value
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetMaxDepth ( int & oMaxDepth ) const = 0;

        /**
        /**
        * Test whether the current PathOfInstances declares that the last component of the path is movable, or not.
        * @return true/false.
        */
        virtual boolean IsEndingWithAMovable () const = 0;
        virtual HRESULT IsEndingWithAMovable ( boolean & oIsEndingWithAMovable ) const = 0;

        /**
        * Get the AllInstancesPath element of the current PathOfInstances, if any.
        * @param oDicAllInstancesPath : the AllInstancesPath element [out, CATBaseUnknown#Release]
        * @return
        *    <ul>
        *    <li>S_OK     A AllInstancesPath was found.</li>
        *    <li>S_FALSE  No AllInstancesPath was found.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetAllInstancesPath ( VPMIDicAllInstancesPath ** oDicAllInstancesPath ) const = 0;

        /**
        * Get the BeginWithPath element of the current PathOfInstances, if any.
        * @param oDicBeginWithPath : the BeginWithPath element [out, CATBaseUnknown#Release]
        * @return
        *    <ul>
        *    <li>S_OK     A BeginWithPath was found.</li>
        *    <li>S_FALSE  No BeginWithPath was found.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetBeginWithPath ( VPMIDicBeginWithPath ** oDicBeginWithPath ) const = 0;

        /**
        * Retrieve the list of InstancePath elements of the current PathOfInstances.
        * @param oDicInstancePathList : list of InstancePath elements
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, the list is not empty.</li>
        *    <li>S_FALSE  Operation succeeded, but the list is empty.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetInstancePathList ( CATLISTP(IUnknown) * oDicInstancePathList ) const = 0;
};
#endif
