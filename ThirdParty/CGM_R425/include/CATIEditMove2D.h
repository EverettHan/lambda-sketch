#ifndef CATIEditMove2D_h
#define CATIEditMove2D_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

class CATCommand;
class CATPathElement;
class CATMathTransformation2D;

extern ExportedByCATAfrSelection IID IID_CATIEditMove2D;

class ExportedByCATAfrSelection CATIEditMove2D: public CATBaseUnknown
{
  CATDeclareInterface;
  
public :

  virtual CATCommand * Translate(CATPathElement *iPath) = 0;
  virtual CATCommand * Rotate(CATPathElement *iPath) = 0;

  // The 2 following are obsolete, please do not use them.
  virtual CATCommand * Translate() = 0;
  virtual CATCommand * Rotate() = 0;

  virtual void BeginMove(CATMathTransformation2D & tra) = 0;
  virtual void Move(CATMathTransformation2D & tra) = 0;
  virtual void EndMove(CATMathTransformation2D & tra) = 0;

   
private:
};

CATDeclareHandler(CATIEditMove2D, CATInterfaceObject);

#endif
