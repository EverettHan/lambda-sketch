// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2017-2022, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCloudPrimitiveDetector.h
//
//===================================================================
//
// Usage notes:  
// Find geometric primitives in point cloud.
//
//=================================================================== 
// Aout 2022   : ANR : preparation de .h pour propagation manuelle a partir d'une liste graine
// 24 Fev 2022    : ANR : Attacher la fonction au lieu du cr
// Fev 2022    : ANR : Convergence 2022xfd02 ---->IR-921443-3DEXPERIENCER2022x
// Janv 2021                 : ANR : livraison dev sur les cylindres (reste des choses a ameliorer )
// Nov    2019               : ANR : Reecreture de la partie Cylindre + MultiRun
//Juillet 2019               : ANR : Ajout de GetMaxMeanDistance
// Juill 2019                : CZI3/ANR : Ajout de SEARCH_SPHERES et SEARCH_CONES (pas encore implementes)
// Juin 2019                 : CZI3 : Ajout de SetMinPrimitiveNbrPoints
// Mai 2019                  : ANR : Correction de CD chez Reverse
// Avril 2019                : ANR : Ajout de GetGeometricForm pour etre homogene avec Mesh2BRep(Tessele)
// Oct 2017                  : ALA : Ajout de SetPlaneHorizontalOrVerticalOnly
// February 2017 - June 2017 : VMC1/ANR : creation.
//===================================================================

#ifndef CATPolyDetectPrimitivesInCloud_H
#define CATPolyDetectPrimitivesInCloud_H

#ifndef _AIX_SOURCE

#include "CATPolyCanonicOperators.h"
#include "CATMapOfPtrToPtr.h"
#include "CATMapOfPtrToInt.h"
#include "CATErrorDef.h"
#include "CATListOfInt.h"
#include "CATAssert.h"
#include "CATMathPoint.h"
#include "CATPolyGeometricForm.h"
#include "CATMathAxis.h"
#include "CATMathPlane.h"
#include "CATMathVector.h"
#include <vector>
#include <set>
#include <deque>
#include <random>
#include <map> 

class CATSoftwareConfiguration;
class CATTolerance;
class CATPolyKDTree;
class CATPolyNeighborsGraph;

class ExportedByCATPolyCanonicOperators CATPolyDetectPrimitivesInCloud
{
public:

  // 2^0, 2^1, 2^2,2^3,2^4,2^5 ...
  enum
  {
    SEARCH_PLANES = 1,
    SEARCH_CYLINDERS = 2,
    SEARCH_JUNCTIONS = 4,
    SEARCH_PIPES = 8,
    SEARCH_SPHERES = 16,
    SEARCH_CONES = 32
  };

  // Need to compute kd-tree/Graph
  CATPolyDetectPrimitivesInCloud(CATSoftwareConfiguration* iConfig, CATTolerance* iTolerance, int iNbOfVertices, const double* iVertices);

  ~CATPolyDetectPrimitivesInCloud();

  void SetNormals(std::vector<double>& iNormals);

  void SetSearchMode(int iVal);

  void SetSizeOfNeighborhood(int iVal); // Need to compute kd-tree/Graph

  void SetMinPrimitiveNbrPoints(int iVal);

  void SetToleranceOnVertices(double iVal);

  void SetToleranceOnNormals(double iVal);

  // if this set is activate : you have only acces to GetNormal(int iVertex, double oNormal[]) or GetNormals();
  void SetComputeOnlyNormals();

  void SetMaxRadius(double iVal);

  void SetMinRadius(double iVal);

  void SetPlaneHorizontalOrVerticalOnly(bool iHorizontalOrVerticalOnly = true);

  void Setversion(int ilevel = 2, int iseed_index = -1);

  // On suppose que level >= 2  sinon je jette
  void SetListOfIdxPoints(int ilevel, CATListOfInt& iSeedIdxPoints);

  // Ne pas appeler : anr
  void SetOldMethod();

  // Ne pas appeler : anr, pour ne perdre le dev , en cours ...
  void SetCoverage();

  enum
  {
    KEEP_IF_COLINEAR_TO_REFERENCE,
    KEEP_IF_ORTHOGONAL_TO_REFERENCE
  };

  /*
  If called, planes satisfying given criterium will be removed.
  iReference is a reference normal. Its length must be one.
  iTolerance is a tolerance on angle, given in radiant.
  iMode is one of :
  - KEEP_WHEN_COLINEAR_TO_REFERENCE,
  - KEEP_WHEN_ORTHOGONAL_TO_REFERENCE,
  In the first case, points whose normal is not colinear to the reference will be removed.
  In the second case, points whose normal is not orthogonal to the reference will be removed.
  */
  void SetRemovalOfPlanesBasedOnNormal(const CATMathVector& iReference, double iTolerance, int iMode);

  /**
  *  //Ajout Anr : proto Segmentation : To Improve!!!
  */
  void SegmentationInFreeForm(const double iAngle = 30);


  /**
  *  //Ajout Anr : propagation manuelle a partir d'une graine
  */
  void FixedConstraintsForPlane(CATMathVector &iImposedAxis);
  void RemoveConstraintsForPlane();
  /**
  *  //Ajout Anr : propagation manuelle a partir d'une graine
  */
  void FixedConstraintsForCylinder(CATMathVector& iImposedAxis, double iImposedRadius);
  void RemoveAxisConstraintsForCylinder();
  void RemoveRadiusConstraintsForCylinder();

