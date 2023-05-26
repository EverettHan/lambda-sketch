// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATIASettingRepoImpl_h
#define CATIASettingRepoImpl_h

#include "CATCORBABoolean.h"
#include "CAT_VARIANT_BOOL.h"
#include "JS0SETT.h"

#include "CATBaseObject.h"
#include "CATBSTR.h"
#include "CATSafeArray.h"
#include "CATVariant.h"
#include "CATSysSettingRepository.h"
#include "CATIASettingRepository.h"

class CATSettingEnv;

class ExportedByJS0SETT CATIASettingRepoImpl : public CATBaseObject
{
  CATDeclareClass;

public:/**
 * Makes a memory copy of the setting attribute values.
 * <br><b>Role</b>: <code>Commit</code> saves the current values of the setting
 * attributes managed by the setting controller in a specific memory area.
 * Successive calls to <code>Commit</code> overwrite the memory area.
 * The values saved by the last call to <code>Commit</code> can be restored from
 * that memory area using the @href #Rollback method.
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT Commit();
  
/**
 * Restores the last memory copy of the setting attribute values.
 * <br><b>Role</b>: <code>Rollback</code> restores the values of the 
 * setting attributes managed by the setting controller from the memory area.
 * All values of the setting attributes managed by the setting controller 
 * modified since the last call to @href #Commit are restored to the values they
 * had when this last @href #Commit was called.
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  HRESULT Rollback();

/**
 * Restores the administrated values of the attributes.
 * <br><b>Role</b>: <code>ResetToAdminValues</code> restores all
 * the values of the setting attributes managed by the setting controller
 * to either the values set by the setting administrator, or to their default 
 * values if the setting administrator did not change them. 
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  HRESULT ResetToAdminValues();

/**
 * Restores the administrated values of a subset of the attributes.
 * <br><b>Role</b>: <code>ResetToAdminValuesByName</code> restores
 * the values of a subset of the setting attributes managed by the setting 
 * controller to either the values set by the setting administrator, or to their
 * default values if the setting administrator did not change them. 
 * @param iAttList
 *  The attribute subset to which the administrated values are to be restored
 */
  HRESULT ResetToAdminValuesByName(const CATSafeArrayVariant & iAttList);

/**
 * Makes a persistent copy of the setting attribute values on file.
 * <br><b>Role</b>: <code>SaveRepository</code> saves the current values of the
 * setting attributes managed by the setting controller in a setting repository 
 * file. To avoid inconsistencies, <code>SaveRepository</code> first saves the 
 * values in the memory area used by the @href #Commit method by calling 
 * @href #Commit before writing the values in the setting repository file.
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  HRESULT SaveRepository();

 

  HRESULT GetAttr(const CATBSTR & iAttrName, CATVariant & oAttr);
  
  HRESULT PutAttr(const CATBSTR & iAttrName, const CATVariant & iAttr);
  
  HRESULT GetAttrArray(const CATBSTR & iAttrName, 
		       CATSafeArrayVariant *& oArray);
  
  HRESULT PutAttrArray(const CATBSTR & iAttrName, 
		       const CATSafeArrayVariant & iArray); 

  HRESULT SetAttrLock(const CATBSTR & iAttrName, CAT_VARIANT_BOOL iLocked);

  HRESULT GetAttrInfo(const CATBSTR & iAttrName, CATBSTR & AdminLevel, 
		      CATBSTR & Locked, CAT_VARIANT_BOOL & oModified);


  CATIASettingRepoImpl(const char *iName, HRESULT &ohres );
  const char *GetName ();


  HRESULT GetAttr(const CATBSTR & iAttrName, CATVariant & oAttr, int iOp);
  
  HRESULT PutAttr(const CATBSTR & iAttrName, const CATVariant & iAttr, int iOp);
  
  HRESULT GetAttrArray(const CATBSTR & iAttrName, 
		       CATSafeArrayVariant *& oArray, int iOp);
  
  HRESULT PutAttrArray(const CATBSTR & iAttrName, 
		       const CATSafeArrayVariant & iArray, int iOp); 

  HRESULT SetAttrLock(const CATBSTR & iAttrName, 
		      CAT_VARIANT_BOOL iLocked, int iOp);

  HRESULT GetAttrInfo(const CATBSTR & iAttrName, CATBSTR & AdminLevel, 
		      CATBSTR & Locked, CAT_VARIANT_BOOL & oModified, int iOp);


  virtual ~CATIASettingRepoImpl();




  static HRESULT Instantiate(CATSysSettingRepository *iCtrl, 
			     CATIASettingRepository **oCtrl);

  static HRESULT Instantiate (const char *iName, 
			      CATIASettingRepository **oCtrl);

 private:
  static CATSettingEnv *_Env;
  char * _XMLName;
  CATSysSettingRepository *_Repo;
  
};

#endif
