/* -*-c++-*- */
#ifndef CATDocEnvManager_H
#define CATDocEnvManager_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @level Private
* @usage U1
*/

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
class CATIDocEnvironment;
class CATUnicodeString;
class CATListValCATBaseUnknown_var;
class CATListPtrCATBaseUnknown;
class CATIDocId;
class CATDocument;
class CATTime;

/**
* @nodoc
* Class to manage the list of environment object.
* @see CATIDocEnvironment
*/
class ExportedByAC0XXLNK CATDocEnvManager : public CATBaseUnknown
{
  public:

  CATDeclareClass;

  /** @nodoc */
  CATDocEnvManager () ;

  virtual ~CATDocEnvManager() ;

  /** @nodoc */
  static HRESULT GetAvailableEnvironments(CATListValCATBaseUnknown_var *& oEnvironments);

  /** @nodoc */
  static void DeleteDocEnvManager();

  /**
   * @nodoc
   * Retrieves the environment by its late type.<br>
   * There is only one environment class for a given type.
   * @param iLateType
   *   The late type of the environment
   * @return
   *   The environment or <tt>NULL</tt> if no environment is found.
   */
  static CATIDocEnvironment * GetEnvironment(const CATUnicodeString &iLateType);

  /** @nodoc */
  static HRESULT GetDocDisplayName(CATIDocId * iDocId, CATUnicodeString& oDisplayName);

  /** @nodoc */
  static HRESULT RegisterDoc(CATDocument * iDocument, CATIDocId * iDocId);

  /** @nodoc */
  static HRESULT GetTimeStamp(CATIDocId * iDocId, CATTime ** oTimeStamp);

  private:

  HRESULT _GetAvailableEnvironments(CATListValCATBaseUnknown_var *& environments);
  CATIDocEnvironment * _GetEnvironment(const CATUnicodeString &iLateType);

  CATListPtrCATBaseUnknown* _docEnvironments;
  static CATDocEnvManager* _envManager;
};

#endif
