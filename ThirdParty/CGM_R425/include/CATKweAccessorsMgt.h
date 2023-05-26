// Copyright Dassault Systemes 2000
#ifndef CATKweAccessorsMgt_H
#define CATKweAccessorsMgt_H

#include "CATLifSpecs.h"
#include "CATAttributeInfos.h"
class CATBaseUnknown_var;
class CATUnicodeString;

class CATHashDico;




/**
* Used to manage lifecycle of list of accessors
*/

class ExportedByCATLifSpecs CATKweAccessorsMgt
{
public:

	static void CleanAccessors();
	// Accesses a value thanks to the accessors
	static CATBaseUnknown* GetAccessor(const CATAttributeInfos& info);
	static CATBaseUnknown* GetAccessor(const CATUnicodeString & className);	
	
	// Accesses controllers
	static CATBaseUnknown* GetController(const CATUnicodeString & className);	
private:
	 
	static CATHashDico *_pHashAccessors;
	static CATHashDico *_pHashControllers;

};

#endif
