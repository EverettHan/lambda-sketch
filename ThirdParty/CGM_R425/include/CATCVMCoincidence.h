/* -*-C++-*- */

#ifndef CATCVMCoincidence_H
#define CATCVMCoincidence_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) coincidence constraints
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
class CATCVMDouble;
class CATCVMCopy;

class ExportedByCATCVMGeoObjects CATCVMCoincidence : public CATCVMGeoConstraint
{
/*  //------------------------------------------------------------------------------
  // CreateConstraint
  //------------------------------------------------------------------------------
  public:
  static CATCVMCoincidence *Create(CATCVMGeometry *iGeometry1,
                                   CATCVMGeometry *iGeometry2);
*/
  public:
  static CATCVMCoincidence *Create(CATCVMContainer *iContainer);

  protected:
  CATCVMCoincidence(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMCoincidence();

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
   *2 CVMGeometry with role 0
   */
  CATBoolean HasCorrectHandles();  
  CATBoolean IsValidArgument(CATCVMHandle * iHandle, int iRole);

  public:
  virtual CATBoolean IsSatisfied();

  public:
  /**
   *Discrepancy for this: distance between the 2 elements
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
  // Create coincidence infrastructure constraint
  //------------------------------------------------------------------------------
  private:
  void CreateSpecificInfraConstraint(CATVirtualInfraTool        *iInfraTool,
                                     CATVirtualInfraConstraint *&oInfraConstraint, 
                                     CATBoolean                  iSetRealValue);
*/
private:
CATCVMCoincidence(const CATCVMCoincidence &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMCoincidence &);

  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  virtual void    Stream   (CATCVMSysStream* CVMStr);
  virtual void    GetLinkedGeometry (CATCVMSysStream* iCVMStr);
  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
  virtual CATBoolean Compare (CATCVMObject *iRef);

};
#endif
