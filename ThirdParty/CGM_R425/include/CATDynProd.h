#ifndef CATDynProd_h
#define CATDynProd_h
//
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// Abstract: Class de base pour le stockage d'informations sur le licensing
// On dissocie trois type d'entites:
//   - Les Produits (Definies par DS)
//   - Les Configs (Definies par DS)
//   - Les Customs Comfigs (Definies a la demande pour le client)
// On Parle de Produits Configs et CustomConfigs
//
// Les Produits sont des types simples.
// Pour Chacun d'entre eux, on associe un CATDynProd simple.
//
// Les Configs et CustomConfige sont plus complexes.
// Pour Chacunes d'entre elles, on associe cependant un CATDynProd simple.
//
// Plusieur CustomConfig peuvent definir le meme contenu.
// Seul leur SerialNumber les differenciera.
// Leur point commun est leur Alias.
// Pour chaque Alias on associe un CATDynProd complexe.
// Il est enrichi de la liste des CATDynProd de Configs ou CustomConfig qui ont cet Alias
//
// Ainsi, Il est possible de ne voir que les Produits et Alias.
//------------------------------------------------------------------------------
//#define CATIAV5R5
//#include "CATIAV5Level.h"
//#ifdef CATIAV5R5
#define _SETTINGS_NOKIA_R15 1
#ifdef _SETTINGS_NOKIA_R15
#include "LicensingFR.h"  // exportedby
#include  "CATUnicodeString.h"
#include "CATLM.h"

#include "CATSysDynLicenseSettingCtrl.h"
#include "CATISysDynLicenseSettingAtt.h"
#include "CATIADynLicenseSettingAtt.h"


class CATISysLicenseSettingAtt;
class CATIALicenseSettingAtt;




class ExportedByLicensingFR CATDynProd 
{
   public:
   enum RepMode {
      Expanded = 0,
      Compact
   };
   enum LicMode {
      License = 0,
      Config,
	  LicenseConfig
   };

   CATDynProd ( CATUnicodeString iname, CATUnicodeString dname, LicMode type);
   //CATDynProd  ( CATUnicodeString i, CATUnicodeString d, CATLM::ProductType t );  
   ~CATDynProd ( );

   void                   SetIName     ( CATUnicodeString iname );
   const CATUnicodeString GetIName     ();
   const char *           GetINameChar ();

   void                   SetDName     ( CATUnicodeString dname );
   const CATUnicodeString GetDName     ();
   const char *           GetDNameChar ();

   const CATLM::AuthorizationStatus GetAuthorizationStatus    ();  // OK

   
   const CATDynProd::RepMode GetRepMode ( );
   void                      SetRepMode ( CATDynProd::RepMode mode );

   
   int          AddDynProd       ( CATDynProd * item );
   CATDynProd * GetNextDynProd   ( );
   unsigned int GetNbInstance ( );
   unsigned int IsGranted  ( );        //Return 1 si licence granted
   unsigned int IsLocked ( );          //Return 1 si attribut locked
   unsigned int IsConfigAuthorized ( );//Return 1 si la config est Authorized
 
   const CATDynProd::LicMode GetLicMode ( );
   void SetLicMode ( CATDynProd::LicMode type );

   CATDynProd::RepMode       _Mode;
   CATDynProd::LicMode       _TypeLicense;

   unsigned int              _IsGranted;
   unsigned int              _NbInstance;
   CATDynProd                * _p;

   protected:
   CATUnicodeString          _IName;
   CATUnicodeString          _DName;

   CATISysDynLicenseSettingAtt * _LicAttr;
   CATIADynLicenseSettingAtt * _LicAttrVB;



   private :

};
#endif
#endif

