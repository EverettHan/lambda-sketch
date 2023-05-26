//===================================================================
// COPYRIGHT Dassault Systemes 2013-10-28
//===================================================================
// 2013-10-28 Creation: D6K
//===================================================================

#ifndef CATVidLoadEventArgs_H
#define CATVidLoadEventArgs_H

// VisuImmersiveDialog
#include <CATVidURL.h>
#include <VisuDialog.h>
// UIVCoreTools
#include <CATSYPArray.h>
#include <CATSYPEventArgs.h>
// System
#include <CATBinary.h>
// SystemTS
#include <DSYString.h>

/**
 * Dispatching arguments for loading events of a web browser.
 */
class ExportedByVisuDialog CATVidLoadEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;

public:
  enum EventType {
    // Regular load start or end, no error.
    LIFECYCLE = 0,
    // Problems like bad connection or invalid certificates.
    LOAD_ERROR,
    // HTTP request errors, with a status matching 4xx or 5xx.
    HTTP_ERROR,
    // Problems like bad connection, content security policies or invalid certificates.
    LOAD_RESOURCE_ERROR
  };

  static CATVidLoadEventArgs* CreateForHTTPError(
    CATSYPEvent* i_pEvent,
    const int i_status,
    const CATUnicodeString& i_statusText,
    const CATUnicodeString& i_method,
    const CATUnicodeString& i_url
  );

  static CATVidLoadEventArgs* CreateForLifecycleEvent(
    CATSYPEvent* i_pEvent,
    const bool i_isLoading,
    const CATUnicodeString& i_url
  );

  static CATVidLoadEventArgs* CreateForLoadError(
    CATSYPEvent* i_pEvent,
    const int i_errorCode,
    const CATUnicodeString& i_errorName,
    const CATUnicodeString& i_url
  );

  static CATVidLoadEventArgs* CreateForLoadResourceError(
    CATSYPEvent* i_pEvent,
    const int i_errorCode,
    const CATUnicodeString& i_errorName,
    const CATUnicodeString& i_url
  );

  /**
   * Destructor.
   */
  ~CATVidLoadEventArgs();

  /**
   * @return The event type.
   */
  EventType GetEventType() const;

  /**
   * @return A smart representation of the URL: see @c CATVidURL methods.
   */
  CATVidURL GetVidURL() const;
  /**
   * @return A string representation of the URL.
   */
  CATUnicodeString GetURL() const;
  /**
   * @return true if this was created for a load start event, or false for load end.
   */
  bool IsLoading() const;
  /**
   * @return An identifier for the error if @c GetType returns LOAD_ERROR or HTTP_ERROR.
   * For LOAD_ERROR, the value should be negative and match descriptions for @c LoadErrorCode
   * in @c CATMMWebTypes.h.
   * For HTTP_ERROR, the value should be positive and match standard HTTP response status definitions.
   */
  int GetErrorCode() const;
  /**
   * @return A string identifier for the error if @c GetType returns LOAD_ERROR or HTTP_ERROR.
   */
  const CATUnicodeString& GetErrorName() const;
  /**
   * @return The HTTP request method if @c GetType returns HTTP_ERROR, else it will be empty.
   */
  const CATUnicodeString& GetMethod() const;

  /**
   * @deprecated Only used for deprecated event @c CustomScheme (from @c CATVidCtlWebViewer)
   */
  void SetPostDataArray(const CATBinary* i_pPostDataArray, const size_t i_postDataArraySize);
  /**
   * @deprecated Only used for deprecated event @c CustomScheme (from @c CATVidCtlWebViewer)
   */
  void AddPostData(const CATBinary& i_postData);
  /**
   * @deprecated Only used for deprecated event @c CustomScheme (from @c CATVidCtlWebViewer)
   */
  CATBinary GetPostData(const unsigned int i_idx = 0) const;
  /**
   * @deprecated Only used for deprecated event @c CustomScheme (from @c CATVidCtlWebViewer)
   */
  size_t GetPostDataCount() const;

private:
  CATVidLoadEventArgs();
  CATVidLoadEventArgs(const CATVidLoadEventArgs&);
  CATVidLoadEventArgs& operator=(const CATVidLoadEventArgs&);

  /**
   * Instantiates args for a load start or load end event.
   */
  CATVidLoadEventArgs(
    CATSYPEvent* i_pEvent,
    const bool i_isLoading,
    const CATUnicodeString& i_url
  );

  /**
   * Instantiates args for an error event.
   */
  CATVidLoadEventArgs(
    CATSYPEvent* i_pEvent,
    const EventType i_type,
    const int i_errorCode,
    const CATUnicodeString& i_errorName,
    const CATUnicodeString& i_method,
    const CATUnicodeString& i_url
  );

  const EventType           _eventType;
  const bool                _isLoading;
  const int                 _errorCode;
  const CATUnicodeString    _errorName;
  const CATUnicodeString    _method;
  const CATVidURL           _url;
  CATSYPDynArray<CATBinary> _postDataArray;
};

#endif
