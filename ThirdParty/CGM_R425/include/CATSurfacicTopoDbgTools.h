#ifndef CATSurfacicTopoDbgTools_h
#define CATSurfacicTopoDbgTools_h
#include "CATSurfacicTopoOperators.h"
#include "CATLib.h"
#include "ListPOfCATBody.h"

class CATBody;
class CATCGMJournalList;

class ExportedByCATSurfacicTopoOperators CATSurfacicTopoDbgTools
{
public :
	// les methodes ne sont pas exportees.
	// methodes de debug+stats commandees 
	// r
	static int dbgGetBodyStats( CATBody* ipBody, const char * iPrefixe) ;
	static int dbgDumpTimer( CATTimerId &iTimerId , const char * iPrefixe);
	static int dbgDumphumainTimer(CATULONG32 t, CATULONG32 &h, CATULONG32 &mn, CATULONG32 &s, CATULONG32 &ms);
	static void dbgPutNameColor(CATBody* ipBody, const char *ipName );
	static void dbgPutNameOnBodies(ListPOfCATBody &ilBodies, const char *ipPrefix);
	// dump all dimension(iDimension) cells of the input body. 
	static void dbgDumpBodyCells( CATBody* ipBody, const int iDimension ,const char * iPrefixe) ;
	// dump journal 
	static void dbgDumpJournal(CATCGMJournalList *ipJournal, const char *ipTitle, const int iTassBeforeDump=0);
	static void dbgDumpBodyCellsToFollow( CATBody* ipBody, const char * iPrefixe) ;
	static int dbgDumpSingularitiesStats(CATBody *ipBodyToCheck, const char *pDumpPrefixed,const double  tol);
};

#endif
