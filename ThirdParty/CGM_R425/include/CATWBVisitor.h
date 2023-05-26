// ============================================================================
//
// CATWBVisitor
//
// ===================================================================
//  Oct 2011  Creation                     Eve-Marie Duclairoir (KJD)
// ===================================================================
#ifndef CATWBVisitor_H
#define CATWBVisitor_H

#include "WhiteBoxModel.h"
#include "CATCDSErrorDef.h"
class CATWBModel;
class CATWBConstNode;
class CATWBVarNode;
class CATWBEqNode;
class CATWBOpNode;

class ExportedByWhiteBoxModel CATWBVisitor
{
public:
//Constructor and destructor
  CATWBVisitor();
  virtual ~CATWBVisitor();
 
//Visitors
  virtual HRESULT VisitModel(CATWBModel & Model ) ;  
  virtual HRESULT VisitConstant(CATWBConstNode & ConstNode) ;
  virtual HRESULT VisitVariable(CATWBVarNode & VarNode) ;
  virtual HRESULT VisitEquation(CATWBEqNode & EqNode) ;
  virtual HRESULT VisitOperator(CATWBOpNode & OpNode);

};
#endif 
