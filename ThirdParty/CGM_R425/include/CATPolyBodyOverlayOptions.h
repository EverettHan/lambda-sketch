// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyOverlayOptions.h
//
//===================================================================
// February 2015 Creation: ndo
// November 2019 Modification JXO: Added a check & healing option
//===================================================================
#ifndef CATPolyBodyOverlayOptions_H
#define CATPolyBodyOverlayOptions_H

// PolyhedralBodyOperators
#include "PolyBodyBoolean.h"

// PolyhedralInterfaces
#include "CATPolyDeprecated.h"

// Mathematics
#include "CATTolerance.h"

// CATMathStream
#include "CATSoftwareConfiguration.h"

// SystemTS
#include "CATErrorDef.h"   // For the definition of HRESULT.

// System
#include "CATLib.h"        // CATGetEnv
#include "CATIAV5Level.h"

class CATPolyBodyOverlayDiagnosis;
class CATPolyBodyOverlayDebug;
class CATSoftwareConfiguration;

#ifdef CATIAR217
namespace PolyOverlay
{
  enum class OverlayLevel : unsigned int;
}
#endif // CATIAR217

/**
 Options for all CATPolyBodyOverlay operators.
 By default, the tolerant options are not activated.
 To perform tolerant operations, set the tolerance
 and activate the tolerant mode.
*/
class ExportedByPolyBodyBoolean CATPolyBodyOverlayOptions
{

public:

  inline CATPolyBodyOverlayOptions ();

  CATPolyBodyOverlayOptions (const CATPolyBodyOverlayOptions& iRHS);

  virtual ~CATPolyBodyOverlayOptions ();

  CATPolyBodyOverlayOptions& operator = (const CATPolyBodyOverlayOptions& iRHS);

public:

  /** @name Software Configuration
      @{ */

      /**
       * Sets the software configuration.
       * AddRef is performed on the set configuration.
       * The life cycle of the set instance should be longer than the life cycle of this instance.
       */
  inline void SetSoftwareConfiguration (const CATSoftwareConfiguration* iSoftConfig);

  /**
   * Returns the software configuration.
   * Unless an AddRef is performed, the returned instance should not be released.
   */
  inline const CATSoftwareConfiguration* GetSoftwareConfiguration () const;

  /** @} */

public:

  /** @name Geometric Modeler Tolerance
      @{ */

  /**
   * Sets the geometric modeler tolerance.
   * For a tolerant overlay, the geometric modeler tolerance should be set.
   * It does not need to be set for non-tolerant overlay.
   * No AddRef is performed on the tolerance instance.
   * The life cycle of the set instance should be longer than the life cycle of this instance.
   */
  inline void SetGMTolerance (const CATTolerance* iGMTolerance);

  /**
   * Returns the geometric modeler tolerance.
   * Unless an AddRef is performed, the returned instance should not be released.
   */
  inline const CATTolerance* GetGMTolerance () const;

  /**
   * Activates (or deactivates) the computation of tolerant overlays.
   */
  inline void SetDoTolerant (bool iTrueOrFalse);

  /**
   * Returns true for tolerant overlays and false for non-tolerant overlay.
   */
  inline bool DoTolerant () const;

  /** @} */

public:

  /** @name Resolution and Tolerances
      @{ */

  /**
   * Returns the geometric modeler resolution.
   * In a tolerant overlay, topological cells must be separated by at least the resolution.
   * No two cell-vertices can be closer than the resolution for instance.
   */
  inline double GetGMResolution () const;

  /**
   * Sets the overlaying tolerance.
   * This distance applies to the overlaying of faces, edges and vertices for the computation of a tolerant overlay.
   * The overlaying tolerance is the maximum distance allowable between cells from separate operands for
   * their overlaying (from one operand to the other.)
   * Topological cells closer than this distance will be considered overlapping.
   * It is always greater or equal to the geometric modeler resolution (see GetGMResolution ().)
   * It will be overriden by the geometric modeler resolution otherwise.
   * If it is not set, it will be equal by default to the geometric modeler resolution.
   * Otherwise, it should be set after setting the geometric modeler tolerance to override the
   * default value.
   */
  inline void SetOverlayingTolerance (const double dtol);

