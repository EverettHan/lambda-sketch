// COPYRIGHT Dassault Systemes 2014
//===================================================================
//
// CATPLMMetaDataClassList
//
//===================================================================
//
// Usage notes:
// ACCESS RESTRICTED TO PROVIDER IMPLEMENTATION ONLY PLM1, PLMxT, TST
//
//===================================================================
// November 2014  Creation: PJQ
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATPLMMetaDataClassList_H_
#define CATPLMMetaDataClassList_H_

//  List  of  forbidden  re-define
#if  defined  (private)  ||  defined(friend)  ||  defined  (protected)
    #error  Forbidden  re-define  of  'private',  'friend'  or  'protected'
        //  Fatal  error  on  solaris
        @error  
#endif

#define  AuthorizedModule          999

//  List  of  authorized  infrastructure  modules  
#define  CATPLMServicesItf                                      AuthorizedModule
#define  CATPLMImplAdapterQLBase                                AuthorizedModule
#define  CATPLMImplAdapterBase                                  AuthorizedModule
#define  CATPLMImplAdapterClass                                 AuthorizedModule
#define  CATPLMDebugProviderImpl                                AuthorizedModule
#define  CATPLMDebugServices                                    AuthorizedModule
#define  TSTCATPLMCATPLMTypeAndAttrAPI                          AuthorizedModule
#define  TSTCATPLMCATPLMTypeAndAttributeAPI                     AuthorizedModule
#define  TSTCATPLMStandardMaskDico                              AuthorizedModule

#if  _MK_MODNAME_  ==  AuthorizedModule

#else

#error  Forbidden  Access  To  CATPLMServicesItf  Services  from  a  non-authorized  module
//  Fatal  error  on  solaris
@error  
#endif

#undef  AuthorizedModule

//  List  of  authorized  infrastructure  modules  
#undef  CATPLMServicesItf
#undef  CATPLMImplAdapterQLBase
#undef  CATPLMImplAdapterClass
#undef  CATPLMImplAdapterBase
#undef  CATPLMDebugProviderImpl
#undef  CATPLMDebugServices
#undef  TSTCATPLMCATPLMTypeAndAttrAPI
#undef  TSTCATPLMCATPLMTypeAndAttributeAPI
#undef  TSTCATPLMStandardMaskDico

#if defined(__CATPLMServicesItf)
#define ExportedByCATPLMServicesItf DSYExport
#else
#define ExportedByCATPLMServicesItf DSYImport
#endif
#include "DSYExport.h"

#include "CATLISTPIUnknown.h"
#include "IUnknown.h"
#include "CATSysMacroPtr.h"

template <class T>
class CATPLMMetaDataClassList
{
public:
  CATLISTP(IUnknown) _List;
  int Size();

  T * operator[](int i);

  int Append(CATPLMMetaDataClassList<T>& iLObj);

  int Append(T * ipObj);

  ~CATPLMMetaDataClassList();

  CATPLMMetaDataClassList();
};

#include "CATOmxQIPtr.h"

template <class T>
int CATPLMMetaDataClassList<T>::Size()
{
  return _List.Size();
}

template <class T>
T * CATPLMMetaDataClassList<T>::operator[](int i)
{
  CATOmxQIPtr<T> p(_List[i]);
  return p.GiveBack();
}

template <class T>
int CATPLMMetaDataClassList<T>::Append(CATPLMMetaDataClassList<T>& iLObj)
{
  for(int i=1;i<=iLObj.Size();i++)
  {
    IUnknown* p=iLObj._List[i];
    if(_List.Append(p)!=0)
      return 1;
    if(p)
      p->AddRef();
  }
  return 0;
}

template <class T>
int CATPLMMetaDataClassList<T>::Append(T * ipObj)
{
  if(!ipObj)
    return 1;

  if(_List.Append(ipObj)!=0)
    return 1;

  ipObj->AddRef();

  return 0;
}

template <class T>
CATPLMMetaDataClassList<T>::~CATPLMMetaDataClassList()
{
  CATLISTP_FORWARD_LOOP(_List,i)
    {
    IUnknown  *  iUnknwnClass = _List[i];
    CATSysReleasePtr(iUnknwnClass);
    }
  CATLISTP_END_LOOP;
  _List.RemoveAll();
}

template <class T>
CATPLMMetaDataClassList<T>::CATPLMMetaDataClassList()
{}

#include "VPMIDicMask.h"
#include "VPMIDicRelationship.h"
#include "VPMIDicClass.h"
#include "VPMIDicRelationClass.h"
#include "VPMIDicSubRelationship.h"
#include "VPMIDicUsingAttributeMask.h"
#include "VPMIDicPackage.h"
#include "VPMIDicElement.h"

// explicit instantiations
template class ExportedByCATPLMServicesItf CATPLMMetaDataClassList<VPMIDicMask>;
template class ExportedByCATPLMServicesItf CATPLMMetaDataClassList<VPMIDicRelationship>;
template class ExportedByCATPLMServicesItf CATPLMMetaDataClassList<VPMIDicSubRelationship>;
template class ExportedByCATPLMServicesItf CATPLMMetaDataClassList<VPMIDicClass>;
template class ExportedByCATPLMServicesItf CATPLMMetaDataClassList<VPMIDicRelationClass>;
template class ExportedByCATPLMServicesItf CATPLMMetaDataClassList<VPMIDicUsingAttributeMask>;
template class ExportedByCATPLMServicesItf CATPLMMetaDataClassList<VPMIDicPackage>;
template class CATPLMMetaDataClassList<VPMIDicElement>;

#endif /* CATPLMMetaDataClassList_H_ */
