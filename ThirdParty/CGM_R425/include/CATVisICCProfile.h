// COPYRIGHT Dassault Systemes 2016

#ifndef CATVisICCProfile_H
#define CATVisICCProfile_H

#include "SGInfra.h"
#include "CATString.h"

class ExportedBySGInfra CATVisICCProfile
{
public:
  CATVisICCProfile();
  CATVisICCProfile(const CATVisICCProfile& iICCProfile);
  ~CATVisICCProfile();

  CATVisICCProfile& operator=(const CATVisICCProfile& iICCProfile);
  int operator==(const CATVisICCProfile& iICCProfile) const;

  CATString     workingProfile;
  CATString     screenProfile;

  CATString     lookupTable;
  unsigned int  size;
  unsigned int  numTilePerLine;
  bool          flipY;
};


#endif
