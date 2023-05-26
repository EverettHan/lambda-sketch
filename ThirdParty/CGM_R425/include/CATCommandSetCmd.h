/**
 * @fullreview SCA-ERS 02:04:04
 * @error MISC Y pas de constructeur par default, constructeur par copie et pas d'operateur =
 * @error MISC Y manque #include "CATString.h"
*/
#ifndef __CATCommandSetCmd_h
#define __CATCommandSetCmd_h

/* COPYRIGHT DASSAULT SYSTEMES 2000 */

#include "CATAfrFoundation.h"
#include "CATCommand.h"
#include "CATCommandSet.h"
#include "CATString.h"
#include "CATListOfCATString.h"
#include "CATListOfCATFrmEditor.h"
#include "CATLISTP_CATBaseUnknown.h"

class CATFrmEditor;

class ExportedByCATAfrFoundation CATCommandSetCmd: public CATCommand {

	CATDeclareClass;

public:
	
	enum Action {
		InstallSet,
		UninstallSet
	};
	
	CATCommandSetCmd (
		CATFrmEditor *, 
		const CATString & topic, 
		Action,
		CATCommandSet * defaultSet = 0
		);
	
  // finalSet is a command set ready to install or uninstall. Do not Release it after use.
  CATCommandSetCmd (
		CATFrmEditor *, 
		const CATString & topic, 
		Action,
		CATCommandSet * defaultSet,
		CATCommandSet * finalSet
		);
	
	virtual ~CATCommandSetCmd ();

	virtual CATStatusChangeRC Activate (CATCommand *, CATNotification *);

 	static void FillAddinCommandSet (CATCommandSet &, CATClassId, CATString);

  static CATLISTP(CATBaseUnknown) _CurrentDefaultSet;
  static CATLISTP(CATBaseUnknown) _CurrentFinalSet;
  static CATListOfCATString       _CurrentTopic;
  static CATListOfCATString       _CurrentWorkshop;
  static CATLISTP(CATFrmEditor)   _CurrentEditor;

protected:

	void Install     ();
	void Uninstall   ();
	void FillCommandSet (CATCommandSet &, const CATString &);
	
	CATFrmEditor  * _editor;
	Action          _action;	
	CATString       _topic;
	CATCommandSet * _defaultSet;
	CATCommandSet * _finalSet;

private:

    // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
    CATCommandSetCmd ();
    CATCommandSetCmd (const CATCommandSetCmd &);
    CATCommandSetCmd & operator= (const CATCommandSetCmd &);
};

#endif
