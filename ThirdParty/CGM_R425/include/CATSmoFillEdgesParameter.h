//======================================================================
// Copyright Dassault Systemes Provence 2017, All Rights Reserved
//======================================================================
//
// CATSmoFillEdgesParameter.h
//
//======================================================================
//
// Usage notes : Paramètres pour les opérateurs 
// CATSmoFillBasicOperator et CATSmoFillNEdgesOperator
//
//======================================================================
// 13.02.2023 : RBD : Ajout SetAutoWeight() : _AutoWeight prend  les valeurs 0 à 3 inclus.
// 19.11.2017 : RBD : Creation d'après CATSmoExtrudeFacesParameter de RAQ
//======================================================================
#ifndef CATSmoFillEdgesParameter_H
#define CATSmoFillEdgesParameter_H

//Pour l'export
#include "CATSmoOperators.h"

//Monocodage OS
#include "CATLib.h"

//Subdivision
#include "CATSobAddRefRelease.h"
#include "CATSobListOfEdge.h"

#include "CATBoolean.h"

class CATSobEdge;


class ExportedByCATSmoOperators CATSmoFillEdgesParameter
{
  SOB_DECLARE_ADDREF_RELEASE;

public:
  //-----------------------------------------------------------------------------
  //Constructeurs
  //-----------------------------------------------------------------------------
  CATSmoFillEdgesParameter(const CATLISTP(CATSobEdge)& iEdgesToFill);
  CATSmoFillEdgesParameter(const CATSmoFillEdgesParameter& iToCopy);

  //--------------------------------------------------------------------------------------
  // SetSymmetry for CATSmoFillNEdgesOperator operator only
  void SetSymmetry(CATBoolean iSymmetry);

  //---------------
  //For CATSmoFillNEdgesOperator operator only
  //Set (or unset) AutoWeight on Vertices
  //---------------
  void SetAutoWeight(const int& iAutoWeight);

  //--------------------------------------------------------------------------------------
  //For CATSmoFillNEdgesOperator operator only
  //this method returns 1 if the symmetry treatment  is successful
  //this method returns 0  if there is not  symmetry axis or if the symmetry treatment 
  //has failed. The result is not necessary symmetrical. 
  CATBoolean IsResultWithSymmetryTreatment();

  //-=-=-=-=-=-=-=-
  //-------- Data:
  CATLISTP(CATSobEdge)  _EdgesToFill;
  CATBoolean            _Symmetry;
  int                   _AutoWeight;
  CATBoolean            _SymmetricalResult;

private:
  //Destructor
  ~CATSmoFillEdgesParameter() {}

};


#endif  // CATSmoFillEdgesParameter_H



