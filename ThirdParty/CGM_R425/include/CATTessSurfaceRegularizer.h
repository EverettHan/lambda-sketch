#ifndef CATTessSurfaceRegularizer_H
#define CATTessSurfaceRegularizer_H

#include "TessCacheEngine.h"

class CATSurface;


/**
* Regularization of the tessellation of a CATSurface by bar flipping.
*/
class ExportedByTessCacheEngine CATTessSurfaceRegularizer
{

public:

  virtual ~CATTessSurfaceRegularizer () {}

public:

  virtual int Regularize (CATSurface *iSurface, double *iPoints, double *iNormals, double *iuv = 0) = 0;

};


#endif // !CATTessSurfaceRegularizer_H
