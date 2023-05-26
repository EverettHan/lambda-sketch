#ifndef CATMshComputeVolumeDispatcher_H
#define CATMshComputeVolumeDispatcher_H

#include <type_traits>

#include <CATMshComputeVolumeGaussTheorem.h>
#include <CATMshComputeVolumeMethod.h>
#include <CATMshComputeVolumeTetDecomposition.h>

namespace details {

/**
 * We need to use these dispatcher classes here because C++ does not allow 
 * partial template specializations. All this boilerplate can go away in R425, 
 * once we get constexpr if.
 */
template <CATMshComputeVolumeMethod Method, typename Vec3>
struct Dispatcher {
    static void ComputeTet(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4) {
        static_assert("The volume method is not available for this element type.");
    }

    static void ComputePyr(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4,
                           const Vec3& node5) {
        static_assert("The volume method is not available for this element type.");
    }

    static void ComputeWed(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4,
                           const Vec3& node5, const Vec3& node6) {
        static_assert("The volume method is not available for this element type.");
    }

    static void ComputeHex(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4,
                           const Vec3& node5, const Vec3& node6,
                           const Vec3& node7, const Vec3& node8) {
        static_assert("The volume method is not available for this element type.");
    }
};

template <typename Vec3>
struct Dispatcher<TET_DECOMPOSITION, Vec3> {
    static auto computeTet(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4) {
        return CATMshComputeVolumeTetTetDecomposition(node1, node2, node3, node4);
    }

    static auto computePyr(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4,
                           const Vec3& node5) {
        return CATMshComputeVolumePyrTetDecomposition(node1, node2, node3, node4, node5);
    }

    static auto computeWed(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4,
                           const Vec3& node5, const Vec3& node6) {
        return CATMshComputeVolumeWedTetDecomposition(node1, node2, node3, 
                                                      node4, node5, node6);
    }

    static auto computeHex(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4,
                           const Vec3& node5, const Vec3& node6,
                           const Vec3& node7, const Vec3& node8) {
        return CATMshComputeVolumeHexTetDecomposition(node1, node2, node3, node4, 
                                                      node5, node6, node7, node8);
    }
};

template <typename Vec3>
struct Dispatcher<GAUSS_THEOREM, Vec3> {
    static auto computeTet(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4) {
        return CATMshComputeVolumeTetGaussTheorem(node1, node2, node3, node4);
    }

    static auto computePyr(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4,
                           const Vec3& node5) {
        return CATMshComputeVolumePyrGaussTheorem(node1, node2, node3, node4, node5);
    }

    static auto computeWed(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4,
                           const Vec3& node5, const Vec3& node6) {
        return CATMshComputeVolumeWedGaussTheorem(node1, node2, node3, 
                                                  node4, node5, node6);
    }

    static auto computeHex(const Vec3& node1, const Vec3& node2, 
                           const Vec3& node3, const Vec3& node4,
                           const Vec3& node5, const Vec3& node6,
                           const Vec3& node7, const Vec3& node8) {
        return CATMshComputeVolumeHexGaussTheorem(node1, node2, node3, node4, 
                                                  node5, node6, node7, node8);
    }
};

} // namespace details

#endif // CATMshComputeVolumeDispatcher_H
