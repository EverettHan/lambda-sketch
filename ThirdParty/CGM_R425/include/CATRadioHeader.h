// Copyright Dassault Systemes 1997
//-----------------------------------------------------------------------------
// Abstract: 
//-----------------------------------------------------------------------------
// Usage:    
//           
//-----------------------------------------------------------------------------
// Inheritance: CATRadioHeader
//                CATCommandHeader
//-----------------------------------------------------------------------------
// Main methods:    
//       
//-----------------------------------------------------------------------------
#ifndef CATRadioHeader_H
#define CATRadioHeader_H

#include "CATCommandHeader.h"
#include "CATAfrFoundation.h"
#include "CATDlgCheckItem.h"

class CATCmdStarter;
class CATDialog;
class CATCmdRep;
class CATLISTP(CATCommand);

#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATString.h"

class ExportedByCATAfrFoundation CATRadioHeader : public CATCommandHeader
{ 
  CATDeclareKindOf;
  
public:

   /** @nodoc */
  CATDeclareCBEvent(SET_RADIO_ICON);
  
  CATRadioHeader (const CATString &);
  CATRadioHeader (const CATString &, const int);
  virtual ~CATRadioHeader();
  
  virtual CATCommandHeader * Clone();
  
  virtual CATCommand * StartCommand();
  
  virtual CATCmdRep * CreateMenuRep(CATCmdStarter *, CATDialog *);
  virtual void        DestroyMenuRep(CATCmdStarter *);

  virtual CATCmdRep * CreateToolbarRep(CATCmdStarter *, CATDialog *);
  virtual void        DestroyToolbarRep(CATCmdStarter *);

  void SetSize(const int);
  
  void SetTitle(const CATUnicodeString &, const int);
  const CATUnicodeString &GetTitle(const int);

  void SetShortHelp(const CATUnicodeString &, const int);
  const CATUnicodeString &GetShortHelp(const int);

  void SetHelp(const CATUnicodeString &, const int);
  const CATUnicodeString &GetHelp(const int);

  void SetLongHelp(const CATUnicodeString &, const int);
  const CATUnicodeString &GetLongHelp(const int);

  void SetIconName(const CATString &, const int, int state = 0);
  const CATString &GetIconName(const int, int state = 0);


  virtual int GetSelected();
  virtual void SetSelected(int, int cmd = 1);
  void SetSelectedNoNotif(int, int cmd = 1);
  virtual void SetSelect(int, int cmd = 1);

  int GetSize();

  void SetState( CATULong nState, int nNotify=1);

  void BecomeAvailable();
  void BecomeUnavailable();

  void SetSensitivity(int num, CATULong iState);
  // Get button sensitivity at button creation. Could depend on represented object (see CATFrmRadioHeader for example)
  virtual CATULong GetInitialSensitivity(int num);
  
  virtual void        DestroyCtxMenuRep (CATCmdStarter *);

  CATDeclareCBEvent(RH_MODIFIED);

  virtual void AcceptVisitor(AfrICommandHeaderVisitor* i_pVisitor) override;

 protected:
  CATRadioHeader (CATCommandHeader *);
  int ResourcesRead();
  
private:
 int _readResources;
  
  void ReadResources();
  void ReadSettings();
  int GetResource(const CATString & key,
		  CATUnicodeString & resource);

  int GetResourceRsc(const CATString & key,
		  CATString & resource);

  int    _selected;
  int    _size;

  CATLISTP(CATCommand)   *   _repList;

  CATListOfCATUnicodeString  _titleList;

  CATListOfCATUnicodeString  _helpList;
  CATListOfCATUnicodeString  _shelpList;
  CATListOfCATUnicodeString  _lhelpList;

  CATListOfCATString         _NormalIconList;
  CATListOfCATString         _FocusedIconList;
  CATListOfCATString         _PressedIconList;

  CATDeclareHeaderResources;

};
#endif
