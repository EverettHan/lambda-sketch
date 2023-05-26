/* -*-C++-*- */

#ifndef CATCVMWBEquationTreeNode_H
#define CATCVMWBEquationTreeNode_H

// COPYRIGHT DASSAULT SYSTEMES 2006
#include"CATCVMGeoObjects.h"
#include "CATCGMNewArray.h"

enum CATCVMWBOp
{
    CATCVMWBOpPlus = 0,
    CATCVMWBOpMinus = 1,
    CATCVMWBOpTimes = 2,
    CATCVMWBOpDiv = 3
};

struct CATCVMWBLeaf
{
    double _Value;
    int _HandleIndex;
    CATCVMWBLeaf()
    {
        _HandleIndex = 0;
    }
    ~CATCVMWBLeaf()
    {
    }
};

class ExportedByCATCVMGeoObjects CATCVMWBEquationTreeNode
{
  public:
  CATCVMWBEquationTreeNode();
  CATCGMNewClassArrayDeclare; // Pool allocation
  virtual ~CATCVMWBEquationTreeNode();

  void SetLeaf(CATCVMWBLeaf * iLeaf);
  void SetChildren(CATCVMWBOp & iOp, CATCVMWBEquationTreeNode * iChild[2]);

  CATCVMWBLeaf * GetLeaf();
  void GetChildren(CATCVMWBOp & oOp, CATCVMWBEquationTreeNode * oChild[2]);

  double Eval();
  double EvalPartialDer(CATCVMWBLeaf * iLeaf);

private:
    CATCVMWBLeaf * _Leaf;
    CATCVMWBOp _Op;
    CATCVMWBEquationTreeNode * _Child[2];
};
#endif
