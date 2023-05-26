/**
 * @fullreview SCA-CMG cmg 02:12:02
 * @error MISC Y manque constrcuteurs par defaut, copie et operateur =
 * @error MISC Y manque certaines instructions class et include
*/


/* -*-C++-*- */
// Copyright Dassault Systemes 1998     
//-----------------------------------------------------------------------------
#ifndef CATVisuModeHeader_H
#define CATVisuModeHeader_H

#include "CATAfrFoundation.h"

#include "CATFrmRadioHeader.h"
#include "CATEventSubscriberTypedefs.h"

class CATCmdStarter;
class CATCmdRep;
class CATCommandHeader;
class CATDialog;
class CATLISTP(CATCommand);
class CATNotification;
class CATString;


class ExportedByCATAfrFoundation CATVisuModeHeader : public CATFrmRadioHeader
{ 
  CATDeclareKindOf;
  
public:
  CATVisuModeHeader (const CATString &);
  virtual ~CATVisuModeHeader();
  
  virtual CATCommandHeader * Clone();  
  
  virtual CATCmdRep * CreateMenuRep(CATCmdStarter *, CATDialog *);
  virtual void        DestroyMenuRep(CATCmdStarter *);

  virtual CATCmdRep * CreateToolbarRep(CATCmdStarter *, CATDialog *);
  virtual void        DestroyToolbarRep(CATCmdStarter *);

  virtual void DoShow();
  virtual void DoHide();

protected:
  CATVisuModeHeader (CATCommandHeader *);
  
private:     
  // Default constructor (not implemented)
  CATVisuModeHeader();

  // Copy constructor (not implemented)
  CATVisuModeHeader(const CATVisuModeHeader&);
  
  // Assignment operator (not implemented)
  CATVisuModeHeader& operator=(const CATVisuModeHeader&);

  CATLISTP(CATCommand) * _repList;

  int _CBAdded;

  void AddCB();
  void RemoveCB();
  void SetAvailability(int available=0, int item=0);
  void Transition(CATCommandHeader * header);
 void DbClkCB(CATCallbackEvent event, void * sender, CATNotification * notif, CATSubscriberData data, CATCallback);

  void AvailabilityCB(CATCallbackEvent event, void * sender, CATNotification * notif, CATSubscriberData data, CATCallback);

  CATDeclareHeaderResources;
};
#endif
