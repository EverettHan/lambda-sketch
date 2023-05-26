#ifndef CATMshComputeCentroid_H
#define CATMshComputeCentroid_H

#include <cmath>
#include <type_traits>

/**
 * @brief Compute the centroid of a triangular face.
 * The nodes must be ordered as per the Abaqus convention (S3).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], std::array<double, 3>, etc.)
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param centroid The centroid gets written in that Vec3 (passed by reference
 * so that it also works with Vec3=C-style arrays)
 */
template <typename Vec3>
constexpr void
CATMshComputeCentroidTri(const Vec3& node1, const Vec3& node2, 
                         const Vec3& node3, Vec3& centroid)
{
    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneThird = T{1.0}/T{3.0};

    centroid[0] = oneThird*(node1[0] + node2[0] + node3[0]);
    centroid[1] = oneThird*(node1[1] + node2[1] + node3[1]);
    centroid[2] = oneThird*(node1[2] + node2[2] + node3[2]);
}

/**
 * @brief Compute the centroid of a quadrilateral face.
 * The nodes must be ordered as per the Abaqus convention (S4).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], std::array<double, 3>, etc.)
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param node4 The fourth node
 * @param centroid The centroid gets written in that Vec3 (passed by reference
 * so that it also works with Vec3=C-style arrays)
 */
template <typename Vec3>
constexpr void
CATMshComputeCentroidQuad(const Vec3& node1, const Vec3& node2, 
                          const Vec3& node3, const Vec3& node4,
                          Vec3& centroid)
{
    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneFourth = T{0.25};

    centroid[0] = oneFourth*(node1[0] + node2[0] + node3[0] + node4[0]);
    centroid[1] = oneFourth*(node1[1] + node2[1] + node3[1] + node4[1]);
    centroid[2] = oneFourth*(node1[2] + node2[2] + node3[2] + node4[2]);
}

/**
 * @brief Compute the centroid of a tetrahedron. 
 * The nodes must be ordered as per the Abaqus convention (FC3D4).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], float*, std::array<double, 3>, etc.)
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param node4 The fourth node
 * @param centroid The centroid gets written in that Vec3 (passed by reference
 * so that it also works with Vec3=C-style arrays)
 */
template <typename Vec3>
constexpr void
CATMshComputeCentroidTet(const Vec3& node1, const Vec3& node2, 
                         const Vec3& node3, const Vec3& node4,
                         Vec3& centroid)
{
    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneFourth = T{0.25};

    centroid[0] = oneFourth*(node1[0] + node2[0] + node3[0] + node4[0]);
    centroid[1] = oneFourth*(node1[1] + node2[1] + node3[1] + node4[1]);
    centroid[2] = oneFourth*(node1[2] + node2[2] + node3[2] + node4[2]);
}

/**
 * @brief Compute the centroid of a pyramid.
 * The nodes must be ordered as per the Abaqus convention (FC3D5).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], float*, std::array<double, 3>, etc.)
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param node4 The fourth node
 * @param node5 The fifth node
 * @param centroid The centroid gets written in that Vec3 (passed by reference
 * so that it also works with Vec3=C-style arrays)
 */
template <typename Vec3>
constexpr void
CATMshComputeCentroidPyr(const Vec3& node1, const Vec3& node2, 
                         const Vec3& node3, const Vec3& node4,
                         const Vec3& node5, Vec3& centroid)
{
    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto threeFourth = T{3.0}/T{4.0};
    constexpr auto oneFourth = T{0.25};

    // pyr_centroid = (3*base_centroid + apex)/4

    centroid[0] = oneFourth*(threeFourth*(node1[0] + node2[0] + node3[0] + node4[0]) + node5[0]);
    centroid[1] = oneFourth*(threeFourth*(node1[1] + node2[1] + node3[1] + node4[1]) + node5[1]);
    centroid[2] = oneFourth*(threeFourth*(node1[2] + node2[2] + node3[2] + node4[2]) + node5[2]);
}

/**
 * @brief Compute the centroid of a wedge.
 * The nodes must be ordered as per the Abaqus convention (FC3D6).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], float*, std::array<double, 3>, etc.)
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param node4 The fourth node
 * @param node5 The fifth node
 * @param node6 The sixth node
 * @param centroid The centroid gets written in that Vec3 (passed by reference
 * so that it also works with Vec3=C-style arrays)
 */
template <typename Vec3>
constexpr void
CATMshComputeCentroidWed(const Vec3& node1, const Vec3& node2, 
                         const Vec3& node3, const Vec3& node4,
                         const Vec3& node5, const Vec3& node6,
                         Vec3& centroid)
{
    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneSixth = T{1.0}/T{6.0};

    centroid[0] = oneSixth*(node1[0] + node2[0] + node3[0] + node4[0] + node5[0] + node6[0]);
    centroid[1] = oneSixth*(node1[1] + node2[1] + node3[1] + node4[1] + node5[1] + node6[1]);
    centroid[2] = oneSixth*(node1[2] + node2[2] + node3[2] + node4[2] + node5[2] + node6[2]);
}

/**
 * @brief Compute the centroid of a hexahedron.
 * The nodes must be ordered as per the Abaqus convention (FC3D8).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], float*, std::array<double, 3>, etc.)
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param node4 The fourth node
 * @param node5 The fifth node
 * @param node6 The sixth node
 * @param node7 The seventh node
 * @param node8 The eighth node
 * @param centroid The centroid gets written in that Vec3 (passed by reference
 * so that it also works with Vec3=C-style arrays)
 */
template <typename Vec3>
constexpr void
CATMshComputeCentroidHex(const Vec3& node1, const Vec3& node2, 
                         const Vec3& node3, const Vec3& node4,
                         const Vec3& node5, const Vec3& node6,
                         const Vec3& node7, const Vec3& node8,
                         Vec3& centroid)
{
    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneEighth = T{1.0}/T{8.0};

    centroid[0] = oneEighth*(node1[0] + node2[0] + node3[0] + node4[0] 
                           + node5[0] + node6[0] + node7[0] + node8[0]);
    centroid[1] = oneEighth*(node1[1] + node2[1] + node3[1] + node4[1] 
                           + node5[1] + node6[1] + node7[1] + node8[1]);
    centroid[2] = oneEighth*(node1[2] + node2[2] + node3[2] + node4[2] 
                           + node5[2] + node6[2] + node7[2] + node8[2]);
}



#endif // CATMshComputeCentroid_H
