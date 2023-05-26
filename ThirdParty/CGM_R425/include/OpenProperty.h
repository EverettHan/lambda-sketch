/**
 * @fullreview LBF-CMG CVE 01:08:31
 * @error MISC Y manque includes CATCallbackManager et CATBooleanDef
 * @error MISC Y manque class CATNotification
 * @error UDOO Y pas de constructeur par copie, d'operateur =
 * @error UDOO Y destructeur non virtuel
*/


#ifndef OpenProperty_H
#define OpenProperty_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATBooleanDef.h"
#include "CATCallbackManager.h"
#include "CATDlgResource.h"
#include "CATStateCommand.h"
#include "CATAfrProperties.h"
#include "CATBoolean.h"

class CATDialogAgent;
class CATFrmNotify; 
class CATPropertyDialog;
class CATCommandGlobalUndo;
class CATLISTP(CATCommandGlobalUndo);
class CATNotification;
class CATPathElement;


class ExportedByCATAfrProperties OpenProperty : public CATStateCommand
{
  
  CATDeclareClass;
  DeclareResource(OpenProperty, CATStateCommand)
    
 public:

  CATDeclareCBEvent(NotifyIsEmitted);
  CATDeclareCBEvent(OKProperties);

  OpenProperty();
  virtual ~OpenProperty();
  virtual void BuildGraph();
  
  CATCommandGlobalUndo * GetGlobalUndo ();
  static void Undo(void *);
  static void Redo(void *);
  static void Clean(void *);
  

 private:
  
  // Copy constructor (not implemented)
  OpenProperty(const OpenProperty&);
  
  // Assignment operator (not implemented)
  OpenProperty& operator=(const OpenProperty&);

  CATLISTP(CATCommandGlobalUndo) * _UndoData;
  
  int _WarnIsEmitted;
  int _First;
  int _NewPath;
  static int _NoDeletion;
  CATBoolean _nothingSelected;
  
  static CATPropertyDialog * _dialog;
  CATFrmNotify * _notify;
  CATDialogAgent * _ok, * _apply, * _close, * _help, * _wng;
  
  CATCallbackManager * _cbManager;
  CATCallback _callback;
  CATPathElement * _pathElement;
  
  boolean PropertyOK(void *);
  boolean PropertyAPPLY(void *);
  boolean PropertyCANCEL(void *);
  boolean WarningDisplayed(void *);
  boolean SetLongHelpId(void *);

  void WarningEmitted(CATCallbackEvent iPublishedEvent,
                      void * iPublishingObject,
                      CATNotification * iNotification,
                      CATSubscriberData iClientData,
                      CATCallback iCallback);

};
#endif
