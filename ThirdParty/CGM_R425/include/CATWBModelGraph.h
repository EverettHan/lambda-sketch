// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBModelGraph.h
// Header definition of CATWBModelGraph
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//  Apr 2009  Creation                     E.-M-Duclairoir, DS.
//===================================================================

#ifndef CATWBModelGraph_h
#define CATWBModelGraph_h

#include "CATCDSVirtual.h"
#include "CATWBExpression.h"
#include "CATWBEquation.h"

#include "WhiteBoxModel.h"
#include "CATCDSStream.h"
#include "CATWBVisitor.h"
#include "CATCDSErrorDef.h"

//-----------------------------------------------------------------------

class ExportedByWhiteBoxModel CATWBModelGraph : public CATWBVisitor
{
public:
  CATWBModelGraph();

  virtual HRESULT VisitModel(CATWBModel & Model ) CATCDSOverride ;  
  virtual HRESULT VisitConstant(CATWBConstNode & ConstNode) CATCDSOverride ;
  virtual HRESULT VisitVariable(CATWBVarNode & VarNode) CATCDSOverride ;
  virtual HRESULT VisitEquation(CATWBEqNode & EqNode) CATCDSOverride ;
  virtual HRESULT VisitOperator(CATWBOpNode & OpNode) CATCDSOverride;

 

CATWBModel * _Model; 
CATCDSString _ShortPath;
CATCDSStream * _pStream;
};

//-----------------------------------------------------------------------

#endif
