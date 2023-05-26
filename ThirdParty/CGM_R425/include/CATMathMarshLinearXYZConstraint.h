// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
//


#ifndef _CATMathMarshLinearXYZConstraint_h
#define _CATMathMarshLinearXYZConstraint_h

#include "CATMathMxNFullMatrix.h"
#include "CATIMathMarshPPCArray.h"

class CATMathMarshPinpointConstraint;
class CATMathVector;


class CATMathMarshLinearXYZConstraint 
{
public:

	CATMathMarshLinearXYZConstraint();
	 // Constructeur pour l'interface CATIMathMarshLXYZCArrayImp  
	CATMathMarshLinearXYZConstraint(CATIMathMarshPPCArray * iPPCArray, CATMathMxNFullMatrix &iCoeffs);
	~CATMathMarshLinearXYZConstraint();

	// Methods for CATIMathMarshLXYZCArrayImp
	inline const CATIMathMarshPPCArray * GetPPCs();
	inline void SetPPCValue(const int iIndex, CATMathVector &iValue);
	inline const CATMathMxNFullMatrix * GetCoeffs();

private: 
	// Une LXYZConstraint est representee par une matrice n*m et m PPC
	CATMathMxNFullMatrix _Coeffs;
	CATIMathMarshPPCArray * _PPCs;
};



inline const CATIMathMarshPPCArray * CATMathMarshLinearXYZConstraint::GetPPCs()
{
	return _PPCs;
}

inline void CATMathMarshLinearXYZConstraint::SetPPCValue(const int iIndex, CATMathVector &iValue)
{
	if (_PPCs) _PPCs->SetPPCValue(iIndex, iValue);
}

inline const CATMathMxNFullMatrix * CATMathMarshLinearXYZConstraint::GetCoeffs()
{
	return &_Coeffs;
}
#endif
