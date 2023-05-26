#pragma once

#include "CATRmaMappingCore.h"
#include "CATRmaMappingLib.h"

#include <optional>

class CATMathTransformation;
class CATMath3x3Matrix;
class CATMathVector2D;

namespace CATRmaMappingCoreServices
{
	/* same as CATRmaMappingCore::MappingInfo but with optional parameters */
	struct ExportedByCATRmaMappingLib PartialMappingInfo
	{
		struct Transform
		{
			std::optional<double> scaleU;
			std::optional<double> scaleV;

			std::optional<double> offsetU;
			std::optional<double> offsetV;

			std::optional<double> angleRad;

			std::optional<bool> flipU;
			std::optional<bool> flipV;
		};

		Transform transform;

		std::optional<bool> repeatU;
		std::optional<bool> repeatV;

		std::optional<CATRmaMappingCore::MappingType> type;
		std::optional<CATRmaMappingCore::MappingBehavior> behavior;

		PartialMappingInfo() = default;
		PartialMappingInfo(const CATRmaMappingCore::MappingInfo& iMapping);

		operator bool() const;

		CATRmaMappingCore::MappingInfo CompleteBasedOn(const CATRmaMappingCore::MappingInfo& iBase) const;

		CATRmaMappingCore::MappingInfo CompleteWithDefaults() const;
	};

	namespace Decoupled
	{
		ExportedByCATRmaMappingLib CATMath3x3Matrix ComputeChannelUvTransform(
			const CATRmaMappingCore::MappingInfo& iChannelMapping, const CATMathVector2D& iTextureSize);

		ExportedByCATRmaMappingLib CATMath3x3Matrix ComputeApplicationUvTransform(
			const CATRmaMappingCore::MappingInfo& iApplicationMapping,
			const CATRmaMappingCore::MappingInfo& iChannelMapping);

		ExportedByCATRmaMappingLib CATMathTransformation ComputeObjectTransform(
			const CATMathTransformation& iTransform);
	}

	namespace Legacy
	{
		ExportedByCATRmaMappingLib CATMath3x3Matrix ComputeChannelUvTransform(
			const CATRmaMappingCore::MappingInfo& iChannelMapping, const CATMathVector2D& iTextureSize);

		ExportedByCATRmaMappingLib CATMath3x3Matrix ComputeApplicationUvTransform(
			const CATRmaMappingCore::MappingInfo& iApplicationMapping,
			const CATRmaMappingCore::MappingInfo& iChannelMapping);

		ExportedByCATRmaMappingLib CATMathTransformation ComputeObjectTransform(
			const CATMathTransformation& iTransform);

		ExportedByCATRmaMappingLib CATRmaMappingCore::MappingInfo CombineMapping(
			const CATRmaMappingCore::MappingInfo& iApplicationMapping,
			const CATRmaMappingCore::MappingInfo& iChannelMapping, const CATMathVector2D& iTextureSize);
	
		namespace GPUGeometryUV
		{
			ExportedByCATRmaMappingLib CATMath3x3Matrix ComputeApplicationUvTransform(
				const CATRmaMappingCore::MappingInfo& iApplicationMapping);
		}

		namespace NoMappingPerChannel
		{
			ExportedByCATRmaMappingLib CATMath3x3Matrix ComputeApplicationUvTransform(
				const CATRmaMappingCore::MappingInfo& iApplicationMapping,
				const CATRmaMappingCore::MappingInfo& iChannelMapping);

			ExportedByCATRmaMappingLib CATMath3x3Matrix ComputeChannelUvTransform(
				const CATRmaMappingCore::MappingInfo& iApplicationMapping,
				const CATRmaMappingCore::MappingInfo& iChannelMapping,
				const CATMathVector2D& iTextureSize);
		}
	}

	ExportedByCATRmaMappingLib bool Compare(const CATRmaMappingCore::MappingInfo& iLeft,
		const CATRmaMappingCore::MappingInfo& iRight, double iEpsylon = 1e-6);

	ExportedByCATRmaMappingLib CATRmaMappingCore::MappingInfo ResolveReferenceMappingInfo(
		const PartialMappingInfo& iReferenceMapping);

	ExportedByCATRmaMappingLib CATRmaMappingCore::MappingInfo ResolveChannelMappingInfo(
		const PartialMappingInfo& iReferenceMapping, const PartialMappingInfo& iChannelMapping);

	ExportedByCATRmaMappingLib CATRmaMappingCore::MappingInfo ResolveApplicationMappingInfo(
		const PartialMappingInfo& iApplicationMapping, const CATRmaMappingCore::MappingInfo& iChannelMapping);
}
