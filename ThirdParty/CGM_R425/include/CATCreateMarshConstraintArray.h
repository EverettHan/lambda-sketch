#ifndef CATCreateMarshConstraintArray_h
#define CATCreateMarshConstraintArray_h
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
/** @level Protected
*  @usage U1
*/


#include "MathMarsh.h"
#include "CATDataType.h"


class CATIMathMarshPPCArray;
class CATIMathMarshLXYZCArray;
class CATIMathMarshLSCArray;


// ==============================================
// ========     Create arrays to fill     =======
// ==============================================
//
/** 
* Build an empty array of pinpoint constraints.
*
* <br><b>Role</b>: Create Constraint for MarshMallow
*
* @param iLength [in]
*   The number of pinpoint in the array.
*
* @return
*   The created array.
*/
ExportedByMathMarsh CATIMathMarshPPCArray * CreateMarshPPCArray(CATLONG32 iLength);

/** 
* Build an empty array of linear xyz constraints.
*
* <br><b>Role</b>: Create Constraint for MarshMallow
*
* @param iLength [in]
*   The number of linear xyz in the array.
*
* @return
*   The created array.
*/
ExportedByMathMarsh CATIMathMarshLXYZCArray *  CreateMarshLXYZCArray(CATLONG32 iLength);

/** 
* Build an empty array of linear scalar constraints.
*
* <br><b>Role</b>: Create Constraint for MarshMallow
*
* @param iLength [in]
*   The number of linear scalar in the array.
*
* @return
*   The created array.
*/
ExportedByMathMarsh CATIMathMarshLSCArray *  CreateMarshLSCArray(CATLONG32 iLength);

#endif
