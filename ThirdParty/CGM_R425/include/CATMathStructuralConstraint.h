// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2019
//


#ifndef _CATMathStructuralConstraint_h
#define _CATMathStructuralConstraint_h

#include "MathAdvMarsh.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATCGMOutput.h"

class CATIMathMarshPPCArray;
class CATIMathMarshLXYZCArray;
class CATMathTransformation;


class  ExportedByMathAdvMarsh  CATMathStructuralConstraint
{
public:

  typedef enum
  {
    Contact = 0,
    Tangent = 1,
    Gradient = 2,
    TangentContact = 3,
    PinTangent = 4
  }ConstraintType;

	
	CATMathStructuralConstraint(const CATMathPoint& iP, const double iValue);
	CATMathStructuralConstraint(const CATMathPoint& iP, const CATMathVector& iDir, const double iRadius, const ConstraintType iType, const double iValue = 0.0, CATMathTransformation* invAnisotropy = NULL);
	~CATMathStructuralConstraint();
	CATMathStructuralConstraint();

  inline const CATMathPoint& GetPoint() const { return _P; }
  int GetTransformedPoint(CATMathPoint& oP) const;
  inline const double& GetRadius() const { return _Radius; }
  inline const double& GetValue() const { return _Value; }
  
  int SetValue(const double iValue);
  int SetRadius(const double iRadius);
  int SetConstraintType(const ConstraintType iType);
  int SetInvAnisotropy(CATMathTransformation * invAnisotropy);

  int GenerateConstraint(CATIMathMarshPPCArray*& oPPCArray, CATIMathMarshLXYZCArray *& oLLXYZArray) const;
  int DumpDebugCGM(CATCGMOutput& oStream);

private: 


  void AnisoMorphPnt(CATMathVector& iP) const;

  CATMathPoint _P;
  CATMathVector _Dir;
  double _Radius;
  double _Value;
  CATMathTransformation* _invAnisotropy;
  ConstraintType _Type;
  
};

#endif
