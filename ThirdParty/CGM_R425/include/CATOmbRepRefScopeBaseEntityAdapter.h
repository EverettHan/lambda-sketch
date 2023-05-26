/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
// Creation: PBV

#ifndef CATOmbRepRefScopeBaseEntityAdapter_h
#define CATOmbRepRefScopeBaseEntityAdapter_h

#include "CATObjectModelerBase.h"

#include "CATIPLMScopeBaseEntity.h"

/**
 * Adapter for CATIPLMScopeBaseEntity implementation for RepRef.
 * <b>Role</b>: Adapter for CATIPLMScopeBaseEntity RepRef implementation.<br>
*/
class ExportedByCATObjectModelerBase CATOmbRepRefScopeBaseEntityAdapter : public CATIPLMScopeBaseEntity
{
public:

  CATOmbRepRefScopeBaseEntityAdapter();
  virtual ~CATOmbRepRefScopeBaseEntityAdapter();

  /**  
  *  Computes  the  scope  base  entity  dependencies.  
  *<br><b>Role</b>:    GetPointedBaseEntities  is  a  <b>not  recursive</b>  method.  
  *  @param oPointedSBEs
  *         The scope base entities are retrieved from pointed simple components
  */  
  virtual  HRESULT  GetPointedBaseEntities  (CATListPtrCATIPLMScopeBaseEntity & oPointedSBEs);  

  /**  
  *  Computes the corresponding elements in the Exposed Scope  
  *  @param ioScopeElem
  *         This component
  */  
  virtual  HRESULT  GetExposedScopeSubpart  (CATListValCATComponentId  &  ioScopeElem);  
};

#endif

