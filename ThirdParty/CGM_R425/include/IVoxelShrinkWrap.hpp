/**
* @fullReview JBS2,JXO Q8M 21:02:15 Initial 
* @quickReview N9H Q8M 21:02:16  Refactored interface for VoxelShrinkWrap.
* @quickReview JBS2 Q8M 21:02:18 Provided option for retractiong non-convex regions to the interface of the voxelshrinkwrap
* @quickReview JBS2 Q8M 21:07:07 Added missing include
* @quickReview N9H Q8M 21:09:20 Added option for closing holes on open geometry to createVoxelShrinkWrapConfig().
*                               Moved to FW XCTGeometryVoxelShinkItf
*/

#ifndef RTT_GEOMETRY_IVOXELSHRINKWRAP_HPP
#define RTT_GEOMETRY_IVOXELSHRINKWRAP_HPP

#include "voxelshrinkwrapbaseconfig.hpp"

#include <array>
#include <vector>


namespace rtt
{
namespace geometry
{

class IVoxelShrinkWrap;
typedef std::shared_ptr<IVoxelShrinkWrap> IVoxelShrinkWrapSPtr;
typedef std::shared_ptr<IVoxelShrinkWrap const> IVoxelShrinkWrapConstSPtr;
typedef std::weak_ptr<IVoxelShrinkWrap>   IVoxelShrinkWrapWPtr;

class VoxelShrinkWrap;

//! This class in an interface for an implementation of a voxel shrink-wrap
//! Currently there is only one implementation using four states of voxels
class ExportedByXCTGeometryVoxelShrink IVoxelShrinkWrap 
{
public:
	friend ExportedByXCTGeometryVoxelShrink IVoxelShrinkWrapSPtr createVoxelShrinkWrapObject(VoxelShrinkWrapObjectType objType);

	//! Type for a point in space
	typedef std::array<float,3> Point;

	//! Type for a STL-like triangle specified by three FVec3
	typedef std::array<Point,3> STLTriangle;

	//! Destructor
	~IVoxelShrinkWrap();

	//! Creates a configuration for wrapping given geometry of the voxel shrink-wrap
	//! specifying voxel size, hole size, penetration depth, minimum penetration depth
	//! and blocking gap size for penetration
	VoxelShrinkWrapBaseConfigSPtr createVoxelShrinkWrapConfig(
		float voxelSize,
		float holeSize,
		float penetrationDepth,
		float minimumPenetrationDepth,
		float blockingGapSizeForPenetration,
		bool  bEnableRetraction,
		bool  bCloseHolesOnOpenGeometry);

	//! Add a list of stl-like triangles to list of geometry to voxelize
	void addSTLTriangles(const std::vector<STLTriangle>& stlTris, bool bAddToOpaqueGeo = true);

	//! Starts shrink-wrapping and returns
	//! -1: wrapping failed (=^= E_FAIL)
	//! 0 : wrapping was successful ( =^= S_OK)
	//! 1 : wrapping was cancelled (not used yet)
	int run(VoxelShrinkWrapBaseConfigConstSPtr cfg);

	//! Returns voxel state at given position. States are enumerated, e.g. for the 4-state implementation:
	//! 0 := OUTER_VOID
	//! 1 := INTERIOR_VOID
	//! 2 := GEOMETRY
	//! 3 := WRAP
	int getVoxelState(const Point& pt) const;

	//! Return type of voxel shrink-wrap object
	VoxelShrinkWrapObjectType voxelShrinkWrapObjectType() const;

	//! Return pointer to actual voxel shrink-wrap object
	VoxelShrinkWrap *actualVoxelShrinkWrap() { return m_pVSW; }

	//! Return const pointer to actual voxel shrink-wrap object
	const VoxelShrinkWrap *actualVoxelShrinkWrap() const { return m_pVSW; }

protected:
	//! Constructor with given type
	IVoxelShrinkWrap(VoxelShrinkWrapObjectType vswObjType);

private:
	//! Type of voxel shrink-wrap to avoid usage of RTTI for dynamic casts
	VoxelShrinkWrapObjectType m_voxelShrinkWrapObjectType = VSW_INVALID_TYPE;

	//! Pointer to real voxel-shrinkwrap object
	VoxelShrinkWrap *m_pVSW = nullptr;
};

} // namespace geometry
} // namespace rtt

#endif // RTT_GEOMETRY_IVOXELSHRINKWRAP_HPP
