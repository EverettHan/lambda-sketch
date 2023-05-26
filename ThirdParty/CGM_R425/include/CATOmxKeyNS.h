#ifndef __CATOmxKeyNS_h__
#define __CATOmxKeyNS_h__
#include "CATOmxKernel.h"
#include "CATOmxMutex.h"
#include "CATOmxBigSet.h"
class CATOmxKSCommon;
class CATOmxKSTemporary;
/** Set to insure that map is not a tuple. */
#define CATOMX_NS_MIN_SIZE 13
/**
 * @private
 * This class help to create KeyString namespace. 
 * Or to create a subset 
 * of namespace for performance purpose.
 *
 * Example 1: create a separate namespace
 * <pre>
 *   CATOmxKeyNS foo;
 *   CATOmxKeyString aa("aa");
 *   CATOmxKeyString foo_aa(foo,"aa");
 *   CATAssert(aa != foo_aa);
 * </pre>
 * Example 2: create a sub namespace from the root namespace
 * <pre>
 *   CATOmxKeyNS foo(CATOmxKeyNS::Global());
 *   CATOmxKeyString aa("aa");
 *   CATOmxKeyString foo_aa(foo,"aa");
 *   CATAssert(aa == foo_aa);
 * </pre>  
 * This pattern may increase performance by improving lookup if the KeyString pattern is run thousand of times.
 *   CATOmxKeyString foo_aa(foo,"aa");
 * 
 */
class ExportedByCATOmxKernel CATOmxKeyNS {
  typedef  CATOmx::shared_mutex MutexType;
  CATOmxKeyNS *m_super;
  CATOmxBigSet<CATOmxKSCommon,sharable_manager> m_str_to_ks; // str to ks
  MutexType m_mutex;
  friend class CATOmxKeyString;
  const char *PutS(const CATOmxKSTemporary &iStr);
  CATOmxKSCommon *Exists(const CATOmxKSTemporary &iStr) const;
public:
  inline CATOmxKeyNS() : m_super(0), m_str_to_ks(CATOMX_NS_MIN_SIZE) {}
  /** Create a subset of an existing namespace */
  inline CATOmxKeyNS(CATOmxKeyNS &iSub) : m_super(&iSub), m_str_to_ks(CATOMX_NS_MIN_SIZE) {}
  /** Return the Global namespace used for any const char *API */
  static CATOmxKeyNS &Global();
  /** Insert iStr in namespace  */
  const CATOmxKSCommon & Put(const CATOmxKSTemporary &iStr);
  /** return True if iStr1 == iStr2.  */
  int Test(const CATOmxKSCommon &iStr1, const CATOmxKSCommon &iStr2) const;
  /** return the letter if iStr exists. */
  CATOmxKSCommon *Exists(const CATOmxKSCommon &iStr) const;
  CATOmxKSCommon *Exists(const char *iStr) const;
};
#endif
