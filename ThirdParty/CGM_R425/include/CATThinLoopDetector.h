//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATThinLoopDetector:
//    Header file for the CATThinLoopDetector operator.
//
//    The purpose of the operator is to determine whether an input list of
//    p-curves forms a thin loop (relative to an input tolerance).
//
//    A loop of p-curves is considered to be thin if:-
//    (1) there are exactly two confusions between consecutive p-curves in the
//        loop,
//    (2) each p-curve in the loop is confused with at least one other p-curve,
//    (3) there are no multiple confusions between any pair of p-curves.
//
//    A typical thin loop is essentially two parallel curves that start and end
//    at approximately the same points, with each of the two curves consisting
//    of at least one p-curve, with the internal end-points of the p-curves in
//    one curve not necessarily being the same as those of the other curve.
//
// Preconditions:
//    (1) The input p-curves are ordered in such a way as to form a loop.
//    (2) The input loop of p-curves must be closed (within a tolerance) and
//        not self-intersecting.
//
// Postconditions:
//    (1) If, during processing, it becomes clear that the input loop is not a
//        thin loop, processing is halted, and the outcome is set to
//        "Outcome_NotThinLoop".
//    (2) If an error occurs, the lists of p-curves on the first and second
//        sides of a thin loop are empty, and all p-curves in the input loop
//        are present in the list of unused p-curves.
//
//=============================================================================
// Usage notes:
//=============================================================================
// 01/09/22 R1Y Creation.
//=============================================================================

#ifndef CATThinLoopDetector_H
#define CATThinLoopDetector_H

// System
#include "CATListOfCATPCurves.h"

// GeometricOperators
#include "Y30C3XGG.h"
#include "CATGeoOperator.h"
#include "CATLISTV_PCurveData.h"


/**
  * Class defining the CATThinLoopDetector operator, which is used to detect
  * thin loops.
  * The input list of p-curve data must correspond to a closed loop.
  * <br> The operator returns 0 for success and 1 for failure.
  *<ul>
  *<li>The CATThinLoopDetector operator is created with the
  * <tt>CreateCATThinLoopDetector</tt> method and directly <tt>delete</tt>d
  * with the usual C++ delete operator.
  *<li>Options can be selected with the <tt>Set</tt> methods, before requesting
  * computation with the <tt>Run</tt> method.
  *<li>The result is accessed using <tt>GetResult()</tt>.
  *</ul>
  */
class ExportedByY30C3XGG CATThinLoopDetector : public CATGeoOperator
{
public:

/**
  * Defines the outcomes that are returned from the operator.
  * As this enum is streamed to the replay file, any new types should be added
  * to the end (and not inserted).
  * @param <tt>Outcome_Unknown</tt>
  * The state of the loop is unknown.
  * @param <tt>Outcome_InvalidInput</tt>
  * The input data is invalid, because either:
  * <dl><dt> the tolerance that is used to detect thin loops is negative,
  *     <dt>the number of input p-curves is less than two,
  *     <dt>at least one p-curve pointer is null,
  *     <dt>at least one set of p-curve limits is empty, or
  *     <dt>at least one edge index is not positive.</dl>
  * @param <tt>Outcome_Error</tt>
  * An error has occurred, so the state of the loop cannot be determined.
  * @param <tt>Outcome_ThinLoop</tt>
  * The loop is considerered to be thin (relative to the tolerance that is used
  * to detect thin loops).
  * @param <tt>Outcome_NotThinLoop</tt>
  * The loop is not considerered to be thin (relative to the tolerance that is
  * used to detect thin loops).
  */
  enum OutcomeType
  {
    Outcome_Unknown = -1,  // the outcome is unknown
    Outcome_InvalidInput,  // the input is invalid
    Outcome_Error,         // an error occurred
    Outcome_ThinLoop,      // the input loop of p-curves is thin
    Outcome_NotThinLoop    // the input loop of p-curves is not thin
  };

protected:

/**
  * @nodoc
  * Do not use these constructors; instead, use the creation method
  * <tt>CreateCATThinLoopDetector</tt>.
  */
  CATThinLoopDetector();
  CATThinLoopDetector(CATGeoFactory * const iFactory);

public:

/**
  * @nodoc
  * Destructor.
  */
  virtual ~CATThinLoopDetector();

