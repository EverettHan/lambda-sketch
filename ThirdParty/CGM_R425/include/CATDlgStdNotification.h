#ifndef CATDLGSTDNOTIFICATION
#define CATDLGSTDNOTIFICATION

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATDlgStandard.h"
#include "CATNotification.h"


/** 
 * Class to notify a dialog tree object's line selection.
 * <b>Role</b>:
 * This event notification is sent by @href CATDlgFolderFrame whenever a line is selected.
 */
class ExportedByCATDlgStandard CATDlgFolderSelectNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgFolderSelectNotification object. 
 */   
    CATDlgFolderSelectNotification();

    virtual ~CATDlgFolderSelectNotification();

};

#endif
