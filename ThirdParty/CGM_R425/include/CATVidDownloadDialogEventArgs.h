//===================================================================
// COPYRIGHT Dassault Systemes 2016-08-17
//===================================================================
// 2016-08-17 Creation: D6K
//===================================================================

#ifndef CATVidDownloadDialogEventArgs_H
#define CATVidDownloadDialogEventArgs_H

// VisuImmersiveDialog
#include <VisuDialog.h>
// SystemTS
#include <DSYString.h>
// UIVCoreTools
#include <CATSYPEventArgs.h>
// std
#include <stdint.h>

class CATSYPEvent;
class CATVidCtlWebViewer;

/**
 * Dispatching arguments for handling the dialog before a download starts.
 * Call @ref #Consume to mark the event as handled and to override the default dehavior.
 */
class ExportedByVisuDialog CATVidDownloadDialogEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  CATVidDownloadDialogEventArgs(CATSYPEvent*,
                                CATVidCtlWebViewer*,
                                const uint32_t,
                                const CATUnicodeString&,
                                const CATUnicodeString&,
                                const CATUnicodeString&,
                                const int64_t);
  ~CATVidDownloadDialogEventArgs();

  /**
   * Possible behaviors for downloads.
   */
  enum Response {
    // Save the file in a temporary location and open it with the default application.
    RE_OPEN = 0,
    // Save the file to a specific location.
    RE_SAVE_AS
  };

  /**
   * Selects a behavior and starts the download.
   * @param i_response
   *   The selected behavior.
   * @param i_path
   *   The absolute path to use for saving the file.
   *   If @c RE_OPEN is selected, @c i_path will be ignored.
   */
  void Continue(const Response i_response, const CATUnicodeString& i_path = "");
  /**
   * Cancels the download that is going to start.
   */
  void Cancel();
  /**
   * Returns a unique id for the download item.
   */
  uint32_t GetDownloadItemId() const;
  /**
   * Returns the file name for the download item.
   */
  const CATUnicodeString& GetFileName() const;
  /**
   * Returns the origin address for the download item.
   */
  const CATUnicodeString& GetOriginURL() const;
  /**
   * Returns the mime type for the download item.
   */
  const CATUnicodeString& GetMimeType() const;
  /**
   * Returns the total size of the download item, in bytes.
   * This value can be negative if the file size is unknown when the download starts.
   */
  int64_t GetTotalBytes() const;

private:
    CATVidDownloadDialogEventArgs();
    CATVidDownloadDialogEventArgs(const CATVidDownloadDialogEventArgs&);
    CATVidDownloadDialogEventArgs& operator=(CATVidDownloadDialogEventArgs&);

    CATVidCtlWebViewer*    _pWebViewer;
    const uint32_t         _downloadItemId;
    const CATUnicodeString _fileName;
    const CATUnicodeString _originURL;
    const CATUnicodeString _mimeType;
    const int64_t          _totalBytes;
};

#endif // CATVidDownloadDialogEventArgs_H
