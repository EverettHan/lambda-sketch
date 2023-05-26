/**
* @fullReview N9H Q8M 21:02:16 Initial
* @quickReview N9H Q8M 21:09:20 Moved to FW XCTGeometryVoxelShinkItf
**/

#ifndef RTT_GEOMETRY_VOXELSHRINKWRAP_BASE_CONFIG_HPP
#define RTT_GEOMETRY_VOXELSHRINKWRAP_BASE_CONFIG_HPP

#include "XCTGeometryVoxelShrinkAPI.h"

#include "voxelshrinkwrapobjecttypes.hpp"

#include <memory>

namespace rtt
{
namespace geometry
{

struct VoxelShrinkWrapBaseConfig;
typedef std::shared_ptr<VoxelShrinkWrapBaseConfig> VoxelShrinkWrapBaseConfigSPtr;
typedef std::shared_ptr<VoxelShrinkWrapBaseConfig const> VoxelShrinkWrapBaseConfigConstSPtr;
typedef std::weak_ptr<VoxelShrinkWrapBaseConfig>   VoxelShrinkWrapBaseConfigWPtr;

class VoxelShrinkWrapConfig;

//! This class is a base class for the configuration of a voxel shrink-wrap
//! It will be used for the run()-method of IVoxelShrinkWrap
struct ExportedByXCTGeometryVoxelShrink VoxelShrinkWrapBaseConfig
{
	friend class IVoxelShrinkWrap;

	//! Destructor
	~VoxelShrinkWrapBaseConfig();

	//! Return type of voxel shrink-wrap object this config was created for
	VoxelShrinkWrapObjectType forVoxelShrinkWrapObjectType() const
	{ return m_forVoxelShrinkWrapObjectType; }

	//! Return pointer to actual config of geometrylib
	VoxelShrinkWrapConfig *actualConfig()
	{ return m_pCfg; }

	//! Return const pointer to actual config of geometrylib
	const VoxelShrinkWrapConfig *actualConfig() const
	{ return m_pCfg; }

protected:
	//! Protected constructor used only by friends
	VoxelShrinkWrapBaseConfig()
	{ }

	//! Type of voxel shrink-wrap to avoid usage of RTTI for dynamic casts
	VoxelShrinkWrapObjectType m_forVoxelShrinkWrapObjectType = VSW_INVALID_TYPE;

	VoxelShrinkWrapConfig *m_pCfg = nullptr;
};

}
}

#endif // RTT_GEOMETRY_VOXELSHRINKWRAP_BASE_CONFIG_HPP
