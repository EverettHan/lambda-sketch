#ifndef CATIHeaderGraphicProperties_H
#define CATIHeaderGraphicProperties_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"

class CATCmdStarter;
class CATDialog;
class CATCmdRep;
class CATCommand;
class CATString;
class CATVidWidget;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrFoundation IID IID_CATIHeaderGraphicProperties ;
#else
extern "C" const IID IID_CATIHeaderGraphicProperties ;
#endif

class ExportedByCATAfrFoundation CATIHeaderGraphicProperties : public CATBaseUnknown
{
 CATDeclareInterface;

 public:
    
  virtual CATCmdRep* CreateToolbarRep(CATCmdStarter *cmd,CATDialog *dia) = 0;
  virtual void DestroyToolbarRep(CATCmdStarter *cmd) = 0;
	virtual CATVidWidget* InitVidWidget(CATCommand *iStarterView,CATString iComboName) = 0;      

};

#endif
