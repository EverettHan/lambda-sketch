#ifndef CATPLMOccurrenceWrapper_H
#define CATPLMOccurrenceWrapper_H

#include "CATPLMIdentificationAccessOccWrapper.h"

#include "CATOmxSR.h"
#include "CATBooleanDef.h"
#include "CATPLMCoreType.h"

class CATPathElement;
class CATBaseUnknown_var;
class CATIPLMNavInstance;
class CATIPLMNavReference;
class CATIPLMNavOccurrence;
class CATIPLMNavRepInstance;
class CATIPLMNavRepReference;
class CATIPLMNavRepOccurrence;
class CATIPLMNavReference_var;
class CATIPLMNavOccurrence_var;
class CATIPLMNavRepOccurrence_var;
class CATListValCATBaseUnknown_var;
class PLMIOmbVirtualObjectDescriptor;
class CATPLMOccurrenceWrapperIterator;
class CATListOfCATPLMOccurrenceWrapper;
class PLMIOmbVirtualObjectDescriptor_var;

class CATPLMOccurrenceWrapperImpl;

class ExportedByCATPLMIdentificationAccessOccWrapper CATPLMOccurrenceWrapper
{
public:
// ----------------------------------------------------------------------------------------------
// -- Constructors with context, supports filtered behavior. The filter is defined by the RootOccurrence.
// ----------------------------------------------------------------------------------------------
  /**
  *  Build a filtered occurrence from an existing PLMNavOccurrence Object.
  *  @param iOccurrence
  *      An occurrence.
  */
  CATPLMOccurrenceWrapper(const CATIPLMNavOccurrence_var & iOccurrence);

public:
  /**
  *  build a filtered occurrence from an existing PLMNavRepOccurrence Object.
  *  @param iRepOccurrence
  *      A representation occurrence.
  */
  CATPLMOccurrenceWrapper(const CATIPLMNavRepOccurrence_var & iRepOccurrence);

public:
  /**
  *  Build a filtered occurrence in a context from a Path Of First Instance.
  *  @param iRootOccurrence
  *      The context : a root occurrence.
  *  @param iPOFI
  *      The path of first instances. <br>
  *      The last element can be a RepInstance in order to wrap an occurrence of a instance of representation.
  */
  CATPLMOccurrenceWrapper(const CATIPLMNavOccurrence_var & iRootOccurrence, const CATListValCATBaseUnknown_var & iPOFI);

  /**
  *  Build a filtered occurrence in a context from a VO descriptor.
  *  @param iRootOccurrence
  *      The context : a root occurrence.
  *  @param iVODescriptor
  *      A virtual object descriptor. <br>
  *      If the VO descriptor contains a representation Instance, this representation instance will be appended to the Path Of First Instance of this wrapper.
  */
  CATPLMOccurrenceWrapper(const CATIPLMNavOccurrence_var & iRootOccurrence, const PLMIOmbVirtualObjectDescriptor_var & iVODescriptor);

  /**
  *  Build a filtered occurrence in a context from a PathElement.
  *  @param iPathElement
  *      The Path Element 
  *      If Path Element contains a PLMNavRepOccurrence object (or a PLMNavRepInstance as long as OCC_RepInst is not activated), the wrapper is built on this object.
  *      Else if Path Element contains a PLMNavOccurrence object, the wrapper is built on this object.
  *      Else the built wrapper is not valid.
  */
  CATPLMOccurrenceWrapper(CATPathElement* iPathElement);

// ----------------------------------------------------------------------------------------------
// -- Constructors without context, supports non filtered behavior.
// ----------------------------------------------------------------------------------------------
  /**
  *  Build a non filtered root occurrence from an existing reference.
  *  @param iReference
  *      A reference.
  */
  CATPLMOccurrenceWrapper(const CATIPLMNavReference_var & iReference);

  /**
  *  Build a non filtered occurrence from a Path Of First Instance.
  *  @param iPOFI
  *      The path of first instances. <br>
  *      The last element can be a RepInstance in order to wrap an occurrence of a instance of representation.
  */
  CATPLMOccurrenceWrapper(const CATListValCATBaseUnknown_var & iPOFI);

