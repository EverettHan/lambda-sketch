/**
 * @level Protected
 * @usage U2
 */

// COPYRIGHT DASSAULT SYSTEMES 1995
//===================================================================
//
// CATIAEntity.h
// Header definition of CATIAEntity class
//
//===================================================================
//
// Usage notes:
//   This object is the basic C++ class for all V4 element.
//===================================================================
//
//  Mar 2004 Cleaning : OGM
//===================================================================

#ifndef CATIAEntity_h
#define CATIAEntity_h

#include "IUnknown.h"
#include "CATBaseUnknown.h"
#include "ExportedByCATIAEntity.h"
#include "DSYExport.h"

class ExportedByCATIAEntity CATIEntityAndUUID;
//  Quelques definitions prealables a la declaration CATIAEntity
// --------------------------------------------------------------

  class DSYImport CATIAPlug ;

class ExportedByCATIAEntity CATIAContainer ;
class ExportedByCATIAEntity CATIAModel ;
class ExportedByCATIAEntity CATIADescription ;
class ExportedByCATIAEntity CATIAEntity ;

#ifndef CATIAuuid_typedef_h
#define CATIAuuid_typedef_h
  typedef unsigned char CATIAuuid[16] ;  // typage externe des identificateurs uuid
#endif

// contraintes sur les modeles SDM stockees dans DATA
// ---------------------------------------------------
#define CATIASDMNameMax 128
typedef char CATIASDMName[CATIASDMNameMax];

// la manipulation des acces aux descriptions CATIA
// est facilitee par cette definition.
typedef struct
{
  int     Type ;
  int     Size ;
  double* Address ;
} CATIAData ;

// La manipulation des acces aux liens CATIA
// est faciliter par cette definition.
enum CATIATypeOfLink { indexTableNumpar=0, weakLink=1 } ;
enum AccessMode      { Direct=0, Next=1 } ;
enum UWLUpdate       { NotUpdated=0, Updated=1 } ;

typedef struct
{
  short     idlnk ;       // Identificateur UWL
  int       user_info ;
  UWLUpdate update ;
} UWL_id ;

typedef struct
{
  CATIATypeOfLink Type ;
  AccessMode      mode ;

  union Link
  {
    int    numpar ;            // Position du parent dans TP
    UWL_id weak ;
  } Address ;

  CATIAEntity* linked_entity ;
  int          IC_link_id ;      // Indice de liaison
} CATIALink ;

//  Lors d'un inventaire par la methode "Inventory"
//  on laisse la main a chaque entite.
// -------------------------------------------------
enum InventoryFilter{ noFilter=0, BreakLevel=1, FilterCurrent=2 } ;
typedef void CATIAEntityInventory( CATIAEntity* const current,
                                   const int          level,
                                   InventoryFilter&   filter ) ;

//  Parametres de la methode "Scan"
// ---------------------------------
enum ScanCriteria{ none=0, plugOnly=1, plugAlreadyGenerated=2, NonGenericNaming=3 } ;
enum ScanOrientation{ direct=+1, reverse=-1 } ;

struct TableOfUUID ;       // table de gestion des uuid.

//  Proprietes de Base
// --------------------
enum CATIABasicProperty{ Identifier=0, Layer=1, Visualization=2, Group=3, Filter=4 } ;


class ExportedByCATIAEntity CATIAEntity
{
  public:
    CATIAEntity( CATIAContainer* const set,
                 struct INDEX*         pindex ) ;
    virtual ~CATIAEntity() ;

    virtual void                  Dump( const int level=0,
                                        const int howmany=0 ) ;

    //  Parcours des entites avec possibilite de filtrage
    //  une valeur nulle signifie qu'on a trouve un element
    virtual int                   Scan( const ScanCriteria    criterion,
                                        CATIAEntity* const    previous,
                                        CATIAEntity*&         next,
                                        const ScanOrientation orientation=direct ) ;

    virtual CATIAEntity*          Duplicate( CATIAContainer* const father,
                                             const unsigned char&  lstand,
                                             const unsigned char&  withParent=1 ) ;
    void                          Clear_isDuplicated( const int level=0 ) ;

    CATIAEntity*                  GetContainer() ;

    //  Voici la methode recursive pour parcourir les constituants
    // ------------------------------------------------------------
    static void                   Inventory( CATIAEntity*const          entity,
                                             CATIAEntityInventory*const UserMethod,
                                             const int                  level,
                                             const ScanCriteria         C=none,
                                             const ScanOrientation      O=direct ) ;

    //  Pour s'y retrouver avec l'adressage relatif /JELE/
    // ----------------------------------------------------
    int                           GetJele() ;   // Obtention de l'adressage temporaire "JELE"

