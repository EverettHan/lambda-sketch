#ifndef CATICommunicatorCommander_H
#define CATICommunicatorCommander_H


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATBaseUnknown.h"
#include <IUnknown.h>
#include "CATMessageClass.h"
#include "CATSysCommunication.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATSysCommunication IID IID_CATICommunicatorCommander;
#else
extern "C" const IID IID_CATICommunicatorCommander;
#endif


/**
 * This interface is for now and until otherwise stated reserved to the 
 *  EXCLUSIVE usage of Backbone coding team.
 *
 * Don't copy it and don't use it if you are not in one of the following cases
 *
 *   1) you are Serge Grapinet and you are still responsible of backbone offer
 *   2) your chief is Serge Grapinet and he is still responsible of backbone 
 *   3) your chief is responsible of backbone and he has given you direct 
 *      authorisation to use this interface
 *   4) Backbone responsable is no more Serge Grapinet and you are now  
 *      responsible of backbone
 *
 **/
class ExportedByCATSysCommunication CATICommunicatorCommander : public IUnknown
{
  CATDeclareInterface;
  public:
  /**
   *
   * <b>Role</b>:  MessageClassOverride is meant for the specific usage of 
   *  some bridges application
   * <br> it permits to ask backbone not to instanciate the received message
   * class but an instance of the  default class iOverridingClass
   *
   * <br> iOverridedClass must be left to null for now 
   *
   *  MessageClassOverride MUST NEVER BE USED IN CATIA 
   */
 virtual HRESULT MessageClassOverride( CATMessageClass iOverridingClass , CATMessageClass iOverridedClass=NULL)=0;


};
/**
 * Declare the handler class for CATICommunicatorCommander :  CATICommunicatorCommander_var
 */
CATDeclareHandler (CATICommunicatorCommander,CATBaseUnknown);

#endif
