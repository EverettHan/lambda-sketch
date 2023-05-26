#ifndef CATCDSMathConversion_H
#define CATCDSMathConversion_H

#include <type_traits>

// COPYRIGHT DASSAULT SYSTEMES 2020

template<class ToVector, class FromVector>
void ConvertVector(FromVector const& iV, ToVector& oV)
{
  double c[3];
  iV.GetCoord(c[0], c[1], c[2]);
  oV.SetCoord(c[0], c[1], c[2]);
}

template<class ToVector, class FromVector>
ToVector ConvertVector(FromVector const& iV)
{
  ToVector res;
  ConvertVector(iV, res);
  return res;
}

template<class ToPoint, class FromPoint>
void ConvertPoint(FromPoint const& iV, ToPoint& oV)
{
  double c[3];
  iV.GetCoord(c[0], c[1], c[2]);
  oV.SetCoord(c[0], c[1], c[2]);
}

template<class ToPoint, class FromPoint>
ToPoint ConvertPoint(FromPoint const& iV)
{
  ToPoint res;
  ConvertPoint(iV, res);
  return res;
}

template<class ToMatrix, class FromMatrix>
void ConvertMatrix(FromMatrix const& iM, ToMatrix& oM)
{
  double c[9];
  iM.GetCoef(c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8]);
  oM.SetCoef(c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8]);
}

template<class ToMatrix, class FromMatrix>
ToMatrix ConvertMatrix(FromMatrix const& iM)
{
  ToMatrix res;
  ConvertMatrix(iM, res);
  return res;
}

template<class ToTransfo, class FromTransfo>
void ConvertTransformation(FromTransfo const& iT, ToTransfo& oT)
{
  oT.SetMatrix(ConvertMatrix<std::remove_const_t<std::remove_reference_t<decltype(oT.GetMatrix())>>>(iT.GetMatrix()));
  oT.SetVector(ConvertVector<std::remove_const_t<std::remove_reference_t<decltype(oT.GetVector())>>>(iT.GetVector()));
}

template<class ToTransfo, class FromTransfo>
ToTransfo ConvertTransformation(FromTransfo const& iT)
{
  ToTransfo res;
  ConvertTransformation(iT, res);
  return res;
}


template<class MathQuaternion, class CDSQuaternion>
MathQuaternion ConvertQuaternionCDSToMath(CDSQuaternion const& iQ)
{
  MathQuaternion res(iQ[0], iQ[1], iQ[2], iQ[3]) ; //todo check for the quaternion convention
  return res;
}
template<class CDSQuaternion, class  MathQuaternion >
CDSQuaternion ConvertQuaternionMathToCDS(MathQuaternion const& iQ)
{
  CDSQuaternion res;
  iQ.GetCoord(res[0], res[1], res[2], res[3]);  //put coord in res
  //todo check for the quaternion convention
  return res;
}



//template is not really usefull
template<class CATCDSFrame, class CATMathAxis>
CATCDSFrame ConvertFrameAxisMathToCDS(CATMathAxis const& iToConvert)
{
  auto P = ConvertPoint<CATCDS3Point>(iToConvert.GetOrigin());
  auto I = ConvertVector<CATCDS3Vector>(iToConvert.GetFirstDirection());
  auto J = ConvertVector<CATCDS3Vector>(iToConvert.GetFirstDirection());
  auto K = ConvertVector<CATCDS3Vector>(iToConvert.GetFirstDirection());
  return  CATCDSFrame(P, I, J, K);
}
template<class CATMathAxis , class CATCDSFrame>
CATMathAxis ConvertFrameAxisCDS2Math(CATCDSFrame const& iToConvert)
{
  CATCDS3Point P;
  CATCDS3Vector I, J, K;
  iToConvert.GetOrigin(P);
  iToConvert.GetVectors(I, J, K);

  CATMathPoint cP = ConvertPoint<CATMathPoint>(P);
  CATMathVector cI = ConvertVector<CATMathVector>(I);
  CATMathVector cJ = ConvertVector<CATMathVector>(J);
  CATMathVector cK = ConvertVector<CATMathVector>(K);
  return  CATMathAxis(cP, cI, cJ, cK);
}

