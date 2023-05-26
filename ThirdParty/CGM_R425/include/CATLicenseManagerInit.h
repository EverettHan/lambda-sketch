#ifndef CATLicenseManagerInit_H
#define CATLicenseManagerInit_H

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
//#define CATIAV5R5
#include "CATIAV5Level.h"
//#ifdef CATIAV5R5
#define _NEW_SETTINGS_R14 1

#include "LicensingFR.h"
#include "CATAdmR.h"
#include "CATCommand.h"
#include "CATLicenseManager.h"
#include "CATLicenseManagerPopup.h"
#include "CATEnvironmentStatus.h"
#include "CATLicenseManagerStatus.h"
#include "CATListOfCATDlgNotify.h"
#include "CATMsgCatalog.h"
#include "CATMsg.h"

// 
// Style du LicenseManagerInit (En reference avec le /LM)
//
#define CATLicenseManagerNoShowAtStart      0 
#define CATLicenseManagerShowAtStart        1 

//
// Ressources
//
#define CATALOG      "LicensingManager"

#define K_P_ADMTITLE     "Popup.AdmTitle"
#define K_P_NO_ENV       "Popup.EnvironnementNotSet"
#define K_P_BAD_ENV      "Popup.EnvironmentBad"
#define K_P_ADMIN_OK     "Popup.AdminModeOK"
#define K_P_NO_RSP       "Popup.RSPNotDefined"
#define K_P_BAD_RSP_ADM  "Popup.RSPBadConcatenationAsAdmin"
#define K_P_ADMIN_KO     "Popup.AdminModeKO"
#define K_P_BAD_RSP_CONC "Popup.RSPBadConcatenation"
#define K_P_BAD_USP      "Popup.USPBadDirectory"

#define K_P_TITLE    "Popup.Title4"
#define K_P_DEMO_KO  "Popup.DemoModeKO"
#define K_P_DEMO_OK  "Popup.DemoModeOK"
#define K_P_NO_PROD  "Popup.NoProduct"
#define K_P_NO_PRO_R "Popup.NoProductRequested"
#define K_P_NO_CON_R "Popup.NoConfigRequested"
#define K_P_NO_CON_A "Popup.NoConfigAvailable"
#define K_P_NO_A_LIC "Popup.NotAllLicenseAvailable"
#define K_P_NEXT_STA "Popup.SetupForNextStart"
#define K_EXPIRY_ALERT  "ExpiryAlert.texte"


#define D_P_ADMTITLE     "Administration Mode"
#define D_P_NO_ENV       "Environment not set or incorrect.\n\n\
Please set an environment using the setcatenv command."
#define D_P_BAD_ENV      "Environment incorrect.\n\n\
Please set a valid environment using the setcatenv command." 
#define D_P_ADMIN_OK "Running Administration Mode."
#define D_P_NO_RSP "Requested Administration Mode Failed.\n\n\
Variable CATReferenceSettingPath in your environment is not set \n\
Set the CATReferenceSettingPath variable in your Environment."
#define D_P_BAD_RSP_ADM  "Requested Administration Mode Failed.\n\n\
Variable CATReferenceSettingPath in your environment is incorrect \n\
The last directory does not have Write access \n\
Check the CATReferenceSettingPath variable in your Environment."
#define D_P_ADMIN_KO     "Requested Administration Mode Failed.\n\n\
Check the CATReferenceSettingPath variable in your Environment."
#define D_P_BAD_RSP_CONC "Variable CATReferenceSettingPath in your environment is incorrect \n\
One of the directory does not have Read access \n\
Check the CATReferenceSettingPath variable in your Environment."
#define D_P_BAD_USP      "Variable CATUserSettingPath in your environment is incorrect \n\
The directory does not have Write access \n\
Check the CATUserSettingPath variable in your Environment."

#define D_P_TITLE    " License  Manager"           
#define D_P_DEMO_KO  "Demo Mode Not Available"   
#define D_P_DEMO_OK  "Running Demo Mode"         
#define D_P_NO_PROD  "No Configuration/Product Available.\n\n\
The path containing the information required to display\n\
the list of configurations/products, referenced by the\n\
CATICPath CATIA environment variable, is incorrect,\n\
or the information is incomplete.\n\n\
Please set a valid environment using the setcatenv command,\n\
or contact your administrator."
#define D_P_NO_PRO_R "You have not requested a configuration or product license.\n\n\
Click OK and select at least one configuration license\n\
using the License Manager dialog box." 
#define D_P_NO_CON_R "You have requested one or more product licenses, but no configuration license.\n\n\
Click OK and select at least one configuration license\n\
using the License Manager dialog box."
#define D_P_NO_CON_A "No License Available for Requested Configuration(s).\n\n\
Click OK and select at least one valid configuration license\n\
using the License Manager dialog box."
#define D_P_NO_A_LIC "Not All Licenses Available\n\n\
Contact your administrator."
#define D_P_NEXT_STA "These modifications will take effect at next session startup"
#define D_EXPIRY_ALERT  "\n(Go to Tools/Options/Licensing and enter 0 for Expiry Alert value \nif you no longer wish to display this message)"



extern "C" ExportedByJS0FM int GetMainArguments ( int *argc, char ***argv, char ***env );

#ifdef _NEW_SETTINGS_R14
class CATISysLicenseSettingAtt;
class CATIALicenseSettingAtt;
#endif
class  ExportedByLicensingFR CATLicenseManagerInit : public CATCommand
{
   public:

   CATLicenseManagerInit ( CATDialog *, const CS &, CATDlgStyle style=CATLicenseManagerNoShowAtStart );
   ~CATLicenseManagerInit ( );

   private:

   void Check ( CATCommand *, CATNotification *, CATCommandClientData );

   // Gestion des messages d'erreur
   CUS         PopupTxt;
   CUS         PopupTitle;
   CUS         PopupAdmTitle;
   CATDlgStyle PopupStyle;

   CATLicenseManagerPopup  * fen;
   CATDlgNotify            * popup;

   // Gestion PopupTNE
   public:
   static void AfficheST ( const CUS & titre, const CUS & texte );        // Point d'entree TNE pour affichage Popup Dlg
   private:
   CATCallback MonAddCB ( CATCommand *, CATNotification *, CATCommandMethod, CATCommandClientData );
   void Close ( CATCommand *, CATNotification *, CATCommandClientData );  // CB d'effacement de Popup Dlg
   
   static CATDialog              * LePereDlg;    // Pere au sens Dialog
   static CATLicenseManagerInit  * LePereCmd;    // pere au sens Command (this)
   static CATLISTP(CATDlgNotify) * LstPopup;
   static int                      LstPopupCnt;
#ifdef _NEW_SETTINGS_R14
   CATISysLicenseSettingAtt * _LicAttr;
   CATIALicenseSettingAtt * _LicAttrVB;
#endif
   CATSysLicenseSettingCtrl * _LicAttrImpl;
  
};

#endif


