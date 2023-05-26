#ifndef CSICommandFactory_H
#define CSICommandFactory_H

#include "CATSysErrorDef.h"

namespace JSON
{
class JOStream;
}

namespace CSI
{
class Commands;
class CommandInterface;
class ErrorContext;

class Node;
class Parameters;

class CommandFactory
{
public:
           CommandFactory() = default;
  virtual ~CommandFactory() = default;

  CommandFactory(const CommandFactory&) = delete;
  CommandFactory& operator=(const CommandFactory&) = delete;

  virtual CommandInterface* CreateCommand(ErrorContext& errorContext, Commands& commands, Node& node, bool debug) = 0;
  virtual HRESULT DeleteCommand(CommandInterface* cmd, bool debug) = 0; // TO REVIEW CP7 2017/11 you need to specify if it's debug?

  virtual HRESULT Serialize_V2(Parameters& out) const = 0;
  virtual HRESULT SerializeToJSON_V2(JSON::JOStream& out) const = 0;
};
}

#endif
