// COPYRIGHT Dassault Systemes 2012
//===================================================================

// CATCSProfile2D.h
// Header definition of CATCSProfile2D

//===================================================================

// Usage notes:

//===================================================================

//  Feb 2012  Creation:                BF8 / CHU

//===================================================================
#ifndef CATCSProfile2D_H
#define CATCSProfile2D_H

#include "CATCDSVirtual.h"
#include "CATCSCurve2D.h"
#include "CATCDSEnums.h"
#include "CATCDSBoolean.h"

class CATCSMonoParametric;
class CATCSPoint2D;
class CATCSSketch;
class CATCSNProfile2D;
class CATCDSProfileIntersector;
class CATCDSStream;
class CATCSCoincidence;

//-----------------------------------------------------------------------
/**
 * Sequence of adjacent mono-parametric elements (curves, line segments, conic arcs) and connecting points.
 * All limiting points and associated constraints (coincidence) must have been created before the profile is created.
 * The number of points is equal to the number of curves if the profile is periodic (closed),
 * it is otherwise equal to the number of curves plus one
 * It is assumed that the n-th point is the starting point of the n-th curve, considering its current limits
 * and that the end point of the n-1 th curve (or the last one if n=1 and if the profile is closed)
 * If two consecutive curves display a tangency at their connecting point and if the tangency has to remain valid throughout all transformations,
 * then it is required that the tangency constraint be created before the profile
 */

class ExportedBySolverInterface CATCSProfile2D: public CATCSCurve2D
{
public:

  CATCSProfile2D();
  CATCSProfile2D(CATCSSketch *ipSketch);
  virtual ~CATCSProfile2D();
  
  /**
   * Modify the behavior of a self-intersected CATCSProfile2D, the mode can take any of the following values
   * - simNOTCHECKED : self intersections are allowed
   * - simFORBIDDEN : self-intersections are not accepted, and make the profile invalid
   * - simAUTOTRIM : unwanted portions are removed on offset profiles
   * @param iMode new mode (simNOTCHECKED is the default value set upon construction)
   * @param iSkipRegeneratingTheProfile if =1, the profile will not be regenerated (e.g. when unstreaming a profile)
   */
  void SetSelfIntersectionMode(CATCDSSelfIntersectionMode iMode, int iSkipRegeneratingTheProfile=0);

   /**
   * Read the self-intersection mode
   */
  CATCDSSelfIntersectionMode GetSelfIntersectionMode() const;

  // Check if a profile (base or offset) has any self-intersection at all
  CATCDSBoolean IsSelfIntersected();
  // Check if the profile has been initialized (if there are segments)
  CATCDSBoolean IsInitialized();

  virtual CATCSType GetType() const CATCDSOverride;
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  // Introspection
  int GetNbOfComponents() const;
  CATCSMonoParametric* GetComponent(int iIdx) const;
  int GetComponentOrientation(int iIdx) const; // returns +1 or -1 according to the orientation of the component with respect to the profile
  CATCSPoint2D * GetVertex(int iIdxVertex) const; // iIdxVertex starts at 0 and increases with the profile global parameter. The last value is NbComponents-1 (if periodic) or NbComponents (if periodic)
  CATCSExtrapolMode GetExtrapolMode(int iIdxComponent, int iEnd) const; // iEnd=0 if investigating the start of the component, 1 if investigating the end

  // Get the coincidence constraint involved at the start or end (wrt profile) of a given component, returns null if none found
  CATCSCoincidence * GetCoincidenceOnComponent(int iComponentIndex, int iStartOrEnd01); // iComponentIndex starts at 0; iStartOrEnd01: 0=start, 1=end

  virtual void ApplyTransformation2D(double iMatrix[3][3]) CATCDSOverride;
  virtual CATParamType GetLimits(double &oLow, double &oUp) CATCDSOverride;
  virtual void Evaluate2D(double iT,
                          double* oaPoint,
                          double* oaFirstDeriv,
                          double* oaSecondDeriv,
                          double* oaThirdDeriv = 0) CATCDSOverride;
  virtual CATCDSBoolean Regenerate() CATCDSOverride;
  virtual void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes) CATCDSOverride;

  virtual void GetLowAndUpGlobalParamsOfComponent(int iIdx, double& oLow, double& oUp);
  virtual void GetLowAndUpLocalParamsOfComponent(int iIdx, double& oLow, double& oUp);

  int GetNumberOfLoops();
  CATCDSBoolean GetNextInLoop(int iLoopIndex, int & ioIter, CATCSMonoParametric *& oSubElement, double & oStart, double & oEnd, int & oOrientation, CATCSPoint2D *& oStartVertex, CATCSPoint2D *& oEndVertex);
  CATCDSBoolean GetNextInProfile(int & ioIter, CATCSMonoParametric *& oProfileEdge, double & oStart, double & oEnd, int & oOrientation, CATCSPoint2D *& oStartVertex, CATCSPoint2D *& oEndVertex, CATCDSBoolean & oHidden, double& oLocalStart) const;

  // Note that iIdx starts at 1 dor discontinuities (by heritage), also note that iIdx and iT are redundant, iIdx may be left null if iT is known, and iT is recomputed if iIdx is not null
  virtual int GetNbOfDiscontinuities() CATCDSOverride;
  virtual void GetDiscontinuitiesParams(double *oaValues) CATCDSOverride;
  virtual void EvaluateAtDiscontinuity2D(int iIdx,
                                         CATDiscontinuitySide iSide,
                                         double iT,
                                         double* oaPoint,
                                         double* oaFirstDeriv,
                                         double* oaSecondDeriv,
                                         double* oaThirdDeriv = 0) CATCDSOverride;

  virtual CATCDSBoolean EvaluateLength(double iStart,
                                    double iEnd,
                                    double &oLength) CATCDSOverride;
  virtual void GetDirection2D(double &oX, double &oY) CATCDSOverride;

  // Internal Use only
  const CATCSNProfile2D * GetProfileNode() const; 
  CATCSNProfile2D * GetProfileNode(); 
  inline void SetParamType(CATParamType iType);
  inline CATParamType GetParamType() const;
  
  // Dump (debug only)
#ifdef CDS_DEBUG
  virtual CATCDSBoolean DumpObj(CATCDSStream& s, int iVerbose=1) const;
  virtual CATCDSBoolean IsSmartProfile();
#endif
  virtual CATCDSBoolean GenerateSegmentsFromString(const CATCDSString& SegmentsStr);
  CATCDSBoolean IsReversedProfile() const;

private:

  CATParamType               _IsPeriodic;
};

//-----------------------------------------------------------------------
inline void CATCSProfile2D::SetParamType(CATParamType iType) {
  _IsPeriodic = iType; }

inline CATParamType CATCSProfile2D::GetParamType() const {
  return _IsPeriodic; }


#endif
