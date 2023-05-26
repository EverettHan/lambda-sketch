#ifndef CATDlgTooltip_H
#define CATDlgTooltip_H

#include "DI0PANV2.h"

#include "CATDialog.h"
#include "CATUnicodeString.h"

/**
 * This class lets manipulate tooltip
 */
class ExportedByDI0PANV2 CATDlgTooltip
{
public:
  /**
   * Show a tooltip
   * @param iParent the parent Dialog object
   * @param iText the text to be displayed
   * @return an identifier to be given back to the Hide method
   */
  static int Show(CATDialog * iParent, const CATUnicodeString& iText);

  /**
   * Hide a tooltip
   * @param iTooltipId the identifier returned by the Show method
   */
  static void Hide(int iTooltipId);
};

#endif
