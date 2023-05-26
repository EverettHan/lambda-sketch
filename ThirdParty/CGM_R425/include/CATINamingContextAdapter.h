/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
// Creation: DEM

#ifndef CATINamingContextAdapter_h
#define CATINamingContextAdapter_h

#include "CATObjectModelerBase.h"

#include "CATINamingContext.h"

/**
 * @level Private
 * @usage U1
 */

/**
* Adapter for  CATINamingContext. Implements useful methods.
* Useful for GetObject_B migration.
*/
class ExportedByCATObjectModelerBase  CATINamingContextAdapter : public  CATINamingContext
{
public:

	/** @nodoc */
	CATINamingContextAdapter();

	/** @nodoc */
	virtual ~CATINamingContextAdapter();

	/** @nodoc */
	/* deprecated*/
  virtual CATBaseUnknown* GetObject (char * const name, 
				     CATIBindParameters*	params,
				     const CATIdent interfaceID);
  
  /** @nodoc */
  /* should migrate on GetObject_B with the other signature*/
  virtual CATBaseUnknown* GetObject_B (const SEQUENCE(octet)& binaryName, 
				       CATIBindParameters* params,
				       const CATIdent interfaceID)=0;

  /** @nodoc */
  virtual  HRESULT GetObject_B (const SEQUENCE(octet)& binaryName, 
				       CATIBindParameters* params,
				       const CATIdent interfaceID,CATBaseUnknown *& );
  /** @nodoc */
  /* deprecated*/
  virtual SEQUENCE(CATBaseUnknown_ptr) ListNamedObjects (
					 const CATIdent interfaceID);

 /** @nodoc */
 /* deprecated*/
  virtual CATLONG32 ListNamedObjectsHere (const CATIdent interfaceID,
				     SEQUENCE(CATBaseUnknown_ptr)& here);

  /** @nodoc */
  /* deprecated*/
  virtual SEQUENCE(octet) GetRelativeName_B   ( const CATBaseUnknown_var& object 
				               ,const CATUnicodeString& context);
  
  /** @nodoc */
  /* deprecated*/
  virtual boolean  CreateIndex ();
  
  /** @nodoc */
  /* deprecated*/
  virtual boolean  UnsetIndex  ();  
};

#endif

