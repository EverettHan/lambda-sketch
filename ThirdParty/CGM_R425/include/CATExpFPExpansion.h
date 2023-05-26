#ifndef CATExpFPExpansion_H
#define CATExpFPExpansion_H

#include "CATMathExactPredicates.h"
#include "CATExpEnums.h"

#include <memory>
#include <cstring>
#include <algorithm>
#include <cmath>

/*
 * A double (p = 53), is represented as :
 * u = M_u 2^{e_u - p + 1} with M_u an integer in [2^{p-1}, 2^p]
 * 
 * We denote unit in the last place : ulp(u) = 2^{e_u - p + 1}
 * 
 * CATExpFPExpansion represents a P-nonoverlaping expansion : x = Sum(ui) with |u_i| <= (2^p - 1) / 2^p ulp(u_{i-1})
 */

class CATExpFPExpansion final
{
public:
  CATExpFPExpansion() = default;
  ExportedByCATMathExactPredicates explicit CATExpFPExpansion(double x);

  ExportedByCATMathExactPredicates CATExpFPExpansion(CATExpFPExpansion const&) = default;
  ExportedByCATMathExactPredicates CATExpFPExpansion(CATExpFPExpansion &&) = default;
  ExportedByCATMathExactPredicates CATExpFPExpansion& operator=(CATExpFPExpansion const&) = default;
  ExportedByCATMathExactPredicates CATExpFPExpansion& operator=(CATExpFPExpansion &&) = default;

  ExportedByCATMathExactPredicates ~CATExpFPExpansion() = default;

  double const& operator[](int i) const;

  int Size() const;

  template<int d = 0>
  double Estimate() const;

  CATExpSign_t Sign() const;

  double LowerBound() const;
  double UpperBound() const;

  ExportedByCATMathExactPredicates void SwapSign();

  ExportedByCATMathExactPredicates static CATExpFPExpansion Sum(double x, double y);
  ExportedByCATMathExactPredicates static CATExpFPExpansion Sub(double x, double y);
  ExportedByCATMathExactPredicates static CATExpFPExpansion Mult(double x, double y);

  ExportedByCATMathExactPredicates friend CATExpFPExpansion operator+(CATExpFPExpansion const& x, CATExpFPExpansion const& y);
  ExportedByCATMathExactPredicates friend CATExpFPExpansion operator-(CATExpFPExpansion const& x, CATExpFPExpansion y);
  ExportedByCATMathExactPredicates friend CATExpFPExpansion operator+(double x, CATExpFPExpansion const& y);
  ExportedByCATMathExactPredicates friend CATExpFPExpansion operator+(CATExpFPExpansion const& x, double y);
  ExportedByCATMathExactPredicates friend CATExpFPExpansion operator*(double x, CATExpFPExpansion const& y);
  ExportedByCATMathExactPredicates friend CATExpFPExpansion operator*(CATExpFPExpansion const& x, double y);
  ExportedByCATMathExactPredicates friend CATExpFPExpansion operator*(CATExpFPExpansion const& x, CATExpFPExpansion const& y);
  ExportedByCATMathExactPredicates friend CATExpFPExpansion operator-(CATExpFPExpansion x);
  ExportedByCATMathExactPredicates CATExpFPExpansion& operator+=(CATExpFPExpansion const& x);
  ExportedByCATMathExactPredicates CATExpFPExpansion& operator-=(CATExpFPExpansion x);
  
  ExportedByCATMathExactPredicates CATExpFPExpansion Abs() const;
  CATExpFPExpansion Square() const;

  /*
   * Assume that a != 0.
   * Compute FP expansion of 1/a of length 2^d with error lower than 2^{-2^d (p - 3) - 1} / |a|
   */
  ExportedByCATMathExactPredicates CATExpFPExpansion Inverse(int d) const;

  /*
   * Compute q = x * z with z = y.Inverse<d>(), x = this
   * |x/y - q| = |x/y - x*z| = |x| |1/y - z| <= |x| / |y| 2^{-2^d (p - 3) - 1}
   *           x0 + ...        x0   1 + x1/x0 + ...       x0  1 + 2^{-p+1} + 2^{2(-p+1)} + ....     2^{p-2}     x0
   * |x/y| = | ________  | = | __ * _______________ | <= |__| _________________________________ <= __________  |__|
   *           y0 + ....       y0   1 + y1/y0 + ...       y0  1 - 2^{-p+1} - 2^{2(-p+1)} - ....    2^{p-2} - 1  y0
   * 
   * So |x/y - q| <= 2^{p-2} / ((2^{p-2} - 1) 2^{-2^d (p - 3) - 1}) |x0/y0|
   */
  CATExpFPExpansion Quotient(int d, CATExpFPExpansion const& y) const;

