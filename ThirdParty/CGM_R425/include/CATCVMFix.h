/* -*-C++-*- */

#ifndef CATCVMFix_H
#define CATCVMFix_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) fix constraints
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

class ExportedByCATCVMGeoObjects CATCVMFix : public CATCVMGeoConstraint
{
/*  //------------------------------------------------------------------------------
  // DEPRECATED -- DO NOT USE -- USE Create() and then CATCVMRelationManager
  //------------------------------------------------------------------------------
  public:
  static CATCVMFix *Create(CATCVMGeometry *iGeometry1);

  //------------------------------------------------------------------------------
  // DEPRECATED -- DO NOT USE -- USE Create() and then CATCVMRelationManager
  //------------------------------------------------------------------------------
  public:
  static CATCVMFix *Create(CATCVMComponent *iComponent);

*/
  public:
  static CATCVMFix *Create(CATCVMContainer *iContainer);

  protected:
  CATCVMFix(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMFix();

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
   *1 CVMGeometry with role 0 
   */
  CATBoolean HasCorrectHandles();  
  CATBoolean IsValidArgument(CATCVMHandle * iHandle, int iRole);

  public:
  CATBoolean IsSatisfied();

  public:
  /**
   *Always return 0.
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
/*
  //------------------------------------------------------------------------------
  // Create fix infrastructure constraint
  //------------------------------------------------------------------------------
  private:
  void CreateSpecificInfraConstraint(CATVirtualInfraTool        *iInfraTool,
                                     CATVirtualInfraConstraint *&oInfraConstraint, 
                                     CATBoolean                  iSetRealValue);*/
private:
CATCVMFix(const CATCVMFix &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMFix &);

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
