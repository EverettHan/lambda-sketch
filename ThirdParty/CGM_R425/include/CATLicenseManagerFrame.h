#ifndef CATLicenseManagerFrame_H
#define CATLicenseManagerFrame_H
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

#include "LicensingFR.h"  // exportedby
#include "CATAdmR.h"      // includes de base
#include "CATSysLicenseSettingCtrl.h"

class CATDlgLock;
class CATDlgPushButton;
class CATDlgToolsOptionsFrame;
class CATAdmRLicenseList;
class CATLicenseManagerStatus;
class CATAdmPCCC;
class CATAdmNDynLicNotification;

#define CATLicenseManagerFrameStatic        1 
#define CATLicenseManagerFrameInterractive  2

#define R12SortedLic 

#ifdef _NEW_SETTINGS_R14
class CATISysLicenseSettingAtt;
class CATIALicenseSettingAtt;
#endif

//------------------------------------------------------------------
#define bug_visu
class  ExportedByLicensingFR CATLicenseManagerFrame : public CATDlgFrame
{

   //------------------------------------------------------------------------
   // Attachement d'un fichier de ressources (CATLicensing) a l'onglet
   //------------------------------------------------------------------------
   DeclareResource ( Licensing, CATDlgFrame )

   public:

   CATLicenseManagerFrame (       CATDialog            * father,
                            const CS                   & name,
                                  CATSettingRepository * _ptrepository,   // Repository pointer
                                  CATDlgStyle            style=CATLicenseManagerFrameStatic );
   ~CATLicenseManagerFrame ( );

   void SetDefault         ( );
   void CloseWindowFromEditor ();

   private:

   void ManageLockLic ( CATCommand *, CATNotification *, CATCommandClientData );
//#ifndef _NEW_SETTINGS_R14
   void ManageLockDem ( CATCommand *, CATNotification *, CATCommandClientData );
   void ManageLockSid ( CATCommand *, CATNotification *, CATCommandClientData );
   void ManageLockTO  ( CATCommand *, CATNotification *, CATCommandClientData );
   void ManageEA	  (CATCommand *, CATNotification *, CATCommandClientData);
   void ManageLockCF  ( CATCommand *, CATNotification *, CATCommandClientData );
//#endif

   void ManageDemo    ( CATCommand *, CATNotification *, CATCommandClientData );
   void ManageSid     ( CATCommand *, CATNotification *, CATCommandClientData );
   void ManageTO      ( CATCommand *, CATNotification *, CATCommandClientData );
   void ManageCF      ( CATCommand *, CATNotification *, CATCommandClientData );
   void PopupWarning  ( CATCommand *, CATNotification *, CATCommandClientData );
   void PopupWarning2 (CATCommand * cmd, CATNotification * notif, CATCommandClientData data);
   void ConfigStatus  ( CATCommand *, CATNotification *, CATCommandClientData );
   void Redraw        ( CATCommand *, CATNotification *, CATCommandClientData );
   void OnActiveServers(CATCommand         * iSendingCommand, 
                           CATNotification    * iSentNotification, 
                           CATCommandClientData iUsefulData);

   CATNotification * GetDynLicNotification ();

   CATDlgToolsOptionsFrame  * _FRinf ;
   CATDlgFrame              * _frinf ;
   CATDlgFrame                 * _fr10 ;
   CATDlgLabel                    * _ltid ;
   CATDlgLabel                    * _tid;
   CATDlgFrame                 * _fr11 ;
   CATDlgLabel                    * _ldis ;
   CATDlgLabel                    * _dis;
   CATDlgFrame                 * _fr12 ;
   CATDlgLabel                    * _lser;
   CATDlgLabel                    * _ser;
#ifdef bug_visu
//   CATDlgCombo                    * _serS;
   CATDlgEditor                   * _serS;
#endif

   CATDlgPushButton				* _serPopUp;


   CATDlgToolsOptionsFrame  * _FRset ;
   CATDlgFrame              * _frset;
   CATDlgFrame                 * _fr20 ;
   CATDlgFrame                    * _fr201 ;
   CATDlgLabel                       * _plus;
   CATDlgLabel                       * _moins;
   CATDlgLock                     * _lkto;
   CATDlgLabel                    * _lto;
   CATDlgSlider                   * _to;
   CATDlgLock                     * _lkea;
   CATDlgLabel                    * _lea;
   CATDlgSpinner                    * _ea;
   CATDlgFrame                 * _fr21 ;
    /*
   
   //PMR// Plus de mode demo en R207

   CATDlgLock                     * _lkdem;
   CATDlgCheckButton              * _demo;
   CATDlgFrame                 * _fr22 ;
   */
   
   CATDlgLock                     * _lksid;
   CATDlgCheckButton              * _sid;
   CATDlgFrame                 * _fr23 ;
   CATDlgLock                     * _lkcf;
   CATDlgLabel                    * _lcf;
   CATDlgCombo                    * _cf;
   CATDlgToolsOptionsFrame  * _FRlic;
   CATDlgFrame              * _frlic;
   CATDlgLock                  * _lklic;
   CATDlgContainer             * _cnt;
   CATAdmRLicenseList             * _lic;

   CATDlgStyle validStyle;
   CATSettingRepository * PtRepository;
#ifdef _NEW_SETTINGS_R14
   //static CATSysLicenseSettingCtrl * _LicAttr;
   CATSysLicenseSettingCtrl * _LicAttrImpl;
   CATISysLicenseSettingAtt * _LicAttr;
   CATIALicenseSettingAtt * _LicAttrVB;
#endif


   unsigned int    nb_item_dispo;
   CATAdmPCCC   ** lst_item_dispo;

   int UnCoup;
   int Une_Config;
   CATLicenseManagerStatus * Lic;

   CATAdmNDynLicNotification * e_conf;

#ifdef R12SortedLic 
   DRECT dim;
   int _NbServers;
   int nStyle;
#endif
};



#endif
