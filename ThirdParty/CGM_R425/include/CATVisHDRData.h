// COPYRIGHT Dassault Systemes 2014

#ifndef CATVisHDRData_H
#define CATVisHDRData_H
#include "SGInfra.h"

class ExportedBySGInfra CATVisHDRData
{
public:
  enum EMode
  {
    eAutomatic,       // hdr is automaticaly activated when it is necessary (when a tone mapper, exposition, or gamma correction is set)
    eNone,            // force ldr mode
    eHalfPrecision,   // force hdr with half float precision (16bits per chanel)
    eFullPrecision    // force hdr mode with full foat precision (32bits per chanel)
  };

private:
  CATVisHDRData(){};
  virtual ~CATVisHDRData(){};
};

#endif