    //  Pour la manipulation du soft de base relatif a un modele en cours
    // -------------------------------------------------------------------
    CATIAModel*                   IsOfModel() ;   // Obtention du model contenant l'entite
    virtual void                  SetCurrent() ;  // Mise en cours du modele associe

    //  Pour la surcouche ObjectModeler
    // ---------------------------------
    int                           GetType( char* type,
                                           char* superType ) ;
    CATIAPlug*                    GetPlug() ;

    //Ajout vzy - 14/04/05
    CATBaseUnknown*               GetObject() ;
    HRESULT                       SetObject(CATBaseUnknown *iObject);

    // --------------------------------------------------------------------
    //  Gestion generale des liens CATIA :
    //   - GetLink :          pour acceder a la table parentale et aux UWL
    //   - GetNumberOfLinks : retourne le nombre de parents d'un element.
    // --------------------------------------------------------------------
    CATIAEntity*                  GetLink( CATIALink& link ) ;
    int                           GetNumberOfLinks( int& nbpar ) ;

    // --------------------------------------------------------------
    //  DataDefine : pour ajouter/modifier/supprimer une description
    //  une valeur de retour identifie la description dans le modele
    // --------------------------------------------------------------
    double*                       DataDefine( const int           TypeOfDescription,
                                              const int           SizeOfDescription,
                                              double* const       ValueOfDescription,
                                              int&                result,
                                              const unsigned char lvisu = 0x00 ) ;

    // --------------------------------------------------------------------
    //  **** ATTENTION : L'ADRESSE PHYSIQUE N'EST VALIDE
    //    TANT QU'ON NE MODIFIE PAS LE MODELE CATIA (AUTORESIZE DE MODELE)
    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    //  Gestion specialisee des descriptions CATIA
    //
    //  - DataAccess : pour adresser une description
    //
    //  - DataAccessSome, on fournit en entree/sortie un tableau CATIAData
    //    avec juste les types de descriptions recherchees.
    //    on valuera correctement (Size,Address) en fonction du resultat
    //    valeur de retour = nombre de descriptions recherchees/trouvees
    //
    //  - DataAccessAll,  on fournit un tableau de sortie qu'on remplira
    //    sans depasser sa limite avec les definitions de descriptions
    //     valeur de retour = nombre de descriptions portees par l'element
    // ----------------------------------------------------------------------
    double*                       DataAccess( const int TypeOfDescription,
                                              int&      SizeOfDescription ) ;

    int                           DataAccessSome( const int NumberOfDescription,
                                                  CATIAData descriptions[] ) ;

    int                           DataAccessAll( const int MaxNumberOfDescription,
                                                 CATIAData descriptions[] ) ;

    //  Services pour la gestion des proprietes basiques
    // --------------------------------------------------
    void                          GetBasicProperty( CATIABasicProperty name,
                                                    const int          Nbytes,
                                                    void*              value,
                                                    int&               NbytesFilled ) ;

    void                          SetBasicProperty( CATIABasicProperty name,
                                                    const int          Nbytes,
                                                    void*              value ) ;

    void                          ReadWindow( int&    itpwin,
                                              double  eye[3],
                                              double  direction[3],
                                              double  up[3],
                                              double& target_distance,
                                              double& angle,
                                              double& scale ) ;

    void                          ReadWspWindow( int&    itpwin,
                                                 double  eye[3],
                                                 double  direction[3],
                                                 double  up[3],
                                                 double& target_distance,
                                                 double& angle,
                                                 double& scale ) ;

    // ---------------------------------------------
    //  Services sur les identificateurs UNIVERSELS
    // ---------------------------------------------
    //  SetUUID :
    //  ---------
    //  Attention, si l'element porte deja un UUID,
    //  on change son UUID, il faut donc recuperer
    //  l'ancien UUID avant de faire un SetUUID.
    //  La remise a jour des liens est la charge de
    //  l'appelant
    // ---------------------------------------------
    int                           SetUUID( const CATIAuuid name ) ;  // Valeur <> 0 si probleme
    int                           GetUUID( CATIAuuid name ) ;        // Valeur == 0 si UUID inexistant
    static int                    UUID_locate( const CATIAuuid name,
                                               const int&      EntityMaxNumber,
                                               CATIAEntity*    EntityAdress[] ) ;
    static int                    UUID_locate( const CATIAuuid name,
                                               int      EntityMaxNumber,
                                               CATIAEntity*    EntityAdress[],
                                               CATBoolean iStopWhenMaxReached) ;
     // Methode de gestion pour le listener
    static HRESULT                RegisterUUIDEntityListener(CATIEntityAndUUID * &ipListener );
    static HRESULT                UnregisterUUIDEntityListener();
    int                           UUID_SetListener(const CATIAuuid name);

    // Le listener en Public pour CATIAPlug::Synchronize()
    static CATIEntityAndUUID * _piListener;

