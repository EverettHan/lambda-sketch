#ifndef CATVizContextualMenuHandler_h_
#define CATVizContextualMenuHandler_h_
        
/* COPYRIGHT DASSAULT SYSTEMES 2002 */


#include "CATVisFoundation.h"
class CATNotification;
class CATManipulator;
class CATDevice;

class ExportedByCATVisFoundation CATVizContextualMenuHandler
{
public :
  CATVizContextualMenuHandler() {};
  virtual ~CATVizContextualMenuHandler();

  virtual void Send(CATManipulator* from, CATNotification* e) = 0;

  virtual void Context(CATManipulator *Manipulator, CATDevice *Device) = 0;
  virtual void EndContext(CATManipulator *Manipulator, CATDevice *Device) = 0;

};


#endif
