#ifndef CATOmbSessionService_H
#define CATOmbSessionService_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003

// ObjectModelerBase
/**
 * @level Protected 
 * @usage U1
 */

// System
#include "IUnknown.h" // for HRESULT
#include "CATLib.h"
#include "AC0XXLNK.h"

class CATOmbSessionContext;

/**   
 * Base Class to create ObjectModelerBase service.
 * It must be derived to create your own services.
 */
class ExportedByAC0XXLNK CATOmbSessionService
{

public:
  /** 
   * Instanciates a service.
   * <br><b>Role</b>: This constructor instanciates this services. It must not be instanciated by a new.
   * @param ipSessionContext [in]
   *   This services is associated to the session identified by its context, <tt>ipSessionContext</tt>. If it
   * is not set, this service is associated to the current session.
   */
  CATOmbSessionService(CATOmbSessionContext *ipSessionContext);

	// destructor is not virtual because we don't wan't the cost of a function table
	// => don't override it.
	~CATOmbSessionService();


private:
	// copy constructor should not be implemented
	CATOmbSessionService(const CATOmbSessionService& ICOPY);

	// = operator should not be implemented
	CATOmbSessionService operator=(CATOmbSessionService& ICOPY);

	CATOmbSessionContext *m_sessionContext;

  // BHG: services must no be instanciated by a new
  // BHG, CATPDMClusterRestrictedAccess class make a new CATOmbSessionService.
  // The fix is delivered and will soon come in BSF. When it is done, this operator must be un commented
  void* operator new(size_t);
};

#endif
