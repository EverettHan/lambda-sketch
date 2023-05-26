#ifndef CATIMathPlateLXYZCArray_h
#define CATIMathPlateLXYZCArray_h

#include "CATBaseUnknown.h"
#include "CATMathDef.h"

class CATMathPoint ;
class CATMathPoint2D ;
class CATMathMxNFullMatrix ;
class CATIMathPlatePPCArray;
class CATMathPlateLinearXYZConstraint;

 class CATIMathPlateLXYZCArray : public CATBaseUnknown
 {
 public :
	
		virtual HRESULT SetLXYZC(CATLONG32 iIndex, CATIMathPlatePPCArray* iPPCArray,const CATMathMxNFullMatrix& iCoeffs) = 0;

	// Accesseur, modifieur des tableau de PinpointConstraints
		virtual HRESULT GetPPCs(CATLONG32 iIndex,  CATIMathPlatePPCArray*& oPPC) = 0;

	// A utiliser comme Accesseur uniquement car le numero de version n'est pas mis a jour en cas de modification
		virtual HRESULT GetCoeffs(CATLONG32 iIndex, CATMathMxNFullMatrix*& oCoeffs) const =0;
	
		virtual HRESULT GetLength(CATLONG32& oLength) const = 0;
		virtual HRESULT GetConstraintVersion(int& oConstraintVersion) const = 0;

 };
#endif



