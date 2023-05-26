#ifndef CATIHelp_H
#define CATIHelp_H

// COPYRIGHT DASSAULT SYSTEMES 2000

///////////////////////////////////////////////////////////////////////////////
//    CATIHelp.h                                               //
///////////////////////////////////////////////////////////////////////////////
//    PROJET:............CNEXT                                               //
//    FRAMEWORK:.........ApplicationFrame                                  //
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

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATAfrItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIHelp;
#else
extern "C" const IID IID_CATIHelp;
#endif

//===================================================================================
//              CATIHelp :  D E C L A R A T I O N S
//===================================================================================

class ExportedByCATAfrItf CATIHelp : public CATBaseUnknown
{
  
  CATDeclareInterface;
  
  
public:

  virtual CATUnicodeString  GetContextualHelp ()                        = 0;
  virtual void              SetContextualHelp (CATUnicodeString s)      = 0;

  virtual CATString         GetContextualDocModule ()                   = 0;
  virtual void              SetContextualDocModule (CATString s)        = 0;
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIHelp, CATBaseUnknown ) ;

#endif
