// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVStreamTools.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Sept 2009  Creation: ZFI
// Tools for uv tess
// More public toolkit in PolyhedralMathematics
//===================================================================

#ifndef CATCGMUVStreamTools_H
#define CATCGMUVStreamTools_H

#include "CATErrorDef.h"
#include "CATDataType.h"

class CATMathStream;

class CATMathPoint2D;
class CATMathPoint;
class CATMathVector;

class CATCGMUVStreamTools
{
public:
  //CATCGMUVStreamTools();
  //virtual ~CATCGMUVStreamTools();

  // bufferizing tools
  static HRESULT ConvertULONG32ToChar(const CATULONG32 iVal, unsigned char oCharVal[4]);
  static HRESULT ConvertCharToULONG32(const unsigned char iCharVal[4], CATULONG32& oVal);

  static HRESULT ConvertShortToChar(const short iVal, unsigned char oCharVal[2]);
  static HRESULT ConvertCharToShort(unsigned char iCharVal[2], short& oVal);

  //vector quantization 
  static HRESULT QuantifyVector(const CATMathVector& iVector,unsigned int& oX);

  static HRESULT UnQuantifyVector(const unsigned int iX, CATMathVector& oVector);


  //axis transfo, angles, vectors..
  static HRESULT GetSphericalAngles(const CATMathVector& iU, double& oTheta, double& oPhi);
  static HRESULT GetVector(const double iTheta, const double iPhi, CATMathVector& oU);


protected:

  static HRESULT SeparateIntoBytes(const CATULONG32 iVal, size_t iNbBytesToSeparate, unsigned char* oCharVal);
  static HRESULT CombineBytes(const unsigned char* iCharVal, size_t iNbBytesToCombine, CATULONG32& oVal);

};

#endif
