// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAssemblyPathPlanning.h
// Header definition of CATPolyAssemblyPathPlanning
//
//===================================================================
//
// Usage notes: Base class for path planning in a physical environment
//
//===================================================================
//
// January 2013 Creation: JXO
// April 2013 Modification JXO: SetAxisForTranslations, SetAxisForRotations, GetRandomPosition
// September 2013 Modification JXO: Phoenix related methods
// September 2013 Modification JXO: C-DIST
// October   2013 Modification JXO: New interpolator class & moved checker in separate file
// October   2015 Modification JXO: CATPolyAssemblyPathPlanningClashCallback
// June      2018 Modification JXO: CATPolyAssemblyPathPlanning2Dx1
//===================================================================
#ifndef CATPolyAssemblyPathPlanning_H
#define CATPolyAssemblyPathPlanning_H

// ExportedBy
#include "PolyBodyBVHOperators.h"

// Poly
class CATBVHTreeSet;
class CATPolyInterferenceOper;
class CATPolyPPCartesianProduct;
class CATPolyBodyFuzzyOffset;
#include "CATPolyUniformRandomGenerator.h"
#include "CATPolyPPConfigurationChecker.h"
#include "CATPolyPPConfigurationDistance.h"
#include "CATPolyAssemblyPathInterpolator.h"
#include "CATPolyAssemblyPathPlanning3DChecker.h"
#include "CATPolyDebugPathPlanningTraces.h"
#include "CATPolyPPTopologicalSpaceSO3.h"
#include "CATPolyInterfClashContactOper.h"

// Math
#include "CATMathPoint.h"
#include "CATMathTransformation.h"
#include "CATMathAxis.h"
#include "CATMathBox.h"

// System
#include "CATListOfInt.h"
#include "CATListOfDouble.h"

#ifdef _AIX_SOURCE
#undef throw
#undef try
#undef catch
#endif

#include <vector>

#ifdef _AIX_SOURCE
#define throw ERROR
#define try ERROR
#define catch ERROR
#endif

// Forward declarations
class CATPolyAssemblyPathPlanning2D;
class CATPolyAssemblyPathPlanning3D;
class CATPolyAssemblyPathPlanning6D;
class CATPolyAssemblyPathPlanning2Dx1;
class CATPolyAssemblyPathPlanning3DChecker;
class CATPolyAssemblyPathPlanningCDIST;
class CATPolyPPDistance;

/**
 * Callback to implement multiple clash contexts (multiple clearances and allowed depths)
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPathPlanningClashCallback
{
public:
  /**
   * To be implemented by application. This method will be called at least once.
   * You can activate or deactivate groups of ids in the input BVHTree sets,
   * and change the clash solver to be used.
   * @param iCurrentCall
   *        1, 2, 3...
   * @param iScene
   *        Input scene. You can activate or deactivate ids in it.
   *        Do not change the positions.
   * @param iMovingModel
   *        Input moving objects, one per id. You can activate or deactivate ids in it.
   *        Note that their positions at the time of the call have been set,
   *        according to the path planning solver.
   *        Do not change the positions.
   * @param oOper
   *        Set the clash solver to be used by the solver.
   * @param oAllowedDepth
   *        Set the allowed depth to be used by the solver.
   * @return Return 0 if you do not want any more clash calls,
   *         or any positive value to continue to be called.
   *         For example, if you want only one clash call, return 0.
   *         For example for four calls, you can return: 3, 2, 1, 0.
   */
  virtual int GetClashSolver(int iCurrentCall, CATBVHTreeSet & iScene, CATBVHTreeSet & iMovingModel, CATPolyInterferenceOper * & oOper, double & oAllowedDepth) = 0;

protected:
  CATPolyAssemblyPathPlanningClashCallback();
  virtual ~CATPolyAssemblyPathPlanningClashCallback();
};

