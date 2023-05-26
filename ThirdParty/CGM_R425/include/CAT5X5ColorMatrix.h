#ifndef CAT5X5COLORMATRIX_H
#define CAT5X5COLORMATRIX_H

#include "CATListOfDouble.h"
#include "CATBoolean.h"
#include "CATMMediaRasterProcessor_Base.h"
#include "CATMath3x3Matrix.h"

class ExportedByCATMMediaRasterProcessor_Base CAT5X5ColorMatrix
{
public:
	CAT5X5ColorMatrix();
	CAT5X5ColorMatrix& operator=(const CAT5X5ColorMatrix& iColorMatrix);

	int MatMul(CATListOfDouble& iRGBAVals,CATListOfDouble& oModifiedRGBAVals);
	void Initialize(const CATMath3x3Matrix& iMatrix);
	//int InitializeRow(int iRowIdx ,CATListOfDouble& iRowCoeffList);
	int Initialize(const CATListOfDouble& iRowCoeffList);
	void InitializeToIdentityMatrix();
	void SetLToA(CATBoolean ibLToA);
	double Get(const int iRow, const int iCol) const;
	void GetCoef(CATListOfDouble& oMatrix);

private:
	double _colorMatrix[5][5];
};

#endif
