#ifndef CATPLMNavHelpers_H
#define CATPLMNavHelpers_H

// System
#include "CATBaseUnknown.h"
// ObjectModelerCollection
#include "CATOmxIter.h"
#include "CATOmxSR.h"
// CATPLMIdentificationAccess
#include "CATPLMCoreType.h"
// CATPLMComponentInterfaces
#include "CATIPLMNavInstance.h"
#include "CATIPLMNavOccurrence.h"
#include "CATIPLMNavRepInstance.h"
#include "CATIPLMNavRepOccurrence.h"
#include "CATPLMComponentInterfaces.h"

class CATIPLMNavEntity;
class CATIPLMNavReference;
class CATIPLMNavRepReference;

/**
 * this namespace exposes wrapper functions on top of
 *   CATIPLMNavReference
 *   CATIPLMNavRepReference
 *   CATIPLMNavInstance
 *   CATIPLMNavRepInstance
 *   CATIPLMNavOccurrence
 *   CATIPLMNavRepOccurrence
 * calling those functions wrapper instead of directly CATIPLMNav* functions do not have any functional incidence (pure delegation)
 * the benefit is that those wrappers have leak free signatures (you do not have to care about Release).
 *
 * the return codes are hidden but they are rarely meaningful (most of the time, fails only if the input object is destroyed).
 *
 * For functions that returns iterators (CATOmxIter<CATIPLMNavXXX>), for example ListChildren:
 *   you can replace this pattern:
 *   <code>
 *     CATPLMCoreType instanceType[1] = {PLMCoreInstance};
 *     CATListPtrCATIPLMNavEntity childrenInstances;
 *     CATIPLMNavReference* reference = ... ;
 *     if(reference)
 *     {
 *       if(SUCCEEDED(reference->ListChildren(childrenInstances,instanceType,1)))
 *       {
 *         int nChildrenInstances = childrenInstances.Size();
 *         for(int i=1; i<=nChildrenInstances; i++)
 *         {
 *           CATIPLMNavEntity* childInstance = childrenInstances[i];
 *           if(childInstance)
 *           {
 *             //some code
 *             //any return here will cause a leak
 *           }
 *         }
 *       }
 *       //release pointers
 *       CATLISTP_APPLY_RELEASE(childrenInstances); //NB: this requires that you have duplicated CATLISTP_APPLY_RELEASE (which already duplicated more than 1000 times !)
 *     }
 *   </code>
 *
 *   by this one:
 *   <code>
 *     CATIPLMNavReference* reference = ... ;
 *     for(CATIPLMNavEntity& childInstance: CATPLMNavHelpers::ListChildren(reference,PLMCoreInstance))
 *     {
 *       //some code
 *       //you can safely return here without causing any leak
 *     }
 *   </code>
 *
 *  Notice that the following code is illegal
 *  <code>
 *    CATIPLMNavEntity* theFirstOneIsProbablyTheGoodOne_WithFMR = CATPLMNavHelpers::ListChildren(reference).Next();
 *  </code>
 *    - "take the first one" is an anti-pattern
 *    - the pointer is Release'd which can cause a core-dump (Free Memory Read)
 *
 * For functions that returns smart pointers (CATOmxSR<CATIPLMNavXXX>), for example GetFather:
 *   you can replace this pattern:
 *   <code>
 *     CATIPLMNavInstance* instance = ... ;
 *     if(instance)
 *     {
 *       CATIPLMNavReference* fatherReference = NULL;
 *       if(SUCCEEDED(instance->GetFather(fatherReference)))
 *       {
 *         //some code
 *         //any return here will cause a leak
 *
 *         //release pointers
 *         CATSysReleasePtr(fatherReference);
 *       }
 *     }
 *   </code>
 *
 *   by this one:
 *   <code>
 *     CATIPLMNavInstance* instance = ... ;
 *     CATOmxSR<CATIPLMNavReference> fatherReference(CATPLMNavHelpers::GetFather(instance));
 *     if(reference)
 *     {
 *       //some code
 *       //you can safely return here without causing any leak
 *     }
 *   </code>
 *
 *  Notice that the following code is illegal
 *  <code>
 *     CATIPLMNavReference* fatherReference_WithFMR = CATPLMNavHelpers::GetFather(instance);
 *  </code>
 *    - the pointer is Release'd which can cause a core-dump (Free Memory Read)
 *
 */
