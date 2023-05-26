#ifndef CATCreateTopologicalFill_H
#define CATCreateTopologicalFill_H

// COPYRIGHT DASSAULT SYSTEMES  1999

 

#include "FrFTopologicalOpe.h"
#include "CATTopologicalFillLight.h"
#include "CATMathDef.h"
#include "CATTopOperator.h"
#include "CATSkillValue.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"
#include "CATTopologicalFillType.h"

class CATBody;

/**
 * Creates a topological operator that fills a closed area defined by a set of wires.
 * @param iFactory
 * The pointer to the factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iNumberOfWires
 * The number of wires defining the boundary of the area to fill. 
 * @param iArrayOfWires
 * The array of pointers to the wire bodies, each containing only one wire. 
 * The set of wires must defined a closed area, 
 * and the wires must be given in the right order (but the orientation
 * of each wire is computed by the operator).
 * @param iArrayOfBodySupports
 * The array of pointers to the supporting bodies of the wires, thus allowing you to define G1 and G2 continuity
 * criteria.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 * @see CATTopologicalFill
 */
ExportedByFrFTopologicalOpe
CATTopologicalFill * CATCreateTopologicalFill(      CATGeoFactory  * iFactory            ,
                                                    CATTopData     * iTopData            ,
                                                    CATLONG32        iNumberOfWires      ,
                                              const CATBody       ** iArrayOfBodyWires   ,
                                              const CATBody       ** iArrayOfBodySupports);

/**
 * Creates a topological operator that fills a closed area defined by a set of wires.
 * @param iFactory
 * The pointer to the factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iListOfEdges
 * The list of pointers to edges of <tt>iBody</tt>. 
 * The list of edges must defined a closed area, 
 * and the edges must be given in the right order (but the orientation
 * of each edge is computed by the operator).
 * @param iListOfFaces
 * The list of pointers to the supporting faces of the edges, thus allowing you to define G1 and G2 continuity
 * criteria.
 * @param iBody
 * The pointer to the body containing the cells of <tt>iListOfEdges</tt> and <tt>iListOfFaces</tt>.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 * @see CATTopologicalFill
 */
ExportedByFrFTopologicalOpe
CATTopologicalFill * CATCreateTopologicalFill(      CATGeoFactory  * iFactory    ,
                                                    CATTopData     * iTopData    ,
                                              const ListPOfCATEdge * iListOfEdges,
                                              const ListPOfCATFace * iListOfFaces,
                                              const CATBody        * iBody       );


/**
 * @deprecated V5R14
 * Use the signature with the body supports or any other exposed function.
 */
ExportedByFrFTopologicalOpe
CATTopologicalFill * CATCreateTopologicalFill(      CATGeoFactory  * iFactory      ,
                                                    CATTopData     * iTopData      ,
                                                    CATLONG32        iNumberOfWires,
                                              const CATBody       ** iArrayOfWires );

#endif





