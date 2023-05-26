#ifndef __CATFrmActivateHeader_h
#define __CATFrmActivateHeader_h

// COPYRIGHT DASSAULT SYSTEMES 2000


#include "CATCommandHeaderWithCSO.h"
#include "CATAfrFoundation.h"
#include "CATBoolean.h"
#include "CATRepParams.h"
#include "CATListOfCATRepParams.h"
#include "CATIContextualSubMenu.h"
#include "CATCommand.h"
#include "CATLISTP_CATBaseUnknown.h"

class CATCmdAccess;
class CATCmdRep;
class CATDlgSubMenu;
class CATCmdStarter;
class CATPathElement;
class CATFrmActivateCommand;
class CATCsoNotification;
class CATDocument;
class CATIAfrOpenInNewWindow;

// Header specialise, permettant la gestion dynamique
// des reps de menu contextuels. Ce header aggrege une 
// liste de rep pour mettre en oeuvre cette gestion.
//----------------------------------------------------
class ExportedByCATAfrFoundation CATFrmActivateHeader: public CATCommandHeaderWithCSO {

  CATDeclareClass;
  friend class CATSelect;

 public:

  // constructeurs
  CATFrmActivateHeader (const CATString&  hdrId);

  // destructeur
  virtual                    ~CATFrmActivateHeader ();
  
  // cree une copie du header
  CATCommandHeader         * Clone                 ();
  

  // callback changement de workbench
  void OnWorkbenchChanged (CATCallbackEvent iPublishedEvent, void* iPublishingObject, CATNotification* iNotification, CATSubscriberData iClientData, CATCallback iCallback);

  // methode la plus importante
  virtual void               CheckCSO              (CATCSO*);
  
  // Surcharge des methode de CATCommandHeader. Elles
  // permettent la creation des rep customisee
  virtual CATCmdRep        * CreateMenuRep         (CATCmdStarter * item, CATDialog * parent);
  virtual void               DestroyMenuRep        (CATCmdStarter *);
  
  virtual CATCmdRep        * CreateCtxMenuRep      (CATCmdStarter * item, CATDialog * parent);
  virtual void               DestroyCtxMenuRep     (CATCmdStarter *);

  virtual CATCmdRep        * CreateToolbarRep      (CATCmdStarter * item, CATDialog * parent);

  // methodes factorisant le code de 
  // Destroy[Ctx]MenuRep et Create[Ctx]MenuRep.
  CATCmdRep                * DoCreateMenuRep       (CATCmdStarter *, CATDialog *, CATKindOfRep);
  void                       DoDestroyMenuRep      (CATCmdStarter *, CATKindOfRep);
  
  // intitule du header : "<Xxxx> object"
  const CATUnicodeString   & GetHeaderTitle        (CATUnicodeString & oHdrTitle);

  // nom de l'action a effectuer sur cet 
  // objet : "Edit" ou "Definition ..."
  const CATUnicodeString   & GetActionName         () const;
  
  // surcharge de BecomeAvailable et BecomeUnavailable
  // pour pouvoir gerer la disponibilite des reps
  virtual void               BecomeAvailable       ();
  virtual void               BecomeUnavailable     ();
  
  // ajoute la desactivation de la  
  // commande avant son lancement
  virtual CATCommand       * StartCommand          ();

  // recuperer le _currentPath
  const CATPathElement     * GetCurrentPath        () const;

  // le chemin courant contient-il un objet activable ?
  CATBoolean                    IsPathActivable       () const;

  // Le chemin courant contient-il un document à ouvrir dans une nouvelle fenêtre ?
  CATBoolean                    WithOpenInNewWindow() const;

  // Recherche d'un document à ouvrir dans sa nouvelle fenêtre
  CATDocument *GetDocToOpenInNewWindow(CATPathElement &iPathElement, const CATDocument *ipCurEdtrDoc); // Aucun AddRef() n'est exécuté sur le document retourné

  // Modèle de sous-menu contextuel fabriqué lors de la dernière modification du CSO
  CATCmdAccess             * GetTopClientAccess();


protected:
  
  CATFrmActivateHeader (CATFrmActivateHeader *);

  // get a contextual menu interface
  CATIContextualSubMenu    * QueryContextualMenu   (CATBaseUnknown *, IID * = 0);

  // destruction / creation effective des reps.
  // methodes appelees par Create / DestroyRep
  virtual CATCmdRep        * DoCreateRep           (CATRepParams *);
  virtual void               DoDestroyRep          (CATRepParams *);

  // modification du titre de la menu rep sur chgt du CSO
  void                       UpdateReps            ();
  
