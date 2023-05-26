/**
* @fullReview N9H Q8M 21:02:16 Initial 
* @quickReview N9H Q8M 21:09:20 Moved to FW XCTGeometryVoxelShinkItf
**/

#ifndef RTT_GEOMETRY_VOXELSHRINKWRAP_OBJECT_TYPES_HPP
#define RTT_GEOMETRY_VOXELSHRINKWRAP_OBJECT_TYPES_HPP

namespace rtt
{
namespace geometry
{

enum VoxelShrinkWrapObjectType
{
	VSW_INVALID_TYPE,
	VSW_4STATE_SINGLE_CPU,  // for not bothering other users on a machine
	VSW_4STATE_MULTI_CPU    // using all available CPUs
};

}
}

#endif // RTT_GEOMETRY_VOXELSHRINKWRAP_OBJECT_TYPES_HPP
