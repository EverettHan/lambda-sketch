#ifndef CATIMathPlateLScalarCArray_h
#define CATIMathPlateLScalarCArray_h

#include "CATBaseUnknown.h"
#include "CATDataType.h"

class CATMathGridOfPoints ;
class CATIMathPlatePPCArray;

 class CATIMathPlateLScalarCArray : public CATBaseUnknown
 {
 public :
		virtual HRESULT SetLScalarC(CATLONG32 iIndex, CATIMathPlatePPCArray* iPPCArray, const CATMathGridOfPoints& iCoeffs) = 0;

	// Accesseur, modifieur des tableau de PinpointConstraints
		virtual HRESULT GetPPCs(CATLONG32 iIndex, CATIMathPlatePPCArray*& oPPC) = 0;

	// A utiliser comme Accesseur uniquement car le numero de version n'est pas mis a jour en cas de modification
		virtual HRESULT GetCoeffs(CATLONG32 iIndex, CATMathGridOfPoints*& oCoeffs) const =0;
		virtual HRESULT GetLength(CATLONG32& oLength) const = 0;
		virtual HRESULT GetConstraintVersion(int& oConstraintVersion) const = 0;

 };
#endif