  /**
  *  Build a non filtered occurrence from a VO descriptor.
  *  @param iVODescriptor
  *      A virtual object descriptor. <br>
  *      If the VO descriptor contains a representation Instance, this representation instance will be appended to the Path Of First Instance of this wrapper.
  */
  CATPLMOccurrenceWrapper(const PLMIOmbVirtualObjectDescriptor_var & iVOD);

// ----------------------------------------------------------------------------------------------
// -- Empty Constructor
// ----------------------------------------------------------------------------------------------
  CATPLMOccurrenceWrapper();

// ----------------------------------------------------------------------------------------------
// -- Check methods.
// ----------------------------------------------------------------------------------------------
  /**
  *  Check wrapper validity.
  *  @return
  *      <code>TRUE</code> if the wrapper is valid. <br>
  *      <code>FALSE</code> if the wrapper is invalid. <br>
  */
  CATBoolean IsValid() const;

  /**
  *  Check the wrapper wraps a root (built from a RootOccurrence or a Reference).
  *  @return
  *      <code>TRUE</code> if the the wrapper wraps a root occurrence or a reference. <br>
  *      <code>FALSE</code> if the the wrapper does'nt wrap a root occurrence or a reference. <br>
  */
  CATBoolean IsRoot() const;

  /**
  *  Check the wrapper wraps a repOccurrence (built from a RepOccurrence or a Path Of First Instance containing a repInstance).
  *  @return
  *      <code>TRUE</code> if the wrapper wraps a repOccurrence. <br>
  *      <code>FALSE</code> if the wrapper does'nt wrap repOccurrence. <br>
  */
  CATBoolean IsRepOccurrence() const;

