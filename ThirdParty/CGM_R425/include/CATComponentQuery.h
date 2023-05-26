//-------------------------------------------------------------------------
//
// COMPOSANT : System
//
//-------------------------------------------------------------------------
// Ensembles de queries sur les cartes d'identites
//
// PREREQUIS :
// -----------
//    Appel aux services d'initialisation/terminaison de System
//    qui permettent d'acceder aux services de parcours de repertoire portables
//       . Appel de CATStartLibServices () avant toute utilisation
//       . Appel de CATStopLibServices () apres derniere utilisation
//
//--------------------------------------------------------------------------

#ifndef CATCOMPONENTQUERY_H
#define CATCOMPONENTQUERY_H


// COPYRIGHT DASSAULT SYSTEMES 2000

//
// --> Parametres de WINDOWS_NT
//

#if defined(__COMPONENTV2)
#define ExportedByCOMPONENTV2 DSYExport
#else
#define ExportedByCOMPONENTV2 DSYImport
#endif
#include "DSYExport.h"

//-------------------------------------------------------------------------
// IMPORTS ET REFERENCES
//------------------------------------------------------------------------- 

class CATSiList;
class CATTrace;

//_________________ enums
#include "CATComponent.h"
//_________________ liste d'objets CATAuthorizedComponent
#include "CATAuthorizedComponentLstV.h"


//-------------------------------------------------------------------------
// DEFINITION DE LA CLASSE CATComponentQuery 
//-------------------------------------------------------------------------

class ExportedByCOMPONENTV2 CATComponentQuery
{

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  public:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------
  
       // Activation des traces de mise au point (inactive par defaut)
//    static int     SetTrace                  (CATTrace*      ipTrace);

       //
       // NOTE
       // ----
       // 
       //     1- Les methodes de requetes suivantes chargent en memoire des cartes d'identite.
       //        Le dechargement de ces cartes d'identite est a la charge de l'APPELANT.
       //                                                                      ========
       //        >> Invoquer la methode de classe "CATComponent::UnloadAllComponents" 
       //           lorsque l'appelant en a fini avec toutes ses requetes
       //
       //     2- La memoire dynamique referencee dans les listes retournees 
       //        par les methodes ci-dessous doit etre aussi liberee par l'APPELANT.
       //        
       //        >> Invoquer la methode "ApplyFree" pour chaque de ces objets liste
       //
       //     3- La valeur de retour de ces methodes correspond a un code d'erreur
       //        dont les valeurs sont definies dans l'enum Error ci-dessous
       //
       //        >>  0: pas d'erreur; <0: erreur
       //
       //     4- Les methodes de requetes retournent un parametre 'Liste d'erreurs detectees'
       //        (echec chargement de carte d'identite d'un composant) -- cet objet liste contient
       //        des objets erreur (CATComponentErr) alloues dynamiquement -- l'appelant
       //        doit liberer cette memoire
       //
       //        >> Invoquer la methode de classe "CATComponentErr:ApplyDelete" 
       //           avec cet objet liste en argument
       //
       //      5- Gestion de la concatenation de plusieurs runtime-view
       //

       //___________________________________________________________________
       // Obtenir tous les frameworks autorises d'un produit ou d'une solution 
       // en resolvant les groupes, produits & solutions autorises.
       //
       // ipPkgCmpName          : nom de produit/solution
       // ipConcatRtViewPath    : directory RuntimeView de cartes d'identite ou trouver 
       //                         TOUTES les cartes d'identite de produits/solutions/
       //                         groupes/frameworks 
       // oAuthorizedFrwLstP    : liste de noms de frameworks autorises (avec filtrage des doublons)
       // oCmpErrorLstP         : liste des erreurs detectees
       //___________________________________________________________________
    static int     GetAllAuthorizedFrameworks (const char*                       ipPkgCmpName,
					       const char*                       ipConcatRtViewPath,
					       CATAuthorizedComponentLstV&       oAuthorizedFrwLstV,
					       CATSiList*                        oCmpErrorLstP = 0);


   static int     GetAllIncludedFrameworks(const char*                       ipPkgCmpName,
											const char*                       ipConcatRtViewPath,
											CATSiList&                       oIncludedFrwLstV,
											CATSiList*                        opCmpErrorLstP);

       //___________________________________________________________________
       // Obtenir tous les produits autorises (directement ou indirectement)
       // par un produit/une solution (les frameworks/groupes sont ignores).
       //
       // ipPkgCmpName          : nom de produit/solution
       // ipConcatRtViewPath    : directory RuntimeView de cartes d'identite ou trouver 
       //                        TOUTES les cartes d'identite de produits/solutions/
       //                        groupes/frameworks 
       // oAuthorizedPrdLstP   : liste des noms de produits autorises (avec filtrage des doublons)
       // oCmpErrorLstP        : liste des erreurs detectees
       //___________________________________________________________________
  static int     GetAllAuthorizedProducts (const char*  ipPkgCmpName,
                                           const char*  ipConcatRtViewPath,
					   CATSiList&   oAuthorizedPrdLstP,
					   CATSiList*   oCmpErrorLstP = 0);

  static int     GetAllIncludedHeaders (const char*  ipPkgCmpName,
                                           const char*  ipConcatRtViewPath,
					   CATSiList&   oIncludedInterLstP,
					   CATSiList*   oCmpErrorLstP = 0);


