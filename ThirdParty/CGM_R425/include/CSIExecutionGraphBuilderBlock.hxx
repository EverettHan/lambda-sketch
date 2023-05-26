#ifndef CSIExecutionGraphBuilderBlock_HXX
#define CSIExecutionGraphBuilderBlock_HXX

#include "CSIExecutionGraphBuilderParametersFactory.h"
#include "CSIParameters.h"
#include "stdint.h"

template <typename T>
bool CSI::ExecutionGraph::Builder::Block::AddCallDefaultValue(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, Path path, T value)
{
  if (path.size() == 0u)
    return false;
  CSI::Parameters parameters = CreateLocalDataPortParameters(parametersFactory, path.back(), value);
  Path callPath({ "call" });
  callPath.insert(callPath.end(), path.begin(), path.end());
  return AddDefaultValue(callPath, parameters);
}

//double
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, double value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteDouble(propertyName.c_str(), value);
  return parameters;
}

//float
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, float value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteFloat(propertyName.c_str(), value);
  return parameters;
}

//const char*
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, const char* value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteString(propertyName.c_str(), value);
  return parameters;
}

//std::string
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, std::string value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteString(propertyName.c_str(), value.c_str());
  return parameters;
}

//bool
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, bool value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteBool(propertyName.c_str(), value);
  return parameters;
}

//int8
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, int8_t value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteInt8(propertyName.c_str(), value);
  return parameters;
}

//int16
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, int16_t value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteInt16(propertyName.c_str(), value);
  return parameters;
}

//int32
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, int32_t value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteInt32(propertyName.c_str(), value);
  return parameters;
}

//int64
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, int64_t value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteInt64(propertyName.c_str(), value);
  return parameters;
}

//uint8
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, uint8_t value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteUint8(propertyName.c_str(), value);
  return parameters;
}

//uint16
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, uint16_t value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteUint16(propertyName.c_str(), value);
  return parameters;
}

//uint32
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, uint32_t value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteUint32(propertyName.c_str(), value);
  return parameters;
}

//uint64
template<>
inline CSI::Parameters CSI::ExecutionGraph::Builder::Block::CreateLocalDataPortParameters(CSI::ExecutionGraph::Builder::ParametersFactory parametersFactory, std::string propertyName, uint64_t value) const
{
  CSI::Parameters parameters = parametersFactory.CreateParameters();
  parameters.WriteUint64(propertyName.c_str(), value);
  return parameters;
}

#endif
