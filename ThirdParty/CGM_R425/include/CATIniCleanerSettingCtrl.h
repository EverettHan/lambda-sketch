/* -*-c++-*- */
#ifndef CATIniCleanerSettingCtrl_H
#define CATIniCleanerSettingCtrl_H

//COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATBaseUnknown.h"  // To derive from

/**
* Class to delete a setting controller.
* <b>Role:</b>This class must be a static data of your 
* setting controller implementation. 
* <br><br>Sample to create the setting controller implementation:
* <br><b>Header file:</b>
* <pre>
*#include "CATBaseUnknown.h"  // To derive from
*#include "CATIniCleanerSettingCtrl.h"
*
*class  MySettingCtrl : public CATBaseUnknown
*{
*   // Used in conjunction with CATImplementClass in the .cpp file
*   CATDeclareClass;
*
*   public:
*
*   MySettingCtrl();
*   virtual ~MySettingCtrl();
*
*   // Method called by a global function
*   // This method creates an unic controler or retrieves it.
*   // 
*   static HRESULT GetSettingController(MySettingCtrl ** oCtrl);
*
* private:
*
*   // Copy constructor, not implemented
*   // Set as private to prevent from compiler automatic creation as public.
*   MySettingCtrl(const MySettingCtrl &iObjectToCopy);
*
* private:
*
*   static CATIniCleanerSettingCtrl _CleanerCtrl ;
*
*
*};
* </pre>
* <b>Cpp file:</b>
* <pre>
*
*#include "MySettingCtrl.h"
*#include "CATErrorDef.h"
*
* //To initialize the static data 
*CATIniCleanerSettingCtrl MySettingCtrl::_CleanerCtrl ;
*
* //To declare that this class is a component main class 
*CATImplementClass(MySettingCtrl, 
*                   Implementation, CATBaseUnknown , CATNull);
*
*
*
*MySettingCtrl::MySettingCtrl()
*{
*}
*
*
*MySettingCtrl::~MySettingCtrl()
*{
*}
*
*HRESULT MySettingCtrl::GetSettingController(
*                       MySettingCtrl ** oCtrl)
*{
*    HRESULT rc = S_OK ;
*
*    if ( NULL != oCtrl )
*    {
*       CATBaseUnknown * Ctrl = _CleanerCtrl.GetController();
*       if ( NULL == Ctrl )
*       {
*          MySettingCtrl * SettingController = NULL;
*          SettingController = new MySettingCtrl();
*          if ( NULL == SettingController )
*          {
*             rc = E_OUTOFMEMORY ;
*          }else
*          {
*             // The cleaner keeps the unic instance
*             // SetController has made an Addref
*             _CleanerCtrl.SetController(SettingController);
*
*             *oCtrl = SettingController ;
*          }
*       }else
*       {
*          *oCtrl = (MySettingCtrl*) Ctrl ;
*       }
*
*    }else rc = E_FAIL ;
*
*    return rc ;
*
*}
* </pre>
* @see CATIIniSettingManagment
*/

#include <CATInteractiveInterfaces.h>
class  ExportedByCATInteractiveInterfaces CATIniCleanerSettingCtrl : public CATBaseUnknown
{

   public:
 
   /** Constructs an instance */
   CATIniCleanerSettingCtrl();

   virtual ~CATIniCleanerSettingCtrl(); 

   /**
    * Retrieves the setting controller.
    */ 
   CATBaseUnknown * GetController();

   /**
    * Sets the setting controller.
    * <br><b>Role</b>: The last controller is released if it exists, and
    * in all cases, the instance keeps a pointer on the setting controller.
    * This pointer is released in the destructor of this class.
    */ 
   void SetController(CATBaseUnknown * iController);

 private:
   
   // Copy constructor, not implemented
   // Set as private to prevent from compiler automatic creation as public.
   CATIniCleanerSettingCtrl(const CATIniCleanerSettingCtrl &iObjectToCopy);

 private:

   // The unic instance of this class
   CATBaseUnknown * _pSettingController ;


};


#endif
