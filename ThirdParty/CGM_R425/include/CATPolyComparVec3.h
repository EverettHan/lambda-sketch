#ifndef CATPolyComparVec3_H
#define CATPolyComparVec3_H
//====================================================================
// Copyright Dassault Systemes Provence 2017, All Rights Reserved 
//====================================================================
// DESCRIPTION : Vecteur de 3 (template)
//=============================================================================
// HISTORIQUE :
//  16/02/2017 : RNO  : Creation !!!
//=============================================================================
#include "CATMathInline.h"
#include "ExportedByCATPolyComparOperators.h"
#include "CATMathPoint.h"
#include <array>
#include "CATTolerance.h"
static const double TinyNorm = CATGetDefaultTolerance().SquareEpsgForRelativeTest();//1.e-24
template<typename TReal>
class ExportedByCATPolyComparOperators CATPolyComparVec3
{
public :
  INLINE CATPolyComparVec3(){}
  //explicit INLINE CATPolyComparVec3(const std::array<TReal,3>  & iArray):m_Vec(iArray){}
  explicit INLINE CATPolyComparVec3(std::array<TReal,3>  && iArray):m_Vec(std::move(iArray)){}
  explicit INLINE CATPolyComparVec3(const std::array<TReal,3> & iArray):m_Vec(iArray){}

  explicit INLINE CATPolyComparVec3(double x, double y, double z){ m_Vec[0]=static_cast<TReal>(x); m_Vec[1]=static_cast<TReal>(y); m_Vec[2]=static_cast<TReal>(z);}
  CATPolyComparVec3(const CATMathPoint & P){ m_Vec[0]=static_cast<TReal>(P.GetX()); m_Vec[1]=static_cast<TReal>(P.GetY()); m_Vec[2]=static_cast<TReal>(P.GetZ());}
  INLINE CATPolyComparVec3(CATPolyComparVec3 && i):m_Vec(std::move(i.m_Vec)){}
  INLINE CATPolyComparVec3(const CATPolyComparVec3 & i):m_Vec(i.m_Vec){}
  INLINE CATPolyComparVec3 & operator= ( CATPolyComparVec3 && iOther){m_Vec=std::move(iOther.m_Vec); return *this;}
  INLINE CATPolyComparVec3& operator=(const CATPolyComparVec3 & other){m_Vec=other.m_Vec; return *this;}

  INLINE TReal & operator [] (size_t i) {return  m_Vec[i];}
  INLINE const TReal operator [] (size_t i) const {return  m_Vec[i];}
  INLINE TReal SquareNorm() const { return ( (m_Vec[0]*m_Vec[0] + m_Vec[1]*m_Vec[1] )+ m_Vec[2]*m_Vec[2] );} 

  INLINE void Normalize() {
    auto norm2 = SquareNorm();
    if (norm2 < TinyNorm) return;
    auto norm = std::sqrt(norm2);
    m_Vec[0] /= norm;
    m_Vec[1] /= norm;
    m_Vec[2] /= norm;
  }
  INLINE TReal SquareDistanceTo(const CATPolyComparVec3& iOther) const 
  { 
    return (iOther-*this).SquareNorm(); 
  }
  INLINE friend CATPolyComparVec3 operator +
    (const CATPolyComparVec3 & iU, const CATPolyComparVec3 & iV)
  {
    return CATPolyComparVec3 (iU[0] + iV[0], iU[1] + iV[1], iU[2] + iV[2]);
  }
  INLINE void operator += (const CATPolyComparVec3 & iP) 
  {
    for(size_t i(0); i<3;++i)   
      m_Vec[i] += iP[i]; 
  }
  INLINE friend CATPolyComparVec3 operator -
    (const CATPolyComparVec3 & iU, const CATPolyComparVec3 & iV)
  {
    return CATPolyComparVec3 (iU[0] - iV[0], iU[1] - iV[1], iU[2] - iV[2]);
  }

