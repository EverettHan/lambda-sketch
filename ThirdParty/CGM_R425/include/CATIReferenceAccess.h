/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//================================================================
/**
 *  CATIReferenceAccess :
 *   
 */
//================================================================
//  Usage notes :
//
//
//		07/98		bpe
//================================================================
#ifndef CATIReferenceAccess_h
#define CATIReferenceAccess_h

#include "CATBaseUnknown.h"
#include "CATBSTR.h"
#include "CATIAReference.h"
#include "InfModelInterfaces.h"



extern ExportedByInfModelInterfaces IID IID_CATIReferenceAccess ;

class ExportedByInfModelInterfaces CATIReferenceAccess : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  // -- methodes de gestion 
  virtual CATIAReference_var GetReferenceFromObject(const CATBaseUnknown_var  &iLinkable) = 0;

  // --- Methodes de Creation 
  // creation d'un feature BRep a partir de  la string de journaling
  virtual CATIAReference_var CreateSpecReferenceFromName(const CATBSTR &str) = 0;

  // creation d'un objet de selection a partir de la string de journaling 
  virtual CATIAReference_var CreateReferenceFromName(const CATBSTR &str) = 0;
 
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIReferenceAccess, CATBaseUnknown ) ;


#endif
