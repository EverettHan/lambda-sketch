#ifndef _CATTopWireRedondancyOpe
#define _CATTopWireRedondancyOpe

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "Parallel.h"
#include "CATTopRedondancyOpe.h"

class CATTopSolution;
class CATDomain;

class ExportedByParallel CATTopWireRedondancyOpe : public CATTopRedondancyOpe
{
public:
	CATTopWireRedondancyOpe (CATLONG32 inbdom, CATBody ** iDoms, CATLONG32 inbsols, CATTopSolution ** iListOfSols, CATSoftwareConfiguration * iSoftConf) ;
	~CATTopWireRedondancyOpe ();
	virtual void SearchConfondability(CATLONG32 & onbcouples,CATLONG32 * oSolCouples[2]);
	virtual CATLONG32 SearchRepresentation (CATLONG32 iNbEquiv,CATTopSolution ** iSolEquiv, CATTopSolution * & oRep);
};

#endif

