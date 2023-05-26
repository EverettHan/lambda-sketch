#ifndef CATIUnitConverter_H
#define CATIUnitConverter_H

/* COPYRIGHT DASSAULT SYSTEMES 2002 */

#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATAfrSelection.h"

extern ExportedByCATAfrSelection IID IID_CATIUnitConverter;

class ExportedByCATAfrSelection CATIUnitConverter: public CATBaseUnknown
{
  CATDeclareInterface;
public:

  enum AfrUnitType { CatAfrLength,CatAfrAngle };

  virtual HRESULT Convert(const AfrUnitType iType,
                          const double iValue, 
                          CATUnicodeString & oResult) = 0;

};



#endif
