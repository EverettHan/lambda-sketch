#ifndef CATInstanceBridgeAdapter_H
#define CATInstanceBridgeAdapter_H

// COPYRIGHT DASSAULT SYSTEMES 2002

/** 
 */

// Export Module 
#include "KnowledgeItf.h"

// inherit from
#include "CATBaseUnknown.h"

#include "CATIInstanceBridge.h"


/**   
 * CAA2 Adapter to CATIInstanceBridge Interface.
 * <b>Role</b>: This class must be derived to implement features extension to CATIInstanceBridge
 * @see CATIInstance
 * @see CATICkeParm
 */
class ExportedByKnowledgeItf CATInstanceBridgeAdapter : public CATBaseUnknown
{
public:

   /** 
    * Constructs the extension.
    */ 
    CATInstanceBridgeAdapter();

   /** 
    * Deletes the extension.
    */ 
    virtual ~CATInstanceBridgeAdapter();


  //-------------------------------------------
  // Interface CATIInstanceBridge implementation
  //-------------------------------------------
  virtual    CATIInstance_var FindRelatedInstance () const = 0;

 
private:
 
  /**
   * @nodoc
   */
   CATInstanceBridgeAdapter(const CATInstanceBridgeAdapter&);
   CATInstanceBridgeAdapter &operator = (const CATInstanceBridgeAdapter&);
};


#endif
