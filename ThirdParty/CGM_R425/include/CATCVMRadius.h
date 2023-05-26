/* -*-C++-*- */

#ifndef CATCVMRadius_H
#define CATCVMRadius_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) 
// Radius Constraint on a circle or cylinder
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

class ExportedByCATCVMGeoObjects CATCVMRadius : public CATCVMGeoDimConstraint
{
  public:
  static CATCVMRadius *Create(CATCVMContainer *iContainer);

  protected:
  CATCVMRadius(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMRadius();

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
   *1 CVMGeometry with Role 0 
   *1 CVMDouble with Role 1
   */
  CATBoolean HasCorrectHandles();  
  CATBoolean IsValidArgument(CATCVMHandle * iHandle, int iRole);

  public:
  CATBoolean IsSatisfied();

  public:
  /**
   *Discrepancy for this: (actual radius - expected radius)
   *May be positive or negative
   */
//  double GetDiscrepancy();

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

private:
CATCVMRadius(const CATCVMRadius &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMRadius &);

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
