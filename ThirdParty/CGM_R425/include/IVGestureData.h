//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef IVGestureData_H
#define IVGestureData_H

// ----- System -----
#include "CATBaseUnknown.h"

// ----- Mathematics -----
#include "CATMathTransformation.h"


class IVGestureData : public CATBaseUnknown
{
public:

  //Constructor/Destructor
  // -----------------------------------
  IVGestureData();
  virtual ~IVGestureData();

  // Setter / Getter
  // -----------------------------------
  inline void SetPosition(const CATMathTransformation & iTransfo) { _positionTransfo = iTransfo; };
  inline CATMathTransformation Position() const { return _positionTransfo; };

  inline void SetTime(const CATLONG64 & iTime) { _timeInMS = iTime; };
  inline CATLONG64 Time() const { return _timeInMS; };

protected:

  // InnerData
  // -----------------------------------
  CATMathTransformation _positionTransfo;
  CATLONG64 _timeInMS;

private:


};

//-----------------------------------------------------------------------
#endif
