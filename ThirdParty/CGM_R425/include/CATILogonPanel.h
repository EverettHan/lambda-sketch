#ifndef CATILogonPanel_H
#define CATILogonPanel_H

// COPYRIGHT DASSAULT SYSTEMES 2005

///////////////////////////////////////////////////////////////////////////////
//    CATILogonPanel.h                                                       //
///////////////////////////////////////////////////////////////////////////////
//    PROJET:............CNEXT                                               //
//    FRAMEWORK:.........ApplicationFrame                                    //
//    AUTEUR:............Cécilia Miltgen                                     //
//    DATE:..............14/12/2005                                          //
///////////////////////////////////////////////////////////////////////////////

//=============================================================================
//
// Interface for Logon
//
//=============================================================================

#include "CATBaseUnknown.h"
#include "CATAfrItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATILogonPanel;
#else
extern "C" const IID IID_CATILogonPanel;
#endif

class CATDialog;
class CATStateCommand;
class CATUnicodeString;


class ExportedByCATAfrItf CATILogonPanel : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  virtual void CreatePanel(CATDialog * dlg, CATUnicodeString& fileName) = 0;
  virtual CATStateCommand * GetStateCommand() = 0;
};


//-----------------------------------------------------------------------------
//                             Handler
//-----------------------------------------------------------------------------

CATDeclareHandler(CATILogonPanel, CATBaseUnknown);

#endif
