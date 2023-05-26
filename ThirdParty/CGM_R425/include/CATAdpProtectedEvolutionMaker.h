/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2013

#ifndef CATAdpProtectedEvolutionMaker_H
#define CATAdpProtectedEvolutionMaker_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATSysErrorDef.h"
#include "CATSysDataType.h"
class CATAdpProtectedComponentsAssociation;
class CATIAdpErrorMonitor;
class CATIAdpPLMIdentificator;
class CATAdpAttributeSet;
class CATAdpProtectedEvolutionMakerImpl;
class CATUnicodeString;

/**
 * Class enabling to perform Evolution of a Component.
 * <br><b>Role</b>: <p>This class creates new Components which are evolutions of given Components if compliant with Evolution protocol.
 * In IRPC typing, only references and representations can be passed as input.</p>
 *
 * <p>An Evolution scope is calculated dynamically. The following components may be transformed
 * (and returned in the result set) if aggregated under a given reference, even if not
 * specified in input :</p><ul>
 *   <li>Instances, Representation Instances, Connections and Ports</li>
 *   <li>MonoInstanciated Representations and their associated instance</li></ul>
 *
 * <p>If defined, the relevant PLMIdentificationInitialization business logic with 'Cloning'
 * OperationId will be called on every impacted references or representations. If not defined
 * a default logic is applied by adding the given IdCloningString to the first string
 * attribute of the identifier set (most of the time the attribute PLM_ExternalID).</p>
 *
 * <p>If a specific attribute set is associated to a given component, those attributes will
 * applied after the attributes defined by the previous business logic. It may overwrite some
 * of them.</p>
 *
 * Example of usage :
 * <pre>
 * CATAdpProtectedEvolutionMaker Evolutor;
 * while(<there are components>)
 * {
 *   CATAdpAttributeSet attributeSet;
 *   // Code which specifies attributes to change, like attributes in the identificator set
 *   // ...
 *   if(FAILED(Evolutor.AddElement(pMyComp, attributeSet))
 *   //Error management
 * }
 * </pre>
 * Then :
 * <pre>
 * if(FAILED(Evolutor.Evolve())
 * {
 *    CATIAdpPLMErrorReviewer pErrorReviewer = NULL;
 *    Evolutor.GetErrorReviewer(pErrorReviewer);
 *    //manage errors
 *    CATSysReleasePtr(pErrorReviewer);
 * }
 * </pre>
 * Or :
 * <pre>
 * CATAdpProtectedComponentsAssociation evolvedComponents;
 * if(SUCCEEDED(Evolutor.Evolve(evolvedComponents))
 * {
 *   CATAdpProtectedComponentsAssociationIter iter(evolvedComponents.GetIterator());
 *   CATIAdpPLMIdentificator *pSource, *pEvolved = NULL;
 *   while(S_OK == iter.NextComponent(pSource, pEvolved))
 *   {
 *      //Do something
 *      CATSysReleasePtr(pSource);
 *      CATSysReleasePtr(pDuplicated);
 *   }
 * }
 * else
 * {
 *    CATIAdpPLMErrorReviewer *pErrorReviewer = NULL;
 *    Evolutor.GetErrorReviewer(pErrorReviewer);
 *    //manage errors
 *    CATSysReleasePtr(pErrorReviewer);
 * }
 *</pre>
 */
class ExportedByCATPLMIntegrationAccess CATAdpProtectedEvolutionMaker
{
public:

  /**
   * Constructor
   * @param iopErrorReviewer
   * An error reviewer.
   * @see CATIAdpPLMErrorReviewer
   */
  CATAdpProtectedEvolutionMaker (CATIAdpErrorMonitor * iopErrorMonitor = NULL);

  /**
   * Constructor
   * @param iIdCloningString
   * The Cloning string identifier which will be given as input of the Business Logic.
   * @param iopErrorReviewer
   * An error reviewer.
   * @see CATIAdpPLMErrorReviewer
   */
  CATAdpProtectedEvolutionMaker (const CATUnicodeString & iIdCloningString, CATIAdpErrorMonitor * iopErrorMonitor = NULL);

  virtual ~CATAdpProtectedEvolutionMaker ();

