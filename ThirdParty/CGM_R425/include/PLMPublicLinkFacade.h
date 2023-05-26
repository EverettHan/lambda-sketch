// COPYRIGHT Dassault Systemes 2013

/**
 * @CAA2Level L1
 * @CAA2Usage U1
*/

#ifndef PLMPublicLinkAccess_H
#define PLMPublicLinkAccess_H

#include "CATObjectModelerBase.h"

#include "CATSysBoolean.h" // CATBoolean
#include "IUnknown.h" // HRESULT
#include "CATErrorDef.h" // MAKE_HRESULT

/** @nodoc HRESULT encoding. */
#define PLMLINK_MAKE_HRESULT(mask, id) MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, (mask | ((id) & 0xff)))

/** The Link facade on which method has been called is invalid, or referencing a NULL or destroyed Link. */
#define E_PLMLINK_INVALIDFACADE PLMLINK_MAKE_HRESULT(0xBE00, 0x1)

/** The Link on which FACADE method has been called does not provided any Synchronization behavior. */
#define E_PLMLINK_NOSYNCHRONIZATIONBEHAVIOR PLMLINK_MAKE_HRESULT(0xBE00, 0x2)

/** The Link on which FACADE method has been called is internal to pointing component : information asked is irrelevant. */
#define E_PLMLINK_INTRACOMPONENTLINK PLMLINK_MAKE_HRESULT(0xBE00, 0x3)

class CATOmbObjectInContext_var ;
class CATListPtrCATIAdpPLMIdentificator ;
class PLMLinkFacadeImpl ;


/**
 * Class representing a Link.
 * <b>Role</b>: This class is a Facade object providing access to a Link.
 * <br>It gathers in a single place all operations and information gathering that can proceeded on a Link.
 */
class ExportedByCATObjectModelerBase PLMPublicLinkFacade 
{

public : 
    
    /**
     * Constructs an empty PLMPublicLinkAccess.
     */
    PLMPublicLinkFacade () ;

    /**
     * Copy constructor.
     * <br><b>Role</b>: This method creates an exact copy of a Link Facade.
     * @param iLinkFacade [in]
     *   The Facade to copy.
     */
    PLMPublicLinkFacade (const PLMPublicLinkFacade & iLinkFacade) ;

    /**
      * Assignment operator.
      * <br><b>Role</b>: This method transforms this Facade to an exact copy of another Feature Facade.
      * @param iLinkFacade [in]
      *   The Facade to copy.
      * @return
      *   This Facade.
      */
    PLMPublicLinkFacade & operator = (const PLMPublicLinkFacade & iLinkFacade) ;

    /**
     * Destructor.
     */
    virtual ~PLMPublicLinkFacade () ;

    /**
     * Retrieves the pointed CATOmbObjectInContext instance value.
     * See @href CATOmbObjectInContext.
     * @param oObjectInContext [out]
     *   A smart pointer to the object in context retrieved.
     *   <br>In case of failure, NULL will be assigned to it.
     * @return 
     *   An HRESULT value.
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK</dt>
     *     <dd>A non NULL object in context has been retrieved.</dd>
     *     <dt>E_PLMLINK_INVALIDFACADE</dt>
     *     <dd> The Facade is not valid.</dd>
     *     <dt>Other</dt>
     *     <dd>Other hresults can occur if the set pointed PLM component could not be loaded or does not exist any more.
     *     <dd>In these cases, more information on the cause can be obtained with @href CATOmbLinkStatusServices#GetLinkStatusFromRc.</dd>
     *  </dl>
     */
    HRESULT GetPointedObjectInContext (CATOmbObjectInContext_var & oObjectInContext) const ;

    /**
     * Retrieves the identifiers of the PLM Components referenced by the Link.
     * See @href CATIAdpPLMIdentificator.
     * @param oIdentifiers [out]
     *   A list that contains the identifiers. Use @href CATAdpOpener to load it if necessary. 
     *   <br>Don't forget to call @href CATIAdpPLMIdentificator#Release on each returned identifiers when useless.
     *   <br>In case of failure, list will be empty.
     * @return 
     *   An HRESULT value.
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK</dt>
     *     <dd>The exhaustive non empty list of identifiers has been retrieved.</dd>
     *     <dt>E_PLMLINK_INVALIDFACADE</dt>
     *     <dd> The Facade is not valid.</dd>
     *     <dt>E_PLMLINK_INTRACOMPONENTLINK</dt>
     *     <dd> The Link is internal to the pointing PLM Component.</dd>
     *     <dt>E_UNEXPECTED</dt>
     *     <dd>The query failed for any other reason.</dd>
     *  </dl>
     */
    HRESULT GetPointedComponentIdentifiers (CATListPtrCATIAdpPLMIdentificator & oIdentifiers) const ;

    /**
     * Retrieves the Synchronization status of the Link.
     * @return 
     *   An HRESULT value.
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK</dt>
     *     <dd>The link is synchronized.</dd>
     *     <dt>S_FALSE</dt>
     *     <dd>The link is not synchronized.</dd>
     *     <dt>E_PLMLINK_NOSYNCHRONIZATIONBEHAVIOR</dt>
     *     <dd> No Synchronization behavior is defined on the Link.</dd>
     *     <dt>E_PLMLINK_INVALIDFACADE</dt>
     *     <dd> The Facade is not valid.</dd>
     *     <dt>E_UNEXPECTED</dt>
     *     <dd>The query failed for any other reason.</dd>
     *  </dl>
     */
    HRESULT IsSynchronized () const ;

    /**
     * Synchronize the link (See IsSynchronized).
     * @return 
     *   An HRESULT value.
     *   <br><b>Legal values</b>:
     *   <dl>
     *     <dt>S_OK</dt>
     *     <dd>The link synchronization succeeded.</dd>
     *     <dt>S_FALSE</dt>
     *     <dd>The link is already synchronized.</dd>
     *     <dt>E_PLMLINK_NOSYNCHRONIZATIONBEHAVIOR</dt>
     *     <dd> No Synchronization behavior is defined on the Link.</dd>
     *     <dt>E_PLMLINK_INVALIDFACADE</dt>
     *     <dd> The Facade is not valid.</dd>
     *     <dt>E_UNEXPECTED</dt>
     *     <dd>The query failed for any other reason.</dd>
     *  </dl>
     */
    HRESULT Synchronize () ;

protected : 

    PLMLinkFacadeImpl * _pImpl ;

} ;

#endif

