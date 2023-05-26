#ifndef CreateTopologicalFillLight_H 
#define CreateTopologicalFillLight_H 

// COPYRIGHT DASSAULT SYSTEMES  2008
 /** @CAA2Required */ 

#include "FrFTopologicalOpeLight.h"
#include "CATDataType.h"
#include "CATSkillValue.h"
#include "CATIACGMLevel.h"

class CATGeoFactory;
class CATBody;
class CATTopologicalFill;
class CATCGMJournalList;

#ifndef CATIACGMV5R20
/**
 * @nodoc
 * Starting with V5R20, this method is no longer supported
 * Creates a topological operator that fills a closed area defined by a set of connecting wires.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iNumberOfWires
 * The number of wires defining the boundary of the area to fill. 
 * @param iArrayOfWires
 * The array of pointers to the wire bodies, each containing only one wire. 
 * The set of wires must defined a closed area, 
 * and the wires must be given in the right order (but the orientation
 * of each wire is computed by the operator).
 * @param iMode
 * The mode of use.
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATTopologicalFill
 */
ExportedByFrFTopologicalOpeLight
CATTopologicalFill * CreateTopologicalFillLight(CATGeoFactory  *iFactory,
					   const CATLONG32 iNumberOfWires,
					   const CATBody **iArrayOfWires,
					   CATSkillValue iMode = BASIC,
					   CATCGMJournalList *iJournal=0);
#endif

#ifndef CATIACGMV5R20
/**
 * @nodoc
 * Starting with V5R20, this method is no longer supported
 * Creates a topological operator that fills a closed area defined by a set of wires.
 * @param iFactory
 * The pointer to the factory of the geometry.
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
 * @param iMode
 * The mode of use.
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATTopologicalFill
 */
ExportedByFrFTopologicalOpeLight
CATTopologicalFill * CreateTopologicalFillLight(CATGeoFactory  *iFactory,
					   const CATLONG32 iNumberOfWires,
					   const CATBody**iArrayOfBodyWires,
					   const CATBody**iArrayOfBodySupports,
					   CATSkillValue iMode = BASIC,
					   CATCGMJournalList *iJournal=0);
#endif

/**
 * @nodoc
 */
ExportedByFrFTopologicalOpeLight
void Remove( CATTopologicalFill *&iTopologicalFill );



#endif