  /**
   * Add element to evolve<br/>
   *
   * <b>Role</b>: Entry point to add elements for Evolution operation. The elements will be evolved only if the Evolve method is called.
   * When using this method, it is recommended that you also specify a non empty and unique iIdCloningString in the constructor. This
   * string will be passed as input to the PLMIdentificationInitialization business logic or be set as prefix of the identifier set if
   * no relevant business logic is found. If iIdCloningString is not specified and components are add this way, naming conflicts may
   * prevent the cloning operation.
   * Please note that CAA attributes are always copied.
   *
   * @param *ipAdpIdentificator [in] : The element to evolve.
   *   Elements must be of a PLM type compliant with Evolution protocol (Reference, RepReference, Entity...), else an error will be put in the error monitor at evolution time.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no evolution done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no evolution done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT AddElement(CATIAdpPLMIdentificator *ipAdpIdentificator);

  /**
   * Add element to evolve with specific attributes to be set on the clone.<br/>
   *
   * <b>Role</b>: Entry point to add elements for Evolution operation. The elements will be evolved only if the Evolve method is called.
   * The attribute set @href CATAdpAttributeSet is associated to the adp identificator @href CATIAdpPLMIdentificator. The given attributes
   * will complete and may overwrite the ones retrieved through the PLMIdentificationInitialization business logic.
   * When using this method, it is recommended that you also specify a non empty and unique iIdCloningString in the constructor. This
   * string will be passed as input to the PLMIdentificationInitialization business logic or be set as prefix of the identifier set if
   * no relevant business logic is found. If iIdCloningString is not specified and components are add this way, naming conflicts may
   * prevent the cloning operation.
   * Please note that CAA attributes are always copied.
   *
   * @param *ipAdpIdentificator [in] : The element to evolve.
   *   Elements must be of a PLM type compliant with Evolution protocol (Reference, RepReference, Entity...), else an error will be put in the error monitor at evolution time.
   *
   * @param &iAdpAttributeSet [in] : The attributes which will be overriden.
   *   The modified attributes must only be of string type.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no evolution done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no evolution done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT AddElement(CATIAdpPLMIdentificator *ipAdpIdentificator, const CATAdpAttributeSet &iAdpAttributeSet);

  /**
   * Launch Evolution operation.<br/>
   *
   * <b>Role</b>: The Evolution is done on the server at this very moment.
   * Elements are allowed to be in session.
   * Elements won't be replaced in session.
   * This method won't return the cloned components.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no evolution done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no evolution done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT Evolve();


  /**
   * Launch Evolution operation.<br/>
   *
   * <b>Role</b>: The Evolution is done on the server at this very moment.
   * Elements are allowed to be in session.
   * Elements won't be replaced in session.
   * This method will return the cloned components.
   * The components which were not added to this class but which were evolved though (ie. instances, connexions, ports...)
   * will be present in output.
   *
   * @param oComponentsAssociation [out]
   *   Association of original components and evolutions (output of evolution operation). Every evolved component will be here.
   *
   * @return
   *   <dl>
   *   <dt><code>S_OK</code> Operation succeeded <dd>
   *   <dt><code>E_FAIL</code> Error were encountered, no evolution done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   <dt><code>E_UNEXPECTED</code> Error were encountered, no evolution done. See error reviewer content to fetch errors details. Nothing was done during the operation<dd>
   *   </dl>
   */
  HRESULT Evolve(CATAdpProtectedComponentsAssociation & oComponentsAssociation);


  /**
   * Get the error reviewer.
   * @param oErrorReviewer [out, CATBaseUnknown#Release]
   *   Reviewer containing errors
   * @see CATIAdpPLMErrorReviewer
   */
  HRESULT GetErrorMonitor(CATIAdpErrorMonitor *& oErrorReviewer);

private:
  /*
   * @nodoc
   */
  CATAdpProtectedEvolutionMaker (CATAdpProtectedEvolutionMaker &);
  /*
   * @nodoc
   */
  CATAdpProtectedEvolutionMaker& operator=(CATAdpProtectedEvolutionMaker&);

  CATAdpProtectedEvolutionMakerImpl *_pImpl;
};

//-----------------------------------------------------------------------

#endif
