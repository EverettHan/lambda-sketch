#ifndef UndoJournal_h
#define UndoJournal_h
#include "CATAfrFoundation.h"
//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 1998
//-----------------------------------------------------------------------------
// Abstract: Objet qui gère l'activité d'Undo du Journaling
//-----------------------------------------------------------------------------
// Usage:    Créé lorsqu'on passe en mode Journaling et détruit aussitot
//-----------------------------------------------------------------------------
// Inheritance: CATEventSubscriber
//-----------------------------------------------------------------------------
// Main methods: NewArticle
//   Responsable: EHT
//-----------------------------------------------------------------------------
#include "CATEventSubscriber.h"

#include "CATCommand.h"
#include "CATEventSubscriberTypedefs.h"

class CATIExecLog;
class CATNotification;

class ExportedByCATAfrFoundation UndoJournal : public CATEventSubscriber
{
  
public:
  
  UndoJournal (CATIExecLog * Object);
  virtual ~UndoJournal ();
  
  /*****************************************************************************/
  /*  NewArticle.  Méthode appelée par le Callback du Journaling               */
  /*  De manière à associer un article de Journal à une Transaction            */
  /*  De la pile d'undo de l'editeur courant.                                  */
  /*****************************************************************************/
  static UndoJournal * Begin(CATIExecLog * Object);
  static void End ();
  void NewArticle (CATCallbackEvent evt,
                   void              *FromClient,
                   CATNotification   *EvtData,
                   CATSubscriberData  data,
                   CATCallback        );
  
private:
  
  CATIExecLog * cmd;
  CATCallback Cb;
  static UndoJournal * Adress;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  UndoJournal ();
  UndoJournal (const UndoJournal &);
  UndoJournal & operator= (const UndoJournal &);
  
};

#endif
