// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyNaryCombine.h
// 
// Compute the union between N operands.
//
//===================================================================
// Fev 2022 : F1Z : Creation
//===================================================================
#pragma once

// PolyhedralBodyOperators
#include "PolyBodyBoolean.h"
#include "CATPolyBodyOverlayOptions.h"

class CATProgressCallback;
class CATMathTransformation;
class CATPolyBody;
class CATPolyBodyNaryCombineImpl;
class CATPolyBodyNaryObserver;

class ExportedByPolyBodyBoolean CATPolyBodyNaryCombine
{
public:
  CATPolyBodyNaryCombine();
  ~CATPolyBodyNaryCombine();

  class Options;

  /**
   * Sets the operator options.
   */
  void SetOptions(const Options & iOptions);
  void SetOptions(const CATPolyBodyOverlayOptions & iOptions);
  void SetObserver(CATPolyBodyNaryObserver * iObserver);
  void SetProgressCallback(CATProgressCallback * iProgress);
  void SetSurfacicMode(bool surfacicMode = true);

  /**
 * Adds an operand to the operator.
 * Identifying tags must be different among all operands.
 */
  void AddOperand(const CATPolyBody & iOperand, const CATMathTransformation * iPosition, const int iTag);

  /**
   * Adds a CATPolyBody operand to the operator.
   * @see AddOperand
   */
  void AddPolyBody(const CATPolyBody & iOperand, const CATMathTransformation * iPosition);

public:

  /**
   * Runs the operator between all given CATPolyBody's through AddPolyBody method.
   * This method must be called prior to a call to the GetResult () method.
   */
  HRESULT Run();

  /**
   * Gets the joined operands after a successfull call to Run ().
   * Upon successful completion of the call, it creates a new instance of a CATPolyBody representing the join result.
   *
   * @param oResult
   *   The resulting CATPolyBody.
   *   This instance must be released.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A valid result (may be null for an empty body) has been constructed.
   *   <li> <tt>S_FALSE</tt> A result cannot be constructed.
   *   <li> <tt>E_FAIL</tt> An error occurred.
   * </ul>
   */
  HRESULT GetResult(CATPolyBody *& oResult);

private:

  CATPolyBodyNaryCombineImpl * _Operator;
};

class  ExportedByPolyBodyBoolean CATPolyBodyNaryCombine::Options : public CATPolyBodyOverlayOptions
{
public:
  Options();
  Options(const Options &);
  Options(const CATPolyBodyOverlayOptions &);
  Options & operator=(const Options &);

public:
  void SetKeepExternalSurfaces(bool keepExternalSurfaces = true);
  bool DoKeepExternalSurfaces() const;

private:
  bool _keepExternalSurfaces;
};
