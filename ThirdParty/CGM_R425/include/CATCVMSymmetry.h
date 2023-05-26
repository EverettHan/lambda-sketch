/* -*-C++-*- */

#ifndef CATCVMSymmetry_H
#define CATCVMSymmetry_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) symmetry constraints
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
#include "CATCVMGeoConstraint.h"
#include "CATCVMDef.h"
#include "CATCGMNewArray.h"

class CATCVMComponent;
class CATCVMCopy;

class ExportedByCATCVMGeoObjects CATCVMSymmetry : public CATCVMGeoConstraint
{
  public:
  static CATCVMSymmetry *Create(CATCVMContainer *iContainer);

  protected:
  CATCVMSymmetry(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMSymmetry();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);
  public:
  CATCVMObjectType GetType();

  public:
  /**
   *Right handles for this:
   *1 CVMGeometry with role 0 (the middle geometry)
   *2 CVMGeometry with role 1 (that are the symmetric geometries)
   */
  CATBoolean HasCorrectHandles();  
  CATBoolean IsValidArgument(CATCVMHandle * iHandle, int iRole);

  public:
  virtual CATBoolean IsSatisfied();

  public:
  /**
   *Discrepancy for this: distance between one element and the symmetric of the other
   */
//  virtual double GetDiscrepancy();

  //------------------------------------------------------------------------------
  // Update from constraint feature
  //------------------------------------------------------------------------------
  public:
//  void UpdateFromConstraintFeature();

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
/*
  //------------------------------------------------------------------------------
  // Create symmetry infrastructure constraint
  //------------------------------------------------------------------------------
  private:
  void CreateSpecificInfraConstraint(CATVirtualInfraTool        *iInfraTool,
                                     CATVirtualInfraConstraint *&oInfraConstraint, 
                                     CATBoolean                  iSetRealValue);*/

private:
CATCVMSymmetry(const CATCVMSymmetry &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMSymmetry &);

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
