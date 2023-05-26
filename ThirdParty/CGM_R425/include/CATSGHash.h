#ifndef CATSGHash_h
#define CATSGHash_h

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGPair.h"
#include "CATSGArray.h"

//#define USE_OLD_SGHASH
#ifdef USE_OLD_SGHASH
    #define CATSGHash CATSGFixedHash
#else

//new version: the number of buckets is increased if necessary
template<typename K, typename T, typename HashFunctor = Hash<K>,  template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy>
class CATSGHash
{
public:
    struct KeyedEntry
    {
        K     _key;
        T    _value;

        KeyedEntry() : _key(), _value()
        {
            //_key = NAT<typename K>::value();
            //_value = NAT<typename T>::value();
        }

        inline bool operator==(const KeyedEntry& iOther) const {
        return ((_key==iOther._key)&&(_value==iOther._value));
        }

        inline bool operator!=(const KeyedEntry& iOther) const {
        return ((_key!=iOther._key)||(_value!=iOther._value));
        }

        static KeyedEntry NaTValue()
        {
        KeyedEntry keyedEntry;
        return keyedEntry;
        }
    };

    typedef        CATSGHash<K, T, HashFunctor, LifeCyclePolicy>     HashType;
    typedef        CATSGArray<KeyedEntry>                            EntryList;
    typedef        CATSGArray<EntryList>                            BucketTable;

    class ConstIterator {
    public:
        ConstIterator() : _associatedHash(NULL)
        {
        }

        ConstIterator(const CATSGHash& iAssociatedHash, const typename BucketTable::ConstIterator& iBucketCIterator, const typename EntryList::ConstIterator& iEntryListCIterator) :
            _associatedHash(&iAssociatedHash), _bucketCIterator(iBucketCIterator), _entryListCIterator(iEntryListCIterator)
        {
        }

        ~ConstIterator() {}

        ConstIterator& operator++()
        {
            if(_entryListCIterator!=(*_bucketCIterator).CEnd()) {
                ++_entryListCIterator;
            }

            while(_entryListCIterator==(*_bucketCIterator).CEnd() && _bucketCIterator!=((_associatedHash->_bucketTable).CEnd()) ) {
                ++_bucketCIterator;
                if(_bucketCIterator!=_associatedHash->_bucketTable.CEnd()) {
                    _entryListCIterator = (*_bucketCIterator).CBegin();
                } else {
                    // To be consistent with what CEnd returns.
                    _entryListCIterator = _associatedHash->_bucketTable.CBegin()->CEnd();
                }
            }
            return *this;
        }

        inline bool operator==(const ConstIterator& iOther) const
        {
            return (    (_associatedHash==iOther._associatedHash)
                &&        (_bucketCIterator==iOther._bucketCIterator)
                &&        (_entryListCIterator==iOther._entryListCIterator) );
        }
        inline bool operator!=(const ConstIterator& iOther) const
        {
            return (    (_associatedHash!=iOther._associatedHash)
                ||        (_bucketCIterator!=iOther._bucketCIterator)
                ||        (_entryListCIterator!=iOther._entryListCIterator) );
        }

        inline const K& GetKey() const { return (*_entryListCIterator)._key; }
        inline const T& operator*() const { return (*_entryListCIterator)._value; }
        inline const T* operator->() const { return &((*_entryListCIterator)._value); }

        static ConstIterator NaTValue() { return ConstIterator(); }
    private:
        const HashType*                                _associatedHash;
        typename BucketTable::ConstIterator            _bucketCIterator;
        typename EntryList::ConstIterator            _entryListCIterator;
    };

    class Iterator {
    public:

        friend class CATSGHash<K, T, HashFunctor, LifeCyclePolicy>;

        Iterator() : _associatedHash(NULL)
        {
        }

        Iterator(CATSGHash& iAssociatedHash, const typename BucketTable::Iterator& iBucketIterator, const typename EntryList::Iterator& iEntryListIterator) :
            _associatedHash(&iAssociatedHash), _bucketIterator(iBucketIterator), _entryListIterator(iEntryListIterator)
        {
        }

        ~Iterator() {}

