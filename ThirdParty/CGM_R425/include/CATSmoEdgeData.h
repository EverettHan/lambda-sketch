//=========================================================================================
// Copyright Dassault Systemes Provence 2018, All Rights Reserved
//=========================================================================================
//
// CATSmoEdgeData.h
//
//=========================================================================================
//
// Usage notes : Operator to retreive all subdivision points from an edge at a given level
//
//=========================================================================================
// May,   2021: RJY1: Modification du constructeur et ajout d'attributs pour la subdivision de courbes
// 16.01.2018 : RAQ : Creation
//=========================================================================================
#ifndef CATSmoEdgeData_H
#define CATSmoEdgeData_H

//Pour l'export
#include "CATSmoOperators.h"

//Subdivision
#include "CATSobDiag.h"

//STL
#include <vector>

class CATSobFace;
class CATSobEdge;
class CATMathPoint;


class CATSmoEdgeData
{
public:

  //Constructor 
  ExportedByCATSmoOperators
    CATSmoEdgeData(CATSobEdge& iEdge,
      CATMathPoint* ioTabOfPoints = NULL,
      const int     iSizeOfTab = 0,
      const int     iLevel = 0);

  //Destructor
  ExportedByCATSmoOperators
    ~CATSmoEdgeData();

  //Extract all subdivision points at a given level.
  //Points are ordered regarding the edge's orientation
  ExportedByCATSmoOperators
    CATSobDiag GetAllPoints(const unsigned int iLevel, std::vector<CATMathPoint>& oPoints);

  //Extract all neighbour points at a given level
  //Points are ordered regarding the edge's orientation
  ExportedByCATSmoOperators
    CATSobDiag GetAllNeighbourPoints(CATSobFace* ipFace, const unsigned int iLevel, std::vector<CATMathPoint>& oPoints);

 //
 //Run operator.
 //
 //@return
 //1 if an error occured, 0 else.
 //
  ExportedByCATSmoOperators
    int InitRun();


  //
  //Run operator.
  //@return
  //1 if an error occured, 0 else.
  //
  ExportedByCATSmoOperators
    int Run();

private:
  
  int GetEdgePointInMultiresMode();

  //---- Data :
  CATSobEdge& m_sobEdge;

  int _Level;
  int _Size;                             //Nbre de points par rangées
  CATMathPoint* _TabPoints;
  CATBoolean _AlreadyRun;                //TRUE si le run a déjà été fait
};

#endif  //CATSmoEdgeData_H


