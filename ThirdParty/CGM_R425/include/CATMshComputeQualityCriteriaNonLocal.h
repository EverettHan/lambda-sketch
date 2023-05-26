#ifndef CATMshComputeQualityCriteriaNonLocal_H
#define CATMshComputeQualityCriteriaNonLocal_H

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <limits>

#include <CATMshComputeCentroid.h>

/**
 * @brief Compute the face non-orthonality, which is defined as the angle
 * between the vector from one centroid to its neighbor, and the face normal
 * vector.
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], std::array<double, 3>, etc.)
 * This type cannot be a pointer type (e.g. float*), as it would cause the vector
 * creation to fail.
 * @param cellCentroid The cell centroid
 * @param neighborCentroid The centroid of the neighboring cell
 * @param faceNormal The face normal (should point towards the neighboring cell)
 * @return T The face non-orthogonality in degrees
 */
template <typename Vec3>
constexpr auto
CATMshComputeNonOrthogonality(const Vec3& cellCentroid,
                              const Vec3& neighborCentroid,
                              const Vec3& faceNormal)
{
    // if Vec3=double* for example, the vector creation will fail
    static_assert(!std::is_pointer<Vec3>::value, "you cannot use pointer types for the vectors");

    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(cellCentroid[0])>;

    Vec3 d {
        neighborCentroid[0] - cellCentroid[0],
        neighborCentroid[1] - cellCentroid[1],
        neighborCentroid[2] - cellCentroid[2]
    };

    auto dMag = std::sqrt(d[0]*d[0] + d[1]*d[1] + d[2]*d[2]);
    auto nMag = std::sqrt(faceNormal[0]*faceNormal[0] + faceNormal[1]*faceNormal[1] + faceNormal[2]*faceNormal[2]);

    T cos = (d[0]*faceNormal[0] + d[1]*faceNormal[1] + d[2]*faceNormal[2])/(dMag*nMag);

    // floating point representation can cause acos to fail. Need to clamp it to be safe.
    cos = (std::min)((std::max)(cos, T{-1.0}), T{1.0}); 

    constexpr T pi = T{3.1415926535897932385L};
    constexpr T radToDeg = T{180.0}/pi;

    return std::acos(cos)*radToDeg;
}

/**
 * @brief Compute the face skewness value, which is defined as the deviation
 * between the face centroid and the intersection between the line joining
 * the two cell centroids and that face. A perfect face has skewness = 1. 
 * A zero skewness means that the line joining the two cell centroids
 * interesects the face at the edge of the face. Negative skewness values imply
 * that the intersection lies outside of the face.
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], std::array<double, 3>, etc.)
 * This type cannot be a pointer type (e.g. float*), as it would cause the vector
 * creation to fail.
 * @param cellCentroid The cell centroid
 * @param neighborCentroid The centroid of the neighboring cell
 * @param faceNormal The face normal (should point towards the neighboring cell)
 * @param faceNodes A pointer to the first element of an array containing
 * the nodes making up that face (the node ordering is irrelevant)
 * @param numNodes The number of face nodes (the faceNodes array must
 * have at least numNodes elements)
 * @return T The face skewness
 */
template <typename Vec3>
constexpr auto
CATMshComputeSkewness(const Vec3& cellCentroid,
                      const Vec3& neighborCentroid,
                      const Vec3& faceNormal,
                      const Vec3* faceNodes, 
                      std::size_t numNodes)
{
    // if Vec3=double* for example, the vector creation will fail
    static_assert(!std::is_pointer<Vec3>::value, "you cannot use pointer types for the vectors");

    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(cellCentroid[0])>;

    Vec3 faceCentroid;
    if (numNodes == 3) 
        CATMshComputeCentroidTri(faceNodes[0], faceNodes[1], faceNodes[2], faceCentroid);
    else if (numNodes == 4) 
        CATMshComputeCentroidQuad(faceNodes[0], faceNodes[1], faceNodes[2], faceNodes[3], faceCentroid);
    else {
        assert(false); // not allowed
        return std::numeric_limits<T>::lowest();
    }
    
    Vec3 x {
        faceCentroid[0] - cellCentroid[0],
        faceCentroid[1] - cellCentroid[1],
        faceCentroid[2] - cellCentroid[2]
    };

    Vec3 d {
        neighborCentroid[0] - cellCentroid[0],
        neighborCentroid[1] - cellCentroid[1],
        neighborCentroid[2] - cellCentroid[2]
    };

    auto nDotX = faceNormal[0]*x[0] + faceNormal[1]*x[1] + faceNormal[2]*x[2];
    auto nDotD = faceNormal[0]*d[0] + faceNormal[1]*d[1] + faceNormal[2]*d[2];

	// in some extreme cases, nDotD <= 0. These cells will be identified
    // using the non-orthogonality criterion.
    nDotD = (std::max)(nDotD, std::numeric_limits<T>::epsilon());

    Vec3 m {
        (nDotX/nDotD)*d[0] - x[0],
        (nDotX/nDotD)*d[1] - x[1],
        (nDotX/nDotD)*d[2] - x[2] 
    };

    // if ||m|| = 0, this term should go away and skewness = 1.0
    T maxMDotV = std::numeric_limits<T>::epsilon();
    for (std::size_t i = 0; i < numNodes; ++i) {
        Vec3 v {
            faceNodes[i][0] - faceCentroid[0],
            faceNodes[i][1] - faceCentroid[1],
            faceNodes[i][2] - faceCentroid[2],
        };
        T mDotV = m[0]*v[0] + m[1]*v[1] + m[2]*v[2];
        maxMDotV = (std::max)(maxMDotV, mDotV);
    }

    T mDotM = m[0]*m[0] + m[1]*m[1] + m[2]*m[2];

    return T{1.0} - mDotM/maxMDotV;
}

/**
 * @brief Compute the maximum ratio between the volume of the cell and those of its 
 * neighbors. This ratio is always larger than one.
 * 
 * @tparam T The floating point type
 * @param cellVolume The cell volume
 * @param neighborVolumes A pointer to the frst element of an array containing
 * the volumes of the cell neighbors
 * @param numNeighbors The number of neighbors (the neighborVolumes array must
 * have at least numNeighbors elements)
 * @return T The maximum volume ratio
 */
template <typename T>
constexpr T
CATMshComputeVolumeRatio(const T& cellVolume,
                         const T* neighborVolumes, 
                         std::size_t numNeighbors)
{
    auto maxRatio = T{1.0};
    for (std::size_t i = 0; i < numNeighbors; ++i) {
        auto ratio = (cellVolume > neighborVolumes[i]) ? cellVolume/neighborVolumes[i]
                                                       : neighborVolumes[i]/cellVolume;
        maxRatio = (std::max)(maxRatio, ratio);
    }

    return maxRatio;
}

#endif // CATMshComputeQualityCriteriaNonLocal_H
