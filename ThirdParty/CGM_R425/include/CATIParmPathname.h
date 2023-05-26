#ifndef CATIParmPathname_h
#define CATIParmPathname_h
//
// COPYRIGHT DASSAULT SYSTEMES 1998
//------------------------------------------------------------------------------
// Abstract: Interface dedicated to literal naming 
//------------------------------------------------------------------------------
// Usage:    
//------------------------------------------------------------------------------
// September 1998 : modification for CAA2  F.Riche (valid)
//------------------------------------------------------------------------------
//   

// inherited from
#include "CATBaseUnknown.h"

// export load module
#include "KnowledgeItf.h"

// forward declaration
#include "CATICkeRelationForwards.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATIParmPathname;
#else
extern "C" const IID IID_CATIParmPathname;
#endif

//-------------------------------------------------------------------
/**   
 * CATIParmPathname is the interface dedicated to literal naming
 * <p>
 * When a literal is shown to the user, it is always in the context of another object we call "root" (which is a CATIParmPublisher) 
 * Example : in part context, a hole's radius is "PartBody\Hole.1\Radius"
 * <p>
 * This is the relative pathname of the literal
 * <p>
 * If you want to customise the way a literal is named, just implement this interface on the root object
 * <p>
 * @see ObjectSpecsModeler.CATIParmPublisher
 */
//-----------------------------------------------------------------------------
class ExportedByKnowledgeItf CATIParmPathname : public CATBaseUnknown
{

  CATDeclareInterface;

public :
  
/**
 * Description : the function of a literal is what it is used for in the context of the root
 *               for example, the function of a Hole's radius is "Radius"
 * @return  CATUnicodeString : NLS function
 * @param const CATICkeParm_var &p : literal to be named
 */
virtual CATUnicodeString GetFunction (const CATICkeParm_var &p) const= 0;

/**
 * Description : the pathname of a literal is what is shown to the user. It must be closed to the
 *               hierarchy shown in the tree view.
 *               From the root, the pathname is a NLS string which is a concatenation of features names
 *               leading to the literal separated by '\'.
 *               For example, in part context, a hole's radius pathname is "PartBody\Hole.1\Radius"
 *               The last string should be the literals function. 
 * @return  CATUnicodeString : NLS pathname
 * @param const CATICkeParm_var &p : literal to be named
 */
virtual CATUnicodeString ComputePathname (const CATICkeParm_var &p) const= 0;

}; 

CATDeclareHandler(CATIParmPathname,CATBaseUnknown);

#endif



