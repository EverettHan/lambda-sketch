//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATPolyDebugFactoryItf.h
//
//=================================================================================
//
// Usage notes: Interface pour une factory de debug
//
//=================================================================================
// June,   2009 : RAQ : Creation
//=================================================================================
#ifndef CATPolyDebugFactoryItf_H
#define CATPolyDebugFactoryItf_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Classe mère
#include "CATPolyRefCounted.h"

#include "CATMathPoint.h"
#include "CATDataType.h"

class ExportedByCATPolyTrimOperators CATPolyDebugFactoryItf: public CATPolyRefCounted
{
public:

  //Constructeur
  CATPolyDebugFactoryItf();

  //Crée un point coloré rend le tag
  virtual CATULONG32 CreatePoint(const CATMathPoint& iPoint, const int iRed, const int iGreen, const int iBlue) { return 0; }
  virtual CATULONG32 CreatePoint(const double* iPoint, const int iRed = 0, const int iGreen = 15, const int iBlue = 0) { return 0; }
  
  //Crée une line colorée et renvoie le tag
  virtual CATULONG32 CreateLine(const CATMathPoint& iP1, const CATMathPoint& iP2, const int iRed, const int iGreen, const int iBlue) { return 0; }
  virtual CATULONG32 CreateLine(const double* iPoint1, const double* iPoint2, const int iRed = 0, const int iGreen = 15, const int iBlue = 0) { return 0; }

protected:

  //Destructeur
  virtual ~CATPolyDebugFactoryItf();

};

#endif



