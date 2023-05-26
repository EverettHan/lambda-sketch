// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATPLMTextInputStream.h
// Header definition of CATPLMTextInputStream
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

#ifndef CATPLMTextInputStream_H
#define CATPLMTextInputStream_H

#include "CATPLMServicesItf.h"
#include "IUnknown.h" // for HRESULT
class CATUnicodeString;

//-----------------------------------------------------------------------

/**
* UnicodeString input stream abstract class.
* <b>Role:</b>This class is used by the replication engine to provide access to imported data.
*/
class ExportedByCATPLMServicesItf CATPLMTextInputStream
{
public:

  // Standard constructors and destructors
  // -------------------------------------
  CATPLMTextInputStream ();
  virtual ~CATPLMTextInputStream ();

  /**
   *	Reads N chars.
   *  @param iNbChars 
   *    the number of chars to be read
   *  @param oText
   *    read data
   *  @returns
   *    S_OK/E_FAIL
   */
  virtual HRESULT ReadText( int iNbChars, CATUnicodeString &oText ) const = 0;

  /**
   *	Get number of available chars.
   *  @param iNbChars 
   *    the number of chars that can be read
   *  @returns
   *    S_OK/E_FAIL
   */
  virtual HRESULT Available( int &oNbChars ) const = 0;

private:
  
  CATPLMTextInputStream (const CATPLMTextInputStream &ICOPY); // not implemented
 
};

//-----------------------------------------------------------------------

#endif
