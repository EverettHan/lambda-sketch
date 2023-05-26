#ifndef CATDlgClipboard_H
#define CATDlgClipboard_H

#include "DI0PANV2.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

/**
 * This class provides some clipboard services
 */
class ExportedByDI0PANV2 CATDlgClipboard
{
public:
  /**
   * Get list of formats available in clipboard
   * @param oList the list of available formats
   * @return S_OK on success
   */
  static HRESULT GetAvailableFormats(CATListOfCATUnicodeString& oList);

  /**
   * Put data to clipboard
   * @param iData the data to copy
   * @param iSize the size of the data to copy
   * @param iFormat the clipboard format
   * @return S_OK on success
   */
  static HRESULT PutDataToClipboard(unsigned char * iData, unsigned int iSize, const CATUnicodeString& iFormat);

  /**
   * Get data from clipboard
   * @param oData the extracted data (to be destroyed by the caller with delete [])
   * @param oSize the size of extracted data
   * @param iFormat the clipboard format
   * @return S_OK on success
   */
  static HRESULT GetDataFromClipboard(unsigned char *& oData, unsigned int & oSize, const CATUnicodeString& iFormat);

  /**
   * Put string to clipboard
   * @param iContent the string to copy
   * @param iFormat the clipboard format (optional, keep it empty to use default "string" format compliant with OS)
   * @return S_OK on success
   */
  static HRESULT PutStringToClipboard(const CATUnicodeString& iContent, const CATUnicodeString& iFormat = "");

  /**
   * Get string from clipboard
   * @param oContent the extracted string
   * @param iFormat the clipboard format (optional, keep it empty to use default "string" format compliant with OS)
   * @return S_OK on success
   */
  static HRESULT GetStringFromClipboard(CATUnicodeString& oContent, const CATUnicodeString& iFormat = "");

  /**
   * Clear the clipboard
   * @return S_OK on success
   */
  static HRESULT ClearClipboard();
};

#endif
