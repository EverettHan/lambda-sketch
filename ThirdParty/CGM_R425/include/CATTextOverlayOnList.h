#ifndef _CATTextOverlayOnList_H
#define _CATTextOverlayOnList_H

#include <CATTextOverlayView.h>

class CATListView;
class CATTextOverlayViewItem;

/**
 * Specialized CATTextOverlayView that layout labels on list view rows
 **/
class ExportedByCATView CATTextOverlayOnList : public CATTextOverlayView
{
public:
	CATDeclareClass;
	/**
	 * Constructor
	 **/
	CATTextOverlayOnList( CATCommand *iFather, const CATString &iName, CATListView *iListView );
	/**
	 * Destructor
	 **/
	virtual ~CATTextOverlayOnList(void);
protected:
	/**
	 * CATTextOverlayView::Layout
	 **/
	virtual void Layout(void);
private:
	static int ItemVerticalCompare( CATTextOverlayViewItem *iItem1, CATTextOverlayViewItem *iItem2 );
	CATListView *_listView;
};

#endif
