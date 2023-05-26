//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchOrCriterion_H
#define CATIIniSearchOrCriterion_H

#include "UIModelInterfaces.h"
#include "CATIIniSearchCombinationCriterion.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchOrCriterion;

/**
 * Interface to define a logical OR complex criterion.
 * <b>Role:</b> This interface defines a complex criterion 
 * based on two simpler criteria.
 * <br>The two criteria are linked with the <b>OR</b> logical operation.
 * <br>Refer to the inherited @href CATIIniSearchCombinationCriterion#SetParameters 
 * method for setting up properly this criterion.
 * <br>The order of the criterion in the input list is very important. The least 
 * discriminating criterion should always be the first input.
 */
class ExportedByUIModelInterfaces CATIIniSearchOrCriterion : public CATIIniSearchCombinationCriterion
{
  CATDeclareInterface;
public:
};
#endif
