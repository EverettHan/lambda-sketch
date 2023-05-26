#ifndef CATSGArray_h_
#define CATSGArray_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include <mutex>

template<typename T, template<class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy>
class CATSGArray
{
public:
    typedef CATSGArray<T, LifeCyclePolicy> ArrayType;

    class ConstIterator {
        friend class CATSGArray<T, LifeCyclePolicy>;

    public:
        ConstIterator() : _vec(NULL), _cursor(-1) {}
        ConstIterator(const CATSGArray<T, LifeCyclePolicy>* iVec, int iIndex) : _vec(iVec), _cursor(iIndex) {}
        ConstIterator(const ConstIterator& iOther) : _vec(iOther._vec), _cursor(iOther._cursor) {}
        ~ConstIterator() { _vec = NULL; _cursor = -1; }

        inline ConstIterator& operator++() { ++_cursor; return *this; }
        inline ConstIterator& operator--() { --_cursor; return *this; }
        inline bool operator==(const ConstIterator& iOther) const
        {
            return ((_vec == iOther._vec) && (_cursor == iOther._cursor)) ? true : false;
        }

        inline bool operator!=(const ConstIterator& iOther) const
        {
            return ((_vec != iOther._vec) || (_cursor != iOther._cursor)) ? true : false;
        }

        inline bool operator>(const ConstIterator& iOther) const
        {
            if (_vec == iOther._vec) {
                return (_cursor > iOther._cursor);
            } else {
                return Op<T>::Compare((*_vec)[_cursor], (*iOther._vec)[iOther._cursor]) < 0;
            }
        }

        inline const T& operator*() const { return (*_vec)[_cursor]; }
        inline const T* operator->() const { return &((*_vec)[_cursor]); }
        inline operator bool() const { return _cursor < _vec->Size();}
        static ConstIterator NaTValue() { return ConstIterator(); }

        inline ERelativePosition GetRelativePosition(ConstIterator iOther)
        {
            if ( iOther._cursor < 0) {
                return ERelativePositionUndefined;
            }
            if ( iOther._cursor >= _vec->Size()) {
                return ERelativePositionUndefined;
            }
            if (iOther._cursor > _cursor) {
                return ERelativePositionAfter;
            } else if (iOther._cursor == _cursor) {
                return ERelativePositionSame;
            } else {
                return ERelativePositionBefore;
            }
        }
    private:
        const CATSGArray<T, LifeCyclePolicy>*   _vec;
        int                                     _cursor;
    };

    class Iterator {
        friend class CATSGArray<T, LifeCyclePolicy>;

    public:
        Iterator() : _vec(NULL), _cursor(-1) {}
        Iterator(CATSGArray<T, LifeCyclePolicy>* iVec, int iIndex) : _vec(iVec), _cursor(iIndex) {}
        Iterator(const Iterator& iOther) : _vec(iOther._vec), _cursor(iOther._cursor) {}
        ~Iterator() { _vec = NULL; _cursor = -1; }

        inline Iterator& operator++() { ++_cursor; return *this; }
        inline Iterator& operator--() { --_cursor; return *this; }
        inline bool operator==(const Iterator& iOther) const { return ((_vec == iOther._vec) && (_cursor == iOther._cursor)) ? true : false; }
        inline bool operator!=(const Iterator& iOther) const { return ((_vec != iOther._vec) || (_cursor != iOther._cursor)) ? true : false; }
        inline bool operator>(const Iterator& iOther) const
        {
            if (_vec == iOther._vec) {
                return (_cursor > iOther._cursor);
            } else {
                return Op<T>::Compare((*_vec)[_cursor], (*iOther._vec)[iOther._cursor]) < 0;
            }
        }
        inline T& operator*() const { return (*_vec)[_cursor]; }
        inline T* operator->() const { return &((*_vec)[_cursor]); }
        inline operator bool() const { return _cursor < _vec->Size();}
        static Iterator NaTValue() { return Iterator(); }
        inline ERelativePosition GetRelativePosition(Iterator iOther)
        {
            if ( iOther._cursor < 0) {
                return ERelativePositionUndefined;
            }
            if ( iOther._cursor >= _vec->Size()) {
                return ERelativePositionUndefined;
            }
            if (iOther._cursor > _cursor) {
                return ERelativePositionAfter;
            } else if (iOther._cursor == _cursor) {
                return ERelativePositionSame;
            } else {
                return ERelativePositionBefore;
            }
        }
    private:
        CATSGArray<T, LifeCyclePolicy>* _vec;
        int                             _cursor;
    };

