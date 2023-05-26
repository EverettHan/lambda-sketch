#ifndef CATCreateTopBoolean2_H 
#define CATCreateTopBoolean2_H 
/**
*/
//=============================================================================
// COPYRIGHT     : DASSAULT SYSTEMES 2007
//
//									Boolean Operator For Shell and Wire : 
// DESCRIPTION   : Split avec extrapolation unitaire des coupantes
//
// Avril 2007      : Creation                                            R.LOJA
//
//============================================================================
#include "CATHybDef.h"
#include "BOHYBOPELight.h"
#include "CATIAV5Level.h"
#include "CATIACGMLevel.h"

#ifndef CATIACGMV5R19
//#include "CATCreateTopBoolean.h"
//#else
//========================================================================
//  Split de Shell
//========================================================================
/**
* Constructs an operator that splits a CATShell domain by a CATShell or a CATWire domain.
* <br>The body to split and the cutting body must only contain 
* one shell domain and one (shell or wire) domain respectively.
* <br><b>Orientation</b>: The orientation of the resulting body is the orientation
* of the body to cut.
* <br><b>Journal</b>:
* <ul>
* <li>The faces that are kept and not cut are written as <tt>CATCGMJournal::Keep</tt>
* <li>The faces that are cut are written as <tt>CATCGMJournal::Subdivision</tt> 
* <li>The new edges are written as <tt>CATCGMJournal::Creation</tt>
* <li>The faces that are neither cut, nor kept, are written as <tt>CATCGMJournal::Deletion</tt>
* </ul>
* @param iFactory
* A pointer to the factory of the resulting body.
* @param iData
* A pointer to the topological data.
* @param iBodyToCut
* A pointer to the body to cut. It must only contain one shell
* domain.
* @param iCuttingBody
* A pointer to the cutting body. It must only contain one (wire or shell)
* domain
* @param iSelectMode
* The selection of the resulting parts.
* @param iExtrapolMode
* The way to keep only the no intersecting solutions of extrapolated cuttings mode is activated or not.
*/


ExportedByBOHYBOPELight CATHybSplit * CATCreateTopNewSplitShell(CATGeoFactory           *iFactory,
                                                                CATTopData              *iData,
                                                                CATBody                 *iBodyToCut,
                                                                CATBody                 *iCuttingBody,
                                                                CATHybSelectionMode      iSelectMode,
                                                                CATHybExtrapolationMode  iExtrapolMode,
                                                                double                   iTol,
                                                                CATBoolean               iSingleExtrapolMode );


#endif
#endif


