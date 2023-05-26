/* -*-C++-*- */

#ifndef CATCVMGeoDimConstraint_H
#define CATCVMGeoDimConstraint_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) geo constraints
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Mar. 2006    Creation                         Alex State
//===================================================================
#include "CATCVMGeoConstraint.h"
#include "CATCGMNewArray.h"

class ExportedByCATCVMGeoObjects CATCVMGeoDimConstraint : public CATCVMGeoConstraint
{
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoDimConstraint(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMGeoDimConstraint();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean IsA(CATCVMObjectType iObjectType);

  virtual void SetValue(double iValue);

private:
CATCVMGeoDimConstraint(const CATCVMGeoDimConstraint &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMGeoDimConstraint &);

};
#endif
