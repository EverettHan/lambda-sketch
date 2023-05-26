// COPYRIGHT Dassault Systemes 2005
/**
 * @level Private
 * @usage U1
 */

#ifndef CATOmbUuidServices_H
#define CATOmbUuidServices_H

#include "AC0XXLNK.h"
#include "CATOmbSessionService.h"

class CATUuid;
class CATDocument;
class CATOmbSessionContext;
//-----------------------------------------------------------------------

/**
 * Restricted service to change Uuid on a document.<BR>
 * This services is only allowed to the class CATDocumentUuidExt.
*/
class ExportedByAC0XXLNK CATOmbUuidServices: public CATOmbSessionService
{  
  public:

    /** 
    * Instanciates this services.
    * <br><b>Role</b>: This constructor instanciates this services. It must not be instanciated by a new.
    * @param ipSessionContext [in]
    *   This services is associated to a session identified by its context (<tt>ipSessionContext</tt>). If this
    * context is not given, this services is associated to the current session.
    */
     CATOmbUuidServices(CATOmbSessionContext* ipSessionContext = NULL);
    /**
     * Releases this services.
     */
     virtual ~CATOmbUuidServices ();

  private:
    friend class CATDocumentUuidExt;
    friend class DWCUUIDServices;
    friend class CATOsmPContainerDef;

    /** 
    * Changes the Uuid on a document.
    * @param iDoc [in]
    *   The given document to change.
    * @param inewUuid [in]
    *   The new uuid to set on the given document <tt>iDoc</tt>.
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.
    */
    HRESULT ChangeDocumentUUID(CATDocument& iDoc, const CATUuid* inewUuid);

  // Copy constructor and equal operator
  // -----------------------------------
  CATOmbUuidServices (CATOmbUuidServices &);
  CATOmbUuidServices& operator=(CATOmbUuidServices&);
};

//-----------------------------------------------------------------------

#endif
