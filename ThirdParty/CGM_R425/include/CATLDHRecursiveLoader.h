#ifndef CATLDHRecursiveLoader_h_
#define CATLDHRecursiveLoader_h_

#include "SGComposites.h"

// SGInfra (PublicInterfaces)
#include "CATRep.h"
#include "CATRepPath.h"
#include "CAT4x4Matrix.h"
// SGInfra (ProtectedInterfaces)
#include "CATLDHLoadFilters.h"

// VisualizationInterfaces (PublicInterfaces)
#include "CATPathElement.h"
#include "CATListOfCATPathElement.h"

class CATSGContext;
class CATCompOutOfCore;

#include <unordered_map>
#include <unordered_set>
#include <vector>

class ExportedBySGComposites CATLDHRecursiveLoader
{
    typedef std::unordered_map<CATRep*, bool> VisitedReps;
    typedef std::unordered_set<CATCompOutOfCore*> LockedReps;

public:
    CATLDHRecursiveLoader(CATSGContext& iSGContext, bool iKeepLoadedUntilRelease = false);
    ~CATLDHRecursiveLoader();


    // From CATRep
    // -----------

    HRESULT ForceLoad(CATRep* iRootRep);
    HRESULT ForceUnload(CATRep* iRootRep);

    HRESULT ForceLoad(const std::vector<CATRep*>& iRepList);
    HRESULT ForceUnload(const std::vector<CATRep*>& iRepList);

    // From CATRepPath
    // ---------------

    HRESULT ForceLoad(CATRepPath& iRepPath);
    HRESULT ForceUnload(CATRepPath& iRepPath);

    HRESULT ForceLoad(const std::vector<CATRepPath*>& iRepPathList);
    HRESULT ForceUnload(const std::vector<CATRepPath*>& iRepPathList);

    // From CATRepPath, with filter
    // ----------------------------

    HRESULT ForceLoad(CATRepPath& iRepPath, const CATLDHBaseLoadFilter& iFilter);
    HRESULT ForceUnload(CATRepPath& iRepPath, const CATLDHBaseLoadFilter& iFilter);

    HRESULT ForceLoad(const std::vector<CATRepPath*>& iRepPathList, const CATLDHBaseLoadFilter& iFilter);
    HRESULT ForceUnload(const std::vector<CATRepPath*>& iRepPathList, const CATLDHBaseLoadFilter& iFilter);


    HRESULT ForceRelease();


private:
    HRESULT VisitRep(CATRep* iRep, const CATLDHBaseLoadFilter& iFilter, const CAT4x4Matrix& iGlobalMatrix = CAT4x4Matrix());
    HRESULT VisitRepPath(CATRepPath* iRepPath, const CATLDHBaseLoadFilter& iFilter);

    HRESULT ForceLoadOnVisitedReps();
    HRESULT ForceUnloadOnVisitedReps();

    void ClearVisitedReps();

private:
    CATSGContext&   _sgContext;
    VisitedReps     _visitedReps;
    LockedReps      _lockedReps;
    bool            _keepLoadedUntilRelease;
};

#endif // !CATLDHRecursiveLoader_h_
