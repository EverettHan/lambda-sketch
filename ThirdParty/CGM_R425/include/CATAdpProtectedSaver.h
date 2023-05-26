/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpProtectedSaver_H
#define CATAdpProtectedSaver_H

#include "CATPLMIntegrationAccess.h"
#include "CATBooleanDef.h"
#include "CATOmxSR.h"
#include "CATListPtrCATIPLMComponent.h"
#include "CATCollec.h"
class CATPLMComponentData;
class CATIPLMSaveScope;
class CATIAdpErrorMonitor;
class CATIPLMListConsultation;
class CATAdpProtectedSaverImpl;
class CATPLMIDSet;
class CATPLMID;
class CATLISTV(CATPLMID);
class CATLISTP(CATIAdpPLMIdentificator);

class ExportedByCATPLMIntegrationAccess CATAdpProtectedSaver
{
public:

/**
 * Builds a Component Saver enabling to Propagate modifications in a connected database.
 * <br><b>Role:</b>Gives access point enabling to compute a save scope and/or perform a Propagation of the 
 * modified data in a connected repository.
 *
 * @param iComponentsToSave [in]
 * The Components you need to propagate to the database. 
 * <ul>
 * <li>Depending on the algorithm which you will chose for Propagate, it is a Root for Save or a single Component.</li>
 * <li>If no Component is given, the whole Authoring Session content will be Propagated (if modified).</li>
 * </ul>
 * @param iErrorMonitor [in]
 * <ul>
 *   <li>The Error Monitor dedicated to store and handle all PLM Errors raised during the execution of this operation.</li>
 *   <li>It can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.</li>
 *   <li>If not given, you can retrieve it through @href GetErrorMonitor entry point.</li>
 * </ul>
 */
  CATAdpProtectedSaver( const CATLISTP(CATIPLMComponent) & iComponentsToSave, CATIAdpErrorMonitor * iErrorMonitor=0 );

/**
 * Builds a Component Saver enabling to Propagate all the modifications of the Authoring Session in a connected database.
 * <br><b>Role:</b>Gives access point enabling to compute a save scope from the whole Authoring Session with the intent of Propagating it to the connected database.
 *
 * @param iErrorMonitor [in]
 * <ul>
 *   <li>The Error Monitor dedicated to store and handle all PLM Errors raised during the execution of this operation.</li>
 *   <li>It can be created through the @href CATAdpErrorMonitorFactory#CreateErrorMonitor entry point.</li>
 *   <li>If not given, you can retrieve it through @href GetErrorMonitor entry point.</li>
 * </ul>
 */
  CATAdpProtectedSaver( CATIAdpErrorMonitor * iErrorMonitor=0 );

  virtual ~CATAdpProtectedSaver();


/**
 * Computes a Save scope.
 * <br><b>Role:</b>Given the input Components, computes the Save Scope which will be propagated when calling the @href Save entry point.
 * <ul>
 * <li>If data were given as input, it will be used as roots for the Scope computation.</li>
 * <li>If no data was given as input, the whole Session will be computed.</li>
 * <li>Deleted Components cannot be seen through this API since @href CATPLMComponentData only deals with "alive" Components.</li>
 * </ul>
 *
 * @param oComponents [out]
 * The Components which will be propagated to the database if the @href Save entry point is called.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the computation was successful.</li> 
 *   <li><tt>E_FAIL</tt> if the computation could not be performed.</li>
 *  </ul>
 */
  enum AdpScopeFilter { AllComponents=0, OnlyModifiedInSession=1 };
  HRESULT ComputeSaveScope( CATPLMComponentData & oComponents, AdpScopeFilter iFilterOnResults=AllComponents );

/**
 * Computes a Save scope.
 * <br><b>Role:</b>Given the input Components, computes the Save Scope which will be propagated when calling the @href Save entry point.
 * <ul>
 * <li>If data were given as input, it will be used as roots for the Scope computation.</li>
 * <li>If no data was given as input, the whole Session will be computed.</li>
 * <li>Session information can be obtained on Components by using combination of @href CATPLMSpaceServices#GetResolutionSpace and @href CATIPLMSpace#SearchComponentInSession.</li>
 * </ul>
 *
 * @param oComponents [out]
 * The Components which will be propagated to the database if the @href Save entry point is called.
 * @param iFilterOnResults [in]
 * The filter applied on retrieved Components.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the computation was successful.</li> 
 *   <li><tt>E_FAIL</tt> if the computation could not be performed.</li>
 *  </ul>
 */
  HRESULT ComputeSaveScope( CATPLMIDSet & oComponents, AdpScopeFilter iFilterOnResults=AllComponents );
  HRESULT ComputeSaveScope( CATLISTV(CATPLMID) & oComponents, AdpScopeFilter iFilterOnResults=AllComponents );
  HRESULT ComputeSaveScope( CATLISTP(CATIAdpPLMIdentificator) & oComponents, AdpScopeFilter iFilterOnResults=AllComponents );

/**
 * Performs a Propagation of the modified components in the database.
 * <br><b>Role:</b>This methods computes the Save scope based on given input (if not already computed) and propagates the result in the database.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the Save was successful.</li> 
 *   <li><tt>E_FAIL</tt> if Save failed. Errors encountered can be read on the @href CATIAdpErrorMonitor.</li>
 *  </ul>
 */
  HRESULT Save();

/** 
 * Saves the given components if it is self sufficient for data integrity.
 * <br><b>Role</b>: This method will save the given components if and only if the given components are consistants for data integrity.
 * If one of the components save would trigger a save action on a component that doesn't belong to the given list, the save of the whole
 * component list will fail. Blocking errors can be accessed on the given @href CATIAdpErrorMonitor.
 * <ul><li><code>ERR_01_SAVE</code> error is available if the given list isn't self sufficient for saving.</li></ul>
 * 
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the Save was successful.</li>
 *   <li><code>E_INVALIDARG<code> if no Component was given as input of the @href CATAdpProtectedSaver.</li>
 *   <li><code>E_FAIL</code> if an error occured. Errors encountered can be read on the @href CATIAdpErrorMonitor.</li>
 *   </ul>
 */
  HRESULT SaveOnlyGivenComponents();

/**
 * Gets the @CATIAdpErrorMonitor enabling to parse the errors.
 * <br><b>Role:</b>This method enables to retrieve a pointer on the @href CATIAdpErrorMonitor enabling to parse the errors which occured during the process.
 *
 * @param oErrorMonitor [out, CATBaseUnknown#Release]
 * The Error Monitor.
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the Error Monitor was retrieved.</li> 
 *   <li><tt>E_FAIL</tt> if the Error Monitor was not retrieved.</li>
 *  </ul>
 */
  HRESULT GetErrorMonitor( CATIAdpErrorMonitor *& oErrorMonitor );

private:
  CATAdpProtectedSaver( const CATAdpProtectedSaver & );
  CATAdpProtectedSaver & operator =( const CATAdpProtectedSaver & );

private:
  CATAdpProtectedSaverImpl * _Saver;
};
#endif
