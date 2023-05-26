/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2002
#ifndef CATTosUndoRedoOperation_H
#define CATTosUndoRedoOperation_H

/**
 * @level Private
 * @usage U1
 */

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATSysWeakRef.h"
#include "CATOmxSharable.h"

class CATOxSpace;
class CATOxCell;
class CATOxEntity;
class CATOxUndoRedoScope;
class CATOxUndoRedoComponent;
class CATPLMTosPendingProviderImpl;
class CATOxSingleton;
class CATUnicodeString;
class CATOxJanus;
class CATOxSpace;

/**
* Small Implementation to manage Undo / Redo
*/
class ExportedByCATPLMTos CATTosUndoRedoOperation : public CATOmxSharable
{
public:

  /**
  *  Do operation
  */
  HRESULT Redo();

  /**
  *  Undo operation
  */
  HRESULT Undo();

  /**
  *  Flush operation
  */
  HRESULT Flush(const int iWithRelease = 1);

  /**
  *  Identified operation with a short string
  */
  CATUnicodeString Name() const;

  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  //  Simulation 
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  inline CATTosUndoRedoOperation* GetNext() const { return _Next; }

  inline CATOxJanus* GetOwner() const { return _Owner; }

protected:

  /**
  *  xRedo = Do/Redo (to be implemented)
  */
  virtual HRESULT xRedo() = 0;

  /**
  *  xUndo = Undo (to be implemented)
  */
  virtual HRESULT xUndo() = 0;

  virtual HRESULT xFlush(const int iWithRelease = 1);

  /**
  *  xName (to be implemented)
  */
  virtual const char * xName() const = 0;

  friend class CATOmXUndoRedoMemento;
  friend class CATOmbRelationSTSSynchroMememto;
  friend class CATOmbRelationPLMAttributesSynchroMememto;

public:
  /**
  * Record Undo/Redo Memento
  */
  HRESULT RecordMemento(CATOxSpace * ipSpace = NULL);
protected:
  /**
  *  Link Memento
  */
  HRESULT LinkMemento(CATBaseUnknown & iMemento);

  /**
  * Constructors
  */
  CATTosUndoRedoOperation(CATOxJanus * iOwner);
  CATTosUndoRedoOperation(CATOxSpace * iOwner); //HTT: ugly
  /**
  * Destructors
  */
  virtual ~CATTosUndoRedoOperation();

  /**
  *  InsertInOwner
  */
  HRESULT InsertInOwner();

  CATOxJanus* _Owner;
  CATOxSpace* _OwnerSpace; //HTT: ugly
  CATSysWeakRef * _Memento;

private:
  CATTosUndoRedoOperation * _Next;
  CATTosUndoRedoOperation * _Previous;

  friend class CATOxSpace;
  friend class CATOxEntity;
  friend class CATPLMTosPendingProviderImpl;
  friend class CATOxSingleton;
  friend class CATOxCell;

  CATTosUndoRedoOperation(const CATTosUndoRedoOperation  &);
  CATTosUndoRedoOperation & operator = (const CATTosUndoRedoOperation  &);
};

#endif
