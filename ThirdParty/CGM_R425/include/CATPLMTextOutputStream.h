// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATPLMTextOutputStream.h
// Header definition of CATPLMTextOutputStream
//
//===================================================================
//
// Usage notes:
//
//===================================================================

/**
* @level Protected
* @usage U1
*/

#ifndef CATPLMTextOutputStream_H
#define CATPLMTextOutputStream_H

#include "CATPLMServicesItf.h"
#include "IUnknown.h" // for HRESULT
class CATUnicodeString;

//-----------------------------------------------------------------------

/**
* UnicodeString output stream abstract class.
* <b>Role:</b>This class is used by the replication engine to provide access to exported data.
*/
class ExportedByCATPLMServicesItf CATPLMTextOutputStream
{
public:

  // Standard constructors and destructors
  // -------------------------------------
  CATPLMTextOutputStream ();
  virtual ~CATPLMTextOutputStream ();

  /**
   *	Write text to the output stream.
   *  @param iText
   *    the text to be written
   *  @returns
   *    S_OK/E_FAIL
   */
  virtual HRESULT WriteText( const CATUnicodeString &iText ) = 0;

  /**
   *	Close the output stream.
   *  @returns
   *    S_OK/E_FAIL
   */
  virtual HRESULT Close() = 0;

private:
  
  CATPLMTextOutputStream (const CATPLMTextOutputStream &ICOPY); // not implemented
  
};

//-----------------------------------------------------------------------

#endif
