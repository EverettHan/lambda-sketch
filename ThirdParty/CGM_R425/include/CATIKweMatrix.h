#ifndef CATIKweMatrix_H
#define CATIKweMatrix_H

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIKweMatrix;
#else
extern "C" const IID IID_CATIKweMatrix;
#endif

class CATCkeEvalContext;
class CATIKweMatrix_var;
class CATMathMxNMatrix;
class ExportedByCATLifSpecs CATIKweMatrix: public CATBaseUnknown
{
	CATDeclareInterface;
public :
	virtual double GetElement(int x, int y) = 0;
	virtual int GetColumnNumber() = 0;
	virtual int GetLineNumber() = 0;
	virtual void SetElement(int x, int y, double iValue) = 0;
	virtual CATUnicodeString Dump() = 0;
	virtual CATUnicodeString ToString() = 0;
	virtual CATBoolean CheckIndexAndRaiseError(int x, int y,const CATCkeEvalContext * iEvalContext = NULL) = 0;
	virtual CATIKweMatrix_var Multiply(const CATIKweMatrix_var &iOther) = 0;
	virtual CATIKweMatrix_var MultiplyScalar(const double &iOper) = 0;
	virtual CATIKweMatrix_var Add(const CATIKweMatrix_var &iOther) = 0;
	virtual CATIKweMatrix_var AddScalar(const double &iOper) = 0;
	virtual CATIKweMatrix_var Substract(const CATIKweMatrix_var &iOther) = 0;
	virtual CATIKweMatrix_var SubstractScalar(const double &iOper) = 0;
	virtual CATIKweMatrix_var Transpose() = 0;
	virtual double Determinant() = 0;
	virtual CATIKweMatrix_var Invert() = 0;
	// /!\ Returns the wrapped object itself, DO NOT DELETE 
	virtual CATMathMxNMatrix * GetInternalMatrix() = 0;
	virtual double Norm() = 0;
	virtual CATBoolean Equals(const CATIKweMatrix_var &iOther) = 0;

	// Only for vectors
	virtual CATIKweMatrix_var CrossProduct(const CATIKweMatrix_var &iOther) = 0;
	virtual double ScalarProduct(const CATIKweMatrix_var& iOther) = 0;
};

CATDeclareHandler(CATIKweMatrix,CATBaseUnknown);

#endif
