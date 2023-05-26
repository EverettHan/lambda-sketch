#ifndef CATTrapSelectionManagerHeader_H
#define CATTrapSelectionManagerHeader_H

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "CATCommandHeader.h"
#include "CATAfrFoundation.h"

class CATViewer;

class ExportedByCATAfrFoundation CATTrapSelectionManagerHeader : public CATCommandHeader
{ 
  CATDeclareClass;
  
public:
  
  CATTrapSelectionManagerHeader (const CATString & iHeaderID);
  CATTrapSelectionManagerHeader (CATTrapSelectionManagerHeader * iHeader);
  virtual ~CATTrapSelectionManagerHeader();

//   CATCommand * StartCommand();
  virtual CATCommandHeader * Clone();

  HRESULT AddTrapHeader(const CATString & iHeaderID);
  HRESULT SetDefaultTrapHeader(const CATString & iHeaderID);

  HRESULT AddViewer(CATViewer * iViewer);
  HRESULT RemoveViewer(CATViewer * iViewer);
  

  void SetTrapChecked(const CATString & iHeaderID);
  void SetTrapUnchecked(const CATString & iHeaderID);
  
  void TrapSelectionBecomeAvailable();
  void TrapSelectionBecomeUnavailable();

  void StartTrapOnGeometry();
  void StopTrapOnGeometry();
  void SetRepeatTrapOnGeometry(CATBoolean iRepeat);

protected:
  CATTrapSelectionManagerHeader (CATCommandHeader *);
  
private:
  
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATTrapSelectionManagerHeader();
  CATTrapSelectionManagerHeader(const CATTrapSelectionManagerHeader &);
  CATTrapSelectionManagerHeader & operator= (const CATTrapSelectionManagerHeader &);

  void CommonInit();
  void CleanViewerList();
  void TrapDeleteCB(CATCallbackEvent, void * ,CATNotification *, CATSubscriberData , CATCallback);
  void ViewerActivatedCB(CATCallbackEvent, void* ,CATNotification* ,CATSubscriberData , CATCallback );
  void AccessChangedCB(CATCallbackEvent, void* ,CATNotification* ,CATSubscriberData , CATCallback );
  void UIActiveObjectToBeModifiedCB(CATCallbackEvent, void* ,CATNotification* ,CATSubscriberData , CATCallback );

  void ActivateCurrentTrap();



  CATSysWeakRef * LocateViewer(CATViewer * iViewer);

  CATListOfCATString _trapHeaderIDList;
  //  CATListPV * _viewerWeakRefList;

  CATCommand * _trapOnGeometryCmd;
  CATString _trapOnGeometryID;
  CATString _DefaultTrapID;
  int _nbChecked;
  CATBoolean _repeatTrapOnGeometry;
  CATBoolean _fromStartDefaut;

};
#endif
