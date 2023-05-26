#ifndef _CATOpeSupport
#define _CATOpeSupport

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "Parallel.h"
#include "CATCGAMEM.h"

class CATBody;

class ExportedByParallel CATOpeSupport
{ public :

	CATOpeSupport();
//	CATOpeSupport(CATLONG32 iNbSupp);
//	CATOpeSupport(CATBody * iSupport, CATBody * icontact, CATLONG32 iDom, CATLONG32 iCell);
	~CATOpeSupport();
//  void SetNbSupp(CATLONG32 iNbSupp);
	CATBody * _Support;
	CATBody * _ContactOnSupport;
	CATLONG32 _NumDomSupport;
	CATLONG32 * _NumCellSupport;
	CATLONG32 _NbSupport;
};


#endif

