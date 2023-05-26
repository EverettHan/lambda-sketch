#ifndef CATIRelativeParameter_h
#define CATIRelativeParameter_h

//
// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
// Abstract: Interface to give relative parameters their root object
// 
//------------------------------------------------------------------------------
// July 1999 : creation C.Lenguin
//------------------------------------------------------------------------------
//   

// export module declaration
#include "KnowledgeItf.h"

// inherited from
#include "CATBaseUnknown.h"

// interfaces used
#include "CATIParmPublisher.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATIRelativeParameter;
#else
extern "C" const IID IID_CATIRelativeParameter;
#endif

//-------------------------------------------------------------------
/**   
 * CATIRelativeParameter is the interface to indicate their root to relative parameters 
 * <p>
 * Given the root and the relative Path, the relative parameter feature retreives the 
 * Literal it points.
 */
//-----------------------------------------------------------------------------
class ExportedByKnowledgeItf CATIRelativeParameter : public CATBaseUnknown
{

  CATDeclareInterface;

public :

  virtual void SetRoot(const CATIParmPublisher_var& iRoot) = 0;
  virtual CATICkeParm_var Parameter() const = 0;

}; 

CATDeclareHandler(CATIRelativeParameter,CATBaseUnknown);

#endif



