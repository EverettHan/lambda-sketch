#ifndef CATMshComputeVolumeGaussTheorem_H
#define CATMshComputeVolumeGaussTheorem_H

#include <type_traits>

#include <CATMshComputeCentroid.h>
#include <CATMshComputeFace.h>

namespace details {

/**
 * @brief Helper function to compute the Gauss contribution for a triangular face.
 */
template <typename Vec3>
constexpr auto
CATMshComputeTriFaceGaussContribution(const Vec3& node1, const Vec3& node2, const Vec3& node3)
{
    Vec3 normal{};
    auto area = CATMshComputeAreaAndUnitNormalTri(node1, node2, node3, normal);

    return area*(normal[0]*node1[0] + normal[1]*node1[1] + normal[2]*node1[2]);
}

/**
 * @brief Helper function to compute the Gauss contribution for a quadrilateral face.
 */
template <typename Vec3>
constexpr auto
CATMshComputeQuadFaceGaussContribution(const Vec3& node1, const Vec3& node2, const Vec3& node3, const Vec3& node4)
{
    // if Vec3=double* for example, the centroid creation will fail
    static_assert(!std::is_pointer<Vec3>::value, "you cannot use pointer types for the nodes");

    // centroid of the base
    Vec3 baseCentroid;
    CATMshComputeCentroidQuad(node1, node2, node3, node4, baseCentroid);

    return CATMshComputeTriFaceGaussContribution(node1, node2, baseCentroid)
         + CATMshComputeTriFaceGaussContribution(node2, node3, baseCentroid)
         + CATMshComputeTriFaceGaussContribution(node3, node4, baseCentroid)
         + CATMshComputeTriFaceGaussContribution(node4, node1, baseCentroid);
}

/**
 * @brief Compute the volume of a tetrahedron using Gauss theorem.
 * The nodes must be ordered as per the Abaqus convention (FC3D4).
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
CATMshComputeVolumeTetGaussTheorem(const Vec3& node1, const Vec3& node2, 
                                   const Vec3& node3, const Vec3& node4)
{
    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneThird = T{1.0}/T{3.0};

    return oneThird*( CATMshComputeTriFaceGaussContribution(node1, node2, node4)
                    + CATMshComputeTriFaceGaussContribution(node2, node3, node4) 
                    + CATMshComputeTriFaceGaussContribution(node3, node1, node4)
                    + CATMshComputeTriFaceGaussContribution(node1, node3, node2));
}

/**
 * @brief Compute the volume of a pyramid using Gauss theorem. Each quadrilateral
 * face is decomposed into triangles going through the face centroid.
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
CATMshComputeVolumePyrGaussTheorem(const Vec3& node1, const Vec3& node2, 
                                   const Vec3& node3, const Vec3& node4, 
                                   const Vec3& node5)
{
    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneThird = T{1.0}/T{3.0};

    return oneThird*( CATMshComputeTriFaceGaussContribution(node1, node2, node5)
                    + CATMshComputeTriFaceGaussContribution(node2, node3, node5)
                    + CATMshComputeTriFaceGaussContribution(node3, node4, node5)
                    + CATMshComputeTriFaceGaussContribution(node4, node1, node5)
                    + CATMshComputeQuadFaceGaussContribution(node1, node4, node3, node2));
}

/**
 * @brief Compute the volume of a wedfe using Gauss theorem. Each quadrilateral
 * face is decomposed into triangles going through the face centroid.
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
CATMshComputeVolumeWedGaussTheorem(const Vec3& node1, const Vec3& node2, 
                                   const Vec3& node3, const Vec3& node4,
                                   const Vec3& node5, const Vec3& node6)
{
    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneThird = T{1.0}/T{3.0};

    return oneThird*( CATMshComputeTriFaceGaussContribution(node4, node5, node6)
                    + CATMshComputeTriFaceGaussContribution(node1, node3, node2)
                    + CATMshComputeQuadFaceGaussContribution(node1, node2, node5, node4)
                    + CATMshComputeQuadFaceGaussContribution(node2, node3, node6, node5)
                    + CATMshComputeQuadFaceGaussContribution(node3, node1, node4, node6));
}

/**
 * @brief Compute the volume of a hexahedron using Gauss theorem. Each quadrilateral
 * face is decomposed into triangles going through the face centroid.
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
CATMshComputeVolumeHexGaussTheorem(const Vec3& node1, const Vec3& node2, 
                                   const Vec3& node3, const Vec3& node4, 
                                   const Vec3& node5, const Vec3& node6,
                                   const Vec3& node7, const Vec3& node8)
{
    // decltype to retrieve the underlying type (float, double, etc)
    using T = std::decay_t<decltype(node1[0])>;

    constexpr auto oneThird = T{1.0}/T{3.0};

    return oneThird*( CATMshComputeQuadFaceGaussContribution(node1, node2, node6, node5)
                    + CATMshComputeQuadFaceGaussContribution(node2, node3, node7, node6)
                    + CATMshComputeQuadFaceGaussContribution(node3, node4, node8, node7)
                    + CATMshComputeQuadFaceGaussContribution(node4, node1, node5, node8)
                    + CATMshComputeQuadFaceGaussContribution(node1, node4, node3, node2)
                    + CATMshComputeQuadFaceGaussContribution(node5, node6, node7, node8));
}

}

#endif // CATMshComputeVolumeGaussTheorem_H
