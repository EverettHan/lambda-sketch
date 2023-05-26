//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011/09/28
//===================================================================
// CATVidMdlEventEmitter.h
// Header definition of class CATVidMdlEventEmitter
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/09/28 Creation: Code generated by the 3DS wizard  VV6
//===================================================================

#ifndef CATVidMdlEventEmitter_H
#define CATVidMdlEventEmitter_H

#include <VisuDialog.h>
#include <CATBaseUnknown.h>
#include <CATVidMdlIndex.h>
#include <CATSYPEventArgs.h>
#include <CATSYPPropertiesChangedEventArgs.h>

class CATSYPEvent;
class CATSYPEventHandler;
class CATSYPEventHandlersSupport;
class CATSYPEventFactory;

class ExportedByVisuDialog CATVidMdlEventItemAddArgs : public CATSYPEventArgs
{
  CATDeclareClass;
public:
  CATVidMdlEventItemAddArgs(CATSYPEvent * i_pEvent, CATVidMdlIndex i_index);
  virtual ~CATVidMdlEventItemAddArgs();

  CATVidMdlIndex GetAddedItem() const;

private:
  CATVidMdlEventItemAddArgs(const CATVidMdlEventItemAddArgs &);
  CATVidMdlEventItemAddArgs & operator= (const CATVidMdlEventItemAddArgs &);

  CATVidMdlIndex _addedItem;
};

class ExportedByVisuDialog CATVidMdlEventItemDataModifiedArgs : public CATSYPPropertiesChangedEventArgs
{
  CATDeclareClass;
public:
  CATVidMdlEventItemDataModifiedArgs(CATSYPEvent * i_pEvent, CATVidMdlIndex i_index, const CATSYPHashMap<CATUnicodeString, CATBaseUnknown_var> & i_modifiedProperties, int i_columnIndex);
  virtual ~CATVidMdlEventItemDataModifiedArgs();

  CATVidMdlIndex GetModifiedItem() const{  return _modifiedItem;}
  int GetColumnIndex() const{return _columnIndex;}

private:
  CATVidMdlEventItemDataModifiedArgs(const CATVidMdlEventItemDataModifiedArgs &);
  CATVidMdlEventItemDataModifiedArgs & operator= (const CATVidMdlEventItemDataModifiedArgs &);

  CATVidMdlIndex _modifiedItem;
  int _columnIndex;
};
/**
 * CATVidMdlEventEmitter must inherit from CATBaseUnknown to be able
 * to be the root of event dispatching.
 */
class ExportedByVisuDialog CATVidMdlEventEmitter : public CATBaseUnknown
{
  CATDeclareClass;

public:
  /** Default constructor */
  CATVidMdlEventEmitter ();
  /** Destructor */
  ~CATVidMdlEventEmitter ();

  int AddHandler(CATSYPEvent * i_pEvent, CATSYPEventHandler * i_pHandler, int i_handleConsumedEvents = 0);
  int RemoveHandler(CATSYPEvent * i_pEvent, CATSYPEventHandler * i_pHandler);
  int Dispatch(CATSYPEventArgs * i_pArgs);

  static CATSYPEventFactory * GetEventFactory();

  static CATSYPEvent * ItemAdd();
  static CATSYPEvent * ItemRemove();
  static CATSYPEvent * PreColumnsInserted();
  static CATSYPEvent * ColumnsInserted();

  static CATSYPEvent * PreColumnsRemoved();
  static CATSYPEvent * ColumnsRemoved();

  static CATSYPEvent * PreRowsInserted();
  static CATSYPEvent * RowsInserted();
	static CATSYPEvent * 	RowsInsertedProxy();

  static CATSYPEvent * PreRowsRemoved();
  static CATSYPEvent * RowsRemoved();
  static CATSYPEvent * RowsRemovedProxy();
  static CATSYPEvent* PreRowsRemovedProxy();

  static CATSYPEvent * Reset();
  static CATSYPEvent * Update();

  static CATSYPEvent * ItemsDrop();

  static CATSYPEvent * CacheUpdated();

  static CATSYPEvent * FilterChanged();

  static CATSYPEvent * SortChanged();

  static CATSYPEvent * ResetProxy();

  static CATSYPEvent * ItemDataModified();

private:
  // Copy constructor and assignement operator are disabled
  CATVidMdlEventEmitter (CATVidMdlEventEmitter &);
  CATVidMdlEventEmitter& operator=(CATVidMdlEventEmitter&);

  /** Support for event handlers */
  CATSYPEventHandlersSupport * _pSupport;

};

#endif
