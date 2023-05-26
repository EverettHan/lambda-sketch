/* -*-c++-*- */
#ifndef CATPLMSessionToolBox_H
#define CATPLMSessionToolBox_H
// COPYRIGHT DASSAULT SYSTEMES 2005
/* -*-c++-*- */
/**
 * @level Private
 * @usage U1
 */
#include "CATOmbTransientServices.h"
#include "CATBaseUnknown.h"


/**
*
* Subject : No need to engage "out of process" request / engine
*    when it could not succeed thanks so some local underlying persistent information.
*
* Context : Persistent operations specified and used from popular memory handler,
*           needless operations may be engaged from the imprecise context.
*           side-effect is reduced by using some of those smart services.
*            
* Condition of usage : When associated remote services targetted are :
*    1) Provided by associated PLM Integration 
*         1.a) exploration services (data addressed outside and read) :
*                 Query , Expand, Open
*         1.b) indirect derivate services (from Database representant mastering the Vault) :
*                 Switch Engine
*    2) Direclty based upon the physical persistent identity of entities :
*         For instance, that means that if query is built on other properties 
*           such as User Identification, these filtering may be abusive.
*
* Some known Limitations are :
*    1) First degree implementation
*         check does not go futher that an associative physical identification system,
*    2) Conceptual : knowledge of repository in current current process may be by nature 
*            partial/incomplete , obsolete (asynchroneous persisted information evolution), ...
* 
*/

class ExportedByCATOmbTransientServices CATPLMSessionToolBox
{
public:

  /**
  * Determine if object is holding enough physical persistent information 
  *   usable for associated remote services provided by PLM Integration : 
  *
  * <br><b>Role:</b>Check physical identification associativity of an object 
  * <br>succeeded if no restriction encountered to build valid persistent identification
  *   that may help forecoming request to succeed.
  *
  * @param iObject
  *   Associated object.
  *
  * @return
  *    <br> S_OK   : Object is holding enough persistent physical identification. 
  *    <br> E_FAIL : Request failed.
  */
  static HRESULT IsRemotePersistencyEnabler(CATBaseUnknown  *iObject);


  /** 
   * IsSamePLMComponentFamilly
   *   Determine if two entities managed by a PLM repository shared a common root 
   *      (i.e differention physical implementation sharing a common origin)
   *   This characteric is checked thanks to management of logical identification.
   *
   * @param ipObjectAlpha
   * 
   * @param ipObjectBeta
   * 
   * @return
   *    S_OK    : Success if Entities are distinct but ared sharing the same logical
   *    S_FALSE : Entities are managed though a PLM repository, but have nothing in commn in versioning process.
   *    E_FAIL  : Failed if any of previous consitions is not fullfilled.
  */
  static HRESULT  IsSamePLMComponentFamilly (CATBaseUnknown* ipObjectAlpha, 
	                                         CATBaseUnknown* ipObjectBeta );

};

#endif
