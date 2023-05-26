#ifndef __CATOmxConcatenationWalker_h__
#define __CATOmxConcatenationWalker_h__
#include "CATOmxPortability.h"
#include "CATOmxUTF8String.h"
struct CATOmxConcatenationWalkerContext;
#define OMX_FILTER_NOTHING   0x0
#define OMX_FILTER_DUPLICATE 0x1
#define OMX_FILTER_DOTDOTDIR 0x2
#define OMX_FILTER_DOTDIR    0x4

/**
 * The following code will glob all files finishing by .fact contained in the CATInstallPath concatenation inside the "code/dictionary" folder
 * <pre>
 * CATOmxConcatenationWalker wk;
 * wk.AddConcatenationPath("CATInstallPath");
 * wk.SetRelativePath("code/dictionary");
 * wk.IncludePatternRegex("[.]fact$");
 * while( wk.Next() ) {
 *    CATOmxUTF8String fullname = wk.CurrentPath();
 * }
 * </pre>
 * The following code will glob all files finishing by .feat or .CATfct contained in the CATFeatureCatalogPath and CATGraphicPath
 * <pre>
 * CATOmxConcatenationWalker wk;
 * wk.AddConcatenationPath("CATFeatureCatalogPath");
 * wk.AddConcatenationPath("CATGraphicPath");
 * wk.IncludePatternRegex("[.](feat|CATfct)$");
 * while( wk.Next() ) {
 *    CATOmxUTF8String fullname = wk.CurrentPath();
 * }
 * </pre>
 */
class ExportedByCATOmxKernel CATOmxConcatenationWalker {
  CATOmxConcatenationWalkerContext &context;
  CATOmxConcatenationWalker(const CATOmxConcatenationWalker &);
  CATOmxConcatenationWalker &operator=(const CATOmxConcatenationWalker &);
public:
  /** */
  CATOmxConcatenationWalker(unsigned int iFilterMask=OMX_FILTER_DUPLICATE);
  /** use the iEnv variable as import pattern. */
  HRESULT AddConcatenationPath(const char *iEnv);
  /** append iPath iterator as concatenation path */
  HRESULT AddConcatenationPath(CATOmxIter<const CATOmxUTF8String> &iPath);
  /** set a relative path */
  HRESULT SetRelativePath(const char *iRelativePath);
  /** filter according to regular expression.
   * @see CATOmxRegex */
  HRESULT IncludePatternRegex(const char *iPattern);
  ~CATOmxConcatenationWalker();
  /** Return true if a path is avalaible */
  CATBoolean Next();
  CATOmxUTF8String CurrentPath();
};
#endif

