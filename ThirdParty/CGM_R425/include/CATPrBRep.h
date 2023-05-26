/* -*-C++-*- */
#ifndef CATPrBRep_H
#define CATPrBRep_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrBRep: BRep piece from CellManifolds (connected set), dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// June 2011    Creation                         R. Rorato
//===================================================================

#include "CATPrRep.h"
#include "ListPOfCATTrd.h"
#include "ListPOfCATPrBRep.h"
#include "CATTopDefine.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"
#include "CATListOfCATSurParams.h"
#include "CATEdge.h"
#include "CATToSort.h"
#include "CATCGMNewArray.h"
#include "CATMath.h"
#include "CATMathInline.h"
#include "AdvOpeInfra.h"
class CATTrdSet;
class CATTrdSSet;
class CATTrdDic;
class CATSurface;
class CATSurLimits;
class CATMathSetOfPoints;

class ExportedByAdvOpeInfra CATPrBRep : public CATPrRep
{
  public:
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATPrBRep(CATPrContext& iContext, const CATULONG32 iTag);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrBRep();
  //------------------------------------------------------------------------------

  //------------------------------------------------------------------------------
  // Forbidden
  //------------------------------------------------------------------------------
  CATPrBRep(CATPrBRep& iRep);
  CATPrBRep& operator= (const CATPrBRep& iRep);

  //------------------------------------------------------------------------------
  // Safe cast management
  //------------------------------------------------------------------------------
  CATPrBRep* GetAsPrBRep();

  //------------------------------------------------------------------------------
  // Debug
  //------------------------------------------------------------------------------
  void Dump(CATCGMOutput& ioOS);
  void GetObjectsToSave(CATLISTP(CATGeometry)& ioObjectsToSave);
  virtual void PutColor(const int iR, const int iG, const int iB);

  //------------------------------------------------------------------------------
  // this class put attributes on the Body. This method cleans them up
  //------------------------------------------------------------------------------
  static void ClearAttributes(CATBody& iBody);

  //------------------------------------------------------------------------------
  // Returns whether oTransfoFromThisToInputRep exists so that oTransfoFromThisToInputRep(this) == iTransfoOnRep(iRep) 
  //------------------------------------------------------------------------------
  virtual CATBoolean IsIsometric(const CATMathTransformation &iTransfoOnRep, CATTrdRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest, CATTrdChk* iChecker, const CATTrd::SimilarityType iSimilarityType, const CATBoolean iOnlyWithInvariant, CATLISTV(CATMathTransformation)& oTransfoFromThisToInputRep);
 
  //------------------------------------------------------------------------------
  // Returns whether iTransfo(iRep) == this 
  //------------------------------------------------------------------------------
  CATBoolean IsEqual(const CATMathTransformation& iTransfo, CATTrdRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest, CATTrdRep* ithisAdjRep = NULL, CATTrdRep* iAdjRep = NULL); 

  //------------------------------------------------------------------------------
  // Returns whether this & iRep are allowed to be adjacent instances of the same pattern
  //------------------------------------------------------------------------------
  virtual CATBoolean IsAllowedToBeInstanceAdjacentTo(CATPrRep& iRep); 

//------------------------------------------------------------------------------
  // returns whether this & iRep are adjacent in BRep 
  //------------------------------------------------------------------------------
  CATBoolean IsAdjacentTo(CATPrRep& iRep, const Convexity iConvexity = Any, const int iCommonCellsMinCount = 1, CATLISTP(CATCell)* oCommonCells = NULL);

  //------------------------------------------------------------------------------
  // Freeze/Unfreeze Border Edges
  //------------------------------------------------------------------------------
  void FreezeBoundary(const CATBoolean iFreeze);

  //------------------------------------------------------------------------------
  // Trihedrons
  //------------------------------------------------------------------------------
  INLINE CATTrdSet& TrdSet() { if ( NULL==_TrdSet ) _TrdSet = ComputeTrihedrons(); return *_TrdSet; }
  virtual ListPOfCATTrd& Trd();

  //------------------------------------------------------------------------------
  // Compare the Trihedrons
  //------------------------------------------------------------------------------
  static CATBoolean FindOutAnIdenticalTrd(CATPrContext& iContext, ListPOfCATTrd& iTrds1, const double iSize1, const CATMathTransformation& iTransfo, ListPOfCATTrd& iTrds2, const double iSize2, int Debug = 0);

  //------------------------------------------------------------------------------
  // Get Wet Area
  //------------------------------------------------------------------------------
  double GetWetArea();
  
  //------------------------------------------------------------------------------
  // Get Surface Type Id
  //------------------------------------------------------------------------------
  virtual unsigned char GetSurfaceTypeId();