  /**
  *  //Ajout Anr : passant par aussi pour le manuel
  */
  void FixedConstraintsForCylinder(CATMathVector& iFixedAxis, CATMathPoint& iPassingByPoint); // new constraint 23xGA (pour reverse) ---- passant par

  void FixedConstraintsForSphere(double& iImposedRadius);
  void RemoveRadiusConstraintsForSphere();

  void FixedConstraintsForSphere(CATMathPoint& iPassingByPoint); // new constraint 23xGA (pour reverse) ---- passant par
  void RemoveConstraintsPassingBypoint();


  /**
  *  //Ajout Anr : propagation manuelle a partir d'une graine
  */
  HRESULT Run();

  /*
  computations Only kdtree and graph.
  */
  HRESULT RunBuildGraph(int iParamSizeOfNeighborhood, CATPolyNeighborsGraph *&oGraph, CATPolyKDTree* &oTree);

  /**
  *  //Ajout Anr : propagation manuelle a partir d'une graine
  */
  HRESULT run_init_graph();

  /**
   *  //Ajout Anr : propagation manuelle a partir d'une graine
   */
  HRESULT run_init_segmentation();

  /**
  *  //Ajout Anr : propagation manuelle a partir d'une graine
  */
  HRESULT run_from_seed(int iParamSearchType, int iIdxPoint, CATListOfInt& oContent, CATPolyGeometricForm& oForm);
   
  /**
  *  //Ajout Anr : propagation manuelle a partir d'une liste graine
  * Not yet Implemeted --->23xFD02 (23xFD01?)
  * Limitation : Only Plane/Cylinder
  */ 
  HRESULT run_from_seed(int iParamSearchType, CATListOfInt& iIdxListOfPoints, CATListOfInt& oContent, CATPolyGeometricForm& oForm);


  /*
  Get how many primitives were found.
  */
  int GetNbPrimitives();

  enum
  {
    PRIMITIVE_PLANE,
    PRIMITIVE_TUBE,
    PRIMITIVE_COUPLER,
    PRIMITIVE_ELBOW,
    PRIMITIVE_TEE,
    PRIMITIVE_SPHERE,
    PRIMITIVE_CONE,
    PRIMITIVE_FREEFORM,
  };

  /*
  Get the type of one primitive.
  1 <= i <= GetNbOfPrimitives()
  */
  int GetPrimitiveType(int iPrimitive);

  /*
  Get the set of points belonging to a given primitive.
  1 <= iPrimitive <= GetNbOfPrimitives()
  1 <= oContent[i] <= NbOfVertices
  */
  void GetPrimitiveContent( int iPrimitive, CATListOfInt& oContent);

  /*
  Get the neighbors of a given primitive.
  1 <= iPrimitive <= GetNbOfPrimitives()
  1 <= oNeighbors[i] <= GetNbOfPrimitives()
  */
  void GetPrimitiveNeighbors(int iPrimitive, CATListOfInt& oNeighbors);

  /*
  Get the primitive to which a point belongs.
  Return 0 if the point does not belong to any primitive.
  Complexity : constant.
  */
  int GetPrimitiveOfPoint(int iPoint);

  // Ajout ANR : pour etre homogene avec MeshToBRep ( mesh tessele )
  void GetGeometricForm(int iPrimitive, CATPolyGeometricForm &oForm);

  //Ajout ANR : Pour eviter que Reverse recalcule
  void GetMaxMeanDistance(int iPrimitive, double &oMaxDist, double &oMeanDist, double &oPercent);

  /*
  Get the parameters of a primitive.
  1 <= iPrimitive <= GetNbOfPrimitives()
  */
  void GetPlanePrimitive(int iPrimitive, CATMathPoint& oOrigin, CATMathVector& oNormal);
  //
  void GetTubePrimitive(int iPrimitive, CATMathPoint& oFirstEndPoint, CATMathPoint& oSecondEndPoint, double& oRadius);
  //
  void GetCouplerPrimitive(int iPrimitive, CATMathPoint& oFirstEndPoint, CATMathPoint& oSecondEndPoint, double& oRadius);
  //
  void GetElbowPrimitive(int iPrimitive, CATMathAxis& oAxis, double& oSmallRadius, double& oBigRadius, double& oAngle);
  //
  void GetTeePrimitive(int iPrimitive, CATMathPoint& oFirstMasterEndPoint, CATMathPoint& oSecondMasterEndPoint, double& oMasterRadius,
                       CATMathPoint& oSlaveEndPoint, double& oSlaveRadius, CATMathPoint& oConnectionPoint);

  //Spheres CZI3 / ANR
  void GetSpherePrimitive(int iPrimitive, CATMathPoint& oCenter, double& oRadius);

  //Cones CZI3 / ANR
  void GetConePrimitive(int iPrimitive, CATMathPoint& oApex, double& oFirstRadius, double& oSecondeRadius, CATMathVector& oAxis);

  /*
  Returns the number of vertices which were given to this detector as input.
  */
  int GetNbVertices() { return _NbOfVertices; }

  /*
  Returns the array of vertices coordinates which was given to this detector as input.
  */
  double* GetVertices() { return _Vertices; }

  /*
  Get the normal of one point.
  1 <= iVertex <= NbOfVertices
  oNormal contains three doubles.
  */
  void GetNormal(  int iVertex, double oNormal[]);

