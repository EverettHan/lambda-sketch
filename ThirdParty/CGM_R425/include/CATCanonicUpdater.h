#ifndef CATCanonicUpdater_h
#define CATCanonicUpdater_h 1

// CATManifoldUpdater
#include "CATGMLiveShapeUpdater.h"
#include "CATGMLiveOperator.h"
#include "ListPOfCATDeclarativeManifold.h"

class CATCanonicUpdaterImpl;
class CATGeoFactory;
class CATTopData;
class CATExtTopOperator;
class CATGMLiveInfra;

class CATCanonicUpdater : public CATGMLiveShapeUpdater
{
  public:
    //## Constructors (generated)
      CATCanonicUpdater(CATGeoFactory  *  iGeoFactory,  CATTopData  *  iData, CATCanonicUpdaterImpl * iImpl);

    //## Destructor (generated)
      virtual ~CATCanonicUpdater();
};


ExportedByCATGMLiveOperator CATCanonicUpdater  *  CATCreateCanonicUpdater(CATGeoFactory                 & iFactory,
                                                                          CATPersistentBody & iInputPersistentBody,
                                                                                CATTopData                    & iTopData,
                                                                                CATGMLiveInfra                & iLiveInfra,
                                                                                ListPOfCATDeclarativeManifold & iDecl,
                                                                                CATCGMJournalList             * iJournal,
                                                                                int                             iNumOperatorId);

#endif
