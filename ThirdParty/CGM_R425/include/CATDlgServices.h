#ifndef CATDLGSERVICES_H
#define CATDLGSERVICES_H

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "CATDlgStandard.h"
#include "CATDlgUtility.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATMsgCatalog.h"

#include "CATLib.h" // CATLibStatus

static CATULong _DlgCurrentState;
static CATBool _DlgCurrentStateInitialized = FALSE;

static CATListOfCATUnicodeString _AvailableExtensions;

static int _DlgWidthsDetails[4] = { 12, 4, 6, 8 };
static int _DlgWidthsList[2] = { 12, 6 };

class ExportedByCATDlgStandard CATDlgServices
{
public:

  static int FindLastPosition (const CATUnicodeString&, const CATUnicodeString&);
  static CATUnicodeString GetExtensionDescription(const CATUnicodeString&);

  static CATUnicodeString GetDlgCurrentDirectory();

  static CATULong GetDlgCurrentState();
  static void SetDlgCurrentState(CATULong);

  static void GetColumnWidths(int owidthsDetails[4], int owidthsList[2]);
  static void SetColumnWidths(int iwidthsDetails[4], int iwidthsList[2]);

  static CATUnicodeString GetFileExtensionName(const CATUnicodeString&);
  static CATUnicodeString GetExtensionFromFilter(const CATUnicodeString&);
  static int ComputeDefaultFilters(CATListOfCATUnicodeString&,
                                   CATListOfCATUnicodeString&,
                                   CATListOfCATUnicodeString&,
                                   int withallfiles=1);

  static CATLibStatus RemoveDirectory(const char *iDir);
};
#endif
