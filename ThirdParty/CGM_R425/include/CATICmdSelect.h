#ifndef CATICmdSelect_H
#define CATICmdSelect_H 
//******************************************************************************
// CATIA Version 5 Release 2 
// Copyright Dassault Systemes 1999
//******************************************************************************
//  Abstract:
//  ---------
//  Created the command select under the control of a editor which are not the
//  current.
//
//******************************************************************************
//  Usage:
//  ------
// 
// 
//******************************************************************************
//  Inheritance:
//  ------------
//                CATBaseUnknown (System Framework).
//
//******************************************************************************
//  Main Methods:
//  ------------- 
//  CreateCommand
//  GetCommand
//******************************************************************************

#include "CATBaseUnknown.h"   // Needed to derive from CATBaseUnknown
#include "CATAfrItf.h"  // Module where is the .cpp

class CATFrmEditor ; // editor of the command
class CATCommand   ; // result of the interface
class CATString    ; // type of the argument

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATICmdSelect;
#else
extern "C" const IID IID_CATICmdSelect;
#endif

class ExportedByCATAfrItf CATICmdSelect : public CATBaseUnknown
{
  // Used in conjunction with CATImplementInterface in the .cpp file 
  CATDeclareInterface;

  public :

	virtual HRESULT  CreateCommand(CATFrmEditor * iEditor, CATString * iArgument=NULL) =0;
	virtual HRESULT  GetCommand   (CATCommand  ** oCommand) =0;

};
// Used in conjunction with CATImplementHandler in the .cpp file
CATDeclareHandler(CATICmdSelect,CATBaseUnknown);

#endif