  /**
   * Returns the overlaying tolerance.
   */
  inline double GetOverlayingTolerance () const;

  /**
   * Returns the tolerance used for reclassification of the copoints (sub-elements.)
   * Copoints are reclassified as topologogical sub-elements of a smaller dimension when the geometries
   * are within this tolerance.  For instance, a triangle-copoint can be reclassified as a bar- or tip-copoint.
   * A bar-copoint can be reclassified as a tip-copoint.
   * Reclassification applies only in the context of a tolerant overlay.
   * (It should NOT apply to a non-tolerant overlay.)
   * The reclassification tolerance is equal to a fraction of the geometric modeler resolution.
   */
  inline double GetReclassificationTolerance () const;

  /**
   * Returns the reclassification tolerance in case of difference cell
   */
  inline double GetReclassificationToleranceDiffCell () const;

  /**
   * Returns the range for gridded arithmetic (integer arithmetic.)
   * This applies to computation done with gridded-arithmetic (non-tolerant overlay.)
   */
  inline double GetArithmeticRange () const;

  /** @} */

public:
  /** @name Validity of the operand
  @{ */
  inline void SetAcceptNonManifoldElement (bool iIsValid = true);
  inline bool AcceptNonManifoldElement () const;

  /** @} */

public:

  /** @name CATPolyBody Result
      @{ */

  /**
   * Query for building a fully editable result.
   */
  inline bool DoBuildEditableResult () const;

  /**
   * Sets the flag for building an editable or non-editable result.
   */
  inline void BuildEditableResult (bool iTrueOrFalse);

  /**
   * Query for regularization of the CATPolyBody result.
   */
  inline bool DoBodyRegularization () const;

  /**
   * Sets the flag for regularizing the CATPolyBody result.
   */
  inline void SetDoBodyRegularization (bool iTrueOrFalse);

  /** @} */

public:

  /** @name Queries
      @{ */

  /**
   * Query for preprocessing (local bisection).
   */
  inline bool DoPreprocessing () const;

  /**
   * Query for switching to conformal regularization instead of tessellation.
   * NOT MAINTAINED AND DEPRECATED. DO NOT USE.
   */
  inline bool DoConformalRegularization () const;

  /**
   * Query for turning on the filtering of the short segments.
   */
  inline bool DoFiltering () const;

  /**
   * Has filtering option been set? (Reserved.)
   */
  inline bool FilteringSet () const;

  /**
   * Query for turning on gridded arithmetic (integer arithmetic.)
   * By default, gridded arithmetic is turned off.
   */
  inline bool DoGriddedArithmetic () const;

  /**
   * Query for activating the timer.
   */
  inline bool DoTimer () const;

  /**
   * Returns true if the operator should be used monothreaded.
   * Otherwise, it will use as many threads as there are cores available on the machine.
   */
  inline bool DoDisableMultithreading () const;

  /**
   * Query for activating the check of the result body and trying a healing.
   */
  inline bool DoCheckAndHealPostProcess () const;

  /**
   * Returns true if surfaces inside solids are to be kept in the result when they separate distinct volumes (false by default). 
   * This option is only supported by the iterative overlay.
   */
  inline bool DoKeepDividingInnerSurfaces () const;

  /**
   * Returns true if surfaces inside solids are to be kept in the result (false by default).
   * This option is only supported by the iterative overlay.
   */
  inline bool DoKeepAllInnerSurfaces () const;

  /**
   * Reserved for internal usage.
   * In the Iterative Overlay, determines whether we iterate until no intersections are found or not.
   */
  inline bool DoDisableIterativeConvergence () const;

