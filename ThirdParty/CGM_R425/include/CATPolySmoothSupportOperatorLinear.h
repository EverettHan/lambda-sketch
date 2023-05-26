#ifndef CATPolySmoothSupportOperatorLinear_H
#define CATPolySmoothSupportOperatorLinear_H

#include "AdvTopoOpeItf.h"

#include "CATPolySmoothSupportOperator.h"

/**
 * the function use to smooth the support will be a linear function (ramp).
 * */
class ExportedByAdvTopoOpeItf CATPolySmoothSupportOperatorLinear : public CATPolySmoothSupportOperator
{

  protected:
    virtual double ComputeOffsetFromZ(double h) ;
};


#endif //CATPolySmoothSupportOperatorLinear
