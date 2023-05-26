#ifndef CATLDHLoadFilters_h_
#define CATLDHLoadFilters_h_

// SGInfra (ProtectedInterfaces)
#include "SGComposites.h"

// Mathematics (PublicInterfaces)
#include "CATMathPoint.h"

class CATRep;
class CAT4x4Matrix;

// CATLDHBaseLoadFilter
class ExportedBySGComposites CATLDHBaseLoadFilter
{
public:
    virtual bool operator()(CATRep* iRep, const CAT4x4Matrix& iGlobalMatrix) const
    {
        return true;
    }
};

// CATLDHAABoxLoadFilter
class ExportedBySGComposites CATLDHAABoxLoadFilter : public CATLDHBaseLoadFilter
{
public:
    CATLDHAABoxLoadFilter(const CATMathPoint& iMin, const CATMathPoint& iMax)
        : _min(iMin)
        , _max(iMax)
    {
    }
    virtual ~CATLDHAABoxLoadFilter()
    {
    }

protected:
    virtual bool IsPointInsideAABox(const CATMathPoint& iPoint) const;
    virtual bool IsSphereInsideAABox(const CATMathPoint& iSphereCenter, const double iSphereRadius) const;

protected:
    const CATMathPoint _min;
    const CATMathPoint _max;
};

// CATLDHInsideAABoxLoadFilter
class ExportedBySGComposites CATLDHInsideAABoxLoadFilter : public CATLDHAABoxLoadFilter
{
public:
    CATLDHInsideAABoxLoadFilter(const CATMathPoint& iMin, const CATMathPoint& iMax);
    virtual ~CATLDHInsideAABoxLoadFilter();

    virtual bool operator()(CATRep* iRep, const CAT4x4Matrix& iGlobalMatrix) const;
};

#endif // !CATLDHLoadFilters_h_
