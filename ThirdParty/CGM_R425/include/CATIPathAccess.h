#ifndef CATIPathAccess_h
#define CATIPathAccess_h

// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1998
//
//----------------------------------------------------------------
//
// Abstract :  interface auquelle doit souscrire un objet modele
// ----------  capable de generer un CATPathElement
//
//            
//   
//-----------------------------------------------------------------
//
//  Usage :    
//  -------   
//           
//
//-----------------------------------------------------------------
//
//  Inheritance :   CATIPathAccess
//  -------------     CATBaseUnknown
//
//-----------------------------------------------------------------
//
//  Main Methods :
//  --------------
//                   GetPathElement()
//
//-----------------------------------------------------------------
#include "CATVisItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIPathAccess;
#else
extern "C" const IID IID_CATIPathAccess;
#endif

class CATPathElement;

class ExportedByCATVisItf CATIPathAccess : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////
 
  virtual CATPathElement * ExtractPathElement () = 0 ;

}; 

CATDeclareHandler(CATIPathAccess,CATBaseUnknown);

#endif