// to do : Frame, Quaternion


//To Be more easy to use , we predeclare the template with standard type on a method called Convert
//? But you need to add #include "CDSType..." and " CATMath..." before the include of CATCDSMathConvertion.h"
// we don't do it here due to packaging reason !

/**
This can generate error
@code
#include "CATCDSMathConversion.h"
#include "CATCDS3Frame.h"
void demo()
{
  auto fcds = CDS::Convert(CATMathAxis());  //generate: CATCDSMathConversion.h(158): error C2027: use of undefined type 'CATCDS3Frame'
}
@endcode

but this code will be correct
@code
#include "CATCDS3Frame.h"
#include "CATCDSMathConversion.h"
void demo()
{
  auto fcds = CDS::Convert(CATMathAxis());  //OK
}
@endcode
*/
//predeclare class
// may be  use include instead it should not be a problem since this is header only
class CATMathTransformation;//#include "CATMathTransformation.h"
class CATCDSTransformation;//#include "CATCDSTransformation.

class CATMathVector;
class CATCDS3Vector;

class CATMathPoint;
class CATCDS3Point;

class CATMath3x3Matrix;
class CATCDS3x3Matrix;

class CATCDS3Frame;
class CATMathAxis;

class CATCDSQuaternion;
class CATMathQuaternion;
// Instanciate template into a single Convert method  just call  NewType dataConverted = CDS::Convert( datatoconvert );
namespace CDS
{
#define CONVERT_IMPL(OUTPUTTYPE, INPUTTYPE, convertmethod )  OUTPUTTYPE inline Convert(const INPUTTYPE& iToConvert ) { return convertmethod<OUTPUTTYPE>(iToConvert) ;};

#if defined(CATMathTransformation_H) && defined(CATCDSTransformation_H) // include  CATMathTransformation.h,ConvertTransformation.h before this file, if you want use it
   CONVERT_IMPL(CATMathTransformation, CATCDSTransformation, ConvertTransformation);
   CONVERT_IMPL(CATCDSTransformation, CATMathTransformation, ConvertTransformation);
#endif

#if defined(CATMathVector_H) && defined(CATCDS3Vector_H) // include  CATMathTransformation.h,ConvertTransformation.h before this file, if you want use it
   CONVERT_IMPL(CATMathVector, CATCDS3Vector, ConvertVector);
   CONVERT_IMPL(CATCDS3Vector, CATMathVector, ConvertVector);
#endif

#if defined(CATMathPoint_H) && defined(CATCDS3Point_H) // include  CATMathTransformation.h,ConvertTransformation.h before this file, if you want use it
   CONVERT_IMPL(CATMathPoint, CATCDS3Point, ConvertPoint);
   CONVERT_IMPL(CATCDS3Point, CATMathPoint, ConvertPoint);
#endif

#if defined(CATMath3x3Matrix_H) && defined(CATCDS3x3Matrix_H) // include  CATMathTransformation.h,ConvertTransformation.h before this file, if you want use it
   CONVERT_IMPL(CATMath3x3Matrix, CATCDS3x3Matrix, ConvertMatrix);
   CONVERT_IMPL(CATCDS3x3Matrix, CATMath3x3Matrix, ConvertMatrix);
#endif

#if defined(CATMathAxis_H) && defined(CATCDS3Frame_H) // include  CATMathTransformation.h,ConvertTransformation.h before this file, if you want use it
   CONVERT_IMPL(CATMathAxis, CATCDS3Frame, ConvertFrameAxisCDS2Math);
   CONVERT_IMPL(CATCDS3Frame, CATMathAxis, ConvertFrameAxisMathToCDS);
#endif

#if defined(CATMathQuaternion_h) && defined(CATCDSQuaternion_H) // include  CATMathTransformation.h,ConvertTransformation.h before this file, if you want use it
   CONVERT_IMPL(CATMathQuaternion, CATCDSQuaternion, ConvertQuaternionCDSToMath);
   CONVERT_IMPL(CATCDSQuaternion, CATMathQuaternion, ConvertQuaternionMathToCDS);
#endif
}

#endif
