 /* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1999 
//-----------------------------------------------------------------------------
// class CATECCPFormatSupport (extension) : 
// 
// All CATICCPFormatSupport adhesions of 'CCP-format Support' objects
// should derive from this base class.
//-----------------------------------------------------------------------------
// Creation nll    Jun 99
//-----------------------------------------------------------------------------
#ifndef CATECCPFormatSupport_H_
#define CATECCPFormatSupport_H_

/**
 * @level Protected 
 * @usage U1
 */

#include "CATObject.h"
#include "CP0CLIP.h"

class CATFormat;
class ListOfVarBaseUnknown;

class ExportedByCP0CLIP CATECCPFormatSupport : public CATBaseUnknown
{
 public:
  CATDeclareClass;

  CATECCPFormatSupport();
  virtual ~CATECCPFormatSupport();
  
  virtual const CATFormat* GetFormat();
  virtual const CATBaseUnknown* GetTarget();
  
  virtual HRESULT CreateBeforePasteData(ListOfVarBaseUnknown* i_object_to_process,
					ListOfVarBaseUnknown* io_to_object,
					ListOfVarBaseUnknown* oFirstResult);

  virtual HRESULT CreateAfterPasteData(ListOfVarBaseUnknown* i_object_to_process,
				       ListOfVarBaseUnknown* io_to_object,
				       ListOfVarBaseUnknown* ioFinalResult);

 protected :
  CATECCPFormatSupport( const CATECCPFormatSupport &);
  CATECCPFormatSupport& operator = (const CATECCPFormatSupport &);
 
};
 
#endif