  /*
  Return the array of normals.
  Its size is three times the number of points.
  Content : nx0 ny0 nz0 nx1 ny1 nz1 nx2 ny2 nz2 ...
  */
  const double* GetNormals();

  /*
  Get the Average distance of one point.
  1 <= iVertex <= NbOfVertices
  */
  void GetAveragedistance(int iVertex, double &oMeanDistance);

  /*
  Return the array of Average distance.
  Its size is the number of points.
  Content : d0, d1, d2 ....
  */
  const double *GetAveragedistances();

  /*
  Return the list of the indices of all the points which belong to no primitives.
  */
  void GetUnaffectedPoints(CATListOfInt& oPoints);

  // ==================================================
  //   For 3D Manual primitive (one click) 
  // ==================================================
  
  /**
  * Returns the max deviation between set of points Result and the primitive. 
  * @return
  * The deviation at each point.
  */
  double GetMaxDeviation();

  /**
  * Returns the Average deviation between set of points and the primitive.
  * @return
  * The Mean deviation value.
  */
  double GetAverageDeviation();

  /**
  * Returns the Average deviation between set of points and the primitive.
  * @return
  * The Mean deviation value.
  */
  double GetpercentOfpointsInTolerance();

  /**
  * Returns the maximum deviation between set of points Result and the primitive.
  * @return
  * The maximum deviation value.
  * @return
  * The oPoint With Max Deviation.
  * @return
  * Index of point with max deviation.
  */
  int GetPointWithMaxDeviation(CATMathPoint &oPointWithMaxDeviation);
   
protected:

  class Urn;
  class PercentagePrinter;
  class Chrono;
  class MathHelpers;

  class AbstractPrimitive
  {
  public:

    enum
    {
      PLANE,
      TUBE,
      COUPLER,
      ELBOW,
      TEE,
      SPHERE,
      CONE,
      FreeForm
    };

    AbstractPrimitive() : _Visited(false) { }

    virtual int GetType() = 0;

    bool IsPlane() { return PLANE == GetType(); }
    bool IsTube() { return TUBE == GetType(); }
    bool IsCoupler() { return COUPLER == GetType(); }
    bool IsElbow() { return ELBOW == GetType(); }
    bool IsTee() { return TEE == GetType(); }
    bool IsSphere() { return SPHERE == GetType(); }
    bool IsCone() { return CONE == GetType(); }
    bool IsFreeSurf() { return FreeForm == GetType(); }

    std::vector<int> _Content;
    std::set<AbstractPrimitive*> _Neighbors;
    bool _Visited;
    bool _Removed;
    int _Index;
    double _Score;
    int _TypeOfPrimitive;
    CATMathVector _Normal_of_patch;
    AbstractPrimitive* _Next;
    AbstractPrimitive* _Prev;
  };

  //Ajout Anr : proto Segmentation
  class FreeFormPrimitive : public AbstractPrimitive
  {
  public:
    virtual int GetType();
    int _ContentSize; 
  };

  //
  class PlanePrimitive : public AbstractPrimitive
  {
  public:
    virtual int GetType();
    CATMathPoint _Origin;
    CATMathVector _Normal;  
  };


  class TubePrimitive : public AbstractPrimitive
  {
  public:
    virtual int GetType();
    CATMathPoint _EndPoints[2];
    CATMathPoint _Center;
    CATMathVector _Direction;
    double _Radius;
    double _Height;

    std::vector<AbstractPrimitive*> _support_plans;
    bool _Neighbors_by_dist;
  };

  class CouplerPrimitive : public AbstractPrimitive
  {
  public:
    virtual int GetType();
    CATMathPoint _EndPoints[2];
    CATMathVector _Direction;
    double _Radius;
  };

  class ElbowPrimitive : public AbstractPrimitive
  {
  public:
    virtual int GetType();
    CATMathAxis _Axis;
    double _SmallRadius;
    double _BigRadius;
    double _Angle;
  };

  class TeePrimitive : public AbstractPrimitive
  {
  public:
    virtual int GetType();
    CATMathPoint _MasterEndPoints[2];
    double _MasterRadius;
    CATMathPoint _SlaveEndPoint;
    double _SlaveRadius;
    CATMathPoint _ConnectionPoint; // on the center line of both master and slave tubes. Lies between _MasterEndPoints[0] and _MasterEndPoints[1].
  };

  class SpherePrimitive : public AbstractPrimitive
  {
  public:
    virtual int GetType();
    double _Radius;
    CATMathPoint _Center;
  };

  class ConePrimitive : public AbstractPrimitive
  {
  public:
    virtual int GetType();
    double _Radius; // ??
    double _Height; // ??
    double _FirstRadius;
    double _SecondeRadius;
    double _OpeningAngle;
    CATMathVector _Axis;
    CATMathPoint _Apex;
    CATMathPoint _Center;
    CATMathPoint _FirstCenter;// ??
    CATMathPoint _SecondeCenter; // ??
  };

  enum {
    TAG_VISITED = 1,
    TAG_DONT_GROW_PATCH = 2,
    TAG_DONT_GROW_PRIMITIVE = 4,
  };

  struct CylinderExtremity
  {
    TubePrimitive* primitive;
    CATMathPoint end_point;
    CATMathVector direction;
    double radius;
    bool available;
  };


private:

