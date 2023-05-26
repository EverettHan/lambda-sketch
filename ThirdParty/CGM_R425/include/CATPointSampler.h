#ifndef CATPointSampler_h
#define CATPointSampler_h
//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//==========================================================================
// CATPointSampler
//==========================================================================
//
// Point Sub sampler
//
// 08/01/2022 : FAA2 Creation
//==========================================================================

#include "MathAdvMarsh.h"
#define CATPointSamplerImp

#ifndef _WINDOWS_SOURCE
#undef CATPointSamplerImp
#endif

#ifdef CATPointSamplerImp

#include "CATMathPoint.h"

#include <vector>
#include <unordered_map>

class ExportedByMathAdvMarsh CATPointSampler
{
public:

	CATPointSampler(std::vector<CATMathPoint>* iPoints, double iSamplingRatio, bool iUseFPS=true, bool iUseGrid=false);
	virtual ~CATPointSampler();
	int GetSampledFlags(std::vector<bool>& oSampledFlags) { oSampledFlags = _SampledFlags; return _RC; };

private:

	// Thread Data structure - a basic matrixial array may be better - To measure.. 
	struct ArrayOfVectors
	{
		std::vector<double> Distances;
	};

	int RunSampling(double iSamplingRatio, bool iUseFPS, bool iUseGrid);
	int FarthestPtsSampling(ArrayOfVectors* PointDistanceMap, int iSeed, int NbTarget, int& NbSampled, std::vector<int>* PtsToSample = nullptr);

	int _RC;
	std::vector<bool> _SampledFlags;
	std::vector<CATMathPoint>* _Points;
};

#endif

#endif

