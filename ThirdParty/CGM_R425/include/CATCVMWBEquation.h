/* -*-C++-*- */

#ifndef CATCVMWBEquation_H
#define CATCVMWBEquation_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) white
// box (WB) equations
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Mar. 2006    Creation                         Alex State
//===================================================================
#include "CATCVMGeoObjects.h"
#include "CATCVMEquation.h"
#include "CATCVMDef.h"
#include "ListPOfCATCVMHandle.h"
#include "CATListOfInt.h"
#include "CATCGMNewArray.h"

class CATCVMComponent;
class CATCVMWBEquationTree;
struct CATCVMWBLeaf;
class CATCVMCopy;

class ExportedByCATCVMGeoObjects CATCVMWBEquation : public CATCVMEquation
{
  public:
  static CATCVMWBEquation *Create(CATCVMContainer *iContainer);

  protected:
  CATCVMWBEquation(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare; 
  protected:
  virtual ~CATCVMWBEquation();

  public:
  virtual CATBoolean IsA(CATCVMObjectType iObjectType);
  public:
  CATCVMObjectType GetType();

  public:
  /**
   *Right handles for this:
   *N handles as defined in the CATCVMWBEquationTreeNode with roles in [0 .. N-1]
   */
  CATBoolean HasCorrectHandles();  
  CATBoolean IsValidArgument(CATCVMHandle * iHandle, int iRole);

  public:
  CATBoolean IsSatisfied();

  public:
  /**
   *Discrepancy for this: result of the method Eval with the actual values of the handles
   */
//  double GetDiscrepancy();

  public:
  virtual double Eval(double * iaX);

  public:
  virtual void EvalGradient(double * iaX, double *oaDX);

  //------------------------------------------------------------------------------
  // Create a copy (the pointed handles must already be duplicated)
  //------------------------------------------------------------------------------
  public:
  CATCVMRelation *CreateCopy(CATCVMCopy      *iCopy);

  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  void SetTree(CATCVMWBEquationTree * iTree);
  CATCVMWBEquationTree * GetTree();

private:
    CATCVMWBEquationTree * _Tree;

    void SetLeafValues(double * iaX);

private:
CATCVMWBEquation(const CATCVMWBEquation &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMWBEquation &);

  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  virtual void    Stream (CATCVMSysStream* CVMStr);
  virtual void    GetLinkedGeometry (CATCVMSysStream* iCVMStr);
  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
  virtual CATBoolean Compare (CATCVMObject *iRef);

};
#endif
