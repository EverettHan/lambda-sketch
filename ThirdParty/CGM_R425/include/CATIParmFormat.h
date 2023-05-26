#ifndef CATIParmFormat_h
#define CATIParmFormat_h
//
// COPYRIGHT DASSAULT SYSTEMES 1998
//------------------------------------------------------------------------------
// Abstract: Interface dedicated to literal format definition
//------------------------------------------------------------------------------
// Usage:    
//------------------------------------------------------------------------------
// September 1998 : modification for CAA2  F.Riche (valid)
//------------------------------------------------------------------------------
//   

// export module declaration
#include "CATLifSpecs.h"

// inherited from
#include <CATBaseUnknown.h>

// forwards declaration
#include "CATICkeRelationForwards.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIParmFormat;
#else
extern "C" const IID IID_CATIParmFormat;
#endif

//-------------------------------------------------------------------
/**   
 * CATIParmFormat is the interface dedicated to literal format definition
 * You must implement is on one of your object to customise a literal visualisation method
 * <p>
 * Wherever a literal is shown (CATICkeParm::Show()), you have the ability to define your own
 * visualisation method with this interface.
 * <p>
 * Use CATICkeParm::SetFormat (f) to define a new format to your literal
 * This information is not persistant
 * <p>
 * @see CATICkeParm
 */
//-----------------------------------------------------------------------------
class ExportedByCATLifSpecs CATIParmFormat : public CATBaseUnknown
{

  CATDeclareInterface;

public :
  
  
/**
 * Description : produces a string relative to this format of a literal
 * @return  CATUnicodeString : string shown to the user
 * @param const CATICkeParm_var &d : literal to be shown
 */
virtual CATUnicodeString Show (const CATICkeParm_var &d) const = 0;

}; 

CATDeclareHandler(CATIParmFormat,CATBaseUnknown);

#endif


