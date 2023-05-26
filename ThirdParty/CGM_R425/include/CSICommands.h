#ifndef CSICommands_H
#define CSICommands_H

#include "CSICommandBinderModule.h"
#include "CSIPool.h" // TO REVIEW remove include

#include "CATSysErrorDef.h"
#include "DSUnicodeString.h"

namespace EK
{
class Context;
}

namespace CSI
{
class CommandsImpl;
class Response;
class Parameters;
class Pool;
class Types;

class ExportedByCSIBinderModule Commands
{
public:
  /**
   * Use this constructor if you are using Execution Framework (=ExperienceKernel) to launch an internal EK::Hypervisor
   */
   Commands(const EK::Context& context, const CATUnicodeString& declarativeFilesPaths = "");
   Commands(const CATUnicodeString& declarativeFilesPaths = "");
  ~Commands();

  /*
  argc & argv will be used for the createNodeData() function,
  exported in user library specified in declarative file CSIDeployedCommands/MyPoolName/MyPoolName.json, field "library"
  dll will be loaded on Commands::GetPool(MyPoolName);
  */
  Commands(const EK::Context& context, int argc, char** argv, const CATUnicodeString& declarativeFilesPaths = "");

  Commands(const Commands&) = delete;
  Commands& operator=(const Commands&) = delete;

  /** Create or get an existing pool,
  Associated with a node (that may or may not exist).
  Can be used to create a Node, and to declare commands.

  \param pool pool name, can be the pool name of the client application, or the pool name of a server application
  \return a Pool
  */
  Pool& GetPool(const CATUnicodeString& pool);

  /** Create a recordable pool,
  Associated with a node (that may or may not exist).
  Can be used to create a Node, and to declare commands.

  \param pool pool name, can be the pool name of the client application, or the pool name of a server application
  \return a Pool, or nullptr if a pool with this name already exists
  */
  Pool* CreateRecordablePool(const CATUnicodeString& poolName);

  /** Create a pool from a bundle file,
  Associated with a node (that may or may not exist).
  Can be used to create a Node, and to declare commands.

  \param pool pool name, can be the pool name of the client application, or the pool name of a server application
  \param bundlePath path of the bundle file containing the definition of all pools/functions/types/events/implementations to load
  \return a Pool, or nullptr if a pool with this name already exists
  */
  Pool* CreatePoolFromBundle(const CATUnicodeString& poolName, const CATUnicodeString& bundlePath, bool recordable = false);

  //@{
  /** Create a client or server Node.
  Do not delete the returned pointer,
  instances are managed by CSI::CommandBinder
  \param settings node settings. You will need to link with ExperienceKernel to have EK::NodeSettings definition
  \return a Node
  */
  Node* CreateNode(const CATUnicodeString& pool);
  Node* CreateNode(const CATUnicodeString& pool, const EK::NodeSettings& settings);
  //@}

  /** Lock process and wait until all node created through Pool::CreateNode() are stopped with the CommandBinder::Stop() method.
  */
  HRESULT WaitAll();

  /** Get Default Response
  <=> set of client callbacks that will be called if a message is received for a domain
  */
  Response& GetDefaultResponse();

  /** Create an empty Parameters
  \return the created Parameters
  */
  [[deprecated("CSI COMMAND BINDER - DEPRECATED - 2020/02/04 - Method Commands::CreateParameters() is deprecated, please use Node::CreateParameters() instead")]]
  Parameters CreateParameters() const;

  /** Create a typed Parameters, and fill it with a value
  \param type typename for the return parameters, can be retrieve with Parameters::GetObjectType();
  \param value used to fill the returned parameters, according that the serialization & unserialization methods have been previously loaded
  \return the created Parameters
  */
  template <class T>
  [[deprecated("CSI COMMAND BINDER - DEPRECATED - 2020/02/04 - Method Commands::CreateParameters(...) is deprecated, please use Node::CreateParameters(...) instead")]]
  Parameters CreateParameters(const CATUnicodeString& type, const T& value) const;

private:
  CommandsImpl& impl_;
  friend CommandsImpl& getImpl(const Commands& commands);
  Types& GetTypes() const;
  Commands& GetThisReference();
};
}

#include "CSICommands.hxx"

#endif
