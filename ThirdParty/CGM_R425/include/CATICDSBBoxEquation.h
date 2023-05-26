#ifndef CATICDSBBoxEquation_H
#define CATICDSBBoxEquation_H

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCDS.h"

#include "CATICDSEnums.h"
#include "CATCDSBoolean.h"
#include "CATICDSEquation.h"

class CATICDSFactory;
class CATICDSBBoxEquationAdapter;

/**
 * @SKIP
 *
 * Black-box equation. It uses an input adapter object 
 * to make the binding with application implemented methods.
 */
class ExportedBySolverInterface CATICDSBBoxEquation : public CATICDSEquation
{
public:
 
  /**
   * Retreive pointer to adapter object.
   */
  virtual CATICDSBBoxEquationAdapter* GetAdapter() const = 0;

  /**
   * Creates an instance of the CATICDSBBoxEquation geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param inVariables
   *   Returned number of variables.
   * @param iapVariables
   *   Returned array of variables.
   * @param ipAdapter
   *   Pointer to the adapter to use.
   */
  static CATICDSBBoxEquation* Create(CATICDSFactory *ipFactory,
                                     int inVariables, CATICDSVariable **iapVariables,
                                     CATICDSBBoxEquationAdapter* ipAdapter);

  virtual ~CATICDSBBoxEquation() {}
};

#endif