        Iterator& operator++()
        {
            if(_entryListIterator!=(*_bucketIterator).End()) {
                ++_entryListIterator;
            }

            //after operator++() call, the iterator should either point to a valid element inside a bucket or be equal to End(),
            //it cannot point to the end of an intermediate bucket because we mostly do "for(it = Begin(); it != End(); ++it)"
            //and expect the iterator to be dereferenceable inside the body of the loop
            while(_entryListIterator==(*_bucketIterator).End() && _bucketIterator!=((_associatedHash->_bucketTable).End()) ) {
                ++_bucketIterator;
                if(_bucketIterator!=_associatedHash->_bucketTable.End()) {
                    _entryListIterator = (*_bucketIterator).Begin();
                } else {
                    // To be consistent with what End returns.
                    _entryListIterator = _associatedHash->_bucketTable.Begin()->End();
                }
            }
            return *this;
        }

        inline bool operator==(const Iterator& iOther) const
        {
            return (    (_associatedHash==iOther._associatedHash)
                &&        (_bucketIterator==iOther._bucketIterator)
                &&        (_entryListIterator==iOther._entryListIterator) );
        }

        inline bool operator!=(const Iterator& iOther) const
        {
            return (    (_associatedHash!=iOther._associatedHash)
                ||        (_bucketIterator!=iOther._bucketIterator)
                ||        (_entryListIterator!=iOther._entryListIterator) );
        }

        inline K& GetKey() { return (*_entryListIterator)._key; }
        inline T& operator*() const { return (*_entryListIterator)._value; }
        inline T* operator->() const { return &((*_entryListIterator)._value); }

        static Iterator NaTValue() { return Iterator(); }
    private:
        HashType*                            _associatedHash;
        typename BucketTable::Iterator                    _bucketIterator;
        typename EntryList::Iterator                    _entryListIterator;
    };

    typedef CATSGPair<ConstIterator, ConstIterator>     ConstRange;
    typedef CATSGPair<Iterator, Iterator>                 Range;

    CATSGHash() : _entryCount(0), _alpha(100.0f)
    {
        InitForSize(_defaultBucketSize);
    }

    CATSGHash(const unsigned int iDesiredBucketSize, float alpha = 100.0f) : _entryCount(0), _alpha(alpha <= 0.1f ? 0.1f : alpha)
    {
        InitForSize((iDesiredBucketSize > 0) ? iDesiredBucketSize : 1);
    }

    ~CATSGHash()
    {
    }

    static HashType NaTValue()
    {
        return HashType();
    }

    HRESULT Insert( const K& iK, const T& iT)
    {
        HRESULT hr = E_FAIL;

        if(_entryCount > static_cast<unsigned int>(_alpha * _bucketSize))
        {
            hr = Resize();
            if(hr != S_OK)
            {
                return hr;
            }
        }

        unsigned int hashKey = HashFunctor()(iK);
        unsigned int bucketIndex = hashKey - (hashKey/_bucketSize)*_bucketSize;

        KeyedEntry kEntry;
        kEntry._key = iK;
        kEntry._value = iT;
        hr = _bucketTable[bucketIndex].PushBack(kEntry);

        if(hr == S_OK)
        {
            ++_entryCount;
        }

        return hr;
    }

    HRESULT Remove( Iterator& iAt)
    {
        if(iAt._entryListIterator!=(*iAt._bucketIterator).End()) {
            (*iAt._bucketIterator).Remove(iAt._entryListIterator);

            --_entryCount;

            return S_OK;
        }

        return E_FAIL;
    }

    Iterator Begin()
    {
        typename BucketTable::Iterator bucketIt = _bucketTable.Begin();
        if(bucketIt==_bucketTable.End()) {
        return End();
        }
        typename EntryList::Iterator entryIt = bucketIt->Begin();
        while(entryIt==bucketIt->End()){
        ++bucketIt;
        if(bucketIt==_bucketTable.End()) {
            return End();
        }
        entryIt = bucketIt->Begin();
        }
        return Iterator(*this, bucketIt, entryIt );
    }

    inline Iterator End()
    {
        return Iterator(*this, _bucketTable.End(), _bucketTable.Begin()->End() );
    }

    ConstIterator CBegin() const
    {
        typename BucketTable::ConstIterator bucketIt = _bucketTable.CBegin();
        if(bucketIt==_bucketTable.CEnd()) {
            return CEnd();
        }
        typename EntryList::ConstIterator entryIt = bucketIt->CBegin();
        while(entryIt==bucketIt->CEnd()){
            ++bucketIt;
            if(bucketIt==_bucketTable.CEnd()) {
                return CEnd();
            }
            entryIt = bucketIt->CBegin();
        }
        return ConstIterator( *this, bucketIt, entryIt );
    }

