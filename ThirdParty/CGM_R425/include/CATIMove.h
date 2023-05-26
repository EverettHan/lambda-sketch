#ifndef CATIMove_h
#define CATIMove_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "UIModelInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATMathTransformation.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIMove;
#else
extern "C" const IID IID_CATIMove ;
#endif


class ExportedByUIModelInterfaces CATIMove: public CATBaseUnknown
{
  CATDeclareInterface;
  
public :
  virtual void Move(const CATMathTransformation & tra) = 0;
  virtual CATLISTV(CATBaseUnknown_var) GetMovable() const = 0;
     
private:
};

CATDeclareHandler(CATIMove, CATInterfaceObject);

#endif
