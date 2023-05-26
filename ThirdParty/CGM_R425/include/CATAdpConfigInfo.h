/**
 * @level Protected
 * @usage U1
 */
#ifndef CATADPCONFIGINFO_H_
#define CATADPCONFIGINFO_H_

#include "CATPLMIntegrationAccess.h"
#include "CATBoolean.h"
#include "CATBinary.h"
#include "CATPLMCEStamp.h"
#include "CATPLMCEStampServices.h"

class CATOmxCollecManager;
class ExportedByCATPLMIntegrationAccess CATAdpConfigInfo
{
  CATBoolean _hasEffectivity, _hasStaticMapping;
  CATBinary _effectivityCompiledForm, _staticMappingCompiledForm;
  CATPLMCEStamp _cestamp;
public:
  inline CATAdpConfigInfo()
  :_hasEffectivity(FALSE), _hasStaticMapping(FALSE), _cestamp(CATPLMCEStampServices::CreateInvalidCEStamp())
  {
  }

  inline CATAdpConfigInfo(const CATPLMCEStamp & iCEStamp)
  :_hasEffectivity(FALSE), _hasStaticMapping(FALSE), _cestamp(iCEStamp)
  {
  }

  inline CATAdpConfigInfo(const CATPLMCEStamp & iCEStamp, const CATBinary &iCompiledForm)
  :_hasEffectivity(TRUE), _hasStaticMapping(FALSE), _effectivityCompiledForm(iCompiledForm), _cestamp(iCEStamp)
  {
  }

  inline void SetCEStamp(const CATPLMCEStamp & iCEStamp)
  {
    _cestamp = iCEStamp;
  }

  inline void UnsetEffectivity()
  {
    _hasEffectivity = FALSE;
    static const CATBinary empty;
    _effectivityCompiledForm = empty;
  }

  inline void UnsetStaticMapping()
  {
    _hasStaticMapping = FALSE;
    static const CATBinary empty;
    _staticMappingCompiledForm = empty;
  }

  inline void SetEffectivity(const CATBinary & iBinary)
  {
    _hasEffectivity = TRUE;
    _effectivityCompiledForm = iBinary;
  }

  inline void SetStaticMapping(const CATBinary & iBinary)
  {
    _hasStaticMapping = TRUE;
    _staticMappingCompiledForm = iBinary;
  }

  inline CATBoolean HasEffectivity() const
  {
    return _hasEffectivity;
  }

  inline CATBoolean HasStaticMapping() const
  {
    return _hasStaticMapping;
  }

  inline const CATBinary & EffectivityCompiledForm() const
  {
    return _effectivityCompiledForm;
  }

  inline const CATBinary & StaticMappingCompiledForm() const
  {
    return _staticMappingCompiledForm;
  }

  inline CATBoolean IsValid() const
  {
    return _cestamp.isValid();
  }

  inline const CATPLMCEStamp & CEStamp() const
  {
    return _cestamp;
  }

  inline int operator ==(const CATAdpConfigInfo & iOther) const
  {
    if( _hasEffectivity != iOther._hasEffectivity || _hasStaticMapping != iOther._hasStaticMapping )
      return 0;
    if( _hasEffectivity && _effectivityCompiledForm != iOther._effectivityCompiledForm)
      return 0;
    if( _hasStaticMapping && _staticMappingCompiledForm != iOther._staticMappingCompiledForm)
      return 0;
    return 1;
  }

  static CATOmxCollecManager& OmxManager();
};
#endif /* CATADPCONFIGINFO_H_ */
