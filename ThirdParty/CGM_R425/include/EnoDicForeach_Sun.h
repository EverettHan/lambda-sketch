//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011/01/05
//===================================================================
/**
 * @level Private
 * @usage U3
 *
 * @fullReview CP7 11:09:28
 */

#ifndef EnoDicForeach_Sun_h
#define EnoDicForeach_Sun_h

namespace details
{
template< typename T, typename Y >
T& traits( int i, Y& list, T /*result_type*/ )
{
  return list[i];
}

template< typename T, typename Y >
T traits( int i, const Y& list, T /*result_type*/ )
{
  return list[i];
}

template< typename T, typename Y >
T& traits( int i, Y& list, T* /*result_type*/ )
{
  return *list[i];
}

template< typename T, typename Y >
T& traits( int i, const Y& list, T* /*result_type*/ )
{
  return *list[i];
}
}

#define DS_FOREACH( var, list ) \
  DS_DECLARE_SCOPE_ASSIGNEMENT( bool foreach_aix_fix = true ) \
    for( int foreach_i = 1, foreach_size = list.Size(); \
         foreach_i <= foreach_size; \
         ++foreach_i ) \
      DS_DECLARE_SCOPE_ASSIGNEMENT( var = details::traits( foreach_i, list, list[foreach_i] ) )

#endif /*EnoDicForeach_Sun_h*/
