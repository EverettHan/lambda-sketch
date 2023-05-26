// COPYRIGHT DASSAULT SYSTEMES 2010
//=============================================================================
//
// CATCDSModifications:
//   class to maintain modifications variables for the versioning process
//
//=============================================================================
//
// Usage notes:
//    macro are defined USING_MODIFICATION() & IS_MODIFICATION_ACTIVE()
//    to use inside CATCDSOperator
//
//=============================================================================
//  Sep 2010  Creation                         Nikolay Snytnikovint
//=============================================================================

#ifndef CATCDSModifications_H
#define CATCDSModifications_H

#include "CATCDSModifications_inc.h"
#include "CATCDSBoolean.h"
#include "CATCDSGlobalParameters.h"
#include "CATCDSVersMacros.h"
#include <stdarg.h>

#if !defined(_EMSCRIPTEN_SOURCE)

#define VA_LAST_ARG 0xFFFF

// internal CDS use only (using GetCDSLevel() to get internal level)
// *********************
#define USING_MODIFICATION(name)
#define IS_MODIFICATION_ACTIVE_SIMPLE(name, internalLevel)                (name <= (unsigned int)internalLevel) // replace the previous IS_MODIFICATION_ACTIVE
#define IS_HF_MODIFICATION_ACTIVE_SIMPLE(name, internalLevel)             ((name <= (unsigned int)internalLevel) && (CDS_EXTERNAL_LEVEL(internalLevel) == CDS_EXTERNAL_LEVEL(name))) // replace the previous IS_HF_MODIFICATION_ACTIVE
#define IS_MODIFICATION_ACTIVE3(internalLevel, ...)                       IsModificationActive(internalLevel, __VA_ARGS__, VA_LAST_ARG) // multi arguments
#define IS_MODIFICATION_ACTIVE(...)                                       IS_MODIFICATION_ACTIVE3(GetCDSLevel(), __VA_ARGS__) // multi arguments
#define IS_SPECIAL_MODIFICATION_ACTIVE3(name, nextLevel, internalLevel)   ((name <= (unsigned int)internalLevel) && ((unsigned int)internalLevel < CDS_INTERNAL_LEVEL(nextLevel,0))) // for compatibility
#define IS_SPECIAL_MODIFICATION_ACTIVE(name, nextLevel)                   IS_SPECIAL_MODIFICATION_ACTIVE3(name, nextLevel, GetCDSLevel()) // for compatibility

static CATCDSBoolean IsModificationActive(unsigned int iCDSInternalLevel, ...)
{
  CATCDSBoolean Active = FALSE;
  va_list args;
  va_start(args, iCDSInternalLevel);
  unsigned int cnt = 0;
  for (;;)
  {
    unsigned int level = va_arg(args, unsigned int);
    if (level == VA_LAST_ARG)
      break;
    if ((cnt==0 && IS_MODIFICATION_ACTIVE_SIMPLE(level, iCDSInternalLevel)) || IS_HF_MODIFICATION_ACTIVE_SIMPLE(level, iCDSInternalLevel))
    {
      Active = TRUE;
      break;
    }
    cnt++;
  }
  va_end(args);
  return Active;
};

#else

#define USING_MODIFICATION(name)
#define IS_MODIFICATION_ACTIVE3(level, ...)                              IsModificationActive(__VA_ARGS__)
#define IS_MODIFICATION_ACTIVE(...)                                      IsModificationActive(__VA_ARGS__)
#define IS_SPECIAL_MODIFICATION_ACTIVE(name, nextLevel)                  0
#define IS_SPECIAL_MODIFICATION_ACTIVE3(name, nextLevel, level)          0

inline bool IsModificationActive(unsigned int level1)
{
  return (level1 != CATCDSModificationInactive);
}

inline bool IsModificationActive(unsigned int level1, unsigned int level2)
{
  return IsModificationActive(level1) || IsModificationActive(level2);
}

inline bool IsModificationActive(unsigned int level1, unsigned int level2, unsigned int level3)
{
  return IsModificationActive(level1) || IsModificationActive(level2, level3);
}

inline bool IsModificationActive(unsigned int level1, unsigned int level2, unsigned int level3, unsigned int level4)
{
  return IsModificationActive(level1) || IsModificationActive(level2, level3, level4);
}

inline bool IsModificationActive(unsigned int level1, unsigned int level2, unsigned int level3, unsigned int level4, unsigned int level5)
{
  return IsModificationActive(level1) || IsModificationActive(level2, level3, level4, level5);
}

#endif

#endif
