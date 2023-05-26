/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

#ifndef CATCkeDictionaryIndexVisitor_H
#define CATCkeDictionaryIndexVisitor_H

#include "CATLifDictionary.h"

#include "CATCkeDictionaryIndex.h"

class CATCkeDictionaryIndexElement;

//-------------------
// Classe de visiteur
//-------------------
class ExportedByCATLifDictionary CATCkeDictionaryIndexVisitor
{
public:
	CATCkeDictionaryIndexVisitor();
	virtual ~CATCkeDictionaryIndexVisitor();

	virtual void visit(CATCkeDictionaryIndexElement& pElt) = 0;

	virtual int isEndOfVisit() const;
	virtual int isTypeToBeInspected(CATCkeDictionaryIndex::predefined_types t) const;
	virtual int visitNotInstalledElement() const;
};

#endif
