#ifndef CATDiaOdt_h
#define CATDiaOdt_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1996
// private DI0GRAF.m

//------------------------------------------------------------------------------
// Abstract: Odt Manager
//------------------------------------------------------------------------------
// Usage:   This class is used to write (and read) ODT
//------------------------------------------------------------------------------
#include "CATCommand.h"
#include "CATString.h"
#include "CATUnicodeString.h"

//--------------------------------------------------------------------------
class ExportedByCATDialogEngine CATDiaOdt : public CATCommand
{

public:
  
  CATDiaOdt (const CATString & output);
  virtual ~CATDiaOdt ();
  
  void SetMessage (const CATString &);
  void SetStateMessage (const CATUnicodeString & text);
  CATUnicodeString & GetStateMessage ();
  
  static CATDiaOdt * GetOdtServer ();
  
private:
  
  CATString _outputString;
  CATUnicodeString _StateMessage;
  int _lserver;
  unsigned int _outputFile;
  
  static CATDiaOdt * _server;
  
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATDiaOdt ();
  CATDiaOdt (const CATDiaOdt &);
  CATDiaOdt & operator= (const CATDiaOdt &);

};

#endif
