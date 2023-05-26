#ifndef CATCreateTopGeodesicProjection_H 
#define CATCreateTopGeodesicProjection_H 

// COPYRIGHT DASSAULT SYSTEMES  2002

#include "CATTopProjection.h"
#include "FrFTopologicalOpe.h"

class CATMathDirection;


/**
** Creates a CATTopGeodesicProjection operator 
* that computes the projections of a point on a wire lying on a shell domain.
* @param iFactory
* The pointer to the factory of the resulting body.
* @param iData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
* is <tt>NULL</tt>, it is not filled.
* @param iPointToProject
* The pointer to the body defining the point to project. 
* @param iWireSupport
* The pointer to the body defining the wire on which projection is done.
* @param iBodyShell
* The pointer to the body defining the shell on which PointToProject and WireSupport are lying on. 
* Use for geodesic projection.
* * @return
* The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator after use.
*/
ExportedByFrFTopologicalOpe 
CATTopProjection * CATCreateTopGeodesicProjection(CATGeoFactory * iFactory,
                                                  CATTopData    * iData,
                                                  CATBody       * iPointToProject,
                                                  CATBody       * iWireSupport,
                                                  CATBody       * iBodyShell);
#endif
