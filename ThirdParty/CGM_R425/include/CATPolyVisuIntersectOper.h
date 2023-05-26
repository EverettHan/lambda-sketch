// COPYRIGHT DASSAULT SYSTEMES 2006-2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuIntersectOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// November 2006 Creation: ndo
// February 2016 JXO: now derives from CATPolyVisuBooleanOper
//===================================================================
#ifndef CATPolyVisuIntersectOper_H
#define CATPolyVisuIntersectOper_H

#include "PolyVisuBoolOper.h"
#include "CATPolyVisuBooleanOper.h"

// Visu
class CAT3DRep;
class CATRep;

// Math
#include "CATMathBox.h"

// System
#include "CATErrorDef.h" // Definition of HRESULT
#include "CATBoolean.h"

/*
 * Boolean operator calculating the intersection of two CAT3DRep.
 */
class ExportedByPolyVisuBoolOper CATPolyVisuIntersectOper : public CATPolyVisuBooleanOper
{

public :

  /*
   * Construct an intersection operator.
   * @param iBox
   *    Bounding box of the domain that contains the operands.
   */
  CATPolyVisuIntersectOper (const CATMathBox& iBox);

  ~CATPolyVisuIntersectOper ();

protected:

  HRESULT RunBooleanOperator ();

};

// OBSOLETE! 
// For backward compatibility with direct calls by SimulationLab (via PolyhedralObjects).
extern "C" ExportedByPolyVisuBoolOper HRESULT CATPolyVisuIntersectOperFunction 
(
  CAT3DRep* iOperand0, 
  CAT3DRep* iOperand1,
  const int iDisregardSurfaceVolumeFlag, /* Option is NO LONGER SUPPORTED (default value is 0!). */
  const int iTakeCustomRep,
  CATRep*& oRep,
  int& oNbDomains,
  int& oErrorID
);

#endif
