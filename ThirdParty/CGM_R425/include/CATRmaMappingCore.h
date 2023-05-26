#pragma once

namespace CATRmaMappingCore
{
	/* mapping operators */
	enum class MappingType
	{
		Planar = 0,
		Spherical,
		Cylindrical,
		Box,
		Auto,
		Adaptive,
		UV,
		HemiSpherical,
		InfCylindrical,
		MappingTypeCount
	};

	/* texture scaling behavior */
	enum class MappingBehavior
	{
		/* scaled by physical texture size */
		TextureFocused = 0,
		/* no additional texture scaling */
		SurfaceFocused
	};

	/* defines how the application and reference mapping are combined */
	enum class MappingSemantic
	{
		LegacyMapping = 0,
		DecoupledMapping
	};

	/* parameters required for the texture mapping computation */
	struct MappingInfo
	{
		struct Transform
		{
			/* scale in U direction, must be greater than 0 */
			double scaleU = 1.;
			/* scale in V direction, must be greater than 0 */
			double scaleV = 1.;

			/* translation in U direction */
			double offsetU = 0.;
			/* translation in V direction */
			double offsetV = 0.;

			/* 2D rotation angle in radiants */
			double angleRad = 0.;

			/* mirrors mapping along the U axis */
			bool flipU = false;
			/* mirrors mapping along the V axis */
			bool flipV = false;
		};

		/* groups mapping transform parameters */
		Transform transform;

		/* repeat texture in U direction */
		bool repeatU = true;
		/* repeat texture in V direction */
		bool repeatV = true;

		/* mapping operator */
		MappingType type = MappingType::UV;

		/* texture scaling behavior */
		MappingBehavior behavior = MappingBehavior::SurfaceFocused;
	};
}
