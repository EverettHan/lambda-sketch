//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================

#ifndef CATVidTextUtilities_H
#define CATVidTextUtilities_H

#include <CATUnicodeString.h>
#include <CATListOfCATUnicodeString.h>
#include <CATListOfInt.h>
#include <VisuDialog.h>

class CATDlgBlackBox;
class CATVidFontDescription;

/**
 * This class provides text utilities.
 */
class ExportedByVisuDialog CATVidTextUtilities
{
public:
  static HRESULT CopyTextToClipboard(const CATUnicodeString& i_text); // Unicode

  static HRESULT CopyTextToClipboard(const CATUnicodeString& i_text, const CATUnicodeString& i_format);

  static HRESULT CopyTextToClipboard(const CATListOfCATUnicodeString& i_texts, const CATListOfCATUnicodeString& i_formats);

  // To get Text from Clipboard
  static HRESULT GetTextFromClipboard(CATUnicodeString& o_text); // Unicode

  static HRESULT GetTextFromClipboard(CATUnicodeString& o_text, const CATUnicodeString& iFormat);

  static HRESULT GetTextFromClipboard(CATListOfCATUnicodeString& o_texts, const CATListOfCATUnicodeString& i_formats);

#ifdef _WINDOWS_SOURCE
  [[deprecated("CopyTextToClipboard(const CATListOfCATUnicodeString& i_texts, const CATListOfInt& i_formats) is deprecated, \
  you should migrate to CopyTextToClipboard(const CATListOfCATUnicodeString& i_texts, const CATListOfCATUnicodeString& i_formats) instead.")]]
  static HRESULT CopyTextToClipboard(const CATListOfCATUnicodeString& i_texts, const CATListOfInt& i_formats);

  // To get Text from Clipboard
  // iFormat can be CF_UNICODETEXT or CF_HTML
  [[deprecated("GetTextFromClipboard(CATUnicodeString& o_text, int iFormat) is deprecated, \
  you should migrate to GetTextFromClipboard(CATUnicodeString& o_text, const CATUnicodeString& iFormat) instead.")]]
  static HRESULT GetTextFromClipboard(CATUnicodeString& o_text, int iFormat);
#endif

#ifdef _LINUX_SOURCE
  [[deprecated("CopyTextToClipboard(CATDlgBlackBox* ipDlg, const CATUnicodeString& i_text) is deprecated, \
  you should migrate to CopyTextToClipboard(const CATUnicodeString& i_text) instead.")]]
  static HRESULT CopyTextToClipboard(CATDlgBlackBox* ipDlg, const CATUnicodeString& i_text);

  // To get Text from Clipboard
  [[deprecated("GetTextFromClipboard(CATDlgBlackBox* ipDlg, CATUnicodeString& io_text) is deprecated, \
  you should migrate to GetTextFromClipboard(CATUnicodeString& o_text) instead.")]]
  static HRESULT GetTextFromClipboard(CATDlgBlackBox* ipDlg, CATUnicodeString& io_text);
#endif

  static void GetStringSize(const CATUnicodeString& i_string, const CATVidFontDescription& i_fontDescription, float& o_width, float& o_height);
  static void GetDefaultStringSize(const CATUnicodeString& i_string, float& o_width, float& o_height);

private:
  /** Blocks the construction of a CATVidTextUtilities object */
  CATVidTextUtilities();
  ~CATVidTextUtilities();
};
#endif
