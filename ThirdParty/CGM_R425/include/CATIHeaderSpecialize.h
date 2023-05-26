/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
//  CATIHeaderSpecialize :
//  Class for managing callback and rep associated to command header
//            
//
//==================================================================
//  Usage notes
//  
//    - StartCallback : allows to set callback in order to intercept
//         events as soon as the command header is activated
//    - CleanCallback : remove all the callbacks when the command 
//         header is desactivated
//    - CreateSpecializedMenuRep : allows to create much specialized
//         menu rep for a command header.
//    - GetStatus : tells if a command is available or not
//==================================================================
#ifndef CATIHeaderSpecialize_H
#define CATIHeaderSpecialize_H

#include "CATBaseUnknown.h"
#include "CATAfrItf.h"
class CATCmdStarter;
class CATDialog;
class CATCmdRep;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIHeaderSpecialize ;
#else
extern "C" const IID IID_CATIHeaderSpecialize ;
#endif

class ExportedByCATAfrItf CATIHeaderSpecialize : public CATBaseUnknown
{
  CATDeclareInterface;

    public:

    virtual HRESULT StartCallback ()  = 0 ;
    virtual HRESULT CleanCallback ()  = 0 ;
    virtual HRESULT CreateSpecializedMenuRep (CATCmdStarter* MyCmdStarter, 
					      CATDialog* Mydialog, 
					      CATCmdRep*& MyCmdRep )  = 0 ;
    virtual HRESULT DeleteSpecializedMenuRep (CATCmdStarter* MyCmdStarter)  = 0 ;
    virtual int GetStatus ()  = 0 ;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(CATIHeaderSpecialize, CATBaseUnknown ) ;


#endif