  /*
 Fit a plane to points of given indices.
 */
  bool FitLeastSquarePlane(const std::vector<int>& iPoints, CATPolyGeometricForm& oForm);

  //
  bool FitLeastSquarePlaneGeneral(const std::vector<int>& iPoints, CATPolyGeometricForm& oForm);

  //
  bool FitLeastSquarePlaneHorizOrVert(const std::vector<int>& iPoints, CATPolyGeometricForm& oForm);

  /*
  Fit a cylinder to points of given indices.
  */
  bool FitLeastSquareCylinder(const std::vector<int>& iPoints, CATPolyGeometricForm& oForm);

  //
  bool FitLeastSquareCylinderGivenDirection(const std::vector<int>& iPoints, const CATMathVector& iAxis, CATPolyGeometricForm& oForm);

  //
  bool UpdateForm(const std::vector<int>& iPoints, CATPolyGeometricForm& ioForm);

  /*
  Compute the standard deviation.
  \sqrt{ \sum_i \Vert P(x_i) - x_i \Vert^2 }
  */
  double ComputeVertexError(const std::vector<int>& iPoints, const CATPolyGeometricForm& iForm);

  /*
  Compute the standard deviation of normal error.
  \sqrt{ \sum_i (acos( \langle n_i | N(x_i) \rangle ))^2 }
  */
  double ComputeNormalError(const std::vector<int>& iPoints, const CATPolyGeometricForm& iForm);

  /*
  Return true if point iPoint lies on surface iForm.
  */
  bool IsWelcome(int iPoint, const CATPolyGeometricForm& iForm, double itolerance);

  /*
  Print statistics on the results of the detection algorithm (how many primitives were found, of what kind, etc).
  */
  void PrintSummary();

  /*
  Fill _PrimitiveTable with primitives from the doubly-linked list.
  */
  void BuildPrimitiveTable();

  void GrowMinimalPatch(int iSeed, std::vector<int>& oPatch);

  void GrowPatchGivenRadius(int iSeed, double iRadius, std::vector<int>& oPatch);

  /*
  Growing-region algorithm.
  Grow a given seed (points listed in ioContent and surface description in ioForm).
  */
  bool GrowForm(std::vector<int>& ioContent, CATPolyGeometricForm& ioForm, std::set<AbstractPrimitive*>& oNeighbors, bool iUpdateTheForm = true);

  /*
  To be called before calling DetectPlanesWithGrowingRegion() or DetectCylindersWithGrowingRegion().
  */
  void PrepareGrowingRegion();

  /*
  To be called after the graph is computed, the normals are computed and PrepareGrowingRegion() has been called.
  Fill the doubly-linked list with detected planes.
  */
  void DetectPlanesWithGrowingRegion();

  /*
  To be called after the graph is computed, the normals are computed and PrepareGrowingRegion() has been called.
  Fill the doubly-linked list with detected tubes.
  */
  void DetectCylindersWithGrowingRegion();

  void DetectPseudoplanesWithGrowingRegion();

  /*
  Remove all planes but the N biggest.
  TODO: give the user a way to set N.
  Asserts that the primitives are sorted by decreasing size.
  */
  void RemoveSmallPlanesI();

  /*
  Uncover some proportion of the points initially covered by planes.
  Asserts that the primitives are sorted by decreasing size.
  */
  void RemoveSmallPlanesII();

  /*
  Remove all planes but the N with the highest scores.
  */
  void SelectBestPlanes();

  /*
  Estimate the mean distance between neighbors.
  */
  double EstimateMeanDistanceBetweenNeighbors();

  /*
  Describe an elbow between two tubes.
  The meaning of the attributes are the same as those of function CATGeoFactory::CreateTorus().
  */
  struct ElbowBetweenCylinderExtremities
  {
    CATMathAxis axis;
    double small_radius;
    double big_radius;
    double angle;
  };

  /*
  Compute an elbow between two cylinders extremities.
  Return false if the geometric configuration is not compatible with
  the existence of en elbow.
  THe cylinder extremities must not belong to the same cylinder.
  */
  bool ComputeElbowBetweenCylinderExtremities(const CylinderExtremity& iExtrA, const CylinderExtremity& iExtrB, ElbowBetweenCylinderExtremities& oElbow);

  /*
  List in oMatched all points of iPoints which lie on the surface described by iForm.
  See IsWelcome().
  */
  void Match(const std::vector<int>& iPoints, const CATPolyGeometricForm& iForm, std::vector<int>& oMatched);
  void Match(const std::vector<int>& iPoints, const CATPolyGeometricForm& iForm, double itol, std::vector<int>& oMatched, std::vector<int> &opts_ko);

  /*
  Compute the two extremities of tube iPrim.
  oExtremities must hold two CylinderExtremitys
  */
  void ComputeCylinderExtremities(TubePrimitive* iPrim, CylinderExtremity oExtremities[]);

  /*
  Insert given primitive into the doubly-linked list.
  */
  void InsertPrimitive(AbstractPrimitive* iPrim);

  enum
  {
    RETURN_NEXT_PRIMITIVE,
    RETURN_PREVIOUS_PRIMITIVE
  };

  /*
  Unlink a given primitive and delete it.
  */
  AbstractPrimitive* RemovePrimitive(AbstractPrimitive *ioPrim, int iRet = RETURN_NEXT_PRIMITIVE);

