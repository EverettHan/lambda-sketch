//===================================================================
// Copyright Dassault Systemes Provence 2012, All Rights Reserved
//===================================================================
//
// CATTopOpeTransformation.h
// Header definition of CATTopOpeTransformation
//
//===================================================================
//
// Usage notes: 
// Topological operator for match curve
// To create an instance of this class use :
// CATTopOpeTransformation* CATCreateTopTransfo(CATGeoFactory* iFactory, CATTopData* iTopData)
//
// See the mandatory setters to use this operator.
// use the method Run() to run it.
//
//===================================================================
//  Apr.  2012   : RBD : Creation Interface/implementation de l'operateur 
//===================================================================
#ifndef CATTopOpeTransformation_H
#define CATTopOpeTransformation_H

//Pour l'export
#include "TopoTransfo.h"
//Classe mère
#include "CATTopOperator.h"

#include "CATMathTransformation.h"

class CATBody;
class CATTopData;
class CATGeoFactory;


class ExportedByTopoTransfo CATTopOpeTransformation: public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopOpeTransformation);

public: 

	//Destructeur
  virtual ~CATTopOpeTransformation();

  //------------------
	// MANDATORY SETTERS
  //------------------

	/**
	* Set a body to transform with this operator
  * All the bodies must belong to the same factory
  * The body must contain a CATEdge cell.
	**/
//	virtual void AddInputBody(CATBody* iInputBody) = 0;

  //-----------------
	// OPTIONAL SETTERS
  //-----------------

	/**
	* Get the CATMathTransformation associated with this operator
  * oMathTransfo MUST NOT be deleted
	**/
//  virtual void GetMathTransformation(CATMathTransformation* &oMathTransfo) const = 0;


  //-----------------
	// OTHER USEFUL METHODS
  //-----------------
	/**

	/*
	* Runs the operator.
	*/
  //	virtual int Run() = 0;

  /** 
  * Gets the result of the operator.
  */
  virtual CATBody* GetResult() = 0;

//  int GetResult(CATLISTP(CATBody) &oListOfOutputBodies)

	/**
	* Journal de l'opérateur (via CATTopOperator)
	*/
  virtual CATCGMJournalList* GetJournal() = 0;

protected:
  // Constructeur
  CATTopOpeTransformation(CATGeoFactory* iFactory, 
                       CATTopData* iTopData);

private:
  // Non implemented methods
  CATTopOpeTransformation();
  CATTopOpeTransformation(CATTopOpeTransformation&);
  CATTopOpeTransformation& operator=(CATTopOpeTransformation&);

};

//-----------------------------------------------------------------------

ExportedByTopoTransfo
CATTopOpeTransformation* CATCreateTopOpeTransformation(const CATMathTransformation& iMathTransfo, CATBody* iInputBody, CATGeoFactory* iFactory, CATTopData* iTopData);

#endif
