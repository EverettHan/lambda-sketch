// COPYRIGHT DASSAULT SYSTEMES 1999 
//==========================================================================
//
// CATConnectionConstraint:
// Interface class of the Connection Constraint Object.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Connection Constraint or derived
// in order to implement specific algorithm or capabilities.
//
// A Connection Constraint is a set of :
//   1 Vertex : location of the constraint
//   1 CATFrFContinuity : continuity order
//   3 doubles : tangent parameter
//               curvature parameter
//               binormal parameter
//   1 CATMathDirection : direction of the connection
//
//========================================================================== 
//   /08/99 TPG Creation                                    Tuan Phung (tpg)
// 09/01/18 NLD Tentative de shunt complet de cette classe
//              Mise au propre
//========================================================================== 

#ifndef CATConnectionConstraint_H
#define CATConnectionConstraint_H

// #define CATConnectionConstraint_ShuntCoverage "KO; utilisation dans CATTopologicalMatch"
//
#include "AdvTopoUtil.h"
#include "CreateConnectionConstraint.h"
#include "CATMathDef.h"
//
#ifndef CATConnectionConstraint_ShuntCoverage
class CATVertex;
class CATMathDirection;

//-----------------------------------------------------------------------------
class ExportedByAdvTopoUtil CATConnectionConstraint
{
  public :

  virtual ~CATConnectionConstraint();

  // Information methods
  virtual CATConnectionConstraintClassId IsA()                                        const = 0;
  virtual CATBoolean        IsAKindOf(const CATConnectionConstraintClassId iClassId)  const = 0;

  // Vertex 
  virtual const CATVertex * GetVertex              ()                                 const = 0;
  virtual void              SetVertex              (const CATVertex * iVertex)              = 0;
  //
  // Connection continuity
  // The default value is iContinuity = CATFrFPointCont.
  virtual void              SetConnectionContinuity(CATFrFContinuity iContinuity)           = 0;
  virtual CATFrFContinuity  GetConnectionContinuity()                                 const = 0; 
  //
  // Tangent Parameter (with a connection continuity >= 1) 
  // The default value is 1.0.
  virtual void              SetTangentParameter(double iTangentRatio)                       = 0;
  virtual double            GetTangentParameter()                                     const = 0;
  //
  // Curvature Parameter (with a connection continuity >= 2) 
  // The default value is 1.0.
  virtual void              SetCurvatureParameter(double iCurvatureRatio)                   = 0;
  virtual double            GetCurvatureParameter()                                   const = 0;
  //
  // Binormal Parameter (with a connection continuity >= 2) 
  // The default value is 1.0.
  virtual void              SetBinormalParameter(double iCurvatureRatio)                    = 0;
  virtual double            GetBinormalParameter()                                    const = 0;
  //
  // Direction
  virtual void              SetDirection        (const CATMathDirection * iDirection)       = 0;
  virtual void              GetDirection        (      CATMathDirection & oDirection) const = 0;
};

#endif
#endif
