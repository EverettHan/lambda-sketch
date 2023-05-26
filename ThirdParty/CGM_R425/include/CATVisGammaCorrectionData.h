// COPYRIGHT Dassault Systemes 2014

#ifndef CATVisGammaCorrectionData_H
#define CATVisGammaCorrectionData_H

#include "SGInfra.h"

//-------------------------------------------------------------------------------------
// Tone Mapping

class ExportedBySGInfra CATVisGammaCorrectionData
{
public:
  CATVisGammaCorrectionData();
  virtual ~CATVisGammaCorrectionData();
  bool operator==(const CATVisGammaCorrectionData& iData) const;
  bool operator!=(const CATVisGammaCorrectionData& iData) const;

  unsigned int  _activation;
  float         _value;
};



#endif
