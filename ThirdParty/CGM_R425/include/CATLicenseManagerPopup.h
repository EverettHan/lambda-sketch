#ifndef CATLicenseManagerPopup_H
#define CATLicenseManagerPopup_H

// CATIA Version 5 Release 1 Framework ApplicationFrame
// Copyright Dassault Systemes 1998
//------------------------------------------------------------------------
//
// Abstract : 
// ---------- 
//
//------------------------------------------------------------------------
//
// Usage :    
// -------    
//
//------------------------------------------------------------------------
//
// Inheritance : 
// -----------  
//
//------------------------------------------------------------------------
//
// Main Methods :  
// -------------- 
//
//------------------------------------------------------------------------
#define _NEW_SETTINGS_R14 1
#include "LicensingFR.h"
#include "CATAdmR.h"
#include "CATLicenseManagerFrame.h"
#include "CATLicenseManager.h"

#ifdef _NEW_SETTINGS_R14
#include "CATSysLicenseSettingCtrl.h"
#include "CATISysLicenseSettingAtt.h"
#include "CATIALicenseSettingAtt.h"
#include "CATInstantiateComponent.h"
class CATISysLicenseSettingAtt;
class CATIALicenseSettingAtt;
#endif
//
// Ressources
//

// use the same catalog as is CATLicenseManagerInit
#define CATALOG      "LicensingManager"

#define K_P_SETTITLE "Popup.UserSettingsTitle"
#define K_P_USETT_KO "Popup.UserSettingsKO"
#define K_P_RESET "ResetButton.Title"

#define D_P_SETTITLE "User Settings"
#define D_P_USETT_KO "Cannot Write User Settings.\n\n\
Check the CATUserSettingPath variable in your Environment."
#define D_P_RESET "RESET"

class  ExportedByLicensingFR CATLicenseManagerPopup : public CATDlgDialog
{
   public:

   CATLicenseManagerPopup ( CATDialog *, const CS &, CATDlgStyle style=CATLicenseManagerFrameInterractive );
   ~CATLicenseManagerPopup ( );

   private:

   void OK ( CATCommand *, CATNotification *, CATCommandClientData );
   void APPLY ( CATCommand *, CATNotification *, CATCommandClientData );
   void CLOSE ( CATCommand *, CATNotification *, CATCommandClientData );

   CATLicenseManagerFrame * _li;
   CATSettingRepository   * repository;
   CATDialog              * _parent;

#ifdef _NEW_SETTINGS_R14
   CATISysLicenseSettingAtt * _LicAttr;
   CATIALicenseSettingAtt * _LicAttrVB;
#endif


};


#endif
