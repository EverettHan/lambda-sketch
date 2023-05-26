#ifndef CATIMultiWorkshopWorkbench_H
#define CATIMultiWorkshopWorkbench_H

// COPYRIGHT DASSAULT SYSTEMES 2014

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

// ==========================================================================
//
// Interface for multi-workshop workbench. See CATIWorkbench interface for workbench description.
// Any late type implementing CATIMultiWorkshopWorkbench is a multi-workshop workbench.
// No method in this interface (in addtion of CATIWorkbench methods). Only workbench resources in CATRsc file.
// Add the following lines in YourWorkbench.CATRsc file.
//    YourWorkbench.MultiWorkshop.1 ="WorkshopNameA";
//    YourWorkbench.MultiWorkshop.2 ="WorkshopNameB";
//      ...
//    YourWorkbench.MultiWorkshop.n ="WorkshopNameZ";
// ==========================================================================

/**
* Interface to create a multi-workshop workbench.
* <b>Role</b>: Any late type implementing CATIMultiWorkshopWorkbench is a multi-workshop workbench. 
* <br><br>
* No method in this interface (in addtion of <tt>CATIWorkbench</tt> methods). Only workbench resources in CATRsc file.
* interface which derives from <tt>CATIWorkbench</tt>.
* <br><br>
* Add the following lines in YourWorkbench.CATRsc file.
* <br>   YourWorkbench.MultiWorkshop.1 ="WorkshopNameA";
* <br>   YourWorkbench.MultiWorkshop.2 ="WorkshopNameB";
* <br>     ...
* <br>   YourWorkbench.MultiWorkshop.n ="WorkshopNameZ";
* <br><br>
* The default workshop for the multi-workshop workbench is the first in the list.
* @see CATIWorkbench
*/
#include "CATIWorkbench.h"
#include "CATAfrItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIMultiWorkshopWorkbench;
#else
extern "C" const IID IID_CATIMultiWorkshopWorkbench;
#endif

#include "CATListOfCATString.h"


class ExportedByCATAfrItf CATIMultiWorkshopWorkbench : public CATIWorkbench
{
  CATDeclareInterface;
  
public:

};
#endif
