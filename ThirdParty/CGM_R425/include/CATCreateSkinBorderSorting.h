#ifndef CATCreateSkinBorderSorting_H 
#define CATCreateSkinBorderSorting_H 

// COPYRIGHT DASSAULT SYSTEMES  2004


#include "BODYNOPE.h"
#include <stdlib.h>
#include "CATTopSkinBorderSorting.h"
#include "ListPOfCATFace.h"

//

class CATGeoFactory;
class CATBody;
class CATTopData;


/** 
 * Creates the operator to compute the border edges of a skin .
 * @param iFactory
 * The pointer to the geometry factory.
 * @param iBody
 * The pointer to the  body on which the edges are computed.
 * @param iInitialFaces
 * The pointer to the liste of faces  on which the edges are computed.
 * @param iWithSmoothPropagation
 * The boolean to decide whether the initial faces should be propagated
 * before border calculation.
 * @param iTopData
 * Data for this current operation. 
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use.
 */
ExportedByBODYNOPE
CATTopSkinBorderSorting * CATCreateSkinBorderSorting (CATGeoFactory     * iFactory,
                                                      CATTopData        * iTopData, 
                                                      CATBody           * iBody,
                                                      CATLISTP(CATEdge) * iEdgesToSort,
                                                      CATLISTP(CATFace) * iInitialFaces,
                                                      CATLISTP(CATFace) * iPropagatedFaces);


#endif


