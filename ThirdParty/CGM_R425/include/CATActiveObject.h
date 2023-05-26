#ifndef CATActiveObject_H_ 
#define CATActiveObject_H_
/**
 * @fullreview ERS-DBN 01:09:05
 * @error MISC N err_1 constr par defaut, copy constr et opeateur = manquent
 * @error MISC Y err_2 include CATIAV5Level inutile
 * @error MISC Y err_3 includes CATEventSubscriberTypedefs et IUnknown ajoutes
**/

#include "CATAfrFoundation.h"
//
// COPYRIGHT DASSAULT SYSTEMES 1996
//------------------------------------------------------------------------------
// Abstract: Object to handle the active object of an editor  
//
//------------------------------------------------------------------------------
// Usage:    Each Editor will have its own active object
//
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
// Main methods:    
//
//           SetActivePath()
//           GetActivePath()
//           GetUIActiveObject()
//       
//------------------------------------------------------------------------------
//       
class CATFrmEditor;

#include "CATEventSubscriber.h"
#include "CATEventSubscriberTypedefs.h"
#include "IUnknown.h"
#include "CATPathElement.h"
#include "CATInPlaceSite.h"
#include "CATBoolean.h"

class CATActiveObjectVisuController;

class CATActivationContext;
class CATStackableCommandSet;

// Trace le contenu d'un CATPathElement
void  ExportedByCATAfrFoundation TracePathElement (CATPathElement pel);

class ExportedByCATAfrFoundation CATActiveObject: public CATEventSubscriber {
 public:

  CATDeclareClass;

  // Constructor / Destructor
  // ------------------------
  CATActiveObject(CATFrmEditor   * editor );
  virtual ~CATActiveObject();
  
  // Management of the UIActive object
  // ---------------------------------
  virtual void                 SetUIActiveObject   (CATPathElement&);
  virtual HRESULT              SetActivePath       (CATPathElement * iPathElement);
  // deprecated
  virtual void                 SetActivePath       (CATPathElement &);

  // rend le chemin dans sa totalite
  virtual CATPathElement     & GetUIActiveObject   (void);

  // rend le chemin uniquement jusqu'a l'objet UIActif
  virtual CATPathElement     & GetActivePath       (void);
  virtual CATInPlaceSite_var   GetActivationSite   ();
  virtual CATInPlaceSite_var   GetDeactivationSite ();
  
  // le renvoie TRUE si le chemin uiactif vient de changer
  CATBoolean                   HasUIActiveObjectChanged () const;    
  void                         NotifyNewUIActiveObject  ();

  // gestion des workbench empiles
  CATBoolean                   StackObject        (CATPathElement * object, 
                                                   CATStackableCommandSet *, const 
                                                   CATString & workbench);
  CATBoolean                   UnstackObject      ();
  CATBoolean                   IsObjectStacked    () const;
  void                         CancelStackedObject();

  // Internes et temporaires pour la gestion du contexte transactionnel
  virtual void                 SetUIActiveObjectFromContext (CATPathElement&);
  virtual HRESULT              SetActivePathFromContext (CATPathElement * iPathElement, CATBoolean iObjectEdition=TRUE);
  virtual void                 SetActivePathFromContext (CATPathElement &, CATBoolean iObjectEdition=TRUE);

  void SetDefaultUIActivationSite (CATBaseUnknown *UISite);


private:

  HRESULT                      CanUIActivate   (CATPathElement &, CATFrmEditor **);

  void OnWorkbenchChanged (
    CATCallbackEvent, void *, CATNotification *,
    CATSubscriberData data, CATCallback
    );

  // chemin actif total
  CATPathElement          _UIActivePath;

  // chemin allant jusqu'au dernier objet UIActif regissant l'atelier
  CATPathElement          _UIActiveObject;

  CATFrmEditor          * _Editor;

  CATBoolean                 _UIActiveObjectChanged;
  
  CATActiveObjectVisuController * _visuController;

  // gestionnaire d'object ui-actifs empiles
  CATActivationContext  * _context;

  IID                     _siteVetoItf;

  CATBaseUnknown        * _defaultUIActivationSite;
}; 
#endif
