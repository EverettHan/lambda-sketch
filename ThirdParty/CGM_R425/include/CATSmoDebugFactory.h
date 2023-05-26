//=================================================================================
// Copyright Dassault Systemes Provence 2008, All Rights Reserved 
//=================================================================================
//
// CATSmoDebugFactory.h
//
//=================================================================================
//
// Usage notes: API permettant de creer de la geometry dans une factory.
//              L'implementation est faite par les clients (Cf CATSmoDebugFactoryImp dans CATSubdivisionTopOperators)
//              Utile pour le debug, ou pour illustrer certain comportment.
//
//=================================================================================
// October, 2008 : RAQ : Pas virtuel pure pour ne pas tout impl�menter
// April,   2008 : PMG : Creation (Juste la gestion des points...)
//=================================================================================
#ifndef CATSmoDebugFactory_H
#define CATSmoDebugFactory_H

//Pour l'export
#include "CATSmoOperators.h"

//Divers
#include "CATDataType.h"

class CATMathPoint;
class CATMathVector;


class ExportedByCATSmoOperators CATSmoDebugFactory
{
public:

  //Destructeur
  virtual ~CATSmoDebugFactory() {};

  //Cr�e un point color� rend le tag
  virtual CATULONG32 CreatePoint(const CATMathPoint& iPoint, const int iRed = 0, const int iGreen = 15, const int iBlue = 0) { return 0; }
  virtual CATULONG32 CreatePoint(const double* iPoint, const int iRed = 0, const int iGreen = 15, const int iBlue = 0) { return 0; }
  
  //Cr�e une line color�e et renvoie le tag
  virtual CATULONG32 CreateLine(const CATMathPoint& iP1, const CATMathPoint& iP2, const int iRed = 0, const int iGreen = 15, const int iBlue = 0) { return 0; }
  virtual CATULONG32 CreateLine(const double* iPoint1, const double* iPoint2, const int iRed = 0, const int iGreen = 15, const int iBlue = 0) { return 0; }
  virtual CATULONG32 CreateLine(const CATMathPoint& iP1, const CATMathVector& iDirection, const int iRed = 0, const int iGreen = 15, const int iBlue = 0) { return 0; }

};
#endif



