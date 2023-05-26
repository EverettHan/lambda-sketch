// COPYRIGHT Dassault Systemes 2016
//===================================================================


#ifndef CATCSPointContactDescription_H
#define CATCSPointContactDescription_H

#include "CATCDS.h"
#include "CATCSInterferenceDescription.h"

class CATCSContact;

class ExportedBySolverInterface CATCSPointContactDescription: public CATCSInterferenceDescription
{
public:
  CATCSPointContactDescription(CATCSContact* iContact);
  void AddPoint(double iX, double iY, double iZ, double iNx, double iNy, double iNz, double iTol, double iDepth = 1.);
};


#endif
