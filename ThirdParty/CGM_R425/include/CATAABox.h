#ifndef CATAABox_h_
#define CATAABox_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

class ExportedBySGComposites CATAABox
{
public:
    CATAABox();
    CATAABox(const CATMathPointf& iCenter, const CATMathVectorf& iHalfSize);
    CATAABox(const CATMathPointf& iMin, const CATMathPointf& iMax, int iCtorTag);
    CATAABox(const CATAABox& iOther);
    ~CATAABox();

    void Set(const CATMathPointf& iMin, const CATMathPointf& iMax, int /*iCtorTag*/);

    bool IsValid() const;
    void Invalidate();

    CATMathPointf GetMax() const;
    CATMathPointf GetMin() const;

    const CATMathPointf& GetCenter() const;
    const CATMathVectorf& GetHalfSize() const;
    CATMathVectorf GetSize() const;

    bool Overlap(const CATAABox& iOther) const;
    bool IsDisjoint(const CATAABox& iOther) const;
    bool Intersect(const CATAABox& iOther, CATAABox& oIntersection) const;
    bool IsSimilar(const CATAABox& iOther) const;
    bool Contains(const CATAABox& iOther) const;

    void AddContent(const CATAABox& iContent);

private:
    CATMathPointf   _center;
    CATMathVectorf  _halfSize;
};

template <>
struct NAT<CATAABox>
{
    // Default ctor return an invalid box thus no need to call
    // invalidate on it.
    static CATAABox value() { return CATAABox(); }
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATAABox_h_
