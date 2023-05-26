//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef VPMIDicEnvironment_h
#define VPMIDicEnvironment_h

#include "VPMIDicInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATLISTPIUnknown.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

#include "VPMDicADMINTYPE.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicEnvironment;
#else
extern "C" const IID IID_VPMIDicEnvironment;
#endif

class  ExportedByVPMIDicInterfaces VPMIDicEnvironment : public CATBaseUnknown
{
    CATDeclareInterface;

public:
    /**
    * Adds a Custo Package as Usable in the current Environment.
    * The Custo Package can optionnaly become Authoring, in which case the previous Authoring Package
    * is simply switched as Usable.
    * @param iPackageName : Package name
    * @param isAuthoring  : either 0/false (default) or 1/true to specify whether the Package
    *                       becomes the new Authoring Package for the current Environemnt
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT AddCustoPackage( const CATUnicodeString& iPackageName, int isAuthoring = 0 ) = 0;

    /**
    * Retrieves the names list of the Environment's Packages defined as "authoring".
    * @param oAuthoringPackageNameList : List of the Packages names
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetAuthoringPackageNames( CATListOfCATUnicodeString& oAuthoringPackageNameList ) = 0;

    /**
    * Retrieves the names list of the Environment's Packages defined as "usable".
    * @param oUsablePackageNameList : List of the Packages names
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetUsablePackageNames( CATListOfCATUnicodeString& oUsablePackageNameList ) const = 0;

    /**
    * Retrieves the names list of the Environment's Packages defined as "usable" for a given Modeler.
    * @param iModelerName : Modeler name
    * @param oUsablePackageNameList : List of the Packages names
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetUsablePackageNames( const CATUnicodeString& iModelerName, CATListOfCATUnicodeString& oUsablePackageNameList ) const = 0;

    /**
    * Retrieves the names list of the Classes described in the "usable" Packages for a given Modeler.
    * @param iModelerName : Modeler name
    * @param iCoreTypeName : CoreType name (PLMConnection, PLMCoreInstance, PLMCoreRepInstance, PLMCoreReference, PLMCoreRepReference, or PLMPort)
    * @param oUsableClassNameList : List of the Class names
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetUsableClassNames( const CATUnicodeString& iModelerName, const CATUnicodeString& iCoreTypeName, CATListOfCATUnicodeString& oUsableClassNameList ) const = 0;

    /**
    * Adds a Top Package as Usable in the current Environment.
    * The Top Package can optionnaly become Authoring, in which case the previous Authoring Package
    * is simply switched as Usable.
    * @param iPackageName : Package name
    * @param isAuthoring  : either 0/false (default) or 1/true to specify whether the Package
    *                       becomes the new Authoring Package for the current Environemnt
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT AddPackage( const CATUnicodeString& iPackageName, int isAuthoring = 0 ) = 0;

    /**
    * Retrieves the Admin Object type.
    */
    virtual VPMDicADMINTYPE Type() = 0;

    /**
    * Retrieves the admin object name.
    * @param oName : admin object name
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetName( CATUnicodeString& oName ) = 0;
};

#endif /*VPMIDicEnvironment_h*/
