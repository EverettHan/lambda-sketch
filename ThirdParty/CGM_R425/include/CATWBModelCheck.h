// ============================================================================
//
// CATWBModelCheck
//
// The recognized units are : 
//  - for the distances : "km"  , "m"  , "cm"  , "mm"  , "nm"   , "in"   , "ft"  , "micron"  , "yard"  , "mile" , "in_ft"
//  - for the angles : "rad"  , "deg"  , "grad"  , "turn"  , "mrad"  , "in_ft"  , "%_angle"
//  - for others :"°"  , "'" , "\""
//
// ===================================================================
//  Dec 2011  Creation                     Eve-Marie Duclairoir (KJD)
// ===================================================================
#ifndef CATWBModelCheck_H
#define CATWBModelCheck_H

#include "CATCDSVirtual.h"
#include "WhiteBoxModel.h"
#include "CATCDSErrorDef.h"
#include "CATWBVisitor.h"

class CATWBModel;
class CATWBConstNode;
class CATWBVarNode;
class CATWBEqNode;
class CATWBOpNode;
class CATWBParserMessenger;

class ExportedByWhiteBoxModel CATWBModelCheck : public CATWBVisitor
{
public:
  //Constructor and destructor
  CATWBModelCheck(CATWBModel * ipModel, CATWBParserMessenger * ipMessenger);
  virtual ~CATWBModelCheck();

  int Run();

private :
  //Visitors
  virtual HRESULT VisitModel(CATWBModel & Model ) CATCDSOverride ;  
  virtual HRESULT VisitConstant(CATWBConstNode & ConstNode) CATCDSOverride ;
  virtual HRESULT VisitVariable(CATWBVarNode & VarNode) CATCDSOverride ;
  virtual HRESULT VisitEquation(CATWBEqNode & EqNode) CATCDSOverride ;
  virtual HRESULT VisitOperator(CATWBOpNode & OpNode) CATCDSOverride;

private :
  CATWBModel * _pModel;
  CATWBParserMessenger  * _pMessenger;
  int _CurrentEqId;

};
#endif 
