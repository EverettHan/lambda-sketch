#ifndef CATMshComputeVolumeTetDecomposition_H
#define CATMshComputeVolumeTetDecomposition_H

#include <type_traits>

#include <CATMshComputeCentroid.h>

namespace details {

/**
 * @brief Compute the volume of a tetrahedron using the pyramid volume
 * formula. The nodes must be ordered as per the Abaqus convention (FC3D4).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], float*, std::array<double, 3>, etc.)
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param node4 The fourth node
 * @return auto The volume of the tetrahedron. The type is deduced from the template
 * parameter Vec3.
 */
template <typename Vec3>
constexpr auto
CATMshComputeVolumeTetTetDecomposition(const Vec3& node1, const Vec3& node2, 
                                       const Vec3& node3, const Vec3& node4)
{
    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    auto x21 = node2[0] - node1[0];
    auto y21 = node2[1] - node1[1];
    auto z21 = node2[2] - node1[2];

    auto x31 = node3[0] - node1[0];
    auto y31 = node3[1] - node1[1];
    auto z31 = node3[2] - node1[2];

    auto x41 = node4[0] - node1[0];
    auto y41 = node4[1] - node1[1];
    auto z41 = node4[2] - node1[2];

    constexpr auto oneSixth = T{1.0 / 6.0};

    return oneSixth*( x41*(y21*z31 - z21*y31)
                    + y41*(z21*x31 - x21*z31)
                    + z41*(x21*y31 - y21*x31));
}

/**
 * @brief Compute the volume of a pyramid, by decomposing it into four
 * tetrahedrons. All tetrahedrons go through the centroid of the quad base.
 * The nodes must be ordered as per the Abaqus convention (FC3D5).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], std::array<double, 3>, etc.)
 * This type cannot be a pointer type (e.g. float*), as it would cause the centroid
 * creation to fail.
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param node4 The fourth node
 * @param node5 The fifth node
 * @return auto The volume of the pyramid. The type is deduced from the template
 * parameter Vec3.
 */
template <typename Vec3>
constexpr auto
CATMshComputeVolumePyrTetDecomposition(const Vec3& node1, const Vec3& node2, 
                                       const Vec3& node3, const Vec3& node4, 
                                       const Vec3& node5)
{
    // if Vec3=double* for example, the centroid creation will fail
    static_assert(!std::is_pointer<Vec3>::value, "you cannot use pointer types for the nodes");

    // centroid of the base
    Vec3 baseCentroid;
    CATMshComputeCentroidQuad(node1, node2, node3, node4, baseCentroid); 

    return CATMshComputeVolumeTetTetDecomposition(node1, node5, node2, baseCentroid)
         + CATMshComputeVolumeTetTetDecomposition(node2, node5, node3, baseCentroid)
         + CATMshComputeVolumeTetTetDecomposition(node3, node5, node4, baseCentroid)
         + CATMshComputeVolumeTetTetDecomposition(node4, node5, node1, baseCentroid);
}

/**
 * @brief Compute the volume of a wedge, by decomposing it into three pyramids
 * and two tetrahedrons. All sub-elements go through the centroid of the wedge.
 * The nodes must be ordered as per the Abaqus convention (FC3D6).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], std::array<double, 3>, etc.)
 * This type cannot be a pointer type (e.g. float*), as it would cause the centroid
 * creation to fail.
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param node4 The fourth node
 * @param node5 The fifth node
 * @param node6 The sixth node
 * @return auto The volume of the wedge. The type is deduced from the template
 * parameter Vec3.
 */
template <typename Vec3>
constexpr auto
CATMshComputeVolumeWedTetDecomposition(const Vec3& node1, const Vec3& node2, 
                                       const Vec3& node3, const Vec3& node4,
                                       const Vec3& node5, const Vec3& node6)
{
    // if Vec3=double* for example, the centroid creation will fail
    static_assert(!std::is_pointer<Vec3>::value, "you cannot use pointer types for the nodes");

    // centroid of the wedge
    Vec3 centroid;
    CATMshComputeCentroidWed(node1, node2, node3, node4, node5, node6, centroid);

    return CATMshComputeVolumePyrTetDecomposition(node1, node4, node5, node2, centroid)
         + CATMshComputeVolumePyrTetDecomposition(node2, node5, node6, node3, centroid)
         + CATMshComputeVolumePyrTetDecomposition(node3, node6, node4, node1, centroid)
         + CATMshComputeVolumeTetTetDecomposition(node1, node2, node3, centroid)
         + CATMshComputeVolumeTetTetDecomposition(node4, node6, node5, centroid);
}

/**
 * @brief Compute the volume of a hexahedron, by decomposing it into six pyramids.
 * All pyramids go through the centroid of the hexahedron.
 * The nodes must be ordered as per the Abaqus convention (FC3D8).
 * 
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], std::array<double, 3>, etc.)
 * This type cannot be a pointer type (e.g. float*), as it would cause the centroid
 * creation to fail.
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param node4 The fourth node
 * @param node5 The fifth node
 * @param node6 The sixth node
 * @param node7 The seventh node
 * @param node8 The eighth node
 * @return auto The volume of the hexahedron. The type is deduced from the template
 * parameter Vec3.
 */
template <typename Vec3>
constexpr auto
CATMshComputeVolumeHexTetDecomposition(const Vec3& node1, const Vec3& node2, 
                                       const Vec3& node3, const Vec3& node4, 
                                       const Vec3& node5, const Vec3& node6,
                                       const Vec3& node7, const Vec3& node8)
{
    // if Vec3=double* for example, the centroid creation will fail
    static_assert(!std::is_pointer<Vec3>::value, "you cannot use pointer types for the nodes");

    // centroid of the hex
    Vec3 centroid;
    CATMshComputeCentroidHex(node1, node2, node3, node4, node5, node6, node7, node8, centroid);
    
    return CATMshComputeVolumePyrTetDecomposition(node1, node5, node6, node2, centroid)
         + CATMshComputeVolumePyrTetDecomposition(node2, node6, node7, node3, centroid)
         + CATMshComputeVolumePyrTetDecomposition(node3, node7, node8, node4, centroid)
         + CATMshComputeVolumePyrTetDecomposition(node4, node8, node5, node1, centroid)
         + CATMshComputeVolumePyrTetDecomposition(node5, node8, node7, node6, centroid)
         + CATMshComputeVolumePyrTetDecomposition(node1, node2, node3, node4, centroid);
}

}

#endif // CATMshComputeVolumeTetDecomposition_H
