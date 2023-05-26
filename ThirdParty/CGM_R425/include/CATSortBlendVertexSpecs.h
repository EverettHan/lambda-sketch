#ifndef CATSortBlendVertexSpecs_H
#define CATSortBlendVertexSpecs_H

// COPYRIGHT DASSAULT SYSTEMES  2002
// creation JHG

#include "BODYNOPE.h"

#include "CATTopOperator.h"
#include "CATDynFilletBlendVertexSpec.h"
#include "ListPOfCATTopPropagationEdge.h"

class CATBody;
class CATListPtrCATICGMTopPropagationEdge;

// Decoupe une super arete selon la convexite

class ExportedByBODYNOPE CATSortBlendVertexSpecs : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATSortBlendVertexSpecs);
public:
   CATSortBlendVertexSpecs(CATGeoFactory* iFactory, CATTopData* iTopData);

  virtual ~CATSortBlendVertexSpecs();
   
  virtual int Run() = 0;

  virtual void GetResult(CATBoolean &oCouldBeOrdered, CATLISTP(CATDynFilletBlendVertexSpec) &oOrderedSpecs) = 0;

private:
};

ExportedByBODYNOPE CATSortBlendVertexSpecs *CATCreateSortBlendVertexSpecs(CATGeoFactory* iFactory, CATTopData* iTopData, CATBody *iBody,
                                                   CATLISTP(CATDynFilletBlendVertexSpec) &iSpecToOrder,
                                                   ListPOfCATTopPropagationEdge &iPropagationEdgeList);

ExportedByBODYNOPE CATSortBlendVertexSpecs *CATCreateSortBlendVertexSpecs(CATGeoFactory* iFactory, CATTopData* iTopData, CATBody *iBody,
                                                   CATLISTP(CATDynFilletBlendVertexSpec) &iSpecToOrder,
                                                   CATListPtrCATICGMTopPropagationEdge &iPropagationEdgeList);
#endif