 static int     GetAllAuthorizedOptions (const char*  ipPkgCmpName,
                                           const char*  ipConcatRtViewPath,
					   CATSiList&   oAuthorizedPrdLstP,
					   CATSiList*   oCmpErrorLstP = 0);

 static int     GetAllAllowedWorkbench (const char*  ipPkgCmpName,
                                           const char*  ipConcatRtViewPath,
					   CATSiList&   oAuthorizedPrdLstP,
					   CATSiList*   oCmpErrorLstP = 0);

       //___________________________________________________________________
       // Obtenir tous les produits prerequis (directement ou indirectement)
       // par un produit.
       //
       // iPrdCmpName          : nom de produit
       // ipConcatRtViewPath   : directory RuntimeView de cartes d'identite ou trouver 
       //                        TOUTES les cartes d'identite de produits/solutions/
       //                        groupes/frameworks 
       // oPrereqPrdLstP       : liste des noms de produits prerequis (avec filtrage des doublons)
       // oCmpErrorLstP        : liste des erreurs detectees
       //___________________________________________________________________
  static int     GetAllPrereqProducts     (const char*  iPrdCmpName,
                                           const char*  ipConcatRtViewPath,
					   CATSiList&   oPrereqPrdLstP,
					   CATSiList*   oCmpErrorLstP = 0);

       //___________________________________________________________________
       // Obtenir la liste des noms de frameworks/groupes/produits/solution par analyse
       // du contenu d'un directory RuntimeView de cartes d'identite.
       //
       // ipConcatRtViewPath   : directory RuntimeView de cartes d'identite ou trouver 
       //                        TOUTES les cartes d'identite de produits/solutions/
       //                        groupes/frameworks 
       // iComponentType       : type de composant a recenser: framework/groupe/produit/solution
       // oComponentNameLstP   : liste des noms de composants
       //___________________________________________________________________
  static int     ReadRuntimeView          (const char*          ipConcatRtViewPath,
                                           const ComponentType  iComponentType,
					   CATSiList&           oComponentNameLstP);


       //------------------------------
       // Localiser la carte d'identite d'un composant dans une concatenation de runtime-view.
       //
       // ipConcatRtViewPath   : directory RuntimeView de cartes d'identite ou trouver 
       //                        TOUTES les cartes d'identite de produits/solutions/
       //                        groupes/frameworks 
       // ipComponentName      : nom du composant
       // opRtViewPath         : buffer contenant le path de la carte d'identite 
       //                        (taille du buffer CATMaxPathSize) - 
       //                        contient la chaine "" si non trouve
       //------------------------------
  static int     GetRtViewPath            (const char*           ipConcatRtViewPath,
					   const char*           ipComponentName,
					   char*                 opRtViewPath);

  //---------------------------------------------------------
  // -> CONSTANTES DE CLASSE
  //---------------------------------------------------------

    enum Error  // code d'erreur retourne par les methodes 
    {
       p_Error_NIL                      = 0,
       p_Error_COMP_TYPE                = -1,
       p_Error_IDCARD_LOAD              = -2,
       p_Error_ARGUMENT                 = -3,
       p_Error_MEM_ALLOC                = -4,
       p_Error_IO                       = -5
    };

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  private:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------
 
       //------------------------------
       // gestion des listes CATSiList
       //------------------------------

    static int     Append                  (const char*           ipCmpName_c,
					    CATSiList&            oCmpNameLstP_o);
    static int     Locate                  (const char*           ipCmpName_c,
					    CATSiList&            iCmpNameLstP_o);
    static int     Delete                  (const int             iCmpType_n,
					    CATSiList&            ioCmpNameLstP_o);
      //---
      //--- NOUVELLE VERSION
      //---
    static int     Delete                  (const int                    iCmpType_n,
					    CATAuthorizedComponentLstV&  ioAuthorizedCmpLstV_o);

       //------------------------------
       // implementation des requetes avec appel recursif
       //------------------------------

    static int     GetAggregatedFrameworks (const char*           ipGrpName_c,
					    CATSiList&            oAuthorizedFrwLstP_o);
    static int     GetAuthorizedFrameworks (const char*                 ipPkgName_c,
					    CATAuthorizedComponentLstV&  oAuthorizedFrwLstV_o);

	static int     GetIncludedFrameworks (const char*                 ipPkgName_c,
					    CATSiList&  oIncludedFrwLstV_o);

    static int     GetAuthorizedProducts   (const char*           ipPkgName_c,
					    CATSiList&            oAuthorizedPrdLstP_o);
	static int     GetAuthorizedOptions   (const char*           ipPkgName_c,
					    CATSiList&            oAuthorizedPrdLstP_o);
	static int     GetAllowedWorkbench   (const char*           ipPkgName_c,
					    CATSiList&            oAuthorizedPrdLstP_o);
    static int     GetPrereqProducts       (const char*           ipPrdName_c,
					    CATSiList&            oPrereqPrdLstP_o);
	 static int    GetIncludedHeaders       (const char*           ipPrdName_c,
					    CATSiList&            oPrereqPrdLstP_o);


  //---------------------------------------------------------
  // -> CONSTANTES DE CLASSE
  //---------------------------------------------------------

    static const char*    s_pMultiPathSep_c;

  //---------------------------------------------------------
  // -> DONNEES DE CLASSE
  //---------------------------------------------------------

    //static CATTrace*      s_pTrace_o;
};



#endif



