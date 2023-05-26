/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES  1999
//=============================================================================
//
// Interface CATICCPFormatSupport
// Object to which the target object delegate its pasting operations.
//
//=============================================================================
// Usage Notes:
//
// The interface object's lifecycle should always be managed
// through the "CATCCPServices" Create and Delete functions.
// This enables code decoupling between CCP source and target.
// 
//=============================================================================
// June 99   Creation                                   NLL
//=============================================================================

#ifndef CATICCPFormatSupport_H
#define CATICCPFormatSupport_H

/**
 * @level Protected 
 * @usage U1
 */

#include "CP0CLIP.h"
#include "CATBaseUnknown.h"

class CATFormat;
class ListOfVarBaseUnknown;

extern ExportedByCP0CLIP IID IID_CATICCPFormatSupport ;

class ExportedByCP0CLIP CATICCPFormatSupport : public CATBaseUnknown
{
 public:
  CATDeclareInterface;

  virtual const CATFormat* GetFormat()=0;
  virtual const CATBaseUnknown* GetTarget()=0;
  
  virtual HRESULT CreateBeforePasteData(ListOfVarBaseUnknown* i_object_to_process,
					ListOfVarBaseUnknown* io_to_object,
					ListOfVarBaseUnknown* oFirstResult)=0;

  virtual HRESULT CreateAfterPasteData(ListOfVarBaseUnknown* i_object_to_process,
				       ListOfVarBaseUnknown* io_to_object,
				       ListOfVarBaseUnknown* ioFinalResult)=0;
};

CATDeclareHandler( CATICCPFormatSupport, CATBaseUnknown);


#endif

