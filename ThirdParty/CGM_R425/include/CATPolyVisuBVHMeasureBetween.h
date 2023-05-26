//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Measure Between Solver visualization interface. Manage the input of
// each operator in the measure between solver that use Bounding
// Volume Hierarchies (BVH).
// Proposes an interface between Visualization data and the
// measure between solver operators on two CATBVHTree.
//
//=============================================================================
// 2009-10-16   XXC: New.
// 2015-05-06   JXO: CATPolyBody operands, see IR 357262
// 2018-06-06   JXO: CATSoftwareConfiguration support with different nb of triangles per node
//=============================================================================

#ifndef CATPolyVisuBVHMeasureBetween_h
#define CATPolyVisuBVHMeasureBetween_h

#include "PolyVisuMeasureBetween.h"
#include "CATSysBoolean.h"
#include "CATBVHTreeRepBuilder.h"
#include "CATPolyBodyBVHTreeBuilder.h"
#include "CATPolyBVHMeasureBetween.h"

class CATBVHTree;
class CATRep;
class CATRepWeakRef;
class CAT4x4Matrix;
class CATPolyBVHTreeFilterHiddenAndPrimitive;
class CATMathPoint;
class CATPolyBody;
class CATModelForSubElement;
class CATSoftwareConfiguration;
class CATPolyVisuBVHMeasureBetweenObserver;

class ExportedByPolyhedralMeasureBetween CATPolyVisuBVHMeasureBetween
{
 public:
  typedef enum {
    HighestLevelType,
    EveryTypes,
    VertexOnly,
    CurvesOnly,
    SurfacesOnly,
    VolumesOnly,
  } SubElementType;

 public:
  CATPolyVisuBVHMeasureBetween();

  virtual ~CATPolyVisuBVHMeasureBetween();

  /** Sets an observer to the solver. Only one observer can be
   * defined. Succeed if no observer has been defined previously,
   * fails if an observer has been already defined. Set a null
   * observer to undefine the current observer.
   */
  HRESULT SetObserver(CATPolyVisuBVHMeasureBetweenObserver * ioObserver);

  /** Gets the observer already set to the operator. Returns a null
   * pointer if no observer as been defined.
   */
  CATPolyVisuBVHMeasureBetweenObserver * GetObserver();

  /** Defines the two objects to use for the distance computation.
   *@param iRepPath1: Path to a visualization representation of the first 3D object.
   *@param iRepPath2: Path to a visualization representation of the first 3D object.
   *@param iSubType1: type of sub-element to consider in the first
   *operand amongst Surfaces, curves and vertices. Can be one of them
   *or everything. Surfaces only by default.
   *@param iSubType2: type of sub-element to consider in the second
   *operand amongst Surfaces, curves and vertices. Can be one of them
   *or everything. Surfaces only by default.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  virtual HRESULT SetOperands(CATRepPath * iRepPath1,
                              CATRepPath * iRepPath2,
                              SubElementType iSubType1 = HighestLevelType,
                              SubElementType iSubType2 = HighestLevelType);

  /** Defines the two objects to use for the distance computation.
   *@param iRep1: visualization representation of the first 3D object.
   *@param iPosition1: position to use for the first 3D object.
   *@param iRep2: visualization representation of the first 3D object.
   *@param iPosition2: position to use for the second 3D object.
   *@param iSubType1: type of sub-element to consider in the first
   *operand amongst Surfaces, curves and vertices. Can be one of them
   *or everything. Surfaces only by default.
   *@param iSubType2: type of sub-element to consider in the second
   *operand amongst Surfaces, curves and vertices. Can be one of them
   *or everything. Surfaces only by default.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  virtual HRESULT SetOperands(CATRep * iRep1, CAT4x4Matrix * iPosition1,
                              CATRep * iRep2, CAT4x4Matrix * iPosition2,
                              SubElementType iSubType1 = HighestLevelType,
                              SubElementType iSubType2 = HighestLevelType);

  virtual HRESULT SetFirstOperand(CATRepPath * iRepPath,
                                  SubElementType iSubType = HighestLevelType);

  virtual HRESULT SetFirstOperand(CATRep * iRep, CAT4x4Matrix * iPosition,
                                  SubElementType iSubType = HighestLevelType);

  virtual HRESULT SetFirstOperand(CATModelForSubElement * iSubElement, CAT4x4Matrix * iPosition,
                                  SubElementType iSubType = HighestLevelType);

  virtual HRESULT SetSecondOperand(CATRepPath * iRepPath,
                                   SubElementType iSubType = HighestLevelType);

  virtual HRESULT SetSecondOperand(CATRep * iRep, CAT4x4Matrix * iPosition,
                                   SubElementType iSubType = HighestLevelType);

  virtual HRESULT SetSecondOperand(CATModelForSubElement * iSubElement, CAT4x4Matrix * iPosition,
                                   SubElementType iSubType = HighestLevelType);

  /**
   * Set the first operand as a CATPolyBody
   * @param iPoly can be released after this call
   */
  virtual HRESULT SetFirstOperand(CATPolyBody * iPoly, const CATMathTransformation * iPos = 0,
                                  SubElementType iSubType = HighestLevelType);
  /**
   * Set the second operand as a CATPolyBody
   * @param iPoly can be released after this call
   */
  virtual HRESULT SetSecondOperand(CATPolyBody * iPoly, const CATMathTransformation * iPos = 0,
                                   SubElementType iSubType = HighestLevelType);

