// COPYRIGHT DASSAULT SYSTEMES  1997
//=============================================================================
//
// CATICkeRelationSet.h:
//   This is an object that contains a list of
//     - relations
//     - expressions
//     - local parameters
//
//=============================================================================
// Usage Notes:
//
// Interface of Relation object.
//
//=============================================================================
// 01/14/97   Creation                                   A. Anquetil
//=============================================================================

#ifndef  CATICkeRelationSet_H
#define  CATICkeRelationSet_H

//Interface deriving from
#include "KnowledgeItf.h"
#include "CATICkeRelationForwards.h"
#include "CATICkeNaming.h"


//SpecsModeler
//#include "CATISpecObject.h"

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeRelationSet;
#else
extern "C" const IID IID_CATICkeRelationSet;
#endif

class ExportedByKnowledgeItf CATICkeRelationSet : public CATICkeNaming
{

  CATDeclareInterface;

public:

// Get list of Relations 
virtual CATCkeListOfRelation    Relations () const = 0;

};

CATDeclareHandler(CATICkeRelationSet,CATICkeNaming);


#endif
