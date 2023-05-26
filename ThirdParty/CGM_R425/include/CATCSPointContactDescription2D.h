// COPYRIGHT Dassault Systemes 2018
//===================================================================


#ifndef CATCSPointContactDescription2D_H
#define CATCSPointContactDescription2D_H

#include "CATCDS.h"
#include "CATCSInterferenceDescription.h"

class CATCSContact;

class ExportedBySolverInterface CATCSPointContactDescription2D: public CATCSInterferenceDescription
{
public:
  CATCSPointContactDescription2D(CATCSContact* iContact);
  void AddPoint2D(double iU, double iV, double iNU, double iNV, double iTol, double iDepth = 1.);

};


#endif