  /**
   * Returns true if the iterative overlay is currently used to make the overlay conformal.
   * This method will return the state of the option as it was manually set on the object, or true by default.
   * Nevertheless, operators will override the option set on this object in some cases.
   * Here are the cases where the option is overriden, by decreasing order of priority (that is, if a case applies, all subsequent cases are ignored) :
   * 1) The intersect, join and heal operators do not use the iterative overlay ;
   * 2) The split will not use the iterative overlay if one of its operand is lineic ;
   * 3) The boolean, split and combine will use the iterative overlay in non-tolerant contexts ;
   * 4) If the CGM level is set to a value prior to the iterative overlay activation level, the iterative overlay cannot be used.
   */
  bool DoIterativeConstruction () const;

  /**
   * By default, we decimate the overlay after it has been made conformal using the iterative approach, but this can be disabled.
   * This decimation is performed to remove unnecessary surface vertices that were added during triangulation of the overlay.
   */
  inline bool DoDisableDecimation () const;

  /**
  * True if we avoid non manifold bar inside a face.
  **/
  inline bool DoRemoveNonManifoldInnerFaceBar() const;

  /**
  *  True if we want to create new faces with unique filiation
  */
  inline bool DoBuildTopoConsistentFiliation() const;

  /** @} */

public:

  /**
   * Query for preprocessing (local bisection).
   */
  inline void SetDoPreprocessing (bool iTrueOrFalse);

  /**
   * NOT MAINTAINED AND DEPRECATED. DO NOT USE.
   */
  inline void SetDoConformalRegularization (bool iTrueOrFalse);

  /**
   * Turn on or off the filtering of the short segments.
   */
  inline void SetDoFiltering (bool iTrueOrFalse);

  /**
   * Activate or deactivate the timer.
   */
  inline void SetDoTimer (bool iTrueOrFalse);

  /**
   * Forces the operator to use either a single thread or as many as there are cores (the later by default).
   */
  inline void SetDisableMultithreading (bool iTrueOrFalse);

  /**
   * If set to true, surfaces inside solids will be kept in the result whenever thet split separate volumes (false by default).
   * This option is only supported by the iterative overlay.
   */
  inline void SetKeepDividingInnerSurfaces (bool iTrueOrFalse);

  /**
   * If set to true, all surfaces inside solids will be kept in the result (false by default).
   * This option is only supported by the iterative overlay.
   */
  inline void SetKeepAllInnerSurfaces (bool iTrueOrFalse);

  /**
   * Used to force the deactivation of the Iterative Overlay.
   * Whether the Iterative Overlay is used or not depends on several criteria described in the associated getter's head comment.
   */
  inline void SetDisableIterativeOverlay (bool iTrueOrFalse);

  /**
   * Reserved for internal usage.
   * Used in the Iterative Overlay to prevent iterating until self-intersections vanish.
   * Mainly used to improve performances at the cost of robustness.
   */
  inline void SetDisableIterativeConvergence (bool iTrueOrFalse);

  /**
   * WARNING : DECIMATION IS DISABLED AND UNAVAILABLE FOR NOW.
   *
   * By default, we decimate the overlay after it has been made conformal using the iterative approach to remove unnecessary surface vertices added during triangulation.
   * This can be disabled using this option.
   */
  inline void SetDisableDecimation (bool iTrueOrFalse);

  /**
   * Sets the mode of the exact arithmetic.
   * By default, the exact arithmetic works with double-precision values.
   * To perform the exact arithmetic with gridded values (integer mode),
   * set this option to true.
   * @param iAbsoluteRange
   *   An optional positive value giving the range of the coordinates in
   *   in absolute values.  The range must be given with the position of
   *   the second operand computed with respect to the first operand.
   *   No position should be applied to the first operand when computing the range.
   */
  inline void SetDoGriddedArithmetic (bool iTrueOrFalse, double* iAbsoluteRange = 0);

  /**
   * Calls the Healing With Overlay operator
   */
  inline void SetDoCheckAndHealPostProcess (bool iTrueOrFalse);

  /**
   * Set to true if you want to avoid non manifold inner face bar
   */
  inline void SetRemoveNonManifoldInnerFaceBar(bool iRemoveNMInnerFaceBar = true);

