
#ifndef ECBodyUtilities_H
#define ECBodyUtilities_H

#include "ListPOfCATBody.h"
#include "CATListOfCATICGMObjects.h"
#include "CATSurLimits.h"
#include "CATCGMJournal.h"

class CATGeoFactory;
class CATTopData;
class CATSoftwareConfiguration;
class CATBody;
class CATSurface;
class CATCGMJournalList;
class CATICGMObject;
class CATCGMJournal;

class  ECBodyUtilities
{
public:

    static int Save( CATBody * iBody,  const char *  iFileName ) ;
    static int Save( CATListPtrCATBody &  iBodies, const char * iFileName) ;
    static int Save( CATLISTP(CATICGMObject) & iObjList, const char * iFileName );
    static  CATBody   * MakeBodyFromSurface( CATTopData * iTopData,
										  CATSurface * iSurface, 
										  CATSurLimits * iLimits = NULL,
										  bool			iAllowInfinite = false);
                                           // just combine the domains into one body
	static CATBody *Combine(CATSoftwareConfiguration *iConfig, CATLISTP(CATBody) &iBodyList);

    // Makes a copy of the body that SHARES all topology
	static CATBody* CreateBody(CATBody *iBody);
	static CATBody* CopyBody(CATBody* iCopy);

    // cloning a body into its own factory if iFactory == NULL default iType is Creation
    // can be also Modification : that will be the JournalItem type for the Journal.
    static CATBody *   Clone( CATBody *                   iBody,
		                      CATCGMJournalList *         ioJournal = NULL,
                              CATGeoFactory     *         iFactory = NULL,
						      CATCGMJournal::Type    iType  = CATCGMJournal::Creation   ) ;
    static CATBody *   Clone( CATBody *                   iBody,
							  CATGeoFactory *             iFactory,
		                      CATCGMJournalList *         ioJournal,
                              CATLISTP(CATICGMObject)&	  iOrigGeoms,
							  CATLISTP(CATICGMObject)&	  ioClonedGeoms   ) ;
    static void    RemoveBodies(CATLISTP(CATBody)& ioBodies);

};

#endif


