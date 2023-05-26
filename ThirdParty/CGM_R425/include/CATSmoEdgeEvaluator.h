//==================================================================================
// Copyright Dassault Systemes Provence 2005, All Rights Reserved 
//==================================================================================
//
// CATSmoEdgeEvaluator.h
//
//==================================================================================
//
// Usage notes: Evaluation d'une edge pour le calcul du plus court chemin.
//              On peut cr�er une classe d�riv�e de celle-ci pour impl�menter
//              d'autres �valuateurs.
//
//==================================================================================
// 26.04.2019 : RAQ : Correction IR-679270-3DEXPERIENCER2020x (pb symbol sous linux)
// February,  2011 : RAQ : Ajout CATSmoEdgeLengthEvaluator + nettoyage de printemps
// August,  2005 : RNO : Cr�ation
//==================================================================================
#ifndef CATSmoEdgeEvaluator_H
#define CATSmoEdgeEvaluator_H

#include "CATSmoOperators.h"

class CATSobEdge;
class CATSobVertex;


/////////////////////////////////////////////
// Evaluateur par d�faut, compteur d'edges
/////////////////////////////////////////////
class ExportedByCATSmoOperators CATSmoEdgeEvaluator
{
public:

  //'ctors
  CATSmoEdgeEvaluator() {}
  virtual ~CATSmoEdgeEvaluator() {}

  //Evaluation de l'edge par d�faut : �valuateur pour compteur, chaque edge vaut 1
  virtual double Eval(CATSobEdge* iEdge, const CATSobVertex* iFromVertex = 0) { return 1.0; }

private :

  // Copy constructor and equal operator
  CATSmoEdgeEvaluator (CATSmoEdgeEvaluator &);
  CATSmoEdgeEvaluator& operator=(CATSmoEdgeEvaluator&);
};


//////////////////////////////////
// Evaluateur par longeur d'edge
//////////////////////////////////
class ExportedByCATSmoOperators CATSmoEdgeLengthEvaluator: public CATSmoEdgeEvaluator
{
public:

  //'ctors
  CATSmoEdgeLengthEvaluator():CATSmoEdgeEvaluator() {}
  virtual ~CATSmoEdgeLengthEvaluator() {}

  //Evaluation de l'edge
  virtual double Eval(CATSobEdge* iEdge, const CATSobVertex* iFromVertex = 0);

private :

  //Copy constructor and equal operator
  CATSmoEdgeLengthEvaluator(CATSmoEdgeLengthEvaluator&);
  CATSmoEdgeLengthEvaluator& operator=(CATSmoEdgeLengthEvaluator&);
};


///////////////////////////////////////////////////////////
// Evaluateur par compteur d'edges sharps :
// - si l'edge est une vraie sharp (interne, sharpness, pas de smoothing), l'�valuateur renvoie 1
// - sinon l'�valuateur retourne +Infinity (DBL_MAX)
///////////////////////////////////////////////////////////
class ExportedByCATSmoOperators CATSmoSharpEdgeCounterEvaluator: public CATSmoEdgeEvaluator
{
public:

  //'ctors
  CATSmoSharpEdgeCounterEvaluator():CATSmoEdgeEvaluator() {}
  virtual ~CATSmoSharpEdgeCounterEvaluator() {}

  //Evaluation de l'edge
  virtual double Eval(CATSobEdge* iEdge, const CATSobVertex* iFromVertex = 0);

private :

  //Copy constructor and equal operator
  CATSmoSharpEdgeCounterEvaluator(CATSmoSharpEdgeCounterEvaluator&);
  CATSmoSharpEdgeCounterEvaluator& operator=(CATSmoSharpEdgeCounterEvaluator&);
};


///////////////////////////////////////////////////////////
// Evaluateur par compteur d'edges de bord :
// - si l'edge est sur un bord, l'�valuateur renvoie 1
// - sinon l'�valuateur retourne +Infinity (DBL_MAX)
///////////////////////////////////////////////////////////
class CATSmoBoundaryEdgeCounterEvaluator : public CATSmoEdgeEvaluator
{
public:

  //'ctors
  ExportedByCATSmoOperators
    CATSmoBoundaryEdgeCounterEvaluator();
  
  ExportedByCATSmoOperators
    virtual ~CATSmoBoundaryEdgeCounterEvaluator();

  //Evaluation de l'edge
  ExportedByCATSmoOperators
    virtual double Eval(CATSobEdge* iEdge, const CATSobVertex* iFromVertex = 0);

private:

  //Copy constructor and equal operator
  CATSmoBoundaryEdgeCounterEvaluator(CATSmoBoundaryEdgeCounterEvaluator&);
  CATSmoBoundaryEdgeCounterEvaluator& operator=(CATSmoBoundaryEdgeCounterEvaluator&);
};


#endif
