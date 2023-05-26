/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000
/** 
 * @level Private 
 * @usage U3 
*/
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

#ifndef CATINamingContext_h
#define CATINamingContext_h

#include "stringDef.h"
#include "booleanDef.h"
#include "sequence_octet.h"
#include "CATBaseUnknown.h"
#include "sequence_CATBaseUnknown.h"
#include "CosLinkable.h"
#include "CATDataType.h"

// ==================================================================================
//    Usage :
//        Services for objects naming and objects recover in context.
//
//        GetObject_B  -> Recover an object relatively named to the context
//                        by the "binaryName"
//
//
//        GetRelativeName_B    -> returns the relativeName to the context of "object".  
//                        "context" is a string to help self to localize "object" in it.
//                        returns a null sequence if object cannot be named
//                        contextually to self
//
//        CreateIndex  -> create an index on all linkable objects contextual to self
//                        to fasten the resolution
//                        returns TRUE in case of success, FALSE in other cases
//        UnsetIndex   -> unset the index previously created.
//
// ==================================================================================
class CATIBindParameters ;


#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATINamingContext ;

class CATUnicodeString;
class ExportedByAD0XXBAS CATINamingContext : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /** @nodoc */
  virtual CATBaseUnknown* GetObject (char * const name, 
				     CATIBindParameters*	params,
				     const CATIdent interfaceID)=0 ;

 /** @nodoc */
  // Deprecated
  virtual CATBaseUnknown* GetObject_B (const SEQUENCE(octet)& binaryName, 
				       CATIBindParameters* params,
				       const CATIdent interfaceID)=0 ;

   /** @nodoc */
  virtual  HRESULT GetObject_B (const SEQUENCE(octet)& binaryName, 
				       CATIBindParameters* params,
				       const CATIdent interfaceID,CATBaseUnknown*& oRes)=0 ;

  
  /** @nodoc */
  virtual SEQUENCE(CATBaseUnknown_ptr) ListNamedObjects (
					 const CATIdent interfaceID)=0 ;
  /** @nodoc */
  virtual CATLONG32 ListNamedObjectsHere (const CATIdent interfaceID,
				     SEQUENCE(CATBaseUnknown_ptr)& here)=0;

  /** @nodoc */
  virtual SEQUENCE(octet) GetRelativeName_B   ( const CATBaseUnknown_var& object 
				               ,const CATUnicodeString& context) = 0;
   /** @nodoc */
  virtual boolean  CreateIndex () = 0;
  
  /** @nodoc */
  virtual boolean  UnsetIndex  () = 0;
  
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATINamingContext, CATBaseUnknown ) ;

//
// WARNING :
// Some Naming Contexts can not list their named objects.
// In that case the returned sequence is empty.
//

#endif
