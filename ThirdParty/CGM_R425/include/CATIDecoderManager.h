#ifndef CATIDecoderManager_H
#define CATIDecoderManager_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1998
// protected DI0APPLI.m + CATDegUUID.m

//------------------------------------------------------------------------------
// Abstract: definition of the interface CATIDecoderManager 
//           which manages a list of CATIDecoderAgent
//
//------------------------------------------------------------------------------
// Usage:    it is used by a CATDialogAgent to be associated with CATIDecoderAgent
//------------------------------------------------------------------------------
// Inheritance: CATIDecoderManager (DialogEngine framework)
//                CATBaseUnknown (System framework)
//------------------------------------------------------------------------------
// Main methods 
//
//           AddDecoder
//           RemoveDecoder
//           GetDecoderListSize
//           GetDecoder
//           
//------------------------------------------------------------------------------

#include "CATBaseUnknown.h"

#include "CATIDecoderAgent.h"

class CATNotification;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATDialogEngine IID IID_CATIDecoderManager;
#else
extern "C" const IID IID_CATIDecoderManager;
#endif

class ExportedByCATDialogEngine CATIDecoderManager : public CATBaseUnknown
{
  
  CATDeclareInterface;
  
public:
  
  // Adds a decode interface
  virtual void AddDecoder (CATIDecoderAgent_var decoder) = 0;
  // Removes a decode interface
  virtual void RemoveDecoder (CATIDecoderAgent_var decoder) = 0;
  // gives the number of decode interfaces
  virtual int GetDecoderListSize () = 0;
  // returns a decode interface according to its location in the list
  virtual CATIDecoderAgent_var GetDecoder (int num) = 0;
  // Tells the decoder manager that the decoding begins
  virtual void BeginDecoding () = 0;
  
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler (CATIDecoderManager, CATBaseUnknown);

#endif
