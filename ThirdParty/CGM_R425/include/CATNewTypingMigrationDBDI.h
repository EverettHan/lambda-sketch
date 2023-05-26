#ifndef NewTypingMigrationDBDI_h
#define NewTypingMigrationDBDI_h

// COPYRIGHT Dassault Systemes 2017 by MFL 01/17/2017


// General framework
#include "NewTypingMigrationDBDI.h"
#include "CATLISTV_CATPLMID.h"

// System framework
#include "CATUnicodeString.h"

class ExportedByNewTypingMigrationDBDI CATNewTypingMigrationDBDI
{

public:
	static HRESULT  MigrateAppliFromV15ToV2(const CATLISTV(CATPLMID)& iListToMigrate,CATLISTV(CATPLMID)& oListNotMigrated,CATUnicodeString& oMigrationMessage);

private:
  	         CATNewTypingMigrationDBDI();
  	         CATNewTypingMigrationDBDI(const CATNewTypingMigrationDBDI&);
	virtual ~CATNewTypingMigrationDBDI();

};
#endif // NewTypingMigrationDBDI_h
