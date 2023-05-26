// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMassPropertiesOper.h
// Header definition of CATPolyMassPropertiesOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  September 2004  Creation:  NDO
//===================================================================
#ifndef CATPolyMassPropertiesOper_H
#define CATPolyMassPropertiesOper_H

#include "CATPolyAnalyzeOper.h"
#include "CATPolyAnalyzeOperators.h"

#include "CATMathPoint.h"

class CATIPolyMesh;


/**
 * This operator calculates mass properties of the polymesh. 
 *
 */
class ExportedByCATPolyAnalyzeOperators CATPolyMassPropertiesOper: public CATPolyAnalyzeOper
{

public:

  /**
  * Constructor
  **/
  CATPolyMassPropertiesOper ();

  /**
  * Destructor
  **/
  virtual ~CATPolyMassPropertiesOper();

  /**
  * Run the operator
  * @return
  *   S_OK the operator runs successfully; E_FAIL otherwise.
  **/
  virtual HRESULT Run(void);

  /**
  * Returns the center of mass.
  * @return
  *   S_OK the operator ran successfully; E_FAIL otherwise.
  **/
  HRESULT GetCentroid (CATMathPoint& oPoint) const;

private:

  HRESULT _RunOk;

  CATMathPoint _CenterOfMass;

};

#endif
