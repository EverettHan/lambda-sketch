#ifndef CATPolyCCDArticulatedTransformation_H
#define CATPolyCCDArticulatedTransformation_H

/*
 * CATPolyCCDArticulatedTransformation describes a continuous path on [0, 1] in SE3.
 * The transformation is defined by the following formula :
 * F(t) = ParentTransformation(t) * SecondTransformation * G(t * Angle, t * Translation) * FirstTransformation
 * G(omega, u) is the rotation around z axis of angle omega followed by a translation along z axis of sign magnitude u.
 * If parent is null ParentTransformation(t) = identity.
 */

#include "ExportedByCATPolyContinuousClashDetection.h"
#include "CATCGMSharedPtr.h"
#include "CATPolyRefCounted.h"

class CATMathTransformation;
class CATMathLine;

class CATPolyCCDArticulatedTransformation : public CATPolyRefCounted
{
public:
  virtual void SetParent(CATCGMSharedPtr<CATPolyCCDArticulatedTransformation> iParent) = 0;
  virtual CATPolyCCDArticulatedTransformation* GetParent() const = 0;

  virtual void SetFirstTransformation(CATMathTransformation const& iTransformation) = 0;
  virtual CATMathTransformation const& GetFirstTransformation() const = 0;

  virtual void SetSecondTransformation(CATMathTransformation const& iStartPosition) = 0;
  virtual CATMathTransformation const& GetSecondTransformation() const = 0;

  virtual void SetAngle(double iAngle) = 0;
  virtual double GetAngle() const = 0;
  
  virtual void SetTranslation(double iTranslation) = 0;
  virtual double GetTranslation() const = 0;

  /**
  * Compute transformation at parameter iTime (belongs to [0, 1])
  */
  virtual CATMathTransformation Eval(double iTime) const = 0;

  /**
  * Create an articulated transformation to be used by the continuous clash detection operator.
  *
  * @param ipParent
  * The parent articulated transformation (may be null)
  * @param iFirstTransformation
  * First transformation
  * @param iSecondTransformation
  * Second transformation
  * @param iAngle
  * Final rotation angle
  * @param iTranslation
  * Final translation parameter
  *
  * @return
  * A shared pointer on the created articulated transformation.
  **/
  ExportedByCATPolyContinuousClashDetection static CATCGMSharedPtr<CATPolyCCDArticulatedTransformation> Create(
    CATCGMSharedPtr<CATPolyCCDArticulatedTransformation> ipParent,
    CATMathTransformation const &iFirstTransformation, CATMathTransformation const &iSecondTransformation,
    double iAngle, double iTranslation);

  /**
  * Create an articulated transformation to be used by the continuous clash detection operator.
  *
  * @param ipParent
  * The parent articulated transformation (may be null)
  * @param iAxis
  * Axis of rotation and translation
  * @param iAngle
  * Final rotation angle
  * @param iTranslation
  * Final translation parameter
  *
  * @return
  * A shared pointer on the created articulated transformation.
  **/
  ExportedByCATPolyContinuousClashDetection static CATCGMSharedPtr<CATPolyCCDArticulatedTransformation> Create(
    CATCGMSharedPtr<CATPolyCCDArticulatedTransformation> ipParent, CATMathLine const &iAxis, double iAngle, double iTranslation);
};

#endif