    CATSGArray() : _storage(NULL), _cursor(0), _reservedSize(0)
    {
        std::call_once(s_nullValueFlag, InitNullValue);
    }

    CATSGArray(const CATSGArray& iOther) : _storage(NULL), _cursor(0), _reservedSize(0)
    {
        Copy(iOther);
    }

    //I don't know why but ODT SKUEditHyperbolaVid in SketcherUI.tst breaks if CATSGArray is non virtual -_-"
#ifndef _EMSCRIPTEN_TESTS
    virtual
#endif//_EMSCRIPTEN_TESTS
    ~CATSGArray()
    {
        Clear();
    }

    static ArrayType NaTValue()
    {
        return ArrayType();
    }

    void Clear()
    {
        if (_storage) {
            for (int i = 0; i < _cursor; ++i) {
                LifeCyclePolicy<T>::Detach(_storage[i], &_storage[i]);
                _storage[i] = s_nullValue;
            }
            delete[] _storage;
            _storage = NULL;
			_cursor = 0;
			_reservedSize = 0;
        }
    }

    HRESULT Copy(const CATSGArray& from)
    {
        HRESULT hr = E_FAIL;
        Clear();
        hr = Reserve(from.ReservedSize());
        for (int i = 0; i < from.Size(); ++i) {
            LifeCyclePolicy<T>::Attach(from[i], &(*this)[i]);
            _storage[i] = from._storage[i];
        }
        _cursor = from.Size();
        return hr;
    }

    CATSGArray& operator=(const CATSGArray& iOther)
    {
        if (&iOther != this) {
            Copy(iOther);
        }
        return *this;
    }

    HRESULT Reserve(const int iSize)
    {
        if (iSize < 0) {
            return E_INVALIDARG;
        }
        else if (iSize <= _reservedSize) {
            return S_OK;
        }

        T* newStorage = new T[iSize];
        if (newStorage == NULL) {
            return E_OUTOFMEMORY;
        }

        const int savedCursor = _cursor;
        for (int i = 0; i < _cursor; ++i) {
            newStorage[i] = _storage[i];
            _storage[i] = NAT<T>::value();
        }
        for (int i = savedCursor; i < iSize; ++i) {
            newStorage[i] = NAT<T>::value();
        }

        delete[] _storage;
        _storage = NULL;

        _storage = newStorage;
        _reservedSize = iSize;
        _cursor = savedCursor;

        return S_OK;
    }

    HRESULT Resize(const int iSize)
    {
        HRESULT hr = Reserve(iSize);
        if (hr != S_OK) {
            return hr;
        }

        for (int i = _cursor; i < _reservedSize && (hr == S_OK); ++i) {
            hr = PushBack(s_nullValue);
        }

        return hr;
    }

    inline const int Size() const
    {
        return _cursor;
    }

    inline const int ReservedSize() const
    {
        return _reservedSize;
    }

    inline Iterator Begin()
    {
        return Iterator(this, 0);
    }

    inline Iterator End()
    {
        return Iterator(this, _cursor);
    }

    inline ConstIterator CBegin() const
    {
        return ConstIterator(this, 0);
    }

    inline ConstIterator CEnd() const
    {
        return ConstIterator(this, _cursor);
    }

    inline T& operator[](int iIndex)
    {
        if (iIndex<_cursor && iIndex>=0 ) {
            return _storage[iIndex];
        } else {
            // irk :( , we should throw :) but...
            return s_nullValue;
        }
    }

    inline const T& operator[](int iIndex) const
    {
        if (iIndex<_cursor && iIndex>=0 ) {
            return _storage[iIndex];
        } else {
            // irk :( , we should throw :) but...
            return s_nullValue;
        }
    }

