// ============================================================================
//
// CATWBNodeSorter
//
// ===================================================================
//  Oct 2011  Creation                     Eve-Marie Duclairoir (KJD)
// ===================================================================
#ifndef CATWBNodeSorter_H
#define CATWBNodeSorter_H

#include "CATCDSVirtual.h"
#include "WhiteBoxModel.h"
#include "CATWBNodeSorter.h"
#include "CATWBModel.h"
#include "CATWBVisitor.h"
#include "CATWBTypes.h"
#include "CATWBValue.h"
#include "CATCDSString.h"
#include "CATCDSBoolean.h"
#include "CATCDSListP.h"
#include "CATWBLocation.h"
#include "CATCDSErrorDef.h"

class CATWBConstNode;
class CATWBVarNode;
class CATWBEqNode;
class CATWBOpNode;


class ExportedByWhiteBoxModel CATWBNodeSorter : public CATWBVisitor
{
public:
//Constructor and destructor
  CATWBNodeSorter();
  virtual ~CATWBNodeSorter();

  HRESULT GetVariables(CATWBModel & iModel, CATCDSLISTP(CATCDSString) & oListOfNames,CATCDSLISTP(CATWBLocation) & oLoc);

  HRESULT GetConstants(CATWBModel & iModel, CATCDSLISTP(CATWBValue) & oListOfValue,CATCDSLISTP(CATWBLocation) & oLoc);

  HRESULT GetConstants(CATWBModel & iModel, 
                                             CATCDSLISTP(CATWBValue) & oListOfValue,CATCDSLISTP(CATWBLocation) & oLoc,
                                             CATCDSLISTP(CATCDSString) & oListOfUnits,CATCDSLISTP(CATWBLocation) & oUnitLoc);

private:
  virtual HRESULT VisitModel(CATWBModel & Model ) CATCDSOverride ;  
  virtual HRESULT VisitConstant(CATWBConstNode & ConstNode) CATCDSOverride ;
  virtual HRESULT VisitVariable(CATWBVarNode & VarNode) CATCDSOverride ;
  virtual HRESULT VisitEquation(CATWBEqNode & EqNode) CATCDSOverride ;
  virtual HRESULT VisitOperator(CATWBOpNode & OpNode) CATCDSOverride;


private:
  CATWBNodeType  _RequestedType;
  CATCDSBoolean _WithUnit;
  CATCDSLISTP(CATCDSString) _ListOfNames;
  CATCDSLISTP(CATWBValue) _ListOfValues;
  CATCDSLISTP(CATWBLocation) _ListOfLocations;
  CATCDSLISTP(CATCDSString) _ListOfUnits;
  CATCDSLISTP(CATWBLocation) _ListOfLocationsOfUnits;
};
#endif 
