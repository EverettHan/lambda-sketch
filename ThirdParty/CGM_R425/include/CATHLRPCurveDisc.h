/* -*-C++-*-*/
#ifndef CATHLRPCurveDisc_H
#define CATHLRPCurveDisc_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRPCurveDisc 
//
// DESCRIPTION :
/**
 * Discretrized PCurve for the HLR. A discretized PCurve is made to handle the 
 * reflect lines on a surface, or PCurve whose definition is a set of points on
 * surface.
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
// Sep. 1999 HKL Gestion des isopares
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRPCurve.h"

// Other includes
#include "CATHLRCrvParamRef.h"
#include "CATCGMScaleCategoryDef.h" // for enum CATCGMScaleCategory

class CATCrvLimits;
class CATCrvParam;
class CATCrvParamReference;
class CATHLRContainer;
class CATHLRSurface;
class CATHLRTransformation;
class CATMathPoint2D;
class CATMathVector2D;
class CATPCurve;
class CATSurParam;
class CATSetOfSurParams; 
class CATSurParamReference;

class ExportedByHLRGeometry CATHLRPCurveDisc : public CATHLRPCurve
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/** Constructor with an identifier and an array of global parameters.
 */
  CATHLRPCurveDisc(int                 iIdentifier,
		               CATMathPoint2D    * iArrayParameters,
		               int                 iCountPoints,
		               CATHLRContainer   * iContainer,
		               CATHLRSurface     * iSupport, 
                   CATCGMScaleCategory iScaleCategory);

/**
 * No Destructor.
 */

//=============================================================================
// METHODS FOR THE MANAGEMENT
//=============================================================================
// Tells if the pcurve is a constant u curve
  virtual short IsIsoParametricU() const;

// Tells if the pcurve is a constant v curve
  virtual short IsIsoParametricV() const;

//=============================================================================
// OVERRIDDEN METHODS
//=============================================================================
  virtual const CATCrvParamReference * GetReference() const;

// Gets the limits of the PCurve
  virtual void GetLimits(CATCrvLimits & oLimits) const;

/** Evaluates the CATSurParam on the surface associated to a parameter.
 */
  virtual void EvalPointUV(const CATCrvParam & iParam, CATSurParam & oParam) const;

/** Evaluates the derivative on the surface associated to a parameter.
 */
  virtual void EvalFirstDerivUV(const CATCrvParam & iParam,
				CATMathVector2D   & oDerivatives) const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Reference for the pcurve
  CATHLRCrvParamRef _CurveReference;

// Size of the datas
  int               _CountPoints;

// Array of points. They are stock as a couple (x,y)
  CATMathPoint2D  * _ArrayGlobalParam;

// Reference manager of the parameters on the support surface, to build a CATSurParam
  const CATSurParamReference * _SurfaceReference;

// Information sur type d'isoapre
  short _IsIsoparU;
  short _IsIsoparV;  
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
