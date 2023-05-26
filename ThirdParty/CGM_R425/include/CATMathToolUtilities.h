// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2003
//

#ifndef _CATMathToolUtilities_HeaderFile
#define _CATMathToolUtilities_HeaderFile

//#include "MathApprox.h"
#include "MathMarsh.h"

#include "CATMath3x3Matrix.h"
#include "CATMathNxNFullSymMatrix.h"
#include "CATBoolean.h"
class CATMathMxNMatrix;
class CATMathSetOfPoints;
class CATMathPlane;
class CATTolerance;

class  ExportedByMathMarsh CATMathToolUtilities  {

public:

	// Methods PUBLIC
	// 

	// Methode safe to allocate CATMathMxNMatrix
	static CATMathMxNMatrix * NewCATMathMxNMatrix(const int iDim1, const int iDim2);


	static double ComputeNorm(const CATMath3x3Matrix& Mat, const CATMath3x3Matrix* iAniso = NULL);
	static int ProjectMatrixOnSimilitude(const CATMath3x3Matrix& iTrsfMatrix, CATBoolean iProjOnIsometry, 
		CATMath3x3Matrix& oSimilMatrix, const CATMath3x3Matrix * iAnisoMat = NULL);


  static int TransGramProduct(const CATMathMxNMatrix& iMat, CATMathNxNFullSymMatrix & oProd);

  static double Round(const double iValue, const short iNnbDigit);

	//@KTU:20131001
	//-----------------------------------------------------------------------------------------------------------------------
	// Function MinimizeUVBOX
	// Purpose: optimize the {in} plane by applying rotation such as the bounding box has the minimial area.
	//         the plane is only  updated if a minimum is reached. 
	//------------------------------------------------------------------------------------------------------------------------ 
	static int MinimizeUVBOX( CATMathSetOfPoints * iPoints,
		CATMathPlane & ioPlanar,
		double iMinMax[6]  ,
		CATBoolean &oIsMinimum ,
		double iRatioOk
		,const CATTolerance & Tolerance
		,const int iDebugLevel= 0,
		const int NewMinimise=0);

  static int ComputeInertia(const int iNbPoints, CATMathPoint * iSourceCloud, CATMathVector& oFirstDir, CATMathVector& oSecondDir, CATMathPoint& oGp,
    const double iResolution);

private :
	static double ScalarProduct(const CATMath3x3Matrix& iMat1, const CATMath3x3Matrix& iMat2, const CATMath3x3Matrix* iAniso = NULL);
	static double ScalarProduct2(const CATMath3x3Matrix& Mat1, const CATMath3x3Matrix& Mat2);
	static int ProjectMatrixOnSimilitude2(const CATMath3x3Matrix& iTrsfMatrix, CATBoolean iProjOnIsometry, CATMath3x3Matrix& oSimilMatrix, const CATMath3x3Matrix * iAnisoMat);
	static void AddComponent(const CATMath3x3Matrix& iPQ, CATMath3x3Matrix& Ti, CATMath3x3Matrix& ioDQ, const CATMath3x3Matrix* iAniso=NULL);
	//@KTU:20131001
   static int EvalBoxArea(
	   const CATMathSetOfPoints & iPoints
	   , const double  iAngle
	   , const CATMathPoint & iCenter
	   , const CATMathVector & iDir1
	   , const CATMathVector & iDir2
	   , double & oArea
	   , CATMathPlane *oPlan = 0
	   , double *oBox = 0 // tab[4];
	   , const int iDebugLevel= 0
	   ) ;
};
#endif
