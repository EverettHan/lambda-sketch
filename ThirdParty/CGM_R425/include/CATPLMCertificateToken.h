// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMCertificateToken.h
// Header definition of CATPLMCertificateToken
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// November 2009  Creation: EPB
//===================================================================

/**
 * @level Protected
 * @usage U1
 */

// U1:        Concrete class: use as is only. C++ usage 
// Protected: The header doc is only generated in the PLMInf web. All frameworks authorized to use the framework containing the header can use it.

#ifndef CATPLMCertificateToken_H
#define CATPLMCertificateToken_H

#include "CATPLMServicesItf.h"

#include "CATOmxKeyString.h"
#include "CATListValCATPLMCertificateToken.h"

class CATString;

enum PLMCertificateTokenType
{
  undef = 0
 ,ifexists = 1
 ,notpresent = 2
};

class ExportedByCATPLMServicesItf CATPLMCertificateToken
{
public:

  /** 
  * Constructs a 'undef' token
  */
  CATPLMCertificateToken ();

  /** 
  * Constructs a 'ifexists' token
  */
  CATPLMCertificateToken (const CATString &iTokenKey);

  /** @nodoc */
  virtual ~CATPLMCertificateToken ();  
  /** @nodoc */
	CATPLMCertificateToken& operator=(CATPLMCertificateToken &iToken);
  /** @nodoc */
  int operator !=(const CATPLMCertificateToken& iToken ) const;
  /** @nodoc */
  int operator ==(const CATPLMCertificateToken& iToken ) const;

  /** 
  * Returns the key of the token.
  */
  void GetKey (CATString &oKey);

  /** 
  * Returns the type of the token.
  */
  PLMCertificateTokenType GetType ( );

  /** 
  * Returns the type of the token.
  */
  HRESULT SetType ( PLMCertificateTokenType iType);

  // Set/GetValue when new token types will be created

  /** 
  * Sets the comment of the token.
  */
  void SetComment (const CATString &iCommentString);

  /** 
  * Returns the comment of the token.
  */
  void GetComment (CATString &oCommentString);

  /** 
  * Checks the token rule on a list of supplied tokens.
  */
  HRESULT CheckRule (const CATListOfCATPLMCertificateToken &iSupCert);

private:
  CATOmxKeyString _Key,_Comment;
  // CATOmxAny _Value;
  PLMCertificateTokenType _Type;
};

#endif
