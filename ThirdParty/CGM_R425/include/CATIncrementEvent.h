// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef CATIncrementEvent_H
#define CATIncrementEvent_H

#include "CATDeviceEvent.h"
#include "CAT4x4Matrix.h"
#include "CATVisFoundation.h"
#include "CATBoolean.h"

class CATDevice;
class CATSupport;


class ExportedByCATVisFoundation CATIncrementEvent : public CATDeviceEvent
{
  CATDeclareClass;

public:

  CATIncrementEvent();
  virtual ~CATIncrementEvent();
  const double* GetIncrementMatrix();

  CATDevice    *Device;
  CATSupport *pSupport;
  CAT4x4Matrix _increment;
  CATBoolean   _resetIntegration;
private:
  double *_pIncrementMatrix;
};
#endif
