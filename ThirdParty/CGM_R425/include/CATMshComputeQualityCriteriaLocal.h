#ifndef CATMshComputeQualityCriteriaLocal_H
#define CATMshComputeQualityCriteriaLocal_H

#include <algorithm>
#include <array>
#include <cstddef>
#include <cmath>

#include <CATMshComputeCentroid.h>

/**
 * @brief Compute the warp angle of a quadrilateral face. The face is
 * decomposed into four triangular subfaces, whose normals are 
 * computed. The face warp angle is calculated as the maximum angle
 * between any two subface normal vectors.
 * The nodes must be ordered as per the Abaqus convention (S4).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], std::array<double, 3>, etc.)
 * This type cannot be a pointer type (e.g. float*), as it would cause the centroid
 * creation to fail.
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param node4 The fourth node
 * @return T The face warp angle in degrees.
 */
template <typename Vec3>
constexpr auto 
CATMshComputeWarpAngle(const Vec3& node1, const Vec3& node2,
                       const Vec3& node3, const Vec3& node4)
{
    // if Vec3=double* for example, the centroid and face normal creation will fail
    static_assert(!std::is_pointer<Vec3>::value, "you cannot use pointer types for the nodes");

    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneQuarter = T{0.25};
    constexpr auto one        = T{1.0};

    // centroid of the face
    Vec3 centroid;
    CATMshComputeCentroidQuad(node1, node2, node3, node4, centroid);

    auto x1c = node1[0] - centroid[0];
    auto y1c = node1[1] - centroid[1];
    auto z1c = node1[2] - centroid[2];

    auto x2c = node2[0] - centroid[0];
    auto y2c = node2[1] - centroid[1];
    auto z2c = node2[2] - centroid[2];

    auto x3c = node3[0] - centroid[0];
    auto y3c = node3[1] - centroid[1];
    auto z3c = node3[2] - centroid[2];

    auto x4c = node4[0] - centroid[0];
    auto y4c = node4[1] - centroid[1];
    auto z4c = node4[2] - centroid[2];

    Vec3 n12c = {
        y1c*z2c - z1c*y2c,
        z1c*x2c - x1c*z2c,
        x1c*y2c - y1c*x2c
    };
    auto invMag12c = one/std::sqrt(n12c[0]*n12c[0] + n12c[1]*n12c[1] + n12c[2]*n12c[2]);
    n12c[0] *= invMag12c;
    n12c[1] *= invMag12c;
    n12c[2] *= invMag12c;

    Vec3 n23c = {
        y2c*z3c - z2c*y3c,
        z2c*x3c - x2c*z3c,
        x2c*y3c - y2c*x3c
    };
    auto invMag23c = one/std::sqrt(n23c[0]*n23c[0] + n23c[1]*n23c[1] + n23c[2]*n23c[2]);
    n23c[0] *= invMag23c;
    n23c[1] *= invMag23c;
    n23c[2] *= invMag23c;

    Vec3 n34c = {
        y3c*z4c - z3c*y4c,
        z3c*x4c - x3c*z4c,
        x3c*y4c - y3c*x4c
    };
    auto invMag34c = one/std::sqrt(n34c[0]*n34c[0] + n34c[1]*n34c[1] + n34c[2]*n34c[2]);
    n34c[0] *= invMag34c;
    n34c[1] *= invMag34c;
    n34c[2] *= invMag34c;

    Vec3 n41c = {
        y4c*z1c - z4c*y1c,
        z4c*x1c - x4c*z1c,
        x4c*y1c - y4c*x1c
    };
    auto invMag41c = one/std::sqrt(n41c[0]*n41c[0] + n41c[1]*n41c[1] + n41c[2]*n41c[2]);
    n41c[0] *= invMag41c;
    n41c[1] *= invMag41c;
    n41c[2] *= invMag41c;

    std::array<T, 6> cosines {
        n12c[0]*n23c[0] + n12c[1]*n23c[1] + n12c[2]*n23c[2],
        n12c[0]*n34c[0] + n12c[1]*n34c[1] + n12c[2]*n34c[2],
        n12c[0]*n41c[0] + n12c[1]*n41c[1] + n12c[2]*n41c[2],
        n23c[0]*n34c[0] + n23c[1]*n34c[1] + n23c[2]*n34c[2],
        n23c[0]*n41c[0] + n23c[1]*n41c[1] + n23c[2]*n41c[2],
        n34c[0]*n41c[0] + n34c[1]*n41c[1] + n34c[2]*n41c[2] 
    };

    T minCos = *std::min_element(std::cbegin(cosines), std::cend(cosines));

    // floating point representation can cause acos to fail. Need to clamp it to be safe.
    minCos = (std::min)((std::max)(minCos, T{-1.0}), T{1.0}); 

    constexpr T pi = T{3.1415926535897932385L};
    constexpr T radToDeg = T{180.0}/pi;

    return std::acos(minCos)*radToDeg;
}

/**
 * @brief Check if the centroid lies within the cell. We do so by computing the dot product
 * of the x vector (cell centroid to face centroid) with the face normal vector. This value
 * must always be positive. Note that for some concave elements, the centroid might actually
 * be inside the cell, but still violate this criterion. That is done on purpose. We also want
 * to flag those cells.
 * 
 * @tparam Vec3 The type containing a vector. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], std::array<double, 3>, etc.)
 * This type cannot be a pointer type (e.g. float*), as it would cause the vector
 * creation to fail.
 * @param cellCentroid The centroid of the element
 * @param faceNormals A pointer to the first element of an array containing
 * the face normals (array of structures, should point towards the neighboring cells)
 * @param faceCentroids A pointer to the first element of an array containing
 * the face centroids (array of structures)
 * @param numFaces The number of faces of the element (the faceNormals and faceCentroids
 * arrays must have at least numFaces elements)
 * @return bool true if the centroid is inside the cell, false otherwise
 */
template <typename Vec3>
constexpr bool 
CATMshCheckCentroidInCell(const Vec3& cellCentroid,
                          const Vec3* faceNormals, 
                          const Vec3* faceCentroids, 
                          std::size_t numFaces)
{
    for (std::size_t f = 0; f < numFaces; ++f) {
        Vec3 x = {
            faceCentroids[f][0] - cellCentroid[0],
            faceCentroids[f][1] - cellCentroid[1],
            faceCentroids[f][2] - cellCentroid[2],
        };

        if (x[0]*faceNormals[f][0] + x[1]*faceNormals[f][1] + x[2]*faceNormals[f][2] < 0.0)
            return false;
    }

    return true;
}

#endif // CATMshComputeQualityCriteriaLocal_H
