#ifndef CreateTopologicalBlendCurve_H 
#define CreateTopologicalBlendCurve_H 

// COPYRIGHT DASSAULT SYSTEMES  1999
 /** @CAA2Required */ 
#include "FrFTopologicalOpe.h"
#include "CATGeoToTopOperator.h"
#include "CATSkillValue.h"

class CATTopologicalBlendCurve;
class CATGeoFactory;
class CATBody;
class CATCGMJournalList;

/**
 * @nodoc
 * Deprecated. Use now @href CATCreateTopologicalBlendCurve .
 * Creates a topological operator that connects two wire bodies.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iWire1
 * The pointer to the first wire body, containing only one wire. 
 * @param iWireParam1
 * The pointer to a vertex body on <tt>iWire1</tt>, defining where the connection must be done.
 * @param iWire2
 * The pointer to the second wire body, containing only one wire. 
 * @param iWireParam2
 * The pointer to a vertex body on <tt>iWire2</tt>, defining where the connection must be done.
 * @param iTargetBody
 * The pointer to the body that will contain the resulting the blend curve.
 * @param iBodyFreezeMode
 * The smart mode of the resulting body.
 * @param iMode
 * The mode of use.
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not filled in.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATTopologicalBlendCurve
 */
ExportedByFrFTopologicalOpe
CATTopologicalBlendCurve * CreateTopologicalBlendCurve (CATGeoFactory     * iFactory        ,
                                                        CATBody           * iWire1          ,
                                                        CATBody           * iWireParam1     ,
                                                        CATBody           * iWire2          ,
                                                        CATBody           * iWireParam2     ,
                                                        CATBody           * iTargetBody     = NULL,
                                                        CATBodyFreezeMode   iBodyFreezeMode = CATBodyFreezeOn,
                                                        CATCGMJournalList * iJournal        = NULL,
                                                        CATSkillValue       iMode           = BASIC);

/**
 * @nodoc
 */
ExportedByFrFTopologicalOpe
void Remove (CATTopologicalBlendCurve *&iTopologicalBlendCurve );

#endif




