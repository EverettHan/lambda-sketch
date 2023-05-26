// COPYRIGHT Dassault Systemes 2019
//===================================================================
//
// CATIPLMFilterAttributeRestricted.h
// Define the CATIPLMFilterAttributeRestricted interface
//
//===================================================================
//
// Usage notes:
//   New interface: Filter on attribute can be made on database (default mode) or on server
//                  USE of this method is authorized only if you have received a request from performance team/server team/PLMAdapter team
//
//                  DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!!
//                  DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!!
//                  DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!!
//                  DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!! DON T REEXPOSE CURRENT SERVICE!!!
//
//===================================================================
// Sept 2019  Creation: EPB
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMFilterAttributeRestricted_H
#define CATIPLMFilterAttributeRestricted_H

#include "CATPLMServicesItf.h"

#include "CATBaseUnknown.h"

extern ExportedByCATPLMServicesItf IID IID_CATIPLMFilterAttributeRestricted;

class ExportedByCATPLMServicesItf CATIPLMFilterAttributeRestricted : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /*@deprecated*/
  enum eLocation{eDatabase,eServer};
  /*@deprecated*/
  virtual HRESULT SetLocationOfFiltering(eLocation iLocation) = 0;

  // Filtering on attribute can be made:
  // - On SQL level and so on database (default mode). iProperty == CATIPLMFilterAttributeRestricted::eDiscriminating eg of discriminating attribute: physicalid
  // - Later (!!!) on MQL level so on M1 server.  iProperty = CATIPLMFilterAttributeRestricted::eNotDiscriminating eg of not discriminating attribute: V_description
  //
  // USE of this method is authorized only if you have received a request from performance team/server team/PLMAdapter team
  enum eAttributeProperty{ eDiscriminating, eNotDiscriminating };

  virtual void SetAttributeProperty(eAttributeProperty iProperty) = 0;
};

#endif
