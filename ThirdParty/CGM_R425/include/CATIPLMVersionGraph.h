#ifndef CATIPLMVersionGraph_H
#define CATIPLMVersionGraph_H

#include "CATBaseUnknown.h"
#include "CATPLMIntegrationInterfaces.h"
#include "CATOmxSet.h"
#include "CATOmxOSet.h"
#include "CATOmxOHMap.h"
#include "CATOmxIter.h"
#include "CATIPLMVersionInput.h"
#include "CATOmxOrderedOSet.h"
#include "CATIAV5Level.h"

class CATUnicodeString;
class CATPLMID;
class CATIAdpErrorMonitor;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMVersionGraph;
#else
extern "C" const IID IID_CATIPLMVersionGraph;
#endif

typedef CATOmxOHMap<CATPLMID, CATPLMID> CATPLMIDSimpleMap;

/**
* This interface is dedicated to version graph process
*
* It enables the user to lauch a versioning transaction for a set of components.
*/
class ExportedByCATPLMIntegrationInterfaces CATIPLMVersionGraph : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
   * Add a set of components which will be versioned by the current transaction.
   * If it is an instance, only specified instance for aggregated element will be versioned.
   * You can call multiple times, with the same intent or not.
   * If using the same intent, input PLMIDs will be added. If a plmid already exists, it will be ignored.
   * @param iIntent: the intent needed to specialize the versioning operation.
   * @param iIds: the identifiers of the components which will be versioned.
   * @return
   *   <ul>
   *   <li><code>S_OK</code> Inputs have been added.</li>
   *   <li><code>E_*</code> Input were not added.</li>
   *   </ul>
   */
  virtual HRESULT AddInputData(const CATUnicodeString & iIntent, const CATOmxOrderedOSet<CATPLMID> & iIds) = 0;
#if !defined(CATIAR424)
  //Do not use
  virtual HRESULT AddInputData(const CATUnicodeString & iIntent, const CATOmxOSet<CATPLMID> & iIds) = 0;
#endif

  /**
  * Add a set of components which will be versioned by the current transaction.
  * You can only specify one same couple PLMID/Intent
  * If specifying the same couple PLMID/Intent, it will be ignored.
  * @param iInputData: input data.
  * @return
  *   <ul>
  *   <li><code>S_OK</code> Inputs have been added.</li>
  *   <li><code>E_*</code> Input were not added.</li>
  *   </ul>
  */
  virtual HRESULT AddInputData(const CATOmxSet<CATIPLMVersionInput> & iInputData) = 0;

  /**
  * Allows the user to declare that the new created components will replace the input data in the session when loaded.
  * This will lead to the deletion of the instance of the old component and the creation of an instance of the new component.
  * If the replace operation is activated but not possible due to specific conditions (see Restrictions), the RunVersionGraph operation will fail and nothing will be done in the database.
  *
  * Restrictions:
  * <ul>
  * <li>The instances of the versioned component must not be VPLM controlled</li>
  * <li>The instances of the versioned component must not be configured</li>
  * <li>You cannot use partial instance duplication with this mode</li>
  * <li>The editability status of the instances of the versioned component must make sure that the user will be able to commit the replace operation to the database</li>
  * </ul>
  *
  */
  virtual void ActivateReplaceInSession() = 0;

  /**
  * Allows the user to declare that the new created components will receive current modifications.
  * If you modify an already saved reference, then activate this mode, the versioned reference will be loaded with the modifications.
  * If you create a new instance of a reference, don't save it and make a new version of the parent reference (which is saved), 
  * then the new instance will instanciate the new component. 
  * Said differently, the parent of the new instance will be the versioned reference.
  * In each case, old reference will still be loaded in a new session component (which will be loaded in the bag you provided), 
  * without the made modifications which are transferred to the versionned component.
  * See FUN107568 PES for a more detailed presentation.
  * A bag is mandatory.
  * There is no such restrictions as the ActivateReplaceInSession as instances are not deleted.
  * @return
  *   <ul>
  *   <li><code>S_OK</code> Operation completed successfully.</li>
  *   <li><code>E_FAIL</code> No bag specified with SetLifeCycleBag() on the CATPLMComponentManagementBuilder</li>
  *   </ul>
  */
  virtual HRESULT ActivateTransferModifications() = 0;

  /**
  * If called, no instances will be versioned by default.
  * You will have to specify the full list of instances to make version of.
  * Restrictions:
  * <ul>
  * <li>You cannot use replace in session with this mode</li>
  * </ul>
  */
  virtual void SpecifyExplicitInstances() = 0;

  /**
  * Run the operation on the server.
  * @return
  *   <ul>
  *   <li><code>S_OK</code> Operation completed successfully.</li>
  *   <li><code>E_*</code> Operation was aborted because of an error.</li>
  *   </ul>
  */
  virtual HRESULT RunVersionGraph() = 0;

  /**
  * Get the components which have been created during the transaction. This set includes the new versions of the input components and the aggregated components which have been cloned together with the given input.
  * @output oIds: the new components.
  */
  virtual HRESULT GetNewComponents(CATOmxOSet<CATPLMID> & oIds) = 0;
  virtual HRESULT GetNewComponents(CATOmxOrderedOSet<CATPLMID> & oIds) = 0;

  /**
  * Get every versioned components, each old version being a key and each new version the corresponding value. This map may contain more elements than passed in input (ie. the aggregated components which have been cloned together
  * with the given input).
  * You can get every source of versionned components using Keys() method on the map, and every result versionned components using Values() method on the map.
  * You can also get corresponding versionned elements using key and corresponding values.
  * You can also iterate on each pair of versions.
  * @see CATOmxOHMap for more information on map usage.
  * @output oResults: map assiociation between old (source) and versionned components. It contains every versionned components.
  */
  virtual HRESULT GetResults(CATPLMIDSimpleMap & oResults) = 0;


  /*
  * <li>Get an error monitor to iterate through errors.</li>
  */
  virtual HRESULT GetErrorMonitor(CATIAdpErrorMonitor *& oErrors) = 0;

};

#endif
