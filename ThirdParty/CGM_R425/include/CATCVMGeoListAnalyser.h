/* -*-C++-*- */

#ifndef CATCVMGeoListAnalyser_H
#define CATCVMGeoListAnalyser_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMGeoListAnalyser
//
// class for Collaborative Variational Modelling (CVM) List analysis operator
//
// Operator made to determine which bodies are defined by a list of geometries
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Mar. 2007    Creation                         ASE
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMSysOperator.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMObject.h"
#include "ListPOfCATCVMGeometry.h"
#include "ListPOfCATCVMBody.h"
#include "CATListOfInt.h"

class CATCVMGeoContainer;
class CATBody;
class CATCell;
class CATCVMBody;

class ExportedByCATCVMGeoOperators CATCVMGeoListAnalyser : public CATCVMSysOperator
{
  //------------------------------------------------------------------------------
  // Create a list analysis operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoListAnalyser *Create(CATCVMGeoContainer *iCVMGeoContainer);

  //------------------------------------------------------------------------------
  // Constructor, copy constructor and = operator
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoListAnalyser(CATCVMGeoContainer *iCVMGeoContainer);
  private:
  CATCVMGeoListAnalyser();
  CATCVMGeoListAnalyser(const CATCVMGeoListAnalyser &);//Necessary to prevent unwanted automatic creation by compiler
  void operator = (const CATCVMGeoListAnalyser &);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMGeoListAnalyser();

  //------------------------------------------------------------------------------
  // Method that provide input list of objects to the operator
  //------------------------------------------------------------------------------
  public:
  void SetObjects(ListPOfCATCVMObject &iObjectList);

  //------------------------------------------------------------------------------
  // Run method of the operator
  //------------------------------------------------------------------------------
  public:
  void Run();

  //------------------------------------------------------------------------------
  // Get the determined bodies
  //------------------------------------------------------------------------------
  public:
  void GetBodies(ListPOfCATCVMBody &oBodyList);

  //------------------------------------------------------------------------------
  // Get the sublist of CVM geometries that belong to a body (defined by the
  // index in the list of determined bodies)
  //------------------------------------------------------------------------------
  public:
  void GetGeometriesOfBody(int                    iIndex,
                           ListPOfCATCVMGeometry &oBodyGeometryList);

  //------------------------------------------------------------------------------
  // Find out if all the geometries of a body were provided
  //------------------------------------------------------------------------------
  public:
  CATBoolean AreAllGeometriesOfBodyInList(int iIndex);

  //------------------------------------------------------------------------------
  // Get the number of identified bodies
  //------------------------------------------------------------------------------
  public:
  int GetNumberOfBodies();

  //------------------------------------------------------------------------------
  // Get a body
  //------------------------------------------------------------------------------
  public:
  CATCVMBody *GetBody(int iIndex);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  ListPOfCATCVMBody      _BodyInputList;
  ListPOfCATCVMGeometry  _GeometryList;
  ListPOfCATCVMBody      _BodyList;
  ListPOfCATCVMGeometry *_GeometryListPerBody;
};
#endif
