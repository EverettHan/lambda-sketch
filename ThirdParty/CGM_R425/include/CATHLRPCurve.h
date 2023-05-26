/* -*-C++-*-*/
#ifndef CATHLRPCurve_H
#define CATHLRPCurve_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRPCurve 
//
// DESCRIPTION :
/**
 * PCurve for the HLR. A PCurve is able to geive the surface on which it lies,
 * and to evalute some points on it, which lie on this surface.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 1998 JCH Creation            
// Sep. 1999 HKL Added the IsIsoParametricU, IsIsoParametricV
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRGeometry.h"

class CATCrvLimits;
class CATCrvParam;
class CATCrvParamReference;
class CATHLRContainer;
class CATHLRSurface;
class CATHLRTransformation;
class CATMathVector2D;
class CATSurParam;
class CATSurParamReference;

class ExportedByHLRGeometry CATHLRPCurve : public CATHLRGeometry
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Constructor from a jele and a container that will contain the object. Note
 * that no transformation is needed for these objects (so it can be null). The
 * object is linked to a CATHLRSurface on which it lies
 */
  CATHLRPCurve(int iJele,
	       CATHLRContainer            * iContainer,
	       CATHLRSurface              * iSurface,
	       const CATHLRTransformation * iTransformation);

/**
 * Constructor from a CATPCurve and a container.
 */
  CATHLRPCurve(void                       * iPCurve,
	       CATHLRContainer            * iContainer,
	       CATHLRSurface              * iSurface,
	       const CATHLRTransformation * iTransformation);

/**
 * Destructor
 */
  virtual ~CATHLRPCurve();

//=============================================================================
// METHODS FOR THE MANAGEMENT
//=============================================================================
/** Gets the surface on which the object lies.
 */
  CATHLRSurface * GetSurface() const;

// Gets the reference for the CATCrvParam, CATCrvLimits and others.
  virtual const CATCrvParamReference * GetReference() const = 0;

// Gets the limits of the PCurve
  virtual void GetLimits(CATCrvLimits & oLimits) const = 0;

// Tells if the pcurve is a constant u curve
  virtual short IsIsoParametricU() const = 0;

// Tells if the pcurve is a constant v curve
  virtual short IsIsoParametricV() const = 0;

//=============================================================================
// EVALUATIONS ON THE PCURVE
//=============================================================================
/** Evaluates the CATSurParam on the surface associated to a parameter.
 */
  virtual void EvalPointUV(const CATCrvParam & iParam, CATSurParam & oParam) const = 0;

/** Evaluates the derivative on the surface associated to a parameter.
 */
  virtual void EvalFirstDerivUV(const CATCrvParam & iParam,
				CATMathVector2D   & oDerivatives) const = 0;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Surface on which the object lies
  CATHLRSurface * _Surface;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

#endif
