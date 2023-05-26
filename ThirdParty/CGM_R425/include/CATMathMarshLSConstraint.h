// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2001
//


#ifndef _CATMathMarshLSConstraint_h
#define _CATMathMarshLSConstraint_h

#include "CATMathMxNFullMatrix.h"
#include "CATIMathMarshPPCArray.h"

class CATMathMarshPinpointConstraint;
class CATMathVector;


class CATMathMarshLSConstraint 
{
public:

	CATMathMarshLSConstraint();
	 // Constructeur pour l'interface CATIMathMarshLXYZCArrayImp  
	 // iCoeffs est une matrice de Vector ranges par lignes
	//(i.e. par contrainte lineaire (iNbCST lignes de iPPCArray->Length() vecteurs)

	CATMathMarshLSConstraint(CATIMathMarshPPCArray * iPPCArray, CATMathVector * iCoeffs, int iNbCST);
	~CATMathMarshLSConstraint();

	// Methods for CATIMathMarshLXYZCArrayImp
	inline const CATIMathMarshPPCArray * GetPPCs();
	inline void SetPPCValue(const int iIndex, CATMathVector &iValue);
	inline const CATMathVector * GetCoeffs();
	inline const int GetNbCST();

private: 
	// Une LSC est representee par une matrice n*m vecteurs et m PPC
	CATIMathMarshPPCArray * _PPCs; // size m
	CATMathVector * _Coeffs; // aray size n*m

	int _N; // n
};



inline const CATIMathMarshPPCArray * CATMathMarshLSConstraint::GetPPCs()
{
	return _PPCs;
}

inline void CATMathMarshLSConstraint::SetPPCValue(const int iIndex, CATMathVector &iValue)
{
	if (_PPCs) _PPCs->SetPPCValue(iIndex, iValue);
}

inline const int CATMathMarshLSConstraint::GetNbCST()
{
	return _N;
}

inline const CATMathVector * CATMathMarshLSConstraint::GetCoeffs()
{
	return _Coeffs;
}
#endif