  // mise a jour de la valeur de _currentAlias et _actionName
  CATBoolean                    SetCurrentProperties  (CATBaseUnknown *, CATPathElement * = 0);

  // mise a jour de la valeur de _currentAlias et _actionName
  void                       SetMultiSelProperties (CATCSO *);

  // mettre a jour le chemin vers l'objet courant
  void                       SetCurrentPath        (CATPathElement *);

  // initialisation. appele par le constructeur
  void                       InitHeader            (const CATFrmActivateHeader * = 0);

  // ressources NLS: intitules "Edit", "Definition...", "<Xxxx> object"
  CATUnicodeString           _nlsEditString;
  CATUnicodeString           _nlsDefinitionString;
  CATUnicodeString           _nlsMultiSelString;
  CATMsg                     _nlsObjectMsg;
  
  // charger les ressources NLS depuis un fichier
  void                       LoadHeaderNLSStrings  ();

  // tracer les erreurs de chargement du catalogue
  CATBoolean                    CheckNLSMsgKey        (CATMsg&, CATString&) const;


private:

  // Recherche d'un objet à ouvrir dans sa nouvelle fenêtre
  // Le HRESULT traduit le fait qu'on trouve ou pas une adhesion a CATIAfrOpenInNewWindow
  // Le pointeur traduit le fait qu'un objet accepte de s'editer ou pas
  static HRESULT GetObjectToOpenInNewWindow(CATPathElement &iPathElement, CATIAfrOpenInNewWindow *&oPIAfrOpenInNewWindow); // ne pas oublier de releaser le pointeur retourne apres usage
  
  // callback destruction de la commande
  void DeleteCB (CATCallbackEvent     evt,
                 void               * sender,
                 CATNotification    * Notification,
                 CATSubscriberData    data,
                 CATCallback          id);

  // intitule de l'action a executer sur l'objet courant
  // du CSO. Vaut "Definition ..." ou "Edit"
  CATUnicodeString           _actionName;

  // alias de l'objet courant du CSO
  CATUnicodeString           _currentAlias;
                
  // container qui devra etre rempli par le client
  CATCmdAccess             * _topClientAccess;

  // path element de l'objet presentant son
  // menu contextuel
  CATPathElement           * _currentPath;

  // ce flag indique si le _currentPath contient
  // un objet activable dans sa feuille (oui = TRUE)
  CATBoolean                    _isPathActivable;

  CATBoolean                    _WithOpenInNewWindow; // TRUE -> au moins un document peut être ouvert dans sa nouvelle fenêtre

  // ce flag indique si ls cso contient plus
  // d'un element
  CATBoolean                    _isMultiSel;

  // liste de parametres de reps permettant
  // la gestion de la multi-representation
  CATListOfCATRepParams      _repParamsList;

  // IID de l'interface a utiliser pour recuperer
  // le menu sous menu contextuel.
  IID                        _ctxSubMenuIID;

  // pointeurs vers l'interface CATIContextualSubMenu
  // de la selection courante du CSO
  CATLISTP (CATBaseUnknown)    _ctxSubMenu;

  // Vide la liste _ctxSubMenu (et Release ses elements)
  void ResetCtxSubMenu();

  // methode permettant d'oter de la liste l'element
  // contenant le starter passe en argument
  CATRepParams             * RemoveParamsFromList  (CATCmdStarter *, CATKindOfRep);

  // rappelle le client sur CATIContextualSubMenu::GetContextualSubMenu
  // pour mettre a jour la liste d'access du sous menu contextuel
  void                       UpdateClientAccess    ();

  CATDeclareHeaderResources;

  // gdx - RI 239391, 239168. Le problème est que lorqu'on déclenche
  // une commande par menu contextuel cette commande peut avoir pour
  // effet de modifier le CSO donc de détruire le menu contextuel à
  // cause de sa remise à jour dans la méthode CheckCSO. Comme la destruction
  // du menu est faite par un delete on obtient un core dump car l'élément
  // de menu est détruit trop tot. Pour éviter cela on "gèle" l'action de 
  // CheckCSO tant que le menu contextuel est ouvert, c'est-à-dire lorsque
  //  FreezeCheckCSO vaut 1.
  // (NB : remplacer le delete par un RequestDelayedDestruction résoud ce
  //       problème en particulier mais génère d'autres pb ailleurs)
  CATBoolean _FreezeCheckCSO;

  void SetEditorToNullWhenClosed(CATCallbackEvent  iEvent, 
                                                   void            * iFrom,
                                                   CATNotification * iNotification,
                                                   CATSubscriberData iClientData,
                                                   CATCallback       iCallBack );

};

#endif//__CATFrmActivateHeader_h