  /**
  *  Set to true if we want to create new faces with unique filiation.
  *  Default is false, so we might build biggest new faces.
  */
  inline void SetBuildTopoConsistentFiliation(bool withConsistentFiliation=true);

public:

  /**
   * Returns the diagnosis for logging the warnings and errors occuring during
   * an overlay operation.
   */
  inline CATPolyBodyOverlayDiagnosis* GetDiagnosis () const;

  /**
   * Sets the diagnosis used for logging the warnings and errors occuring during
   * an overlay operation.
   */
  inline void SetDiagnosis (CATPolyBodyOverlayDiagnosis* diagnosis);

public:

  /**
   * Returns a service used for debugging purpose.
   */
  inline CATPolyBodyOverlayDebug* GetDebugOverlay () const;

  /**
   * Sets the service used for debugging purpose.
   */
  inline void SetDebugOverlay (CATPolyBodyOverlayDebug* bdbg);

public:

#ifdef CATIAR217

  bool IsOverlayChangeActive (const PolyOverlay::OverlayLevel iChange) const;

  /**
  * true if the provided overlay changes are ALL actives
   */
  template<typename ...Args>
  constexpr bool AreOverlayChangesActive (const PolyOverlay::OverlayLevel iChange0, Args...iArgs) const;

  constexpr bool AreOverlayChangesActive () const { return true; };

  /**
  * true if one of the provided overlay changes is active
  */
  template<typename ...Args>
  constexpr bool AreOverlayChangesPartiallyActive (const PolyOverlay::OverlayLevel iChange0, Args...iArgs) const;

  constexpr bool AreOverlayChangesPartiallyActive () const { return true; };

#endif // CATIAR217

protected:
  void Copy (const CATPolyBodyOverlayOptions & iToCopy);
  // Not exposed
  void SetReclassificationTolerance (const double iReclassificationTolerance);
  void SetReclassificationToleranceDiffCell (const double iReclassificationToleranceDiffCell);

  union
  {
    struct
    {
      unsigned int _DoTolerant : 1; /** Tolerant overlay. */
      unsigned int _UsePreprocessing : 1; /** Preprocessing (bisection). */ 
      unsigned int _UseConformalRegularization : 1; /** Conformal regularization. */    
      unsigned int _DisableFiltering : 1; /** Short segment filtering off. */ 
      unsigned int _UseGriddedArithmetic : 1; /** Gridded arithmetic. */   
      unsigned int _UseIntersectionCurves : 1; /** Intersection curves. */ 
      unsigned int _UseTimer : 1; /** Timer. */   
      unsigned int _UseFiltering : 1; /** Option filtering set (temp.) */ 
      unsigned int _DisableMultithreading : 1; /** Forces monothreading. */
      unsigned int _KeepDividingInnerSurfaces : 1; /** Keep null multiplicity surfaces inside solids, but only if they separate distinct volumes. */
      unsigned int _KeepAllInnerSurfaces : 1; /** Keep all null multiplicity surfaces inside solids. */

      unsigned int _BuildEditableResult : 1; /** Fully editable result. */   
      unsigned int _RegularizeBody : 1; /** Body regularization after operation. */
      unsigned int _UseMeshBoolean : 1; /** Reserved for boolean operations. */   
      unsigned int _ForceOverlay : 1; /** Reserved for boolean operations. */ 
      unsigned int _UseHealingWithOverlay : 1; /** Reserved for boolean operations. */ 
      unsigned int _DisableIterativeOverlay : 1; /** Do not use Iterative Overlay. */  
      unsigned int _DisableIterativeConvergence : 1; /** Do not converge with Iterative Overlay . */
      unsigned int _DisableDecimation : 1; /** Disable the decimation performed at the end of the Iterative Ovzerlay. */
      unsigned int _DisableRemoveNonManifoldInnerFace : 1; /** Disable non manifold treatment to avoid non manifold bar inside a face*/
      unsigned int _BuildTopoConsistentFiliation : 1; /** We build new topo with consistent filiation at any point */
    };

