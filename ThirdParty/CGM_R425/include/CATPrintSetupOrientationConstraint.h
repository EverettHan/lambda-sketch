#ifndef CATPrintSetupOrientationConstraint_H
#define CATPrintSetupOrientationConstraint_H
#include "CATGMOperatorsInterfaces.h"

#include "CATCollec.h"
#include "CATBoolean.h"
#include "CATMathTransformation.h"
#include "CATListOfDouble.h"

class ExportedByCATGMOperatorsInterfaces CATPrintSetupOrientationConstraint
{
public:
  CATPrintSetupOrientationConstraint();

#ifndef _AIX_SOURCE
  CATPrintSetupOrientationConstraint(const CATPrintSetupOrientationConstraint &);
  CATPrintSetupOrientationConstraint& operator =(const CATPrintSetupOrientationConstraint &);
  CATPrintSetupOrientationConstraint(CATPrintSetupOrientationConstraint &&);
  CATPrintSetupOrientationConstraint& operator =(CATPrintSetupOrientationConstraint &&);
  ~CATPrintSetupOrientationConstraint();
#endif

  // ===================================
  //    Fixed orientation 3D
  // ===================================
  void SetFixedOrientation();
  CATBoolean IsFreeOrientation() const;

  void SetUseZLimit(bool iUseZLimit);
  bool GetUseZLimit() const;

  // ===================================
  //    Rotation2D for nesting
  // ===================================
  //ListAngle == NULL --> FreeRotation2D
  //ListAngle Empty   --> FixedRotation
  //ListAngle = {Angle1, Angle2, ...}: only Angle1, Angle2, ... are allowed. Angles are in radian for example: {CATPI, CATPIBy2}
  void SetRotationList(CATMath3x3Matrix const& iInitRotation, CATListOfDouble const* iListAngle, CATBoolean iMirror);
  CATListOfDouble const& GetRotationList() const;

  // ===================================
  //    Rotation for nesting 2D
  // ===================================
  // Specify the step k of rotation 
  // Nesting operator will allow all rotation of 2pi*k/n with 0 <= k < n
  void SetRotationAngleStep(int n);

  CATBoolean IsFreeRotation2D() const;

  void SetMinTrayDistance(double);
  double GetMinTrayDistance() const;

  void SetMirror(CATBoolean iMirror);
  CATBoolean GetMirror()const;

  /**
   * Initial position of CATBody used for nesting (mostly useful for body with fixed orientation)
   */
  void SetInitialPlacement(CATMathTransformation const& iTransformation);
  CATMathTransformation const& GetInitialPlacement() const;

private:
  CATMathTransformation _InitPlacement;  
  CATListOfDouble _angles;
  double _MinTrayDistance;
  CATBoolean _FreeOrientation;
  CATBoolean _Mirror;
  bool _UseZLimit;
};

inline void CATPrintSetupOrientationConstraint::SetMinTrayDistance(double iMinTrayDistance)
{
  _MinTrayDistance = iMinTrayDistance;
}

inline double CATPrintSetupOrientationConstraint::GetMinTrayDistance() const
{
  return _MinTrayDistance;
}

inline void CATPrintSetupOrientationConstraint::SetInitialPlacement(CATMathTransformation const& iTransformation)
{
  _InitPlacement = iTransformation;
}

inline CATMathTransformation const& CATPrintSetupOrientationConstraint::GetInitialPlacement() const
{
  return _InitPlacement;
}

inline CATListOfDouble const& CATPrintSetupOrientationConstraint::GetRotationList() const
{
  return _angles;
}

inline void CATPrintSetupOrientationConstraint::SetMirror(CATBoolean iMirror)
{
  _Mirror = iMirror;
}

inline CATBoolean CATPrintSetupOrientationConstraint::GetMirror() const
{
  return _Mirror;
}

inline void CATPrintSetupOrientationConstraint::SetFixedOrientation()
{
  _FreeOrientation = FALSE;
}

inline CATBoolean CATPrintSetupOrientationConstraint::IsFreeOrientation() const
{
  return _FreeOrientation;
}

inline void CATPrintSetupOrientationConstraint::SetUseZLimit(bool iUseZLimit)
{
  _UseZLimit = iUseZLimit;
}

inline bool CATPrintSetupOrientationConstraint::GetUseZLimit() const
{
  return _UseZLimit;
}

inline CATBoolean CATPrintSetupOrientationConstraint::IsFreeRotation2D() const
{
  return _angles.Size() > 1;
}


#endif