    HRESULT PushBack(const T& iT)
    {
        HRESULT hr = E_FAIL;
        if (_storage == NULL || _cursor>=ReservedSize()) {
            hr = Reserve(s_newReserveCoef * (_reservedSize+1));
            if (hr != S_OK) {
                return hr;
            }
        }
        if (_cursor<_reservedSize) {
            LifeCyclePolicy<T>::Attach(iT, &_storage[_cursor]);
            _storage[_cursor] = iT;
            ++_cursor;
        } else {
            return E_FAIL;
        }
        return S_OK;
    }

    HRESULT Remove(const T& iT)
    {
        for (int i=0; i<_cursor; ++i) {
            if (Op<T>::Equal(_storage[i], iT)) {
                return RemoveAt(i);
            }
        }
        return E_FAIL;
    }

    HRESULT RemoveAt(const int iAt) {
        if (iAt<0 || iAt>_cursor) {
            return E_INVALIDARG;
        }

        HRESULT hr = Swap(iAt, _cursor-1);
        if (hr != S_OK) {
            return hr;
        }

        PopBack();
        return hr;
    }

    HRESULT Remove(const Iterator& it)
    {
        if (it._vec != this) {
            return E_INVALIDARG;
        }
        return RemoveAt(it._cursor);
    }

    Iterator Find(const T& iT)
    {
        for (int i=0; i<_cursor; ++i) {
            if (Op<T>::Equal(_storage[i], iT)) {
                return Iterator(this, i);
            }
        }
        return End();
    }

    ConstIterator CFind(const T& iT) const
    {
        for (int i=0; i<_cursor; ++i) {
            if (Op<T>::Equal(_storage[i], iT)) {
                return ConstIterator(this, i);
            }
        }
        return CEnd();
    }

    inline bool IsHere(const T& iT) const
    {
        return (CFind(iT) != CEnd());
    }

    HRESULT InsertAt(const int iAt, const T& iT)
    {
        HRESULT hr = E_FAIL;

        if (iAt<0 || iAt>_cursor) {
            return E_INVALIDARG;
        }

        if (iAt == _cursor) {
            hr = PushBack(iT);
        } else {
            if (_storage == NULL || _cursor == _reservedSize) {
                hr = Reserve(s_newReserveCoef * (_reservedSize+1));
                if (hr != S_OK) return hr;
            }
            for (int i=_cursor; i>iAt; --i) {
                _storage[i] = _storage[i-1];
            }
            LifeCyclePolicy<T>::Attach(iT, &_storage[iAt]);
            _storage[iAt] = iT;
            ++_cursor;
            hr = S_OK;
        }
        return hr;
    }

    HRESULT InsertRevertSorted(const T& iT)
    {
        return InsertRevertSortedInRange(iT, 0, _cursor);
    }

    //TODO FVM1 not very clean
    HRESULT InsertRevertSortedInRange(const T& iT, const int iRangeStart, const int iRangeEnd)
    {
        if (_cursor == 0) {
            return PushBack(iT);
        }
        if (iRangeStart < 0 || iRangeStart >= _cursor || iRangeStart > iRangeEnd) {
            return E_INVALIDARG;
        }
        if (iRangeEnd <= 0 || iRangeEnd > _cursor) {
            return E_INVALIDARG;
        }

        int rs = iRangeStart;
        int mid;
        int count = iRangeEnd-rs;
        while (count>0)
        {
            mid = rs+count/2;

            if (Op<T>::Compare( iT, (*this)[mid]) >= 0) {
                rs=mid+1;
                count-=count/2+1;
            }
            else{
                count/=2;
            }
        }

        return InsertAt(rs, iT);
    }

    HRESULT InsertSorted(const T& iT)
    {
        return InsertSortedInRange(iT, 0, _cursor);
    }

