#ifndef CATITosStreamDescriptorStreamAccess_H
#define CATITosStreamDescriptorStreamAccess_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
 * @level Private
 * @usage U3
 */

#define NEWTOSINHERITANCE

#include "ExportedByCATPLMTos.h"
#include "CATBoolean.h"
#include "CATTosTodoLevel.h"
#include "CATBaseUnknown.h"
#include "CATOmxKeyString.h"
#include "CATIAV5Level.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATITosStreamDescriptorStreamAccess;
#else
extern "C" const IID IID_CATITosStreamDescriptorStreamAccess;
#endif

class CATVVSUrl;
class CATVVSURLConnection;
class CATOmyVVSURLConnectionHolder;
class CATUnicodeString;

#define CATITosStreamDescriptorStreamAccessNewFormatManagement 1

/**
 * Restricted access for managing stream descriptor persistency
 */
class ExportedByCATPLMTos CATITosStreamDescriptorStreamAccess : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
   * Returns CuteIO identifier of current stream iteration
   *
   * @param oURL
   *     Returned a clone UrlConnection to access the stream. You MUST delete the UrlConnection
   * @param oWS
   *     ieration of the stream
   * @return
   *   <code>S_OK</code> Always
   */
  virtual HRESULT GetCurrentSDStreamAccess(CATVVSURLConnection*& oURL, unsigned int& oWS) = 0;

  /**
   * Sets the new location of the stream in the Vault/LocalVault
   *
   * @param iURL [in]
   *   UrlConnection will be cloned
   * @param iWS [in]
   *   Stream iteration stored in vault
   *
   * @return
   *   <code>S_OK</code> if success
   *   <code>E_FAIL</code> if failure
   *
   */
  virtual HRESULT SetSDStreamAccessInVault(CATVVSUrl& iURL, unsigned int iWS) = 0;

  /**
   * Gets the new location of the stream in the Vault/LocalVault
   *
   * @param iURL [in]
   *   UrlConnection will be cloned
   * @param iWS [in]
   *   Stream iteration stored in vault
   *
   * @return
   *   <code>S_OK</code> if success
   *   <code>S_FALSE</code> if SD is not associated to a stream (CNX without stream)
   *   <code>E_FAIL</code> if failure
   *
   */
  virtual HRESULT GetSDStreamAccessInVault(CATVVSUrl& oURL, unsigned int& oWS) = 0;

  /**
   * Returns CuteIO Holder for current stream iteration.
   * Used only during Local Save/Save transaction as local stream target (entry in vault)
   *
   * @param opConnectionHolder
   *     Returned a clone CATOmyVVSURLConnectionHolder.
   *	  You have to release it after use.
   *   <code>S_OK</code> Always
   */

  virtual HRESULT GetCuteIOConnexionHolder(CATOmyVVSURLConnectionHolder*& opConnectionHolder) const = 0;

  virtual CATOmxKeyString GetFormatAsKey() const = 0;

  /**
   * @return
   *      The stream descritor role.
   */
  virtual CATUnicodeString GetRole() = 0;

  /**
   * @return
   *      The stream descritor late type.
   */
  virtual CATUnicodeString GetLateType() = 0;

  /**
   * @return
   *      The stream descritor presistency name.
   */
  virtual CATUnicodeString GetPersistencyName() = 0;

  /**
   * @return
   *      The stream descritor persistency type
   */
  virtual CATUnicodeString GetPersistencyType() const = 0;

  /**
   * @return
   *      The stream descritor synchro stamp
   */
  virtual HRESULT GetSynchroStamp(int  &  oSMS) = 0;

  /**
   * Returns the modification status according to LOG level.
   *
   * @param iTodoLevel
   *     The LOG level Global/Differential.
   * @param oIsModified
   *     The modification status.
   * @return
   *     An HRESULT value.
   *     <br><b>Legal values</b>:
   *     <ul>
   *         <li><tt>S_OK</tt> if succeeded.</li>
   *         <li><tt>E_FAIL</tt> if failed.</li>
   *     </ul>
   */
  virtual HRESULT IsModified(CATTosTodoLevel iTodoLevel, CATBoolean & oIsModified) = 0;


};

CATDeclareHandler(CATITosStreamDescriptorStreamAccess, CATBaseUnknown);
#endif
