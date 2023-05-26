#ifndef CreateHybBoundary_H 
#define CreateHybBoundary_H 

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATHybDef.h"
#include "CATSkillValue.h"
#include "HybBoundary.h"

//========================================================================
// 
//  Boundary Operator For Shell and Wire : 
// 
//========================================================================
// 
// Usage notes:
// -------------
// 
// if inputDomain is not provided the body must contain a single Domain on 
// which the boundary will be computed.
// 
// By default, all the boundaries are computed (2 vertices for a wire,
// 1 or more wire for the shell).
// You can specify a criteria to get a partial boundary solution : 
// 1) For the Wire : by giving a vertex in initialCell argument.
//    the nearest wire extremity will be return in this case
// 2) For the shell : by giving an edge in initialCell argument.
//    this edge will be propagate according to CATHybPropagateMode
//    (NO_CONTINUITY, POINT_CONTINUITY, TANGENT_CONTINUITY) to build
//    the solution wire. 
//========================================================================
/**
 * Constructs an operator that creates a piece of boundary of a
 * CATShell or a CATWire.
 * <br>By default, all the boundaries are computed (2 vertices for a wire,
 * 1 or more wire(s) for the shell). To get a partial boundary solution, use an
 * <tt>iInitialCell</tt>.
 * <br><b>Orientation</b>: The orientation of <tt>initialCell</tt>. If <tt>initialCell=null</tt>,
 * the orientation of the loop of the first face of the shell.
 * <br><b>Journal</b>: 
 * <dl><dt>Shell</dt><dd>
 * The edges are written as <tt>CATCGMJournal::Keep</tt>. The first and last vertex of
 * the boundary are written 
 * as <tt>CATCGMJournal::Creation</tt>.
 * <dt>Wire</dt>
 * <dd>The two vertices are written as <tt>CATCGMJournal::Keep</tt>.
 *</dl>
 * @param iFactory
 * A pointer to the factory of the resulting body.
 * @param inputBody
 * A pointer to the body for which the boundary is asked for. If it contains several
 * domains, use <tt>inputDomain</tt> to specify which one is to take into account.
 * @param inputDomain
 * The domain on which the boundary is computed. To use if <tt>inputBody</tt> contains several
 * domains.
 * @param iInitialCell
 * The initial cell from which the boundary is computed.
 * <ul>
 *     <li>for a CATWire: <tt>iInitialCell</tt> is a CATVertex. The boundary begins
 * at <tt>iInitialCell</tt> and ends at the nearest extremity of the CATWire
 *     <li>for a CATShell: <tt>iInitialCell</tt> is a CATEdge. The boundary is
 * propagated according to <tt>CATHybPropagateMode</tt>. The boundary is retrieved
 * as one or more CATWire.
 * </ul>
 * @param iPropagateMode
 * The rule of propagation of a piece of the boundary of a shell domain.
 * <dl><dt>NO_CONTINUITY</dt>
 * <dd>No restriction is made on the definition of the boundary. In particular, this boundary
 * can be made of several domains (case of inner loops of a shell).
 * <dt> POINT_CONTINUITY</dt>
 * <dd>The boundary stops at the last cell of the bounding domain.
 * <dt> TANGENT_CONTINUITY</dt>
 * <dd>The boundary stops at the first vertex where the boundary is not continous in tangent.
 * </dl>
 * @param iMode
 * <dl>
 * <dt> <tt>BASIC</tt></dt><dd> the operation is run at the creation. 
 * <dt>  <tt>ADVANCED</tt></dt><dd> the <tt>Run</tt> method is mandatory.
 * </dl>
 * @param iReport
 * A pointer to the journal. If <tt>NULL</tt>, the journal is not written.
 */
ExportedByHybBoundary CATHybOperator * CreateHybBoundary(CATGeoFactory*         iFactory,
							 const CATBody*         inputBody,
							 const CATDomain*       inputDomain=NULL,
							 const CATCell*         initialCell=NULL,
							 CATHybPropagateMode    iPropagateMode=NO_CONTINUITY,
							 CATSkillValue          iMode = BASIC,
							 CATCGMJournalList*     iReport=NULL);
#endif







