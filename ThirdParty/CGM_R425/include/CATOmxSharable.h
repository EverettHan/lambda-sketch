#ifndef __CATOmxSharable_h__
#define __CATOmxSharable_h__

/**
 * @level Protected
 * @usage U2
 */


#include "CATOmxPortability.h"
#include "CATOmxKernel.h"
#include "CATOmxCRefTS.h"

class CATMetaClass;

/**
 * The following class implements a basic IUnknown object.
 * This class is integrated with the MLK_Tracker.
 * AddRef/Release implementation is thread-safe.
 */
class ExportedByCATOmxKernel CATOmxSharable : public IUnknown
{
  friend class CATOmxSharableGuts;
  friend class CATOmxKSCommon;
  CATOmxSharable& operator=(const CATOmxSharable&);
  CATOmxCRefTS<unsigned int> m_cRef;
  unsigned int m_flags;

public:
  CATOmxSharable();
  CATOmxSharable(const CATOmxSharable&);
  OMX_EXPLICIT CATOmxSharable(unsigned int iFlags);
  OMX_EXPLICIT CATOmxSharable(CATMetaClass *iMetaclass);

  /** new/delete */
  void* operator new(size_t iSize);
  void operator delete(void *iAddr);

  /**
   * QueryInterface basic implementation
   * @param iIID default implementation accepts IID_IUnknown,IID_CATOmxMlkRefCounter and CLSID_CATMetaClass.
   */
  virtual HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV);
  /**
   * AddRef/Release implementation. Thread safe
   */
  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();

  /**
   * Check if object is Mutable.
   * This call is used to implements Omx collections Copy On Write mechanisms.
   * @return true if object is not shared
   */
  inline bool Mutable() const { return m_cRef.Get() <= 1; }

  /**
   * Hashing
   * Can be overridden by subclass
   * @return the hash code
   */
  virtual CATHashKey Hash() const;

  /**
   * Implement a ternary comparison based on address.
   * Can be overridden by subclass
   * @param other is the compared object
   * @return -1 if this < &other
   * @return 1 if this > &other
   * @return 0 if this == &other
   */
  virtual int Cmp(const CATOmxSharable& other) const;

  /*
   * Must be called when creating a CATOmxSharable on the stack
   */
  void AutomaticRelease();
protected:
  /**
   * Assert if m_cRef != 0
   */
  virtual ~CATOmxSharable();
};

#endif
