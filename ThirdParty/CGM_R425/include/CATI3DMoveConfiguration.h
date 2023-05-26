#ifndef CATI3DMoveConfiguration_h
#define CATI3DMoveConfiguration_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

class CATMathAxis;
class CATMathPoint;

extern ExportedByCATAfrSelection IID IID_CATI3DMoveConfiguration;

class ExportedByCATAfrSelection CATI3DMoveConfiguration : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  // Interface pour initialiser le CAT3DMoveAgent
  
  // Seule méthode utilisée : permet de donner l'axe associé à l'objet, 
  // sur lequel le CATSelectMoveAgent viendra plaquer la boussole si besoin est.
  virtual HRESULT SetObjectAxis(const CATMathAxis * Axis) = 0;

  //obsolète
  virtual HRESULT SetObjectBounds(const CATMathPoint * Point1, 
                                  const CATMathPoint * Point2) = 0;

  //obsolète
  virtual HRESULT SetManipulationStyle(const unsigned Style) = 0;
};

CATDeclareHandler(CATI3DMoveConfiguration, CATBaseUnknown);

#endif
