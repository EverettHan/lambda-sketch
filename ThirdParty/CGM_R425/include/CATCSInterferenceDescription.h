// COPYRIGHT Dassault Systemes 2016


#ifndef CATCSInterferenceDescription_H
#define CATCSInterferenceDescription_H

#include "CATCDS.h"
#include "CATCDSBoolean.h"
class CATCSInterferenceDescriptionImp;

class ExportedBySolverInterface CATCSInterferenceDescription
{
public:
  virtual ~CATCSInterferenceDescription();
  virtual CATCSInterferenceDescriptionImp* GetImp();

  // ppour distinguer les contacts francs des cas en confusion
  CATCDSBoolean IsAbutment();
  void SetAbutment(CATCDSBoolean isSignificant);


protected:
  CATCSInterferenceDescription();
  CATCSInterferenceDescriptionImp* _imp;
  CATCDSBoolean _isAbutment;
};


#endif
