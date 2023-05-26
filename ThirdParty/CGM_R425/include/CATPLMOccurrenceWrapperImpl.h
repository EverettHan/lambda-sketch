#ifndef CATPLMOccurrenceWrapperImpl_H
#define CATPLMOccurrenceWrapperImpl_H

#include "CATOmxSR.h"
#include "CATErrorDef.h"
#include "CATBooleanDef.h"
#include "CATBaseUnknown.h"
#include "CATPLMCoreType.h"
#include "CATOmxSharable.h"

class CATPathElement;
class CATBaseUnknown_var;
class CATIPLMNavInstance;
class CATIPLMNavReference;
class CATIPLMNavOccurrence;
class CATIPLMNavRepInstance;
class CATIPLMNavRepReference;
class CATPLMOccurrenceWrapper;
class CATIPLMNavReference_var;
class CATIPLMNavOccurrence_var;
class CATIPLMNavRepOccurrence_var;
class CATListValCATBaseUnknown_var;
class PLMIOmbVirtualObjectDescriptor;
class CATPLMOccurrenceWrapperIterator;
class PLMIOmbVirtualObjectDescriptor_var;

class CATPLMOccurrenceWrapperImpl: public CATOmxSharable
{
private:
  friend class CATPLMOccurrenceWrapper;
  friend class PLMOccurrenceWrapper;
  friend class PLMOccurrenceWrapperWithoutContext;
  CATPLMOccurrenceWrapperImpl():CATOmxSharable((CATMetaClass*)NULL) {}
  virtual CATBoolean IsValid() const=0;
  virtual CATBoolean IsRoot() const=0;
  virtual CATBoolean IsRepOccurrence() const=0;
  virtual CATBoolean IsInContext() const=0;
  virtual HRESULT GetFather(CATPLMOccurrenceWrapper & oFather) const=0;
  virtual HRESULT ScanChildren(CATPLMOccurrenceWrapperIterator & oChildrenIterator,int iTypeFilterSize, CATPLMCoreType * iTypeFilter) const=0;
  virtual HRESULT GetRootOccurrence(CATIPLMNavOccurrence *& oRootOccurrence) const=0;
  virtual HRESULT GetPLMNavOccurrenceObject(const IID& iIID, void ** oPLMNavOccurrence) const=0;
  virtual HRESULT GetPLMNavRepOccurrenceObject(const IID& iIID, void ** oPLMNavRepOccurrence) const=0;
  virtual HRESULT GetOccurrencesInContexts(CATListValCATBaseUnknown_var& iContexts, CATPLMOccurrenceWrapperIterator & oOccurrenceIterator) const=0;
  virtual HRESULT GetRootReference(CATIPLMNavReference *& oRootReference) const=0;
  virtual HRESULT GetPathOfInstances(CATListValCATBaseUnknown_var & oPOFI) const=0;
  virtual HRESULT GetRelatedInstance(CATIPLMNavInstance *& oInstance) const=0;
  virtual HRESULT GetRelatedReference(CATIPLMNavReference *& oReference) const=0;
  virtual HRESULT GetRelatedRepInstance(CATIPLMNavRepInstance *& opRepInstance) const=0;
  virtual HRESULT GetRelatedRepReference(CATIPLMNavRepReference* & opRepReference) const=0;
  virtual HRESULT GetVODescriptor(PLMIOmbVirtualObjectDescriptor *& oVODescriptor, CATBoolean iKeepFinalTarget) const=0;
  virtual HRESULT BuildPathElement(const CATPathElement* iContext, CATPathElement** oPath) const=0;
  virtual int IsEqual(const CATPLMOccurrenceWrapperImpl& iWrapper) const=0;
};

class CATPLMOccurrenceWrapperBuilder
{
  friend class CATPLMOccurrenceWrapper;
  virtual CATPLMOccurrenceWrapperImpl* BuildWrapWithContextFromNavOcc(const CATIPLMNavOccurrence_var & iOccurrence)=0;
  virtual CATPLMOccurrenceWrapperImpl* BuildWrapWithContextFromNavRepOcc(const CATIPLMNavRepOccurrence_var & iRepOccurrence, const CATIPLMNavOccurrence * iFatherOccurrence)=0;
  virtual CATPLMOccurrenceWrapperImpl* BuildWrapWithContextFromPOFI(const CATIPLMNavOccurrence_var & iRootOccurrence, const CATListValCATBaseUnknown_var & iPOFI)=0;
  virtual CATPLMOccurrenceWrapperImpl* BuildWrapWithContextFromVO(const CATIPLMNavOccurrence_var & iRootOccurrence, const PLMIOmbVirtualObjectDescriptor_var & iVODescriptor)=0;
  virtual CATPLMOccurrenceWrapperImpl* BuildWrapWithContextFromPathElement(CATPathElement* iPathElement)=0;
  virtual CATPLMOccurrenceWrapperImpl* BuildWrapWithoutContextFromRef(const CATIPLMNavReference_var & iRootRef)=0;
  virtual CATPLMOccurrenceWrapperImpl* BuildWrapWithoutContextFromPOFI(const CATListValCATBaseUnknown_var & iPOFI)=0;
  virtual CATPLMOccurrenceWrapperImpl* BuildWrapWithoutContextFromVO(const PLMIOmbVirtualObjectDescriptor_var & iVODescriptor)=0;
};
#endif
