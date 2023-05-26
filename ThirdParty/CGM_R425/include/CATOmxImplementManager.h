#ifndef CATOmxImplementManager_H
#define CATOmxImplementManager_H

#include "CATOmxCxxPortability.h"

#if OMX_CXX11 == 0
#error CATOmxImplementManager is usable only on C++11-supported target
#endif

#include "CATOmxPortability.h"
#include "CATOmxClassManager.h"
#include "CATOmxCollecManagers.h"
#include <type_traits>
#include "CATBaseUnknown.h"
#include "CATOmxSharable.h"

namespace omx
{
  /**
   * internal usage
   * omx::is_pointed_base_of<IUnknown, CATOmxSharable*>::value is true
   * omx::is_pointed_base_of<CATOmxSharable, IUnknown*>::value is false
   * omx::is_pointed_base_of<IUnknown, CATOmxSharable>::value  is false
   */
  template<class BaseType, typename PointerType>
  struct is_pointed_base_of : public
    std::integral_constant<bool,
    std::is_pointer<PointerType>::value && std::is_base_of<BaseType, typename std::remove_pointer<PointerType>::type>::value
    >
  {};
}

/**
 * specialization of CATOmxImplementManager for CATBaseUnknown pointers
 * returns cbu_manager
 */
template<typename PointerType>
inline typename std::enable_if<omx::is_pointed_base_of < CATBaseUnknown, PointerType > ::value, CATOmxCollecManager&>::type CATOmxImplementManager()
{
  return cbu_manager();
}

/**
 * specialization of CATOmxImplementManager for CATOmxSharable pointers
 * returns sharable_manager
 */
template<typename PointerType>
inline typename std::enable_if<omx::is_pointed_base_of<CATOmxSharable, PointerType>::value, CATOmxCollecManager&>::type CATOmxImplementManager()
{
  return sharable_manager();
}

/**
 * specialization of CATOmxImplementManager for IUnknown pointers
 * returns com_manager
 */
template<typename PointerType>
inline
typename std::enable_if<
  std::is_pointer<PointerType>::value
  && !omx::is_pointed_base_of<CATBaseUnknown, PointerType>::value
  && !omx::is_pointed_base_of<CATOmxSharable, PointerType>::value
  , CATOmxCollecManager&>::type CATOmxImplementManager()
{
  static_assert(omx::is_pointed_base_of<IUnknown, PointerType>::value, "CATOmxImplementManager only works for IUnknown derived types");
  return com_manager();
}

/**
 * specialization of CATOmxImplementManager for enum
 * returns enum_manager
 */
template<typename EnumType>
inline typename std::enable_if<std::is_enum<EnumType>::value, CATOmxCollecManager&>::type CATOmxImplementManager()
{
  return enum_manager<EnumType>();
}

/**
 * specialization of CATOmxImplementManager for class
 * returns a CATOmxClassManager
 */
template<typename ClassType>
inline typename std::enable_if<!std::is_pointer<ClassType>::value && !std::is_enum<ClassType>::value, CATOmxCollecManager&>::type CATOmxImplementManager()
{
  static_assert(!std::is_arithmetic<ClassType>::value, "CATOmxDefaultCollecManager is already implemented for all numeric types");
  static_assert(!std::is_reference<ClassType>::value, "illegal usage");
  static auto* s_manager = new CATOmxClassManager<ClassType>;
  return *s_manager;
}

#endif

