#ifndef CATICDSWBEquation_h
#define CATICDSWBEquation_h

// COPYRIGHT DASSAULT SYSTEMES  2013

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSEquation.h"

class CATICDSFactory;
class CATWBEquation;
class CATWBVariable;

/**
 * @SKIP
 *
 * An algebraic equation constructed from a WhiteBox object.
 */
class ExportedBySolverInterface CATICDSWBEquation : public CATICDSEquation
{
public:

  /**
   * Retreives WhiteBox equation.
   */
  virtual CATWBEquation* GetWBEquation() const = 0;
  
  /**
   * Retrieves WhiteBox variables of the equation.
   * @param oNbVariables
   *   Returned number of variables.
   * @param oaVariables
   *   Returned array of variables.
   *
   * @SIZE oapVariables oNbVariables
   */
  virtual void GetWBVariables(int &oNbVariables, CATWBVariable **&oapVariables) const = 0;
  
  /**
   * Creates an instance of the CATICDSWBEquation equation.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param iEquation
   *   A pointer to the WB equation.
   * @param iNbVariables
   *   Value that indicates the number of variables.
   * @param iaVariables
   *   Pointer to the array of variables.
   * @param iaWBVariables
   *   List of WB variables (at least all the variables used in this
   *   WB equation). Each WB variable will be mapped to the corresponding
   *   CDS variable with respect to iaVariables and iaWBVariables
   *   ordering.
   *
   * @SIZE iapVariables iNbVariables
   * @SIZE iapWBVariables iNbVariables
   */
  static CATICDSWBEquation* Create(CATICDSFactory* ipFactory,
                                   CATWBEquation * ipEquation,
                                   unsigned int iNbVariables,
                                   CATICDSVariable **iapVariables,
                                   CATWBVariable **iapWBVariables);

  virtual ~CATICDSWBEquation() {}
};

#endif
