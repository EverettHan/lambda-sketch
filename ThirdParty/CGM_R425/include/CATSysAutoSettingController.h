/* -*-c++-*- */
#ifndef CATSysAutoSettingController_H
#define CATSysAutoSettingController_H

// COPYRIGHT DASSAULT SYSTEMES 2003

// System framework
#include "IUnknown.h"   
#include "CATBaseObject.h"
#include "CATSafeArray.h"
#include "CATBoolean.h"
#include "CATAutoConversions.h"
#include "CATDataType.h"
#include "JS0SETT.h"


class CATISysSettingController;


/**
* Interface to handle a setting repository controller for Automation.
* <b>Role</b>: This interface must be implemented by a component which
* represents the controller of the setting file for an Automation context. 
* <br>This controller must implement:
* <ul>
* <li>An interface to access to each attribute</li>
* <li>This interface</li>
* </ul>
*/
class ExportedByJS0SETT CATSysAutoSettingController : public CATBaseObject
{
  
public :
  virtual ~CATSysAutoSettingController();
  
/**
 * Makes a memory copy of the setting attribute values.
 * <br><b>Role</b>: <code>Commit</code> saves the current values of the setting attributes
 * managed by the setting controller in a specific memory area.
 * Successive calls to <code>Commit</code> overwrite the memory area.
 * The values saved by the last call to <code>Commit</code> can be restored from that memory area
 * using the @href #Rollback method.
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT Commit();
  
/**
 * Restores the last memory copy of the setting attribute values.
 * <br><b>Role</b>: <code>Rollback</code> restores the values of the 
 * setting attributes managed by the setting controller from the
 * memory area.
 * All values of the 
 * setting attributes managed by the setting controller modified since the last call
 * to @href #Commit are restored to the values they had when this last @href #Commit was called.
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT Rollback();

/**
 * Restores the administrated values of the attributes.
 * <br><b>Role</b>: <code>ResetToAdminValues</code> restores all
 * the values of the setting attributes managed by the setting controller
 * to either the values set by the setting administrator, or to their default values
 * if the setting administrator did not change them. 
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT ResetToAdminValues();

/**
 * Restores the administrated values of a subset of the attributes.
 * <br><b>Role</b>: <code>ResetToAdminValuesByName</code> restores
 * the values of a subset of the setting attributes managed by the setting controller
 * to either the values set by the setting administrator, or to their default values
 * if the setting administrator did not change them. 
 * @param iAttList
 *  The attribute subset to which the administrated values are to be restored
 */
  virtual HRESULT ResetToAdminValuesByName(const CATSafeArrayVariant & iAttList);

/**
 * Makes a persistent copy of the setting attribute values on file.
 * <br><b>Role</b>: <code>SaveRepository</code> saves the current values of the
 * setting attributes managed by the setting controller in a setting repository file.
 * To avoid inconsistencies, <code>SaveRepository</code> first saves the values in the memory area
 * used by the @href #Commit method by calling @href #Commit before writing the values
 * in the setting repository file.
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT SaveRepository();

 

protected:
/**
 * Initializes the setting controller.
 * <br><b>Role</b>: <code>Initialize</code> might be necessary for setting controllers
 * that keep some setting attribute values as data member for performance reasons.
 * Such setting controllers are qualified as bufferized setting controllers.
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT Initialize();
  
  /**
   * Constructs an empty setting controller for Automation.
   */
  CATSysAutoSettingController ();
};



#endif
