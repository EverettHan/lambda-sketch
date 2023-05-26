#ifndef CATDecoderManagerImpl_H
#define CATDecoderManagerImpl_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0APPLI.m

//------------------------------------------------------------------------------
// Abstract: default implementation of the CATDecoderManagerImpl interface
//
//------------------------------------------------------------------------------
// Usage:    it is used by a CATDialogAgent to be associated to CATIDecoderAgent
//           the agent must be extended with a class derived from CATDecoderManagerImpl
//------------------------------------------------------------------------------
// Inheritance: CATDecoderManagerImpl (DialogEngine framework)
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
#include "CATCollec.h"

class CATLISTV(CATBaseUnknown_var);

class CATNotification;

class ExportedByCATDialogEngine CATDecoderManagerImpl : public CATBaseUnknown
{
  
  CATDeclareClass;
  
public:
  
  CATDecoderManagerImpl ();
  virtual ~CATDecoderManagerImpl ();
  
  // Add a decode interface
  virtual void AddDecoder (CATIDecoderAgent_var decoder);
  // Remove a decode interface
  virtual void RemoveDecoder (CATIDecoderAgent_var decoder);
  // give the number of decode interfaces
  virtual int GetDecoderListSize ();
  // returns a decode interface according to its location in the list
  virtual CATIDecoderAgent_var GetDecoder (int num);
  // Tells the decoder manager the decoding begins
  virtual void BeginDecoding ();
  
  
private:
  
  CATLISTV(CATBaseUnknown_var) * _DecoderList;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATDecoderManagerImpl (const CATDecoderManagerImpl &);
  CATDecoderManagerImpl & operator= (const CATDecoderManagerImpl &);

};

#endif
