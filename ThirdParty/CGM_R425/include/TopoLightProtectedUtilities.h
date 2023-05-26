#ifndef TopoLightProtectedUtilities_h
#define TopoLightProtectedUtilities_h

#include "ExportedByPBELight.h"
#include "CATBoolean.h"

class CATBody;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCell;
class CATCGMJournalList;
class CATListPtrListPOfCATCell;
class CATListPtrCATFace;
class CATSurLimits;
class CATSurface;
class CATListValShort;
class CATListPtrCATCrvLimits;
class CATListPtrCATPCurve;
class CATListPtrCATCell;

#ifndef NULL
#define NULL 0
#endif

class ExportedByPBELight TopoLightProtectedUtilities
{
public:

  /** @nodoc @nocgmitf */
  static CATCell * GetCellThroughLayDown(CATBody * iOneVertexBody,
    CATBody * iBodySupport,
    CATGeoFactory * iFactory,
    CATSoftwareConfiguration * iConfig);

  /** @nodoc @nocgmitf */
  static CATBody * Boundary(CATGeoFactory * iFactory,
    CATSoftwareConfiguration * iConfig,
    CATBody * iInput,
    CATCGMJournalList * iJournal = NULL);

  /** @nodoc @nocgmitf */
  static CATBody * DisconnectShell(CATGeoFactory * iFactory,
    CATSoftwareConfiguration * iConfig,
    CATBody * iBodyToDisconnect,
    CATBody * iDisconnectingBody,
    CATCGMJournalList * iJournal = NULL,
    CATListPtrListPOfCATCell * oPacks = NULL);

  /** @nodoc @nocgmitf */
  static CATBody * CreateLocalUntrimFromGlobalUntrim(CATGeoFactory * iFactory,
    CATSoftwareConfiguration * iConfig,
    CATBody * iBodyToUntrim,
    CATBody * iGlobalUntrim,
    CATListPtrCATCell & iEdgesToExtend);

  /** @nodoc @nocgmitf */
  static CATBoolean IsAThinFace(CATCell * ipFace,
    CATGeoFactory * ipFactory,
    CATSoftwareConfiguration * ipConfig,
    double iTolerance);

  /** @nodoc @nocgmitf */
  static void DetectThinFaces(CATGeoFactory* ipFactory,CATSoftwareConfiguration* ipConfig,
                              CATBody* ipBody, double iTolerance,CATListPtrCATFace& oThinFaces);

  /** @nodoc @nocgmitf */
  static CATBoolean AreFacesCoincident(CATGeoFactory * iFactory,
    CATSoftwareConfiguration * iConfig,
    CATCell * iCell1,
    CATCell * iCell2,
    double iTolerance);

  /** @nodoc @nocgmitf */
  static CATBody * CreateBodyFromSurfaceAndSurLimits(
    CATGeoFactory & iFactory,
    CATSoftwareConfiguration & iConfig,
    CATSurface & iSurface,
    CATSurLimits & iSurLimits,
    CATCGMJournalList * iJournal = NULL,
    CATBoolean iUseGeometriesInJournalItems = TRUE);

  /** @nodoc @nocgmitf */
  static CATBody * CreateBodyFromSurfaceAndMaxLimits(
    CATGeoFactory & iFactory,
    CATSoftwareConfiguration & iConfig,
    CATSurface & iSurface,
    CATCGMJournalList * iJournal = NULL,
    CATBoolean iUseGeometriesInJournalItems = TRUE);

  /** @nodoc @nocgmitf */
  static CATBody * CreateBodyFromSurfaceAndPCurves(
    CATSoftwareConfiguration & iConfig,
    CATSurface & iSurface,
    CATListPtrCATPCurve & iPCurves,
    CATListPtrCATCrvLimits & iCrvLimits,
    CATListValShort & iOriPCurvesVsLoop,
    CATCGMJournalList * iJournal = NULL,
    CATBoolean iUseGeometriesInJournalItems = TRUE);
};

#endif
