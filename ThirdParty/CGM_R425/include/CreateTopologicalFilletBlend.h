#ifndef CreateTopologicalFilletBlend_H 
#define CreateTopologicalFilletBlend_H 

// COPYRIGHT DASSAULT SYSTEMES  1999
 /** @CAA2Required */ 

#include "CATDataType.h"
#include "PowerTopologicalOpe.h"

#include "CATSkillValue.h"

class CATGeoFactory;
class CATBody;
class CATDomain;
class CATTopologicalFilletBlend;
class CATCGMJournalList;

/**
 * @nodoc
 * Deprecated. Use now @href CATCreateTopologicalFilletBlend . 
 * Creates a topological operator that computes the connecting surface between two skin bodies,
 * using a bi-tangency algorithm.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iBodySupport1
 * The pointer to the first skin body: it contains only one face, that covers the whole surface.
 * @param iBodySupport2
 * The pointer to the second skin body: it contains only one face, that covers the whole surface.
 * @param iOrientation1
 * The orientation of <tt>iBodySupport1</tt>, to define the center of the fillet.
 * @param iOrientation2
 * The orientation of <tt>iBodySupport2</tt>, to define the center of the fillet. 
 * @param iRadius
 * The constant radius value.
 * @param iDomainSupport1
 * To keep to <tt>0</tt>.
 * @param iDomainSupport2
 * To keep to <tt>0</tt>.
 * @param iMode
 * The mode of use.
 * @param iJournal
 * The pointer to the journal corresponding to the operation. If <tt>NULL</tt>, the journal is not filled in.
 * <br>The journal is not yet implemented.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATTopologicalFilletBlend
 */
ExportedByPowerTopologicalOpe
CATTopologicalFilletBlend *    CreateTopologicalFilletBlend 
                                (      CATGeoFactory     *    iFactory        ,
                                 const CATBody           *    iBodySupport1   ,
                                 const CATBody           *    iBodySupport2   ,
                                       CATLONG32              iOrientation1   ,
                                       CATLONG32              iOrientation2   ,
                                       double                 iRadius         ,
                                 const CATDomain         *    iDomainSupport1 = 0,
                                 const CATDomain         *    iDomainSupport2 = 0,
                                       CATSkillValue          iMode           = BASIC,
                                       CATCGMJournalList *    iReport         = 0);
/**
 * @nodoc
 */
ExportedByPowerTopologicalOpe
void Remove ( CATTopologicalFilletBlend *&iTopologicalFilletBlend );



#endif