    //  Services internes pour la gestion de ExtendedData
    // ---------------------------------------------------
    int                           defineDatb( const int    itydes,
                                              const int    longueur,
                                              const double valeur[],
                                              double*&     adresse ) ;

    int                           adressDatb( const int itydes,
                                              double*&  adresse,
                                              int&      longueur ) ;

    int                           suppressDatb( const int itydes ) ;

    //  Mecanisme de gestion interne
    // ------------------------------
    void ResetPlug() ;

    //  Gestion des cles recursives pour les Liens Symboliques
    // --------------------------------------------------------
    static void*                  CodeKey( CATIAEntity* user,
                                           CATIAEntity* pointedObj,
                                           void*        temp,
                                           const int    sizeTemp,
                                           int&         sizeKey ) ;
    static int                    DecodeKey( const void*  keyInput,
                                             const int    sizeInput,
                                             const int    sizeEntities,
                                             CATIAEntity* entities[] ) ;

    //  Passage des CATIAEntity aux numele et inversement
    // ---------------------------------------------------
    int                           CodeNumele( int&          numele,
                                              CATIAEntity*& entitySet ) ;
    int                           DecodeNumele( const int     numele,
                                                CATIAEntity*& entityElt ) ;

    //  Gestion des references GenericNaming
    // --------------------------------------
    void                          IsUsedByGenericNaming( const int Yes1_or_No0 ) ;

    //  Services internes pour la gestion des UUID
    // --------------------------------------------
    static void                   UUID_dump() ;

  protected:
    // Services internes pour la gestion des UUID
    void                          UUID_recovery( const CATIAuuid name ) ;
    void                          UUID_delete() ;

    // Donnees membres systematiques sur l'entite
    CATIAModel*                   _IsOfModel ;
    CATIAPlug*                    _CatiaPlug ;
    // For the purely V5 CATIAEntities without plug
    CATBaseUnknown *              _CatiaObject ;
    int                           _Jele ;
public:
  unsigned char                  _PlugAlreadyUnstreamed:1;
protected:
    // Champ de bits, sur l'etat de l'entite
    unsigned char                 _PlugComputed : 1;  // determine la validite du Plug
    unsigned char                 _withUUID     : 1;  // determine si porteur d''UUID
    unsigned char                 _isDuplicated : 1;  // determine si deja duplique
    unsigned char                 _GenericNamed : 2;  // reference par generic Naming 0(non) 1(oui)

    CATIAuuid                     _Uuid;


    static CATIAModel*            _CurrentModel;

    // Pour le debug interne, un affichage de la boite blanche
    void                          GetAdress( struct JELE*&  pJele,
                                             struct INDEX*& pIndex,
                                             struct DATA*&  pData ) ;

    // Gestion de la Table de Duplication associee a _IsOfModel
    //  passage en Protected : OGM le 13/12/2002, pour le soft
    //  non recursif.
    CATIAEntity*                  GetCOPY( CATIAEntity* const cont ) ;
    void                          AddCOPY( CATIAEntity* const dupli ) ;

    HRESULT                       DuplicateLight( CATIAContainer* const father,
                                                  const unsigned char&  lstand,
                                                  CATIAEntity*&         oDuplicatedEntity,
                                                  const unsigned char&  withParent=1 ) ;
    // Never use this method.
    HRESULT                       DuplicateLightForFTA( CATIAContainer* const father,
                                                        const unsigned char&  lstand,
                                                        CATIAEntity*&         oDuplicatedEntity,
                                                        const unsigned char&  withParent=1 ) ;

  private:
    CATIADescription*             _ExtendedData ;

    // Donnees de session pour l'optimisation memoire des UUID
    static struct TableOfUUID*    _TableOfUUID ;  // Table de session des UUID
    static                int     _MaxUUID ;      // Nb maximum UUID sans reallocation
    static                int     _UsedUUID ;     // Nb de couple UUID-CATIAEntity

    // Les petits amis autorises a s'optimiser dans l'acces direct _Jele
    friend class CATIAContainer ;
    friend class CATIAModel ;
    friend class CATIAWorkspace ;

    // Un petit copain supplementaire pour jouer avec les tables
    // de duplication
    friend class CATEntityDuplicationManager ;

    //  Pour le codage de la cle recursive a partir de l'element pointe
    //  + Pour le decodage de la cle recursive jusqu'a l'element pointe
    // -----------------------------------------------------------------
    virtual void*                 CodeKeyOne( CATIAEntity* user,
                                              void*        temp,
                                              const int    sizeTemp,
                                              int&         sizeKey ) ;

    int                           DecodeKeyOne( const void*  keyInput,
                                                const int    sizeInput,
                                                const int    sizeEntities,
                                                CATIAEntity* entities[] ) ;
} ;

#endif
