#ifndef _CATTopSolution
#define _CATTopSolution
// COPYRIGHT DASSAULT SYSTEMES 2000
#include "Parallel.h"
#include "CATCGAMEM.h"
#include "CATTopData.h"

class CATDomain;
class CATBody;
class CATOpeSupport;
class CATTopFreeSol;
class CATTopConfondability;
class CATTopCornerSolution;

typedef enum ST{CATCornerSolType, CATLineSolType} CATSolutionType;

class ExportedByParallel CATTopSolution
{
public:
CATTopSolution (CATTopData * iData, CATLONG32 iNbsupp, CATOpeSupport * iTabSupport,CATBody * iSolution);
virtual ~CATTopSolution();
void GetBody(CATBody *& oBody);  // body solution
void GetSupport(CATLONG32 iNumieme, CATBody *& oAppui);
void GetSupportSolution (CATLONG32 iNumieme, CATLONG32 & numdom, CATLONG32 & numcell, CATBody *& oSolAppui);  // rend le nieme support
void GetAllSupportSolution (CATLONG32 iNumieme, CATLONG32 & numdom, CATLONG32 & nbcells, CATLONG32 *&onumcells, CATBody *& oSolAppui);  // rend le nieme support
//virtual void GetConfondability(CATTopSolution * oConfondableSol,CATLONG32 inbsupports, CATTopConfondability ** iTabConfondability,CATBoolean & oConfondable); // indique si deux solutions sont confondables
virtual void GetEquality(CATSoftwareConfiguration * iConfig, const CATTopSolution * iEqualSol, CATLONG32 inbsupports, CATBody ** iDomains, CATBoolean & oEquality); // indique si deux solutions sont egales. Illes sont egales si GetConfusion et GetSupportConfusion rendent vrai
//virtual void IsBetterSolution(CATTopSolution * iBetterSol, CATBoolean & oBetter); //indique la meilleure des deux solutions
 void GetContact(CATLONG32 inum, CATBody *& oContact);
 void SetOpeSupport(CATLONG32 inbsupp, CATOpeSupport * DescSupp);
 void GetCornerSolution(CATTopCornerSolution *& oCornSol) const ;
//
 virtual CATSolutionType GetSolutionType() const = 0;
virtual void Duplicate(CATTopSolution *& oRep)=0; // prend une zone de non confusion entre deux solutions et indique si cette zone peut etre ignoree ou non
protected :
virtual void GetConfusion(CATSoftwareConfiguration * iConfig, const CATTopSolution * iEqualSol, CATTopFreeSol *&  FreeSol, CATBoolean & oSupportConfusion) ; //indiquent si deux solution sont partiellement confondues et donnent les zones ou elles ne sont pas partiellement confondues
virtual void GetSupportConfusion(const CATTopSolution * iEqualSol, CATTopFreeSol * Freesol, CATBoolean & oSupportConfusion); // prend une zone de non confusion entre deux solutions et indique si cette zone peut etre ignoree ou non
protected :
  CATTopData _CurData;
	CATOpeSupport * _Support;
	CATLONG32 _NbSupp;
	CATBody * _Sol;
};


#endif

