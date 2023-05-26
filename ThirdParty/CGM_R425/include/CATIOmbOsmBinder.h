#ifndef __CATIOmbOsmBinder_h__
#define __CATIOmbOsmBinder_h__ 3

/**
 * @level Private
 * @usage U3
 * COPYRIGHT Dassault Systemes 2011
 */

// CATIOmbOsmBinder.h
// Interface realizing the binding between Omb and Osm:
// Services implemented specifically by OSM on this interface are usable from dedicated OMB entities
//
// This interface is migrated from previous V5R21 CATIOmbContainerForUnload interface
//
// TO BE IMPLEMENTED ONLY BY FEATURE MODELER

// System
#include "CATBaseUnknown.h"
#include "CATError.h"
// ObjectModelerBase
class CATDocument;
class CATIUndoTransaction;
// ObjectModelerCollection
#include "CATOmxOHMap.h"
#include "CATOmxIter.h"
#include "CATOmxPortability.h"
#include "CATOmxVector.h"
// ObjectModelerBase
#include "AD0XXBAS.h"

extern ExportedByAD0XXBAS IID IID_CATIOmbOsmBinder;

namespace Catalog
{
  /**
   * The V6ToV5 compliance state for a catalog used by a V6 Authoring Document (to) downgrade(d) in V5 :
   * @param UndefCompliance
   *   The compliance has been yet determined or cannot be determined.
   * @param NoCompliance
   *   The catalog is not described as compliant for a V6Tov5 document downgrade
   * @param PartialCompliance
   *   Some startups into the catalog are described as compliant for a V6Tov5 document downgrade
   * @param FullCompliance
   *   The catalog is described as full compliant for a V6Tov5 document downgrade
   */
  enum DwndCompliance {UndefCompliance, NoCompliance , PartialCompliance, FullCompliance};
}

// THIS INTERFACE IS TO BE IMPLEMENTED ONLY BY FEATURE MODELER
class ExportedByAD0XXBAS CATIOmbOsmBinder: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  // Following Services have to be implemented specifically by OSM to be usable on OMB side:
  /**
   * Cleans invalid links from a given feature document
   * <br><b>Role:</b> Cleans invalid links from a given feature document
   * <br> applying CATDUA rules DOC_3, DOC_4, DOC_8
   * @param ipAuthoringDoc [in]
   *     The V6 document linked to the main Authoring StreamDescriptor of the RepRef, globally loaded in session
   * @return
   * <br>  : SUCCEEDED : eventual clean successfull
   * <br>  : FAILED : internal error
   */                                        
  virtual HRESULT CleanDocumentLinks(CATDocument& ipAuthoringDoc) = 0;

  virtual CATBoolean IsCatalogRemovable(CATDocument& iCatalog) = 0;

  virtual bool IsAResourceCatalog(CATDocument & iDocument) = 0;
  
#if OMX_CODE_PHASE == 1

  /**
   * Emit InstanciatedEvent or RemoveEvent for CAA
   * <br><b>Role:</b> Emit InstanciatedEvent or RemoveEvent for CAA
   * @param iListOfFeatures [in]
   *     The list of feature to be destroyed/created 
   * @param iInstanciateEvent [in]
   *     if TRUE emit InstanciatedEvent else RemoveEvent
   */                                    
  virtual void EmitCaaEvents(CATOmxVector<CATBaseUnknown> iListOfFeatures, CATBoolean iInstanciateEvent) = 0;

  /**
   * Get a Vector containing deleted or created object during a given transaction
   */
  virtual void GetUndoRedoObject(CATIUndoTransaction* iCont, int ID, int mode, CATOmxVector<CATBaseUnknown>& oVect) = 0;
  
  /** 
   * Determines if a specific container can be unloaded
   *    
   * @return
   *   <code>S_OK</code> container can be unloaded
   *   <code>S_FALSE</code> container cannot be unloaded; document cannot be unloaded
   *   <code>E_*</code> unexpected error. document cannot be unloaded
   *
   */
  virtual HRESULT IsContainerUnloadable(const CATBaseUnknown * ipContainer) = 0;

#endif
  
#if OMX_CODE_PHASE == 2

  /**
  * Gets the V6 to V5 catalogs compliance report for an Authoring document
  * <br><b>Role:</b> Gets the V6 to V5 compliance report about all feature catalogs pointed by 
  * <br> an authoring document globally loaded in session
  * @param ipAuthoringDoc [in]
  *     The V6 document linked to the main Authoring StreamDescriptor of the RepRef, globally loaded in session
  * @param oComplianceErrors [out]
  *      the list of compliance errors eventually raised by compliance analysis
  * @param obCompliant [out]
  *     The global compliance value:
  *     TRUE  : The document IS V6ToV5 compliant regarding its pointed feature catalogs
  *     FALSE : The document is NOT V6ToV5 compliant regarding its pointed feature catalogs
  *             and cannot be downwarded from V6 To V5
  * @return
  * <br>  : SUCCEEDED : error reporting is available
  * <br>  : E_FAIL : internal error, cannot read compliance status. obCompliant is FALSE.
  */  
  virtual HRESULT IsDocV6ToV5CatalogCompliant(CATDocument& ipAuthoringDoc, CATOmxIter<CATError>& oComplianceReport, CATBoolean& obCompliant) = 0;

  /**
   * Gets the V6 to V5 catalogs compliance report for an Authoring document
   * <br><b>Role:</b> Gets the V6 to V5 compliance report about all feature catalogs pointed by
   * <br> an authoring document globally loaded in session
   * @param ipAuthoringDoc [in]
   *     The V6 document linked to the main Authoring StreamDescriptor of the RepRef, globally loaded in session
   * @param oFeatureErrorList [out]
   *      the list of features which are not compliant V6toV5
   * @param obCompliant [out]
   *     The global compliance value:
   *     TRUE  : The document IS V6ToV5 compliant regarding its pointed feature catalogs
   *     FALSE : The document is NOT V6ToV5 compliant regarding its pointed feature catalogs
   *             and cannot be downwarded from V6 To V5
   * @return
   * <br>  : SUCCEEDED : error reporting is available
   * <br>  : E_FAIL : internal error, cannot read compliance status. obCompliant is FALSE.
   */
  virtual HRESULT IsDocV6ToV5CatalogCompliant(CATDocument& ipAuthoringDoc, CATOmxVector<CATBaseUnknown>& oFeatureErrorList, CATBoolean& obCompliant) = 0;

  /**
   * Cleans Catalog Manager link for V6 to V5 only
   */
  virtual HRESULT CleanCatalogManager(CATDocument& ipAuthoringDoc) = 0;

  /**
   * Isolate features located in CATDrwMirrorCont container.
   * Inter-component instance/reference links of features located in a CATDrwMirrorCont container are rerouted to their startup.
   *
   * @param ioDocument [in]
   *     The V6 document linked to the main Authoring StreamDescriptor of the RepRef, globally loaded in session
   * @return
   *     Isolation success or failure.
   */
  virtual HRESULT IsolateDrwMirrorCont(CATDocument & ioDocument) = 0;

#endif

};


#endif
