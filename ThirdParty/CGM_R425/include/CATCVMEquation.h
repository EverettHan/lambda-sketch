/* -*-C++-*- */

#ifndef CATCVMEquation_H
#define CATCVMEquation_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMEquation
//
// class for equations between CATCVMDouble
//
// 1) Mathematical expression
// The equation is defined by :
//         F(X0, X1, ..., Xn-1)=0
// with    F: Rn -> R
// The evaluations of F can be obtained with the methods Eval() and EvalDeriv() 
//
// 2) Signification of handles and variables
// This can have M handles (retrieved with GetNbHandles())
// If some of these handles are equal (same object), then the number of independent variables is N < M
// The values X0, X1, ..., Xn-1 used above correspond to the values of the N variables.
// To update the list of the variables, the method UpdateVariables() must be called
// after the handles are defined
// 
//===================================================================
//===================================================================
// Mar. 2006    Creation                         Alex State
//===================================================================
#include "CATCVMGeoObjects.h"
#include "CATCVMConstraint.h"
#include "CATCVMDef.h"
#include "CATCGMNewArray.h"

class CATCVMComponent;

class ExportedByCATCVMGeoObjects CATCVMEquation : public CATCVMConstraint
{
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMEquation(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMEquation();

public:
  /**
   *Return F(X0, X1, ..., Xn-1)
   *If (iaX == Null) uses the actual values of the handles (as CVMDouble) for the Xi
   *else uses the values in iaX
   */
  virtual double Eval(double * iaX) = 0;

  /**
   *Output:  oaDX[i] = dF(X0, X1, ..., Xn-1)/dXi
   *If (iaX == Null) uses the actual values of the handles (as CVMDouble) for the Xi
   *else uses the values in iaX
   */
  virtual void EvalGradient(double * iaX, double *oaDX) = 0;

  virtual int GetNbVariables();
  virtual CATCVMHandle * GetVariable(int iIndex);
  virtual int GetVariableIndex(int iHandleIndex);
  virtual void UpdateVariables();



  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean IsA(CATCVMObjectType iObjectType);

protected:
    ListPOfCATCVMHandle  _VariableList;
    CATListOfInt _HandleVariableMatch;


private:
CATCVMEquation(const CATCVMEquation &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMEquation &);

};
#endif
