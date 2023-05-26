/* -*-C++-*- */
#ifndef CATPrBRepDM_H
#define CATPrBRepDM_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrBRepDM: BRep piece from DeclarativeManifold, dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// May 2011    Creation                         R. Rorato
//===================================================================

#include "CATPrBRep.h"
#include "ListPOfCATDeclarativeManifold.h"
#include "CATCGMNewArray.h"
#include "AdvOpeInfra.h"

class ExportedByAdvOpeInfra CATPrBRepDM : public CATPrBRep
{
  public:
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATPrBRepDM(CATPrContext& iContext, CATDeclarativeManifold* iDM);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrBRepDM();

  //------------------------------------------------------------------------------
  // Forbidden
  //------------------------------------------------------------------------------
  CATPrBRepDM(CATPrBRepDM& iRep);
  CATPrBRepDM& operator= (const CATPrBRepDM& iRep);

  //------------------------------------------------------------------------------
  // Returns Geometric Representation
  //------------------------------------------------------------------------------
  void GetOwnedCells(CATLISTP(CATCell) &oCells, CATListOfInt* oOrns = NULL);

private:
  //------------------------------------------------------------------------------
  // Safe cast management
  //------------------------------------------------------------------------------
  CATPrBRepDM* GetAsPrBRepDM();

  //------------------------------------------------------------------------------
  // Dump internal data
  //------------------------------------------------------------------------------
  void Dump(CATCGMOutput& ioOS);

  //------------------------------------------------------------------------------
  // IsEqual based on Specifications
  //------------------------------------------------------------------------------
  CATBoolean IsEqualBasedOnSpecGlobal(const CATMathTransformation& iTransfo, CATPrBRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest); 
  CATBoolean IsEqualBasedOnSpecLocal(const CATMathTransformation& iTransfo, CATPrBRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest, CATLISTP(CATCell) iOnCells[2]); 

  //------------------------------------------------------------------------------
  // IsIsometric based on Specifications
  //------------------------------------------------------------------------------
  CATBoolean IsIsometric(const CATMathTransformation &iTransfoOnRep, CATTrdRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest, CATTrdChk* iChecker, const CATTrd::SimilarityType iSimilarityType, const CATBoolean iOnlyWithInvariant, CATLISTV(CATMathTransformation)& oTransfoFromThisToInputRep);
  static CATBoolean FixAroundAxis(CATMathTransformation& ioTransfoFromThisToInputRep, const CATMathTransformation& iTransfoOnRep, const CATMathLine& iTransformedRepAxis, CATPrRep& iThis, CATPrRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest);

  //------------------------------------------------------------------------------
  // Returns whether this & iRep are allowed to be adjacent instances of the same pattern
  //------------------------------------------------------------------------------
  CATBoolean IsAllowedToBeInstanceAdjacentTo(CATPrRep& iRep); 

  //------------------------------------------------------------------------------
  // Compute Rotation from 2 Translation (must be overloaded if Translation returned by IsIsometric is not unique)
  //------------------------------------------------------------------------------
  CATBoolean ComputeRotationFromTwoTranslations(const CATMathTransformation& iTr1, const CATMathTransformation& iTr2, CATMathTransformation& oRotation);

  //------------------------------------------------------------------------------
  // Get Convexity (0 is unknown)
  //------------------------------------------------------------------------------
  int GetConvexity();

  //------------------------------------------------------------------------------
  // GetConvexity of a Border Edge
  //------------------------------------------------------------------------------
  virtual Convexity GetConvexity(CATEdge& iEdge, CATFace* ioFaces[2]);

  //------------------------------------------------------------------------------
  // Extract canonicity
  //------------------------------------------------------------------------------
  void ExtractCanonicity();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private :

  // Spec
  CATDeclarativeManifold* _DM;
  CATShell*               _Shell; // Performances only

  // Canonicity
  CATBoolean _CanonicityExtracted;
  
  CATBoolean _IsACylinder;
  double _CylinderRadius;
  CATMathLine _CylinderAxis;

  CATBoolean _IsACone;
  double _ConeAngle;
  CATMathPoint _ConeSummit;
  CATMathDirection _ConeAxisDirection;

  CATBoolean _IsATorus;
  double _TorusMinorRadius;
  double _TorusMajorRadius;
  CATMathPoint _TorusCenter;
  CATMathDirection _TorusAxisDirection;

};

#endif
