#ifndef CATMshComputeFace_H
#define CATMshComputeFace_H

#include <cmath>
#include <type_traits>

#include <CATMshComputeCentroid.h>

/**
 * @brief Compute the area and unit normal vector of a triangular face, using
 * a simple cross product.
 * The nodes must be ordered as per the Abaqus convention (S3).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], std::array<double, 3>, etc.)
 * This type cannot be a pointer type (e.g. float*), as it would cause the centroid
 * creation to fail.
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param normal The unit normal vector gets written in that Vec3 (passed by reference
 * so that it also works with Vec3=C-style arrays)
 * @return auto The face area. The face unit normal vector is returned by reference.
 * The type is deduced from the template parameter Vec3.
 */
template <typename Vec3>
constexpr auto
CATMshComputeAreaAndUnitNormalTri(const Vec3& node1, const Vec3& node2, 
                                  const Vec3& node3, Vec3& normal)
{
    // if Vec3=double* for example, the face normal creation will fail
    static_assert(!std::is_pointer<Vec3>::value, "you cannot use pointer types for the nodes");

    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto one     = T{1.0};
    constexpr auto oneHalf = T{0.5};

    auto x21 = node2[0] - node1[0];
    auto y21 = node2[1] - node1[1];
    auto z21 = node2[2] - node1[2];

    auto x31 = node3[0] - node1[0];
    auto y31 = node3[1] - node1[1];
    auto z31 = node3[2] - node1[2];

    normal[0] = y21*z31 - z21*y31;
    normal[1] = z21*x31 - x21*z31;
    normal[2] = x21*y31 - y21*x31;

    auto mag = std::sqrt(normal[0]*normal[0] + normal[1]*normal[1] + normal[2]*normal[2]);
    auto invMag = one/mag;

    normal[0] *= invMag;
    normal[1] *= invMag;
    normal[2] *= invMag;

    return oneHalf*mag;
}

/**
 * @brief Compute the area of a triangular face, using a simple cross product.
 * The nodes must be ordered as per the Abaqus convention (S3).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], std::array<double, 3>, etc.)
 * This type cannot be a pointer type (e.g. float*), as it would cause the centroid
 * creation to fail.
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @return auto The face area. The type is deduced from the template parameter Vec3.
 */
template <typename Vec3>
constexpr auto
CATMshComputeAreaTri(const Vec3& node1, const Vec3& node2, const Vec3& node3)
{
    // if Vec3=double* for example, the face normal creation will fail
    static_assert(!std::is_pointer<Vec3>::value, "you cannot use pointer types for the nodes");

    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneHalf = T{0.5};

    auto x21 = node2[0] - node1[0];
    auto y21 = node2[1] - node1[1];
    auto z21 = node2[2] - node1[2];

    auto x31 = node3[0] - node1[0];
    auto y31 = node3[1] - node1[1];
    auto z31 = node3[2] - node1[2];

    Vec3 normal = {
        y21*z31 - z21*y31,
        z21*x31 - x21*z31,
        x21*y31 - y21*x31 
    };

    auto mag = std::sqrt(normal[0]*normal[0] + normal[1]*normal[1] + normal[2]*normal[2]);

    return oneHalf*mag;
}

/**
 * @brief Compute the area and unit normal vector of a quadrilateral face, by
 * decomposing it into four triangular faces, going through the face centroid.
 * The face normal is taken as the average of the non-unit subface normals. The
 * result is then normalized to have unit magnitude.
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
 * @param normal The unit normal vector gets written in that Vec3 (passed by reference
 * so that it also works with Vec3=C-style arrays)
 * @return auto The face area. The face unit normal vector is returned by reference.
 * The type is deduced from the template parameter Vec3.
 */