  //------------------------------------------------------------------------------
  // Manage Size/Type
  //------------------------------------------------------------------------------
  virtual double GetSize();
  void SetSizeType(const int iType); // -1: same value for all, 0 (default): max vertex distance, 1: Sqrt(WetArea)

  //------------------------------------------------------------------------------
  // Create TrdSSet from PrBRep
  //------------------------------------------------------------------------------
  static CATTrdSSet* CreateTrdSSet(ListPOfCATPrBRep& iReps, CATTrdDic*& ioDic, const double iScale); // ioDic gets owned by created CATTrdSSet

  //------------------------------------------------------------------------------
  // To support stabilization
  //------------------------------------------------------------------------------
  static int Compare2Values(CATPrBRep* iRep1, CATPrBRep* iRep2);

  //------------------------------------------------------------------------------
  // Rectify tesselated geometry
  //------------------------------------------------------------------------------
  static void RectifyGeometry(ListPOfCATPrBRep& iReps, CATTrdDic* iDic);

  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  // Protected section
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  protected:

  //------------------------------------------------------------------------------
  // GetConvexity of a Border Edge of this
  //------------------------------------------------------------------------------
  virtual Convexity GetConvexity(CATEdge& iEdge, CATFace* ioFaces[2]);
  void StoreConvexity(CATEdge& iEdge, CATFace* iFaces[2], CATBody* iBody, const CATTopSharpness& iSharpness);


  //------------------------------------------------------------------------------
  // Returns convexity of border edges
  //------------------------------------------------------------------------------
  virtual Convexity GetBorderConvexity(int* oConcaveCount = NULL); 

  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  // Protected section
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  protected:

  //------------------------------------------------------------------------------
  // Compute BRep data
  //------------------------------------------------------------------------------
  void ComputeTopologicalBuffer();

  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  // Private section
  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------
  private :

  //------------------------------------------------------------------------------
  // Update computed data in case of spec or aggregation change
  //------------------------------------------------------------------------------
  virtual void Update();

  //------------------------------------------------------------------------------
  // Compute BRep data
  //------------------------------------------------------------------------------
  void UpdateBRep(ListPOfCATFace& iFaces, CATListOfInt& iFaceOrns);

  //------------------------------------------------------------------------------
  // Clouds
  //------------------------------------------------------------------------------
  void ClearClouds();

  //------------------------------------------------------------------------------
  // Trihedrons
  //------------------------------------------------------------------------------
  void ClearTrihedrons();
  virtual CATTrdSet* ComputeTrihedrons();
  void ComputeTrihedronAtVertex(CATVertex& iVertex, CATLISTP(CATCell)& iCellsAroundVertex, CATFace& iFace, const CATSide iFaceVsShell, CATTrdSet& oTrdSet);
  static HRESULT EvalTrd(CATPrContext& iContext, CATVertex& iVertex, CATEdge& iEdge1, CATSide iSide1, CATEdge& iEdge2, CATSide iSide2, CATFace& iFace, const CATSide iFaceVsShell, CATMathPoint oPoint[2], CATMathVector oTangent[2], CATMathVector& oNormal);

  //------------------------------------------------------------------------------
  // Signature
  //------------------------------------------------------------------------------
  void ClearSignature();

  //------------------------------------------------------------------------------
  // Geometry
  //------------------------------------------------------------------------------
  virtual void DeleteGeometricBuffer(const CATBoolean iDeleteTopologicalBuffer = TRUE);

  //------------------------------------------------------------------------------
  // Spec Compare
  //------------------------------------------------------------------------------
  virtual CATBoolean IsEqualBasedOnSpecGlobal(const CATMathTransformation& iTransfo, CATPrBRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest); 
  virtual CATBoolean IsEqualBasedOnSpecLocal(const CATMathTransformation& iTransfo, CATPrBRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest, CATLISTP(CATCell) iOnCells[2]); 

  //------------------------------------------------------------------------------
  // BRep Compare
  //------------------------------------------------------------------------------
  CATBoolean IsEqualBasedOnBRepGlobal(const CATMathTransformation& iTransfo, CATPrBRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest, int Debug = 0); 
  CATBoolean IsEqualBasedOnBRepLocal(const CATMathTransformation& iTransfo, CATPrBRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest, CATLISTP(CATCell) iOnCells[2], int Debug = 0); 

