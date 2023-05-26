#ifndef CATIParmRestore_h
#define CATIParmRestore_h
//
// COPYRIGHT DASSAULT SYSTEMES 1998
//------------------------------------------------------------------------------
// Abstract: Interface dedicated to restoring relations
//------------------------------------------------------------------------------
// Usage:    
//------------------------------------------------------------------------------
// September 1998 : modification for CAA2  F.Riche (valid)
//------------------------------------------------------------------------------
//   

// inherited from
#include "CATBaseUnknown.h"

// module
#include "KnowledgeItf.h"


// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATIParmRestore;
#else
extern "C" const IID IID_CATIParmRestore;
#endif

//-------------------------------------------------------------------
/**   
 * CATIParmRestore is the interface dedicated to restoring relations
 * <p>
 * When loading a document containing relations (or when instanciating relations)
 * you MUST use this interface to restore the callbacks between relations
 * <p>
 * This is a BUG for the moment. We hope we will be able to avoid it in next versions.
 * <p> 
 */
//-----------------------------------------------------------------------------
class ExportedByKnowledgeItf CATIParmRestore : public CATBaseUnknown
{

  CATDeclareInterface;

public :
  
/**
 * Description : restore a relation
 * @return  void : nothing
 */
virtual void Restore () = 0;

}; 

CATDeclareHandler(CATIParmRestore,CATBaseUnknown);

#endif



