#ifndef CATMshComputeVolume_H
#define CATMshComputeVolume_H

#include <type_traits>

#include <CATMshComputeVolumeDispatcher.h>
#include <CATMshComputeVolumeMethod.h>

/**
 * @brief Compute the volume of a tetrahedron. 
 * The nodes must be ordered as per the Abaqus convention (FC3D4).
 * 
 * @tparam Method The method used to compute the volume
 * @tparam Vec3 The type containing a node. It must have the bracket operator 
 * and at least three elements (My3DVector, double[3], float*, std::array<double, 3>, etc.)
 * @param node1 The first node
 * @param node2 The second node
 * @param node3 The third node
 * @param node4 The fourth node
 * @return auto The volume of the tetrahedron. The type is deduced from the template
 * parameter Vec3.
 */
template <CATMshComputeVolumeMethod Method, typename Vec3>
constexpr auto
CATMshComputeVolumeTet(const Vec3& node1, const Vec3& node2, 
                       const Vec3& node3, const Vec3& node4)
{
    return details::Dispatcher<Method, Vec3>::computeTet(node1, node2, node3, node4);
}

/**
 * @brief Compute the volume of a pyramid.
 * The nodes must be ordered as per the Abaqus convention (FC3D5).
 * 
 * @tparam Method The method used to compute the volume
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
template <CATMshComputeVolumeMethod Method, typename Vec3>
constexpr auto
CATMshComputeVolumePyr(const Vec3& node1, const Vec3& node2, 
                       const Vec3& node3, const Vec3& node4,
                       const Vec3& node5)
{
    return details::Dispatcher<Method, Vec3>::computePyr(node1, node2, node3, node4, node5);
}

/**
 * @brief Compute the volume of a wedge.
 * The nodes must be ordered as per the Abaqus convention (FC3D6).
 * 
 * @tparam Method The method used to compute the volume
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
template <CATMshComputeVolumeMethod Method, typename Vec3>
constexpr auto
CATMshComputeVolumeWed(const Vec3& node1, const Vec3& node2, 
                       const Vec3& node3, const Vec3& node4,
                       const Vec3& node5, const Vec3& node6)
{
    return details::Dispatcher<Method, Vec3>::computeWed(node1, node2, node3, 
                                                         node4, node5, node6);
}

/**
 * @brief Compute the volume of a hexahedron.
 * The nodes must be ordered as per the Abaqus convention (FC3D8).
 * 
 * @tparam Method The method used to compute the volume
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
template <CATMshComputeVolumeMethod Method, typename Vec3>
constexpr auto
CATMshComputeVolumeHex(const Vec3& node1, const Vec3& node2, 
                       const Vec3& node3, const Vec3& node4,
                       const Vec3& node5, const Vec3& node6,
                       const Vec3& node7, const Vec3& node8)
{
    return details::Dispatcher<Method, Vec3>::computeHex(node1, node2, node3, node4, 
                                                         node5, node6, node7, node8);
}

#endif // CATMshComputeVolume_H
