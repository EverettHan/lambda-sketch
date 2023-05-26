/* -*-C++-*- */

#ifndef CATCVMDistance_H
#define CATCVMDistance_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) distance constraints
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
#include "CATCVMGeoDimConstraint.h"
#include "CATCVMDef.h"
#include "CATCGMNewArray.h"

class CATCVMComponent;
class CATCVMCopy;

class ExportedByCATCVMGeoObjects CATCVMDistance : public CATCVMGeoDimConstraint
{
/*  //------------------------------------------------------------------------------
  // CreateConstraint
  //------------------------------------------------------------------------------
  public:
  static CATCVMDistance *Create(CATCVMGeometry *iGeometry1,
                                CATCVMGeometry *iGeometry2,
                                CATCVMDouble   *iDistance);

  //------------------------------------------------------------------------------
  // CreateConstraint
  //------------------------------------------------------------------------------
  public:
  static CATCVMDistance *Create(CATCVMGeometry *iGeometry1,
                                CATCVMGeometry *iGeometry2,
                                double          iDistanceValue);

*/
  public:
  static CATCVMDistance *Create(CATCVMContainer *iContainer);

  protected:
  CATCVMDistance(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMDistance();

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
   *1 CVMDouble with role 1
   */
  CATBoolean HasCorrectHandles();  
  CATBoolean IsValidArgument(CATCVMHandle * iHandle, int iRole);

  public:
  virtual CATBoolean IsSatisfied();

  public:
  /**
   *Discrepancy for this: (actual distance - expected distance)
   *May be positive or negative
   *TODO: define discrepancy in the case where distance is meaningless (example: 2 non-parallel planes)
   */
///  virtual double GetDiscrepancy();

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
  public:
  void UpdateInfraConstraintValue();
//  CATBoolean HasRealValue();


  //------------------------------------------------------------------------------
  // Create distance infrastructure constraint
  //------------------------------------------------------------------------------
  private:
  void CreateSpecificInfraConstraint(CATVirtualInfraTool        *iInfraTool,
                                     CATVirtualInfraConstraint *&oInfraConstraint,
                                     CATBoolean                  iSetRealValue);*/
private:
CATCVMDistance(const CATCVMDistance &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMDistance &);
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
