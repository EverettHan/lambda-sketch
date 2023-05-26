#ifndef CATIDecoderAgent_H
#define CATIDecoderAgent_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1998
// protected DI0APPLI.m + CATDegUUID.m

//------------------------------------------------------------------------------
// Abstract: definition of the interface CATIDecoderAgent 
//           which decodes notifications received by a CATDialogAgent
//
//------------------------------------------------------------------------------
// Usage:    it is used by a CATDialogAgent whose decode depends on the
//           context (2D or 3D Visualization)
//------------------------------------------------------------------------------
// Inheritance: CATIDecoderAgent (DialogEngine framework)
//                CATBaseUnknown (System framework)
//------------------------------------------------------------------------------
// Main methods 
//
//           InitDecode
//           ResetDecode
//           Decode
//           
//------------------------------------------------------------------------------

#include "CATBaseUnknown.h"

class CATNotification;
class CATCommand;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATDialogEngine IID IID_CATIDecoderAgent;
#else
extern "C" const IID IID_CATIDecoderAgent;
#endif

class ExportedByCATDialogEngine CATIDecoderAgent : public CATBaseUnknown
{
  
  CATDeclareInterface;
  
public:
  
  // initializes decode
  virtual void InitDecode () = 0;
  // resets decode because no more notification will be send
  virtual void ResetDecode () = 0;
  // Decodes, returns S_OK if the decode succeeds.
  virtual HRESULT Decode (CATCommand * sender, CATNotification * notif) = 0;

};
 
// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler (CATIDecoderAgent, CATBaseUnknown);

#endif
