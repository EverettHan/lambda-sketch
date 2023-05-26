//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATPolyMCNOPoint.h
//
//=================================================================================
//
// Usage notes: Point d'une courbe CATPolyMCNOCurve pour l'op�rateur
//              CATPolyMCurveNetworkOperator.
//
//=================================================================================
// 17.01.2017 : RAQ : Correction du RI 486067
// June,   2009 : RAQ : Cr�ation
//=================================================================================
#ifndef CATPolyMCNOPoint_H
#define CATPolyMCNOPoint_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Classe m�re
#include "CATPolyMPoint.h"
#include "CATLISTP_CATPolyMCNOEdge.h"

//Divers
#include "CATListPV.h"
#include "CATBoolean.h"


class CATPolyMCNOCurve;
class CATPolyMCNOEdge;
class CATPolyMCurveNetworkIntersectionPoint;


class ExportedByCATPolyTrimOperators CATPolyMCNOPoint: public CATPolyMPoint
{
public:
  
  //Constructeurs
  CATPolyMCNOPoint(const CATPolyMPoint& iPoint);
  CATPolyMCNOPoint(const CATMathPoint& iPoint);

  //Gestion r�f�rences
  int AddRef();
  void Release();

  //Obtention ID
  unsigned int GetID() const { return _ID; }
  
  //Position g�om�trique
  inline const CATMathPoint& GetMathPoint() const { return _position; }

  //Flag de point d'intersection
  inline void SetIntersectionPoint(const CATBoolean iIsIntersection = TRUE);
  inline CATBoolean IsIntersectionPoint() const;

  //Flag de classification
  void SetClassified(const CATBoolean iClassified);
  CATBoolean IsClassified() const;

  //Ajout d'une courbe pour les points d'intersection, check interne pour ne pas ajouter deux fois la m�me courbe
  void AddCurve(const CATPolyMCNOCurve* iCurve);

  //Suppression des courbes
  void RemoveCurve(const CATPolyMCNOCurve* iCurve);
  void RemoveAllCurves(const CATBoolean iJustKeepFirstCurve = FALSE);

  //Suppression des courbes ne contenant pas le point
  void RemoveAllCurvesNotContainingPoint();

  //Test d'appartenance du point d'intersection � une courbe
  CATBoolean IsIntersectionPointOnCurve(const CATPolyMCNOCurve* iCurve) const;

  //R�cup�ration des courbes autour d'un point d'intersection
  const CATListPV* GetAllCurvesAroundIntersectionPoint() const;
  int GetAllCurvesAroundIntersectionPoint(CATListPV& oAllCurvesAround) const;

  //R�cup�ration du nombre de courbes autour de ce point
  int GetNbCurvesAround() const;

  //Test de confusion g�o
  CATBoolean IsConfusedWith(const CATMathPoint& iGeoPoint) const;

  //Test de confusion (topo & g�o)
  CATBoolean IsConfusedWith(const CATPolyMCNOPoint* iOtherPoint) const;

  //Distance entre deux points
  double SquareDistanceTo(const CATPolyMCNOPoint& iPoint) const { return _position.SquareDistanceTo(iPoint._position); }

  //Test d'existence d'une edge en fonction de ses extr�mit�s et des points internes
  //iEdge is compared with each edge using 'this' point.
  //If iCheckByAddress is TRUE : if iEdge is one of the edges using this point, the methood will return TRUE
  //If iCheckByAddress is FALSE : the comparaison will be done on all edges which address is different from the one of iEdge
  const CATPolyMCNOEdge* ExistEdge(CATPolyMCNOEdge* iEdge, const CATBoolean iCheckByAddress = TRUE) const;

  //Test d'existence d'une edge bas� uniquement sur la comparaison des extr�mit�s
  const CATPolyMCNOEdge* ExistEdgeBasic(CATPolyMCNOEdge* iEdge, const CATBoolean iCheckByAddress = TRUE) const;
  const CATPolyMCNOEdge* ExistEdgeBasic(const CATPolyMCNOPoint* ipOtherExtremity) const;

  //Gestion des CATPolyMCNOEdge
  void AddEdge(CATPolyMCNOEdge* iEdge);
  void RemoveEdge(CATPolyMCNOEdge* iEdge);

  //R�cup�ration des edges
  CATListPOfPolyMCNOEdge* GetAllEdges();
  CATPolyMCNOEdge* GetPreviousEdgeInRing(const CATPolyMCNOEdge* iEdge, int* ioLocate = 0);
  int GetNbEdgesAround() const { return _AllMCNOEdges ? _AllMCNOEdges->Size() : 0; }

  //Gestion de l'objet point d'intersection du r�seau
  CATPolyMCurveNetworkIntersectionPoint* GetOrCreateNetworkIntersectionPoint();
  CATPolyMCurveNetworkIntersectionPoint* GetNetworkIntersectionPoint();

  //R�cup�ration de la courbe commune (si elle existe) � ce point et � un autre point donn�
  const CATPolyMCNOCurve* GetCommonCurve(const CATPolyMCNOPoint& iOtherPoint) const;

  //Debug : check que le point est bien sur chacune des courbes autour de lui
  CATBoolean CheckPointIsOnAllCurvesAround();

  //Debug : check si une courve fait partie des courbes autour d'un point
  CATBoolean IsPartOfCurvesAround(const CATPolyMCNOCurve* ipCurve) const;


protected:

  //Destructeur
  virtual ~CATPolyMCNOPoint();
  


private:

  //Pour �viter les recopies
  CATPolyMCNOPoint(const CATPolyMCNOPoint&);
  CATPolyMCNOPoint& operator=(const CATPolyMCNOPoint&);


  //--------- Data:
  int _RefCounter;
  //CATBoolean _IsIntersectionPoint;
  CATListPV _AllMCNOCurveAround;
  CATListPOfPolyMCNOEdge* _AllMCNOEdges;
  CATPolyMCurveNetworkIntersectionPoint* _NetworkIntersectionPoint;

  //Codage de donn�es binaires:
  // Bit 0x01: Point d'intersection (1)
  // Bit 0x02: Point classifi� (1)
  // Bit 0x04: Not used
  // Bit 0x08: Not used
  // Bit 0x10: Not used
  // Bit 0x20: Not used
  // Bit 0x40: Not used
  // Bit 0x80: Not used
  unsigned char _BinaryInfos;

  //Debug
  unsigned int _ID;

};


//-------------------------------
// Flag de point d'intersection
//-------------------------------
inline void CATPolyMCNOPoint::SetIntersectionPoint(const CATBoolean iIsIntersection)
{
  if(iIsIntersection) _BinaryInfos|=0x01;
  else _BinaryInfos&=~0x01;
}


inline CATBoolean CATPolyMCNOPoint::IsIntersectionPoint() const
{
  return (_BinaryInfos & 0x01) ? TRUE : FALSE;
}


#endif


