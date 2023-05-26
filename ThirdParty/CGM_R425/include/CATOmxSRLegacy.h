#ifndef CATIAR425
#ifdef SWXAsMateMcxServices_H
#define SWXAsMateModeler 1226
#if _MK_MODNAME_ == 1226
#include "CATOmxDeprecated.h"
#include "CATBaseUnknown_var.h"
class CATIMCXBase_var;
class CATIMCXBase;
OMX_DEPRECATED("add .Get() on right operand") inline int operator==(const CATIMCXBase_var& iLeft, const CATOmxSR<CATIMCXBase>& iRight)
{
  const CATBaseUnknown_var& left = reinterpret_cast<const CATBaseUnknown_var&>(iLeft);
  CATBaseUnknown* right = reinterpret_cast<CATBaseUnknown*>(iRight.Get());
  return left.operator==(right);
}
#endif
#undef SWXAsMateModeler
#endif
#endif
