#ifndef CATICkeLocalSet_H
#define CATICkeLocalSet_H

// COPYRIGHT DASSAULT SYSTEMES  2000

/** 
 * Interface used to discriminate our set of parameter (the one we put user parameters in) from Product Properties one
 */

#include "KnowledgeItf.h"

#include "CATBaseUnknown.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeLocalSet;
#else
extern "C" const IID IID_CATICkeLocalSet;
#endif

class ExportedByKnowledgeItf CATICkeLocalSet : public CATBaseUnknown
{
	CATDeclareInterface;
public:
};
CATDeclareHandler(CATICkeLocalSet,CATBaseUnknown);

#endif
