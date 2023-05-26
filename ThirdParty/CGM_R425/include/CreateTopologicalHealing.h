// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//

#ifndef CreateTopologicalHealing_H 
#define CreateTopologicalHealing_H 

#include "CATSurfacicTopoOperators.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATBody;
class CATHealing;
class CATCGMJournalList;

/**
 * @nodoc 
 * Deprecated.
 * Creates a CATHealing operator
 * Class defining the topological operator that heals geometric holes inside skin bodies.
 * <br>The principle is to create new surfaces by deforming the initial surfaces, so that the
 * the gap of the edges is reduced to a given value. Continuity objectives can be precised between
 * the surfaces. The healed body is created, using these new surfaces and 
 * sharing the non-modified geometry and topology of the initial body (smart concept).
 * @param iGeoFactory
 * The pointer to the factory of the geometry.
 * @param iBodyToHeal
 * The pointer to the body to heal.
 * @param iMode
 * BASIC means Healing with global G0 continuity
 * ADVANCED 
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not filled in.
 */
ExportedByCATSurfacicTopoOperators
CATHealing * CreateTopologicalHealing(CATGeoFactory  *iFactory,
									  CATBody * iBodyToHeal,
									  CATSkillValue iMode = BASIC,
									  CATCGMJournalList *iJournal=0);

#endif


