// COPYRIGHT Dassault Systemes 2005
#ifndef CATListViewController_H
#define CATListViewController_H

#include "CATView.h"
#include "CATBasicViewController.h"
#include "CATString.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"

class CATListView;
class CATViewMoreCmd;

/**
 * Basic Implementation of CATIViewController for a list view.
 * Used as controller to support row selection, as well as some
 * functionality for managing columns.  Also implements
 * CATIListViewContextController
 **/
class ExportedByCATView CATListViewController: public CATBasicViewController
{
	CATDeclareClass;
public:
	/**
	* Constructor
	**/
	CATListViewController( CATListView* iView );
	CATListViewController( CATListViewController &iCtrl );
	/**
	 * Destructor
	 **/
	virtual ~CATListViewController(void);
	/**
	 * = operator
	 **/
	CATListViewController& operator=(CATListViewController&);
	/**
	 * Request for contextual menu (right click) on one of the view's column headers
	 **/
	virtual void OnColHeaderContext( const CATString& iColID );
	/**
	 * Request for contextual mnu (right click) on an individual cell within the list view.
	 **/
	virtual void OnCellContext( CATBaseUnknown_var iObj, const CATString& iColID );
	/**
	 * Request for contextual menu on one of the view's row headers
	 **/
	virtual void OnRowHeaderContext( CATBaseUnknown_var iObj );
	/*
	 * CATBasicViewController methods
	 */
	virtual void OnSelect( CATBaseUnknown_var iNode );
protected:
	virtual void OnHideColumn( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
	virtual void OnShowColumn( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
	virtual void OnShowAllColumns( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
	virtual void CleanViewMoreCmd( );
#ifdef SCA_PROTOTYPE
	virtual void OnColumnFilter( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
#endif
	/**
	 * Get the position of a node.
	 * Default implementation relies on CATListView::GetItemRow, which only works for
	 * visible items
	 * Return -1 if item not found
	 * First item is 0
	 **/
	virtual int GetItemRowIndex(CATBaseUnknown_var iNode);

  virtual void OnColumnMore( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
  virtual HRESULT AddMoreMenu( );

private:
	CATListView *GetListView(void);
	/**
	 * maintain previous selection, used to process shift+click selection
	 **/
	int _lastSelection;
	/**
	 * string used in menu support.  An instance var for lifecycle mgmt purposes,
	 * since it must be passed into the callback
	 **/
	CATString *_tmpColID;
	CATListOfCATString tmpHiddenColIDs;  // needed for lifecycle of data for OnShowColumn
  CATViewMoreCmd*    _pMoreCmd;
};

#endif
