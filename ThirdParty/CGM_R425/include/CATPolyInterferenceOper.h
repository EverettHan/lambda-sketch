// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterferenceOper.h
//
//===================================================================
//
// Usage notes:
// To be derived by actual interference operators.
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATPolyInterferenceOper_h
#define CATPolyInterferenceOper_h

#include "CATPolyBoundingVolumeOperators.h"

// Interferences traces
#include "CATPolyDebugClashTraces.h"

// System
#include "CATMathTransformation.h"
#include "CATBoolean.h"

// Interference
#include "CATPolyInterferenceObservable.h"
#include "CATPolyBodyTreeSetDescent.h"
class CATIPolyInterfInputCoupleFilter;
class CATPolyInterferenceList;
class CATIPolyInterference;
class CATPolyInterfWarningList;
class CATPolyInterferenceRecorder;
class CATIPolyInterfDecoPolyBodyFactory;
class CATPolyInterfDecoratedObjectsVisitor;
class CATPolyInterferenceOperObserver;
class CATPolyInterfClashOper;
class CATPolyInterfClashContactOper;
class CATPolyInterfClashContactClearanceOper;
class CATPolyInterfClashClearanceOper;
class CATPolyInterfCollisionOper;
class CATPolyInterfACMOper;
class OOCPCInterferenceOper;

// Math
class CATTolerance;

