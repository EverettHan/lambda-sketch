/* -*-c++-*- */
#ifndef CATBINDINTERFACE_h
#define CATBINDINTERFACE_h

/**
* @level Private
* @usage U1
*/

//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATBaseUnknown.h"
#include "sequence_octet.h"
#include "stringDef.h"
#include "AC0XXLNK.h"

// ========================================================================================
//  CATBindInterface_B : 
//  --------------------
//    Allows to recover an object from its binary name.
//    The binary name is generated through two methods  :
//       CATISymbolicLink  ::GetName_B
//       CATILinkableObject::GetName_B
//
//    The recovery of the object implies eventually to reload the document containing
//    the object to recover. 
//    Thus, the recovery strategy can be customized through the CATIBindParameters argument.
//
//  CATBindParams :
//  ---------------
//   One default bind object is managed for which strategy parameters can be set.
//   One can use it to avoid reimplementing the CATIBindParameters interface.
//  CATBindParams :
//  ---------------
//   One default bind object is managed for which strategy parameters can be set.
//   One can use it to avoid reimplementing the CATIBindParameters interface.
// ========================================================================================

class CATString;
class CATIBindParameters ;
class CATUnicodeString;


ExportedByAC0XXLNK 
CATBaseUnknown* CATBindInterface_B (const SEQUENCE(octet)& iBinaryName, 
				    const CATIdent 	   iIntfID,
				    CATIBindParameters*	   iParams=0,
				    CATUnicodeString*      iErrMsg = NULL) ;

ExportedByAC0XXLNK 
CATBaseUnknown* CATBindInterface (char*   		name,
				  const CATIdent 	interfaceID,
				  CATIBindParameters*	params=0) ;
				  

ExportedByAC0XXLNK 
CATBaseUnknown*  BindToSessionSymbols( const SEQUENCE(octet)&  binaryName
				      ,const CATIdent 	   interfaceID);


ExportedByAC0XXLNK CATIBindParameters* CATBindParams () ;


#endif

