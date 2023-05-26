/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

#ifndef CATCkeDictionaryIndexVisitorInstalledPackages_H
#define CATCkeDictionaryIndexVisitorInstalledPackages_H

#include "CATLifDictionary.h"

#include "CATCkeDictionaryIndexVisitor.h"
#include "CATListOfCATUnicodeString.h"

class ExportedByCATLifDictionary CATCkeDictionaryIndexVisitorInstalledPackages : public CATCkeDictionaryIndexVisitor {
	CATListOfCATUnicodeString& _retour;
	
public:
	CATCkeDictionaryIndexVisitorInstalledPackages(CATListOfCATUnicodeString& l);
	
	virtual void visit(CATCkeDictionaryIndexElement& pElt);
	virtual int visitNotInstalledElement() const;
};

#endif
