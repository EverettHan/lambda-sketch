#ifndef CATICAfrTree_H
#define CATICAfrTree_H

// COPYRIGHT DASSAULT SYSTEMES 2013/03/12

#include "CATAfrItf.h"
#include "CATICAfrList.h"

extern ExportedByCATAfrItf  IID IID_CATICAfrTree ;

//-----------------------------------------------------------------------------
/**
* Interface representing The Tree Component.
*/
class ExportedByCATAfrItf CATICAfrTree: public CATICAfrList
{
  CATDeclareInterface;

  public:

    /**
    * Collapse all expanded model items.
    */
    virtual void CollapseAll() = 0;

    /**
    * Expand all expandable model items.
    */
    virtual void ExpandAll() = 0;

    /**
    * Collapse the model item and updates the view.
    *
    * @return 1 if collapse is done, 0 if the item is already collapsed.
    */
    virtual int Collapse( ) = 0;

    /**
    * Expand the model item and updates the view.
     *
    * @return 1 if expand is done, 0 if the item is already expanded.
    */
    virtual int Expand( ) = 0;

};
CATDeclareHandler( CATICAfrTree, CATICAfrList );
#endif