    unsigned int _Flags;
  };

  // Tolerances for tolerant overlays.
  double _OverlayingTolerance;               // Distance tolerance (by default it is set to the resolution from GM tolerance.)
  double _ReclassificationTolerance;
  double _ReclassificationToleranceDiffCell;
  const double _ReclassificationOverResolution;  // Ratio between the reclassification tolerance and the resolution. By default 0.1.

  double _Range;  // Absolute value of the coordinate range for gridded-arithmetic.

  bool _AcceptNonManifoldElement;

  CATSoftwareConfiguration* _SoftConfig;  // Software configuration (no AddRef/Release on this instance.)
  const CATTolerance* _GMTolerance;  // Geometric modeler tolerance (no AddRef/Release on this instance.)

  CATPolyBodyOverlayDiagnosis* _Diagnosis;
  CATPolyBodyOverlayDebug* _BDBG;   // An instance set for debugging purpose.

private:

  // void* instead of std::bitset<eOverlay_NbModifications> to avoid exposing bitset and helpersversioning
  void* _overlayLevel; // initialized at the options creation and updated when the software config is set

protected:
  virtual void UpdateLevel ();

private:

  void UpdateReclassificationTolerance ();
  inline static bool CATPolyBodyOverlayWithEditableResult ();

public:

  /**
   * Do not use.
   * Sets the tolerance used for reclassification of the copoints.
   * This is the reclassification tolerance applicable only to a non-tolerant overlay.
   */
  inline POLY_DEPRECATED ("Do not call this useless method: SetDefaultReclassificationTolerance",
                          void SetDefaultReclassificationTolerance (const double tolReclassification));
};

bool CATPolyBodyOverlayOptions::CATPolyBodyOverlayWithEditableResult ()
{
  static const char* str = CATGetEnv ("CATPolyBodyOverlayWithEditableResult");
  int d = str ? atoi (str) : 0;
  return d > 0;
}

inline CATPolyBodyOverlayOptions::CATPolyBodyOverlayOptions () :
  _Flags (0u),
  _OverlayingTolerance (0),                  // Default value.
  _ReclassificationOverResolution (0.1),
  _Range (0),                                // Default value (unset.)
  _SoftConfig (0),
  _GMTolerance (0),
  _Diagnosis (0),
  _BDBG (0),
  _AcceptNonManifoldElement (false),
  _overlayLevel (NULL)
{
  _KeepDividingInnerSurfaces = false;
  _KeepAllInnerSurfaces = false;
  if (CATPolyBodyOverlayWithEditableResult ())
  {
    _BuildEditableResult = 1u;
    _RegularizeBody = 1u;
  }
  UpdateReclassificationTolerance ();
  UpdateLevel ();
}

inline CATPolyBodyOverlayOptions::~CATPolyBodyOverlayOptions ()
{
  if (_SoftConfig)
    _SoftConfig->Release ();
  _SoftConfig = 0;

  if (_overlayLevel)
    delete _overlayLevel;
  _overlayLevel = NULL;

  _BDBG = 0;
  _Diagnosis = 0;
  _GMTolerance = 0;
}



inline void CATPolyBodyOverlayOptions::SetSoftwareConfiguration (const CATSoftwareConfiguration* iSoftConfig)
{
  if (_SoftConfig)
    _SoftConfig->Release ();

  _SoftConfig = (CATSoftwareConfiguration*)iSoftConfig;

  if (_SoftConfig)
    _SoftConfig->AddRef ();

  UpdateLevel ();
}

inline const CATSoftwareConfiguration* CATPolyBodyOverlayOptions::GetSoftwareConfiguration () const
{
  return _SoftConfig;
}

