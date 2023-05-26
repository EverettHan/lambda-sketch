#ifndef _CATAdpPDMLogWriter_H
#define _CATAdpPDMLogWriter_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Private
 * @usage U1       
 */
#define AuthorizedModule                  999
#define CATPLMNavDlgServices              AuthorizedModule
#define CATPLMIntegrationAccess           AuthorizedModule
#define CATPLMItgTestIntegrationAccess             AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
      #error Forbidden access to CATAdpPDMLogWriter from a non-infrastructure module
        @error 
#endif
#undef CATPLMNavDlgServices
#undef CATPLMIntegrationAccess
#undef CATPLMItgTestIntegrationAccess
#undef CATPLMIntegration

#include "IUnknown.h"
#include "CATPLMIntegrationAccess.h"
#include "CATBoolean.h"
#include <stdlib.h>

class CATPLMID;
class CATxPDMLogWriter;

// Entry point for creating a new save log.
// This class is intended to be used by the save engines.

class ExportedByCATPLMIntegrationAccess CATAdpPDMLogWriter
{
public:
  /**
  * Constructor 
  * Must be instanciated only if necessary
  */
  CATAdpPDMLogWriter();

  /**
  * destructor
  */
  ~CATAdpPDMLogWriter();

  /**
  * Check if PDM Log is activated
  *
  * @return
  *   TRUE  : PDM is activated
  *   FALSE : PDM is not activated
  */
  static CATBoolean IsPDMLogActivated();

  /**
  * Init
  *   Initializes the writer with no logged data
  *
  * @return
  *   S_OK if the initialization process succeeded
  *   S_FALSE if xPDMLog is NOT activated
  *   E_FAIL otherwise
  */
  HRESULT Init ();

  /**
  * Append PLMID to log creation
  *
  * @param iPLMID
  *   The PLMID of a REFERENCE to log in the save log file
  *
  * @return
  *   S_OK if the entry was correctly added
  *   S_FALSE if xPDMLog is NOT activated
  *   E_FAIL otherwise
  */
  HRESULT LogAsCreated (const CATPLMID & iPLMID);

  /**
  * Append PLMID to log modification
  *
  * @param iPLMID
  *   The PLMID of a REFERENCE to log in the save log file
  *
  * @return
  *   S_OK if the entry was correctly added
  *   S_FALSE if xPDMLog is NOT activated
  *   E_FAIL otherwise
  */
  HRESULT LogAsModified (const CATPLMID & iPLMID);

    /**
  * Append PLMID to log deletion
  *
  * @param iPLMID
  *   The PLMID of a REFERENCE to log in the save log file
  *
  * @return
  *   S_OK if the entry was correctly added
  *   S_FALSE if xPDMLog is NOT activated
  *   E_FAIL otherwise
  */
  HRESULT LogAsDeleted (const CATPLMID & iPLMID);

  /**
  * Commit result on file system
  */
  HRESULT Commit ();

private:

  // Forbidden operators 
  CATAdpPDMLogWriter (CATAdpPDMLogWriter&);
  CATAdpPDMLogWriter& operator=(CATAdpPDMLogWriter&);
  void * operator new(size_t, CATAdpPDMLogWriter&);

  CATxPDMLogWriter * _LogWriter;
};

#endif






