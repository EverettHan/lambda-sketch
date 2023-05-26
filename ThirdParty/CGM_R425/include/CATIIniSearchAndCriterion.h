//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchAndCriterion_H
#define CATIIniSearchAndCriterion_H

#include "UIModelInterfaces.h"
#include "CATIIniSearchCombinationCriterion.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchAndCriterion;

/**
 * Interface to define a logical AND complex criterion.
 * <b>Role:</b> This interface defines a complex criterion 
 * based on two simpler criteria.
 * <br>The two criteria are linked with the <b>AND</b> logical operation.
 * <br>Refer to the inherited @href CATIIniSearchCombinationCriterion#SetParameters 
 * method for setting up properly this criterion.
 * <br>The order of the criterion in the input list is very important. The most 
 * discriminating criterion should always be the first input. When carrying out a 
 * search on a knowledgeware-based attribute, the @href CATIIniSearchTypeCriterion
 * criterion must be the first input.
 */
class ExportedByUIModelInterfaces CATIIniSearchAndCriterion : public CATIIniSearchCombinationCriterion
{
  CATDeclareInterface;
public:
};
#endif