    HRESULT InsertSortedInRange(const T& iT, const int iRangeStart, const int iRangeEnd)
    {
        if (_cursor == 0) {
            return PushBack(iT);
        }
        if (iRangeStart < 0 || iRangeStart >= _cursor || iRangeStart > iRangeEnd) {
            return E_INVALIDARG;
        }
        if (iRangeEnd <= 0 || iRangeEnd > _cursor) {
            return E_INVALIDARG;
        }

        int rs = iRangeStart;
        int mid;
        int count = iRangeEnd-rs;
        while (count>0)
        {
            mid = rs+count/2;

            if (Op<T>::Compare((*this)[mid], iT ) >= 0) {
                rs=mid+1;
                count-=count/2+1;
            }
            else{
                count/=2;
            }
        }

        return InsertAt(rs, iT);
    }

    T PopBack()
    {
        if (Size()>0) {
            --_cursor;
            T res = _storage[_cursor];
            LifeCyclePolicy<T>::Detach(res, &_storage[_cursor]);
            _storage[_cursor] = s_nullValue;
            return res;
        } else {
            // irk :( , we should throw :) but...
            return NAT<T>::value();
        }
    }

    inline HRESULT Swap(int i, int j)
    {
        if (i < 0 || i >= _cursor) {
            return E_INVALIDARG;
        }
        if (j < 0 || j >= _cursor) {
            return E_INVALIDARG;
        }
        if (i == j) {
            return S_OK;
        }

        return Op<T>::Swap(_storage[i], _storage[j]);
    }

    inline T& Back()
    {
        if (Size()>0) {
            return _storage[_cursor-1];
        } else {
            return s_nullValue;
        }
    }

    inline const T& CBack() const
    {
        if (Size()>0) {
            return _storage[_cursor-1];
        } else {
            return s_nullValue;
        }
    }

    inline T& Front()
    {
        if (Size()>0) {
            return _storage[0];
        } else {
            return s_nullValue;
        }
    }

    inline const T& CFront() const
    {
        if (Size()>0) {
            return _storage[0];
        } else {
            return s_nullValue;
        }
    }

    T PopFront()
    {
        if (Size()>0) {
            T res = _storage[0];
            LifeCyclePolicy<T>::Detach(res, &_storage[0]);
            for (int i=0; i<_cursor-1; ++i) {
                _storage[i] = _storage[i+1];
            }
            --_cursor;
            return res;
        } else {
            // irk :( , we should throw :) but...
            return NAT<T>::value();
        }
    }

    inline int SizeInBytes() const
    {
        return sizeof(T) * Size();
    }

    bool SameContent(const CATSGArray<T, LifeCyclePolicy>& iOther) const
    {
        if (Size() != iOther.Size()) {
            return false;
        }
        ConstIterator meIt = CBegin();
        ConstIterator meEndIt = CEnd();
        ConstIterator otherIt = iOther.CBegin();
        ConstIterator otherEndIt = iOther.CEnd();

        for (; (meIt != meEndIt) && (otherIt != otherEndIt); ++meIt, ++otherIt) {
            if (!Op<T>::Equal(*meIt, *otherIt)) {
                return false;
            }
        }

        return true;
    }

    HRESULT Append(ArrayType& iContent)
    {
        HRESULT hr = S_OK;

        ArrayType::Iterator it = iContent.Begin();
        ArrayType::Iterator endIt = iContent.End();

        for (; (it != endIt) && (hr == S_OK) ; ++it) {
            hr = PushBack(*it);
        }

        return hr;
    }

    inline void Swap(CATSGArray& other)
    {
        Op<T*>::Swap(other._storage, _storage);
        Op<volatile int>::Swap(other._cursor, _cursor);
        Op<volatile int>::Swap(other._reservedSize, _reservedSize);
    }

    static void InitNullValue()
    {
        s_nullValue = NAT<T>::value();
    }

private:
    T*                      _storage;
    volatile int            _cursor;
    volatile int            _reservedSize;
    static const int        s_newReserveCoef = 2;
    static std::once_flag   s_nullValueFlag;
    static T                s_nullValue;
};

template<typename T, template<class> class LifeCyclePolicy>
std::once_flag CATSGArray<T, LifeCyclePolicy>::s_nullValueFlag;

template<typename T, template<class> class LifeCyclePolicy>
T CATSGArray<T, LifeCyclePolicy>::s_nullValue;

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGArray_h_
