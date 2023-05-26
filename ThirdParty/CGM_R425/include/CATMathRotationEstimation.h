// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2011
//

#ifndef _CATMathRotationEstimation_HeaderFile
#define _CATMathRotationEstimation_HeaderFile

#include "MathApprox.h"

#include "CATMathQuaternion.h"
#include "CATMathMxNMatrix.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"
#include "CATMath3x3Matrix.h"
#include "CATMathTransformation.h"



class ExportedByMathApprox CATMathRotationEstimation  
{

public:

CATMathRotationEstimation();
~CATMathRotationEstimation();

void Reset();

int AddMatrix(const CATMath3x3Matrix& iMatrix, const double iWeights = 1.0);

int AddVectors(const CATMathVector& initVector, const CATMathVector&  targetVector, const double iWeights = 1.0);

int GetEstimedRotation(CATMathQuaternion& oRotationQuat);

int GetEstimedRotation(CATMath3x3Matrix& oMatrix);

int GetEstimedTransformation(CATMathPoint& iPInit, CATMathPoint& iPTarget, CATMathTransformation& oTransfo);

static int RotMatrixToQuaternion(const double iMatrixCoefs[9], CATMathQuaternion& oQuat);

static int GetEstimedTransformation(CATMathPoint& iPinit, CATMathPoint& iPtarget,
                                                       CATMathQuaternion& iQRotation,
                                                       CATMathTransformation& oTransfo);


private :

  int ComputeEstimedRotation();


  CATMathMxNMatrix _MSum;
  //CATMath3x3Matrix  _mRotation;
  CATMathQuaternion _qRotation;
  double _tIv[3];
  double _tDv[3];
  double * _Mvals;
  CATBoolean _isComputed;
};
#endif
