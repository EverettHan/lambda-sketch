// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : RR
//
// DESCRIPTION  : Select Faces according to WallFacesSelector
//
//=============================================================================
// Creation RR September 2012
//=============================================================================
#ifndef CATWallFacesSelector_H
#define CATWallFacesSelector_H


#include "AdvOpeInfra.h"
#include "CATMathBox.h"
#include "CATBoolean.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "ListPOfCATPrRep.h"
#include "CATLISTP_CATMathTransformation.h"
#include "CATPrContext.h"
#include "CATCGMNewArray.h"
#include "CATErrorDef.h"

class CATSoftwareConfiguration;
class CATBody;
class CATLiveBody;
class CATFace;
class CATCellManifoldOffsetNavigator;
class CATWallFacesSelector;
class CATCellHashTable;
class CATFaceHashTable;

//----------------------------------------------------------------------------
// Public section
//----------------------------------------------------------------------------
ExportedByAdvOpeInfra CATWallFacesSelector* CATCreateWallFacesSelector(CATSoftwareConfiguration & iConfig,
                                                                       CATBody                  & iBody,
                                                                       const ListPOfCATFace     & iFaceList);

ExportedByAdvOpeInfra CATWallFacesSelector* CATCreateWallFacesSelector(CATSoftwareConfiguration & iConfig,
                                                                       CATBody                  & iBody,
                                                                       const CATFaceHashTable   & iFaceHT);


class ExportedByAdvOpeInfra CATWallFacesSelector 
{
public:

  // constructor 1
  CATWallFacesSelector(CATSoftwareConfiguration &iConfig, CATBody &iBody, const ListPOfCATFace &iFaces);
  // constructor 2 - with hashtable
  CATWallFacesSelector(CATSoftwareConfiguration &iConfig, CATBody &iBody, const CATFaceHashTable &iFaceHT);

  // Destructor
  ~CATWallFacesSelector(); 

  HRESULT SetMaxThickness(const double iMaxThickness);

  HRESULT SetLiveBody(CATLiveBody* iLiveBody);

  enum Constraint { Parallel=0, Mirror, LocalMirror };
  HRESULT SetConstraint(const Constraint iConstraint); // Default is Parallel

  void Run();

  void GetFacesOnOtherWallSide(ListPOfCATFace& oFaces);

  HRESULT GetSymmetry(CATMathTransformation& oSymmetry); // Only if Constraint is Symmetry

  CATFace* GetFaceOnOtherWallSide(CATFace* iFace); // iFace must be one of the iFaces Faces, return NULL if no wall found. Warning: if SetLiveBody is used, mapping between input & output face is not guaranted inside a CellManifold 

  //----------------------------------------------------------------------------
  // Private section (do not use)
  //----------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare; // Pool allocation

private:
  CATWallFacesSelector(const CATWallFacesSelector& iWallFacesSelectorToCopy);
  CATWallFacesSelector & operator=(const CATWallFacesSelector& iWallFacesSelectorToCopy);

  void RunOnDRepOffset();
  void RunOnGeometry();
  void SetOutputFace(const int iIndex, CATFace* iFace = NULL, const double iDistance = 0., CATMathTransformation* iSymmetry = NULL);
  int GetFaceToTestFirst();
  void UpdateWalledFacesBorderEdges(const int iIndex, CATFace& iFace);
  CATBoolean IsAdjacentToWalledFaces(const int iIndex, CATFace& iFace);
  void SearchForAWall(CATFace* iFace, double& ioDistance, CATMathTransformationList& oSymmetries, CATListOfInt& oFound);
  CATBoolean FilterOut(CATFace& iFace1, CATFace& iFace2);
  static int Compare2Faces(CATFace* iFace1, CATFace* iFace2);
  CATBoolean AreMirrored(CATFace& iFace1, CATFace& iFace2, CATMathTransformation& oSymmetry, double& oDistance);
  CATFace* FindMirroredFace(CATFace* iFace, const CATMathTransformation& iSymmetry); 
  CATPrRep& Rep(CATFace& iFace);
  void SelectBestWall();
  void SelectBestSymmetry();

  // Input Data
  CATSoftwareConfiguration&              _Config;
  CATBody&                               _Body;
  CATLiveBody*                           _LiveBody;
  Constraint                             _Constraint;
  double                                 _MaxThickness;
  ListPOfCATFace                         _InputFace;

  // Computed Data
  CATListOfInt                           _InputFaceDone; // Synchronized with _InputFace
  ListPOfCATFace                         _OutputFace;    // Synchronized with _InputFace
  CATListOfDouble                        _Distance;      // Synchronized with _InputFace
  CATMathTransformationList              _Symmetry;      // Synchronized with _InputFace

  ListPOfCATFace                         _FaceToSearchIn;
  ListPOfCATPrRep                        _Reps;
  CATPrContext                           _PrContext;
  CATBoolean                             _Run;
  double                                 _Tolerance;
  int                                    _RepAttrKey;

  // GetFaceToTestFirst buffer
  CATMathBox                             _WalledFacesBoxes[2];
  CATCellHashTable*                      _WalledFacesBorderEdges[2]; 
};

//----------------------------------------------------------------------------

#endif