/**
 * Base class for path planning in a physical environment
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPathPlanning : public CATPolyAssemblyPathInterpolator
{
public:
  /**
   * Constructor
   * @param iScene
   *        BVHTreeSet containing the whole scene where iMovingModel should be moving (without iMovingModel)
   * @param iMovingModel
   *        BVHTreeSet containing moving model. Should contain one and only one model.
   * @param iRandomSeed Seed for the random generator. You should NEVER use 0.
   * @param iType CATPolyUniformRandomGenerator::AdvMathematics is a good idea
   */
  CATPolyAssemblyPathPlanning(CATBVHTreeSet & iScene, CATBVHTreeSet & iMovingModel, unsigned int iRandomSeed, CATPolyUniformRandomGenerator::Type iType);

  CATPolyAssemblyPathPlanning( const CATPolyAssemblyPathPlanning& iOther );
  /** Destructor */
  virtual ~CATPolyAssemblyPathPlanning();

  /**
   * @brief Set an optimized hull of the iMovingModel, that can be used to improve clash performance
   * @see CATPolyVisuBVHPPHullBuilder can be used to create the input but other service can also this this input
   * 
   * use SetClashSolverPassHull on each pass   
  virtual void SetMovingModelHull(CATBVHTreeSet * iMovingHull=nullptr, CATBoolean iuseHullOnly=FALSE);
  **/
  
  

  /**
   * Sets the limits of the search space, in model space.
   * Limits always have to be set AFTER SetAxisForTranslations and SetAxisForRotations.
   * Limits apply to the moving object in the physical world, more specifically to the translations.
   * @param iDim
   *        Dimension: 1, 2 for 2D case
   *                   3 for 3D case
   *                   4 to 6 for yaw, pitch, roll
   * @param[in] min
   *        Limit min of the iDim dimension
   * @param[in] max
   *        Limit max of the iDim dimension
   * @return E_INVALIDARG if iDim out of range, S_OK otherwise
   */
  virtual HRESULT SetLimits(int iDim, double min, double max) = 0;

  /** Converts the position of moving model (inside iMovingModel) to a point in configuration space
   * @return to be deleted by caller
   */
  virtual CATPolyPPPosition * Convert(const CATMathTransformation & iTransfo) const = 0;

  /** Converts a point in configuration space to the position of moving model (inside iMovingModel)
   */
  virtual CATMathTransformation Convert(const CATPolyPPPosition & iPoint) const = 0;

  /** Set the clash operator that will be used in the TestConfiguration method.
   * Default is null. Meaning that all positions are free.
   * Life cycle of the operator is left to the caller.
   * Operands are set by this CATPolyAssemblyPathPlanning::SetClashSolver call.
   * @deprecated since R417 use AddClashSolverPass instead.
   * @warning In the context of multi pass, a solver can be set first with it and then other pass could be added
   * This call clear all previous registered passes
   * pOper ownership is up to the caller
   */
  void SetClashSolver(CATPolyInterferenceOper * pOper);

  /**
   * @brief Add a new pass of clash with a different operator
   * @warning By default, the ownership of the operator is taken, do not delete it except if iTakeOwnership is set to false
   *
   * @param pOper                  clash operator
   * @param iActivatedSceneObject  list of active bvh id
   * @param iActivatedMovingObject list of active bvh id
   * @param iPenetration           penetration value
   * @param iTakeOwnership         by default ownership over clash oper is taken and will be destroyed at pass dtor
   *
   */
  void AddClashSolverPass(CATPolyInterferenceOper * pOper, const CATListOfInt& iActivatedSceneObject, const CATListOfInt& iActivatedMovingObject, double iPenetration = -1.0, bool iTakeOwnership = true );
  /**
   * add a new bvhtree set optimized with new ids 
   * @param iHull optimized version of the moving bvhtree set for this pass
   * @param iActivatedMovingObject new id of the new iHull bvhtreeset 
   * */
  HRESULT SetClashSolverPassHull(unsigned iPass,CATBVHTreeSet * iHull ,const CATListOfInt& iActivatedMovingObject, bool iFull=false);
  HRESULT SetClashSolverPassSceneHull(unsigned iPass,CATBVHTreeSet * iHullScene ,const CATListOfInt& iActivatedSceneObject);
  //void SetClashSolverPassHullMode(unsigned iPass,CATBVHTreeSet * iH );
  void GetClashSolverPass(unsigned iPass, CATPolyInterferenceOper *& opOper, CATListOfInt& oActivatedSceneObject, CATListOfInt& oActivatedMovingObject, double &oPenetration  ) const;
  void GetClashSolverPassHull(unsigned iPass, CATBVHTreeSet *& oHull ,CATListOfInt& oActivatedMovingObject, bool &ofull ) const;
  int GetNbClashSolverPass() const;

  /**
   * @brief clear all previously added clash passes
   * @warning Solver must be destroyed in multi-thread context
   *
   */
  void ClearClashSolverPass();

  /**
   * @brief Get the list of activated BVH tree object from the scene
   * An empty list will activate all objects
   *
   * @param iPass pass to be edited ( from 0 to N pass )
   *
   * @return CATListOfInt* to be edited, NULL pointer otherwise
   *
   */
  CATListOfInt* GetActivatedSceneObjectPass( unsigned iPass );

  /**
   * @brief Get the list of activated BVH tree object from the moving object
   * An empty list will activate all objects
   *
   * @param iPass pass to be edited ( from 0 to N pass )
   *
   * @return CATListOfInt* to be edited, NULL pointer otherwise
   *
   */
  CATListOfInt* GetActivatedMovingObjectPass( unsigned iPass );

  /**
   * @brief Get the allowed penetration value for the clash operator of the current pass
   *
   * @param iPass pass to be edited ( from 0 to N pass )
   *
   * @return double* to be edited, NULL pointer otherwise
   *
   */
  double* GetPenetrationPass( unsigned iPass );

  /** Set the penetration value allowed for clash
   * It's effective if and only if the penetration vector computation hase been
   * activated in the clash solver.
   * Default value is -1, meaning that allowed penetration is NOT activated.
   */
  void SetAllowedPenetration(double iPenetration);

  /** Set the clash callback in case you want multiple solvers and groups to be used.
   * This supersedes any call to SetClashSolver and SetAllowedPenetration.
   * See documentation of CATPolyAssemblyPathPlanningClashCallback.
   */
  void SetMultipleClashsCallback(CATPolyAssemblyPathPlanningClashCallback * iClashcallback){m_clashcallback = iClashcallback;}

  /** Returns clash checker to be used in the solvers */
  CATPolyPPConfigurationChecker & GetChecker();//gh7 avoid inline code to hook it{return *m_Checker;}

  /** Returns the computed center of the moving object */
  const CATMathPoint & GetCenterOfMovingObject() const { return m_CenterOfMovingObject; }

  /** Get a random position in the space.
   * @return A uniformly distributed random position in the range space. To be deleted by caller.
   */
  CATMathTransformation * GetRandomPosition();

  /**
   * @brief By pass packaging problems over CATFuzzyOffset
   * Gives an implementation of PolyBody fuzzy offset operator
   * @warning The ownership over the operator is taken by the path planner
   *
   * @param iOperator implementation inherited from CATIPolyBodyFuzzyOffset
   *
   */
  void SetOffsetOperator( CATPolyBodyFuzzyOffset* iOperator );


  /** @nodoc Debug */
  int GetClashesLaunched();

  /**
   * Returns the best estimated radius to be used in the AddGuidingPath method on the CATPolyPPDefinition.
   *
   * Note that any radius smaller than oMinRadius or bigger than oMaxRadius passed to AddGuidingPath
   * can lead to the path planning not converging.
   * @param[out] oMinRadius
   *        Minimal radius to set (lesser will generate convergence issue)
   * @param[out] oMaxRadius
   *        Maximal radius to set (bigger will generate convergence issue)
   * @param[out] oPreferedRadius
   *        Should be the radius hopefully leading to the best performances.
   * @return S_OK if everything went fine
   *         Error code if the planner was not set properly.
   */
  HRESULT GetPreferedRadius(double & oMinRadius, double & oMaxRadius, double & oPreferedRadius);

  /**
   * Checks wether this CATMathTransformation actually is inside the config space.
   * @param iTransfo
   *        CATMathTransformation to be checked.
   * @return
   *        S_OK if iTransfo is inside the config space.
   *        S_FALSE if iTransfo is NOT inside the config space.
   *        E_FAIL on unrecoverable error.
   */
  HRESULT CheckTransformation(const CATMathTransformation & iTransfo);


  /** For Phoenix record */
  virtual const CATListOfInt & GetLimitedDimensions() const = 0;
  /** For Phoenix record */
  virtual const CATListOfDouble & GetMinLimits() const = 0;
  /** For Phoenix record */
  virtual const CATListOfDouble & GetMaxLimits() const = 0;
  /** For Phoenix record */
  virtual CATPolyPPTopologicalSpaceSO3::RotationType GetRotationType() const;
  /** For Phoenix record */
  virtual CATPolyAssemblyPathPlanning2D * CastTo2D() {return 0;}
  /** For Phoenix record */
  virtual CATPolyAssemblyPathPlanning3D * CastTo3D() {return 0;}
  /** For Phoenix record */
  virtual CATPolyAssemblyPathPlanning6D * CastTo6D() {return 0;}
  /** For Phoenix record */
  virtual CATPolyAssemblyPathPlanning2Dx1 * CastTo2Dx1() {return 0;}
  /** Returns distance solver */
  CATPolyPPConfigurationDistance * GetDistance();
  /** Returns the scene */
  CATBVHTreeSet & GetScene() {return m_Scene;}
  /** Returns the moving object */
  CATBVHTreeSet & GetMovingObject() {return m_MovingModel;}

  virtual CATPolyAssemblyPathPlanning* Clone() const;

  const CATListOfDouble & GetInfLimits() const { return m_InfLimits; }

  const CATListOfDouble & GetSupLimits() const { return m_SupLimits; }


  /** Resets the random generator */
  void ResetRandomGenerator(unsigned int iRandomSeed = 0, CATPolyUniformRandomGenerator::Type iType = CATPolyUniformRandomGenerator::undefined);
  CATPolyUniformRandomGenerator& GetRandomGenerator(){ return m_Generator; };
