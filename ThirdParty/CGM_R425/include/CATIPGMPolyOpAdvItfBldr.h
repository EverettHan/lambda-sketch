#ifndef CATIPGMPolyOpAdvItfBldr_h
#define CATIPGMPolyOpAdvItfBldr_h

#include "CATPolyhedralOperatorsInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATCollec.h"

class CATIPolyMesh;
class CATTolerance;
class CATPGMPolySteepestSlopeOperator;

extern ExportedByCATPolyhedralOperatorsInterfaces IID IID_CATIPGMPolyOpAdvItfBldr;

/**
 * Factory of implementations of CGM interfaces for the framework TopologicalOperators.
 */
class ExportedByCATPolyhedralOperatorsInterfaces CATIPGMPolyOpAdvItfBldr: public CATBaseUnknown
{
  CATDeclareInterface;
public:

  virtual CATPGMPolySteepestSlopeOperator *CATPolySteepestSlopeOperator_CATPGMCreateInstance(
    const CATIPolyMesh &iMesh,
    const CATTolerance &iTolObject) = 0;

};

/**
 * Returns the factory of implementations of interfaces for the framework TopologicalOpe3rators.
 * @return
 *   The factory. Pay attention: no <tt>AddRef</tt> is run.
 */
ExportedByCATPolyhedralOperatorsInterfaces CATIPGMPolyOpAdvItfBldr *CATCGMGetPolyOpAdvItfBldr();

#endif /* CATIPGMPolyOpAdvItfBldr_h */
