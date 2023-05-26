
#ifndef CATCAfrComponentControllerArg_H
#define CATCAfrComponentControllerArg_H

// COPYRIGHT DASSAULT SYSTEMES 2011/08/12

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATString.h"
#include "CATListOfCATString.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATCAfrEnum.h"

/**
 * CATCAfrComponentControllerArg
 *
 * CATCAfrComponentControllerArg allows users of C-Afr to specify an argument for
 * a CATCAfrComponentController.
 */
class ExportedByCATAfrItf CATCAfrComponentControllerArg : public CATBaseUnknown
{
  CATDeclareClass;
  public:
    /** 
    * Default constructor
    */
    CATCAfrComponentControllerArg ();

    /** Destructor */
    virtual ~CATCAfrComponentControllerArg ();

  /**
  * Retrieves the name of the Property.
  * returns: the name of the Property.
   */
    const CATString & GetPropertyID() const;

    /**
    * Set the name of the Property.
    * i_id: the name of the Property to set.
    */
    void SetPropertyID(const CATString & i_id);

  /**
  * Retrieves the value of the Property.
  * returns: the value of the Property.
   */
    CATBaseUnknown_var& GetValue();

    /**
    * Set the value of the Property.
    * ispValue: the  to set.
    */
    void SetValue( CATBaseUnknown_var ispValue );

    /**
  * Retrieves the Component.
  * returns: the Component.
   */
    CATBaseUnknown_var& GetComponent();

    /**
    * Set the Component.
    * i_value: the  to set.
    */
    void SetComponent( CATBaseUnknown_var ispComponent );

    /**
    * Retrieves the id of the event.
    * returns: the id of the event.
    */
    const CATString & GetEventID() const;

    /**
    * Set the id of the event.
    * i_id: the id of the event.
    */
    void SetEventID(const CATString & i_id);

    /**
    * Retrieves the list of elements.
    * returns: the list of elements.
    */
    const CATListValCATString& GetItemsId() const;

    /**
    * Set the list of elements.
    * i_list: the list of elements.
    */
    void SetItemsId( const CATListValCATString& i_list );

    /**
    * Retrieves the list of elements.
    * returns: the list of elements.
    */
    virtual CATLISTV(CATBaseUnknown_var)& GetItems( );

    /**
    * Set the list of elements.
    * i_list: the list of elements.
    */
    void SetItems( const CATLISTV(CATBaseUnknown_var)& i_list );

    /**
    * Retrieves the index of the ImportData event.
    * returns: the index of the ImportData event.
    */
    const int& GetImportDataIndex() const;

    /**
    * Set the id index of the ImportData event.
    * i_id: the id of the event.
    */
    void SetImportDataIndex(const int& i_id);

    /**
    * Retrieves the Dnd location type.
    *
    * Drop is not possible anywhere.
       NoDropLocation = 0,
    * Dragged item can be dropped on other items.
        DropOn = 1<<0,
    * Dragged item can be dropped before other items. 
        DropBefore = 1<<1,
    * Dragged item can be dropped after other items. 
        DropAfter = 1<<2,
    * Dragged items can be dropped on the viewport. On that case, their drop
    * position is determined by the default drop position of the model.
        DropViewport = 1<<3
    */
    const AfrDnDStyle& GetDndLocation() const;

    /**
    * Set the the Dnd location type.
    * i_id: the the Dnd location type.
    */
    void SetDndLocation(const AfrDnDStyle& i_id);

  private:
    // Not implemented
    CATCAfrComponentControllerArg (CATCAfrComponentControllerArg &);
    CATCAfrComponentControllerArg & operator=(CATCAfrComponentControllerArg &);

    CATString                     _PropId;
    CATString                     _EventId;
    CATBaseUnknown_var            _spValue;
    CATBaseUnknown_var            _spComponent;
    CATListValCATString           _ItemsId;
    CATLISTV(CATBaseUnknown_var)  _spListItems;
    int                           _ImportDataIndex;
    AfrDnDStyle                   _DndLocation;
};
#endif