  INLINE void operator -= (const CATPolyComparVec3 & iV) 
  {
    for(size_t i(0); i<3;++i)   
      m_Vec[i] -= iV[i]; 
  }

  INLINE CATPolyComparVec3 operator ^ (const CATPolyComparVec3 & iV) 
  {
    return CATPolyComparVec3 ((m_Vec[1]*iV[2])-(m_Vec[2]*iV[1]), m_Vec[2]*iV[0]-m_Vec[0]*iV[2],   m_Vec[0]*iV[1]-m_Vec[1]*iV[0]);
  }


  INLINE friend ExportedByCATPolyComparOperators CATPolyComparVec3 operator *
    (const double iScalar, const CATPolyComparVec3 & iVector )
  {
    return CATPolyComparVec3 (iScalar*iVector[0], iScalar*iVector[1], iScalar*iVector[2]); 
  }


  INLINE friend ExportedByCATPolyComparOperators CATPolyComparVec3 operator *
    (const CATPolyComparVec3 & iVector, const double iScalar)
  {
    return CATPolyComparVec3 (iScalar*iVector[0], iScalar*iVector[1], iScalar*iVector[2]); 
  }

  INLINE friend ExportedByCATPolyComparOperators TReal operator *
    (const CATPolyComparVec3 & iV1, const CATPolyComparVec3 & iV2)
  {
    return (iV1[0]*iV2[0]+ iV1[1]*iV2[1]) +  iV1[2]*iV2[2];
  }

  INLINE friend ExportedByCATPolyComparOperators CATPolyComparVec3 operator ^
    (const CATPolyComparVec3 & iV1, const CATPolyComparVec3 & iV2)
  {
    return CATPolyComparVec3((iV1[1] * iV2[2]) - (iV1[2] * iV2[1]), iV1[2] * iV2[0] - iV1[0] * iV2[2], iV1[0] * iV2[1] - iV1[1] * iV2[0]);
  }

  INLINE void operator *= ( double iScalar) 
  {
    for(auto & v:m_Vec)
      v*=iScalar;
  } 


  //cast operator
  INLINE operator CATMathPoint (){ return CATMathPoint(m_Vec[0],m_Vec[1],m_Vec[2]);}  
  INLINE operator const CATMathPoint () const { return CATMathPoint(m_Vec[0],m_Vec[1],m_Vec[2]);}  

  //Swap Operator
  INLINE void swap(CATPolyComparVec3& iOther){m_Vec.swap(iOther.m_Vec);}
  INLINE friend void swap(CATPolyComparVec3& a, CATPolyComparVec3& b){ a.m_Vec.swap(b.m_Vec);}

  static inline CATPolyComparVec3<TReal> Low(const CATPolyComparVec3<TReal> & v1, const CATPolyComparVec3<TReal> & v2)
  {
    return(CATPolyComparVec3<TReal>(v1[0]<v2[0] ? v1[0] : v2[0],
                              v1[1]<v2[1] ? v1[1] : v2[1],
                              v1[2]<v2[2] ? v1[2] : v2[2]));
  }

  static inline CATPolyComparVec3<TReal> High(const CATPolyComparVec3<TReal> & v1, const CATPolyComparVec3<TReal> & v2)
  {
    return(CATPolyComparVec3<TReal>(v1[0] > v2[0] ? v1[0] : v2[0],
                              v1[1] > v2[1] ? v1[1] : v2[1],
                              v1[2] > v2[2] ? v1[2] : v2[2]));
  }


private:
  std::array<TReal,3>  m_Vec;
};

namespace std {
  template <class T>
  INLINE CATPolyComparVec3<T> swap(CATPolyComparVec3<T> & a, CATPolyComparVec3<T> & b) { a.swap(b); return a; }
}


//const CATPolyComparVec3<double> Origine(0.,0.,0.);
#endif // CATPolyComparVec3_H
