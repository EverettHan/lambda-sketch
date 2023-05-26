//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef IVGestureDataSet_H
#define IVGestureDataSet_H

// ----- IVInterfaces -----
#include "CATLISTP_IVGestureData.h"

// ----- System -----
#include "CATBaseUnknown.h"

class CATMathTransformation;
class IVGestureData;

class IVGestureDataSet : public CATBaseUnknown
{
public:

  //Constructor/Destructor
  // -----------------------------------
  IVGestureDataSet();
  virtual ~IVGestureDataSet();

  // Setter / Getter
  // -----------------------------------
  HRESULT Add(CATMathTransformation & iPosition, CATLONG64 &iTimeInMs);

  HRESULT RemoveAll();

  int Length() const;

  CATMathTransformation Position();
  CATMathTransformation PreviousPosition();
  CATMathTransformation BeganPosition();

  CATLONG64 Time();
  CATLONG64 PreviousTime();
  CATLONG64 BeganTime();

  IVGestureData * Data();
  IVGestureData * DataPrevious();
  IVGestureData * DataBegan();

  /**
  iNb : -1 infinite, discrete nb >=2 otherwise
  */
  HRESULT SetMaxNbOfLastInData(const int & iNb);
  inline int MaxNbOfLastInData() const { return _maxNbOfLastInData; };

protected:

  //protected
  HRESULT CleanUnnecessaryData();

  //Data
  CATLISTP(IVGestureData) _dataListP;
  int _maxNbOfLastInData;

private:


};

//-----------------------------------------------------------------------
#endif
