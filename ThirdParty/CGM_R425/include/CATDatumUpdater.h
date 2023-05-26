#ifndef CATDatumUpdater_h
#define CATDatumUpdater_h 1

// CATManifoldUpdater
#include "CATGMLiveShapeUpdater.h"
//#include "CATGMLiveOperator.h"
#include "AdvTrimOpe.h"
#include "ListPOfCATDeclarativeManifold.h"

class CATDatumUpdaterImpl;
class CATGeoFactory;
class CATTopData;
class CATGMLiveInfra;

class CATDatumUpdater : public CATGMLiveShapeUpdater
{
  public:
    //## Constructors (generated)
      CATDatumUpdater(CATGeoFactory  *  iGeoFactory,  CATTopData  *  iData, CATDatumUpdaterImpl * iImpl);

    //## Destructor (generated)
      virtual ~CATDatumUpdater();
};


ExportedByCATGMLiveOperator CATDatumUpdater  *  CATCreateDatumUpdater(CATGeoFactory                 & iFactory,
                                                                          CATPersistentBody & iInputPersistentBody,
                                                                                CATTopData                    & iTopData,
                                                                                CATGMLiveInfra                & iLiveInfra,
                                                                                ListPOfCATDeclarativeManifold & iDecl,
                                                                                CATCGMJournalList             * iJournal,
                                                                                int                             iNumOperatorId);
                                                                                

#endif
