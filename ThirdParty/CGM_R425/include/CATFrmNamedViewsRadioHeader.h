/* -*-C++-*- */
// Copyright Dassault Systemes 2000
//-----------------------------------------------------------------------------
// Abstract: 
//-----------------------------------------------------------------------------
// Usage:    
//           
//-----------------------------------------------------------------------------
// Inheritance: CATFrmNamedViewsRadioHeader
//                CATRadioHeader
//-----------------------------------------------------------------------------
// Main methods:    
//       
//-----------------------------------------------------------------------------
#ifndef CATFrmNamedViewsRadioHeader_H
#define CATFrmNamedViewsRadioHeader_H

#include "CATAfrFoundation.h"
#include "CATRadioHeader.h"

class CATCommandHeader;

#include "CATListOfCATString.h"

class ExportedByCATAfrFoundation CATFrmNamedViewsRadioHeader : public CATRadioHeader
{ 
  CATDeclareKindOf;
  
public:
  CATFrmNamedViewsRadioHeader (const CATString &);
  virtual ~CATFrmNamedViewsRadioHeader();
  
  virtual CATCommandHeader * Clone();
  
  virtual CATCommand * StartCommand();
  
  CATListOfCATString  GetCmdList();
  
  void        AddItem   (const CATString& cmdName);
  void        BeginItem (const CATString& cmdName);
  void        EndItem   (const CATString& cmdName);
  void        RemoveItem(const CATString& cmdName);
  
  
protected:
  CATFrmNamedViewsRadioHeader (CATCommandHeader *);
  
private:
  
  CATListOfCATString     _cmdList;
  
  CATDeclareHeaderResources;
};
#endif
