#ifndef CATCreateTopParallelSimplif_H
#define CATCreateTopParallelSimplif_H


// COPYRIGHT DASSAULT SYSTEMES  2001

#include "FrFTopologicalOpe.h"
#include "CATTopParallel.h"
//
class CATBody;
class CATTopParallel;
class CATExtrapolParallelTool;
class CATICGMExtrapolParallelTool;


/** @nodoc */
/**
* Creates a CATTopParallel operator that computes a wire parallel 
* (according to a given law) to another one on a shell.
* <b>Orientation</b>: The resulting wire is oriented as the input one.<br>
* <b>Journal</b>: If the distance is null, a new body is created and 
* the edges are written as kept. If not, the new body contains the new edges, written
* as created.
* @param iOption
* The definition of the parameters for the operation.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/

ExportedByFrFTopologicalOpe
CATTopParallel * CATCreateTopParallelSimplif       (CATExtrapolParallelTool * iOption,
                                                    CATBody                 * iCurve);

/**
* Creates a CATTopParallel operator that computes a wire parallel 
* (according to a given law) to another one on a shell.
* <b>Orientation</b>: The resulting wire is oriented as the input one.<br>
* <b>Journal</b>: If the distance is null, a new body is created and 
* the edges are written as kept. If not, the new body contains the new edges, written
* as created.
* @param iOption
* The definition of the parameters for the operation.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/
ExportedByFrFTopologicalOpe
CATTopParallel * CATCreateTopParallelMostContinuous(CATExtrapolParallelTool * iOption,
                                                    CATBody                 * iCurve);

/**
* Creates a CATTopParallel operator that computes a wire parallel 
* (according to a given law) to another one on a shell.
* <b>Orientation</b>: The resulting wire is oriented as the input one.<br>
* <b>Journal</b>: If the distance is null, a new body is created and 
* the edges are written as kept. If not, the new body contains the new edges, written
* as created.
* @param iOption
* The definition of the parameters for the operation.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
*/
ExportedByFrFTopologicalOpe
CATTopParallel * CATCreateTopParallelMostContinuous (CATICGMExtrapolParallelTool * iOption,
                                                     CATBody                     * iCurve);

#endif




