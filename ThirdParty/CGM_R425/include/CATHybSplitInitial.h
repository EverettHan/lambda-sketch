#ifndef CATHybSplitInitial_H 
#define CATHybSplitInitial_H 
/**
*/
//=============================================================================
// COPYRIGHT    : DASSAULT SYSTEMES 2006
//
//									Boolean Operator For Shell and Wire : 
// DESCRIPTION  : noyeau Split/Trim  (utilitaires)
//
// Jan 2007			: Creation                                            R.LOJA
//
//============================================================================
#include "CATHybDef.h"
#include "BOHYBOPELight.h"
#include "CATIAV5Level.h"

class CATError;
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
* The way of extrapolation if the cutting body does not cut right along the body to cut.
*/


ExportedByBOHYBOPELight CATBody    * CATHybSplitShellInitial(CATGeoFactory           *iFactory,
														CATTopData              *iData,
														CATBody                 *iBodyToCut,
														CATBody                 *iCuttingBody,
                            short                    iSideToKeep,
														CATHybExtrapolationMode  iExtrapolMode,
														double                   iTol,
                            CATTopOpInError         *&InternalWarning ,
														CATBoolean               iSemiSpaceMode=FALSE,
                            CATBoolean               iSingleExtrapolMode=FALSE);

ExportedByBOHYBOPELight CATError *
CheckCicatriceCompletude(CATGeoFactory * ImplicitFactory,CATTopData * iData,CATBody * iBodyToCut,CATBody *& Cicatrice);
														

#endif



