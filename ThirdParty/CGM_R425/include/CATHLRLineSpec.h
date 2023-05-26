/* -*-C++-*-*/
#ifndef CATHLRLineSpec_H
#define CATHLRLineSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRLineSpec 
//
// DESCRIPTION :
/**
 * Specifications of a curve that is in reality a line.
 * <BR> One can read the extremities of the line.
 */
//
//  
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 1998 JCH Creation            
// Dec. 1999 HKL Retrait du destructeur
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRCurveSpec.h"
#include "CATHLRConstant.h"

class CATMathPoint;

class ExportedByHLRGeometry CATHLRLineSpec : public CATHLRCurveSpec
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Constructor from the two extremities of the curve
 */
  CATHLRLineSpec(const CATMathPoint & iStartPoint,
		 const CATMathPoint & iEndPoint);

//=============================================================================
// METHODS
//=============================================================================
// Method to read the datas
  void GetExtremities(CATMathPoint & oStartPoint,
		      CATMathPoint & oEndPoint) const;

/** Overridden method to get the type of the curve : Line
 */
  virtual CATHLRConstant::TypeCurve GetType() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Position of the start and end points
  double _StartPoint[3];
  double _EndPoint[3];

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
