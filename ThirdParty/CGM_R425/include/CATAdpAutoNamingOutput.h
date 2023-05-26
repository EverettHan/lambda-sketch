/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpAutoNamingOutput_H
#define CATAdpAutoNamingOutput_H

class CATPLMAutoNamingOutput;

#include "CATCollec.h"
#include "IUnknown.h"

#include "CATPLMIntegrationAccess.h"

class CATUnicodeString;
class CATAdpAutoNamingInput;

/**
* Class to use as Output of CATAdpProtectedAutoNamingServices.
*/
class ExportedByCATPLMIntegrationAccess CATAdpAutoNamingOutput 
{
  friend class CATAdpProtectedAutoNamingServices;
public:
  CATAdpAutoNamingOutput ();
  ~CATAdpAutoNamingOutput ();

  /**
  * List of replacement mode that should be used.
  //*/
  enum NamingMode 
    {
      /** The string should be placed after. */
      Suffix = 1,
      /** The string should be placed before. */
      Prefix = 2,
      /** The string should be used as is. */
      Replace = 3
    };
  /**
  * Method to retreive an Naming string based on an input.
  * 
  */
  HRESULT GetOutput (const CATAdpAutoNamingInput &iInput, 
                     NamingMode *oMode,
                     CATUnicodeString &oNamingString);

  /**
  * @nodoc 
  * Copy constructor for CATLISTV.
  */
  CATAdpAutoNamingOutput (const CATAdpAutoNamingOutput  &iOuput);

private:
  CATPLMAutoNamingOutput *_pPLMOutput;
};

#endif
