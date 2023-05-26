// COPYRIGHT Dassault Systemes 2022
//-------------------------------------------------------------------------------------------------
#pragma once

#include <UIVCoreTools.h>
#include <CATSYPGenericUIDump.h>

extern ExportedByUIVCoreTools IID IID_CATISYPUIDumpForWatcher;

/**
 * @brief Interface to retrieve the dump of a component for a watching process
 *
 * This interface can be used with CATSYPGenericUIDumpVisitor visitor to retrive component and its children components dump
 *
 * The Dump method is supposed to return a nlohmann::json::object with following properties
 *    - id: a unique identifier of the component
 *    - type: the component type
 *    - properties: nlohmann::json::object containing all {propertyName, properyValue} properties
 */
class ExportedByUIVCoreTools CATISYPUIDumpForWatcher : public CATSYPGenericUIDump
{
  CATDeclareInterface;

  public:
};

CATDeclareHandler(CATISYPUIDumpForWatcher, CATBaseUnknown);
