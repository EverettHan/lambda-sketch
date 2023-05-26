#ifndef CATSYPDeferredJSResult_H
#define CATSYPDeferredJSResult_H

#include <DSYString.h>
#include <UIVCoreTools.h>

// Disable C4355 warning in ppltaskscheduler.h:
// 'this': used in base member initializer list
#pragma warning(push)
#pragma warning(disable : 4355)
#include <future>
#pragma warning(pop)

struct CATSYPJSValue
{
  // Objects and arrays are not supported for now. Only primitive values.
  enum class Type
  {
    Undefined,
    Null,
    NaN,
    Boolean,
    Number,
    String
  };

  Type type = Type::Undefined;

  // Non-default only if `type` is `Boolean`.
  bool booleanValue = false;
  // Non-default only if `type` is `Number`.
  // `std::isnan` should return true if `type` is `NaN`.
  double numberValue = 0.;
  // Non-default only if `type` is `String`.
  CATUnicodeString stringValue;
};

struct CATSYPJSError
{
  // Message of the error, equivalent to `Error.message` in JS.
  CATUnicodeString message;
  // Source code line that triggered the error.
  CATUnicodeString sourceCode;
  // URL for the script that triggered the error, only defined if it comes from a separate script
  // and not from the snippet that was evaluated.
  CATUnicodeString url;
  // Line number for the error, index starting at 1.
  int line = 1;
  // Column number for the error, index starting at 0.
  int column = 0;
};

/**
 * Result of the asynchronous execution of a JavaScript code snippet.
 * This class is not CopyAssignable: use std::move when reassigning a value of this type.
 */
class ExportedByUIVCoreTools CATSYPDeferredJSResult
{
public:
  CATSYPDeferredJSResult(
    std::future<bool>&&, std::future<CATSYPJSValue>&&, std::future<CATSYPJSError>&&);
  CATSYPDeferredJSResult() = default;
  ~CATSYPDeferredJSResult() = default;

  CATSYPDeferredJSResult(CATSYPDeferredJSResult&&) = default;

  CATSYPDeferredJSResult(const CATSYPDeferredJSResult&) = delete;
  CATSYPDeferredJSResult& operator=(const CATSYPDeferredJSResult&) = delete;

  // Returns `true` if the evaluation succeeded and a result is available.
  bool HasValue();
  // Returns `true` if the evaluation failed and an error is available.
  bool HasError();

  // Returns the result of the evaluation if it ended with a success.
  // If the evaluation is pending, returns a default-constructed `JSValue`.
  CATSYPJSValue GetValue();
  // Returns the error details for the evaluation if it ended with an exception.
  // If the evaluation is pending, returns a default-constructed `JSError`.
  CATSYPJSError GetError();

  // Wait until a result or error is available or until the provided max time has been reached.
  void WaitForResult(const int i_msMaxTime);

private:
  enum class InternalStatus
  {
    ST_UNDEFINED = 0,
    ST_SUCCESS,
    ST_ERROR
  };

  InternalStatus _status = InternalStatus::ST_UNDEFINED;

  std::future<bool> _futureStatus;
  std::future<CATSYPJSValue> _futureValue;
  std::future<CATSYPJSError> _futureError;
};

#endif // CATSYPDeferredJSResult_H