  /**
  *  Check the wrapper was built from an occurrence or a repOccurrence belonging to a filtered context.
  *  @return
  *      <code>TRUE</code> if the wrapper was built from an occurrence or a repOccurrence belonging to a filtered context. <br>
  *      <code>FALSE</code> if the wrapper was'nt built from an occurrence or a repOccurrence belonging to a filtered context. <br>
  */
  CATBoolean IsInContext() const;

// ----------------------------------------------------------------------------------------------
// -- Navigation Behaviors.
// ----------------------------------------------------------------------------------------------
  /**
  *  Retrieves the Occurrence which aggregates the Occurrence.
  *  @param oFather
  *      The father occurrence wrapper. <br>
  *      If this wrapper has been built from a RootOccurrence as context, or rfom a PLMNavOccurrence/PLMNavRepOccurrence, this method returns a wrapper on the built occurrence in this context. <br>
  *      Else, this method computes a wrapper on an Occurrence/RepOccurrence object in the non filtered context of the Path Of First Instance used to built this wrapper. <br>
  *      In this case, the implementation of CATIPLMNavInstance of the modeler owning the leaf instance of the path will be used to provide navigation on the reference/instance model. <br>
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetFather(CATPLMOccurrenceWrapper & oFather) const;

  /**
  *  Gets children occurrences, filtered or not by children type. Supported filter types are PLMCoreInstance and PLMCoreRepInstance. <br>
  *  Scan with CATPLMOccurrenceWrapperIterator::Next.
  *  @param oChildrenIterator
  *      An iterator on children occurrence wrapper. <br>
  *      If this wrapper has been built from a RootOccurrence, or a PLMNavOccurrence/PLMNavRepOccurrence, this method returns a wrapper iterator on the built occurrences in this context. <br>
  *      Else, this method compute a wrapper iterator on an Occurrence/RepOccurrence object in the non filtered context of the Path Of First Instance used to built this wrapper. <br>
  *      In this case, the implementation of CATIPLMNavInstance of the modeler owning the leaf instance of the path will be used to provide navigation on the reference/instance model. <br>
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT ScanChildren(CATPLMOccurrenceWrapperIterator & oChildrenIterator, const int& iTypeFilterSize, CATPLMCoreType * iTypeFilter) const;

  /**
  *  Gets the Root Occurrence.
  *  @param oRootOccurrence [out, CATBaseUnknown#Release]
  *      The root occurrence wrapper. <br>
  *      If this wrapper has been built from a RootOccurrence, or a PLMNavOccurrence/PLMNavRepOccurrence, this method returns this root occurrence. <br>
  *      Else, this method build a new root occurrence without filter from the root of the Path Of First Instance used to built this wrapper. <br>
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetRootOccurrence(CATIPLMNavOccurrence *& oRootOccurrence) const;

  /**
  *  Gets the CATIPLMNavOccurrence object.
  *  @param oPLMNavOccurrence [out, CATBaseUnknown#Release]
  *      The PLMNavOccurrence object. <br>
  *      If this wrapper has been built from a RootOccurrence, or a PLMNavOccurrence, this method returns the built occurrence in this context. <br>
  *      Else, this method build a new PMLNavOccurrence object in a non filtered context from the root of the Path Of First Instance used to built this wrapper. <br>
  *  @param iIID
  *      The interface identifier for which a pointer is requested.
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetPLMNavOccurrenceObject(const IID& iIID, void ** oPLMNavOccurrence) const;

  /**
  *  Gets the CATIPLMNavRepOccurrence object.
  *  @param oPLMNavRepOccurrence [out, CATBaseUnknown#Release]
  *      The PLMNavRepOccurrence object. <br>
  *      If this wrapper has been built from a RootOccurrence, or a PLMNavRepOccurrence, this method returns the built rep occurrence in this context. <br>
  *      Else, this method build a new PMLNavRepOccurrence object in a non filtered context from the root of the Path Of First Instance used to built this wrapper. <br>
  * @param iIID
  *      The interface identifier for which a pointer is requested.
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetPLMNavRepOccurrenceObject(const IID& iIID, void ** oPLMNavRepOccurrence) const;

  /**
  *  Retrieves the occurrence wrappers corresponding to a given occurrence wrapper, in a given list of contexts. <br>
  *  @param iContexts
  *      A list of contexts (a context can be a Reference, an Instance or an Occurrence).
  *  @param oOccurrenceIterator
  *      An iterator from which can be accessed the retrieved occurrences.
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetOccurrencesInContexts(CATListValCATBaseUnknown_var& iContexts, CATPLMOccurrenceWrapperIterator & oOccurrenceIterator) const;

// ----------------------------------------------------------------------------------------------
// -- Instance/Reference model Accessors.
// ----------------------------------------------------------------------------------------------
  /**
  *  Gets the root reference.
  *  @param oRootReference [out, CATBaseUnknown#Release]
  *      The root reference. <br>
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetRootReference(CATIPLMNavReference *& oRootReference) const;

  /**
  *  Gets the path of instances.
  *  @param oPOFI
  *      The path of instances, the last element can be a RepInstance. <br>
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetPathOfInstances(CATListValCATBaseUnknown_var & oPOFI) const;

  /**
  *  Gets the related instance.
  *  @param oInstance [out, CATBaseUnknown#Release]
  *      The related instance. <br>
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetRelatedInstance(CATIPLMNavInstance *& oInstance) const;

  /**
  *  Gets the related reference.
  *  @param oReference [out, CATBaseUnknown#Release]
  *      The related reference. <br>
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetRelatedReference(CATIPLMNavReference *& oReference) const;

  /**
  *  Gets (if exists) the related representation instance.
  *  @param opRepInstance [out, CATBaseUnknown#Release]
  *      The related representation instance. <br>
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetRelatedRepInstance(CATIPLMNavRepInstance *& opRepInstance) const;

  /**
  *  Gets (if exists) the related representation reference.
  *  @param opRepReference [out, CATBaseUnknown#Release]
  *      The related representation reference. <br>
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetRelatedRepReference(CATIPLMNavRepReference *& opRepReference) const;

// ----------------------------------------------------------------------------------------------
// -- VO Descriptor Accessor.
// ----------------------------------------------------------------------------------------------
  /**
  *  Gets a VO Descriptor.
  *  @param oVODescriptor [out, CATBaseUnknown#Release]
  *      A VO Descriptor. <br>
  *      This method build a new VO descriptor from the path of instances of this wrapper (plus eventually with the representation instance).
  *  @param iKeepFinalTarget
  *      If iKeepFinalTarget==FALSE and this wrapper has been built from a VO descriptor, this method returns a new VO descriptor with an empty target, even if the original VO descriptor contains a target. <br>
  *      Else if iKeepFinalTarget==TRUE and this wrapper has been built from a VO descriptor, the returned VO descriptor contains the original target (if exists).
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetVODescriptor(PLMIOmbVirtualObjectDescriptor *& oVODescriptor, CATBoolean iKeepFinalTarget) const;

// ----------------------------------------------------------------------------------------------
// -- PathElement Accessor.
// ----------------------------------------------------------------------------------------------
  /**
  *  Builds a CATPathElement.
  *  @param oPathElement [out, CATBaseUnknown#Release]
  *      A PathElement. <br>
  *      This method build a new PathElement through the CATIBuildPath implementation of its corresponding PLMNavOccurrence or PLMNavRepOccurrence object. <br>
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT BuildPathElement(const CATPathElement* iContext, CATPathElement** oPathElement) const;

// ----------------------------------------------------------------------------------------------
// -- Compare Path of Instances.
// ----------------------------------------------------------------------------------------------
  /**
  *  Compares the instance path with another Occurrence Wrapper.
  *  The comparison does not take in account the context of the two occurrence wrapper,
  *  it only tests the instances path equality (including the representation instance if exists).
  *  @param iWrapToCompare
  *      The occurrence wrapper in which we compare the instance path. <br>
  *  @return
  *      <code>S_OK</code> success. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  int ComparePathOfInstances(const CATPLMOccurrenceWrapper & iWrapToCompare) const;

// ----------------------------------------------------------------------------------------------
// -- == and != operator
// ----------------------------------------------------------------------------------------------
  int operator==(const CATPLMOccurrenceWrapper& iWrapper) const;
  int operator!=(const CATPLMOccurrenceWrapper& iWrapper) const;

// ----------------------------------------------------------------------------------------------
// -- Copy Constructor & Assignment operator & Destructor.
// ----------------------------------------------------------------------------------------------
  ~CATPLMOccurrenceWrapper();
  CATPLMOccurrenceWrapper(const CATPLMOccurrenceWrapper & iWrapper);
  CATPLMOccurrenceWrapper& operator=(const CATPLMOccurrenceWrapper& iWrapper);

// ----------------------------------------------------------------------------------------------
// -- Deprecated.
// ----------------------------------------------------------------------------------------------
  /** Use GetVODescriptor(PLMIOmbVirtualObjectDescriptor *& oVODescriptor, CATBoolean iKeepFinalTarget) **/
  HRESULT GetVODescriptor(PLMIOmbVirtualObjectDescriptor *& oVODescriptor) const;

private:

