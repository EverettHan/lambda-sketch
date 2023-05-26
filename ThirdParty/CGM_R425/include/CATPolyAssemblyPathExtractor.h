// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAssemblyPathExtractor.h
// Header definition of CATPolyAssemblyPathExtractor
//
//===================================================================
//
// Usage notes: Extractor for positions that are clashing
//
//===================================================================
//
// March 2013 Creation: JXO
// January 2017 Modification JXO: Added new options:
//                                SmallStep, MinimumRadius, MaximumRadius, RandomMode, RotationMode
//                                and observers
//                                Added new extraction method: RRTUniform
// June    2018 Modification JXO: Angle in radian in code search
//===================================================================
#ifndef CATPolyAssemblyPathExtractor_H
#define CATPolyAssemblyPathExtractor_H

// ExportedBy
#include "PolyBodyBVHOperators.h"


// Poly
#include "CATIPolyAssemblyPathExtractor.h"
class CATPolyAssemblyPathPlanning;

// Math
class CATTolerance;
#include "CATMathTransformation.h"




/**
 * Extract positions that are clashing
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPathExtractor : public CATIPolyAssemblyPathExtractor
{
public:
  /** Method used for the extraction */
  enum Method {
    /** Uses the penetration vector from the clash operator */
    PenetrationVector,
    /** Uses the collision solver from CDS-Dyn. Quite buggy. */
    CollisionSolver,
    /** Uses RRT to try to go out. DO NOT USE. NOT IMPLEMENTED. */
    RRT,
    /** Uses a uniform RRT to try to go out */
    RRTUniform
  };
  /** Constructor
   * @param iMethod method used 
   * @param iTol tolerance used in the clash operator (XScale support)
   * @param pPathPlanner
   *        Mandatory path planner in case of RRT method.
   * @param iNbThread set the number of thread 3 case exist:
   *    - negative value => heuristic will choose the number of thread to use
   *    - 0 => mono thread is active 
   *    - positive value => nb thread to use
  */
  CATPolyAssemblyPathExtractor(Method iMethod = PenetrationVector, const CATTolerance & iTol = CATGetDefaultTolerance(), CATPolyAssemblyPathPlanning * pPathPlanner = 0, int iNbThread = 0);
  /** Destructor */
  ~CATPolyAssemblyPathExtractor();

  Method GetMethod() const { return _Method; };
  //CATIPolyAssemblyPathExtractor & GetImpl() { return *m_ExtractorImpl };
  CATPolyAssemblyPathPlanning * GetPathPlanner() const { return _pPathPlanner; };

  /**
   * Set the first operand for the extraction.
   * This is basically the scene where the moving product must be extracted from
   */
  void SetFirstOperand(CATBVHTreeSet * data1);
  CATBVHTreeSet *GetFirstOperand() const;
  /**
   * Set the second operand.
   * This BVH tree set must contain one tree/object that represents the moving object.
   * Its position inside the BVH tree set is to be moved.
   */
  void SetSecondOperand(CATBVHTreeSet * data2);
  CATBVHTreeSet *GetSecondOperand() const;
  /**
   * Performs the extraction
   * @param iPos
   *        Initial (clashing) position of the second operand
   * @param oPos
   *        If everything went fine, contains a non clashing position
   * @return S_FALSE       initial position was not clashing
   *         S_OK          everything went fine and a non clashing position was found
   *         E_INVALIDARG  no moving object
   *         E_FAIL        it was impossible to find a non clashing position
   */
  HRESULT ExtractFromPosition(const CATMathTransformation & iPos, CATMathTransformation & oPos);

  /** Sets the number of tries for the solver.
   * Default is ONE try.
   */
  void SetMaxNumberOfIterations(int iMaxIterations);
  /** Returns the maximum number of tries. */
  int GetMaxNumberOfIterations();

  /**
   * @brief Enable/disable the multithread extract on implementation that handle it (if not mono thread is used ).
   * @param iNbThread set the number of thread 3 case exist:
   *    - negative value => heuristic will choose the number of thread to use
   *    - 0 => mono thread is active 
   *    - positive value => nb thread to use
   */
  void SetThreadNumber(int iNbThread = -1);
  int GetThreadNumber() const;
  /*
   * Set the small step used in the Random extractor. Default is the large resolution from the CATTolerance (100 X the resolution)
   */
  HRESULT SetSmallStep(double iSmallStep);
  double GetSmallStep() const;
  /*
   * Set the minimum radius used in the Random extractor. Default is 0.
   */
  HRESULT SetMinimumRadius(double iMinimumRadius);
  double GetMinimumRadius() const;
  /*
   * Set the maximum radius used in the Random extractor. Default is 1000.
   */
  HRESULT SetMaximumRadius(double iMaximumRadius);
  double GetMaximumRadius() const;

  /*
   * Set the random mode used in the Random extractor. Default is eNoRandom.
   */
  HRESULT SetRandomMode(RandomMode iRandomMode);
  RandomMode GetRandomMode() const;
  /*
   * Set the rotation mode used in the Random extractor. Default is no rotation.
   * @param iRotationMode
   *        0. for no rotation
   *        0.5 for sharing rotations and translations
   *        1. for expanding rotations from translations
   *        Any values in between for a smooth transition
   */
  HRESULT SetRotationMode(double iRotationMode);
  double GetRotationMode() const;

  /**
   * @param iDirection
   *        Search direction
   * @param iAngle
   *        Cone half angle, in radian
   */
  HRESULT SetSearchCone(const CATMathVector & iDirection, double iAngle);
  double GetSearchConeAngle() const;
  CATMathVector GetSearchConeDirection() const;
  /**
   * Resets
   */
  HRESULT ResetSearchCone();

  /**
   * Set a progress bar.
   * @param iBar you can release it after this call.
   */
  void SetProgressCallback(CATProgressCallback * iBar);
  /**
   * Registers an observer for fine outputs.
   * And AddRef is done on obs, a Release will be done in destructor
   */
  void RegisterObserver(CATPolyAssemblyPathExtractorObserver * obs);
  /** 
   * Unregisters obs. Release will be called.
   */
  void UnregisterObserver(CATPolyAssemblyPathExtractorObserver * obs);

  /**
   * Debug only, don't use
   */
  HRESULT SetBackAndForthFrequency(int iBackAndForth);
private:
  CATIPolyAssemblyPathExtractor * m_ExtractorImpl = nullptr;
  Method _Method = PenetrationVector;
  CATPolyAssemblyPathPlanning * _pPathPlanner = nullptr;
};

#endif

