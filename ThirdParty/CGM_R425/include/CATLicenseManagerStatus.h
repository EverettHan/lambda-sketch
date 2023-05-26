#ifndef CATLicenseManagerStatus_H
#define CATLicenseManagerStatus_H
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
#define _NEW_SETTINGS_R14 1
#include "CATIAV5Level.h"

#include "LicensingFR.h"
#include "CATAdmR.h"
#include "CATLM.h"
//#include "CATAdmSint.h"
//#include "CATAdmSfloat.h"
//#include "CATAdmSListCharEtoile.h"
#include "CATLicenseManager.h"
#include "CATAdmPCCC.h"

#define INT_OK_DEMO       1
#define INT_KO_DEMO       0
#define INT_DEFAULT_DEMO  0
#define FLOAT_DEFAULT_TIME  1000.f

class CATTrace;
#ifdef _NEW_SETTINGS_R14
class CATISysLicenseSettingAtt;
class CATIALicenseSettingAtt;
#endif

class ExportedByLicensingFR CATLicenseManagerStatus
{
   public:

   CATLicenseManagerStatus ( int iRADE = 0);
   ~CATLicenseManagerStatus ( );

#ifdef coverage
   // C'est le nombre, par defaut d'item demandant une license. normalement 0 sauf a DS, 1 (InternalDS)
   unsigned int NombreParDefautItemDemandantUneLicense ();
   unsigned int ListeParDefautItemDemandantUneLicense ( CATAdmPCCC ** & l, int & nb );
   unsigned int ListeParDefautItemDemandantUneLicense ( CUS * & l, unsigned int & nb );
   // C'est le nombre d'Alias, CustomConfig, Config et Produits demandant une license (provenance Settings)
   unsigned int NombreItemDemandantUneLicense ( );
   unsigned int ListeItemDemandantUneLicense ( CATAdmPCCC ** & l, int & nb );
#endif

   unsigned int ListeItemDemandantUneLicense ( CATUnicodeString * & l, unsigned int & nb );

   // C'est le nombre d'alias, Config et de Produits disponibles 
   unsigned int NombreItemDispo ( );
   unsigned int ListeItemDispo ( CATAdmPCCC ** & l, unsigned int & nb );

   // C'est le nombre d'Alias, CustomConfig, Config et Produits demandant une license hormis ceux non presents sur l'installation
   unsigned int NombreReelItemDemandantUneLicense ( );

   // C'est le nombre d'Alias, CustomConfig et Config demandant une license hormis ceux non presents sur l'installation
   unsigned int NombreReelConfigDemandantUneLicense ( );

   // C'est le nombre d'Alias, CustomConfig, Config et Produits qui ont eu une license
   unsigned int NombreItemAyantEuUneLicense ();

   // C'est le nombre d'Alias, CustomConfig et Config qui ont eu une license
   unsigned int NombreConfigAyantEuUneLicense ();


   typedef enum 
   {
      NoLicForProd = 0,
      NoLicForConf,
      LicForProd,
      LicForConf
   } LicenseStatus;
 
//   int ListeDeProduitsDispo                        ( CUS * lst, CUS * lst2, int * lst3, int nb );
//   int ListeParDefautDeProduitsDemandantUneLicense ( CUS * lst, int nb );
//   int ListeDeProduitsDemandantUneLicense          ( CUS * lst, int nb );

   
   private:
   void SortProducts ( CUS * Ldef, CUS * L, int nb );
   void GetLstDemLic ( );
   void CleanLstDemLic ( );
//   void Licensing_GetLstDemLic ( char ** & lic, int & nblic );
   void GetLstDispo  ( CATAdmPCCC ** & lst_dispo_item, unsigned int & nb_dispo_item, CATLM::ProductType ptype, 
                       unsigned int & nb_real_item_dem_lic, unsigned int & nb_real_item_got_lic );
   unsigned int IsRADEProduct ( CUS & iName); // Return 0 si pas RADE
   
   float TimeOut;
   int Demo;

   unsigned int   nb_def_prod_dem_lic;
   CUS          * Lst_def_prod_dem_lic;

            int   nb_prod_dem_lic;
   CUS          * Lst_prod_dem_lic;

   unsigned int nb_dispo_alias;
   unsigned int nb_dispo_product;
   unsigned int nb_dispo_RADE;		//Nombre de produits RADE
   CATListOfCATUnicodeString  _CAARADEProducts;

   CATAdmPCCC ** lst_dispo_cust_conf;
   CATAdmPCCC ** lst_dispo_alias;
   CATAdmPCCC ** lst_dispo_config;
   CATAdmPCCC ** lst_dispo_product;

   unsigned int nb_dispo_item; 
   CATAdmPCCC ** lst_dispo_item;

   unsigned int nb_real_cust_conf_dem_lic;
   unsigned int nb_real_alias_dem_lic;
   unsigned int nb_real_config_dem_lic;
   unsigned int nb_real_product_dem_lic;

   unsigned int nb_real_cust_conf_got_lic;
   unsigned int nb_real_alias_got_lic;
   unsigned int nb_real_config_got_lic;
   unsigned int nb_real_product_got_lic;

   void * ioContext;

#ifdef _NEW_SETTINGS_R14
   CATISysLicenseSettingAtt * _LicAttr;
   CATIALicenseSettingAtt * _LicAttrVB;
#endif
   int _IsRADE;

   CATTrace * t;
   void DumpList ( CATTrace * t );
   

};
#endif
