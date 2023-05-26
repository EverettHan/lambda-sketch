/**
 * @fullreview SCA-ERS 02:03:07
 * @error MISC  Y manque class CATIProgressTaskUI et CATString
 * @error MISC  Y passage du constructeur et destructeur en protected
 * @error MISC N pas de constructeur par copie et pas d'operateur =
*/
#ifndef __CATExtIProgressTask_h
#define __CATExtIProgressTask_h

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATAfrProgressTask.h"
#include "CATIProgressTask.h"

class CATIProgressTaskUI;
class CATString;

/**
  * Default implementation base class for CATIProgressTask
  * interface.
  */
class ExportedByCATAfrProgressTask CATExtIProgressTask: public CATIProgressTask {

  CATDeclareClass;

public:

  /**
    * Called to begin the task.
    * The <tt>iUI</tt> argument points the task's
    * user interface. (@see CATIProgressTaskUI)
    * S_OK is returned on success.
    */  
  virtual HRESULT PerformTask    (CATIProgressTaskUI  * iUI, void * iUserData);

  /**
    * Returns the tasks label.
    * The title is set in <tt>oLabel</tt>.
    * S_OK is returned on success.
    */  
  virtual HRESULT GetCatalogName (CATString        * oCatalog);

  /**
    * Returns the tasks icon name.
    * The icon name is set in <tt>oIcon</tt>.
    * S_OK is returned on success.
    */  
  virtual HRESULT GetIcon        (CATString        * oIcon);


protected:

  CATExtIProgressTask ();
  virtual ~CATExtIProgressTask ();


private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATExtIProgressTask (const CATExtIProgressTask &);
  CATExtIProgressTask & operator= (const CATExtIProgressTask &);
};


#endif//__CATExtIProgressTask_h
