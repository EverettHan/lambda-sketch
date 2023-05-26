// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATSaveLoadNotification_h
#define CATSaveLoadNotification_h

/**
 * @level Private
 * @usage U1
 */

#include "CATNotification.h"
#include "CATDocument.h"
#include "booleanDef.h"
#include <AD0XXBAS.h>

class CATDialog;


class ExportedByAD0XXBAS CATSaveLoadNotification : public CATNotification
{
  public:
    CATDeclareClass;

    CATSaveLoadNotification();
    virtual ~CATSaveLoadNotification();
    
    CATDocument*  GetDoc() const;
    void Feed(CATDocument* doc);

    // To Differentiate the Load from the Save notification
	boolean		IsASaveNotification ();
	void		SetSaveNotification ( boolean IASaveNotif = FALSE);

protected:

    CATDocument*		_document;
	boolean				_SaveNotif;
};

class ExportedByAD0XXBAS CATEndOpenNotification : public CATNotification
{
public:
    CATDeclareClass;

    CATEndOpenNotification(CATLISTP(CATDocument)& idoc);
    virtual ~CATEndOpenNotification();

    CATLISTP(CATDocument)&  GetOpenedDocList() const;

protected:

    CATLISTP(CATDocument)& _DocumentList;
};

#endif