template <typename Vec3>
constexpr auto
CATMshComputeAreaAndUnitNormalQuad(const Vec3& node1, const Vec3& node2, 
                                   const Vec3& node3, const Vec3& node4,
                                   Vec3& normal)
{
    // if Vec3=double* for example, the centroid and face normal creation will fail
    static_assert(!std::is_pointer<Vec3>::value, "you cannot use pointer types for the nodes");

    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneQuarter = T{0.25};
    constexpr auto oneHalf    = T{0.5};
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

    Vec3 n23c = {
        y2c*z3c - z2c*y3c,
        z2c*x3c - x2c*z3c,
        x2c*y3c - y2c*x3c
    };

    Vec3 n34c = {
        y3c*z4c - z3c*y4c,
        z3c*x4c - x3c*z4c,
        x3c*y4c - y3c*x4c
    };

    Vec3 n41c = {
        y4c*z1c - z4c*y1c,
        z4c*x1c - x4c*z1c,
        x4c*y1c - y4c*x1c
    };

    auto mag12c = std::sqrt(n12c[0]*n12c[0] + n12c[1]*n12c[1] + n12c[2]*n12c[2]);
    auto mag23c = std::sqrt(n23c[0]*n23c[0] + n23c[1]*n23c[1] + n23c[2]*n23c[2]);
    auto mag34c = std::sqrt(n34c[0]*n34c[0] + n34c[1]*n34c[1] + n34c[2]*n34c[2]);
    auto mag41c = std::sqrt(n41c[0]*n41c[0] + n41c[1]*n41c[1] + n41c[2]*n41c[2]);

    T total_area = oneHalf*(mag12c + mag23c + mag34c + mag41c);

    normal[0] =	oneQuarter*(n12c[0] + n23c[0] + n34c[0] + n41c[0]);
    normal[1] =	oneQuarter*(n12c[1] + n23c[1] + n34c[1] + n41c[1]);
    normal[2] =	oneQuarter*(n12c[2] + n23c[2] + n34c[2] + n41c[2]);

    auto mag = std::sqrt(normal[0]*normal[0] + normal[1]*normal[1] + normal[2]*normal[2]);
    auto invMag = one/mag;

    normal[0] *= invMag;
    normal[1] *= invMag;
    normal[2] *= invMag;

    return total_area;
}

/**
 * @brief Compute the area of a quadrilateral face, by decomposing it into 
 * four triangular faces, going through the face centroid.
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
 * @return auto The face area. The type is deduced from the template parameter Vec3.
 */
template <typename Vec3>
constexpr auto
CATMshComputeAreaQuad(const Vec3& node1, const Vec3& node2, const Vec3& node3, const Vec3& node4)
{
    // if Vec3=double* for example, the centroid and face normal creation will fail
    static_assert(!std::is_pointer<Vec3>::value, "you cannot use pointer types for the nodes");

    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneQuarter = T{0.25};
    constexpr auto oneHalf    = T{0.5};

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

    Vec3 n23c = {
        y2c*z3c - z2c*y3c,
        z2c*x3c - x2c*z3c,
        x2c*y3c - y2c*x3c
    };

    Vec3 n34c = {
        y3c*z4c - z3c*y4c,
        z3c*x4c - x3c*z4c,
        x3c*y4c - y3c*x4c
    };

    Vec3 n41c = {
        y4c*z1c - z4c*y1c,
        z4c*x1c - x4c*z1c,
        x4c*y1c - y4c*x1c
    };

    auto mag12c = std::sqrt(n12c[0]*n12c[0] + n12c[1]*n12c[1] + n12c[2]*n12c[2]);
    auto mag23c = std::sqrt(n23c[0]*n23c[0] + n23c[1]*n23c[1] + n23c[2]*n23c[2]);
    auto mag34c = std::sqrt(n34c[0]*n34c[0] + n34c[1]*n34c[1] + n34c[2]*n34c[2]);
    auto mag41c = std::sqrt(n41c[0]*n41c[0] + n41c[1]*n41c[1] + n41c[2]*n41c[2]);

    return oneHalf*(mag12c + mag23c + mag34c + mag41c);
}

#endif // CATMshComputeFace_H
