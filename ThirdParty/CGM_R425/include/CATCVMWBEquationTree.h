/* -*-C++-*- */

#ifndef CATCVMWBEquationTree_H
#define CATCVMWBEquationTree_H

// COPYRIGHT DASSAULT SYSTEMES 2006
#include"CATCVMGeoObjects.h"
#include "CATListPV.h"
#include "CATCGMNewArray.h"

class CATCVMWBEquationTreeNode;
struct CATCVMWBLeaf;

class ExportedByCATCVMGeoObjects CATCVMWBEquationTree
{
public:

CATCVMWBEquationTree();
CATCGMNewClassArrayDeclare; 
virtual ~CATCVMWBEquationTree();

void SetRootNode(CATCVMWBEquationTreeNode * iRootNode);
CATCVMWBEquationTreeNode * GetRootNode();
double Eval();
void EvalGradient(double *oaDX);
void SetLeafValues(double * iaX);
int GetNbLeaf();

private:

void RetrieveVariableLeaf(CATCVMWBEquationTreeNode * iNode);

CATListPV _Leaf;
CATCVMWBEquationTreeNode * _RootNode;
};
#endif
