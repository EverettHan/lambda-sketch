// COPYRIGHT Dassault Systemes 2008
#ifndef CATIOccurrenceServices_H
#define CATIOccurrenceServices_H

/**
* @level Private
* @usage U3
*/

#include "CATBaseUnknown.h"
#include "CATPLMModelerOccInterfaces.h"
#include "CATBoolean.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerOccInterfaces IID IID_CATIOccurrenceServices;
#else
extern "C" const IID IID_CATIOccurrenceServices;
#endif

class CATIPLMNavReference_var;
class CATIPLMNavOccurrence_var;
class CATIPLMNavRepInstance_var;
class CATIPLMNavRepOccurrence_var;
class CATListValCATBaseUnknown_var;
class CATBaseUnknown_var;
class PLMIIterator;

#include "CATLISTV_CATBaseUnknown.h"

/**
* @nodoc
*/

class ExportedByCATPLMModelerOccInterfaces CATIOccurrenceServices : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * DEPRECATED R424
  * check LIP Simultaneous views of Product Structure_Migration_Cookbook.pptx
  * (https://dsxdev-online.dsone.3ds.com/enovia/common/emxNavigator.jsp?physicalId=622CB056E11600005FCFC0C50012BAAA)
  * use CATRootOccurrenceMgr
  *
  * Computes the root occurrence corresponding to a given root reference and filter.
  *  @param iRoot
  *      A root reference.
  *  @param oRootOcc
  *      The computed root occurrence
  *  @param iFilter
  *      A filter.
  *  @param iForce
  *      Specify if the root occurrence must be created if not already existing. <br>
  *      Creation is done if necessary by default.
  *  @param isExplicitFilter
  *      Specify if the children occurrences list will be explicitely defined. <br>
  *  @return
  *      <code>S_OK</code> if the methods succeeds and the root occurrence has been retrieved. <br>
  *      <code>E_INVALIDARG</code> if provided arguments are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT GetOrCreateRootOccurrence(const CATIPLMNavReference_var& iRoot, CATIPLMNavOccurrence_var& oRootOcc, const CATBaseUnknown_var& iFilter = NULL_var, CATBoolean iForce = 1, CATBoolean isExplicitFilter = 0) = 0;

  /**
  * Computes an occurrence corresponding to a given path of instances in a given context.
  *  @param iRootOccurrence
  *      The context : a root occurrence.
  *  @param iPOFI
  *      The path of first instances.
  *  @param oOccurrence
  *      The computed occurrence.
  *  @param iForce
  *      Specify if the occurrence must be created if not already existing. <br>
  *      Creation is done if necessary by default.
  *  @return
  *      <code>S_OK</code> if the methods succeeds and the occurrence has been retrieved. <br>
  *      <code>E_INVALIDARG</code> if provided arguments are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT GetOrCreateOccurrence(const CATIPLMNavOccurrence_var& iRootOccurrence, const CATListValCATBaseUnknown_var& iPOFI, CATIPLMNavOccurrence_var& oOccurrence, CATBoolean iForce = 1) = 0;

  /**
  * Computes a rep occurrence corresponding to a given child rep instance of an occurrence.
  *  @param iOccurrence
  *      The occurrence.
  *  @param iRepInstance
  *      The rep instance.
  *  @param oRepOccurrence
  *      The computed rep occurrence.
  *  @return
  *      <code>S_OK</code> if the methods succeeds and the occurrence has been retrieved. <br>
  *      <code>E_INVALIDARG</code> if provided arguments are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT GetOrCreateRepOccurrence(const CATIPLMNavOccurrence_var& iOccurrence, const CATIPLMNavRepInstance_var& iRepInstance, CATIPLMNavRepOccurrence_var& oRepOccurrence) = 0;

  /**
  * Computes the path of instances corresponding to a given occurrence.
  *  @param iOccurrence
  *      The occurrence.
  *  @param oPOFI
  *      The computed path of first instances.
  *  @return
  *      <code>S_OK</code> if the methods succeeds and the occurrence has been retrieved. <br>
  *      <code>E_INVALIDARG</code> if provided arguments are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT FromOccurrenceToPathOfInstances(const CATIPLMNavOccurrence_var& iOccurrence, CATListValCATBaseUnknown_var& oPOFI) = 0;

  /**
  * Checks whether an occurrence is up to date with respect to the model events dispatched in the current transaction.
  *  @param iOccurrence
  *      The occurrence.
  *  @param iAllTree
  *      Specify if the whole occurrences tree must be checked, or just the given occurrence.
  *  @return
  *      <code>TRUE</code> if all model event have already been dispatched. <br>
  *      <code>FLASE</code> if undispatched events are currently stored. <br>
  */
  virtual CATBoolean IsSynchronized(const CATIPLMNavOccurrence_var& iOccurrence, CATBoolean iAllTree = 0) = 0;

  /**
  * Synchronizes an occurrence with respect to the model events stored in the current transaction.
  *
  *  @param iOccurrence
  *      The occurrence.
  *  @param iAllTree
  *      Specify of the whole occurrences tree must be synchronized, or just the given occurrence.
  *  @return
  *      <code>S_OK</code> if the synchronization succeeds. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT Synchronize(const CATIPLMNavOccurrence_var& iOccurrence, CATBoolean iAllTree = 0) = 0;

  /**
  * @nodoc
  */
  virtual HRESULT Expand(CATIPLMNavOccurrence_var& iOccurrence) = 0;

  /**
  * @nodoc
  */
  virtual HRESULT ExpandAll(CATIPLMNavOccurrence_var& iOccurrence) = 0;

  /**
  * Retrieves the occurrence corresponding to a given to a given Reference, Instance or Occurrence in a given context.
  *  @param iObject
  *      A Reference, an Instance or an Occurrence.
  *  @param iContext
  *      A context (can be a Reference, an Instance or an Occurrence).
  *  @param oOccurrence
  *      The occurrence.
  *  @return
  *      <code>S_OK</code> if the methods succeeds and occurrences have been retrieved. <br>
  *      <code>E_INVALIDARG</code> if provided arguments are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT FindOccurrenceInContext(const CATBaseUnknown_var& iObject, const CATBaseUnknown_var& iContext, CATIPLMNavOccurrence_var& oOccurrence) = 0;

  /**
  * Retrieves the occurrence corresponding to a given Reference, Instance or Occurrence in a given list of contexts.
  *  @param iObject
  *      A Reference, an Instance or an Occurrence.
  *  @param iContexts
  *      A list of contexts (a context can be a Reference, an Instance or an Occurrence).
  *  @param oIterator [CATBaseUnknown#Release]
  *      An iterator from which can be accessed the retrieved occurrences.
  *  @param iForce
  *      Specify if occurrences must be created if not already existing. <br>
  *      Creation is done if necessary by default.
  *  @param iIID
  *      An interface IID filtering the retrieved occurrences. <br>
  *      IID_CATBaseUnknown by default
  *  @return
  *      <code>S_OK</code> if the methods succeeds and occurrences have been retrieved. <br>
  *      <code>S_FALSE</code> if the methods succeeds but no occurrences have been retrieved. <br>
  *      <code>E_INVALIDARG</code> if provided arguments are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT GetOccurrencesInContexts(const CATBaseUnknown_var& iObject, CATListValCATBaseUnknown_var& iContexts, PLMIIterator*& oIterator, int iForce = 1, const IID& iIID = IID_CATBaseUnknown) = 0;

  /**
  * Retrieves all the occurrences corresponding to a given path of instances in a given list of contexts.
  *
  *  @param iPOFI
  *      A path of instances.
  *  @param iContexts
  *      A list of contexts (a context can be a Reference, an Instance or an Occurrence).
  *  @param  oIterator [CATBaseUnknown#Release]
  *      An iterator from which can be accessed the retrieved occurrences.
  *  @param iForce
  *      Specify if occurrences must be created if not already existing. <br>
  *      Creation is done if necessary by default.
  *  @param iIID
  *      An interface IID filtering the retrieved occurrences. <br>
  *      IID_CATBaseUnknown by default
  *  @return
  *      <code>S_OK</code> if the methods succeeds and occurrences have been retrieved. <br>
  *      <code>S_FALSE</code> if the methods succeeds but no occurrences have been retrieved. <br>
  *      <code>E_INVALIDARG</code> if provided arguments are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT GetOccurrencesInContexts(const CATListValCATBaseUnknown_var& iPOFI, CATListValCATBaseUnknown_var& iContexts, PLMIIterator*& oIterator, int iForce = 1, const IID& iIID = IID_CATBaseUnknown) = 0;

  /**
  *
  */
  virtual HRESULT ApplySessionFilter(const CATIPLMNavOccurrence_var& iRootOccurrence, const CATBaseUnknown_var& iFilter) = 0;

};

CATDeclareHandler(CATIOccurrenceServices, CATBaseUnknown);

#endif
