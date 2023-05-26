#ifndef CATExpDeterminant_H
#define CATExpDeterminant_H

#include "CATMathExactPredicates.h"

// Return sign of determinant |x1 x2|
//                            |y1 y2|
ExportedByCATMathExactPredicates int CATExpSignOfDeterminant(double x1, double y1, double x2, double y2);

// Return sign of determinant |(bx1 - ax1) (bx2 - ax2)|
//                            |(by1 - ay1) (by2 - ay2)|
ExportedByCATMathExactPredicates int CATExpSignOfDeterminant(double ax1, double ay1, double bx1, double by1, double ax2, double ay2, double bx2, double by2);

ExportedByCATMathExactPredicates int CATExpSignOfDeterminant(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);

#endif
