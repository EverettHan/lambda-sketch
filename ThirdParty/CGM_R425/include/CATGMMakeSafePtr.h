/* -*-C++-*- */
#ifndef CATGMMakeSafePtr_H
#define CATGMMakeSafePtr_H
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================

//=============================================================================
//
// RESPONSABLE  : Q. FREGER (QF2)
//
// DESCRIPTION  : Template class  for smart pointer on AddRef/Release() object.
//                Multi OS - AIX Compliant
//                            
//=============================================================================


#if __cplusplus >= 201103L
#include <utility>


template <class T> class CATGMSafePtr;

/**
 * ----------------------------------------- *
 *         - Makers -
 * ----------------------------------------- *
 * Usage:
 *  CATGMSafePtr<myClass> safePtr = CATGM::MakeSafePtr<myClass>(args...);
 * Example:
 *  CATGMSafePtr<CATSoftwareConfiguration> safeConf = CATGM::MakeSafePtr<CATSoftwareConfiguration>();
 */
namespace CATGM
{
  template< class T>
  CATGMSafePtr<T> MakeSafePtr();

  template< class U, class... Args >
  CATGMSafePtr<U> MakeSafePtr(Args&&... args);
}





/**  Implementation **/ 
namespace CATGM
{
  template< class T>
  CATGMSafePtr<T> MakeSafePtr() {

    CATGMSafePtr<T> safePtr = nullptr;
    safePtr.TakeOwnership(new T());
    return safePtr; // move
  }

  template< class U, class... Args >
  CATGMSafePtr<U> MakeSafePtr(Args&&... args) {
    
    CATGMSafePtr<U> safePtr = nullptr;
    U * ptr = new U(std::forward<Args>(args)...);
    safePtr.TakeOwnership(ptr);
    
    return safePtr; // move
  }
}

#endif // if C++11


#endif

