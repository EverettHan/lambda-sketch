#ifndef CATCreateTopRegularize_H 
#define CATCreateTopRegularize_H 

// COPYRIGHT DASSAULT SYSTEMES  2000

#include "CATHybDef.h"
#include "BOHYBOPE.h"

/**
* Constructs a hybrid operator to regularize body.
* <br> The regularization consists in the suppression of too small
* volumes / faces / edges (which size is less than a tolerance).
* @param iFactory
* The pointer to the factory of the geometry.
* @param iData
* A pointer to the topological data.
* @param iBodyToRegularize
* The pointer to the body to process.
* @Use the SetTolerance() method to modify tolerance.
* @Use the GetResult() method to get result.
* @return
* The pointer to the created operator. To <tt>delete</tt> after use.
*/

ExportedByBOHYBOPE 
CATHybRegularize * CATCreateTopRegularize(CATGeoFactory*     iFactory,
                                          CATTopData*        iData,
                                          CATBody*           iBodyToRegularize);

#endif