  //-----------------------------------------------------------------------
  // Methods for setting data.
  //-----------------------------------------------------------------------

/**
  * Sets the tolerance that is used to detect thin loops.
  * @param iThinLoopTol
  * The tolerance that is used to detect thin loops.
  * The recommended value of the tolerance is two times the resolution.
  * If the value of iThinLoopTol is negative then the tolerance is not changed.
  * @return
  * Returns TRUE if the tolerance is set to the input value, and FALSE otherwise.
  */
  virtual CATBoolean SetThinLoopTol(const double iThinLoopTol) = 0;

/**
  * Sets the p-curves in the input loop, together with the curve limits,
  * orientations, and edge indexes.
  * If input data is already stored, this stored data is removed; further, if
  * the new data is valid, this new data is stored as the input data
  * (otherwise, the input data is empty).
  * @param InputPCurveData
  * The p-curves in the input loop, together with the curve limits,
  * orientations, and edge indexes.
  * @return
  * Returns TRUE if the input data is successfully set, and FALSE otherwise.
  */
  virtual CATBoolean SetInputPCurveData(const PCurveDataList & iInputPCurveData) = 0;

 /**
   * Sets the replay prefix (which appears in the name of a replay file) to
   * contain the input string.
   * If the input string is not empty, the replay prefix is set to be the
   * contents of "iPrefix" (with a leading underscore); otherwise, the replay
   * prefix is not modified.
   */
   virtual void SetReplayPrefix(const CATUnicodeString & iPrefix) = 0;

  //-----------------------------------------------------------------------
  // Methods for getting data.
  //-----------------------------------------------------------------------

/**
  * @nodoc
  * Returns the tolerance that is used to detect thin loops.
  * @return
  * The tolerance that is used to detect thin loops.
  */
  virtual double GetThinLoopTol() const = 0;

/**
  * @nodoc
  * Returns the p-curves in the input loop, together with the curve limits,
  * orientations, and edge indexes.
  * If the list for p-curves is non-empty on entry, this list is emptied, and
  * any input p-curves are added to the list.
  * @param oInputPCurveData
  * The p-curves in the input loop, together with the curve limits,
  * orientations, and edge indexes.
  * @return
  * Returns TRUE if the data is successfully obtained, and FALSE otherwise.
  */
  virtual CATBoolean GetInputPCurveData(PCurveDataList & oInputPCurveData) const = 0;
  
/**
  * Returns the outcome of the check for a thin loop.
  */
  virtual OutcomeType GetOutcome() const = 0;

/**
  * Returns the numbers of p-curves in the output lists of p-curves (from
  * <tt>this</tt> operator).
  * @param iNumPCurves1
  * The number of p-curves on the first side of a thin loop.
  * @param iNumPCurves2
  * The number of p-curves on the second side of a thin loop.
  * @param iNumUnusedPCurves
  * The number of unused p-curves.
  */
  virtual void GetNumOutputPCurves(CATLONG32 & oNumThinLoopPCurves1,
                                   CATLONG32 & oNumThinLoopPCurves2,
                                   CATLONG32 & oNumUnusedPCurves) const = 0;

/**
  * Returns the output lists of p-curves (from <tt>this</tt> operator).
  * If a list for p-curves is non-empty on entry, this list is emptied, and any
  * appropriate p-curves are added to the list.
  * @param oThinLoopPCurves1
  * The list of p-curves on the first side of a thin loop.
  * @param oThinLoopPCurves2
  * The list of p-curves on the second side of a thin loop.
  * @param oUnusedPCurves
  * The list of unused p-curves.
  */
  virtual void GetResult(CATLISTP(CATPCurve) & oThinLoopPCurves1,
                         CATLISTP(CATPCurve) & oThinLoopPCurves2,
                         CATLISTP(CATPCurve) & oUnusedPCurves) const = 0;
};

/**
  * Creates an operator for determining whether an input list of p-curve data
  * forms a thin loop (relative to an input tolerance).
  * @param iFactory
  * The factory.
  * @param iConfig
  * The software configuration.
  * @param iThinLoopTol
  * The tolerance that is used to detect thin loops.
  * The recommended value of the tolerance is two times the resolution.
  * @param iInputPCurves
  * The p-curves in the input loop, together with the curve limits,
  * orientations, and edge indexes.
  * @return
  * The pointer to the operator created.
  * To delete it, use the usual C++ delete operator after use.
  */
ExportedByY30C3XGG CATThinLoopDetector * CATCreateThinLoopDetector(      CATGeoFactory            * const   iFactory,
                                                                         CATSoftwareConfiguration * const   iConfig,
                                                                   const double                             iThinLoopTol,
                                                                   const PCurveDataList                   & iInputPCurveData);

#endif
