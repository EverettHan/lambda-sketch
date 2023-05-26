/* -*-C++-*- */
#ifndef CATPrRep_H
#define CATPrRep_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrRep: BRep piece, dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// May 2011    Creation                         R. Rorato
//===================================================================

#include "CATTrdRep.h"
#include "CATCGMNewArray.h"
#include "CATMathTransformation.h"
#include "CATMathBox.h"
#include "CATMathInline.h"
#include "CATListOfCATCells.h"
#include "CATListOfCATGeometries.h"
#include "ListPOfCATPrRep.h"
#include "CATTrd.h"
#include "CATListOfULONG32.h"
#include "CATSafe.h"
#include "AdvOpeInfra.h"
CATSafeDefine(CATPrRep);       

class CATPrContext;
class CATPrBRep;
class CATPrBRepCM;
class CATPrBRepDM;
class CATPrBRepFace;
class CATPrBRepHole;
class CATPrBRepDisk;
class CATMathPoint;
class CATMathLine;
class CATMathOBB;
class CATTolerance;
class CATCGMOutput;

class ExportedByAdvOpeInfra CATPrRep : public CATTrdRep
{
public:
  //------------------------------------------------------------------------------
  // Object Management
  //------------------------------------------------------------------------------
  CATPrRep(CATPrContext& iContext, const CATULONG32 iTag);
  CATCGMNewClassArrayDeclare;        // Pool allocation
  virtual ~CATPrRep();
  CATPrRep(CATPrRep& iRep);
  CATPrRep& operator= (const CATPrRep& iRep);
  virtual CATPrRep* GetAsPrRep();

  //------------------------------------------------------------------------------
  // Overide creation Tag
  //------------------------------------------------------------------------------
  void SetTag(const CATULONG32 iTag);

  //==============================================================================
  // Methods managing CATPRRep growth - Must not be virtual
  //==============================================================================
  //------------------------------------------------------------------------------
  // Absorb geometry of iRep and take ownership of adjacent Reps input Rep. 
  // if iOnlyIfAdjacent then Append non adjacent Reps to input list.
  //------------------------------------------------------------------------------
  void Absorb(CATPrRep*& ioRep, const CATULONG32 iStamp, const CATBoolean iOnlyIfAdjacent, ListPOfCATPrRep& ioRejectedReps); // called only if IsAdjacentTo returned TRUE

  //------------------------------------------------------------------------------
  // Indicates whether this has absorbed another Rep, returns number of absorbed Reps
  //------------------------------------------------------------------------------
  int HasGrown() const; 

  //------------------------------------------------------------------------------
  // Get access for read to an absorbed Rep (0 for the main one)
  //------------------------------------------------------------------------------
  CATPrRep& GetRep(const int iIndex, CATULONG32* oStamp=NULL); 

  //------------------------------------------------------------------------------
  // return absorbed Reps
  //------------------------------------------------------------------------------
  void ExtractAbsorbedReps(ListPOfCATPrRep& ioReps);

  //------------------------------------------------------------------------------
  // Get the stamps of all the Reps
  //------------------------------------------------------------------------------
  void GetStamps(CATListOfULONG32& oStamps) const; 

  //------------------------------------------------------------------------------
  // Generate a new unique stamp
  //------------------------------------------------------------------------------
  static CATULONG32 GetNewUniqueStamp();

  //==============================================================================
  // Mandatory methods to be implemented for an instance type
  //==============================================================================
  //------------------------------------------------------------------------------
  // Returns Geometric Representation & orientations (CATSide) if requested 
  //------------------------------------------------------------------------------
  virtual void GetOwnedCells(CATLISTP(CATCell) &oCells, CATListOfInt* oOrns = NULL) = 0;

  //==============================================================================
  // Customization methods that can be implemented for an instance type
  //==============================================================================
  //------------------------------------------------------------------------------
  // Returns whether iTransfo(iRep) == this 
  // Must be overloaded if IsIsometric does not return UNIQUE Transformation (cylinder case)
  // If both ithisAdjRep & iAdjRep are provided, then comparison is done only locally
  //------------------------------------------------------------------------------
  virtual CATBoolean IsEqual(const CATMathTransformation& iTransfo, CATTrdRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest, CATTrdRep* ithisAdjRep = NULL, CATTrdRep* iAdjRep = NULL); 

  //------------------------------------------------------------------------------
  // Returns whether this & iRep are allowed to be adjacent instances of the same pattern
  //------------------------------------------------------------------------------
  virtual CATBoolean IsAllowedToBeInstanceAdjacentTo(CATPrRep& iRep); 

  //------------------------------------------------------------------------------
  // Update computed data in case of spec or aggregation change
  //------------------------------------------------------------------------------
  virtual void Update(); // Must be implemented if IsAdjacent may return TRUE

  //------------------------------------------------------------------------------
  // Returns whether this & iRep are adjacent in BRep (Default implementation returns FALSE)
  // If it returns TRUE then Absorb may be called
  // If oCommonCells is provided, then it is filled up
  //------------------------------------------------------------------------------
  enum Convexity {Border = -2, Concave = -1, Smooth = 0, Convex = 1, Any = 2};
  virtual CATBoolean IsAdjacentTo(CATPrRep& iRep, const Convexity iConvexity = Any, const int iCommonCellsMinCount = 1, CATLISTP(CATCell)* oCommonCells = NULL); 

  //------------------------------------------------------------------------------
  // Returns convexity of border edges
  //------------------------------------------------------------------------------
  virtual Convexity GetBorderConvexity(int* oConcaveCount = NULL); 