  /*
   * Assume that a >= 0.
   * Compute FP expansion of sqrt(a) of length 2^d with error lower than 3 x 2^{-2^d (p - 3) - 2} sqrt(a)
   */
  ExportedByCATMathExactPredicates CATExpFPExpansion SquareRoot(int d) const;

private:
  explicit CATExpFPExpansion(int n);

  template<class IntegralValue>
  explicit CATExpFPExpansion(IntegralValue const&);

  static CATExpFPExpansion FastSum(double x, double y);
  
  void Renormalize();
  void VecSum();
  void VecSumErrBranch();
  void VecSumErr();

  CATExpFPExpansion ScaleExpansion(double x) const;

  class StaticVector : private std::allocator<double>
  {
  public:
    StaticVector()
      : _begin(_staticBuffer)
      , _end(_staticBuffer)
      , _last(_staticBuffer + StaticSize)
    {}

    StaticVector(int iSize, double iValue = 0.)
      : StaticVector()
    {
      Reserve<false>(iSize);
      std::fill_n(_begin, iSize, iValue);
      _end = _begin + iSize;
    }

    template<class IntegralValue>
    StaticVector(IntegralValue const&)
      : StaticVector()
    {
      constexpr int Size = IntegralValue::value;
      if constexpr (Size > StaticSize)
      {
        Reserve<false>(Size);
      }

      std::memset(_begin, 0, Size * sizeof(double));
      _end = _begin + Size;
    }

    ~StaticVector()
    {
      if (!UseStaticBuffer())
        deallocate(_begin, _last - _begin);
    }

    StaticVector(StaticVector const& iV)
      : StaticVector()
    {
      operator=(iV);
    }

    StaticVector& operator=(StaticVector const& iV)
    {
      if (this != &iV)
      {
        auto const size = iV._end - iV._begin;
        Reserve<false>(size);
        std::memcpy(_begin, iV._begin, size * sizeof(double));
        _end = _begin + size;
      }
      return *this;
    }

    StaticVector(StaticVector &&iV)
    {
      if (iV.UseStaticBuffer())
      {
        auto const size = iV._end - iV._begin;
        _begin = _staticBuffer;
        _end = _staticBuffer + size;
        _last = _staticBuffer + StaticSize;
        std::memcpy(_begin, iV._begin, size * sizeof(double));
      }
      else
      {
        _begin = iV._begin;
        _end = iV._end;
        _last = iV._last;

        iV._begin = iV._staticBuffer;
        iV._end = iV._staticBuffer;
        iV._last = iV._staticBuffer + StaticSize;
      }
    }

    StaticVector& operator=(StaticVector &&iV)
    {
      if (iV.UseStaticBuffer())
      {
        auto const size = iV._end - iV._begin;
        std::memcpy(_begin, iV._begin, size * sizeof(double));
        _end = _begin + size;
      }
      else if (UseStaticBuffer())
      {
        _begin = iV._begin;
        _end = iV._end;
        _last = iV._last;

        iV._begin = iV._staticBuffer;
        iV._end = iV._staticBuffer;
        iV._last = iV._staticBuffer + StaticSize;
      }
      else
      {
        std::swap(_begin, iV._begin);
        std::swap(_end, iV._end);
        std::swap(_last, iV._last);
      }
      return *this;
    }

    double const& operator[](int i) const
    {
#ifdef __CATMathExactPredicates
      CATExpAssert(i >= 0 && i < static_cast<int>(size()));
#endif
      return _begin[i];
    }

    double& operator[](int i)
    {
#ifdef __CATMathExactPredicates
      CATExpAssert(i >= 0 && i < static_cast<int>(size()));
#endif
      return _begin[i];
    }

    std::size_t size() const
    {
      return _end - _begin;
    }

    std::size_t capacity() const
    {
      return _last - _begin;
    }