/**
 * To be derived by actual interference operators.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterferenceOper : public CATPolyInterferenceObservable
{
public:

  /**
   * Enum containing the different granularity levels.
   * For now there are:
   * - Geometric Level: All local interferences are computed.
   *                    This granularity is more accurate but result in more Interferences to analyse.
   * - Product Level: The local interferences are gathered in a single larger one for each object couple.
   */
  enum GranularityLevel
  {
    PRODUCT,
    GEOMETRY
  };

  /**
   * Enum controlling the amount of memory that will be used during interference computation.
   * Enabling higher memory modes will results in better performances.
   * For now parameters are:
   * - MINIMUM : The operator uses as few memory as possible, but will run with worst performances.
   * - LOW : The operator uses only little cache for its operations. The performances are significantly better
   *         than the minimum mode, while the memory only rises a little.
   * - MEDIUM : Probably the best compromise between CPU and Memory.
   * - HIGH : The operators uses lot of memory to cache internal data. It gives the best performances
   *          but might not be useable on large models. Also running twice on the same
   *          data while in HIGH mode will increase performances.
   * - AUTO : The operator tries to guess which above option will be best suitable for the operator
   *          according to the input BVH tree set. This is the recommanded option.
   */
  enum MemoryConsumption
  {
    MINIMUM,
    LOW,
    MEDIUM,
    HIGH,
    AUTO
  };

  virtual ~CATPolyInterferenceOper();

  /**
   * Set the first data to be used by the operator.
   * To test only the first set against itself, set the second operand
   * to NULL.
   * @param data1 first set of data.
   */
  virtual void SetFirstOperand(CATBVHTreeSet * data1);

  /**
   * Set the seond set of data to be used by the operator.
   * If not set or set to NULL, the operator will test the first set
   * against itself.
   * @param data2 second set of data.
   */
  virtual void SetSecondOperand(CATBVHTreeSet * data2);

  /**
   * Launch the computation of inteferences between the two trees.
   * @return S_OK if the computation was successfull. In this case the interferences can be retrieved with the
   *              GetResult function.
   */
  virtual HRESULT Run() = 0;

  /**
   * After a call to Run, retrieve the interferences between the 2 trees.
   * @return NULL if Run as not yet been called succesfully, the list of interferences otherwise.
   *         The resulting list is a CATPolyRefCounted and must released afterwards.
   */
  virtual CATPolyInterferenceList * GetResult();

  /**
   * After a call to Run, retrieve all the warnings that has been found between the
   * objects of the first operand.
   * @return NULL if Run as not yet been called successfully, the list of warnings otherwise.
   *         The resulting list is a CATPolyRefCounted and must released afterwards.
   */
  virtual CATPolyInterfWarningList * GetWarnings();

  /**
   * Add a filter between the input objects couples.
   * Each time a pair of input objects might be interfering
   * (ie their bounding volumes is interfering) the filters are called.
   * If one of them return TRUE, then the interference computation between the
   * objects is cancelled.
   */
  void AddInputCoupleFilter(CATIPolyInterfInputCoupleFilter * filter);

  /**
   * Remove a filter previously added by AddRepCoupleFilter.
   */
  void RemoveInputCoupleFilter(CATIPolyInterfInputCoupleFilter * filter);

  /**
   * @deprecated.
   * Use AddInputCoupleFilter instead.
   */
  void AddRepCoupleFilter(CATIPolyInterfInputCoupleFilter * filter);

  /**
   * @deprecated
   * Use RemoveInputCoupleFilter instead.
   */
  void RemoveRepCoupleFilter(CATIPolyInterfInputCoupleFilter * filter);

  /**
   * Specify whether the operator compute all the interferences or stops when the first is found.
   * @param stopMode if TRUE the operator will stop when the first interference is found. If FALSE
   *                 it will compute all of them.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT StopAtFirstInterference(CATBoolean stopMode);

  /**
   * @return Whether the operator stops when the first interference is found or not.
   */
  virtual CATBoolean IsStoppingAtFirstInterference() const;

  /**
   * Specify the granularity level of the operator.
   * @param granularity If GEOMETRY all local interferences are computed.
   *                    If PRODUCT local interferences are gathered in a single larger one for each object couple.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT SetGranularityLevel(GranularityLevel granularity);

  /**
   * @return The granularity level of the operator.
   */
  virtual GranularityLevel GetGranularityLevel() const;

  /**
   * Specify whether the operator detects inclusion between input objects or not.
   * @param inclusionMode if TRUE the operator will test whether the input objects are included in each others or not.
   *                      If FALSE it won't check.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT DetectInclusion(CATBoolean inclusionMode);

  /**
   * @return Whether the operator detects inclusion between input objects.
   */
  virtual CATBoolean IsDetectingInclusion() const;

  /**
   * Specify whether the geometric results stored in the interferences are complete or if only a part of them is computed.
   * For example, if the partial mode is enabled, only the first intersection is stored in case of clash or the first
   * two triangles in contact in case of contact.
   * Enabling this mode reduce memory consumption and also in some cases computation time.
   * @param inclusionMode if TRUE the operator will compute only the first primitives for each geometric result.
   *                      If FALSE it compute the whole geometric result.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT EnablePartialGeometricResults(CATBoolean partialMode);

  /**
   * @return Whether the operator is only computing the first primitives for each interference (TRUE)
   *         or the whole geomtric results (FALSE).
   */
  virtual CATBoolean IsPartialGeometricResultsEnabled() const;

  /**
   * Specify an indicator on the amount of memory that will be used during interference computation.
   * Allowing the operator to use more memory will result in better performances.
   * @param memoryHint Mode to use. Default is MINIMUM.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT SetMemoryConsumptionHint(MemoryConsumption memoryHint);

  /**
   * @return Indicator about memory consumption currently used by the operator.
   */
  virtual MemoryConsumption GetMemoryConsumptionHint() const;
  /**
   * @return the actual hint that has been used in the last call to Run method.
   */
  virtual MemoryConsumption GetGuessedMemoryConsumptionHint() const;


  /**
   * To be used with SetMaximalNumberOfThreads to let the operator
   * guess the best number of thread to use.
   */
  static const int AUTO_NBTHREADS;

  /**
   * Specify the maximum number of simultaneous threads the operator may use.
   * The specified number of threads is only an indicator. Only a part of
   * it may be actually used. However, it is guaranteed that there can't be more
   * than nbThreads running simultaneously during the Run of the operator.
   * Basically, to get the best performances nbThread should be equal to the number of
   * cores available in the computer. However, this number can be reduced if parallel tasks
   * have to be run during the operator computation.
   * It's also possible to let the operator choose the right number of threads by using setting
   * AUTO_NBTHREADS.
   * @param nbThreads Maximum number of threads to use or AUTO_NBTHREADS to let the operator choose.
   *                  Default is AUTO_NBTHREADS.
   * @return S_OK if the mode is successfully set, E_NOTIMPL if the mode can not be taken into account
   *         because the functionnality is not yet implemented, E_FAIL otherwise.
   */
  virtual HRESULT SetMaximalNumberOfThreads(int nbThreads);

  /**
   * @return Maximal number of threads that can be used simultaneously during the operator run.
   */
  virtual int GetMaximalNumberOfThreads() const;

  /**
   * Set the full result mode (default is off)
   * In each interference, you will get a CATMapOfBodyFaceToMesh that contains all the interfering triangles inside their surfaces and bodies.
   */
  virtual HRESULT SetFullResultMode(CATBoolean iFullResult);

  /**
   * Get the full result mode (default is off)
   */
  virtual CATBoolean GetFullResultMode();


  /**
   * @nodoc
   * For debug, get the number of intersections found during the last call to Run.
   */
  virtual int GetNbInputBVIntersections();

  // Internal only!!!!!
  virtual void SetCacheVisitor(CATPolyInterfDecoratedObjectsVisitor * backDoor);

  virtual CATPolyInterferenceOper* Clone() const;

  /**
   *	@brief Get the tolerance associated with the clash operator
   */
  const CATTolerance& GetTolerance() const;


  /**
   * Debug
   */
  void SetObserver(CATPolyInterferenceOperObserver * o);

  /** Debug */
  virtual CATPolyInterfClashOper *                 CastToClashOper()                 {return 0;}
  /** Debug */
  virtual CATPolyInterfClashContactOper *          CastToClashContactOper()          {return 0;}
  /** Debug */
  virtual CATPolyInterfClashContactClearanceOper * CastToClashContactClearanceOper() {return 0;}
  /** Debug */
  virtual CATPolyInterfClashClearanceOper *        CastToClashClearanceOper()        {return 0;}
  /** Debug */
  virtual CATPolyInterfCollisionOper *             CastToCollisionOper()             {return 0;}
  /** Debug */
  virtual CATPolyInterfACMOper *                   CastToACMOper()                   {return 0;}
  /** Debug */
  virtual OOCPCInterferenceOper *                  CastToOOCPointCloudOper()         {return 0;}

  /**
   * Get first operand.
   */
  CATBVHTreeSet* GetFirstOperand();

  /**
   * Then the second.
   */
  CATBVHTreeSet* GetSecondOperand();

