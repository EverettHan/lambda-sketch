
#ifndef __CATOmeUndoRedoMemento_H
#define __CATOmeUndoRedoMemento_H

#include "CATOme.h"
#include "CATOmeUndoRedoDefs.h"
#include "CATBaseUnknown.h"

#define MementoOwnerKey unsigned int

class ExportedByCATOme CATOmeSessionUndoContext{
public:
  CATOmeSessionUndoContext(){}
  virtual ~CATOmeSessionUndoContext(){};
};

class ExportedByCATOme CATOmeUndoRedoMemento : public CATBaseUnknown
{            
public:
  CATDeclareClass;
  CATOmeUndoRedoMemento(OmeMementoFactoryFlag iFlags);
  ~CATOmeUndoRedoMemento();

  virtual ULONG __stdcall AddRef();

  virtual ULONG __stdcall Release();


  /**
  * Replay forwards  a Model's state.
  *	@param oErrorId
  *		Typed informations if an error is detected and S_OK is not returned.
  *	@param ioContext
  *		CATOmbSessionUndoContext to add a CATOmbSessionUndoContextClient or update an existing one.
  *   CATOmbSessionUndoContextClient is postprocessed at the end of UndoRedoEngine operation.
  *	@return
  *		An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_UNEXPECTED</code>, unexpected error occured.
  *   <dl/>
  */
  virtual HRESULT Redo(CATOmeSessionUndoContext& ioContext,OmeUndoRedoErrorId& oErrorId);
  /**
  * Replay backwards  a Model's state.
  *	@param oErrorId
  *		Typed informations if an error is detected and S_OK is not returned.
  *	@param ioContext
  *		CATOmbSessionUndoContext to add a CATOmbSessionUndoContextClient or update an existing one.
  *   CATOmbSessionUndoContextClient is postprocessed at the end of UndoRedoEngine operation.
  *	@return
  *		An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_UNEXPECTED</code>, unexpected error occured.
  *   <dl/>
  */
  virtual HRESULT Undo(CATOmeSessionUndoContext& ioContext,OmeUndoRedoErrorId& oErrorId);   

  virtual HRESULT SwapData(CATBoolean iUndo,CATOmeSessionUndoContext& ioContext,OmeUndoRedoErrorId& oErrorId);

  inline CATBoolean IsDirtyfying() const {return (m_flags&OME_MemDIRTY ? TRUE : FALSE);}
protected:
  friend class CATOmbSessionUndoRedoTransaction;
  friend class MementosCaretaker;
  friend class CATOmeSessionRecorder;
  CATOmeMementoId m_Id;
  MementoOwnerKey m_OwnerKey;
  OmeMementoFlag m_flags;
  

private:	


  CATOmeUndoRedoMemento( const CATOmeUndoRedoMemento &);
  CATOmeUndoRedoMemento& operator = (const CATOmeUndoRedoMemento &);

};

class ExportedByCATOme CATOmeUndoRedoMementoFactory 
{
public:
  /**
  * Creates the memento's factory.   
  * @param iFlags
  *		flags to toggle Memento behaviors. 
  */
  CATOmeUndoRedoMementoFactory(OmeMementoFactoryFlag iFlags);
  virtual HRESULT BuildOmeMemento(CATOmeUndoRedoMemento*& ioMemento) const;
  /**
  * Check whether a flag is activated. 
  * @return
  *   A boolean value:
  *   <br><b>Legal values</b>:
  *   <code>TRUE</code>, if it is enabled,<code>FALSE</code> otherwise.
  */
  inline CATBoolean HasFlag(OmeMementoFactoryFlag iFlag) const {return (m_flags&iFlag ? TRUE : FALSE);}
  /**
  * Get all flags of a MementoFactory. 
  * @return
  *   A <code>OmbMementoFactoryFlag</code> value.
  */
  OmeMementoFactoryFlag GetAllFlags() const; 
  virtual const char* GetType() const =0;
  virtual ~CATOmeUndoRedoMementoFactory();
protected :
  OmeMementoFactoryFlag m_flags;
  
private:
  CATOmeUndoRedoMementoFactory (const CATOmeUndoRedoMementoFactory &);
  CATOmeUndoRedoMementoFactory& operator=(const CATOmeUndoRedoMementoFactory&);
};


#endif
