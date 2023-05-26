/* -*-C++-*- */
#ifndef CATPrBRepCM_H
#define CATPrBRepCM_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrBRepCM: BRep piece from CellManifolds (connected set), dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// June 2011    Creation                         R. Rorato
//===================================================================

#include "CATPrBRep.h"
#include "ListPOfCATCellManifold.h"
#include "CATCGMNewArray.h"
#include "AdvOpeInfra.h"

class ExportedByAdvOpeInfra CATPrBRepCM : public CATPrBRep
{
  public:
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATPrBRepCM(CATPrContext& iContext, CATCellManifold* iCM);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrBRepCM();

  //------------------------------------------------------------------------------
  // Forbidden
  //------------------------------------------------------------------------------
  CATPrBRepCM(CATPrBRepCM& iRep);
  CATPrBRepCM& operator= (const CATPrBRepCM& iRep);

  //------------------------------------------------------------------------------
  // Returns Geometric Representation
  //------------------------------------------------------------------------------
  void GetOwnedCells(CATLISTP(CATCell) &oCells, CATListOfInt* oOrns = NULL);

  //------------------------------------------------------------------------------
  // Safe cast management
  //------------------------------------------------------------------------------
  CATPrBRepCM* GetAsPrBRepCM();

  //------------------------------------------------------------------------------
  // Dump internal data
  //------------------------------------------------------------------------------
  void Dump(CATCGMOutput& ioOS);

  //------------------------------------------------------------------------------
  // Returns Geometric Representation
  //------------------------------------------------------------------------------
  //void GetFaces(CATLISTP(CATFace) &oFaces);
  void GetCellManifolds(CATLISTP(CATCellManifold) &oCellManifolds, CATULONG32* iThisStampOnly = NULL); 

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private :

  // Spec
  ListPOfCATCellManifold _CM; 

};

//------------------------------------------------------------------------------

#endif
