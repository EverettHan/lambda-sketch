// COPYRIGHT Dassault Systemes 2015
//=======================================================================
/**
 * @level Protected
 * @usage U6
 */
#ifndef CATOmbNonCATIADocumentApplicativeBehaviorAdapter_H
#define CATOmbNonCATIADocumentApplicativeBehaviorAdapter_H

// System
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

// ObjectModelerBase
#include "CATOmbNonCATIADocument.h"
#include "CATIOmbNonCATIADocumentApplicativeBehavior.h"
#include "CATIOmbNonCATIASDPersistencyMngt.h"
#include "CATOmxSR.h"

//-----------------------------------------------------------------------

/**
* Adapter class for all CATIOmbNonCATIADocumentApplicativeBehavior implementations.
* All CATIOmbNonCATIADocumentApplicativeBehavior implementations MUST derive from this adapter to ease evolutions
*/
class ExportedByCATOmbNonCATIADocument CATOmbNonCATIADocumentApplicativeBehaviorAdapter: public CATIOmbNonCATIADocumentApplicativeBehavior
{
   CATDeclareClass;

public:

  // Standard constructors and destructors
  // -------------------------------------
  CATOmbNonCATIADocumentApplicativeBehaviorAdapter();
  CATOmbNonCATIADocumentApplicativeBehaviorAdapter(CATIOmbNonCATIASDPersistencyMngt* iNonCATIASDPersistencyMngt);
  CATOmbNonCATIADocumentApplicativeBehaviorAdapter(const CATUnicodeString& iProjectedFilePath, const time_t& iProjectedFileTimeStamp);

  virtual ~CATOmbNonCATIADocumentApplicativeBehaviorAdapter();

  virtual HRESULT SaveProjectedFile(const CATUnicodeString& iProjectedFilePath);
  virtual CATBoolean IsDirty();
  HRESULT SetRefProjectedFileTimeStamp(const time_t& ProjectedFileTimeStamp);

  // Default OMB behaviors: 
  // Replace User projection with OMB projection
  inline CATBoolean OnReplaceWorkingFile(const CATUnicodeString& iOldWorkingFilePath, const CATUnicodeString& iNewProjectedFilePath){return TRUE;};
  // User projection file is NOT deleted when replacing User projection with OMB projection
  inline CATBoolean OnRemoveWorkingFile(const CATUnicodeString& iProjectedFilePath){return FALSE;};

private:

  CATUnicodeString _ProjectedFilePath;
	time_t _ProjectedFileTimeStamp;

  CATOmxSR<CATIOmbNonCATIASDPersistencyMngt> _pNonCATIASDPersistencyMngt;

  // The copy constructor and the equal operator must not be implemented
  // -------------------------------------------------------------------
  CATOmbNonCATIADocumentApplicativeBehaviorAdapter (CATOmbNonCATIADocumentApplicativeBehaviorAdapter &);
  CATOmbNonCATIADocumentApplicativeBehaviorAdapter& operator=(CATOmbNonCATIADocumentApplicativeBehaviorAdapter&);

};

#endif
