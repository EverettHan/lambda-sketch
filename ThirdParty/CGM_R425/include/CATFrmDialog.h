/**
 * @fullreview CMG-ERS 02:07:11
 * @error MISC  Y manque class CATDialog et CATString
 * @error MISC  Y manque include CATDlgUtility
 * @error MISC  N pas de constructeur par defaut, par copie et pas d'operateur =
*/
#ifndef CATFrmDialog_h
#define CATFrmDialog_h

// COPYRIGHT DASSAULT SYSTEMES 2000

// Obsolete, do not use.

#include <CATAfrFoundation.h>
#include <CATDlgDialog.h>
#include <CATDlgUtility.h>

class CATDialog;
class CATString;

class ExportedByCATAfrFoundation CATFrmDialog : public CATDlgDialog
{
  CATDeclareClass;
  
public:
  
  CATFrmDialog(CATDialog * pParent,
	       const CATString & rObjectName,
	       CATDlgStyle nStyle = NULL);
  virtual ~CATFrmDialog();
  
private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  //CATFrmDialog ();
  //CATFrmDialog (const CATFrmDialog &);
  //CATFrmDialog & operator= (const CATFrmDialog &);
};

#endif
