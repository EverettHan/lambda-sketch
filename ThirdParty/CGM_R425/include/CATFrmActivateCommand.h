/**
 * @fullreview CVE-ERS 02:02:21
 * @error MISC Y pas de constructeur par copie et pas d'operateur =
*/
#ifndef CATFrmActivateCommand_H
#define CATFrmActivateCommand_H
//
// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// Class CATEditCom:
// PartDesign 
//
//=============================================================================
// Usage Notes:
// Lancement de l'activate de CATIEdit sur le CSO
// CATFrmActivateCommand();
//=============================================================================
// NOV. 97 - Creation: DBI
//

#include "CATCommand.h"
#include "CATIEdit.h"
#include "CATAfrFoundation.h"

class ExportedByCATAfrFoundation CATFrmActivateCommand : public CATCommand {

  CATDeclareClass;

public:

  CATFrmActivateCommand   ();

  virtual ~CATFrmActivateCommand();

  CATStatusChangeRC Activate (
    CATCommand      * iFromClient,
    CATNotification * iEvtDat
    );
  
 private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATFrmActivateCommand (const CATFrmActivateCommand &);
  CATFrmActivateCommand & operator= (const CATFrmActivateCommand &);
  
};
#endif // CATFrmActivateCommand_H
  