    inline ConstIterator CEnd() const
    {
        return ConstIterator( *this, _bucketTable.CEnd(), _bucketTable.CBegin()->CEnd() );
    }

    inline bool IsHere(const K& iK) const
    {
        ConstIterator cit = CFind(iK);
        return (cit!=this->CEnd());
    }

    Iterator Find(const K& iK)
    {
        unsigned int hashKey = HashFunctor()(iK);
        unsigned int bucketIndex = hashKey - (hashKey/_bucketSize)*_bucketSize;
        typename EntryList::Iterator entryListIt = _bucketTable[bucketIndex].Begin();
        typename EntryList::Iterator entryListEndIt = _bucketTable[bucketIndex].End();

        for(;entryListIt!=entryListEndIt; ++entryListIt) {
            if(Op<K>::Equal((*entryListIt)._key,iK)) {
                return Iterator(*this, typename BucketTable::Iterator(&_bucketTable, bucketIndex), entryListIt);
            }
        }

        return End();
    }

    ConstIterator     CFind(const K& iK) const
    {
        unsigned int hashKey = HashFunctor()(iK);
        unsigned int bucketIndex = hashKey - (hashKey/_bucketSize)*_bucketSize;
        typename EntryList::ConstIterator entryListIt = _bucketTable[bucketIndex].CBegin();
        typename EntryList::ConstIterator entryListEndIt = _bucketTable[bucketIndex].CEnd();

        for(;entryListIt!=entryListEndIt; ++entryListIt) {
            if((*entryListIt)._key==iK) {
                return ConstIterator(*this, typename BucketTable::ConstIterator(&_bucketTable, bucketIndex), entryListIt);
            }
        }

        return CEnd();
    }

    inline Range         EqualRange(const unsigned int iHashKey)
    {
        unsigned int bucketIndex = iHashKey - (iHashKey/_bucketSize)*_bucketSize;

        Iterator startIt(*this, typename BucketTable::Iterator(&_bucketTable, bucketIndex), _bucketTable[bucketIndex].Begin());
        Iterator endIt(*this, typename BucketTable::Iterator(&_bucketTable, bucketIndex), _bucketTable[bucketIndex].End());
        ++endIt;//expected to be used with for(it=startIt; it!=endIt; ++it) so endIt has to be reachable by ++it (see operator++())
        return Range(Iterator(startIt), Iterator(endIt));
    }

    inline ConstRange    CEqualRange(const unsigned int iHashKey) const
    {
        unsigned int bucketIndex = iHashKey - (iHashKey/_bucketSize)*_bucketSize;

        ConstIterator startIt(*this, typename BucketTable::ConstIterator(&_bucketTable, bucketIndex), _bucketTable[bucketIndex].CBegin());
        ConstIterator endIt(*this, typename BucketTable::ConstIterator(&_bucketTable, bucketIndex), _bucketTable[bucketIndex].CEnd());
        ++endIt;//expected to be used with for(it=startIt; it!=endIt; ++it) so endIt has to be reachable by ++it (see operator++())
        return ConstRange(ConstIterator(startIt), ConstIterator(endIt));
    }

    inline int         Size() const
    {
        return _entryCount;
    }

    //if it does not return S_OK, the container is untouched
    //if no iNewSize is provided: doubles the size
    HRESULT Resize(unsigned int iNewSize=0)
    {
        if(iNewSize == 0)
        {
            iNewSize = _bucketSize*2;
        }

        CATSGHash newTable(iNewSize, _alpha);

        HRESULT hr = E_FAIL;

        Iterator endIt = End();
        for(Iterator it = Begin(); it != endIt; ++it)
        {
            hr = newTable.Insert(it.GetKey(), *it);
            if(hr != S_OK) {
                return hr;
            }
        }

        Swap(newTable);

        return S_OK;
    }

    void Swap(CATSGHash& other)
    {
        _bucketTable.Swap(other._bucketTable);

        Op<unsigned int>::Swap(_bucketSize, other._bucketSize);
        Op<unsigned int>::Swap(_entryCount, other._entryCount);
        Op<float>::Swap(_alpha, other._alpha);
    }

    inline float       GetAlpha()
    {
        return _alpha;
    }

    HRESULT        SetAlpha(float alpha)
    {
        if(alpha <= 0.1)
            return E_INVALIDARG;

        HRESULT hr = S_OK;
        if(alpha < _alpha)
        {
            //change in alpha may force Resize in order to maintain occupancy
            if(_entryCount > static_cast<unsigned int>(alpha * _bucketSize))
            {
                hr = Resize(static_cast<unsigned int>(_entryCount/alpha));
            }
        }
        _alpha = alpha;

        return hr;
    }

