/* -*-C++-*- */
#ifndef CATPrBRepFace_H
#define CATPrBRepFace_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrBRepFace: BRep piece from a Face, dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// Feb 2012    Creation                         R. Rorato
//===================================================================

#include "CATPrBRep.h"
#include "ListPOfCATFace.h"
#include "CATCGMNewArray.h"
#include "AdvOpeInfra.h"
class CATGeoFactory;
class CATSoftwareConfiguration;

class ExportedByAdvOpeInfra CATPrBRepFace : public CATPrBRep
{
  public:
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATPrBRepFace(CATPrContext& iContext, CATFace* iFace, const int iOrn);
  CATPrBRepFace(CATPrContext& iContext, ListPOfCATFace& iFaces, CATListOfInt& iOrns);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrBRepFace();

  //----------------------------------------------------------------------------
  // Utility
  //----------------------------------------------------------------------------
  static CATBoolean AreIsometric(CATPrContext& iContext, CATFace& iFace1, CATFace& iFace2, const CATTrd::SimilarityType iSimilarityType, const CATBoolean iLocalMode, CATMathTransformation& oTransfo);

  //------------------------------------------------------------------------------
  // Forbidden
  //------------------------------------------------------------------------------
  CATPrBRepFace(CATPrBRepFace& iRep);
  CATPrBRepFace& operator= (const CATPrBRepFace& iRep);

  //------------------------------------------------------------------------------
  // Returns Geometric Representation
  //------------------------------------------------------------------------------
  void GetOwnedCells(CATLISTP(CATCell) &oCells, CATListOfInt* oOrns = NULL);

  //------------------------------------------------------------------------------
  // Safe cast management
  //------------------------------------------------------------------------------
  CATPrBRepFace* GetAsPrBRepFace();

  //------------------------------------------------------------------------------
  // Dump internal data
  //------------------------------------------------------------------------------
  void Dump(CATCGMOutput& ioOS);

  //------------------------------------------------------------------------------
  // Returns Geometric Representation
  //------------------------------------------------------------------------------
  //void GetFaces(CATLISTP(CATFace) &oFaces);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private :

  // Spec
  ListPOfCATFace         _Faces;
  CATListOfInt           _Orns;
};

//------------------------------------------------------------------------------

#endif
