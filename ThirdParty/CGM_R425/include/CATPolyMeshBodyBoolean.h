// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshBodyBoolean.h
//
//===================================================================
// September 2016 Creation: ndo
//===================================================================
#ifndef CATPolyMeshBodyBoolean_H
#define CATPolyMeshBodyBoolean_H

#include "PolyBodyBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"

#include "CATPolyBoolean.h"
#include "CATPolyBodyBooleanOptions.h"
#include "CATPolyBodyBoolean.h"

class CATIPolyMesh;
class CATPolyBody;
class CATPolyCell;
class CATMathTransformation;
class CATPolyBodyBooleanOptions;


/**
 * Boolean operator for solid operands of CATIPolyMesh type.
 * It performs the union, intersection or subtraction between two solid mesh operands.
 * The result is returned in a new CATPolyBody or CATIPolyMesh instance.
 *
 */
class ExportedByPolyBodyBoolean CATPolyMeshBodyBoolean
{

public:

  /**
   * Constructor of the boolean operator.
   * @param iDTolerance
   *   Distance tolerance (contact).
   *   Topological cells and sub-elements closer than this distance will be considered coincident and merged.
   *   This parameter is used only in a tolerant mode.
   */
  CATPolyMeshBodyBoolean (const double iDTolerance = 0);

  ~CATPolyMeshBodyBoolean ();

  /**
   * Sets the operator options.
   */
  void SetOptions (const CATPolyBodyBooleanOptions& iOptions);

public:

  /**
   * Runs the operator. 
   * This method must be called prior to calls to the GetResult () method.
   */
  HRESULT Run (const CATIPolyMesh& iMesh0, const CATMathTransformation* iPosition0, 
               const CATIPolyMesh& iMesh1, const CATMathTransformation* iPosition1);

  /**
   * Returns the result of the boolean operation after a successfull call to Run ().
   * This method can be called several times to perform distinct boolean operations between the operands.
   * Upon successful completion of the call, it creates a new instance of a CATPolyBody representing the boolean result.
   * 
   * @param oResult
   *   The resulting CATPolyBody.
   *   This instance must be released.
   * @param iOperation
   *   Specifies the boolean operation.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> A valid result (may be null for an empty body) has been constructed.
   *   <li> <tt>S_FALSE</tt> A result cannot be constructed.
   *   <li> <tt>E_FAIL</tt> An error occurred.
   * </ul>
   */
  HRESULT GetResult (CATPolyBody*& oResult,
                     const CATPolyBoolean::BooleanOperation iOperation);

  HRESULT GetResult (CATIPolyMesh*& oMesh,
                     const CATPolyBoolean::BooleanOperation iOperation);

private:

  CATPolyBodyBooleanOptions _Options;
  CATPolyBodyBoolean _Operator;

  // Backup.
  const CATPolyBody* _Operand[2];
  const CATMathTransformation* _Position[2];

};

#endif
