#ifndef __CATIOmbSwitchExits_H
#define __CATIOmbSwitchExits_H

#include "CATOmbSwitchEngine.h"
#include "CATBaseUnknown.h"
#include "CATBooleanDef.h"
#include "CATUnicodeString.h"
#include "CATOmxArray.h"
#include "CATOmbStreamDescriptorDefinitionQualifiers.h"

extern ExportedByCATOmbSwitchEngine const IID IID_CATIOmbSwitchExits;

/**
 * Implement this interface to control some details of switch engine stream descriptor loading.
 * It must be implemented on the late type "CATOmbSwitchExitsFor<late type of the authoring stream descriptor>".
 * Use @href CATCreateAndAddOMFactoryFunction to register class factory
 */
class ExportedByCATOmbSwitchEngine CATIOmbSwitchExits: public CATBaseUnknown
{
  CATDeclareInterface;
public:
  struct Parameters 
  {
    CATUnicodeString SourceMode; //Switch source mode
    CATUnicodeString DestinationMode; //switch destination mode
    CATUnicodeString LateType; //Late type of the document of the main authoring stream descriptor
    CATUnicodeString Role; //role of the of the main authoring stream descriptor
  };

  /**
   * if output list is filled then corresponding stream will be available when switch transition will be performed.
   */
  virtual HRESULT ListAdditionalStreamsForLoad(const Parameters& iSwitchTransition,CATOmxArray<CATOmbStreamDescriptorDefinitionQualifiers>& oListSDKeys) {return E_NOTIMPL;} //FIXME, to replace by pure virtual function once MecMod implements it.

  //Helper function
  HRESULT TransitionWillLoadMainAuthoring(const Parameters& iSwitchTransition) const;
};


#endif

