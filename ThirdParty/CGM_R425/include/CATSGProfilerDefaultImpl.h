#ifndef CATSGProfilerDefaultImpl_h_
#define CATSGProfilerDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATSGComposite.h"
#include "CATSGProfiler.h"
#include "CATSGCompositeHost.h"
#include <unordered_map>

class ExportedBySGComposites CATSGProfilerDefaultImpl : public CATSGCompositeHost1<CATSGProfiler, CATSGComposite>
{
    typedef std::unordered_map<CATUnicodeString,float, Hash<CATUnicodeString>> StatMap;
public:
    CATSGProfilerDefaultImpl();
    virtual ~CATSGProfilerDefaultImpl();

    virtual bool DoesStatExist(const CATUnicodeString &iStatName) const;

    virtual HRESULT GetStatValue(const CATUnicodeString &iStatName, float &oStatValue) const;
    virtual HRESULT SetStatValue(const CATUnicodeString &iStatName, float iStatValue);
    virtual HRESULT IncrementStatValue(const CATUnicodeString &iStatName);
    virtual HRESULT DecrementStatValue(const CATUnicodeString &iStatName);

    virtual HRESULT GetAllStats(std::vector<std::pair<CATUnicodeString, float> > &oStats) const;

    virtual CATSGTickTime GetTimeStamp();
private:
    StatMap       _map;
    CATSGTickTime _timerFreqInCountPerSeconds;
};

#endif    // SG_COMPOSITES_MULTIOS
#endif    // !CATSGProfilerDefaultImpl