  /**
  *  build a filtered occurrence from an existing CATIPLMNavRepOccurrence Object.
  *  @param iRepOccurrence
  *      A representation occurrence.
  *  !!! If OCC_REPINST project is not active (R2016x), substitute ctor 
  */
  friend class PrdOccModelUC_Wrapper_GetOccsInContexts;
  friend class PrdOccModelUC_Wrapper_WithContext;
  friend class CATLPRepOccurrenceServices;
  friend class CATOccurrenceTreeServices;
  friend class CATVisPropertiesOverloadableOnRepOcc;
  CATPLMOccurrenceWrapper(const CATIPLMNavRepOccurrence_var & iRepOccurrence, const CATIPLMNavOccurrence * iFatherOccurrence);

  friend class PLMOccurrenceWrapperWithContextFromNavOcc;
  friend class PLMOccurrenceWrapperWithContextFromPofi;
  friend class PLMOccurrenceWrapperWithContextFromNavRepInst;
  friend class PLMOccurrenceWrapperWithoutContextFromRef;
  friend class PLMOccurrenceWrapperWithoutContextFromPofi;
  friend class PLMOccurrenceWrapperChildIterator;
  friend class PLMOccurrenceWrapperOccIteratorFromOcc;
  friend class PLMOccurrenceWrapperOccIteratorFromRepOcc;
  friend class PLMOccurrenceWrapperOccIteratorFromRepInst;
  friend class PLMOccurrenceWrapperOccIteratorFromPofi;
  CATOmxSR<CATPLMOccurrenceWrapperImpl> _impl;
};
#endif
