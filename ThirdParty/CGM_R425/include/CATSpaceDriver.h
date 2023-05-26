// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATSpaceDriver_H
#define CATSpaceDriver_H

#include "CATVisFoundation.h"

class CATSpaceCalibration;

class ExportedByCATVisFoundation CATSpaceDriver
{

public :
  static void Instantiate(); 
  static void Uninstantiate();

  static CATSpaceCalibration *GetSpaceCalibration(void);

private :
  CATSpaceDriver(void);
  ~CATSpaceDriver(void);
  
  static CATSpaceDriver *_driver;
  CATSpaceCalibration *_pSpaceCalibration;
};

#endif
