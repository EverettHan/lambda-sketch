// Copyright Dassault Systemes 2000
#ifndef CATICkeFvar_h
#define CATICkeFvar_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Cke Engineering Equations
// 	declaration of Formal Parameters 
//	this interface is NOT public
//
//////////////////////////////////////////////////////////////////////////
#include "CATLifSpecs.h"

#include "CATICkeTerm.h"
#include "CATICkeArg.h"
#include "CATICkeParm.h"
#include "CATICkeUnit.h"

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeFvar;
#else
extern "C" const IID IID_CATICkeFvar;
#endif

class ExportedByCATLifSpecs CATICkeFvar: public CATICkeTerm
{

public :
  
  // name
  virtual CATUnicodeString  Name    () const =0;
  virtual CATUnicodeString  RelativeName (const CATIParmPublisher_var &iRoot) const =0; 
  virtual void            Rename    (CATUnicodeString s) =0;

  virtual  CATICkeArg_var  Argument    () const = 0;
  virtual  CATCke::Boolean  	   IsSet       () const = 0;
  virtual  CATCke::Boolean  	   IsOutside   () const = 0;
  virtual  CATICkeInst_var Value       () const = 0;
  virtual CATCke::Boolean     	IsConst     () const = 0;

  // Layer-dependant services
  virtual  void     Valuate     (const CATICkeInst_var &v) = 0;
  virtual  void     Assign      (const CATICkeParm_var &p) = 0;
  virtual  void     Unset       () = 0;


	// Modification and access to units representations of a parameter
  virtual CATICkeUnit_var  Unit () const = 0;
  virtual void             SetUnit (const CATICkeUnit_var &u) = 0;  

private:

  // 2 define ClassName
  CATDeclareInterface;

}; 

CATDeclareHandler(CATICkeFvar,CATICkeTerm);

#endif