inline void CATPolyBodyOverlayOptions::SetGMTolerance (const CATTolerance* iGMTolerance)
{
  _GMTolerance = iGMTolerance;
  if (iGMTolerance)
  {
    _OverlayingTolerance = iGMTolerance->ResolutionForLengthTest ();
    _DoTolerant = 1u;
  }
  else
    _DoTolerant = 0u;

  UpdateReclassificationTolerance ();
}

inline const CATTolerance* CATPolyBodyOverlayOptions::GetGMTolerance () const
{
  return _GMTolerance;
}

inline double CATPolyBodyOverlayOptions::GetGMResolution () const
{
  return _GMTolerance ? _GMTolerance->ResolutionForLengthTest () : 0;
}

inline void CATPolyBodyOverlayOptions::SetDoTolerant (bool iTrueOrFalse)
{
  _DoTolerant = iTrueOrFalse ? 1u : 0u;
}

inline void CATPolyBodyOverlayOptions::SetOverlayingTolerance (const double dtol)
{
  _OverlayingTolerance = dtol;
}

inline double CATPolyBodyOverlayOptions::GetOverlayingTolerance () const
{
  return _OverlayingTolerance;
}

inline void CATPolyBodyOverlayOptions::SetReclassificationTolerance (const double iReclassificationTolerance)
{
  _ReclassificationTolerance = iReclassificationTolerance;
}

inline void CATPolyBodyOverlayOptions::SetReclassificationToleranceDiffCell (const double iReclassificationTolerance)
{
  _ReclassificationToleranceDiffCell = iReclassificationTolerance;
}

inline void CATPolyBodyOverlayOptions::UpdateReclassificationTolerance ()
{
  if (DoTolerant ())
    _ReclassificationTolerance = _ReclassificationOverResolution * GetGMResolution ();
  else
    _ReclassificationTolerance = _ReclassificationOverResolution / 100;  // To get rid of. (To return 0 for a non-tolerant overlay.)

  _ReclassificationToleranceDiffCell = GetGMResolution ();
}

inline double CATPolyBodyOverlayOptions::GetReclassificationTolerance () const
{
  return _ReclassificationTolerance;
}

inline double CATPolyBodyOverlayOptions::GetReclassificationToleranceDiffCell () const
{
  return _ReclassificationToleranceDiffCell;
}

inline double CATPolyBodyOverlayOptions::GetArithmeticRange () const
{
  return _Range;
}

inline bool CATPolyBodyOverlayOptions::DoTolerant () const
{
  return _DoTolerant;
}

inline bool CATPolyBodyOverlayOptions::DoBuildEditableResult () const
{
  return _BuildEditableResult;
}

inline bool CATPolyBodyOverlayOptions::DoBodyRegularization () const
{
  return _RegularizeBody;
}

inline bool CATPolyBodyOverlayOptions::DoPreprocessing () const
{
  return _UsePreprocessing;
}

inline bool CATPolyBodyOverlayOptions::DoConformalRegularization () const
{
  return _UseConformalRegularization;
}

inline bool CATPolyBodyOverlayOptions::DoFiltering () const
{
  return !_DisableFiltering;
}

inline bool CATPolyBodyOverlayOptions::FilteringSet () const
{
  return _UseFiltering;
}

inline bool CATPolyBodyOverlayOptions::DoGriddedArithmetic () const
{
  return _UseGriddedArithmetic;
}

inline bool CATPolyBodyOverlayOptions::DoTimer () const
{
  return _UseTimer;
}

inline bool CATPolyBodyOverlayOptions::DoDisableMultithreading () const
{
  return _DisableMultithreading;
}

inline bool CATPolyBodyOverlayOptions::DoKeepDividingInnerSurfaces () const
{
  return _KeepDividingInnerSurfaces;
}

inline bool CATPolyBodyOverlayOptions::DoKeepAllInnerSurfaces () const
{
  return _KeepAllInnerSurfaces;
}

inline bool CATPolyBodyOverlayOptions::DoCheckAndHealPostProcess () const
{
  return _UseHealingWithOverlay;
}

inline bool CATPolyBodyOverlayOptions::DoDisableIterativeConvergence () const
{
  return _DisableIterativeConvergence;
}

