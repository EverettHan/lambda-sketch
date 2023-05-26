// COPYRIGHT Dassault Systemes 2014

#ifndef CATVisVignettingData_H
#define CATVisVignettingData_H

#include "SGInfra.h"
//-----------------------------------------------------------------------
//Vignetting

class ExportedBySGInfra CATVisVignettingData
{
public:
  enum EType
  {
    eNone,
    ePhotographic
  };

  CATVisVignettingData ();
  virtual ~CATVisVignettingData();
};

class ExportedBySGInfra CATVisVignettingPhotographicData : public CATVisVignettingData
{
public:
  CATVisVignettingPhotographicData ();
  virtual ~CATVisVignettingPhotographicData();

  float _power;
  
  bool operator!=(const CATVisVignettingPhotographicData& iData) const;
  bool operator==(const CATVisVignettingPhotographicData& iData) const;
};


#endif
