/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpAutoNamingInput_H
#define CATAdpAutoNamingInput_H

#include "CATPLMIntegrationAccess.h"

class CATAdpAutoNamingInput;
class CATPLMAutoNamingInput;
// List management
#include "CATLISTV_Clean.h"
/** @nodoc INTERNAL */
#define CATLISTV_Append
#include "CATLISTV_Declare.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIntegrationAccess
CATLISTV_DECLARE( CATAdpAutoNamingInput )


#include "CATUnicodeString.h"
class CATIAdpType;

/**
* Class to use as input of CATAdpProtectedAutoNamingServices.
*/
class ExportedByCATPLMIntegrationAccess CATAdpAutoNamingInput
{
  friend class CATAdpProtectedAutoNamingServices;
  friend class CATAdpAutoNamingOutput;
  public:
  CATAdpAutoNamingInput (const CATIAdpType *iType, 
                         const CATUnicodeString &iDiscipline, 
                         const CATUnicodeString &iUsage, 
                         const CATUnicodeString &iUserString);
  virtual ~CATAdpAutoNamingInput ();

  virtual void SetReservationNumber (unsigned int iNb);

  virtual HRESULT GetInfo (CATIAdpType **oType, CATUnicodeString &oDiscipline, CATUnicodeString &oUsage, CATUnicodeString &oUserString);

  virtual int operator != (const CATAdpAutoNamingInput &iInput) const; 

  CATAdpAutoNamingInput (const CATAdpAutoNamingInput &iInput); 
  CATAdpAutoNamingInput &operator = (CATAdpAutoNamingInput &iInput); 

private:
  CATPLMAutoNamingInput *_pPLMInput;
};

#endif