namespace CATPLMNavHelpers
{
  /** CATIPLMNavEntity::GetPLMCoreType, returns PLMCoreType_Undefined in case of error */
  ExportedByCATPLMComponentInterfaces CATPLMCoreType GetPLMCoreType(const CATIPLMNavEntity* entity);

  /** CATIPLMNavReference::ListChildren */
  ExportedByCATPLMComponentInterfaces CATOmxIter<CATIPLMNavEntity> ListChildren(const CATIPLMNavReference* iReference, CATPLMCoreType iCoreTypeFilter = PLMCoreType_Undefined);

  /** CATIPLMNavReference::ListInstances */
  ExportedByCATPLMComponentInterfaces CATOmxIter<CATIPLMNavInstance> ListInstances(const CATIPLMNavReference* iReference);

  /** CATIPLMNavReference::ListRelatedOccurrences */
  ExportedByCATPLMComponentInterfaces CATOmxIter<CATIPLMNavOccurrence> ListRelatedOccurrences(const CATIPLMNavReference* iReference, const CATBaseUnknown* iContext);



  /** CATIPLMNavRepReference::ListInstances */
  ExportedByCATPLMComponentInterfaces CATOmxIter<CATIPLMNavRepInstance> ListInstances(const CATIPLMNavRepReference* iRepReference);

  namespace Internal
  {
    template<class ChildType, class FatherType>
    inline CATOmxSR<FatherType> _GetFather(const ChildType* iChild)
    {
      FatherType* father = NULL;
      if (iChild)
        (void)const_cast<ChildType*>(iChild)->GetFather(father);
      return CATOmxSR<FatherType>(father, Steal);
    }
  }

  /** CATIPLMNavInstance::GetFather */
  inline CATOmxSR<CATIPLMNavReference> GetFather(const CATIPLMNavInstance* iInstance) { return Internal::_GetFather<CATIPLMNavInstance, CATIPLMNavReference>(iInstance); }

  /** CATIPLMNavInstance::GetReferenceInstanceOf */
  inline CATOmxSR<CATIPLMNavReference> GetReferenceInstanceOf(const CATIPLMNavInstance* iInstance)
  {
    CATIPLMNavReference* instanceOf = NULL;
    if (iInstance)
      const_cast<CATIPLMNavInstance*>(iInstance)->GetReferenceInstanceOf(instanceOf);
    return CATOmxSR<CATIPLMNavReference>(instanceOf, Steal);
  }

  /** CATIPLMNavInstance::ListRelatedOccurrences */
  ExportedByCATPLMComponentInterfaces CATOmxIter<CATIPLMNavOccurrence> ListRelatedOccurrences(const CATIPLMNavInstance* iInstance, const CATBaseUnknown* iContext);

  /** CATIPLMNavInstance::GetFirstLevelOccurrence */
  inline CATOmxSR<CATIPLMNavOccurrence> GetFirstLevelOccurrence(const CATIPLMNavInstance* iInstance, const CATIPLMNavOccurrence* iContext)
  {
    CATIPLMNavOccurrence* firstlevelOccurrence = NULL;
    if (iInstance)
      const_cast<CATIPLMNavInstance*>(iInstance)->GetFirstLevelOccurrence(const_cast<CATIPLMNavOccurrence*>(iContext), firstlevelOccurrence);
    return CATOmxSR<CATIPLMNavOccurrence>(firstlevelOccurrence, Steal);
  }


  /** CATIPLMNavRepInstance::GetFather */
  inline CATOmxSR<CATIPLMNavReference> GetFather(const CATIPLMNavRepInstance* iRepInstance) { return Internal::_GetFather<CATIPLMNavRepInstance, CATIPLMNavReference>(iRepInstance); }

  /** CATIPLMNavRepInstance::GetRepReferenceInstanceOf */
  inline CATOmxSR<CATIPLMNavRepReference> GetRepReferenceInstanceOf(const CATIPLMNavRepInstance* iRepInstance)
  {
    CATIPLMNavRepReference* instanceOf = NULL;
    if (iRepInstance)
      const_cast<CATIPLMNavRepInstance*>(iRepInstance)->GetRepReferenceInstanceOf(instanceOf);
    return CATOmxSR<CATIPLMNavRepReference>(instanceOf, Steal);
  }