    inline unsigned int GetBucketSize()
    {
        return _bucketSize;
    }

    inline int         EntryCount() const
    {
        return _entryCount;
    }

    HRESULT        Clear()
    {
        for(unsigned int i=0; i<_bucketSize; ++i) {
            _bucketTable[i].Clear();
        }
        _entryCount = 0;

        return S_OK;
    }
private:
    HRESULT InitForSize(const unsigned int iDesiredBucketSize)
    {
        _bucketSize = iDesiredBucketSize;
        HRESULT hr =  _bucketTable.Reserve(_bucketSize);
        if(hr!=S_OK) {
            return hr;
        }
        for(unsigned int i=0; i<_bucketSize; ++i) {
            _bucketTable.PushBack(EntryList());
        }
        return S_OK;
    }

    static const unsigned int    _defaultBucketSize = 2047;
    unsigned int                _bucketSize;
    unsigned int                _entryCount;
    float                       _alpha;

    BucketTable            _bucketTable;
};
#endif//USE_OLD_SGHASH

//old version: buckets are resizable but the number of buckets is fixed
template<typename K, typename T, typename HashFunctor = Hash<K>,  template <class> class LifeCyclePolicy = CATSGNoLifeCycleMgtPolicy>
class CATSGFixedHash
{
public:
    struct KeyedEntry
    {
        K     _key;
        T    _value;

        KeyedEntry() : _key(), _value()
        {
            //_key = NAT<typename K>::value();
            //_value = NAT<typename T>::value();
        }

        inline bool operator==(const KeyedEntry& iOther) const {
        return ((_key==iOther._key)&&(_value==iOther._value));
        }

        inline bool operator!=(const KeyedEntry& iOther) const {
        return ((_key!=iOther._key)||(_value!=iOther._value));
        }

        static KeyedEntry NaTValue()
        {
        KeyedEntry keyedEntry;
        return keyedEntry;
        }
    };

    typedef        CATSGFixedHash<K, T, HashFunctor, LifeCyclePolicy>     HashType;
    typedef        CATSGArray<KeyedEntry>                                EntryList;
    typedef        CATSGArray<EntryList>                                BucketTable;

    class ConstIterator {
    public:
        ConstIterator() : _associatedHash(NULL)
        {
        }

        ConstIterator(const CATSGFixedHash& iAssociatedHash, const typename BucketTable::ConstIterator& iBucketCIterator, const typename EntryList::ConstIterator& iEntryListCIterator) :
            _associatedHash(&iAssociatedHash), _bucketCIterator(iBucketCIterator), _entryListCIterator(iEntryListCIterator)
        {
        }

        ~ConstIterator() {}

        ConstIterator& operator++()
        {
            if(_entryListCIterator!=(*_bucketCIterator).CEnd()) {
                ++_entryListCIterator;
            }

            while(_entryListCIterator==(*_bucketCIterator).CEnd() && _bucketCIterator!=((_associatedHash->_bucketTable).CEnd()) ) {
                ++_bucketCIterator;
                if(_bucketCIterator!=_associatedHash->_bucketTable.CEnd()) {
                    _entryListCIterator = (*_bucketCIterator).CBegin();
                } else {
                    // To be consistent with what CEnd returns.
                    _entryListCIterator = _associatedHash->_bucketTable.CBegin()->CEnd();
                }
            }
            return *this;
        }

        inline bool operator==(const ConstIterator& iOther) const
        {
            return (    (_associatedHash==iOther._associatedHash)
                &&        (_bucketCIterator==iOther._bucketCIterator)
                &&        (_entryListCIterator==iOther._entryListCIterator) );
        }
        inline bool operator!=(const ConstIterator& iOther) const
        {
            return (    (_associatedHash!=iOther._associatedHash)
                ||        (_bucketCIterator!=iOther._bucketCIterator)
                ||        (_entryListCIterator!=iOther._entryListCIterator) );
        }

        inline const K& GetKey() const { return (*_entryListCIterator)._key; }
        inline const T& operator*() const { return (*_entryListCIterator)._value; }

        static ConstIterator NaTValue() { return ConstIterator(); }
    private:
        const HashType*                                _associatedHash;
        typename BucketTable::ConstIterator            _bucketCIterator;
        typename EntryList::ConstIterator            _entryListCIterator;
    };

