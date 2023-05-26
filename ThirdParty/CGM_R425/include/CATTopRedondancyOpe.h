#ifndef _CATTopRedondancyOpe_H
#define _CATTopRedondancyOpe_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "Parallel.h"
#include "CATDataType.h"
#include "CATMathInline.h"

class CATTopSolution;
class CATBody;
class CATSoftwareConfiguration;

class ExportedByParallel CATTopRedondancyOpe
{
public:
	CATTopRedondancyOpe (CATLONG32 inbdom, CATBody ** iDoms, CATLONG32 inbsols, CATTopSolution ** iListOfSols, CATSoftwareConfiguration * iSoftConf);
	~CATTopRedondancyOpe ();
  INLINE CATSoftwareConfiguration* GetSoftwareConfiguration() const;
	void RunElimination();  // lancer le calcul d elimintation de solution
	CATLONG32 GetNbSolutions() ;  // recuperation du nombre de solutions
	CATLONG32 GetSolutions(CATLONG32 inum, CATLONG32 & oNumSol, CATTopSolution *& CurSol); // recuperation des solutions par leur numero
	virtual void SearchConfondability(CATLONG32 & onbcouples,CATLONG32 * ioSolCouples[2])=0;
	virtual CATLONG32 SearchRepresentation (CATLONG32 iNbEquiv,CATTopSolution ** iSolEquiv, CATTopSolution * & oRep)=0;
protected :
	void SetConfondability() ;
	void SetRedondancy() ;
	void SetRedondancyClass() ;
	void SetSolutions();
  //short _LevelToExecute;
	CATLONG32 _NbDom;
	CATBody ** _Domains;
	CATLONG32 _NbSolIni;
	CATTopSolution ** _SolIni;
	CATLONG32 _NbStoredSols;
	CATTopSolution ** _StoredSols;
	CATLONG32 * _NewSols;
  CATSoftwareConfiguration * _Config;
};

//------------------------------------------------------------------------------
// GetSoftwareConfiguration
//------------------------------------------------------------------------------
INLINE CATSoftwareConfiguration* CATTopRedondancyOpe::GetSoftwareConfiguration() const
{
  return _Config;
}

#endif

