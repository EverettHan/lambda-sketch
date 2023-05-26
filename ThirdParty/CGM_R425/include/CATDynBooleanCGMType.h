#ifndef CATDynBooleanCGMType_H
#define CATDynBooleanCGMType_H

#include "BODYNOPE.h"
#include "CATDynOperatorDef.h"

/**
 * Defines the Boolean operation types.
 *   @param CATBoolNone
 *     Undefined operation.
 *   @param CATBoolUnion
 *     The union.
 *   @param CATBoolIntersection
 *     The intersection.
 *   @param CATBoolRemoval
 *     The difference.
 *   @param CATBoolCGMDelta
 *     The delta.
 */
enum CATDynBooleanCGMType
{ 
  CATBoolCGMNone         = 0,
  CATBoolCGMUnion        = 1, 
  CATBoolCGMIntersection = 2, 
  CATBoolCGMRemoval      = 3,
  CATBoolCGMDelta        = 4
};

enum 

ExportedByBODYNOPE
CATDynBooleanCGMType ConvertOpTypeToOpTypeCGM(CATDynBooleanType iOperation);

ExportedByBODYNOPE
CATDynBooleanType ConvertOpTypeCGMToOpType(CATDynBooleanCGMType iOperationCGM);


#endif