    class Iterator {
    public:
        Iterator() : _associatedHash(NULL)
        {
        }

        Iterator(CATSGFixedHash& iAssociatedHash, const typename BucketTable::Iterator& iBucketIterator, const typename EntryList::Iterator& iEntryListIterator) :
            _associatedHash(&iAssociatedHash), _bucketIterator(iBucketIterator), _entryListIterator(iEntryListIterator)
        {
        }

        ~Iterator() {}

        Iterator& operator++()
        {
            if(_entryListIterator!=(*_bucketIterator).End()) {
                ++_entryListIterator;
            }

            //after operator++() call, the iterator should either point to a valid element inside a bucket or be equal to End(),
            //it cannot point to the end of an intermediate bucket because we mostly do "for(it = Begin(); it != End(); ++it)"
            //and expect the iterator to be dereferenceable inside the body of the loop
            while(_entryListIterator==(*_bucketIterator).End() && _bucketIterator!=((_associatedHash->_bucketTable).End()) ) {
                ++_bucketIterator;
                if(_bucketIterator!=_associatedHash->_bucketTable.End()) {
                    _entryListIterator = (*_bucketIterator).Begin();
                } else {
                    // To be consistent with what End returns.
                    _entryListIterator = _associatedHash->_bucketTable.Begin()->End();
                }
            }
            return *this;
        }

        inline bool removeFromHash()
        {
            if(_entryListIterator!=(*_bucketIterator).End()) {
                (*_bucketIterator).Remove(_entryListIterator);
                return true;
            }
            return false;
        }

        inline bool operator==(const Iterator& iOther) const
        {
            return (    (_associatedHash==iOther._associatedHash)
                &&        (_bucketIterator==iOther._bucketIterator)
                &&        (_entryListIterator==iOther._entryListIterator) );
        }

        inline bool operator!=(const Iterator& iOther) const
        {
            return (    (_associatedHash!=iOther._associatedHash)
                ||        (_bucketIterator!=iOther._bucketIterator)
                ||        (_entryListIterator!=iOther._entryListIterator) );
        }

        inline K& GetKey() { return (*_entryListIterator)._key; }
        inline T& operator*() const { return (*_entryListIterator)._value; }

        static Iterator NaTValue() { return Iterator(); }
    private:
        HashType*                            _associatedHash;
        typename BucketTable::Iterator                    _bucketIterator;
        typename EntryList::Iterator                    _entryListIterator;
    };

    typedef CATSGPair<ConstIterator, ConstIterator>     ConstRange;
    typedef CATSGPair<Iterator, Iterator>                 Range;

    CATSGFixedHash()
    {
        InitForSize(_defaultBucketSize);
    }

    CATSGFixedHash(const unsigned int iDesiredBucketSize)
    {
        InitForSize((iDesiredBucketSize > 0) ? iDesiredBucketSize : 1);
    }

    ~CATSGFixedHash()
    {
    }

    static HashType NaTValue()
    {
        return HashType();
    }

    HRESULT Insert( const K& iK, const T& iT)
    {
        HRESULT hr = E_FAIL;

        unsigned int hashKey = HashFunctor()(iK);
        unsigned int bucketIndex = hashKey - (hashKey/_bucketSize)*_bucketSize;

        KeyedEntry kEntry;
        kEntry._key = iK;
        kEntry._value = iT;
        hr = _bucketTable[bucketIndex].PushBack(kEntry);
        return hr;
    }

    HRESULT Remove( Iterator& iAt)
    {
        HRESULT hr = iAt.removeFromHash() ? S_OK : E_FAIL;
        return hr;

    }

    Iterator Begin()
    {
        typename BucketTable::Iterator bucketIt = _bucketTable.Begin();
        if(bucketIt==_bucketTable.End()) {
        return End();
        }
        typename EntryList::Iterator entryIt = bucketIt->Begin();
        while(entryIt==bucketIt->End()){
        ++bucketIt;
        if(bucketIt==_bucketTable.End()) {
            return End();
        }
        entryIt = bucketIt->Begin();
        }
        return Iterator(*this, bucketIt, entryIt );
    }

    inline Iterator End()
    {
        return Iterator(*this, _bucketTable.End(), _bucketTable.Begin()->End() );
    }

