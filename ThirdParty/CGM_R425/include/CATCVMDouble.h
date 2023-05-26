/* -*-C++-*- */

#ifndef CATCVMDouble_H
#define CATCVMDouble_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) doubles
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
#include "CATCVMVariable.h"
#include "CATCVMDef.h"
#include "CATCGMNewArray.h"

class CATCVMSystem;
class CATUnicodeString;
class CATCVMCopy;

class ExportedByCATCVMGeoObjects CATCVMDouble : public CATCVMVariable
{
  //------------------------------------------------------------------------------
  // CreateDouble
  //------------------------------------------------------------------------------
  public:
  static CATCVMDouble *Create(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  protected:
  CATCVMDouble(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMDouble();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);
  CATCVMObjectType GetType();

  //------------------------------------------------------------------------------
  // Get value
  //------------------------------------------------------------------------------
  public:
  double GetValue();

  //------------------------------------------------------------------------------
  // Set value
  //------------------------------------------------------------------------------
  public:
  void SetValue(double iValue);

  //------------------------------------------------------------------------------
  // Create a copy
  //------------------------------------------------------------------------------
  public:
  CATCVMDouble *CreateCopy(CATCVMCopy   *iCopy);

  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  double _Value;
  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  virtual void    Stream   (CATCVMSysStream* CVMStr);
  virtual void    GetLinkedGeometry (CATCVMSysStream* CVMStr); 
  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
  virtual CATBoolean Compare (CATCVMObject *iRef);
};
#endif
