#ifndef CATSGPair_h_
#define CATSGPair_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

template<typename T0, typename T1>
class CATSGPair
{
public:
    CATSGPair()
    {
        Invalidate();
    }
    CATSGPair(const T0& iT0, const T1& iT1) : _first(iT0), _second(iT1)
    {
    }
    ~CATSGPair()
    {
        Invalidate();
    }

    bool IsValid()
    {
        if (_first == NAT<T0>::value()
            || _second == NAT<T1>::value())
        {
            return false;
        }
        return true;
    }
    void Invalidate()
    {
        _first = NAT<T0>::value();
        _second = NAT<T1>::value();
    }

    bool operator==(const CATSGPair<T0, T1>& iOther) const
    {
        return ((_first == iOther._first) && (_second == iOther._second)) ? true : false;
    }
    bool operator>(const CATSGPair<T0, T1>& iOther) const
    {
        return (_first > iOther._first) || (_first == iOther._first && _second > iOther._second);
    }

    const T0& CFirst() const
    {
        return _first;
    }

    const T1& CSecond() const
    {
        return _second;
    }

    T0& First()
    {
        return _first;
    }

    T1& Second()
    {
        return _second;
    }

    static CATSGPair<T0, T1> NaTValue()
    {
        return CATSGPair<T0, T1>();
    }

private:
    T0 _first;
    T1 _second;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGPair_h_
