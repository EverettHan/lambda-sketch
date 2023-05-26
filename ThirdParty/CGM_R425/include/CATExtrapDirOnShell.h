/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2001
//------------------------------------------------------------------------------
//
// NE PAS INTERFACER EN PHASE 2 (LAP 10/10/2007)
// DO NOT INTERFACE IN PHASE 2 WITH CATIPGM....
// DO NOT USE IN PHASE 2  CATIAV6...
// DO NOT USE IN PHASE 1  CATIAV5...
//
//------------------------------------------------------------------------------
//      
// CATExtrapolOpWireOnShell :
//      
// Extrapolation d'un body filaire pose sur un body surfacique shell.
//
//
//------------------------------------------------------------------------------
// Creation JHN
//
// 
// NE PAS UTILISER / DO NOT USE
//------------------------------------------------------------------------------
//
#ifndef CATExtrapDirOnShell_h
#define CATExtrapDirOnShell_h

//------------------------------------------------------------------------------
#include "CATTopOperator.h"
#include "HybOper.h"
class CATMathVector;
/**
 * Do not use.
 * Interface representing a topological operation of extrapolation of a wire 
 * CATBody 
 */
class ExportedByHybOper CATExtrapDirOnShell : public CATTopOperator
{
public:
  //  Constructor
  CATExtrapDirOnShell( CATGeoFactory * iFactory, 
    CATTopData    * iTopData );
  //  Destructor
  virtual ~CATExtrapDirOnShell();     


  // Execution of the operator
  virtual int Run()=0;
  
  // Get the resulting Body
  virtual CATBody * GetResult()=0;
  virtual CATBody * GetResult(CATCGMJournalList * iJournal)=0;
  virtual void  SetLength(double iLgth)=0;


};


ExportedByHybOper CATExtrapDirOnShell * CATCreateExtrapDirOnShell(
                            CATGeoFactory * iFactory, 
			                      CATTopData    * iTopData,
                            CATBody       * iBodyVertex,
                            const CATMathVector * iDirToExtrap,
			                      CATBody       * iBodyShell);

#endif











