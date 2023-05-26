#ifndef _CATTopCornerSolution
#define _CATTopCornerSolution

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "Parallel.h"
#include "CATCGAMEM.h"
#include "CATTopSolution.h"

class CATDomain;
class CATBody;
class CATOpeSupport;
class CATTopFreeSol;
class CATTopConfondability;

class ExportedByParallel CATTopCornerSolution : public CATTopSolution
{
public:
CATTopCornerSolution (CATTopData * iData, CATBody * iSolution, CATOpeSupport * iTabSupport, CATLONG32 iNbsupp, CATBody * iCenter);
virtual ~CATTopCornerSolution();
virtual CATSolutionType GetSolutionType() const;
void GetCenter(CATBody *& oCenter);
virtual void Duplicate(CATTopSolution *& oRep); // prend une zone de non confusion entre deux solutions et indique si cette zone peut etre ignoree ou non
protected :
virtual void GetConfusion(CATSoftwareConfiguration * iConfig, const CATTopSolution * iEqualSol, CATTopFreeSol *&  FreeSol, CATBoolean & oSupportConfusion) ; //indiquent si deux solution sont partiellement confondues et donnent les zones ou elles ne sont pas partiellement confondues
virtual void GetSupportConfusion(const CATTopSolution * iEqualSol, CATTopFreeSol * Freesol, CATBoolean & oSupportConfusion); // prend une zone de non confusion entre deux solutions et indique si cette zone peut etre ignoree ou non
private :
	CATBody * _Center;
};


#endif

