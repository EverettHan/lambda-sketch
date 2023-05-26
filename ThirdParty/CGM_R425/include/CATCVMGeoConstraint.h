/* -*-C++-*- */

#ifndef CATCVMGeoConstraint_H
#define CATCVMGeoConstraint_H

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
#include "CATCVMGeoObjects.h"
#include "CATCVMConstraint.h"
#include "CATCVMDef.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"
#include "CATCGMNewArray.h"


class CATCVMComponent;
class CATCVMDouble;
class CATCVMGeometry;
class CATGeometry;
class CATBody;
//class CATVirtualInfraConstraint;
//class CATVirtualInfraTool;
class CATCell;
class CATCVMCopy;

class ExportedByCATCVMGeoObjects CATCVMGeoConstraint : public CATCVMConstraint
{
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoConstraint(CATCVMContainer *iContainer);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMGeoConstraint();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean IsA(CATCVMObjectType iObjectType);

  //------------------------------------------------------------------------------
  // Get real value
  //------------------------------------------------------------------------------
  public:
  CATCVMDouble *GetValue();

  //------------------------------------------------------------------------------
  // Get geometry
  //------------------------------------------------------------------------------
  public:
  CATCVMGeometry *GetGeometry(int iIndex);

  //------------------------------------------------------------------------------
  // Get geometries
  //------------------------------------------------------------------------------
  public:
  void GetGeometries(ListPOfCATCVMGeometry &oGeometryList);

  //------------------------------------------------------------------------------
  // Get real distance value
  //------------------------------------------------------------------------------
  public:
  double GetRealValue();

  //------------------------------------------------------------------------------
  // Get geometry
  //------------------------------------------------------------------------------
  public:
  CATGeometry *GetCGMGeometry(int iIndex);

  //------------------------------------------------------------------------------
  // Set geometry
  //------------------------------------------------------------------------------
  protected:
/*  void SetCGMGeometry(int          iIndex,
                      CATGeometry *iGeometry,
                      CATBody     *iBody);*/

  //------------------------------------------------------------------------------
  // Set real value
  //------------------------------------------------------------------------------
  protected:
  void SetRealValue(double iRealDistanceValue);
/*
  //------------------------------------------------------------------------------
  // Update from infrastructure constraint
  //------------------------------------------------------------------------------
  public:
  CATBoolean UpdateFromInfra(CATVirtualInfraTool *iInfraTool);

  //------------------------------------------------------------------------------
  // Set infrastructure constraint
  //------------------------------------------------------------------------------
  public:
  void SetInfraConstraint(CATVirtualInfraConstraint *iInfraConstraint);

  //------------------------------------------------------------------------------
  // Get infrastructure constraint
  //------------------------------------------------------------------------------
  public:
  CATVirtualInfraConstraint *GetInfraConstraint();

  //------------------------------------------------------------------------------
  // Update the infrastructure constraint from local data
  //------------------------------------------------------------------------------
  public:
  void UpdateInfraConstraint(CATVirtualInfraTool *iInfraTool);

  //------------------------------------------------------------------------------
  // Create the infrastructure constraint from local data
  //------------------------------------------------------------------------------
  public:
  void CreateInfraConstraint(CATVirtualInfraTool *iInfraTool,
                             CATBoolean           iSetRealValue);

  //------------------------------------------------------------------------------
  // Create
  //------------------------------------------------------------------------------
  private:
  virtual void CreateSpecificInfraConstraint(CATVirtualInfraTool        *iInfraTool,
                                             CATVirtualInfraConstraint *&oInfraConstraint,
                                             CATBoolean                  iSetRealValue);
*/
  //------------------------------------------------------------------------------
  // Get the CGM cell and body for a given index
  //------------------------------------------------------------------------------
/*  protected:
  void GetCGMCellAndBody(int       iIndex,
                         CATCell *&oCGMCell,
                         CATBody *&oCGMBody);*/

  //------------------------------------------------------------------------------
  // Get the number of geometric handles
  //------------------------------------------------------------------------------
//  public:
//  int GetNbGeometricHandles();
//  virtual CATBoolean HasRealValue();
  public:
//  virtual void UpdateInfraConstraintValue();

  //------------------------------------------------------------------------------
  // CleanUp
  //------------------------------------------------------------------------------
  public:
  virtual void CleanUp(CATBoolean iCompleteRemoval = FALSE);

  //------------------------------------------------------------------------------
  // Destroy infrastructure constraint
  //------------------------------------------------------------------------------
  private:
//  void DestroyInfraConstraint();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
//  CATVirtualInfraConstraint *_InfraConstraint;

private:
CATCVMGeoConstraint(const CATCVMGeoConstraint &);//Necessary to prevent unwanted automatic creation by compiler
void operator = (const CATCVMGeoConstraint &);

};
#endif