inline bool CATPolyBodyOverlayOptions::DoDisableDecimation () const
{
  return _DisableDecimation;
}

inline void CATPolyBodyOverlayOptions::BuildEditableResult (bool iTrueOrFalse)
{
  _BuildEditableResult = iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetDoPreprocessing (bool iTrueOrFalse)
{
  _UsePreprocessing = iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetDoBodyRegularization (bool iTrueOrFalse)
{
  _RegularizeBody = iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetDoConformalRegularization (bool iTrueOrFalse)
{
  _UseConformalRegularization = iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetDoFiltering (bool iTrueOrFalse)
{
  _DisableFiltering = iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetDoTimer (bool iTrueOrFalse)
{
  _UseTimer = iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetDisableMultithreading (bool iTrueOrFalse)
{
  _DisableMultithreading = iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetKeepDividingInnerSurfaces (bool iTrueOrFalse)
{
  _KeepDividingInnerSurfaces = _KeepAllInnerSurfaces || iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetKeepAllInnerSurfaces (bool iTrueOrFalse)
{
  _KeepDividingInnerSurfaces = iTrueOrFalse;
  _KeepAllInnerSurfaces = iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetDoGriddedArithmetic (bool iTrueOrFalse, double* iAbsoluteRange)
{
  _UseGriddedArithmetic = iTrueOrFalse;
  if (iAbsoluteRange && *iAbsoluteRange > 0)
    _Range = *iAbsoluteRange;
}

inline void CATPolyBodyOverlayOptions::SetDoCheckAndHealPostProcess (bool iTrueOrFalse)
{
  _UseHealingWithOverlay = iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetDisableIterativeOverlay (bool iTrueOrFalse)
{
  _DisableIterativeOverlay = iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetDisableIterativeConvergence (bool iTrueOrFalse)
{
  _DisableIterativeConvergence = iTrueOrFalse;
}

inline void CATPolyBodyOverlayOptions::SetDisableDecimation (bool iTrueOrFalse)
{
  _DisableDecimation = iTrueOrFalse;
}

inline CATPolyBodyOverlayDiagnosis* CATPolyBodyOverlayOptions::GetDiagnosis () const
{
  return _Diagnosis;
}

inline void CATPolyBodyOverlayOptions::SetDiagnosis (CATPolyBodyOverlayDiagnosis* diagnosis)
{
  _Diagnosis = diagnosis;
}

inline CATPolyBodyOverlayDebug* CATPolyBodyOverlayOptions::GetDebugOverlay () const
{
  return _BDBG;
}

inline void CATPolyBodyOverlayOptions::SetDebugOverlay (CATPolyBodyOverlayDebug* bdbg)
{
  _BDBG = bdbg;
}

void CATPolyBodyOverlayOptions::SetAcceptNonManifoldElement (bool iIsValid)
{
  _AcceptNonManifoldElement = iIsValid;
};

bool CATPolyBodyOverlayOptions::AcceptNonManifoldElement () const
{
  return _AcceptNonManifoldElement;
};

bool CATPolyBodyOverlayOptions::DoRemoveNonManifoldInnerFaceBar() const
{
  return !_DisableRemoveNonManifoldInnerFace;
}

void CATPolyBodyOverlayOptions::SetRemoveNonManifoldInnerFaceBar(bool iRemoveNMInnerFaceBar)
{
  _DisableRemoveNonManifoldInnerFace = !iRemoveNMInnerFaceBar;
}

// Do not call.
inline void CATPolyBodyOverlayOptions::SetDefaultReclassificationTolerance (const double tolReclassification)
{
}

inline bool CATPolyBodyOverlayOptions::DoBuildTopoConsistentFiliation() const
{
  return _BuildTopoConsistentFiliation;
}

inline void CATPolyBodyOverlayOptions::SetBuildTopoConsistentFiliation(bool withConsistentFiliation)
{
  _BuildTopoConsistentFiliation = withConsistentFiliation;
}

#endif
