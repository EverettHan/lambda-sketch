// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyOverlayDebug.h
//
//===================================================================
// Aug 2014 : NDO : Creation
// Nov 2021 : F1Z : Full review. Factorisation & genericity
//===================================================================
#ifndef CATPolyBodyOverlayDebug_H
#define CATPolyBodyOverlayDebug_H

#include "CATPolyBodyOverlayDebugEnum.h"
#include "PolyBodyBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"
#include "CATLISTV_CATMathPoint.h"

#include <string>
#include <map>

class CATPolyBody;


/**
Class handling various callbacks and observers for the debugging of an overlay.
*/
class ExportedByPolyBodyBoolean CATPolyBodyOverlayDebug
{
public:

  /**
   * Returns the level of debugging.  If it returns 0, debugging is not activated.
   * The level of debugging can be set with the environment variable:
   * <code>
   *   set DebugCATPolyBodyOverlay = 1
   * </code>
   * <ul>
   *   <li> 1: Debug of the overlay is activated. Report of internal failures.
   *   <li> 2: Activate additional checks of the overlay during the processing steps.
   * </ul>
   */
  static unsigned int Level ();

public:

  /**
   * Constructs a Debug instance at a given level.
   */
  CATPolyBodyOverlayDebug ();

  ~CATPolyBodyOverlayDebug ();

public:

/** @name Callbacks
@{ */

  // any callback needs to implement GetName
  // You can add any new callback this way, even not visible from this class

  template<typename CallbackType>
  CallbackType * GetCallback()
  {
    if (_callbacks.size() && _callbacks.find(CallbackType::GetName())!=_callbacks.end())
      return reinterpret_cast<CallbackType *>(_callbacks[CallbackType::GetName()]);
    else
      return nullptr;
  };

  template<typename CallbackType>
  void SetCallback(CallbackType * iCB)
  {
    _callbacks[CallbackType::GetName()] = iCB;
  }

  /**
   * Interface defining the callbacks made during the varions stages
   * of an overlay.
   */
  class Callbacks;
  class OverlapObserver;
  class WNPropagateObserver;

/** @} */

private:

  std::map<std::string, void*> _callbacks;
};


class ExportedByPolyBodyBoolean CATPolyBodyOverlayDebug::Callbacks
{
protected:

  virtual ~Callbacks() {}


public:
  inline static std::string GetName() { return "StageCallBack"; };

  /**
   * Turns on or off the construction of the body operands during processing.
   */
  virtual CATBoolean DoBuildOperandBodies(Poly::Overlay::Debug::OperationType opType,
                                          unsigned int Stage)
  {
    return FALSE;
  }

  /**
   * Call made each time a CATPolyBody is reconstructed during processing
   * for one of the N operands.
   * @param index
   *   Index of the operand: 0..N
   */
  virtual void OverlayOperandBody(unsigned int index, CATPolyBody & iOperand) {}

public:

  /**
   * Turns on or off the construction of the overlay points during processing.
   */
  virtual CATBoolean DoBuildPoints(Poly::Overlay::Debug::OperationType opType,
                                   unsigned int Stage)
  {
    return FALSE;
  }

  /**
   * Call made with the list of overlay points on one of the N operands.
   * @param index
   *   Index of the operand: 0..N
   */
  virtual void OverlayPoints(unsigned int index, CATLISTV(CATMathPoint) & points) {};

public:

  /**
   * Turns on or off the construction of the overlay segments during processing.
   */
  virtual CATBoolean DoBuildSegments(Poly::Overlay::Debug::OperationType opType,
                                     unsigned int Stage)
  {
    return FALSE;
  }

  /**
   * Call made with the list of pair of overlay points for each segment on one of the N operands.
   * @param index
   *   Index of the operand: 0..N
   */
  virtual void OverlaySegments(unsigned int index, CATLISTV(CATMathPoint) & points) {};

public:

  /**
   * Turns on or off the construction of the segment bodies during processing.
   */
  virtual CATBoolean DoBuildSegmentBodies(Poly::Overlay::Debug::OperationType opType,
                                          unsigned int Stage)
  {
    return FALSE;
  }

  /**
   * Call made each time a body is constructed by concatenation of all the overlay segments for
   * a specific operand.
   * @param index
   *   Index of the operand: 0..N
   */
  virtual void OverlaySegmentBody(unsigned int index, CATPolyBody & body) {};

public:

  /**
   * Turns on or off the construction of the patch bodies during processing.
   */
  virtual CATBoolean DoBuildPatchBodies(Poly::Overlay::Debug::OperationType opType,
                                        unsigned int Stage)
  {
    return FALSE;
  }

  /**
   * Call made each time a body is constructed by concatenation of all the overlay patches for
   * a specific operand.
   * @param index
   *   Index of the operand: 0..N
   */
  virtual void OverlayPatchBody(unsigned int index, CATPolyBody & body) {};

public:

  /**
   * Call made at the end of processing for an overlay for a specific stage.
   */
  virtual void Done() {}

};

class CATPolyBodyOverlayDebug::OverlapObserver
{
protected:

  virtual ~OverlapObserver() {}

public:
  inline static std::string GetName() { return "OverlapObserver"; };

  virtual void StartOverlapping(double iOverlayingTolerance, double iReclassificationTolerance) {}

  /**
   * Call made when two overlapping regions of faces are identified.
   */
  virtual void Overlap(int iID, const CATMathPoint iTriangles[2][3]) {}
  virtual void DeactivateOverlap(int iID) {}

  virtual void EndOverlapping() {}
};

class CATPolyBodyOverlayDebug::WNPropagateObserver
{
protected:

  virtual ~WNPropagateObserver() {}

public:
  inline static std::string GetName() { return "WNPropagateObserver"; };
  /**
   * Call made when winding numbers are propagated around selected vertices.
   */
  virtual void PropagateAroundVertex(CATPolyBody & iVertexBody, unsigned int countVertex, HRESULT hr) {}

  /**
   * Call made when winding numbers are propagated around selected bars.
   */
  virtual void PropagateAroundBar(CATPolyBody & iBarBody, unsigned int countBar, HRESULT hr) {}

  /**
   * Call made with a CATPolyBody constructed from the overlay for a set of winding number pairs
   */
  virtual void WNBody(CATPolyBody & iBody, const int wnLHS[2], const int wnRHS[2]) {}

};

#endif
