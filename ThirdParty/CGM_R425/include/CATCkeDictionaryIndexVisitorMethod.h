/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

#ifndef CATCkeDictionaryIndexVisitorMethod_h
#define CATCkeDictionaryIndexVisitorMethod_h

#include "CATLifDictionary.h"

#include "CATCkeDictionaryIndexVisitor.h"
#include "CATString.h"
#include "CATLISTV_CATBaseUnknown.h"

#include "CATKWEError.h"

//---------------------------------------------------------------
// Visiteur pour retrouver, dans l'index, une methode par son nom
//---------------------------------------------------------------
class ExportedByCATLifDictionary CATCkeDictionaryIndexVisitorMethod : public CATCkeDictionaryIndexVisitor {
	CATString _key;
	CATListValCATBaseUnknown_var& _liste;
	int _with_errors;
public:
	CATCkeDictionaryIndexVisitorMethod(const CATString& iKey, CATListValCATBaseUnknown_var& liste, int with_errors = 0);
	
	int isTypeToBeInspected(CATCkeDictionaryIndex::predefined_types t) const;
	void visit(CATCkeDictionaryIndexElement& pElt);
};

class ExportedByCATLifDictionary CATKweMethodNotLoadableFromIndex : public CATKWEError
{
	CATDeclareClass;

public:
	CATKweMethodNotLoadableFromIndex();
	CATKweMethodNotLoadableFromIndex(const CATKweMethodNotLoadableFromIndex&);

	virtual CATKWEError* Clone() const;
};
#endif