  /*
  If compiled with DEBUG being defined, CheckPrimitiveList() checks that all the links are correct.
  It checks the doubly-linked list, the neighborhoods, the content, etc.
  If an assertion fails, the program stops.
  If compiled without DEBUG being defined, this function does nothing.
  */
  void CheckPrimitiveList();

  /*
  Compute a score for each primitive, evaluating how interesting this primitive is likely to be from the point of view of the user.
  */
  void ComputeScores();

  /*
  Sort the primitives according to the size of their content.
  */
  void SortPrimitivesByDecreasingSize();

  /*
  Sort the primitives by type (elbow, plane, etc).
  Primitives of same type are sorted according to their scores.
  */
  void SortPrimitivesByTypeAndScore();

  /*
  Improves the delimitation between planes (where one plane ends and the other begins).
  */
  void RefinePlanes();

  /*
  Remove planes whose normal does not satisfy constraints.
  See SetRemovalOfPlanesBasedOnNormal();
  */
  void RemovePlanesBasedOnNormal();

  /*
  Merge adjacent primitives of similar kind iType and similar geometry.
  Before calling MergeBrokenPrimitives(), you should first sort the primitives with SortPrimitivesByDecreasingSize().
  */
  void MergeBrokenPrimitives(int iType);

  /*
  Computes how far a cylinder can impinge on an elbow.
  The first function relies on the hypothesis torus_major_radius = 2*torus_minor_radius and uses an heuristic.
  THe second function relies on a projected gradient to compute how far the cylinder must be trimmed.
  */
  double ComputeRetractionLength(double iCylinderRadius);
  double ComputeRetractionLength(double iMinorRadius, double iMajorRadius);

  /*
  Detect junctions based on the geometric configuration of previously detected tubes.
  */
  void DetectPipingJunctions();

  /*
  Return non-null if an elbow was detected and built.
  */
  ElbowPrimitive* DetectElbow(const CylinderExtremity& iEA, const CylinderExtremity& iEB);

  /*
  Return non-null if a coupler was detected and built.
  */
  CouplerPrimitive* DetectCoupler(const CylinderExtremity& iEA, const CylinderExtremity& iEB);

  // =============================================================================================
  //
  //                               DEBUT Ajout ANR
  //
  // =============================================================================================

  /*
     Detetct cylinders, spheres and cones with RANSAC CZI3/ANR
  */

  // Plans : 
  //Ajout ANR : Modeles CAD necessite de revoir la segmentation en Plan avant de passer aux cylindres ---
  void SegmentationOfUnusedPoints();
  void CheckUnsedPoints(std::vector<int> &iUnusedPts);

  void ExpandSeedNotAffected(int iUnallocatedPoint, double iTolAngle_d, std::map<int, int> iVisitedseed, std::vector<int> &oCondidates);
  void FindNeighborsOfNewAbstractPrim(AbstractPrimitive *iPatch, std::set<AbstractPrimitive*> &oListOfNeighborsPrimitives);
  void DetectPlanesWithRansac(); // Ajout de Chedli (mais non utilises)
  void NewRefinePlanes(); //Ajout Chedli pour remplacer RefinePlanes de Victor :  A verifier

  void DebugOneNeighbor(int iPointToDebug);

  // Cylindres :
  bool RansacCylinder(CATMathPoint &iPoint1, CATMathVector &iNormal1, CATMathPoint &iPoint2, CATMathVector &iNormal2, double &oRadius, CATMathPoint &oCenter, CATMathVector &oAxis);
  void DetectCylinderWithRansac();
  void MergeCylinders();
  void RefineCylinders();
  void GrowPatchGivenNormalAngle(int iSeed, double iAngle, int MinSizeOfPts, std::vector<int>& oPatch);

  // Ajout Anr
  void FindASequenceOfPlane(double iTolAngle_d, AbstractPrimitive *iPatch, CATMapOfPtrToInt *iMapOfRemovedPatches, std::vector<AbstractPrimitive*> &oCondidates);
  void FindTheBestNeighborPrimitive(double iTolAngle_d, AbstractPrimitive *iPatch, CATMapOfPtrToInt *iMapOfRemovedPatches, CATMapOfPtrToInt *iMapOfExpandList, std::vector<AbstractPrimitive*> &oListOfCondidates);
  void GetCondidatesNeighPrimitives(double iTolAngle_d, AbstractPrimitive *iPatch, std::vector<AbstractPrimitive*> &oCondidates);
  void DetectCylinderWithRansacAnr();
  void DetectCylinderWithRansacAnr_new();

  void MergeCylindersAnr();
  void RefineCylindersAnr();
  void MergeCylindersWithPlanesAnr();
  //void CreateNewCylinderFromListOfPlanesAnr(std::vector<int> &iTargetpatch, CATPolyGeometricForm &iTargetCylinder, std::vector<AbstractPrimitive*> &ioTargetPlanesToBuildCylinder);
  void CreateNewCylinderFromListOfPlanesAnr(CATPolyGeometricForm &iTargetCylinder, CATMapOfPtrToInt *ioMapOfRemovedPatches, std::vector<AbstractPrimitive*> &ioTargetPlanesToBuildCylinder, TubePrimitive *&ocylinder);
  void CreateNewSphereFromListOfPlanesAnr(CATPolyGeometricForm &iTargetSphere, CATMapOfPtrToInt *ioMapOfRemovedPatches, std::vector<AbstractPrimitive*> &ioTargetPlanesToBuildSphere, SpherePrimitive *&oNewSphere);

