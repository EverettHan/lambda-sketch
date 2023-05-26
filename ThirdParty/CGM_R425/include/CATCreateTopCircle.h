#ifndef CATCreateTopCircle_H
#define CATCreateTopCircle_H

// COPYRIGHT DASSAULT SYSTEMES  1999

#include "BasicTopology.h"
#include "CATTopCircle.h"
//

/**
 * Creates a topological operator that builds a circle body.
 * <br> After creating the operator, use the </tt>Setxxx</tt> methods to tune
 * your parameters. Then run it, retrieve the resulting body, and delete the operator.
 * @param iFactory
 * The factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iCenter
 * The pointer to the point body defining the center of the circle.
 * @param iSupport
 * The pointer to the skin body defining the support of the circle.
 * @param iRadius
 * The radius of the circle
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
 */
ExportedByBasicTopology
CATTopCircle * CATCreateTopCircleCenterRadius(CATGeoFactory		*iFactory,
                                  CATTopData		*iReport,
								  CATBody			*iCenter,
								  CATBody			*iSupport,
								  double			iRadius);
#endif
