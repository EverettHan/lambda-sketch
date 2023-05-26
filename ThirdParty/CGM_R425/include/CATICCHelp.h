#ifndef CATICCHelp_H
#define CATICCHelp_H

// COPYRIGHT DASSAULT SYSTEMES 2000

///////////////////////////////////////////////////////////////////////////////
//    CATICCHelp.h                                                           //
///////////////////////////////////////////////////////////////////////////////
//    PROJET:............CNEXT                                               //
//    FRAMEWORK:.........ApplicationFrame                                    //
//    AUTEUR:............Eric Ropars                                         //
//    DATE:..............24/01/1997                                          //
//             -----------------------------------------------               //
//    AUTEUR:............                                                    //
//    MODIF:.............                                                    //
//    DATE:..............  /  /1997                                          //
///////////////////////////////////////////////////////////////////////////////

// ==========================================================================
//
// Interface for Contextual help
//
// ==========================================================================

#include "CATIHelp.h"
#include "CATCommand.h"
#include "CATAfrItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATICCHelp;
#else
extern "C" const IID IID_CATICCHelp;
#endif

class CATNotification;

//===================================================================================
//              CATICCHelp :  D E C L A R A T I O N S
//===================================================================================

class ExportedByCATAfrItf CATICCHelp : public CATIHelp
{
  CATDeclareInterface;
  
public:
  virtual void CurrentCommandHelpCB (CATCommand *Cmd,
                                     CATNotification *Evt,
                                     CATCommandClientData Data) = 0;
  virtual void CurrentCommandPanelHelpCB (CATCommand *Cmd,
                                          CATNotification *Evt,
                                          CATCommandClientData Data) = 0;
} ;
#endif
