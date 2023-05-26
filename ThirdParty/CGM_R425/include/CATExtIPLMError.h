// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATExtIPLMError.h
// Provide implementation to interface
//    CATIPLMError
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//   IMPLEMENTATION
//   TIE: CATIPLMError
//
//  Feb 2009  virtual added because it is an adapter.
//  Aug 2004  Creation: jvm
//===================================================================
#ifndef CATExtIPLMError_H
#define CATExtIPLMError_H

#include "CATPLMServicesItf.h"
#include "CATIPLMError.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

class CATString;
class CATError;
//-----------------------------------------------------------------------

/**
* @level Protected
* @usage U2
*/

/**
* Adapter for CATIPLMError
*/
class ExportedByCATPLMServicesItf CATExtIPLMError: public CATIPLMError
{
public:

  // Standard constructors and destructors for an implementation class
  // -----------------------------------------------------------------
  CATExtIPLMError ();
  CATExtIPLMError (CATPLMSeverity  iSeverity,
    const CATString * ipErrorTag,
    const CATString * ipCatalogName,
    const CATUnicodeString * ipRequest = NULL,
    const CATUnicodeString * iDiagnostic = NULL,
    const CATUnicodeString * iAdvice = NULL);

  CATExtIPLMError(CATPLMSeverity  iSeverity,
    const CATString& iErrorTag,
    const CATString& iCatalogName,
    const CATUnicodeString& iRequest = "",
    const CATUnicodeString& iDiagnostic = "",
    const CATUnicodeString& iAdvice = "");

  CATExtIPLMError (CATPLMSeverity  iSeverity,
    const CATString * ipCatalogName,
    const CATString * ipRequestTag,
    const CATString * iDiagnosticTag,
    const CATString * iAdviceTag);
  // iXMLErrMsg is a <REPORT>...</REPORT> structure
  CATExtIPLMError (const CATUnicodeString *iXMLErrMsg);
  virtual ~CATExtIPLMError ();

  virtual void SetSeverity(CATPLMSeverity iSeverity);

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetSeverity
  */
  virtual HRESULT GetSeverity (CATPLMSeverity *  oSeverity  ) ;

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetSeverity
  */
  virtual CATPLMSeverity GetSeverity() const;

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#SetErrorCode
  */
  virtual void SetErrorCode(const CATString& iErrorCode, const CATString& iCatalogName);

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetErrorCode
  */
  virtual HRESULT GetErrorCode( CATString ** oErrorCode, CATString ** oCatalogName);

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetErrorCode
  */
  virtual HRESULT GetErrorCode(CATString& oErrorCode, CATString& oCatalogName) const;

  /**
  * Get error key.
  */
  virtual CATString GetErrorKey() const;

  /**
  * Get error catalog.
  */
  virtual CATString GetCatalogName() const;

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetRequest
  */
  virtual HRESULT GetRequest (CATUnicodeString **  oMsg  ) ;

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetDiagnostic
  */
  virtual HRESULT GetDiagnostic (CATUnicodeString **  oMsg  ) ;

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetAdvice
  */
  virtual HRESULT GetAdvice (CATUnicodeString **  oMsg );

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetRequestNLSParams
  */
  virtual HRESULT GetRequestNLSParams (CATListValCATUnicodeString * oParams  ) ;

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetRequestNLSParams
  */
  virtual CATListValCATUnicodeString GetRequestNLSParams() const;

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetDiagnosticNLSParams
  */
  virtual HRESULT GetDiagnosticNLSParams (CATListValCATUnicodeString * oParams   ) ;

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetDiagnosticNLSParams
  */
  virtual CATListValCATUnicodeString GetDiagnosticNLSParams() const;

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetAdviceNLSParams
  */
  virtual HRESULT GetAdviceNLSParams (CATListValCATUnicodeString * oParams );

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetAdviceNLSParams
  */
  virtual CATListValCATUnicodeString GetAdviceNLSParams() const;

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#GetError
  */
  virtual HRESULT GetError( CATError ** oError);

  /**
  * Internal use.
  */
  virtual HRESULT SetDiagnosticNLSParams (const CATListValCATUnicodeString &iParams );

  /**
  * Internal use.
  */
  virtual HRESULT SetAdviceNLSParams (const CATListValCATUnicodeString &iParams );

  /**
  * Internal use.
  */
  virtual HRESULT SetRequestNLSParams (const CATListValCATUnicodeString &iParams );

  /**
  * Implements a function from an interface.
  * @see CATPLMServices.CATIPLMError#SetError
  */
  virtual void SetError(CATError* ipError);

  /**
  * Returns the request error message (short error message).
  * @param oMsg
  *    The short error message.
  */
  virtual CATUnicodeString GetRequest() const;

  /**
  * Returns the diagnostic error message (long error message).
  * @param oMsg
  *    The long error message.
  */
  virtual CATUnicodeString GetDiagnostic() const;

  /**
  * Returns the Advice error message.
  * @param oMsg
  *    The advice error message.
  */
  virtual CATUnicodeString GetAdvice() const;

  /**
  * Returns the CATIA error.
  * @param oError
  *    The error.
  */
  virtual CATError* GetError();

protected:
  /** Methode to release all internals. */
  void Flush ();

  /** The error severity code. */
  CATPLMSeverity  _Severity;
  /** The error code. */
  CATString * _pErrorTag;
  /** The error Catalog Name. */
  CATString * _pCatalogName;
  /** the Advice error message. */
  CATUnicodeString * _pAdvice;
  /** the diagnostic error message (long error message). */
  CATUnicodeString * _pDiagnostic;
  /** the request error message (short error message). */
  CATUnicodeString * _pRequest;
  /** the request nls params. */
  CATListValCATUnicodeString * _pRequestParams;
  /** the diagnostic nls params. */
  CATListValCATUnicodeString * _pDiagnosticParams;
  /** the Advice nls params. */
  CATListValCATUnicodeString * _pAdviceParams;

private:
  // The copy constructor and the equal operator must not be implemented
  // -------------------------------------------------------------------
  CATExtIPLMError (CATExtIPLMError &);
  CATExtIPLMError& operator=(CATExtIPLMError&);

  static CATListOfCATUnicodeString _emptyList;
  static CATUnicodeString _empty;
};

//-----------------------------------------------------------------------

#endif
