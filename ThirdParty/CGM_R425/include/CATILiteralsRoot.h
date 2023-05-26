#ifndef CATILiteralsRoot_h
#define CATILiteralsRoot_h

//
// COPYRIGHT DASSAULT SYSTEMES 1998
//------------------------------------------------------------------------------
// Abstract: Interface to give knowledge editors the root object
// 
//------------------------------------------------------------------------------
// Usage: should be implemented on your personal container    
//------------------------------------------------------------------------------
// September 1998 : modification for CAA2  F.Riche (valid)
//------------------------------------------------------------------------------
//   

// export module declaration
#include "KnowledgeItf.h"

// inherited from
#include "CATBaseUnknown.h"

// interfaces used
//#include "CATISpecObject.h"
#include "CATInterfaceObject.h"
#include "CATIParmPublisher.h"
#include "CATString.h"

#include "CATLISTV_CATBaseUnknown.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATILiteralsRoot;
#else
extern "C" const IID IID_CATILiteralsRoot;
#endif

//-------------------------------------------------------------------
/**   
 * CATILiteralsRoot is the interface to indicate to Knowledge editors where the root is
 * <p>
 * This interface should be implemented on your container
 * Our knowledge editors are trying to find the current Editor, then document, then active
 * object, then its container and the LiteralsRoot interface on it.
 * <p>
 * This is a way for your application to precise where the root is. 
 * <p> 
 * The root is a CATIParmPublisher object where :
 *     - relations and user parameters will be appended (with CATIParmPublisher::Append methods)
 *     - it defines what literals can be used at that level (with CATIParmPublisher::GetAllChildren()) 
 * <p>
 * @see ObjectSpecsModeler.CATIParmPublisher
 */
//-----------------------------------------------------------------------------
class ExportedByKnowledgeItf CATILiteralsRoot : public CATBaseUnknown
{

  CATDeclareInterface;

public :

  /**
   * If there is no doubt in your container about where the formulas
   * will be added as components, this method returns the root
   * @return = root CATIParmPublisher. NULL_var if no root available on this container
   */
  virtual CATIParmPublisher_var GetRoot() = 0;

  virtual CATString          InterfaceToSelect  () = 0;

}; 

CATDeclareHandler(CATILiteralsRoot,CATBaseUnknown);

#endif



