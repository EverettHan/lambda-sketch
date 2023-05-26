#ifndef __CATAdpQueryHelpers_H
#define __CATAdpQueryHelpers_H

// System
#include "CATError.h"
// ObjectModelerCollection
#include "CATOmxArray.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxIter.h"
#include "CATOmxKeyString.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxOHMap.h"
// CATPLMIdentificationAccess
#include "CATPLMID_Simple.h"
#include "CATPLMTypeH.h"
// CATPLMIntegrationAccess
#include "CATPLMIntegrationAccess.h"

/** 
 * @see CATAdpQueryChildrenAndAttributes
 */
struct CATAdpChildAndAttributes
{
  CATPLMID_Simple Id; //PLMID of the child
  CATOmxKeyValueBlock Attributes; //Requested attributes of the child
};

template<> 
ExportedByCATPLMIntegrationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATAdpChildAndAttributes>::manager();

template<> 
ExportedByCATPLMIntegrationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxArray<CATAdpChildAndAttributes> >::manager();

/**
 * Query children of a given set of objects
 * @param iTypesAndAttributes:
 *   children types that should be queried with their set of attribute (attributes set can be empty)
 * @param ioChildren:
 *   from/V_Owner of the objects which children must be retrieved
 *   in input, keys must be filled and associated with an empty list of CATAdpChildAndAttributes
 *   in output, values are filled with associated children
 * example:
 * retrieve all VPMPort aggregated by an object with their associated V_FunctionalName attribute:
 *
    static const CATOmxKeyString VPMPort("VPMPort"),V_FunctionalName("V_FunctionalName");
    //restrict the type of aggregated objects we want to retrieve and specify that V_FunctionalName must be retrieved
    CATOmxOHMap<CATPLMTypeH,CATOmxArray<CATOmxKeyString> > VPMPortWithFunctionalName;
    VPMPortWithFunctionalName[CATPLMTypeH(VPMPort)].Append(V_FunctionalName);

    //build the set of objects whose children must be retrieved
    CATOmxOHMap<CATPLMID_Simple,CATOmxArray<CATAdpChildAndAttributes> > referencesToVPMPorts;
    CATPLMID_Simple someReference = ... ; //some reference for which we want aggregated ports
    referencesToVPMPorts.Insert( someReference , CATOmxArray<CATAdpChildAndAttributes>() );

    //server query
    CATOmxIter<CATError> errors;
    HRESULT hr = CATAdpQueryChildren(VPMPortWithFunctionalName,referencesToVPMPorts,errors);

    //process results
    if(SUCCEEDED(hr))
    {
      CATOmxArray<CATAdpChildAndAttributes> ports = referencesToVPMPorts[someReference];
      for(int iPort=1; iPort<=ports.Size(); iPort++)
      {
        const CATPLMID_Simple portId = ports[iPort].Id;
        CATOmxAny portFunctionalNameAny;
        ports[iPort].Attributes.GetValue(V_FunctionalName,portFunctionalNameAny);
        const CATUnicodeString portFunctionalName = portFunctionalNameAny;

        //here we have the PLMID of some aggregated port (portId) and its associated V_FunctionalName attribute value (portFunctionalName)
      }
    }
 *
 */
ExportedByCATPLMIntegrationAccess HRESULT CATAdpQueryChildrenAndAttributes(const CATOmxOHMap<CATPLMTypeH,CATOmxArray<CATOmxKeyString> >& iTypesAndAttributes,CATOmxOHMap<CATPLMID_Simple,CATOmxArray<CATAdpChildAndAttributes> >& ioChildren,CATOmxIter<CATError>& oErrors);

/**
 * Query attributes of a set of objects
 * @param ioAttributes
 *   in input, it must contain a map PLMID => a CATOmxKeyValueBlock containing the requested attribute names associated to an unset CATOmxAny
 *   in output: the values of the CATOmxKeyValueBlock are filled with attributes value from server
 * 
 * @example:
 * retrieve V_FunctionalName attribute value for a VPMPort:
 *
  //build inputs of the service
  static const CATOmxKeyString V_FunctionalName("V_FunctionalName");
  CATPLMID_Simple someVPMPort = ... ;
  CATOmxOHMap<CATPLMID_Simple,CATOmxKeyValueBlock> ports;
  CATOmxKeyValueBlock attributes;
  attributes.SetValue(V_FunctionalName,CATOmxAny()); //add V_FunctionalName attribute associated with "unset" value
  ports.Insert(someVPMPort,attributes); //add id of the object associated with the attributes that must queried

  //server query
  CATOmxIter<CATError> errors;
  HRESULT hr = CATAdpQueryAttributes(objectsToAttributes,errors);

  //process results
  if(SUCCEEDED(hr))
  {
    CATOmxAny portFunctionalNameAny;
    ports[someVPMPort].GetValue(V_FunctionalName,portFunctionalNameAny);
    const CATUnicodeString portFunctionalName = portFunctionalNameAny;

    //here we have V_FunctionalName attribute value of someVPMPort inside portFunctionalName
  }
 *
 *
 */
ExportedByCATPLMIntegrationAccess HRESULT CATAdpQueryAttributes(CATOmxOHMap<CATPLMID_Simple,CATOmxKeyValueBlock>& ioAttributes,CATOmxIter<CATError>& oErrors);
ExportedByCATPLMIntegrationAccess HRESULT CATAdpQueryAttribute(const CATOmxKeyString& iAttribute,CATOmxOHMap<CATPLMID_Simple,CATOmxAny>& ioAttributes,CATOmxIter<CATError>& oErrors);

#endif
