// COPYRIGHT Dassault Systemes 2004
#ifndef CATBasicViewController_H
#define CATBasicViewController_H

#include <CATBaseUnknown_WR.h>
#include <CATDynHashTable.h>
#include <CATView.h>
#include <CATCommand.h>
#include <CATLISTV_CATBaseUnknown.h>
typedef  CATLISTV(CATBaseUnknown_var)  CATListOfCATBaseUnknown_var;
#include <string>
#include <vector>

class CATDrawView;
class CATTreeView;
class CATDeviceEvent;

/**
 * CATBasicViewController
 * Simple CATIViewController and CATITreeViewController implementation to manage selection with an internal
 * hashtable.
 **/
class ExportedByCATView CATBasicViewController: public CATCommand
{
    CATDeclareClass;
public:
    /**
     * Constructor
     **/
    CATBasicViewController( CATDrawView *iView );
    /**
     * Destructor
     **/
    virtual ~CATBasicViewController();
    /**
     * Is a node selected ?
     **/
    virtual int IsInSelection( CATBaseUnknown *iNode );
    /**
     * Empty selection, if iNotify=1 a notification is sent.
     **/
    virtual void ClearSelection( int iNotify= 1 );
    /**
     * Add a node to the selection, if iNotify=1 a notification is sent.
     **/
    virtual void AddToSelection( CATBaseUnknown *iNode, int iNotify= 1 );
    /**
     * Remove a node from the selection, if iNotify=1 a notification is sent.
     **/
    virtual void RemoveFromSelection( CATBaseUnknown *iNode, int iNotify= 1 );
    /**
     * Get list of currently selected objects.
     **/
    virtual void GetSelection( CATListOfCATBaseUnknown_var &oSelection );
    /**
     * Notification sent when selection changes
     **/
    CATNotification *GetSelectionNotification();
    /**
     * Notification sent when a node is activated (double-click)
     **/
    CATNotification *GetActivationNotification();
	/**
	 * Selection modes
	 **/
	enum SelectBehavior
	{
		NoSelection,
		MultipleSelect,
		SingleSelect
	};
	/**
	 * Set selection mode. Default is multiple selection allowed.
	 **/
	HRESULT SetSelectBehavior( SelectBehavior iSelectBehavior );
	/**
	 * Get selection mode
	 **/
	SelectBehavior GetSelectBehavior() const;

    virtual void OnContext( CATBaseUnknown_var iNode );
    virtual void OnActivate( CATBaseUnknown_var iNode );
    virtual void OnExpand( CATBaseUnknown_var iNode );
    virtual void OnCollapse( CATBaseUnknown_var iNode );
    virtual void OnSelect( CATBaseUnknown_var iNode );
    virtual void OnMoveOver( CATBaseUnknown_var iNode );
    virtual int IsSelected( CATBaseUnknown_var iNode );
    virtual int IsPreSelected( CATBaseUnknown_var iNode );
    virtual int IsActive( CATBaseUnknown_var iNode );
	/*
	 * CATIDragViewController methods
	 */
	void OnDrag( int iStart );
	/*
	 * CATIDropViewController methods
	 */
	void OnBeginPreDrop( CATNotification *iNotification );
	void OnPreDrop( CATNotification *iNotification );
	void OnEndPreDrop( CATNotification *iNotification );
	void OnDrop( CATNotification *iNotification );

protected:

  CATDrawView *GetView();
  CATTreeView *GetTreeView();
  CATDeviceEvent *GetEvent();
  std::vector<std::string> _GetPathFromItem(const CATBaseUnknown_var& iNode);

  CATBaseUnknown_var _prehighlight;

private:

	SelectBehavior _selectBehavior;
  CATBaseUnknown_WR _view;
  CATDynHashTable _table;
};

#endif
