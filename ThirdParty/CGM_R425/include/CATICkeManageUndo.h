#ifndef CATICkeManageUndo_h
#define CATICkeManageUndo_h
//
// COPYRIGHT DASSAULT SYSTEMES 1998
//------------------------------------------------------------------------------
// Abstract: Interface dedicated to restoring Kb objects after Undo/Redo to add/remove callbacks
//------------------------------------------------------------------------------
// Usage:    
//------------------------------------------------------------------------------
// Nov 1999 : F.Riche 
//------------------------------------------------------------------------------
//   

// inherited from
#include "CATBaseUnknown.h"

// module
#include "KnowledgeItf.h"


// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeManageUndo;
#else
extern "C" const IID IID_CATICkeManageUndo;
#endif

//-------------------------------------------------------------------
/**   
 * CATICkeManageUndo is the interface dedicated to restoring event based objects after Undo/Redo
 * <p>
 * When loading a document containing relations (or when instanciating relations)
 * you MUST use this interface to restore the callbacks between relations
 * <p>
 */
//-----------------------------------------------------------------------------
class ExportedByKnowledgeItf CATICkeManageUndo : public CATBaseUnknown
{

  CATDeclareInterface;

public :
  
/**
 * Description : restore an object which creation is undone (objective: suppress callbacks)
 * @return  void : nothing
 */
virtual void SuppressEvents () = 0;

 
/**
 * Description : restore an object which deletion or modification is undone (objective: restore callbacks)
 * @return  void : nothing
 */
virtual void RestoreEvents () = 0;

}; 

CATDeclareHandler(CATICkeManageUndo,CATBaseUnknown);

#endif



