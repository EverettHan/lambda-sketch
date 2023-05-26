/**
* @fullReview N9H Q8M 21:02:16 Initial 
* @quickReview N9H Q8M 21:09:20 Moved to FW XCTGeometryVoxelShinkItf
**/

#ifndef RTT_GEOMETRY_IVOXELSHRINKWRAP_OBJECT_FACTORY_HPP
#define RTT_GEOMETRY_IVOXELSHRINKWRAP_OBJECT_FACTORY_HPP

#include "IVoxelShrinkWrap.hpp"

namespace rtt
{
namespace geometry
{

//! Creates a voxel shrink-wrap object of given type
ExportedByXCTGeometryVoxelShrink IVoxelShrinkWrapSPtr createVoxelShrinkWrapObject(VoxelShrinkWrapObjectType objType);

}
}

#endif // RTT_GEOMETRY_IVOXELSHRINKWRAP_OBJECT_FACTORY_HPP
