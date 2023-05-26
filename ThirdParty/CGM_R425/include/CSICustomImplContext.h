//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2023
//===================================================================

#ifndef CSICustomImplContext_H
#define CSICustomImplContext_H

#include "CSICommandBinderModule.h"
#include "DSUnicodeString.h"

namespace JSON
{
  class JIStream;
}

namespace CSI
{
  class Parameters;

  class ExportedByCSIBinderModule CustomImplContext
  {
  public:
    CustomImplContext(const CATUnicodeString& poolName, const CATUnicodeString& functionName, int functionVersion, const Parameters& settings);
    ~CustomImplContext() = default;

    CustomImplContext(const CustomImplContext&) = delete;
    CustomImplContext& operator=(const CustomImplContext&) = delete;

    inline CATUnicodeString GetPoolName() const { return poolName_; };
    inline CATUnicodeString GetFunctionName() const { return functionName_; };
    inline int GetFunctionVersion() const { return functionVersion_; };
    inline const Parameters& GetSettings() const { return settings_; };

    /** Resolve a relative path to this CustomImpl's pool name.
     * Runtime pathes concatenation is taken into account for resolution.
     *
     * \param iRelativePath the relative path to this CustomImpl's pool name.
     * \param oResolvedPath the first resolved absolute path that exist in runtime concatenation or empty string.
     * \return S_OK when oResolvedPath is not empty, E_FAIL otherwise.
     */
    HRESULT ResolvePath(const CATUnicodeString& iRelativePath, CATUnicodeString& oResolvedPath) const;

    /** Builds a Parameters of a given type from a JSON that respect the given type definition.
     * 
     * \param iTypeName the desired Parameters type name.
     * \param iJSON the JSON to build the Parameters from.
     * \param oParameters the output Parameters.
     * \return S_OK on success, E_FAIL otherwise.
     */
    HRESULT BuildParametersFromJSON(const CATUnicodeString& iTypeName, const JSON::JIStream& iJSON, Parameters& oParameters) const;

  private:
    CATUnicodeString poolName_;
    CATUnicodeString functionName_;
    const Parameters& settings_;
    int functionVersion_;
  };
} // namespace CSI
#endif /*CSICustomImplContext_H*/
