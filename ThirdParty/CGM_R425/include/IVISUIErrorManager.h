#ifndef IVISUIErrorManager_H
#define IVISUIErrorManager_H

// COPYRIGHT Dassault Systemes 2017

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATError.h"


/**
 * IVISUIErrorManager
 *
 * Interface to propose services around the errors detected during SUI activation
 *
 * @example
 * <pre>
 *
 * // Get SUI Error Manager
 * IVISUIErrorManager* pSUIErrorManager = IVISUIErrorManager::GetManager();
 */
class ExportedByIVInterfaces IVISUIErrorManager : public CATBaseUnknown
{

  CATDeclareClass;

public:

  /**
  * Retrieves the unique @href IVISUIErrorManager instance.
  *
  * @return
  *     The @href IVISUIErrorManager instance.
  *
  * <br><strong>Lifecycle rules deviation</strong>:
  * The @href IVISUIErrorManager is a Singleton. Its lifecycle is automatically handled by the iV framework.
  * The returned pointer should never be <tt>NULL</tt>, and the caller should <strong>never</strong> try and delete it.
  */
  static IVISUIErrorManager* GetManager();

  /**
  * Add a message in a log file.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The request succeeds</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The request doesn't succeed</dd>
  *   </dl>
  */
  virtual HRESULT AddMessageInLogFile(CATUnicodeString iMessage) = 0;

  /**
  * Save the errors in a log file.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The request succeeds</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The request doesn't succeed</dd>
  *   </dl>
  */
  virtual HRESULT SaveInLogFile() = 0;

  /**
  * Cleans the error list.
  */
  virtual void Reset() = 0;

  /**
  * Get the errors count.
  *
  * @return
  *   An int value.
  */
  virtual unsigned int GetErrorCount() const = 0;

  /**
  * Get the errors type.
  *
  * @return
  *   An CATErrorType value.
  */
  virtual CATErrorType GetErrorType() const = 0;

  /**
  * Get the errors type.
  *
  * @return
  *   An CATErrorType value.
  */
  virtual CATUnicodeString GetErrorMessage() const = 0;

  /**
  * Get the errors type.
  *
  * @return
  *   An CATErrorType value.
  */
  virtual CATUnicodeString GetLogFilePath() const = 0;

protected:

  // Instantiation not allowed
  IVISUIErrorManager();

  virtual ~IVISUIErrorManager();

private:

  // Copy not allowed
  IVISUIErrorManager(const IVISUIErrorManager&);

  // Operator = not allowed
  IVISUIErrorManager& operator=(const IVISUIErrorManager&);

};

#endif
