// COPYRIGHT Dassault Systemes 2004
#ifndef CATIListViewContextController_H
#define CATIListViewContextController_H

#include <CATViewItf.h>
#include <CATBaseUnknown.h>
#include <CATString.h>

extern ExportedByCATViewItf IID IID_CATIListViewContextController;

/**
 * General controller methods
 **/
class ExportedByCATViewItf CATIListViewContextController: public CATBaseUnknown
{
    CATDeclareInterface;
public:

    /**
     * Request for contextual menu (right click) on one of the view's column headers
     **/
    virtual void OnColHeaderContext( const CATString& iColID ) = 0;

    /**
     * Request for contextual mnu (right click) on an individual cell within the list view.
     */
    virtual void OnCellContext( CATBaseUnknown_var iObj, const CATString& iColID ) = 0;

    /**
     * Request for contextual menu on one of the view's row headers
     */
    virtual void OnRowHeaderContext( CATBaseUnknown_var iObj )=0;

};

CATDeclareHandler( CATIListViewContextController, CATBaseUnknown );

#endif
