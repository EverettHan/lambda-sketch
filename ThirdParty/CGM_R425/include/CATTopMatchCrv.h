//===================================================================
// Copyright Dassault Systemes Provence 2011, All Rights Reserved
//===================================================================
//
// CATTopMatchCrv.h
// Header definition of CATTopMatchCrv
//
//===================================================================
//
// Usage notes: 
// Topological operator for match curve
// To create an instance of this class use :
// CATTopMatchCrv* CATCreateTopMatchCrv(CATGeoFactory* iFactory, CATTopData* iTopData)
//
// See the mandatory setters to use this operator.
// call IsInit() to know if this operator is correctly initialized
// use the method Run() to run it.
//
//===================================================================
//  Febr  2013   : RBD : GetGlobalParams
//  Dec.  2011   : RBD : Creation Interface/implementation de l'operateur 
//===================================================================
#ifndef CATTopMatchCrv_H
#define CATTopMatchCrv_H

//Pour l'export
#include "TopoMatch.h"
//Classe mère
#include "CATTopOperator.h"

#include "CATBoolean.h"
class CATBody;

class CATTopData;
class CATGeoFactory;



class ExportedByTopoMatch CATTopMatchCrv: public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopMatchCrv);

public: 

	//Destructeur
  virtual ~CATTopMatchCrv();

  //------------------
	// MANDATORY SETTERS
  //------------------

	/**
	* Set the reference body (= target body curve) to the operator.
  * The body must contain a CATEdge cell.
	**/
	virtual void SetRefBody(CATBody* iBodyRef) = 0;

	/**
	* Set the body to be matched (= moving body curve) to the operator.
  * The body must contain a CATEdge cell.
	**/
	virtual void Set2BMatchedBody(CATBody* iBody2BMatched) = 0;

  //-----------------
	// OPTIONAL SETTERS
  //-----------------
	/**
	* Set/Get global parameters (between 0. and 1.) on each body to the operator.
  * (If the global parameters are not set, the algorithm compute the best guess between each end curve).
	**/
	virtual void SetGlobalParams(const double iGlobalParOnRef, const double iGlobalParOn2BMatched) = 0;
	virtual void GetGlobalParams(double &oGlobalParOnRef, double &oGlobalParOn2BMatched) = 0;

	/**
	* Set/Get the type of transition continuity.
  *  -1  : No continuity (free)
  *   0  : G0 (Default)
  *   1  : Colinear tangents (G1) (same or opposite direction, see SetG1Side below)
  *        plus G0     
  *   2  : Curvature continuity (G2) 
  *        plus G1 and G0
  *   3  : G3 continuity 
  *        plus G2, G1 and G0
	**/
  virtual void SetTransitionContinuity(const int iContinuity = 0) = 0;
  virtual int  GetTransitionContinuity() = 0; 

  /**
	* Set/Get the tolerances for transition continuity.
  * TolG0 homogène à une longueur
  * TolG1 homogène à un angle (en degres)
  * TolG2Angle homogene a un angle (en degres)
  * TolG2Curvature homogene a un pourcentage
  * TolG3 homogene a un angle (en degres)
  **/
  virtual void SetTransitionTolerances(const double iTolG0 = 0.0, 
                                       const double iTolG1 = 0.0, 
                                       const double iTolG2Angle = 0.0, 
                                       const double iTolG2Curvature = 0.0,
                                       const double iTolG3 = 0.0) = 0;

  virtual void GetTransitionTolerances(double &oTolG0, 
                                       double &oTolG1, 
                                       double &oTolG2Angle,
                                       double &oTolG2Curvature,
                                       double &oTolG3) = 0;

  /**
	* Get the errors for transition continuity.
  * oErrG0 homogène à une longueur
  * oErrG1 homogène à un angle (en degres) entre 0 et 180 degres
  * oErrG2Angle homogene a un angle (en degres) entre 0 et 180 degres
  * oErrG2Curvature homogene a un pourcentage
  * oErrG3 homogene a un angle (en degres) entre 0 et 180 degres
  **/ 
  virtual void GetTransitionError(double &oErrG0, 
                                  double &oErrG1, 
                                  double &oErrG2Angle,
                                  double &oErrG2Curvature,
                                  double &oErrG3) = 0;

	/**
	* Set side for the G1 continuity to the operator
  * This parameter is irrelevant if the transition continuity is set to zero.
  *   +1  : tangents on the reference body and the body to be matched must be on the same direction.
  *    0  : Best guess by the algorithm (auto mode)
  *   -1  : tangents are on opposite direction.
	**/
  virtual void SetG1Side(const int iSide = 0) = 0;
  virtual int GetG1Side() const = 0;

  /**
  * Defining the ratio (> 0.0) DefaultTensionTangency/RealTensionTangency 
  * 1.0 is default ; if the setted value is not valid, the ratio is set to the default value 1.0;
  */
  virtual void SetTangencyRatio(const double iTangencyRatio = 1.0) = 0;
  virtual double GetTangencyRatio() const = 0;


  /**
  * Set a constraint on the opposite side of the body to be matched (=  moving body curve),
  *  -1 : None (the opposite side is free to move)
  *   0 : G0 (Default)
  *   1 : G1
  *   2 : G2 
  *   3 : G3  (NOT YET IMPLEMENTED)
  */
  virtual void SetOppositeConstraint(const int iOppConst = 0) = 0;

  /**
  * Get the constraint on the opposite side of the body to be matched (=  moving body curve),
  *  -1 : None (the opposite side is free to move)
  *   0 : G0 (Default)
  *   1 : G1
  *   2 : G2 
  *   3 : G3  (NOT YET IMPLEMENTED)
  */
  virtual int GetOppositeConstraint() const  = 0;

  /**
  * Set the deformation mode on the body to be matched (=  moving body curve),
  * FALSE : Matching creates only a local deformation according to the transition continuity.
  * TRUE  : (Default) Deformation will be equally diffused along the the body to be matched.
  */
  virtual void SetPropagation(const CATBoolean iPropag=TRUE) = 0;

  /**
  * Get the deformation mode on the body to be matched (=  moving body curve),
  * FALSE : Matching creates only a local deformation according to the transition continuity.
  * TRUE  : Deformation will be equally diffused along the the body to be matched.
  */
  virtual CATBoolean GetPropagation() const = 0;

  //-----------------
	// OTHER USEFUL METHODS
  //-----------------
	/**
	* Returns true if the operator is correctly initialized (ready to run).
	*/
	virtual CATBoolean IsInit() = 0;

	/*
	* Runs the operator.
	*/
  //	virtual int Run() = 0;

  /** 
  * Gets the result of the operator.
  */
  virtual CATBody* GetResult() = 0;

	/**
	* Journal de l'opérateur (via CATTopOperator)
	*/
  virtual CATCGMJournalList* GetJournal() = 0;


protected:
  // Constructeur
  CATTopMatchCrv(CATGeoFactory* iFactory, CATTopData* iTopData);

private:
  // Non implemented methods
  CATTopMatchCrv();
  CATTopMatchCrv(CATTopMatchCrv&);
  CATTopMatchCrv& operator=(CATTopMatchCrv&);

};

//-----------------------------------------------------------------------

ExportedByTopoMatch
CATTopMatchCrv* CATCreateTopMatchCrv(CATGeoFactory* iFactory, CATTopData* iTopData);

#endif
