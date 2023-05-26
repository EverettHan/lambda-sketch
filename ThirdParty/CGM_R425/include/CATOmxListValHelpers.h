#ifndef CATOmxListValHelpers_H
#define CATOmxListValHelpers_H

#include "CATLISTV_CATBaseUnknown.h"

#ifndef OMXLVCBUHASRANGEFOR
#define OMXLVCBUHASRANGEFOR

/** range for integration for CATListValCATBaseUnknown_var */
inline CATBaseUnknown_var* begin(CATListValCATBaseUnknown_var& list)
{
  int size = list.Size();
  return size ? &list[1] : NULL;
}

/** range for integration for CATListValCATBaseUnknown_var */
inline CATBaseUnknown_var* end(CATListValCATBaseUnknown_var& list)
{
  int size = list.Size();
  return size ? ((&list[1]) + size) : NULL;
}

/** range for integration for CATListValCATBaseUnknown_var */
inline const CATBaseUnknown_var* begin(const CATListValCATBaseUnknown_var& list) { return begin(const_cast<CATListValCATBaseUnknown_var&>(list)); }

/** range for integration for CATListValCATBaseUnknown_var */
inline const CATBaseUnknown_var* end(const CATListValCATBaseUnknown_var& list) { return end(const_cast<CATListValCATBaseUnknown_var&>(list)); }

#endif

#endif
