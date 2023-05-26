//===================================================================
// COPYRIGHT Dassault Systemes 2016-08-17
//===================================================================
// 2016-08-17 Creation: D6K
//===================================================================

#ifndef CATVidDownloadProgressEventArgs_H
#define CATVidDownloadProgressEventArgs_H

// VisuImmersiveDialog
#include <VisuDialog.h>
// UIVCoreTools
#include <CATSYPEventArgs.h>
// std
#include <stdint.h>

class CATSYPEvent;
class CATVidCtlWebViewer;

/**
 * Dispatching arguments for progress updates on one download item.
 * Call @ref #Consume to mark the event as handled and to override the default dehavior.
 */
class ExportedByVisuDialog CATVidDownloadProgressEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  CATVidDownloadProgressEventArgs(CATSYPEvent*,
                                  CATVidCtlWebViewer*,
                                  const uint32_t,
                                  const int64_t,
                                  const int64_t,
                                  const int64_t,
                                  const bool);
  ~CATVidDownloadProgressEventArgs();

  /**
   * Cancels the current download.
   */
  void Cancel();
  /**
   * Returns a unique id for the download item.
   */
  uint32_t GetDownloadItemId() const;
  /**
   * Returns the amount of data already received for the download item.
   * This value can be negative if the amount of received data is unknown.
   */
  int64_t GetReceivedBytes() const;
  /**
   * Returns the total size of the download item, in bytes.
   * This value can be negative if the size of the download item is unknown.
   */
  int64_t GetTotalBytes() const;
  /**
   * Returns an estimation of the current download speed, in bytes per second.
   */
  int64_t GetCurrentSpeed() const;
  /**
   * Returns true if the download has been completed.
   */
  bool IsComplete() const;

private:
  CATVidDownloadProgressEventArgs();
  CATVidDownloadProgressEventArgs(const CATVidDownloadProgressEventArgs&);
  CATVidDownloadProgressEventArgs& operator=(const CATVidDownloadProgressEventArgs&);

  CATVidCtlWebViewer* _pWebViewer;
  const uint32_t      _downloadItemId;
  const int64_t       _receivedBytes;
  const int64_t       _totalBytes;
  const int64_t       _currentSpeed;
  const bool          _complete;
};

#endif // CATVidDownloadProgressEventArgs_H
