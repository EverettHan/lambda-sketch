/**
 * @level Protected
 * @usage U2
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES  2005
#ifndef CATOmcV5ContainerAdapter_H_
#define CATOmcV5ContainerAdapter_H_

// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef TypeSDM
#define TypeSDM 14000
#endif

#include "CATBaseUnknown.h"
#include "CATOmcBase.h"
#include "CATIContainer.h"	
#include "CATBaseUnknown.h"
#include "CATContainerAdhesion.h"

class CATUuid;
class CATIUuidTable;

/**
	* Adapter class for LifeCycleObject, CATIContainer and  CATIUUIDManager 
	* interfaces.
	* <b>Role:</b> Deriving from this adapter enables you to implement the 
	*							LifeCycleObject, CATIContainer and  CATIUUIDManager 
	*							interfaces, inheriting implementation.<br>
  * The methods are the following:
  * <ul> 
  * <li> ListMembers</li>
  * <li> ListMembersHere</li>
  * <li> remove</li>
  * <li> RegenerateAndPublishUuids</li>
  * <li> ChangeLinks</li>
  * <li> ReplaceUuids</li>
  * <li> FindObject</li>
  * <li> SetV4Element</li>
	* <li> Internalremove</li> 
  * </ul>
  */

//Cet Adapter derive provisoirement de CATContainerAdhesion 
//en attendant l'activation definitive de la variable d'environnement 
//associee aux nouveaux ContainersV5
class ExportedByCATOmcBase CATOmcV5ContainerAdapter : public CATContainerAdhesion
{
public:

  /**
   * Constructs a CATOmcV5ContainerAdapter.
   */
  CATOmcV5ContainerAdapter();
  virtual ~CATOmcV5ContainerAdapter();


  /**
   * CATIContainer.
   */
	virtual SEQUENCE(CATBaseUnknown_ptr) ListMembers (const CATIdent interfaceID) ;
  virtual CATLONG32 ListMembersHere (const CATIdent interfaceID,SEQUENCE(CATBaseUnknown_ptr)& ioMembersList);

  /**
   * LifeCycleObject
   */
  void remove() ;
  void remove(int context) ;
};

#endif
