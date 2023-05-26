#ifndef CATCreateTopBlend_H 
#define CATCreateTopBlend_H 

// COPYRIGHT DASSAULT SYSTEMES  2000

/**
* @level Protected
* @usage U1
*/ 

#include "FrFTopologicalOpe.h"
#include "CATIACGMLevel.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATTopBlend;
class CATCGMJournalList;
/**
 * Creates a topological operator that computes a connecting surface between two wires.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data of the operation.
 * @param iWire1
 * The pointer to the first wire to connect.
 * @param iWire2
 * The pointer to the second wire to connect.
 * @param iSupport1
 * The pointer to the supporting surface of the first wire to connect, thus allowing you to define G1 and G2
 * continuity criteria.
 * @param iSupport2
 * The pointer to the supporting surface of the second wire to connect, thus allowing you to define G1 and G2
 * continuity criteria.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> afer use.
 * @see CATTopBlend
 */

ExportedByFrFTopologicalOpe
CATTopBlend * CATCreateTopBlend(      CATGeoFactory * iFactory ,
                                      CATTopData    * iTopData ,
                                const CATBody       * iWire1   ,
                                const CATBody       * iWire2   ,
                                const CATBody       * iSupport1,
                                const CATBody       * iSupport2);
//
#endif







