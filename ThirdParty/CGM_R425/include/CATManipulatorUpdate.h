#ifndef CATMANIPULATORUPDATE_H
#define CATMANIPULATORUPDATE_H

/* COPYRIGHT DASSAULT SYSTEMES 2002 */

#include "CATVisFoundation.h"

class CATManipulator;
class CATDevice;

class ExportedByCATVisFoundation CATManipulatorUpdate
{
  public:
    enum CATManipulatorUpdateType {
      Preactivate,
      MoveOver,
      Move,
      EndPreactivate,
      BeginManipulate,
      Activate,
      Context,
      EndManipulate,
      //Manipulate
    };

    CATManipulatorUpdate(CATManipulator*, CATDevice*, CATManipulatorUpdateType);
    virtual ~CATManipulatorUpdate();

    inline CATManipulator* GetManipulator();
    inline CATDevice*      GetDevice();
    inline CATManipulatorUpdate::CATManipulatorUpdateType GetType();

  private:

    CATManipulator* _manipulator;
    CATDevice* _device;
    CATManipulatorUpdateType _type;
};

ExportedByCATVisFoundation CATManipulator* CATManipulatorUpdate::GetManipulator()
{
  return _manipulator;
}

ExportedByCATVisFoundation CATDevice* CATManipulatorUpdate::GetDevice()
{
  return _device;
}

ExportedByCATVisFoundation CATManipulatorUpdate::CATManipulatorUpdateType CATManipulatorUpdate::GetType()
{
  return _type;
}

#endif
