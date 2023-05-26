#ifndef CATIParmSelector_h
#define CATIParmSelector_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U5 
 */


/*  CAA2Reviewed  by FRH */

// inherited from
#include "CATBaseUnknown.h"

// export load module
#include "KnowledgeItf.h"

// forward
class CATICkeParm_var;


// OLE id
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATIParmSelector;
#else
extern "C" const IID IID_CATIParmSelector;
#endif

/** 
 * Interface for parameter selection.
 * <b>Role</b>: to be implemented by objects that can be used as selection to return a parameter.<br>
 * For example, a constraint.
 * This interface is used by F(x) commands to select parameters.<br>
 * It is implemented at least on parameters.<br>
 * This interface is multi implemented.
 * It is not supposed to be used for other purpose than F(x).
 */
class ExportedByKnowledgeItf CATIParmSelector : public CATBaseUnknown
{

  CATDeclareInterface;

public :
  
/**
 * Returns the underlying parameter.
 * Can return NULL_var
 */
virtual CATICkeParm_var SelectedLiteral () const = 0;

}; 

CATDeclareHandler(CATIParmSelector,CATBaseUnknown);

#endif



