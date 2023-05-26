#ifndef CATWindowHeader_h
#define CATWindowHeader_h
#include "CATAfrFoundation.h"

//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 1996
//-----------------------------------------------------------------------------
// Abstract: header of a command that calls the window ExecuteCommand method
//-----------------------------------------------------------------------------
// Usage:    instanciate and assign to a menu or toolbar
//-----------------------------------------------------------------------------

#include "CATMacInterface.h"
#include "CATCommandHeader.h"

class CATString;

class ExportedByCATAfrFoundation CATWindowHeader : public CATCommandHeader
{
  
  CATDeclareClass;
  CATDeclareHeaderResources;
  
public:
  
  CATWindowHeader (const CATString & iHeaderID,
                   const CATString & iArgument,
                   int iState = CATFrmAvailable);
  virtual ~CATWindowHeader ();
  
  virtual CATCommandHeader * Clone ();
  
protected:
  
  CATWindowHeader (CATCommandHeader * iHeader);
  
private:

  CATString * _pargument;  

};

#endif
