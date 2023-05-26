//-------------------------------------------------------------------------

// COPYRIGHT DASSAULT SYSTEMES 2000

//
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
//  HISTORIQUE :   
//           1- valeurs des enum modifiees:
//                   ComponentAccess
//                   ComponentType
//                   ComponentEffectivity
//           2- restriction de la signature des methodes de lecture 
//              des attributs: ajout d'un const
//           3- ajout des methodes:
//                    >> UnloadAllComponents
//                    >> AttachComponent
//                    >> GetListAttachComponent
//                    >> GetPrereqComponent
//                    >> GetAttachComponent
//                    >> MakeMacroIdent
//                    >> MakeShLibName
//                    >> CheckName
//                    >> StripName
//                    >> SetTrace
//           4- utilisation des traces de System
//           5- troncature des noms qui depassent la longueur maxi.
//           6- plus de distinction Majuscules/Mininuscules pour les
//              noms de Frameworks passes en argument
//                    >> LoadComponent
//                    >> GetComponent
//                    >> AddPrereqComponent
//                    >> GetPrereqComponent
//                    >> AttachComponent
//                    >> GetAttachComponent
//
//       Modification   97/04/03                                      ADH
//           1- ajout d'un buffer pour le stockage de futures donnees 
//              de maniere a assurer compatibilite des cartes d'identite
//              dans la cas ou des donnees sont ajoutees a celles-ci
//
//       Modification   97/06/06                                      ADH
//           1- toutes les methodes sont virtuelles
//           2- definition de CATComponentPrereq et CATComponentAttach
//              dans des fichiers headers distincts + changement de type (struct -> class)
//           3- type enum ComponentType enrichi
//
//       Modification   97/06/27                                      ADH
//           1- ajout des methodes GetExtension
//
//       Modification   97/07/18                                      ADH
//           1- ajout de la methode ExtractName
//
//       Modification   97/07/21                                ADH/LBO
//           1- Encapsulation des valeurs de ComponentExport suite
//              a une collision sur le symbole Exported
//
//       Modification   99/06/23                                ADE
//           1- Chargement et format de la CI modifies
//
//-------------------------------------------------------------------------
// CATComponent :
//    Super-classe dont derive chacun des objets Carte d'Identite des Composants CNEXT
//--------------------------------------------------------------------------

#ifndef CATCOMPONENT_H
#define CATCOMPONENT_H

#include <stdio.h>

//
// --> Parametres de WINDOWS_NT
//

#if defined(__COMPONENTV2)
#define ExportedByCOMPONENTV2 DSYExport
#else
#define ExportedByCOMPONENTV2 DSYImport
#endif
#include "DSYExport.h"

//===================================================================
//                          IMPORTATION
//===================================================================

//!!!ADE NE SERT QUE POUR CI du type .DLL
//_____________________ macro GenerateIdentityCard
#include "CATIdentityMacro.h"
//!!!
#include "CATString.h"
#include <stdio.h>

#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:04:52 [Replace forward declaration of standard streams with iosfwd.h] **/
#include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class ostream;
#endif //_CAT_ANSI_STREAMS

//class CATTrace;

class CATSiList;

//===================================================================
//                          EXPORTATION
//===================================================================

class CATComponent;

/////////////////////////////////////////////////////////////////////
//
//                           CONSTANTES
//
/////////////////////////////////////////////////////////////////////


//
// NOM de composant CNEXT 
// ===
//
//        - longueur maximum (avec son eventuelle extension)
//
#define CATComponentNameLength       255
#define CATOptionNameLength          64

//
// TYPE du composant CNEXT
// ====
//
enum ComponentType
{
  ComponentType_NIL = 0,
  Code              = 1,   //   CATComponent -- FrameWork de Code
  Test,                    //   CATComponent -- FrameWork de Test
  Education,               //   CATComponent -- FrameWork d'Education
  Group,                   //   CATComponentGroup
  ProductInclude,          //   CATComponentProductInclude
  Product,                 //   CATComponentPackaging -- Produit Run Time
  ProductBuild,            //   CATComponentPackaging -- Produit Build Time
  ProductDoc,              //   CATComponentPackaging -- Produit de Doc
  ProductEdu,              //   CATComponentPackaging -- Produit de Formation
  Solution, 
  SolutionBuild,	      	//   CATComponentPackaging -- Solution
  Component,               //   CATComponentPackaging -- Composant
  Media                     //   CATComponentMedia
  };


