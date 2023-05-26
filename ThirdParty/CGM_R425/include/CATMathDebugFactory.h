//=================================================================================
// Copyright Dassault Systemes Provence 2008, All Rights Reserved 
//=================================================================================
//
// CATMathDebugFactory.h
//
//=================================================================================
//
// Usage notes: API permettant de creer de la geometry dans une factory.
//              L'implementation est faite par les clients (Cf CATMathDebugFactoryImp dans CATSubdivisionTopOperators)
//              Utile pour le debug, ou pour illustrer certain comportment.
//
//=================================================================================
// January,   2011 : PMG : Creation (Juste la gestion des points...)
//=================================================================================
#ifndef CATMathDebugFactory_H
#define CATMathDebugFactory_H

//Pour l'export
#include "MathMarsh.h"

#include "CATMathPoint.h"
#include "CATMathBox.h"
#include "CATMathOBB.h"
#include "CATDataType.h"

class ExportedByMathMarsh CATMathDebugFactory
{
public:

  //Destructeur
  virtual ~CATMathDebugFactory() {};

  //Crée un point coloré rend le tag
  virtual CATULONG32 CreatePoint(const CATMathPoint& iPoint, const int iRed, const int iGreen, const int iBlue) { return 0; }
  virtual CATULONG32 CreatePoint(const double* iPoint, const int iRed = 0, const int iGreen = 15, const int iBlue = 0) { return 0; }
  
  //Crée une line colorée et renvoie le tag
  virtual CATULONG32 CreateLine(const CATMathPoint& iP1, const CATMathPoint& iP2, const int iRed, const int iGreen, const int iBlue) { return 0; }
  virtual CATULONG32 CreateLine(const double* iPoint1, const double* iPoint2, const int iRed = 0, const int iGreen = 15, const int iBlue = 0) { return 0; }

  //Crée une boite colorée et renvoie le tag
  virtual CATULONG32 CreateBox(const CATMathBox& box, const int iRed = 0, const int iGreen = 0, const int iBlue = 15, char const* iName = NULL) { return 0; }
  virtual CATULONG32 CreateBox(const CATMathOBB& box, const int iRed = 0, const int iGreen = 0, const int iBlue = 15, char const* iName = NULL) { return 0; }

  //Crée une sphère colorée et renvoie le tag
  virtual CATULONG32 CreateSphere(const CATMathPoint& iPoint, double radius, const int iRed = 0, const int iGreen = 0, const int iBlue = 15, char const* iName = NULL) { return 0; }

};
#endif



