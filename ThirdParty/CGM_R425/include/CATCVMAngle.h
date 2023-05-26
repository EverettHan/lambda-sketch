/* -*-C++-*- */

#ifndef CATCVMAngle_H
#define CATCVMAngle_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) angle constraints
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
class CATCVMDouble;
class CATCVMCopy;

class ExportedByCATCVMGeoObjects CATCVMAngle : public CATCVMGeoDimConstraint
{
  //------------------------------------------------------------------------------
  // CreateConstraint
  //------------------------------------------------------------------------------
/*  public:
  static CATCVMAngle *Create(CATCVMGeometry *iGeometry1,
                             CATCVMGeometry *iGeometry2,
                             CATCVMDouble   *iAngle);

  //------------------------------------------------------------------------------
  // CreateConstraint
  //------------------------------------------------------------------------------
  public:
  static CATCVMAngle *Create(CATCVMGeometry *iGeometry1,
                             CATCVMGeometry *iGeometry2,
                             double          iAngleValue);
*/
  public:
  static CATCVMAngle *Create(CATCVMContainer *iContainer);

  protected:
  CATCVMAngle(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMAngle();

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
  CATBoolean IsSatisfied();

  public:
  /**
   *Discrepancy for this: (actual angle - expected angle)
   *May be positive or negative
   */
//  double GetDiscrepancy();

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

  public:
/*  void UpdateInfraConstraintValue();
//  CATBoolean HasRealValue();
  //------------------------------------------------------------------------------
  // Create angle infrastructure constraint
  //------------------------------------------------------------------------------
  private:
  void CreateSpecificInfraConstraint(CATVirtualInfraTool        *iInfraTool,
                                     CATVirtualInfraConstraint *&oInfraConstraint, 
                                     CATBoolean                  iSetRealValue);*/
private:
CATCVMAngle(const CATCVMAngle &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMAngle &);

//------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  virtual void    Stream (CATCVMSysStream*  Str);
  virtual void    GetLinkedGeometry (CATCVMSysStream* CVMStr); 

  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
  virtual CATBoolean Compare (CATCVMObject *iRef);

};
#endif
