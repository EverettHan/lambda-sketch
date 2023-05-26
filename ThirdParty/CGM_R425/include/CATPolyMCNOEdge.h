//=================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================================
//
// CATPolyMCNOEdge.h
//
//=================================================================================
//
// Usage notes: Objet Edge du r�seau de courbe.
//
//=================================================================================
// July,   2009 : RAQ : Cr�ation
//=================================================================================
#ifndef CATPolyMCNOEdge_H
#define CATPolyMCNOEdge_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Classe m�re
#include "CATPolyRefCounted.h"

//Divers
#include "CATListPV.h"
#include "CATMathVector.h"
#include "CATBoolean.h"
#include "CATDataType.h"

//STL
#include <set>

class CATPolyMCNOPoint;
class CATPolyMCNOCurve;


class ExportedByCATPolyTrimOperators CATPolyMCNOEdge: public CATPolyRefCounted
{
public:

  //Constructeur
  CATPolyMCNOEdge(CATListPV* iMCNOPointsOfEdge);

  //R�cup�ration de l'ID
  inline unsigned int GetID() const { return _ID; }

  //ID de la courbe support
  void SetSupportCurveID(const CATULONG32 iSupportCurveID);
  inline CATULONG32 GetSupportCurveID() const { return _SupportCurveID; }

  //R�cup�ration des courbes contenant simultan�ment les deux vertex extr�mit�
  void GetAllSupportingCurves(std::set<CATPolyMCNOCurve*>& oSupportingCurves) const;
  
  //Obtention des extr�mit�s
  void GetExtremities(CATPolyMCNOPoint*& oExtremity1, CATPolyMCNOPoint*& oExtremity2) const;
  CATPolyMCNOPoint* GetOtherExtremity(const CATPolyMCNOPoint* iMCNOPoint) const;

  //Inversion de l'orientation de l'edge
  void InvertExtremities();

  //Obtention des points de l'edge
  inline CATListPV* GetPoints() const { return _MCNOPointsOfEdge; }

  //Calcul de la direction locale au voisinage d'une des extremit�s
  int GetLocalEdgeDirection(CATPolyMCNOPoint* iEdgeExtremity, CATMathVector& oLocalDirection) const;

  //Nombre de visites
  void SetNbVisitedTimes(const int iNbVisitedTimes);
  int& GetNbVisitedTimes();

  //Identification des edges de bord
  void SetFreeEdge(const CATBoolean iIsFreeEdge = TRUE);
  CATBoolean IsFreeEdge() const;


protected:

  //Destructeur
  virtual ~CATPolyMCNOEdge();

private:


  //---------- Data:
  unsigned int _ID;
  CATULONG32 _SupportCurveID;
  CATPolyMCNOPoint *_StartPoint, *_EndPoint;
  CATListPV* _MCNOPointsOfEdge;
  int _NbVisitedTimes;
  CATBoolean _IsFreeEdge;
};


#endif


