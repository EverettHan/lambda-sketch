#ifndef CATIMathPlatePPCArray_h
#define CATIMathPlatePPCArray_h

#include "CATBaseUnknown.h"
#include "CATMathDef.h"

class CATMathPoint ;
class CATMathPlatePinpointConstraint;
class CATMathPlateArray1OfPinpointConstraint;

 class CATIMathPlatePPCArray : public CATBaseUnknown
 {
 public :
		virtual HRESULT SetPPCValue(const CATLONG32 iIndex, const CATMathPoint& iValue) = 0;
		virtual HRESULT SetPPC(const CATLONG32 iIndex, const CATMathPlatePinpointConstraint& iPPC) = 0;

		virtual HRESULT GetPPC(const CATLONG32 iIndex, CATMathPlatePinpointConstraint*& oPPC) = 0;
		virtual HRESULT GetLength(CATLONG32& oLength) = 0;
		virtual HRESULT GetValueVersion(int& oValueVersion) = 0;
		virtual HRESULT GetConstraintVersion(int& oConstraintVersion) = 0;

 };
#endif