//  
// MODE D'ACCES A UN COMPOSANT
// ===========================
//
//        ( interfaces PUBLIQUES = PublicInterfaces, PublicGenerated
//        ( interfaces PROTEGEES = ProtectedInterfaces, ProtectedGenerated
//        ( interfaces PRIVEES   = PrivateInterfaces, PrivateGenerated
//  
enum ComponentAccess 
{
  ComponentAccess_NIL = 0,
  Public              = 1, // acces aux interfaces PUBLIQUES
  Protected           = 2, // acces aux interfaces PUBLIQUES & PROTEGEES
  Private             = 3  // acces aux interfaces PUBLIQUES & PROTEGEES & PRIVEES
  };



//
//

enum ComponentCAAMode 
{
  ComponentCAAMode_NIL = 0,
  CustomerBuild        = 1, 
  RuntimeStability     = 2
  };




//  
// MODE D'EXPORT D'UN COMPOSANT
// ============================
//  

enum ComponentExport
{
  ComponentExport_NIL     = 0,  // 
  ComponentNotExported    = 1,  // pas d'export des interfaces du prerequis 
  ComponentExported       = 2,  // export des interfcaes du prerequis
  AddToClientPrereqs      = 3,
  DoNotAddToClientPrereqs = 4,
  AddToClientNotSpecified = 5
  };

enum ComponentExposePrereq
{
  DoNotExposePrereq        = 0,   
  ExposePrereq             = 1,  
  ExposePrereqNotSpecified = 2
  };

//  
// MATURITE du composant CNEXT
// ========
//
//         - attribut facultatif, en vue d'une utilisation future
//  
enum ComponentMaturity 
{
  ComponentMaturity_NIL = 0,
  M1                    = 1,              // Prototype
  M2                    = 2,              // Develeppement initial
  M3                    = 3,              // Disponibilite interne DS
  M4                    = 4,              // Disponibilite externe
  M5                    = 5               // Obsolescence
  };

//  
// EFFECTIVITE de debut/fin de support du composant CNEXT
// ===========
//
//         - attribut facultatif, en vue d'une utilisation future
//
enum ComponentEffectivity 
{
  ComponentEffectivity_NIL = 0,
  MIN                      = 1,
  FR1,
  FR2,
  FR3,
  FR4,
  FR5,
  FR6,
  FR7,
  FR8,
  FR9,
  MAX                      = 100
  };

/////////////////////////////////////////////////////////////////////
//
//                                CLASSE
//
/////////////////////////////////////////////////////////////////////


class ExportedByCOMPONENTV2 CATComponent  
{

  //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

public:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------

  //-------------------------------
  // Implementation
  //-------------------------------

  //
  // COMPILATION de la Carte d'Identite d'un composant
  // ==========
  //
  //       
  // static int CompilComponent       (const char*    ipIdCardHeaderPath_c,
  //                                 const char*    ipIdCardScriptDirPath_c,char* PreproBuffer=NULL);

  //
  // CHARGEMENT en memoire de la Carte d'Identite d'un composant
  // ==========
  //
  //!!!ADE NE SERT QUE POUR CI du type .DLL
  //       1- chargement en memoire de la Shared-Library associee
  //!!!ADE
  //       2- instanciation de l'objet carte d'identite CATComponent
  //       
  static CATComponent*  LoadComponent( const char*    ipComponentName_c,
												  const char*    ipIdCardLibPath_c,
												  int inMkmk = 0);

  //
  // DECHARGEMENT memoire de la Carte d'Identite d'un composant
  // ============
  //
  //!!!ADE NE SERT QUE POUR CI du type .DLL
  //       1- dechargement memoire de la Shared-Library associee
  //!!!ADE
  //       2- destruction de l'objet carte d'identite CATComponent
  //
  static int UnloadComponent( CATComponent * ipIdCardObject_o);

  //
  // DECHARGEMENT memoire de TOUTES les Cartes d'Identite chargees
  // ============
  //
  static int UnloadAllComponents (void);

  //
  // RECHERCHE en memoire d'un objet carte d'identite
  // =========
  //
  static CATComponent*  GetComponent(const char * ipComponentName_c);



  static int  GetFWScriptName ( const char * pProductICScriptPath, const char * FWName,
										 char** pIdCardScriptPath );

  static ComponentType  GetFWScriptType ( const char * ipComponentHeaderPath_c );


  //
  // CONSTRUCTION DE NOMS a partir du nom du composant
  // ====================
  //
  //!!!ADE NE SERT QUE POUR CI du type .DLL
  //       1- macro-identificateur de composant pour la macro GenerateIdentityCard
  //!!!ADE
  //       2- nom de la Shared-Lib/Script associee a la carte d'identite du composant
  //       3- path de la Shared-Lib/Script associe a la carte d'identite du composant
  //
  //!!!ADE NE SERT QUE POUR CI du type .DLL
  static char * MakeMacroIdent (const char * ipComponentName_c);
  //!!!ADE
  static char * MakeShLibName (const char * ipComponentName_c);

