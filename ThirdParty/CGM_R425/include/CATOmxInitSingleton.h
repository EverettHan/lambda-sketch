#ifndef __CATOmxInitSingleton_H
#define __CATOmxInitSingleton_H

#if !defined(CATIAR425) && !defined(CATIAV5R33)
/** obsolete c++11 */
template<typename Type>
inline Type* CATOmxInitSingleton(Type*& s_singleton, Type* singleton) { return s_singleton = singleton; }
#endif

/**
 * obsolete c++11, replace by produced code
 */
#define OMX_IMPLEMENT_SINGLETON(Type) \
  static Type* s_singleton = new Type();\
  return *s_singleton;\

#endif
