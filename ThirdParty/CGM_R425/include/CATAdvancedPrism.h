#ifndef CATAdvancedPrism_H
#define CATAdvancedPrism_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATMathDef.h"
#include "CATPrism.h"
#include "CATMathDirection.h"
#include "AdvExtrude.h"
class CATGeoFactory;
class CATBody;
class CATMathPoint;
//
//--------------------------------------------------------------------------
//
class ExportedByAdvExtrude   CATAdvancedPrism : public CATPrism
{

protected:
  CATBoolean _ThinSolidMode;  
  CATLength _ThinSolidValue[2];


// to extrapol the profile profile 
  CATBody * SweepProf    (CATGeoFactory * iGeoFactory);
  CATBody * ProfileClose (CATBody       * iBody      );
//
//
//
public:
// Constructor of a prism from a body 
  CATAdvancedPrism(      CATGeoFactory   * iGeoFactory,
                         CATTopData      * iData,
                         CATBody         * iProfBody,
                   const CATMathDirection& iDir,
                         CATLength         iStartOffset, 
                         CATLength         iEndOffset);
//
// Destructor 
  ~CATAdvancedPrism();
//
// asks for the profile closure in ThinSolid mode  
  void       SetThinSolidMode (CATBoolean iThinSolidMode);
  CATBoolean GetThinSolidMode ();
// Absolute value of the offsets is only kept
// The first value corresponds to the offset in the direction
// NormalSupport ^ TgtWire
// the second value is the offset value in the direction -(NormalSupport^TgtWire)
  void SetOffsetValues(double iVal1, double iVal2);  // for the  mono-Wire bodies 

// overload to have the extrapolation cells 
  void GetProfileCell (ListPOfCATCell & ListNewCell, 
                       ListPOfCATCell & ListOldCell);
//
};
#endif




