  //------------------------------------------------------------------------------
  // Freeze or Unfreeze the boundary cells of this Rep.
  // IsAdjacentTo must use frozen boundary first then current boundary.
  //------------------------------------------------------------------------------
  virtual void FreezeBoundary(const CATBoolean iFreeze); // Must be implemented if IsAdjacent may return TRUE

  //------------------------------------------------------------------------------
  // Compute Rotation from 2 Translation (must be overloaded if Translation returned by IsIsometric is not unique)
  //------------------------------------------------------------------------------
  virtual CATBoolean ComputeRotationFromTwoTranslations(const CATMathTransformation& iTr1, const CATMathTransformation& iTr2, CATMathTransformation& oRotation);

  //------------------------------------------------------------------------------
  // Safe cast management
  //------------------------------------------------------------------------------
  virtual CATPrBRep*  GetAsPrBRep();
  virtual CATPrBRepCM* GetAsPrBRepCM();
  virtual CATPrBRepDM* GetAsPrBRepDM();
  virtual CATPrBRepFace* GetAsPrBRepFace();
  virtual CATPrBRepHole* GetAsPrBRepHole();
  virtual CATPrBRepDisk* GetAsPrBRepDisk();

  //------------------------------------------------------------------------------
  // Dump internal data
  //------------------------------------------------------------------------------
  virtual void Dump(CATCGMOutput& ioOS);
  friend CATCGMOutput& operator << (CATCGMOutput& s, const CATPrRep & iRep);
  virtual void GetObjectsToSave(CATLISTP(CATGeometry)& ioObjectsToSave);

  //==============================================================================
  // Utilities
  //==============================================================================
  //------------------------------------------------------------------------------
  // Returns Geometric Representation
  //------------------------------------------------------------------------------
  void GetCells(CATLISTP(CATCell) &oCells, CATULONG32* iThisStampOnly = NULL, CATListOfInt* oOrns = NULL); // returns also absorbed Reps cells

  //------------------------------------------------------------------------------
  // Evaluate distance based on RefPoint
  //------------------------------------------------------------------------------
  double SquareDistanceTo(CATPrRep& iRep);

  //------------------------------------------------------------------------------
  // Check whether this.Boxes intersect iTransfo(iRep).Boxes
  //------------------------------------------------------------------------------
  CATBoolean DoBoxesIntersect(const CATMathTransformation &iTransfoOnRep, CATPrRep& iRep);
  CATBoolean DoBoxesIntersect(CATPrRep& iRep); // With no transformation & only sphere check

  //------------------------------------------------------------------------------
  // Check whether half an infinite line intersects this
  //------------------------------------------------------------------------------
  CATBoolean IsIntersecting(const CATMathPoint& iOrigin, const CATMathVector& iDirection);

  //------------------------------------------------------------------------------
  // Returns Rep Center (close to BRep)
  //------------------------------------------------------------------------------
  void GetCenter(CATMathPoint& oCenter);

  //------------------------------------------------------------------------------
  // Stabilize ordering with geometry
  //------------------------------------------------------------------------------
  static void StabilizeOrder(CATLISTP(CATPrRep) &ioReps);

  //------------------------------------------------------------------------------
  // Support StabilizeOrder 
  //------------------------------------------------------------------------------
  virtual int Compare(CATPrRep& iRep);

  //------------------------------------------------------------------------------
  // Assign color to this CATPrRep for Debug purpose
  //------------------------------------------------------------------------------
  void SetColor(const int iR, const int iG, const int iB);

  //------------------------------------------------------------------------------
  // Get Tag (debug only)
  //------------------------------------------------------------------------------
  CATULONG32 GetTag();

  //------------------------------------------------------------------------------
  // Check
  //------------------------------------------------------------------------------
  virtual void Check();

  //------------------------------------------------------------------------------
  // GetContext
  //------------------------------------------------------------------------------
  INLINE CATPrContext& GetContext() { return _Context; };

  //==============================================================================
  // Protected section
  //==============================================================================
protected :

  //------------------------------------------------------------------------------
  // Compare OBB Volumes
  //------------------------------------------------------------------------------
  //int CompareOBBVolume(CATPrRep& iRep);

  //------------------------------------------------------------------------------
  // Support StabilizeOrder 
  //------------------------------------------------------------------------------
  static int Compare2Values(CATPrRep* iRep1, CATPrRep* iRep2);

  //------------------------------------------------------------------------------
  // Manage Geometric Buffer 
  //------------------------------------------------------------------------------
  virtual void DeleteGeometricBuffer(const CATBoolean iDeleteTopologicalBuffer = TRUE);

  //==============================================================================
  // Private section
  //==============================================================================
private :
  void ComputeGeometricBuffer();
  void ComputeGeometricBuffer(ListPOfCATCell& iExplicitCells);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  CATULONG32      _Tag;
  CATULONG32      _Stamp;
  
  ListPOfCATPrRep _Absorbed; // only one level, i.e. _Absorbed reps do not own _Absorbed reps, checked

  CATPrContext   &_Context;

  // Geometric Buffer
  CATMathPoint   *_CenterPoint;
  double          _BoxRad;
  int             _OBBCount;
  CATMathOBB     *_OBBs;
  //double          _OBBVolume;
  CATMathBox      _Box;

  friend class CATPrSet;
  void SetTransfoThisVsRef(CATMathTransformation* iTransfoThisVsRef = NULL);
  CATMathTransformation _TransfoThisVsRef; // For CATPrSet usage only
  CATMathTransformation _TransfoRefVsThis; // For CATPrSet usage only
  CATBoolean            _TransfoRefVsThisComputed;
};

#endif
