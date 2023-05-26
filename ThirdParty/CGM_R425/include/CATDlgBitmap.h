#ifndef CATDlgBitmap_H
#define CATDlgBitmap_H

#include "DI0PANV2.h"

#include "CATUnicodeString.h"
#include "CATBoolean.h"

/**
 * This class provides some tools for bitmap management
 */
class ExportedByDI0PANV2 CATDlgBitmap
{
public:
  /**
   * Get the full path of a bitmap from its name
   * @param iBitmapName the bitmap name (without any extension)
   * @param iWantSmall set to TRUE to look for the small icon
   * @return the full path of the bitmap, or an empty string when the bitmap is not found
   */
  static CATUnicodeString GetPath(const CATUnicodeString& iBitmapName, CATBoolean iWantSmall = FALSE);
};

#endif
