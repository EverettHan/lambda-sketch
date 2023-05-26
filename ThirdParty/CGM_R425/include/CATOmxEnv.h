#ifndef __CATOmxEnv_h__
#define __CATOmxEnv_h__

#include "CATOmxKernel.h"
class CATOmxTextStream;
class CATMetaClass;
#include "CATOmxUTF8String.h"
#include "CATUnicodeString.h"
class CATUnicodeString;
#if ! defined(OMX_SUPPORT_LEGACY_NAME)
#define odt_log_name ODT_LOG_NAME
#define ADL_ODT_TEMP ADL_ODT_TMP
#endif
/** DEPRECATED Use is_odt instead */
#define is_testing is_odt

class CATOmxEnv;
ExportedByCATOmxKernel const CATOmxEnv & omx_env();
ExportedByCATOmxKernel CATOmxEnv & omx_env_modify();

class ExportedByCATOmxKernel CATOmxEnv
{
public:
  friend ExportedByCATOmxKernel CATOmxEnv & omx_env_modify();
  class SafeEnv : public CATOmxUTF8String
  {
  public:
    inline SafeEnv() {}
    inline SafeEnv &operator =(const char *a) { CATOmxUTF8String::operator=(a); return *this; }
    inline SafeEnv &operator =(const SafeEnv &a) { CATOmxUTF8String::operator=(a); return *this; }
    inline SafeEnv(const CATOmxUTF8String &a) : CATOmxUTF8String(a) {}
    inline const char *asChar() const { return !IsNull() ? CATOmxUTF8String::asChar() : NULL; }
    inline operator const char*() const { return asChar(); }
    inline operator CATUnicodeString () const { return CATOmxUTF8String::operator CATUnicodeString(); }
  };
  // Standard environment variables.
  SafeEnv ADL_ODT_IN;
  SafeEnv ADL_ODT_OUT;
  SafeEnv ADL_ODT_TMP;
  SafeEnv ODT_LOG_NAME;
  SafeEnv path_temp;
  SafeEnv CATFeatureCatalogPath;
  SafeEnv CATGraphicPath;
  SafeEnv CATInstallPath;
  SafeEnv OSM_DIFF;
  SafeEnv MMI_LISTENER_PORT;
  unsigned int flags;
  unsigned int omx_trace : 1;
  unsigned int pcs_tools_detected : 1; /** at 1 if a pcs tool is detected.*/
  unsigned int is_odt : 1; /** at  1 if ADL_ODT_OUT or ADL_ODT_IN or ODT_LOG_NAME is set */

  // Test frameworks.
  enum TestFrameworkKind
  {
    NotATest = 0,
    Modeler = 1,  // ObjectSpecsModeler.tst, LiteralFeatures.tst or ObjectModelerCollection.tst
    Cleaner = 2,  // ObjectSpecsModelerCleaner.tst
    other = 3
  };
  TestFrameworkKind currentTestFramwork : 8;
  CATBoolean m_allowLogAbendFilter;

  inline CATBoolean IsInModelerTestFramework() const { return currentTestFramwork == Modeler; } // ObjectSpecsModeler.tst, LiteralFeatures.tst or ObjectModelerCollection.tst
  inline CATBoolean IsInCleanerTestFramework() const { return currentTestFramwork == Cleaner; } // ObjectSpecsModelerCleaner.tst
  inline CATBoolean IsCATOmxErrorFilterable() const { return m_allowLogAbendFilter; }

protected:
  /**
   * get boolean iVar.
   */
  unsigned int get_envb(const char *iVar);

public:
  const char * GetEnv(const char * iVarName);
  void sync();
  void on_ADL_ODT_IN_change();

  CATOmxTextStream &serr() const;
protected:
  CATOmxEnv();
  ~CATOmxEnv();
};


#endif
