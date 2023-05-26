#ifndef CSIPool_H
#define CSIPool_H

#include "CSICommandBinderModule.h"

#include "CATSysErrorDef.h"

#include "DSUnicodeString.h"

// TO REVIEW TVS 2022/03: FIXME remove those includes when test user are cleaned during CPP Build
//added to prevent build user break after removal of RegisterCommand() and dependencies from csi code
#include "CSICommandFactory.h"
#include "CSICommandInterface.h"
#include "CSIParameters.h"

namespace CSI
{
  class Channel;
  class Commands;
}
using DummyChannel = CSI::Channel; // Silence EKLint
using DummyCommands = CSI::Commands; // Silence EKLint
// files to compile check on release user
// UIVCoreAutomation.tst\CSIInjectLibraryEx.m\src\CSIInjectLibraryEx.cpp
// CSIClientServerIntegration.tst\CSIInfraServerTest.m\src\CSICommandTest.cpp
// CSIClientServerIntegration.tst\CSIInfraServerTestLetters.m\src\CSICommandTest_Letter.cpp
// CSIDistributed3DModeler.tst\CSIDataModeler.m\src\CSIServiceProxy.cpp
// SMAFeaCSIServices.tst\SMAFeaCSITestModule.m\src\SMAFeaCSITestCommandAddNum.cpp
// SMADataExchange.tst\SMADexCommandsModule.m\src\SMADexAgentReady.cpp
// SMADataExchange.tst\SMADexCommandsModule.m\src\SMADexPullVTKUGrid.cpp
// SMADataExchange.tst\SMADexCommandsModule.m\src\SMADexPushSpecification.cpp
// SMADataExchange.tst\SMADexCommandsModule.m\src\SMADexPushUnitSystem.cpp
// SMADataExchange.tst\SMADexCommandsModule.m\src\SMADexPushVTKCellField.cpp
// SMADataExchange.tst\SMADexCommandsModule.m\src\SMADexPushVTKPointField.cpp
// SMADataExchange.tst\SMADexCommandsModule.m\src\SMADexPushVTKUGrid.cpp

namespace EK
{
class NodeSettings;
}

namespace CSI
{
class DeclarativePoolDescription;
class Node;
class PoolToLaunch;
class PoolImpl;

/** Pool class.
A Pool is used to create Client & Server nodes (Node), and stores a list of declared command.
*/
class ExportedByCSIBinderModule Pool
{
public:
  explicit Pool(PoolImpl& poolImpl);
          ~Pool();

  Pool(const Pool&) = delete;
  Pool& operator=(const Pool&) = delete;

  /** Create a client or server Node.
  Do not delete the returned pointer,
  instances are managed by CSI::CommandBinder
  \param settings node settings. You will need to link with ExperienceKernel to have EK::NodeSettings definition
  \return a Node
  */
  Node* CreateNode(void* data = nullptr);
  Node* CreateNode(EK::NodeSettings& settings);
  Node* CreateNode(const EK::NodeSettings& settings, void* data = nullptr);

  template <class T>
  Node* CreateNode(T& userData);

  template <class T>
  Node* CreateNode(const EK::NodeSettings& settings, T& userData);

  /** Create a client or server CallbackNode
  use then
  EK::CallbackNode* Node::GetCallbackNode();
  to retrieve EK::CallbackNode and use it as is
  \param settings node settings. You will need to link with ExperienceKernel to have EK::NodeSettings definition
  \return a Node
  */
  Node* CreateCallbackNode(void* data = nullptr);
  Node* CreateCallbackNode(const EK::NodeSettings& settings, void* data = nullptr);

  /** import all commands from a declarative pool, in this pool
  \param poolName the pool name to import, folder must exists in /resources/CSIDeployedCommands
  \return S_OK on success, E_FAIL otherwise
  */
  HRESULT ImportDeclarativePool(const CATUnicodeString& poolName);

private:
  friend class PoolToLaunch;
  DeclarativePoolDescription GetDeclarativePoolDescription() const;

private:
  PoolImpl& impl_;

  friend PoolImpl& getImpl(const Pool& pool);
};
}

#include "CSIPool.hxx"

#endif