  //
  void UpdateNeighborsAfterMerge(CATMapOfPtrToInt *ioMapOfRemovedPatches, AbstractPrimitive *iPatchToKeep, AbstractPrimitive *iPatchToRemove,
    std::set<AbstractPrimitive*> &oListOfNeighbors);
  //
  void update_planar_topology();
  void update_topology();
  void detect_cylinders_to_merge();

  // Spheres : 
  bool RansacSphere(CATMathPoint &iPoint1, CATMathVector &iNormal1, CATMathPoint &iPoint2, CATMathVector &iNormal2, double &oRadius, CATMathPoint &oCenter);
  void DetectSphereWithRansac();
  void MergeSpheres();
  void RefineSpheres();

  // Cones :
  bool RansacCone(CATMathPoint &iPoint1, CATMathVector &iNormal1, CATMathPoint &iPoint2, CATMathVector &iNormal2, CATMathPoint &iPoint3, CATMathVector &iNormal3, CATMathPoint &oApex, CATMathVector &oAxis, double &oOpeningAngle, double &oRadius);
  void DetectConeWithRansac();
  void MergeCones();
  bool ConeCharacteristicsCompute(AbstractPrimitive* iPlane, CATMathPoint &iO2, CATMathPoint &iInter, CATMathVector &iDirection, double &oRadius, CATMathPoint &oCenter, CATMathPoint &oApex, CATMathVector &oAxis);

  // Utilitaires
  bool Intersect_TwoSegments(double iScale, CATMathPoint *PP, CATMathPoint *QQ, double iTol, CATMathPoint &oIntersect, double &olambda1, double &olambda2);
  bool Intersect_TwoSegments_For_Sphere(double iScale, CATMathPoint *PP, CATMathPoint *QQ, double iTol, CATMathPoint &oIntersect, double &olambda1, double &olambda2);

  //
  void DeleteDirectory(CATUnicodeString & icDirectoryPath);

  //
  void VisuPatches(char *iDirName, char *iFileName, std::vector<AbstractPrimitive*> iListOfPatches);
  void Visu_list_of_patches(char *full_name, std::vector<AbstractPrimitive*> iListOfPatches);
  void Visu_cylinder(char *iFileName, std::vector<int> &icurrentpatch);
  void debug_Neighbors();

  void DetectFreeFormWithGrowingRegion();

  void compute_unused_pts(std::vector<int> &oAllUnUsedPoints, int &oNbPlanePrimitives, int &onb_pts_affected);
  void write_stats(int iNbPlanePrimitives, int inb_pts_affected, int inb_unused_pts);

  void DetectPlanesWithNormalsPropagation(std::vector<int> &iAllUnUsedPoints, double itol_on_normals, double& opercent_isok);
  void GetPtMinPtMax(std::vector<int>& iPatch, CATMathPoint &oPtMin, CATMathPoint &oPtMax);
  void detectPatchGivenNormalAngle(int iSeed, double iAngle, int MinSizeOfPts, std::vector<int>& oPatch); 
  void DetectCylindersFromAdjacentPlanes();
  void IsPatchPlanar(const std::vector<int>& iPoints, CATMathPoint &plane_origin, CATMathVector &plane_normal, std::vector<int>& oMatched); 
  void ComputeBoundingBoxOfPlanarPrimitives();
  void compute_the_nearest_neighbors_by_distance(AbstractPrimitive* iPrim, std::vector<AbstractPrimitive*> &oListOfPrimitivesToCheck);
  void detect_adjacent_planes_condidate_for_cylinders();
  
  void convergence_cylinders();

  void call_old_run();    // version Victor toute premiere
  void call_new_run_v1(); // reprise avec Chedli
  void call_new_run_v2(); // version courante : Reprise ANR

  // convergence cylindre manuelle 22xFD02 
  bool extract_plane_with_given_seed(std::vector<int>& iPoints, std::vector<int>& oPointsInPlane, CATPolyGeometricForm& ioForm);
  HRESULT extract_plane_with_given_list_of_seeds(CATListOfInt& iIdxListOfPoints, std::vector<int>& oPointsInPlane, CATPolyGeometricForm& ioForm);

  bool extract_cylinder_with_given_seed(std::vector<int>& iPoints, std::vector<int>& oPointsOnCylinder, CATPolyGeometricForm& ioForm);
  HRESULT extract_cylinder_with_given_list_of_seeds(int iParamSearchType, CATListOfInt& iIdxListOfPoints, std::vector<int>& oPointsOnCylindre, CATPolyGeometricForm& ioForm);

  void compute_box_of_patch(std::vector<int>& iContent, CATMathBox& obox, double& hx, double& ohy, double& ohz);
  int detect_adjacent_planes_for_one_cylinder(AbstractPrimitive* iprim_ref, AbstractPrimitive*& onext_prim, CATPolyGeometricForm& form_cylinder);
  int convergence_one_cylinder(AbstractPrimitive* iprim_ref, AbstractPrimitive *inext_prim, CATPolyGeometricForm & ioform_cylinder);
  void create_cylinder_by_picking(AbstractPrimitive* iprim_ref, AbstractPrimitive *&ocylinder);


