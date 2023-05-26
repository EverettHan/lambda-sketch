#pragma once

// Polyhedral Objects
#include "CATPolyBody.h"
#include "CATPolyBodyUnaryObserver.h"

// Polyhedral Body Operators
#include "PolyBodySweptAndThickness.h"


class ExportedByPolyBodySweptAndThickness CATPolyBodyThicknessOperator
{
public:

  CATPolyBodyThicknessOperator();
  ~CATPolyBodyThicknessOperator();

  /**
   * Set the Thickness values to apply.
   *
   * @param iThicknessValue1 First Thickness value, which is the offset
   *                         applied in the direction of the surface
   *                         normals. Can be any value.
   * @param iThicknessValue2 First Thickness value, which is the offset
   *                         applied in the opposite direction of the
   *                         surface normals. Can be any value.
   */
  void SetThicknessValues(double iThicknessValue1,
                          double iThicknessValue2);
  /**
   * Get the Thickness values
   */
  void GetThicknessValues(double& iThicknessValue1,
                          double& iThicknessValue2);

  /**
   * Prepro to clean the input from invalide topology (true by default)
   */
  void CleanInvalidityInput(bool clean = true);

  /**
   * Set the output poly body.
   * If not provided, a new one will be created.
   */
  void SetOutputPolyBody(CATPolyBody* iOutputPolyBody);
  /**
   * If set to true, an offset will also be made at the border perpendicular to the normal
   */
  void SetOrthogonalBorderShift(bool iDoOrthogonalOffsetShift);

  // Generic observer are not enough for geometry information in this context.
  class AdvancedGeoObserver
  {
  public:
    virtual void BeginFace() {};
    virtual void ReactToAddTriangle(int iIdT, CATPolyFace * iFromFace, int idFromT, int iOrientation) {};
    virtual void EndFace(CATPolyFace * iFace, CATPolyFace * iFromFace) {};

    virtual void BeginRubanFace(CATPolyEdge & iFromEdge) {};
    virtual void ReactToAddRubanTriangle(int iIdT, CATPolyEdge & iFromEdge, int idP0, int iSVT0, int iSVT1) {};
    virtual void EndRubanFace(CATPolyFace * iFace, CATPolyEdge & iFromEdge) {};
  };

  /**
 * Compute the poly body thickness result
 * @param iPolyBody
 * The surfacic model to compute the offset
 * @param iObserver
 * Observer on the operator. Useful to update the CATPolyBodyVisLayer for instance.
 */
  HRESULT Run(const CATPolyBody& iPolyBody,
              CATPolyBodyUnaryObserver* iObserver = nullptr,
              AdvancedGeoObserver * iAdvObs = nullptr);

  /**
   * Compute the poly body thickness result
   * @param iPolyBody
   * The surfacic model to compute the offset
   * @param iTransfo
   * Apply iTransfo on the result
   * @param iObserver
   * Observer on the operator. Useful to update the CATPolyBodyVisLayer for instance.
   */
  HRESULT Run(const CATPolyBody & iPolyBody,
              const CATMathTransformation * iTransfo = nullptr,
              CATPolyBodyUnaryObserver* iObserver=nullptr,
              AdvancedGeoObserver * iAdvObs = nullptr);

  /**
   * Return the result.
   * An AddRef is performed inside the method.
   */
  CATPolyBody* GetResult();

private:
  CATPolyBody* _outputPolyBody;
  bool _doOrthoShift;
  bool _cleanInput;

  double _thickness[2];
};
