#ifndef ScalarFieldsOperatorsCommon_h
#define ScalarFieldsOperatorsCommon_h

#include "ScalarFieldsOperators.h"

// CATFuzzyOperators
#include "CATVRepTree.h"

// Lattice
#include "LatticeNBModel.h"

// CGM
#include "CATTolerance.h"

// Scalar Fields
#include "SFTypes.h"

// STD
#include <memory>

namespace SF
{
  typedef std::shared_ptr<CATVRepTree>    CATVRepTreePtr;
  typedef std::shared_ptr<LatticeNBModel> LatticeNBModelPtr;

  /**
   * Functions common to various operations in ScalarFieldsOperators are group
   * in this class for convenience.
   */
  class ExportedByScalarFieldsOperators ScalarFieldsOperatorsCommon
  {
  public:
    /**
     * Return a suggested voxel size to handle bar geometries with the specified min radius.
     * This is the same computation that was used historically in LatticeGMOperators and which seem to have
     * given satisfaction so far. It is reproduce here to avoid having to add Lattice as a dependency of
     * ScalarFields just for this helper function.
     */
    static const double VoxelSizeFromMinRadius(const double iMinRadius);

    /**
     * Return a suggested voxel size to deal with a geometry with the specified max curvature.
     * This is the same computation that was used historically in LatticeGMOperators and which seem to have
     * given satisfaction so far. It is reproduce here to avoid having to add Lattice as a dependency of
     * ScalarFields just for this helper function.
     */
    static const double VoxelSizeFromCurvature(const double iMaxCurvature);

    /**
     * Return a suggested voxel size to handle bar geometries with the specified min radius while
     * satisfying the provided tolerance.
     */
    static const double VoxelSizeFromRadiusAndSag(const double iMinRadius, const double iSag);

    /**
     * Return a suggested voxel size to deal with a geometry with the specified max curvature while
     * satisfying the provided tolerance.
     */
    static const double VoxelSizeFromCurvatureAndSag(const double iMaxCurvature, const double iSag);

    /**
     * Given a Box and a voxel size this will compute the needed tree depth.
     * If it requires a tree depth higher or equal to 14 it will return -1
     * which indicate it would require an unrealistic tree depth.
     */
    static const int GetExpectedDepthFromVoxelSize(const CATMathBox& iBox, const double iVoxelSize);

    /**
     * Given a box and an expected depth it will return the associated voxel size.
     */
    static const double GetVoxelSizeFromExpectedDepth(const CATMathBox& iBox, const int iExpectedDepth);

    /**
    * Return the sag to be used based on the specified level of accuracy.
    */
    static const double GetSagFromDiscretizationAccuracyLevel(
      const CATTolerance& iTolerance,
      const CATGMSFDiscretizationAccuracyLevel iDiscretizationAccuracyLevel);

    static const double GetRealisticVoxelSize(
      const CATMathBox& iBox,
      const double iMaxCurvature,
      const CATTolerance& iTolerance,
      const CATGMSFDiscretizationAccuracyLevel iDiscretizationAccuracyLevel = CoarseDiscretizationAccuracy,
      CATGMSFDiscretizationAccuracyLevel* oDiscretizationAccuracyStatus = nullptr);

    template<typename InGrid, typename Rescale, typename PixelIndex, typename PixelScalar>
    static const double GetInterpolatedScalarFromGridDeviation(const CATMathPoint & iPosition, InGrid inside, Rescale rescale, PixelIndex index, PixelScalar scalar)
    {
      double xyz[3];
      rescale(iPosition, xyz);
      const unsigned int pixel[3] = {(unsigned int)floor(xyz[0]), (unsigned int)floor(xyz[1]), (unsigned int)floor(xyz[2])};
      if (inside(pixel[0], pixel[1], pixel[2]))
      {
        double delta[3] = {	xyz[0] - (double)pixel[0], xyz[1] - (double)pixel[1], xyz[2] - (double)pixel[2]};
        unsigned int dxyz[3] = {0, 0, 0};
        if (inside(pixel[0]+1, pixel[1], pixel[2]))
          dxyz[0] = 1;
        if (inside(pixel[0], pixel[1]+1, pixel[2]))
          dxyz[1] = 1;
        if (inside(pixel[0], pixel[1], pixel[2]+1))
          dxyz[2] = 1;

        const unsigned int
          index000 = index(pixel[0]        , pixel[1]        , pixel[2]        ),
          index001 = index(pixel[0]        , pixel[1]        , pixel[2]+dxyz[2]),
          index010 = index(pixel[0]        , pixel[1]+dxyz[1], pixel[2]        ),
          index011 = index(pixel[0]        , pixel[1]+dxyz[1], pixel[2]+dxyz[2]),
          index100 = index(pixel[0]+dxyz[0], pixel[1]        , pixel[2]        ),
          index101 = index(pixel[0]+dxyz[0], pixel[1]        , pixel[2]+dxyz[2]),
          index110 = index(pixel[0]+dxyz[0], pixel[1]+dxyz[1], pixel[2]        ),
          index111 = index(pixel[0]+dxyz[0], pixel[1]+dxyz[1], pixel[2]+dxyz[2]);

        double
          c000 = scalar(index000),
          c001 = scalar(index001),
          c010 = scalar(index010),
          c011 = scalar(index011),
          c100 = scalar(index100),
          c101 = scalar(index101),
          c110 = scalar(index110),
          c111 = scalar(index111);

        double
          c00 = c000 * (1.0 - delta[0]) + c100 * delta[0],
          c01 = c001 * (1.0 - delta[0]) + c101 * delta[0],
          c10 = c010 * (1.0 - delta[0]) + c110 * delta[0],
          c11 = c011 * (1.0 - delta[0]) + c111 * delta[0],
          c0 = c00 * (1.0 - delta[1]) + c10 * delta[1],
          c1 = c01 * (1.0 - delta[1]) + c11 * delta[1],
          c = c0 * (1.0 - delta[2]) + c1 * delta[2];

        return c;
      }
      return GetSFMaxScalar();
    }

  public:
    static const unsigned RecommendedDepth;
    static const unsigned RecommendedMaximumDepth;
  };
};


#endif // ScalarFieldsOperatorsCommon_h
