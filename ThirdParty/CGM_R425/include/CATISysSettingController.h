/* -*-c++-*- */
#ifndef CATISysSettingController_H
#define CATISysSettingController_H

// COPYRIGHT DASSAULT SYSTEMES 2003
// System framework
#include "CATBaseUnknown.h"  
#include "JS0SETT.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0SETT IID IID_CATISysSettingController;
#else
extern "C" const IID IID_CATISysSettingController;
#endif

/**
 * Interface to handle the  setting controller.
 * <b>Role</b>: This interface must be implemented by a component which
 * represents the controller of the setting repository and file.
 * Use the @href CATSysSettingController class to implement 
 * CATISysSettingController.
 * In most cases, you should not re-implement these methods, except if you create
 * a bufferized setting controller. Refer to the CAA Encyclopedia to know
 * about such controllers.</p>  
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click on Foundations -> Abstractions -> PLM Enterprise Foundations -> Base OS Abstraction -> Object Modeler.
 * Several articles deal with the BOA.</p>
 */
class ExportedByJS0SETT CATISysSettingController : public CATBaseUnknown
{
  CATDeclareInterface;
  
public :
  
/**
 * Makes a memory copy of the setting attribute values.
 * <br><b>Role</b>: <code>Commit</code> saves the current values of the setting 
 * attributes managed by the setting controller in a specific memory area.
 * Successive calls to <code>Commit</code> overwrite the memory area.
 * The values saved by the last call to <code>Commit</code> can be restored from
 * that memory area using the @href #Rollback method.
 * @param iNoEvent [in]
 *	Reserved for internal use. Do not use. Should always be set to 0
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT Commit(int iNoEvent=0) = 0;

/**
 * Restores the administrated values of the attributes.
 * <br><b>Role</b>: <code>ResetToAdminValues</code> restores all
 * the values of the setting attributes managed by the setting controller
 * to either the values set by the setting administrator, or to their default 
 * values if the setting administrator did not change them. 
 * @param iAttList [in]
 *	Reserved for internal use. Do not use. Should always be set to NULL
 * @param iNbAtt [in]
 *	Reserved for internal use. Do not use. Should always be set to 0
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */  
  virtual HRESULT ResetToAdminValues(char** iAttList=NULL, int iNbAtt=0) = 0;
  
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
  virtual HRESULT Rollback() = 0;
  
/**
 * Makes a persistent copy of the setting attribute values on file.
 * <br><b>Role</b>: <code>SaveRepository</code> saves the current values of the
 * setting attributes managed by the setting controller in a setting repository 
 * file. To avoid inconsistencies, <code>SaveRepository</code> first saves the 
 * values in the memory area used by the @href #Commit method by calling 
 * @href #Commit before writing the values in the setting repository file.
 * @param iTmp [in]
 *	Reserved for internal use. Do not use. Should always be set to NULL
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT SaveRepository(const char *itmp=NULL) = 0;
  
};
#endif

