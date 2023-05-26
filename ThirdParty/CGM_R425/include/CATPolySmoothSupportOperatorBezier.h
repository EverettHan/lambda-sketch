#ifndef CATPolySmoothSupportOperatorBezier_H
#define CATPolySmoothSupportOperatorBezier_H

#include "AdvTopoOpeItf.h"

#include "CATPolySmoothSupportOperator.h"

/**
 * the function use to smooth the support will be a bezier function.
 * */
class ExportedByAdvTopoOpeItf CATPolySmoothSupportOperatorBezier : public CATPolySmoothSupportOperator
{

  protected:
    virtual double ComputeOffsetFromZ(double h) ;
};


#endif //CATPolySmoothSupportOperatorBezier
