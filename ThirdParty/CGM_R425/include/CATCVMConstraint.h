/* -*-C++-*- */

#ifndef CATCVMConstraint_H
#define CATCVMConstraint_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) constraints
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
#include "CATCVMRelation.h"
#include "CATCVMDef.h"
#include "CATUnicodeString.h"
#include "CATCGMNewArray.h"

class CATCVMComponent;

class ExportedByCATCVMGeoObjects CATCVMConstraint : public CATCVMRelation
{
  // Ajout PFS pour delaration du composant
	CATDeclareClass;
 
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMConstraint(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare;
  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMConstraint();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean IsA(CATCVMObjectType iObjectType);

  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  public:
  /**
   *Return 1 if this is satisfied;
   *else return 0;
   */ 
  virtual CATBoolean IsSatisfied() = 0;

  /**
   *Return the discrepancy of this, ie the gap by which this is not satisfied.
   *This is satisfied if (|discrepancy| < tolerance), where tolerance is defined by the constraint solver.
   *Example: for a coincidence constraint between 2 points, return the distance between the 2 points.
   *The exact meaning must be defined in each leaf class.
   */ 
//  virtual double GetDiscrepancy() = 0;


private:
CATCVMConstraint(const CATCVMConstraint &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMConstraint &);

};
#endif
