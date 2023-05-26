#ifndef CATTopSplitByClosedSurface_h
#define CATTopSplitByClosedSurface_h

#include "CATDynOperatorDef.h"
#include "ExportedByBONEWOPE.h"

class CATBody;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCGMJournalList;

/**
* Split iBodyToSplit by iSplittingBody.
* iSplittingBody must be a body containing exacty 1 (ONE) shell.
* The shell MUST be closed.
* Allowed values for iSplitType are CATSplitPositiveSideOnly or CATSplitNegativeSideOnly.
*/

ExportedByBONEWOPE CATBody * CATTopSplitByClosedSurface(CATGeoFactory * iFactory,
                                                        CATSoftwareConfiguration * iConfig,
                                                        CATCGMJournalList * iJournal,
                                                        CATBody * iBodyToSplit,
                                                        CATBody * iSplittingBody,
                                                        CATDynSplitType iSplitType);

#endif

