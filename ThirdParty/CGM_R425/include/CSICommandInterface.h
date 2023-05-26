#ifndef CSICommandInterface_H
#define CSICommandInterface_H

#include "CATSysErrorDef.h"
#include "CSICommandBinderModule.h"

namespace CSI
{
class Channel;
class Commands;
class Node;
class Parameters;

class ExportedByCSIBinderModule CommandInterface
{
public:
           CommandInterface() = default;
  virtual ~CommandInterface() = default;

  CommandInterface(const CommandInterface&) = delete;
  CommandInterface& operator=(const CommandInterface&) = delete;

  virtual HRESULT OnBegin(const Parameters& parameters, Channel& origin) = 0;
  virtual HRESULT OnCommand(const Parameters& parameters, Channel& origin) = 0;
  virtual HRESULT OnEnd(const Parameters& parameters, Channel& origin) = 0;

  virtual HRESULT OnDisconnect() = 0;

  //do not use this method, which is kept only for migration purpose
  //we need to keep this operator, otherwise deprecated code will not compile at all (tested)
  HRESULT operator()(Commands&, Parameters&, Channel&) {return E_FAIL;} // DEPRECATED
};
}

#include "DSYExport.h"

#define CSI_INSTANTIATE_COMMAND(className, pool, function, version) \
extern "C" \
{ \
  DSYExport CSI::CommandInterface* CCI_##pool##_##function##version(CSI::Node&) \
  { \
    return new className(); \
  } \
  DSYExport void DCI_##pool##_##function##version(CSI::CommandInterface* ci) \
  { \
    delete ci; \
  } \
}

#define CSI_INSTANTIATE_COMMAND_WITH_NODE(className, pool, function, version) \
extern "C" \
{ \
  DSYExport CSI::CommandInterface* CCI_##pool##_##function##version(CSI::Node& node) \
  { \
    return new className(node); \
  } \
  DSYExport void DCI_##pool##_##function##version(CSI::CommandInterface* ci) \
  { \
    delete ci; \
  } \
}

#endif
