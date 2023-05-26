/* -*-C++-*- */
// Copyright Dassault Systemes 1997
//-----------------------------------------------------------------------------
// Abstract: 
//-----------------------------------------------------------------------------
// Usage:    
//           
//-----------------------------------------------------------------------------
// Inheritance: CATFrmRadioHeader
//                CATRadioHeader
//-----------------------------------------------------------------------------
// Main methods:    
//       
//-----------------------------------------------------------------------------
#ifndef CATFrmRadioHeader_H
#define CATFrmRadioHeader_H

#include "CATAfrFoundation.h"
#include "CATRadioHeader.h"

class CATCommandHeader;

#include "CATListOfCATString.h"

class ExportedByCATAfrFoundation CATFrmRadioHeader : public CATRadioHeader
{ 
  CATDeclareKindOf;
  
public:
  CATFrmRadioHeader (const CATString &);
  virtual ~CATFrmRadioHeader();
  
  virtual CATCommandHeader * Clone();
  
  virtual CATCommand * StartCommand();
  
  CATListOfCATString  GetCmdList();
  
  void        AddItem   (const CATString& cmdName);
  void        BeginItem (const CATString& cmdName);
  void        EndItem   (const CATString& cmdName);
  void        RemoveItem(const CATString& cmdName);
  
  // Get button sensitivity at button creation. Depends on represented headers
  CATULong GetInitialSensitivity(int num);

  virtual void AcceptVisitor(AfrICommandHeaderVisitor* i_pVisitor) override;

protected:
  CATFrmRadioHeader (CATCommandHeader *);
  
private:
  
  CATListOfCATString     _cmdList;
  
  CATDeclareHeaderResources;

public:
  CATString GetSelectedHeader();
};
#endif