  static char * MakeShLibPath (const char * ipComponentName_c);

  //
  // EXTRACTION DU NOM D'UN COMPOSANT a partir du nom du la Shared-Lib associee
  // ================================
  //
  static int ExtractName (const char * ipShLibName_c, char * oaComponentName_c);

  //
  // CONTROLES ELEMENTAIRES des attributs de la carte d'identite
  // ======================
  //  
  //       1- longueur du nom d'un Composant CNEXT ( >= 1 & <= CATComponentNameLength)
  //
  static int CheckName (const char * ipComponentName_c);

  //
  static const char * GetExtension (const ComponentType iComponentType_e);

  //
  // TRACE de mise au point
  // =====
  // 
  //static int            SetTrace        (CATTrace*      ipTrace_o);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------

  //-------------------------------
  // Construction/Destruction
  //------------------------------- 

  //-------------------------------
  // Affectation des attributs
  //-------------------------------

  virtual int SetName (const char * ipComponentName_c); 

  virtual int SetBrand (const char * ipComponentBrand_c);

  virtual int SetCopyright (const char * ipCopyright_c); 

  virtual int SetType (const ComponentType iType_e);

  //
  // AJOUT D'UN COMPOSANT PREREQUIS dans la liste des composants prerequis
  // ==============================
  //
  // 21/07 modif de signature
  //
  virtual int AddPrereqComponent (const char * ipComponentName_c,
											 const ComponentAccess iAccess_e = Public,
											 const ComponentExport iExport_e = ComponentExport_NIL,
											 const ComponentExposePrereq iExpose_e = ExposePrereqNotSpecified);

  virtual int AddPrereqAuthorization (const char * ipComponentName_c,
												  const ComponentAccess iAccess_e = ComponentAccess_NIL,
												  const ComponentExport iExport_e = ComponentExport_NIL);

  virtual int AddSubDirectory (const CATString iSubDir, const ComponentAccess  iAccessLevel);
  //
  // AJOUT D'UN COMPOSANT ATTACHE dans la liste des composants attaches
  // ============================
  //
  //      - Permet d'attacher :
  //          * un composant de Test a un composant de Code
  //          * un composant de Test a un composant d'Education
  //          * un composant d'Education a un composant de Code
  //
  virtual int   AttachComponent    (const char* ipComponentName_c);

  virtual int   AttachCAAComponent (const char* ipComponentName_c);

  virtual int   SetAICPrefix       (const char* ipComponentName_c);

  virtual int   SetDescription     (const char* ipDescription_c);

  virtual int   SetSubOSBuildtime  (const char* ipSubOSBuildtime_c);



  virtual int   SetCAAMode         (ComponentCAAMode iCAAMode);

  virtual int   SetModelerPrefix   (const char* ipComponentName_c);


  virtual int   SetEffectivityMin  (const ComponentEffectivity iEffectivityMin_e);

  virtual int   SetEffectivityMax  (const ComponentEffectivity iEffectivityMax_e);

  virtual int   SetMaturity        (const ComponentMaturity iMaturity_e); 


  //-------------------------------
  // Lecture des attributs
  //-------------------------------

  virtual CATSiList * GetListPrereqAuthorization (void);
  virtual CATSiList * GetPurifyListPrereqComponent (CATString InstallConcat,CATString IDCardRTPath);

  virtual const char * GetName (void) const;

  int  IsInfra (void) { return _iIsInfra; };
  void SetInfra (int i) { _iIsInfra = i; };

  int  IsNotBuilt (void) { return _iIsNotBuilt; };
  void SetNotBuilt (int i) { _iIsNotBuilt = i; };
  int  IsNotTransitiveBuilt (void) { return _iIsNotTransitiveBuilt; };
  void SetNotTransitiveBuilt (int i) { _iIsNotTransitiveBuilt = i; };

  int  GetCheckOnPrereq (void) { return _NoCheckOnPrereq; };
  void SetCheckOnPrereq (int i){ _NoCheckOnPrereq = i; };


  int  IsCompanion (void) { return _iIsCompanion; };
  void SetCompanion (int i){ _iIsCompanion = i; };

  virtual const char* GetCopyright (void) const;

  virtual const char* GetAICPrefix (void) const;

  const char* GetDescription (void) const;

  virtual const char* GetSubOSBuildtime (void) const;


  virtual const ComponentCAAMode GetCAAMode (void) const;

  virtual const char* GetModelerPrefix (void) const;

  virtual const ComponentType GetType (void) const;

