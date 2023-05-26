// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATFrFSection:
// Interface class of FrF Section Object.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Section or derived
// in order to implement specific algorithm or capabilities.
//
//========================================================================== 
// May 97     Creation                       Tuan Phung (tpg)
//========================================================================== 
/*
#ifndef CATFrFSection_H
#define CATFrFSection_H

#include "FrFAdvancedObjects.h"
#include "CATMathDef.h"

#include "CreateFrFSection.h"

class CATMathSetOfPoints;
class CATMathSetOfPointsND;

class CATMathSetOfVectors;
class CATMathInterval;
class CATFrFCoupling;
class CATFrFMovingFrame;
class CATFrFSetOfGuides;
class CATFrFShapeConstraint;
class CATFrFProfile;
class CATFrFNurbsMultiForm;
class CATCurve;
class CATGeoFactory;
class CATMathTransformation;

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFSection
{
  public :

  virtual ~CATFrFSection();
//
//  Get Section Domain 
//
  virtual const CATMathInterval * GetSectionDomain() const = 0;
//
//  Get the Section Set Of Guides 
//
  virtual CATFrFSetOfGuides * GetSetOfGuides() const = 0;
//
//  Get the Section Coupling 
//
  virtual CATFrFCoupling * GetCoupling() const = 0;
//
//  Get the Section Moving Frame 
//
  virtual CATFrFMovingFrame * GetMovingFrame() const = 0;
//
//  Get number of Constraints
//
  virtual CATLONG32 GetNumberOfShapeConstraints() const = 0;
//
//  Get one Shape Contraint
//
  virtual CATFrFShapeConstraint * GetShapeConstraints(const CATLONG32 iShapeConstraintIndex) const = 0;
//
//  Get the Shape Contraints
//
  virtual CATFrFShapeConstraint ** GetShapeConstraints() const = 0;
//
//  Get the next Section 
// 
  virtual CATFrFSection * GetNextSection() const = 0;
//
//  Get the previous Section 
// 
  virtual CATFrFSection * GetPreviousSection() const = 0;
//
//  Get the first Section 
// 
  virtual CATFrFSection * GetFirstSection() const = 0;
//
//  Get the last Section 
// 
  virtual CATFrFSection * GetLastSection() const = 0;
//
// Get the number of sections
//
  virtual CATLONG32 GetNumberOfSections() const = 0;
//
//  Get Profile 
//
  virtual CATFrFProfile * GetProfile() const = 0;
//
//  Get Profile 
//
  virtual CATFrFNurbsMultiForm ** GetProfile( const double iT) const = 0;
//
//  Get Profile of all sections
//
  virtual CATCurve** GetAllProfiles( double iT, CATGeoFactory* iFactory) const = 0;
//
// Get Section
//
  virtual CATFrFNurbsMultiForm ** GetSection( const CATMathSetOfPointsND* iParams ) const = 0;
//
  virtual CATLONG32 GetNumberOfSurfaces() const = 0;
//
//  Get Profile Transformation (return NULL if no result)
//
  virtual CATMathTransformation* GetTransformation( double iT ) const = 0;
//
//  Get Profile Transformation (return FALSE if no result)
//
  virtual CATBoolean GetTransformation( double iT, 
                                        CATMathTransformation& oTransfo) const = 0;
//
//  Set the Section Set Of Guides 
//
  virtual void SetSetOfGuides(CATFrFSetOfGuides * iGuides) = 0;
//
//  Set the Section Coupling 
//
  virtual void SetCoupling(CATFrFCoupling * iCoupling) = 0;
//
//  Set the Section Moving Frame 
//
  virtual void SetMovingFrame(CATFrFMovingFrame * iMovingFrame) = 0;
//
//  Set the Shape Contraints
//
  virtual void SetShapeConstraints(CATLONG32 iNumberOfShapeConstraints,
                                   CATFrFShapeConstraint ** IConstraints) = 0;


//
//  Eval discretized Profile
//
  virtual CATLONG32 GetNumberOfPoints() const = 0;
//
// oPt is already allocated
//
  virtual void Eval (const double  iT, CATMathSetOfPoints *oPt) const = 0;
  virtual void Eval (const double  iT, double *oPt) const = 0;
//
// oDer1 is already allocated
//
  virtual CATBoolean IsEvalFirstDerivAvailable() const = 0;
  virtual void EvalFirstDeriv(const double  iT, CATMathSetOfVectors *oDer1) const = 0;
//
// oDer2 is already allocated
//
  virtual CATBoolean IsEvalSecondDerivAvailable() const = 0;
  virtual void EvalSecondDeriv(const double  iT, CATMathSetOfVectors *oDer2) const = 0;
 
};

#endif
*/
