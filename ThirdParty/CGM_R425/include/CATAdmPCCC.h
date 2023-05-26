#ifndef CATAdmPCCC_h
#define CATAdmPCCC_h
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
// Pour Chacun d'entre eux, on associe un CATAdmPCCC simple.
//
// Les Configs et CustomConfige sont plus complexes.
// Pour Chacunes d'entre elles, on associe cependant un CATAdmPCCC simple.
//
// Plusieur CustomConfig peuvent definir le meme contenu.
// Seul leur SerialNumber les differenciera.
// Leur point commun est leur Alias.
// Pour chaque Alias on associe un CATAdmPCCC complexe.
// Il est enrichi de la liste des CATAdmPCCC de Configs ou CustomConfig qui ont cet Alias
//
// Ainsi, Il est possible de ne voir que les Produits et Alias.
//------------------------------------------------------------------------------
//#define CATIAV5R5
//#include "CATIAV5Level.h"
//#ifdef CATIAV5R5

#include "LicensingFR.h"  // exportedby
#include  "CATUnicodeString.h"
#include "CATLM.h"

#define _NEW_SETTINGS_R14 1

#include "CATSysLicenseSettingCtrl.h"
#include "CATISysLicenseSettingAtt.h"
#include "CATIALicenseSettingAtt.h"


class CATISysLicenseSettingAtt;
class CATIALicenseSettingAtt;

class ExportedByLicensingFR CATAdmPCCC 
{
   public:
   CATAdmPCCC  ( CATUnicodeString i, CATUnicodeString d, CATLM::ProductType t );  
   ~CATAdmPCCC ( );

   void                   SetIName     ( CATUnicodeString iname );
   const CATUnicodeString GetIName     ();
   const char *           GetINameChar ();
   
   void                   SetDName     ( CATUnicodeString dname );
   const CATUnicodeString GetDName     ();
   const char *           GetDNameChar ();

   const CATLM::ProductType GetType ();
   void                     SetType ( CATLM::ProductType ptype );


   const CATLM::LicenseSource       GetAvailableLicenseSource ();  // none, nodelocked, concurrent included
   const CATLM::LicenseSource       GetGrantedLicenseSource   ();  // none, nodelocked, concurrent included
   const char *                     GetLicenseServer          ();
   void                             GetInclByProd             ( int & nb, const char * & tab );
   void                             GetReqByProd              ( int & nb, const char * & tab );
   const CATLM::AuthorizationStatus GetAuthorizationStatus    ();  // OK

   enum RequestStatus {
      NotRequested = 0,
      Requested
   };
   const CATAdmPCCC::RequestStatus  GetRequestStatus ( CATUnicodeString & iname );
   void                             SetRequestStatus ( CATUnicodeString i, CATAdmPCCC::RequestStatus s );

   CATUnicodeString GetRequestDefaultLicenseName ();
   void             SetRequestDefaultLicenseName ( CATUnicodeString name );

   unsigned int GetInternalStatus ( ); //Return 1 si licence granted, local or requested by
   unsigned int IsGranted  ( );        //Return 1 si licence granted
   unsigned int IsRequested ( );       //Return 1 si licence requested (selectionnee)
   unsigned int IsLocked ( );          //Return 1 si attribut locked

   protected :
   CATUnicodeString          IName;
   CATUnicodeString          DName;
   CATUnicodeString          DefaultLicenseName;
   CATLM::ProductType        Type;
   CATAdmPCCC::RequestStatus Status;
   CATAdmPCCC                * p;
   unsigned int              nb_instance;
   CATISysLicenseSettingAtt * _LicAttr;
   CATIALicenseSettingAtt * _LicAttrVB;

   private :

};
#endif

