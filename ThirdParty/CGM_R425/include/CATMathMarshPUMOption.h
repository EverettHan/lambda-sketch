
#ifndef CATMathMarshPUMOption_h
#define CATMathMarshPUMOption_h
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2019
//

#include "MathAdvMarsh.h"

    
class ExportedByMathAdvMarsh CATMathMarshPUMOption
{
public:
  CATMathMarshPUMOption();

  ~CATMathMarshPUMOption();

  int nbPointsByBox() const { return _nbPPCByBox; }
  void SetNbPointsByBox(const int inbPPCByBox) { _nbPPCByBox = inbPPCByBox; }

  short geomChosen() const {
    return _geomChosen;
  }

  double Covering() const { return _Covering; }
  int SetCovering(const double iCovering); 

  bool HasMaxElemComputation() const { return _cao; }
  void SetMaxElemComputation(const bool iHasMaxElem)  { _cao = iHasMaxElem; }

  bool HasComplementSpace() const {
    return _HasComplementSpace;
  }
  void SetComplementSpace(const bool iHasComplementSpace) {
    _HasComplementSpace = iHasComplementSpace;
  }

private :

  double _Covering;  //default = 0.3 const 
  int _nbPPCByBox; //default = 100.,
  bool _cao; //default  = false;
  short _geomChosen; //default = 1
  bool  _HasComplementSpace; //default = true;

  
};
#endif
