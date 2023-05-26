#ifndef CATICAfrUrlViewer_H
#define CATICAfrUrlViewer_H

// COPYRIGHT DASSAULT SYSTEMES 2012/06/20

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
// UIVCoreTools
#include <CATSYPDeferredJSResult.h>
// std
#include <functional>

extern ExportedByCATAfrItf  IID IID_CATICAfrUrlViewer ;

//-----------------------------------------------------------------------------
/**
* Interface representing The CAfrUrlViewer Component.
*/
class ExportedByCATAfrItf CATICAfrUrlViewer: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Run javascript script in web page
    * @param iScript the script to run
    */
    virtual void RunScript(const CATUnicodeString& iScript) = 0;
    
    /**
    * Executes JavaScript code on the current page and returns result or error
    * in the provided callbacks.
    * The result is the last expression of the snippet: same behavior as the `eval()` function in JS
    * or the interactive console in the DevTools of a browser.
    * @param iScript
    *   The JavaScript code to run.
    * @param i_resultCallback
    *   The callback that will be executed with the result of the provided code.
    *   Called asynchronously on the main thread.
    * @param i_errorCallback
    *   The callback that will be executed with error details if the provided code triggers an
    *   exception.
    *   Called asynchronously on the main thread.
    * @warning
    *   Results only work for primitive values for now, i.e. objects and arrays are excluded.
    */
    virtual void EvalScript(const CATUnicodeString& iScript,
      std::function<void(const CATSYPJSValue&)> i_resultCallback,
      std::function<void(const CATSYPJSError&)> i_errorCallback) = 0;
    
    /**
    * Executes JavaScript code on the current page and returns an object that allows to wait for the
    * result or an error.
    * The result is the last expression of the snippet: same behavior as the `eval()` function in JS
    * or the interactive console in the DevTools of a browser.
    * @param iScript
    *   The JavaScript code to run.
    * @warning
    *   Results only work for primitive values for now, i.e. objects and arrays are excluded.
    * @return
    *   An object that will provide a result or an error.
    */
  virtual CATSYPDeferredJSResult EvalScriptSync(const CATUnicodeString& iScript) = 0;
};
#endif
