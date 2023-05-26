//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2012
//===================================================================
#ifndef VisManageIVDeviceRepository_H
#define VisManageIVDeviceRepository_H

#include "CATVisFoundation.h"
class CATSysSettingRepository;

extern ExportedByCATVisFoundation CATSysSettingRepository * VisGetIVDeviceRepository();
extern ExportedByCATVisFoundation void InitDefaultValues();

extern ExportedByCATVisFoundation unsigned int VisGetAutoSpaceTargetMode();
extern ExportedByCATVisFoundation void VisSetAutoSpaceTargetMode(const unsigned int mode);

extern ExportedByCATVisFoundation unsigned int VisGetShowSpaceTargetOpt();
extern ExportedByCATVisFoundation void VisSetShowSpaceTargetOpt(const unsigned int opt);

//*****************************************************************************
#include "CATSysSettingController.h"
class VisIVDeviceSettingCtrl: public CATSysSettingController
{
    // Macro for declaration of the VisIVDeviceSettingCtrl controller
    //CATDeclareSettingCtrl(CAT, Vis, IVDevice);

public :

   static VisIVDeviceSettingCtrl * GetIVDeviceSettingCtrl();

protected:

   virtual  ~VisIVDeviceSettingCtrl();

private:

   VisIVDeviceSettingCtrl();

   void RepositoryUpdatedCB(CATCallbackEvent, void *, CATNotification *, CATSubscriberData , CATCallback);
};

//*****************************************************************************
#endif
