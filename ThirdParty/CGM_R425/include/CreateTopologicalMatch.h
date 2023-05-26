#ifndef CreateTopologicalMatch_H 
#define CreateTopologicalMatch_H 

// COPYRIGHT DASSAULT SYSTEMES  1999
 /** @CAA2Required */ 
// 16/11/05 CCK : CreateTopologicalMatchBoth
//                non teste -> je mets en commentaire pour le coverage

#include "FrFTopologicalOpe.h"

#include "CATDataType.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATBody;
class CATTopologicalMatch;
class CATCGMJournalList;

/**
 * @nodoc
 * Deprecated. Use now @href CATCreateTopologicalMatch .
 * Creates a topological operator of multiple sides matching.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iWire1
 * The array <tt>[NbWires]</tt> of pointers to wire body on the first same surface. 
 * Each body only contains one wire with one edge. The geometry of the edge must
 * be a boundary of <tt>iSupport1</tt>.
 * @param iWire2
 * The array <tt>[NbWires]</tt> of pointers to the corresponding wire bodies to match.
 * Each body only contains one wire with one edge. The geometry of the edge must
 * be a boundary of the corresponding surface in <tt>iSupport2</tt>. 
 * @param iNbWires
 * The number of wires to match.
 * @param iSupport1
 * The pointer to the common surface of the wire bodies of <tt>iWire1</tt>.
 * @param iSupport2
 * The array <tt>[NbWires]</tt> pointers to the corresponding surfaces of the wire bodies of <tt>iWire2</tt>.
 * @param iMode
 * The mode of use.
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not written.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATTopologicalMatch
 */
ExportedByFrFTopologicalOpe
CATTopologicalMatch * CreateTopologicalMatch(CATGeoFactory     * iFactory ,
                                             CATBody          ** iWire1   ,
                                             CATBody          ** iWire2   ,
                                             CATLONG32           iNbWires ,
                                             CATBody           * iSupport1,
                                             CATBody          ** iSupport2,
                                             CATSkillValue       iMode    = BASIC,
                                             CATCGMJournalList * iJournal = 0);

/**
 * @nodoc
 * Deprecated. Use now @href CATCreateTopologicalMatch .
 * Creates a topological operator of both matching.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iWire1
 * The pointer to wire body on the first surface. 
 * The body only contains one wire with one edge. The geometry of the edge must
 * be a boundary of <tt>iSupport1</tt>.
 * @param iWire2
 * The pointer to wire body on the second surface. 
 * The body only contains one wire with one edge. The geometry of the edge must
 * be a boundary of <tt>iSupport2</tt>.
 * @param iSupport1
 * The pointer to the first surface.
 * @param iSupport2
 * The pointer to the second surface.
 * @param iMode
 * The mode of use.
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not written.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATTopologicalMatch
 */
/*
ExportedByFrFTopologicalOpe
CATTopologicalMatch * CreateTopologicalMatchBoth(CATGeoFactory     * iFactory,
                                                 CATBody           * iWire1,
                                                 CATBody           * iWire2,
                                                 CATBody           * iSupport1,
                                                 CATBody           * iSupport2,
                                                 CATSkillValue       iMode = BASIC,
                                                 CATCGMJournalList * iJournal = 0);
*/
/**
 * @nodoc
 * Use directly <tt>delete</tt>. 
 */
ExportedByFrFTopologicalOpe
void Remove( CATTopologicalMatch *&iTopologicalMatch );
#endif


