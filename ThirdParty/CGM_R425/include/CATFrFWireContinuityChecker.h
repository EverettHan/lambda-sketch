//============================================================================================
// Copyright Dassault Systemes Provence 2013, All Rights Reserved
//============================================================================================
//
// CATFrFWireContinuityChecker.h
//
//============================================================================================
//
// Usage notes: Operator to eval the continuity at a wire CATVertex.
//
//============================================================================================
// 27.08.2013 : RAQ : Modif commentaires
// 14.05.2013 : RAQ : Creation
//============================================================================================
#ifndef CATFrFWireContinuityChecker_H
#define CATFrFWireContinuityChecker_H

//Pour l'export
#include "FrFAdvancedOpeSur.h"

class CATSoftwareConfiguration;
class CATGeoFactory;
class CATWire;
class CATVertex;


class ExportedByFrFAdvancedOpeSur CATFrFWireContinuityChecker
{
public:

  //Destructeur
  virtual ~CATFrFWireContinuityChecker() {}

  //Runs the operator at a wire vertex and outputs the geometric continuity, returns 0 if successful
  virtual int Run(CATVertex* iVertex    ,
                  int      & oContinuity) = 0;


protected:

  //Constructeur
  CATFrFWireContinuityChecker() {}


private:

  //No default implementation
  CATFrFWireContinuityChecker           (const CATFrFWireContinuityChecker&);
  CATFrFWireContinuityChecker& operator=(const CATFrFWireContinuityChecker&);

};


/**
 * Creates the operator.
 *
 * @param iConfig
 * The config
 * @param iFactory
 * The factory
 * @param iWire
 * The wire
 * @param iContinuityTolerances
 * The tolerances to use : G0 in mm, G1 in rad, G2 as a percentage.
 *
 * @return
 * A pointer to the operator if creation successful.
 **/
ExportedByFrFAdvancedOpeSur
CATFrFWireContinuityChecker* CATCreateFrFWireContinuityChecker(CATSoftwareConfiguration* iConfig ,
                                                               CATGeoFactory           * iFactory,
                                                               CATWire                 * iWire   ,
                                                               double                    iContinuityTolerances[3]);

#endif  //CATFrFWireContinuityChecker_H