  virtual CATSiList* GetListPrereqComponent (void);

  virtual CATSiList* GetListPrereqToCheck (void);

  virtual CATSiList* GetListComponentSubDir (void);

  virtual CATSiList* GetListAttachComponent (void);

  virtual CATSiList* GetListAttachCAAComponent (void);

  virtual CATSiList* GetListOfBrand (void);

  virtual const ComponentEffectivity GetEffectivityMin (void) const;

  virtual const ComponentEffectivity GetEffectivityMax (void) const;

  virtual const ComponentMaturity GetMaturity (void) const;

  virtual void Display (const char*  ipTab_c, ostream& oOStream_o) const;


  //>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PROTECTED <<<<<<<<<<<<<<<<<<<<<<<<<<<<

protected:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------
  
  //-------------------------------
  // Implementation
  //-------------------------------
  static int  StripName (const char*  ipComponentName_c,
								 char oaComponentStripName_c [CATComponentNameLength + 2]);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------

  //-------------------------------
  // Construction/Destruction
  //------------------------------- 

  CATComponent (const char* ipComponentName_c);
  // 
  virtual ~CATComponent ();


  //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<

private:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------

  //!!!ADE NE SERT QUE POUR CI du type .SCR
  //
  // CREATION en memoire d'un composant
  // ========
  //
  //       
  static CATComponent*  CreateComponent(const char*    ipComponentName_c,
													 const char*    ipIdCardLibPath_c,
													 int inMkmk = 0);
  //!!!ADE


  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------

  //-------------------------------
  // Construction/Destruction
  //-------------------------------

  //   CATComponent (void);

  //   CATComponent (const CATComponent& iIdCardObject_o);

  //-------------------------------
  // Operateur
  //-------------------------------

  //   CATComponent& operator = ( const CATComponent& iIdCardObject_o);


  //---------------------------------------------------------
  // -> DONNEES DE CLASSE
  //---------------------------------------------------------

  // 
  // Liste des cartes d'identite chargees en memoire
  //
  //      1- Contient des objets CATComponentPackage
  //         (ie. objet carte d'identite + handler Shared-Lib associee)
  //      2- Est utilisee pour s'assurer que l'on ne charge
  //         en memoire qu'une seule fois la carte d'identite
  //         d'un composant CNEXT
  //
  static CATSiList * s_pListLoadedIdCard_o;

  //
  // Trace de mise au point
  //
  //      - par defaut, trace non active
  //


  //---------------------------------------------------------
  // -> DONNEES
  //---------------------------------------------------------

  //  
  // Nom du composant CNEXT (avec eventuelle extension)
  //
  char _aComponentName_c [CATComponentNameLength + 1] ;
  
  CATSiList * _pListSubDirectory_o;

  CATSiList * _pListOfBrand_o ;
  
  //  
  // Type du composant CNEXT 
  //  
  ComponentType _ComponentType_e ;

  //  
  // Liste des Composants Prerequis du composant CNEXT
  //  
  CATSiList * _pListPrereqComponent_o ;

  //  
  // Liste des Composants Authoriser a Prerequir le composant CNEXT
  //  
  CATSiList * _pListPrereqAuthorization_o ;

  //  
  // Liste des Composants Attaches du composant CNEXT
  //
  CATSiList * _pListAttachedComponent_o ;
  
  //  
  // Liste des Composants CAA Attaches du composant CNEXT
  //
  CATSiList * _pListAttachedCAAComponent_o ;

  //  
  // ATTRIBUTS NON EXPLOITES
  // =======================
  //
  //      - Effectivite de debut de support du composant CNEXT
  //      - Effectivite de fin de support du composant CNEXT
  //      - Maturite du composant CNEXT
  //  
  ComponentEffectivity  _ComponentEffectivityMin_e ; 

  ComponentEffectivity  _ComponentEffectivityMax_e ; 

  ComponentMaturity     _ComponentMaturity_e ;

  //  
  // POINTEUR SUR UN BUFFER pour l'extension des donnees de la Carte d'Identite
  // ======================
  //
  //      (pour assurer une compatibilite entre Cartes d'Identite
  //       en cas d'ajout de nouvelles donnees)
  //

  char * _pCopyright_c;

  char * _pDescription_c;

  char * _pSubOSBuildtime_c;

  char * _pAICPrefix_c;

  char * _pModelerPrefix_c;

  ComponentCAAMode _CAAMode;

  void * _pDataExtension_v ;

  int _iIsNotBuilt;
  int _iIsNotTransitiveBuilt;
  int _iIsInfra;
  int _iIsCompanion;
  int _NoCheckOnPrereq;

};

#endif

//
