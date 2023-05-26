// ============================================================================
//
// CATWBParserMessenger
//
//Notice the following convention is chosen for the error code :
// Error Code Convention :
// -1 "Unknown error"
// 1 "syntax error, unexpected end of input" (blocking error i.e. the associated equation is not generated)
// 2 "syntax error, unexpected identifier" (blocking error)
// 3 "syntax error, unexpected integer" (blocking error)
// 4 "syntax error, unexpected real" (blocking error)
// 5 "syntax error, unexpected bracket" (blocking error)
// 6 "syntax error, unexpected integer, expecting bracket" (blocking error)
// 7 "syntax error, unexpected semi-colon" 
// [...]
// 21 "semantic error, unknown variable name" (blocking error)
// 22 "semantic error, unknown unit" (blocking error)
// 23 "semantic error, inconsistent unit" (blocking error)
// 24 "semantic error, invalid operation with unit"
// 25 "semantic error, ambiguous Pi" (blocking error)
// [...]
// 100 "internal error, unit computation not available"

// ============================================================================
// 25 Oct 2011    Creation                       KJD
// ============================================================================
#ifndef CATWBParserMessenger_H
#define CATWBParserMessenger_H


#include "WhiteBoxParser.h"
#include "CATCDSString.h"
#include "CATCDSListP.h"
#include "CATWBLocation.h"
#include "CATCDSErrorDef.h"
#include "CATCDSIntArray.h"

class CATWBLocation;
//


class ExportedByWhiteBoxParser CATWBParserMessenger
{
 //name Constructor and destructor
public:
  CATWBParserMessenger();
  virtual ~CATWBParserMessenger();

public:

  HRESULT GetError(int iIndex, int & oErrorCode, CATWBLocation & oLocation);
  HRESULT GetErrors(CATCDSIntArray & oListErrorCodes, CATCDSLISTP(CATWBLocation) & oListOfErrorLocations);
  int GetErrorNumber() const;
  HRESULT ReportError(const CATWBLocation *location, const CATCDSString &message);
  CATCDSString GetString();

protected:
  CATCDSString _string;
  CATCDSLISTP(CATWBLocation) _ListOfErrorLocations; 
  CATCDSIntArray _ListOfErrorCodes; 
  int _ErrorNumber;
};

#endif // !CATWBParserMessenger_H