    ConstIterator CBegin() const
    {
        typename BucketTable::ConstIterator bucketIt = _bucketTable.CBegin();
        if(bucketIt==_bucketTable.CEnd()) {
        return CEnd();
        }
        typename EntryList::ConstIterator entryIt = bucketIt->CBegin();
        while(entryIt==bucketIt->CEnd()){
        ++bucketIt;
        if(bucketIt==_bucketTable.CEnd()) {
            return CEnd();
        }
        entryIt = bucketIt->CBegin();
        }
        return ConstIterator( *this, bucketIt, entryIt );
    }

    inline ConstIterator CEnd() const
    {
        return ConstIterator( *this, _bucketTable.CEnd(), _bucketTable.CBegin()->CEnd() );
    }

    inline bool IsHere(const K& iK) const
    {
        ConstIterator cit = CFind(iK);
        return (cit!=this->CEnd());
    }

    Iterator Find(const K& iK)
    {
        unsigned int hashKey = HashFunctor()(iK);
        unsigned int bucketIndex = hashKey - (hashKey/_bucketSize)*_bucketSize;
        typename EntryList::Iterator entryListIt = _bucketTable[bucketIndex].Begin();
        typename EntryList::Iterator entryListEndIt = _bucketTable[bucketIndex].End();

        for(;entryListIt!=entryListEndIt; ++entryListIt) {
            if(Op<K>::Equal((*entryListIt)._key,iK)) {
                return Iterator(*this, typename BucketTable::Iterator(&_bucketTable, bucketIndex), entryListIt);
            }
        }

        return End();
    }

    ConstIterator     CFind(const K& iK) const
    {
        unsigned int hashKey = HashFunctor()(iK);
        unsigned int bucketIndex = hashKey - (hashKey/_bucketSize)*_bucketSize;
        typename EntryList::ConstIterator entryListIt = _bucketTable[bucketIndex].CBegin();
        typename EntryList::ConstIterator entryListEndIt = _bucketTable[bucketIndex].CEnd();

        for(;entryListIt!=entryListEndIt; ++entryListIt) {
            if((*entryListIt)._key==iK) {
                return ConstIterator(*this, typename BucketTable::ConstIterator(&_bucketTable, bucketIndex), entryListIt);
            }
        }

        return CEnd();
    }

    Range         EqualRange(const unsigned int iHashKey)
    {
        unsigned int bucketIndex = iHashKey - (iHashKey/_bucketSize)*_bucketSize;

        Iterator startIt(*this, typename BucketTable::Iterator(&_bucketTable, bucketIndex), _bucketTable[bucketIndex].Begin());
        Iterator endIt(*this, typename BucketTable::Iterator(&_bucketTable, bucketIndex), _bucketTable[bucketIndex].End());
        ++endIt;//expected to be used with for(it=startIt; it!=endIt; ++it) so endIt has to be reachable by ++it (see operator++())
        return Range(Iterator(startIt), Iterator(endIt));
    }

    ConstRange    CEqualRange(const unsigned int iHashKey) const
    {
        unsigned int bucketIndex = iHashKey - (iHashKey/_bucketSize)*_bucketSize;

        ConstIterator startIt(*this, typename BucketTable::ConstIterator(&_bucketTable, bucketIndex), _bucketTable[bucketIndex].CBegin());
        ConstIterator endIt(*this, typename BucketTable::ConstIterator(&_bucketTable, bucketIndex), _bucketTable[bucketIndex].CEnd());
        ++endIt;//expected to be used with for(it=startIt; it!=endIt; ++it) so endIt has to be reachable by ++it (see operator++())
        return ConstRange(ConstIterator(startIt), ConstIterator(endIt));
    }

    int         Size() const
    {
        int tot = 0;
        for(unsigned int i=0; i<_bucketSize; ++i) {
            tot += _bucketTable[i].Size();
        }
        return tot;
    }

    HRESULT        Clear()
    {
        for(unsigned int i=0; i<_bucketSize; ++i) {
            _bucketTable[i].Clear();
        }
        return S_OK;
    }
private:
    HRESULT InitForSize(const unsigned int iDesiredBucketSize)
    {
        _bucketSize = iDesiredBucketSize;
        HRESULT hr =  _bucketTable.Reserve(_bucketSize);
        if(hr!=S_OK) {
            return hr;
        }
        for(unsigned int i=0; i<_bucketSize; ++i) {
            _bucketTable.PushBack(EntryList());
        }
        return S_OK;
    }

    static const unsigned int    _defaultBucketSize = 10000;
    unsigned int                _bucketSize;

    BucketTable            _bucketTable;
};

#endif //SG_COMPOSITES_MULTIOS
#endif //CATSGHash_h
