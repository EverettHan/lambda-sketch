//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2021
//==========================================================================
// CATMathVolumeDeformation
//==========================================================================
//
// Space deformation based on elastically coupled rigid voxels
//
// Theory from
// "Adaptive space deformations based on rigid cells" - Botsch et al.
//
// Achtung : beware of input data management, the class doesn't own/copy data
// Don't destroy the input data before the run !
// 
// 10/4/2021 : FAA2 Creation
//==========================================================================
#ifndef CATMathVolumeDeformation_H_
#define CATMathVolumeDeformation_H_

#include "MathVolumeDeformation.h"

#define ENABLE_COMPIL_MVD

#if defined(_AIX_SOURCE) || defined(_MOBILE_SOURCE)
#undef ENABLE_COMPIL_MVD
#endif

#ifdef ENABLE_COMPIL_MVD
#include <array>
#include <vector>
#include <unordered_map>

class CATMathMarshFunction;
class CATMathBox;


class ExportedByMathVolumeDeformation CATMathVolumeDeformation
{
public:

    typedef std::array<double, 3> Point;


    // Instantiate
    static CATMathVolumeDeformation* Create(const std::vector<Point>& iPoints, int iBucketSize, int iLevelMax, bool iRefinement = false, int iNbThreads = 4);
    virtual ~CATMathVolumeDeformation() = default;


    // Initialize
    virtual void Initialize(const CATMathMarshFunction*& IndicatorFct, CATMathBox& BBox, double iBoundingIso1, double iBoundingIso2, std::vector<bool>* iBoundaryFlags = nullptr) = 0;


    // Boundary conditions
    virtual void SetDualPts(std::unordered_map<int, Point>& iDualPts, std::vector<int>* iPtsClass = nullptr) = 0;


    // Run
    virtual int Run() = 0;


    // Get resulting deformation
    virtual int GetDeformation(CATMathMarshFunction*& oDeformation) = 0;


    // Apply deformation
    virtual int ApplyDeformation(std::unordered_map<int, Point>& oTransformedPts, std::vector<Point>* iPts = nullptr) = 0;


private:

  // CATMathVolumeDeformation(const CATMathVolumeDeformation&);
  CATMathVolumeDeformation& operator=(const CATMathVolumeDeformation& iPrimoDef);

};

#endif

#endif 
