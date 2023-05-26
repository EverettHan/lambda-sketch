// ============================================================================
//
// CATWBModelHomogeneity
//
// ===================================================================
//  Dec 2011  Creation                     Eve-Marie Duclairoir (KJD)
// ===================================================================
#ifndef CATWBModelHomogeneity_H
#define CATWBModelHomogeneity_H

#include "WhiteBoxModel.h"
#include "CATCDSErrorDef.h"
#include "CATWBVisitor.h"
#include "CATCDSString.h"

class CATWBModel;
class CATWBNode;
class CATWBConstNode;
class CATWBVarNode;
class CATWBEqNode;
class CATWBOpNode;

class ExportedByWhiteBoxModel CATWBModelHomogeneity
{
public:
 static HRESULT CheckHomogeneity(CATWBModel & Model);
 static HRESULT CheckHomogeneity(CATWBEqNode & Node);
 static CATCDSString FillHomogeneity(CATWBNode * Node);

private:
	CATWBModelHomogeneity();
	CATWBModelHomogeneity(const CATWBModelHomogeneity &);//Necessary to prevent unwanted automatic creation by compiler
	void operator = (const CATWBModelHomogeneity &);
};
#endif 

