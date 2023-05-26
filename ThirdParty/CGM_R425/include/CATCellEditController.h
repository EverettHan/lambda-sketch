// COPYRIGHT Dassault Systemes 2005
//  Mar 2005  Creation: mok
#ifndef CATCellEditController_H
#define CATCellEditController_H

#include "CATViewEdit.h"
#include "CATCellSelectionController.h"
#include "CATString.h"
#include "CATBaseUnknown.h"
#include "CATBaseUnknown_WR.h"

class CATListEditor;

/**
 * A list controller to support editing list cells
 **/
class ExportedByCATViewEdit CATCellEditController: public CATCellSelectionController
{
	CATDeclareClass;
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATCellEditController (CATListEditor* iView);
	virtual ~CATCellEditController ();
	// Copy constructor and equal operator
	// -----------------------------------
	CATCellEditController (CATCellEditController &);
	CATCellEditController& operator=(CATCellEditController&);
	virtual void OnActivate( CATBaseUnknown_var iNode );
	/**
	 * Request for contextual mnu (right click) on an individual cell within the list view.
	 **/
	virtual void OnCellContext( CATBaseUnknown_var iObj, const CATString& iColID );
	/**
	 * Request for contextual menu on one of the view's row headers
	 **/
	virtual void OnRowHeaderContext( CATBaseUnknown_var iObj );
	virtual void OnRevertRow( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
	virtual void OnRevertAll( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
private:
	CATListEditor *GetEditor(void);
	static const CATString CATVIEW_MSGCAT;
	CATBaseUnknown_WR _Editor;
};

#endif
