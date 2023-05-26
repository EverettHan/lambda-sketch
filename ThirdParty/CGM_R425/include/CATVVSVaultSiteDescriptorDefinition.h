/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================


#ifndef CATVVSVaultSiteDescriptorDefinition_H
#define CATVVSVaultSiteDescriptorDefinition_H

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATVVSUnicodeStringHashtable.h"
#include "VVSCoreStructure.h"
/**
 * 
 */
class ExportedByVVSCoreStructure CATVVSVaultSiteDescriptorDefinition
{
  friend class CATVVSVaultSiteDescriptor ;

  public:
  
  /**
   * Construct a new CATVVSVaultSiteDescriptorDefinition
   */
  CATVVSVaultSiteDescriptorDefinition(const CATUnicodeString& iUserName);

  /**
   * Destructor
   */
  ~CATVVSVaultSiteDescriptorDefinition ();


  /**
   * Declares the Component that will be instantiated and that will implement
   * the behavior of the Vault
   * @param iLateType
   * The  late type of the Component 
   * @return
   * S_OK if the Property has been added , otherwise S_FALSE.
   */
  HRESULT DeclareComponentImplementingVaultBehavior(const CATUnicodeString& iLateType) ;

  /**
   * Read the late type of the Component that will be instantiated and that will implement
   * the behavior of the Vault
   * @param oLateType
   * The  late type of the Component 
   * @return
   * S_OK if the Property can be read , otherwise S_FALSE.
   */
  HRESULT ReadComponentImplementingVaultBehavior(CATUnicodeString& oLateType) ;

  /**
   * Declares a Property to be used by the component implementing the Protocol CATIVVSURLLifeCycleManagement
   * It is passed at the initialisation of the component
   * The component used ( defined by its late type) defines its required properties
   * @param iKey
   * The  Key of the Property
   * @param iValue
   * The  Value of the Property
   * @return
   * S_OK if the Property has been added , otherwise S_FALSE.
   */
  HRESULT DeclareProperty(const CATUnicodeString& iKey,const CATUnicodeString& iValue) ;

  /**
   * Declares a Resource to be used by the component implementing the Protocol CATIVVSURLLifeCycleManagement
   * It is passed at the initialisation of the component
   * The component used ( defined by its late type) defines its required properties
   * @param iKey
   * The  Key of the Property
   * @param iResource
   * The  Value of the Property
   * @return
   * S_OK if the Property has been added , otherwise S_FALSE.
   */  
  HRESULT DeclareAResource(const CATUnicodeString& iKey,CATBaseUnknown* iValue) ;

  /**
   * Read the name of the Component that will be instantiated and that will implement
   * the behavior of the Vault
   * @param oName
   * The Nale of the Component 
   * @return
   * S_OK if the Property can be read , otherwise S_FALSE.
   */
  HRESULT ReadComponentName(CATUnicodeString& oName);


  private :

    HRESULT CloneResource(CATVVSUnicodeStringHashtable& oInputParameters) ;


	CATVVSUnicodeStringHashtable _values ;

    static  CATUnicodeString Name ;
    static  CATUnicodeString ComponentClass ;

};

#endif


