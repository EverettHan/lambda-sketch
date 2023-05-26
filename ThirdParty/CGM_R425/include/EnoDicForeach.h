//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011/01/05
//===================================================================
/**
 * @level Private
 * @usage U3
 *
 * @fullReview CP7 11:01:05
 */

#ifndef EnoDicForeach_h
#define EnoDicForeach_h

#define CONCAT( a, b ) a ## b
#define TEMP_OBJ( a, b ) CONCAT( a, b )
#define FOREACH_AIX_FIX( var ) TEMP_OBJ( var, __LINE__ )

/**
 * Allows you to add a statement which is deleted once the scope ends.
 */
#define DS_DECLARE_SCOPE_ASSIGNEMENT( statement ) \
  for( bool FOREACH_AIX_FIX( scope_assignement_switcher ) = true; \
       FOREACH_AIX_FIX( scope_assignement_switcher ); \
       /*NOTHING*/) \
    for( statement; \
         FOREACH_AIX_FIX( scope_assignement_switcher ); \
         FOREACH_AIX_FIX( scope_assignement_switcher )= false )

// $$$$ 2011-09-28 CP7: On Sun/Solaris, I got this error : "Error: Partial specialization is not implemented."
#if defined(_SUNOS_SOURCE)
# include "EnoDicForeach_Sun.h"
#else
namespace details
{
template< typename T >
struct is_pointer
{
  static const bool value = false;
};

template< typename T >
struct is_pointer< T* >
{
  static const bool value = true;
};

template< typename T >
struct remove_pointer
{
  typedef T type;
};

template< typename T >
struct remove_pointer< T* >
{
  typedef T& type;
};

template< bool >
struct algorithm_selector;

template<>
struct algorithm_selector< true >
{
  template< typename T >
  static T& impl( T* pValue )
  {
    return *pValue;
  }
 
  template< typename T >
  static T& impl_with_ref( T* pValue )
  {
    return *pValue;
  }
};

template<>
struct algorithm_selector< false >
{
  template< typename T >
  static T impl( T value )
  {
    return value;
  }
  template< typename T >
  static T& impl_with_ref( T& value )
  {
    return value;
  }
};

template< typename T, typename U >
typename remove_pointer< T >::type traits( T value, const U& list )
{
  return algorithm_selector< is_pointer< T >::value >::impl( value );
}
template< typename T, typename U >
typename remove_pointer< T >::type& traits( T& value, U& list )
{
  return algorithm_selector< is_pointer< T >::value >::impl_with_ref( value );
}
}

/**
 * For iterating over a CATList.
 * For example:
 * CATListOfThings things;
 * DS_FOREACH( const Thing& thing, things )
 * {
 *   cout << thing << endl;
 * }
 *
 * It is quite like you had written:
 * CATListOfThings things;
 * const int size = things.Size();
 * for( int i = 1; i <= size; ++i )
 * {
 *   const Thing& thing = *things[i];
 *   {
 *     cout << thing.Name() << endl;
 *   }
 * }
 *
 * @arg type is the type of the content of the list
 * @arg var is the variable name of the content of the list
 * @arg list is simply the list
 */
// $$$$ 2011-06-03 CP7: list is evaluated many times, that sucks
#define DS_FOREACH( var, list ) \
  DS_DECLARE_SCOPE_ASSIGNEMENT( bool foreach_aix_fix = true ) \
    for( int foreach_i = 1, foreach_size = list.Size(); \
         foreach_i <= foreach_size; \
         ++foreach_i ) \
      DS_DECLARE_SCOPE_ASSIGNEMENT( var = details::traits( list[foreach_i], list ) )

#endif /*SUN*/

#endif /*EnoDicForeach_h*/
