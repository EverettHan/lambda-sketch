//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATPolyMCNOCurve.h
//
//=================================================================================
//
// Usage notes: Courbe sur maillage pour l'opérateur CATPolyMCurveNetworkOperator.
//              Similaire à CATPolyMCurve mais avec des pointeurs.
//              /!\ En cas de fermeture de la courbe les points extrémités
//                  ne sont pas dupliqués.
//
//=================================================================================
// 17.01.2017 : RAQ : Correction du RI 486067
// 21.08.2015 : RAQ : Ajout GetPointIndex, à optimiser par un set pour booster la localisation dans la liste et garder l'ordre
// June,   2009 : RAQ : Création
//=================================================================================
#ifndef CATPolyMCNOCurve_H
#define CATPolyMCNOCurve_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Classe mère
#include "CATPolyRefCounted.h"

//Divers
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATMathOBB.h"

//STL
#ifdef _AIX_SOURCE
#undef throw
#undef catch
#undef try
#endif  //_AIX_SOURCE
#include <vector>

class CATPolyMCurve;
class CATPolyMPoint;
class CATPolyMCNOPoint;
class CATMathPoint;
class CATMathStream;
class CATMathSetOfPoints;


class ExportedByCATPolyTrimOperators CATPolyMCNOCurve: public CATPolyRefCounted
{
public:

  //Constructeurs
  CATPolyMCNOCurve();
  CATPolyMCNOCurve(const CATULONG32 iCurveHandle);
  CATPolyMCNOCurve(const CATPolyMCurve& iCurve);

  //Ajout d'un point
  void AddPoint(const CATPolyMPoint& iMPoint, const CATBoolean iAddCurveToMCNOPoint = FALSE);
  void AddPoint(const CATMathPoint& iMathPoint, const CATBoolean iAddCurveToMCNOPoint = FALSE);

  //Insertion d'un point : 1 <= iIndex <= nbPoints before insertion
  void InsertPoint(const int iIndex, CATPolyMCNOPoint* iPoint);

  //Obtention du nombre de points
  int GetNbPoints() const;

  //Obtention d'un point, 1 <= i <= NbPoints
  CATPolyMCNOPoint* GetPoint(const int iIndex) const;

  //Gets a point index with 1 <= index <= NbPoints, returns 0 if point is not on curve
  int GetPointIndex(const CATPolyMCNOPoint* ipMCNOPoint) const;

  //Replacement d'un point, renvoie TRUE si le point a bien été remplacé
  CATBoolean ReplacePoint(CATPolyMCNOPoint* iPointToReplace, CATPolyMCNOPoint* iReplacingPoint);

  //Suppression d'un point
  int RemovePoint(CATPolyMCNOPoint* iPointToRemove, const CATBoolean iReleaseObject = TRUE);
  int RemovePoint(const int iIndex, const CATBoolean iReleaseObject = TRUE);

  //Fermeture de la courbe
  void SetClosed();
  CATBoolean IsClosed() const;

  //Identification des courbes de bord
  void SetBorderCurve(const CATBoolean iIsBorderCurve = TRUE);
  CATBoolean IsBorderCurve() const;

  //Suppression des courbes sous les points
  void ClearAllCurvesFromPoints();

  //Obtention ID
  CATULONG32 GetID() const { return _ID; }

  //Récupération de l'OBB
  const CATMathOBB& GetOBB();

  //Gestion stream/unstream pour CGMReplay
  int Stream(CATMathStream& iStr);
  static int Unstream(CATMathStream& iStr, CATMathSetOfPoints& oSetOfPoints);


protected:

  //Destructeur
  virtual ~CATPolyMCNOCurve();


private:

  //Calcul de l'OBB de la courbe
  int UpdateOBB();


  //--------- Data:
  std::vector<CATPolyMCNOPoint*> _AllMCNOPoints;
  CATBoolean _IsClosed, _IsBorderCurve;
  CATULONG32 _ID;

  CATMathOBB m_curveOBB;
  bool m_obbIsUpToDate;

};

#endif