protected:

  /**
   * Not to be used as is.
   */
  CATPolyInterferenceOper(const CATTolerance & iTol);

  CATPolyInterferenceOper( const CATPolyInterferenceOper& iOther );

  /**
   * Set the whole interference list using one function.
   * @param interfs list of result interferences.
   */
  void SetInterferenceList(CATPolyInterferenceList * interfs);

  /**
   * Get the raw pointer on the result.
   */
  CATPolyInterferenceList * GetResultList();

  // Set the list of warnings
  void SetWarnings(CATPolyInterfWarningList * warList);

  /**
   * Run the operator with an already created descent
   */
  HRESULT Descent(CATPolyInterferenceRecorder & recorder, double tolerance);

  /**
   * Useless, should be removed.
   * However, surpisingly, removing it breaks linkage of some application frameworks....
   */
  virtual CATIPolyInterfDecoPolyBodyFactory * CreateFactory() const;

  /**
   * Fill the list with all the filters
   */
   void GetInputCoupleFilterList(CATListPV & filters) const;

   /**
   * Try to guess what would be the best memory consumption mode, depending on the
   * currently available memory on the computer. We will try to avoid pagination
   * at all cost. If plenty of memory is available then LOW, MEDIUM, etc... modes
   * may be returned. Note that more consuming modes are generaly much faster than
   * MINIMUM.
   * @return S_OK if we successfully guessed what would be best, E_NOTIMPL otherwise.
   *         In case of failure, oMemoryHint falls back to MINIMUM.
   */
  virtual HRESULT GuessBestMemoryConsumptionHint(MemoryConsumption & oMemoryHint) const;

  /**
   * Returns the actual number of threads that can be launched.
   */
  int GetRealNumberOfThreads() const;
  /**
   * To be called for each call to GetRealNumberOfThreads
   */
  void ReleaseAcquiredThreads();

  /**
   * @return operator name. Usefull for debug.
   */
  virtual const char * GetOperatorName() const;

protected:
  // Debug:
  CATPolyInterferenceOperObserver * m_Obs;
  // Tolerance to be used in descendants
  const CATTolerance & m_Tol;

  // It de-activate multi thread if activated
  CATBoolean _bIsComputingIntersectionVolumes;

private:

  //--------------------------------------------------------------------
  CATBoolean _bIsStoppingAtFirstInterference;
  enum GranularityLevel _eGranularity;
  CATBoolean _bIsDetectingInclusion;
  CATBoolean _bPartialModeEnabled;
  MemoryConsumption _eMemoryHint;
  MemoryConsumption _eGuessedMemoryHint;
  int _iNbMaxthreads;

  CATPolyInterferenceList * _pResult;
  CATPolyInterfWarningList * _pWarnings;

  CATBVHTreeSet * _pData1;
  CATBVHTreeSet * _pData2;

  CATPolyInterfDecoratedObjectsVisitor * _pBackDoor;

  CATListPV _oCoupleFilters; // Keep a trace of them for the copy constructor
  CATPolyBodyTreeSetDescent _oTreeSetDescent;
  int _nbMultiThreadAuthorizations;
  //--------------------------------------------------------------------

  DEBUGCLASHOBJECTTRACE(m_traces);


protected:

  CATPolyInterferenceRecorder* m_Recorder;
  mutable CATBoolean m_ScopedRecorder;

  CATBoolean _bFullResult;
};

#endif /* CATPolyInterferenceOper_h */