  /**
   * Set the first operand as a list of CATPolyBody's
   * iPolyBodies and (optional) iPositions (if not null) should be the same size. Note that some positions (CATMathTransformation)
   * may however be null.
   * Positions are duplicated and can be deleted after the call to AddSetOfPolyBodies.
   * Given Polybodies can be released after this call.
   */
  virtual HRESULT SetFirstOperand(CATListPV & iPolyBodies,
                                  CATListPV * iPositions = 0,
                                  SubElementType iSubType = HighestLevelType);
  /**
   * Set the second operand as a list of CATPolyBody's
   * iPolyBodies and (optional) iPositions (if not null) should be the same size. Note that some positions (CATMathTransformation)
   * may however be null.
   * Positions are duplicated and can be deleted after the call to AddSetOfPolyBodies.
   * Given Polybodies can be released after this call.
   */
  virtual HRESULT SetSecondOperand(CATListPV & iPolyBodies,
                                   CATListPV * iPositions = 0,
                                   SubElementType iSubType = HighestLevelType);

  /** Indicates if hidden geometry (i.e. noshow attribute) have to be
   *  taken into account or not in the minimal distance
   *  computation. This parameter must be precised before the set of
   *  two operands. Default behaviour is to not filter hidden objects
   *  (FALSE).
   *@param iFilter: TRUE if hidden geometry must be ignored (filter
   *on), FALSE if it must be taken into account (filter off).
   */
  virtual void FilterHiddenGeometry(CATBoolean iFilter);

  /** Run the operator: compute the minimum distance between the two
   *  given objects, according to two optional positions.
   *@param iPosition1: position to apply to the first object.
   *@param iPosition2: position to apply to the second object.
   */
  virtual HRESULT Run(const CAT4x4Matrix * iPosition1 = NULL, const CAT4x4Matrix * iPosition2 = NULL);

  /** Force the freed of recorded data and refresh the operator to admit new operands.
   */
  virtual void Reboot();

  /**
   * Set a software configuration to take advantage of the last performances possible
   * If not set (default), there is no performances improvement.
   * If set, the improvement is available on R214, and R420 and upward.
   * Note that some result (points) may change, hence the versioning.
   */
  void SetSoftwareConfiguration(CATSoftwareConfiguration * iSoftwareConfiguration = 0);

  HRESULT GetResultSupportCells(CATCellId *& oCell1, CATCellId *& oCell2) const;

 private:
  HRESULT InitData(CATRepPath * iRepPath,
                   CATRep *& oRep, CATPolyBody *& oPolyBody,
                   CAT4x4Matrix & oPosition);
  void CleanOperands();
  static CATPolyVisuBVHMeasureBetween::SubElementType GetTypeFromRep(const CATRep & iRep, CATBoolean iFilterNoShow);
  static CATPolyVisuBVHMeasureBetween::SubElementType GetTypeFromPolyBody(const CATPolyBody & iPolyBody);
  static void GetEntityType(CATPolyVisuBVHMeasureBetween::SubElementType iSubType,
                            CATBVHTreeRepBuilder::EntityType & oTypeRep, CATPolyBodyBVHTreeBuilder::EntityType & oTypeBody);

 protected:
  CATPolyBVHMeasureBetween * _Operator;                              // The main measure between operator.
  CATPolyVisuBVHMeasureBetweenObserver * _Observer;                 // The observer, I suppose you guessed.
  CATBoolean _PreventOperandInclusion;                             //
 private:                                                         //
  CATPolyBVHTreeFilterHiddenAndPrimitive * _Filter1, * _Filter2; // Management of hidden objects and sub-element
  CATBVHTree * _Tree1, * _Tree2;                                // BVH trees
  CATRepWeakRef * _Operand1, * _Operand2;                      // Reps
  CATPolyBody * _PolyBody1, * _PolyBody2;                     // In case of subelements
  CATMathTransformation _Pos1, _Pos2;                        // Memory lifecycle for positions of subelements
  CATRepPath * _RepPath1, * _RepPath2;                      // To verify if one operand is not included in the other one
  CATBoolean _FilterNoShow;
  CATSoftwareConfiguration * m_config;
  int m_nbtrianglespernode;
};

#endif //CATPolyVisuBVHMeasureBetween_h