protected:

  /**
   * @brief Selection of the best penetration algorithm
   *
   * Algorithms :
   * - Offset
   * - Contact with custom accuracy
   * - Penetration vector
   *
   * If input geometry is a solid or a closed skin, an offset is performed.
   * Depending on the penetration value, e.g. a small one on a large object, offsetting could be too expensive, so a fall back algorithm will be selected.
   * This fall back algorithm consists in performing a clash contact operator with a custom contact tolerance e.g. penetration / 2
   * Otherwise, the input geometry is not solid or not closed, a second fall back algorithm will be used. It falls back to the clash operator with penetration vector computation. One limitation remains, the object could still be in clash
   * after penetration extraction. As a result, no path could be found.
   *
   * @warning In case of offset algorithm, some part of the object could be suppressed if penetration value is bigger than the object thickness.
   *
   * @param iInput        moving object tree set
   * @param ioPass        clash pass to edit
   * @param ioMinDist     min dist operator to set operand in case of offset algorithm
   *
   */
  void SetupPenetrationAlgorithm( CATBVHTreeSet& iInput, CATPolyAssemblyPathPlanning3DChecker::MultiPassClash& ioPass, CATPolySetMeasureBetween& ioMinDist );

  /** Get steering distance used in solver */
  double GetSteeringDistance();


  friend class CATPolyAssemblyPathPlanning3DChecker;
  friend class CATPolyAssemblyPathPlanningCDIST;
  friend class CATPolyAssemblyPathPlanningClashCallbackDefaultImpl;
  friend class CATPolyPathPlanningSolver;
  friend class CATPolyPPDefinition;

  friend class RRTThread;
  friend class DDRRTThread;

  CATBVHTreeSet & m_Scene;
  CATBVHTreeSet & m_MovingModel;
  //CATBVHTreeSet * m_MovingModelHull=nullptr;
  //CATBoolean  _useHullOnly=FALSE;

  std::vector< std::pair<int, CATMathTransformation> > m_IdsToPos; ///< Store initial positions of moving object trees, saves search and allocation in TestConfiguration

  CATMathPoint m_CenterOfMovingObject;
  CATMathTransformation m_InitialTransformation;
  CATPolyUniformRandomGenerator m_Generator;
  CATPolyAssemblyPathPlanning3DChecker * m_Checker;
  CATPolyAssemblyPathPlanningCDIST * m_CDIST;
  //CATPolyInterferenceOper * m_ClashOper;
  double m_Penetration;
  CATPolyAssemblyPathPlanningClashCallback * m_clashcallback;

  bool m_DestroyObjects;
  //bool m_DestroyClashOper;

  CATListOfDouble m_InfLimits; // infimum limits
  CATListOfDouble m_SupLimits; // supremum limits

  DEBUGPATHPLANNINGOBJECTTRACE(m_traces);

  CATPolyBodyFuzzyOffset* m_Offset;

  class PenetrationFallBack : public CATPolyInterfClashContactOper::AccuracyChooser
  {
  public:

    PenetrationFallBack( double iAccuracy ) : m_Accuracy(iAccuracy) {}

    virtual double GetAccuracy(double sag) { return m_Accuracy; }

    double m_Accuracy;
  };


};

/**
 * C-Distance implementation
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPathPlanningCDIST : public CATPolyPPConfigurationDistance
{
public:
  CATPolyAssemblyPathPlanningCDIST(CATPolyAssemblyPathPlanning & iSpecs);
  ~CATPolyAssemblyPathPlanningCDIST();
  /**
   * Returns the square distance from first configuration (iConfig1) to second configuration (iConfig2),
   * using the DISP distance metric, i.e. longest of the displacements of all points on the moving objects
   * @param iConfig1: the first configuration of moving objects.
   * @param iConfig2: the second configuration of moving objects.
   * @param ioSquareDistance: square distance (using DISP distance metric)
   * @return E_FAIL if computation failed, S_OK otherwise
   */
  virtual HRESULT SquareDistance(const CATPolyPPPosition & iConfig1, const CATPolyPPPosition & iConfig2, double& ioSquareDistance);

private:
  CATPolyPPDistance* m_PPDistance;

  DEBUGPATHPLANNINGOBJECTTRACE(m_traces);
};


#endif