  void check_output_points();
  void ComputeDistancesToInitPlansPrimitives();
  void fix_tab_Of_first_primitives_and_map();
  void SortPlanesByDecreasingNbCondidatesToCylinder(int iStep);
  void SortCurrentPrimitives();
  void check_duplicates_points();
  void create_first_new_cylinders();
  void prepare_compute_cylinders();
  void fix_first_cylinders();
  void GrowingCylinderRegion(int &onb_modif, CATMapOfPtrToPtr *iomap_of_visited_patches);
  void merge_between_cylinders(int &oNb_merge, CATMapOfPtrToPtr *iomap_of_merge_patches);
  void merge_with_neighbors();
  void merge_step_cylinders(); //Anr Janv 2021

  void debug_adjacent_planes_condidate_for_cylinders();
  void debug_convergence_cylinders();
  void debug_convergence_cylinders(int iPrimitive, PlanePrimitive *p);
  void Visu_Final_result();
  void check_Content_of_primitives();

  void test_perfo_on_knn(); 
  void get_adjacent_plans(AbstractPrimitive *prim_p, std::vector<AbstractPrimitive*> &ocandidates_to_cylinder);
  bool keep_planar_patch(AbstractPrimitive *prim_p, std::vector<int> &oremainingpoints);

  //Ajout Anr Dec 2020
  void Init_segmentation();
  void update_from_backup();

  //deplacer ...
  void RetrievePoint(int iIndex, CATMathPoint& opoint);
  void RetrieveNormal(int iIndex, CATMathVector& ovector);
 
  void SetDefaultParameters();
  void BuildKDTree();
  void BuildGraph();
  void ComputeNormals();
  void ComputeDistancesToPrimitives();
  void ComputeAverageDistances();

  //ajout Anr
  void ClearGraph();
  void ClearPrimitivesDetection();


  //IR-961557-3DEXPERIENCER2023x ---------------------------------------------------------------------------
  //void distance_analysis_of_current_cylinder(CATPolyGeometricForm &iCylinderForm, CATListOfInt &iContent,
  //                                           double& omean_deviation, double& omax_deviation, double& opercent);

  void distance_analysis_of_current_cylinder(CATPolyGeometricForm& iCylinderForm, CATListOfInt& ioContent,
                                             double& omean_deviation, double& omax_deviation, double& opercent,  
                                             int& oIndexMaxDeviation, CATMathPoint& opoint_with_max_deviation);

  void update_form_by_calling_recognition_oper(AbstractPrimitive* tube, CATPolyGeometricForm& ioForm);

  void get_neighbors_of_patch(AbstractPrimitive* iprim, std::vector<AbstractPrimitive*>& oListOfNeighbordsToCheck);

  void propagation_cylinder_by_neighborhood(AbstractPrimitive *iotube, CATPolyGeometricForm &ioForm, CATListOfInt &ioContent);

  void visu_for_debug(int iIdxPoint, CATListOfInt& iCurrentContent);
  void visu_Neighbors_debug(int iIdxPoint, int iter, AbstractPrimitive* iprim);


  // On garde la meme archi ... pour eviter les if, je prefere separer ! ---------------------------------------------------------------------------
  // dev surprise! pour les spheres ( en Manuel pour etre homogene avec mesh )
  int detect_adjacent_planes_for_one_sphere(AbstractPrimitive* iprim_ref, AbstractPrimitive*& onext_prim, CATPolyGeometricForm& sphere_form);
  int convergence_one_sphere(AbstractPrimitive* iprim_ref, AbstractPrimitive* inext_prim, CATPolyGeometricForm& ioSphere_form);
  void create_sphere_by_picking(AbstractPrimitive* iprim_ref, AbstractPrimitive*& oresult);

  void propagation_sphere_by_neighborhood(AbstractPrimitive* iosphere, CATPolyGeometricForm& ioForm, CATListOfInt& ioContent);

  void distance_analysis_of_current_sphere(CATPolyGeometricForm& iSphereForm, CATListOfInt& ioContent,
                                           double& omean_deviation, double& omax_deviation, double& opercent,
                                           int& oIndexMaxDeviation, CATMathPoint& opoint_with_max_deviation);

  // =============================================================================================
  //
  //                               FIN Ajout ANR
  //
  // =============================================================================================

  // champ prives :
  //---------------
  CATSoftwareConfiguration* _Config;
  CATTolerance* _Tolerance;

  int _ParamSearchMode;
  int _ParamSizeOfNeighborhood;
  int _MinPrimitiveNbrPoints;
  double _ParamToleranceOnVertices;
  double _ParamToleranceOnNormals;
  double _ParamCosToleranceOnNormals;
  double _ParamMaxRadius;
  double _ParamMinRadius;
  bool _ParamRPBNEnabled;
  CATMathVector _ParamRPBNReference;
  double _ParamRPBNTolerance;
  int _ParamRPBNMode;
  bool _HorizontalOrVerticalOnly;
  int _Level_Version;

  int _NbOfVertices;
  double* _Vertices;
  CATPolyKDTree* _Tree;
  CATPolyNeighborsGraph* _Graph;

  CATBoolean _ImposedNormals;
  std::vector<double> _Normals;

  std::vector<char> _Tags;
  std::vector<AbstractPrimitive*> _PrimitivesInv;
  std::vector<AbstractPrimitive*> _PrimitivesTable;
  AbstractPrimitive* _FirstPrimitive;
  AbstractPrimitive* _LastPrimitive;
  std::default_random_engine _RandomEngine;

