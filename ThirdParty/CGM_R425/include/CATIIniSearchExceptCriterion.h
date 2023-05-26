//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2002
//------------------------------------------------------------------------------
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchExceptCriterion_H
#define CATIIniSearchExceptCriterion_H

#include "UIModelInterfaces.h"
#include "CATIIniSearchCombinationCriterion.h"

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchExceptCriterion;

/**
 * Interface to define a logical EXCEPT complex criterion.
 * <b>Role:</b> This interface defines a complex criterion 
 * based on two simpler criteria.
 * <br>The two criteria are linked with the <b>EXCEPT</b> logical operation.
 * <br>Refer to the inherited @href CATIIniSearchCombinationCriterion#SetParameters 
 * method for setting up properly this criterion.
 */
class ExportedByUIModelInterfaces CATIIniSearchExceptCriterion : public CATIIniSearchCombinationCriterion
{
  CATDeclareInterface;
public:
};
#endif