    double const* begin() const
    {
      return _begin;
    }

    double const* end() const
    {
      return _end;
    }

    double* begin()
    {
      return _begin;
    }

    double* end()
    {
      return _end;
    }

    void erase(double *iStart, double *iEnd)
    {
      std::size_t nBack = _end - iEnd;
      std::memmove(iStart, iEnd, nBack);
      _end = iStart + nBack;
    }

    double const& front() const
    {
#ifdef __CATMathExactPredicates
      CATExpAssert(size() > 0);
#endif
      return *_begin;
    }

    double& front()
    {
#ifdef __CATMathExactPredicates
      CATExpAssert(size() > 0);
#endif
      return *_begin;
    }

    double const& back() const
    {
#ifdef __CATMathExactPredicates
      CATExpAssert(size() > 0);
#endif
      return *(_end - 1);
    }

    double& back()
    {
#ifdef __CATMathExactPredicates
      CATExpAssert(size() > 0);
#endif
      return *(_end - 1);
    }

  private:
    bool UseStaticBuffer() const
    {
      return _staticBuffer == _begin;
    }

    template<bool CopyData>
    void Reserve(std::size_t iSize)
    {
      std::size_t const currentCapacity = _last - _begin;
      if (iSize <= currentCapacity)
        return;

      auto const allocatedSize = (std::max)(iSize, (3 * currentCapacity) / 2);
      double* newBuffer = static_cast<double*>(allocate(allocatedSize));
      if constexpr (CopyData)
      {
        std::size_t const currentSize = _end - _begin;
        std::memcpy(newBuffer, _begin, currentSize);
        _end = newBuffer + currentSize;
      }
      else
      {
        _end = newBuffer;
      }

      if (!UseStaticBuffer())
        deallocate(_begin, _last - _begin);
      _begin = newBuffer;
      _last = newBuffer + allocatedSize;
    }

    static const std::size_t StaticSize = 5;

    double _staticBuffer[StaticSize];
    double* _begin;
    double* _end;
    double* _last;

    friend class CATExpFPExpansion;
  };

  StaticVector _expansion;
};

inline double const& CATExpFPExpansion::operator[](int i) const
{
  return _expansion[i];
}

inline int CATExpFPExpansion::Size() const
{
  return static_cast<int>(_expansion.size());
}

template<int d>
double CATExpFPExpansion::Estimate() const
{
  return d < Size() ? (*this)[d] : 0.;
}

inline CATExpSign_t CATExpFPExpansion::Sign() const
{
  if (_expansion.size() == 0)
    return CATExpZERO;
  else if (std::isnan(_expansion[0]))
    return CATExpSIGNUNDEF;
  else
    return _expansion[0] > 0 ? CATExpPOSITIVE : CATExpNEGATIVE;
}

inline CATExpFPExpansion::CATExpFPExpansion(double x)
  : _expansion(1, x)
{
}

inline CATExpFPExpansion::CATExpFPExpansion(int n)
  : _expansion(n)
{
}

template<class IntegralValue>
inline CATExpFPExpansion::CATExpFPExpansion(IntegralValue const& iIntegralValue)
  : _expansion(iIntegralValue)
{
}

inline CATExpFPExpansion operator-(CATExpFPExpansion const& x, CATExpFPExpansion y)
{
  return x + (-y);
}

inline CATExpFPExpansion& CATExpFPExpansion::operator+=(CATExpFPExpansion const& x)
{
  return *this = *this + x;
}

inline CATExpFPExpansion& CATExpFPExpansion::operator-=(CATExpFPExpansion x)
{
  return *this = *this - std::move(x);
}

inline CATExpFPExpansion operator+(CATExpFPExpansion const& x, double y)
{
  return x + CATExpFPExpansion(y);
}

inline CATExpFPExpansion operator+(double x, CATExpFPExpansion const& y)
{
  return CATExpFPExpansion(x) + y;
}

inline CATExpFPExpansion operator*(CATExpFPExpansion const& x, double y)
{
  return y * x;
}

inline CATExpFPExpansion CATExpFPExpansion::Square() const
{
  return (*this) * (*this);
}

inline CATExpFPExpansion CATExpFPExpansion::Quotient(int d, CATExpFPExpansion const &y) const
{
  return (*this) * y.Inverse(d);
}

#endif