  //------------------------------------------------------------------------------
  // Compare the Faces
  //------------------------------------------------------------------------------
  CATBoolean Compare2FaceLists(ListPOfCATFace& iFaces1, CATMathSetOfPoints* ioClouds1, CATLISTP(CATSurParam)* ioParams1, const CATMathTransformation& iTransfo, ListPOfCATFace& iFaces2, CATMathSetOfPoints* ioClouds2, CATLISTP(CATSurParam)* ioParams2);
  CATBoolean Compare2Faces(CATFace& iFace1, CATMathSetOfPoints& ioCloud1,  CATLISTP(CATSurParam)& ioParams1, const CATMathTransformation& iTransfo, CATFace& iFace2, CATMathSetOfPoints& ioCloud2,  CATLISTP(CATSurParam)& ioParams2); // iFace1!=iTransfo(iFace2)    
  CATBoolean Compare2FaceListsLocally(ListPOfCATFace& iFaces1, ListPOfCATCell& iCell1, const CATMathTransformation& iTransfo, ListPOfCATFace& iFaces2, ListPOfCATCell& iCell2);

  CATBoolean GetBoxes(CATSurface& iSurface, ListPOfCATFace& iFaces, ListPOfCATCell& iCells, CATSurLimits& oUVBox, CATMathOBB& oOBB); // return whether iSurface is Adjacent to iCells

  static CATBoolean ComputeCloud(CATPrContext& iContext, CATFace& iFace, CATLISTP(CATSurParam) &oParams, CATMathSetOfPoints &oCloud); 
  static CATBoolean Compare2Clouds(CATPrContext& iContext, CATMathSetOfPoints& iCloud1, const CATMathTransformation& iTransfo, CATMathSetOfPoints& iCloud2);
  static CATBoolean CompareCloudAndFace(CATPrContext& iContext, CATFace& iFace1, const CATMathTransformation& iTransfo, CATMathSetOfPoints& iCloud2, CATLISTP(CATSurParam)& iParams2, CATFace& iFace2);

  //------------------------------------------------------------------------------
  // Compare the Signature
  //------------------------------------------------------------------------------
  CATBoolean CompareSignature(CATPrBRep &iRep);

  //------------------------------------------------------------------------------
  // For order stabilization
  //------------------------------------------------------------------------------
  virtual int Compare(CATPrRep& iRep);

  //------------------------------------------------------------------------------
  // Infra for order stabilization & filtering
  //------------------------------------------------------------------------------
  int CompareRep(CATPrBRep& iRep, const CATBoolean iFull);

  //------------------------------------------------------------------------------
  // Check if this is made of a single planar face
  //------------------------------------------------------------------------------
  CATBoolean IsPlanar();

  //------------------------------------------------------------------------------
  // Utilities for IsAdjacentTo
  //------------------------------------------------------------------------------
  CATBoolean CommonEdges(ListPOfCATEdge& iEdges1, ListPOfCATEdge& iEdges2, ListPOfCATEdge* ioCommonEdges = NULL);
  INLINE static int Compare2Edges(CATEdge* iValue1, CATEdge* iValue2) { /*CATLONG32 Diff = (iValue1?iValue1->GetPersistentTag():0) - (iValue2?iValue2->GetPersistentTag():0); */ CATLONGPTR Diff = iValue1 - iValue2; return (int)CATSign(Diff); };

  //------------------------------------------------------------------------------
  // Tolerant mapping
  //------------------------------------------------------------------------------
  double ComputeSquareTolFromMinTrdTrdDistance(ListPOfCATTrdRep iTrdReps, CATVertex **ioVertex1 = NULL, CATVertex **ioVertex2 = NULL);

  //------------------------------------------------------------------------------
  // Debug
  //------------------------------------------------------------------------------
  void Display(CATTrdSet& iTrdSet);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  // BRep 
  ListPOfCATFace         _Faces;
  CATListOfInt           _FaceOrns;
  ListPOfCATEdge         _BorderEdges; // Sorted
  ListPOfCATEdge         _InternalEdges;
  ListPOfCATVertex       _Vertices; 
  int                    _Loops;
  Convexity*             _BorderConvexity;
  int                    _ConcaveCount;

  // Wet area
  double*                _WetArea;
  int                    _SizeType;

  // Signature
  CATLISTP(CATToSort)    _Signature;

  // Trihedron Set
  CATTrdSet*             _TrdSet;  

  // Clouds
  CATMathSetOfPoints*    _Clouds;
  CATLISTP(CATSurParam)* _Params;
  int                    _CloudsCount;

  // Frozen Boundary
  ListPOfCATEdge*        _FrozenBorderEdges;

  // Management
  CATBoolean             _BRep;
  CATBoolean             _IsPlanar;

  // Debug
  //CATLISTP(CATGeometry)  _CreatedObjects;
};

//------------------------------------------------------------------------------

#endif
