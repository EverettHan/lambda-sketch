/* -*-C++-*- */

#ifndef CATCVMGeoDelete_H
#define CATCVMGeoDelete_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoDelete
//
// class for Collaborative Variational Modelling (CVM) geometric delete operator
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Mar. 2006    Creation                         Alex State
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "ListPOfCATCVMBody.h"

class CATBody;
class CATCVMGeometry;
class CATCVMGeoContainer;
class CATTopData;
class CATCVMLog;
class CATCVMReference;
class CATCVMInstance;
class CATCVMInstancePath;
class CATCVMGeoRep;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoDelete : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a delete operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoDelete *Create(CATCVMGeoContainer *iCVMGeoContainer,
                                 CATTopData         *iTopData);
  static CATCVMGeoDelete *Create(CATCVMInstancePath *iCVMInstancePath,
                                 CATTopData         *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoDelete(CATCVMGeoContainer *iCVMGeoContainer,
                  CATTopData         *iTopData,
                  CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoDelete(CATTopData         *iTopData,
                  CATCVMGeoOperatorExt *iExtensible);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMGeoDelete();

  //------------------------------------------------------------------------------
  // Set EraseOnlySelectedCells
  //------------------------------------------------------------------------------
  public:
  virtual void SetEraseOnlySelectedCells(CATBoolean iEraseOnlySelectedCells);

  //------------------------------------------------------------------------------
  // Add an InstancePath to delete
  //------------------------------------------------------------------------------
  void AddInstancePath(CATCVMInstancePath *iInstancePath);

  //------------------------------------------------------------------------------
  // Add a body to delete
  //------------------------------------------------------------------------------
  public:
  virtual void AddBody(CATCVMBody *iBody);

  //------------------------------------------------------------------------------
  // Add a cell to delete
  //------------------------------------------------------------------------------
  public:
  virtual void AddCell(CATCVMGeometry *iCell);

  //------------------------------------------------------------------------------
  // Delete the CVM body that contains a given CGM body
  //------------------------------------------------------------------------------
  public:
  static void DeleteCVMBody(CATCVMGeoContainer *iCVMGeoContainer,
                            CATBody            *iCGMBody,
                            CATCVMLog          *iCVMLog = NULL);

  //------------------------------------------------------------------------------
  // CGM Internal Use
  //------------------------------------------------------------------------------
  private:
  //virtual int RunOperator();

  public:
  static const CATString *GetDefaultOperatorId();

  //------------------------------------------------------------------------------
  // Add a reference to delete
  //------------------------------------------------------------------------------
  public:
  void AddReference(CATCVMReference *iReference);

  //------------------------------------------------------------------------------
  // Add an instance to delete
  //------------------------------------------------------------------------------
 // private:
  public:
  HRESULT AddInstance(CATCVMInstance *iInstance);

  //------------------------------------------------------------------------------
  // Add a GeoRep to delete
  //------------------------------------------------------------------------------
  public:
  void AddGeoRep(CATCVMGeoRep *iGeoRep);
};
#endif
