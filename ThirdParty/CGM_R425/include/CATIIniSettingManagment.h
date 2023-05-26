/* -*-c++-*- */
#ifndef CATIIniSettingManagment_H
#define CATIIniSettingManagment_H

// COPYRIGHT DASSAULT SYSTEMES 2001

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATEIniSettingManagment
 */

// System framework
#include "IUnknown.h"   

// Global Unique IDentifier defined in .cpp 
#include "CATInteractiveInterfaces.h" 
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIIniSettingManagment;
#else
extern "C" const IID IID_CATIIniSettingManagment;
#endif

/**
* Interface to handle the controller of setting repository.
* <b>Role</b>: This interface must be implemented by a component which
* represents the controller of the setting file. 
* <br>To create this controller see @href CATIniCleanerSettingCtrl . 
* <br>This controller must implemented:
* <ul>
* <li>An interface to access to each attribut</li>
* <li>This interface </li>
* </ul>
* <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
* @see CATSettingRepository
*/
class ExportedByCATInteractiveInterfaces CATIIniSettingManagment : public IUnknown
{

  public :

	/**
     * Makes a persistent copy of the setting file in Memory.
	 */
    virtual  HRESULT   Commit()             = 0;

	/**
    * Restores the administrated values of the attributes.
	*/
    virtual  HRESULT   ResetToAdminValues() = 0;

	/**
	 * Restores a previous persistent copy of the setting file in Memory.
	 */
    virtual  HRESULT   Rollback()           = 0;

     /**
      * Makes a persistent copy of the setting file on file.
	 */
    virtual  HRESULT   SaveRepository()     = 0;

};
#endif

