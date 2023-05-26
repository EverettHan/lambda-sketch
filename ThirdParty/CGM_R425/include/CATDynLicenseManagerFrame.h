#ifndef CATDynLicenseManagerFrame_H
#define CATDynLicenseManagerFrame_H
// CATIA Version 5 Release 1 Framework ApplicationFrame
// Copyright Dassault Systemes 2002
#define _NEW_BMW_R201 1
#define _SETTINGS_NOKIA_R15  1
#define _NEW_SETTINGS_R14 1
#include "LicensingFR.h"  // exportedby
#include "CATDlgInclude.h"
#include "CATListOfCATUnicodeString.h"
#ifdef _SETTINGS_NOKIA_R15 
#include "CATDynProductList.h"
#include "CATDynProd.h"
#endif
#include "CATISysLicenseSettingAtt.h"
#include "CATIALicenseSettingAtt.h"
#include "CATSysLicenseSettingCtrl.h"
class CATDlgLock;
class CATDlgToolsOptionsFrame;
class CATDynProductList;
class CATAdmNDynLicNotification;
class CATTrace;

class CATISysDynLicenseSettingAtt;
class CATIADynLicenseSettingAtt;

#define K_EXPIRY_ALERT  "ExpiryAlert.texte"
#define K_P_TITLE    "Popup.Title4"

#define D_EXPIRY_ALERT  "\n(Go to Tools/Options/Licensing and enter 0 for Expiry Alert value \nif you no longer wish to display this message)"
#define D_P_TITLE    " License  Manager"           

class  ExportedByLicensingFR CATDynLicenseManagerFrame : public CATDlgFrame
{
   //------------------------------------------------------------------------
   // Attachement d'un fichier de ressources (CATLicensing) a l'onglet
   //------------------------------------------------------------------------
   DeclareResource ( DynLicensing, CATDlgFrame )

   public: 
   enum Style {
      ActiveAndLicDyn = 0,
      ActiveAndNoLicDyn,
      NotActive
   };
   CATDynLicenseManagerFrame ( CATDialog * father, const CATString & name, Style style=ActiveAndLicDyn );
   ~CATDynLicenseManagerFrame ( );
   void SetDefault         ( );
   void CloseWindowFromEditor ();
   void CancelLicense();
   //static void CancelLicense();
   void CommitLicense();

#define cor_sta
#ifdef cor_sta
   static void UnMake ();
#endif
   private:
   void ManageLockLic ( CATCommand *, CATNotification *, CATCommandClientData );
   void ManageChgLic  ( CATCommand *, CATNotification *, CATCommandClientData );

#ifdef _SETTINGS_NOKIA_R15 
   void GetListProdDemLic ( CATListOfCATUnicodeString &L_Prod_Desc_dem_lic, CATListOfCATUnicodeString & L_UnrequestedProdintName, CATListOfCATUnicodeString & L_UnrequestedProdoffName,
	                        CATListOfCATUnicodeString & L_UnrequestedConfintName, CATListOfCATUnicodeString & L_UnrequestedConfoffName, unsigned int &NbConfig);
#else
   void GetListProdDemLic ( CATListOfCATUnicodeString &L_Prod_Desc_dem_lic, CATListOfCATUnicodeString & L_UnrequestedProdintName, CATListOfCATUnicodeString & L_UnrequestedProdoffName);
#endif
   void SortProducts ( CATUnicodeString * Lst_prod_dispo_def, CATUnicodeString * Lst_prod_dispo, int nb_prod_dispo );
#ifdef _SETTINGS_NOKIA_R15 
   void Redraw (CATCommand *, CATNotification *, CATCommandClientData);
#endif

   CATNotification * GetDynLicNotification ();

   CATDlgFrame              * _frwarn;
   CATDlgLabel                 * _lwarn1;
   CATDlgLabel                 * _lwarn2;

   CATDlgToolsOptionsFrame  * _FRinf ;
   CATDlgFrame              * _frinf ;
   CATDlgContainer             * _cnt1;
   CATDlgFrame                    * _fr01;
   CATDlgLabel                       ** _lprod;

   CATDlgToolsOptionsFrame  * _FRlic;
   CATDlgFrame              * _frlic;
   CATDlgLock                  * _lklic;
   CATDlgContainer             * _cnt2;
   CATDynProductList             * _lic;

   CATISysDynLicenseSettingAtt * _LicAttr;
   CATIADynLicenseSettingAtt * _LicAttrVB;
   CATSysLicenseSettingCtrl * _LicAttrImpl;

   CATDlgStyle validStyle;
   unsigned int _Une_Config;
   CATTrace * _t;
   Style      _style;

   CATAdmNDynLicNotification * e_conf;
#ifdef cor_sta
   static CATListOfCATUnicodeString * _l1;
   static CATListOfCATUnicodeString * _l2;
   static CATListOfCATUnicodeString * _l3;
#endif
#ifdef _SETTINGS_NOKIA_R15 
   CATDialog *_parent;
#endif
#ifdef _SETTINGS_NOKIA_R15  
   static CATListOfCATUnicodeString * _l4;
   static CATListOfCATUnicodeString * _l5;
   static unsigned int _NbConfig;
   CATDynProductList::Style s;
   unsigned int    _nb_item_dispo;
   CATDynProd   ** _lst_item_dispo;


#endif
 
}; 
#endif
