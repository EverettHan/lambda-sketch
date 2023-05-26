#pragma once

// Polyhedral Objects
#include "CATPolyBody.h"
#include "CATPolyBodyUnaryObserver.h"

// Polyhedral Body Operators
#include "PolyBodySweptAndThickness.h"


class ExportedByPolyBodySweptAndThickness CATPolyBodyOffsetOperator
{
public:

  CATPolyBodyOffsetOperator();
  ~CATPolyBodyOffsetOperator();

  /**
   * Set the offset values to apply.
   *
   * @param iOffsetValue value, which is the offset
   *                     applied in the direction of the surface
   *                     normals. Can be any value.
   */
  void SetOffsetValue(double iOffsetValue);
  /**
   * Get the offset values
   */
  double GetOffsetValue() const;

  /**
   * Set the output poly body.
   * If not provided, a new one will be created.
   */
  void SetOutputPolyBody(CATPolyBody* iOutputPolyBody);

  /**
 * Compute the poly body thickness result
 * @param iPolyBody
 * The surfacic model to compute the offset
 * @param iObserver
 * Observer on the operator. Useful to update the CATPolyBodyVisLayer for instance.
 */
  HRESULT Run(const CATPolyBody& iPolyBody,
              CATPolyBodyUnaryObserver* iObserver = nullptr);

  /**
   * Compute the poly body thickness result
   * @param iPolyBody
   * The surfacic model to compute the offset
   * @param iTransfo
   * Apply iTransfo on the result
   * @param iObserver
   * Observer on the operator. Useful to update the CATPolyBodyVisLayer for instance.
   */
  HRESULT Run(const CATPolyBody& iPolyBody,
              const CATMathTransformation* iTransfo = nullptr,
              CATPolyBodyUnaryObserver* iObserver = nullptr);

  /**
   * Return the result.
   * An AddRef is performed inside the method.
   */
  CATPolyBody* GetResult();

private:
  CATPolyBody* _outputPolyBody;

  double _offsetValue;
};
