#ifndef CATOmbRerouteIntegrityUnitAssistant_H
#define CATOmbRerouteIntegrityUnitAssistant_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @level Protected
 * @usage U3
 */

#include "CATObjectModelerBase.h"
#include "IUnknown.h"
#include "CATCollec.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

class CATLISTP (CATOmbRerouteRequest) ;
class CATOmbRerouteAssistant ;
class CATOmbRerouteRequest ;

/**
 * Class that defines an assistant for reroute, compliant with PLMIntegrity inter-relations rules. It owns a set of reroute assistants which cannot be 
 * commited individually, to prevent PLMIntegrity violation.
 */
class  ExportedByCATObjectModelerBase CATOmbRerouteIntegrityUnitAssistant
{
public:
    
    /**
     * Generate Reroute Request relating to current assistants resolution state. 
     * @param oRequests
     *   The request.
     */
    virtual void GenerateRequest (CATOmbRerouteRequest & oRequest) const = 0 ;
    
    /**
     * Returns a string describing the current integrity unit.
     * @return
     *	Nls string
     */
    virtual const CATUnicodeString GetNlsMessage () const = 0 ;

    /**
     * Iterate through the assistants.
     * @return
     *	NULL if there are no more assistants to return
     *  otherwise, the next element.
     *  <br><b>Note:</b>The returned element must not be deleted.
     */
    virtual CATOmbRerouteAssistant * operator ++ () = 0 ;

    /**
     * Reset iterator browse on CATOmbRerouteAssistant
     */
    virtual void ResetIterator () = 0 ;    

    /**
     * Cancel the reroute: don't do any modifications to the relations inside the integrity unit referenced by this assitant.
     * @return
     *  An HRESULT value
     * <dl>
     *  <dt>E_FAIL</dt><dd>The error had already been solved.</dd>
     *  <dt>S_OK</dt><dd>The error was successfully ignored.</dd>
     * </dl> 
     */
    virtual HRESULT Cancel () = 0 ;

    /**
     * Checks whether all the assistants are solved (and consistant regarding PLMIntegrity) or not. 
     * @return
     *	A CATBoolean
     */
    virtual CATBoolean IsCompletellySolved () const = 0 ;

} ;

#endif