  //Ajout Anr
  std::vector<AbstractPrimitive*> _all_primitives_resulting_from_first_segmentation;
  int _ParamSearchMode_client;
   
  std::vector<double> _MaxDist;
  std::vector<double> _MeanDist;
  std::vector<double> _Percent;

  CATBoolean _MustComputeGraph;

  // Rattrappe des points isoles ( non calculespar le graph )
  std::vector<int> _AllUnUsedPoints;
  std::vector<int> _AllIsolatePoints;
  std::vector<AbstractPrimitive*> _ListOfNewPrimitives;
  std::map<AbstractPrimitive*, int> _MapOfNewPrimitivesFromUnsedPts;

  std::map<int, int> _VisitedseedForUnsedPts;

  bool _FollowingOfHorizontalPlans;
  int _CurrentNbOfCondidates;
  int _Nb_merged_cylinder_cylinder, _Nb_merged_cylinder_Plane, _iterationMax;
  

  std::vector<int> _IdxPoints;
  std::vector<double> _AverageDistances;
  std::vector<int> _tag_is_ok;

  CATMathPlane _CurrentPlane;
  CATMathVector *_MainDirection;

  AbstractPrimitive *_seed_patch;
  CATBoolean _stop_propagation;

  double _xmin, _xmax, _ymin, _ymax, _zmin, _zmax;
  std::vector<double> _Hx;
  std::vector<double> _Hy;
  std::vector<double> _Hz;
  std::vector<CATMathBox> _box;
  CATMapOfPtrToInt *_map_all_first_primitives_bb; //map entre la premiere sgmenttain et les primitives tourvees

  //std::vector<CATListOfInt> list_of_adjacent_plans;  // pour calcul une suite successive pour chaque primitive
  std::vector< std::vector<int> > _list_of_adjacent_plans;
  std::vector< std::vector<int> > _list_of_split_adjacent_points_used_for_computing_cylinder;

  // pour la convergence des cylindres 
  std::vector<CATPolyGeometricForm> _list_condidates_to_be_cylinders;
  std::vector< std::vector<int> > _list_Of_pts_indices;
  std::vector <double> _list_of_scores;
   
  std::vector<AbstractPrimitive*> _list_of_new_cyl_primitives_created;

  std::vector <int> _Tag_of_each_pt_InPlane_InCylinder;
  std::vector< std::vector<int> > _remaining_points_in_final;

  //Anr
  CATBoolean _CallOldMethod, _ActivateCoverage;

  std::vector<AbstractPrimitive*> _CurrentPatches;

  //Anr :proto pour segmentation
  CATBoolean _SegmentationInFreeForm;
  double _AngleForPropagation;
  double _ParamCosForPropagation;
   
  std::vector<int> _Current_all_UnusedPoints;
  int _mean_nb_pts_after_first_step;
  CATMapOfPtrToInt *_map_first_planes;

  CATBoolean _change_radius_interval, _change_normals, _change_size_of_neighborhood, _change_min_points_in_primitive,
             _Change_tolerance_on_vertices, _Change_tolerance_on_normals;

  int _save_nb_init_primitives; 
  std::vector<CATMathPoint> _save_init_origin;
  std::vector<CATMathVector> _save_init_normal;
  std::vector<std::vector<int>> _save_points_of_first_segmentation; 

  std::vector<char> _save_tags;
  std::vector<AbstractPrimitive*> _save_primitivesInv;
  int _tol_size_patch;
  //
  std::vector<AbstractPrimitive*> _ordered_first_cylinders; 
  std::vector< std::vector<AbstractPrimitive*> > _list_of_merge_cylinders;

  double _zero_value;
  double _null_norm_of_vector;

  CATBoolean _search_plane_with_fixed_axis, _search_cylinder_with_fixed_axis, _search_cylinder_with_fixed_radius;
  CATMathVector _imposed_plane_axis, _imposed_cylinder_axis;
  double _imposed_cylinder_radius;

  CATMathPoint _imposed_Point_on_Axis;
  CATBoolean _search_passing_by_point;

  double _imposed_sphere_radius;
  CATBoolean _search_sphere_with_fixed_radius;

  CATBoolean _debug_tol;
  // Disable copy.
  CATPolyDetectPrimitivesInCloud(const CATPolyDetectPrimitivesInCloud&);
  CATPolyDetectPrimitivesInCloud& operator=(const CATPolyDetectPrimitivesInCloud&);

  CATBoolean _ComputeOnlyNormal;

  //Pour 3DPrimitive Manuelle : one click
  double _max_deviation, _mean_deviation, _opercent ;
  int _IndexMaxDeviation; CATMathPoint _point_with_max_deviation;

  CATBoolean _manual_mode; int _seed_index;
  CATListOfInt _SeedIdxPoints;

  // for manual detection
  std::vector<int> _list_of_pattern_candidates; int _comp_of_prim;
  std::vector<double> _list_of_percent_candidates;
  CATMathVector _current_cyl_direction; CATMathPoint _current_cyl_Center; double _current_cyl_radius ;

  std::vector< std::vector<AbstractPrimitive*> > _neighb_of_unused_pts;

  // on prevoit pour l'auto ... mais pour le manual pas besoin y en a que 1 de creer
  std::vector<CATPolyGeometricForm> _list_condidates_to_be_spheres;
  std::vector<AbstractPrimitive*>   _list_of_new_spheres_primitives_created;

};

#endif
#endif