  /** CATIPLMNavRepInstance::ListRelatedRepOccurrences */
  ExportedByCATPLMComponentInterfaces CATOmxIter<CATIPLMNavRepOccurrence> ListRelatedRepOccurrences(const CATIPLMNavRepInstance* iRepInstance, const CATBaseUnknown* iContext);




  /** CATIPLMNavOccurrence::GetFather */
  inline CATOmxSR<CATIPLMNavOccurrence> GetFather(const CATIPLMNavOccurrence* iOccurrence) { return Internal::_GetFather<CATIPLMNavOccurrence, CATIPLMNavOccurrence>(iOccurrence); }

  /** CATIPLMNavOccurrence::GetRelatedInstance */
  inline CATOmxSR<CATIPLMNavInstance> GetRelatedInstance(const CATIPLMNavOccurrence* iOccurrence)
  {
    CATIPLMNavInstance* instance = NULL;
    if (iOccurrence)
      (void)const_cast<CATIPLMNavOccurrence*>(iOccurrence)->GetRelatedInstance(instance);
    return CATOmxSR<CATIPLMNavInstance>(instance, Steal);
  }

  /** CATIPLMNavOccurrence::GetRelatedReference */
  inline CATOmxSR<CATIPLMNavReference> GetRelatedReference(const CATIPLMNavOccurrence* iOccurrence)
  {
    CATIPLMNavReference* reference = NULL;
    if (iOccurrence)
      (void)const_cast<CATIPLMNavOccurrence*>(iOccurrence)->GetRelatedReference(reference);
    return CATOmxSR<CATIPLMNavReference>(reference, Steal);
  }

  /** CATIPLMNavOccurrence::ListChildren */
  ExportedByCATPLMComponentInterfaces CATOmxIter<CATIPLMNavOccurrence> ListChildren(const CATIPLMNavOccurrence* iOccurrence);

  /** CATIPLMNavOccurrence::ListRepChildren */
  ExportedByCATPLMComponentInterfaces CATOmxIter<CATIPLMNavRepOccurrence> ListRepChildren(const CATIPLMNavOccurrence* iOccurrence);


  /** CATIPLMNavRepOccurrence::GetFather */
  inline CATOmxSR<CATIPLMNavOccurrence> GetFather(const CATIPLMNavRepOccurrence* iRepOccurrence) { return Internal::_GetFather<CATIPLMNavRepOccurrence, CATIPLMNavOccurrence>(iRepOccurrence); }

  /** CATIPLMNavRepOccurrence::GetRelatedRepInstance */
  inline CATOmxSR<CATIPLMNavRepInstance> GetRelatedRepInstance(const CATIPLMNavRepOccurrence* iRepOccurrence)
  {
    CATIPLMNavRepInstance* repInstance = NULL;
    if (iRepOccurrence)
      (void)const_cast<CATIPLMNavRepOccurrence*>(iRepOccurrence)->GetRelatedRepInstance(repInstance);
    return CATOmxSR<CATIPLMNavRepInstance>(repInstance, Steal);
  }

  /** CATIPLMNavRepOccurrence::GetRelatedRepReference */
  inline CATOmxSR<CATIPLMNavRepReference> GetRelatedRepReference(const CATIPLMNavRepOccurrence* iRepOccurrence)
  {
    CATIPLMNavRepReference* repReference = NULL;
    if (iRepOccurrence)
      (void)const_cast<CATIPLMNavRepOccurrence*>(iRepOccurrence)->GetRelatedRepReference(repReference);
    return CATOmxSR<CATIPLMNavRepReference>(repReference, Steal);
  }

  /** retrieve the root occurrence */
  ExportedByCATPLMComponentInterfaces CATOmxSR<CATIPLMNavOccurrence> GetRootOccurrence(const CATIPLMNavOccurrence* iOccurrence);

  /** retrieve the root occurrence */
  inline CATOmxSR<CATIPLMNavOccurrence> GetRootOccurrence(const CATIPLMNavRepOccurrence* iRepOccurrence) { return GetRootOccurrence(GetFather(iRepOccurrence)); }

}

#endif
