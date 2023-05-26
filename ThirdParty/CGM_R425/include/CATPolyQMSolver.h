// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyQMSolver.h
//
//===================================================================
// January 2019  Creation JBS2
//===================================================================
#ifndef CATPolyQMSolver_H
#define CATPolyQMSolver_H

#include "PolyMathUtils.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"


/**
* Solver minimizing the n-dimensional quadric.
* The solver tries to find the point v minimizing the quadratic expression Q(v).
*/

class ExportedByPolyMathUtils CATPolyQMSolver
{
public:

  static CATPolyQMSolver*New(unsigned int posDimension, unsigned int nbDataLayers);
  ~CATPolyQMSolver();

public:

  inline void SetCoefficients(const double* q0, const double* q1);
  inline void SetLayerSize(unsigned int dataDimension, CATBoolean hasPos, unsigned int layer, unsigned int nbCoeffs);
  inline void SetCoefficientsData(const double q0[], const double q1[], unsigned int layer, unsigned int index);
  inline void SetCoefficientsDataPos(const double q0[], const double q1[], unsigned int layer, unsigned int index);
  inline void SetCoefficientsPos(const double q0[], const double q1[], unsigned int layer, unsigned int index);

  inline unsigned int GetDataDimension(unsigned int layer) const;

  /**
  * Finds the nD-point minimizing the quadric.
  */
  virtual HRESULT Solve(double *p, double *d) const = 0;

  /**
  * Computes the quadratic expression for the input nD-point.
  */
  virtual double Multiply(const double *p) const = 0;

  /**
   * Computes the quadratic expression for the input nD-point + normal.
   */
  virtual double Multiply(const double *p, const double n[3], unsigned int layer) const = 0;

  /**
   * Computes the quadratic expression for the input nD-point + normal. Normal length is fixed during computation to minimize result.
   */
  virtual double MultiplyMin(const double *p, const double n[3], unsigned int layer, unsigned int nf) const = 0;

  /**
  * Compute relative residual error of Ax-b = 0 values.
  */
  virtual  double RelativeResidualError(double *p) const = 0;

protected:
  static unsigned int getSymMatrixId(unsigned int i, unsigned int j);

protected:
  CATPolyQMSolver(int nbDataLayers);
  virtual double* GetData() = 0;
  virtual unsigned int GetPosDimension() const = 0;
  inline unsigned int GetCoefficientsSize() const;
  inline unsigned int GetCoefficientsDataSize(unsigned int layer) const;
  inline unsigned int GetCoefficientsDataPosSize(unsigned int layer) const;
  inline unsigned int GetCoefficientsPosSize(unsigned int layer) const;

protected:
  unsigned int* _DDimension;
  double** _CoefD;
  double** _CoefDP;
  double** _CoefP;
  const int _NbDataLayers;
};

inline void CATPolyQMSolver::SetCoefficients(const double* q0, const double* q1)
{
  double* data = GetData();
  for (int k = 0; k < GetCoefficientsSize(); k++)
    data[k] = q0[k] + q1[k];
}

void CATPolyQMSolver::SetLayerSize(unsigned int dataDimension, CATBoolean hasPos, unsigned int layer, unsigned int nbCoeffs)
{
  if (nbCoeffs > 0)
  {
    if (_DDimension)
    {
      _DDimension[layer] = dataDimension;
    }
    if (_CoefD && !_CoefD[layer])
    {
      const unsigned int dataSize = GetCoefficientsDataSize(layer);
      _CoefD[layer] = dataSize > 0 ? new double[nbCoeffs * dataSize] : 0;
    }
    if (_CoefDP && !_CoefDP[layer])
    {
      const unsigned int dataPosSize = GetCoefficientsDataPosSize(layer);
      _CoefDP[layer] = dataPosSize > 0 ? new double[nbCoeffs * dataPosSize] : 0;
    }
    if (hasPos && _CoefP && !_CoefP[layer])
    {
      const unsigned int posSize = GetCoefficientsPosSize(layer);
      _CoefP[layer] = posSize > 0 ? new double[nbCoeffs * posSize] : 0;
    }
  }
}

void CATPolyQMSolver::SetCoefficientsData(const double q0[], const double q1[], unsigned int layer, unsigned int index)
{
  const unsigned int dataSize = GetCoefficientsDataSize(layer);
  for (unsigned int i = index * dataSize; i < (index + 1) * dataSize; ++i)
  {
    _CoefD[layer][i] = q0[i] + q1[i];
  }
}

void CATPolyQMSolver::SetCoefficientsDataPos(const double q0[], const double q1[], unsigned int layer, unsigned int index)
{
  const unsigned int dataPosSize = GetCoefficientsDataPosSize(layer);
  for (unsigned int i = index * dataPosSize; i < (index + 1) * dataPosSize; ++i)
  {
    _CoefDP[layer][i] = q0[i] + q1[i];
  }
}

void CATPolyQMSolver::SetCoefficientsPos(const double q0[], const double q1[], unsigned int layer, unsigned int index)
{
  if (_CoefP && _CoefP[layer])
  {
    const unsigned int posSize = GetCoefficientsPosSize(layer);
    for (unsigned int i = index * posSize; i < (index + 1) * posSize; ++i)
    {
      _CoefP[layer][i] = q0[i] + q1[i];
    }
  }
}

unsigned int CATPolyQMSolver::GetDataDimension(unsigned int layer) const
{
  return _DDimension[layer];
}
inline unsigned int CATPolyQMSolver::GetCoefficientsSize() const
{
  const unsigned int P = GetPosDimension();
  return P * (P + 3) / 2 + 1; // Symmetric Matrix (P*P) + Vector (P) + Constant (1)
}
inline unsigned int CATPolyQMSolver::GetCoefficientsDataSize(unsigned int layer) const
{
  const unsigned int D = GetDataDimension(layer);
  return D * (D + 3) / 2; // Symmetric Matrix (D*D) + Vector (D);
}
inline unsigned int CATPolyQMSolver::GetCoefficientsDataPosSize(unsigned int layer) const
{
  const unsigned int P = GetPosDimension();
  const unsigned int D = GetDataDimension(layer);
  return D * P; // Matrix (D*P);
}
inline unsigned int CATPolyQMSolver::GetCoefficientsPosSize(unsigned int layer) const
{
  const unsigned int P = GetPosDimension();
  return  P * (P + 3) / 2 + 1; // Symmetrix Matrix (P*P) + Vector (P) + Constant (1)
}
#endif
