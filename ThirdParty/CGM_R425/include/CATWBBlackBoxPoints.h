// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//
// Points:
// Claster of points. Used during the Black-Box computations
//
//===================================================================
// Usage notes:
//===================================================================
// Dec. 06    Creation                   VTN
//===================================================================

#ifndef CATWBBlackBoxPoints_H
#define CATWBBlackBoxPoints_H

#include "CATWhiteBoxSolver.h"

class ExportedByCATWhiteBoxSolver CATWBBlackBoxPoints {

  public:

   /**
    * Make CATWBblackBoxPoints object.
    * @param iSz the size of 1 point
    * @param iN the number of points
    */
    CATWBBlackBoxPoints(unsigned iSz, unsigned iN);
  /**
    * Destroy the object.
    */
    virtual ~CATWBBlackBoxPoints();

   /**
    * Return a pointer to the 1st field of the point.
    */
    double *GetPoint(unsigned i);

   /**
    * Set a value to the point i.
    */
    void SetPoint(unsigned i, double *iPoint);

   /**
    * Return a pointer to the 1st field of the point.
    */
    double GetCoord(unsigned iPoint, unsigned iCoord);

   /**
    * Set a value to the point i.
    */
    void SetCoord(unsigned iPoint, unsigned iCoord, double iValue);

  private:
    double *_data;  // Data field to store points values
    unsigned _PointSize; // Nb of doubles in one point == domain dimension+1 (== BB arity + 1)
    unsigned _Npoints;   // Nb of points
};

#endif  // ifndef CATWBBlackBoxPoints_H
