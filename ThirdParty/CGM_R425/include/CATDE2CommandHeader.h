//===================================================================
// COPYRIGHT Dassault Systemes 2014-09-09
//===================================================================
// CATDE2CommandHeader.cpp
// Header definition of class CATDE2CommandHeader
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2014-09-09 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATDE2CommandHeader_H
#define CATDE2CommandHeader_H

#include "CATCommandHeader.h"

//-----------------------------------------------------------------------

class ExportedByCATAfrFoundation CATDE2CommandHeader: public CATCommandHeader{
  CATDeclareClass;

public:
  // Standard constructors and destructors
  // -------------------------------------
  CATDE2CommandHeader ();
  virtual ~CATDE2CommandHeader ();
  
  // Introspectable properties getters and setters
  // -------------------------------------
  const CATUnicodeString  GetCmdName();
  void                    SetCmdName(const CATUnicodeString& iCmdName);

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATDE2CommandHeader (CATDE2CommandHeader &);
  CATDE2CommandHeader& operator=(CATDE2CommandHeader&);

};

//-----------------------------------------------------------------------

#endif
