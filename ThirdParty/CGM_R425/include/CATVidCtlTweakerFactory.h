#ifndef CATVidCtlTweakerFactory_h
#define CATVidCtlTweakerFactory_h

// COPYRIGHT Dassault Systemes 2011

#include <VisuDialog.h>
#include <CATUnicodeString.h>
#include <CATSYPBindingData.h>

class CATVidCtlTweaker;
class CATSYPPropertyDescriptorEx;
class CATVidCtl;
class CATVidCtlTweakerFactoryEx;
/**
 * Class used to create a CATVidCtlTweaker widget from a type name.
 * @see CATVidCtlTweaker
 */
class ExportedByVisuDialog CATVidCtlTweakerFactory
{
  public:

    /**
     * Builds the name of a tweaker to instantiate from a type
     */
    static CATUnicodeString BuildTweakerClassName(const CATUnicodeString& i_propertyType);

    /**
     * Instantiate a tweaker from its class name.
     */
    static CATVidCtlTweaker *InstanciateTweaker(const CATUnicodeString &i_tweakClassName);

    /**
     * Creates a new CATVidCtlTweaker from the given type name.
     * @param iTypeName
     * The name of the type corresponding to the tweak widget to create (e.g "int", "CATUnicodeString", ...).
     * @param i_pIdentifier
     * The identifier of the created CATVidCtlTweaker.
     * @param i_tweakType
     * The optional tweak type of the created CATVidCtlTweaker (e.g "bool" for the type "int").
     * @param i_tweakClassName 
     * The optional tweaker class name of the CATVidCtlTweaker to create; allows to customize pre-defined basic tweaker
     * such int or CATUnicodeString tweaker.
     */
    static CATVidCtlTweaker * CreateTweaker(const CATUnicodeString& i_typeName, 
                                            const CATString & i_pIdentifier, 
                                            const CATUnicodeString& i_tweakType = "",
                                            CATSYPPropertyDescriptorEx * i_pPropertyDescriptorEx = NULL,
                                            const CATUnicodeString& i_tweakClassName="");
    /**
    * Calls to CreateTweaker, embed it in a binding tweaker and propose properties binding features
    * @see CreateTweaker
    */
    static CATVidCtl* CreateBindingCtl(CATVidCtlTweaker* i_pTweaker, CATSYPBindingSourceData* i_pSourceDB);

private:
  static void SetExFactory(CATVidCtlTweakerFactoryEx* i_pTweakerFactoryEx);
  static CATVidCtlTweakerFactoryEx* _pTweakerFactoryEx;
  friend class CATVidCtlTweakerFactoryExImplFactory;
};

#endif // CATVidCtlTweakerFactory_h
